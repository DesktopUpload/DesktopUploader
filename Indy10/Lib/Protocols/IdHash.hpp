// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhash.pas' rev: 20.00

#ifndef IdhashHPP
#define IdhashHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhash
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHash;
class PASCALIMPLEMENTATION TIdHash : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual Sysutils::TBytes __fastcall GetHashBytes(Classes::TStream* AStream, __int64 ASize) = 0 ;
	virtual System::UnicodeString __fastcall HashToHex(const Sysutils::TBytes AHash) = 0 ;
	System::UnicodeString __fastcall WordHashToHex(const Sysutils::TBytes AHash, const int ACount);
	System::UnicodeString __fastcall LongWordHashToHex(const Sysutils::TBytes AHash, const int ACount);
	
public:
	__fastcall virtual TIdHash(void);
	Sysutils::TBytes __fastcall HashString(const System::UnicodeString ASrc, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	System::UnicodeString __fastcall HashStringAsHex(const System::UnicodeString AStr, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	Sysutils::TBytes __fastcall HashBytes(const Sysutils::TBytes ASrc);
	System::UnicodeString __fastcall HashBytesAsHex(const Sysutils::TBytes ASrc);
	Sysutils::TBytes __fastcall HashStream(Classes::TStream* AStream)/* overload */;
	System::UnicodeString __fastcall HashStreamAsHex(Classes::TStream* AStream)/* overload */;
	Sysutils::TBytes __fastcall HashStream(Classes::TStream* AStream, const __int64 AStartPos, const __int64 ASize)/* overload */;
	System::UnicodeString __fastcall HashStreamAsHex(Classes::TStream* AStream, const __int64 AStartPos, const __int64 ASize)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHash(void) { }
	
};


class DELPHICLASS TIdHash16;
class PASCALIMPLEMENTATION TIdHash16 : public TIdHash
{
	typedef TIdHash inherited;
	
protected:
	virtual Sysutils::TBytes __fastcall GetHashBytes(Classes::TStream* AStream, __int64 ASize);
	virtual System::UnicodeString __fastcall HashToHex(const Sysutils::TBytes AHash);
	
public:
	System::Word __fastcall HashValue(const System::UnicodeString ASrc, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::Word __fastcall HashValue(const Sysutils::TBytes ASrc)/* overload */;
	System::Word __fastcall HashValue(Classes::TStream* AStream)/* overload */;
	System::Word __fastcall HashValue(Classes::TStream* AStream, const __int64 AStartPos, const __int64 ASize)/* overload */;
	virtual void __fastcall HashStart(System::Word &VRunningHash) = 0 ;
	virtual void __fastcall HashEnd(System::Word &VRunningHash);
	virtual void __fastcall HashByte(System::Word &VRunningHash, const System::Byte AByte) = 0 ;
public:
	/* TIdHash.Create */ inline __fastcall virtual TIdHash16(void) : TIdHash() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHash16(void) { }
	
};


class DELPHICLASS TIdHash32;
class PASCALIMPLEMENTATION TIdHash32 : public TIdHash
{
	typedef TIdHash inherited;
	
protected:
	virtual Sysutils::TBytes __fastcall GetHashBytes(Classes::TStream* AStream, __int64 ASize);
	virtual System::UnicodeString __fastcall HashToHex(const Sysutils::TBytes AHash);
	
public:
	unsigned __fastcall HashValue(const System::UnicodeString ASrc, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	unsigned __fastcall HashValue(const Sysutils::TBytes ASrc)/* overload */;
	unsigned __fastcall HashValue(Classes::TStream* AStream)/* overload */;
	unsigned __fastcall HashValue(Classes::TStream* AStream, const __int64 AStartPos, const __int64 ASize)/* overload */;
	virtual void __fastcall HashStart(unsigned &VRunningHash) = 0 ;
	virtual void __fastcall HashEnd(unsigned &VRunningHash);
	virtual void __fastcall HashByte(unsigned &VRunningHash, const System::Byte AByte) = 0 ;
public:
	/* TIdHash.Create */ inline __fastcall virtual TIdHash32(void) : TIdHash() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHash32(void) { }
	
};


typedef TMetaClass* TIdHashClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhash */
using namespace Idhash;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhashHPP
