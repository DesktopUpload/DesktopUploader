/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#include "Config.h"
#include "TFramework.h"
#pragma hdrstop
//---------------------------------------------------------------------------

#include "XMLMsg.h"
#ifdef CFG_REQUEST_ENCRYPT
	#include "RSA.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Helper functions:
//---------------------------------------------------------------------------
_di_IXMLDocument __fastcall NewXMLMessage(AnsiString RootTag)
{
	_di_IXMLDocument result = NewXMLDocument();
	result->Options >> doAttrNull;

	result->Encoding = L"UTF-8";
	result->Options << doAttrNull;
	//result->Options << doNodeAutoIndent;

	result->AddChild(RootTag);

	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TXMLMessage
//---------------------------------------------------------------------------
__fastcall TXMLMessage::TXMLMessage(AnsiString RootTag)
{
	this->FDoc = NewXMLMessage(RootTag);
}
//---------------------------------------------------------------------------

__fastcall TXMLMessage::~TXMLMessage()
{
	this->FDoc = NULL;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TXMLMessage::ToString()
{
	return this->FDoc->XML->Text;
}
//---------------------------------------------------------------------------

TMemoryStream* __fastcall TXMLMessage::ToStream()
{
	TMemoryStream* result = new TMemoryStream();
	this->FDoc->SaveToStream(result);

	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TXMLRequest
//---------------------------------------------------------------------------
__fastcall TXMLRequest::TXMLRequest(AnsiString Action)
	: TXMLMessage("Request")
{
	_di_IXMLNode root = this->FDoc->DocumentElement;
	root->SetAttribute(L"action", Action);
}
//---------------------------------------------------------------------------

__fastcall TXMLRequest::~TXMLRequest()
{
}
//---------------------------------------------------------------------------

void __fastcall TXMLRequest::SetProperty(AnsiString Name, UnicodeString Value)
{
	_di_IXMLNode root = this->FDoc->DocumentElement;
	_di_IXMLNode node = root->ChildNodes->FindNode(Name);
	if (!node) {
		node = root->AddChild(Name);
	}

	node->SetNodeValue(Value);
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TXMLRequest::GetProperty(AnsiString Name)
{
	_di_IXMLNode root = this->FDoc->DocumentElement;
	_di_IXMLNode node = root->ChildNodes->FindNode(Name);

	return node? node->GetNodeValue().bstrVal : L"";
}
//---------------------------------------------------------------------------
