// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparseunisysclearpath.pas' rev: 20.00

#ifndef IdftplistparseunisysclearpathHPP
#define IdftplistparseunisysclearpathHPP

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
#pragma link "IdFTPListParseUnisysClearPath"

namespace Idftplistparseunisysclearpath
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUnisysClearPathFTPListItem;
class PASCALIMPLEMENTATION TIdUnisysClearPathFTPListItem : public Idftplisttypes::TIdCreationDateFTPListItem
{
	typedef Idftplisttypes::TIdCreationDateFTPListItem inherited;
	
protected:
	System::UnicodeString FFileKind;
	
public:
	__property System::UnicodeString FileKind = {read=FFileKind, write=FFileKind};
public:
	/* TIdCreationDateFTPListItem.Create */ inline __fastcall virtual TIdUnisysClearPathFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdCreationDateFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdUnisysClearPathFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPUnisysClearPath;
class PASCALIMPLEMENTATION TIdFTPLPUnisysClearPath : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod bool __fastcall IsContinuedLine(const System::UnicodeString AData);
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall IsFooter(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPUnisysClearPath(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPUnisysClearPath(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparseunisysclearpath */
using namespace Idftplistparseunisysclearpath;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparseunisysclearpathHPP
