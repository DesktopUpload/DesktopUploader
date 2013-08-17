// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrshserver.pas' rev: 20.00

#ifndef IdrshserverHPP
#define IdrshserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idremotecmdserver.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrshserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdRSHCommandEvent)(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdError, System::UnicodeString AClientUserName, System::UnicodeString AHostUserName, System::UnicodeString ACommand);

class DELPHICLASS TIdRSHServer;
class PASCALIMPLEMENTATION TIdRSHServer : public Idremotecmdserver::TIdRemoteCMDServer
{
	typedef Idremotecmdserver::TIdRemoteCMDServer inherited;
	
protected:
	TIdRSHCommandEvent FOnCommand;
	virtual void __fastcall DoCMD(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdError, System::UnicodeString AParam1, System::UnicodeString AParam2, System::UnicodeString ACommand);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TIdRSHCommandEvent OnCommand = {read=FOnCommand, write=FOnCommand};
	__property DefaultPort = {default=514};
	__property bool ForcePortsInRange = {read=FForcePortsInRange, write=FForcePortsInRange, default=1};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdRSHServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRSHServer(Classes::TComponent* AOwner)/* overload */ : Idremotecmdserver::TIdRemoteCMDServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool RSH_FORCEPORTSINRANGE = true;

}	/* namespace Idrshserver */
using namespace Idrshserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrshserverHPP
