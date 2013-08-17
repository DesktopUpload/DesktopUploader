/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/
#include "TFramework.h"

#pragma hdrstop
extern TFramework* Framework;

#include "MediaInfoDLL.h"
#include "MediaInfoWrapper.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Parameter read functions
//---------------------------------------------------------------------------
UnicodeString __fastcall ReadStringDef(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0, 
	UnicodeString DefaultValue=L"")
{
	UnicodeString Val = MI->Get(StreamKind, StreamNumber, Name.c_str(),
		MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str();
	return Val.IsEmpty()? DefaultValue : Val;
}
//---------------------------------------------------------------------------	

long double __fastcall ReadFloatDef(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0, 
	long double DefaultValue=-1)
{
	UnicodeString Val = ReadStringDef(Name, MI, StreamKind, StreamNumber);
	try {
		return Val.IsEmpty()? DefaultValue : StrToFloat(Val, Framework->NeutralFormatSettings);
	}
	catch (EConvertError& e) {
		throw EMediaInfoError(UnicodeString(L"Cannot parse ") + Name + L": " + e.Message);
	}
}
//---------------------------------------------------------------------------

__int64 __fastcall ReadIntDef(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0, 
	__int64 DefaultValue=-1)
{
	UnicodeString Val = ReadStringDef(Name, MI, StreamKind, StreamNumber);
	try {
		return Val.IsEmpty()? DefaultValue : StrToInt64(Val);
	}
	catch (EConvertError& e) {
		throw EMediaInfoError(UnicodeString(L"Cannot parse ") + Name + L": " + e.Message);
	}
}
//---------------------------------------------------------------------------

UnicodeString __fastcall ReadString(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0)
{
	UnicodeString Val = MI->Get(StreamKind, StreamNumber, Name.c_str(),
		MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str();

	if (Val.IsEmpty()) {
		throw EMediaInfoError(UnicodeString(L"Cannot read ") + Name);
	}
	return Val;
}
//---------------------------------------------------------------------------

long double __fastcall ReadFloat(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0)
{
	UnicodeString Val = ReadString(Name, MI, StreamKind, StreamNumber);
	try {
		return StrToFloat(Val, Framework->NeutralFormatSettings);
	}
	catch (EConvertError& e) {
		throw EMediaInfoError(UnicodeString(L"Cannot parse ") + Name + L": " + e.Message);
	}
}
//---------------------------------------------------------------------------

__int64 __fastcall ReadInt(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0)
{
	UnicodeString Val = ReadString(Name, MI, StreamKind, StreamNumber);
	try {
		return StrToInt64(Val);
	}
	catch (EConvertError& e) {
		throw EMediaInfoError(UnicodeString(L"Cannot parse ") + Name + L": " + e.Message);
	}
}
//---------------------------------------------------------------------------

__int64 __fastcall ReadBitRate(UnicodeString Name, MediaInfoDLL::MediaInfo* MI,
	MediaInfoDLL::stream_t StreamKind=MediaInfoDLL::Stream_General, size_t StreamNumber=0)
{
	UnicodeString Val = ReadStringDef(Name, MI, StreamKind, StreamNumber);
	int pos = Val.Pos(L"/"); //Check for variable bitrate
	if (pos == 0) {
		return ReadIntDef(Name, MI, StreamKind, StreamNumber);
	}
	//Parse variable bitrate: get first value
	UnicodeString strVal = Val.SubString(1, pos-1).Trim();
	try {
		return strVal.IsEmpty()? -1 : StrToInt64(strVal);
	}
	catch (EConvertError& e) {
		throw EMediaInfoError(UnicodeString(L"Cannot parse ") + Name + L": " + e.Message);
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TMediaInfoWrapper
//---------------------------------------------------------------------------
__fastcall TMediaInfoWrapper::TMediaInfoWrapper(UnicodeString FileName, TMediaType MediaType)
{
	MediaInfoDLL::MediaInfo* MI = new MediaInfoDLL::MediaInfo;
	try {
		if (!MI->IsReady()) throw EMediaInfoError("Cannot initialize MediaInfo library.");
		
		MI->Option(L"Internet", L"No");
		
		if (MI->Open(FileName.c_str()) == 0) throw EMediaInfoError("Cannot open file \'" + FileName + "\'.");

		//General parameters
		this->FVideoCount = ReadIntDef(L"VideoCount", MI, MediaInfoDLL::Stream_General, 0);
		if (MediaType==mtVideo && this->FVideoCount<=0) {
			throw EMediaInfoError(L"Video file is invalid.");
		}
		this->FAudioCount = ReadIntDef(L"AudioCount", MI, MediaInfoDLL::Stream_General, 0, 0);
		if (MediaType==mtAudio && this->FAudioCount<=0) {
			throw EMediaInfoError(L"Audio file is invalid.");
		}

		__int64 duration = ReadInt(L"Duration", MI);
		this->FDuration = duration > 0? (long double)duration/1000 : -1;
		//Video parameters
		this->FVideo_Format = ReadStringDef(L"Format", MI, MediaInfoDLL::Stream_Video);
		this->FVideo_Width = ReadIntDef(L"Width", MI, MediaInfoDLL::Stream_Video);
		this->FVideo_Height = ReadIntDef(L"Height", MI, MediaInfoDLL::Stream_Video);

		this->FVideo_BitRate = ReadBitRate(L"BitRate", MI, MediaInfoDLL::Stream_Video);
		this->FVideo_FrameRate = ReadFloatDef(L"FrameRate", MI, MediaInfoDLL::Stream_Video);
		this->FVideo_DisplayAspectRatio = ReadFloatDef(L"DisplayAspectRatio", MI, MediaInfoDLL::Stream_Video, 0, 1.0);
		this->FVideo_PixelAspectRatio = ReadFloatDef(L"PixelAspectRatio", MI, MediaInfoDLL::Stream_Video, 0, 1.0);
		this->FVideo_DisplayAspectRatio_String = ReadStringDef(L"DisplayAspectRatio/String", MI, MediaInfoDLL::Stream_Video);
		
		//Audio parameters
		this->FAudio_Format = ReadStringDef(L"Format", MI, MediaInfoDLL::Stream_Audio);
		this->FAudio_Channels =  ReadIntDef(L"Channel(s)", MI, MediaInfoDLL::Stream_Audio);;
		this->FAudio_BitRate = ReadBitRate(L"BitRate", MI, MediaInfoDLL::Stream_Audio);
		this->FAudio_SamplingRate = ReadIntDef(L"SamplingRate", MI, MediaInfoDLL::Stream_Audio);
	} 
	catch (EMediaInfoError& e) {
		MI->Close();
		delete MI;
		throw EMediaInfoError(e.Message);
	}
	MI->Close();
	delete MI;
}
//---------------------------------------------------------------------------		
	
