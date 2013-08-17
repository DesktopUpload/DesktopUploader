// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idwhoisserver.pas' rev: 20.00

#ifndef IdwhoisserverHPP
#define IdwhoisserverHPP

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

namespace Idwhoisserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TGetEvent)(Idcontext::TIdContext* AContext, System::UnicodeString ALookup, System::UnicodeString &VResponse);

class DELPHICLASS TIdWhoIsServer;
class PASCALIMPLEMENTATION TIdWhoIsServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	TGetEvent FOnCommandLookup;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TGetEvent OnCommandLookup = {read=FOnCommandLookup, write=FOnCommandLookup};
	__property DefaultPort = {default=43};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdWhoIsServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdWhoIsServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idwhoisserver */
using namespace Idwhoisserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdwhoisserverHPP
