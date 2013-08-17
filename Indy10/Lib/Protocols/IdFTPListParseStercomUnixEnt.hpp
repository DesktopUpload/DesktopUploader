// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsestercomunixent.pas' rev: 20.00

#ifndef IdftplistparsestercomunixentHPP
#define IdftplistparsestercomunixentHPP

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
#pragma link "IdFTPListParseStercomUnixEnt"

namespace Idftplistparsestercomunixent
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSterCommEntUxFTPListItem;
class PASCALIMPLEMENTATION TIdSterCommEntUxFTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	System::UnicodeString FFlagsProt;
	System::UnicodeString FProtIndicator;
	
public:
	__property System::UnicodeString FlagsProt = {read=FFlagsProt, write=FFlagsProt};
	__property System::UnicodeString ProtIndicator = {read=FProtIndicator, write=FProtIndicator};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdSterCommEntUxFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdSterCommEntUxFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPSterComEntBase;
class PASCALIMPLEMENTATION TIdFTPLPSterComEntBase : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual bool __fastcall IsFooter(const System::UnicodeString AData);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPSterComEntBase(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPSterComEntBase(void) { }
	
};


class DELPHICLASS TIdFTPLPSterCommEntUx;
class PASCALIMPLEMENTATION TIdFTPLPSterCommEntUx : public TIdFTPLPSterComEntBase
{
	typedef TIdFTPLPSterComEntBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPSterCommEntUx(void) : TIdFTPLPSterComEntBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPSterCommEntUx(void) { }
	
};


class DELPHICLASS TIdSterCommEntUxNSFTPListItem;
class PASCALIMPLEMENTATION TIdSterCommEntUxNSFTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdSterCommEntUxNSFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdSterCommEntUxNSFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPSterCommEntUxNS;
class PASCALIMPLEMENTATION TIdFTPLPSterCommEntUxNS : public TIdFTPLPSterComEntBase
{
	typedef TIdFTPLPSterComEntBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod void __fastcall StripPlus(System::UnicodeString &VString);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPSterCommEntUxNS(void) : TIdFTPLPSterComEntBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPSterCommEntUxNS(void) { }
	
};


class DELPHICLASS TIdSterCommEntUxRootFTPListItem;
class PASCALIMPLEMENTATION TIdSterCommEntUxRootFTPListItem : public Idftplisttypes::TIdMinimalFTPListItem
{
	typedef Idftplisttypes::TIdMinimalFTPListItem inherited;
	
public:
	/* TIdMinimalFTPListItem.Create */ inline __fastcall virtual TIdSterCommEntUxRootFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdMinimalFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdSterCommEntUxRootFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPSterCommEntUxRoot;
class PASCALIMPLEMENTATION TIdFTPLPSterCommEntUxRoot : public TIdFTPLPSterComEntBase
{
	typedef TIdFTPLPSterComEntBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsFooter(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPSterCommEntUxRoot(void) : TIdFTPLPSterComEntBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPSterCommEntUxRoot(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define STIRCOMUNIX L"CONNECT:Enterprise for UNIX"
#define STIRCOMUNIXNS L"CONNECT:Enterprise for UNIX$$"
#define STIRCOMUNIXROOT L"CONNECT:Enterprise for UNIX ROOT"

}	/* namespace Idftplistparsestercomunixent */
using namespace Idftplistparsestercomunixent;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsestercomunixentHPP
