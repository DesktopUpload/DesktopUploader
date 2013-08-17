/*---------------------------------------------------------------------------
$Id: SrvInfo.cpp 526 2011-02-09 22:10:55Z fwhite $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include "Config.h"
#include "Utils.h"

#pragma hdrstop

#include <StrUtils.hpp>

#include "SrvInfo.h"
#include "YouTube.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvSettings
//---------------------------------------------------------------------------
__fastcall TSrvSettings::TSrvSettings(TSrvResponse* Response)
{
	//  Test Code:
		//Response->SaveToFile(L"c:\\test.txt");
		//Response->Clear();
		//Response->LoadFromFile(L"c:\\test.txt");

	//Init pointers
	this->FErrorHandling = NULL;

	//Init properties:
	this->FExternalOnly = false;

	#ifdef CUSTOM_VIDEO_ON
	this->FVideo = (Response->ReadBool(TSrvResponseValID(L"AllowUpload", L"Video"),	CFG_DEFAULT_VIDEO_ALLOWUPLOAD))?
		new TSrvVideoSettings(Response) :
		NULL;
	#else
    	this->FVideo = NULL;
	#endif

	#ifdef CUSTOM_AUDIO_ON
	this->FAudio = (Response->ReadBool(TSrvResponseValID(L"AllowUpload", L"Audio"),	CFG_DEFAULT_AUDIO_ALLOWUPLOAD))?
		new TSrvAudioSettings(Response) :
		NULL;
	#else
		this->FAudio = NULL;
	#endif
	#ifdef CUSTOM_IMAGE_ON
	this->FImage = (Response->ReadBool(TSrvResponseValID(L"AllowUpload", L"Image"),	CFG_DEFAULT_IMAGE_ALLOWUPLOAD))?
		new TSrvImageSettings(Response) :
		NULL;
	#else
		this->FImage = NULL;
	#endif

	#ifdef CUSTOM_YOUTUBE
	//If video not allowed but external download/embed is allowed
	if (!this->FVideo &&
		(Response->ReadBool(TSrvResponseValID(L"AllowYTDownload", L"Video"), CFG_DEFAULT_ALLOWYTDOWNLOAD)
		|| Response->ReadBool(TSrvResponseValID(L"AllowYTEmbed", L"Video"),	CFG_DEFAULT_ALLOWYTEMBED)))
	{
		//Force load of video settings:
		this->FVideo = new TSrvVideoSettings(Response);

		if (!(this->FImage || this->FAudio)) { //If other media types not allowed too
			this->FExternalOnly = true; //Global setting
			this->FVideo->ExternalOnly = true;
		}
		else {  //If other media types are allowed
			this->FVideo->ExternalOnly = true;
		}
	}
	#endif
	if (!(this->Video || this->Audio || this->Image))
	{
		throw ESrvResponseError(L"No media type allowed for upload.");
	}

//Parse server info
	//AllowTorrents
	this->FAllowTorrents = (TSRTorrentOption)Response->ReadEnum(
		TSrvResponseValID(L"AllowTorrents"),
		MIN_TSRTorrentOption, MAX_TSRTorrentOption,
		CFG_DEFAULT_ALLOWTORRENTS);
	//DisplayAvatar
	this->FDisplayAvatar = Response->ReadBool(
		TSrvResponseValID(L"DisplayAvatar"),
		CFG_DEFAULT_DISPLAYAVATAR);
	//ErrorHandling
	this->FErrorHandling = Response->ReadList(
		TSrvResponseValID(L"ErrorHandling"),
		CFG_DEFAULT_ERRORHANDLING);
	//ExternalProcessPriority
	this->FExternalProcessPriority = this->ParsePriority(
		Response->ReadString(TSrvResponseValID(L"ExternalProcessPriority"), L""));
	//MaxCategories
	this->FMaxCategories = Response->ReadInt(
		TSrvResponseValID(L"MaxCategories"), CUSTOM_MAX_CATEGORIES);
	//AllowEmptyFields
	this->FAllowEmptyFields = Response->ReadBool(
		TSrvResponseValID(L"AllowEmptyFields"),
		CFG_DEFAULT_ALLOW_EMPTY_FIELDS);
}
//---------------------------------------------------------------------------

__fastcall TSrvSettings::~TSrvSettings()
{
	delete this->FErrorHandling;
	delete this->FVideo;
	delete this->FAudio;
	delete this->FImage;
}
//---------------------------------------------------------------------------

TSrvMediaSettings* __fastcall TSrvSettings::getMediaSettings(TMediaType Type)
{
	return
		Type == mtVideo? (TSrvMediaSettings*)this->Video :
		Type == mtAudio? (TSrvMediaSettings*)this->Audio :
		Type == mtImage? (TSrvMediaSettings*)this->Image :
		NULL;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvSettings::getMultiMedia()
{
	unsigned short count = 0;
	if (this->Video) count++;
	if (this->Audio) count++;
	if (this->Image) count++;

	return count > 1;
}
//---------------------------------------------------------------------------

DWORD __fastcall TSrvSettings::ParsePriority(AnsiString Str)
{
	DWORD result = CFG_DEFAULT_OUTER_PROCESS_PRIORITY;

	if 		(Str == "idle")     		result = IDLE_PRIORITY_CLASS;
	else if (Str == "below-normal")     result = BELOW_NORMAL_PRIORITY_CLASS;
	else if (Str == "normal")     		result = NORMAL_PRIORITY_CLASS;
	else if (Str == "above-normal")     result = ABOVE_NORMAL_PRIORITY_CLASS;
	else if	(Str == "high") 			result = HIGH_PRIORITY_CLASS;
	else if	(Str == "realtime") 		result = REALTIME_PRIORITY_CLASS;

	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvMediaSettings
//---------------------------------------------------------------------------
__fastcall TSrvMediaSettings::TSrvMediaSettings(TSrvResponse* Response,
	UnicodeString MediaName, bool DefaultMedia, UnicodeString DefaultExts)
{
	this->FCategories = new TCollection(__classid(TSrvCategory));
	this->FAllowExts = NULL;
	this->FNativeExts = new TStringList;
	this->FFormats = new TStringList;
	this->FAllNative = false;
	this->FExternalOnly = false;

//Parse server info
	//MaxFileSize
    this->FMaxFileSize = Response->ReadInt(
        TSrvResponseValID(L"MaxFileSize", MediaName, DefaultMedia),
            CFG_DEFAULT_MAXFILESIZE);
		    if (this->FMaxFileSize < 0) {
			    throw ESrvResponseError(L"Negative numbers not allowed for MaxFileSize.");
		    }

/*
    #ifdef DEMO_MAX_FILESIZE
		if(this->FMaxFileSize > DEMO_MAX_FILESIZE) {
            this->FMaxFileSize = DEMO_MAX_FILESIZE;
        }
    #endif
*/

	//AllowExtensions
	this->FAllowExts = Response->ReadList(
		TSrvResponseValID(L"AllowExtensions", MediaName, DefaultMedia),
		DefaultExts);

	//Categories
	UnicodeString search = MediaName + L"-Category ";
	UnicodeString name;
	for (int i = 0; i < Response->Count; i++) {
		name = Response->Names[i];

		if (StartsStr(search, name) || (DefaultMedia && StartsStr(L"Category ", name))) {
			TSrvCategory* obj = (TSrvCategory*)this->Categories->Add();

			UnicodeString id = StrExtract(name, L" ");
			if (id.IsEmpty()) throw ESrvResponseError(L"Invalid Category value. No ID found.");

			try {
				obj->ID = StrToInt(id);
			}
			catch (EConvertError& e) {
				throw ESrvResponseError(UnicodeString(L"Invalid Category value. Cannot read ID: ") + e.Message);
			}

			obj->Label = Response->ValueFromIndex[i];
		}
	}

	if (this->Categories->Count == 0) throw ESrvResponseError(L"No categories for " + MediaName + " found.");
}
//---------------------------------------------------------------------------

__fastcall TSrvMediaSettings::~TSrvMediaSettings()
{
	delete this->FCategories;
	delete this->FAllowExts;
	delete this->FNativeExts;

	for (int i = 0; i < this->FFormats->Count; i++) {
		delete (TSrvMediaFormat*)this->FFormats->Objects[i];
	}
	delete this->FFormats;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvVideoSettings
//---------------------------------------------------------------------------
#define MEDIA_NAME L"Video"
#define MEDIA_DEFAULT true
__fastcall TSrvVideoSettings::TSrvVideoSettings(TSrvResponse* Response)
	: TSrvMediaSettings(Response, MEDIA_NAME, MEDIA_DEFAULT,
		CFG_DEFAULT_VIDEO_ALLOWEXTENSIONS)
{
	//Init pointers:
	this->FResolution = NULL;
	this->FThumbResolution = NULL;
	this->FBigThumbResolution = NULL;

	this->FYouTubeFormats = new TStringList;

	//Default values:
	this->FMkvAsDivx = false;

//Parse server info
	//ResizeType
	this->FResizeType = (TSRResizeType)Response->ReadEnum(
		TSrvResponseValID(L"ResizeType", MEDIA_NAME, MEDIA_DEFAULT),
		MIN_TSRResizeType, MAX_TSRResizeType,
		CFG_DEFAULT_RESIZETYPE);

	//VideoResolution
	this->FResolution = Response->ReadResolution(
		TSrvResponseValID(L"Resolution", MEDIA_NAME, MEDIA_DEFAULT, L"VideoResolution"),
		CFG_DEFAULT_VIDEO_RESOLUTION);
	//BigThumbResolution
	this->FBigThumbResolution = Response->ReadResolution(
		TSrvResponseValID(L"BigThumbResolution", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_BIGTHUMBRESOLUTION);
	//ThumbResolution
	this->FThumbResolution = Response->ReadResolution(
		TSrvResponseValID(L"ThumbResolution", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_THUMBRESOLUTION);


	// re-transcode MP4?
	this->FReTranscodeMP4 = Response->ReadBool(
		TSrvResponseValID(L"ReTranscodeMP4", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_RETRANSCODE_MP4);

	//ThumbPadding
	this->FThumbPadding = Response->ReadBool(
		TSrvResponseValID(L"ThumbPadding", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_THUMBPADDING);
	//ThumbCount
	this->FThumbCount= Response->ReadInt(
		TSrvResponseValID(L"ThumbCount", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_THUMBNAIL_COUNT);
	//BigThumbCount
	this->FThumbCountBig= Response->ReadInt(
		TSrvResponseValID(L"ThumbCountBig", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_THUMBNAIL_COUNT_BIG);
	//AllowYTDownload
	this->FAllowYTDownload = Response->ReadBool(
		TSrvResponseValID(L"AllowYTDownload", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_ALLOWYTDOWNLOAD);
	//AllowYTEmbed
	this->FAllowYTEmbed = Response->ReadBool(
		TSrvResponseValID(L"AllowYTEmbed", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_ALLOWYTEMBED);
	//YTDownloadThumbnails
	this->FYTDownloadThumbnails = Response->ReadBool(
		TSrvResponseValID(L"YTDownloadThumbnails", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_YT_DOWNLOAD_THUMBNAILS);
	//WatermarkEnabled
	this->FWatermarkEnabled = Response->ReadBool(
		TSrvResponseValID(L"WatermarkEnabled", MEDIA_NAME, MEDIA_DEFAULT),
		CUSTOM_DEFAULT_WATERMARK_ENABLED);
	//WatermarkPosition
	this->FWatermarkPosition = StrToWatermarkPos(Response->ReadString(
		TSrvResponseValID(L"WatermarkPosition", MEDIA_NAME, MEDIA_DEFAULT),
		CUSTOM_DEFAULT_WATERMARK_POSITION));
	//WatermarkOffsetX
	this->FWatermarkOffsetX = Response->ReadInt(
		TSrvResponseValID(L"WatermarkOffsetX", MEDIA_NAME, MEDIA_DEFAULT),
		CUSTOM_DEFAULT_WATERMARK_OFFSET_X);
	//WatermarkOffsetY
	this->FWatermarkOffsetY = Response->ReadInt(
		TSrvResponseValID(L"WatermarkOffsetY", MEDIA_NAME, MEDIA_DEFAULT),
		CUSTOM_DEFAULT_WATERMARK_OFFSET_Y);

	//Format
	TStringList* SL = Response->ReadList(
		TSrvResponseValID("Formats", MEDIA_NAME, MEDIA_DEFAULT, "VideoFormat"),
		CFG_DEFAULT_VIDEO_FORMATS);
	if (SL->IndexOf(L"flv")>=0) {
		TSrvMediaFormat* obj = new TSrvMediaFormat;
		obj->Label = L"Flash Video";
		obj->FileExt = L"flv";
		obj->InternetMediaType = L"video/flv";
		obj->FFmpegOptions =
			Response->ReadString(
				TSrvResponseValID("FLVOptions", MEDIA_NAME, MEDIA_DEFAULT),
				CFG_DEFAULT_FLV_OPTIONS, false);
		this->Formats->AddObject(L"flv", obj);

		TYouTubeFormat* yf = new TYouTubeFormat;
		yf->Label = L"Normal";
		yf->QualityLevel = YT_QUALITYLEVEL_NORMAL;
		this->YouTubeFormats->AddObject(L"0", yf);
		if (!this->FWatermarkEnabled) {
			this->NativeExts->Add(L"flv=flv");
		}
	}
	if (SL->IndexOf(L"divx")>=0) {
		TSrvMediaFormat* obj = new TSrvMediaFormat;
		obj->Label = L"DivX";
		obj->FileExt = L"divx";
		obj->InternetMediaType = L"video/divx";
		obj->FFmpegOptions =
			Response->ReadString(TSrvResponseValID("DivXOptions", MEDIA_NAME, MEDIA_DEFAULT),
			CFG_DEFAULT_DIVX_OPTIONS, false);
		this->Formats->AddObject(L"divx", obj);
		if (!this->FWatermarkEnabled) {
			this->NativeExts->Add(L"divx=divx");
        }
		//Allow native MKV upload
		if (Response->ReadBool(
			TSrvResponseValID(L"MkvAsDivx", MEDIA_NAME, MEDIA_DEFAULT),
				CFG_DEFAULT_MKVASDIVX))
		{
			if (!this->FWatermarkEnabled) {
				this->NativeExts->Add(L"mkv=divx");
            }
			this->FMkvAsDivx = true;
        }
	}
	if (SL->IndexOf(L"mp4")>=0) {
		TSrvMediaFormat* obj = new TSrvMediaFormat;
		obj->Label = L"MPEG4";
		obj->FileExt = L"mp4";
		obj->InternetMediaType = L"video/mp4";
		obj->FFmpegOptions =
			Response->ReadString(TSrvResponseValID("MP4Options", MEDIA_NAME, MEDIA_DEFAULT),
			CFG_DEFAULT_MP4_OPTIONS, false);
		obj->EnablePass2 = true;
		obj->Preset = L"libx264-hq";
		obj->PresetPass1 = L"libx264-fastfirstpass";
		obj->PresetPass2 = L"libx264-hq";
		this->Formats->AddObject(L"mp4", obj);

		TYouTubeFormat* yf = new TYouTubeFormat;
		yf->Label = L"High Definition";
		yf->QualityLevel = YT_QUALITYLEVEL_HD;
		this->YouTubeFormats->AddObject(L"0", yf);

		if(!this->FReTranscodeMP4 && !this->FWatermarkEnabled) {
			this->NativeExts->Add(L"mp4=mp4");
        }
	}
	delete SL;
	if (this->Formats->Count == 0) throw ESrvResponseError(L"No valid video formats found.");

	if (Response->ReadBool(
			TSrvResponseValID(L"NoTranscode"), CFG_DEFAULT_NO_TRANSCODE)
		|| Response->ReadBool(
			TSrvResponseValID(L"NoTranscode", MEDIA_NAME),
				CFG_DEFAULT_VIDEO_NO_TRANSCODE))
	{
			this->FAllNative = true;
	}
}
//---------------------------------------------------------------------------

__fastcall TSrvVideoSettings::~TSrvVideoSettings()
{
	for (int i = 0; i < this->FYouTubeFormats->Count; i++) {
		delete (TYouTubeFormat*)this->FYouTubeFormats->Objects[i];
	}
	delete this->FYouTubeFormats;

	delete this->FResolution;
	delete this->FThumbResolution;
	delete this->FBigThumbResolution;
}
//---------------------------------------------------------------------------
#undef MEDIA_NAME
#undef MEDIA_DEFAULT

//---------------------------------------------------------------------------
// TSrvAudioSettings
//---------------------------------------------------------------------------
#define MEDIA_NAME L"Audio"
#define MEDIA_DEFAULT false
__fastcall TSrvAudioSettings::TSrvAudioSettings(TSrvResponse* Response)
	: TSrvMediaSettings(Response, MEDIA_NAME, MEDIA_DEFAULT,
		CFG_DEFAULT_AUDIO_ALLOWEXTENSIONS)
{
	this->FRequirePicture = Response->ReadBool(
		TSrvResponseValID(L"RequirePic", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_AUDIO_REQUIREPICTURE);

	//Format
	TStringList* SL = Response->ReadList(
		TSrvResponseValID("Formats", MEDIA_NAME, MEDIA_DEFAULT),
		CFG_DEFAULT_AUDIO_FORMATS);
	if (SL->IndexOf(L"mp3")>=0) {
		TSrvMediaFormat* obj = new TSrvMediaFormat;
		obj->Label = L"MPEG 3";
		obj->FileExt = L"mp3";
		obj->InternetMediaType = L"audio/mp3";
		obj->FFmpegOptions =
			Response->ReadString(TSrvResponseValID("MP3Options", MEDIA_NAME, MEDIA_DEFAULT),
			CFG_DEFAULT_MP3_OPTIONS, false);
		this->Formats->AddObject(L"mp3", obj);

		this->NativeExts->Add(L"mp3=mp3");
	}
	delete SL;
	if (this->Formats->Count == 0) throw ESrvResponseError(L"No valid audio formats found.");

	if (Response->ReadBool(
			TSrvResponseValID(L"NoTranscode"), CFG_DEFAULT_NO_TRANSCODE)
		|| Response->ReadBool(
			TSrvResponseValID(L"NoTranscode", MEDIA_NAME),
				CFG_DEFAULT_AUDIO_NO_TRANSCODE))
	{
			this->FAllNative = true;
	}
}
//---------------------------------------------------------------------------

__fastcall TSrvAudioSettings::~TSrvAudioSettings()
{
}
//---------------------------------------------------------------------------
#undef MEDIA_NAME
#undef MEDIA_DEFAULT

//---------------------------------------------------------------------------
// TSrvImageSettings
//---------------------------------------------------------------------------
#define MEDIA_NAME L"Image"
#define MEDIA_DEFAULT false
__fastcall TSrvImageSettings::TSrvImageSettings(TSrvResponse* Response)
	: TSrvMediaSettings(Response, MEDIA_NAME, MEDIA_DEFAULT,
		CFG_DEFAULT_IMAGE_ALLOWEXTENSIONS)
{
	if (Response->ReadBool(
			TSrvResponseValID(L"NoTranscode"), CFG_DEFAULT_NO_TRANSCODE)
		|| Response->ReadBool(
			TSrvResponseValID(L"NoTranscode", MEDIA_NAME),
				CFG_DEFAULT_IMAGE_NO_TRANSCODE))
	{
			this->FAllNative = true;
	}
}
//---------------------------------------------------------------------------

__fastcall TSrvImageSettings::~TSrvImageSettings()
{
}
//---------------------------------------------------------------------------
#undef MEDIA_NAME
#undef MEDIA_DEFAULT

//---------------------------------------------------------------------------
// TSrvCategory
//---------------------------------------------------------------------------
__fastcall TSrvCategory::TSrvCategory(TCollection* Collection)
	: TCollectionItem(Collection)
{
	this->ID = 0;
}
//---------------------------------------------------------------------------

__fastcall TSrvCategory::~TSrvCategory()
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvMediaFormat
//---------------------------------------------------------------------------
__fastcall TSrvMediaFormat::TSrvMediaFormat()
	:TObject()
{
	this->EnablePass2 = false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvResponse
//---------------------------------------------------------------------------
__fastcall TSrvResponse::TSrvResponse(UnicodeString ResponseText)
	: TStringList()
{
	if (ResponseText.IsEmpty()) throw ESrvResponseError(L"Server response is empty.");

	this->Text = ResponseText;
	try {
		this->StatusCode = StrToInt(this->Strings[0]);
	}
	catch (EConvertError& e) {
		throw ESrvResponseError(L"Cannot read status code. "+e.Message);
	}

	this->Delete(0); //Remove status code line

	for (int i = this->Count-1; i >= 0; i--) {
		UnicodeString line = this->Strings[i].Trim();
		int split = line.Pos(L":");
		if (split) {
			this->Strings[i] = line.SubString(1, split-1).Trim() \
			+ L":" \
			+ line.SubString(split+1, line.Length()-split).Trim();
		}
		else {
			this->Delete(i);
		}
	}

	this->NameValueSeparator = ':';

	if (this->StatusCode != 0) {
		if (this->StatusCode < 0) throw ESrvResponseError(L"Negative status code not allowed.");

		this->ErrorMessage = this->ReadString(TSrvResponseValID("ErrorMessage"), L"", true);
		if (this->ErrorMessage.IsEmpty()) this->ErrorMessage = L"Error #"
			+ IntToStr(this->StatusCode)
			+ L" (No error message provided).";
	}
	else { //Find URLs
		this->AvatarURL = this->Values[L"AvatarURL"];
		this->WatermarkURL = this->Values[L"WatermarkURL"];
    }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvResponse::Read(TSrvResponseValID ID)
{
	UnicodeString result = this->Values[ID.FullName];
	if (result.IsEmpty() && ID.DefaultMedia) {
		result = this->Values[ID.LegacyName];
	}
	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvResponse::ReadString(TSrvResponseValID ID,
	UnicodeString DefVal, bool MultiLine)
{
	UnicodeString val = this->Read(ID);
	if (MultiLine) {
		val = ReplaceStr(val, L"<br />", "\n");
		val = ReplaceStr(val, L"<br>", "\n");
		val = ReplaceStr(val, L"<BR>", "\n");
	}

	return val.IsEmpty()? DefVal : val;
}
//---------------------------------------------------------------------------

__int64 __fastcall TSrvResponse::ReadInt(TSrvResponseValID ID, __int64 DefVal)
{
	UnicodeString val = this->Read(ID);
	if (val.IsEmpty()) return DefVal;

	try {
		return StrToInt64(val);
	}
	catch (EConvertError& e) {
		throw ESrvResponseError(UnicodeString(L"Invalid ") + ID.FullName + " value. "
			+ e.Message);
	}
}
//---------------------------------------------------------------------------

int __fastcall TSrvResponse::ReadEnum(TSrvResponseValID ID, int Min, int Max, int DefVal)
{
	UnicodeString val = this->Read(ID);
	if (val.IsEmpty()) return DefVal;

	int result;
	try {
		result = StrToInt(val);
		if (result < Min || result > Max) {
			ESrvResponseError(UnicodeString(L"Invalid ") + ID.FullName + " value.");
		}
	}
	catch (EConvertError& e) {
		throw ESrvResponseError(UnicodeString(L"Invalid ") + ID.FullName + " value. "
			+ e.Message);
	}

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvResponse::ReadBool(TSrvResponseValID ID, bool DefVal)
{
	UnicodeString val = this->Read(ID);
	if (val.IsEmpty()) return DefVal;

	return val != L"0";
}
//---------------------------------------------------------------------------

TResolution* __fastcall TSrvResponse::ReadResolution(TSrvResponseValID ID,
	UnicodeString DefStr)
{
	UnicodeString val = this->Read(ID);
	if (val.IsEmpty()) val = DefStr;

	try {
		return new TResolution(val, true);
	}
	catch (EResolutionError& e) {
		throw ESrvResponseError(UnicodeString(L"Invalid ") + ID.FullName + " value. "
		+ e.Message);
	}
}
//---------------------------------------------------------------------------

TStringList* __fastcall TSrvResponse::ReadList(TSrvResponseValID ID, UnicodeString DefStr)
{
	UnicodeString val = this->Read(ID);
	if (val.IsEmpty()) val = DefStr;

	return StrExplode(val, L",", true);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvResponseValID
//---------------------------------------------------------------------------
__fastcall TSrvResponseValID::TSrvResponseValID(UnicodeString Name,
	UnicodeString MediaType, bool DefaultMedia, UnicodeString LegacyName)
{
		this->FName = Name;
		this->FLegacyName = LegacyName.IsEmpty()? Name : LegacyName;

		this->FMediaType = MediaType;
		this->FDefaultMedia = DefaultMedia;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvResponseValID::getFullName()
{
		return this->FMediaType.IsEmpty()?
			this->FName :
			this->FMediaType + L"-" + this->FName;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TYouTubeFormat
//---------------------------------------------------------------------------
__fastcall TYouTubeFormat::TYouTubeFormat()
	:TObject()
{
	this->QualityLevel = 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Helpers
//---------------------------------------------------------------------------
UnicodeString __fastcall MediaTypeToStr(TMediaType MediaType)
{
	return
		MediaType == mtVideo? L"Video" :
		MediaType == mtAudio? L"Audio" :
		MediaType == mtImage? L"Image" :
		L"";
}
//---------------------------------------------------------------------------

TMediaType 	  __fastcall StrToMediaType(UnicodeString Str)
{
	Str = Str.LowerCase();

	return
		Str == L"video"? mtVideo :
		Str == L"audio"? mtAudio :
		Str == L"image"? mtImage :
		mtNone;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall WatermarkPosToStr(TWatermarkPos Pos)
{
	return
		Pos == wpTopRight? L"top-right" :
		Pos == wpBottomRight? L"bottom-right" :
		Pos == wpBottomLeft? L"bottom-left" :
		L"top-left";
}
//---------------------------------------------------------------------------

TWatermarkPos __fastcall StrToWatermarkPos(UnicodeString Str)
{
	Str = Str.LowerCase();

	return
		Str == L"top-right"? wpTopRight :
		Str == L"bottom-right"? wpBottomRight :
		Str == L"bottom-left"? wpBottomLeft :
		wpTopLeft;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TResolution
//---------------------------------------------------------------------------
__fastcall TResolution::TResolution(bool EnsureEven)
{
	this->FWidth = 0;
	this->FHeight = 0;
	this->FEnsureEven = EnsureEven;
}
//---------------------------------------------------------------------------

__fastcall TResolution::TResolution(int Width, int Height, bool EnsureEven)
{
	this->FEnsureEven = EnsureEven;

	this->Width = Width;
	this->Height = Height;
}
//---------------------------------------------------------------------------

__fastcall TResolution::TResolution(UnicodeString ResString, bool EnsureEven)
{
	this->FEnsureEven = EnsureEven;

	this->SetByString(ResString);
}
//---------------------------------------------------------------------------

void __fastcall TResolution::SetByString(UnicodeString ResString)
{
	int pos = Pos(L"x", ResString);
	if (pos == 0) throw EResolutionError(L"Divider not found");
	try {
		this->Width = this->Convert(ResString.SubString(1, pos-1));
	}
	catch (EResolutionError& e) {
		throw EResolutionError(UnicodeString(L"Cannot read width. ") + e.Message);
	}
	try {
		this->Height = this->Convert(ResString.SubString(pos+1, ResString.Length()-pos));
	}
	catch (EResolutionError& e) {
		throw EResolutionError(UnicodeString(L"Cannot read height. ") + e.Message);
	}
}
//---------------------------------------------------------------------------

int __fastcall TResolution::Convert(UnicodeString Dim)
{
	if (Dim.IsEmpty()) throw EResolutionError(L"Dimension is empty");

	int result;
	try {
		result = StrToInt(Dim);
	}
	catch (EConvertError& e) {
		throw EResolutionError(UnicodeString(L"Invalid dimension: ") + e.Message);
	}
	if (result<=0) throw EResolutionError(L"Dimension cannot be zero or negative");

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TResolution::IsEmpty()
{
    return this->Width <= 0 || this->Height <= 0;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TResolution::ToString()
{
	if (this->IsEmpty()) {
		throw EResolutionError(L"Resolution is empty.");
	}

	return UnicodeString(this->Width) + L"x" + UnicodeString(this->Height);
}
//---------------------------------------------------------------------------

float __fastcall TResolution::GetAspectRatio()
{
	return this->IsEmpty()? 0.0
		: ((float)this->Width) / ((float)this->Height);
}
//---------------------------------------------------------------------------

int __fastcall TResolution::CheckDim(int Dim)
{
	if ((Dim <= 0) || (this->FEnsureEven && (Dim%2 != 0)))
		throw EResolutionError(L"Attempt to set invalid dimension: " + IntToStr(Dim));

	return Dim;
}
//---------------------------------------------------------------------------

void __fastcall TResolution::setWidth(int Val)
{
	this->FWidth = CheckDim(Val);
}
//---------------------------------------------------------------------------

void __fastcall TResolution::setHeight(int Val)
{
	this->FHeight = CheckDim(Val);
}
//---------------------------------------------------------------------------
