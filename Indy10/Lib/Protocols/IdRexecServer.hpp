// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrexecserver.pas' rev: 20.00

#ifndef IdrexecserverHPP
#define IdrexecserverHPP

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

namespace Idrexecserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdRexecCommandEvent)(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdError, System::UnicodeString AUserName, System::UnicodeString APassword, System::UnicodeString ACommand);

class DELPHICLASS TIdRexecServer;
class PASCALIMPLEMENTATION TIdRexecServer : public Idremotecmdserver::TIdRemoteCMDServer
{
	typedef Idremotecmdserver::TIdRemoteCMDServer inherited;
	
protected:
	TIdRexecCommandEvent FOnCommand;
	virtual void __fastcall DoCMD(Idcontext::TIdContext* AThread, Idtcpclient::TIdTCPClient* AStdError, System::UnicodeString AParam1, System::UnicodeString AParam2, System::UnicodeString ACommand);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TIdRexecCommandEvent OnCommand = {read=FOnCommand, write=FOnCommand};
	__property DefaultPort = {default=512};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdRexecServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRexecServer(Classes::TComponent* AOwner)/* overload */ : Idremotecmdserver::TIdRemoteCMDServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idrexecserver */
using namespace Idrexecserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrexecserverHPP
