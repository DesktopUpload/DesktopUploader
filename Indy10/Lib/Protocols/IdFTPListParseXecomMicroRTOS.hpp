// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsexecommicrortos.pas' rev: 20.00

#ifndef IdftplistparsexecommicrortosHPP
#define IdftplistparsexecommicrortosHPP

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
#pragma link "IdFTPListParseXecomMicroRTOS"

namespace Idftplistparsexecommicrortos
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdXecomMicroRTOSTPListItem;
class PASCALIMPLEMENTATION TIdXecomMicroRTOSTPListItem : public Idftplist::TIdFTPListItem
{
	typedef Idftplist::TIdFTPListItem inherited;
	
protected:
	unsigned FMemStart;
	unsigned FMemEnd;
	
public:
	__fastcall virtual TIdXecomMicroRTOSTPListItem(Classes::TCollection* AOwner);
	__property unsigned MemStart = {read=FMemStart, write=FMemStart, nodefault};
	__property unsigned MemEnd = {read=FMemEnd, write=FMemEnd, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdXecomMicroRTOSTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPXecomMicroRTOS;
class PASCALIMPLEMENTATION TIdFTPLPXecomMicroRTOS : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall IsFooter(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPXecomMicroRTOS(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPXecomMicroRTOS(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsexecommicrortos */
using namespace Idftplistparsexecommicrortos;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsexecommicrortosHPP
