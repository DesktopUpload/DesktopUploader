// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idipmcastserver.pas' rev: 20.00

#ifndef IdipmcastserverHPP
#define IdipmcastserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idipmcastbase.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idipmcastserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIPMCastServer;
class PASCALIMPLEMENTATION TIdIPMCastServer : public Idipmcastbase::TIdIPMCastBase
{
	typedef Idipmcastbase::TIdIPMCastBase inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	System::UnicodeString FBoundIP;
	System::Word FBoundPort;
	bool FLoopback;
	System::Byte FTimeToLive;
	void __fastcall ApplyLoopback(void);
	void __fastcall ApplyTimeToLive(void);
	virtual void __fastcall CloseBinding(void);
	virtual bool __fastcall GetActive(void);
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	virtual void __fastcall Loaded(void);
	void __fastcall MulticastBuffer(const System::UnicodeString AHost, const int APort, const Sysutils::TBytes ABuffer);
	virtual void __fastcall SetLoopback(const bool AValue);
	virtual void __fastcall SetTTL(const System::Byte AValue);
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall Send(const System::UnicodeString AData)/* overload */;
	void __fastcall Send(const Sysutils::TBytes ABuffer)/* overload */;
	__fastcall virtual ~TIdIPMCastServer(void);
	__property Idsockethandle::TIdSocketHandle* Binding = {read=GetBinding};
	
__published:
	__property Active = {default=0};
	__property System::UnicodeString BoundIP = {read=FBoundIP, write=FBoundIP};
	__property System::Word BoundPort = {read=FBoundPort, write=FBoundPort, nodefault};
	__property bool Loopback = {read=FLoopback, write=SetLoopback, default=1};
	__property MulticastGroup;
	__property IPVersion = {default=0};
	__property Port;
	__property System::Byte TimeToLive = {read=FTimeToLive, write=SetTTL, default=1};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIPMCastServer(Classes::TComponent* AOwner)/* overload */ : Idipmcastbase::TIdIPMCastBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool DEF_IMP_LOOPBACK = true;
static const ShortInt DEF_IMP_TTL = 0x1;

}	/* namespace Idipmcastserver */
using namespace Idipmcastserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdipmcastserverHPP
