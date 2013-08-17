// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idecho.pas' rev: 20.00

#ifndef IdechoHPP
#define IdechoHPP

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

namespace Idecho
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEcho;
class PASCALIMPLEMENTATION TIdEcho : public Idtcpclient::TIdTCPClient
{
	typedef Idtcpclient::TIdTCPClient inherited;
	
protected:
	unsigned FEchoTime;
	virtual void __fastcall InitComponent(void);
	
public:
	System::UnicodeString __fastcall Echo(const System::UnicodeString AText);
	__property unsigned EchoTime = {read=FEchoTime, nodefault};
	
__published:
	__property Port = {default=7};
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdEcho(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEcho(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idecho */
using namespace Idecho;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdechoHPP
