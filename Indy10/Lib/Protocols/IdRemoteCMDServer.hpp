// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idremotecmdserver.pas' rev: 20.00

#ifndef IdremotecmdserverHPP
#define IdremotecmdserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idremotecmdserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdRemoteCMDServer;
class PASCALIMPLEMENTATION TIdRemoteCMDServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	bool FForcePortsInRange;
	bool FStdErrorPortsInRange;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AThread);
	virtual void __fastcall DoCMD(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdError, System::UnicodeString AParam1, System::UnicodeString AParam2, System::UnicodeString ACommand) = 0 ;
	
public:
	void __fastcall SendError(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdErr, System::UnicodeString AMsg);
	void __fastcall SendResults(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdErr, System::UnicodeString AMsg);
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdRemoteCMDServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRemoteCMDServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idremotecmdserver */
using namespace Idremotecmdserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdremotecmdserverHPP
