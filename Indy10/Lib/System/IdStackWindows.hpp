// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idstackwindows.pas' rev: 20.00

#ifndef IdstackwindowsHPP
#define IdstackwindowsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idstackbsdbase.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idwinsock2.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstackwindows
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdIPv6Unavailable;
class PASCALIMPLEMENTATION EIdIPv6Unavailable : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIPv6Unavailable(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIPv6Unavailable(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIPv6Unavailable(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIPv6Unavailable(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIPv6Unavailable(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIPv6Unavailable(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIPv6Unavailable(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIPv6Unavailable(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIPv6Unavailable(void) { }
	
};


class DELPHICLASS TIdSocketListWindows;
class PASCALIMPLEMENTATION TIdSocketListWindows : public Idstack::TIdSocketList
{
	typedef Idstack::TIdSocketList inherited;
	
protected:
	#pragma pack(push,1)
	Idwinsock2::TFDSet FFDSet;
	#pragma pack(pop)
	__classmethod bool __fastcall FDSelect(Idwinsock2::PFDSet AReadSet, Idwinsock2::PFDSet AWriteSet, Idwinsock2::PFDSet AExceptSet, const int ATimeout = 0xfffffffe);
	virtual unsigned __fastcall GetItem(int AIndex);
	
public:
	virtual void __fastcall Add(unsigned AHandle);
	virtual void __fastcall Remove(unsigned AHandle);
	virtual int __fastcall Count(void);
	virtual void __fastcall Clear(void);
	virtual Idstack::TIdSocketList* __fastcall Clone(void);
	virtual bool __fastcall ContainsSocket(unsigned AHandle);
	void __fastcall GetFDSet(Idwinsock2::TFDSet &VSet);
	void __fastcall SetFDSet(Idwinsock2::TFDSet &VSet);
	__classmethod virtual bool __fastcall Select(Idstack::TIdSocketList* AReadList, Idstack::TIdSocketList* AWriteList, Idstack::TIdSocketList* AExceptList, const int ATimeout = 0xfffffffe);
	virtual bool __fastcall SelectRead(const int ATimeout = 0xfffffffe);
	virtual bool __fastcall SelectReadList(Idstack::TIdSocketList* &VSocketList, const int ATimeout = 0xfffffffe);
public:
	/* TIdSocketList.Create */ inline __fastcall virtual TIdSocketListWindows(void) : Idstack::TIdSocketList() { }
	/* TIdSocketList.Destroy */ inline __fastcall virtual ~TIdSocketListWindows(void) { }
	
};


class DELPHICLASS TIdStackWindows;
class PASCALIMPLEMENTATION TIdStackWindows : public Idstackbsdbase::TIdStackBSDBase
{
	typedef Idstackbsdbase::TIdStackBSDBase inherited;
	
protected:
	void __fastcall WSQuerryIPv6Route(unsigned ASocket, const System::UnicodeString AIP, const System::Word APort, void *VSource, void *VDest);
	void __fastcall WriteChecksumIPv6(unsigned s, Sysutils::TBytes &VBuffer, const int AOffset, const System::UnicodeString AIP, const System::Word APort);
	virtual System::UnicodeString __fastcall HostByName(const System::UnicodeString AHostName, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual System::UnicodeString __fastcall ReadHostName();
	virtual int __fastcall WSCloseSocket(unsigned ASocket);
	virtual int __fastcall WSRecv(unsigned ASocket, void *ABuffer, const int ABufferLength, const int AFlags);
	virtual int __fastcall WSSend(unsigned ASocket, const void *ABuffer, const int ABufferLength, const int AFlags);
	virtual int __fastcall WSShutdown(unsigned ASocket, int AHow);
	
public:
	virtual unsigned __fastcall Accept(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion &VIPVersion)/* overload */;
	virtual System::Word __fastcall HostToNetwork(System::Word AValue)/* overload */;
	virtual unsigned __fastcall HostToNetwork(unsigned AValue)/* overload */;
	virtual __int64 __fastcall HostToNetwork(__int64 AValue)/* overload */;
	virtual void __fastcall Listen(unsigned ASocket, int ABackLog);
	virtual System::Word __fastcall NetworkToHost(System::Word AValue)/* overload */;
	virtual unsigned __fastcall NetworkToHost(unsigned AValue)/* overload */;
	virtual __int64 __fastcall NetworkToHost(__int64 AValue)/* overload */;
	virtual void __fastcall SetBlocking(unsigned ASocket, const bool ABlocking);
	virtual bool __fastcall WouldBlock(const int AResult);
	virtual System::UnicodeString __fastcall HostByAddress(const System::UnicodeString AAddress, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual System::Word __fastcall WSGetServByName(const System::UnicodeString AServiceName);
	virtual Classes::TStrings* __fastcall WSGetServByPort(const System::Word APortNumber);
	virtual int __fastcall RecvFrom(const unsigned ASocket, void *VBuffer, const int ALength, const int AFlags, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual unsigned __fastcall ReceiveMsg(unsigned ASocket, Sysutils::TBytes &VBuffer, Idstack::TIdPacketInfo* APkt, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall WSSendTo(unsigned ASocket, const void *ABuffer, const int ABufferLength, const int AFlags, const System::UnicodeString AIP, const System::Word APort, Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual unsigned __fastcall WSSocket(int AFamily, int AStruct, int AProtocol, const bool AOverlapped = false);
	virtual System::UnicodeString __fastcall WSTranslateSocketErrorMsg(const int AErr);
	virtual int __fastcall WSGetLastError(void);
	virtual void __fastcall WSSetLastError(const int AErr);
	virtual void __fastcall WSGetSockOpt(unsigned ASocket, int Alevel, int AOptname, char * AOptval, int &AOptlen);
	virtual void __fastcall Bind(unsigned ASocket, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall Connect(const unsigned ASocket, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	__fastcall virtual TIdStackWindows(void);
	__fastcall virtual ~TIdStackWindows(void);
	virtual void __fastcall Disconnect(unsigned ASocket);
	virtual void __fastcall GetPeerName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion &VIPVersion)/* overload */;
	virtual void __fastcall GetSocketName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion &VIPVersion)/* overload */;
	virtual void __fastcall GetSocketOption(unsigned ASocket, int ALevel, int AOptName, /* out */ int &AOptVal);
	virtual void __fastcall SetSocketOption(unsigned ASocket, int ALevel, int AOptName, int AOptVal)/* overload */;
	virtual void __fastcall SetSocketOption(const unsigned ASocket, const int Alevel, const int Aoptname, char * Aoptval, const int Aoptlen)/* overload */;
	virtual int __fastcall IOControl(const unsigned s, const unsigned cmd, unsigned &arg);
	virtual bool __fastcall SupportsIPv6(void);
	virtual bool __fastcall CheckIPVersionSupport(const Idglobal::TIdIPVersion AIPVersion);
	virtual void __fastcall WriteChecksum(unsigned s, Sysutils::TBytes &VBuffer, const int AOffset, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall AddLocalAddressesToList(Classes::TStrings* AAddresses);
	
/* Hoisted overloads: */
	
public:
	inline unsigned __fastcall  Accept(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort){ return Idstack::TIdStack::Accept(ASocket, VIP, VPort); }
	inline Idglobal::TIdIPv6Address __fastcall  HostToNetwork(System::Word const *AValue){ return Idstack::TIdStack::HostToNetwork(AValue); }
	inline Idglobal::TIdIPv6Address __fastcall  NetworkToHost(System::Word const *AValue){ return Idstack::TIdStack::NetworkToHost(AValue); }
	inline void __fastcall  GetPeerName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort){ Idstack::TIdStack::GetPeerName(ASocket, VIP, VPort); }
	inline void __fastcall  GetSocketName(unsigned ASocket, System::UnicodeString &VIP, System::Word &VPort){ Idstack::TIdStack::GetSocketName(ASocket, VIP, VPort); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIdStackWindows* GWindowsStack;

}	/* namespace Idstackwindows */
using namespace Idstackwindows;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdstackwindowsHPP
