/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#include <vcl.h>
#pragma hdrstop

#include "HTTPAuth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "HTTPAuthBase"
#pragma resource "*.dfm"
THTTPAuthForm *HTTPAuthForm;
//---------------------------------------------------------------------------

__fastcall THTTPAuthForm::THTTPAuthForm(TComponent* AOwner,
		UnicodeString Server, UnicodeString Realm, UnicodeString Username,
		UnicodeString Password)
	: THTTPAuthFormBase(AOwner, Server, Realm, Username, Password)
{
}
//---------------------------------------------------------------------------
