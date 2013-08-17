// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecollection.pas' rev: 20.00

#ifndef IdmessagecollectionHPP
#define IdmessagecollectionHPP

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

namespace Idmessagecollection
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass* TIdMessageItems;

class DELPHICLASS TIdMessageItem;
class PASCALIMPLEMENTATION TIdMessageItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	int FAttempt;
	bool FQueued;
	
public:
	Idmessage::TIdMessage* Msg;
	__property int Attempt = {read=FAttempt, write=FAttempt, nodefault};
	__property bool Queued = {read=FQueued, write=FQueued, nodefault};
	__fastcall virtual TIdMessageItem(Classes::TCollection* Collection);
	__fastcall virtual ~TIdMessageItem(void);
};


class DELPHICLASS TIdMessageCollection;
class PASCALIMPLEMENTATION TIdMessageCollection : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	Idmessage::TIdMessage* operator[](int index) { return Messages[index]; }
	
private:
	Idmessage::TIdMessage* __fastcall GetIdMessage(int index);
	void __fastcall SetIdMessage(int index, const Idmessage::TIdMessage* Value);
	
public:
	HIDESBASE TIdMessageItem* __fastcall Add(void);
	__property Idmessage::TIdMessage* Messages[int index] = {read=GetIdMessage, write=SetIdMessage/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TIdMessageCollection(Classes::TCollectionItemClass ItemClass) : Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdMessageCollection(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessagecollection */
using namespace Idmessagecollection;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagecollectionHPP
