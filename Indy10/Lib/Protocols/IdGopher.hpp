// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idgopher.pas' rev: 20.00

#ifndef IdgopherHPP
#define IdgopherHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idgopher
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdGopherMenuItem;
class PASCALIMPLEMENTATION TIdGopherMenuItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FTitle;
	System::WideChar FItemType;
	System::UnicodeString FSelector;
	System::UnicodeString FServer;
	System::Word FPort;
	bool FGopherPlusItem;
	Idheaderlist::TIdHeaderList* FGopherBlock;
	Classes::TStrings* FViews;
	System::UnicodeString FURL;
	Classes::TStrings* FAbstract;
	Idheaderlist::TIdHeaderList* FAsk;
	Idemailaddress::TIdEMailAddressItem* fAdminEmail;
	System::UnicodeString __fastcall GetLastModified();
	System::UnicodeString __fastcall GetOrganization();
	System::UnicodeString __fastcall GetLocation();
	System::UnicodeString __fastcall GetGeog();
	
public:
	__fastcall virtual TIdGopherMenuItem(Classes::TCollection* ACollection);
	__fastcall virtual ~TIdGopherMenuItem(void);
	virtual void __fastcall DoneSettingInfoBlock(void);
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
	__property System::WideChar ItemType = {read=FItemType, write=FItemType, nodefault};
	__property System::UnicodeString Selector = {read=FSelector, write=FSelector};
	__property System::UnicodeString Server = {read=FServer, write=FServer};
	__property System::Word Port = {read=FPort, write=FPort, nodefault};
	__property bool GopherPlusItem = {read=FGopherPlusItem, write=FGopherPlusItem, nodefault};
	__property Idheaderlist::TIdHeaderList* GopherBlock = {read=FGopherBlock};
	__property System::UnicodeString URL = {read=FURL};
	__property Classes::TStrings* Views = {read=FViews};
	__property Classes::TStrings* AAbstract = {read=FAbstract};
	__property System::UnicodeString LastModified = {read=GetLastModified};
	__property Idemailaddress::TIdEMailAddressItem* AdminEMail = {read=fAdminEmail};
	__property System::UnicodeString Organization = {read=GetOrganization};
	__property System::UnicodeString Location = {read=GetLocation};
	__property System::UnicodeString Geog = {read=GetGeog};
	__property Idheaderlist::TIdHeaderList* Ask = {read=FAsk};
};


class DELPHICLASS TIdGopherMenu;
class PASCALIMPLEMENTATION TIdGopherMenu : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdGopherMenuItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdGopherMenuItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdGopherMenuItem* Value);
	
public:
	__fastcall TIdGopherMenu(void);
	HIDESBASE TIdGopherMenuItem* __fastcall Add(void);
	__property TIdGopherMenuItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdGopherMenu(void) { }
	
};


typedef void __fastcall (__closure *TIdGopherMenuEvent)(System::TObject* Sender, TIdGopherMenuItem* MenuItem);

class DELPHICLASS TIdGopher;
class PASCALIMPLEMENTATION TIdGopher : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	TIdGopherMenuEvent FOnMenuItem;
	void __fastcall DoMenu(TIdGopherMenuItem* MenuItem);
	void __fastcall ProcessGopherError(void);
	TIdGopherMenuItem* __fastcall MenuItemFromString(System::UnicodeString stLine, TIdGopherMenu* Menu);
	TIdGopherMenu* __fastcall ProcessDirectory(System::UnicodeString PreviousData = L"", const int ExpectedLength = 0x0);
	TIdGopherMenu* __fastcall LoadExtendedDirectory(System::UnicodeString PreviousData = L"", const int ExpectedLength = 0x0);
	void __fastcall ProcessFile(Classes::TStream* ADestStream, System::UnicodeString APreviousData = L"", const int ExpectedLength = 0x0);
	void __fastcall ProcessTextFile(Classes::TStream* ADestStream, System::UnicodeString APreviousData = L"", const int ExpectedLength = 0x0);
	virtual void __fastcall InitComponent(void);
	
public:
	TIdGopherMenu* __fastcall GetMenu(System::UnicodeString ASelector, bool IsGopherPlus = false, System::UnicodeString AView = L"");
	TIdGopherMenu* __fastcall Search(System::UnicodeString ASelector, System::UnicodeString AQuery);
	void __fastcall GetFile(System::UnicodeString ASelector, Classes::TStream* ADestStream, bool IsGopherPlus = false, System::UnicodeString AView = L"");
	void __fastcall GetTextFile(System::UnicodeString ASelector, Classes::TStream* ADestStream, bool IsGopherPlus = false, System::UnicodeString AView = L"");
	TIdGopherMenu* __fastcall GetExtendedMenu(System::UnicodeString ASelector, System::UnicodeString AView = L"");
	
__published:
	__property TIdGopherMenuEvent OnMenuItem = {read=FOnMenuItem, write=FOnMenuItem};
	__property Port = {default=70};
	__property Host;
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdGopher(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdGopher(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idgopher */
using namespace Idgopher;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdgopherHPP
