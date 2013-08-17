// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmappedportudp.pas' rev: 20.00

#ifndef IdmappedportudpHPP
#define IdmappedportudpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmappedportudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMappedPortUDP;
class PASCALIMPLEMENTATION TIdMappedPortUDP : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	System::Word FMappedPort;
	System::UnicodeString FMappedHost;
	Classes::TNotifyEvent FOnRequest;
	virtual void __fastcall DoRequestNotify(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	
__published:
	__property System::UnicodeString MappedHost = {read=FMappedHost, write=FMappedHost};
	__property System::Word MappedPort = {read=FMappedPort, write=FMappedPort, nodefault};
	__property Classes::TNotifyEvent OnRequest = {read=FOnRequest, write=FOnRequest};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdMappedPortUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMappedPortUDP(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmappedportudp */
using namespace Idmappedportudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmappedportudpHPP
