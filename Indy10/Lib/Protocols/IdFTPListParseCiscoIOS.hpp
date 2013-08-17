// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparseciscoios.pas' rev: 20.00

#ifndef IdftplistparseciscoiosHPP
#define IdftplistparseciscoiosHPP

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
#pragma link "IdFTPListParseCiscoIOS"

namespace Idftplistparseciscoios
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdCiscoIOSFTPListItem;
class PASCALIMPLEMENTATION TIdCiscoIOSFTPListItem : public Idftplisttypes::TIdMinimalFTPListItem
{
	typedef Idftplisttypes::TIdMinimalFTPListItem inherited;
	
public:
	/* TIdMinimalFTPListItem.Create */ inline __fastcall virtual TIdCiscoIOSFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdMinimalFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdCiscoIOSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPCiscoIOS;
class PASCALIMPLEMENTATION TIdFTPLPCiscoIOS : public Idftplistparsebase::TIdFTPLPNList
{
	typedef Idftplistparsebase::TIdFTPLPNList inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPCiscoIOS(void) : Idftplistparsebase::TIdFTPLPNList() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPCiscoIOS(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparseciscoios */
using namespace Idftplistparseciscoios;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparseciscoiosHPP
