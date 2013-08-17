/*---------------------------------------------------------------------------
$Id: YoutubeGrabBase.cpp 466 2010-04-04 14:00:27Z anton $
---------------------------------------------------------------------------*/
#include "Custom/Custom.h"
#ifdef CUSTOM_YOUTUBE

#include <vcl.h>
#include <Math.hpp>

#include "Custom/Main.h"
#include "TFramework.h"
#include "Utils.h"

#pragma hdrstop

#include "SrvAdapter.h"

#include "YoutubeGrabBase.h"
//---------------------------------------------------------------------
#pragma link "UploadProps"
#pragma link "TProgressPanel"
#pragma link "TProgressPanel"
#pragma link "UploadProps"
#pragma link "TProgressPanel"
#pragma link "UploadProps"
#pragma resource "*.dfm"
extern TFramework* Framework;
extern TMainForm *MainForm;

//--------------------------------------------------------------------- 
__fastcall TYoutubeGrabFormBase::TYoutubeGrabFormBase(TComponent* AOwner)
	: TForm(AOwner)
{
	this->Busy = false;
}
//---------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::FormCreate(TObject *Sender)
{
	this->Constraints->MinWidth = this->Width;
	this->Constraints->MinHeight = this->Height;

	this->pnlProgress->Visible = false;

	Framework->RestoreFormPosition(this);

	TSrvSettings* settings = SrvAdapterModule->Session->Settings;

	for (int i = 0; i < settings->Video->YouTubeFormats->Count ; i++) {
		TYouTubeFormat* yf = (TYouTubeFormat*) settings->Video->YouTubeFormats->Objects[i];
		this->cmbQuality->Items->Add(yf->Label);
	}

	this->UploadProperties->Init(mtVideo);
	if (settings->AllowTorrents == srtoRequire) {
		this->chkAutoUpload->Visible = false;
		this->pnlYouTube->Height = this->UploadProperties->Height;
	}
	else {
		this->chkAutoUpload->Checked = Framework->IniFile->ReadBool(this->Name, L"AutoUpload", false);
	}

	bool methods = settings->Video->AllowYTDownload && settings->Video->AllowYTEmbed;
	if (methods) {
		this->cmbGrabbingMethod->ItemIndex = Framework->IniFile->ReadInteger(this->Name, L"GrabbingMethod", CFG_DEFAULT_YTGRABMETHOD);
	}
	else {
		this->lblGrabbingMethod->Enabled = false;
		this->lblGrabbingMethod->Tag = 1;
		this->cmbGrabbingMethod->Enabled = false;
		this->cmbGrabbingMethod->Tag = 1;


		this->cmbGrabbingMethod->ItemIndex = settings->Video->AllowYTDownload? 0 : 1;
	}
	this->cmbGrabbingMethodCloseUp(NULL);

	int index = Framework->IniFile->ReadInteger(this->Name, L"Quality", 0);
	if (index >=0 && index < this->cmbQuality->Items->Count) {
		this->cmbQuality->ItemIndex = index;
	}
	else {
		this->cmbQuality->ItemIndex = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::FormClose(TObject *Sender, TCloseAction &Action)
{
	Framework->SaveFormPosition(this);

	if (ModalResult == mrOk) {
		this->UploadProperties->SaveToIni();
	}
}
//---------------------------------------------------------------------------

TStringList* __fastcall TYoutubeGrabFormBase::PrepareLinks()
{
	TStringList* result = NULL;
	try {
		//Check categories
		try {
			this->UploadProperties->CheckCategories();
		} catch (UnicodeString msg) {
        	this->UploadProperties->GetCategoryControl()->SetFocus();
			throw msg;
		}

		//Remove empty lines and trim
		UnicodeString link;
		int pos = 0;
		for (int i = 0; i < this->memLinks->Lines->Count; i++) {
			link = this->memLinks->Lines->Strings[i].Trim();
			if (link.IsEmpty()) {
				this->memLinks->Lines->Delete(i);
				i--; continue;
			}
			this->memLinks->Lines->Strings[i] = link;
		}
		//Check if no links
		if (this->memLinks->Lines->Count == 0) {
			this->memLinks->SetFocus();
			throw UnicodeString(L"Please provide YouTube links.");
		}

		//Extract IDs
		UnicodeString id;
		result = new TStringList;
		for (int i = 0; i < this->memLinks->Lines->Count; i++) {
			link = this->memLinks->Lines->Strings[i];

			id = YT_ExpractID(link);
			if (id.IsEmpty()) {
				UnicodeString msg = L"Invalid YouTube link \"" \
				+ link + L"\".\r\n" \
				+ L"No YouTube video ID found.";

				this->memLinks->SetFocus();
				this->memLinks->SelStart = pos;
				this->memLinks->SelLength = memLinks->Lines->Strings[i].Length();
				throw msg;
			}
			result->Add(id);

			pos += link.Length()+2;
		}
	}
	catch (UnicodeString msg) {
		Framework->ShowErrorMessage(msg, this->Caption, true);
		delete result;
		return NULL;
	}

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TYoutubeGrabFormBase::GrabDownload()
{
	TYouTubeFormat* yf =
		(TYouTubeFormat*)SrvAdapterModule->Session->Settings->Video->YouTubeFormats->Objects[this->cmbQuality->ItemIndex];
	int quality = yf->QualityLevel;

	TStringList* ids = PrepareLinks();
	if (!ids) return false;

	const int itemcount = ids->Count;
	__int64* sizes = new __int64[itemcount];
	UnicodeString* links = new UnicodeString[itemcount];
	TStrings* lines = this->memLinks->Lines;

	TProgressPanel* p = this->pnlProgress;

	bool result = false;
	try {
		//Get clip sizes
		__int64 total_size=0;

		p->Title = L"Downloading Clips";
		p->CompletedText = L"Downloaded";

		p->EnableETA = ETA_NONE;
		p->EnableSpeed = false;
		p->EnableSkip = false;

		this->Progress();

		p->TotalWork = 1; //dummy value

		p->StartOperation(L"Querying download sizes:");

		int sel_start = 0;
		for (int i = 0; i < itemcount && Busy; i++) {
			this->memLinks->SelStart = sel_start;
			this->memLinks->SelLength = lines->Strings[i].Length();

			UnicodeString link = lines->Strings[i];
			links[i] = link;

			p->SubOperation = link;
			p->UpdateProgress(false);

			__int64 size = SrvAdapterModule->YT_GetFileSize(ids->Strings[i], quality);
			if (size < 0) Abort();

			total_size += size;
			sizes[i] = size;

			p->CompleteRatio = ((float)i+1.0)/(float)itemcount;
			p->UpdateProgress(false);

			sel_start += lines->Strings[i].Length()+2;
		}
		SrvAdapterModule->Disconnect();

		//Download clips
		UnicodeString operation = itemcount==1 ? \
			L"Downloading clip: %2:s" : L"Downloading clip %0:s of %1:s: %2:s";

		p->TotalWork = total_size;
		p->TotalBytes = total_size;
		p->SubOperation = L"";

		int current_line = 0;
		sel_start=0;

		result = true;
		for (int i = 0; i < itemcount && Busy; i++) {
			this->memLinks->SelStart = sel_start;
			this->memLinks->SelLength = lines->Strings[current_line].Length();

			__int64 size = sizes[i];
			UnicodeString link = links[i];
			p->EnableSkip = i < itemcount-1;
			p->StartOperation(Format(operation,
				ARRAYOFCONST((UnicodeString(i+1), UnicodeString(itemcount), link))),
				size);

			TMediaItem* mi = new TMediaItem(mtVideo);
			this->UploadProperties->Save(mi);

			result = SrvAdapterModule->YT_Download(mi, ids->Strings[i], quality);
			if (!result) {
				delete mi;

				if (p->Terminated == pptSkip) {
					sel_start += lines->Strings[current_line].Length()+2;
					current_line++;
					p->TotalWork -= size;
					p->TotalBytes -= size;
					p->EnableETA = ETA_NONE;
					p->EnableSpeed = false;
					continue;
				}
				else {
					this->Progress(false);
					this->memLinks->SelStart = sel_start;
					this->memLinks->SelLength = lines->Strings[current_line].Length();
					this->memLinks->SetFocus();
					break;
				}
			}
			mi->MediaLocation = link;

			this->memLinks->Lines->Delete(current_line);
			MainForm->AddMediaItem(mi);

			p->CommittedWork += size;
			p->CommittedBytes += size;
		}
	}
	catch (EAbort&) {
		_asm nop;
	}

	this->Progress(false);

	delete ids;
	delete [] sizes;
	delete [] links;

	if (result) {
		this->AutoUpload = this->chkAutoUpload->Checked;

		//Save settings
		this->SaveSettings();
		Framework->IniFile->WriteInteger(this->Name, L"Quality", this->cmbQuality->ItemIndex);
	}

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TYoutubeGrabFormBase::GrabEmbed()
{
	TStringList* ids = PrepareLinks();
	if (!ids) return false;

	const int itemcount = ids->Count;
	UnicodeString* links = new UnicodeString[itemcount];
	TStrings* lines = this->memLinks->Lines;

	for (int i = 0; i < itemcount; i++) {
		links[i] = lines->Strings[i];
	}

	TProgressPanel* p = this->pnlProgress;

	bool result = false;
	try {
		p->Title = L"Retrieving Video Information";
		p->CompletedText = L"Completed";

		p->EnableETA = ETA_ALL;
		p->EnableSpeed = false;
		p->EnableSkip = false;

		this->Progress();

		p->TotalWork = itemcount;

		UnicodeString operation = itemcount==1 ? \
			L"Retrieving clip: %2:s" : L"Retrieving clip %0:s of %1:s: %2:s";

		int current_line = 0;
		int sel_start=0;

		result = true;
		for (int i = 0; i < itemcount && Busy; i++) {
			this->memLinks->SelStart = sel_start;
			this->memLinks->SelLength = lines->Strings[current_line].Length();

			UnicodeString link = links[i];
			p->EnableSkip = i < itemcount-1;
			p->StartOperation(Format(operation,
				ARRAYOFCONST((UnicodeString(i+1), UnicodeString(itemcount), link))));

			TMediaItem* mi = new TMediaItem(mtVideo);
			this->UploadProperties->Save(mi);

			result = SrvAdapterModule->YT_Embed(mi, ids->Strings[i]);
			if (!result) {
				delete mi;

				if (p->Terminated == pptSkip) {
					sel_start += lines->Strings[current_line].Length()+2;
					current_line++;
					p->TotalWork -= 1;
					p->EnableETA = ETA_NONE;
					p->EnableSpeed = false;
					continue;
				}
				else {
					this->Progress(false);
					this->memLinks->SelStart = sel_start;
					this->memLinks->SelLength = lines->Strings[current_line].Length();
					this->memLinks->SetFocus();
					break;
				}
			}
			mi->MediaLocation = link;

			this->memLinks->Lines->Delete(current_line);
			MainForm->AddMediaItem(mi);

			p->CommittedWork += 1;
		}
	}
	catch (EAbort&) {
		_asm nop;
	}

	this->Progress(false);

	delete ids;
	delete [] links;

	if (result) {
		this->AutoUpload = this->chkAutoUpload->Checked;
		//Save settings
		this->SaveSettings();
    }

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::SaveSettings()
{
	if (this->chkAutoUpload->Visible)
		Framework->IniFile->WriteBool(this->Name, L"AutoUpload", this->chkAutoUpload->Checked);
	if (this->cmbGrabbingMethod->Enabled)
		Framework->IniFile->WriteInteger(this->Name, L"GrabbingMethod", this->cmbGrabbingMethod->ItemIndex);

}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::Progress(bool Start)
{
	LockWindowUpdate(this->Handle);

	this->Busy = Start;
	PrepareContainerToProgress(this, Start, false);

	this->pnlProgress->Visible = Start;
	this->pnlButtons->Visible = !Start;

	this->pnlProgress->Active = Start;

	this->ProgressTimer->Enabled = Start;

	LockWindowUpdate(NULL);

	this->Update();
}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::OnProgress()
{
	if (!this->Busy) return;

	TProgressPanel* p = this->pnlProgress;

	bool speed = false;
	if (SrvAdapterModule->Progress) {
		TProgressMeter* pm = SrvAdapterModule->Progress;
		float val = pm->Value;
		if (val >= 0.00) {
			p->CompleteRatio = val;

			if (pm->Mode == pmmMain && pm->LastCount >= 0) {
				p->CurrentBytes = pm->TotalCount;
				p->CompletedBytes = pm->LastCount;
				speed = true;
				p->EnableETA = ETA_ALL;
			}
		}

		p->SubOperation = pm->SubOperation;
	}

    p->EnableSpeed = speed;

	p->UpdateProgress();
}
//---------------------------------------------------------------------------

int __fastcall TYoutubeGrabFormBase::OnMove(TMessage &Msg)
{   //VCL does not handle winodow movement
	Framework->SaveFormPosition(this);
	return 1; //enable default processing
}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::btnOKClick(TObject *Sender)
{
	bool result = this->cmbGrabbingMethod->ItemIndex == 0?
		this->GrabDownload() : this->GrabEmbed();

	if (result) {
		this->ModalResult = mrOk;
		this->Hide();
    }
}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::ProgressTimerTimer(TObject *Sender)
{
	this->OnProgress();
}
//---------------------------------------------------------------------------

void __fastcall TYoutubeGrabFormBase::cmbGrabbingMethodCloseUp(TObject *Sender)
{
	bool quality = this->cmbGrabbingMethod->ItemIndex == 0;
	this->lblQuality->Visible = quality;
	this->cmbQuality->Visible = quality;
}
//---------------------------------------------------------------------------

#endif

