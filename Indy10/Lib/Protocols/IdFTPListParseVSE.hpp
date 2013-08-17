// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsevse.pas' rev: 20.00

#ifndef IdftplistparsevseHPP
#define IdftplistparsevseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idftpcommon.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idftplistparsebase.hpp>	// Pascal unit
#include <Idftplisttypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "IdFTPListParseVSE"

namespace Idftplistparsevse
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdVSERootDirFTPListItem;
class PASCALIMPLEMENTATION TIdVSERootDirFTPListItem : public Idftplisttypes::TIdMinimalFTPListItem
{
	typedef Idftplisttypes::TIdMinimalFTPListItem inherited;
	
public:
	/* TIdMinimalFTPListItem.Create */ inline __fastcall virtual TIdVSERootDirFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdMinimalFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVSERootDirFTPListItem(void) { }
	
};


class DELPHICLASS TIdVSELibraryFTPListItem;
class PASCALIMPLEMENTATION TIdVSELibraryFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	int FNumberBlocks;
	
public:
	__property int NumberBlocks = {read=FNumberBlocks, write=FNumberBlocks, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVSELibraryFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVSELibraryFTPListItem(void) { }
	
};


class DELPHICLASS TIdVSEPowerQueueFTPListItem;
class PASCALIMPLEMENTATION TIdVSEPowerQueueFTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	Idftpcommon::TIdVSEPQDisposition FVSEPQDisposition;
	int FVSEPQPriority;
	int FNumberRecs;
	
public:
	__property int NumberRecs = {read=FNumberRecs, write=FNumberRecs, nodefault};
	__property Idftpcommon::TIdVSEPQDisposition VSEPQDisposition = {read=FVSEPQDisposition, write=FVSEPQDisposition, nodefault};
	__property int VSEPQPriority = {read=FVSEPQPriority, write=FVSEPQPriority, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVSEPowerQueueFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVSEPowerQueueFTPListItem(void) { }
	
};


class DELPHICLASS TIdVSESubLibraryFTPListItem;
class PASCALIMPLEMENTATION TIdVSESubLibraryFTPListItem : public TIdVSELibraryFTPListItem
{
	typedef TIdVSELibraryFTPListItem inherited;
	
protected:
	int FNumberRecs;
	System::TDateTime FCreationDate;
	
public:
	__property System::TDateTime CreationDate = {read=FCreationDate, write=FCreationDate};
	__property int NumberRecs = {read=FNumberRecs, write=FNumberRecs, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVSESubLibraryFTPListItem(Classes::TCollection* AOwner) : TIdVSELibraryFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVSESubLibraryFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPVSESubLibrary;
class PASCALIMPLEMENTATION TIdFTPLPVSESubLibrary : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVSESubLibrary(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVSESubLibrary(void) { }
	
};


class DELPHICLASS TIdVSEVSAMCatalogFTPListItem;
class PASCALIMPLEMENTATION TIdVSEVSAMCatalogFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVSEVSAMCatalogFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVSEVSAMCatalogFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPVSERootDir;
class PASCALIMPLEMENTATION TIdFTPLPVSERootDir : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVSERootDir(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVSERootDir(void) { }
	
};


class DELPHICLASS TIdFTPLPVSELibrary;
class PASCALIMPLEMENTATION TIdFTPLPVSELibrary : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVSELibrary(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVSELibrary(void) { }
	
};


class DELPHICLASS TIdFTPLPVSEVSAMCatalog;
class PASCALIMPLEMENTATION TIdFTPLPVSEVSAMCatalog : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVSEVSAMCatalog(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVSEVSAMCatalog(void) { }
	
};


class DELPHICLASS TIdVSEVTOCFTPListItem;
class PASCALIMPLEMENTATION TIdVSEVTOCFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
public:
	__fastcall virtual TIdVSEVTOCFTPListItem(Classes::TCollection* AOwner);
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVSEVTOCFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPVSEVTOC;
class PASCALIMPLEMENTATION TIdFTPLPVSEVTOC : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVSEVTOC(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVSEVTOC(void) { }
	
};


class DELPHICLASS TIdFTPLPVSEPowerQueue;
class PASCALIMPLEMENTATION TIdFTPLPVSEPowerQueue : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVSEPowerQueue(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVSEPowerQueue(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsevse */
using namespace Idftplistparsevse;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsevseHPP
