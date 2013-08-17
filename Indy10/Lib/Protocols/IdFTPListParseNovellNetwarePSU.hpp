// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsenovellnetwarepsu.pas' rev: 20.00

#ifndef IdftplistparsenovellnetwarepsuHPP
#define IdftplistparsenovellnetwarepsuHPP

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
#pragma link "IdFTPListParseNovellNetwarePSU"

namespace Idftplistparsenovellnetwarepsu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdNovellPSU_DOSFTPListItem;
class PASCALIMPLEMENTATION TIdNovellPSU_DOSFTPListItem : public Idftplisttypes::TIdNovellBaseFTPListItem
{
	typedef Idftplisttypes::TIdNovellBaseFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdNovellPSU_DOSFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdNovellBaseFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdNovellPSU_DOSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPNetwarePSUDos;
class PASCALIMPLEMENTATION TIdFTPLPNetwarePSUDos : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPNetwarePSUDos(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPNetwarePSUDos(void) { }
	
};


class DELPHICLASS TIdNovellPSU_NFSFTPListItem;
class PASCALIMPLEMENTATION TIdNovellPSU_NFSFTPListItem : public Idftplisttypes::TIdUnixBaseFTPListItem
{
	typedef Idftplisttypes::TIdUnixBaseFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdNovellPSU_NFSFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdUnixBaseFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdNovellPSU_NFSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPNetwarePSUNFS;
class PASCALIMPLEMENTATION TIdFTPLPNetwarePSUNFS : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPNetwarePSUNFS(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPNetwarePSUNFS(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define NOVELLNETWAREPSU L"Novell Netware Print Services for Unix:  "

}	/* namespace Idftplistparsenovellnetwarepsu */
using namespace Idftplistparsenovellnetwarepsu;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsenovellnetwarepsuHPP
