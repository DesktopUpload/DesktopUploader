// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idqotd.pas' rev: 20.00

#ifndef IdqotdHPP
#define IdqotdHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idqotd
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdQOTD;
class PASCALIMPLEMENTATION TIdQOTD : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	System::UnicodeString __fastcall GetQuote();
	virtual void __fastcall InitComponent(void);
	
public:
	__property System::UnicodeString Quote = {read=GetQuote};
	
__published:
	__property Port = {default=17};
	__property Host;
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdQOTD(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdQOTD(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idqotd */
using namespace Idqotd;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdqotdHPP
