// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idexceptioncore.pas' rev: 20.00

#ifndef IdexceptioncoreHPP
#define IdexceptioncoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idexceptioncore
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdFiber;
class PASCALIMPLEMENTATION EIdFiber : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFiber(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFiber(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFiber(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFiber(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFiber(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFiber(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFiber(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFiber(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFiber(void) { }
	
};


class DELPHICLASS EIdFiberFinished;
class PASCALIMPLEMENTATION EIdFiberFinished : public EIdFiber
{
	typedef EIdFiber inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFiberFinished(const System::UnicodeString AMsg)/* overload */ : EIdFiber(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFiberFinished(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFiber(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFiberFinished(int Ident)/* overload */ : EIdFiber(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFiberFinished(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFiber(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFiberFinished(const System::UnicodeString Msg, int AHelpContext) : EIdFiber(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFiberFinished(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFiber(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFiberFinished(int Ident, int AHelpContext)/* overload */ : EIdFiber(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFiberFinished(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFiber(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFiberFinished(void) { }
	
};


class DELPHICLASS EIdFibersNotSupported;
class PASCALIMPLEMENTATION EIdFibersNotSupported : public EIdFiber
{
	typedef EIdFiber inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFibersNotSupported(const System::UnicodeString AMsg)/* overload */ : EIdFiber(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFibersNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFiber(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFibersNotSupported(int Ident)/* overload */ : EIdFiber(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFibersNotSupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFiber(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFibersNotSupported(const System::UnicodeString Msg, int AHelpContext) : EIdFiber(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFibersNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFiber(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFibersNotSupported(int Ident, int AHelpContext)/* overload */ : EIdFiber(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFibersNotSupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFiber(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFibersNotSupported(void) { }
	
};


class DELPHICLASS EIdAlreadyConnected;
class PASCALIMPLEMENTATION EIdAlreadyConnected : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdAlreadyConnected(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdAlreadyConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdAlreadyConnected(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdAlreadyConnected(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdAlreadyConnected(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdAlreadyConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdAlreadyConnected(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdAlreadyConnected(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdAlreadyConnected(void) { }
	
};


class DELPHICLASS EIdClosedSocket;
class PASCALIMPLEMENTATION EIdClosedSocket : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdClosedSocket(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdClosedSocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdClosedSocket(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdClosedSocket(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdClosedSocket(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdClosedSocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdClosedSocket(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdClosedSocket(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdClosedSocket(void) { }
	
};


class DELPHICLASS EIdResponseError;
class PASCALIMPLEMENTATION EIdResponseError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdResponseError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdResponseError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdResponseError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdResponseError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdResponseError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdResponseError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdResponseError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdResponseError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdResponseError(void) { }
	
};


class DELPHICLASS EIdReadTimeout;
class PASCALIMPLEMENTATION EIdReadTimeout : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdReadTimeout(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdReadTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdReadTimeout(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdReadTimeout(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdReadTimeout(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdReadTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdReadTimeout(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdReadTimeout(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdReadTimeout(void) { }
	
};


class DELPHICLASS EIdAcceptTimeout;
class PASCALIMPLEMENTATION EIdAcceptTimeout : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdAcceptTimeout(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdAcceptTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdAcceptTimeout(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdAcceptTimeout(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdAcceptTimeout(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdAcceptTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdAcceptTimeout(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdAcceptTimeout(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdAcceptTimeout(void) { }
	
};


class DELPHICLASS EIdReadLnMaxLineLengthExceeded;
class PASCALIMPLEMENTATION EIdReadLnMaxLineLengthExceeded : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdReadLnMaxLineLengthExceeded(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdReadLnMaxLineLengthExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdReadLnMaxLineLengthExceeded(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdReadLnMaxLineLengthExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdReadLnMaxLineLengthExceeded(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdReadLnMaxLineLengthExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdReadLnMaxLineLengthExceeded(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdReadLnMaxLineLengthExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdReadLnMaxLineLengthExceeded(void) { }
	
};


class DELPHICLASS EIdReadLnWaitMaxAttemptsExceeded;
class PASCALIMPLEMENTATION EIdReadLnWaitMaxAttemptsExceeded : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdReadLnWaitMaxAttemptsExceeded(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdReadLnWaitMaxAttemptsExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdReadLnWaitMaxAttemptsExceeded(void) { }
	
};


class DELPHICLASS EIdPortRequired;
class PASCALIMPLEMENTATION EIdPortRequired : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdPortRequired(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdPortRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdPortRequired(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdPortRequired(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdPortRequired(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdPortRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdPortRequired(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdPortRequired(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdPortRequired(void) { }
	
};


class DELPHICLASS EIdHostRequired;
class PASCALIMPLEMENTATION EIdHostRequired : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHostRequired(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHostRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHostRequired(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHostRequired(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHostRequired(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHostRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHostRequired(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHostRequired(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHostRequired(void) { }
	
};


class DELPHICLASS EIdTCPConnectionError;
class PASCALIMPLEMENTATION EIdTCPConnectionError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTCPConnectionError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTCPConnectionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTCPConnectionError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTCPConnectionError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTCPConnectionError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTCPConnectionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTCPConnectionError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTCPConnectionError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTCPConnectionError(void) { }
	
};


class DELPHICLASS EIdObjectTypeNotSupported;
class PASCALIMPLEMENTATION EIdObjectTypeNotSupported : public EIdTCPConnectionError
{
	typedef EIdTCPConnectionError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdObjectTypeNotSupported(const System::UnicodeString AMsg)/* overload */ : EIdTCPConnectionError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdObjectTypeNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdObjectTypeNotSupported(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdObjectTypeNotSupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdObjectTypeNotSupported(const System::UnicodeString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdObjectTypeNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdObjectTypeNotSupported(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdObjectTypeNotSupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdObjectTypeNotSupported(void) { }
	
};


class DELPHICLASS EIdInterceptPropIsNil;
class PASCALIMPLEMENTATION EIdInterceptPropIsNil : public EIdTCPConnectionError
{
	typedef EIdTCPConnectionError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInterceptPropIsNil(const System::UnicodeString AMsg)/* overload */ : EIdTCPConnectionError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInterceptPropIsNil(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInterceptPropIsNil(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInterceptPropIsNil(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInterceptPropIsNil(const System::UnicodeString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInterceptPropIsNil(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInterceptPropIsNil(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInterceptPropIsNil(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInterceptPropIsNil(void) { }
	
};


class DELPHICLASS EIdInterceptPropInvalid;
class PASCALIMPLEMENTATION EIdInterceptPropInvalid : public EIdTCPConnectionError
{
	typedef EIdTCPConnectionError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInterceptPropInvalid(const System::UnicodeString AMsg)/* overload */ : EIdTCPConnectionError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInterceptPropInvalid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInterceptPropInvalid(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInterceptPropInvalid(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInterceptPropInvalid(const System::UnicodeString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInterceptPropInvalid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInterceptPropInvalid(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInterceptPropInvalid(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInterceptPropInvalid(void) { }
	
};


class DELPHICLASS EIdIOHandlerPropInvalid;
class PASCALIMPLEMENTATION EIdIOHandlerPropInvalid : public EIdTCPConnectionError
{
	typedef EIdTCPConnectionError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIOHandlerPropInvalid(const System::UnicodeString AMsg)/* overload */ : EIdTCPConnectionError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIOHandlerPropInvalid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIOHandlerPropInvalid(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIOHandlerPropInvalid(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIOHandlerPropInvalid(const System::UnicodeString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIOHandlerPropInvalid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIOHandlerPropInvalid(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIOHandlerPropInvalid(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIOHandlerPropInvalid(void) { }
	
};


class DELPHICLASS EIdNoDataToRead;
class PASCALIMPLEMENTATION EIdNoDataToRead : public EIdTCPConnectionError
{
	typedef EIdTCPConnectionError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNoDataToRead(const System::UnicodeString AMsg)/* overload */ : EIdTCPConnectionError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNoDataToRead(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNoDataToRead(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNoDataToRead(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNoDataToRead(const System::UnicodeString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNoDataToRead(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNoDataToRead(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNoDataToRead(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNoDataToRead(void) { }
	
};


class DELPHICLASS EIdFileNotFound;
class PASCALIMPLEMENTATION EIdFileNotFound : public EIdTCPConnectionError
{
	typedef EIdTCPConnectionError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileNotFound(const System::UnicodeString AMsg)/* overload */ : EIdTCPConnectionError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileNotFound(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileNotFound(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileNotFound(const System::UnicodeString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileNotFound(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileNotFound(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileNotFound(void) { }
	
};


class DELPHICLASS EIdNotConnected;
class PASCALIMPLEMENTATION EIdNotConnected : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNotConnected(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNotConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNotConnected(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNotConnected(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNotConnected(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNotConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNotConnected(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNotConnected(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNotConnected(void) { }
	
};


class DELPHICLASS EInvalidSyslogMessage;
class PASCALIMPLEMENTATION EInvalidSyslogMessage : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EInvalidSyslogMessage(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EInvalidSyslogMessage(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidSyslogMessage(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidSyslogMessage(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidSyslogMessage(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidSyslogMessage(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidSyslogMessage(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidSyslogMessage(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidSyslogMessage(void) { }
	
};


class DELPHICLASS EIdSSLProtocolReplyError;
class PASCALIMPLEMENTATION EIdSSLProtocolReplyError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSSLProtocolReplyError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSSLProtocolReplyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSSLProtocolReplyError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSSLProtocolReplyError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSSLProtocolReplyError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSSLProtocolReplyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSSLProtocolReplyError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSSLProtocolReplyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSSLProtocolReplyError(void) { }
	
};


class DELPHICLASS EIdConnectTimeout;
class PASCALIMPLEMENTATION EIdConnectTimeout : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdConnectTimeout(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdConnectTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdConnectTimeout(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdConnectTimeout(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdConnectTimeout(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdConnectTimeout(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdConnectTimeout(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdConnectTimeout(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdConnectTimeout(void) { }
	
};


class DELPHICLASS EIdConnectException;
class PASCALIMPLEMENTATION EIdConnectException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdConnectException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdConnectException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdConnectException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdConnectException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdConnectException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdConnectException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdConnectException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdConnectException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdConnectException(void) { }
	
};


class DELPHICLASS EIdTransparentProxyCantBind;
class PASCALIMPLEMENTATION EIdTransparentProxyCantBind : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTransparentProxyCantBind(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTransparentProxyCantBind(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTransparentProxyCantBind(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTransparentProxyCantBind(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTransparentProxyCantBind(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTransparentProxyCantBind(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTransparentProxyCantBind(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTransparentProxyCantBind(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTransparentProxyCantBind(void) { }
	
};


class DELPHICLASS EIdHttpProxyError;
class PASCALIMPLEMENTATION EIdHttpProxyError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHttpProxyError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHttpProxyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHttpProxyError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHttpProxyError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHttpProxyError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHttpProxyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHttpProxyError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHttpProxyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHttpProxyError(void) { }
	
};


class DELPHICLASS EIdSocksError;
class PASCALIMPLEMENTATION EIdSocksError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksError(void) { }
	
};


class DELPHICLASS EIdSocksRequestFailed;
class PASCALIMPLEMENTATION EIdSocksRequestFailed : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksRequestFailed(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksRequestFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksRequestFailed(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksRequestFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksRequestFailed(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksRequestFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksRequestFailed(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksRequestFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksRequestFailed(void) { }
	
};


class DELPHICLASS EIdSocksRequestServerFailed;
class PASCALIMPLEMENTATION EIdSocksRequestServerFailed : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksRequestServerFailed(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksRequestServerFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksRequestServerFailed(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksRequestServerFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksRequestServerFailed(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksRequestServerFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksRequestServerFailed(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksRequestServerFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksRequestServerFailed(void) { }
	
};


class DELPHICLASS EIdSocksRequestIdentFailed;
class PASCALIMPLEMENTATION EIdSocksRequestIdentFailed : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksRequestIdentFailed(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksRequestIdentFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksRequestIdentFailed(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksRequestIdentFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksRequestIdentFailed(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksRequestIdentFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksRequestIdentFailed(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksRequestIdentFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksRequestIdentFailed(void) { }
	
};


class DELPHICLASS EIdSocksUnknownError;
class PASCALIMPLEMENTATION EIdSocksUnknownError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksUnknownError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksUnknownError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksUnknownError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksUnknownError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksUnknownError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksUnknownError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksUnknownError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksUnknownError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksUnknownError(void) { }
	
};


class DELPHICLASS EIdSocksServerRespondError;
class PASCALIMPLEMENTATION EIdSocksServerRespondError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerRespondError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerRespondError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerRespondError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerRespondError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerRespondError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerRespondError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerRespondError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerRespondError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerRespondError(void) { }
	
};


class DELPHICLASS EIdSocksAuthMethodError;
class PASCALIMPLEMENTATION EIdSocksAuthMethodError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksAuthMethodError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksAuthMethodError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksAuthMethodError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksAuthMethodError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksAuthMethodError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksAuthMethodError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksAuthMethodError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksAuthMethodError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksAuthMethodError(void) { }
	
};


class DELPHICLASS EIdSocksAuthError;
class PASCALIMPLEMENTATION EIdSocksAuthError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksAuthError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksAuthError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksAuthError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksAuthError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksAuthError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksAuthError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksAuthError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksAuthError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksAuthError(void) { }
	
};


class DELPHICLASS EIdSocksServerGeneralError;
class PASCALIMPLEMENTATION EIdSocksServerGeneralError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerGeneralError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerGeneralError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerGeneralError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerGeneralError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerGeneralError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerGeneralError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerGeneralError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerGeneralError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerGeneralError(void) { }
	
};


class DELPHICLASS EIdSocksServerPermissionError;
class PASCALIMPLEMENTATION EIdSocksServerPermissionError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerPermissionError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerPermissionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerPermissionError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerPermissionError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerPermissionError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerPermissionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerPermissionError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerPermissionError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerPermissionError(void) { }
	
};


class DELPHICLASS EIdSocksServerNetUnreachableError;
class PASCALIMPLEMENTATION EIdSocksServerNetUnreachableError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerNetUnreachableError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerNetUnreachableError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerNetUnreachableError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerNetUnreachableError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerNetUnreachableError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerNetUnreachableError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerNetUnreachableError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerNetUnreachableError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerNetUnreachableError(void) { }
	
};


class DELPHICLASS EIdSocksServerHostUnreachableError;
class PASCALIMPLEMENTATION EIdSocksServerHostUnreachableError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerHostUnreachableError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerHostUnreachableError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerHostUnreachableError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerHostUnreachableError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerHostUnreachableError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerHostUnreachableError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerHostUnreachableError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerHostUnreachableError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerHostUnreachableError(void) { }
	
};


class DELPHICLASS EIdSocksServerConnectionRefusedError;
class PASCALIMPLEMENTATION EIdSocksServerConnectionRefusedError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerConnectionRefusedError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerConnectionRefusedError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerConnectionRefusedError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerConnectionRefusedError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerConnectionRefusedError(void) { }
	
};


class DELPHICLASS EIdSocksServerTTLExpiredError;
class PASCALIMPLEMENTATION EIdSocksServerTTLExpiredError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerTTLExpiredError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerTTLExpiredError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerTTLExpiredError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerTTLExpiredError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerTTLExpiredError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerTTLExpiredError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerTTLExpiredError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerTTLExpiredError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerTTLExpiredError(void) { }
	
};


class DELPHICLASS EIdSocksServerCommandError;
class PASCALIMPLEMENTATION EIdSocksServerCommandError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerCommandError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerCommandError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerCommandError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerCommandError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerCommandError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerCommandError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerCommandError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerCommandError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerCommandError(void) { }
	
};


class DELPHICLASS EIdSocksServerAddressError;
class PASCALIMPLEMENTATION EIdSocksServerAddressError : public EIdSocksError
{
	typedef EIdSocksError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSocksServerAddressError(const System::UnicodeString AMsg)/* overload */ : EIdSocksError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerAddressError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerAddressError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerAddressError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerAddressError(const System::UnicodeString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerAddressError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerAddressError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerAddressError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSocksServerAddressError(void) { }
	
};


class DELPHICLASS EIdConnectionStateError;
class PASCALIMPLEMENTATION EIdConnectionStateError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdConnectionStateError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdConnectionStateError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdConnectionStateError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdConnectionStateError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdConnectionStateError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdConnectionStateError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdConnectionStateError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdConnectionStateError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdConnectionStateError(void) { }
	
};


class DELPHICLASS EIdDnsResolverError;
class PASCALIMPLEMENTATION EIdDnsResolverError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDnsResolverError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDnsResolverError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDnsResolverError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDnsResolverError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDnsResolverError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDnsResolverError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDnsResolverError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDnsResolverError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDnsResolverError(void) { }
	
};


class DELPHICLASS EIdInvalidSocket;
class PASCALIMPLEMENTATION EIdInvalidSocket : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidSocket(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidSocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidSocket(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidSocket(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidSocket(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidSocket(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidSocket(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidSocket(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidSocket(void) { }
	
};


class DELPHICLASS EIdThreadMgrError;
class PASCALIMPLEMENTATION EIdThreadMgrError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdThreadMgrError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdThreadMgrError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdThreadMgrError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdThreadMgrError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdThreadMgrError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdThreadMgrError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdThreadMgrError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdThreadMgrError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdThreadMgrError(void) { }
	
};


class DELPHICLASS EIdThreadClassNotSpecified;
class PASCALIMPLEMENTATION EIdThreadClassNotSpecified : public EIdThreadMgrError
{
	typedef EIdThreadMgrError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdThreadClassNotSpecified(const System::UnicodeString AMsg)/* overload */ : EIdThreadMgrError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdThreadClassNotSpecified(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdThreadMgrError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdThreadClassNotSpecified(int Ident)/* overload */ : EIdThreadMgrError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdThreadClassNotSpecified(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdThreadMgrError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdThreadClassNotSpecified(const System::UnicodeString Msg, int AHelpContext) : EIdThreadMgrError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdThreadClassNotSpecified(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdThreadMgrError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdThreadClassNotSpecified(int Ident, int AHelpContext)/* overload */ : EIdThreadMgrError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdThreadClassNotSpecified(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdThreadMgrError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdThreadClassNotSpecified(void) { }
	
};


class DELPHICLASS EIdTFTPException;
class PASCALIMPLEMENTATION EIdTFTPException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPException(void) { }
	
};


class DELPHICLASS EIdTFTPFileNotFound;
class PASCALIMPLEMENTATION EIdTFTPFileNotFound : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPFileNotFound(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPFileNotFound(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPFileNotFound(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPFileNotFound(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPFileNotFound(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPFileNotFound(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPFileNotFound(void) { }
	
};


class DELPHICLASS EIdTFTPAccessViolation;
class PASCALIMPLEMENTATION EIdTFTPAccessViolation : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPAccessViolation(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPAccessViolation(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPAccessViolation(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPAccessViolation(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPAccessViolation(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPAccessViolation(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPAccessViolation(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPAccessViolation(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPAccessViolation(void) { }
	
};


class DELPHICLASS EIdTFTPAllocationExceeded;
class PASCALIMPLEMENTATION EIdTFTPAllocationExceeded : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPAllocationExceeded(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPAllocationExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPAllocationExceeded(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPAllocationExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPAllocationExceeded(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPAllocationExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPAllocationExceeded(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPAllocationExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPAllocationExceeded(void) { }
	
};


class DELPHICLASS EIdTFTPIllegalOperation;
class PASCALIMPLEMENTATION EIdTFTPIllegalOperation : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPIllegalOperation(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPIllegalOperation(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPIllegalOperation(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPIllegalOperation(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPIllegalOperation(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPIllegalOperation(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPIllegalOperation(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPIllegalOperation(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPIllegalOperation(void) { }
	
};


class DELPHICLASS EIdTFTPUnknownTransferID;
class PASCALIMPLEMENTATION EIdTFTPUnknownTransferID : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPUnknownTransferID(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPUnknownTransferID(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPUnknownTransferID(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPUnknownTransferID(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPUnknownTransferID(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPUnknownTransferID(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPUnknownTransferID(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPUnknownTransferID(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPUnknownTransferID(void) { }
	
};


class DELPHICLASS EIdTFTPFileAlreadyExists;
class PASCALIMPLEMENTATION EIdTFTPFileAlreadyExists : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPFileAlreadyExists(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPFileAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPFileAlreadyExists(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPFileAlreadyExists(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPFileAlreadyExists(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPFileAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPFileAlreadyExists(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPFileAlreadyExists(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPFileAlreadyExists(void) { }
	
};


class DELPHICLASS EIdTFTPNoSuchUser;
class PASCALIMPLEMENTATION EIdTFTPNoSuchUser : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPNoSuchUser(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPNoSuchUser(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPNoSuchUser(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPNoSuchUser(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPNoSuchUser(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPNoSuchUser(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPNoSuchUser(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPNoSuchUser(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPNoSuchUser(void) { }
	
};


class DELPHICLASS EIdTFTPOptionNegotiationFailed;
class PASCALIMPLEMENTATION EIdTFTPOptionNegotiationFailed : public EIdTFTPException
{
	typedef EIdTFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTFTPOptionNegotiationFailed(const System::UnicodeString AMsg)/* overload */ : EIdTFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPOptionNegotiationFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTFTPOptionNegotiationFailed(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPOptionNegotiationFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(const System::UnicodeString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTFTPOptionNegotiationFailed(void) { }
	
};


class DELPHICLASS EIdIcmpException;
class PASCALIMPLEMENTATION EIdIcmpException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIcmpException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIcmpException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIcmpException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIcmpException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIcmpException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIcmpException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIcmpException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIcmpException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIcmpException(void) { }
	
};


class DELPHICLASS EIdSetSizeExceeded;
class PASCALIMPLEMENTATION EIdSetSizeExceeded : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSetSizeExceeded(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSetSizeExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSetSizeExceeded(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSetSizeExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSetSizeExceeded(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSetSizeExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSetSizeExceeded(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSetSizeExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSetSizeExceeded(void) { }
	
};


class DELPHICLASS EIdMessageException;
class PASCALIMPLEMENTATION EIdMessageException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMessageException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMessageException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMessageException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMessageException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMessageException(void) { }
	
};


class DELPHICLASS EIdSchedulerException;
class PASCALIMPLEMENTATION EIdSchedulerException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSchedulerException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSchedulerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSchedulerException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSchedulerException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSchedulerException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSchedulerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSchedulerException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSchedulerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSchedulerException(void) { }
	
};


class DELPHICLASS EIdSchedulerMaxThreadsExceeded;
class PASCALIMPLEMENTATION EIdSchedulerMaxThreadsExceeded : public EIdSchedulerException
{
	typedef EIdSchedulerException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSchedulerMaxThreadsExceeded(const System::UnicodeString AMsg)/* overload */ : EIdSchedulerException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSchedulerMaxThreadsExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSchedulerException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSchedulerMaxThreadsExceeded(int Ident)/* overload */ : EIdSchedulerException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSchedulerMaxThreadsExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSchedulerException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSchedulerMaxThreadsExceeded(const System::UnicodeString Msg, int AHelpContext) : EIdSchedulerException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSchedulerMaxThreadsExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSchedulerException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSchedulerMaxThreadsExceeded(int Ident, int AHelpContext)/* overload */ : EIdSchedulerException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSchedulerMaxThreadsExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSchedulerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSchedulerMaxThreadsExceeded(void) { }
	
};


class DELPHICLASS EIdMaxCaptureLineExceeded;
class PASCALIMPLEMENTATION EIdMaxCaptureLineExceeded : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMaxCaptureLineExceeded(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMaxCaptureLineExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMaxCaptureLineExceeded(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMaxCaptureLineExceeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMaxCaptureLineExceeded(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMaxCaptureLineExceeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMaxCaptureLineExceeded(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMaxCaptureLineExceeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMaxCaptureLineExceeded(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idexceptioncore */
using namespace Idexceptioncore;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdexceptioncoreHPP
