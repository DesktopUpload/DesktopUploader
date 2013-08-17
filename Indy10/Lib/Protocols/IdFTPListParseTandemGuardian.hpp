// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsetandemguardian.pas' rev: 20.00

#ifndef IdftplistparsetandemguardianHPP
#define IdftplistparsetandemguardianHPP

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
#pragma link "IdFTPListParseTandemGuardian"

namespace Idftplistparsetandemguardian
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTandemGuardianFTPListItem;
class PASCALIMPLEMENTATION TIdTandemGuardianFTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	System::UnicodeString FGroupName;
	unsigned FCode;
	System::UnicodeString FPermissions;
	
public:
	__property System::UnicodeString GroupName = {read=FGroupName, write=FGroupName};
	__property unsigned Code = {read=FCode, write=FCode, nodefault};
	__property System::UnicodeString Permissions = {read=FPermissions, write=FPermissions};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdTandemGuardianFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdOwnerFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdTandemGuardianFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPTandemGuardian;
class PASCALIMPLEMENTATION TIdFTPLPTandemGuardian : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPTandemGuardian(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPTandemGuardian(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define TANDEM_GUARDIAN_ID L"Tandem NonStop Guardian"

}	/* namespace Idftplistparsetandemguardian */
using namespace Idftplistparsetandemguardian;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsetandemguardianHPP
