// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhttpproxyserver.pas' rev: 20.00

#ifndef IdhttpproxyserverHPP
#define IdhttpproxyserverHPP

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
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcmdtcpserver.hpp>	// Pascal unit
#include <Idcommandhandlers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhttpproxyserver
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdHTTPProxyTransferMode { tmFullDocument, tmStreaming };
#pragma option pop

#pragma option push -b-
enum TIdHTTPProxyTransferSource { tsClient, tsServer };
#pragma option pop

class DELPHICLASS TIdHTTPProxyServerContext;
class PASCALIMPLEMENTATION TIdHTTPProxyServerContext : public Idcustomtcpserver::TIdServerContext
{
	typedef Idcustomtcpserver::TIdServerContext inherited;
	
protected:
	Idheaderlist::TIdHeaderList* FHeaders;
	System::UnicodeString FCommand;
	System::UnicodeString FDocument;
	Idtcpconnection::TIdTCPConnection* FOutboundClient;
	TIdHTTPProxyTransferMode FTransferMode;
	TIdHTTPProxyTransferSource FTransferSource;
	
public:
	__fastcall virtual TIdHTTPProxyServerContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__fastcall virtual ~TIdHTTPProxyServerContext(void);
	__property Idheaderlist::TIdHeaderList* Headers = {read=FHeaders};
	__property System::UnicodeString Command = {read=FCommand};
	__property System::UnicodeString Document = {read=FDocument};
	__property Idtcpconnection::TIdTCPConnection* OutboundClient = {read=FOutboundClient};
	__property TIdHTTPProxyTransferMode TransferMode = {read=FTransferMode, write=FTransferMode, nodefault};
	__property TIdHTTPProxyTransferSource TransferSource = {read=FTransferSource, nodefault};
};


typedef void __fastcall (__closure *TOnHTTPContextEvent)(TIdHTTPProxyServerContext* AContext);

typedef void __fastcall (__closure *TOnHTTPDocument)(TIdHTTPProxyServerContext* AContext, Classes::TStream* &VStream);

class DELPHICLASS TIdHTTPProxyServer;
class PASCALIMPLEMENTATION TIdHTTPProxyServer : public Idcmdtcpserver::TIdCmdTCPServer
{
	typedef Idcmdtcpserver::TIdCmdTCPServer inherited;
	
protected:
	TIdHTTPProxyTransferMode FDefTransferMode;
	TOnHTTPContextEvent FOnHTTPBeforeCommand;
	TOnHTTPContextEvent FOnHTTPResponse;
	TOnHTTPDocument FOnHTTPDocument;
	void __fastcall CommandPassThrough(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandCONNECT(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall DoHTTPBeforeCommand(TIdHTTPProxyServerContext* AContext);
	void __fastcall DoHTTPDocument(TIdHTTPProxyServerContext* AContext, Classes::TStream* &VStream);
	void __fastcall DoHTTPResponse(TIdHTTPProxyServerContext* AContext);
	virtual void __fastcall InitializeCommandHandlers(void);
	void __fastcall TransferData(TIdHTTPProxyServerContext* AContext, Idtcpconnection::TIdTCPConnection* ASrc, Idtcpconnection::TIdTCPConnection* ADest);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=8080};
	__property TIdHTTPProxyTransferMode DefaultTransferMode = {read=FDefTransferMode, write=FDefTransferMode, default=0};
	__property TOnHTTPContextEvent OnHTTPBeforeCommand = {read=FOnHTTPBeforeCommand, write=FOnHTTPBeforeCommand};
	__property TOnHTTPContextEvent OnHTTPResponse = {read=FOnHTTPResponse, write=FOnHTTPResponse};
	__property TOnHTTPDocument OnHTTPDocument = {read=FOnHTTPDocument, write=FOnHTTPDocument};
public:
	/* TIdCmdTCPServer.Destroy */ inline __fastcall virtual ~TIdHTTPProxyServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdHTTPProxyServer(Classes::TComponent* AOwner)/* overload */ : Idcmdtcpserver::TIdCmdTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word IdPORT_HTTPProxy = 0x1f90;

}	/* namespace Idhttpproxyserver */
using namespace Idhttpproxyserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhttpproxyserverHPP
