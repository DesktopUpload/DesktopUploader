// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsimpleserver.pas' rev: 20.00

#ifndef IdsimpleserverHPP
#define IdsimpleserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsimpleserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSimpleServer;
class PASCALIMPLEMENTATION TIdSimpleServer : public Idtcpconnection::TIdTCPConnection
{
	typedef Idtcpconnection::TIdTCPConnection inherited;
	
protected:
	bool FAbortedRequested;
	int FAcceptWait;
	System::UnicodeString FBoundIP;
	System::Word FBoundPort;
	System::Word FBoundPortMin;
	System::Word FBoundPortMax;
	Idglobal::TIdIPVersion FIPVersion;
	unsigned FListenHandle;
	bool FListening;
	Classes::TNotifyEvent FOnBeforeBind;
	Classes::TNotifyEvent FOnAfterBind;
	void __fastcall Bind(void);
	virtual void __fastcall DoBeforeBind(void);
	virtual void __fastcall DoAfterBind(void);
	Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall SetIOHandler(Idiohandler::TIdIOHandler* AValue);
	void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	
public:
	virtual void __fastcall Abort(void);
	virtual void __fastcall BeginListen(void);
	void __fastcall CreateBinding(void);
	virtual void __fastcall EndListen(void);
	virtual void __fastcall Listen(int ATimeout = 0xffffffff);
	__property int AcceptWait = {read=FAcceptWait, write=FAcceptWait, default=1000};
	
__published:
	__property System::UnicodeString BoundIP = {read=FBoundIP, write=FBoundIP};
	__property System::Word BoundPort = {read=FBoundPort, write=FBoundPort, nodefault};
	__property System::Word BoundPortMin = {read=FBoundPortMin, write=FBoundPortMin, nodefault};
	__property System::Word BoundPortMax = {read=FBoundPortMax, write=FBoundPortMax, nodefault};
	__property Idsockethandle::TIdSocketHandle* Binding = {read=GetBinding};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=SetIPVersion, nodefault};
	__property Classes::TNotifyEvent OnBeforeBind = {read=FOnBeforeBind, write=FOnBeforeBind};
	__property Classes::TNotifyEvent OnAfterBind = {read=FOnAfterBind, write=FOnAfterBind};
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdSimpleServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSimpleServer(Classes::TComponent* AOwner)/* overload */ : Idtcpconnection::TIdTCPConnection(AOwner) { }
	
};


class DELPHICLASS EIdCannotUseNonSocketIOHandler;
class PASCALIMPLEMENTATION EIdCannotUseNonSocketIOHandler : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCannotUseNonSocketIOHandler(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCannotUseNonSocketIOHandler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCannotUseNonSocketIOHandler(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCannotUseNonSocketIOHandler(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCannotUseNonSocketIOHandler(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCannotUseNonSocketIOHandler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCannotUseNonSocketIOHandler(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCannotUseNonSocketIOHandler(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCannotUseNonSocketIOHandler(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word ID_ACCEPT_WAIT = 0x3e8;

}	/* namespace Idsimpleserver */
using namespace Idsimpleserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsimpleserverHPP
