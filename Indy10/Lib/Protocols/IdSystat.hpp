// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsystat.pas' rev: 20.00

#ifndef IdsystatHPP
#define IdsystatHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsystat
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSystat;
class PASCALIMPLEMENTATION TIdSystat : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall GetStat(Classes::TStrings* ADest);
	
__published:
	__property Port = {default=11};
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdSystat(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSystat(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsystat */
using namespace Idsystat;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsystatHPP
