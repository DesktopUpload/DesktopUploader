/*---------------------------------------------------------------------------
$Id: VideoEditor.h 309 2009-07-04 08:41:57Z anton $
---------------------------------------------------------------------------*/
#ifndef VideoEditorH
#define VideoEditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UploadProps.h"
#include "VideoEditorBase.h"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "TGroupTitle.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TVideoEditorForm : public TVideoEditorFormBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TVideoEditorForm(TComponent* AOwner, TMediaItem* MI, bool EditMode=false)
		: TVideoEditorFormBase(AOwner, MI, EditMode) {};
};
//---------------------------------------------------------------------------
extern PACKAGE TVideoEditorForm *VideoEditorForm;
//---------------------------------------------------------------------------
#endif
