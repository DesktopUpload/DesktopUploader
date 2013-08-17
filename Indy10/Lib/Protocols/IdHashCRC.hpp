// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhashcrc.pas' rev: 20.00

#ifndef IdhashcrcHPP
#define IdhashcrcHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhashcrc
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHashCRC16;
class PASCALIMPLEMENTATION TIdHashCRC16 : public Idhash::TIdHash16
{
	typedef Idhash::TIdHash16 inherited;
	
public:
	virtual void __fastcall HashStart(System::Word &VRunningHash);
	virtual void __fastcall HashByte(System::Word &VRunningHash, const System::Byte AByte);
public:
	/* TIdHash.Create */ inline __fastcall virtual TIdHashCRC16(void) : Idhash::TIdHash16() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashCRC16(void) { }
	
};


class DELPHICLASS TIdHashCRC32;
class PASCALIMPLEMENTATION TIdHashCRC32 : public Idhash::TIdHash32
{
	typedef Idhash::TIdHash32 inherited;
	
public:
	virtual void __fastcall HashStart(unsigned &VRunningHash);
	virtual void __fastcall HashEnd(unsigned &VRunningHash);
	virtual void __fastcall HashByte(unsigned &VRunningHash, const System::Byte AByte);
public:
	/* TIdHash.Create */ inline __fastcall virtual TIdHashCRC32(void) : Idhash::TIdHash32() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashCRC32(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhashcrc */
using namespace Idhashcrc;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhashcrcHPP
