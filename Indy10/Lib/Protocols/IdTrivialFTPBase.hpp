// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtrivialftpbase.pas' rev: 20.00

#ifndef IdtrivialftpbaseHPP
#define IdtrivialftpbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtrivialftpbase
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdTFTPMode { tfNetAscii, tfOctet };
#pragma option pop

typedef SmallString<2>  WordStr;

//-- var, const, procedure ---------------------------------------------------
static const ShortInt TFTP_RRQ = 0x1;
static const ShortInt TFTP_WRQ = 0x2;
static const ShortInt TFTP_DATA = 0x3;
static const ShortInt TFTP_ACK = 0x4;
static const ShortInt TFTP_ERROR = 0x5;
static const ShortInt TFTP_OACK = 0x6;
static const Word MaxWord = 0xffff;
static const ShortInt hdrsize = 0x4;
#define sBlockSize L"blksize"
static const ShortInt ErrUndefined = 0x0;
static const ShortInt ErrFileNotFound = 0x1;
static const ShortInt ErrAccessViolation = 0x2;
static const ShortInt ErrAllocationExceeded = 0x3;
static const ShortInt ErrIllegalOperation = 0x4;
static const ShortInt ErrUnknownTransferID = 0x5;
static const ShortInt ErrFileAlreadyExists = 0x6;
static const ShortInt ErrNoSuchUser = 0x7;
static const ShortInt ErrOptionNegotiationFailed = 0x8;
extern PACKAGE System::UnicodeString __fastcall MakeAckPkt(const System::Word BlockNumber);
extern PACKAGE void __fastcall SendError(Idudpbase::TIdUDPBase* UDPBase, System::UnicodeString APeerIP, const System::Word APort, const System::Word ErrNumber, System::UnicodeString ErrorString)/* overload */;
extern PACKAGE void __fastcall SendError(Idudpclient::TIdUDPClient* UDPClient, const System::Word ErrNumber, System::UnicodeString ErrorString)/* overload */;
extern PACKAGE void __fastcall SendError(Idudpbase::TIdUDPBase* UDPBase, System::UnicodeString APeerIP, const System::Word APort, Sysutils::Exception* E)/* overload */;
extern PACKAGE void __fastcall SendError(Idudpclient::TIdUDPClient* UDPClient, Sysutils::Exception* E)/* overload */;

}	/* namespace Idtrivialftpbase */
using namespace Idtrivialftpbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtrivialftpbaseHPP
