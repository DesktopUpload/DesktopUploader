// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhashsha1.pas' rev: 20.00

#ifndef Idhashsha1HPP
#define Idhashsha1HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhashsha1
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<unsigned, 5> T5x4LongWordRecord;

typedef StaticArray<System::Byte, 64> T512BitRecord;

class DELPHICLASS TIdHashSHA1;
class PASCALIMPLEMENTATION TIdHashSHA1 : public Idhash::TIdHash
{
	typedef Idhash::TIdHash inherited;
	
protected:
	T5x4LongWordRecord FCheckSum;
	Sysutils::TBytes FCBuffer;
	void __fastcall Coder(void);
	virtual Sysutils::TBytes __fastcall GetHashBytes(Classes::TStream* AStream, __int64 ASize);
	virtual System::UnicodeString __fastcall HashToHex(const Sysutils::TBytes AHash);
	
public:
	__fastcall virtual TIdHashSHA1(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashSHA1(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhashsha1 */
using namespace Idhashsha1;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idhashsha1HPP
