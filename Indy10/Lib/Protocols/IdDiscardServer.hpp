// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddiscardserver.pas' rev: 20.00

#ifndef IddiscardserverHPP
#define IddiscardserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddiscardserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDISCARDServer;
class PASCALIMPLEMENTATION TIdDISCARDServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=9};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdDISCARDServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDISCARDServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddiscardserver */
using namespace Iddiscardserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddiscardserverHPP
