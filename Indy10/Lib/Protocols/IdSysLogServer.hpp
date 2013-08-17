// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsyslogserver.pas' rev: 20.00

#ifndef IdsyslogserverHPP
#define IdsyslogserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idsyslogmessage.hpp>	// Pascal unit
#include <Idsyslog.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsyslogserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TOnSyslogEvent)(System::TObject* Sender, Idsyslogmessage::TIdSysLogMessage* ASysLogMessage, Idsockethandle::TIdSocketHandle* ABinding);

class DELPHICLASS TIdSyslogServer;
class PASCALIMPLEMENTATION TIdSyslogServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	TOnSyslogEvent FOnSyslog;
	virtual void __fastcall DoSyslogEvent(Idsyslogmessage::TIdSysLogMessage* AMsg, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=514};
	__property TOnSyslogEvent OnSyslog = {read=FOnSyslog, write=FOnSyslog};
public:
	/* TIdUDPServer.Destroy */ inline __fastcall virtual ~TIdSyslogServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSyslogServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsyslogserver */
using namespace Idsyslogserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsyslogserverHPP
