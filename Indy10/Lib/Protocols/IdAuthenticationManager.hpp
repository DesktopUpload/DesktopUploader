// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idauthenticationmanager.pas' rev: 20.00

#ifndef IdauthenticationmanagerHPP
#define IdauthenticationmanagerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idauthentication.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Iduri.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idauthenticationmanager
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAuthenticationItem;
class PASCALIMPLEMENTATION TIdAuthenticationItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	Iduri::TIdURI* FURI;
	Classes::TStrings* FParams;
	void __fastcall SetParams(const Classes::TStrings* Value);
	void __fastcall SetURI(const Iduri::TIdURI* Value);
	
public:
	__fastcall virtual TIdAuthenticationItem(Classes::TCollection* ACollection);
	__fastcall virtual ~TIdAuthenticationItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Iduri::TIdURI* URL = {read=FURI, write=SetURI};
	__property Classes::TStrings* Params = {read=FParams, write=SetParams};
};


class DELPHICLASS TIdAuthenticationCollection;
class PASCALIMPLEMENTATION TIdAuthenticationCollection : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
protected:
	TIdAuthenticationItem* __fastcall GetAuthItem(int AIndex);
	void __fastcall SetAuthItem(int AIndex, const TIdAuthenticationItem* Value);
	
public:
	HIDESBASE TIdAuthenticationItem* __fastcall Add(void);
	__fastcall TIdAuthenticationCollection(Classes::TPersistent* AOwner);
	__property TIdAuthenticationItem* Items[int AIndex] = {read=GetAuthItem, write=SetAuthItem};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdAuthenticationCollection(void) { }
	
};


class DELPHICLASS TIdAuthenticationManager;
class PASCALIMPLEMENTATION TIdAuthenticationManager : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TIdAuthenticationCollection* FAuthentications;
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdAuthenticationManager(void);
	void __fastcall AddAuthentication(Idauthentication::TIdAuthentication* AAuthentication, Iduri::TIdURI* AURL);
	__property TIdAuthenticationCollection* Authentications = {read=FAuthentications};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdAuthenticationManager(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idauthenticationmanager */
using namespace Idauthenticationmanager;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdauthenticationmanagerHPP
