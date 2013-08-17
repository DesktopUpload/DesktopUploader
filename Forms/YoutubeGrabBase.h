/*---------------------------------------------------------------------------
$Id: YoutubeGrabBase.h 466 2010-04-04 14:00:27Z anton $
---------------------------------------------------------------------------*/
#include "Custom/Custom.h"
#include "TProgressPanel.h"
#include "UploadProps.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
#ifdef CUSTOM_YOUTUBE

#ifndef YoutubeGrabBaseH
#define YoutubeGrabBaseH

#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ComCtrls.hpp>

#include "TProgressPanel.h"
#include "UploadProps.h"
#include "YouTube.h"

#include "TProgressPanel.h"
//----------------------------------------------------------------------------
class TYoutubeGrabFormBase : public TForm
{
__published:
	TPanel *pnlMain;
	TUploadProperties *UploadProperties;
	TCheckBox *chkAutoUpload;
	TPanel *pnlButtons;
	TButton *btnOK;
	TButton *btnCancel;
	TBevel *blvBottom;
	TProgressPanel *pnlProgress;
	TTimer *ProgressTimer;
	TPanel *pnlYouTube;
	TComboBox *cmbGrabbingMethod;
	TComboBox *cmbQuality;
	TLabel *lblGrabbingMethod;
	TLabel *lblQuality;
	TLabel *lblTitle;
	TMemo *memLinks;
	TLabel *Label1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnOKClick(TObject *Sender);
	void __fastcall ProgressTimerTimer(TObject *Sender);
	void __fastcall cmbGrabbingMethodCloseUp(TObject *Sender);
protected:
	bool __fastcall GrabDownload();
	bool __fastcall GrabEmbed();
	TStringList* __fastcall PrepareLinks();

	bool Busy;
	void __fastcall Progress(bool Start=true);
	void __fastcall OnProgress();

	void __fastcall SaveSettings();

	int __fastcall OnMove(TMessage &Msg);
		BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, TMessage, OnMove);
		END_MESSAGE_MAP(TForm);

	//TProgressPanel* pnlProgress;

public:
	virtual __fastcall TYoutubeGrabFormBase(TComponent* AOwner);

	bool AutoUpload;
};
//----------------------------------------------------------------------------
extern PACKAGE TYoutubeGrabFormBase *YoutubeGrabFormBase;
//----------------------------------------------------------------------------
#endif

#endif
