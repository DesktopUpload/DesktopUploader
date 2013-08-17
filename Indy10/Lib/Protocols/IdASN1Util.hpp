// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idasn1util.pas' rev: 20.00

#ifndef Idasn1utilHPP
#define Idasn1utilHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idasn1util
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const ShortInt ASN1_INT = 0x2;
static const ShortInt ASN1_OCTSTR = 0x4;
static const ShortInt ASN1_NULL = 0x5;
static const ShortInt ASN1_OBJID = 0x6;
static const ShortInt ASN1_SEQ = 0x30;
static const ShortInt ASN1_IPADDR = 0x40;
static const ShortInt ASN1_COUNTER = 0x41;
static const ShortInt ASN1_GAUGE = 0x42;
static const ShortInt ASN1_TIMETICKS = 0x43;
static const ShortInt ASN1_OPAQUE = 0x44;
extern PACKAGE System::UnicodeString __fastcall ASNEncOIDItem(int Value);
extern PACKAGE int __fastcall ASNDecOIDItem(int &Start, const System::UnicodeString Buffer);
extern PACKAGE System::UnicodeString __fastcall ASNEncLen(int Len);
extern PACKAGE int __fastcall ASNDecLen(int &Start, const System::UnicodeString Buffer);
extern PACKAGE System::UnicodeString __fastcall ASNEncInt(int Value);
extern PACKAGE System::UnicodeString __fastcall ASNEncUInt(int Value);
extern PACKAGE System::UnicodeString __fastcall ASNObject(const System::UnicodeString Data, int ASNType);
extern PACKAGE System::UnicodeString __fastcall ASNItem(int &Start, const System::UnicodeString Buffer, int &ValueType);
extern PACKAGE System::UnicodeString __fastcall MibToId(System::UnicodeString Mib);
extern PACKAGE System::UnicodeString __fastcall IdToMib(const System::UnicodeString Id);
extern PACKAGE System::UnicodeString __fastcall IntMibToStr(const System::UnicodeString Value);

}	/* namespace Idasn1util */
using namespace Idasn1util;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idasn1utilHPP
