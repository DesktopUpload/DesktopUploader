// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcodermime.pas' rev: 20.00

#ifndef IdcodermimeHPP
#define IdcodermimeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcoder3to4.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcodermime
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEncoderMIME;
class PASCALIMPLEMENTATION TIdEncoderMIME : public Idcoder3to4::TIdEncoder3to4
{
	typedef Idcoder3to4::TIdEncoder3to4 inherited;
	
public:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoderMIME(Classes::TComponent* AOwner)/* overload */ : Idcoder3to4::TIdEncoder3to4(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoderMIME(void) { }
	
};


class DELPHICLASS TIdDecoderMIME;
class PASCALIMPLEMENTATION TIdDecoderMIME : public Idcoder3to4::TIdDecoder4to3
{
	typedef Idcoder3to4::TIdDecoder4to3 inherited;
	
public:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoderMIME(Classes::TComponent* AOwner)/* overload */ : Idcoder3to4::TIdDecoder4to3(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoderMIME(void) { }
	
};


class DELPHICLASS TIdDecoderMIMELineByLine;
class PASCALIMPLEMENTATION TIdDecoderMIMELineByLine : public TIdDecoderMIME
{
	typedef TIdDecoderMIME inherited;
	
protected:
	Sysutils::TBytes FLeftFromLastTime;
	
public:
	virtual void __fastcall DecodeBegin(Classes::TStream* ADestStream);
	virtual void __fastcall DecodeEnd(void);
	virtual void __fastcall Decode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff)/* overload */;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoderMIMELineByLine(Classes::TComponent* AOwner)/* overload */ : TIdDecoderMIME(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoderMIMELineByLine(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Decode(const System::UnicodeString AIn){ Idcoder::TIdDecoder::Decode(AIn); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString GBase64CodeTable;
extern PACKAGE Idcoder3to4::TIdDecodeTable GBase64DecodeTable;

}	/* namespace Idcodermime */
using namespace Idcodermime;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcodermimeHPP
