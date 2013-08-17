// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsempeix.pas' rev: 20.00

#ifndef IdftplistparsempeixHPP
#define IdftplistparsempeixHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idftplistparsebase.hpp>	// Pascal unit
#include <Idftplisttypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "IdFTPListParseMPEiX"

namespace Idftplistparsempeix
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMPiXFTPListItem;
class PASCALIMPLEMENTATION TIdMPiXFTPListItem : public Idftplisttypes::TIdRecFTPListItem
{
	typedef Idftplisttypes::TIdRecFTPListItem inherited;
	
protected:
	unsigned FLimit;
	
public:
	__fastcall virtual TIdMPiXFTPListItem(Classes::TCollection* AOwner);
	__property RecLength;
	__property RecFormat;
	__property NumberRecs;
	__property unsigned Limit = {read=FLimit, write=FLimit, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMPiXFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPMPiXBase;
class PASCALIMPLEMENTATION TIdFTPLPMPiXBase : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsSecondHeader(Classes::TStrings* ACols);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMPiXBase(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMPiXBase(void) { }
	
};


class DELPHICLASS TIdFTPLPMPiX;
class PASCALIMPLEMENTATION TIdFTPLPMPiX : public TIdFTPLPMPiXBase
{
	typedef TIdFTPLPMPiXBase inherited;
	
protected:
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMPiX(void) : TIdFTPLPMPiXBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMPiX(void) { }
	
};


class DELPHICLASS TIdFTPLPMPiXWithPOSIX;
class PASCALIMPLEMENTATION TIdFTPLPMPiXWithPOSIX : public TIdFTPLPMPiXBase
{
	typedef TIdFTPLPMPiXBase inherited;
	
protected:
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMPiXWithPOSIX(void) : TIdFTPLPMPiXBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMPiXWithPOSIX(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsempeix */
using namespace Idftplistparsempeix;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsempeixHPP
