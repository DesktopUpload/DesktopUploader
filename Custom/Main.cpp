/*---------------------------------------------------------------------------
$Id: Main.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>

#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MainBase"
#pragma link "TProgressPanel"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TMainFormBase(Owner)
{
}
//---------------------------------------------------------------------------
