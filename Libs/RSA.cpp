/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#include "Custom/Custom.h"

#pragma hdrstop

//---------------------------------------------------------------------------
#include "RSA.h"
#include "TFramework.h"
extern TFramework* Framework;
#include "KeyConversion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "crypt32.lib"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TRSA methods
//---------------------------------------------------------------------------
__fastcall TRSA::TRSA()
{
	this->ClientKey = NULL;
	this->ServerKey = NULL;
	this->ClientSignKey = NULL;
	this->ServerSignKey = NULL;

	//Clear context
	CryptAcquireContextW(&this->hCryptProv, CUSTOM_PRODUCT_NAME, NULL,
		PROV_RSA_FULL, CRYPT_DELETEKEYSET);
	//Create new context
	if (!CryptAcquireContextW(&this->hCryptProv, CUSTOM_PRODUCT_NAME, NULL,
		PROV_RSA_FULL, CRYPT_NEWKEYSET))
	{
		throw ERSAError(GetLastError(), L"Failed to initalize CryptoAPI");
	}

	//Read key resources
	this->ClientKey = new TRSAKey(this->hCryptProv, "ClientPrivateKey", true);
	this->ServerKey = new TRSAKey(this->hCryptProv, "ServerPublicKey", false);

	//Generate session signature key
	this->ClientSignKey = new TRSAKey(this->hCryptProv, AT_SIGNATURE, CFG_SIGNATUREKEY_LENGTH);
}
//---------------------------------------------------------------------------

__fastcall TRSA::~TRSA()
{
	delete this->ClientKey;
	delete this->ServerKey;
	delete this->ClientSignKey;
	delete this->ServerSignKey;

	CryptReleaseContext(this->hCryptProv, 0);
	//Clear context
	CryptAcquireContextW(&this->hCryptProv, CUSTOM_PRODUCT_NAME, NULL,
		PROV_RSA_FULL, CRYPT_DELETEKEYSET);
}
//---------------------------------------------------------------------------

void __fastcall TRSA::Encrypt(TMemoryStream* Stream)
{
	/* Damage message test
	Stream->Position = 0;
	Stream->Write("{Peq", 3);
	*/

	//Calculate input & output block sizes
	TRSAKey* key = this->ServerKey;
	DWORD dwOutSize = key->ByteLength;
	DWORD dwInSize = dwOutSize-11;

	//Create a buffers for encrypted data
	TMemoryStream* buf = new TMemoryStream;
	TMemoryStream* result = new TMemoryStream;
	buf->Size = dwOutSize;

	//Loop throgh chunks of data
	Stream->Position = 0;
	DWORD dwSize = dwInSize;
	bool final = false;
	do {
		buf->Position = 0;
		if (Stream->Position + dwInSize >= Stream->Size) {
			final = true;
			dwSize = Stream->Size - Stream->Position;
		}
		else {
			dwSize = dwInSize;
		}
		buf->CopyFrom(Stream, dwSize);

		// Encrypt data
		if (!CryptEncrypt(key->KeyHandle, NULL, final, 0, (System::PByte)buf->Memory, &dwSize, dwOutSize))
		{
			delete buf;
			throw ERSAError(GetLastError(), L"Encryption failed");
		}

		//Reverse bytes and add to result
		ReverseStream(buf);
		result->CopyFrom(buf, 0);
	} while (!final);

	Stream->LoadFromStream(result);
	Stream->Position = 0;

	delete buf;
	delete result;
}
//---------------------------------------------------------------------------

void __fastcall TRSA::Decrypt(TMemoryStream* Stream)
{
    //Calculate input & output block sizes
	TRSAKey* key = this->ClientKey;
	DWORD dwInSize = key->ByteLength;

	//Create a buffers for decrypted data
	TMemoryStream* buf = new TMemoryStream;
	TMemoryStream* result = new TMemoryStream;
	buf->Size = dwInSize;

	//Loop throgh chunks of data
	Stream->Position = 0;
	DWORD dwSize = dwInSize;
	bool final = false;
	do {
		buf->Position = 0;
		if (Stream->Position + dwInSize >= Stream->Size) {
			final = true;
			dwSize = Stream->Size - Stream->Position;
		}
		else {
			dwSize = dwInSize;
		}
		buf->CopyFrom(Stream, dwSize);
		ReverseStream(buf); //to little-endian

		// Decrypt data
		if (!CryptDecrypt(key->KeyHandle, NULL, final, 0, (System::PByte)buf->Memory, &dwSize))
		{
			delete buf;
			//throw ERSAException(L"Decryption failed.");
			throw ERSAError(GetLastError(), L"Decryption failed");
		}
		buf->Position = 0;
		result->CopyFrom(buf, dwSize);
	} while (!final);

	Stream->LoadFromStream(result);
	Stream->Position = 0;

	delete buf;
	delete result;
}
//---------------------------------------------------------------------------

void __fastcall TRSA::Sign(TMemoryStream* Message, TMemoryStream* Signature)
{
	// Create hash object
	HCRYPTHASH hHash;

	if(!CryptCreateHash(this->hCryptProv, CALG_SHA1, 0, 0, &hHash)) {
		throw ERSAError(GetLastError(), L"Cannot create hash object");
    }

	// Calulate hash value
	if(!CryptHashData(hHash, (System::PByte)Message->Memory, Message->Size, 0))
	{
		throw ERSAError(GetLastError(), L"Hashing failed");
	}

	// Prepare signature buffer
	System::PByte pbSignature;
	DWORD dwSigLen;

	if(!CryptSignHash(hHash, AT_SIGNATURE, NULL, 0, NULL, &dwSigLen))
	{
		throw ERSAError(GetLastError(), L"Signing failed");
	}

	Signature->Clear();
	Signature->Size = dwSigLen;

	// Sign hash
	if(!CryptSignHash(hHash, AT_SIGNATURE, NULL, 0, (System::PByte)Signature->Memory, &dwSigLen))
	{
		CryptDestroyHash(hHash);
		delete Signature;
		throw ERSAError(GetLastError(), L"Signing failed");
	}

	// Write to steam
	ReverseStream(Signature);  //to big-endian

	// Clean up
	CryptDestroyHash(hHash);
}
//---------------------------------------------------------------------------

void __fastcall TRSA::Verify(TMemoryStream* Message, TMemoryStream* Signature)
{
	// Create hash object
	HCRYPTHASH hHash;

	if(!CryptCreateHash(this->hCryptProv, CALG_SHA1, 0, 0, &hHash)) {
		throw ERSAError(GetLastError(), L"Cannot create hash object");
	}

	// Calulate hash value
	if(!CryptHashData(hHash, (System::PByte)Message->Memory, Message->Size, 0))
	{
		throw ERSAError(GetLastError(), L"Hashing failed");
	}

	// Verify signature
	ReverseStream(Signature); //to little-endian
	if (!CryptVerifySignature(hHash, (System::PByte)Signature->Memory,
		Signature->Size, this->ServerSignKey->KeyHandle, NULL, 0))
	{
		DWORD dwError = GetLastError();
		if (dwError == (DWORD)NTE_BAD_SIGNATURE) throw ERSAException("Bad signature.");
		else throw ERSAError(dwError, L"Verification failed");
	}

	// Clean up
	CryptDestroyHash(hHash);
}
//---------------------------------------------------------------------------

void __fastcall TRSA::JoinMessage(TMemoryStream* Message, TMemoryStream* Signature,
	TMemoryStream* Pack)
{
	Pack->LoadFromStream(Message);

	Pack->Position = Pack->Size;
	System::Byte zeroByte = 0x00;
	Pack->WriteBuffer(&zeroByte, 1); //Add signature separator

	Pack->CopyFrom(Signature, 0);

	//Hosekeeping
	Message->Position = 0;
	Signature->Position = 0;
	Pack->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TRSA::SplitMessage(TMemoryStream* Message, TMemoryStream* Signature,
	TMemoryStream* Pack)
{
	Message->Clear();
	Signature->Clear();

	Pack->Position = 0;
	__int64 pos = 0;
	do {
		System::Byte curByte;
		Pack->ReadBuffer(&curByte, 1);
		if (curByte == 0x00) {
			pos = Pack->Position-1;
			break;
		}
	} while (Pack->Position < Pack->Size);

	if (pos==0 || pos==Pack->Size-1) {
		throw ERSAException("Invalid message");
	}

	Pack->Position = 0;
	Message->CopyFrom(Pack, pos);
	Pack->Position = pos+1;
	Signature->CopyFrom(Pack, Pack->Size - Pack->Position);

	//Hosekeeping
	Message->Position = 0;
	Signature->Position = 0;
	Pack->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TRSA::ExportClientSignKey(TMemoryStream* Stream)
{
	this->ClientSignKey->ExportPublic(Stream);
}
//---------------------------------------------------------------------------

void __fastcall TRSA::ImportServerSignKey(TMemoryStream* Stream)
{
	delete this->ServerSignKey; this->ServerSignKey = NULL;
	this->ServerSignKey = new TRSAKey(this->hCryptProv, Stream, false);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TRSAKey
//---------------------------------------------------------------------------
void __fastcall TRSAKey::Init(HCRYPTPROV hCryptProv, HCRYPTKEY hKey)
{
	this->FKeyHandle = hKey;
	//Get key length
	DWORD dwData;
	DWORD dwDataSize = 4;
	if (!CryptGetKeyParam(this->FKeyHandle, KP_BLOCKLEN, (System::PByte)&dwData, &dwDataSize, 0)) {
		throw ERSAError(GetLastError(), L"Failed to get key data");
	}
	this->FByteLength = dwData/8;
}
//---------------------------------------------------------------------------

void __fastcall TRSAKey::Init(HCRYPTPROV hCryptProv, TMemoryStream* Stream)
{
	HCRYPTKEY hKey;
	if (!CryptImportKey(hCryptProv, (System::PByte)Stream->Memory,
		Stream->Size, 0, 0, &hKey))
	{
		throw ERSAError(GetLastError(), L"Failed to load key");
	}
	this->Init(hCryptProv, hKey);
}
//---------------------------------------------------------------------------

void __fastcall TRSAKey::Init(HCRYPTPROV hCryptProv, TMemoryStream* Stream, bool Private)
{
	//Convert key
	TBaseKeyCoder* coder;
	if (Private) coder = new TPrivateKeyCoder;
	else coder = new TPublicKeyCoder;

	coder->DecodeDer(Stream);
	TMemoryStream* blobStream = new TMemoryStream;
	coder->EncodeBlob(blobStream);
	delete coder;
	//Import key
	this->Init(hCryptProv, blobStream);
	delete blobStream;
}
//---------------------------------------------------------------------------

__fastcall TRSAKey::TRSAKey(HCRYPTPROV hCryptProv, ALG_ID AlgID, DWORD Length)
{
	this->FKeyHandle = NULL;

	HCRYPTKEY hKey;
	if (!CryptGenKey(hCryptProv, AlgID, Length<<16, &hKey)) {
		throw ERSAError(GetLastError(), L"Failed to generate key");
	}
	this->Init(hCryptProv, hKey);
}
//---------------------------------------------------------------------------

__fastcall TRSAKey::TRSAKey(HCRYPTPROV hCryptProv, TMemoryStream* Stream, bool Private)
{
	this->FKeyHandle = NULL;

	this->Init(hCryptProv, Stream, Private);
}
//---------------------------------------------------------------------------

__fastcall TRSAKey::TRSAKey(HCRYPTPROV hCryptProv, AnsiString ResourceName, bool Private)
{
	this->FKeyHandle = NULL;

	//Read key resource
	TMemoryStream* derStream = new TMemoryStream;
	if (!Framework->ExtractResourceToStream(ResourceName, derStream)) {
		throw ERSAError(L"Key resource not found", L"Failed to load key");
	}
	//Convert key
	this->Init(hCryptProv, derStream, Private);

	delete derStream;
}
//---------------------------------------------------------------------------

__fastcall TRSAKey::~TRSAKey()
{
	CryptDestroyKey(this->FKeyHandle);
}
//---------------------------------------------------------------------------

void __fastcall TRSAKey::ExportPublic(TMemoryStream* Stream)
{
	TMemoryStream* buf = new TMemoryStream;

	Stream->Clear();

	// Get public key size
	DWORD dwLen;
	if (!CryptExportKey(this->KeyHandle, NULL, PUBLICKEYBLOB, 0,
		NULL, &dwLen))
	{
		throw ERSAError(GetLastError(), L"Signature key export failed");
	}

	//Prepare buffer
	buf->Size = dwLen;

	// Get public key
	if (!CryptExportKey(this->KeyHandle, NULL, PUBLICKEYBLOB, 0,
		(System::PByte)buf->Memory, &dwLen))
	{
		throw ERSAError(GetLastError(), L"Signature key export failed");
	}

	//Convert key
	TPublicKeyCoder* coder = new TPublicKeyCoder;

	coder->DecodeBlob(buf);
	buf->Clear();
	coder->EncodeDer(Stream);

	delete coder;
	delete buf;
}
//---------------------------------------------------------------------------
