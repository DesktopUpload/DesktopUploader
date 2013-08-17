// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtimeudp.pas' rev: 20.00

#ifndef IdtimeudpHPP
#define IdtimeudpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtimeudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdCustomTimeUDP;
class PASCALIMPLEMENTATION TIdCustomTimeUDP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	System::TDateTime FBaseDate;
	unsigned FRoundTripDelay;
	unsigned __fastcall GetDateTimeCard(void);
	System::TDateTime __fastcall GetDateTime(void);
	virtual void __fastcall InitComponent(void);
	
public:
	bool __fastcall SyncTime(void);
	__property unsigned DateTimeCard = {read=GetDateTimeCard, nodefault};
	__property System::TDateTime DateTime = {read=GetDateTime};
	__property unsigned RoundTripDelay = {read=FRoundTripDelay, nodefault};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdCustomTimeUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomTimeUDP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


class DELPHICLASS TIdTimeUDP;
class PASCALIMPLEMENTATION TIdTimeUDP : public TIdCustomTimeUDP
{
	typedef TIdCustomTimeUDP inherited;
	
__published:
	__property System::TDateTime BaseDate = {read=FBaseDate, write=FBaseDate};
	__property Port = {default=37};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdTimeUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTimeUDP(Classes::TComponent* AOwner)/* overload */ : TIdCustomTimeUDP(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtimeudp */
using namespace Idtimeudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtimeudpHPP
