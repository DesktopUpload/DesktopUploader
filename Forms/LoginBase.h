/*---------------------------------------------------------------------------
$Id: LoginBase.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef LoginBaseH
#define LoginBaseH
//----------------------------------------------------------------------------
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include "Header.h"
#include "HeaderBase.h"
//----------------------------------------------------------------------------
class TLoginFormBase : public TForm
{
__published:
	TLabel *lblProgress;
	TLabel *lblPassword;
	TLabel *lblUsername;
	TButton *btnCancel;
	TButton *btnOK;
	TLinkLabel *lnkSignup;
	TLinkLabel *lnkForgot;
	TCheckBox *chkRemember;
	TEdit *edtPassword;
	TEdit *edtUsername;
	THeaderFrame *Header;
	TComboBox *cmbDomain;
	TLabel *lblDomain;
	void __fastcall lnkForgotOnLinkClick(TObject *Sender, const UnicodeString Link,
          TSysLinkType LinkType);
	void __fastcall lnkSignupOnLinkClick(TObject *Sender, const UnicodeString Link,
		  TSysLinkType LinkType);
	void __fastcall btnOKClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall HeaderlblVersionClick(TObject *Sender);
protected:
	// Handles window creation w/o main form
	void __fastcall CreateParams(Controls::TCreateParams &Params);
public:
	virtual __fastcall TLoginFormBase(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TLoginFormBase *LoginFormBase;
//----------------------------------------------------------------------------
#endif
