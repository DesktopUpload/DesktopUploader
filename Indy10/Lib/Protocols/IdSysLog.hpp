// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsyslog.pas' rev: 20.00

#ifndef IdsyslogHPP
#define IdsyslogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idsyslogmessage.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsyslog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSysLog;
class PASCALIMPLEMENTATION TIdSysLog : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall SendLogMessage(const Idsyslogmessage::TIdSysLogMessage* AMsg, const bool AAutoTimeStamp = true)/* overload */;
	void __fastcall SendLogMessage(const System::UnicodeString AMsg, const Idsyslogmessage::TIdSyslogFacility AFacility, const Idsyslogmessage::TIdSyslogSeverity ASeverity)/* overload */;
	void __fastcall SendLogMessage(const System::UnicodeString AProcess, const System::UnicodeString AText, const Idsyslogmessage::TIdSyslogFacility AFacility, const Idsyslogmessage::TIdSyslogSeverity ASeverity, const bool AUsePID = false, const int APID = 0xffffffff)/* overload */;
	
__published:
	__property Port = {default=514};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdSysLog(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSysLog(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsyslog */
using namespace Idsyslog;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsyslogHPP
