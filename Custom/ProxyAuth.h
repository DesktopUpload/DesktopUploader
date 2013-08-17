/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#ifndef ProxyAuthH
#define ProxyAuthH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ProxyAuthBase.h"
//---------------------------------------------------------------------------
class TProxyAuthForm : public TProxyAuthFormBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TProxyAuthForm(TComponent* AOwner,
		UnicodeString Server, UnicodeString Port=L"", UnicodeString Username=L"",
		UnicodeString Password=L"");
};
//---------------------------------------------------------------------------
extern PACKAGE TProxyAuthForm *ProxyAuthForm;
//---------------------------------------------------------------------------
#endif
