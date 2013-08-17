// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idzlib.pas' rev: 20.00

#ifndef IdzlibHPP
#define IdzlibHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idctypes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idzlibheaders.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idzlib
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomZlibStream;
class PASCALIMPLEMENTATION TCustomZlibStream : public Idglobal::TIdBaseStream
{
	typedef Idglobal::TIdBaseStream inherited;
	
protected:
	Classes::TStream* FStrm;
	int FStrmPos;
	Classes::TNotifyEvent FOnProgress;
	Idzlibheaders::z_stream FZRec;
	StaticArray<char, 65536> FBuffer;
	StaticArray<char, 256> FNameBuffer;
	Idzlibheaders::gz_header FGZHeader;
	Idzlibheaders::TZStreamType FStreamType;
	DYNAMIC void __fastcall Progress(void);
	virtual void __fastcall IdSetSize(__int64 ASize);
	__property Classes::TNotifyEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	
public:
	__fastcall TCustomZlibStream(Classes::TStream* Strm);
	__fastcall virtual ~TCustomZlibStream(void);
	__property Idzlibheaders::gz_header GZHeader = {read=FGZHeader};
};


#pragma option push -b-
enum TCompressionLevel { clNone, clFastest, clDefault, clMax };
#pragma option pop

class DELPHICLASS TCompressionStream;
class PASCALIMPLEMENTATION TCompressionStream : public TCustomZlibStream
{
	typedef TCustomZlibStream inherited;
	
protected:
	float __fastcall GetCompressionRate(void);
	virtual int __fastcall IdRead(Sysutils::TBytes &VBuffer, int AOffset, int ACount);
	virtual int __fastcall IdWrite(const Sysutils::TBytes ABuffer, int AOffset, int ACount);
	virtual __int64 __fastcall IdSeek(const __int64 AOffset, Classes::TSeekOrigin AOrigin);
	
public:
	__fastcall TCompressionStream(TCompressionLevel CompressionLevel, Classes::TStream* Dest, const Idzlibheaders::TZStreamType StreamType, const System::UnicodeString AName, int ATime);
	__fastcall TCompressionStream(TCompressionLevel CompressionLevel, Classes::TStream* Dest, const bool AIncludeHeaders);
	__fastcall TCompressionStream(TCompressionLevel CompressionLevel, Classes::TStream* Dest, const System::UnicodeString AName, int ATime)/* overload */;
	__fastcall virtual ~TCompressionStream(void);
	__property float CompressionRate = {read=GetCompressionRate};
	__property OnProgress;
};


class DELPHICLASS TDecompressionStream;
class PASCALIMPLEMENTATION TDecompressionStream : public TCustomZlibStream
{
	typedef TCustomZlibStream inherited;
	
protected:
	__int64 FInitialPos;
	virtual int __fastcall IdRead(Sysutils::TBytes &VBuffer, int AOffset, int ACount);
	virtual int __fastcall IdWrite(const Sysutils::TBytes ABuffer, int AOffset, int ACount);
	virtual __int64 __fastcall IdSeek(const __int64 AOffset, Classes::TSeekOrigin AOrigin);
	
public:
	__fastcall TDecompressionStream(Classes::TStream* Source);
	__fastcall virtual ~TDecompressionStream(void);
	void __fastcall InitRead(void);
	bool __fastcall IsGZip(void);
	__property OnProgress;
};


class DELPHICLASS EZlibError;
class PASCALIMPLEMENTATION EZlibError : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
protected:
	int FErrorCode;
	
public:
	__classmethod void __fastcall RaiseException(const int AError);
	__property int ErrorCode = {read=FErrorCode, nodefault};
public:
	/* Exception.Create */ inline __fastcall EZlibError(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EZlibError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EZlibError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EZlibError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EZlibError(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EZlibError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EZlibError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EZlibError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EZlibError(void) { }
	
};


class DELPHICLASS ECompressionError;
class PASCALIMPLEMENTATION ECompressionError : public EZlibError
{
	typedef EZlibError inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECompressionError(const System::UnicodeString Msg) : EZlibError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EZlibError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECompressionError(int Ident)/* overload */ : EZlibError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall ECompressionError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EZlibError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECompressionError(const System::UnicodeString Msg, int AHelpContext) : EZlibError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EZlibError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECompressionError(int Ident, int AHelpContext)/* overload */ : EZlibError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECompressionError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EZlibError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECompressionError(void) { }
	
};


class DELPHICLASS EDecompressionError;
class PASCALIMPLEMENTATION EDecompressionError : public EZlibError
{
	typedef EZlibError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EDecompressionError(const System::UnicodeString Msg) : EZlibError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EDecompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EZlibError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EDecompressionError(int Ident)/* overload */ : EZlibError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EDecompressionError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EZlibError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EDecompressionError(const System::UnicodeString Msg, int AHelpContext) : EZlibError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EDecompressionError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EZlibError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDecompressionError(int Ident, int AHelpContext)/* overload */ : EZlibError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDecompressionError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EZlibError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EDecompressionError(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt MAX_WBITS = 0xf;
static const ShortInt GZIP_WINBITS = 0x1f;
static const ShortInt RAW_WBITS = -15;
extern PACKAGE int __fastcall CCheck(int code);
extern PACKAGE int __fastcall DCheck(int code);
extern PACKAGE void __fastcall CompressBuf(const void * InBuf, int InBytes, /* out */ void * &OutBuf, /* out */ unsigned &OutBytes);
extern PACKAGE Idzlibheaders::TZStreamType __fastcall GetStreamType(void * InBuffer, unsigned InCount, Idzlibheaders::gz_headerp gzheader, /* out */ unsigned &HeaderSize)/* overload */;
extern PACKAGE Idzlibheaders::TZStreamType __fastcall GetStreamType(Classes::TStream* InStream, Idzlibheaders::gz_headerp gzheader, /* out */ unsigned &HeaderSize)/* overload */;
extern PACKAGE void __fastcall DecompressStream(Classes::TStream* InStream, Classes::TStream* OutStream);
extern PACKAGE void __fastcall IndyDecompressStream(Classes::TStream* InStream, Classes::TStream* OutStream, const int AWindowBits);
extern PACKAGE void __fastcall IndyCompressStream(Classes::TStream* InStream, Classes::TStream* OutStream, const int level = 0xffffffff, const int WinBits = 0xf, const int MemLevel = 0x9, const int Stratagy = 0x0);
extern PACKAGE void __fastcall CompressStream(Classes::TStream* InStream, Classes::TStream* OutStream, TCompressionLevel level, Idzlibheaders::TZStreamType StreamType);
extern PACKAGE void __fastcall CompressStreamEx(Classes::TStream* InStream, Classes::TStream* OutStream, TCompressionLevel level, Idzlibheaders::TZStreamType StreamType);
extern PACKAGE System::UnicodeString __fastcall CompressString(const System::UnicodeString InString, TCompressionLevel level, Idzlibheaders::TZStreamType StreamType);
extern PACKAGE void __fastcall DecompressBuf(const void * InBuf, int InBytes, int OutEstimate, /* out */ void * &OutBuf, /* out */ int &OutBytes);
extern PACKAGE void __fastcall DecompressToUserBuf(const void * InBuf, int InBytes, const void * OutBuf, int BufSize);

}	/* namespace Idzlib */
using namespace Idzlib;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdzlibHPP
