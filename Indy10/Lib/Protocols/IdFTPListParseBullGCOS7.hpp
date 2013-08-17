// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsebullgcos7.pas' rev: 20.00

#ifndef Idftplistparsebullgcos7HPP
#define Idftplistparsebullgcos7HPP

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
#pragma link "IdFTPListParseBullGCOS7"

namespace Idftplistparsebullgcos7
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdFTPLPGOS7;
class PASCALIMPLEMENTATION TIdFTPLPGOS7 : public Idftplistparsebase::TIdFTPLineOwnedList
{
	typedef Idftplistparsebase::TIdFTPLineOwnedList inherited;
	
protected:
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPGOS7(void) : Idftplistparsebase::TIdFTPLineOwnedList() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPGOS7(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsebullgcos7 */
using namespace Idftplistparsebullgcos7;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idftplistparsebullgcos7HPP
