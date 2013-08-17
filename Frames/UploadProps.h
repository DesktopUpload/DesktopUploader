/*---------------------------------------------------------------------------
$Id: UploadProps.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef UploadPropsH
#define UploadPropsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>

#include "MediaItem.h"
#include "TGroupTitle.h"
//---------------------------------------------------------------------------
class TUploadProperties : public TFrame
{
__published:	// IDE-managed Components
	TLabel *lblCategories;
	TCheckListBox *clbCategories;
	TRadioGroup *rgpBroadcast;
	TGroupTitle *Title;
	TComboBox *cbxCategory;
private:	// User declarations
	TMediaType FMediaType;
	int MaxCategories;
	bool SingleCategoryMode;

public:		// User declarations
	__fastcall TUploadProperties(TComponent* Owner);
	__fastcall ~TUploadProperties();

	void __fastcall Init(TMediaType MediaType, bool Ini=true);
	void __fastcall Save(TMediaItem* MI);
	void __fastcall Restore(TMediaItem* MI);
	void __fastcall SaveToIni();
	void __fastcall CheckCategories();
	TWinControl* __fastcall GetCategoryControl();

	TStringList* CategoryIDs;
};
//---------------------------------------------------------------------------
extern PACKAGE TUploadProperties *UploadProperties;
//---------------------------------------------------------------------------
#endif
