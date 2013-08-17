// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplist.pas' rev: 20.00

#ifndef IdftplistHPP
#define IdftplistHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idftpcommon.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftplist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdInvalidFTPListingFormat;
class PASCALIMPLEMENTATION EIdInvalidFTPListingFormat : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidFTPListingFormat(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidFTPListingFormat(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidFTPListingFormat(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidFTPListingFormat(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidFTPListingFormat(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidFTPListingFormat(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidFTPListingFormat(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidFTPListingFormat(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidFTPListingFormat(void) { }
	
};


#pragma option push -b-
enum TIdDirItemType { ditDirectory, ditFile, ditSymbolicLink, ditSymbolicLinkDir, ditBlockDev, ditCharDev, ditFIFO, ditSocket };
#pragma option pop

typedef System::UnicodeString TIdFTPFileName;

class DELPHICLASS TIdFTPListItem;
class PASCALIMPLEMENTATION TIdFTPListItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	__int64 FSize;
	System::UnicodeString FData;
	System::UnicodeString FFileName;
	System::UnicodeString FLocalFileName;
	bool FSizeAvail;
	bool FModifiedAvail;
	System::TDateTime FModifiedDate;
	System::TDateTime FModifiedDateGMT;
	TIdDirItemType FItemType;
	bool FDirError;
	System::UnicodeString FPermissionDisplay;
	void __fastcall SetFileName(const System::UnicodeString AValue);
	__property System::TDateTime ModifiedDateGMT = {read=FModifiedDateGMT, write=FModifiedDateGMT};
	
public:
	__fastcall virtual TIdFTPListItem(Classes::TCollection* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString Data = {read=FData, write=FData};
	__property __int64 Size = {read=FSize, write=FSize};
	__property System::TDateTime ModifiedDate = {read=FModifiedDate, write=FModifiedDate};
	__property System::UnicodeString FileName = {read=FFileName, write=SetFileName};
	__property System::UnicodeString LocalFileName = {read=FLocalFileName, write=FLocalFileName};
	__property TIdDirItemType ItemType = {read=FItemType, write=FItemType, nodefault};
	__property bool SizeAvail = {read=FSizeAvail, write=FSizeAvail, nodefault};
	__property bool ModifiedAvail = {read=FModifiedAvail, write=FModifiedAvail, nodefault};
	__property System::UnicodeString PermissionDisplay = {read=FPermissionDisplay, write=FPermissionDisplay};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdFTPListItem(void) { }
	
};


typedef void __fastcall (__closure *TIdFTPListOnGetCustomListFormat)(TIdFTPListItem* AItem, System::UnicodeString &VText);

typedef void __fastcall (__closure *TIdOnParseCustomListFormat)(TIdFTPListItem* AItem);

class DELPHICLASS TIdFTPListItems;
class PASCALIMPLEMENTATION TIdFTPListItems : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdFTPListItem* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	System::UnicodeString FDirectoryName;
	void __fastcall SetDirectoryName(const System::UnicodeString AValue);
	TIdFTPListItem* __fastcall GetItems(int AIndex);
	void __fastcall SetItems(int AIndex, const TIdFTPListItem* Value);
	
public:
	HIDESBASE TIdFTPListItem* __fastcall Add(void);
	__fastcall TIdFTPListItems(void);
	int __fastcall IndexOf(TIdFTPListItem* AItem);
	__property System::UnicodeString DirectoryName = {read=FDirectoryName, write=SetDirectoryName};
	__property TIdFTPListItem* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdFTPListItems(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplist */
using namespace Idftplist;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistHPP
