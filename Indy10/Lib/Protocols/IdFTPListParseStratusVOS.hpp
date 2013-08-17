// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsestratusvos.pas' rev: 20.00

#ifndef IdftplistparsestratusvosHPP
#define IdftplistparsestratusvosHPP

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
#pragma link "IdFTPListParseStratusVOS"

namespace Idftplistparsestratusvos
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdStratusVOSFTPListItem;
class PASCALIMPLEMENTATION TIdStratusVOSFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	System::UnicodeString FAccess;
	int FNumberBlocks;
	int FBlockSize;
	System::UnicodeString FFileFormat;
	System::UnicodeString FLinkedItemName;
	
public:
	__property System::UnicodeString Access = {read=FAccess, write=FAccess};
	__property int NumberBlocks = {read=FNumberBlocks, write=FNumberBlocks, nodefault};
	__property int BlockSize = {read=FBlockSize, write=FBlockSize, nodefault};
	__property System::UnicodeString FileFormat = {read=FFileFormat, write=FFileFormat};
	__property System::UnicodeString LinkedItemName = {read=FLinkedItemName, write=FLinkedItemName};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdStratusVOSFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdStratusVOSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPStratusVOS;
class PASCALIMPLEMENTATION TIdFTPLPStratusVOS : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod bool __fastcall IsValidFileEntry(const System::UnicodeString ALine);
	__classmethod bool __fastcall IsValidDirEntry(const System::UnicodeString ALine);
	__classmethod bool __fastcall IsFilesHeader(const System::UnicodeString ALine);
	__classmethod bool __fastcall IsDirsHeader(const System::UnicodeString ALine);
	__classmethod bool __fastcall IsLinksHeader(const System::UnicodeString ALine);
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod bool __fastcall ParseDirEntry(const Idftplist::TIdFTPListItem* AItem);
	__classmethod bool __fastcall ParseFileEntry(const Idftplist::TIdFTPListItem* AItem);
	__classmethod bool __fastcall ParseLinkEntry(const Idftplist::TIdFTPListItem* AItem);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPStratusVOS(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPStratusVOS(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsestratusvos */
using namespace Idftplistparsestratusvos;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsestratusvosHPP
