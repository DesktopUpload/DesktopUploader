// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsevms.pas' rev: 20.00

#ifndef IdftplistparsevmsHPP
#define IdftplistparsevmsHPP

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
#pragma link "IdFTPListParseVMS"

namespace Idftplistparsevms
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdVMSFTPListItem;
class PASCALIMPLEMENTATION TIdVMSFTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	System::UnicodeString FGroupName;
	System::UnicodeString FVMSOwnerPermissions;
	System::UnicodeString FVMSWorldPermissions;
	System::UnicodeString FVMSSystemPermissions;
	System::UnicodeString FVMSGroupPermissions;
	int FNumberBlocks;
	int FBlockSize;
	int FVersion;
	
public:
	__property System::UnicodeString GroupName = {read=FGroupName, write=FGroupName};
	__property System::UnicodeString VMSSystemPermissions = {read=FVMSSystemPermissions, write=FVMSSystemPermissions};
	__property System::UnicodeString VMSOwnerPermissions = {read=FVMSOwnerPermissions, write=FVMSOwnerPermissions};
	__property System::UnicodeString VMSGroupPermissions = {read=FVMSGroupPermissions, write=FVMSGroupPermissions};
	__property System::UnicodeString VMSWorldPermissions = {read=FVMSWorldPermissions, write=FVMSWorldPermissions};
	__property int Version = {read=FVersion, write=FVersion, nodefault};
	__property int NumberBlocks = {read=FNumberBlocks, write=FNumberBlocks, nodefault};
	__property int BlockSize = {read=FBlockSize, write=FBlockSize, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdVMSFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVMSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPVMS;
class PASCALIMPLEMENTATION TIdFTPLPVMS : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod bool __fastcall IsVMSHeader(const System::UnicodeString AData);
	__classmethod bool __fastcall IsVMSFooter(const System::UnicodeString AData);
	__classmethod bool __fastcall IsContinuedLine(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPVMS(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPVMS(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsevms */
using namespace Idftplistparsevms;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsevmsHPP
