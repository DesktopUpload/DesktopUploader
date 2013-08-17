// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsemusic.pas' rev: 20.00

#ifndef IdftplistparsemusicHPP
#define IdftplistparsemusicHPP

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
#pragma link "IdFTPListParseMusic"

namespace Idftplistparsemusic
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMusicFTPListItem;
class PASCALIMPLEMENTATION TIdMusicFTPListItem : public Idftplisttypes::TIdRecFTPListItem
{
	typedef Idftplisttypes::TIdRecFTPListItem inherited;
	
protected:
	System::UnicodeString FOwnerName;
	
public:
	__property System::UnicodeString OwnerName = {read=FOwnerName, write=FOwnerName};
	__property RecLength;
	__property RecFormat;
	__property NumberRecs;
public:
	/* TIdFTPListItem.Create */ inline __fastcall virtual TIdMusicFTPListItem(Classes::TCollection* AOwner) : Idftplisttypes::TIdRecFTPListItem(AOwner) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMusicFTPListItem(void) { }
	
};


class DELPHICLASS TIdFTPLPMusic;
class PASCALIMPLEMENTATION TIdFTPLPMusic : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMusic(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMusic(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsemusic */
using namespace Idftplistparsemusic;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsemusicHPP
