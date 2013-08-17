// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtcpconnection.pas' rev: 20.00

#ifndef IdtcpconnectionHPP
#define IdtcpconnectionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtcpconnection
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTCPConnection;
class PASCALIMPLEMENTATION TIdTCPConnection : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	Idreply::TIdReply* FGreeting;
	Idintercept::TIdConnectionIntercept* FIntercept;
	Idiohandler::TIdIOHandler* FIOHandler;
	Idreply::TIdReply* FLastCmdResult;
	bool FManagedIOHandler;
	Classes::TNotifyEvent FOnDisconnected;
	Idiohandlersocket::TIdIOHandlerSocket* FSocket;
	Idreply::TIdReplyClass FReplyClass;
	void __fastcall CheckConnected(void);
	virtual void __fastcall DoOnDisconnected(void);
	virtual void __fastcall InitComponent(void);
	virtual Idintercept::TIdConnectionIntercept* __fastcall GetIntercept(void);
	virtual Idreply::TIdReplyClass __fastcall GetReplyClass(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetIntercept(Idintercept::TIdConnectionIntercept* AValue);
	virtual void __fastcall SetIOHandler(Idiohandler::TIdIOHandler* AValue);
	void __fastcall SetGreeting(Idreply::TIdReply* AValue);
	void __fastcall WorkBeginEvent(System::TObject* ASender, Idcomponent::TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall WorkEndEvent(System::TObject* ASender, Idcomponent::TWorkMode AWorkMode);
	void __fastcall WorkEvent(System::TObject* ASender, Idcomponent::TWorkMode AWorkMode, __int64 AWorkCount);
	virtual void __fastcall PrepareCmd(System::UnicodeString &aCmd);
	
public:
	void __fastcall CreateIOHandler(Idiohandler::TIdIOHandlerClass ABaseType = 0x0);
	virtual void __fastcall CheckForGracefulDisconnect(bool ARaiseExceptionIfDisconnected = true);
	virtual short __fastcall CheckResponse(const short AResponse, short const *AAllowedResponses, const int AAllowedResponses_Size)/* overload */;
	virtual System::UnicodeString __fastcall CheckResponse(const System::UnicodeString AResponse, const System::UnicodeString AAllowedResponse)/* overload */;
	virtual bool __fastcall Connected(void);
	__fastcall virtual ~TIdTCPConnection(void);
	void __fastcall Disconnect(void)/* overload */;
	virtual void __fastcall Disconnect(bool ANotifyPeer)/* overload */;
	virtual void __fastcall DisconnectNotifyPeer(void);
	virtual void __fastcall GetInternalResponse(Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	short __fastcall GetResponse(const short AAllowedResponse = (short)(0xffffffff), Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual short __fastcall GetResponse(short const *AAllowedResponses, const int AAllowedResponses_Size, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual System::UnicodeString __fastcall GetResponse(const System::UnicodeString AAllowedResponse, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	__property Idreply::TIdReply* Greeting = {read=FGreeting, write=SetGreeting};
	virtual void __fastcall RaiseExceptionForLastCmdResult(void)/* overload */;
	virtual void __fastcall RaiseExceptionForLastCmdResult(Idexception::TClassIdException AException)/* overload */;
	short __fastcall SendCmd(System::UnicodeString AOut, const short AResponse = (short)(0xffffffff), Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual short __fastcall SendCmd(System::UnicodeString AOut, short const *AResponse, const int AResponse_Size, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::UnicodeString __fastcall SendCmd(System::UnicodeString AOut, const System::UnicodeString AResponse, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall WriteHeader(Classes::TStrings* AHeader);
	void __fastcall WriteRFCStrings(Classes::TStrings* AStrings);
	__property Idreply::TIdReply* LastCmdResult = {read=FLastCmdResult};
	__property bool ManagedIOHandler = {read=FManagedIOHandler, write=FManagedIOHandler, nodefault};
	__property Idiohandlersocket::TIdIOHandlerSocket* Socket = {read=FSocket};
	
__published:
	__property Idintercept::TIdConnectionIntercept* Intercept = {read=GetIntercept, write=SetIntercept};
	__property Idiohandler::TIdIOHandler* IOHandler = {read=FIOHandler, write=SetIOHandler};
	__property Classes::TNotifyEvent OnDisconnected = {read=FOnDisconnected, write=FOnDisconnected};
	__property OnWork;
	__property OnWorkBegin;
	__property OnWorkEnd;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTCPConnection(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtcpconnection */
using namespace Idtcpconnection;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtcpconnectionHPP
