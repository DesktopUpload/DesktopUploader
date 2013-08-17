/*---------------------------------------------------------------------------
$Id: VideoEditorBase.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef VideoEditorBaseH
#define VideoEditorBaseH
//----------------------------------------------------------------------------
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>

#include "MediaItem.h"
#include "UploadProps.h"
#include "TGroupTitle.h"
//----------------------------------------------------------------------------

class EMediaEditorException : public Exception
{
public:
	__fastcall EMediaEditorException(UnicodeString Message=L"User Cancel")
		: Exception(Message) {};
};
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
class TVideoEditorFormBase : public TForm
{
__published:
	TButton *btnOK;
	TButton *btnCancel;
	TOpenDialog *dlgOpen;
	TSaveDialog *dlgSave;
	TPageControl *Pages;
	TTabSheet *Main;
	TTabSheet *Optional;
	TDateTimePicker *dtpDate;
	TLabel *lblDate;
	TLabel *lblCountry;
	TLabel *lblLocation;
	TComboBox *cmbCountry;
	TEdit *edtLocation;
	TCheckBox *chkAllowComment;
	TCheckBox *chkAllowVoting;
	TCheckBox *chkAllowRating;
	TCheckBox *chkAllowEmbedding;
	TPanel *pnlMain;
	TButton *btnBrowse;
	TEdit *edtFile;
	TEdit *edtTags;
	TEdit *edtTitle;
	TLabel *lblTitle;
	TLabel *lblDescription;
	TLabel *lblTags;
	TLabel *lblFile;
	TMemo *memDescription;
	TUploadProperties *UploadProperties;
	TPanel *pnlTorrent;
	TButton *btnTorrentBrowse;
	TEdit *edtTorrent;
	TLabel *lblTorrent;
	TBevel *Bevel5;
	TPanel *pnlBottomField;
	TOpenDialog *dlgTorrent;
	TGroupTitle *gtInfo;
	TGroupTitle *gtOptional1;
	TGroupTitle *gtOptional2;
	TPanel *pnlFormat;
	TGroupTitle *gtFormat;
	TComboBox *cmbUploadFormat;
	TPanel *pnlVideo;
	TCheckBox *chkDeinterlace;
	TCheckBox *chkPass2;
	TOpenDialog *dlgPicture;
	TPanel *pnlPicture;
	TLabel *lblPicture;
	TBevel *Bevel1;
	TButton *btnPictureBrowse;
	TEdit *edtPicture;
	void __fastcall btnBrowseClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall chkPass2Click(TObject *Sender);
	void __fastcall chkDeinterlaceClick(TObject *Sender);
	void __fastcall btnTorrentBrowseClick(TObject *Sender);
	void __fastcall edtFileEnter(TObject *Sender);
	void __fastcall edtFileExit(TObject *Sender);
	void __fastcall edtTorrentEnter(TObject *Sender);
	void __fastcall edtTorrentExit(TObject *Sender);
	void __fastcall cmbUploadFormatChange(TObject *Sender);
	void __fastcall btnPictureBrowseClick(TObject *Sender);
	void __fastcall edtPictureEnter(TObject *Sender);
	void __fastcall edtPictureExit(TObject *Sender);
protected:
	int __fastcall OnMove(TMessage &Msg);
		BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, TMessage, OnMove);
		END_MESSAGE_MAP(TForm);

	void __fastcall UpdateUI();
	bool __fastcall SaveData();
	bool __fastcall SaveFile();
	bool __fastcall OpenTorrentFile(UnicodeString FileName=L"");
	bool __fastcall OpenPictureFile(UnicodeString FileName=L"");

	TMediaType MediaType;
	TMediaItemType MediaItemType;
	UnicodeString UploadFormat;
	bool NativeFormat;

	bool Pass2, oldPass2;
	bool Deinterlace, oldDeinterlace;

	bool EditMode;

	UnicodeString oldFile, oldTorrent, oldPicture;
	bool InplaceEditError;
public:
	virtual __fastcall TVideoEditorFormBase(TComponent* AOwner, TMediaItem* MI,
		bool EditMode=false);

	//void __fastcall UpdateUploadFormat();
	bool __fastcall OpenFile(UnicodeString FileName=L""); //Public for access from main form

	TMediaItem *MediaItem;
};
//----------------------------------------------------------------------------
extern PACKAGE TVideoEditorFormBase *VideoEditorFormBase;
//----------------------------------------------------------------------------
#endif
