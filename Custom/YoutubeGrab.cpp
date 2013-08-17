/*---------------------------------------------------------------------------
$Id: YoutubeGrab.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include "Custom.h"
#ifdef CUSTOM_YOUTUBE

#include <vcl.h>
#pragma hdrstop

#include "YoutubeGrab.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "YoutubeGrabBase"
#pragma link "TProgressPanel"
#pragma link "TProgressPanel"
#pragma link "UploadProps"
#pragma link "TProgressPanel"
#pragma link "UploadProps"
#pragma link "YoutubeGrabBase"
#pragma link "TProgressPanel"
#pragma link "UploadProps"
#pragma link "YoutubeGrabBase"
#pragma resource "*.dfm"
//TYoutubeGrabForm *YoutubeGrabForm;
//---------------------------------------------------------------------------

__fastcall TYoutubeGrabForm::TYoutubeGrabForm(TComponent* Owner)
	: TYoutubeGrabFormBase(Owner)
{
}
//---------------------------------------------------------------------------
#endif
