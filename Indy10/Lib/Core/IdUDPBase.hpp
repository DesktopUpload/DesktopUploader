// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idudpbase.pas' rev: 20.00

#ifndef IdudpbaseHPP
#define IdudpbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idudpbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUDPBase;
class PASCALIMPLEMENTATION TIdUDPBase : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	int FBufferSize;
	bool FDsgnActive;
	System::UnicodeString FHost;
	System::Word FPort;
	int FReceiveTimeout;
	Idglobal::TIdIPVersion FIPVersion;
	bool FBroadcastEnabled;
	DYNAMIC void __fastcall BroadcastEnabledChanged(void);
	virtual void __fastcall CloseBinding(void);
	virtual bool __fastcall GetActive(void);
	virtual void __fastcall InitComponent(void);
	void __fastcall SetActive(const bool Value);
	void __fastcall SetBroadcastEnabled(const bool AValue);
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void) = 0 ;
	virtual void __fastcall Loaded(void);
	virtual Idglobal::TIdIPVersion __fastcall GetIPVersion(void);
	virtual void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	virtual System::UnicodeString __fastcall GetHost();
	virtual void __fastcall SetHost(const System::UnicodeString AValue);
	virtual System::Word __fastcall GetPort(void);
	virtual void __fastcall SetPort(const System::Word AValue);
	__property System::UnicodeString Host = {read=GetHost, write=SetHost};
	__property System::Word Port = {read=GetPort, write=SetPort, nodefault};
	
public:
	__fastcall virtual ~TIdUDPBase(void);
	__property Idsockethandle::TIdSocketHandle* Binding = {read=GetBinding};
	void __fastcall Broadcast(const System::UnicodeString AData, const System::Word APort, const System::UnicodeString AIP = L"")/* overload */;
	void __fastcall Broadcast(const Sysutils::TBytes AData, const System::Word APort, const System::UnicodeString AIP = L"")/* overload */;
	virtual int __fastcall ReceiveBuffer(Sysutils::TBytes &ABuffer, System::UnicodeString &VPeerIP, System::Word &VPeerPort, int AMSec = 0xffffffff)/* overload */;
	virtual int __fastcall ReceiveBuffer(Sysutils::TBytes &ABuffer, System::UnicodeString &VPeerIP, System::Word &VPeerPort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0), const int AMSec = 0xffffffff)/* overload */;
	virtual int __fastcall ReceiveBuffer(Sysutils::TBytes &ABuffer, const int AMSec = 0xffffffff)/* overload */;
	System::UnicodeString __fastcall ReceiveString(const int AMSec = 0xffffffff)/* overload */;
	System::UnicodeString __fastcall ReceiveString(System::UnicodeString &VPeerIP, System::Word &VPeerPort, const int AMSec = 0xffffffff)/* overload */;
	void __fastcall Send(const System::UnicodeString AHost, const System::Word APort, const System::UnicodeString AData);
	virtual void __fastcall SendBuffer(const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion, const Sysutils::TBytes ABuffer)/* overload */;
	virtual void __fastcall SendBuffer(const System::UnicodeString AHost, const System::Word APort, const Sysutils::TBytes ABuffer)/* overload */;
	__property int ReceiveTimeout = {read=FReceiveTimeout, write=FReceiveTimeout, default=-2};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property int BufferSize = {read=FBufferSize, write=FBufferSize, default=8192};
	__property bool BroadcastEnabled = {read=FBroadcastEnabled, write=SetBroadcastEnabled, default=0};
	__property Idglobal::TIdIPVersion IPVersion = {read=GetIPVersion, write=SetIPVersion, default=0};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUDPBase(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


class DELPHICLASS EIdUDPException;
class PASCALIMPLEMENTATION EIdUDPException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdUDPException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdUDPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdUDPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdUDPException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdUDPException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdUDPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdUDPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdUDPException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdUDPException(void) { }
	
};


class DELPHICLASS EIdUDPReceiveErrorZeroBytes;
class PASCALIMPLEMENTATION EIdUDPReceiveErrorZeroBytes : public EIdUDPException
{
	typedef EIdUDPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdUDPReceiveErrorZeroBytes(const System::UnicodeString AMsg)/* overload */ : EIdUDPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdUDPReceiveErrorZeroBytes(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdUDPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdUDPReceiveErrorZeroBytes(int Ident)/* overload */ : EIdUDPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdUDPReceiveErrorZeroBytes(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdUDPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdUDPReceiveErrorZeroBytes(const System::UnicodeString Msg, int AHelpContext) : EIdUDPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdUDPReceiveErrorZeroBytes(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdUDPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdUDPReceiveErrorZeroBytes(int Ident, int AHelpContext)/* overload */ : EIdUDPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdUDPReceiveErrorZeroBytes(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdUDPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdUDPReceiveErrorZeroBytes(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word ID_UDP_BUFFERSIZE = 0x2000;

}	/* namespace Idudpbase */
using namespace Idudpbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdudpbaseHPP
