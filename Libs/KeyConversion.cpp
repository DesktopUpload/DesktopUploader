/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/
#include "windows.h"
#include "wincrypt.h"

#include "stdio.h"
#include "conio.h"
#include "tchar.h"

#pragma hdrstop

#include "KeyConversion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#define BLOB_KEY_ALG CALG_RSA_KEYX

#define PUBLICKEYBLOB_MAGIC 0x31415352
#define PRIVATEKEYBLOB_MAGIC 0x32415352
#define DER_PUBLICKEY_HEADER 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00

//---------------------------------------------------------------------------
// Helpers
//---------------------------------------------------------------------------
void __fastcall ReverseStream(TMemoryStream* Stream)
{
	TMemoryStream* buf = new TMemoryStream;
	buf->LoadFromStream(Stream);
	__int64 size = Stream->Size;
	Stream->Clear();
	for (__int64 i=size-1; i >= 0; i--) {
		buf->Position = i;
		Stream->CopyFrom(buf, 1);
	}
}
//---------------------------------------------------------------------------

__int64 __fastcall StreamReadInt(TStream* Stream, unsigned short Length=0)
{
	if (Length==0) {
		Length = Stream->Size - Stream->Position;
	}

	__int64 result = 0;
	for (unsigned short i=0; i < Length; i++) {
		System::Byte curByte;
		Stream->ReadBuffer(&curByte, 1);

		result += (__int64)curByte << ((Length-i-1)*8);
	}
	return result;
}
//---------------------------------------------------------------------------

void __fastcall StreamWriteInt(TStream* Stream, __int64 Value)
{
	TMemoryStream* ms = new TMemoryStream;

	do {
		System::Byte curByte = Value % 256;
		ms->WriteBuffer(&curByte, 1);
		Value = (Value-curByte)/256;
	} while (Value>0);

	ReverseStream(ms);
	Stream->CopyFrom(ms, 0);
	delete ms;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TBaseKeyCoder
//---------------------------------------------------------------------------
__fastcall TBaseKeyCoder::TBaseKeyCoder()
{
	this->Modulus = new TMemoryStream;
	this->PublicExponent = 0;
}
//---------------------------------------------------------------------------

__fastcall TBaseKeyCoder::~TBaseKeyCoder()
{
	delete this->Modulus;
}
//---------------------------------------------------------------------------

void __fastcall TBaseKeyCoder::ReadBlobInt(TMemoryStream* Stream,
	System::PByte Buffer, unsigned int Length)
{
	Stream->Clear();
	Stream->WriteBuffer(Buffer, Length);
	ReverseStream(Stream);
}
//---------------------------------------------------------------------------

void __fastcall TBaseKeyCoder::WriteBlobInt(TMemoryStream* Blob, TMemoryStream* Value)
{
	TMemoryStream* ms = new TMemoryStream;
	ms->LoadFromStream(Value);
	ReverseStream(ms);
	Blob->CopyFrom(ms, 0);

	delete ms;
}
//---------------------------------------------------------------------------

void __fastcall TBaseKeyCoder::ReadAsnInt(TASNValue* AsnValue, TMemoryStream* Dest)
{
	Dest->Clear();

	TMemoryStream* val = AsnValue->Value;

	val->Position = 0;
	if (val->Size > 1) {
		System::Byte firstByte;
		val->ReadBuffer(&firstByte, 1);
		if (firstByte != 0x00) {
			val->Position = 0;
		}
	}

	Dest->CopyFrom(val, val->Size - val->Position);
	Dest->Position = 0;
	val->Position = 0;
}
//---------------------------------------------------------------------------

__int64 __fastcall TBaseKeyCoder::ReadAsnInt(TASNValue* AsnValue)
{
	TMemoryStream* ms = new TMemoryStream;
	this->ReadAsnInt(AsnValue, ms);
	__int64 result = StreamReadInt(ms);
	delete ms;

	return result;
}
//---------------------------------------------------------------------------

TASNValue* __fastcall TBaseKeyCoder::EncodeAsnInt(TMemoryStream* Value)
{
	TASNValue* result = new TASNValue(0x02); //integer

	Value->Position = 0;
	if (Value->Size > 1) {
		System::Byte firstByte;
		Value->ReadBuffer(&firstByte, 1);
		if (firstByte & 0x80) { //first bit set
			System::Byte zeroByte = 0x00;
			result->Value->WriteBuffer(&zeroByte, 1);
		}
	}

	result->Value->CopyFrom(Value, 0);

	result->Value->Position = 0;
    Value->Position = 0;

	return result;
}
//---------------------------------------------------------------------------

TASNValue* __fastcall TBaseKeyCoder::EncodeAsnInt(__int64 Value)
{
	TMemoryStream* ms = new TMemoryStream;
	StreamWriteInt(ms, Value);

	TASNValue* result = this->EncodeAsnInt(ms);
	delete ms;

	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TPublicKeyCoder
//---------------------------------------------------------------------------
__fastcall TPublicKeyCoder::TPublicKeyCoder()
	: TBaseKeyCoder()
{
}
//---------------------------------------------------------------------------

__fastcall TPublicKeyCoder::~TPublicKeyCoder()
{
}
//---------------------------------------------------------------------------

void __fastcall TPublicKeyCoder::EncodeBlob(TMemoryStream* Stream)
{
	BLOBHEADER blobheader;
	RSAPUBKEY rsapubkey;

	//Prepare structures
	blobheader.bType = PUBLICKEYBLOB;
	blobheader.bVersion = 2;
	blobheader.reserved = 0;
	blobheader.aiKeyAlg = CALG_RSA_KEYX; //CALG_RSA_SIGN?

	rsapubkey.magic = PUBLICKEYBLOB_MAGIC; //RSA1
	rsapubkey.bitlen = this->Modulus->Size*8;
	rsapubkey.pubexp = this->PublicExponent;

	//Clear resulting stream
	Stream->Clear();
	//Write structures
	Stream->WriteBuffer((void*)&blobheader, sizeof(BLOBHEADER));
	Stream->WriteBuffer((void*)&rsapubkey, sizeof(RSAPUBKEY));

	//Write modulus
	this->WriteBlobInt(Stream, this->Modulus);

	//Housekeeping
	Stream->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TPublicKeyCoder::DecodeBlob(TMemoryStream* Stream)
{
	BLOBHEADER* blobheader = (BLOBHEADER*)Stream->Memory;
	RSAPUBKEY* rsapubkey = (RSAPUBKEY*)((System::PByte)Stream->Memory + sizeof(BLOBHEADER));

	unsigned int byteLen = rsapubkey->bitlen/8;

	System::PByte modulus = ((System::PByte)Stream->Memory + sizeof(BLOBHEADER) + sizeof(RSAPUBKEY));

    // Get exponent
	this->PublicExponent = rsapubkey->pubexp;
	// Get modulus
	this->ReadBlobInt(this->Modulus, modulus, byteLen);
	/*
	#ifdef _DEBUG
		this->Modulus->SaveToFile("modulus.bin");

		_tprintf(_T("\t blobheader->bType 0x%x\n"), blobheader->bType);
		_tprintf(_T("\t blobheader->bVersion 0x%x\n"), blobheader->bVersion);
		_tprintf(_T("\t blobheader->reserved 0x%x\n"), blobheader->reserved);
		_tprintf(_T("\t blobheader->aiKeyAlg 0x%x\n\n"), blobheader->aiKeyAlg);

		_tprintf(_T("\t rsapubkey->magic 0x%x\n"), rsapubkey->magic);
		_tprintf(_T("\t rsapubkey->bitlen 0x%x\n"), rsapubkey->bitlen);
		_tprintf(_T("\t rsapubkey->pubexp 0x%x\n"), rsapubkey->pubexp);
	#endif  */

	//Housekeeping
	Stream->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TPublicKeyCoder::EncodeDer(TMemoryStream* Stream)
{
	System::Byte zeroByte = 0x00;

	//Encode modulus
	TASNValue* modulus = this->EncodeAsnInt(this->Modulus);

	//Encode exponent
	TASNValue* exponent = this->EncodeAsnInt(this->PublicExponent);

	//Encode key sequence
	TASNValue* keySequence = new TASNValue(0x30); //sequence
	keySequence->WriteASNValue(modulus);
	keySequence->WriteASNValue(exponent);

	//Bit string
	TASNValue* bitString = new TASNValue(0x03); //bit string
	bitString->Value->WriteBuffer(&zeroByte, 1); //Unused bits
	bitString->WriteASNValue(keySequence);

	//Root sequence
	TASNValue* body = new TASNValue(0x30);
	//Write header
	System::Byte headerBytes[] = {DER_PUBLICKEY_HEADER};
	body->Value->WriteBuffer(&headerBytes, sizeof(headerBytes));
	//Write bit string
	body->WriteASNValue(bitString);

	//Encode DER
	Stream->Clear();
	body->Encode(Stream);

	//Clean up
	delete body;
	delete bitString;
	delete keySequence;
	delete modulus;
	delete exponent;

	//Housekeeping
	Stream->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TPublicKeyCoder::DecodeDer(TMemoryStream* Stream)
{
	//Decode root sequence
	TASNValue* body = new TASNValue;
	body->Decode(Stream);

	//Seek to bit string with keys
	TASNValue* bitString = new TASNValue;
	bitString->Decode(body->Value, true); //Skip header
	bitString->Decode(body->Value);

	//Decode key sequence
	bitString->Value->Position = 1; //Skip unused bits
	TASNValue* keySequence = new TASNValue;
	keySequence->Decode(bitString->Value);
	//Read modulus
	TASNValue* modulus = new TASNValue;
	modulus->Decode(keySequence->Value);
	this->ReadAsnInt(modulus, this->Modulus);
	//Read exponent
	TASNValue* exponent = new TASNValue;
	exponent->Decode(keySequence->Value);
	this->PublicExponent = this->ReadAsnInt(exponent);

	delete body;
	delete bitString;
	delete keySequence;
	delete modulus;
	delete exponent;

	//Housekeeping
	Stream->Position = 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TPrivateKeyCoder
//---------------------------------------------------------------------------
__fastcall TPrivateKeyCoder::TPrivateKeyCoder()
	: TBaseKeyCoder()
{
	this->Prime1 = new TMemoryStream;
	this->Prime2 = new TMemoryStream;
	this->Exponent1 = new TMemoryStream;
	this->Exponent2 = new TMemoryStream;
	this->Coefficient = new TMemoryStream;
	this->PrivateExponent = new TMemoryStream;
}
//---------------------------------------------------------------------------

__fastcall TPrivateKeyCoder::~TPrivateKeyCoder()
{
	delete this->Prime1;
	delete this->Prime2;
	delete this->Exponent1;
	delete this->Exponent2;
	delete this->Coefficient;
	delete this->PrivateExponent;
}
//---------------------------------------------------------------------------

void __fastcall TPrivateKeyCoder::EncodeBlob(TMemoryStream* Stream)
{
	BLOBHEADER blobheader;
	RSAPUBKEY rsapubkey;

	//Prepare structures
	blobheader.bType = PRIVATEKEYBLOB;
	blobheader.bVersion = 2;
	blobheader.reserved = 0;
	blobheader.aiKeyAlg = BLOB_KEY_ALG;

	rsapubkey.magic = PRIVATEKEYBLOB_MAGIC; //RSA1
	rsapubkey.bitlen = this->Modulus->Size*8;
	rsapubkey.pubexp = this->PublicExponent;

	//Write structures
	Stream->WriteBuffer((void*)&blobheader, sizeof(BLOBHEADER));
	Stream->WriteBuffer((void*)&rsapubkey, sizeof(RSAPUBKEY));

	//Write streams
	this->WriteBlobInt(Stream, this->Modulus);
	this->WriteBlobInt(Stream, this->Prime1);
	this->WriteBlobInt(Stream, this->Prime2);
	this->WriteBlobInt(Stream, this->Exponent1);
	this->WriteBlobInt(Stream, this->Exponent2);
	this->WriteBlobInt(Stream, this->Coefficient);
	this->WriteBlobInt(Stream, this->PrivateExponent);
}
//---------------------------------------------------------------------------

void __fastcall TPrivateKeyCoder::DecodeBlob(TMemoryStream* Stream)
{
	/*
	BLOBHEADER blobheader;
	RSAPUBKEY rsapubkey;
	BYTE modulus[rsapubkey.bitlen/8];
	BYTE prime1[rsapubkey.bitlen/16];
	BYTE prime2[rsapubkey.bitlen/16];
	BYTE exponent1[rsapubkey.bitlen/16];
	BYTE exponent2[rsapubkey.bitlen/16];
	BYTE coefficient[rsapubkey.bitlen/16];
	BYTE privateExponent[rsapubkey.bitlen/8];
	*/

	BLOBHEADER* blobheader = (BLOBHEADER*)Stream->Memory;
	RSAPUBKEY* rsapubkey = (RSAPUBKEY*)((System::PByte)Stream->Memory + sizeof(BLOBHEADER));

	unsigned int byteLen = rsapubkey->bitlen/8;
	unsigned int halfLen = byteLen/2;

	System::PByte modulus = ((System::PByte)Stream->Memory + sizeof(BLOBHEADER) + sizeof(RSAPUBKEY));
	System::PByte prime1 = modulus + byteLen;
	System::PByte prime2 = prime1 + halfLen;
	System::PByte exponent1 = prime2 + halfLen;
	System::PByte exponent2 = exponent1 + halfLen;
	System::PByte coefficient = exponent2 + halfLen;
	System::PByte privateExponent = coefficient + halfLen;


    // Get exponent
	this->PublicExponent = rsapubkey->pubexp;
	// Get values
	this->ReadBlobInt(this->Modulus, modulus, byteLen);
	this->ReadBlobInt(this->Prime1, prime1, halfLen);
	this->ReadBlobInt(this->Prime2, prime2, halfLen);
	this->ReadBlobInt(this->Exponent1, exponent1, halfLen);
	this->ReadBlobInt(this->Exponent2, exponent2, halfLen);
	this->ReadBlobInt(this->Coefficient, coefficient, halfLen);
	this->ReadBlobInt(this->PrivateExponent, privateExponent, byteLen);
	/*
	#ifdef _DEBUG
		this->Modulus->SaveToFile("Modulus.bin");
		this->Prime1->SaveToFile("Prime1.bin");
		this->Prime2->SaveToFile("Prime2.bin");
		this->Exponent1->SaveToFile("Exponent1.bin");
		this->Exponent2->SaveToFile("Exponent2.bin");
		this->Coefficient->SaveToFile("Coefficient.bin");
		this->PrivateExponent->SaveToFile("PrivateExponent.bin");

		_tprintf(_T("\t blobheader->bType 0x%x\n"), blobheader->bType);
		_tprintf(_T("\t blobheader->bVersion 0x%x\n"), blobheader->bVersion);
		_tprintf(_T("\t blobheader->reserved 0x%x\n"), blobheader->reserved);
		_tprintf(_T("\t blobheader->aiKeyAlg 0x%x\n\n"), blobheader->aiKeyAlg);

		_tprintf(_T("\t rsapubkey->magic 0x%x\n"), rsapubkey->magic);
		_tprintf(_T("\t rsapubkey->bitlen 0x%x\n"), rsapubkey->bitlen);
		_tprintf(_T("\t rsapubkey->pubexp 0x%x\n"), rsapubkey->pubexp);
	#endif  */
}
//---------------------------------------------------------------------------

void __fastcall TPrivateKeyCoder::EncodeDer(TMemoryStream* Stream)
{
	//Create body sequence
	TASNValue* body = new TASNValue(0x30);

	TASNValue* asn;
	//Write dummy int
	asn = this->EncodeAsnInt((__int64)0);
	body->WriteASNValue(asn); delete asn;
	//Write modulus
	asn = this->EncodeAsnInt(this->Modulus);
	body->WriteASNValue(asn); delete asn;
	//Write public exponent
	asn = this->EncodeAsnInt(this->PublicExponent);
	body->WriteASNValue(asn); delete asn;
	//Write private exponent
	asn = this->EncodeAsnInt(this->PrivateExponent);
	body->WriteASNValue(asn); delete asn;
	//Write prime1
	asn = this->EncodeAsnInt(this->Prime1);
	body->WriteASNValue(asn); delete asn;
	//Write prime2
	asn = this->EncodeAsnInt(this->Prime2);
	body->WriteASNValue(asn); delete asn;
	//Write exponent1
	asn = this->EncodeAsnInt(this->Exponent1);
	body->WriteASNValue(asn); delete asn;
	//Write exponent2
	asn = this->EncodeAsnInt(this->Exponent2);
	body->WriteASNValue(asn); delete asn;
	//Write coefficient
	asn = this->EncodeAsnInt(this->Coefficient);
	body->WriteASNValue(asn); delete asn;

	//Encode DER
	body->Encode(Stream);

	//Clean up
	delete body;
}
//---------------------------------------------------------------------------

void __fastcall TPrivateKeyCoder::DecodeDer(TMemoryStream* Stream)
{
	//Decode root sequence
	TASNValue* body = new TASNValue;
	body->Decode(Stream);

	//Read values
	TASNValue* asn = new TASNValue;
	//Skip first value
	asn->Decode(body->Value, true);
	//Read modulus
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->Modulus);
	//Read public exponent
	asn->Decode(body->Value);
	this->PublicExponent = ReadAsnInt(asn);
	//Read private exponent
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->PrivateExponent);
	//Read prime1
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->Prime1);
	//Read prime2
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->Prime2);
	//Read exponent1
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->Exponent1);
	//Read exponent2
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->Exponent2);
	//Read coefficient
	asn->Decode(body->Value);
	this->ReadAsnInt(asn, this->Coefficient);

	delete body;
	delete asn;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TASNValue
//---------------------------------------------------------------------------
__fastcall TASNValue::TASNValue(System::Byte Tag)
{
	this->Value = new TMemoryStream;
	this->Tag = Tag;
}
//---------------------------------------------------------------------------

__fastcall TASNValue::~TASNValue()
{
	delete this->Value;
}
//---------------------------------------------------------------------------

void __fastcall TASNValue::Encode(TMemoryStream* Stream)
{
	//Write type
	Stream->WriteBuffer(&this->Tag, 1);

	//Write size

	__int64 size = this->Value->Size;
	System::Byte firstByte;
	if (size < 127) {
		//Write size as is
		firstByte = (System::Byte)size;
		Stream->WriteBuffer(&firstByte, 1);
	}
	else {
		//Prepare length sequence
		TMemoryStream* sizeBuf = new TMemoryStream;
		do {
			System::Byte curByte = size % 256;
			sizeBuf->WriteBuffer(&curByte, 1);

			size = (size - curByte) / 256;
		} while (size > 0);

		ReverseStream(sizeBuf);

		//Write length sequence
		firstByte = 0x80 + sizeBuf->Size;
		Stream->WriteBuffer(&firstByte, 1);
		Stream->CopyFrom(sizeBuf, 0);
	}

	//Write value
	Stream->CopyFrom(this->Value, 0);
	this->Value->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TASNValue::Decode(TMemoryStream* Stream, bool Skip)
{
	this->Value->Clear();

	//Read type
	System::Byte tag;
	Stream->ReadBuffer(&tag, 1);

	//Read first byte
	System::Byte firstByte;
	Stream->ReadBuffer(&firstByte, 1);

	__int64 size = 0;
	if (firstByte < 127) {
		size = firstByte;
	}
	else if (firstByte > 127) {
		System::Byte sizeLen;
		sizeLen = firstByte - 0x80;
		//Read length sequence
		size = StreamReadInt(Stream, sizeLen);
	}
	else {
		throw EKeyConversionError("Invalid length value.");
	}

	if (Skip) {
		Stream->Seek(size, soCurrent);
		return;
	}

	this->Value->CopyFrom(Stream, size);
	this->Value->Position = 0;
	this->Tag = tag;
}
//---------------------------------------------------------------------------

void __fastcall TASNValue::WriteASNValue(TASNValue* ASNValue)
{
	ASNValue->Encode(this->Value);
}
//---------------------------------------------------------------------------
