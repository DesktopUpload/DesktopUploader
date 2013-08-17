// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftpcommon.pas' rev: 20.00

#ifndef IdftpcommonHPP
#define IdftpcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftpcommon
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdFTPTransferType { ftASCII, ftBinary };
#pragma option pop

#pragma option push -b-
enum TIdFTPDataStructure { dsFile, dsRecord, dsPage };
#pragma option pop

#pragma option push -b-
enum TIdFTPTransferMode { dmStream, dmDeflate };
#pragma option pop

#pragma option push -b-
enum TIdFTPDataPortSecurity { ftpdpsClear, ftpdpsPrivate };
#pragma option pop

typedef StaticArray<System::UnicodeString, 4> Idftpcommon__1;

#pragma option push -b-
enum TIdVSEPQDisposition { IdPQAppendable, IdPQProcessAndDelete, IdPQHoldUntilReleased, IdPQProcessAndKeep, IdPQLeaveUntilReleased, IdPQErrorHoldUntilDK, IdPQGetOrErrorHoldUntilDK, IdPQJobProcessing, IdPQSpoolOutputToInputD, IdPQSurpressOutputSpooling, IdPQSpoolOutputToTape };
#pragma option pop

typedef StaticArray<System::UnicodeString, 6> Idftpcommon__2;

typedef StaticArray<System::UnicodeString, 4> Idftpcommon__3;

typedef StaticArray<System::UnicodeString, 2> Idftpcommon__4;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Idftpcommon__1 TLS_AUTH_NAMES;
#define SCCN_FEAT L"SSCN"
#define SSCN_ON L"SSCN ON"
#define SSCN_OFF L"SSCN OFF"
static const Byte SSCN_OK_REPLY = 0xc8;
static const Word SSCN_ERR_NEGOTIATION_REPLY = 0x1a5;
static const WideChar PATH_FILENAME_SEP_UNIX = (WideChar)(0x2f);
static const WideChar PATH_FILENAME_SEP_DOS = (WideChar)(0x5c);
static const WideChar PATH_FILENAME_SEP_VMS = (WideChar)(0x5d);
static const WideChar PATH_SUBDIR_SEP_UNIX = (WideChar)(0x2f);
static const WideChar PATH_SUBDIR_SEP_DOS = (WideChar)(0x5c);
static const WideChar PATH_SUBDIR_SEP_VMS = (WideChar)(0x2e);
#define PATH_DEVICE_SEP_UNIX L""
static const WideChar PATH_DEVICE_SEP_DOS = (WideChar)(0x3a);
#define PATH_DEVICE_SEP_VMS L":["
static const WideChar UNIX_ALL_FILES = (WideChar)(0x2a);
#define MS_DOS_ALL_FILES L"*.*"
#define VMS_ALL_FILES L"*.*;*"
static const WideChar CUR_DIR = (WideChar)(0x2e);
#define PARENT_DIR L".."
#define VMS_RELPATH_PREFIX L"[."
#define MS_DOS_CURDIR L".\\"
#define UNIX_CURDIR L"./"
static const Word UNIX_DIR_SIZE = 0x200;
static const Word VMS_BLOCK_SIZE = 0x200;
static const Word EPLF_BASE_DATE = 0x63e1;
static const ShortInt DEF_ZLIB_COMP_LEVEL = 0x7;
static const ShortInt DEF_ZLIB_WINDOW_BITS = 0xf;
static const ShortInt DEF_ZLIB_MEM_LEVEL = 0x8;
static const ShortInt DEF_ZLIB_STRATAGY = 0x0;
static const ShortInt DEF_ZLIB_METHOD = 0x8;
extern PACKAGE Idftpcommon__2 VSERootDirItemTypes;
extern PACKAGE Idftpcommon__3 MVS_JES_Status;
extern PACKAGE StaticArray<System::WideChar, 11> VSE_PowerQueue_Dispositions;
extern PACKAGE Idftpcommon__4 UnitreeStoreTypes;
#define UNIX_LINKTO_SYM L" -> "
#define CDATE_PART_SEP L"/-"
static const Word Id__S_ISUID = 0x800;
static const Word Id__S_ISGID = 0x400;
static const Word Id__S_ISVTX = 0x200;
static const Word Id__S_IREAD = 0x100;
static const Byte Id__S_IWRITE = 0x80;
static const ShortInt Id__S_IEXEC = 0x40;
static const Word IdS_ISUID = 0x800;
static const Word IdS_ISGID = 0x400;
static const Word IdS_ISVTX = 0x200;
static const Word IdS_IRUSR = 0x100;
static const Byte IdS_IWUSR = 0x80;
static const ShortInt IdS_IXUSR = 0x40;
static const Word IdS_IRWXU = 0x1c0;
static const Word IdS_IREAD = 0x100;
static const Byte IdS_IWRITE = 0x80;
static const ShortInt IdS_IEXEC = 0x40;
static const ShortInt IdS_IRGRP = 0x20;
static const ShortInt IdS_IWGRP = 0x10;
static const ShortInt IdS_IXGRP = 0x8;
static const ShortInt IdS_IRWXG = 0x38;
static const ShortInt IdS_IROTH = 0x4;
static const ShortInt IdS_IWOTH = 0x2;
static const ShortInt IdS_IXOTH = 0x1;
static const ShortInt IdS_IRWXO = 0x7;
static const WideChar KoreanTotal = (WideChar)(0xcd1d);
static const WideChar KoreanMonth = (WideChar)(0xc6d4);
static const WideChar KoreanDay = (WideChar)(0xc77c);
static const WideChar KoreanEUCMonth = (WideChar)(0xbff9);
#define ChineseTotal L"??"
static const WideChar ChineseMonth = (WideChar)(0x6708);
static const WideChar ChineseDay = (WideChar)(0x65e5);
static const WideChar ChineseYear = (WideChar)(0x5e74);
#define JapaneseTotal L"??"
static const WideChar JapaneseMonth = (WideChar)(0x8c8e);
static const WideChar JapaneseDay = (WideChar)(0x93fa);
static const WideChar JapaneseYear = (WideChar)(0x944e);
extern PACKAGE void __fastcall DeleteSuffix(System::UnicodeString &VStr, const System::UnicodeString ASuffix);
extern PACKAGE System::UnicodeString __fastcall StripSpaces(const System::UnicodeString AString, const unsigned ASpaces);
extern PACKAGE System::UnicodeString __fastcall StripPath(const System::UnicodeString AFileName, const System::UnicodeString APathDelim = L"/");
extern PACKAGE int __fastcall CharsInStr(const System::WideChar ASearchChar, const System::UnicodeString AString);
extern PACKAGE int __fastcall PatternsInStr(const System::UnicodeString ASearchPattern, const System::UnicodeString AString);
extern PACKAGE System::UnicodeString __fastcall UnfoldLines(const System::UnicodeString AData, int ALine, Classes::TStrings* AStrings);
extern PACKAGE System::UnicodeString __fastcall StrPart(System::UnicodeString &AInput, const int AMaxLength, const bool ADelete = true);
extern PACKAGE System::UnicodeString __fastcall FetchLength(System::UnicodeString &AInput, const int AMaxLength, const System::UnicodeString ADelim = L" ", const bool ADelete = true, const bool ACaseSensitive = true);
extern PACKAGE bool __fastcall IsLineStr(const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall FindDelimInNumbers(const System::UnicodeString AData);
extern PACKAGE int __fastcall ExtractNumber(const System::UnicodeString AData, const bool ARetZero = true);
extern PACKAGE System::UnicodeString __fastcall StripNo(const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall IndyGetFilePath(const System::UnicodeString AFileName);
extern PACKAGE System::UnicodeString __fastcall IndyGetFileName(const System::UnicodeString AFileName);
extern PACKAGE bool __fastcall IndyIsRelativePath(const System::UnicodeString APathName);
extern PACKAGE System::UnicodeString __fastcall IndyGetFileExt(const System::UnicodeString AFileName);
extern PACKAGE System::UnicodeString __fastcall StripInitPathDelim(const System::UnicodeString AStr);
extern PACKAGE bool __fastcall IsNavPath(const System::UnicodeString APath);
extern PACKAGE System::UnicodeString __fastcall RemoveDuplicatePathSyms(System::UnicodeString APath);
extern PACKAGE System::UnicodeString __fastcall UnixPathToDOSPath(const System::UnicodeString APath);
extern PACKAGE System::UnicodeString __fastcall DOSPathToUnixPath(const System::UnicodeString APath);
extern PACKAGE bool __fastcall IsSubDirContentsBanner(const System::UnicodeString AData);
extern PACKAGE bool __fastcall IsTotalLine(const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall UnquotedStr(const System::UnicodeString AStr);
extern PACKAGE void __fastcall ParseQuotedArgs(const System::UnicodeString AParams, Classes::TStrings* AStrings);
extern PACKAGE System::TDateTime __fastcall EPLFDateToLocalDateTime(const System::UnicodeString AData);
extern PACKAGE System::TDateTime __fastcall EPLFDateToGMTDateTime(const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall GMTDateTimeToEPLFDate(const System::TDateTime ADateTime);
extern PACKAGE System::UnicodeString __fastcall LocalDateTimeToEPLFDate(const System::TDateTime ADateTime);
extern PACKAGE bool __fastcall IsValidTimeStamp(const System::UnicodeString AString);
extern PACKAGE bool __fastcall IsMDTMDate(const System::UnicodeString ADate);
extern PACKAGE System::TDateTime __fastcall MDTMOffset(const System::UnicodeString AOffs);
extern PACKAGE int __fastcall MinutesFromGMT(void);
extern PACKAGE System::UnicodeString __fastcall FTPDateTimeToMDTMD(const System::TDateTime ATimeStamp, const bool AIncludeMSecs = true, const bool AIncludeGMTOffset = true);
extern PACKAGE System::TDateTime __fastcall FTPMDTMToGMTDateTime(const System::UnicodeString ATimeStamp);
extern PACKAGE bool __fastcall IsYYYYMMDD(const System::UnicodeString AData);
extern PACKAGE bool __fastcall IsDDMonthYY(const System::UnicodeString AData, const System::UnicodeString ADelim);
extern PACKAGE bool __fastcall IsMMDDYY(const System::UnicodeString AData, const System::UnicodeString ADelim);
extern PACKAGE int __fastcall Y2Year(const int AYear);
extern PACKAGE System::TDateTime __fastcall DateYYMMDD(const System::UnicodeString AData);
extern PACKAGE System::TDateTime __fastcall DateYYStrMonthDD(const System::UnicodeString AData, const System::UnicodeString ADelim = L"-");
extern PACKAGE System::TDateTime __fastcall DateStrMonthDDYY(const System::UnicodeString AData, const System::UnicodeString ADelim = L"-", const bool AAddMissingYear = false);
extern PACKAGE System::TDateTime __fastcall DateDDStrMonthYY(const System::UnicodeString AData, const System::UnicodeString ADelim = L"-");
extern PACKAGE System::TDateTime __fastcall DateMMDDYY(const System::UnicodeString AData);
extern PACKAGE System::TDateTime __fastcall TimeHHMMSS(const System::UnicodeString AData);
extern PACKAGE bool __fastcall IsIn6MonthWindow(const System::TDateTime AMDate);
extern PACKAGE unsigned __fastcall AddMissingYear(const unsigned ADay, const unsigned AMonth);
extern PACKAGE bool __fastcall IsHHMMSS(const System::UnicodeString AData, const System::UnicodeString ADelim);
extern PACKAGE System::TDateTime __fastcall MVSDate(const System::UnicodeString AData);
extern PACKAGE System::TDateTime __fastcall AS400Date(const System::UnicodeString AData);
extern PACKAGE bool __fastcall IsValidUnixPerms(System::UnicodeString AData, const bool AStrict = false);
extern PACKAGE bool __fastcall IsUnixLsErr(const System::UnicodeString AData);
extern PACKAGE bool __fastcall IsUnixHiddenFile(const System::UnicodeString AFileName);
extern PACKAGE bool __fastcall IsUnixExec(const System::UnicodeString LUPer, const System::UnicodeString LGPer, const System::UnicodeString LOPer);
extern PACKAGE unsigned __fastcall PermStringToModeBits(const System::UnicodeString APerms);
extern PACKAGE System::UnicodeString __fastcall ModeBitsToPermString(const unsigned AMode);
extern PACKAGE int __fastcall ModeBitsToChmodNo(const unsigned AMode);
extern PACKAGE unsigned __fastcall ChmodNoToModeBits(const unsigned AModVal);
extern PACKAGE void __fastcall ChmodNoToPerms(const int AChmodNo, System::UnicodeString &VPermissions)/* overload */;
extern PACKAGE void __fastcall ChmodNoToPerms(const int AChmodNo, System::UnicodeString &VUser, System::UnicodeString &VGroup, System::UnicodeString &VOther)/* overload */;
extern PACKAGE int __fastcall PermsToChmodNo(const System::UnicodeString AUser, const System::UnicodeString AGroup, const System::UnicodeString AOther);
extern PACKAGE bool __fastcall IsNovelPSPattern(const System::UnicodeString AStr);
extern PACKAGE bool __fastcall IsValidNovellPermissionStr(const System::UnicodeString AStr);
extern PACKAGE System::UnicodeString __fastcall ExtractNovellPerms(const System::UnicodeString AData);
extern PACKAGE bool __fastcall ExcludeQVNET(const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall ExtractQVNETFileName(const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall ExtractRecFormat(const System::UnicodeString ARecFM);
extern PACKAGE TIdVSEPQDisposition __fastcall DispositionCodeToTIdVSEPQDisposition(const System::WideChar ADisp);
extern PACKAGE System::WideChar __fastcall TIdVSEPQDispositionDispositionCode(const TIdVSEPQDisposition ADisp);
extern PACKAGE bool __fastcall IsVMBFS(System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall ParseFacts(System::UnicodeString AData, Classes::TStrings* AResults, const System::UnicodeString AFactDelim = L";", const System::UnicodeString ANameDelim = L" ");
extern PACKAGE bool __fastcall IsValidSterCommFlags(const System::UnicodeString AString);
extern PACKAGE bool __fastcall IsValidSterCommProt(const System::UnicodeString AString);
extern PACKAGE bool __fastcall IsValidSterCommData(const System::UnicodeString AString);

}	/* namespace Idftpcommon */
using namespace Idftpcommon;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftpcommonHPP
