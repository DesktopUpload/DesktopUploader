// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddaytimeserver.pas' rev: 20.00

#ifndef IddaytimeserverHPP
#define IddaytimeserverHPP

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

namespace Iddaytimeserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDayTimeServer;
class PASCALIMPLEMENTATION TIdDayTimeServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	System::UnicodeString FTimeZone;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property System::UnicodeString TimeZone = {read=FTimeZone, write=FTimeZone};
	__property DefaultPort = {default=13};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdDayTimeServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDayTimeServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddaytimeserver */
using namespace Iddaytimeserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddaytimeserverHPP
