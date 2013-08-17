// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idreply.pas' rev: 20.00

#ifndef IdreplyHPP
#define IdreplyHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idreply
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdReply;
class DELPHICLASS TIdReplies;
class PASCALIMPLEMENTATION TIdReply : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FCode;
	Classes::TStrings* FFormattedReply;
	TIdReplies* FReplyTexts;
	Classes::TStrings* FText;
	virtual void __fastcall AssignTo(Classes::TPersistent* ADest);
	void __fastcall CommonInit(void);
	virtual Classes::TStrings* __fastcall GetFormattedReplyStrings(void);
	virtual bool __fastcall CheckIfCodeIsValid(const System::UnicodeString ACode);
	virtual System::UnicodeString __fastcall GetDisplayName();
	virtual Classes::TStrings* __fastcall GetFormattedReply(void);
	int __fastcall GetNumericCode(void);
	void __fastcall SetCode(const System::UnicodeString AValue);
	virtual void __fastcall SetFormattedReply(const Classes::TStrings* AValue) = 0 ;
	void __fastcall SetText(const Classes::TStrings* AValue);
	void __fastcall SetNumericCode(const int AValue);
	
public:
	virtual void __fastcall Clear(void);
	__fastcall virtual TIdReply(Classes::TCollection* ACollection);
	__fastcall virtual TIdReply(Classes::TCollection* ACollection, TIdReplies* AReplyTexts);
	__fastcall virtual ~TIdReply(void);
	__classmethod virtual bool __fastcall IsEndMarker(const System::UnicodeString ALine);
	virtual void __fastcall RaiseReplyError(void) = 0 ;
	virtual bool __fastcall ReplyExists(void);
	virtual void __fastcall SetReply(const int ACode, const System::UnicodeString AText)/* overload */;
	virtual void __fastcall SetReply(const System::UnicodeString ACode, const System::UnicodeString AText)/* overload */;
	void __fastcall UpdateText(void);
	__property Classes::TStrings* FormattedReply = {read=GetFormattedReply, write=SetFormattedReply};
	__property int NumericCode = {read=GetNumericCode, write=SetNumericCode, nodefault};
	
__published:
	__property System::UnicodeString Code = {read=FCode, write=SetCode};
	__property Classes::TStrings* Text = {read=FText, write=SetText};
};


typedef TMetaClass* TIdReplyClass;

class PASCALIMPLEMENTATION TIdReplies : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdReply* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdReply* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdReply* Value);
	
public:
	HIDESBASE TIdReply* __fastcall Add(void)/* overload */;
	HIDESBASE TIdReply* __fastcall Add(const int ACode, const System::UnicodeString AText)/* overload */;
	HIDESBASE TIdReply* __fastcall Add(const System::UnicodeString ACode, const System::UnicodeString AText)/* overload */;
	__fastcall virtual TIdReplies(Classes::TPersistent* AOwner, const TIdReplyClass AReplyClass);
	virtual TIdReply* __fastcall Find(const System::UnicodeString ACode, TIdReply* AIgnore = (TIdReply*)(0x0));
	virtual void __fastcall UpdateText(TIdReply* AReply);
	__property TIdReply* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdReplies(void) { }
	
};


typedef TMetaClass* TIdRepliesClass;

class DELPHICLASS EIdReplyError;
class PASCALIMPLEMENTATION EIdReplyError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdReplyError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdReplyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdReplyError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdReplyError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdReplyError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdReplyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdReplyError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdReplyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdReplyError(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idreply */
using namespace Idreply;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdreplyHPP
