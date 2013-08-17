// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrawclient.pas' rev: 20.00

#ifndef IdrawclientHPP
#define IdrawclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idrawbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrawclient
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdRawClient;
class PASCALIMPLEMENTATION TIdRawClient : public Idrawbase::TIdRawBase
{
	typedef Idrawbase::TIdRawBase inherited;
	
__published:
	__property ReceiveTimeout = {default=0};
	__property Host;
	__property Port = {default=0};
	__property Protocol = {default=255};
	__property ProtocolIPv6;
	__property IPVersion;
public:
	/* TIdRawBase.Destroy */ inline __fastcall virtual ~TIdRawClient(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRawClient(Classes::TComponent* AOwner)/* overload */ : Idrawbase::TIdRawBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idrawclient */
using namespace Idrawclient;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrawclientHPP
