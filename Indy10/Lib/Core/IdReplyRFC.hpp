// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idreplyrfc.pas' rev: 20.00

#ifndef IdreplyrfcHPP
#define IdreplyrfcHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idreplyrfc
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdReplyRFC;
class PASCALIMPLEMENTATION TIdReplyRFC : public Idreply::TIdReply
{
	typedef Idreply::TIdReply inherited;
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* ADest);
	virtual bool __fastcall CheckIfCodeIsValid(const System::UnicodeString ACode);
	virtual Classes::TStrings* __fastcall GetFormattedReply(void);
	virtual void __fastcall SetFormattedReply(const Classes::TStrings* AValue);
	
public:
	__classmethod virtual bool __fastcall IsEndMarker(const System::UnicodeString ALine);
	virtual void __fastcall RaiseReplyError(void);
	virtual bool __fastcall ReplyExists(void);
public:
	/* TIdReply.Create */ inline __fastcall virtual TIdReplyRFC(Classes::TCollection* ACollection) : Idreply::TIdReply(ACollection) { }
	/* TIdReply.CreateWithReplyTexts */ inline __fastcall virtual TIdReplyRFC(Classes::TCollection* ACollection, Idreply::TIdReplies* AReplyTexts) : Idreply::TIdReply(ACollection, AReplyTexts) { }
	/* TIdReply.Destroy */ inline __fastcall virtual ~TIdReplyRFC(void) { }
	
};


class DELPHICLASS TIdRepliesRFC;
class PASCALIMPLEMENTATION TIdRepliesRFC : public Idreply::TIdReplies
{
	typedef Idreply::TIdReplies inherited;
	
public:
	__fastcall virtual TIdRepliesRFC(Classes::TPersistent* AOwner)/* overload */;
	__fastcall virtual TIdRepliesRFC(Classes::TPersistent* AOwner, const Idreply::TIdReplyClass AReplyClass)/* overload */;
	virtual void __fastcall UpdateText(Idreply::TIdReply* AReply);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdRepliesRFC(void) { }
	
};


class DELPHICLASS EIdReplyRFCError;
class PASCALIMPLEMENTATION EIdReplyRFCError : public Idreply::EIdReplyError
{
	typedef Idreply::EIdReplyError inherited;
	
protected:
	int FErrorCode;
	
public:
	__fastcall virtual EIdReplyRFCError(const int AErrorCode, const System::UnicodeString AReplyMessage);
	__property int ErrorCode = {read=FErrorCode, nodefault};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdReplyRFCError(const System::UnicodeString AMsg)/* overload */ : Idreply::EIdReplyError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdReplyRFCError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreply::EIdReplyError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdReplyRFCError(int Ident)/* overload */ : Idreply::EIdReplyError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdReplyRFCError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreply::EIdReplyError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdReplyRFCError(const System::UnicodeString Msg, int AHelpContext) : Idreply::EIdReplyError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdReplyRFCError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreply::EIdReplyError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdReplyRFCError(int Ident, int AHelpContext)/* overload */ : Idreply::EIdReplyError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdReplyRFCError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreply::EIdReplyError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdReplyRFCError(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idreplyrfc */
using namespace Idreplyrfc;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdreplyrfcHPP
