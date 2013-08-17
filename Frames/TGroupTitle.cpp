//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TGroupTitle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGroupTitle *GroupTitle;
//---------------------------------------------------------------------------
__fastcall TGroupTitle::TGroupTitle(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TGroupTitle::Init()
{
	int width = this->Label->Canvas->TextWidth(this->Label->Caption + L" ");

	this->Bevel->Left = this->Label->Left + width;
	this->Bevel->Width = this->Width - this->Bevel->Left;

	this->Label->Transparent = true;
}
//---------------------------------------------------------------------------
