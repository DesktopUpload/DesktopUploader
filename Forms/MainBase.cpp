/*---------------------------------------------------------------------------
$Id: MainBase.cpp 513 2010-11-11 16:13:02Z fwhite $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <StrUtils.hpp>
#include <Math.hpp>

#include "Custom/Custom.h"
#include "MUI.h"
#include "TFramework.h"
#include "SrvAdapter.h"
#include "Utils.h"

#pragma hdrstop

#include "MainBase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TProgressPanel"
#pragma link "TProgressPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
extern TFramework* Framework;
extern TSrvAdapterModule* SrvAdapterModule;
//---------------------------------------------------------------------------

//Maximium number of media items missing information to display in warning message box:
#define MAX_MISSING_ITEMS 3

//TMainFormBase *MainFormBase;
//---------------------------------------------------------------------------
// Initialization
//---------------------------------------------------------------------------
__fastcall TMainFormBase::TMainFormBase(TComponent* Owner)
	: TForm(Owner)
{
	this->Busy = false;
	this->Closing = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::FormCreate(TObject *Sender)
{
	//Restore size & position
	this->Constraints->MinHeight = this->Height;
	this->Constraints->MinWidth = this->Width;
	Framework->RestoreFormPosition(this);
	Framework->RestoreListViewColWidths(this->lvQueue, this->Name);

	//Customize form captions
	this->Caption = CUSTOM_PRODUCT_NAME;
	this->lblVersion->Caption = UnicodeString(L"Desktop Uploader ") + PRODUCT_VERSION
		+ L" (Build: " + VER_BUILD + L")";

	//Init
	this->lblTotalSize->Caption = L"";
	this->lblMaxFileSize->Caption = L"";
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::FormShow(TObject *Sender)
{
	this->lblUserLeftAvatar = this->lblUser->Left;
	#ifdef CUSTOM_UI_LBLUSER_LEFT_NO_AVATAR
		this->lblUserLeftNoAvatar = CUSTOM_UI_LBLUSER_LEFT_NO_AVATAR;
	#else
		this->lblUserLeftNoAvatar = this->imgAvatar->Left;
	#endif

	this->UpdateUI();
	this->OnLogin();
	this->ShowProgress(false);
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::FormActivate(TObject *Sender)
{
	if (!Framework->FileToAdd.IsEmpty()) {
		UnicodeString file = Framework->FileToAdd;
		Framework->FileToAdd = L"";
		this->AddMedia(file);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->Hide();
	SrvAdapterModule->Logout(false);
	Framework->SaveFormPosition(this);

	//Clear MI objects for remaining items
	for (int i = 0; i < this->lvQueue->Items->Count; i++) {
		delete (TMediaItem*)this->lvQueue->Items->Item[i]->Data;
	}
	Framework->SaveListViewColWidths(this->lvQueue, this->Name);
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (this->Busy) {
		CanClose = false;
		if (Framework->ShowMessageBox(L"Upload in progress. Are you sure you want to terminate the operation and exit?", L"", \
			MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON2) == IDYES) {

			SrvAdapterModule->Terminate();
			this->Closing = true;
        }
	}
}
//---------------------------------------------------------------------------
// Actions
//---------------------------------------------------------------------------
bool __fastcall TMainFormBase::AddMedia(UnicodeString FileName)
{
	TMediaItem* mi = new TMediaItem(mtNone);
	mi->MediaLocation = FileName;

	TVideoEditorForm* dlg = NULL;
	try {
		dlg = new TVideoEditorForm(this, mi);
	}
	catch (EMediaEditorException& e) {
		delete mi;
		return false;
	}

	bool result = dlg->ModalResult == mrOk;

	if (result) {
		mi = dlg->MediaItem;
		dlg->MediaItem = NULL;
		this->AddMediaItem(mi);

		this->lvQueue->ItemIndex = lvQueue->Items->Count-1;
		this->UpdateUI();
	}
	else {
		delete mi;
	}
	delete dlg;

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::RemoveMedia(int Index)
{
	if (Index < 0) {
		Index = this->lvQueue->ItemIndex;
	}
	if (Index >= 0) {

		TMediaItem* mi = (TMediaItem*)this->lvQueue->Items->Item[Index]->Data;
		delete mi;
		this->lvQueue->Items->Delete(Index);
		Index--;
		if (Index<0 && this->lvQueue->Items->Count>0) Index = 0;
		this->lvQueue->ItemIndex = Index;
		if (!this->Busy) {
			this->UpdateUI();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::EditMedia()
{
	int index = this->lvQueue->ItemIndex;
	if (index < 0) return;

	TMediaItem* mi = this->GetMediaItem(index);

	TVideoEditorForm* dlg = new TVideoEditorForm( this, mi, true);
	if (dlg->ModalResult == mrOk) {
		this->UpdateMediaItem(index);
		this->UpdateUI();
	}
	delete dlg;
}
//---------------------------------------------------------------------------

#ifdef CUSTOM_YOUTUBE
bool __fastcall TMainFormBase::GrabYouTube()
{
	int itemcount = this->lvQueue->Items->Count;

	TYoutubeGrabForm* dlg = new TYoutubeGrabForm(this);
	dlg->ShowModal();

	bool result = dlg->ModalResult == mrOk;
	bool upload = result && dlg->AutoUpload;
	delete dlg;

	if (result) {
		this->lvQueue->ItemIndex = itemcount;
		this->UpdateUI();
	}

	if (upload) {
		result = this->Upload();
	}

	return result;
}
#endif
//---------------------------------------------------------------------------

bool __fastcall TMainFormBase::Upload()
{
	TProgressPanel* p = this->pnlProgress;

	bool result = false;
	bool need_login = false;

	try {
	//Check for invalid items
		int item_count = 0;
		__int64 total_bytes = 0;
		bool found_valid = false;
		UnicodeString missing_details;
		int missing_count = 0;

		for (int i = 0; i < this->lvQueue->Items->Count; i++) {
			TMediaItem* mi = this->GetMediaItem(i);
			TMediaItemState state = mi->GetState();

			if (state==misInvalid) {
				missing_count++;
				if (missing_count <= MAX_MISSING_ITEMS) {
                	TStringList* fields = mi->GetMissingFields();
						missing_details += L"• Please provide " + StrImplode(fields, L", ")
						+ L" for " + mi->Label + ".\n";
					delete fields;
				}
				else if (missing_count == MAX_MISSING_ITEMS+1) {
					missing_details += L"...\n";
				}
			}
			else {
				found_valid = true;
				if (state==misNotReady) {
					item_count++;
					if (mi->InputData) total_bytes += mi->InputData->Size;
				}
			}
		}
		if (missing_count > 0) {
			if (found_valid) {
				if (Framework->ShowMessageBox(L"Some items are missing required fields. These items will not be uploaded:\n"
					+ missing_details + L"\n"
					+ L"Do you want to continue?",
					L"Missing Information", MB_YESNO|MB_ICONQUESTION) == IDNO)
        		{
					Abort();
				}
			}
			else {
				Framework->ShowMessageBox(L"All items are missing required fields:\n"
					+ missing_details,
					L"Missing Information", MB_ICONWARNING);
				Abort();
            }
		}

		if (item_count > 0) {

		//Convert medias
			//Prepare progress bar
			p->Title = LoadStr(LANG_PREPARING);
			p->CompletedText = LoadStr(LANG_PROCESSED);
			p->EnableSkip = item_count > 1;
			this->Progress();
			this->ShowProgressBytes = false;
			p->EnableETA = ETA_CURRENT;

			p->TotalWork = total_bytes;
			//p->TotalBytes = this->TotalInputSize;

			//Conversion loop
			UnicodeString operation = item_count > 1 ? \
				L"Processing file %0:s of %1:s: %2:s" :
				L"Processing file: %2:s";

			int item_index = 0;
			for (int i = 0; i < this->lvQueue->Items->Count || !this->Busy; i++) {
				TMediaItem* mi = this->GetMediaItem(i);
				if (mi->GetState() != misNotReady) continue;

				this->lvQueue->ItemIndex = i;

				__int64 size = mi->InputData? mi->InputData->Size : 0;
			//this->pnlProgress->EnableSkip = i < itemcount-1;
				p->StartOperation(Format(operation,
					ARRAYOFCONST((UnicodeString(item_index+1), UnicodeString(item_count), mi->Title))),
					size);

				if (!SrvAdapterModule->PrepareMedia(mi)) {
					if (this->pnlProgress->Terminated == pptSkip) {
						p->TotalWork -= p->CurrentWork;
						p->TotalBytes -= p->CurrentBytes;
						continue;
					}
					else Abort();
				}

				this->UpdateMediaItem(i);
				this->OnQueueUpdate();

				p->CommittedWork += p->CurrentWork;
				item_index++;
			}
		}

		//Calcualte upload size & item count
		item_count = 0;
		total_bytes = 0;
		for (int i = 0; i < this->lvQueue->Items->Count; i++) {
			TMediaItem* mi = this->GetMediaItem(i);
			if (mi->GetState()==misReady) {
				item_count++;
				total_bytes += mi->GetUploadSize();
			}
		}
		if (item_count == 0) Abort();

		//Prepare progress panel
		p->Title = LoadStr(LANG_UPLOADING);
		p->CompletedText = LoadStr(LANG_UPLOADED);
		p->EnableSkip = item_count > 1;
		this->Progress();
		this->ShowProgressBytes = true;
		this->Update();

		p->TotalWork = total_bytes;
		p->TotalBytes = total_bytes;

		//UPLOAD loop
		int task_index = 1;
		int item_index = 0;
		UnicodeString operation = (item_count > 1)?
			L"Uploading file %0:s of %1:s: %2:s" :
			L"Uploading file: %2:s";

		//Possible workaroud for slow first upload problem
		SrvAdapterModule->Disconnect();

		bool uploaded = false;
		while (item_index < this->lvQueue->Items->Count && Busy) {
			TMediaItem* mi = this->GetMediaItem(item_index);
			if (!mi->IsReady()) { //not ready
                item_index++;
				continue;
			}

			this->lvQueue->ItemIndex = item_index;

			__int64 size = mi->GetUploadSize();
			p->EnableSkip = item_index < this->lvQueue->Items->Count-1;
			p->StartOperation(Format(operation,
				ARRAYOFCONST((UnicodeString(task_index), IntToStr(item_count), mi->Title))),
				size);
			p->CurrentBytes = size;

			//Upload item:
			int upload_error = SrvAdapterModule->Upload(mi);

			if (upload_error) {
				if (upload_error == SRVADAPTER_ERROR_TERMINATED) {
					if (this->pnlProgress->Terminated == pptSkip) { //skipped
						task_index++;
						item_index++;
						p->TotalWork -= p->CurrentWork;
						p->TotalBytes -= p->CurrentBytes;
						p->EnableETA = ETA_NONE;
						p->EnableSpeed = false;
						continue;
					}
					else Abort();
				}
				else if (upload_error == 202 || upload_error == 203) {
					need_login = true;
                }
				Abort();
			}
			else uploaded = true;

			p->CommittedWork += p->CurrentWork;
			p->CommittedBytes += p->CurrentBytes;
			this->RemoveMedia(item_index);

			task_index++;
		}

		result = uploaded;
	}
	catch (EAbort&) {
		_asm nop;
	}

	this->Progress(false);

	if (this->Closing) {
		this->Close();
		return false;
	}
	else if (result) {
		Framework->ShowMessageBox(L"Upload finished successfully.", L"", MB_ICONINFORMATION);
	}
	else if (need_login) {
		this->Logout(false);
	}
	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TMainFormBase::Login()
{
	TLoginForm* dlg = new TLoginForm(this);
	dlg->ShowModal();

	bool result = dlg->ModalResult == mrOk;
	if (result) {
		this->UpdateUI();
		this->OnLogin();
	}

	delete dlg;
	return result;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::Logout(bool ClearCredentials)
{
	SrvAdapterModule->Logout(ClearCredentials);
	this->UpdateUI();
	this->OnLogin();

	this->Login();
}

//---------------------------------------------------------------------------
// Helpers
//---------------------------------------------------------------------------
void __fastcall TMainFormBase::AddMediaItem(TMediaItem* MI)
{
	TListItem* item = this->lvQueue->Items->Add();

	for (int i = 0; i < this->lvQueue->Columns->Count-1; i++) {
		item->SubItems->Add(L"");
	}
	item->Data = MI;
	this->UpdateMediaItem(item);
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::UpdateMediaItem(int Index)
{
	TListItem* item = this->lvQueue->Items->Item[Index];
	this->UpdateMediaItem(item);
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::UpdateMediaItem(TListItem* Item)
{
	TMediaItem* MI = (TMediaItem*)Item->Data;

	Item->Caption = MI->Title;
	Item->SubItems->Strings[0] = MI->Label;

	UnicodeString size;
	__int64 upload_size = MI->GetUploadSize();
	if (upload_size > 0) {
		size = FormatDataSize(upload_size) + L"/";
	}
	Item->SubItems->Strings[1] = size
		+ ((MI->InputData)? FormatDataSize(MI->InputData->Size) : UnicodeString(L"(none)"));
	Item->ImageIndex = (int)MI->Type;
	Item->StateIndex = (int)MI->GetState();
}
//---------------------------------------------------------------------------

TMediaItem* __fastcall TMainFormBase::GetMediaItem(int Index)
{
	return (TMediaItem*)this->lvQueue->Items->Item[Index]->Data;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::Progress(bool Start)
{
	LockWindowUpdate(this->Handle);

	this->Busy = Start;
	PrepareContainerToProgress(this, Start, false);

	if (!Start) this->UpdateUI();

	this->pnlProgress->Active = Start;
	this->ShowProgress(Start);

	this->ProgressTimer->Enabled = Start;

	this->lblVersion->Cursor = Start? crDefault : crHelp;

	LockWindowUpdate(NULL);

	this->Update();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::OnProgress()
{
	if (!this->Busy) return;

	TProgressPanel* p = this->pnlProgress;

	bool enableSpeed = false;
	if (SrvAdapterModule->Progress) {
		TProgressMeter* pm = SrvAdapterModule->Progress;
		float val = pm->Value;
		if (val >= 0.00) {
			p->CompleteRatio = val;

			if ((pm->Mode==pmmMain) && (pm->LastCount>=0)) {
				if (p->CurrentBytes != pm->TotalCount) {
                	//Reflects additional bytes added in POST package
					p->TotalBytes = p->TotalBytes - p->CurrentBytes + pm->TotalCount;
					p->CurrentBytes = pm->TotalCount;
				}
				p->CompletedBytes = pm->LastCount;
				enableSpeed = true;
				p->EnableETA = ETA_ALL;
			}
		}

		p->SubOperation = pm->SubOperation;
	}

	p->EnableSpeed = enableSpeed;

	p->UpdateProgress();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::ShowProgress(bool Show)
{
	this->pnlProgress->Visible = Show;
	this->pnlMain->Height = Show?
		this->pnlProgress->Top - this->pnlMain->Top
		: this->ClientHeight - this->pnlMain->Top;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::Reactivate()
{
    Application->BringToFront();
	if (this->WindowState == wsMinimized) {
		this->Perform(WM_SYSCOMMAND, SC_RESTORE, 0);
	}
	//this->BringToFront();
}

UnicodeString __fastcall FormatMaxFileSizeVal(__int64 Size)
{
	return Size>0? FormatDataSize(Size) : UnicodeString(L"Unlimited");
}
//---------------------------------------------------------------------------

void __fastcall FormatMaxFileSize (UnicodeString& List, TMediaType MediaType,
	bool MultiMedia)
{
	TSrvMediaSettings* media = SrvAdapterModule->Session->Settings->Media[MediaType];
	if (!media) return;

	if (!List.IsEmpty()) List += L", ";

	if (MultiMedia) {
		List += MediaTypeToStr(MediaType) + L": ";
	}
	List += FormatMaxFileSizeVal(media->MaxFileSize);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Custom events
//---------------------------------------------------------------------------
void __fastcall TMainFormBase::UpdateUI()
{
	bool ready = SrvAdapterModule->Authorized;

	bool have_videos = (this->lvQueue->Items->Count > 0);
	bool video_selected = this->lvQueue->ItemIndex >= 0;

	#ifdef DEMO_QUEUE_LIMIT
		if (this->lvQueue->Items->Count >= DEMO_QUEUE_LIMIT)
		{
			this->btnAdd->Enabled = false;
			#ifdef CUSTOM_YOUTUBE
				this->btnYouTube->Enabled = false;
			#endif
		}
		else
		{
			this->btnAdd->Enabled = ready;
			#ifdef CUSTOM_YOUTUBE
				this->btnYouTube->Enabled = ready;
			#endif
		}
	#else
		this->btnAdd->Enabled = ready;
		this->btnYouTube->Enabled = ready;
	#endif

	this->btnEdit->Enabled 		= ready && video_selected;
	this->btnRemove->Enabled 	= ready && video_selected;
	this->btnUpload->Enabled 	= ready && have_videos;
	this->lvQueue->Enabled 		= ready;

	if (ready) {
		TSrvSettings* s = SrvAdapterModule->Session->Settings;
		#ifdef CUSTOM_YOUTUBE
			this->btnYouTube->Visible = s->Video
				&& (s->Video->AllowYTDownload
				|| s->Video->AllowYTEmbed);
			if(s->ExternalOnly) {
				this->btnAdd->Visible = false;
				this->btnYouTube->Top = this->btnAdd->Top;
				this->btnYouTube->TabOrder = this->btnAdd->TabOrder;
			}
		#endif

		//Max Upload File Size label
		bool multi_media = s->MultiMedia;
		UnicodeString txt = multi_media?
			L"Max Upload File Sizes:\n" :
			L"Max Upload File Size: ";

		UnicodeString list;
		FormatMaxFileSize(list, mtVideo, multi_media);
		FormatMaxFileSize(list, mtAudio, multi_media);
		FormatMaxFileSize(list, mtImage, multi_media);

		this->lblMaxFileSize->Caption = txt + list;

		bool avatar = s->DisplayAvatar;
		this->imgAvatar->Visible = avatar;
		this->lblUser->Left = avatar? this->lblUserLeftAvatar : this->lblUserLeftNoAvatar;
	}
	else  {
		this->lblMaxFileSize->Caption = L"";
	}

	this->OnQueueUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::OnLogin()
{
	bool ready = SrvAdapterModule->Authorized;

	this->lblUser->Caption = ready?
		LoadStr(LANG_LOGGEDINAS) + SrvAdapterModule->Username :
		LoadStr(LANG_NOT_LOGGEDIN);
	//Avatar
	this->imgAvatar->Picture->Graphic = ready && this->imgAvatar->Visible?
		SrvAdapterModule->Avatar :
		NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::OnQueueUpdate()
{
	TMediaItem* mi;
	__int64 total_input = 0;
	__int64 total_upload = 0;

	for (int i = 0; i < this->lvQueue->Items->Count; i++) {
		mi = this->GetMediaItem(i);
		if (mi->InputData) total_input += mi->InputData->Size;

		total_upload += mi->GetUploadSize();
	}

	if (total_input > 0) {
		UnicodeString txt;
		if (total_upload > 0) txt = FormatDataSize(total_upload) + L"/";
		this->lblTotalSize->Caption = L"Total size: " + txt + FormatDataSize(total_input);
	}
	else {
		this->lblTotalSize->Caption = L"";
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::ExecuteDDEMacro(TStrings *Msg)
{
	this->Reactivate();

	AnsiString cmd = Msg->Strings[0].LowerCase();
	if (StartsText("add", cmd)) {
		if (this->Busy) {
			MessageBeep(0);
			return;
		}
		int start, end;
		start = AnsiPos("(\"", cmd);
		end = PosEx("\")", cmd, start);

		UnicodeString file = cmd.SubString(start+2, end-start-2);
		if (!file.IsEmpty()) {
			this->AddMedia(file);
		}
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Form events
//---------------------------------------------------------------------------
int __fastcall TMainFormBase::OnMove(TMessage &Msg)
{   //VCL does not handle winodow movement
	Framework->SaveFormPosition(this);
	return 1; //enable default processing
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Control events
//---------------------------------------------------------------------------
void __fastcall TMainFormBase::btnLogoutClick(TObject *Sender)
{
	if (!SrvAdapterModule->Authorized) this->Login();
	else this->Logout();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::imgLogoClick(TObject *Sender)
{
	Framework->BrowseURL(CUSTOM_SITE_URL);
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::lvQueueClick(TObject *Sender)
{   //Set up edit and remove buttons state
	this->UpdateUI();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::btnAddClick(TObject *Sender)
{
	if (this->AddMedia()) this->lvQueue->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::btnYouTubeClick(TObject *Sender)
{
	#ifdef CUSTOM_YOUTUBE
		if (this->GrabYouTube()) this->lvQueue->SetFocus();
	#endif
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::btnEditClick(TObject *Sender)
{
	this->EditMedia();
	this->lvQueue->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::btnRemoveClick(TObject *Sender)
{
	this->RemoveMedia();
	this->lvQueue->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::btnUploadClick(TObject *Sender)
{
	this->Upload();
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::lblVersionClick(TObject *Sender)
{
	if (this->Busy) return;

	TAboutBox* dlg = new TAboutBox(this);
	dlg->ShowModal();

	delete dlg;
}
//---------------------------------------------------------------------------

void __fastcall TMainFormBase::ProgressTimerTimer(TObject *Sender)
{
	this->OnProgress();
}
//---------------------------------------------------------------------------

