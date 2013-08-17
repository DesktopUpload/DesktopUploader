// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsocksserver.pas' rev: 20.00

#ifndef IdsocksserverHPP
#define IdsocksserverHPP

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
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsocksserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdSocksSvrException;
class PASCALIMPLEMENTATION EIdSocksSvrException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrException(void) { }
	
};


class DELPHICLASS EIdSocksSvrNotSupported;
class PASCALIMPLEMENTATION EIdSocksSvrNotSupported : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrNotSupported(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrNotSupported(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrNotSupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrNotSupported(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrNotSupported(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrNotSupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrNotSupported(void) { }
	
};


class DELPHICLASS EIdSocksSvrInvalidLogin;
class PASCALIMPLEMENTATION EIdSocksSvrInvalidLogin : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrInvalidLogin(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrInvalidLogin(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrInvalidLogin(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrInvalidLogin(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrInvalidLogin(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrInvalidLogin(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrInvalidLogin(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrInvalidLogin(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrInvalidLogin(void) { }
	
};


class DELPHICLASS EIdSocksSvrSocks5WrongATYP;
class PASCALIMPLEMENTATION EIdSocksSvrSocks5WrongATYP : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrSocks5WrongATYP(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrSocks5WrongATYP(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrSocks5WrongATYP(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrSocks5WrongATYP(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrSocks5WrongATYP(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrSocks5WrongATYP(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrSocks5WrongATYP(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrSocks5WrongATYP(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrSocks5WrongATYP(void) { }
	
};


class DELPHICLASS EIdSocksSvrWrongSocksVer;
class PASCALIMPLEMENTATION EIdSocksSvrWrongSocksVer : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrWrongSocksVer(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrWrongSocksVer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrWrongSocksVer(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrWrongSocksVer(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrWrongSocksVer(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrWrongSocksVer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrWrongSocksVer(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrWrongSocksVer(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrWrongSocksVer(void) { }
	
};


class DELPHICLASS EIdSocksSvrWrongSocksCmd;
class PASCALIMPLEMENTATION EIdSocksSvrWrongSocksCmd : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrWrongSocksCmd(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrWrongSocksCmd(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrWrongSocksCmd(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrWrongSocksCmd(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrWrongSocksCmd(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrWrongSocksCmd(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrWrongSocksCmd(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrWrongSocksCmd(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrWrongSocksCmd(void) { }
	
};


class DELPHICLASS EIdSocksSvrAccessDenied;
class PASCALIMPLEMENTATION EIdSocksSvrAccessDenied : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrAccessDenied(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrAccessDenied(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrAccessDenied(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrAccessDenied(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrAccessDenied(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrAccessDenied(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrAccessDenied(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrAccessDenied(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrAccessDenied(void) { }
	
};


class DELPHICLASS EIdSocksSvrUnexpectedClose;
class PASCALIMPLEMENTATION EIdSocksSvrUnexpectedClose : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrUnexpectedClose(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrUnexpectedClose(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrUnexpectedClose(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrUnexpectedClose(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrUnexpectedClose(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrUnexpectedClose(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrUnexpectedClose(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrUnexpectedClose(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrUnexpectedClose(void) { }
	
};


class DELPHICLASS EIdSocksSvrPeerMismatch;
class PASCALIMPLEMENTATION EIdSocksSvrPeerMismatch : public EIdSocksSvrException
{
	typedef EIdSocksSvrException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksSvrPeerMismatch(const System::UnicodeString AMsg)/* overload */ : EIdSocksSvrException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksSvrPeerMismatch(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksSvrException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksSvrPeerMismatch(int Ident)/* overload */ : EIdSocksSvrException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksSvrPeerMismatch(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksSvrException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksSvrPeerMismatch(const System::UnicodeString Msg, int AHelpContext) : EIdSocksSvrException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksSvrPeerMismatch(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksSvrException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksSvrPeerMismatch(int Ident, int AHelpContext)/* overload */ : EIdSocksSvrException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksSvrPeerMismatch(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksSvrException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksSvrPeerMismatch(void) { }
	
};


class DELPHICLASS TIdSocksServerContext;
class PASCALIMPLEMENTATION TIdSocksServerContext : public Idcustomtcpserver::TIdServerContext
{
	typedef Idcustomtcpserver::TIdServerContext inherited;
	
protected:
	Idglobal::TIdIPVersion FIPVersion;
	System::UnicodeString FUsername;
	System::UnicodeString FPassword;
	System::Byte FSocksVersion;
	
public:
	__fastcall virtual TIdSocksServerContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, nodefault};
	__property System::UnicodeString Username = {read=FUsername};
	__property System::UnicodeString Password = {read=FPassword};
	__property System::Byte SocksVersion = {read=FSocksVersion, nodefault};
public:
	/* TIdContext.Destroy */ inline __fastcall virtual ~TIdSocksServerContext(void) { }
	
};


typedef void __fastcall (__closure *TIdOnAuthenticate)(TIdSocksServerContext* AContext, bool &AAuthenticated);

typedef void __fastcall (__closure *TIdOnBeforeEvent)(TIdSocksServerContext* AContext, System::UnicodeString &VHost, System::Word &VPort, bool &VAllowed);

typedef void __fastcall (__closure *TIdOnVerifyEvent)(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::UnicodeString APeer, bool &VAllowed);

class DELPHICLASS TIdCustomSocksServer;
class PASCALIMPLEMENTATION TIdCustomSocksServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	bool FNeedsAuthentication;
	bool FAllowSocks4;
	bool FAllowSocks5;
	TIdOnAuthenticate FOnAuthenticate;
	TIdOnBeforeEvent FOnBeforeSocksConnect;
	TIdOnBeforeEvent FOnBeforeSocksBind;
	TIdOnVerifyEvent FOnVerifyBoundPeer;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall CommandConnect(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort) = 0 ;
	virtual void __fastcall CommandBind(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort) = 0 ;
	virtual bool __fastcall DoAuthenticate(TIdSocksServerContext* AContext);
	virtual bool __fastcall DoBeforeSocksConnect(TIdSocksServerContext* AContext, System::UnicodeString &VHost, System::Word &VPort);
	virtual bool __fastcall DoBeforeSocksBind(TIdSocksServerContext* AContext, System::UnicodeString &VHost, System::Word &VPort);
	virtual bool __fastcall DoVerifyBoundPeer(TIdSocksServerContext* AContext, const System::UnicodeString AExpected, const System::UnicodeString AActual);
	virtual void __fastcall HandleConnectV4(TIdSocksServerContext* AContext, System::Byte &VCommand, System::UnicodeString &VHost, System::Word &VPort);
	virtual void __fastcall HandleConnectV5(TIdSocksServerContext* AContext, System::Byte &VCommand, System::UnicodeString &VHost, System::Word &VPort);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property DefaultPort = {default=1080};
	__property bool AllowSocks4 = {read=FAllowSocks4, write=FAllowSocks4, nodefault};
	__property bool AllowSocks5 = {read=FAllowSocks5, write=FAllowSocks5, nodefault};
	__property bool NeedsAuthentication = {read=FNeedsAuthentication, write=FNeedsAuthentication, nodefault};
	__property TIdOnAuthenticate OnAuthenticate = {read=FOnAuthenticate, write=FOnAuthenticate};
	__property TIdOnBeforeEvent OnBeforeSocksConnect = {read=FOnBeforeSocksConnect, write=FOnBeforeSocksConnect};
	__property TIdOnBeforeEvent OnBeforeSocksBind = {read=FOnBeforeSocksBind, write=FOnBeforeSocksBind};
	__property TIdOnVerifyEvent OnVerifyBoundPeer = {read=FOnVerifyBoundPeer, write=FOnVerifyBoundPeer};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdCustomSocksServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomSocksServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


class DELPHICLASS TIdSocksServer;
class PASCALIMPLEMENTATION TIdSocksServer : public TIdCustomSocksServer
{
	typedef TIdCustomSocksServer inherited;
	
protected:
	virtual void __fastcall CommandConnect(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort);
	virtual void __fastcall CommandBind(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort);
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdSocksServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSocksServer(Classes::TComponent* AOwner)/* overload */ : TIdCustomSocksServer(AOwner) { }
	
};


typedef void __fastcall (__closure *TIdOnCommandEvent)(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort);

class DELPHICLASS TIdEventSocksServer;
class PASCALIMPLEMENTATION TIdEventSocksServer : public TIdCustomSocksServer
{
	typedef TIdCustomSocksServer inherited;
	
protected:
	TIdOnCommandEvent FOnCommandConnect;
	TIdOnCommandEvent FOnCommandBind;
	virtual void __fastcall CommandConnect(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort);
	virtual void __fastcall CommandBind(TIdSocksServerContext* AContext, const System::UnicodeString AHost, const System::Word APort);
	
__published:
	__property TIdOnCommandEvent OnCommandConnect = {read=FOnCommandConnect, write=FOnCommandConnect};
	__property TIdOnCommandEvent OnCommandBind = {read=FOnCommandBind, write=FOnCommandBind};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdEventSocksServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEventSocksServer(Classes::TComponent* AOwner)/* overload */ : TIdCustomSocksServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt IdSocksAuthNoAuthenticationRequired = 0x0;
static const ShortInt IdSocksAuthGSSApi = 0x1;
static const ShortInt IdSocksAuthUsernamePassword = 0x2;
static const Byte IdSocksAuthNoAcceptableMethods = 0xff;
static const ShortInt IdSocks5ReplySuccess = 0x0;
static const ShortInt IdSocks5ReplyGeneralFailure = 0x1;
static const ShortInt IdSocks5ReplyConnNotAllowed = 0x2;
static const ShortInt IdSocks5ReplyNetworkUnreachable = 0x3;
static const ShortInt IdSocks5ReplyHostUnreachable = 0x4;
static const ShortInt IdSocks5ReplyConnRefused = 0x5;
static const ShortInt IdSocks5ReplyTTLExpired = 0x6;
static const ShortInt IdSocks5ReplyCmdNotSupported = 0x7;
static const ShortInt IdSocks5ReplyAddrNotSupported = 0x8;

}	/* namespace Idsocksserver */
using namespace Idsocksserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsocksserverHPP
