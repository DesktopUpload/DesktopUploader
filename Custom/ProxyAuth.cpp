/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#include <vcl.h>
#pragma hdrstop

#include "ProxyAuth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ProxyAuthBase"
#pragma resource "*.dfm"
TProxyAuthForm *ProxyAuthForm;
//---------------------------------------------------------------------------

__fastcall TProxyAuthForm::TProxyAuthForm(TComponent* AOwner,
		UnicodeString Server, UnicodeString Port, UnicodeString Username,
		UnicodeString Password)
	: TProxyAuthFormBase(AOwner, Server, Port, Username, Password)
{
}
//---------------------------------------------------------------------------
