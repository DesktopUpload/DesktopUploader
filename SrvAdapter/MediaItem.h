/*---------------------------------------------------------------------------
$Id: MediaItem.h 521 2011-02-07 14:04:29Z anton $
---------------------------------------------------------------------------*/
#ifndef MediaItemH
#define MediaItemH

#include <Classes.hpp>

#include "Config.h"
#include "MediaConversion.h"
#include "SrvInfo.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TMetadata
//---------------------------------------------------------------------------
class TMetadata
{
public:
	__fastcall TMetadata();
	__fastcall ~TMetadata();

	TResolution* Resolution;
	double Duration;
	UnicodeString AspectRatio_String;
};

//---------------------------------------------------------------------------
// TThumbs
//---------------------------------------------------------------------------
class TThumbs
{
public:
	__fastcall TThumbs();
	__fastcall ~TThumbs();

	//TFileStream* Items[CFG_THUMBNAILCOUNT];
	TList* List;
	TList* BigList;
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TMediaItem
//---------------------------------------------------------------------------
enum TMediaItemType 	{mitNone=mtNone, mitVideoFile=mtVideo, mitAudioFile=mtAudio,
	mitImageFile=mtImage, mitVideoYoutube=mtImage+1, mitVideoYoutubeEmbed=mtImage+2};
enum TMediaItemWorkType {miwtAll=0, miwtTranscode=1, miwtMetadata=2, miwtThumbs=3};
enum TMediaItemState	{misInvalid=0, misNotReady=1, misReady=2};

class TMediaItem : public TObject
{
private:
	bool FUploadInput;
    bool __fastcall getUploadInput();

public:		// User declarations
	__fastcall TMediaItem(TMediaType MediaType=mtNone);
	__fastcall ~TMediaItem();

	__property bool UploadInput = {read=getUploadInput, write=FUploadInput};

	TMediaType MediaType;

	//Video properties
	UnicodeString Title, Description, Tags, MediaLocation, Label;
	TStringList* Categories;
	short Broadcast;
	//Optional
	TDate Date; bool hasDate;
	UnicodeString Country, Location;
	bool AllowComments, AllowVoting, AllowRating, AllowEmbedding;
	//Format
	UnicodeString UploadFormat;
	short Pass2;
	short Deinterlace;

	//Data properties
	TFileStream* InputData;
	TFileStream* UploadData;
	TMetadata* Metadata;
	TThumbs* Thumbs;
	//Additional files
	TFileStream* TorrentData;
	TFileStream* PictureData;

	UnicodeString InternetMediaType, FileExt;

	void __fastcall ClearUploadData(bool ClearThumbs=false);
	TFileStream* __fastcall GetUploadData();
	__int64 __fastcall GetUploadSize();

	bool __fastcall IsReady(TMediaItemWorkType Type=miwtAll);
	TMediaItemState __fastcall GetState();
	bool __fastcall IsMissingFields();
	TStringList* __fastcall GetMissingFields();

	//Flags:
	bool NativeFormat;
	bool TempInput;
	bool External;
	UnicodeString EmbedCode;
	UnicodeString EmbedURL;

	TMediaItemType Type;

	//YouTube fields
	int YouTube_fmt;

	//Hashes
	AnsiString MediaMD5, TorrentMD5;
};
//---------------------------------------------------------------------------
#endif



