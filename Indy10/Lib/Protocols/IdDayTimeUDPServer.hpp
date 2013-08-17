// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddaytimeudpserver.pas' rev: 20.00

#ifndef IddaytimeudpserverHPP
#define IddaytimeudpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddaytimeudpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDayTimeUDPServer;
class PASCALIMPLEMENTATION TIdDayTimeUDPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	System::UnicodeString FTimeZone;
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property System::UnicodeString TimeZone = {read=FTimeZone, write=FTimeZone};
	__property DefaultPort = {default=13};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdDayTimeUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDayTimeUDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddaytimeudpserver */
using namespace Iddaytimeudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddaytimeudpserverHPP
