// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idotpcalculator.pas' rev: 20.00

#ifndef IdotpcalculatorHPP
#define IdotpcalculatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idotpcalculator
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdOTPCalculator;
class PASCALIMPLEMENTATION TIdOTPCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod __int64 __fastcall GenerateKeyMD4(const System::UnicodeString ASeed, const System::UnicodeString APassword, const int ACount);
	__classmethod __int64 __fastcall GenerateKeyMD5(const System::UnicodeString ASeed, const System::UnicodeString APassword, const int ACount);
	__classmethod __int64 __fastcall GenerateKeySHA1(const System::UnicodeString ASeed, const System::UnicodeString APassword, const int ACount);
	__classmethod bool __fastcall GenerateSixWordKey(const System::UnicodeString AStr, const System::UnicodeString APassword, System::UnicodeString &VKey)/* overload */;
	__classmethod System::UnicodeString __fastcall GenerateSixWordKey(const System::UnicodeString AMethod, const System::UnicodeString ASeed, const System::UnicodeString APassword, const int ACount)/* overload */;
	__classmethod bool __fastcall IsValidOTPString(const System::UnicodeString AStr);
	__classmethod System::UnicodeString __fastcall ToHex(const __int64 AKey);
	__classmethod System::UnicodeString __fastcall ToSixWordFormat(const __int64 AKey);
public:
	/* TObject.Create */ inline __fastcall TIdOTPCalculator(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdOTPCalculator(void) { }
	
};


class DELPHICLASS EIdOTPError;
class PASCALIMPLEMENTATION EIdOTPError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOTPError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOTPError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOTPError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOTPError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOTPError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOTPError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOTPError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOTPError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOTPError(void) { }
	
};


class DELPHICLASS EIdOTPUnknownMethod;
class PASCALIMPLEMENTATION EIdOTPUnknownMethod : public EIdOTPError
{
	typedef EIdOTPError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOTPUnknownMethod(const System::UnicodeString AMsg)/* overload */ : EIdOTPError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOTPUnknownMethod(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdOTPError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOTPUnknownMethod(int Ident)/* overload */ : EIdOTPError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOTPUnknownMethod(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdOTPError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOTPUnknownMethod(const System::UnicodeString Msg, int AHelpContext) : EIdOTPError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOTPUnknownMethod(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdOTPError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOTPUnknownMethod(int Ident, int AHelpContext)/* overload */ : EIdOTPError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOTPUnknownMethod(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdOTPError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOTPUnknownMethod(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idotpcalculator */
using namespace Idotpcalculator;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdotpcalculatorHPP
