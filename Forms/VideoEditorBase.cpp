/*---------------------------------------------------------------------------
$Id: VideoEditorBase.cpp 468 2010-04-21 12:06:23Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <FileCtrl.hpp>
#include <StrUtils.hpp>
#include <SysUtils.hpp>

#include "Config.h"
#include "Custom/Custom.h"
#include "Custom/Main.h"
#include "Utils.h"
#include "TFramework.h"
#include "SrvAdapter.h"

#pragma hdrstop

#include "VideoEditorBase.h"
//---------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UploadProps"
#pragma link "TGroupTitle"
#pragma resource "*.dfm"
//---------------------------------------------------------------------
extern TFramework* Framework;
extern TSrvAdapterModule* SrvAdapterModule;
extern TMainForm* MainForm;
//---------------------------------------------------------------------

//INI file section just because multiple forms may have different names
#define INISECTION L"VideoEditorForm"
//---------------------------------------------------------------------

//----------------------------------------------------------------------------
// EMediaEditorCheckException
//----------------------------------------------------------------------------
class EMediaEditorCheckException : public Exception
{
private:
	int FPageIndex;
	TWinControl* FControl;

public:
	__fastcall EMediaEditorCheckException(UnicodeString Message,
		TWinControl* Control=NULL, int PageIndex=0)
		: Exception(Message)
		{
			this->FPageIndex = PageIndex;
			this->FControl = Control;
		};

	__property int PageIndex = {read=FPageIndex};
	__property TWinControl* Control = {read=FControl};
};
//----------------------------------------------------------------------------

//---------------------------------------------------------------------
// Helper functions
//---------------------------------------------------------------------
void __fastcall FormatExtList(TStringList* List, UnicodeString Label,
	UnicodeString& Filter, UnicodeString& AllFilter, bool& MultiMedia)
// Gathers allowed media extensions and formats lists for open dialog
{
	UnicodeString filter=L"";
	UnicodeString display=L"";

	for (int i = 0; i < List->Count; i++) {
		if (i > 0) {
			filter += L"; ";
			display += ", ";
		}
		filter += L"*." + List->Strings[i];
		display += L"*." + List->Strings[i];
	}

	if (!Filter.IsEmpty()) {
		Filter += L"|";
		AllFilter += L"; ";
		MultiMedia = true;
	}
	Filter += Label + L" (" + display + L")|" + filter;
	AllFilter += filter;
}
//---------------------------------------------------------------------

UnicodeString __fastcall PrepareFileName(UnicodeString FileName)
{
	UnicodeString result = FileName.Trim();
	result = ReplaceStr(result, L"/", L""); //Remove slashes

	return result;
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// TInfoEditorFormBase
//---------------------------------------------------------------------
__fastcall TVideoEditorFormBase::TVideoEditorFormBase(TComponent* AOwner, TMediaItem* MI,
	bool EditMode)
	: TForm(AOwner)
{
	this->InplaceEditError = false;

	this->MediaItem = MI;
	this->EditMode = EditMode;
	this->Caption = EditMode? L"Edit Media" : L"Add Media";

	TSrvSettings* s = SrvAdapterModule->Session->Settings;

	this->pnlTorrent->Visible = s->AllowTorrents != srtoDisable;

	//Allowed extensions
	if(MI->External) {
		this->lblFile->Enabled = false;
		this->btnBrowse->Caption = L"Save As...";
		this->btnBrowse->Enabled = MI->EmbedCode.IsEmpty();
	}
	else {
		UnicodeString filter, all_filter;
		bool multi_media = false;
		if (s->Video && !s->Video->ExternalOnly) FormatExtList(s->Video->AllowExts, L"Video Files",
			filter, all_filter, multi_media);
		if (s->Audio && !s->Audio->ExternalOnly) FormatExtList(s->Audio->AllowExts, L"Audio Files",
			filter, all_filter, multi_media);
		if (s->Image && !s->Image->ExternalOnly) FormatExtList(s->Image->AllowExts, L"Image Files",
			filter, all_filter, multi_media);
		if (multi_media) {
			filter = L"All Supported Media Files|" + all_filter + L"|" + filter;
		}
		this->dlgOpen->Filter = filter;
	}
	//Image extensions
	UnicodeString filter=L""; UnicodeString display=L"";
	TStringList* sl = StrExplode(CFG_DEFAULT_IMAGE_ALLOWEXTENSIONS, L",");
	for (int i = 0; i < sl->Count; i++) {
		if (i > 0) {
			filter += L"; ";
			display += ", ";
		}
		filter += L"*." + sl->Strings[i];
		display += L"*." + sl->Strings[i];
	}
	delete sl;
	this->dlgPicture->Filter = L"Image Files (" + display + L")|" + filter;

	//Restore info
    this->edtFile->Enabled 				= !MI->External;
	this->edtTitle->Text 				= MI->Title;
	this->memDescription->Text 			= MI->Description;
	this->edtTags->Text 				= MI->Tags;

	this->edtTorrent->Text 				= MI->TorrentData? MI->TorrentData->FileName : UnicodeString(L"");
	this->edtPicture->Text 				= MI->PictureData? MI->PictureData->FileName : UnicodeString(L"");

	this->dtpDate->Date         		= MI->Date;
	this->dtpDate->Checked 				= MI->hasDate;
	int index = this->cmbCountry->Items->IndexOf(MI->Country);
	this->cmbCountry->ItemIndex 		= index==-1? 0 : index;
	this->edtLocation->Text 			= MI->Location;
	this->chkAllowComment->Checked 		= MI->AllowComments;
	this->chkAllowVoting->Checked 		= MI->AllowVoting;
	this->chkAllowRating->Checked 		= MI->AllowRating;
	this->chkAllowEmbedding->Checked 	= MI->AllowEmbedding;

	//Restore conversion settings
	this->Pass2 = (MI->Pass2 != -1)?
		MI->Pass2 :
		Framework->IniFile->ReadBool(INISECTION, L"Pass2", CFG_DEFAULT_PASS2);
	this->Deinterlace = (MI->Deinterlace != -1)?
		MI->Deinterlace :
		Framework->IniFile->ReadBool(INISECTION, L"Deinterlace", CFG_DEFAULT_DEINTERLACE);
	this->oldPass2 = this->Pass2;
	this->oldDeinterlace = this->Deinterlace;

	//Restore data
	if (EditMode) {
		if (s->Media[MI->MediaType] == NULL) {
			Framework->ShowErrorMessage(L"Uploading of media type '"
				+ MediaTypeToStr(MI->MediaType) + L"' not allowed.");
			throw EMediaEditorException(L"Invalid media type");
		}

		this->MediaType = MI->MediaType;
		this->MediaItemType = MI->Type;
		this->NativeFormat = MI->NativeFormat;
		this->UploadFormat = this->NativeFormat? UnicodeString(L"") : MI->UploadFormat;

		this->edtFile->Text	= MI->MediaLocation;

		this->UploadProperties->Restore(MI);

		this->UpdateUI();
	}
	else {
		this->MediaType = mtNone;
		if (!this->OpenFile(MI->Location)) {
			throw EMediaEditorException();
		}
	}

	//Init controls
	this->gtInfo->Init();
	this->gtFormat->Init();
	this->gtOptional1->Init();
	this->gtOptional2->Init();

	this->ShowModal();
}
//---------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::FormCreate(TObject *Sender)
{
   	this->Constraints->MinWidth = this->Width;
	this->Constraints->MinHeight = this->Height;

	Framework->RestoreFormPosition(this, INISECTION, ContainsStr(Name, "_"));
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::FormClose(TObject *Sender, TCloseAction &Action)
{
	Framework->SaveFormPosition(this, INISECTION);
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::UpdateUI()
{
	MainForm->ilItemTypes->GetIcon((int)this->MediaItemType, this->Icon);
	this->Caption = UnicodeString(this->EditMode? L"Edit" : L"Add")	+ L" "
		+ MediaTypeToStr(this->MediaType);

	this->pnlPicture->Visible = this->MediaType==mtAudio;

	this->cmbUploadFormat->Clear();
	this->cmbUploadFormat->ItemIndex = -1;
	if (!(this->MediaItem->External || this->NativeFormat)) {
		TStringList* formats = SrvAdapterModule->Session->Settings->Media[this->MediaType]->Formats;
		for (int i = 0; i < formats->Count; i++) {
			TSrvMediaFormat* f = (TSrvMediaFormat*) formats->Objects[i];
			this->cmbUploadFormat->Items->Add(f->Label);
			if (this->UploadFormat == formats->Strings[i]) {
                this->cmbUploadFormat->ItemIndex = i;
			}
		}
	}
	bool format_selection = this->cmbUploadFormat->Items->Count > 0;
	this->pnlVideo->Visible = this->MediaType==mtVideo && format_selection;
	this->pnlFormat->Visible = format_selection;
	this->pnlFormat->Height =
		this->pnlVideo->Visible?
		this->pnlVideo->Top + this->pnlVideo->Height :
		this->cmbUploadFormat->Top + this->cmbUploadFormat->Height;
	if (format_selection && this->cmbUploadFormat->ItemIndex == -1) {
		this->cmbUploadFormat->ItemIndex = 0;
	}
	this->cmbUploadFormatChange(NULL);
}
//---------------------------------------------------------------------------

bool __fastcall TVideoEditorFormBase::SaveData()
{ //Check media info and provide error message if needed.
	//Prepare
	TMediaItem* mi = this->MediaItem;

	UnicodeString title, descr, tags;
	AnsiString buf;
	__int64 size;
	TFileStream* file_fs = NULL;
	UnicodeString file_name = this->edtFile->Text;
	TFileStream* torrent_fs = NULL;
	UnicodeString torrent_name = this->edtTorrent->Text;
	TFileStream* picture_fs = NULL;
	UnicodeString picture_name = this->pnlPicture->Visible?
		this->edtPicture->Text : UnicodeString(L"");

	bool file_changed = !mi->External &&
		(!mi->InputData || (LowerCase(mi->InputData->FileName) != LowerCase(file_name)));
	bool torrent_changed = LowerCase(torrent_name) !=
		LowerCase(mi->TorrentData? mi->TorrentData->FileName : UnicodeString(L""));
	bool picture_changed = LowerCase(picture_name) !=
		LowerCase(mi->PictureData? mi->PictureData->FileName : UnicodeString(L""));

	TSrvSettings* s = SrvAdapterModule->Session->Settings;
	TSrvMediaSettings* media = s->Media[this->MediaType];

try {
//0. File
	if (file_changed) {
		if (file_name.IsEmpty()) {
			throw EMediaEditorCheckException(
				L"Please provide a media file to upload.",
				this->btnBrowse);
		}

		try {
			file_fs = new TFileStream(file_name, OPENMODE_INPUTFILE);
		}
		catch (EFOpenError &e) {
			throw EMediaEditorCheckException(
				e.Message,
				this->btnBrowse);
		}
	}

//1. Title
	title = this->edtTitle->Text.Trim();
	if (title.Length() < 3) {
		throw EMediaEditorCheckException(
			L"Please provide a media title with minimum 3 characters.",
			this->edtTitle);
	}

 //2. Description
	descr = this->memDescription->Text.Trim();
	if ((!s->AllowEmptyFields) && (descr.Length() < 3)) {
		throw EMediaEditorCheckException(
			L"Please provide a media description with minimum 3 characters.",
			this->memDescription);
	}
 //3. Tags
	tags = this->edtTags->Text.Trim();
	tags = ReplaceStr(tags, L"$", "");
	tags = ReplaceStr(tags, L"+", "");
	tags = ReplaceStr(tags, L"/", "");
	tags = ReplaceStr(tags, L"=", "");
	tags = ReplaceStr(tags, L"[", "");
	tags = ReplaceStr(tags, L"]", "");
	tags = ReplaceStr(tags, L"&", "");
	tags = ReplaceStr(tags, L"~", "");
	tags = ReplaceStr(tags, L"/", "");
	tags = ReplaceStr(tags, L", ", " ");
	tags = ReplaceStr(tags, L",", " ");
	tags = ReplaceStr(tags, L"  ", " ");
	if ((!s->AllowEmptyFields) && (tags.Length() < 3)) {
		throw EMediaEditorCheckException(
			L"Please provide tag(s).",
			this->edtTags);
	}
 //4. Categories
	try {
		this->UploadProperties->CheckCategories();
	} catch (UnicodeString msg) {
		throw EMediaEditorCheckException(msg, this->UploadProperties->GetCategoryControl());
	}
 //5. Torrent
	if (s->AllowTorrents == srtoRequire
		&& torrent_name.IsEmpty())
	{
		throw EMediaEditorCheckException(
			L"Please provide a torrent file for upload.",
			this->btnTorrentBrowse);
	}
	if (torrent_changed) {
		if (!torrent_name.IsEmpty()) {
			try {
				torrent_fs = new TFileStream(torrent_name, OPENMODE_INPUTFILE);
			}
			catch (EFOpenError &e) {
				throw EMediaEditorCheckException(
					e.Message,
					this->btnTorrentBrowse);
			}
		}
	}

 //6. Audio Picture
	if (this->MediaType == mtAudio && s->Audio->RequirePicture
		&& picture_name.IsEmpty())
	{
		throw EMediaEditorCheckException(
			L"Please provide a picture file for upload.",
			this->btnPictureBrowse);
	}
	if (picture_changed) {
		if (!picture_name.IsEmpty()) {
			try {
				picture_fs = new TFileStream(picture_name, OPENMODE_INPUTFILE);
			}
			catch (EFOpenError &e) {
				throw EMediaEditorCheckException(
					e.Message,
					this->btnPictureBrowse);
			}
		}
	}
}
catch (EMediaEditorCheckException& e) {
	delete file_fs;
	delete torrent_fs;
	delete picture_fs;

	this->Pages->ActivePageIndex = e.PageIndex;
	if (e.Control) {
		e.Control->SetFocus();
	}

	Framework->ShowErrorMessage(e.Message, this->Caption, true);

	return false;
}

//Set properties
	mi->MediaLocation   = file_name;
	mi->Title 			= title;
	mi->Description 	= descr;
	mi->Tags 			= tags;
	mi->Pass2 = this->chkPass2->Enabled?
		(this->chkPass2->Checked? 1 : 0) : -1;
	mi->Deinterlace = this->chkDeinterlace->Enabled?
		(this->chkDeinterlace->Checked? 1 : 0) : -1;

	this->UploadProperties->Save(this->MediaItem);
	//Optional
	mi->Date 			= this->dtpDate->Date;
	mi->hasDate			= this->dtpDate->Checked;
	mi->Country			= this->cmbCountry->Text;
	mi->Location		= this->edtLocation->Text;
	mi->AllowComments	= this->chkAllowComment->Checked;
	mi->AllowVoting		= this->chkAllowVoting->Checked;
	mi->AllowRating		= this->chkAllowRating->Checked;
	mi->AllowEmbedding	= this->chkAllowEmbedding->Checked;

	mi->MediaType = this->MediaType;
	mi->Type = this->MediaItemType;
	mi->NativeFormat = this->NativeFormat;

	if (!mi->External && (file_changed
		|| this->UploadFormat != mi->UploadFormat
		|| (this->MediaType == mtVideo &&
		(this->chkPass2->Checked != this->oldPass2 || this->chkDeinterlace->Checked != this->oldDeinterlace))))
	{
		mi->ClearUploadData(file_changed);

		mi->UploadFormat = this->NativeFormat?
			media->NativeExts->Values[GetFileExt(file_name)] :
			this->UploadFormat;
	}
	if (file_changed) {
		//Set file properties
		delete this->MediaItem->InputData;
		mi->InputData = file_fs;

		if (!mi->External) mi->Label = ExtractFileName(file_name);
	}

	if (torrent_changed) {
		delete mi->TorrentData;
		mi->TorrentData = torrent_fs;
		mi->TorrentMD5 = SrvAdapterModule->HashMedia(torrent_fs);
	}

	if (picture_changed) {
		delete mi->PictureData;
		mi->PictureData = picture_fs;
	}

	//Save to ini
	UploadProperties->SaveToIni();
	if (this->pnlFormat->Visible) {
		Framework->IniFile->WriteString(INISECTION,
			MediaTypeToStr(this->MediaType) + L"-UploadFormat", this->UploadFormat);
	}
	if (this->chkPass2->Enabled) {
		Framework->IniFile->WriteBool(INISECTION, L"Pass2", this->chkPass2->Checked);
	}
	if (this->chkDeinterlace->Enabled) {
		Framework->IniFile->WriteBool(INISECTION, L"Deinterlace", this->chkDeinterlace->Checked);
	}

	return true;
}
//---------------------------------------------------------------------

bool __fastcall TVideoEditorFormBase::OpenFile(UnicodeString FileName)
{
	FileName = PrepareFileName(FileName);

	if (FileName.IsEmpty()) {
		this->dlgOpen->FileName = this->edtFile->Text;
		if (!this->dlgOpen->Execute()) return false;
		FileName = this->dlgOpen->FileName;
	}
	if (!FileExists(FileName)) {
		Framework->ShowErrorMessage(L"File \'" + FileName + L"\' not found.",
			L"Media File", true);
		return false;
	}

	UnicodeString ext = GetFileExt(FileName);
	if (ext.IsEmpty()) {
		Framework->ShowErrorMessage(L"Sorry, files without extension are not allowed.",
			L"Media File", true);
		return false;
	}

	if (!SrvAdapterModule->Authorized) {
    	throw Exception(L"No active session.");
	}
	TSrvSettings* s = SrvAdapterModule->Session->Settings;
	TMediaType mt = mtNone;
	for (int i = 0; i <= COUNT_TMediaType; i++) {
		if (s->Media[(TMediaType) i] && s->Media[(TMediaType) i]->AllowExts->IndexOf(ext) >= 0) {
			mt = (TMediaType)i;
		}
	}

	if (mt == mtNone) {
		Framework->ShowErrorMessage(L"Sorry, files with the extension \"" + ext + L"\" are not allowed.",
			L"Media File", true);
		return false;
	}
	//Native format
	TSrvMediaSettings* media = s->Media[mt];
	bool native = media->AllNative || media->NativeExts->IndexOfName(ext) >= 0;
	if (native && media->MaxFileSize>0 && FileGetSize(FileName) > media->MaxFileSize) {
		Framework->ShowErrorMessage(L"Max file size exeeded.",
			L"Media File", true);
		return false;
	}

	if (mt!=this->MediaType) {
		this->UploadProperties->Init(mt);
		this->UploadFormat = Framework->IniFile->ReadString(INISECTION,
			MediaTypeToStr(mt) + L"-UploadFormat", L"");
	}

	this->MediaType = mt;
	this->MediaItemType = (TMediaItemType)mt;

	this->NativeFormat = native;

	this->edtFile->Text = FileName;
	if (this->edtTitle->Text.IsEmpty()) {
		UnicodeString stem = ExtractFileName(FileName);
		this->edtTitle->Text = stem.SubString(1, stem.Length() - ExtractFileExt(stem).Length());
	}

	this->UpdateUI();

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall TVideoEditorFormBase::SaveFile()
{
	if (!this->MediaItem->FileExt.IsEmpty()) {
		UnicodeString ext = this->MediaItem->FileExt;
		dlgSave->DefaultExt = ext;
		dlgSave->Filter = UpperCase(ext) + L" files (*." +  ext + L")|*." + UpperCase(ext);
	}
	if (dlgSave->Execute()) {
		TFileStream* fs;
		try {
			fs = new TFileStream(dlgSave->FileName, fmCreate);
        } catch (EFOpenError &e) {
			Framework->ShowErrorMessage(e.Message, L"Save File Error", true);
			return false;
		}
		fs->CopyFrom(this->MediaItem->InputData, 0);
		delete fs;
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------

bool __fastcall TVideoEditorFormBase::OpenTorrentFile(UnicodeString FileName)
{
	FileName = PrepareFileName(FileName);

	if (FileName.IsEmpty()) {
		this->dlgTorrent->FileName = this->edtTorrent->Text;
		if (!this->dlgTorrent->Execute()) return false;
		FileName = this->dlgTorrent->FileName;
	}

	if (!FileExists(FileName)) {
		Framework->ShowErrorMessage(L"File \'" + FileName + L"\' not found.",
			L"Torrent File", true);
		return false;
	}

	this->edtTorrent->Text = FileName;
	return true;
}
//---------------------------------------------------------------------------

bool __fastcall TVideoEditorFormBase::OpenPictureFile(UnicodeString FileName)
{
	FileName = PrepareFileName(FileName);

	if (FileName.IsEmpty()) {
		this->dlgPicture->FileName = this->edtPicture->Text;
		if (!this->dlgPicture->Execute()) return false;
		FileName = this->dlgPicture->FileName;
	}

	if (!FileExists(FileName)) {
		Framework->ShowErrorMessage(L"File \'" + FileName + L"\' not found.",
			L"Picture File", true);
		return false;
	}

	this->edtPicture->Text = FileName;
	return true;
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::btnBrowseClick(TObject *Sender)
{
	if (!this->MediaItem->External) { //Open
		this->OpenFile();
	}
	else {
		this->SaveFile();
	}
}
//---------------------------------------------------------------------------

int __fastcall TVideoEditorFormBase::OnMove(TMessage &Msg)
{   //VCL does not handle winodow movement
	Framework->SaveFormPosition(this, INISECTION);
	return 1; //enable default processing
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (this->ModalResult == mrOk) {
		//Check for pending inplace edits
		this->InplaceEditError = false;
		this->btnOK->SetFocus(); //This will trigger OnExit events
		if (this->InplaceEditError) {
			CanClose = false; return;
		}
		//Try to save data
		if (!this->SaveData()) {
			CanClose = false; return;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::chkPass2Click(TObject *Sender)
{
	if (this->chkPass2->Enabled) {
		this->Pass2 = this->chkPass2->Checked;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::chkDeinterlaceClick(TObject *Sender)
{
	if (this->chkDeinterlace->Enabled) {
		this->Deinterlace = this->chkDeinterlace->Checked;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::cmbUploadFormatChange(TObject *Sender)
{
	TSrvMediaSettings* media = SrvAdapterModule->Session->Settings->Media[this->MediaType];

	int index = this->cmbUploadFormat->ItemIndex;
	if (index >= 0) {
		this->UploadFormat = media->Formats->Strings[index];

		TSrvMediaFormat* f = (TSrvMediaFormat*)media->Formats->Objects[index];
		if (this->MediaType == mtVideo) {
			this->chkPass2->Enabled = f->EnablePass2;
			this->chkPass2->Checked = this->chkPass2->Enabled? this->Pass2 : false;
			this->chkDeinterlace->Enabled = true;
			this->chkDeinterlace->Checked = this->chkDeinterlace->Enabled? this->Deinterlace : false;
		}
	}
	else {
		this->UploadFormat = L"";

		if (this->MediaType == mtVideo) {
			this->chkPass2->Enabled = false;
			this->chkPass2->Checked = false;
			this->chkDeinterlace->Enabled = false;
			this->chkDeinterlace->Checked = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::btnTorrentBrowseClick(TObject *Sender)
{
	this->OpenTorrentFile();
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::edtFileEnter(TObject *Sender)
{
	this->edtFile->Modified = false;
	this->oldFile = this->edtFile->Text;
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::edtFileExit(TObject *Sender)
{
	if (this->edtFile->Modified) {
		this->edtFile->Text = PrepareFileName(this->edtFile->Text);
		UnicodeString file = this->edtFile->Text;
		if (!file.IsEmpty() && !this->OpenFile(file)) {
			this->InplaceEditError = true;
			this->edtFile->Text = this->oldFile;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::edtTorrentEnter(TObject *Sender)
{
	this->edtTorrent->Modified = false;
	this->oldTorrent = this->edtTorrent->Text;
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::edtTorrentExit(TObject *Sender)
{
	if (this->edtTorrent->Modified) {
		this->edtTorrent->Text = PrepareFileName(this->edtTorrent->Text);
		UnicodeString file = this->edtTorrent->Text;
		if (!file.IsEmpty() && !this->OpenTorrentFile(file)) {
			this->InplaceEditError = true;
			this->edtTorrent->Text = this->oldTorrent;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::btnPictureBrowseClick(TObject *Sender)
{
	this->OpenPictureFile();
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::edtPictureEnter(TObject *Sender)
{
	this->edtPicture->Modified = false;
	this->oldPicture = this->edtPicture->Text;
}
//---------------------------------------------------------------------------

void __fastcall TVideoEditorFormBase::edtPictureExit(TObject *Sender)
{
	if (this->edtPicture->Modified) {
		this->edtPicture->Text = PrepareFileName(this->edtPicture->Text);
		UnicodeString file = this->edtPicture->Text;
		if (!file.IsEmpty() && !this->OpenPictureFile(file)) {
			this->InplaceEditError = true;
			this->edtPicture->Text = this->oldPicture;
		}
	}
}
//---------------------------------------------------------------------------

