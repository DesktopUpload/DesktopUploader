// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhmac.pas' rev: 20.00

#ifndef IdhmacHPP
#define IdhmacHPP

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

namespace Idhmac
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHMACKeyBuilder;
class PASCALIMPLEMENTATION TIdHMACKeyBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod Sysutils::TBytes __fastcall Key(const int ASize);
	__classmethod Sysutils::TBytes __fastcall IV(const int ASize);
public:
	/* TObject.Create */ inline __fastcall TIdHMACKeyBuilder(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHMACKeyBuilder(void) { }
	
};


class DELPHICLASS TIdHMAC;
class PASCALIMPLEMENTATION TIdHMAC : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	int FHashSize;
	int FBlockSize;
	Sysutils::TBytes FKey;
	Idhash::TIdHash* FHash;
	System::UnicodeString FHashName;
	virtual void __fastcall InitHash(void) = 0 ;
	void __fastcall InitKey(void);
	
public:
	__fastcall virtual TIdHMAC(void);
	__fastcall virtual ~TIdHMAC(void);
	Sysutils::TBytes __fastcall HashValue(const Sysutils::TBytes ABuffer, const int ATruncateTo = 0xffffffff);
	__property int HashSize = {read=FHashSize, nodefault};
	__property int BlockSize = {read=FBlockSize, nodefault};
	__property System::UnicodeString HashName = {read=FHashName};
	__property Sysutils::TBytes Key = {read=FKey, write=FKey};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhmac */
using namespace Idhmac;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhmacHPP
