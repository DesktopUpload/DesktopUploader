/*---------------------------------------------------------------------------
$Id: Custom.h 518 2010-11-22 18:05:56Z fwhite $
---------------------------------------------------------------------------*/
#ifndef CustomH
#define CustomH

#include "Macros.h"

/*---------------------------------------------------------------------------
	Define demo or dev mode
----------------------------------------------------------------------------*/

//Enable demo version limits:
//#define SWITCH_DEMO_VERSION

/*---------------------------------------------------------------------------
	Sandbox server selection.
	Only one can be enabled at the same time.
	Disable in retail version.
----------------------------------------------------------------------------*/

//#define SWITCH_LOCAL_SERVER	// localhost
#define SWITCH_DEV_SERVER 		// dev.desktopupload.com
//#define SWITCH_CBV1_DEMO		// ClipBucket v1 Demo
//#define SWITCH_CBV2_DEMO		// ClipBucket v2 Demo

/*---------------------------------------------------------------------------
	Define target system
---------------------------------------------------------------------------*/

//#define AVS_TARGET
#define CLIPBUCKET_TARGET
//#define CLIPHOUSE_TARGET
//#define CLIPSHARE_TARGET
//#define GENERIC_TARGET
//#define MEDIAMAX_TARGET
//#define MEDIASHARE_TARGET
//#define PHPBB3_TARGET
//#define PHPMELODY_TARGET
//#define PHPMOTION_TARGET
//#define SHAREIGNITER_TARGET
//#define VSHARE_TARGET

/*---------------------------------------------------------------------------
	Password Handling
----------------------------------------------------------------------------*/

// plaintext password
// #define PLAINTEXT_PASSWORD

#if defined PHPBB3_TARGET
	#define PLAINTEXT_PASSWORD
#endif

// MD5 password
//#define MD5_PASSWORD

#if defined AVS_TARGET || defined CLIPHOUSE_TARGET || defined CLIPSHARE_TARGET || defined MEDIASHARE_TARGET || defined PHPMELODY_TARGET || defined PHPMOTION_TARGET || defined SHAREIGNITER_TARGET || defined VSHARE_TARGET
	#define MD5_PASSWORD
#endif

/*---------------------------------------------------------------------------
	Custom Settings
----------------------------------------------------------------------------*/

// enabled features
//#define CUSTOM_AUDIO_ON
//#define CUSTOM_IMAGE_ON
#define CUSTOM_VIDEO_ON

// YouTube
//#define CUSTOM_YOUTUBE

// User Avatar
//#define CUSTOM_UI_LBLUSER_LEFT_NO_AVATAR		8

// Ping (keep alive) interval in seconds:
#define CUSTOM_PING_INTERVAL	600

/*
 	For custom systems:

	CUSTOM_MAX_CATEGORIES specifies maximum
	category selection.
	0 = unlimited
*/
//#define CUSTOM_MAX_CATEGORIES	0

#if defined AVS_TARGET || defined CLIPHOUSE_TARGET || defined PHPMELODY_TARGET || defined PHPMOTION_TARGET
	#define CUSTOM_MAX_CATEGORIES	1
#endif

#if defined MEDIASHARE_TARGET
	#define CUSTOM_MAX_CATEGORIES 2
#endif

#if defined CLIPBUCKET_TARGET || defined CLIPSHARE_TARGET || defined SHAREIGNITER_TARGET || defined VSHARE_TARGET
	#define CUSTOM_MAX_CATEGORIES	3
#endif

#define CUSTOM_PRODUCT_NAME 	L"ClipBucket Desktop Uploader"
#define CUSTOM_EXE				clipbucket
/*
 	CUSTOM_SITE_NAME is used in the Windows shell extension
	and the installer.
	A descriptive name is recommended.
*/
#define CUSTOM_SITE_NAME   		L"ClipBucket v1 Dev Server"
// Displayed in title bar
#define CUSTOM_SITE_CAPTION    	L"Desktop Upload Development Server"
// define useragent
#define CUSTOM_USERAGENT		L"ClipBucket Desktop Uploader"

// HTTP requests go to this domain name
#define CUSTOM_DOMAIN			"dev.desktopupload.com"
/*
 	For custom systems, where auxillary pages
	differ from CUSTOM_DOMAIN
	ex: phpBB
*/
//#define CUSTOM_AUTH_URL			UnicodeString("http://domain.tld/")
#define CUSTOM_UPLOAD_URL		UnicodeString(CUSTOM_SITE_URL) + L"desktop"

#define CUSTOM_SITE_URL			UnicodeString("http://") + CUSTOM_DOMAIN + L"/"
#define CUSTOM_GUID				UnicodeString(CUSTOM_DOMAIN) + L"." + L"57BB7895-C8F4-4412-B702-2FFF690216D2"
#define CUSTOM_SALT				UnicodeString("krgP7^-Z8hfjnTW*cDKa")

#ifdef AVS_TARGET
	#define CUSTOM_PAGE_FORGOT		L"lost"
	#define CUSTOM_PAGE_SIGNUP 		L"signup"
#endif

#ifdef CLIPBUCKET_TARGET
	#define CUSTOM_PAGE_FORGOT		L"forgot.php"
	#define CUSTOM_PAGE_SIGNUP 		L"signup.php"
