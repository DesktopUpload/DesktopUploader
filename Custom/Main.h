/*---------------------------------------------------------------------------
$Id: Main.h 185 2009-05-01 12:58:01Z anton $
---------------------------------------------------------------------------*/
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MainBase.h"
#include <ComCtrls.hpp>
#include <DdeMan.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <GIFImg.hpp>
#include "TProgressPanel.h"
//---------------------------------------------------------------------------
class TMainForm : public TMainFormBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
