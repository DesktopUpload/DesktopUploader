/*---------------------------------------------------------------------------
$Id: DdeClient.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include "Custom/Custom.h"
#pragma hdrstop

#include "DdeClient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall TDdeClient::TDdeClient()
{
	this->Conv = new TDdeClientConv(NULL);
	this->Conv->ConnectMode = ddeManual;
	this->Conv->SetLink(UnicodeString(CUSTOM_EXE_NAME), "System");
	this->Conv->ServiceApplication = NULL;
}
//---------------------------------------------------------------------------

__fastcall TDdeClient::~TDdeClient()
{
	delete this->Conv;
}
//---------------------------------------------------------------------------

bool __fastcall TDdeClient::Connect()
{
	return this->Conv->OpenLink();
}
//---------------------------------------------------------------------------

void __fastcall TDdeClient::Exec(UnicodeString Cmd)
{
	this->Conv->ExecuteMacro(Cmd.t_str(), false);
}
//---------------------------------------------------------------------------