#endif

#ifdef CLIPHOUSE_TARGET
	#define CUSTOM_PAGE_FORGOT		L"index.php?page=forgot"
	#define CUSTOM_PAGE_SIGNUP		L"index.php?page=join"
#endif

#ifdef CLIPSHARE_TARGET
	#define CUSTOM_PAGE_FORGOT		L"recoverpassword"
	#define CUSTOM_PAGE_SIGNUP 		L"signup"
#endif

// page locations for custom targets
#ifdef GENERIC_TARGET
	#define CUSTOM_PAGE_FORGOT		L"forgot.php"
	#define CUSTOM_PAGE_SIGNUP 		L"signup.php"
#endif

#ifdef MEDIASHARE_TARGET
	#define CUSTOM_PAGE_FORGOT      L"login"
	#define CUSTOM_PAGE_SIGNUP		L"signup"
#endif

#ifdef PHPBB3_TARGET
	#define CUSTOM_PAGE_FORGOT      L"ucp.php?mode=sendpassword"
	#define CUSTOM_PAGE_SIGNUP		L"ucp.php?mode=register"
#endif

#ifdef PHPMELODY_TARGET
	#define CUSTOM_PAGE_FORGOT		L"login.php?do=forgot_pass"
	#define CUSTOM_PAGE_SIGNUP 		L"register.php"
#endif

#ifdef PHPMOTION_TARGET
	#define CUSTOM_PAGE_FORGOT		L"login.php"
	#define CUSTOM_PAGE_SIGNUP 		L"join.php"
#endif

#ifdef SHAREIGNITER_TARGET
	#define CUSTOM_PAGE_FORGOT		L"recover-password/"
	#define CUSTOM_PAGE_SIGNUP 		L"new-account/"
#endif

#ifdef VSHARE_TARGET
	#define CUSTOM_PAGE_FORGOT		L"recoverpass.php"
	#define CUSTOM_PAGE_SIGNUP 		L"signup/"
#endif


/*---------------------------------------------------------------------------
	Default watermarking settings:
----------------------------------------------------------------------------*/
#ifdef SWITCH_DEMO_VERSION
	#define CUSTOM_DEFAULT_WATERMARK_ENABLED 	true
#else
	#define CUSTOM_DEFAULT_WATERMARK_ENABLED 	false
#endif

#define CUSTOM_DEFAULT_WATERMARK_POSITION	"top-right"
#define CUSTOM_DEFAULT_WATERMARK_OFFSET_X	188
#define CUSTOM_DEFAULT_WATERMARK_OFFSET_Y	20

/*---------------------------------------------------------------------------
	Demo Restrictions:
----------------------------------------------------------------------------*/

#ifdef SWITCH_DEMO_VERSION
	// Max files in upload queue
	#define DEMO_QUEUE_LIMIT 			2
	// Video duration limit in seconds
	#define DEMO_VIDEO_DURATION_LIMIT	30
	// Force filesize limit (bytes)
	#define DEMO_MAX_FILESIZE           62914560
#endif

/*---------------------------------------------------------------------------
	Sandbox Server URLs:
-----------------------------------------------------------------------------*/

#ifdef SWITCH_LOCAL_SERVER
	#undef  CUSTOM_UPLOAD_URL
	#define CUSTOM_UPLOAD_URL	L"http://localhost/dev/rsa/test.php"
#endif

#ifdef SWITCH_DEV_SERVER
	#undef  CUSTOM_UPLOAD_URL
	#define CUSTOM_UPLOAD_URL	L"http://dev.desktopupload.com/desktop"
#endif

#ifdef SWITCH_SWITCH_CBV1_DEMO
	#undef  CUSTOM_UPLOAD_URL
	#define CUSTOM_UPLOAD_URL	L"http://v1.clipbucket.desktopupload.com/desktop"
#endif

#ifdef SWITCH_SWITCH_CBV2_DEMO
	#undef  CUSTOM_UPLOAD_URL
	#define CUSTOM_UPLOAD_URL	L"http://v2.clipbucket.desktopupload.com/desktop"
#endif

/*---------------------------------------------------------------------------
	Proxy server:
-----------------------------------------------------------------------------*/

// Proxy IP or domain name to override target system settings
//#define CUSTOM_PROXY_SERVER "127.0.0.1"

// Proxy port (required if CUSTOM_PROXY_SERVER defined)
//#define CUSTOM_PROXY_PORT 808

// Proxy credentials to use as defaults.
// If not accpeted INI file setting will be used or user will be queried
//#define CUSTOM_PROXY_USERNAME "user"
//#define CUSTOM_PROXY_PASSWORD "123"

/*---------------------------------------------------------------------------
	Post procerssing:
-----------------------------------------------------------------------------*/
// Force YouTube, audio and picture support for debug builds on dev site:
#ifdef SWITCH_DEV_SERVER
	#if defined _DEBUG && !defined CUSTOM_YOUTUBE
		#define CUSTOM_YOUTUBE
		#define CUSTOM_AUDIO_ON
		#define CUSTOM_IMAGE_ON
	#endif
#endif

#define CUSTOM_EXE_NAME			QUOTE(CUSTOM_EXE)

#endif
