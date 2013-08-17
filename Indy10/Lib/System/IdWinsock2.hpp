// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idwinsock2.pas' rev: 20.00

#ifndef Idwinsock2HPP
#define Idwinsock2HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <winsock2.h>
#include <ws2tcpip.h>
#include <wsipx.h>
#include <wsnwlink.h>
#include <wsnetbs.h>
#include <ws2atm.h>
#include <mswsock.h>

namespace Idwinsock2
{
    typedef fd_set *PFDSet;
    typedef fd_set TFDSet;
}


namespace Idwinsock2
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdWinsockStubError;
#pragma pack(push,1)
class PASCALIMPLEMENTATION EIdWinsockStubError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
protected:
	unsigned FWin32Error;
	System::UnicodeString FWin32ErrorMessage;
	System::UnicodeString FTitle;
	
public:
	__fastcall EIdWinsockStubError(unsigned AWin32Error, const System::UnicodeString ATitle, System::TVarRec *AArgs, const int AArgs_Size);
	__property unsigned Win32Error = {read=FWin32Error, nodefault};
	__property System::UnicodeString Win32ErrorMessage = {read=FWin32ErrorMessage};
	__property System::UnicodeString Title = {read=FTitle};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdWinsockStubError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdWinsockStubError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdWinsockStubError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdWinsockStubError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdWinsockStubError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdWinsockStubError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdWinsockStubError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdWinsockStubError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdWinsockStubError(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct WSACOMPLETION_EVENT
{
	
public:
	_OVERLAPPED *lpOverlapped;
};
#pragma pack(pop)


typedef int __stdcall (*LPFN_WSAENUMNAMESPACEPROVIDERSA)(unsigned &lpdwBufferLength, const PWSANAMESPACE_INFOA lpnspBuffer);

//-- var, const, procedure ---------------------------------------------------
#define WINSOCK2_DLL L"WS2_32.DLL"
#define MSWSOCK_DLL L"MSWSOCK.DLL"
extern PACKAGE unsigned __fastcall WinsockHandle(void);
extern PACKAGE bool __fastcall Winsock2Loaded(void);

}	/* namespace Idwinsock2 */
using namespace Idwinsock2;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idwinsock2HPP
