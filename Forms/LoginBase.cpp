/*---------------------------------------------------------------------------
$Id: LoginBase.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include "Custom/Custom.h"
#include "Custom/Main.h"
#include "MUI.h"
#include "Utils.h"
#include "TFramework.h"
#include "SrvAdapter.h"
#include "Product.h"
#pragma hdrstop

extern TFramework* Framework;
extern TSrvAdapterModule *SrvAdapterModule;
extern TMainForm *MainForm;

#include "LoginBase.h"
//---------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Header"
#pragma link "HeaderBase"
#pragma resource "*.dfm"
TLoginFormBase *LoginFormBase;
//---------------------------------------------------------------------

__fastcall TLoginFormBase::TLoginFormBase(TComponent* AOwner)
	: TForm(AOwner)
{
	this->cmbDomain->Text = CUSTOM_DOMAIN;
	this->lblUsername->Caption = LoadStr(LANG_USERNAME);

	if (MainForm) {
		MainForm->Hide();
	}
}
//---------------------------------------------------------------------

void __fastcall TLoginFormBase::FormShow(TObject *Sender)
{
	this->Caption = LoadStr(LANG_LOG_ON_TO) + " " + CUSTOM_SITE_CAPTION;

	this->edtUsername->Text = SrvAdapterModule->Username;
	this->edtPassword->Text = SrvAdapterModule->Password;
	this->chkRemember->Checked = SrvAdapterModule->RememberUser;
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::btnOKClick(TObject *Sender)
{
	if (this->edtUsername->Text.IsEmpty()){
		Framework->ShowErrorMessage(LoadStr(LANG_USERNAME_EMPTY), this->Caption, true);
		return;
	}
	if (this->edtPassword->Text.IsEmpty()){
		Framework->ShowErrorMessage(LoadStr(LANG_PASSWORD_EMPTY), this->Caption, true);
		return;
	}

	this->Header->lblVersion->Cursor = crDefault;
	PrepareContainerToProgress(this);
		int result = SrvAdapterModule->Login(
			this->edtUsername->Text, this->edtPassword->Text, this->chkRemember->Checked);
	PrepareContainerToProgress(this, false);
	this->Header->lblVersion->Cursor = crHelp;

	if (result==0) { //Login OK
		this->ModalResult = mrOk;
		this->Hide();
		if (MainForm) MainForm->Show();
	}
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::btnCancelClick(TObject *Sender)
{
	if (SrvAdapterModule->Busy) {//login in progress
		SrvAdapterModule->Terminate();
	}
	else {
		this->ModalResult = mrCancel;
		this->Hide();
	}
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::lnkForgotOnLinkClick(TObject *Sender, const UnicodeString Link,
          TSysLinkType LinkType)
{
	#ifdef CUSTOM_AUTH_URL
		Framework->BrowseURL(UnicodeString(CUSTOM_AUTH_URL) + CUSTOM_PAGE_FORGOT);
	#else
		Framework->BrowseURL(UnicodeString(CUSTOM_SITE_URL) + CUSTOM_PAGE_FORGOT);
	#endif
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::lnkSignupOnLinkClick(TObject *Sender, const UnicodeString Link,
          TSysLinkType LinkType)
{
	#ifdef CUSTOM_AUTH_URL
		Framework->BrowseURL(UnicodeString(CUSTOM_AUTH_URL) + CUSTOM_PAGE_SIGNUP);
	#else
		Framework->BrowseURL(UnicodeString(CUSTOM_SITE_URL) + CUSTOM_PAGE_SIGNUP);
	#endif
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (this->ModalResult != mrOk) {
		if (SrvAdapterModule->Busy) {//login in progress
			SrvAdapterModule->Terminate();
        }
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::CreateParams(Controls::TCreateParams &Params)
{
	// Handles window creation w/o main form
	TForm::CreateParams(Params);
	this->BorderStyle = bsSingle;
	Params.ExStyle   = Params.ExStyle | WS_EX_APPWINDOW;
	Params.WndParent = GetDesktopWindow();
}
//---------------------------------------------------------------------------

void __fastcall TLoginFormBase::HeaderlblVersionClick(TObject *Sender)
{
	if (SrvAdapterModule->Busy) return;

	TAboutBox* Dlg = new TAboutBox(this);
	Dlg->ShowModal();

	delete Dlg;
}
//---------------------------------------------------------------------------

