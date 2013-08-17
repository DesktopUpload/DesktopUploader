// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcookiemanager.pas' rev: 20.00

#ifndef IdcookiemanagerHPP
#define IdcookiemanagerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcookie.hpp>	// Pascal unit
#include <Iduri.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcookiemanager
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TOnNewCookieEvent)(System::TObject* ASender, Idcookie::TIdCookieRFC2109* ACookie, bool &VAccept);

typedef void __fastcall (__closure *TOnCookieManagerEvent)(System::TObject* ASender, Idcookie::TIdCookies* ACookieCollection);

typedef TOnCookieManagerEvent TOnCookieCreateEvent;

typedef TOnCookieManagerEvent TOnCookieDestroyEvent;

class DELPHICLASS TIdCookieManager;
class PASCALIMPLEMENTATION TIdCookieManager : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TOnCookieManagerEvent FOnCreate;
	TOnCookieManagerEvent FOnDestroy;
	TOnNewCookieEvent FOnNewCookie;
	Idcookie::TIdCookies* FCookieCollection;
	void __fastcall CleanupCookieList(void);
	void __fastcall DoAdd(Idcookie::TIdCookieRFC2109* ACookie, System::UnicodeString ACookieText, System::UnicodeString AHost);
	virtual void __fastcall DoOnCreate(void);
	virtual void __fastcall DoOnDestroy(void);
	virtual bool __fastcall DoOnNewCookie(Idcookie::TIdCookieRFC2109* ACookie);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdCookieManager(void);
	void __fastcall AddCookie(System::UnicodeString ACookie, System::UnicodeString AHost);
	void __fastcall AddCookie2(System::UnicodeString ACookie, System::UnicodeString AHost);
	void __fastcall AddCookies(TIdCookieManager* ASource);
	void __fastcall CopyCookie(Idcookie::TIdCookieRFC2109* ACookie);
	System::UnicodeString __fastcall GenerateCookieList(Iduri::TIdURI* URL, bool SecureConnection = false);
	__property Idcookie::TIdCookies* CookieCollection = {read=FCookieCollection};
	
__published:
	__property TOnCookieManagerEvent OnCreate = {read=FOnCreate, write=FOnCreate};
	__property TOnCookieManagerEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property TOnNewCookieEvent OnNewCookie = {read=FOnNewCookie, write=FOnNewCookie};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCookieManager(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcookiemanager */
using namespace Idcookiemanager;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcookiemanagerHPP
