/*---------------------------------------------------------------------------
$Id: Config.h 526 2011-02-09 22:10:55Z fwhite $
---------------------------------------------------------------------------*/
#ifndef ConfigH
#define ConfigH

//---------------------------------------------------------------------------
//Configuration options:
//---------------------------------------------------------------------------
//Color for padding thumbnails on aspect ratio maintenance:
#define CFG_PADCOLOR_THUMBS				"000000"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Protocol options
//---------------------------------------------------------------------------
#define CFG_REQUEST_VER2 //Enable encrypted XML request
#define CFG_RESPONSE_VER2 //Enable RSA decryption of response

//Login request:
#define CFG_LOGIN_REQUEST_EXECUTABLE_SHA1  //Send executable SHA1
#define CFG_LOGIN_REQUEST_VERSION_SHA1   //Send version SHA1

//Encryption settings:
#define CFG_SIGNATUREKEY_LENGTH 1024 //Signature key length in bits
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Default protocol values:
//---------------------------------------------------------------------------
//General settings
#define CFG_DEFAULT_ALLOWTORRENTS 		srtoDisable
#define CFG_DEFAULT_DISPLAYAVATAR		false
#define CFG_DEFAULT_ERRORHANDLING 		""

//Common media settings
#define CFG_DEFAULT_MAXFILESIZE 			0
#define CFG_DEFAULT_VIDEO_ALLOWUPLOAD		true
#define CFG_DEFAULT_AUDIO_ALLOWUPLOAD		false
#define CFG_DEFAULT_IMAGE_ALLOWUPLOAD		false
#define CFG_DEFAULT_VIDEO_ALLOWEXTENSIONS 	"asf,avi,dat,divx,flv,mkv,mov,mp4,mpeg,mpeg4,mpg,m2ts,mts,qt,vob,wmv,xvid"
#define CFG_DEFAULT_AUDIO_ALLOWEXTENSIONS  	"flac,mp3,m4a,ogg,wav,wma"
#define CFG_DEFAULT_IMAGE_ALLOWEXTENSIONS   "bmp,gif,jpeg,jpg,png"
#define CFG_DEFAULT_NO_TRANSCODE			false

#define CFG_DEFAULT_VIDEO_FORMATS			"flv, divx, mp4"
#define CFG_DEFAULT_AUDIO_FORMATS			"mp3"

#define CFG_DEFAULT_ALLOW_EMPTY_FIELDS		true

//Specific video settings
#define CFG_DEFAULT_VIDEO_RESOLUTION 		"320x240"
#define CFG_DEFAULT_THUMBRESOLUTION 		"120x90"
#define CFG_DEFAULT_BIGTHUMBRESOLUTION 		"320x240"
#define CFG_DEFAULT_RESIZETYPE 				srrtKeepAspectRatio
#define CFG_DEFAULT_THUMBPADDING    		true
#define CFG_DEFAULT_ALLOWYTDOWNLOAD			true
#define CFG_DEFAULT_ALLOWYTEMBED			true
#define CFG_DEFAULT_FLV_OPTIONS				"-f flv -b 500k -bt 128k -maxrate 600k -bufsize 260k"
#define CFG_DEFAULT_MP4_OPTIONS             "-f mp4 -threads 0 -vcodec libx264 -b 1250k -bt 256k -maxrate 1500k -bufsize 4M"
#define CFG_DEFAULT_DIVX_OPTIONS            "-f avi -threads 0 -vcodec libxvid -vtag xvid -b 1250k -bt 256k -maxrate 1500k -acodec libmp3lame -ar 44100 -bufsize 4M"
#define CFG_DEFAULT_MKVASDIVX				false
#define CFG_DEFAULT_OUTER_PROCESS_PRIORITY	BELOW_NORMAL_PRIORITY_CLASS
#define CFG_DEFAULT_THUMBNAIL_COUNT_BIG 	1
#define CFG_DEFAULT_THUMBNAIL_COUNT 		3
#define CFG_DEFAULT_VIDEO_NO_TRANSCODE		false
#define CFG_DEFAULT_YT_DOWNLOAD_THUMBNAILS	true
#define CFG_DEFAULT_RETRANSCODE_MP4			true

//Specific audio settings
#define CFG_DEFAULT_AUDIO_REQUIREPICTURE	false
#define CFG_DEFAULT_MP3_OPTIONS				"-f mp3 -threads 0"
#define CFG_DEFAULT_AUDIO_NO_TRANSCODE		false

//Specific image settings
#define CFG_DEFAULT_IMAGE_NO_TRANSCODE		true
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Default user options:
//---------------------------------------------------------------------------
#define CFG_DEFAULT_YTGRABMETHOD			0 //download
#define CFG_DEFAULT_PASS2					false
#define CFG_DEFAULT_DEINTERLACE				false
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Misc options:
//---------------------------------------------------------------------------
#define COPY_FILE_BUFFER 					10485760

#endif
