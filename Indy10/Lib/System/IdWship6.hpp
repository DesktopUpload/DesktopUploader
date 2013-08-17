// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idwship6.pas' rev: 20.00

#ifndef Idwship6HPP
#define Idwship6HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Idwinsock2.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idwship6
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define Wship6_dll L"Wship6.dll"
#define iphlpapi_dll L"iphlpapi.dll"
#define fwpuclnt_dll L"Fwpuclnt.dll"
extern PACKAGE bool GIdIPv6FuncsAvailable;
extern PACKAGE int __fastcall gaiErrorToWsaError(const int gaiError);
extern PACKAGE void __fastcall CloseLibrary(void);
extern PACKAGE void __fastcall InitLibrary(void);

}	/* namespace Idwship6 */
using namespace Idwship6;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idwship6HPP
