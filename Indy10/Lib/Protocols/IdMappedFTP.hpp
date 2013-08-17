// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmappedftp.pas' rev: 20.00

#ifndef IdmappedftpHPP
#define IdmappedftpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idmappedporttcp.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmappedftp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMappedFtpContext;
class DELPHICLASS TIdMappedFtpDataThread;
class PASCALIMPLEMENTATION TIdMappedFtpContext : public Idmappedporttcp::TIdMappedPortContext
{
	typedef Idmappedporttcp::TIdMappedPortContext inherited;
	
protected:
	System::UnicodeString FFtpCommand;
	System::UnicodeString FFtpParams;
	System::UnicodeString FHost;
	System::UnicodeString FoutboundHost;
	System::Word FPort;
	System::Word FoutboundPort;
	TIdMappedFtpDataThread* FDataChannelThread;
	virtual void __fastcall CheckForData(bool DoRead);
	System::UnicodeString __fastcall GetFtpCmdLine();
	void __fastcall CreateDataChannelThread(void);
	virtual bool __fastcall ProcessFtpCommand(void);
	virtual void __fastcall ProcessOutboundDc(const bool APASV);
	virtual void __fastcall ProcessDataCommand(void);
	
public:
	__fastcall virtual TIdMappedFtpContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__property System::UnicodeString FtpCommand = {read=FFtpCommand, write=FFtpCommand};
	__property System::UnicodeString FtpParams = {read=FFtpParams, write=FFtpParams};
	__property System::UnicodeString FtpCmdLine = {read=GetFtpCmdLine};
	__property System::UnicodeString Host = {read=FHost, write=FHost};
	__property System::UnicodeString OutboundHost = {read=FoutboundHost, write=FoutboundHost};
	__property System::Word Port = {read=FPort, write=FPort, nodefault};
	__property System::Word OutboundPort = {read=FoutboundPort, write=FoutboundPort, nodefault};
	__property TIdMappedFtpDataThread* DataChannelThread = {read=FDataChannelThread};
public:
	/* TIdMappedPortContext.Destroy */ inline __fastcall virtual ~TIdMappedFtpContext(void) { }
	
};


class PASCALIMPLEMENTATION TIdMappedFtpDataThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	TIdMappedFtpContext* FMappedFtpThread;
	Idtcpconnection::TIdTCPConnection* FConnection;
	Idtcpconnection::TIdTCPConnection* FOutboundClient;
	Idstack::TIdSocketList* FReadList;
	Sysutils::TBytes FNetData;
	virtual void __fastcall BeforeRun(void);
	virtual void __fastcall Run(void);
	
public:
	__fastcall TIdMappedFtpDataThread(TIdMappedFtpContext* AMappedFtpThread);
	__fastcall virtual ~TIdMappedFtpDataThread(void);
	__property TIdMappedFtpContext* MappedFtpThread = {read=FMappedFtpThread};
	__property Idtcpconnection::TIdTCPConnection* Connection = {read=FConnection};
	__property Idtcpconnection::TIdTCPConnection* OutboundClient = {read=FOutboundClient};
	__property Sysutils::TBytes NetData = {read=FNetData, write=FNetData};
};


#pragma option push -b-
enum TIdMappedFtpOutboundDcMode { fdcmClient, fdcmPort, fdcmPasv };
#pragma option pop

class DELPHICLASS TIdMappedFTP;
class PASCALIMPLEMENTATION TIdMappedFTP : public Idmappedporttcp::TIdMappedPortTCP
{
	typedef Idmappedporttcp::TIdMappedPortTCP inherited;
	
protected:
	TIdMappedFtpOutboundDcMode FOutboundDcMode;
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=21};
	__property MappedPort = {default=21};
	__property TIdMappedFtpOutboundDcMode OutboundDcMode = {read=FOutboundDcMode, write=FOutboundDcMode, default=0};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdMappedFTP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMappedFTP(Classes::TComponent* AOwner)/* overload */ : Idmappedporttcp::TIdMappedPortTCP(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmappedftp */
using namespace Idmappedftp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmappedftpHPP
