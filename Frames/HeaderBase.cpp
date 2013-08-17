/*---------------------------------------------------------------------------
$Id: HeaderBase.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include "Custom/Custom.h"
#include "Product.h"
#include "TFramework.h"
#pragma hdrstop

extern TFramework* Framework;

#include "HeaderBase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THeaderFrameBase *HeaderFrameBase;
//---------------------------------------------------------------------------

__fastcall THeaderFrameBase::THeaderFrameBase(TComponent* Owner)
	: TFrame(Owner)
{
	this->lblVersion->Caption = UnicodeString(L"Desktop Uploader ") + PRODUCT_VERSION
		+ L" (Build: " + VER_BUILD + L")";
}
//---------------------------------------------------------------------------

void __fastcall THeaderFrameBase::imgLogoClick(TObject *Sender)
{
	Framework->BrowseURL(CUSTOM_SITE_URL);
}
//---------------------------------------------------------------------------

