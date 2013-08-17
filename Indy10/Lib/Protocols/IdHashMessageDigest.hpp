// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhashmessagedigest.pas' rev: 20.00

#ifndef IdhashmessagedigestHPP
#define IdhashmessagedigestHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhashmessagedigest
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<unsigned, 4> T4x4LongWordRecord;

typedef StaticArray<unsigned, 16> T16x4LongWordRecord;

typedef StaticArray<StaticArray<unsigned, 4>, 4> T4x4x4LongWordRecord;

typedef StaticArray<System::Byte, 64> T512BitRecord;

typedef StaticArray<System::Byte, 48> T384BitRecord;

typedef StaticArray<System::Byte, 16> T128BitRecord;

class DELPHICLASS TIdHashMessageDigest;
class PASCALIMPLEMENTATION TIdHashMessageDigest : public Idhash::TIdHash
{
	typedef Idhash::TIdHash inherited;
	
protected:
	Sysutils::TBytes FCBuffer;
	virtual void __fastcall MDCoder(void) = 0 ;
	virtual void __fastcall Reset(void);
public:
	/* TIdHash.Create */ inline __fastcall virtual TIdHashMessageDigest(void) : Idhash::TIdHash() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashMessageDigest(void) { }
	
};


class DELPHICLASS TIdHashMessageDigest2;
class PASCALIMPLEMENTATION TIdHashMessageDigest2 : public TIdHashMessageDigest
{
	typedef TIdHashMessageDigest inherited;
	
protected:
	T384BitRecord FX;
	T128BitRecord FCheckSum;
	virtual void __fastcall MDCoder(void);
	virtual void __fastcall Reset(void);
	virtual Sysutils::TBytes __fastcall GetHashBytes(Classes::TStream* AStream, __int64 ASize);
	virtual System::UnicodeString __fastcall HashToHex(const Sysutils::TBytes AHash);
	
public:
	__fastcall virtual TIdHashMessageDigest2(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashMessageDigest2(void) { }
	
};


class DELPHICLASS TIdHashMessageDigest4;
class PASCALIMPLEMENTATION TIdHashMessageDigest4 : public TIdHashMessageDigest
{
	typedef TIdHashMessageDigest inherited;
	
protected:
	T4x4LongWordRecord FState;
	virtual Sysutils::TBytes __fastcall GetHashBytes(Classes::TStream* AStream, __int64 ASize);
	virtual System::UnicodeString __fastcall HashToHex(const Sysutils::TBytes AHash);
	virtual void __fastcall MDCoder(void);
	
public:
	__fastcall virtual TIdHashMessageDigest4(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashMessageDigest4(void) { }
	
};


class DELPHICLASS TIdHashMessageDigest5;
class PASCALIMPLEMENTATION TIdHashMessageDigest5 : public TIdHashMessageDigest4
{
	typedef TIdHashMessageDigest4 inherited;
	
protected:
	virtual void __fastcall MDCoder(void);
public:
	/* TIdHashMessageDigest4.Create */ inline __fastcall virtual TIdHashMessageDigest5(void) : TIdHashMessageDigest4() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHashMessageDigest5(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhashmessagedigest */
using namespace Idhashmessagedigest;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhashmessagedigestHPP
