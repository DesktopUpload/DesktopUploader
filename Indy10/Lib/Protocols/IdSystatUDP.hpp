// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsystatudp.pas' rev: 20.00

#ifndef IdsystatudpHPP
#define IdsystatudpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsystatudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSystatUDP;
class PASCALIMPLEMENTATION TIdSystatUDP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall GetStat(Classes::TStrings* ADest);
	
__published:
	__property ReceiveTimeout = {default=1000};
	__property Port = {default=11};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdSystatUDP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSystatUDP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word DefIdSysUDPTimeout = 0x3e8;

}	/* namespace Idsystatudp */
using namespace Idsystatudp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsystatudpHPP
