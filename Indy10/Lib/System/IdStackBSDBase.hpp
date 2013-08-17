// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idstackbsdbase.pas' rev: 20.00

#ifndef IdstackbsdbaseHPP
#define IdstackbsdbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstackbsdbase
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct TIdInt64Parts
{
	
	union
	{
		struct 
		{
			__int64 QuadPart;
			
		};
		struct 
		{
			unsigned LowPart;
			unsigned HighPart;
			
		};
		
	};
};
#pragma pack(pop)


typedef StaticArray<System::Word, 8> TIdIPv6AddressRec;

#pragma pack(push,1)
struct TIdIPAddressRec
{
	
public:
	Idglobal::TIdIPVersion IPVer;
	union
	{
		struct 
		{
			TIdIPv6AddressRec IPv6;
			
		};
		struct 
		{
			unsigned IPv4;
			unsigned Junk1;
			unsigned Junk2;
			unsigned Junk3;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct TIdSunB
{
	
public:
	System::Byte s_b1;
	System::Byte s_b2;
	System::Byte s_b3;
	System::Byte s_b4;
};
#pragma pack(pop)


#pragma pack(push,1)
struct TIdSunW
{
	
public:
	System::Word s_w1;
	System::Word s_w2;
};
#pragma pack(pop)


struct TIdIn4Addr;
typedef TIdIn4Addr *PIdIn4Addr;

#pragma pack(push,1)
struct TIdIn4Addr
{
	
	union
	{
		struct 
		{
			unsigned S_addr;
			
		};
		struct 
		{
			TIdSunW S_un_w;
			
		};
		struct 
		{
			TIdSunB S_un_b;
			
		};
		
	};
};
#pragma pack(pop)


struct TIdIn6Addr;
typedef TIdIn6Addr *PIdIn6Addr;

#pragma pack(push,1)
struct TIdIn6Addr
{
	
	union
	{
		struct 
		{
			StaticArray<unsigned, 4> s6_addr32;
			
		};
		struct 
		{
			StaticArray<System::Word, 8> s6_addr16;
			
		};
		struct 
		{
			StaticArray<System::Byte, 16> s6_addr;
			
		};
		
	};
};
#pragma pack(pop)


typedef TIdIn4Addr *PIdInAddr;

typedef TIdIn4Addr TIdInAddr;

#pragma pack(push,1)
struct TIdIPMreq
{
	
public:
	TIdIn4Addr IMRMultiAddr;
	TIdIn4Addr IMRInterface;
};
#pragma pack(pop)


#pragma pack(push,1)
struct TIdIPv6Mreq
{
	
public:
	TIdIn6Addr ipv6mr_multiaddr;
	unsigned ipv6mr_interface;
};
#pragma pack(pop)


class DELPHICLASS TIdStackBSDBase;
class PASCALIMPLEMENTATION TIdStackBSDBase : public Idstack::TIdStack
{
	typedef Idstack::TIdStack inherited;
	
protected:
	virtual int __fastcall WSCloseSocket(unsigned ASocket) = 0 ;
	virtual int __fastcall WSRecv(unsigned ASocket, void *ABuffer, const int ABufferLength, const int AFlags) = 0 ;
	virtual int __fastcall WSSend(unsigned ASocket, const void *ABuffer, const int ABufferLength, const int AFlags) = 0 ;
	virtual int __fastcall WSShutdown(unsigned ASocket, int AHow) = 0 ;
	void __fastcall MembershipSockOpt(unsigned AHandle, const System::UnicodeString AGroupIP, const System::UnicodeString ALocalIP, const int ASockOpt, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	
public:
	__fastcall virtual TIdStackBSDBase(void);
	virtual bool __fastcall CheckIPVersionSupport(const Idglobal::TIdIPVersion AIPVersion) = 0 ;
	virtual int __fastcall Receive(unsigned ASocket, Sysutils::TBytes &VBuffer);
	virtual int __fastcall Send(unsigned ASocket, const Sysutils::TBytes ABuffer, const int AOffset = 0x0, const int ASize = 0xffffffff);
	virtual int __fastcall ReceiveFrom(unsigned ASocket, Sysutils::TBytes &VBuffer, System::UnicodeString &VIP, System::Word &VPort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual int __fastcall SendTo(unsigned ASocket, const Sysutils::TBytes ABuffer, const int AOffset, const int ASize, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0))/* overload */;
	HIDESBASE virtual void __fastcall SetSocketOption(const unsigned ASocket, const int Alevel, const int Aoptname, char * Aoptval, const int Aoptlen) = 0 /* overload */;
	System::UnicodeString __fastcall TranslateTInAddrToString(void *AInAddr, const Idglobal::TIdIPVersion AIPVersion);
	void __fastcall TranslateStringToTInAddr(const System::UnicodeString AIP, void *AInAddr, const Idglobal::TIdIPVersion AIPVersion);
	virtual System::Word __fastcall WSGetServByName(const System::UnicodeString AServiceName) = 0 ;
	virtual Classes::TStrings* __fastcall WSGetServByPort(const System::Word APortNumber) = 0 ;
	virtual int __fastcall RecvFrom(const unsigned ASocket, void *ABuffer, const int ALength, const int AFlags, System::UnicodeString &VIP, System::Word &VPort, Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual void __fastcall WSSendTo(unsigned ASocket, const void *ABuffer, const int ABufferLength, const int AFlags, const System::UnicodeString AIP, const System::Word APort, Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)) = 0 ;
	virtual unsigned __fastcall WSSocket(int AFamily, int AStruct, int AProtocol, const bool AOverlapped = false) = 0 ;
	virtual void __fastcall WSGetSockOpt(unsigned ASocket, int Alevel, int AOptname, char * AOptval, int &AOptlen) = 0 ;
	virtual void __fastcall SetBlocking(unsigned ASocket, const bool ABlocking) = 0 ;
	virtual bool __fastcall WouldBlock(const int AResult) = 0 ;
	virtual unsigned __fastcall NewSocketHandle(const unsigned ASocketType, const int AProtocol, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0), const bool AOverlapped = false);
	virtual void __fastcall SetMulticastTTL(unsigned AHandle, const System::Byte AValue, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall SetLoopBack(unsigned AHandle, const bool AValue, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall DropMulticastMembership(unsigned AHandle, const System::UnicodeString AGroupIP, const System::UnicodeString ALocalIP, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall AddMulticastMembership(unsigned AHandle, const System::UnicodeString AGroupIP, const System::UnicodeString ALocalIP, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
public:
	/* TIdStack.Destroy */ inline __fastcall virtual ~TIdStackBSDBase(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  SendTo(unsigned ASocket, const Sysutils::TBytes ABuffer, const int AOffset, const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0)){ return Idstack::TIdStack::SendTo(ASocket, ABuffer, AOffset, AIP, APort, AIPVersion); }
	inline void __fastcall  SetSocketOption(unsigned ASocket, int ALevel, int AOptName, int AOptVal){ Idstack::TIdStack::SetSocketOption(ASocket, ALevel, AOptName, AOptVal); }
	
};


class DELPHICLASS EIdInvalidServiceName;
class PASCALIMPLEMENTATION EIdInvalidServiceName : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidServiceName(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidServiceName(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidServiceName(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidServiceName(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidServiceName(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidServiceName(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidServiceName(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidServiceName(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidServiceName(void) { }
	
};


class DELPHICLASS EIdStackInitializationFailed;
class PASCALIMPLEMENTATION EIdStackInitializationFailed : public Idstack::EIdStackError
{
	typedef Idstack::EIdStackError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdStackInitializationFailed(const System::UnicodeString AMsg)/* overload */ : Idstack::EIdStackError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdStackInitializationFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idstack::EIdStackError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdStackInitializationFailed(int Ident)/* overload */ : Idstack::EIdStackError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdStackInitializationFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idstack::EIdStackError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdStackInitializationFailed(const System::UnicodeString Msg, int AHelpContext) : Idstack::EIdStackError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdStackInitializationFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idstack::EIdStackError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdStackInitializationFailed(int Ident, int AHelpContext)/* overload */ : Idstack::EIdStackError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdStackInitializationFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idstack::EIdStackError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdStackInitializationFailed(void) { }
	
};


class DELPHICLASS EIdStackSetSizeExceeded;
class PASCALIMPLEMENTATION EIdStackSetSizeExceeded : public Idstack::EIdStackError
{
	typedef Idstack::EIdStackError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdStackSetSizeExceeded(const System::UnicodeString AMsg)/* overload */ : Idstack::EIdStackError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdStackSetSizeExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idstack::EIdStackError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdStackSetSizeExceeded(int Ident)/* overload */ : Idstack::EIdStackError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdStackSetSizeExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idstack::EIdStackError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdStackSetSizeExceeded(const System::UnicodeString Msg, int AHelpContext) : Idstack::EIdStackError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdStackSetSizeExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idstack::EIdStackError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdStackSetSizeExceeded(int Ident, int AHelpContext)/* overload */ : Idstack::EIdStackError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdStackSetSizeExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idstack::EIdStackError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdStackSetSizeExceeded(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIdStackBSDBase* GBSDStack;
extern PACKAGE StaticArray<int, 2> IdIPFamily;

}	/* namespace Idstackbsdbase */
using namespace Idstackbsdbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdstackbsdbaseHPP
