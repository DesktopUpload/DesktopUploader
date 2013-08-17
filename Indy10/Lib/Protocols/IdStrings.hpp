// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idstrings.pas' rev: 20.00

#ifndef IdstringsHPP
#define IdstringsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstrings
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall StrHtmlEncode(const System::UnicodeString AStr);
extern PACKAGE System::UnicodeString __fastcall StrHtmlDecode(const System::UnicodeString AStr);
extern PACKAGE System::UnicodeString __fastcall StrXHtmlEncode(const System::UnicodeString ASource);
extern PACKAGE System::UnicodeString __fastcall StrXHtmlDecode(const System::UnicodeString ASource);
extern PACKAGE System::UnicodeString __fastcall BinToHexStr(System::Byte AData);
extern PACKAGE bool __fastcall IsWhiteString(const System::UnicodeString AStr);
extern PACKAGE void __fastcall SplitString(const System::UnicodeString AStr, const System::UnicodeString AToken, System::UnicodeString &VLeft, System::UnicodeString &VRight);
extern PACKAGE System::UnicodeString __fastcall CommaAdd(const System::UnicodeString AStr1, const System::UnicodeString AStr2);

}	/* namespace Idstrings */
using namespace Idstrings;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdstringsHPP
