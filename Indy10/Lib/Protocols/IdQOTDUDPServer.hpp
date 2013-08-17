// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idqotdudpserver.pas' rev: 20.00

#ifndef IdqotdudpserverHPP
#define IdqotdudpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idqotdudpserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdQotdUDPGetEvent)(Idsockethandle::TIdSocketHandle* ABinding, System::UnicodeString &AQuote);

class DELPHICLASS TIdQotdUDPServer;
class PASCALIMPLEMENTATION TIdQotdUDPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	TIdQotdUDPGetEvent FOnCommandQOTD;
	virtual void __fastcall DoOnCommandQUOTD(Idsockethandle::TIdSocketHandle* ABinding, System::UnicodeString &AQuote);
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=17};
	__property TIdQotdUDPGetEvent OnCommandQOTD = {read=FOnCommandQOTD, write=FOnCommandQOTD};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdQotdUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdQotdUDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idqotdudpserver */
using namespace Idqotdudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdqotdudpserverHPP
