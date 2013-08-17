// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idglobal.pas' rev: 20.00

#ifndef IdglobalHPP
#define IdglobalHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Syncobjs.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
// These are for backwards compatibility with past Indy 10 releases
#define enDefault ( TIdTextEncoding* )NULL
#define en8Bit Indy8BitEncoding(true)
#define en7Bit TIdTextEncoding::ASCII
#define enUTF8 TIdTextEncoding::UTF8

namespace Idglobal
{
    struct TIdIPv6Address
    {
        Word data[8];
        Word& operator[](int index) { return data[index]; }
        const Word& operator[](int index) const { return data[index]; }
        operator const Word*() const { return data; }
        operator Word*() { return data; }
    };
}

namespace Idglobal
{
//-- type declarations -------------------------------------------------------
typedef unsigned TIdPID;

typedef unsigned TIdThreadId;

typedef unsigned TIdThreadHandle;

typedef Classes::TThreadPriority TIdThreadPriority;

typedef Sysutils::TBytes TIdBytes;

typedef Sysutils::TCharArray TIdWideChars;

typedef int PtrInt;

typedef unsigned PtrUInt;

typedef __int64 TIdStreamSize;

typedef Sysutils::TEncoding TIdTextEncoding;

class DELPHICLASS TIdAppendFileStream;
class PASCALIMPLEMENTATION TIdAppendFileStream : public Classes::TFileStream
{
	typedef Classes::TFileStream inherited;
	
public:
	__fastcall TIdAppendFileStream(const System::UnicodeString AFile);
public:
	/* TFileStream.Destroy */ inline __fastcall virtual ~TIdAppendFileStream(void) { }
	
};


class DELPHICLASS TIdReadFileExclusiveStream;
class PASCALIMPLEMENTATION TIdReadFileExclusiveStream : public Classes::TFileStream
{
	typedef Classes::TFileStream inherited;
	
public:
	__fastcall TIdReadFileExclusiveStream(const System::UnicodeString AFile);
public:
	/* TFileStream.Destroy */ inline __fastcall virtual ~TIdReadFileExclusiveStream(void) { }
	
};


class DELPHICLASS TIdReadFileNonExclusiveStream;
class PASCALIMPLEMENTATION TIdReadFileNonExclusiveStream : public Classes::TFileStream
{
	typedef Classes::TFileStream inherited;
	
public:
	__fastcall TIdReadFileNonExclusiveStream(const System::UnicodeString AFile);
public:
	/* TFileStream.Destroy */ inline __fastcall virtual ~TIdReadFileNonExclusiveStream(void) { }
	
};


class DELPHICLASS TIdFileCreateStream;
class PASCALIMPLEMENTATION TIdFileCreateStream : public Classes::TFileStream
{
	typedef Classes::TFileStream inherited;
	
public:
	__fastcall TIdFileCreateStream(const System::UnicodeString AFile);
public:
	/* TFileStream.Destroy */ inline __fastcall virtual ~TIdFileCreateStream(void) { }
	
};


class DELPHICLASS TIdLocalEvent;
class PASCALIMPLEMENTATION TIdLocalEvent : public Syncobjs::TEvent
{
	typedef Syncobjs::TEvent inherited;
	
public:
	__fastcall TIdLocalEvent(const bool AInitialState, const bool AManualReset);
	Syncobjs::TWaitResult __fastcall WaitForEver(void)/* overload */;
public:
	/* THandleObject.Destroy */ inline __fastcall virtual ~TIdLocalEvent(void) { }
	
};


class DELPHICLASS TIdCriticalSection;
class PASCALIMPLEMENTATION TIdCriticalSection : public Syncobjs::TCriticalSection
{
	typedef Syncobjs::TCriticalSection inherited;
	
public:
	/* TCriticalSection.Create */ inline __fastcall TIdCriticalSection(void) : Syncobjs::TCriticalSection() { }
	/* TCriticalSection.Destroy */ inline __fastcall virtual ~TIdCriticalSection(void) { }
	
};


typedef short *PShort;

class DELPHICLASS EIdCorruptServicesFile;
class PASCALIMPLEMENTATION EIdCorruptServicesFile : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdCorruptServicesFile(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdCorruptServicesFile(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdCorruptServicesFile(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdCorruptServicesFile(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdCorruptServicesFile(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCorruptServicesFile(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdCorruptServicesFile(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCorruptServicesFile(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdCorruptServicesFile(void) { }
	
};


class DELPHICLASS EIdEndOfStream;
class PASCALIMPLEMENTATION EIdEndOfStream : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdEndOfStream(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdEndOfStream(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdEndOfStream(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdEndOfStream(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdEndOfStream(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdEndOfStream(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdEndOfStream(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdEndOfStream(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdEndOfStream(void) { }
	
};


class DELPHICLASS EIdInvalidIPv6Address;
class PASCALIMPLEMENTATION EIdInvalidIPv6Address : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidIPv6Address(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidIPv6Address(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidIPv6Address(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidIPv6Address(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidIPv6Address(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidIPv6Address(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidIPv6Address(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidIPv6Address(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidIPv6Address(void) { }
	
};


class DELPHICLASS EIdNoEncodingSpecified;
class PASCALIMPLEMENTATION EIdNoEncodingSpecified : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNoEncodingSpecified(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNoEncodingSpecified(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNoEncodingSpecified(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNoEncodingSpecified(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNoEncodingSpecified(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNoEncodingSpecified(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNoEncodingSpecified(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNoEncodingSpecified(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNoEncodingSpecified(void) { }
	
};


class DELPHICLASS EIdFailedToRetreiveTimeZoneInfo;
class PASCALIMPLEMENTATION EIdFailedToRetreiveTimeZoneInfo : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFailedToRetreiveTimeZoneInfo(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFailedToRetreiveTimeZoneInfo(void) { }
	
};


typedef System::Word TIdPort;

#pragma option push -b-
enum TIdMaxLineAction { maException, maSplit };
#pragma option pop

#pragma option push -b-
enum TIdOSType { otUnknown, otUnix, otWindows, otDotNet };
#pragma option pop

#pragma option push -b-
enum TIdIPVersion { Id_IPv4, Id_IPv6 };
#pragma option pop

typedef int __fastcall (*TPosProc)(const System::UnicodeString substr, const System::UnicodeString str);

typedef System::WideChar * __fastcall (*TStrScanProc)(System::WideChar * Str, System::WideChar Chr);

#pragma option push -b-
enum TIdReuseSocket { rsOSDependent, rsTrue, rsFalse };
#pragma option pop

class DELPHICLASS TIdExtList;
class PASCALIMPLEMENTATION TIdExtList : public Classes::TList
{
	typedef Classes::TList inherited;
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TIdExtList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdExtList(void) : Classes::TList() { }
	
};


class DELPHICLASS TIdBaseStream;
class PASCALIMPLEMENTATION TIdBaseStream : public Classes::TStream
{
	typedef Classes::TStream inherited;
	
protected:
	virtual int __fastcall IdRead(Sysutils::TBytes &VBuffer, int AOffset, int ACount) = 0 ;
	virtual int __fastcall IdWrite(const Sysutils::TBytes ABuffer, int AOffset, int ACount) = 0 ;
	virtual __int64 __fastcall IdSeek(const __int64 AOffset, Classes::TSeekOrigin AOrigin) = 0 ;
	virtual void __fastcall IdSetSize(__int64 ASize) = 0 ;
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual __int64 __fastcall Seek(const __int64 Offset, Classes::TSeekOrigin Origin)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TIdBaseStream(void) : Classes::TStream() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdBaseStream(void) { }
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(int NewSize){ Classes::TStream::SetSize(NewSize); }
	
public:
	inline int __fastcall  Seek(int Offset, System::Word Origin){ return Classes::TStream::Seek(Offset, Origin); }
	
};


//-- var, const, procedure ---------------------------------------------------
#define gsIdVersion L"10.5.5"
#define gsIdProductName L"Indy"
static const WideChar LF = (WideChar)(0xa);
static const WideChar CR = (WideChar)(0xd);
#define EOL L"\r\n"
static const WideChar CHAR0 = (WideChar)(0x0);
static const WideChar BACKSPACE = (WideChar)(0x8);
static const WideChar TAB = (WideChar)(0x9);
static const WideChar CHAR32 = (WideChar)(0x20);
static const ShortInt IdTimeoutDefault = -1;
static const ShortInt IdTimeoutInfinite = -2;
static const WideChar IdFetchDelimDefault = (WideChar)(0x20);
static const bool IdFetchDeleteDefault = true;
static const bool IdFetchCaseSensitiveDefault = true;
#define IdWhiteSpace (Set<Byte, 0, 255> () << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 )
extern PACKAGE StaticArray<System::WideChar, 16> IdHexDigits;
extern PACKAGE StaticArray<System::WideChar, 8> IdOctalDigits;
#define IdHexPrefix L"0x"
static const ShortInt DEF_PORT_ANY = 0x0;
static const TIdOSType GOSType = (TIdOSType)(2);
static const WideChar GPathDelim = (WideChar)(0x5c);
static const unsigned Infinite = 0xffffffff;
static const TIdIPVersion ID_DEFAULT_IP_VERSION = (TIdIPVersion)(0);
static const Byte POWER_1 = 0xff;
static const Word POWER_2 = 0xffff;
static const int POWER_3 = 0xffffff;
static const unsigned POWER_4 = 0xffffffff;
extern PACKAGE TPosProc IndyPos;
extern PACKAGE void __fastcall EnsureEncoding(Sysutils::TEncoding* &VEncoding);
extern PACKAGE Sysutils::TEncoding* __fastcall Indy8BitEncoding(const bool AOwnedByIndy = true);
extern PACKAGE void __fastcall IndyRaiseLastError(void);
extern PACKAGE unsigned __fastcall InterlockedExchangeTHandle(unsigned &VTarget, const unsigned AValue);
extern PACKAGE void * __fastcall InterlockedCompareExchangePtr(void * &VTarget, const void * AValue, const void * Compare);
extern PACKAGE System::Word __fastcall HostToLittleEndian(const System::Word AValue)/* overload */;
extern PACKAGE unsigned __fastcall HostToLittleEndian(const unsigned AValue)/* overload */;
extern PACKAGE int __fastcall HostToLittleEndian(const int AValue)/* overload */;
extern PACKAGE System::Word __fastcall LittleEndianToHost(const System::Word AValue)/* overload */;
extern PACKAGE unsigned __fastcall LittleEndianToHost(const unsigned AValue)/* overload */;
extern PACKAGE int __fastcall LittleEndianToHost(const int AValue)/* overload */;
extern PACKAGE void __fastcall FillBytes(Sysutils::TBytes &VBytes, const int ACount, const System::Byte AValue);
extern PACKAGE bool __fastcall IsASCIILDH(const System::Byte AByte)/* overload */;
extern PACKAGE bool __fastcall IsASCIILDH(const Sysutils::TBytes ABytes)/* overload */;
extern PACKAGE bool __fastcall IsASCII(const System::Byte AByte)/* overload */;
extern PACKAGE bool __fastcall IsASCII(const Sysutils::TBytes ABytes)/* overload */;
extern PACKAGE bool __fastcall StartsWithACE(const Sysutils::TBytes ABytes);
extern PACKAGE int __fastcall PosInSmallIntArray(const short ASearchInt, short const *AArray, const int AArray_Size);
extern PACKAGE int __fastcall PosInStrArray(const System::UnicodeString SearchStr, System::UnicodeString const *Contents, const int Contents_Size, const bool CaseSensitive = true);
extern PACKAGE System::UnicodeString __fastcall ByteToHex(const System::Byte AByte);
extern PACKAGE System::UnicodeString __fastcall LongWordToHex(const unsigned ALongWord);
extern PACKAGE System::UnicodeString __fastcall ToHex(const Sysutils::TBytes AValue, const int ACount = 0xffffffff, const int AIndex = 0x0)/* overload */;
extern PACKAGE System::UnicodeString __fastcall ToHex(unsigned const *AValue, const int AValue_Size)/* overload */;
extern PACKAGE System::UnicodeString __fastcall IPv4ToHex(const System::UnicodeString AIPAddress, const bool ADotted = false);
extern PACKAGE System::UnicodeString __fastcall ByteToOctal(const System::Byte AByte);
extern PACKAGE System::UnicodeString __fastcall IPv4ToOctal(const System::UnicodeString AIPAddress);
extern PACKAGE void __fastcall CopyTIdBytes(const Sysutils::TBytes ASource, const int ASourceIndex, Sysutils::TBytes &VDest, const int ADestIndex, const int ALength);
extern PACKAGE void __fastcall CopyTIdChar(const System::WideChar ASource, Sysutils::TBytes &VDest, const int ADestIndex, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
extern PACKAGE void __fastcall CopyTIdShort(const short ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdWord(const System::Word ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdLongWord(const unsigned ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdLongInt(const int ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdInt64(const __int64 ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdIPV6Address(System::Word const *ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdByteArray(System::Byte const *ASource, const int ASource_Size, const int ASourceIndex, System::Byte *VDest, const int VDest_Size, const int ADestIndex, const int ALength);
extern PACKAGE void __fastcall CopyTIdString(const System::UnicodeString ASource, Sysutils::TBytes &VDest, const int ADestIndex, const int ALength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE void __fastcall CopyTIdString(const System::UnicodeString ASource, const int ASourceIndex, Sysutils::TBytes &VDest, const int ADestIndex, const int ALength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE void __fastcall DebugOutput(const System::UnicodeString AText);
extern PACKAGE unsigned __fastcall CurrentThreadId(void);
extern PACKAGE unsigned __fastcall CurrentProcessId(void);
extern PACKAGE System::UnicodeString __fastcall Fetch(System::UnicodeString &AInput, const System::UnicodeString ADelim = L" ", const bool ADelete = true, const bool ACaseSensitive = true);
extern PACKAGE System::UnicodeString __fastcall FetchCaseInsensitive(System::UnicodeString &AInput, const System::UnicodeString ADelim = L" ", const bool ADelete = true);
extern PACKAGE unsigned __fastcall GetThreadHandle(Classes::TThread* AThread);
extern PACKAGE unsigned __fastcall Ticks(void);
extern PACKAGE unsigned __fastcall GetTickDiff(const unsigned AOldTickCount, const unsigned ANewTickCount);
extern PACKAGE System::UnicodeString __fastcall ServicesFilePath();
extern PACKAGE Classes::TList* __fastcall IdPorts(void);
extern PACKAGE int __fastcall iif(bool ATest, const int ATrue, const int AFalse)/* overload */;
extern PACKAGE System::UnicodeString __fastcall iif(bool ATest, const System::UnicodeString ATrue, const System::UnicodeString AFalse = L"")/* overload */;
extern PACKAGE bool __fastcall iif(bool ATest, const bool ATrue, const bool AFalse)/* overload */;
extern PACKAGE bool __fastcall InMainThread(void);
extern PACKAGE void __fastcall WriteMemoryStreamToStream(Classes::TMemoryStream* Src, Classes::TStream* Dest, __int64 Count);
extern PACKAGE bool __fastcall IsCurrentThread(Classes::TThread* AThread);
extern PACKAGE System::UnicodeString __fastcall MakeDWordIntoIPv4Address(const unsigned ADWord);
extern PACKAGE bool __fastcall IsAlpha(const System::WideChar AChar)/* overload */;
extern PACKAGE bool __fastcall IsAlpha(const System::UnicodeString AString, const int ALength = 0xffffffff, const int AIndex = 0x1)/* overload */;
extern PACKAGE bool __fastcall IsAlphaNumeric(const System::WideChar AChar)/* overload */;
extern PACKAGE bool __fastcall IsAlphaNumeric(const System::UnicodeString AString, const int ALength = 0xffffffff, const int AIndex = 0x1)/* overload */;
extern PACKAGE bool __fastcall IsOctal(const System::WideChar AChar)/* overload */;
extern PACKAGE bool __fastcall IsOctal(const System::UnicodeString AString, const int ALength = 0xffffffff, const int AIndex = 0x1)/* overload */;
extern PACKAGE bool __fastcall IsHexidecimal(const System::WideChar AChar)/* overload */;
extern PACKAGE bool __fastcall IsHexidecimal(const System::UnicodeString AString, const int ALength = 0xffffffff, const int AIndex = 0x1)/* overload */;
extern PACKAGE bool __fastcall IsNumeric(const System::UnicodeString AString)/* overload */;
extern PACKAGE bool __fastcall IsNumeric(const System::UnicodeString AString, const int ALength, const int AIndex = 0x1)/* overload */;
extern PACKAGE bool __fastcall IsNumeric(const System::WideChar AChar)/* overload */;
extern PACKAGE unsigned __fastcall IPv4MakeLongWordInRange(const __int64 AInt, const int A256Power);
extern PACKAGE unsigned __fastcall IPv4ToDWord(const System::UnicodeString AIPAddress)/* overload */;
extern PACKAGE unsigned __fastcall IPv4ToDWord(const System::UnicodeString AIPAddress, bool &VErr)/* overload */;
extern PACKAGE System::UnicodeString __fastcall IPv6AddressToStr(System::Word const *AValue);
extern PACKAGE System::UnicodeString __fastcall MakeCanonicalIPv4Address(const System::UnicodeString AAddr);
extern PACKAGE System::UnicodeString __fastcall MakeCanonicalIPv6Address(const System::UnicodeString AAddr);
extern PACKAGE void __fastcall IPv6ToIdIPv6Address(const System::UnicodeString AIPAddress, System::Word *VAddress)/* overload */;
extern PACKAGE void __fastcall IPv6ToIdIPv6Address(const System::UnicodeString AIPAddress, System::Word *VAddress, bool &VErr)/* overload */;
extern PACKAGE __int64 __fastcall IndyMax(const __int64 AValueOne, const __int64 AValueTwo)/* overload */;
extern PACKAGE int __fastcall IndyMax(const int AValueOne, const int AValueTwo)/* overload */;
extern PACKAGE System::Word __fastcall IndyMax(const System::Word AValueOne, const System::Word AValueTwo)/* overload */;
extern PACKAGE int __fastcall MemoryPos(const System::UnicodeString ASubStr, System::WideChar * MemBuff, int MemorySize);
extern PACKAGE int __fastcall IndyMin(const int AValueOne, const int AValueTwo)/* overload */;
extern PACKAGE __int64 __fastcall IndyMin(const __int64 AValueOne, const __int64 AValueTwo)/* overload */;
extern PACKAGE System::Word __fastcall IndyMin(const System::Word AValueOne, const System::Word AValueTwo)/* overload */;
extern PACKAGE unsigned __fastcall PosIdx(const System::UnicodeString ASubStr, const System::UnicodeString AStr, unsigned AStartPos = (unsigned)(0x0));
extern PACKAGE void __fastcall IndySetThreadPriority(Classes::TThread* AThread, const Classes::TThreadPriority APriority, const int APolicy = 0x80000001);
extern PACKAGE void __fastcall IndySleep(unsigned ATime);
extern PACKAGE void __fastcall SplitColumnsNoTrim(const System::UnicodeString AData, Classes::TStrings* AStrings, const System::UnicodeString ADelim = L" ");
extern PACKAGE void __fastcall SetThreadName(const System::UnicodeString AName);
extern PACKAGE void __fastcall SplitColumns(const System::UnicodeString AData, Classes::TStrings* AStrings, const System::UnicodeString ADelim = L" ");
extern PACKAGE void __fastcall ToDo(void);
extern PACKAGE int __fastcall IndyLength(const System::UnicodeString ABuffer, const int ALength = 0xffffffff, const int AIndex = 0x1)/* overload */;
extern PACKAGE int __fastcall IndyLength(const Sysutils::TBytes ABuffer, const int ALength = 0xffffffff, const int AIndex = 0x0)/* overload */;
extern PACKAGE __int64 __fastcall IndyLength(const Classes::TStream* ABuffer, const __int64 ALength = 0xffffffffffffffff)/* overload */;
extern PACKAGE System::UnicodeString __fastcall IndyFormat(const System::UnicodeString AFormat, System::TVarRec const *Args, const int Args_Size);
extern PACKAGE System::UnicodeString __fastcall DateTimeGMTToHttpStr(const System::TDateTime GMTValue);
extern PACKAGE System::UnicodeString __fastcall DateTimeGMTToCookieStr(const System::TDateTime GMTValue);
extern PACKAGE System::UnicodeString __fastcall LocalDateTimeToHttpStr(const System::TDateTime Value);
extern PACKAGE System::UnicodeString __fastcall LocalDateTimeToCookieStr(const System::TDateTime Value);
extern PACKAGE System::UnicodeString __fastcall DateTimeToInternetStr(const System::TDateTime Value, const bool AUseGMTStr = false);
extern PACKAGE System::UnicodeString __fastcall LocalDateTimeToGMT(const System::TDateTime Value, const bool AUseGMTStr = false);
extern PACKAGE System::UnicodeString __fastcall DateTimeToGmtOffSetStr(System::TDateTime ADateTime, const bool AUseGMTStr = false);
extern PACKAGE System::TDateTime __fastcall OffsetFromUTC(void);
extern PACKAGE System::UnicodeString __fastcall UTCOffsetToStr(const System::TDateTime AOffset, const bool AUseGMTStr = false);
extern PACKAGE System::UnicodeString __fastcall IndyIncludeTrailingPathDelimiter(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall IndyExcludeTrailingPathDelimiter(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall StringsReplace(const System::UnicodeString S, System::UnicodeString const *OldPattern, const int OldPattern_Size, System::UnicodeString const *NewPattern, const int NewPattern_Size);
extern PACKAGE System::UnicodeString __fastcall ReplaceOnlyFirst(const System::UnicodeString S, const System::UnicodeString OldPattern, const System::UnicodeString NewPattern);
extern PACKAGE int __fastcall IndyStrToInt(const System::UnicodeString S)/* overload */;
extern PACKAGE int __fastcall IndyStrToInt(const System::UnicodeString S, int ADefault)/* overload */;
extern PACKAGE int __fastcall CompareDate(const System::TDateTime D1, const System::TDateTime D2);
extern PACKAGE System::TDateTime __fastcall AddMSecToTime(const System::TDateTime ADateTime, const int AMSec);
extern PACKAGE System::TDateTime __fastcall IndyFileAge(const System::UnicodeString AFileName);
extern PACKAGE bool __fastcall IndyDirectoryExists(const System::UnicodeString ADirectory);
extern PACKAGE __int64 __fastcall IndyStrToInt64(const System::UnicodeString S, const __int64 ADefault)/* overload */;
extern PACKAGE __int64 __fastcall IndyStrToInt64(const System::UnicodeString S)/* overload */;
extern PACKAGE __int64 __fastcall IndyStrToStreamSize(const System::UnicodeString S, const __int64 ADefault)/* overload */;
extern PACKAGE __int64 __fastcall IndyStrToStreamSize(const System::UnicodeString S)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const System::UnicodeString AValue, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const System::UnicodeString AValue, const int ALength, const int AIndex = 0x1, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const System::WideChar AValue, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const __int64 AValue)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const int AValue)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const unsigned AValue)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const short AValue)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const System::Word AValue)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const System::Byte AValue)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall ToBytes(const Sysutils::TBytes AValue, const int ASize, const int AIndex = 0x0)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall RawToBytes(const void *AValue, const int ASize);
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const System::WideChar AValue, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const int AValue)/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const short AValue)/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const System::Word AValue)/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const System::Byte AValue)/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const unsigned AValue)/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const __int64 AValue)/* overload */;
extern PACKAGE void __fastcall ToBytesF(Sysutils::TBytes &Bytes, const Sysutils::TBytes AValue, const int ASize, const int AIndex = 0x0)/* overload */;
extern PACKAGE void __fastcall RawToBytesF(Sysutils::TBytes &Bytes, const void *AValue, const int ASize);
extern PACKAGE System::WideChar __fastcall BytesToChar(const Sysutils::TBytes AValue, const int AIndex = 0x0, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE int __fastcall BytesToChar(const Sysutils::TBytes AValue, System::WideChar &VChar, const int AIndex = 0x0, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE int __fastcall BytesToLongInt(const Sysutils::TBytes AValue, const int AIndex = 0x0);
extern PACKAGE __int64 __fastcall BytesToInt64(const Sysutils::TBytes AValue, const int AIndex = 0x0);
extern PACKAGE System::Word __fastcall BytesToWord(const Sysutils::TBytes AValue, const int AIndex = 0x0);
extern PACKAGE short __fastcall BytesToShort(const Sysutils::TBytes AValue, const int AIndex = 0x0);
extern PACKAGE System::UnicodeString __fastcall BytesToIPv4Str(const Sysutils::TBytes AValue, const int AIndex = 0x0);
extern PACKAGE void __fastcall BytesToIPv6(const Sysutils::TBytes AValue, System::Word *VAddress, const int AIndex = 0x0);
extern PACKAGE unsigned __fastcall BytesToLongWord(const Sysutils::TBytes AValue, const int AIndex = 0x0);
extern PACKAGE System::UnicodeString __fastcall BytesToString(const Sysutils::TBytes AValue, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE System::UnicodeString __fastcall BytesToString(const Sysutils::TBytes AValue, const int AStartIndex, const int ALength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE void __fastcall BytesToRaw(const Sysutils::TBytes AValue, void *VBuffer, const int ASize);
extern PACKAGE System::Word __fastcall TwoByteToWord(System::Byte AByte1, System::Byte AByte2);
extern PACKAGE System::UnicodeString __fastcall ReadStringFromStream(Classes::TStream* AStream, int ASize = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE __int64 __fastcall ReadTIdBytesFromStream(const Classes::TStream* AStream, Sysutils::TBytes &ABytes, const __int64 Count);
extern PACKAGE int __fastcall ReadCharFromStream(Classes::TStream* AStream, System::WideChar &VChar, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
extern PACKAGE void __fastcall WriteTIdBytesToStream(const Classes::TStream* AStream, const Sysutils::TBytes ABytes, const int ASize = 0xffffffff, const int AIndex = 0x0);
extern PACKAGE void __fastcall WriteStringToStream(Classes::TStream* AStream, const System::UnicodeString AStr, Sysutils::TEncoding* AEncoding)/* overload */;
extern PACKAGE void __fastcall WriteStringToStream(Classes::TStream* AStream, const System::UnicodeString AStr, const int ALength = 0xffffffff, const int AIndex = 0x1, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE void __fastcall AppendBytes(Sysutils::TBytes &VBytes, const Sysutils::TBytes AToAdd, const int AIndex = 0x0, const int ALength = 0xffffffff);
extern PACKAGE void __fastcall AppendByte(Sysutils::TBytes &VBytes, const System::Byte AByte);
extern PACKAGE void __fastcall AppendString(Sysutils::TBytes &VBytes, const System::UnicodeString AStr, const int ALength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
extern PACKAGE void __fastcall ExpandBytes(Sysutils::TBytes &VBytes, const int AIndex, const int ACount, const System::Byte AFillByte = (System::Byte)(0x0));
extern PACKAGE void __fastcall InsertBytes(Sysutils::TBytes &VBytes, const int ADestIndex, const Sysutils::TBytes ASource, const int ASourceIndex = 0x0);
extern PACKAGE void __fastcall InsertByte(Sysutils::TBytes &VBytes, const System::Byte AByte, const int AIndex);
extern PACKAGE void __fastcall RemoveBytes(Sysutils::TBytes &VBytes, const int ACount, const int AIndex = 0x0);
extern PACKAGE void __fastcall IdDelete(System::UnicodeString &s, int AOffset, int ACount);
extern PACKAGE void __fastcall IdInsert(const System::UnicodeString Source, System::UnicodeString &S, int Index);
extern PACKAGE bool __fastcall TextIsSame(const System::UnicodeString A1, const System::UnicodeString A2);
extern PACKAGE bool __fastcall TextStartsWith(const System::UnicodeString S, const System::UnicodeString SubS);
extern PACKAGE bool __fastcall TextEndsWith(const System::UnicodeString S, const System::UnicodeString SubS);
extern PACKAGE System::UnicodeString __fastcall IndyLowerCase(const System::UnicodeString A1);
extern PACKAGE System::UnicodeString __fastcall IndyUpperCase(const System::UnicodeString A1);
extern PACKAGE int __fastcall IndyCompareStr(const System::UnicodeString A1, const System::UnicodeString A2);
extern PACKAGE int __fastcall CharPosInSet(const System::UnicodeString AString, const int ACharPos, const System::UnicodeString ASet);
extern PACKAGE bool __fastcall CharIsInSet(const System::UnicodeString AString, const int ACharPos, const System::UnicodeString ASet);
extern PACKAGE bool __fastcall CharIsInEOL(const System::UnicodeString AString, const int ACharPos);
extern PACKAGE bool __fastcall CharEquals(const System::UnicodeString AString, const int ACharPos, const System::WideChar AValue);
extern PACKAGE int __fastcall ByteIndex(const System::Byte AByte, const Sysutils::TBytes ABytes, const int AStartIndex = 0x0);
extern PACKAGE int __fastcall ByteIdxInSet(const Sysutils::TBytes ABytes, const int AIndex, const Sysutils::TBytes ASet);
extern PACKAGE bool __fastcall ByteIsInSet(const Sysutils::TBytes ABytes, const int AIndex, const Sysutils::TBytes ASet);
extern PACKAGE bool __fastcall ByteIsInEOL(const Sysutils::TBytes ABytes, const int AIndex);
extern PACKAGE System::UnicodeString __fastcall ReadLnFromStream(Classes::TStream* AStream, int AMaxLineLength = 0xffffffff, bool AExceptionIfEOF = false, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE bool __fastcall ReadLnFromStream(Classes::TStream* AStream, System::UnicodeString &VLine, int AMaxLineLength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
extern PACKAGE bool __fastcall IndyRegisterExpectedMemoryLeak(void * AAddress);

}	/* namespace Idglobal */
using namespace Idglobal;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdglobalHPP
