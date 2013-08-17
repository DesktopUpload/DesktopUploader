// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparseeplf.pas' rev: 20.00

#ifndef IdftplistparseeplfHPP
#define IdftplistparseeplfHPP

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
#pragma link "IdFTPListParseEPLF"

namespace Idftplistparseeplf
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAEPLFFTPListItem;
class PASCALIMPLEMENTATION TIdAEPLFFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	System::UnicodeString FUniqueID;
	
public:
	__property ModifiedDateGMT;
	__property System::UnicodeString UniqueID = {read=FUniqueID, write=FUniqueID};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdAEPLFFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdAEPLFFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPEPLF;
class PASCALIMPLEMENTATION TIdFTPLPEPLF : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPEPLF(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPEPLF(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparseeplf */
using namespace Idftplistparseeplf;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparseeplfHPP
