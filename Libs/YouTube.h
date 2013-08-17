/*---------------------------------------------------------------------------
$Id: YouTube.h 503 2010-09-14 09:17:07Z anton $
---------------------------------------------------------------------------*/
#ifndef YouTubeH
#define YouTubeH
//---------------------------------------------------------------------------
#include "MediaItem.h"
#include "Custom/Custom.h"
//---------------------------------------------------------------------------
//Link templates
#define YT_LINK 			L"http://www.youtube.com/watch?v=%0:s"
#define YT_LINK_TOKEN 		L"http://www.youtube.com/get_video_info?video_id=%0:s"
//#define YT_LINK_WORKAROUND	L"http://clipbucketdemo.com/get_yt.php?v=%0:s"
#ifndef _DEBUG
	#define YT_LINK_INFO		L"http://gdata.youtube.com/feeds/api/videos/%0:s"
#else
	#define YT_LINK_INFO		L"http://stage.gdata.youtube.com/feeds/api/videos/%0:s?v=2"
#endif
#define YT_LINK_THUMB       L"http://img.youtube.com/vi/%0:s/%1:s.jpg"
#define YT_EMBED_CODE		L"<object width=\"560\" height=\"340\"><param name=\"movie\" value=\"http://www.youtube.com/v/%0:s&fs=1\"></param><param name=\"allowFullScreen\" value=\"true\"></param><param name=\"allowscriptaccess\" value=\"always\"></param><embed src=\"http://www.youtube.com/v/%0:s&fs=1\" type=\"application/x-shockwave-flash\" allowscriptaccess=\"always\" allowfullscreen=\"true\" width=\"560\" height=\"340\"></embed></object>"
#define YT_SHORT 			L"youtube.com?v=%s"
//Quality levels and fmt
#define YT_FORMATS_COUNT		7
#define YT_FORMATS				{0, 6, 35, 18, 37, 22, 44, 45}
#define YT_FORMATS_STR			{"flv", "flv", "flv", "mp4", "mp4", "mp4", "mp4", "mp4"} //must correspond to YT_FORMATS
#define YT_QUALITYLEVEL_NORMAL	0
#define YT_QUALITYLEVEL_HD		6
//---------------------------------------------------------------------------

#ifdef CUSTOM_YOUTUBE
void __fastcall YT_ExtractInfoXML(TMediaItem* MI, UnicodeString XML);
void __fastcall YT_ExtractInfoHTML(TMediaItem* MI, UnicodeString HTML);
UnicodeString __fastcall YT_ComposeDownloadLink(UnicodeString ID, UnicodeString Token, int Quality);
TStringList* __fastcall YT_ParseFmtMap(UnicodeString Map);
UnicodeString __fastcall YT_ExpractID(UnicodeString URL);
UnicodeString __fastcall YT_FmtToStr(int Fmt);
#endif
//---------------------------------------------------------------------------
#endif

