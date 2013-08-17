// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmappedporttcp.pas' rev: 20.00

#ifndef IdmappedporttcpHPP
#define IdmappedporttcpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmappedporttcp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMappedPortContext;
class DELPHICLASS TIdMappedPortTCP;
class PASCALIMPLEMENTATION TIdMappedPortContext : public Idcustomtcpserver::TIdServerContext
{
	typedef Idcustomtcpserver::TIdServerContext inherited;
	
protected:
	Idtcpconnection::TIdTCPConnection* FOutboundClient;
	Idstack::TIdSocketList* FReadList;
	Idstack::TIdSocketList* FDataAvailList;
	System::UnicodeString FNetData;
	int FConnectTimeOut;
	TIdMappedPortTCP* FServer;
	virtual void __fastcall CheckForData(bool DoRead);
	virtual void __fastcall OutboundConnect(void);
	
public:
	__fastcall virtual TIdMappedPortContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__fastcall virtual ~TIdMappedPortContext(void);
	__property TIdMappedPortTCP* Server = {read=FServer, write=FServer};
	__property int ConnectTimeOut = {read=FConnectTimeOut, write=FConnectTimeOut, default=-1};
	__property System::UnicodeString NetData = {read=FNetData, write=FNetData};
	__property Idtcpconnection::TIdTCPConnection* OutboundClient = {read=FOutboundClient, write=FOutboundClient};
};


class PASCALIMPLEMENTATION TIdMappedPortTCP : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	System::UnicodeString FMappedHost;
	System::Word FMappedPort;
	Idcustomtcpserver::TIdServerThreadEvent FOnBeforeConnect;
	Idcustomtcpserver::TIdServerThreadEvent FOnOutboundConnect;
	Idcustomtcpserver::TIdServerThreadEvent FOnOutboundData;
	Idcustomtcpserver::TIdServerThreadEvent FOnOutboundDisConnect;
	virtual void __fastcall ContextCreated(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoBeforeConnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoConnect(Idcontext::TIdContext* AContext);
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoDisconnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoLocalClientConnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoLocalClientData(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoOutboundClientConnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoOutboundClientData(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoOutboundDisconnect(Idcontext::TIdContext* AContext);
	Idcustomtcpserver::TIdServerThreadEvent __fastcall GetOnConnect();
	Idcustomtcpserver::TIdServerThreadEvent __fastcall GetOnExecute();
	void __fastcall SetOnConnect(const Idcustomtcpserver::TIdServerThreadEvent Value);
	void __fastcall SetOnExecute(const Idcustomtcpserver::TIdServerThreadEvent Value);
	Idcustomtcpserver::TIdServerThreadEvent __fastcall GetOnDisconnect();
	void __fastcall SetOnDisconnect(const Idcustomtcpserver::TIdServerThreadEvent Value);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property Idcustomtcpserver::TIdServerThreadEvent OnBeforeConnect = {read=FOnBeforeConnect, write=FOnBeforeConnect};
	__property System::UnicodeString MappedHost = {read=FMappedHost, write=FMappedHost};
	__property System::Word MappedPort = {read=FMappedPort, write=FMappedPort, nodefault};
	__property Idcustomtcpserver::TIdServerThreadEvent OnConnect = {read=GetOnConnect, write=SetOnConnect};
	__property Idcustomtcpserver::TIdServerThreadEvent OnOutboundConnect = {read=FOnOutboundConnect, write=FOnOutboundConnect};
	__property Idcustomtcpserver::TIdServerThreadEvent OnExecute = {read=GetOnExecute, write=SetOnExecute};
	__property Idcustomtcpserver::TIdServerThreadEvent OnOutboundData = {read=FOnOutboundData, write=FOnOutboundData};
	__property Idcustomtcpserver::TIdServerThreadEvent OnDisconnect = {read=GetOnDisconnect, write=SetOnDisconnect};
	__property Idcustomtcpserver::TIdServerThreadEvent OnOutboundDisconnect = {read=FOnOutboundDisConnect, write=FOnOutboundDisConnect};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdMappedPortTCP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMappedPortTCP(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmappedporttcp */
using namespace Idmappedporttcp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmappedporttcpHPP
