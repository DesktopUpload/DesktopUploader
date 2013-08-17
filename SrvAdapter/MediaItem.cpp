/*---------------------------------------------------------------------------
$Id: MediaItem.cpp 521 2011-02-07 14:04:29Z anton $
---------------------------------------------------------------------------*/
#include "SrvAdapter.h"
#include "TFramework.h"
#pragma hdrstop

#include "MediaItem.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

extern TSrvAdapterModule* SrvAdapterModule;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TMediaItem
//---------------------------------------------------------------------------
__fastcall TMediaItem::TMediaItem(TMediaType MediaType)
	: TObject()
{
	this->MediaType = MediaType;

	this->Categories = new TStringList;
		this->Categories->Delimiter = '|';
	this->Broadcast = 0;

	this->Date = TDate::CurrentDate();
	this->hasDate = false;
	this->AllowComments = true;
	this->AllowVoting = true;
	this->AllowRating = true;
	this->AllowEmbedding = true;

	this->Pass2 = -1;
	this->Deinterlace = -1;

	this->InputData = NULL;
	this->UploadData = NULL;

	this->Metadata = NULL;

	this->TorrentData = NULL;
	this->PictureData = NULL;

	this->External = false;
	this->FUploadInput = false;
	this->TempInput = false;
	this->NativeFormat = false;

	this->Type = mitNone;

	this->YouTube_fmt = -1;
}
//---------------------------------------------------------------------------

__fastcall TMediaItem::~TMediaItem()
{
	delete this->Categories;
	Framework->DeleteFileStream(this->InputData, this->TempInput);

	this->ClearUploadData(true);

	delete this->TorrentData;
	delete this->PictureData;
}
//---------------------------------------------------------------------------

void __fastcall TMediaItem::ClearUploadData(bool ClearThumbs)
{
	Framework->DeleteFileStream(this->UploadData, true);
	delete this->Metadata; this->Metadata = NULL;

    this->MediaMD5 = L"";

	if (ClearThumbs) {
		delete this->Thumbs; this->Thumbs = NULL;
	}
}
//---------------------------------------------------------------------------

TFileStream* __fastcall TMediaItem::GetUploadData()
{
	if (this->UploadInput) return this->InputData;
	else if (this->UploadData) return this->UploadData;
	else return NULL;
}
//---------------------------------------------------------------------------

__int64 __fastcall TMediaItem::GetUploadSize()
{
	if (this->GetState() != misReady) return 0;

	__int64 result = 0;

	TFileStream* fs = this->GetUploadData();
	if (fs) {
		result += fs->Size;
	}
	if (this->Thumbs) {
		int count = this->Thumbs->List->Count;
		for (int i = 0; i < count; i++) {
			TFileStream* fs = (TFileStream*)this->Thumbs->List->Items[i];
			result += fs->Size;
		}
			count = this->Thumbs->BigList->Count;
			for (int i = 0; i < count; i++) {
				TFileStream* fs = (TFileStream*)this->Thumbs->BigList->Items[i];
				result += fs->Size;
		}
	}
	if (this->TorrentData) {
		result += this->TorrentData->Size;
	}
	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TMediaItem::IsReady(TMediaItemWorkType Type)
{
	if (!this->EmbedCode.IsEmpty()) {
        return true;
	}

	switch (Type) {
	case miwtTranscode:
		return this->GetUploadData()!=NULL;
	case miwtMetadata:
		//if (this->MediaType != mtVideo) return true;
		return (this->Metadata!=NULL
			|| (this->External && !this->EmbedCode.IsEmpty()));
	case miwtThumbs:
		if (this->MediaType != mtVideo) return true;
		return this->Thumbs!=NULL;

	default:
		return this->IsReady(miwtTranscode)
			&& this->IsReady(miwtMetadata)
			&& this->IsReady(miwtThumbs);
	}
}
//---------------------------------------------------------------------------

TMediaItemState __fastcall TMediaItem::GetState()
{
	return
		this->IsMissingFields()? misInvalid :
		this->IsReady()? 		 misReady 	:
		misNotReady;
}
//---------------------------------------------------------------------------

bool __fastcall TMediaItem::IsMissingFields()
{
	if (SrvAdapterModule->Session->Settings->AllowTorrents == srtoRequire
		&& !this->TorrentData)
	{
		return true;
	}

	return false;
}
//---------------------------------------------------------------------------

TStringList* __fastcall TMediaItem::GetMissingFields()
{
	TStringList* result = new TStringList;

	if (SrvAdapterModule->Session->Settings->AllowTorrents == srtoRequire
		&& !this->TorrentData)
	{
		result->Add(L"torrent file");
	}

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TMediaItem::getUploadInput()
{
	return
		this->MediaType == mtImage? true :
		this->MediaType == mtAudio? this->NativeFormat :
		this->FUploadInput;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TMetadata
//---------------------------------------------------------------------------
__fastcall TMetadata::TMetadata()
{
	this->Resolution = NULL;
	this->Duration = 0;
}
//---------------------------------------------------------------------------

__fastcall TMetadata::~TMetadata()
{
	delete this->Resolution;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TThumbs
//---------------------------------------------------------------------------
__fastcall TThumbs::TThumbs()
{
//	for (int i = 0; i < CFG_THUMBNAILCOUNT; i++) {
//		this->Items[i] = NULL;
//	}
	this->List = new TList;
	this->BigList = new TList;
}
//---------------------------------------------------------------------------

__fastcall TThumbs::~TThumbs()
{
	int count = this->List->Count;
	for (int i = 0; i < count; i++) {
		TFileStream* fs = (TFileStream*)this->List->Items[i];
		Framework->DeleteFileStream(fs, true);
	}
	delete this->List;

	count = this->BigList->Count;
	for (int i = 0; i < count; i++) {
		TFileStream* fs = (TFileStream*)this->BigList->Items[i];
		Framework->DeleteFileStream(fs, true);
	}
	delete this->BigList;
}
//---------------------------------------------------------------------------



