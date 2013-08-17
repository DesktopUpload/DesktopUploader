// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoderuue.pas' rev: 20.00

#ifndef IdcoderuueHPP
#define IdcoderuueHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcoder00e.hpp>	// Pascal unit
#include <Idcoder3to4.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoderuue
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDecoderUUE;
class PASCALIMPLEMENTATION TIdDecoderUUE : public Idcoder00e::TIdDecoder00E
{
	typedef Idcoder00e::TIdDecoder00E inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoderUUE(Classes::TComponent* AOwner)/* overload */ : Idcoder00e::TIdDecoder00E(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoderUUE(void) { }
	
};


class DELPHICLASS TIdEncoderUUE;
class PASCALIMPLEMENTATION TIdEncoderUUE : public Idcoder00e::TIdEncoder00E
{
	typedef Idcoder00e::TIdEncoder00E inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoderUUE(Classes::TComponent* AOwner)/* overload */ : Idcoder00e::TIdEncoder00E(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoderUUE(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString GUUECodeTable;
extern PACKAGE Idcoder3to4::TIdDecodeTable GUUEDecodeTable;

}	/* namespace Idcoderuue */
using namespace Idcoderuue;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcoderuueHPP
