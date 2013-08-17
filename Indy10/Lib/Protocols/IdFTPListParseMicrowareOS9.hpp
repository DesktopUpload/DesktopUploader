// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsemicrowareos9.pas' rev: 20.00

#ifndef Idftplistparsemicrowareos9HPP
#define Idftplistparsemicrowareos9HPP

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
#pragma link "IdFTPListParseMicrowareOS9"

namespace Idftplistparsemicrowareos9
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMicrowareOS9FTPListItem;
class PASCALIMPLEMENTATION TIdMicrowareOS9FTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	System::UnicodeString FOS9OwnerPermissions;
	System::UnicodeString FOS9PublicPermissions;
	System::UnicodeString FOS9MiscPermissions;
	unsigned FOS9Sector;
	
public:
	__property System::UnicodeString OS9OwnerPermissions = {read=FOS9OwnerPermissions, write=FOS9OwnerPermissions};
	__property System::UnicodeString OS9PublicPermissions = {read=FOS9PublicPermissions, write=FOS9PublicPermissions};
	__property System::UnicodeString OS9MiscPermissions = {read=FOS9MiscPermissions, write=FOS9MiscPermissions};
	__property unsigned OS9Sector = {read=FOS9Sector, write=FOS9Sector, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdMicrowareOS9FTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMicrowareOS9FTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPMicrowareOS9;
class PASCALIMPLEMENTATION TIdFTPLPMicrowareOS9 : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMicrowareOS9(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMicrowareOS9(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsemicrowareos9 */
using namespace Idftplistparsemicrowareos9;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idftplistparsemicrowareos9HPP
