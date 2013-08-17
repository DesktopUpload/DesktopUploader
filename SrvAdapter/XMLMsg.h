/*---------------------------------------------------------------------------
$Id: $
---------------------------------------------------------------------------*/
#ifndef XMLMsgH
#define XMLMsgH
//---------------------------------------------------------------------------
#include <XMLDoc.hpp>
#include <IdMultipartFormData.hpp>
//---------------------------------------------------------------------------

class TXMLMessage
{
protected:
	_di_IXMLDocument FDoc;

public:
	__fastcall TXMLMessage(AnsiString RootTag);
	__fastcall ~TXMLMessage();

	UnicodeString __fastcall ToString();
	TMemoryStream* __fastcall ToStream();
};
//---------------------------------------------------------------------------

class TXMLRequest: public TXMLMessage
{
public:
	__fastcall TXMLRequest(AnsiString Action);
	__fastcall ~TXMLRequest();

	void __fastcall SetProperty(AnsiString Name, UnicodeString Value);
	UnicodeString __fastcall GetProperty(AnsiString Name);
	//bool __fastcall WriteToPostData(TIdMultiPartFormDataStream* PostData);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
