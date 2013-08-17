/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/
#ifndef MediaInfoWrapperH
#define MediaInfoWrapperH

#include <Classes.hpp>
#include "SrvInfo.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TMediaInfoWrapper
//---------------------------------------------------------------------------
class TMediaInfoWrapper
{
protected:
	long double FDuration;
	short FVideoCount, FAudioCount;

	UnicodeString FVideo_Format;
	int FVideo_Width, FVideo_Height;
	int FVideo_BitRate;
	int FVideo_FrameRate;
	float FVideo_DisplayAspectRatio, FVideo_PixelAspectRatio;
	UnicodeString FVideo_DisplayAspectRatio_String;

	UnicodeString FAudio_Format;
	int FAudio_BitRate;
	int FAudio_SamplingRate;
	short FAudio_Channels;
public:
	__fastcall TMediaInfoWrapper(UnicodeString FileName, TMediaType MediaType);

	__property long double Duration = {read=FDuration, write=FDuration};
	__property short VideoCount = {read=FVideoCount};
	__property short AudioCount = {read=FAudioCount};

	__property UnicodeString Video_Format = {read=FVideo_Format};
	__property int Video_Width = {read=FVideo_Width};
	__property int Video_Height = {read=FVideo_Height};
	__property int Video_BitRate = {read=FVideo_BitRate};
	__property int Video_FrameRate = {read=FVideo_FrameRate};
	__property float Video_DisplayAspectRatio = {read=FVideo_DisplayAspectRatio};
	__property float Video_PixelAspectRatio = {read=FVideo_PixelAspectRatio};
	__property UnicodeString Video_DisplayAspectRatio_String = {read=FVideo_DisplayAspectRatio_String};

	__property UnicodeString Audio_Format = {read=FAudio_Format};
	__property int Audio_BitRate = {read=FAudio_BitRate};
	__property int Audio_SamplingRate = {read=FAudio_SamplingRate};
	__property short Audio_Channels = {read=FAudio_Channels};
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// EMediaInfoError
//---------------------------------------------------------------------------
class EMediaInfoError: public Exception
{
public:
	__fastcall EMediaInfoError(UnicodeString Message) : Exception(Message) {};
};

//---------------------------------------------------------------------------
#endif
