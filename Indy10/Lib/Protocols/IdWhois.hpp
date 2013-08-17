// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idwhois.pas' rev: 20.00

#ifndef IdwhoisHPP
#define IdwhoisHPP

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

namespace Idwhois
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdWhois;
class PASCALIMPLEMENTATION TIdWhois : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	System::UnicodeString __fastcall WhoIs(const System::UnicodeString ADomain);
	
__published:
	__property Port = {default=43};
	__property Host;
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdWhois(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdWhois(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idwhois */
using namespace Idwhois;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdwhoisHPP
