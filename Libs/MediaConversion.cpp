/*---------------------------------------------------------------------------
$Id: MediaConversion.cpp 521 2011-02-07 14:04:29Z anton $
---------------------------------------------------------------------------*/
#include "Utils.h"
#include "SrvAdapter.h"
#include "TFramework.h"

#pragma hdrstop

#include "MediaConversion.h"

#include <StrUtils.hpp>
#include <System.hpp>
#include <Math.hpp>
#include <Character.hpp>

#include "MediaInfoDLL.h"

extern TSrvAdapterModule* TSrvAdapterModule;
extern TFramework* Framework;
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Timeouts
//---------------------------------------------------------------------------
//Pause between reading responses:
#define EXECUTION_WAIT_TIME 	500
//Time to wait for process to terminate:
#define TERMINATE_WAIT_TIMEOUT 	10000
//Time to wait for thumbnail creation process:
#define THUMBNAIL_TIMEOUT       120000

//---------------------------------------------------------------------------
// FFmpeg command-line options
//---------------------------------------------------------------------------
// Common options:
#define FFMPEG_OPTIONS_GENERAL L"-y"

//---------------------------------------------------------------------------
// Constants for SetOutputRates calcualtions
//---------------------------------------------------------------------------
//Default bit tolerance (bits):
#define DEFUALT_BT					256000
//Default bufsize (bits):
#define DEFUALT_BUFSIZE				4000000
//Allowed audio sampling rates
#define SAMPLING_RATES				{11025, 22050, 44100, 48000}
#define SAMPLING_RATES_COUNT		4
//Allowed audio sampling rates for flv format
#define SAMPLING_RATES_FLV			{11025, 22050, 44100}
#define SAMPLING_RATES_FLV_COUNT	3
//Allowed audio bit rates for libmp3lame
#define AUDIO_BITRATES_MP3			{32000, 40000, 48000, 56000, 64000, 80000, \
96000, 112000, 128000, 144000, 160000, 192000, 224000, 256000, 320000}
#define AUDIO_BITRATES_MP3_COUNT	15
//Max mp3 audio bitrate for limited sampling rate
#define AUDIO_MP3_LIMITED_BITRATE 			160000
#define AUDIO_MP3_LIMITED_SAMPLING_RATE 	22050
//Max audio bitrate for libfaac
#define AUDIO_BITRATE_MAX_FAAC      525000

//---------------------------------------------------------------------------
// TFFmpegConsole
//---------------------------------------------------------------------------
__fastcall TFFmpegConsole::TFFmpegConsole(UnicodeString InputFileName,
	TMediaType MediaType, DWORD PriorityClass)
{
	this->FMediaType = MediaType;
	this->PRIORITY_CLASS = PriorityClass;

	//Init constants
	UnicodeString path = ExtractFilePath(Application->ExeName);
	this->PATH_FFMPEG = L"\"" + path + L"ffmpeg.exe\"";
	this->PATH_MP4BOX = L"\"" + path + L"mp4box.exe\"";
	this->PATH_FLVMETA = L"\"" + path + L"flvmeta.exe\"";

	//Open file with FFmpeg
	this->InputFileName = InputFileName;

	this->MediaInfo = NULL;
	try {
		this->MediaInfo = new TMediaInfoWrapper(this->InputFileName, MediaType);
	}
	catch (EMediaInfoError& e) {
		delete this->MediaInfo; this->MediaInfo = NULL;

		throw EMediaProcessingError(e.Message, L"Cannot read media information");
	}
}
//---------------------------------------------------------------------------

__fastcall TFFmpegConsole::~TFFmpegConsole()
{
	delete this->MediaInfo;
}
//---------------------------------------------------------------------------

int __fastcall TFFmpegConsole::GetNearestRate(int Rate, int Rates[], int Count)
{
	int result = 0;
	for (int i = Count-1; i > 0; i--) {
		if (Rates[i] <= Rate) {
			return Rates[i];
		}
	}
	return Rates[0];
}
//---------------------------------------------------------------------------

void __fastcall TFFmpegConsole::SetOutputRates(UnicodeString &OutputOptions)
{
	UnicodeString format = this->GetOption(OutputOptions, L"f");
	UnicodeString acodec = this->GetOption(OutputOptions, L"acodec");
	if (acodec.IsEmpty()) {
		acodec = (format == L"flv" || format == L"mp3")? L"libmp3lame" :
				 (format == L"mp4")? L"libfaac" :
				 L"";
	}

	if (this->FMediaType == mtVideo) {
		//Limit video bitrate:
		int video_bitrate = this->MediaInfo->Video_BitRate;
		if (video_bitrate > 0) {
			//Extract bt from options
			int bt = this->ParseFFmpegValue((this->GetOption(OutputOptions, L"bt", DEFUALT_BT)));
			if (video_bitrate < 2*bt) { //Overall bitrate is too low
				video_bitrate = 2*bt;
			}

			//Extract maxrate from options
			int maxrate = this->ParseFFmpegValue((this->GetOption(OutputOptions, L"maxrate", L"0")));
			int b = this->ParseFFmpegValue((this->GetOption(OutputOptions, L"b", L"0")));

			if (maxrate == 0) { //not specified
				maxrate = video_bitrate;
				//Use default bitrate option
			}
			else if (video_bitrate < maxrate) {
				maxrate = video_bitrate;
				b = maxrate-bt;  //Set bitrate option
			}

			if (b == 0) b = maxrate-bt; //if not specified

			//Apply limitation:
			OutputOptions = this->SetOption(OutputOptions, L"b", b);
			OutputOptions = this->SetOption(OutputOptions, L"bt", bt);
			OutputOptions = this->SetOption(OutputOptions, L"maxrate", maxrate);
			if (this->GetOption(OutputOptions, L"bufsize").IsEmpty()) {
				OutputOptions = this->SetOption(OutputOptions, L"bufsize", DEFUALT_BUFSIZE);
			}
		}

	//Limit video frame rate
		float video_framerate = this->MediaInfo->Video_FrameRate;
		if (video_framerate > 0) {
			float r = StrToFloat(this->GetOption(OutputOptions, L"r", L"0"), Framework->NeutralFormatSettings);
			if (r == 0 || video_framerate < r) r = video_framerate;
			OutputOptions = this->SetOption(OutputOptions, L"r", FloatToStr(r, Framework->NeutralFormatSettings));
		}
	}

	if (this->MediaInfo->AudioCount > 0) {
	//Limit audio sampling rate
    	int ar = 44100;

		int audio_samplingrate = this->MediaInfo->Audio_SamplingRate;
		if (audio_samplingrate > 0) {
			ar = this->ParseFFmpegValue((this->GetOption(OutputOptions, L"ar", L"0")));
			if (ar == 0 || audio_samplingrate < ar) ar = audio_samplingrate;
			//Find nearest lower or equal allowed rate:
			if (format == L"flv") {
				int rates[] = SAMPLING_RATES_FLV;
				ar = GetNearestRate(ar, rates, SAMPLING_RATES_FLV_COUNT);
			}
			else {
				int rates[] = SAMPLING_RATES;
				ar = GetNearestRate(ar, rates, SAMPLING_RATES_COUNT);
			}
			OutputOptions = this->SetOption(OutputOptions, L"ar", ar);
		}

	//Limit audio bitrate
		int audio_bitrate = this->MediaInfo->Audio_BitRate;
		if (audio_bitrate > 0) {
			int ab = this->ParseFFmpegValue((this->GetOption(OutputOptions, L"ab", L"0")));
			if (ab == 0 || audio_bitrate < ab) ab = audio_bitrate;

			if (acodec == L"libmp3lame") {
				int rates[] = AUDIO_BITRATES_MP3;
				if (ar <= AUDIO_MP3_LIMITED_SAMPLING_RATE
					&& ab > AUDIO_MP3_LIMITED_BITRATE)
				{
					ab = AUDIO_MP3_LIMITED_BITRATE;
				}

				ab = GetNearestRate(ab, rates, AUDIO_BITRATES_MP3_COUNT);
			}
			else if (acodec == L"libfaac") {
				if (ab > AUDIO_BITRATE_MAX_FAAC) ab = AUDIO_BITRATE_MAX_FAAC;
			}

			OutputOptions = this->SetOption(OutputOptions, L"ab", ab);
		}

	//Limit audio channels
		int audio_channels = this->MediaInfo->Audio_Channels;
		if (audio_channels > 0) {
			int ac = StrToInt(this->GetOption(OutputOptions, L"ac", L"0"));
			if (ac == 0 || audio_channels < ac) ac = audio_channels;
			if (acodec == L"libmp3lame" && ac > 2) ac = 2;
			OutputOptions = this->SetOption(OutputOptions, L"ac", ac);
		}
	}
	else {
		OutputOptions = this->SetOption(OutputOptions, L"an");
		OutputOptions = this->RemoveOption(OutputOptions, "acodec");
		OutputOptions = this->RemoveOption(OutputOptions, "ab");
		OutputOptions = this->RemoveOption(OutputOptions, "ar");
		OutputOptions = this->RemoveOption(OutputOptions, "ac");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFFmpegConsole::TranscodePass(UnicodeString Command, UnicodeString WorkDir,
	UnicodeString OutputFileName, __int64 MaxFileSize,
	float ProgressOffset, float ProgressGain)
{
	Command = AddSpace(Command)
		+ (OutputFileName.IsEmpty()?
		UnicodeString(L"NUL")
		: UnicodeString(L"\"" + OutputFileName + L"\""));

	#ifdef _DEBUG
    	MessageBoxW(NULL, Command.c_str(), L"FFmpeg command", NULL);
	#endif

	TConsoleProcess* cp = new TConsoleProcess;
	TStringList* Lines = new TStringList;
	DWORD error;

	try {
		error = cp->Start(Command, WorkDir.IsEmpty()? Framework->TempDir : WorkDir,
			this->PRIORITY_CLASS);
		if (error) throw EMediaProcessingError(error, L"Cannot start FFmpeg");

		UnicodeString output=L"", buf;

		bool HeaderFound = false;
		float Progress = -1;
		do {
			error = cp->Read(buf);
			if (error) throw EMediaProcessingError(error);

			if (!buf.IsEmpty()) {
				output += buf;
				if (!HeaderFound) {
					if (this->ProcessHeader(output)) { HeaderFound = true; }
				}

				Lines->Text = buf.Trim();

				for (int i = Lines->Count-1; i >= 0; i--) {
					UnicodeString line = Lines->Strings[i];
					if (!ContainsStr(line, L"time=")) continue;

					UnicodeString sTime = StrExtract(line, L"time=", L" ");
					if(!sTime.IsEmpty()) {
						Progress = StrToFloat(sTime, Framework->NeutralFormatSettings) / this->MediaInfo->Duration;
						if (Progress > 1.0) Progress = 1.0;

						break;
					}
				}
			}
			else {
				__asm nop;
			}

			if (!OutputFileName.IsEmpty() && MaxFileSize>0
				&& FileGetSize(OutputFileName) > MaxFileSize)
			{
				this->Terminate(cp);
				throw EMediaProcessingError(L"Maximum file size exeeded.");
			}

			if (Progress >= 0) {
				Progress = ProgressOffset + (Progress * ProgressGain);
			}
			if (!SrvAdapterModule->FFmpegProgress(Progress)) {
				this->Terminate(cp);
				Abort();
			}
		} while (cp->Wait(EXECUTION_WAIT_TIME)==0);
		SrvAdapterModule->FFmpegProgress(ProgressOffset + (1.00 * ProgressGain));

		if (cp->Read(buf) == 0) output += buf;

		this->CheckResult(cp, output);
	}
	catch (EMediaProcessingError& e) {
		delete cp;
		delete Lines;
		DeleteFile(OutputFileName);

		if (e.FailedOperation.IsEmpty())
			e.FailedOperation = L"Cannot convert " + this->InputFileName;
		throw EMediaProcessingError(e);
	}
	catch (EAbort&)	{
		delete cp;
		delete Lines;

		Abort();
	}

	delete cp;
	delete Lines;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::Transcode_Command(
	UnicodeString FFmpegPath,
	UnicodeString InputOptions,	UnicodeString OutputOptions, UnicodeString WatermarkOptions,
	UnicodeString Preset, unsigned short Pass)
{
	UnicodeString result = FFmpegPath + L" " + FFMPEG_OPTIONS_GENERAL + L" "
		+ AddSpace(InputOptions) + "-i \"" + this->InputFileName + L"\" " + AddSpace(OutputOptions);

	bool watermark = !WatermarkOptions.IsEmpty();

	if (watermark) result += AddSpace(WatermarkOptions);

	//Add encoding preset:
	if (!Preset.IsEmpty()) {
		if (watermark? FFMPEG_WATERMARK_SUPPORT_PRESETS : FFMPEG_SUPPORT_PRESETS) {
		//Presets are supported
			result += L"-vpre \""
				+ ExtractFilePath(Application->ExeName) + Preset + L".ffpreset\" ";
		}
		else {
		//Presets aren't supported - convert preset values to command line options:
			TFileStream* fs = new TFileStream(ExtractFilePath(Application->ExeName) + Preset + L".ffpreset", fmOpenRead);
			TStringList* sl = new TStringList;
			sl->LoadFromStream(fs);
			delete fs;
			for (int i = 0; i < sl->Count; i++) {
				result += L" -" + sl->Names[i] + L" " + sl->ValueFromIndex[i];
			}
		}
	}

	if (Pass) result = AddSpace(result) + L"-pass " + UnicodeString(Pass);

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TFFmpegConsole::Transcode(UnicodeString OutputFileName,
	UnicodeString InputOptions, UnicodeString OutputOptions,
	__int64 MaxFileSize,
	UnicodeString Preset1, UnicodeString Preset2, bool Pass2,
	UnicodeString WatermarkOptions)
{
	if (this->InputFileName.IsEmpty()) throw Exception(L"No file open.");

	InputOptions = AddSpace(InputOptions);
	OutputOptions = AddSpace(OutputOptions);

	bool watermark = !WatermarkOptions.IsEmpty();

	UnicodeString workdir;
	if (Pass2 || watermark) {
		workdir = AddBS(Framework->GetNewTempDir());

		if (watermark) {
			try {
				Framework->CopyDir(AddBS(ExtractFilePath(Application->ExeName)) + L"FFmpeg.vhooks", workdir);
			}
			catch (EFrameworkError& e) {
				Framework->RemoveDir(workdir);
				throw EMediaProcessingError(e.Message, L"Cannot copy FFmpeg files");
			}
		}
	}

	UnicodeString ffmpegPath = watermark? workdir + "FFmpeg.exe" : this->PATH_FFMPEG;

	UnicodeString cmd;
	try {
		if (Pass2) {
			SrvAdapterModule->Progress->SubOperation = L"1st pass";
			cmd = this->Transcode_Command(ffmpegPath, InputOptions,
				this->SetOption(OutputOptions, L"an"), WatermarkOptions, Preset1, 1);
			this->TranscodePass(cmd, workdir, L"", 0, 0.00, 0.50);

			SrvAdapterModule->Progress->SubOperation = L"2nd pass";
			cmd = this->Transcode_Command(ffmpegPath, InputOptions,
				OutputOptions, WatermarkOptions, Preset2, 2);
			this->TranscodePass(cmd, workdir, OutputFileName, MaxFileSize, 0.50, 0.50);
		}
		else {
			cmd = this->Transcode_Command(ffmpegPath, InputOptions,
				OutputOptions, WatermarkOptions, Preset1);
			this->TranscodePass(cmd, workdir, OutputFileName, MaxFileSize);
		}
	}
	catch (EMediaProcessingError& e) {
        DeleteFile(OutputFileName);
		if (!workdir.IsEmpty()) Framework->RemoveDir(workdir);
		throw EMediaProcessingError(e);
	}
	catch (EAbort&)	{
		DeleteFile(OutputFileName);
	}
	if (!workdir.IsEmpty()) Framework->RemoveDir(workdir);
}
//---------------------------------------------------------------------------

DWORD __fastcall TFFmpegConsole::Run(TConsoleProcess* CP, UnicodeString Command,
	__int64 Timeout)
{
	#ifdef _DEBUG
    	MessageBoxW(NULL, Command.c_str(), L"FFmpeg command", NULL);
	#endif

	DWORD error = CP->Start(Command, Framework->TempDir, this->PRIORITY_CLASS);
	if (error) return error;

	__int64 time = 0;
	do {
		if (!SrvAdapterModule->FFmpegProgress(-1.0)) Abort();

		if (Timeout > 0) {
			if (time > Timeout) throw EMediaProcessingError(L"Execution timeout");
			time += EXECUTION_WAIT_TIME;
		}
	}
	while (CP->Wait(EXECUTION_WAIT_TIME)==0);

	UnicodeString buf;
	error = CP->Read(buf);
	if (error) throw EMediaProcessingError(error);
	this->CheckResult(CP, buf);

	return 0;
}
//---------------------------------------------------------------------------

void __fastcall TFFmpegConsole::MakeThumbnail(UnicodeString OutputFileName,
	long double Time, UnicodeString Options)
{
	TConsoleProcess* cp = new TConsoleProcess;
	DWORD error;

	bool altCmd = false;
	if (L"MPEG Video" == this->MediaInfo->Video_Format) {
		altCmd = true;
	}

	try {
		error = this->Run(cp,
			this->GetThumbnailCommand(altCmd?1:0, OutputFileName, Time, Options),
			THUMBNAIL_TIMEOUT);
		if (error) throw EMediaProcessingErrorFatal(error, L"Cannot start FFmpeg");

		if (!FileExists(OutputFileName) || FileGetSize(OutputFileName)==0) {
			error = this->Run(cp,
				this->GetThumbnailCommand(altCmd?0:1, OutputFileName, Time, Options),
				THUMBNAIL_TIMEOUT);
			if (!FileExists(OutputFileName) || FileGetSize(OutputFileName)==0) {
				throw EMediaProcessingErrorRecoverable(L"Thumbnail not created.");
			}
		}
	}
	catch (EMediaProcessingErrorRecoverable& e) {
		delete cp;

		DeleteFile(OutputFileName);

		throw EMediaProcessingErrorRecoverable(e);
	}
	catch (EMediaProcessingErrorFatal& e) {
		delete cp;

		DeleteFile(OutputFileName);

		if (e.FailedOperation.IsEmpty())
			e.FailedOperation = L"Cannot produce thumbnail for " + this->InputFileName;
		throw EMediaProcessingErrorFatal(e);
	}
	catch (EAbort&)
	{
		DeleteFile(OutputFileName);
	}

	delete cp;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::GetThumbnailCommand(unsigned short Type,
		UnicodeString OutputFileName, long double Time,
		UnicodeString Options)
{
	UnicodeString result;
    UnicodeString time_string = this->FormatTime(Time);

	switch (Type) {
	case 1:
		result = this->PATH_FFMPEG + L" " + FFMPEG_OPTIONS_GENERAL + L" "
			+ L"-an " + L" -vframes 1 "
			+ L" -i \"" + this->InputFileName + L"\" "
			+ L" -f image2 -an " + "-ss " + time_string + L" "
			+ Options + L" \"" + OutputFileName + "\"";
		break;

	default:
		result = this->PATH_FFMPEG + L" " + FFMPEG_OPTIONS_GENERAL + L" "
				+ L"-an " + "-ss " + time_string + L" -vframes 1 "
				+ L" -i \"" + this->InputFileName + L"\" "
				+ L" -f image2 -an "
				+ Options + L" \"" + OutputFileName + "\"";
	}

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TFFmpegConsole::ProcessHeader(UnicodeString &Output, bool SearchErrorMsg)
{
	TStringList* Lines = new TStringList;
	Lines->Text = Output;

	if (Lines->Count==0) return false;

	Lines->Delete(0); //Remove copyright line

	while (Lines->Count>0 && Lines->Strings[0].SubString(1, 1)==L" ") {
		Lines->Delete(0);
	}
	if (Lines->Count == 0) return false;

	if (SearchErrorMsg) {
		UnicodeString msg = Lines->Strings[0].Trim();
		if (!msg.IsEmpty() && !StartsStr(L"Input", msg) && !StartsStr(L"[", msg))
			throw EMediaProcessingError(msg);
	}

	Output = Lines->Text;

	delete Lines;
	return true;
}
//---------------------------------------------------------------------------

void __fastcall TFFmpegConsole::CheckResult(TConsoleProcess* CP, UnicodeString Output)
{
	DWORD code;
	DWORD error = CP->GetExitCode(code);
	if (error) throw EMediaProcessingError(error);
	if (code) { //Find error message
		TStringList* Lines = new TStringList;
		Lines->Text = Output.Trim();
		UnicodeString line = Lines->Strings[Lines->Count-1].Trim();

        Lines->SaveToFile(Framework->TempDir + "FFmpeg_error.log");

		delete Lines;

		throw EMediaProcessingError(line);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFFmpegConsole::Terminate(TConsoleProcess* CP)
{
	if (!CP->Terminate(TERMINATE_WAIT_TIMEOUT)) {
		throw Exception(L"Failed to terminate FFmpeg process");
	}
}
//---------------------------------------------------------------------------

int RoundToEven(float Val)
{
	int result = Floor(Val+0.5);
	if (result % 2) {
		result += ((float)result < Val)? +1 : -1;
	}
	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::GetResizeOptions(TResolution* TargetRes,
	bool KeepAspect, AnsiString PadColor, bool UsePadFilter)
{
	if (this->MediaInfo->Video_Width==0 || this->MediaInfo->Video_Height==0) return L"";

	float source_width = this->MediaInfo->Video_Width;
	if (KeepAspect) source_width*= this->MediaInfo->Video_PixelAspectRatio;
	float source_height = this->MediaInfo->Video_Height;

	float calc_width, calc_height;
	if (TargetRes) {
		calc_width = TargetRes->Width;
		calc_height = TargetRes->Height;
	}
	else {
		calc_width = source_width;
		calc_height = source_height;
	}

	if (KeepAspect && (source_width > calc_width || source_height > calc_height)) {
		//Keep aspect

		float source_aspect = source_width / source_height;
		if (source_aspect > TargetRes->GetAspectRatio()) { //keep width
			calc_height = calc_width / source_aspect;
		}
		else { //keep height
			calc_width = calc_height * source_aspect;
		}
	}

	int width = RoundToEven(calc_width);
	int height = RoundToEven(calc_height);

	UnicodeString result = UnicodeString(L"-s ") + IntToStr(width) + L"x" + IntToStr(height);
	if (PadColor.IsEmpty()) { //No padding
		result += L" -aspect " + FloatToStr((double)width / (double)height,
        	Framework->NeutralFormatSettings);

		return result;
	}

	//Padding
	if (UsePadFilter) {
		//Reset the result - use target sizes:
		result = UnicodeString(L"-s ") + IntToStr(TargetRes->Width) + L"x" + IntToStr(TargetRes->Height);

		int x=0;
		int y=0;

		if (TargetRes->Width != width) {
			x = RoundToEven(((float)TargetRes->Width - (float)width)/2.0);
		}
		if (TargetRes->Height != height) {
			y = RoundToEven(((float)TargetRes->Height - (float)height)/2.0);
		}
		//width:height:x:y:color
		result += L" -vf \"scale=" +  IntToStr(width) + L":" + IntToStr(height) + L","
		+ "pad=" + IntToStr(TargetRes->Width) + L":" + IntToStr(TargetRes->Height) + L":"
		+ IntToStr(x) + L":" + IntToStr(y) + L":"
		+ L"0x" + PadColor
		+ L"\"";
	}
	else {
		//Use legacy pad options:
		int padleft=0;
		int padright=0;
		int padtop=0;
		int padbottom=0;

		if (TargetRes->Width != width) {
			padleft = RoundToEven(((float)TargetRes->Width - (float)width)/2.0);
			padright = TargetRes->Width - width - padleft;
		}
		if (TargetRes->Height != height) {
			padtop = RoundToEven(((float)TargetRes->Height - (float)height)/2.0);
			padbottom = TargetRes->Height - height - padtop;
		}

		if (padleft > 0) result += UnicodeString(L" -padleft ") + IntToStr(padleft);
		if (padright > 0) result += UnicodeString(L" -padright ") + IntToStr(padright);
		if (padtop > 0) result += UnicodeString(L" -padtop ") + IntToStr(padtop);
		if (padbottom > 0) result += UnicodeString(L" -padbottom ") + IntToStr(padbottom);

		result += UnicodeString(L" -padcolor ") + PadColor;

		result += " -aspect " + FloatToStr((double)TargetRes->Width / (double)TargetRes->Height,
			Framework->NeutralFormatSettings);
	}

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::GetWatermarkOptions(TResolution* TargetRes,
	UnicodeString FileName, TWatermarkPos Position, int OffsetX, int OffsetY)
{
	if (FileName.IsEmpty()) {
		return L"";
	}

	int width, height, posX, posY;
    if (TargetRes) {
		width = TargetRes->Width;
		height = TargetRes->Height;
	}
	else {
		width = this->MediaInfo->Video_Width;
		height = this->MediaInfo->Video_Height;
	}

	if (Position==wpTopRight || Position==wpBottomRight) {
		posX = width - OffsetX;
	}
	else {
		posX = OffsetX;
	}
	if (Position==wpBottomLeft || Position==wpBottomRight) {
		posY = height - OffsetY;
	}
	else {
		posY = OffsetY;
	};

	if (posX<0) posX = 0;
	if (posY<0) posY = 0;

	UnicodeString result = UnicodeString(L"-vhook \"vhook\\imlib2.dll")
	+ L" -x " + IntToStr(posX)
	+ L" -y " + IntToStr(posY)
	+ L" -i \"" + FileName + L"\"\"";

	return result;
}

//---------------------------------------------------------------------------
// Post-processing
//---------------------------------------------------------------------------
void __fastcall TFFmpegConsole::PostProcessMP4(UnicodeString FileName)
{
	TConsoleProcess* cp = new TConsoleProcess;
	TStringList* Lines = new TStringList;
	DWORD error;

	try {
		error = cp->Start(this->PATH_MP4BOX + L" -inter 0.001 "
			+ L"\"" + FileName + L"\"",
			Framework->TempDir, this->PRIORITY_CLASS);
		if (error) throw EMediaProcessingError(error, L"Cannot start MP4Box");

		UnicodeString output=L"", buf;
		float progress = 0.00;
		do {
			error = cp->Read(buf);
			if (error) throw EMediaProcessingError(error);
			if (buf.IsEmpty()) continue;

			output += buf;
			Lines->Text = buf.Trim();

			for (int i = Lines->Count-1; i >= 0; i--) {
				UnicodeString line = Lines->Strings[i];
				if (!StartsStr(L"ISO File Writing:", line)) continue;

				UnicodeString sPrc = StrExtract(line, L"| (", L"/100)");
				if(!sPrc.IsEmpty()) {
					progress = StrToFloat(sPrc, Framework->NeutralFormatSettings) / 100;
					break;
				}
			}

			if (!SrvAdapterModule->FFmpegProgress(progress)) {
				this->Terminate(cp);
				DeleteFile(FileName);
				Abort();
			}
		}
		while (cp->Wait(EXECUTION_WAIT_TIME)==0);
		SrvAdapterModule->FFmpegProgress(1.00);

		if (cp->Read(buf) == 0) output += buf;

		this->CheckResult(cp, output);
	}
	catch (EMediaProcessingError& e) {
		delete cp;
		delete Lines;

		//DeleteFile(FileName);

		if (e.FailedOperation.IsEmpty())
			e.FailedOperation = L"MP4 streaming failed";
		throw EMediaProcessingError(e);
	}
	catch (EAbort&)
	{
		__asm nop;
	}

	delete cp;
	delete Lines;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::PostProcessFLV(UnicodeString FileName)
{
    UnicodeString outfile;
	try {
		outfile = Framework->GetNewTempFile();
    }
	catch (EFrameworkError& e) {
		throw new EMediaProcessingError(e.Message);
	}

	TConsoleProcess* cp = new TConsoleProcess;
	DWORD error;

	double inSize = FileGetSize(FileName);
	double outSize = 0;

	try {
		error = cp->Start(this->PATH_FLVMETA + L" "
			+ L"\"" + FileName + L"\" "
			+ L"\"" + outfile + L"\"",
			Framework->TempDir,
			this->PRIORITY_CLASS);
		if (error) throw EMediaProcessingError(error, L"Cannot start flvmeta");

		UnicodeString output=L"", buf;

		float progress = 0.00;
		do {
			error = cp->Read(buf);
			if (error) throw EMediaProcessingError(error);

			output += buf;

			//Get progress by out file size:
			if (inSize > 0.0) {
				outSize = FileGetSize(outfile);
				progress = outSize/inSize;
				if (progress < 0.0) progress = 0.0;
				else if (progress > 1.0) progress = 1.0;
			}
			else {
				progress = 0.0;
			}

			if (!SrvAdapterModule->FFmpegProgress(progress)) {
				this->Terminate(cp);
				DeleteFile(FileName);
				Abort();
			}
		}
		while (cp->Wait(EXECUTION_WAIT_TIME)==0);
		SrvAdapterModule->FFmpegProgress(1.00);

		if (cp->Read(buf) == 0) output += buf;

		this->CheckResult(cp, output);
	}
	catch (EMediaProcessingError& e) {
		delete cp;

		if (e.FailedOperation.IsEmpty())
			e.FailedOperation = L"FLV metadata injection failed";
		throw EMediaProcessingError(e);
	}
	catch (EAbort&)
	{
		__asm nop;
	}

	delete cp;
	return outfile;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Command line manipulation methods
//---------------------------------------------------------------------------
bool __fastcall TFFmpegConsole::HasOption(UnicodeString Command, UnicodeString Option)
{
	return Pos(L"-"+Option+L" ", Command) > 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
UnicodeString __fastcall TFFmpegConsole::RemoveOption(UnicodeString Command, UnicodeString Option)
{
	Option = L"-"+Option+L" ";

	int begin = Pos(Option, Command);
	if (begin == 0) return Command; //not found

	UnicodeString result = Command.SubString(1, begin-1).Trim();

	int pos = PosEx(L" -", Command, begin + Option.Length());
	if (pos > 0) {
		result += L" " + Command.SubString(pos, Command.Length()-pos+1).Trim();
	}

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::GetOption(UnicodeString Command,
	UnicodeString Option, UnicodeString Default)
{
	UnicodeString result = StrExtract(Command, L"-"+Option+L" ", L" -", false).Trim();
	if (result.IsEmpty()) result = Default;

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFFmpegConsole::SetOption(UnicodeString Command,
	UnicodeString Option, UnicodeString Value)
{
	Option = L"-"+Option+L" ";

	int begin = Pos(Option, Command);

	UnicodeString result = (begin > 0? Command.SubString(1, begin-1) : Command).Trim();

	result += L" " + Option + Value;

	if (begin > 0) {
		int pos = PosEx(L" -", Command, begin + Option.Length());
		if (pos > 0) {
			result += L" " + Command.SubString(pos, Command.Length()-pos+1).Trim();
		}
	}

	return result;
}
//---------------------------------------------------------------------------

__int64 __fastcall TFFmpegConsole::ParseFFmpegValue(UnicodeString Val)
{
	Val = Trim(Val);
	if (TCharacter::IsLetter(Val, Val.Length())) {
		UnicodeString unit = Val.SubString(Val.Length(), 1);
		long mult = 1;
		if 		(unit==L"k" || unit==L"K") mult = 1000;
		else if (unit==L"m" || unit==L"M") mult = 1000000;
		else throw Exception(L"Invalid unit: " + unit + L".");

		return StrToInt64(Val.SubString(1, Val.Length()-1))*mult;
	}

	return StrToInt64(Val);
}
//---------------------------------------------------------------------------

UnicodeString __fastcall FormatTime_AddLeadingZeros(__int64 Number, short Digits=2)
{
	UnicodeString result = IntToStr(Number);
	short length = result.Length();
	if (length < Digits) result = StringOfChar('0', Digits-length) + result;
	return result;
}

UnicodeString __fastcall TFFmpegConsole::FormatTime(long double Val)
{
	__int64 seconds_count = Int(Val);
	UnicodeString result = IntToStr(seconds_count);
	result += L"." + FormatTime_AddLeadingZeros(Frac(Val)*1000, 3);

	return result;
}
//---------------------------------------------------------------------------

