/*---------------------------------------------------------------------------
$Id: LoginBase.cpp 397 2010-01-30 22:11:20Z fwhite $
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

#include "HTTPAuthBase.h"
//---------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Header"
#pragma link "HeaderBase"
#pragma resource "*.dfm"
THTTPAuthFormBase *HTTPAuthFormBase;
//---------------------------------------------------------------------

__fastcall THTTPAuthFormBase::THTTPAuthFormBase(TComponent* AOwner,
	UnicodeString Server, UnicodeString Realm, UnicodeString Username,
	UnicodeString Password)
	: TForm(AOwner)
{
	UnicodeString notice;
	notice = L"The server " + Server + L" ";
	if (!Realm.IsEmpty()) {
		notice += L"at " + Realm + " ";
	}
	notice += "requires username and password.";

	this->lblNotice->Caption = notice;

	this->edtUsername->Text = Username;
	this->edtPassword->Text = Password;
}
//---------------------------------------------------------------------

void __fastcall THTTPAuthFormBase::OKBtnClick(TObject *Sender)
{
	this->ModalResult = mrOk;
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall THTTPAuthFormBase::CancelBtnClick(TObject *Sender)
{
	this->ModalResult = mrCancel;
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall THTTPAuthFormBase::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (this->ModalResult == mrOk) {
		this->Username = this->edtUsername->Text;
		this->Password = this->edtPassword->Text;
	}
}
//---------------------------------------------------------------------------

