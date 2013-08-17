/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#ifndef RSAH
#define RSAH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------
#include "Config.h"
#include "BaseExceptions.h"

#pragma hdrstop

#include <wincrypt.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TRSAKey
//---------------------------------------------------------------------------
class TRSAKey
{
protected:
   HCRYPTKEY FKeyHandle;
   int FByteLength;

	void __fastcall Init(HCRYPTPROV hCryptProv, HCRYPTKEY hKey);
	void __fastcall Init(HCRYPTPROV hCryptProv, TMemoryStream* Stream);
	void __fastcall Init(HCRYPTPROV hCryptProv, TMemoryStream* Stream, bool Private);

public:
   __property HCRYPTKEY KeyHandle = {read=FKeyHandle};
   __property int ByteLength = {read=FByteLength};

public:
	__fastcall TRSAKey(HCRYPTPROV hCryptProv, ALG_ID AlgID, DWORD Length); //generate
	__fastcall TRSAKey(HCRYPTPROV hCryptProv, TMemoryStream* Stream, bool Private=false);
	__fastcall TRSAKey(HCRYPTPROV hCryptProv, AnsiString ResourceName, bool Private=false);
	__fastcall ~TRSAKey();

	void __fastcall ExportPublic(TMemoryStream* Stream);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TRSA
//---------------------------------------------------------------------------
class TRSA
{
protected:
	HCRYPTPROV hCryptProv;
	TRSAKey* ClientKey;
	TRSAKey* ServerKey;
	TRSAKey* ClientSignKey;
	TRSAKey* ServerSignKey;

public:
	__fastcall TRSA();
	__fastcall ~TRSA();

	void __fastcall Encrypt(TMemoryStream* Stream);
	void __fastcall Decrypt(TMemoryStream* Stream);
	void __fastcall Sign(TMemoryStream* Message, TMemoryStream* Signature);
	void __fastcall Verify(TMemoryStream* Message, TMemoryStream* Signature);

	void __fastcall JoinMessage(TMemoryStream* Message, TMemoryStream* Signature,
		TMemoryStream* Pack);
	void __fastcall SplitMessage(TMemoryStream* Message, TMemoryStream* Signature,
		TMemoryStream* Pack);

	void __fastcall ExportClientSignKey(TMemoryStream* Stream);
	void __fastcall ImportServerSignKey(TMemoryStream* Stream);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// ERSAError (fatal)
//---------------------------------------------------------------------------
class ERSAError : public EWinAPIError
{
public:
	__fastcall ERSAError(UnicodeString Msg, UnicodeString FailedOperation=L"")
		:EWinAPIError(Msg, FailedOperation) {};
	__fastcall ERSAError(DWORD ErrorCode, UnicodeString FailedOperation=L"")
		:EWinAPIError(ErrorCode, FailedOperation) {};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// ERSAException (non-fatal)
//---------------------------------------------------------------------------
class ERSAException : public Exception
{
public:
	__fastcall ERSAException(UnicodeString Msg)	: Exception(Msg) {};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
