// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtimeudpserver.pas' rev: 20.00

#ifndef IdtimeudpserverHPP
#define IdtimeudpserverHPP

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

namespace Idtimeudpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdCustomTimeUDPServer;
class PASCALIMPLEMENTATION TIdCustomTimeUDPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	System::TDateTime FBaseDate;
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall InitComponent(void);
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdCustomTimeUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomTimeUDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


class DELPHICLASS TIdTimeUDPServer;
class PASCALIMPLEMENTATION TIdTimeUDPServer : public TIdCustomTimeUDPServer
{
	typedef TIdCustomTimeUDPServer inherited;
	
__published:
	__property DefaultPort = {default=37};
	__property System::TDateTime BaseDate = {read=FBaseDate, write=FBaseDate};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdTimeUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTimeUDPServer(Classes::TComponent* AOwner)/* overload */ : TIdCustomTimeUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtimeudpserver */
using namespace Idtimeudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtimeudpserverHPP
