// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idudpclient.pas' rev: 20.00

#ifndef IdudpclientHPP
#define IdudpclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idcustomtransparentproxy.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idudpclient
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdMustUseOpenProxy;
class PASCALIMPLEMENTATION EIdMustUseOpenProxy : public Idudpbase::EIdUDPException
{
	typedef Idudpbase::EIdUDPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMustUseOpenProxy(const System::UnicodeString AMsg)/* overload */ : Idudpbase::EIdUDPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMustUseOpenProxy(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idudpbase::EIdUDPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMustUseOpenProxy(int Ident)/* overload */ : Idudpbase::EIdUDPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMustUseOpenProxy(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idudpbase::EIdUDPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMustUseOpenProxy(const System::UnicodeString Msg, int AHelpContext) : Idudpbase::EIdUDPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMustUseOpenProxy(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idudpbase::EIdUDPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMustUseOpenProxy(int Ident, int AHelpContext)/* overload */ : Idudpbase::EIdUDPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMustUseOpenProxy(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idudpbase::EIdUDPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMustUseOpenProxy(void) { }
	
};


class DELPHICLASS TIdUDPClient;
class PASCALIMPLEMENTATION TIdUDPClient : public Idudpbase::TIdUDPBase
{
	typedef Idudpbase::TIdUDPBase inherited;
	
protected:
	System::UnicodeString FBoundIP;
	System::Word FBoundPort;
	System::Word FBoundPortMin;
	System::Word FBoundPortMax;
	bool FProxyOpened;
	Classes::TNotifyEvent FOnConnected;
	Classes::TNotifyEvent FOnDisconnected;
	bool FConnected;
	Idcustomtransparentproxy::TIdCustomTransparentProxy* FTransparentProxy;
	bool __fastcall UseProxy(void);
	void __fastcall RaiseUseProxyError(void);
	virtual void __fastcall DoOnConnected(void);
	virtual void __fastcall DoOnDisconnected(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	virtual void __fastcall SetHost(const System::UnicodeString AValue);
	virtual void __fastcall SetPort(const System::Word AValue);
	void __fastcall SetTransparentProxy(Idcustomtransparentproxy::TIdCustomTransparentProxy* AProxy);
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	Idcustomtransparentproxy::TIdCustomTransparentProxy* __fastcall GetTransparentProxy(void);
	
public:
	__fastcall virtual ~TIdUDPClient(void);
	void __fastcall OpenProxy(void);
	void __fastcall CloseProxy(void);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	bool __fastcall Connected(void);
	virtual int __fastcall ReceiveBuffer(Sysutils::TBytes &ABuffer, const int AMSec = 0xffffffff)/* overload */;
	virtual int __fastcall ReceiveBuffer(Sysutils::TBytes &ABuffer, System::UnicodeString &VPeerIP, System::Word &VPeerPort, int AMSec = 0xffffffff)/* overload */;
	virtual int __fastcall ReceiveBuffer(Sysutils::TBytes &ABuffer, System::UnicodeString &VPeerIP, System::Word &VPeerPort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0), const int AMSec = 0xffffffff)/* overload */;
	HIDESBASE void __fastcall Send(const System::UnicodeString AData)/* overload */;
	virtual void __fastcall SendBuffer(const System::UnicodeString AHost, const System::Word APort, const Sysutils::TBytes ABuffer)/* overload */;
	HIDESBASE void __fastcall SendBuffer(const Sysutils::TBytes ABuffer)/* overload */;
	virtual void __fastcall SendBuffer(const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion, const Sysutils::TBytes ABuffer)/* overload */;
	
__published:
	__property System::UnicodeString BoundIP = {read=FBoundIP, write=FBoundIP};
	__property System::Word BoundPort = {read=FBoundPort, write=FBoundPort, default=0};
	__property System::Word BoundPortMin = {read=FBoundPortMin, write=FBoundPortMin, default=0};
	__property System::Word BoundPortMax = {read=FBoundPortMax, write=FBoundPortMax, default=0};
	__property IPVersion = {default=0};
	__property Host;
	__property Port;
	__property ReceiveTimeout = {default=-2};
	__property Idcustomtransparentproxy::TIdCustomTransparentProxy* TransparentProxy = {read=GetTransparentProxy, write=SetTransparentProxy};
	__property Classes::TNotifyEvent OnConnected = {read=FOnConnected, write=FOnConnected};
	__property Classes::TNotifyEvent OnDisconnected = {read=FOnDisconnected, write=FOnDisconnected};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUDPClient(Classes::TComponent* AOwner)/* overload */ : Idudpbase::TIdUDPBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idudpclient */
using namespace Idudpclient;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdudpclientHPP
