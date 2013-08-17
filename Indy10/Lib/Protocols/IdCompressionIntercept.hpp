// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcompressionintercept.pas' rev: 20.00

#ifndef IdcompressioninterceptHPP
#define IdcompressioninterceptHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idctypes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idzlibheaders.hpp>	// Pascal unit
#include <Idzlib.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcompressionintercept
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdCompressionException;
class PASCALIMPLEMENTATION EIdCompressionException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCompressionException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCompressionException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCompressionException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCompressionException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCompressionException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCompressionException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCompressionException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCompressionException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCompressionException(void) { }
	
};


class DELPHICLASS EIdCompressorInitFailure;
class PASCALIMPLEMENTATION EIdCompressorInitFailure : public EIdCompressionException
{
	typedef EIdCompressionException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCompressorInitFailure(const System::UnicodeString AMsg)/* overload */ : EIdCompressionException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCompressorInitFailure(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdCompressionException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCompressorInitFailure(int Ident)/* overload */ : EIdCompressionException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCompressorInitFailure(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdCompressionException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCompressorInitFailure(const System::UnicodeString Msg, int AHelpContext) : EIdCompressionException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCompressorInitFailure(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdCompressionException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCompressorInitFailure(int Ident, int AHelpContext)/* overload */ : EIdCompressionException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCompressorInitFailure(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdCompressionException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCompressorInitFailure(void) { }
	
};


class DELPHICLASS EIdDecompressorInitFailure;
class PASCALIMPLEMENTATION EIdDecompressorInitFailure : public EIdCompressionException
{
	typedef EIdCompressionException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDecompressorInitFailure(const System::UnicodeString AMsg)/* overload */ : EIdCompressionException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDecompressorInitFailure(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdCompressionException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDecompressorInitFailure(int Ident)/* overload */ : EIdCompressionException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDecompressorInitFailure(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdCompressionException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDecompressorInitFailure(const System::UnicodeString Msg, int AHelpContext) : EIdCompressionException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDecompressorInitFailure(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdCompressionException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDecompressorInitFailure(int Ident, int AHelpContext)/* overload */ : EIdCompressionException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDecompressorInitFailure(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdCompressionException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDecompressorInitFailure(void) { }
	
};


class DELPHICLASS EIdCompressionError;
class PASCALIMPLEMENTATION EIdCompressionError : public EIdCompressionException
{
	typedef EIdCompressionException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCompressionError(const System::UnicodeString AMsg)/* overload */ : EIdCompressionException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdCompressionException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCompressionError(int Ident)/* overload */ : EIdCompressionException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCompressionError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdCompressionException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCompressionError(const System::UnicodeString Msg, int AHelpContext) : EIdCompressionException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdCompressionException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCompressionError(int Ident, int AHelpContext)/* overload */ : EIdCompressionException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCompressionError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdCompressionException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCompressionError(void) { }
	
};


class DELPHICLASS EIdDecompressionError;
class PASCALIMPLEMENTATION EIdDecompressionError : public EIdCompressionException
{
	typedef EIdCompressionException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDecompressionError(const System::UnicodeString AMsg)/* overload */ : EIdCompressionException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDecompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdCompressionException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDecompressionError(int Ident)/* overload */ : EIdCompressionException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDecompressionError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdCompressionException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDecompressionError(const System::UnicodeString Msg, int AHelpContext) : EIdCompressionException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDecompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdCompressionException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDecompressionError(int Ident, int AHelpContext)/* overload */ : EIdCompressionException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDecompressionError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdCompressionException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDecompressionError(void) { }
	
};


typedef ShortInt TIdCompressionLevel;

class DELPHICLASS TIdCompressionIntercept;
class PASCALIMPLEMENTATION TIdCompressionIntercept : public Idintercept::TIdConnectionIntercept
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
protected:
	TIdCompressionLevel FCompressionLevel;
	Idzlibheaders::z_stream FCompressRec;
	Idzlibheaders::z_stream FDecompressRec;
	Sysutils::TBytes FRecvBuf;
	unsigned FRecvCount;
	unsigned FRecvSize;
	Sysutils::TBytes FSendBuf;
	unsigned FSendCount;
	unsigned FSendSize;
	void __fastcall SetCompressionLevel(TIdCompressionLevel Value);
	void __fastcall InitCompressors(void);
	void __fastcall DeinitCompressors(void);
	
public:
	__fastcall virtual ~TIdCompressionIntercept(void);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall Receive(Sysutils::TBytes &VBuffer);
	virtual void __fastcall Send(Sysutils::TBytes &VBuffer);
	
__published:
	__property TIdCompressionLevel CompressionLevel = {read=FCompressionLevel, write=SetCompressionLevel, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCompressionIntercept(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdConnectionIntercept(AOwner) { }
	
};


class DELPHICLASS TIdServerCompressionIntercept;
class PASCALIMPLEMENTATION TIdServerCompressionIntercept : public Idintercept::TIdServerIntercept
{
	typedef Idintercept::TIdServerIntercept inherited;
	
protected:
	TIdCompressionLevel FCompressionLevel;
	
public:
	virtual void __fastcall Init(void);
	virtual Idintercept::TIdConnectionIntercept* __fastcall Accept(Classes::TComponent* AConnection);
	
__published:
	__property TIdCompressionLevel CompressionLevel = {read=FCompressionLevel, write=FCompressionLevel, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerCompressionIntercept(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdServerIntercept(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdServerCompressionIntercept(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcompressionintercept */
using namespace Idcompressionintercept;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcompressioninterceptHPP
