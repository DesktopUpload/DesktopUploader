// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsystatudpserver.pas' rev: 20.00

#ifndef IdsystatudpserverHPP
#define IdsystatudpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsystatudpserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdUDPSystatEvent)(Idsockethandle::TIdSocketHandle* ABinding, Classes::TStrings* AResults);

class DELPHICLASS TIdSystatUDPServer;
class PASCALIMPLEMENTATION TIdSystatUDPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	TIdUDPSystatEvent FOnSystat;
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TIdUDPSystatEvent OnSystat = {read=FOnSystat, write=FOnSystat};
	__property DefaultPort = {default=11};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdSystatUDPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSystatUDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsystatudpserver */
using namespace Idsystatudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsystatudpserverHPP
