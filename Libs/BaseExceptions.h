/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#ifndef BaseExceptionsH
#define BaseExceptionsH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// EWinAPIError
//---------------------------------------------------------------------------
class EWinAPIError : public Exception
{
	public:
		__fastcall EWinAPIError(UnicodeString Msg, UnicodeString FailedOperation=L"");
		__fastcall EWinAPIError(DWORD ErrorCode, UnicodeString FailedOperation=L"");

		UnicodeString FailedOperation;
};

//---------------------------------------------------------------------------
#endif
