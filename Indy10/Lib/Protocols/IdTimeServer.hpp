// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtimeserver.pas' rev: 20.00

#ifndef IdtimeserverHPP
#define IdtimeserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtimeserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdCustomTimeServer;
class PASCALIMPLEMENTATION TIdCustomTimeServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	System::TDateTime FBaseDate;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdCustomTimeServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomTimeServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


class DELPHICLASS TIdTimeServer;
class PASCALIMPLEMENTATION TIdTimeServer : public TIdCustomTimeServer
{
	typedef TIdCustomTimeServer inherited;
	
__published:
	__property DefaultPort = {default=37};
	__property System::TDateTime BaseDate = {read=FBaseDate, write=FBaseDate};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdTimeServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTimeServer(Classes::TComponent* AOwner)/* overload */ : TIdCustomTimeServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtimeserver */
using namespace Idtimeserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtimeserverHPP
