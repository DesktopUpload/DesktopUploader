/*---------------------------------------------------------------------------
$Id: UploadProps.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <StrUtils.hpp>

#include "Custom/Custom.h"
#include "MUI.h"
#include "TFramework.h"
#include "SrvAdapter.h"

#pragma hdrstop

#include "UploadProps.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TGroupTitle"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
extern TFramework* Framework;
extern TSrvAdapterModule* SrvAdapterModule;

//TUploadProperties *UploadProperties;

#define INISECTION L"Upload Properties"

//---------------------------------------------------------------------------
__fastcall TUploadProperties::TUploadProperties(TComponent* Owner)
	: TFrame(Owner)
{
	//Can't run w/o active session
	if (!SrvAdapterModule->Authorized) {
		throw Exception("No active session.");
	}

	this->MaxCategories = SrvAdapterModule->Session->Settings->MaxCategories;
	this->SingleCategoryMode = this->MaxCategories==1;

	//Adjust editor look for SingleCategoryMode
	if (this->SingleCategoryMode) {
		this->lblCategories->Caption = L"Channel:";
		this->clbCategories->Visible = false;
		this->cbxCategory->Visible = true;
	}

	this->CategoryIDs = new TStringList;
	this->Title->Init();
	this->FMediaType = mtNone;

	this->rgpBroadcast->ItemIndex = Framework->IniFile->ReadInteger(INISECTION, L"Broadcast",0);
}
//---------------------------------------------------------------------------

__fastcall TUploadProperties::~TUploadProperties()
{
	delete this->CategoryIDs;
}
//---------------------------------------------------------------------------

void __fastcall TUploadProperties::Init(TMediaType MediaType, bool Ini)
{
	this->clbCategories->Clear();
	this->CategoryIDs->Clear();

	TSrvMediaSettings* media = SrvAdapterModule->Session->Settings->Media[MediaType];
	if (media) {
		TCollection* cats = media->Categories;
		for (int i = 0; i < cats->Count; i++) {
			TSrvCategory* c = (TSrvCategory*) cats->Items[i];
			this->CategoryIDs->Add(c->ID);

			if (!this->SingleCategoryMode) {
				this->clbCategories->Items->Add(c->Label);
			}
			else {
				this->cbxCategory->Items->Add(c->Label);
            }
		}
	}

	this->FMediaType = media? MediaType : mtNone;

	//Read INI settings
	if (Ini) {
		UnicodeString cats = Framework->IniFile->ReadString(INISECTION,
			MediaTypeToStr(this->FMediaType) + L"-Categories", L"");;
		for (int i = 0; i < this->CategoryIDs->Count; i++) {
			if (ContainsStr(cats, L"(" + this->CategoryIDs->Strings[i] + L")")) {
				if (!this->SingleCategoryMode) {
					this->clbCategories->Checked[i] = true;
				}
				else {
					this->cbxCategory->ItemIndex = i;
					break;
				}
			}
		}
	}

	// Auto select if there is only single category
	if (this->CategoryIDs->Count==1) {
    	if (!this->SingleCategoryMode) {
			this->clbCategories->Checked[0] = true;
			this->clbCategories->Enabled = false;
		}
		else {
			this->cbxCategory->ItemIndex = 0;
			this->cbxCategory->Enabled = false;
		}
		this->lblCategories->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TUploadProperties::Save(TMediaItem* MI)
{
	MI->Broadcast = rgpBroadcast->ItemIndex;

	MI->Categories->Clear();
	if (!this->SingleCategoryMode) {
		for (int i = 0; i < clbCategories->Count; i++) {
			if (this->clbCategories->Checked[i]) {
				MI->Categories->Add(this->CategoryIDs->Strings[i]);
			}
		}
	}
	else {
		MI->Categories->Add(this->CategoryIDs->Strings[this->cbxCategory->ItemIndex]);
	}

}
//---------------------------------------------------------------------------

void __fastcall TUploadProperties::Restore(TMediaItem* MI)
{
	this->Init(MI->MediaType, false);

	this->rgpBroadcast->ItemIndex = MI->Broadcast;

	for (int i = 0; i < MI->Categories->Count; i++) {
		int index = this->CategoryIDs->IndexOf(MI->Categories->Strings[i]);
		if (index >= 0) {
			if (!this->SingleCategoryMode) {
				this->clbCategories->Checked[index] = true;
			}
			else {
				this->cbxCategory->ItemIndex = index;
				break;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TUploadProperties::SaveToIni()
{
	UnicodeString cats;
	if (!this->SingleCategoryMode) {
		for (int i = 0; i < this->CategoryIDs->Count; i++) {
			if (this->clbCategories->Checked[i]) {
				cats += L"(" + this->CategoryIDs->Strings[i] + L")";
			}
		}
	}
	else {
		cats += L"(" + this->CategoryIDs->Strings[this->cbxCategory->ItemIndex] + L")";
    }

	Framework->IniFile->WriteString(INISECTION,
		MediaTypeToStr(this->FMediaType) + L"-Categories", cats);

	Framework->IniFile->WriteInteger(INISECTION, L"Broadcast", rgpBroadcast->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TUploadProperties::CheckCategories()
{
	UnicodeString msg;

	if (this->SingleCategoryMode) {
		if (this->cbxCategory->ItemIndex < 0) {
			msg = LoadStr(LANG_NOCATEGORY);
		}
	}
	else {
		int iCat = 0;
		for (int i = 0; i < this->clbCategories->Count; i++) {
			if (this->clbCategories->Checked[i]) iCat++;
		}
		if (iCat < 1) {
			msg = LoadStr(LANG_NOCATEGORY);
		}

		if(this->MaxCategories > 0 && iCat > this->MaxCategories) {
			msg = UnicodeString(L"Maximum count of channels (") + IntToStr(this->MaxCategories)
			+ UnicodeString(L") exceeded.");
		}
	}

	if (!msg.IsEmpty()) {
        throw msg;
	}
}
//---------------------------------------------------------------------------

TWinControl* __fastcall TUploadProperties::GetCategoryControl()
{
	if (!this->SingleCategoryMode) return this->clbCategories;
	else return this->cbxCategory;
}
//---------------------------------------------------------------------------

