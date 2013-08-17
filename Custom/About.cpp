/*---------------------------------------------------------------------------
$Id: About.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#pragma hdrstop

#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AboutBase"
#pragma link "Header"
#pragma link "HeaderBase"
#pragma resource "*.dfm"
//TAboutBox *AboutBox;
//---------------------------------------------------------------------------

__fastcall TAboutBox::TAboutBox(TComponent* Owner)
	: TAboutBoxBase(Owner)
{
}
//---------------------------------------------------------------------------
