// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtime.pas' rev: 20.00

#ifndef IdtimeHPP
#define IdtimeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtime
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdCustomTime;
class PASCALIMPLEMENTATION TIdCustomTime : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	System::TDateTime FBaseDate;
	unsigned FRoundTripDelay;
	int FTimeout;
	unsigned __fastcall GetDateTimeCard(void);
	System::TDateTime __fastcall GetDateTime(void);
	virtual void __fastcall InitComponent(void);
	
public:
	bool __fastcall SyncTime(void);
	__property unsigned DateTimeCard = {read=GetDateTimeCard, nodefault};
	__property System::TDateTime DateTime = {read=GetDateTime};
	__property unsigned RoundTripDelay = {read=FRoundTripDelay, nodefault};
	
__published:
	__property int Timeout = {read=FTimeout, write=FTimeout, default=2500};
	__property Host;
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdCustomTime(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomTime(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


class DELPHICLASS TIdTime;
class PASCALIMPLEMENTATION TIdTime : public TIdCustomTime
{
	typedef TIdCustomTime inherited;
	
__published:
	__property System::TDateTime BaseDate = {read=FBaseDate, write=FBaseDate};
	__property int Timeout = {read=FTimeout, write=FTimeout, default=2500};
	__property Port = {default=37};
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdTime(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTime(Classes::TComponent* AOwner)/* overload */ : TIdCustomTime(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word TIME_TIMEOUT = 0x9c4;

}	/* namespace Idtime */
using namespace Idtime;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtimeHPP
