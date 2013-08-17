// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idstack.pas' rev: 20.00

#ifndef IdstackHPP
#define IdstackHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstack
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdSocketError;
class PASCALIMPLEMENTATION EIdSocketError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
protected:
	int FLastError;
	
public:
	__fastcall virtual EIdSocketError(const int AErr, const System::UnicodeString AMsg);
	__property int LastError = {read=FLastError, nodefault};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocketError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocketError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocketError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocketError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocketError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocketError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocketError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocketError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocketError(void) { }
	
};


class DELPHICLASS EIdStackError;
class PASCALIMPLEMENTATION EIdStackError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdStackError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdStackError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdStackError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdStackError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdStackError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdStackError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdStackError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdStackError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdStackError(void) { }
	
};


class DELPHICLASS EIdIPVersionUnsupported;
class PASCALIMPLEMENTATION EIdIPVersionUnsupported : public EIdStackError
{
	typedef EIdStackError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIPVersionUnsupported(const System::UnicodeString AMsg)/* overload */ : EIdStackError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIPVersionUnsupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdStackError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIPVersionUnsupported(int Ident)/* overload */ : EIdStackError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIPVersionUnsupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdStackError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIPVersionUnsupported(const System::UnicodeString Msg, int AHelpContext) : EIdStackError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIPVersionUnsupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdStackError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIPVersionUnsupported(int Ident, int AHelpContext)/* overload */ : EIdStackError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIPVersionUnsupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdStackError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIPVersionUnsupported(void) { }
	
};


class DELPHICLASS EIdNotASocket;
class PASCALIMPLEMENTATION EIdNotASocket : public EIdSocketError
{
	typedef EIdSocketError inherited;
	
public:
	/* EIdSocketError.CreateError */ inline __fastcall virtual EIdNotASocket(const int AErr, const System::UnicodeString AMsg) : EIdSocketError(AErr, AMsg) { }
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNotASocket(const System::UnicodeString AMsg)/* overload */ : EIdSocketError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNotASocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNotASocket(int Ident)/* overload */ : EIdSocketError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNotASocket(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNotASocket(const System::UnicodeString Msg, int AHelpContext) : EIdSocketError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNotASocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNotASocket(int Ident, int AHelpContext)/* overload */ : EIdSocketError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNotASocket(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNotASocket(void) { }
	
};


typedef __int64 __fastcall (*TIdServeFile)(unsigned ASocket, const System::UnicodeString AFileName);

class DELPHICLASS TIdPacketInfo;
class PASCALIMPLEMENTATION TIdPacketInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::UnicodeString FSourceIP;
	System::Word FSourcePort;
	System::UnicodeString FDestIP;
	System::Word FDestPort;
	unsigned FSourceIF;
	unsigned FDestIF;
	System::Byte FTTL;
	
public:
	__property System::Byte TTL = {read=FTTL, write=FTTL, nodefault};
	__property System::UnicodeString SourceIP = {read=FSourceIP, write=FSourceIP};
	__property System::Word SourcePort = {read=FSourcePort, write=FSourcePort, nodefault};
	__property unsigned SourceIF = {read=FSourceIF, write=FSourceIF, nodefault};
	__property System::UnicodeString DestIP = {read=FDestIP, write=FDestIP};
	__property System::Word DestPort = {read=FDestPort, write=FDestPort, nodefault};
	__property unsigned DestIF = {read=FDestIF, write=FDestIF, nodefault};
public:
	/* TObject.Create */ inline __fastcall TIdPacketInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdPacketInfo(void) { }
	
};


typedef TMetaClass* TIdSocketListClass;

class DELPHICLASS TIdSocketList;
class PASCALIMPLEMENTATION TIdSocketList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	unsigned operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	Idglobal::TIdCriticalSection* FLock;
	virtual unsigned __fastcall GetItem(int AIndex) = 0 ;
	
public:
	__fastcall virtual TIdSocketList(void);
	__fastcall virtual ~TIdSocketList(void);
	virtual void __fastcall Add(unsigned AHandle) = 0 ;
	virtual TIdSocketList* __fastcall Clone(void) = 0 ;
	virtual int __fastcall Count(void) = 0 ;
	__classmethod TIdSocketList* __fastcall CreateSocketList();
	__property unsigned Items[int AIndex] = {read=GetItem/*, default*/};
	virtual void __fastcall Remove(unsigned AHandle) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsSocket(unsigned AHandle) = 0 ;
	void __fastcall Lock(void);
	__classmethod virtual bool __fastcall Select(TIdSocketList* AReadList, TIdSocketList* AWriteList, TIdSocketList* AExceptList, const int ATimeout = 0xfffffffe);
	virtual bool __fastcall SelectRead(const int ATimeout = 0xfffffffe) = 0 ;
	virtual bool __fastcall SelectReadList(TIdSocketList* &VSocketList, const int ATimeout = 0xfffffffe) = 0 ;
	void __fastcall Unlock(void);
};


class DELPHICLASS TIdStack;
class PASCALIMPLEMENTATION TIdStack : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* FLocalAddresses;
	void __fastcall IPVersionUnsupported(void);
	virtual System::UnicodeString __fastcall HostByName(const System::UnicodeString AHostName, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	System::UnicodeString __fastcall MakeCanonicalIPv6Address(const System::UnicodeString AAddr);
	virtual System::UnicodeString __fastcall ReadHostName(void) = 0 ;
	System::UnicodeString __fastcall GetLocalAddress();
	Classes::TStrings* __fastcall GetLocalAddresses(void);
	
public:
	unsigned __fastcall Accept(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort)/* overload */;
	virtual unsigned __fastcall Accept(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion &VIPVersion) = 0 /* overload */;
	virtual void __fastcall Bind(unsigned ASocket, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall Connect(const unsigned ASocket, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	__fastcall virtual TIdStack(void);
	__fastcall virtual ~TIdStack(void);
	virtual void __fastcall Disconnect(unsigned ASocket) = 0 ;
	virtual int __fastcall IOControl(const unsigned s, const unsigned cmd, unsigned &arg) = 0 ;
	__classmethod void __fastcall IncUsage();
	__classmethod void __fastcall DecUsage();
	void __fastcall GetPeerName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort)/* overload */;
	virtual void __fastcall GetPeerName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion &VIPVersion) = 0 /* overload */;
	void __fastcall GetSocketName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort)/* overload */;
	virtual void __fastcall GetSocketName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion &VIPVersion) = 0 /* overload */;
	virtual System::UnicodeString __fastcall HostByAddress(const System::UnicodeString AAddress, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual System::Word __fastcall HostToNetwork(System::Word AValue) = 0 /* overload */;
	virtual unsigned __fastcall HostToNetwork(unsigned AValue) = 0 /* overload */;
	virtual __int64 __fastcall HostToNetwork(__int64 AValue) = 0 /* overload */;
	virtual Idglobal::TIdIPv6Address __fastcall HostToNetwork(System::Word const *AValue)/* overload */;
	bool __fastcall IsIP(System::UnicodeString AIP);
	virtual void __fastcall Listen(unsigned ASocket, int ABackLog) = 0 ;
	virtual int __fastcall WSGetLastError(void) = 0 ;
	virtual void __fastcall WSSetLastError(const int AErr) = 0 ;
	virtual System::UnicodeString __fastcall WSTranslateSocketErrorMsg(const int AErr);
	int __fastcall CheckForSocketError(const int AResult)/* overload */;
	int __fastcall CheckForSocketError(const int AResult, int const *AIgnore, const int AIgnore_Size)/* overload */;
	void __fastcall RaiseLastSocketError(void);
	virtual void __fastcall RaiseSocketError(int AErr);
	virtual unsigned __fastcall NewSocketHandle(const unsigned ASocketType, const int AProtocol, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0), const bool AOverlapped = false) = 0 ;
	virtual System::Word __fastcall NetworkToHost(System::Word AValue) = 0 /* overload */;
	virtual unsigned __fastcall NetworkToHost(unsigned AValue) = 0 /* overload */;
	virtual __int64 __fastcall NetworkToHost(__int64 AValue) = 0 /* overload */;
	virtual Idglobal::TIdIPv6Address __fastcall NetworkToHost(System::Word const *AValue)/* overload */;
	virtual void __fastcall GetSocketOption(unsigned ASocket, int ALevel, int AOptName, /* out */ int &AOptVal) = 0 ;
	virtual void __fastcall SetSocketOption(unsigned ASocket, int ALevel, int AOptName, int AOptVal) = 0 /* overload */;
	System::UnicodeString __fastcall ResolveHost(const System::UnicodeString AHost, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual int __fastcall Receive(unsigned ASocket, Sysutils::TBytes &VBuffer) = 0 ;
	virtual int __fastcall Send(unsigned ASocket, const Sysutils::TBytes ABuffer, const int AOffset = 0x0, const int ASize = 0xffffffff) = 0 ;
	virtual int __fastcall ReceiveFrom(unsigned ASocket, Sysutils::TBytes &VBuffer, System::UnicodeString &VIP, System::Word &VPort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	int __fastcall SendTo(unsigned ASocket, const Sysutils::TBytes ABuffer, const int AOffset, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0))/* overload */;
	virtual int __fastcall SendTo(unsigned ASocket, const Sysutils::TBytes ABuffer, const int AOffset, const int ASize, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 /* overload */;
	virtual unsigned __fastcall ReceiveMsg(unsigned ASocket, Sysutils::TBytes &VBuffer, TIdPacketInfo* APkt, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual bool __fastcall SupportsIPv6(void) = 0 ;
	bool __fastcall IsValidIPv4MulticastGroup(const System::UnicodeString Value);
	bool __fastcall IsValidIPv6MulticastGroup(const System::UnicodeString Value);
	virtual void __fastcall SetMulticastTTL(unsigned AHandle, const System::Byte AValue, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall SetLoopBack(unsigned AHandle, const bool AValue, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall DropMulticastMembership(unsigned AHandle, const System::UnicodeString AGroupIP, const System::UnicodeString ALocalIP, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall AddMulticastMembership(unsigned AHandle, const System::UnicodeString AGroupIP, const System::UnicodeString ALocalIP, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual System::Word __fastcall CalcCheckSum(const Sysutils::TBytes AData);
	virtual void __fastcall WriteChecksum(unsigned s, Sysutils::TBytes &VBuffer, const int AOffset, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall AddLocalAddressesToList(Classes::TStrings* AAddresses) = 0 ;
	__property System::UnicodeString HostName = {read=ReadHostName};
	__property System::UnicodeString LocalAddress = {read=GetLocalAddress};
	__property Classes::TStrings* LocalAddresses = {read=GetLocalAddresses};
};


typedef TMetaClass* TIdStackClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIdStack* GStack;
extern PACKAGE TIdServeFile GServeFileProc;
extern PACKAGE TIdSocketListClass GSocketListClass;
extern PACKAGE void __fastcall SetStackClass(TIdStackClass AStackClass);

}	/* namespace Idstack */
using namespace Idstack;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdstackHPP
