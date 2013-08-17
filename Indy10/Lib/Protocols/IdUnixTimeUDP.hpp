// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idunixtimeudp.pas' rev: 20.00

#ifndef IdunixtimeudpHPP
#define IdunixtimeudpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idtimeudp.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idunixtimeudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUnixTimeUDP;
class PASCALIMPLEMENTATION TIdUnixTimeUDP : public Idtimeudp::TIdCustomTimeUDP
{
	typedef Idtimeudp::TIdCustomTimeUDP inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
__published:
	__property Port = {default=519};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdUnixTimeUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUnixTimeUDP(Classes::TComponent* AOwner)/* overload */ : Idtimeudp::TIdCustomTimeUDP(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idunixtimeudp */
using namespace Idunixtimeudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdunixtimeudpHPP
