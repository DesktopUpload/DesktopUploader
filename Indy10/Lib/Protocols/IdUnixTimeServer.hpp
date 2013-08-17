// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idunixtimeserver.pas' rev: 20.00

#ifndef IdunixtimeserverHPP
#define IdunixtimeserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idtimeserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idunixtimeserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUnixTimeServer;
class PASCALIMPLEMENTATION TIdUnixTimeServer : public Idtimeserver::TIdCustomTimeServer
{
	typedef Idtimeserver::TIdCustomTimeServer inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=519};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdUnixTimeServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUnixTimeServer(Classes::TComponent* AOwner)/* overload */ : Idtimeserver::TIdCustomTimeServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idunixtimeserver */
using namespace Idunixtimeserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdunixtimeserverHPP
