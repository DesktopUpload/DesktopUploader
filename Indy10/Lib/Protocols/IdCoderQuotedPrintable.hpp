// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoderquotedprintable.pas' rev: 20.00

#ifndef IdcoderquotedprintableHPP
#define IdcoderquotedprintableHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Idstream.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoderquotedprintable
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDecoderQuotedPrintable;
class PASCALIMPLEMENTATION TIdDecoderQuotedPrintable : public Idcoder::TIdDecoder
{
	typedef Idcoder::TIdDecoder inherited;
	
public:
	virtual void __fastcall Decode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff)/* overload */;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoderQuotedPrintable(Classes::TComponent* AOwner)/* overload */ : Idcoder::TIdDecoder(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoderQuotedPrintable(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Decode(const System::UnicodeString AIn){ Idcoder::TIdDecoder::Decode(AIn); }
	
};


class DELPHICLASS TIdEncoderQuotedPrintable;
class PASCALIMPLEMENTATION TIdEncoderQuotedPrintable : public Idcoder::TIdEncoder
{
	typedef Idcoder::TIdEncoder inherited;
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrcStream, Classes::TStream* ADestStream, const int ABytes = 0xffffffff)/* overload */;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoderQuotedPrintable(Classes::TComponent* AOwner)/* overload */ : Idcoder::TIdEncoder(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoderQuotedPrintable(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline System::UnicodeString __fastcall  Encode(const System::UnicodeString AIn){ return Idcoder::TIdEncoder::Encode(AIn); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStrings* ADestStrings){ Idcoder::TIdEncoder::Encode(AIn, ADestStrings); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStream* ADestStream){ Idcoder::TIdEncoder::Encode(AIn, ADestStream); }
	inline System::UnicodeString __fastcall  Encode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff){ return Idcoder::TIdEncoder::Encode(ASrcStream, ABytes); }
	inline void __fastcall  Encode(Classes::TStream* ASrcStream, Classes::TStrings* ADestStrings, const int ABytes = 0xffffffff){ Idcoder::TIdEncoder::Encode(ASrcStream, ADestStrings, ABytes); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcoderquotedprintable */
using namespace Idcoderquotedprintable;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcoderquotedprintableHPP
