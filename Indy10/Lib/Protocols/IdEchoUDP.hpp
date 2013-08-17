// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idechoudp.pas' rev: 20.00

#ifndef IdechoudpHPP
#define IdechoudpHPP

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

namespace Idechoudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEchoUDP;
class PASCALIMPLEMENTATION TIdEchoUDP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	unsigned FEchoTime;
	virtual void __fastcall InitComponent(void);
	
public:
	System::UnicodeString __fastcall Echo(System::UnicodeString AText);
	__property unsigned EchoTime = {read=FEchoTime, nodefault};
	
__published:
	__property Port = {default=7};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdEchoUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEchoUDP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idechoudp */
using namespace Idechoudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdechoudpHPP
