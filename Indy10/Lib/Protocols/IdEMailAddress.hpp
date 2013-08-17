// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idemailaddress.pas' rev: 20.00

#ifndef IdemailaddressHPP
#define IdemailaddressHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idemailaddress
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdEmailParseError;
class PASCALIMPLEMENTATION EIdEmailParseError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdEmailParseError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdEmailParseError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdEmailParseError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdEmailParseError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdEmailParseError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdEmailParseError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdEmailParseError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdEmailParseError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdEmailParseError(void) { }
	
};


class DELPHICLASS TIdEMailAddressItem;
class PASCALIMPLEMENTATION TIdEMailAddressItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FAddress;
	System::UnicodeString FName;
	System::UnicodeString __fastcall GetText();
	void __fastcall SetText(System::UnicodeString AText);
	System::UnicodeString __fastcall ConvertAddress();
	System::UnicodeString __fastcall GetDomain();
	void __fastcall SetDomain(const System::UnicodeString ADomain);
	System::UnicodeString __fastcall GetUsername();
	void __fastcall SetUsername(const System::UnicodeString AUsername);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall TIdEMailAddressItem(void)/* overload */;
	__fastcall virtual TIdEMailAddressItem(Classes::TCollection* ACollection)/* overload */;
	__fastcall TIdEMailAddressItem(const System::UnicodeString AText)/* overload */;
	
__published:
	__property System::UnicodeString Address = {read=FAddress, write=FAddress};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property System::UnicodeString Text = {read=GetText, write=SetText};
	__property System::UnicodeString Domain = {read=GetDomain, write=SetDomain};
	__property System::UnicodeString User = {read=GetUsername, write=SetUsername};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdEMailAddressItem(void) { }
	
};


class DELPHICLASS TIdEMailAddressList;
class PASCALIMPLEMENTATION TIdEMailAddressList : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdEMailAddressItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdEMailAddressItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdEMailAddressItem* Value);
	System::UnicodeString __fastcall GetEMailAddresses();
	void __fastcall SetEMailAddresses(System::UnicodeString AList);
	
public:
	__fastcall TIdEMailAddressList(Classes::TPersistent* AOwner);
	void __fastcall FillTStrings(Classes::TStrings* AStrings);
	HIDESBASE TIdEMailAddressItem* __fastcall Add(void);
	void __fastcall AddItems(TIdEMailAddressList* AList);
	void __fastcall GetDomains(Classes::TStrings* AStrings);
	void __fastcall SortByDomain(void);
	void __fastcall AddressesByDomain(TIdEMailAddressList* AList, const System::UnicodeString ADomain);
	__property TIdEMailAddressItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property System::UnicodeString EMailAddresses = {read=GetEMailAddresses, write=SetEMailAddresses};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdEMailAddressList(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idemailaddress */
using namespace Idemailaddress;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdemailaddressHPP
