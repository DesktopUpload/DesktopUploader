// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsevm.pas' rev: 20.00

#ifndef IdftplistparsevmHPP
#define IdftplistparsevmHPP

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
#pragma link "IdFTPListParseVM"

namespace Idftplistparsevm
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdVMCMSFTPListItem;
class PASCALIMPLEMENTATION TIdVMCMSFTPListItem : public Idftplisttypes::TIdRecFTPListItem
{
	typedef Idftplisttypes::TIdRecFTPListItem inherited;
	
protected:
	System::UnicodeString FOwnerName;
	int FNumberBlocks;
	
public:
	__property int RecLength = {read=FRecLength, write=FRecLength, nodefault};
	__property System::UnicodeString RecFormat = {read=FRecFormat, write=FRecFormat};
	__property int NumberRecs = {read=FNumberRecs, write=FNumberRecs, nodefault};
	__property System::UnicodeString OwnerName = {read=FOwnerName, write=FOwnerName};
	__property int NumberBlocks = {read=FNumberBlocks, write=FNumberBlocks, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVMCMSFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdRecFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVMCMSFTPListItem(void) { }
	
};


class DELPHICLASS TIdVMVirtualReaderFTPListItem;
class PASCALIMPLEMENTATION TIdVMVirtualReaderFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	int FNumberRecs;
	
public:
	__fastcall virtual TIdVMVirtualReaderFTPListItem(Classes::TCollection* AOwner);
	__property int NumberRecs = {read=FNumberRecs, write=FNumberRecs, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVMVirtualReaderFTPListItem(void) { }
	
};


class DELPHICLASS TIdVMBFSFTPListItem;
class PASCALIMPLEMENTATION TIdVMBFSFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVMBFSFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVMBFSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPVMCMS;
class PASCALIMPLEMENTATION TIdFTPLPVMCMS : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVMCMS(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVMCMS(void) { }
	
};


class DELPHICLASS TIdFTPLPVMBFS;
class PASCALIMPLEMENTATION TIdFTPLPVMBFS : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVMBFS(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVMBFS(void) { }
	
};


class DELPHICLASS TIdFTPLVirtualReader;
class PASCALIMPLEMENTATION TIdFTPLVirtualReader : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLVirtualReader(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLVirtualReader(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsevm */
using namespace Idftplistparsevm;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsevmHPP
