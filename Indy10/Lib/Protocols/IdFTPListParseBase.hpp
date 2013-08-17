// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsebase.pas' rev: 20.00

#ifndef IdftplistparsebaseHPP
#define IdftplistparsebaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftplistparsebase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdFTPListBase;
class PASCALIMPLEMENTATION TIdFTPListBase : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPListBase(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPListBase(void) { }
	
};


typedef TMetaClass* TIdFTPListParseClass;

class DELPHICLASS TIdFTPListBaseHeader;
class PASCALIMPLEMENTATION TIdFTPListBaseHeader : public TIdFTPListBase
{
	typedef TIdFTPListBase inherited;
	
protected:
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall IsFooter(const System::UnicodeString AData);
	
public:
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPListBaseHeader(void) : TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPListBaseHeader(void) { }
	
};


class DELPHICLASS TIdFTPLineOwnedList;
class PASCALIMPLEMENTATION TIdFTPLineOwnedList : public TIdFTPListBase
{
	typedef TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLineOwnedList(void) : TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLineOwnedList(void) { }
	
};


class DELPHICLASS TIdFTPLPNList;
class PASCALIMPLEMENTATION TIdFTPLPNList : public TIdFTPListBase
{
	typedef TIdFTPListBase inherited;
	
protected:
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPNList(void) : TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPNList(void) { }
	
};


class DELPHICLASS TIdFTPLPMList;
class PASCALIMPLEMENTATION TIdFTPLPMList : public TIdFTPListBase
{
	typedef TIdFTPListBase inherited;
	
protected:
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMList(void) : TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMList(void) { }
	
};


class DELPHICLASS TIdFTPLPBaseDOS;
class PASCALIMPLEMENTATION TIdFTPLPBaseDOS : public TIdFTPListBase
{
	typedef TIdFTPListBase inherited;
	
protected:
	__classmethod virtual bool __fastcall IsValidAttr(const System::UnicodeString AAttr);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPBaseDOS(void) : TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPBaseDOS(void) { }
	
};


class DELPHICLASS EIdFTPListParseError;
class PASCALIMPLEMENTATION EIdFTPListParseError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPListParseError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPListParseError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPListParseError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPListParseError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPListParseError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPListParseError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPListParseError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPListParseError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPListParseError(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define NLST L"NLST"
#define MLST L"MLST"
extern PACKAGE void __fastcall RegisterFTPListParser(const TIdFTPListParseClass AParser);
extern PACKAGE void __fastcall UnregisterFTPListParser(const TIdFTPListParseClass AParser);
extern PACKAGE bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir, const System::UnicodeString AFormatID);
extern PACKAGE bool __fastcall CheckListParse(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir, System::UnicodeString &AFormat, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
extern PACKAGE System::UnicodeString __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
extern PACKAGE bool __fastcall CheckListParseCapa(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir, System::UnicodeString &VFormat, TIdFTPListParseClass &VClass, const System::UnicodeString ASysDescript, const bool ADetails = true);
extern PACKAGE void __fastcall EnumFTPListParsers(Classes::TStrings* AData);

}	/* namespace Idftplistparsebase */
using namespace Idftplistparsebase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsebaseHPP
