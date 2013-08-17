// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparseas400.pas' rev: 20.00

#ifndef Idftplistparseas400HPP
#define Idftplistparseas400HPP

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
#pragma link "IdFTPListParseAS400"

namespace Idftplistparseas400
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAS400FTPListItem;
class PASCALIMPLEMENTATION TIdAS400FTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdAS400FTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdAS400FTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPAS400;
class PASCALIMPLEMENTATION TIdFTPLPAS400 : public Idftplistparsebase::TIdFTPLineOwnedList
{
	typedef Idftplistparsebase::TIdFTPLineOwnedList inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPAS400(void) : Idftplistparsebase::TIdFTPLineOwnedList() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPAS400(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparseas400 */
using namespace Idftplistparseas400;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idftplistparseas400HPP
