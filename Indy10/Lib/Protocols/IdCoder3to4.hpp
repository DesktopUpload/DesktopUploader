// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoder3to4.pas' rev: 20.00

#ifndef Idcoder3to4HPP
#define Idcoder3to4HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoder3to4
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<System::Byte, 127> TIdDecodeTable;

class DELPHICLASS TIdEncoder3to4;
class PASCALIMPLEMENTATION TIdEncoder3to4 : public Idcoder::TIdEncoder
{
	typedef Idcoder::TIdEncoder inherited;
	
protected:
	System::AnsiString FCodingTable;
	char FFillChar;
	Sysutils::TBytes __fastcall InternalEncode(const Sysutils::TBytes ABuffer);
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrcStream, Classes::TStream* ADestStream, const int ABytes = 0xffffffff)/* overload */;
	
__published:
	__property System::AnsiString CodingTable = {read=FCodingTable};
	__property char FillChar = {read=FFillChar, write=FFillChar, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoder3to4(Classes::TComponent* AOwner)/* overload */ : Idcoder::TIdEncoder(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoder3to4(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline System::UnicodeString __fastcall  Encode(const System::UnicodeString AIn){ return Idcoder::TIdEncoder::Encode(AIn); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStrings* ADestStrings){ Idcoder::TIdEncoder::Encode(AIn, ADestStrings); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStream* ADestStream){ Idcoder::TIdEncoder::Encode(AIn, ADestStream); }
	inline System::UnicodeString __fastcall  Encode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff){ return Idcoder::TIdEncoder::Encode(ASrcStream, ABytes); }
	inline void __fastcall  Encode(Classes::TStream* ASrcStream, Classes::TStrings* ADestStrings, const int ABytes = 0xffffffff){ Idcoder::TIdEncoder::Encode(ASrcStream, ADestStrings, ABytes); }
	
};


typedef TMetaClass* TIdEncoder3to4Class;

class DELPHICLASS TIdDecoder4to3;
class PASCALIMPLEMENTATION TIdDecoder4to3 : public Idcoder::TIdDecoder
{
	typedef Idcoder::TIdDecoder inherited;
	
protected:
	System::AnsiString FCodingTable;
	TIdDecodeTable FDecodeTable;
	char FFillChar;
	Sysutils::TBytes __fastcall InternalDecode(const Sysutils::TBytes ABuffer);
	
public:
	__classmethod void __fastcall ConstructDecodeTable(const System::AnsiString ACodingTable, System::Byte *ADecodeArray);
	virtual void __fastcall Decode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff)/* overload */;
	
__published:
	__property char FillChar = {read=FFillChar, write=FFillChar, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoder4to3(Classes::TComponent* AOwner)/* overload */ : Idcoder::TIdDecoder(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoder4to3(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Decode(const System::UnicodeString AIn){ Idcoder::TIdDecoder::Decode(AIn); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcoder3to4 */
using namespace Idcoder3to4;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idcoder3to4HPP
