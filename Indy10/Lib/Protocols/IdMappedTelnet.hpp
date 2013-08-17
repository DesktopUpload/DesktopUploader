// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmappedtelnet.pas' rev: 20.00

#ifndef IdmappedtelnetHPP
#define IdmappedtelnetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idmappedporttcp.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmappedtelnet
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMappedTelnetThread;
class PASCALIMPLEMENTATION TIdMappedTelnetThread : public Idmappedporttcp::TIdMappedPortContext
{
	typedef Idmappedporttcp::TIdMappedPortContext inherited;
	
protected:
	int FAllowedConnectAttempts;
	virtual void __fastcall OutboundConnect(void);
	
public:
	__property int AllowedConnectAttempts = {read=FAllowedConnectAttempts, nodefault};
public:
	/* TIdMappedPortContext.Create */ inline __fastcall virtual TIdMappedTelnetThread(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList) : Idmappedporttcp::TIdMappedPortContext(AConnection, AYarn, AList) { }
	/* TIdMappedPortContext.Destroy */ inline __fastcall virtual ~TIdMappedTelnetThread(void) { }
	
};


typedef void __fastcall (__closure *TIdMappedTelnetCheckHostPort)(Idmappedporttcp::TIdMappedPortContext* AContext, const System::UnicodeString AHostPort, System::UnicodeString &VHost, System::UnicodeString &VPort);

class DELPHICLASS TIdCustomMappedTelnet;
class PASCALIMPLEMENTATION TIdCustomMappedTelnet : public Idmappedporttcp::TIdMappedPortTCP
{
	typedef Idmappedporttcp::TIdMappedPortTCP inherited;
	
protected:
	int FAllowedConnectAttempts;
	TIdMappedTelnetCheckHostPort FOnCheckHostPort;
	virtual void __fastcall DoCheckHostPort(Idmappedporttcp::TIdMappedPortContext* AContext, const System::UnicodeString AHostPort, System::UnicodeString &VHost, System::UnicodeString &VPort);
	void __fastcall SetAllowedConnectAttempts(const int Value);
	void __fastcall ExtractHostAndPortFromLine(Idmappedporttcp::TIdMappedPortContext* AContext, const System::UnicodeString AHostPort);
	virtual void __fastcall InitComponent(void);
	
public:
	__property int AllowedConnectAttempts = {read=FAllowedConnectAttempts, write=SetAllowedConnectAttempts, default=-1};
	__property TIdMappedTelnetCheckHostPort OnCheckHostPort = {read=FOnCheckHostPort, write=FOnCheckHostPort};
	
__published:
	__property DefaultPort = {default=23};
	__property MappedPort = {default=23};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdCustomMappedTelnet(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomMappedTelnet(Classes::TComponent* AOwner)/* overload */ : Idmappedporttcp::TIdMappedPortTCP(AOwner) { }
	
};


class DELPHICLASS TIdMappedTelnet;
class PASCALIMPLEMENTATION TIdMappedTelnet : public TIdCustomMappedTelnet
{
	typedef TIdCustomMappedTelnet inherited;
	
__published:
	__property int AllowedConnectAttempts = {read=FAllowedConnectAttempts, write=SetAllowedConnectAttempts, default=-1};
	__property TIdMappedTelnetCheckHostPort OnCheckHostPort = {read=FOnCheckHostPort, write=FOnCheckHostPort};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdMappedTelnet(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMappedTelnet(Classes::TComponent* AOwner)/* overload */ : TIdCustomMappedTelnet(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmappedtelnet */
using namespace Idmappedtelnet;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmappedtelnetHPP
