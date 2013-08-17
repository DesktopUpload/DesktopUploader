// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsechameleonnewt.pas' rev: 20.00

#ifndef IdftplistparsechameleonnewtHPP
#define IdftplistparsechameleonnewtHPP

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
#pragma link "IdFTPListParseChameleonNewt"

namespace Idftplistparsechameleonnewt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdChameleonNewtFTPListItem;
class PASCALIMPLEMENTATION TIdChameleonNewtFTPListItem : public Idftplisttypes::TIdDOSBaseFTPListItem
{
	typedef Idftplisttypes::TIdDOSBaseFTPListItem inherited;
	
public:
	/* TIdDOSBaseFTPListItem.Create */ inline __fastcall virtual TIdChameleonNewtFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdDOSBaseFTPListItem(AOwner) { }
	/* TIdDOSBaseFTPListItem.Destroy */ inline __fastcall virtual ~TIdChameleonNewtFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPChameleonNewt;
class PASCALIMPLEMENTATION TIdFTPLPChameleonNewt : public Idftplistparsebase::TIdFTPLPBaseDOS
{
	typedef Idftplistparsebase::TIdFTPLPBaseDOS inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPChameleonNewt(void) : Idftplistparsebase::TIdFTPLPBaseDOS() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPChameleonNewt(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsechameleonnewt */
using namespace Idftplistparsechameleonnewt;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsechameleonnewtHPP
