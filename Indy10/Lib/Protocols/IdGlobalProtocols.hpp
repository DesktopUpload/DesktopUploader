// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idglobalprotocols.pas' rev: 20.00

#ifndef IdglobalprotocolsHPP
#define IdglobalprotocolsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Idcharsets.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idglobalprotocols
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<System::UnicodeString, 7> Idglobalprotocols__1;

typedef StaticArray<System::UnicodeString, 12> Idglobalprotocols__2;

typedef System::UnicodeString TIdFileName;

typedef System::UnicodeString __fastcall (__closure *TIdReadLnFunction)(void);

typedef void __fastcall (*TStringEvent)(Classes::TComponent* ASender, const System::UnicodeString AString);

class DELPHICLASS TIdMimeTable;
class PASCALIMPLEMENTATION TIdMimeTable : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FLoadTypesFromOS;
	Classes::TNotifyEvent FOnBuildCache;
	Classes::TStrings* FMIMEList;
	Classes::TStrings* FFileExt;
	virtual void __fastcall BuildDefaultCache(void);
	
public:
	__property bool LoadTypesFromOS = {read=FLoadTypesFromOS, write=FLoadTypesFromOS, nodefault};
	virtual void __fastcall BuildCache(void);
	void __fastcall AddMimeType(const System::UnicodeString Ext, const System::UnicodeString MIMEType, const bool ARaiseOnError = true);
	System::UnicodeString __fastcall GetFileMIMEType(const System::UnicodeString AFileName);
	System::UnicodeString __fastcall GetDefaultFileExt(const System::UnicodeString MIMEType);
	void __fastcall LoadFromStrings(const Classes::TStrings* AStrings, const System::WideChar MimeSeparator = (System::WideChar)(0x3d));
	void __fastcall SaveToStrings(const Classes::TStrings* AStrings, const System::WideChar MimeSeparator = (System::WideChar)(0x3d));
	__fastcall virtual TIdMimeTable(const bool AutoFill);
	__fastcall virtual ~TIdMimeTable(void);
	__property Classes::TNotifyEvent OnBuildCache = {read=FOnBuildCache, write=FOnBuildCache};
};


class DELPHICLASS TIdInterfacedObject;
class PASCALIMPLEMENTATION TIdInterfacedObject : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	HIDESBASE int __fastcall _AddRef(void);
	HIDESBASE int __fastcall _Release(void);
public:
	/* TObject.Create */ inline __fastcall TIdInterfacedObject(void) : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdInterfacedObject(void) { }
	
};


#pragma option push -b-
enum TIdWin32Type { Win32s, WindowsNT40PreSP6Workstation, WindowsNT40PreSP6Server, WindowsNT40PreSP6AdvancedServer, WindowsNT40Workstation, WindowsNT40Server, WindowsNT40AdvancedServer, Windows95, Windows95OSR2, Windows98, Windows98SE, Windows2000Pro, Windows2000Server, Windows2000AdvancedServer, WindowsMe, WindowsXPPro, Windows2003Server, Windows2003AdvancedServer };
#pragma option pop

class DELPHICLASS EIdExtensionAlreadyExists;
class PASCALIMPLEMENTATION EIdExtensionAlreadyExists : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdExtensionAlreadyExists(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdExtensionAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdExtensionAlreadyExists(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdExtensionAlreadyExists(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdExtensionAlreadyExists(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdExtensionAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdExtensionAlreadyExists(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdExtensionAlreadyExists(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdExtensionAlreadyExists(void) { }
	
};


typedef DynamicArray<System::UnicodeString> Idglobalprotocols__6;

typedef DynamicArray<System::UnicodeString> Idglobalprotocols__7;

//-- var, const, procedure ---------------------------------------------------
#define LWS L"	 "
extern PACKAGE Idglobalprotocols__1 wdays;
extern PACKAGE Idglobalprotocols__2 monthnames;
extern PACKAGE Idglobalprotocols__6 IndyFalseBoolStrs;
extern PACKAGE Idglobalprotocols__7 IndyTrueBoolStrs;
extern PACKAGE System::TDateTime UNIXSTARTDATE;
static const ShortInt TIME_BASEDATE = 0x2;
#define HexNumbers L"01234567890ABCDEF"
#define BinNumbers L"01"
extern PACKAGE System::UnicodeString __fastcall IndyWrapText(const System::UnicodeString ALine, const System::UnicodeString ABreakStr, const System::UnicodeString ABreakChars, int MaxCol);
extern PACKAGE int __fastcall IndyCurrentYear(void);
extern PACKAGE System::UnicodeString __fastcall CharRange(const System::WideChar AMin, const System::WideChar AMax);
extern PACKAGE bool __fastcall StartsWith(const System::UnicodeString ANSIStr, const System::UnicodeString APattern);
extern PACKAGE System::TDateTime __fastcall UnixDateTimeToDelphiDateTime(unsigned UnixDateTime);
extern PACKAGE unsigned __fastcall DateTimeToUnix(System::TDateTime ADateTime);
extern PACKAGE void __fastcall CopyBytesToHostWord(const Sysutils::TBytes ASource, const int ASourceIndex, System::Word &VDest);
extern PACKAGE void __fastcall CopyBytesToHostLongWord(const Sysutils::TBytes ASource, const int ASourceIndex, unsigned &VDest);
extern PACKAGE void __fastcall CopyTIdNetworkWord(const System::Word ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall CopyTIdNetworkLongWord(const unsigned ASource, Sysutils::TBytes &VDest, const int ADestIndex);
extern PACKAGE void __fastcall MoveChars(const System::ShortString &ASource, int ASourceStart, SmallString<255>  &ADest, const int ADest_Size, int ADestStart, int ALen);
extern PACKAGE System::UnicodeString __fastcall LongWordToFourChar(unsigned AValue);
extern PACKAGE void __fastcall WordToTwoBytes(System::Word AWord, Sysutils::TBytes ByteArray, int Index);
extern PACKAGE System::Word __fastcall StrToWord(const System::UnicodeString Value);
extern PACKAGE System::UnicodeString __fastcall WordToStr(const System::Word Value);
extern PACKAGE unsigned __fastcall OrdFourByteToLongWord(System::Byte AByte1, System::Byte AByte2, System::Byte AByte3, System::Byte AByte4);
extern PACKAGE void __fastcall LongWordToOrdFourByte(const unsigned AValue, System::Byte &VByte1, System::Byte &VByte2, System::Byte &VByte3, System::Byte &VByte4);
extern PACKAGE System::Word __fastcall TwoCharToWord(System::WideChar AChar1, System::WideChar AChar2);
extern PACKAGE TIdWin32Type __fastcall Win32Type(void);
extern PACKAGE int __fastcall CompareDateTime(const System::TDateTime ADateTime1, const System::TDateTime ADateTime2);
extern PACKAGE System::TDateTime __fastcall StrInternetToDateTime(System::UnicodeString Value);
extern PACKAGE System::TDateTime __fastcall FTPMLSToGMTDateTime(const System::UnicodeString ATimeStamp);
extern PACKAGE System::TDateTime __fastcall FTPMLSToLocalDateTime(const System::UnicodeString ATimeStamp);
extern PACKAGE System::UnicodeString __fastcall FTPGMTDateTimeToMLS(const System::TDateTime ATimeStamp, const bool AIncludeMSecs = true);
extern PACKAGE System::UnicodeString __fastcall FTPLocalDateTimeToMLS(const System::TDateTime ATimeStamp, const bool AIncludeMSecs = true);
extern PACKAGE Classes::TStrings* __fastcall BreakApart(System::UnicodeString BaseString, System::UnicodeString BreakString, Classes::TStrings* StringList);
extern PACKAGE void __fastcall CommaSeparatedToStringList(Classes::TStrings* AList, const System::UnicodeString Value);
extern PACKAGE bool __fastcall CopyFileTo(const System::UnicodeString Source, const System::UnicodeString Destination);
extern PACKAGE System::UnicodeString __fastcall MakeTempFilename(const System::UnicodeString APath = L"");
extern PACKAGE System::UnicodeString __fastcall GetUniqueFileName(const System::UnicodeString APath, const System::UnicodeString APrefix, const System::UnicodeString AExt);
extern PACKAGE int __fastcall RPos(const System::UnicodeString ASub, const System::UnicodeString AIn, int AStart = 0xffffffff);
extern PACKAGE __int64 __fastcall FileSizeByName(const System::UnicodeString AFilename);
extern PACKAGE System::TDateTime __fastcall GetGMTDateByName(const System::UnicodeString AFileName);
extern PACKAGE System::UnicodeString __fastcall RightStr(const System::UnicodeString AStr, const int Len);
extern PACKAGE System::TDateTime __fastcall TimeZoneBias(void);
extern PACKAGE bool __fastcall IndyStrToBool(const System::UnicodeString AString);
extern PACKAGE bool __fastcall IndySetLocalTime(System::TDateTime Value);
extern PACKAGE System::Byte __fastcall StrToDay(const System::UnicodeString ADay);
extern PACKAGE System::Byte __fastcall StrToMonth(const System::UnicodeString AMonth);
extern PACKAGE System::UnicodeString __fastcall UpCaseFirst(const System::UnicodeString AStr);
extern PACKAGE System::UnicodeString __fastcall UpCaseFirstWord(const System::UnicodeString AStr);
extern PACKAGE bool __fastcall IsHex(const System::WideChar AChar);
extern PACKAGE bool __fastcall IsBinary(const System::WideChar AChar);
extern PACKAGE int __fastcall BinStrToInt(const System::UnicodeString ABinary);
extern PACKAGE System::UnicodeString __fastcall ABNFToText(const System::UnicodeString AText);
extern PACKAGE System::UnicodeString __fastcall GetMIMETypeFromFile(const System::UnicodeString AFile);
extern PACKAGE System::UnicodeString __fastcall GetMIMEDefaultFileExt(const System::UnicodeString MIMEType);
extern PACKAGE System::TDateTime __fastcall GmtOffsetStrToDateTime(const System::UnicodeString S);
extern PACKAGE System::TDateTime __fastcall GMTToLocalDateTime(System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall IntToBin(unsigned Value);
extern PACKAGE bool __fastcall IsValidIP(const System::UnicodeString S);
extern PACKAGE bool __fastcall IsHostname(const System::UnicodeString S);
extern PACKAGE bool __fastcall IsTopDomain(const System::UnicodeString AStr);
extern PACKAGE bool __fastcall IsDomain(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall DomainName(const System::UnicodeString AHost);
extern PACKAGE bool __fastcall IsFQDN(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall PadString(const System::UnicodeString AString, const int ALen, const System::WideChar AChar);
extern PACKAGE System::UnicodeString __fastcall ProcessPath(const System::UnicodeString ABasePath, const System::UnicodeString APath, const System::UnicodeString APathDelim = L"/");
extern PACKAGE System::UnicodeString __fastcall EnsureMsgIDBrackets(const System::UnicodeString AMsgID);
extern PACKAGE System::UnicodeString __fastcall ExtractHeaderItem(const System::UnicodeString AHeaderLine);
extern PACKAGE System::UnicodeString __fastcall ExtractHeaderSubItem(const System::UnicodeString AHeaderLine, const System::UnicodeString ASubItem);
extern PACKAGE System::UnicodeString __fastcall ReplaceHeaderSubItem(const System::UnicodeString AHeaderLine, const System::UnicodeString ASubItem, const System::UnicodeString AValue);
extern PACKAGE __int64 __fastcall GetClockValue(void);
extern PACKAGE unsigned __fastcall ROL(const unsigned AVal, System::Byte AShift);
extern PACKAGE unsigned __fastcall ROR(const unsigned AVal, System::Byte AShift);
extern PACKAGE System::UnicodeString __fastcall IndyComputerName();
extern PACKAGE Idcharsets::TIdCharSet __fastcall IdGetDefaultCharSet(void);
extern PACKAGE System::UnicodeString __fastcall RemoveHeaderEntry(const System::UnicodeString AHeader, const System::UnicodeString AEntry);
extern PACKAGE System::UnicodeString __fastcall RemoveHeaderEntries(const System::UnicodeString AHeader, System::UnicodeString *AEntries, const int AEntries_Size);
extern PACKAGE int __fastcall FindFirstOf(const System::UnicodeString AFind, const System::UnicodeString AText, const int ALength = 0xffffffff, const int AStartPos = 0x1);
extern PACKAGE int __fastcall FindFirstNotOf(const System::UnicodeString AFind, const System::UnicodeString AText, const int ALength = 0xffffffff, const int AStartPos = 0x1);
extern PACKAGE System::UnicodeString __fastcall TrimAllOf(const System::UnicodeString ATrim, const System::UnicodeString AText);
extern PACKAGE Sysutils::TEncoding* __fastcall ContentTypeToEncoding(const System::UnicodeString AContentType);
extern PACKAGE Sysutils::TEncoding* __fastcall CharsetToEncoding(const System::UnicodeString ACharset);
extern PACKAGE System::UnicodeString __fastcall ReadStringAsContentType(Classes::TStream* AStream, const System::UnicodeString AContentType);
extern PACKAGE void __fastcall ReadStringsAsContentType(Classes::TStream* AStream, Classes::TStrings* AStrings, const System::UnicodeString AContentType);
extern PACKAGE System::UnicodeString __fastcall ReadStringAsCharset(Classes::TStream* AStream, const System::UnicodeString ACharset);
extern PACKAGE void __fastcall ReadStringsAsCharset(Classes::TStream* AStream, Classes::TStrings* AStrings, const System::UnicodeString ACharset);

}	/* namespace Idglobalprotocols */
using namespace Idglobalprotocols;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdglobalprotocolsHPP
