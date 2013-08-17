// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplisttypes.pas' rev: 20.00

#ifndef IdftplisttypesHPP
#define IdftplisttypesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftplisttypes
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDOSAttributes;
class PASCALIMPLEMENTATION TIdDOSAttributes : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	unsigned FFileAttributes;
	bool __fastcall GetRead_Only(void);
	void __fastcall SetRead_Only(const bool AValue);
	bool __fastcall GetHidden(void);
	void __fastcall SetHidden(const bool AValue);
	bool __fastcall GetSystem(void);
	void __fastcall SetSystem(const bool AValue);
	bool __fastcall GetArchive(void);
	void __fastcall SetArchive(const bool AValue);
	bool __fastcall GetDirectory(void);
	void __fastcall SetDirectory(const bool AValue);
	bool __fastcall GetNormal(void);
	void __fastcall SetNormal(const bool AValue);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetAsString();
	bool __fastcall AddAttribute(const System::UnicodeString AString);
	
__published:
	__property unsigned FileAttributes = {read=FFileAttributes, write=FFileAttributes, nodefault};
	__property System::UnicodeString AsString = {read=GetAsString};
	__property bool Read_Only = {read=GetRead_Only, write=SetRead_Only, nodefault};
	__property bool Archive = {read=GetArchive, write=SetArchive, nodefault};
	__property bool System = {read=GetSystem, write=SetSystem, nodefault};
	__property bool Directory = {read=GetDirectory, write=SetDirectory, nodefault};
	__property bool Hidden = {read=GetHidden, write=SetHidden, nodefault};
	__property bool Normal = {read=GetNormal, write=SetNormal, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdDOSAttributes(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdDOSAttributes(void) : Classes::TPersistent() { }
	
};


class DELPHICLASS TIdWin32ea;
class PASCALIMPLEMENTATION TIdWin32ea : public TIdDOSAttributes
{
	typedef TIdDOSAttributes inherited;
	
protected:
	bool __fastcall GetDevice(void);
	void __fastcall SetDevice(const bool AValue);
	bool __fastcall GetTemporary(void);
	void __fastcall SetTemporary(const bool AValue);
	bool __fastcall GetSparseFile(void);
	void __fastcall SetSparseFile(const bool AValue);
	bool __fastcall GetReparsePoint(void);
	void __fastcall SetReparsePoint(const bool AValue);
	bool __fastcall GetCompressed(void);
	void __fastcall SetCompressed(const bool AValue);
	bool __fastcall GetOffline(void);
	void __fastcall SetOffline(const bool AValue);
	bool __fastcall GetNotContextIndexed(void);
	void __fastcall SetNotContextIndexed(const bool AValue);
	bool __fastcall GetEncrypted(void);
	void __fastcall SetEncrypted(const bool AValue);
	
public:
	virtual System::UnicodeString __fastcall GetAsString();
	
__published:
	__property bool Device = {read=GetDevice, write=SetDevice, nodefault};
	__property bool Temporary = {read=GetTemporary, write=SetTemporary, nodefault};
	__property bool SparseFile = {read=GetSparseFile, write=SetSparseFile, nodefault};
	__property bool ReparsePoint = {read=GetReparsePoint, write=SetReparsePoint, nodefault};
	__property bool Compressed = {read=GetCompressed, write=SetCompressed, nodefault};
	__property bool Offline = {read=GetOffline, write=SetOffline, nodefault};
	__property bool NotContextIndexed = {read=GetNotContextIndexed, write=SetNotContextIndexed, nodefault};
	__property bool Encrypted = {read=GetEncrypted, write=SetEncrypted, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdWin32ea(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdWin32ea(void) : TIdDOSAttributes() { }
	
};


class DELPHICLASS TIdMinimalFTPListItem;
class PASCALIMPLEMENTATION TIdMinimalFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
public:
	__fastcall virtual TIdMinimalFTPListItem(Classes::TCollection* AOwner);
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMinimalFTPListItem(void) { }
	
};


class DELPHICLASS TIdRecFTPListItem;
class PASCALIMPLEMENTATION TIdRecFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	int FRecLength;
	System::UnicodeString FRecFormat;
	int FNumberRecs;
	__property int RecLength = {read=FRecLength, write=FRecLength, nodefault};
	__property System::UnicodeString RecFormat = {read=FRecFormat, write=FRecFormat};
	__property int NumberRecs = {read=FNumberRecs, write=FNumberRecs, nodefault};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdRecFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdRecFTPListItem(void) { }
	
};


class DELPHICLASS TIdCreationDateFTPListItem;
class PASCALIMPLEMENTATION TIdCreationDateFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	System::TDateTime FCreationDate;
	
public:
	__fastcall virtual TIdCreationDateFTPListItem(Classes::TCollection* AOwner);
	__property System::TDateTime CreationDate = {read=FCreationDate, write=FCreationDate};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdCreationDateFTPListItem(void) { }
	
};


class DELPHICLASS TIdMLSTFTPListItem;
class PASCALIMPLEMENTATION TIdMLSTFTPListItem : public TIdCreationDateFTPListItem
{
	typedef TIdCreationDateFTPListItem inherited;
	
protected:
	bool FAttributesAvail;
	TIdWin32ea* FAttributes;
	System::TDateTime FCreationDateGMT;
	System::TDateTime FLastAccessDate;
	System::TDateTime FLastAccessDateGMT;
	System::UnicodeString FUniqueID;
	System::UnicodeString FMLISTPermissions;
	System::UnicodeString __fastcall GetFact(const System::UnicodeString AName);
	
public:
	__fastcall virtual TIdMLSTFTPListItem(Classes::TCollection* AOwner);
	__fastcall virtual ~TIdMLSTFTPListItem(void);
	__property ModifiedDateGMT;
	__property System::TDateTime CreationDateGMT = {read=FCreationDateGMT, write=FCreationDateGMT};
	__property System::TDateTime LastAccessDate = {read=FLastAccessDate, write=FLastAccessDate};
	__property System::TDateTime LastAccessDateGMT = {read=FLastAccessDateGMT, write=FLastAccessDateGMT};
	__property System::UnicodeString UniqueID = {read=FUniqueID, write=FUniqueID};
	__property System::UnicodeString MLISTPermissions = {read=FMLISTPermissions, write=FMLISTPermissions};
	__property System::UnicodeString Facts[const System::UnicodeString Name] = {read=GetFact};
	__property bool AttributesAvail = {read=FAttributesAvail, write=FAttributesAvail, nodefault};
	__property TIdWin32ea* Attributes = {read=FAttributes};
};


class DELPHICLASS TIdOwnerFTPListItem;
class PASCALIMPLEMENTATION TIdOwnerFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	System::UnicodeString FOwnerName;
	
public:
	__property System::UnicodeString OwnerName = {read=FOwnerName, write=FOwnerName};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdOwnerFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdOwnerFTPListItem(void) { }
	
};


class DELPHICLASS TIdNovellBaseFTPListItem;
class PASCALIMPLEMENTATION TIdNovellBaseFTPListItem : public TIdOwnerFTPListItem
{
	typedef TIdOwnerFTPListItem inherited;
	
protected:
	System::UnicodeString FNovellPermissions;
	
public:
	__property System::UnicodeString NovellPermissions = {read=FNovellPermissions, write=FNovellPermissions};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdNovellBaseFTPListItem(Classes::TCollection* AOwner) : TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdNovellBaseFTPListItem(void) { }
	
};


class DELPHICLASS TIdUnixPermFTPListItem;
class PASCALIMPLEMENTATION TIdUnixPermFTPListItem : public TIdOwnerFTPListItem
{
	typedef TIdOwnerFTPListItem inherited;
	
protected:
	System::UnicodeString FUnixGroupPermissions;
	System::UnicodeString FUnixOwnerPermissions;
	System::UnicodeString FUnixOtherPermissions;
	
public:
	__property System::UnicodeString UnixOwnerPermissions = {read=FUnixOwnerPermissions, write=FUnixOwnerPermissions};
	__property System::UnicodeString UnixGroupPermissions = {read=FUnixGroupPermissions, write=FUnixGroupPermissions};
	__property System::UnicodeString UnixOtherPermissions = {read=FUnixOtherPermissions, write=FUnixOtherPermissions};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdUnixPermFTPListItem(Classes::TCollection* AOwner) : TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdUnixPermFTPListItem(void) { }
	
};


class DELPHICLASS TIdUnixBaseFTPListItem;
class PASCALIMPLEMENTATION TIdUnixBaseFTPListItem : public TIdUnixPermFTPListItem
{
	typedef TIdUnixPermFTPListItem inherited;
	
protected:
	int FLinkCount;
	System::UnicodeString FGroupName;
	System::UnicodeString FLinkedItemName;
	
public:
	__property int LinkCount = {read=FLinkCount, write=FLinkCount, nodefault};
	__property System::UnicodeString GroupName = {read=FGroupName, write=FGroupName};
	__property System::UnicodeString LinkedItemName = {read=FLinkedItemName, write=FLinkedItemName};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdUnixBaseFTPListItem(Classes::TCollection* AOwner) : TIdUnixPermFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdUnixBaseFTPListItem(void) { }
	
};


class DELPHICLASS TIdDOSBaseFTPListItem;
class PASCALIMPLEMENTATION TIdDOSBaseFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	TIdDOSAttributes* FAttributes;
	void __fastcall SetAttributes(TIdDOSAttributes* AAttributes);
	
public:
	__fastcall virtual TIdDOSBaseFTPListItem(Classes::TCollection* AOwner);
	__fastcall virtual ~TIdDOSBaseFTPListItem(void);
	__property TIdDOSAttributes* Attributes = {read=FAttributes, write=SetAttributes};
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt IdFILE_ATTRIBUTE_READONLY = 0x1;
static const ShortInt IdFILE_ATTRIBUTE_HIDDEN = 0x2;
static const ShortInt IdFILE_ATTRIBUTE_SYSTEM = 0x4;
static const ShortInt IdFILE_ATTRIBUTE_DIRECTORY = 0x10;
static const ShortInt IdFILE_ATTRIBUTE_ARCHIVE = 0x20;
static const ShortInt IdFILE_ATTRIBUTE_DEVICE = 0x40;
static const Byte IdFILE_ATTRIBUTE_NORMAL = 0x80;
static const Word IdFILE_ATTRIBUTE_TEMPORARY = 0x100;
static const Word IdFILE_ATTRIBUTE_SPARSE_FILE = 0x200;
static const Word IdFILE_ATTRIBUTE_REPARSE_POINT = 0x400;
static const Word IdFILE_ATTRIBUTE_COMPRESSED = 0x800;
static const Word IdFILE_ATTRIBUTE_OFFLINE = 0x1000;
static const Word IdFILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 0x2000;
static const Word IdFILE_ATTRIBUTE_ENCRYPTED = 0x4000;

}	/* namespace Idftplisttypes */
using namespace Idftplisttypes;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplisttypesHPP
