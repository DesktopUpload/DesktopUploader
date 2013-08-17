// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idexception.pas' rev: 20.00

#ifndef IdexceptionHPP
#define IdexceptionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idexception
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdException;
class PASCALIMPLEMENTATION EIdException : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	__fastcall virtual EIdException(const System::UnicodeString AMsg)/* overload */;
	__classmethod void __fastcall IfAssigned(const System::TObject* ACheck, const System::UnicodeString AMsg = L"");
	__classmethod void __fastcall IfFalse(const bool ACheck, const System::UnicodeString AMsg = L"");
	__classmethod void __fastcall IfNotAssigned(const System::TObject* ACheck, const System::UnicodeString AMsg = L"");
	__classmethod void __fastcall IfNotInRange(const int AValue, const int AMin, const int AMax, const System::UnicodeString AMsg = L"");
	__classmethod void __fastcall IfTrue(const bool ACheck, const System::UnicodeString AMsg = L"");
	__classmethod void __fastcall Toss(const System::UnicodeString AMsg);
public:
	/* Exception.CreateFmt */ inline __fastcall EIdException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdException(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdException(void) { }
	
};


typedef TMetaClass* TClassIdException;

class DELPHICLASS EIdSilentException;
class PASCALIMPLEMENTATION EIdSilentException : public EIdException
{
	typedef EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSilentException(const System::UnicodeString AMsg)/* overload */ : EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSilentException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSilentException(int Ident)/* overload */ : EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSilentException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSilentException(const System::UnicodeString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSilentException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSilentException(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSilentException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSilentException(void) { }
	
};


class DELPHICLASS EIdConnClosedGracefully;
class PASCALIMPLEMENTATION EIdConnClosedGracefully : public EIdSilentException
{
	typedef EIdSilentException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdConnClosedGracefully(const System::UnicodeString AMsg)/* overload */ : EIdSilentException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdConnClosedGracefully(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSilentException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdConnClosedGracefully(int Ident)/* overload */ : EIdSilentException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdConnClosedGracefully(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSilentException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdConnClosedGracefully(const System::UnicodeString Msg, int AHelpContext) : EIdSilentException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdConnClosedGracefully(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSilentException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdConnClosedGracefully(int Ident, int AHelpContext)/* overload */ : EIdSilentException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdConnClosedGracefully(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSilentException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdConnClosedGracefully(void) { }
	
};


class DELPHICLASS EIdSocketHandleError;
class PASCALIMPLEMENTATION EIdSocketHandleError : public EIdException
{
	typedef EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocketHandleError(const System::UnicodeString AMsg)/* overload */ : EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocketHandleError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocketHandleError(int Ident)/* overload */ : EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocketHandleError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocketHandleError(const System::UnicodeString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocketHandleError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocketHandleError(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocketHandleError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocketHandleError(void) { }
	
};


class DELPHICLASS EIdPackageSizeTooBig;
class PASCALIMPLEMENTATION EIdPackageSizeTooBig : public EIdSocketHandleError
{
	typedef EIdSocketHandleError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdPackageSizeTooBig(const System::UnicodeString AMsg)/* overload */ : EIdSocketHandleError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdPackageSizeTooBig(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketHandleError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdPackageSizeTooBig(int Ident)/* overload */ : EIdSocketHandleError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdPackageSizeTooBig(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketHandleError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdPackageSizeTooBig(const System::UnicodeString Msg, int AHelpContext) : EIdSocketHandleError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdPackageSizeTooBig(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketHandleError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdPackageSizeTooBig(int Ident, int AHelpContext)/* overload */ : EIdSocketHandleError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdPackageSizeTooBig(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketHandleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdPackageSizeTooBig(void) { }
	
};


class DELPHICLASS EIdNotAllBytesSent;
class PASCALIMPLEMENTATION EIdNotAllBytesSent : public EIdSocketHandleError
{
	typedef EIdSocketHandleError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNotAllBytesSent(const System::UnicodeString AMsg)/* overload */ : EIdSocketHandleError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNotAllBytesSent(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketHandleError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNotAllBytesSent(int Ident)/* overload */ : EIdSocketHandleError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNotAllBytesSent(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketHandleError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNotAllBytesSent(const System::UnicodeString Msg, int AHelpContext) : EIdSocketHandleError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNotAllBytesSent(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketHandleError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNotAllBytesSent(int Ident, int AHelpContext)/* overload */ : EIdSocketHandleError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNotAllBytesSent(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketHandleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNotAllBytesSent(void) { }
	
};


class DELPHICLASS EIdCouldNotBindSocket;
class PASCALIMPLEMENTATION EIdCouldNotBindSocket : public EIdSocketHandleError
{
	typedef EIdSocketHandleError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCouldNotBindSocket(const System::UnicodeString AMsg)/* overload */ : EIdSocketHandleError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCouldNotBindSocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketHandleError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCouldNotBindSocket(int Ident)/* overload */ : EIdSocketHandleError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCouldNotBindSocket(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketHandleError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCouldNotBindSocket(const System::UnicodeString Msg, int AHelpContext) : EIdSocketHandleError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCouldNotBindSocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketHandleError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCouldNotBindSocket(int Ident, int AHelpContext)/* overload */ : EIdSocketHandleError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCouldNotBindSocket(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketHandleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCouldNotBindSocket(void) { }
	
};


class DELPHICLASS EIdCanNotBindPortInRange;
class PASCALIMPLEMENTATION EIdCanNotBindPortInRange : public EIdSocketHandleError
{
	typedef EIdSocketHandleError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCanNotBindPortInRange(const System::UnicodeString AMsg)/* overload */ : EIdSocketHandleError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCanNotBindPortInRange(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketHandleError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCanNotBindPortInRange(int Ident)/* overload */ : EIdSocketHandleError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCanNotBindPortInRange(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketHandleError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCanNotBindPortInRange(const System::UnicodeString Msg, int AHelpContext) : EIdSocketHandleError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCanNotBindPortInRange(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketHandleError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCanNotBindPortInRange(int Ident, int AHelpContext)/* overload */ : EIdSocketHandleError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCanNotBindPortInRange(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketHandleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCanNotBindPortInRange(void) { }
	
};


class DELPHICLASS EIdInvalidPortRange;
class PASCALIMPLEMENTATION EIdInvalidPortRange : public EIdSocketHandleError
{
	typedef EIdSocketHandleError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidPortRange(const System::UnicodeString AMsg)/* overload */ : EIdSocketHandleError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidPortRange(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketHandleError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidPortRange(int Ident)/* overload */ : EIdSocketHandleError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidPortRange(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketHandleError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidPortRange(const System::UnicodeString Msg, int AHelpContext) : EIdSocketHandleError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidPortRange(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketHandleError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidPortRange(int Ident, int AHelpContext)/* overload */ : EIdSocketHandleError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidPortRange(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketHandleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidPortRange(void) { }
	
};


class DELPHICLASS EIdCannotSetIPVersionWhenConnected;
class PASCALIMPLEMENTATION EIdCannotSetIPVersionWhenConnected : public EIdSocketHandleError
{
	typedef EIdSocketHandleError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCannotSetIPVersionWhenConnected(const System::UnicodeString AMsg)/* overload */ : EIdSocketHandleError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCannotSetIPVersionWhenConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocketHandleError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCannotSetIPVersionWhenConnected(int Ident)/* overload */ : EIdSocketHandleError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCannotSetIPVersionWhenConnected(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocketHandleError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCannotSetIPVersionWhenConnected(const System::UnicodeString Msg, int AHelpContext) : EIdSocketHandleError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCannotSetIPVersionWhenConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocketHandleError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCannotSetIPVersionWhenConnected(int Ident, int AHelpContext)/* overload */ : EIdSocketHandleError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCannotSetIPVersionWhenConnected(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocketHandleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCannotSetIPVersionWhenConnected(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idexception */
using namespace Idexception;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdexceptionHPP
