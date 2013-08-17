// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoderxxe.pas' rev: 20.00

#ifndef IdcoderxxeHPP
#define IdcoderxxeHPP

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

namespace Idcoderxxe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDecoderXXE;
class PASCALIMPLEMENTATION TIdDecoderXXE : public Idcoder00e::TIdDecoder00E
{
	typedef Idcoder00e::TIdDecoder00E inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoderXXE(Classes::TComponent* AOwner)/* overload */ : Idcoder00e::TIdDecoder00E(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoderXXE(void) { }
	
};


class DELPHICLASS TIdEncoderXXE;
class PASCALIMPLEMENTATION TIdEncoderXXE : public Idcoder00e::TIdEncoder00E
{
	typedef Idcoder00e::TIdEncoder00E inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoderXXE(Classes::TComponent* AOwner)/* overload */ : Idcoder00e::TIdEncoder00E(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoderXXE(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString GXXECodeTable;
extern PACKAGE Idcoder3to4::TIdDecodeTable GXXEDecodeTable;

}	/* namespace Idcoderxxe */
using namespace Idcoderxxe;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcoderxxeHPP
