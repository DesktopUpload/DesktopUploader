// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddiscardudpserver.pas' rev: 20.00

#ifndef IddiscardudpserverHPP
#define IddiscardudpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddiscardudpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDiscardUDPServer;
class PASCALIMPLEMENTATION TIdDiscardUDPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=9};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdDiscardUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDiscardUDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddiscardudpserver */
using namespace Iddiscardudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddiscardudpserverHPP
