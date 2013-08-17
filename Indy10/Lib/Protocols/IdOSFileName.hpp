// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idosfilename.pas' rev: 20.00

#ifndef IdosfilenameHPP
#define IdosfilenameHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idftpcommon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idosfilename
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToVMS(const System::UnicodeString AUnixFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameVMSToUnix(const System::UnicodeString AVMSFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameMSDOSToUnix(const System::UnicodeString AMSDOSFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToMSDOS(const System::UnicodeString AUnixFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToWin32(const System::UnicodeString AUnixFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameWin32ToUnix(const System::UnicodeString AWin32FileName);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToVMCMS(const System::UnicodeString AUnixFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameVMCMSToUnix(const System::UnicodeString AVMCMSFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToMUSICSP(const System::UnicodeString AUnixFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameMUSICSPToUnix(const System::UnicodeString AMUSICSPFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToMVS(const System::UnicodeString AUnixFileName, const System::UnicodeString AUserID, const bool AUseAnotherID = false);
extern PACKAGE System::UnicodeString __fastcall FileNameMVSToUnix(const System::UnicodeString AMVSFileName);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToMPEiXTraditional(const System::UnicodeString AUnixFileName, const System::UnicodeString AGroupName = L"", const System::UnicodeString AAcountName = L"");
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToMPEiXHFS(const System::UnicodeString AUnixFileName, const bool IsRoot = false);
extern PACKAGE System::UnicodeString __fastcall FileNameUnixToOS9(const System::UnicodeString AUnixFileName);

}	/* namespace Idosfilename */
using namespace Idosfilename;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdosfilenameHPP
