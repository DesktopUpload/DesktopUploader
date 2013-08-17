// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparseunix.pas' rev: 20.00

#ifndef IdftplistparseunixHPP
#define IdftplistparseunixHPP

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
#pragma link "IdFTPListParseUnix"

namespace Idftplistparseunix
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUnixFTPListItem;
class PASCALIMPLEMENTATION TIdUnixFTPListItem : public Idftplisttypes::TIdUnixBaseFTPListItem
{
	typedef Idftplisttypes::TIdUnixBaseFTPListItem inherited;
	
protected:
	int FNumberBlocks;
	int FInode;
	
public:
	__property int NumberBlocks = {read=FNumberBlocks, write=FNumberBlocks, nodefault};
	__property int Inode = {read=FInode, write=FInode, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdUnixFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdUnixBaseFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdUnixFTPListItem(void) { }
	
};


class DELPHICLASS TIdUnitreeFTPListItem;
class PASCALIMPLEMENTATION TIdUnitreeFTPListItem : public TIdUnixFTPListItem
{
	typedef TIdUnixFTPListItem inherited;
	
protected:
	bool FMigrated;
	System::UnicodeString FFileFamily;
	
public:
	__property bool Migrated = {read=FMigrated, write=FMigrated, nodefault};
	__property System::UnicodeString FileFamily = {read=FFileFamily, write=FFileFamily};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdUnitreeFTPListItem(Classes::TCollection* AOwner) : TIdUnixFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdUnitreeFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPUnix;
class PASCALIMPLEMENTATION TIdFTPLPUnix : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall InternelChkUnix(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall IsUnitree(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall IsUnitreeBanner(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPUnix(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPUnix(void) { }
	
};


class DELPHICLASS TIdFTPLPUnitree;
class PASCALIMPLEMENTATION TIdFTPLPUnitree : public TIdFTPLPUnix
{
	typedef TIdFTPLPUnix inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPUnitree(void) : TIdFTPLPUnix() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPUnitree(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define UNIX L"Unix"
#define UNITREE L"Unitree"

}	/* namespace Idftplistparseunix */
using namespace Idftplistparseunix;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparseunixHPP
