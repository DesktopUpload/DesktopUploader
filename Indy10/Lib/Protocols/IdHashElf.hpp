// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhashelf.pas' rev: 20.00

#ifndef IdhashelfHPP
#define IdhashelfHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhashelf
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHashElf;
class PASCALIMPLEMENTATION TIdHashElf : public Idhash::TIdHash32
{
	typedef Idhash::TIdHash32 inherited;
	
public:
	virtual void __fastcall HashStart(unsigned &VRunningHash);
	virtual void __fastcall HashByte(unsigned &VRunningHash, const System::Byte AByte);
public:
	/* TIdHash.Create */ inline __fastcall virtual TIdHashElf(void) : Idhash::TIdHash32() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashElf(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhashelf */
using namespace Idhashelf;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhashelfHPP
