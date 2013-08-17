// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idssl.pas' rev: 20.00

#ifndef IdsslHPP
#define IdsslHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idserveriohandler.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idssl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSSLIOHandlerSocketBase;
class PASCALIMPLEMENTATION TIdSSLIOHandlerSocketBase : public Idiohandlerstack::TIdIOHandlerStack
{
	typedef Idiohandlerstack::TIdIOHandlerStack inherited;
	
protected:
	bool fPassThrough;
	bool fIsPeer;
	System::UnicodeString FURIToCheck;
	virtual int __fastcall RecvEnc(Sysutils::TBytes &ABuffer) = 0 ;
	virtual int __fastcall SendEnc(const Sysutils::TBytes ABuffer, const int AOffset, const int ALength) = 0 ;
	virtual int __fastcall ReadDataFromSource(Sysutils::TBytes &VBuffer);
	virtual int __fastcall WriteDataToTarget(const Sysutils::TBytes ABuffer, const int AOffset, const int ALength);
	virtual void __fastcall SetPassThrough(const bool AValue);
	virtual void __fastcall SetURIToCheck(const System::UnicodeString AValue);
	
public:
	virtual TIdSSLIOHandlerSocketBase* __fastcall Clone(void) = 0 ;
	virtual void __fastcall StartSSL(void) = 0 ;
	__property bool PassThrough = {read=fPassThrough, write=SetPassThrough, nodefault};
	__property bool IsPeer = {read=fIsPeer, write=fIsPeer, nodefault};
	__property System::UnicodeString URIToCheck = {read=FURIToCheck, write=SetURIToCheck};
public:
	/* TIdIOHandlerSocket.Destroy */ inline __fastcall virtual ~TIdSSLIOHandlerSocketBase(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSSLIOHandlerSocketBase(Classes::TComponent* AOwner)/* overload */ : Idiohandlerstack::TIdIOHandlerStack(AOwner) { }
	
};


class DELPHICLASS TIdServerIOHandlerSSLBase;
class PASCALIMPLEMENTATION TIdServerIOHandlerSSLBase : public Idserveriohandler::TIdServerIOHandler
{
	typedef Idserveriohandler::TIdServerIOHandler inherited;
	
public:
	virtual Idiohandler::TIdIOHandler* __fastcall MakeClientIOHandler(Idyarn::TIdYarn* ATheThread)/* overload */;
	HIDESBASE virtual TIdSSLIOHandlerSocketBase* __fastcall MakeClientIOHandler(void) = 0 /* overload */;
	virtual TIdSSLIOHandlerSocketBase* __fastcall MakeFTPSvrPort(void) = 0 ;
	virtual TIdSSLIOHandlerSocketBase* __fastcall MakeFTPSvrPasv(void) = 0 ;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdServerIOHandlerSSLBase(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerIOHandlerSSLBase(Classes::TComponent* AOwner)/* overload */ : Idserveriohandler::TIdServerIOHandler(AOwner) { }
	
};


typedef TMetaClass* TIdClientSSLClass;

typedef TMetaClass* TIdServerSSLClass;

class DELPHICLASS TIdSSLRegEntry;
class PASCALIMPLEMENTATION TIdSSLRegEntry : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FProductName;
	System::UnicodeString FVendor;
	System::UnicodeString FCopyright;
	System::UnicodeString FDescription;
	System::UnicodeString FURL;
	TIdClientSSLClass FClientClass;
	TIdServerSSLClass FServerClass;
	
public:
	__property System::UnicodeString ProductName = {read=FProductName, write=FProductName};
	__property System::UnicodeString Vendor = {read=FVendor, write=FVendor};
	__property System::UnicodeString Copyright = {read=FCopyright, write=FCopyright};
	__property System::UnicodeString Description = {read=FDescription, write=FDescription};
	__property System::UnicodeString URL = {read=FURL, write=FURL};
	__property TIdClientSSLClass ClientClass = {read=FClientClass, write=FClientClass};
	__property TIdServerSSLClass ServerClass = {read=FServerClass, write=FServerClass};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdSSLRegEntry(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdSSLRegEntry(void) { }
	
};


class DELPHICLASS TIdSSLRegistry;
class PASCALIMPLEMENTATION TIdSSLRegistry : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdSSLRegEntry* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdSSLRegEntry* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdSSLRegEntry* Value);
	
public:
	__fastcall TIdSSLRegistry(void);
	HIDESBASE TIdSSLRegEntry* __fastcall Add(void);
	__property TIdSSLRegEntry* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdSSLRegistry(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIdSSLRegistry* GSSLRegistry;
extern PACKAGE void __fastcall RegisterSSL(const System::UnicodeString AProduct, const System::UnicodeString AVendor, const System::UnicodeString ACopyright, const System::UnicodeString ADescription, const System::UnicodeString AURL, const TIdClientSSLClass AClientClass, const TIdServerSSLClass AServerClass);

}	/* namespace Idssl */
using namespace Idssl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsslHPP
