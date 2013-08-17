// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcustomtransparentproxy.pas' rev: 20.00

#ifndef IdcustomtransparentproxyHPP
#define IdcustomtransparentproxyHPP

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
#include <Idiohandler.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcustomtransparentproxy
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdTransparentProxyCircularLink;
class PASCALIMPLEMENTATION EIdTransparentProxyCircularLink : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTransparentProxyCircularLink(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTransparentProxyCircularLink(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTransparentProxyCircularLink(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTransparentProxyCircularLink(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTransparentProxyCircularLink(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTransparentProxyCircularLink(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTransparentProxyCircularLink(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTransparentProxyCircularLink(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTransparentProxyCircularLink(void) { }
	
};


class DELPHICLASS EIdTransparentProxyUDPNotSupported;
class PASCALIMPLEMENTATION EIdTransparentProxyUDPNotSupported : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTransparentProxyUDPNotSupported(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTransparentProxyUDPNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTransparentProxyUDPNotSupported(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTransparentProxyUDPNotSupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTransparentProxyUDPNotSupported(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTransparentProxyUDPNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTransparentProxyUDPNotSupported(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTransparentProxyUDPNotSupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTransparentProxyUDPNotSupported(void) { }
	
};


typedef TMetaClass* TIdCustomTransparentProxyClass;

class DELPHICLASS TIdCustomTransparentProxy;
class PASCALIMPLEMENTATION TIdCustomTransparentProxy : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	System::UnicodeString FHost;
	System::UnicodeString FPassword;
	System::Word FPort;
	Idglobal::TIdIPVersion FIPVersion;
	System::UnicodeString FUsername;
	TIdCustomTransparentProxy* FChainedProxy;
	virtual bool __fastcall GetEnabled(void) = 0 ;
	virtual void __fastcall SetEnabled(bool AValue);
	virtual void __fastcall MakeConnection(Idiohandler::TIdIOHandler* AIOHandler, const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetChainedProxy(const TIdCustomTransparentProxy* AValue);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* ASource);
	virtual void __fastcall OpenUDP(Idsockethandle::TIdSocketHandle* AHandle, const System::UnicodeString AHost = L"", const System::Word APort = (System::Word)(0x0), const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall CloseUDP(Idsockethandle::TIdSocketHandle* AHandle);
	virtual int __fastcall RecvFromUDP(Idsockethandle::TIdSocketHandle* AHandle, Sysutils::TBytes &ABuffer, System::UnicodeString &VPeerIP, System::Word &VPeerPort, const Idglobal::TIdIPVersion AIPVersion, int AMSec = 0xffffffff);
	virtual void __fastcall SendToUDP(Idsockethandle::TIdSocketHandle* AHandle, const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion, const Sysutils::TBytes ABuffer);
	void __fastcall Connect(Idiohandler::TIdIOHandler* AIOHandler, const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall Bind(Idiohandler::TIdIOHandler* AIOHandler, const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0))/* overload */;
	void __fastcall Bind(Idiohandler::TIdIOHandler* AIOHandler, const System::Word APort)/* overload */;
	virtual bool __fastcall Listen(Idiohandler::TIdIOHandler* AIOHandler, const int ATimeOut);
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property System::UnicodeString Host = {read=FHost, write=FHost};
	__property System::UnicodeString Password = {read=FPassword, write=FPassword};
	__property System::Word Port = {read=FPort, write=FPort, nodefault};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=FIPVersion, default=0};
	__property System::UnicodeString Username = {read=FUsername, write=FUsername};
	__property TIdCustomTransparentProxy* ChainedProxy = {read=FChainedProxy, write=SetChainedProxy};
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdCustomTransparentProxy(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomTransparentProxy(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcustomtransparentproxy */
using namespace Idcustomtransparentproxy;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcustomtransparentproxyHPP
