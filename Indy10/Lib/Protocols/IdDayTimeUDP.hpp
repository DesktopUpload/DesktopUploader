// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddaytimeudp.pas' rev: 20.00

#ifndef IddaytimeudpHPP
#define IddaytimeudpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddaytimeudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDayTimeUDP;
class PASCALIMPLEMENTATION TIdDayTimeUDP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	System::UnicodeString __fastcall GetDayTimeStr();
	virtual void __fastcall InitComponent(void);
	
public:
	__property System::UnicodeString DayTimeStr = {read=GetDayTimeStr};
	
__published:
	__property Port = {default=13};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdDayTimeUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDayTimeUDP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddaytimeudp */
using namespace Iddaytimeudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddaytimeudpHPP
