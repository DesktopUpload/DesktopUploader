/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#pragma hdrstop

#include "BaseExceptions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// EWinAPIError
//---------------------------------------------------------------------------
__fastcall EWinAPIError::EWinAPIError(UnicodeString Msg,
	UnicodeString FailedOperation)
	: Exception(Msg)
{
	this->FailedOperation = FailedOperation;
}
//---------------------------------------------------------------------------

__fastcall EWinAPIError::EWinAPIError(DWORD ErrorCode,
	UnicodeString FailedOperation)
	: Exception(L"")
{
	this->FailedOperation = FailedOperation;

	LPVOID lpMsgBuf;
	//DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		ErrorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );

	this->Message = UnicodeString((const char*) lpMsgBuf).Trim();
}
//---------------------------------------------------------------------------
