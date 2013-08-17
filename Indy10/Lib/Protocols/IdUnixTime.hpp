// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idunixtime.pas' rev: 20.00

#ifndef IdunixtimeHPP
#define IdunixtimeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtime.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idunixtime
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUnixTime;
class PASCALIMPLEMENTATION TIdUnixTime : public Idtime::TIdCustomTime
{
	typedef Idtime::TIdCustomTime inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
__published:
	__property Port = {default=519};
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdUnixTime(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUnixTime(Classes::TComponent* AOwner)/* overload */ : Idtime::TIdCustomTime(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idunixtime */
using namespace Idunixtime;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdunixtimeHPP
