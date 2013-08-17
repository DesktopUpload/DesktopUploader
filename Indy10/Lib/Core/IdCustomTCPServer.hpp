// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcustomtcpserver.pas' rev: 20.00

#ifndef IdcustomtcpserverHPP
#define IdcustomtcpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idschedulerofthread.hpp>	// Pascal unit
#include <Idserveriohandler.hpp>	// Pascal unit
#include <Idserveriohandlerstack.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcustomtcpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdListenerThread;
class DELPHICLASS TIdCustomTCPServer;
class PASCALIMPLEMENTATION TIdListenerThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	TIdCustomTCPServer* FServer;
	Idthread::TIdNotifyThreadEvent FOnBeforeRun;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall BeforeRun(void);
	virtual void __fastcall Run(void);
	
public:
	__fastcall TIdListenerThread(TIdCustomTCPServer* AServer, Idsockethandle::TIdSocketHandle* ABinding);
	__property Idsockethandle::TIdSocketHandle* Binding = {read=FBinding};
	__property TIdCustomTCPServer* Server = {read=FServer};
	__property Idthread::TIdNotifyThreadEvent OnBeforeRun = {read=FOnBeforeRun, write=FOnBeforeRun};
public:
	/* TIdThread.Destroy */ inline __fastcall virtual ~TIdListenerThread(void) { }
	
};


typedef void __fastcall (__closure *TIdListenExceptionEvent)(TIdListenerThread* AThread, Sysutils::Exception* AException);

typedef void __fastcall (__closure *TIdServerThreadExceptionEvent)(Idcontext::TIdContext* AContext, Sysutils::Exception* AException);

typedef void __fastcall (__closure *TIdServerThreadEvent)(Idcontext::TIdContext* AContext);

class DELPHICLASS TIdServerContext;
class PASCALIMPLEMENTATION TIdServerContext : public Idcontext::TIdContext
{
	typedef Idcontext::TIdContext inherited;
	
protected:
	TIdCustomTCPServer* FServer;
	
public:
	__property TIdCustomTCPServer* Server = {read=FServer};
public:
	/* TIdContext.Create */ inline __fastcall virtual TIdServerContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList) : Idcontext::TIdContext(AConnection, AYarn, AList) { }
	/* TIdContext.Destroy */ inline __fastcall virtual ~TIdServerContext(void) { }
	
};


typedef TMetaClass* TIdServerContextClass;

class PASCALIMPLEMENTATION TIdCustomTCPServer : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	bool FActive;
	Idscheduler::TIdScheduler* FScheduler;
	Idsockethandle::TIdSocketHandles* FBindings;
	TIdServerContextClass FContextClass;
	bool FImplicitScheduler;
	bool FImplicitIOHandler;
	Idintercept::TIdServerIntercept* FIntercept;
	Idserveriohandler::TIdServerIOHandler* FIOHandler;
	Classes::TThreadList* FListenerThreads;
	int FListenQueue;
	int FMaxConnections;
	Idglobal::TIdReuseSocket FReuseSocket;
	int FTerminateWaitTime;
	Classes::TThreadList* FContexts;
	TIdServerThreadEvent FOnConnect;
	TIdServerThreadEvent FOnDisconnect;
	TIdServerThreadExceptionEvent FOnException;
	TIdServerThreadEvent FOnExecute;
	TIdListenExceptionEvent FOnListenException;
	Idsockethandle::TIdSocketHandleEvent FOnBeforeBind;
	Classes::TNotifyEvent FOnAfterBind;
	Idthread::TIdNotifyThreadEvent FOnBeforeListenerRun;
	void __fastcall CheckActive(void);
	virtual void __fastcall CheckOkToBeActive(void);
	virtual void __fastcall ContextCreated(Idcontext::TIdContext* AContext);
	virtual void __fastcall ContextConnected(Idcontext::TIdContext* AContext);
	virtual void __fastcall ContextDisconnected(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoBeforeBind(Idsockethandle::TIdSocketHandle* AHandle);
	virtual void __fastcall DoAfterBind(void);
	virtual void __fastcall DoBeforeListenerRun(Idthread::TIdThread* AThread);
	virtual void __fastcall DoConnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoDisconnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoException(Idcontext::TIdContext* AContext, Sysutils::Exception* AException);
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall DoListenException(TIdListenerThread* AThread, Sysutils::Exception* AException);
	virtual void __fastcall DoMaxConnectionsExceeded(Idiohandler::TIdIOHandler* AIOHandler);
	virtual void __fastcall DoTerminateContext(Idcontext::TIdContext* AContext);
	System::Word __fastcall GetDefaultPort(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SendGreeting(Idcontext::TIdContext* AContext, Idreply::TIdReply* AGreeting);
	virtual void __fastcall SetActive(bool AValue);
	virtual void __fastcall SetBindings(const Idsockethandle::TIdSocketHandles* AValue);
	virtual void __fastcall SetDefaultPort(const System::Word AValue);
	virtual void __fastcall SetIntercept(const Idintercept::TIdServerIntercept* AValue);
	virtual void __fastcall SetIOHandler(const Idserveriohandler::TIdServerIOHandler* AValue);
	virtual void __fastcall SetScheduler(const Idscheduler::TIdScheduler* AValue);
	virtual void __fastcall Startup(void);
	virtual void __fastcall Shutdown(void);
	void __fastcall TerminateAllThreads(void);
	__property TIdServerThreadEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	
public:
	__fastcall virtual ~TIdCustomTCPServer(void);
	void __fastcall StartListening(void);
	void __fastcall StopListening(void);
	__property Classes::TThreadList* Contexts = {read=FContexts};
	__property TIdServerContextClass ContextClass = {read=FContextClass, write=FContextClass};
	__property bool ImplicitIOHandler = {read=FImplicitIOHandler, nodefault};
	__property bool ImplicitScheduler = {read=FImplicitScheduler, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property Idsockethandle::TIdSocketHandles* Bindings = {read=FBindings, write=SetBindings};
	__property System::Word DefaultPort = {read=GetDefaultPort, write=SetDefaultPort, nodefault};
	__property Idintercept::TIdServerIntercept* Intercept = {read=FIntercept, write=SetIntercept};
	__property Idserveriohandler::TIdServerIOHandler* IOHandler = {read=FIOHandler, write=SetIOHandler};
	__property int ListenQueue = {read=FListenQueue, write=FListenQueue, default=15};
	__property int MaxConnections = {read=FMaxConnections, write=FMaxConnections, default=0};
	__property Idsockethandle::TIdSocketHandleEvent OnBeforeBind = {read=FOnBeforeBind, write=FOnBeforeBind};
	__property Classes::TNotifyEvent OnAfterBind = {read=FOnAfterBind, write=FOnAfterBind};
	__property Idthread::TIdNotifyThreadEvent OnBeforeListenerRun = {read=FOnBeforeListenerRun, write=FOnBeforeListenerRun};
	__property TIdServerThreadEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property TIdServerThreadEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
	__property TIdServerThreadExceptionEvent OnException = {read=FOnException, write=FOnException};
	__property TIdListenExceptionEvent OnListenException = {read=FOnListenException, write=FOnListenException};
	__property Idglobal::TIdReuseSocket ReuseSocket = {read=FReuseSocket, write=FReuseSocket, default=0};
	__property int TerminateWaitTime = {read=FTerminateWaitTime, write=FTerminateWaitTime, default=5000};
	__property Idscheduler::TIdScheduler* Scheduler = {read=FScheduler, write=SetScheduler};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomTCPServer(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


class DELPHICLASS EIdTCPServerError;
class PASCALIMPLEMENTATION EIdTCPServerError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTCPServerError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTCPServerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTCPServerError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTCPServerError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTCPServerError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTCPServerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTCPServerError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTCPServerError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTCPServerError(void) { }
	
};


class DELPHICLASS EIdNoExecuteSpecified;
class PASCALIMPLEMENTATION EIdNoExecuteSpecified : public EIdTCPServerError
{
	typedef EIdTCPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNoExecuteSpecified(const System::UnicodeString AMsg)/* overload */ : EIdTCPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNoExecuteSpecified(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNoExecuteSpecified(int Ident)/* overload */ : EIdTCPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNoExecuteSpecified(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNoExecuteSpecified(const System::UnicodeString Msg, int AHelpContext) : EIdTCPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNoExecuteSpecified(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNoExecuteSpecified(int Ident, int AHelpContext)/* overload */ : EIdTCPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNoExecuteSpecified(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNoExecuteSpecified(void) { }
	
};


class DELPHICLASS EIdTerminateThreadTimeout;
class PASCALIMPLEMENTATION EIdTerminateThreadTimeout : public EIdTCPServerError
{
	typedef EIdTCPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTerminateThreadTimeout(const System::UnicodeString AMsg)/* overload */ : EIdTCPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTerminateThreadTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTerminateThreadTimeout(int Ident)/* overload */ : EIdTCPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTerminateThreadTimeout(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTerminateThreadTimeout(const System::UnicodeString Msg, int AHelpContext) : EIdTCPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTerminateThreadTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTerminateThreadTimeout(int Ident, int AHelpContext)/* overload */ : EIdTCPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTerminateThreadTimeout(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTerminateThreadTimeout(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt IdListenQueueDefault = 0xf;

}	/* namespace Idcustomtcpserver */
using namespace Idcustomtcpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcustomtcpserverHPP
