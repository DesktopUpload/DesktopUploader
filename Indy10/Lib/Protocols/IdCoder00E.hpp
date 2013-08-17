// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoder00e.pas' rev: 20.00

#ifndef Idcoder00eHPP
#define Idcoder00eHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcoder3to4.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoder00e
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDecoder00E;
class PASCALIMPLEMENTATION TIdDecoder00E : public Idcoder3to4::TIdDecoder4to3
{
	typedef Idcoder3to4::TIdDecoder4to3 inherited;
	
public:
	virtual void __fastcall Decode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff)/* overload */;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoder00E(Classes::TComponent* AOwner)/* overload */ : Idcoder3to4::TIdDecoder4to3(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoder00E(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Decode(const System::UnicodeString AIn){ Idcoder::TIdDecoder::Decode(AIn); }
	
};


class DELPHICLASS TIdEncoder00E;
class PASCALIMPLEMENTATION TIdEncoder00E : public Idcoder3to4::TIdEncoder3to4
{
	typedef Idcoder3to4::TIdEncoder3to4 inherited;
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrcStream, Classes::TStream* ADestStream, const int ABytes = 0xffffffff)/* overload */;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoder00E(Classes::TComponent* AOwner)/* overload */ : Idcoder3to4::TIdEncoder3to4(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoder00E(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline System::UnicodeString __fastcall  Encode(const System::UnicodeString AIn){ return Idcoder::TIdEncoder::Encode(AIn); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStrings* ADestStrings){ Idcoder::TIdEncoder::Encode(AIn, ADestStrings); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStream* ADestStream){ Idcoder::TIdEncoder::Encode(AIn, ADestStream); }
	inline System::UnicodeString __fastcall  Encode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff){ return Idcoder::TIdEncoder::Encode(ASrcStream, ABytes); }
	inline void __fastcall  Encode(Classes::TStream* ASrcStream, Classes::TStrings* ADestStrings, const int ABytes = 0xffffffff){ Idcoder::TIdEncoder::Encode(ASrcStream, ADestStrings, ABytes); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcoder00e */
using namespace Idcoder00e;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idcoder00eHPP
