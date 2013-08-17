/*---------------------------------------------------------------------------
$Id: MediaConversion.h 521 2011-02-07 14:04:29Z anton $
---------------------------------------------------------------------------*/
#ifndef MediaConversionH
#define MediaConversionH

#include <vcl.h>
#include "BaseExceptions.h"
#include "ConsoleProcess.h"
#include "MediaInfoWrapper.h"
#include "SrvInfo.h"

//---------------------------------------------------------------------------
// FFmpeg handling options
//---------------------------------------------------------------------------
// Specifies if normal & watermark-enabled FFmpeg builds support presets:
#define FFMPEG_SUPPORT_PRESETS           		false
#define FFMPEG_WATERMARK_SUPPORT_PRESETS		false
// Specifies if normal & watermark-enabled FFmpeg builds support pad video filter (-vf):
#define FFMPEG_REQUIRE_FILTER_PAD          		false
#define FFMPEG_WATERMARK_REQUIRE_FILTER_PAD		false

//---------------------------------------------------------------------------
// TFFmpegConsole
//---------------------------------------------------------------------------
class TFFmpegConsole
{
public:
	__fastcall TFFmpegConsole(UnicodeString InputFileName, TMediaType MediaType,
		DWORD PriorityClass);
	__fastcall ~TFFmpegConsole();

	UnicodeString InputFileName;
	TMediaInfoWrapper* MediaInfo;

	void __fastcall Transcode(UnicodeString OutputFileName,
		UnicodeString InputOptions=L"", UnicodeString OutputOptions=L"",
		__int64 MaxFileSize=0,
		UnicodeString Preset1 = L"", UnicodeString Preset2 = L"", bool Pass2 = false,
		UnicodeString WatermarkOptions=L"");
	void __fastcall MakeThumbnail(UnicodeString OutpuFileName, long double Time,
		UnicodeString Options=L"");
	void __fastcall PostProcessMP4(UnicodeString FileName);
	UnicodeString __fastcall PostProcessFLV(UnicodeString FileName);
	UnicodeString __fastcall GetResizeOptions(TResolution* TargetRes=NULL,
		bool KeepAspect=false, AnsiString PadColor="",
		bool UsePadFilter=FFMPEG_REQUIRE_FILTER_PAD);
	UnicodeString __fastcall GetWatermarkOptions(TResolution* TargetRes,
		UnicodeString FileName, TWatermarkPos Position, int OffsetX, int OffsetY);
	void __fastcall SetOutputRates(UnicodeString &OutputOptions);

	static bool __fastcall HasOption(UnicodeString Command, UnicodeString Option);
	static UnicodeString __fastcall RemoveOption(UnicodeString Command, UnicodeString Option);
	static UnicodeString __fastcall GetOption(UnicodeString Command,
		UnicodeString Option, UnicodeString Default=L"");
	static UnicodeString __fastcall SetOption(UnicodeString Command,
		UnicodeString Option, UnicodeString Value=L"");
	static __int64 __fastcall ParseFFmpegValue(UnicodeString Val);
	static UnicodeString __fastcall FormatTime(long double Val);

protected:
	DWORD PRIORITY_CLASS;

	UnicodeString PATH_FFMPEG;
	UnicodeString PATH_MP4BOX;
	UnicodeString PATH_FLVMETA;

	TMediaType FMediaType;

	bool __fastcall ProcessHeader(UnicodeString &Output, bool SearchErrorMsg=false);
	void __fastcall CheckResult(TConsoleProcess* CP, UnicodeString Output);
	void __fastcall Terminate(TConsoleProcess* CP);
	DWORD __fastcall Run(TConsoleProcess* CP, UnicodeString Command, __int64 Timeout=0);
	int __fastcall GetNearestRate(int Rate, int Rates[], int Count);
	void __fastcall TranscodePass(UnicodeString Command, UnicodeString WorkDir,
		UnicodeString OutputFileName, __int64 MaxFileSize,
		float ProgressOffset=0.00, float ProgressGain=1.00);
	UnicodeString __fastcall Transcode_Command(UnicodeString FFmpegPath,
		UnicodeString InputOptions, UnicodeString OutputOptions,
		UnicodeString WatermarkOptions,
		UnicodeString Preset, unsigned short Pass=0);
	UnicodeString __fastcall GetThumbnailCommand(unsigned short Type,
		UnicodeString OutputFileName, long double Time,
		UnicodeString Options=L"");
};
//---------------------------------------------------------------------------
// EMediaProcessingError (general error)
//---------------------------------------------------------------------------
class EMediaProcessingError : public EWinAPIError
{
public:
	__fastcall EMediaProcessingError(UnicodeString Msg, UnicodeString FailedOperation=L"")
		:EWinAPIError(Msg, FailedOperation) {};
	__fastcall EMediaProcessingError(DWORD ErrorCode, UnicodeString FailedOperation=L"")
		:EWinAPIError(ErrorCode, FailedOperation) {};
};
//---------------------------------------------------------------------------
// EMediaProcessingErrorFatal (fatal error)
//---------------------------------------------------------------------------
class EMediaProcessingErrorFatal : public EMediaProcessingError
{
public:
	__fastcall EMediaProcessingErrorFatal(UnicodeString Msg, UnicodeString FailedOperation=L"")
		:EMediaProcessingError(Msg, FailedOperation) {};
	__fastcall EMediaProcessingErrorFatal(DWORD ErrorCode, UnicodeString FailedOperation=L"")
		:EMediaProcessingError(ErrorCode, FailedOperation) {};
};
//---------------------------------------------------------------------------
// EMediaProcessingErrorRecoverable (non-fatal error)
//---------------------------------------------------------------------------
class EMediaProcessingErrorRecoverable : public EMediaProcessingError
{
public:
	__fastcall EMediaProcessingErrorRecoverable(UnicodeString Msg)
		:EMediaProcessingError(Msg) {};
};

//---------------------------------------------------------------------------
#endif
