// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idiohandlersocket.pas' rev: 20.00

#ifndef IdiohandlersocketHPP
#define IdiohandlersocketHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcustomtransparentproxy.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idiohandlersocket
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIOHandlerSocket;
class PASCALIMPLEMENTATION TIdIOHandlerSocket : public Idiohandler::TIdIOHandler
{
	typedef Idiohandler::TIdIOHandler inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	System::UnicodeString FBoundIP;
	System::Word FBoundPort;
	System::Word FBoundPortMax;
	System::Word FBoundPortMin;
	System::Word FDefaultPort;
	Classes::TNotifyEvent FOnBeforeBind;
	Classes::TNotifyEvent FOnAfterBind;
	Classes::TNotifyEvent FOnSocketAllocated;
	Idcustomtransparentproxy::TIdCustomTransparentProxy* FTransparentProxy;
	bool FUseNagle;
	Idglobal::TIdReuseSocket FReuseSocket;
	Idglobal::TIdIPVersion FIPVersion;
	virtual void __fastcall ConnectClient(void);
	virtual void __fastcall DoBeforeBind(void);
	virtual void __fastcall DoAfterBind(void);
	virtual void __fastcall DoSocketAllocated(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual System::UnicodeString __fastcall GetDestination();
	virtual void __fastcall SetDestination(const System::UnicodeString AValue);
	virtual Idcustomtransparentproxy::TIdCustomTransparentProxy* __fastcall GetTransparentProxy(void);
	virtual void __fastcall SetTransparentProxy(Idcustomtransparentproxy::TIdCustomTransparentProxy* AProxy);
	void __fastcall SetUseNagle(bool AValue);
	void __fastcall SetNagleOpt(bool AEnabled);
	virtual bool __fastcall SourceIsAvailable(void);
	
public:
	__fastcall virtual ~TIdIOHandlerSocket(void);
	bool __fastcall BindingAllocated(void);
	virtual void __fastcall Close(void);
	virtual bool __fastcall Connected(void);
	virtual void __fastcall Open(void);
	virtual __int64 __fastcall WriteFile(const System::UnicodeString AFile, bool AEnableTransferFile = false);
	__property Idsockethandle::TIdSocketHandle* Binding = {read=FBinding};
	__property System::Word BoundPortMax = {read=FBoundPortMax, write=FBoundPortMax, nodefault};
	__property System::Word BoundPortMin = {read=FBoundPortMin, write=FBoundPortMin, nodefault};
	__property Classes::TNotifyEvent OnBeforeBind = {read=FOnBeforeBind, write=FOnBeforeBind};
	__property Classes::TNotifyEvent OnAfterBind = {read=FOnAfterBind, write=FOnAfterBind};
	__property Classes::TNotifyEvent OnSocketAllocated = {read=FOnSocketAllocated, write=FOnSocketAllocated};
	
__published:
	__property System::UnicodeString BoundIP = {read=FBoundIP, write=FBoundIP};
	__property System::Word BoundPort = {read=FBoundPort, write=FBoundPort, default=0};
	__property System::Word DefaultPort = {read=FDefaultPort, write=FDefaultPort, nodefault};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=FIPVersion, default=0};
	__property Idglobal::TIdReuseSocket ReuseSocket = {read=FReuseSocket, write=FReuseSocket, default=0};
	__property Idcustomtransparentproxy::TIdCustomTransparentProxy* TransparentProxy = {read=GetTransparentProxy, write=SetTransparentProxy};
	__property bool UseNagle = {read=FUseNagle, write=SetUseNagle, default=1};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIOHandlerSocket(Classes::TComponent* AOwner)/* overload */ : Idiohandler::TIdIOHandler(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt IdDefTimeout = 0x0;
static const ShortInt IdBoundPortDefault = 0x0;

}	/* namespace Idiohandlersocket */
using namespace Idiohandlersocket;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdiohandlersocketHPP
