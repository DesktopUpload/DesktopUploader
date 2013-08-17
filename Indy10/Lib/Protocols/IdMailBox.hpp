// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmailbox.pas' rev: 20.00

#ifndef IdmailboxHPP
#define IdmailboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idmessagecollection.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmailbox
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdMailBoxState { msReadWrite, msReadOnly };
#pragma option pop

#pragma option push -b-
enum TIdMailBoxAttributes { maNoinferiors, maNoselect, maMarked, maUnmarked };
#pragma option pop

typedef Set<TIdMailBoxAttributes, maNoinferiors, maUnmarked>  TIdMailBoxAttributesSet;

typedef DynamicArray<int> TLongIntArray;

class DELPHICLASS TIdMailBox;
class PASCALIMPLEMENTATION TIdMailBox : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TIdMailBoxAttributes FAttributes;
	Idmessage::TIdMessageFlagsSet FChangeableFlags;
	int FFirstUnseenMsg;
	Idmessage::TIdMessageFlagsSet FFlags;
	System::UnicodeString FName;
	Idmessagecollection::TIdMessageCollection* FMessageList;
	int FRecentMsgs;
	TIdMailBoxState FState;
	int FTotalMsgs;
	System::UnicodeString FUIDNext;
	System::UnicodeString FUIDValidity;
	int FUnseenMsgs;
	void __fastcall SetMessageList(const Idmessagecollection::TIdMessageCollection* Value);
	virtual void __fastcall InitComponent(void);
	
public:
	TLongIntArray DeletedMsgs;
	TLongIntArray SearchResult;
	__property TIdMailBoxAttributes Attributes = {read=FAttributes, write=FAttributes, nodefault};
	__property Idmessage::TIdMessageFlagsSet ChangeableFlags = {read=FChangeableFlags, write=FChangeableFlags, nodefault};
	__property int FirstUnseenMsg = {read=FFirstUnseenMsg, write=FFirstUnseenMsg, nodefault};
	__property Idmessage::TIdMessageFlagsSet Flags = {read=FFlags, write=FFlags, nodefault};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Idmessagecollection::TIdMessageCollection* MessageList = {read=FMessageList, write=SetMessageList};
	__property int RecentMsgs = {read=FRecentMsgs, write=FRecentMsgs, nodefault};
	__property TIdMailBoxState State = {read=FState, write=FState, nodefault};
	__property int TotalMsgs = {read=FTotalMsgs, write=FTotalMsgs, nodefault};
	__property System::UnicodeString UIDNext = {read=FUIDNext, write=FUIDNext};
	__property System::UnicodeString UIDValidity = {read=FUIDValidity, write=FUIDValidity};
	__property int UnseenMsgs = {read=FUnseenMsgs, write=FUnseenMsgs, nodefault};
	virtual void __fastcall Clear(void);
	__fastcall virtual ~TIdMailBox(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMailBox(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


typedef StaticArray<System::UnicodeString, 4> Idmailbox__2;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Idmailbox__2 MailBoxAttributes;

}	/* namespace Idmailbox */
using namespace Idmailbox;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmailboxHPP
