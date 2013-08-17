// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idunixtimeudpserver.pas' rev: 20.00

#ifndef IdunixtimeudpserverHPP
#define IdunixtimeudpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idtimeudpserver.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idunixtimeudpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUnixTimeUDPServer;
class PASCALIMPLEMENTATION TIdUnixTimeUDPServer : public Idtimeudpserver::TIdCustomTimeUDPServer
{
	typedef Idtimeudpserver::TIdCustomTimeUDPServer inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=519};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdUnixTimeUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUnixTimeUDPServer(Classes::TComponent* AOwner)/* overload */ : Idtimeudpserver::TIdCustomTimeUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idunixtimeudpserver */
using namespace Idunixtimeudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdunixtimeudpserverHPP
