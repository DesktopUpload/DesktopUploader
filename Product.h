/*---------------------------------------------------------------------------
$Id: Product.h 522 2011-02-07 14:58:50Z anton $
---------------------------------------------------------------------------*/
#ifndef ProductH
#define ProductH

//---------------------------------------------------------------------------
#include "SvnInfo.h"
#include "Macros.h"

//Begin of settings

//Verson:
#define VER_MAJOR				1
#define VER_MINOR				4
#define VER_RELEASE				8   		//Uncomment if non-zero only
#define VER_BUILD				SVN_REV     //Set by SubWCRev on pre-build

//Names:
#define PRODUCT_NAME				CUSTOM_PRODUCT_NAME
#define	PRODUCT_EXE_NAME			QUOTE(CUSTOM_EXE ## .exe)

//Company, copyrights, trademarks:
#define PRODUCT_COMPANYNAME			"Desktop Upload"
#define PRODUCT_COPYRIGHT			"© 2009 - 2010 DesktopUpload.com"
#define	PRODUCT_TRADEMARKS			"Desktop Upload, Desktop Uploader, DesktopUpload.com"

//Credits:
#define PRODUCT_ORIGINAL_DEVELOPER	"Anton Oliinyk"
#define PRODUCT_PROJECT_MANAGER 	"Frank White"

//Sites, URLs:
#define PRODUCT_SITE_NAME 			"DesktopUpload.com"
#define PRODUCT_SITE_URL 			"http://desktopupload.com"
#define PRODUCT_BUG_TRACKER 		"http://bugs.desktopupload.com"
#define PRODUCT_CONTACT_URL			"http://desktopupload.com"
#define PRODUCT_SUPPORT_URL			"http://support.desktopupload.com"

//End of  settings

#ifdef VER_RELEASE
	#define PRODUCT_VERSION     QUOTE(VER_MAJOR.VER_MINOR.VER_RELEASE)
#else
	#define PRODUCT_VERSION     QUOTE(VER_MAJOR.VER_MINOR)
	#define VER_RELEASE 		0
#endif

#define PRODUCT_VERSION_STRICT  QUOTE(VER_MAJOR.VER_MINOR.VER_RELEASE.VER_BUILD)

#endif
