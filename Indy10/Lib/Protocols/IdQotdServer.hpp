// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idqotdserver.pas' rev: 20.00

#ifndef IdqotdserverHPP
#define IdqotdserverHPP

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

namespace Idqotdserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdQOTDGetEvent)(Idcontext::TIdContext* AContext, System::UnicodeString &AQuote);

class DELPHICLASS TIdQOTDServer;
class PASCALIMPLEMENTATION TIdQOTDServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	TIdQOTDGetEvent FOnCommandQOTD;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TIdQOTDGetEvent OnCommandQOTD = {read=FOnCommandQOTD, write=FOnCommandQOTD};
	__property DefaultPort = {default=17};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdQOTDServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdQOTDServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idqotdserver */
using namespace Idqotdserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdqotdserverHPP
