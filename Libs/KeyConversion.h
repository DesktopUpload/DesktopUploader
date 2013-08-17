/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/
#ifndef KeyConversionH
#define KeyConversionH

#include <vcl.h>
//---------------------------------------------------------------------------
// Helpers
//---------------------------------------------------------------------------
void __fastcall ReverseStream(TMemoryStream* Stream);

//---------------------------------------------------------------------------
// TASNValue
//---------------------------------------------------------------------------
class TASNValue
{
public:
	__fastcall TASNValue(System::Byte Tag=0x00);
	__fastcall ~TASNValue();

	TMemoryStream* Value;
	unsigned __int8 Tag;

	void __fastcall Encode(TMemoryStream* Stream);
	void __fastcall Decode(TMemoryStream* Stream, bool Skip=false);
	void __fastcall WriteASNValue(TASNValue* ASNValue);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Key coders
//---------------------------------------------------------------------------
class TBaseKeyCoder
{
public:
	__fastcall TBaseKeyCoder();
	__fastcall ~TBaseKeyCoder();

	TMemoryStream* Modulus;
	unsigned int PublicExponent;

	virtual void __fastcall EncodeBlob(TMemoryStream* Stream) = NULL;
	virtual void __fastcall DecodeBlob(TMemoryStream* Stream) = NULL;
	virtual void __fastcall EncodeDer(TMemoryStream* Stream) = NULL;
	virtual void __fastcall DecodeDer(TMemoryStream* Stream) = NULL;

protected:
	void __fastcall ReadBlobInt(TMemoryStream* Stream,
		System::PByte Buffer, unsigned int Length);
	void __fastcall WriteBlobInt(TMemoryStream* Blob, TMemoryStream* Value);

	void __fastcall ReadAsnInt(TASNValue* AsnValue, TMemoryStream* Dest);
	__int64 __fastcall ReadAsnInt(TASNValue* AsnValue);
	TASNValue* __fastcall EncodeAsnInt(TMemoryStream* Value);
	TASNValue* __fastcall EncodeAsnInt(__int64 Value);
};
//---------------------------------------------------------------------------

class TPublicKeyCoder : public TBaseKeyCoder
{
public:
	__fastcall TPublicKeyCoder();
	__fastcall ~TPublicKeyCoder();

	void __fastcall EncodeBlob(TMemoryStream* Stream);
	void __fastcall DecodeBlob(TMemoryStream* Stream);
	void __fastcall EncodeDer(TMemoryStream* Stream);
	void __fastcall DecodeDer(TMemoryStream* Stream);
};
//---------------------------------------------------------------------------

class TPrivateKeyCoder : public TBaseKeyCoder
{
public:
	__fastcall TPrivateKeyCoder();
	__fastcall ~TPrivateKeyCoder();

	TMemoryStream* Prime1;
	TMemoryStream* Prime2;
	TMemoryStream* Exponent1;
	TMemoryStream* Exponent2;
	TMemoryStream* Coefficient;
	TMemoryStream* PrivateExponent;

	void __fastcall EncodeBlob(TMemoryStream* Stream);
	void __fastcall DecodeBlob(TMemoryStream* Stream);
	void __fastcall EncodeDer(TMemoryStream* Stream);
	void __fastcall DecodeDer(TMemoryStream* Stream);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// EKeyConversionError
//---------------------------------------------------------------------------
class EKeyConversionError: public Exception
{
public:
	__fastcall EKeyConversionError(UnicodeString Message) : Exception(Message) {};
};

//---------------------------------------------------------------------------
#endif
