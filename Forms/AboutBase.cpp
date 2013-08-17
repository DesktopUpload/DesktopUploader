/*---------------------------------------------------------------------------
$Id: AboutBase.cpp 425 2010-02-19 05:48:55Z fwhite $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include "TFramework.h"
#pragma hdrstop

extern TFramework* Framework;

#include "AboutBase.h"
//--------------------------------------------------------------------- 
#pragma link "Header"
#pragma link "HeaderBase"
#pragma resource "*.dfm"
//TAboutBoxBase *AboutBoxBase;
//--------------------------------------------------------------------- 
__fastcall TAboutBoxBase::TAboutBoxBase(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TAboutBoxBase::FormShow(TObject *Sender)
{
	this->lblProduct->Caption = UnicodeString(CUSTOM_PRODUCT_NAME) + L" " + PRODUCT_VERSION
		+ L" (Build: " + VER_BUILD + L")";
	this->lblCopyright->Caption = PRODUCT_COPYRIGHT;
	this->lblComments->Caption = UnicodeString(L"Original Developer:  ") + PRODUCT_ORIGINAL_DEVELOPER;
	this->lnkWeb->Caption = UnicodeString(L"Web:  <a>") + PRODUCT_SITE_NAME + L"</a>";

	this->lblLicense->Caption = UnicodeString(L"Licensed to:  ") + CUSTOM_DOMAIN;
}
//---------------------------------------------------------------------------


void __fastcall TAboutBoxBase::lnkWebLinkClick(TObject *Sender, const UnicodeString Link,
          TSysLinkType LinkType)
{
	Framework->BrowseURL(PRODUCT_SITE_URL);
}
//---------------------------------------------------------------------------

