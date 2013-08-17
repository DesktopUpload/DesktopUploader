/*---------------------------------------------------------------------------
$Id: Header.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#pragma hdrstop

#include "Header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "HeaderBase"
#pragma resource "*.dfm"
THeaderFrame *HeaderFrame;
//---------------------------------------------------------------------------

__fastcall THeaderFrame::THeaderFrame(TComponent* Owner)
	: THeaderFrameBase(Owner)
{
}
//---------------------------------------------------------------------------
