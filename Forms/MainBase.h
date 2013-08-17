/*---------------------------------------------------------------------------
$Id: MainBase.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef MainBaseH
#define MainBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <pngimage.hpp>
#include <DdeMan.hpp>
#include <ImgList.hpp>
#include <Forms.hpp>

//Used dialogs
#include "Custom/Login.h"
#include "Custom/VideoEditor.h"
#include "Custom/About.h"
#include "TProgressPanel.h"
#ifdef CUSTOM_YOUTUBE
	#include "Custom/YoutubeGrab.h"
#endif

#include "TProgressPanel.h"

//---------------------------------------------------------------------------
class TMainFormBase : public TForm
{
__published:	// IDE-managed Components
	TImageList *ilItemTypes;
	TPanel *pnlMain;
	TBevel *Bevel2;
	TLabel *lblVideos;
	TButton *btnAdd;
	TButton *btnUpload;
	TButton *btnRemove;
	TButton *btnEdit;
	TListView *lvQueue;
	TLabel *lblTotalSize;
	TButton *btnYouTube;
	TBevel *Bevel3;
	TPanel *pnlHeader;
	TLabel *lblUser;
	TImage *imgLogo;
	TButton *btnLogout;
	TLabel *lblMaxFileSize;
	TTimer *ProgressTimer;
	TLabel *lblVersion;
	TProgressPanel *pnlProgress;
	TImageList *ilItemStates;
	TImage *imgAvatar;

	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnLogoutClick(TObject *Sender);
	void __fastcall imgLogoClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnAddClick(TObject *Sender);
	void __fastcall lvQueueClick(TObject *Sender);
	void __fastcall btnEditClick(TObject *Sender);
	void __fastcall btnRemoveClick(TObject *Sender);
	void __fastcall btnUploadClick(TObject *Sender);
	void __fastcall btnYouTubeClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall lblVersionClick(TObject *Sender);
	void __fastcall ProgressTimerTimer(TObject *Sender);

protected:	// User declarations
	void __fastcall UpdateUI();
	void __fastcall OnLogin();
	void __fastcall OnQueueUpdate();
	void __fastcall Progress(bool Start=true);
	void __fastcall UpdateMediaItem(TListItem* Item);
	void __fastcall ShowProgress(bool Show=true);
	void __fastcall OnProgress();

	TMediaItem* __fastcall GetMediaItem(int Index);

	bool ShowProgressBytes;

	int __fastcall OnMove(TMessage &Msg);
		BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, TMessage, OnMove);
		END_MESSAGE_MAP(TForm);

	bool Busy;
	bool Closing;
	//__int64 TotalInputSize, TotalUploadSize;

	int lblUserLeftAvatar, lblUserLeftNoAvatar;

public:		// User declarations
	__fastcall TMainFormBase(TComponent* Owner);

	//DDE
	void __fastcall ExecuteDDEMacro(TStrings *Msg);

	//Actions
	bool __fastcall AddMedia(UnicodeString FileName = "");
	void __fastcall RemoveMedia(int Index=-1);
	void __fastcall EditMedia();
	#ifdef CUSTOM_YOUTUBE
		bool __fastcall GrabYouTube();
	#endif
	bool __fastcall Login();
	void __fastcall Logout(bool ClearCredentials=true);
	bool __fastcall Upload();

	void __fastcall UpdateMediaItem(int Index);
	void __fastcall AddMediaItem(TMediaItem* MI);

	//UI
	void __fastcall Reactivate();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFormBase *MainFormBase;
//---------------------------------------------------------------------------
#endif
