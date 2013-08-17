/*---------------------------------------------------------------------------
$Id: YoutubeGrab.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include "Custom.h"
#include "TProgressPanel.h"
#include "UploadProps.h"
#include "YoutubeGrabBase.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
#ifdef CUSTOM_YOUTUBE

#include "TProgressPanel.h"
#include "UploadProps.h"
#include "YoutubeGrabBase.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>

#ifndef YoutubeGrabH
#define YoutubeGrabH
//---------------------------------------------------------------------------

#include "TProgressPanel.h"
#include "UploadProps.h"
#include "YoutubeGrabBase.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>

//---------------------------------------------------------------------------
class TYoutubeGrabForm : public TYoutubeGrabFormBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TYoutubeGrabForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TYoutubeGrabForm *YoutubeGrabForm;
//---------------------------------------------------------------------------
#endif

#endif
