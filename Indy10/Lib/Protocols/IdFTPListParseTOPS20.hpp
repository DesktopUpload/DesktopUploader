// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsetops20.pas' rev: 20.00

#ifndef Idftplistparsetops20HPP
#define Idftplistparsetops20HPP

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
#pragma link "IdFTPListParseTOPS20"

namespace Idftplistparsetops20
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTOPS20FTPListItem;
class PASCALIMPLEMENTATION TIdTOPS20FTPListItem : public Idftplisttypes::TIdCreationDateFTPListItem
{
	typedef Idftplisttypes::TIdCreationDateFTPListItem inherited;
	
public:
	/* TIdCreationDateFTPListItem.Create */ inline __fastcall virtual TIdTOPS20FTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdCreationDateFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdTOPS20FTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPTOPS20;
class PASCALIMPLEMENTATION TIdFTPLPTOPS20 : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPTOPS20(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPTOPS20(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define TOPS20_VOLPATH_SEP L":<"
static const WideChar TOPS20_DIRFILE_SEP = (WideChar)(0x3e);

}	/* namespace Idftplistparsetops20 */
using namespace Idftplistparsetops20;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idftplistparsetops20HPP
