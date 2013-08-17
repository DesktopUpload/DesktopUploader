/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#ifndef HTTPAuthH
#define HTTPAuthH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "HTTPAuthBase.h"
//---------------------------------------------------------------------------
class THTTPAuthForm : public THTTPAuthFormBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall THTTPAuthForm(TComponent* AOwner,
		UnicodeString Server, UnicodeString Realm=L"", UnicodeString Username=L"",
		UnicodeString Password=L"");
};
//---------------------------------------------------------------------------
extern PACKAGE THTTPAuthForm *HTTPAuthForm;
//---------------------------------------------------------------------------
#endif
