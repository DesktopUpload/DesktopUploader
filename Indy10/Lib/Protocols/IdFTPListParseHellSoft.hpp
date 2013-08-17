// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsehellsoft.pas' rev: 20.00

#ifndef IdftplistparsehellsoftHPP
#define IdftplistparsehellsoftHPP

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
#include <Idftplistparsenovellnetware.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "IdFTPListParseHellSoft"

namespace Idftplistparsehellsoft
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHellSoftFTPListItem;
class PASCALIMPLEMENTATION TIdHellSoftFTPListItem : public Idftplistparsenovellnetware::TIdNovellNetwareFTPListItem
{
	typedef Idftplistparsenovellnetware::TIdNovellNetwareFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdHellSoftFTPListItem(Classes::TCollection* AOwner) : Idftplistparsenovellnetware::TIdNovellNetwareFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdHellSoftFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPHellSoft;
class PASCALIMPLEMENTATION TIdFTPLPHellSoft : public Idftplistparsenovellnetware::TIdFTPLPNovellNetware
{
	typedef Idftplistparsenovellnetware::TIdFTPLPNovellNetware inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPHellSoft(void) : Idftplistparsenovellnetware::TIdFTPLPNovellNetware() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPHellSoft(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsehellsoft */
using namespace Idftplistparsehellsoft;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsehellsoftHPP
