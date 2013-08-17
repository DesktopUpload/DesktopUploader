// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsesupertcp.pas' rev: 20.00

#ifndef IdftplistparsesupertcpHPP
#define IdftplistparsesupertcpHPP

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

//-- user supplied -----------------------------------------------------------
#pragma link "IdFTPListParseSuperTCP"

namespace Idftplistparsesupertcp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSuperTCPFTPListItem;
class PASCALIMPLEMENTATION TIdSuperTCPFTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	System::UnicodeString FShortFileName;
	
public:
	__property System::UnicodeString ShortFileName = {read=FShortFileName, write=FShortFileName};
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdSuperTCPFTPListItem(Classes::TCollection* AOwner) : Idftplist::TIdFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdSuperTCPFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPSuperTCP;
class PASCALIMPLEMENTATION TIdFTPLPSuperTCP : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod bool __fastcall IsValidWin32FileName(const System::UnicodeString AFileName);
	__classmethod bool __fastcall IsValidMSDOSFileName(const System::UnicodeString AFileName);
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPSuperTCP(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPSuperTCP(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsesupertcp */
using namespace Idftplistparsesupertcp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsesupertcpHPP
