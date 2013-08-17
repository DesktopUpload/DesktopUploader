// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idreplyimap4.pas' rev: 20.00

#ifndef Idreplyimap4HPP
#define Idreplyimap4HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idreplyimap4
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<System::UnicodeString, 6> Idreplyimap4__1;

class DELPHICLASS TIdReplyIMAP4;
class PASCALIMPLEMENTATION TIdReplyIMAP4 : public Idreply::TIdReply
{
	typedef Idreply::TIdReply inherited;
	
protected:
	System::UnicodeString FSequenceNumber;
	Classes::TStrings* FExtra;
	Classes::TStrings* __fastcall GetExtra(void);
	virtual Classes::TStrings* __fastcall GetFormattedReply(void);
	virtual void __fastcall SetFormattedReply(const Classes::TStrings* AValue);
	virtual bool __fastcall CheckIfCodeIsValid(const System::UnicodeString ACode);
	
public:
	__fastcall virtual TIdReplyIMAP4(Classes::TCollection* ACollection, Idreply::TIdReplies* AReplyTexts);
	__fastcall virtual ~TIdReplyIMAP4(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall RaiseReplyError(void);
	void __fastcall DoReplyError(System::UnicodeString ADescription, System::UnicodeString AnOffendingLine = L"");
	void __fastcall RemoveUnsolicitedResponses(System::UnicodeString *AExpectedResponses, const int AExpectedResponses_Size);
	bool __fastcall DoesLineHaveExpectedResponse(System::UnicodeString ALine, System::UnicodeString *AExpectedResponses, const int AExpectedResponses_Size);
	bool __fastcall IsItAValidSequenceNumber(const System::UnicodeString AValue);
	bool __fastcall ParseRequest(System::UnicodeString ARequest);
	__property int NumericCode = {read=GetNumericCode, write=SetNumericCode, nodefault};
	__property Classes::TStrings* Extra = {read=GetExtra};
	__property System::UnicodeString SequenceNumber = {read=FSequenceNumber};
public:
	/* TIdReply.Create */ inline __fastcall virtual TIdReplyIMAP4(Classes::TCollection* ACollection) : Idreply::TIdReply(ACollection) { }
	
};


class DELPHICLASS TIdRepliesIMAP4;
class PASCALIMPLEMENTATION TIdRepliesIMAP4 : public Idreply::TIdReplies
{
	typedef Idreply::TIdReplies inherited;
	
public:
	__fastcall TIdRepliesIMAP4(Classes::TPersistent* AOwner);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdRepliesIMAP4(void) { }
	
};


class DELPHICLASS EIdReplyIMAP4Error;
class PASCALIMPLEMENTATION EIdReplyIMAP4Error : public Idreply::EIdReplyError
{
	typedef Idreply::EIdReplyError inherited;
	
public:
	__fastcall EIdReplyIMAP4Error(const System::UnicodeString AReplyMessage);
public:
	/* EIdException.Create */ inline __fastcall virtual EIdReplyIMAP4Error(const System::UnicodeString AMsg)/* overload */ : Idreply::EIdReplyError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdReplyIMAP4Error(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreply::EIdReplyError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdReplyIMAP4Error(int Ident)/* overload */ : Idreply::EIdReplyError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdReplyIMAP4Error(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreply::EIdReplyError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdReplyIMAP4Error(const System::UnicodeString Msg, int AHelpContext) : Idreply::EIdReplyError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdReplyIMAP4Error(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreply::EIdReplyError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdReplyIMAP4Error(int Ident, int AHelpContext)/* overload */ : Idreply::EIdReplyError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdReplyIMAP4Error(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreply::EIdReplyError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdReplyIMAP4Error(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define IMAP_OK L"OK"
#define IMAP_NO L"NO"
#define IMAP_BAD L"BAD"
#define IMAP_PREAUTH L"PREAUTH"
#define IMAP_BYE L"BYE"
static const WideChar IMAP_CONT = (WideChar)(0x2b);
extern PACKAGE Idreplyimap4__1 VALID_TAGGEDREPLIES;

}	/* namespace Idreplyimap4 */
using namespace Idreplyimap4;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idreplyimap4HPP
