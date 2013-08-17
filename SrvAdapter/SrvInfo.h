/*---------------------------------------------------------------------------
$Id: SrvInfo.h 526 2011-02-09 22:10:55Z fwhite $
---------------------------------------------------------------------------*/
#ifndef SrvInfoH
#define SrvInfoH

#include <Types.hpp>
#include <Classes.hpp>
//---------------------------------------------------------------------------

// Media type handling:
enum TMediaType			{mtNone=-1, mtVideo=0, mtAudio=1, mtImage=2};
#define COUNT_TMediaType 3 //Count of media types
UnicodeString __fastcall MediaTypeToStr(TMediaType MediaType);
TMediaType 	  __fastcall StrToMediaType(UnicodeString Str);

//Watermark positions:
enum TWatermarkPos {wpTopLeft=1, wpTopRight=2, wpBottomRight=3, wpBottomLeft=4};
UnicodeString __fastcall WatermarkPosToStr(TWatermarkPos Pos);
TWatermarkPos __fastcall StrToWatermarkPos(UnicodeString Str);

//---------------------------------------------------------------------------
// TResolution
//---------------------------------------------------------------------------
class TResolution
{
public:
	__fastcall TResolution(bool EnsureEven=false);
	__fastcall TResolution(int Width, int Height, bool EnsureEven=false);
	__fastcall TResolution(UnicodeString ResString, bool EnsureEven=false);
	bool __fastcall IsEmpty();
	void __fastcall SetByString(UnicodeString ResString);
	UnicodeString __fastcall ToString();
	float __fastcall GetAspectRatio();

	__property int Width = {read=FWidth, write=setWidth};
	__property int Height = {read=FHeight, write=setHeight};

protected:
	int FWidth, FHeight;
	int __fastcall Convert(UnicodeString Dim);

	void __fastcall setWidth(int Val);
	void __fastcall setHeight(int Val);
	int __fastcall CheckDim(int Dim);

	bool FEnsureEven;
};
//---------------------------------------------------------------------------

class EResolutionError : public Exception
{
public:
	__fastcall EResolutionError(UnicodeString Message)
		: Exception(Message) {};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvResponse
//---------------------------------------------------------------------------
class  TSrvResponseValID
{
private:
	UnicodeString FName, FLegacyName, FMediaType;
	bool FDefaultMedia;
	UnicodeString __fastcall getFullName();
public:
	__fastcall TSrvResponseValID(UnicodeString Name, UnicodeString MediaType=L"",
		bool DefaultMedia=false, UnicodeString LegacyName=L"");

	__property UnicodeString Name = {read=FName};
	__property UnicodeString LegacyName = {read=FLegacyName};
	__property UnicodeString FullName = {read=getFullName};
	__property UnicodeString MediaType = {read=FMediaType};
	__property bool DefaultMedia = {read=FDefaultMedia};
};
//---------------------------------------------------------------------------

class TSrvResponse : public TStringList
{
private:
public:
	__fastcall TSrvResponse(UnicodeString ResponseText);

	int StatusCode;
	UnicodeString ErrorMessage;
	UnicodeString AvatarURL;
	UnicodeString WatermarkURL;

	UnicodeString __fastcall Read(TSrvResponseValID ID);
	UnicodeString __fastcall ReadString(TSrvResponseValID ID, UnicodeString DefVal=L"",
		bool MultiLine=false);
	__int64 __fastcall ReadInt(TSrvResponseValID ID, __int64 DefVal=0);
	int __fastcall ReadEnum(TSrvResponseValID ID, int Min, int Max, int DefVal=0);
	bool __fastcall ReadBool(TSrvResponseValID ID, bool DefVal=false);
	TResolution* __fastcall ReadResolution(TSrvResponseValID ID, UnicodeString DefStr);
	TStringList* __fastcall ReadList(TSrvResponseValID ID, UnicodeString DefStr=L"");
};
//---------------------------------------------------------------------------

class ESrvResponseError : public Exception
{
public:
	__fastcall ESrvResponseError(UnicodeString Message)
		: Exception(Message) {};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvMediaSettings
//---------------------------------------------------------------------------
enum TSRTorrentOption 	{srtoDisable=0, srtoEnable=1, srtoRequire=2};
#define MIN_TSRTorrentOption srtoDisable
#define MAX_TSRTorrentOption srtoRequire

class TSrvMediaSettings
{
private:
	__int64 FMaxFileSize;
	TCollection* 		FCategories;
	TStringList* 		FFormats;
	TStringList* 		FAllowExts;
	TStringList* 		FNativeExts;

protected:
	bool 				FAllNative;
	bool                FExternalOnly;

public:
	__fastcall TSrvMediaSettings(TSrvResponse* Response, UnicodeString MediaName,
		bool DefaultMedia, UnicodeString DefaultExts);
	__fastcall ~TSrvMediaSettings();

	__property __int64 MaxFileSize = {read=FMaxFileSize};

	__property TCollection* 		Categories = {read=FCategories};
	__property TStringList* 		AllowExts = {read=FAllowExts};
	__property TStringList* 		NativeExts = {read=FNativeExts};
	__property TStringList* 		Formats = {read=FFormats};
	__property bool					AllNative = {read=FAllNative};
	__property bool					ExternalOnly = {read=FExternalOnly, write=FExternalOnly}; //allow public access for setting from TSrvSettings constructor
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvVideoSettings
//---------------------------------------------------------------------------
enum TSRResizeType 		{srrtNoResize=0, srrtStretch=1, srrtKeepAspectRatio=2};
#define MIN_TSRResizeType srrtNoResize
#define MAX_TSRResizeType srrtKeepAspectRatio

class TSrvVideoSettings : public TSrvMediaSettings
{
private:
	TResolution* 		FResolution;
	TResolution* 		FThumbResolution;
	TResolution* 		FBigThumbResolution;
	TStringList* 		FYouTubeFormats;

	TSRResizeType     	FResizeType;
	TSRTorrentOption    FAllowTorrents;

	bool				FThumbPadding;
	int					FThumbCount;
    int					FThumbCountBig;
	bool 				FAllowYTDownload, FAllowYTEmbed, FYTDownloadThumbnails;
	bool				FMkvAsDivx;
	bool				FReTranscodeMP4;

	bool				FWatermarkEnabled;
	TWatermarkPos 		FWatermarkPosition;
	int					FWatermarkOffsetX, FWatermarkOffsetY;

public:
	__fastcall TSrvVideoSettings(TSrvResponse* Response);
	__fastcall ~TSrvVideoSettings();

	__property TResolution* 	Resolution = {read=FResolution};
	__property TResolution* 	ThumbResolution	= {read=FThumbResolution};
	__property TResolution* 	BigThumbResolution = {read=FBigThumbResolution};
	__property TStringList* 	YouTubeFormats = {read=FYouTubeFormats};

	__property TSRResizeType 	ResizeType = {read=FResizeType};
	__property bool         	ThumbPadding = {read=FThumbPadding};
	__property int         		ThumbCount = {read=FThumbCount};
    __property int         		ThumbCountBig = {read=FThumbCountBig};
	__property bool				AllowYTDownload	= {read=FAllowYTDownload};
	__property bool				AllowYTEmbed = {read=FAllowYTEmbed};
	__property bool				YTDownloadThumbnails = {read=FYTDownloadThumbnails};
	__property bool				MkvAsDivx = {read=FMkvAsDivx};
	__property bool				ReTranscodeMP4	= {read=FReTranscodeMP4};

	__property bool				WatermarkEnabled = {read=FWatermarkEnabled};
	__property TWatermarkPos  	WatermarkPosition = {read=FWatermarkPosition};
	__property int				WatermarkOffsetX = {read=FWatermarkOffsetX};
	__property int				WatermarkOffsetY = {read=FWatermarkOffsetY};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvAudioSettings
//---------------------------------------------------------------------------
class TSrvAudioSettings : public TSrvMediaSettings
{
private:
	bool FRequirePicture;
public:
	__fastcall TSrvAudioSettings(TSrvResponse* Response);
	__fastcall ~TSrvAudioSettings();

	__property bool RequirePicture = {read=FRequirePicture};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvImageSettings
//---------------------------------------------------------------------------
class TSrvImageSettings : public TSrvMediaSettings
{
public:
	__fastcall TSrvImageSettings(TSrvResponse* Response);
	__fastcall ~TSrvImageSettings();
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvSettings
//---------------------------------------------------------------------------
class TSrvCategory: public TCollectionItem
{
public:
	__fastcall TSrvCategory(TCollection* Collection);
	__fastcall ~TSrvCategory();
	UnicodeString Label;
	long ID;
};

//---------------------------------------------------------------------------
class TSrvMediaFormat: public TObject
{
public:
	__fastcall TSrvMediaFormat();

	UnicodeString Label;
	UnicodeString FileExt;
	UnicodeString InternetMediaType;
	UnicodeString FFmpegOptions;

	UnicodeString Preset;
	UnicodeString PresetPass1;
	UnicodeString PresetPass2;

	bool EnablePass2;
};
//---------------------------------------------------------------------------
class TYouTubeFormat: public TObject
{
public:
	__fastcall TYouTubeFormat();

	UnicodeString Label;
	int QualityLevel;
};
//---------------------------------------------------------------------------

class TSrvSettings
{
protected:
	TStringList* 		FErrorHandling;
	TSRTorrentOption    FAllowTorrents;
	bool                FDisplayAvatar;
	bool				FExternalOnly;
	bool				FAllowEmptyFields;

	TSrvVideoSettings* 	FVideo;
	TSrvAudioSettings* 	FAudio;
	TSrvImageSettings* 	FImage;

	TSrvMediaSettings* __fastcall getMediaSettings(TMediaType Type);
	bool __fastcall getMultiMedia();

	DWORD FExternalProcessPriority;
		DWORD __fastcall ParsePriority(AnsiString Str);
	int FMaxCategories;

public:
	__fastcall TSrvSettings(TSrvResponse* Response);
	__fastcall ~TSrvSettings();

	__property TStringList* 	ErrorHandling = {read=FErrorHandling};
	__property TSRTorrentOption	AllowTorrents	= {read=FAllowTorrents};
	__property bool				DisplayAvatar 	= {read=FDisplayAvatar};
	__property bool				ExternalOnly = {read=FExternalOnly};
	__property bool 			AllowEmptyFields = {read=FAllowEmptyFields};

	__property TSrvVideoSettings* Video = {read=FVideo};
	__property TSrvAudioSettings* Audio = {read=FAudio};
	__property TSrvImageSettings* Image = {read=FImage};

	__property TSrvMediaSettings* Media[TMediaType Type] = {read=getMediaSettings};
	__property bool MultiMedia = {read=getMultiMedia};

	__property DWORD ExternalProcessPriority = {read=FExternalProcessPriority};
	__property int MaxCategories = {read=FMaxCategories};
};
//---------------------------------------------------------------------------
#endif
