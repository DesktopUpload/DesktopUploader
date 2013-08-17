// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcookie.pas' rev: 20.00

#ifndef IdcookieHPP
#define IdcookieHPP

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
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcookie
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdCookieVersion { cvNetscape, cvRFC2109, cvRFC2965 };
#pragma option pop

class DELPHICLASS TIdCookieList;
class DELPHICLASS TIdNetscapeCookie;
class PASCALIMPLEMENTATION TIdCookieList : public Classes::TStringList
{
	typedef Classes::TStringList inherited;
	
protected:
	TIdNetscapeCookie* __fastcall GetCookie(int Index);
	
public:
	__property TIdNetscapeCookie* Cookies[int Index] = {read=GetCookie};
public:
	/* TStringList.Create */ inline __fastcall TIdCookieList(void)/* overload */ : Classes::TStringList() { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TIdCookieList(void) { }
	
};


class DELPHICLASS TIdCookieDomainList;
class PASCALIMPLEMENTATION TIdCookieDomainList : public Classes::TStringList
{
	typedef Classes::TStringList inherited;
	
protected:
	TIdCookieList* __fastcall GetCookieList(int Index);
	
public:
	__property TIdCookieList* CookieList[int Index] = {read=GetCookieList};
public:
	/* TStringList.Create */ inline __fastcall TIdCookieDomainList(void)/* overload */ : Classes::TStringList() { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TIdCookieDomainList(void) { }
	
};


class PASCALIMPLEMENTATION TIdNetscapeCookie : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FCookieText;
	System::UnicodeString FDomain;
	System::UnicodeString FExpires;
	bool FHttpOnly;
	System::UnicodeString FName;
	System::UnicodeString FPath;
	bool FSecure;
	System::UnicodeString FValue;
	TIdCookieVersion FInternalVersion;
	virtual System::UnicodeString __fastcall GetCookie();
	virtual void __fastcall SetExpires(const System::UnicodeString AValue);
	void __fastcall SetCookie(const System::UnicodeString AValue);
	virtual System::UnicodeString __fastcall GetServerCookie();
	virtual System::UnicodeString __fastcall GetClientCookie();
	virtual void __fastcall LoadProperties(Classes::TStrings* APropertyList);
	
public:
	__fastcall virtual TIdNetscapeCookie(Classes::TCollection* ACollection);
	__fastcall virtual ~TIdNetscapeCookie(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString ClientCookie = {read=GetClientCookie};
	__property System::UnicodeString CookieName = {read=FName, write=FName};
	__property System::UnicodeString CookieText = {read=GetCookie, write=SetCookie};
	__property System::UnicodeString Domain = {read=FDomain, write=FDomain};
	__property System::UnicodeString Expires = {read=FExpires, write=SetExpires};
	__property bool HttpOnly = {read=FHttpOnly, write=FHttpOnly, nodefault};
	__property System::UnicodeString Path = {read=FPath, write=FPath};
	__property bool Secure = {read=FSecure, write=FSecure, nodefault};
	__property System::UnicodeString ServerCookie = {read=GetServerCookie};
	__property System::UnicodeString Value = {read=FValue, write=FValue};
};


class DELPHICLASS TIdCookieRFC2109;
class PASCALIMPLEMENTATION TIdCookieRFC2109 : public TIdNetscapeCookie
{
	typedef TIdNetscapeCookie inherited;
	
protected:
	__int64 FMax_Age;
	System::UnicodeString FVersion;
	System::UnicodeString FComment;
	virtual System::UnicodeString __fastcall GetClientCookie();
	virtual System::UnicodeString __fastcall GetCookie();
	virtual void __fastcall SetExpires(const System::UnicodeString AValue);
	virtual void __fastcall LoadProperties(Classes::TStrings* APropertyList);
	
public:
	__fastcall virtual TIdCookieRFC2109(Classes::TCollection* ACollection);
	__property System::UnicodeString Comment = {read=FComment, write=FComment};
	__property __int64 MaxAge = {read=FMax_Age, write=FMax_Age};
	__property System::UnicodeString Version = {read=FVersion, write=FVersion};
public:
	/* TIdNetscapeCookie.Destroy */ inline __fastcall virtual ~TIdCookieRFC2109(void) { }
	
};


class DELPHICLASS TIdCookieRFC2965;
class PASCALIMPLEMENTATION TIdCookieRFC2965 : public TIdCookieRFC2109
{
	typedef TIdCookieRFC2109 inherited;
	
private:
	typedef DynamicArray<int> _TIdCookieRFC2965__1;
	
	
protected:
	System::UnicodeString FCommentURL;
	bool FDiscard;
	_TIdCookieRFC2965__1 FPortList;
	virtual System::UnicodeString __fastcall GetCookie();
	virtual void __fastcall LoadProperties(Classes::TStrings* APropertyList);
	void __fastcall SetPort(int AIndex, int AValue);
	int __fastcall GetPort(int AIndex);
	
public:
	__fastcall virtual TIdCookieRFC2965(Classes::TCollection* ACollection);
	__property System::UnicodeString CommentURL = {read=FCommentURL, write=FCommentURL};
	__property bool Discard = {read=FDiscard, write=FDiscard, nodefault};
	__property int PortList[int AIndex] = {read=GetPort, write=SetPort};
public:
	/* TIdNetscapeCookie.Destroy */ inline __fastcall virtual ~TIdCookieRFC2965(void) { }
	
};


typedef TMetaClass* TIdNetscapeCookieClass;

typedef TMetaClass* TIdCookieRFC2109Class;

typedef TMetaClass* TIdCookieRFC2965Class;

class DELPHICLASS TIdServerCookie;
class PASCALIMPLEMENTATION TIdServerCookie : public TIdCookieRFC2109
{
	typedef TIdCookieRFC2109 inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCookie();
	
public:
	__fastcall virtual TIdServerCookie(Classes::TCollection* ACollection);
	void __fastcall AddAttribute(const System::UnicodeString Attribute, const System::UnicodeString Value);
public:
	/* TIdNetscapeCookie.Destroy */ inline __fastcall virtual ~TIdServerCookie(void) { }
	
};


#pragma option push -b-
enum TIdCookieAccess { caRead, caReadWrite };
#pragma option pop

class DELPHICLASS TIdCookies;
class PASCALIMPLEMENTATION TIdCookies : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdCookieRFC2109* operator[](int Index) { return Items[Index]; }
	
protected:
	TIdCookieDomainList* FCookieListByDomain;
	Sysutils::TMultiReadExclusiveWriteSynchronizer* FRWLock;
	TIdCookieRFC2109* __fastcall GetCookie(const System::UnicodeString AName, const System::UnicodeString ADomain);
	HIDESBASE TIdCookieRFC2109* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdCookieRFC2109* Value);
	
public:
	__fastcall TIdCookies(Classes::TPersistent* AOwner);
	__fastcall virtual ~TIdCookies(void);
	HIDESBASE TIdCookieRFC2109* __fastcall Add(void);
	TIdCookieRFC2965* __fastcall Add2(void);
	void __fastcall AddCookie(TIdCookieRFC2109* ACookie);
	void __fastcall AddSrcCookie(const System::UnicodeString ACookie);
	void __fastcall AddCookies(TIdCookies* ASource);
	virtual void __fastcall Assign(Classes::TPersistent* ASource);
	HIDESBASE void __fastcall Clear(void);
	HIDESBASE void __fastcall Delete(int Index);
	int __fastcall GetCookieIndex(int FirstIndex, const System::UnicodeString AName)/* overload */;
	int __fastcall GetCookieIndex(int FirstIndex, const System::UnicodeString AName, const System::UnicodeString ADomain)/* overload */;
	TIdCookieDomainList* __fastcall LockCookieListByDomain(TIdCookieAccess AAccessType);
	void __fastcall UnlockCookieListByDomain(TIdCookieAccess AAccessType);
	__property TIdCookieRFC2109* Cookie[const System::UnicodeString AName][const System::UnicodeString ADomain] = {read=GetCookie};
	__property TIdCookieRFC2109* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


class DELPHICLASS TIdServerCookies;
class PASCALIMPLEMENTATION TIdServerCookies : public TIdCookies
{
	typedef TIdCookies inherited;
	
protected:
	HIDESBASE TIdCookieRFC2109* __fastcall GetCookie(const System::UnicodeString AName);
	
public:
	HIDESBASE TIdServerCookie* __fastcall Add(void);
	__property TIdCookieRFC2109* Cookie[const System::UnicodeString AName] = {read=GetCookie};
public:
	/* TIdCookies.Create */ inline __fastcall TIdServerCookies(Classes::TPersistent* AOwner) : TIdCookies(AOwner) { }
	/* TIdCookies.Destroy */ inline __fastcall virtual ~TIdServerCookies(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt GFMaxAge = -1;

}	/* namespace Idcookie */
using namespace Idcookie;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcookieHPP
