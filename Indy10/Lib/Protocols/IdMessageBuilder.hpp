// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagebuilder.pas' rev: 20.00

#ifndef IdmessagebuilderHPP
#define IdmessagebuilderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagebuilder
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMessageBuilderAttachment;
class PASCALIMPLEMENTATION TIdMessageBuilderAttachment : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FContentID;
	System::UnicodeString FFileName;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString ContentID = {read=FContentID, write=FContentID};
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdMessageBuilderAttachment(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMessageBuilderAttachment(void) { }
	
};


class DELPHICLASS TIdMessageBuilderAttachments;
class PASCALIMPLEMENTATION TIdMessageBuilderAttachments : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdMessageBuilderAttachment* operator[](int Index) { return Attachment[Index]; }
	
private:
	TIdMessageBuilderAttachment* __fastcall GetAttachment(int Index);
	void __fastcall SetAttachment(int Index, TIdMessageBuilderAttachment* Value);
	
public:
	__fastcall TIdMessageBuilderAttachments(void);
	HIDESBASE TIdMessageBuilderAttachment* __fastcall Add(const System::UnicodeString AFileName, const System::UnicodeString AContentID = L"");
	__property TIdMessageBuilderAttachment* Attachment[int Index] = {read=GetAttachment, write=SetAttachment/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdMessageBuilderAttachments(void) { }
	
};


class DELPHICLASS TIdCustomMessageBuilder;
class PASCALIMPLEMENTATION TIdCustomMessageBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* FAttachments;
	Classes::TStrings* FPlainText;
	System::UnicodeString FPlainTextCharSet;
	void __fastcall AddAttachments(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall InternalFill(Idmessage::TIdMessage* AMsg) = 0 ;
	void __fastcall SetPlainText(Classes::TStrings* AValue);
	void __fastcall SetAttachments(Classes::TStrings* AValue);
	virtual void __fastcall SetContentTypeAndCharSet(Idmessage::TIdMessage* AMsg);
	
public:
	__fastcall virtual TIdCustomMessageBuilder(void);
	__fastcall virtual ~TIdCustomMessageBuilder(void);
	virtual void __fastcall Clear(void);
	void __fastcall FillMessage(Idmessage::TIdMessage* AMsg);
	Idmessage::TIdMessage* __fastcall NewMessage(Classes::TComponent* AOwner = (Classes::TComponent*)(0x0));
	__property Classes::TStrings* Attachments = {read=FAttachments, write=SetAttachments};
	__property Classes::TStrings* PlainText = {read=FPlainText, write=SetPlainText};
	__property System::UnicodeString PlainTextCharSet = {read=FPlainTextCharSet, write=FPlainTextCharSet};
};


class DELPHICLASS TIdMessageBuilderPlain;
class PASCALIMPLEMENTATION TIdMessageBuilderPlain : public TIdCustomMessageBuilder
{
	typedef TIdCustomMessageBuilder inherited;
	
protected:
	virtual void __fastcall InternalFill(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall SetContentTypeAndCharSet(Idmessage::TIdMessage* AMsg);
public:
	/* TIdCustomMessageBuilder.Create */ inline __fastcall virtual TIdMessageBuilderPlain(void) : TIdCustomMessageBuilder() { }
	/* TIdCustomMessageBuilder.Destroy */ inline __fastcall virtual ~TIdMessageBuilderPlain(void) { }
	
};


class DELPHICLASS TIdMessageBuilderHtml;
class PASCALIMPLEMENTATION TIdMessageBuilderHtml : public TIdCustomMessageBuilder
{
	typedef TIdCustomMessageBuilder inherited;
	
protected:
	Classes::TStrings* FHtml;
	System::UnicodeString FHtmlCharSet;
	TIdMessageBuilderAttachments* FHtmlFiles;
	System::UnicodeString FHtmlViewerNeededMsg;
	virtual void __fastcall InternalFill(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall SetContentTypeAndCharSet(Idmessage::TIdMessage* AMsg);
	void __fastcall SetHtml(Classes::TStrings* AValue);
	void __fastcall SetHtmlFiles(TIdMessageBuilderAttachments* AValue);
	
public:
	__fastcall virtual TIdMessageBuilderHtml(void);
	__fastcall virtual ~TIdMessageBuilderHtml(void);
	virtual void __fastcall Clear(void);
	__property Classes::TStrings* Html = {read=FHtml, write=SetHtml};
	__property System::UnicodeString HtmlCharSet = {read=FHtmlCharSet, write=FHtmlCharSet};
	__property TIdMessageBuilderAttachments* HtmlFiles = {read=FHtmlFiles, write=SetHtmlFiles};
	__property System::UnicodeString HtmlViewerNeededMsg = {read=FHtmlViewerNeededMsg, write=FHtmlViewerNeededMsg};
};


#pragma option push -b-
enum TIdMessageBuilderRtfType { idMsgBldrRtfMS, idMsgBldrRtfEnriched, idMsgBldrRtfRichtext };
#pragma option pop

class DELPHICLASS TIdMessageBuilderRtf;
class PASCALIMPLEMENTATION TIdMessageBuilderRtf : public TIdCustomMessageBuilder
{
	typedef TIdCustomMessageBuilder inherited;
	
protected:
	Classes::TStrings* FRtf;
	System::UnicodeString FRtfCharSet;
	TIdMessageBuilderRtfType FRtfType;
	System::UnicodeString FRtfViewerNeededMsg;
	virtual void __fastcall InternalFill(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall SetContentTypeAndCharSet(Idmessage::TIdMessage* AMsg);
	void __fastcall SetRtf(Classes::TStrings* AValue);
	
public:
	__fastcall virtual TIdMessageBuilderRtf(void);
	__fastcall virtual ~TIdMessageBuilderRtf(void);
	virtual void __fastcall Clear(void);
	__property Classes::TStrings* Rtf = {read=FRtf, write=SetRtf};
	__property System::UnicodeString RtfCharSet = {read=FRtfCharSet, write=FRtfCharSet};
	__property TIdMessageBuilderRtfType RtfType = {read=FRtfType, write=FRtfType, nodefault};
	__property System::UnicodeString RtfViewerNeededMsg = {read=FRtfViewerNeededMsg, write=FRtfViewerNeededMsg};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessagebuilder */
using namespace Idmessagebuilder;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagebuilderHPP
