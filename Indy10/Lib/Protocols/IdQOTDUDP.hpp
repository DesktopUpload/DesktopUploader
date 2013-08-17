// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idqotdudp.pas' rev: 20.00

#ifndef IdqotdudpHPP
#define IdqotdudpHPP

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

namespace Idqotdudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdQOTDUDP;
class PASCALIMPLEMENTATION TIdQOTDUDP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	System::UnicodeString __fastcall GetQuote();
	virtual void __fastcall InitComponent(void);
	
public:
	__property System::UnicodeString Quote = {read=GetQuote};
	
__published:
	__property Port = {default=17};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdQOTDUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdQOTDUDP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idqotdudp */
using namespace Idqotdudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdqotdudpHPP
