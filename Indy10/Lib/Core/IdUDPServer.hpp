// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idudpserver.pas' rev: 20.00

#ifndef IdudpserverHPP
#define IdudpserverHPP

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
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idudpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUDPListenerThread;
class DELPHICLASS TIdUDPServer;
class PASCALIMPLEMENTATION TIdUDPListenerThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	int FAcceptWait;
	Sysutils::TBytes FBuffer;
	System::UnicodeString FCurrentException;
	System::TClass FCurrentExceptionClass;
	System::TObject* FData;
	TIdUDPServer* FServer;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall Run(void);
	
public:
	__fastcall virtual TIdUDPListenerThread(TIdUDPServer* AOwner, Idsockethandle::TIdSocketHandle* ABinding);
	__fastcall virtual ~TIdUDPListenerThread(void);
	void __fastcall UDPRead(void);
	void __fastcall UDPException(void);
	__property int AcceptWait = {read=FAcceptWait, write=FAcceptWait, nodefault};
	__property Idsockethandle::TIdSocketHandle* Binding = {read=FBinding};
	__property TIdUDPServer* Server = {read=FServer};
	__property System::TObject* Data = {read=FData, write=FData};
};


typedef TMetaClass* TIdUDPListenerThreadClass;

typedef void __fastcall (__closure *TIdUDPExceptionEvent)(TIdUDPListenerThread* AThread, Idsockethandle::TIdSocketHandle* ABinding, const System::UnicodeString AMessage, const System::TClass AExceptionClass);

typedef void __fastcall (__closure *TUDPReadEvent)(TIdUDPListenerThread* AThread, Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);

class PASCALIMPLEMENTATION TIdUDPServer : public Idudpbase::TIdUDPBase
{
	typedef Idudpbase::TIdUDPBase inherited;
	
protected:
	Idsockethandle::TIdSocketHandles* FBindings;
	Idsockethandle::TIdSocketHandle* FCurrentBinding;
	Classes::TThreadList* FListenerThreads;
	TIdUDPListenerThreadClass FThreadClass;
	bool FThreadedEvent;
	Idsockethandle::TIdSocketHandleEvent FOnBeforeBind;
	Classes::TNotifyEvent FOnAfterBind;
	TUDPReadEvent FOnUDPRead;
	TIdUDPExceptionEvent FOnUDPException;
	DYNAMIC void __fastcall BroadcastEnabledChanged(void);
	virtual void __fastcall CloseBinding(void);
	virtual void __fastcall DoBeforeBind(Idsockethandle::TIdSocketHandle* AHandle);
	virtual void __fastcall DoAfterBind(void);
	virtual void __fastcall DoOnUDPException(TIdUDPListenerThread* AThread, Idsockethandle::TIdSocketHandle* ABinding, const System::UnicodeString AMessage, const System::TClass AExceptionClass);
	virtual void __fastcall DoUDPRead(TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual bool __fastcall GetActive(void);
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	System::Word __fastcall GetDefaultPort(void);
	virtual void __fastcall InitComponent(void);
	void __fastcall SetBindings(const Idsockethandle::TIdSocketHandles* Value);
	void __fastcall SetDefaultPort(const System::Word AValue);
	
public:
	__fastcall virtual ~TIdUDPServer(void);
	__property TIdUDPListenerThreadClass ThreadClass = {read=FThreadClass, write=FThreadClass};
	
__published:
	__property Idsockethandle::TIdSocketHandles* Bindings = {read=FBindings, write=SetBindings};
	__property System::Word DefaultPort = {read=GetDefaultPort, write=SetDefaultPort, nodefault};
	__property bool ThreadedEvent = {read=FThreadedEvent, write=FThreadedEvent, default=0};
	__property Idsockethandle::TIdSocketHandleEvent OnBeforeBind = {read=FOnBeforeBind, write=FOnBeforeBind};
	__property Classes::TNotifyEvent OnAfterBind = {read=FOnAfterBind, write=FOnAfterBind};
	__property TUDPReadEvent OnUDPRead = {read=FOnUDPRead, write=FOnUDPRead};
	__property TIdUDPExceptionEvent OnUDPException = {read=FOnUDPException, write=FOnUDPException};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpbase::TIdUDPBase(AOwner) { }
	
};


class DELPHICLASS EIdUDPServerException;
class PASCALIMPLEMENTATION EIdUDPServerException : public Idudpbase::EIdUDPException
{
	typedef Idudpbase::EIdUDPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdUDPServerException(const System::UnicodeString AMsg)/* overload */ : Idudpbase::EIdUDPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdUDPServerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idudpbase::EIdUDPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdUDPServerException(int Ident)/* overload */ : Idudpbase::EIdUDPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdUDPServerException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idudpbase::EIdUDPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdUDPServerException(const System::UnicodeString Msg, int AHelpContext) : Idudpbase::EIdUDPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdUDPServerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idudpbase::EIdUDPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdUDPServerException(int Ident, int AHelpContext)/* overload */ : Idudpbase::EIdUDPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdUDPServerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idudpbase::EIdUDPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdUDPServerException(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idudpserver */
using namespace Idudpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdudpserverHPP
