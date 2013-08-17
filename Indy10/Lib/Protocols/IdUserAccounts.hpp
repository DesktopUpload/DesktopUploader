// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iduseraccounts.pas' rev: 20.00

#ifndef IduseraccountsHPP
#define IduseraccountsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idstrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iduseraccounts
{
//-- type declarations -------------------------------------------------------
typedef unsigned TIdUserHandle;

typedef int TIdUserAccess;

#pragma option push -b-
enum TIdCustomUserManagerOption { umoCaseSensitiveUsername, umoCaseSensitivePassword };
#pragma option pop

typedef Set<TIdCustomUserManagerOption, umoCaseSensitiveUsername, umoCaseSensitivePassword>  TIdCustomUserManagerOptions;

typedef void __fastcall (__closure *TIdUserManagerAuthenticationEvent)(System::TObject* Sender, const System::UnicodeString AUsername, System::UnicodeString &VPassword, unsigned &VUserHandle, int &VUserAccess);

typedef void __fastcall (__closure *TIdUserManagerLogoffEvent)(System::TObject* Sender, unsigned &VUserHandle);

class DELPHICLASS TIdCustomUserManager;
class PASCALIMPLEMENTATION TIdCustomUserManager : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	System::UnicodeString FDomain;
	TIdUserManagerAuthenticationEvent FOnAfterAuthentication;
	TIdUserManagerAuthenticationEvent FOnBeforeAuthentication;
	TIdUserManagerLogoffEvent FOnLogoffUser;
	virtual void __fastcall DoBeforeAuthentication(const System::UnicodeString AUsername, System::UnicodeString &VPassword, unsigned &VUserHandle, int &VUserAccess);
	virtual void __fastcall DoAuthentication(const System::UnicodeString AUsername, System::UnicodeString &VPassword, unsigned &VUserHandle, int &VUserAccess) = 0 ;
	virtual void __fastcall DoAfterAuthentication(const System::UnicodeString AUsername, System::UnicodeString &VPassword, unsigned &VUserHandle, int &VUserAccess);
	virtual void __fastcall DoLogoffUser(unsigned &VUserHandle);
	virtual TIdCustomUserManagerOptions __fastcall GetOptions(void);
	virtual void __fastcall SetDomain(const System::UnicodeString AValue);
	virtual void __fastcall SetOptions(const TIdCustomUserManagerOptions AValue);
	__property System::UnicodeString Domain = {read=FDomain, write=SetDomain};
	__property TIdCustomUserManagerOptions Options = {read=GetOptions, write=SetOptions, nodefault};
	__property TIdUserManagerAuthenticationEvent OnBeforeAuthentication = {read=FOnBeforeAuthentication, write=FOnBeforeAuthentication};
	__property TIdUserManagerAuthenticationEvent OnAfterAuthentication = {read=FOnAfterAuthentication, write=FOnAfterAuthentication};
	__property TIdUserManagerLogoffEvent OnLogoffUser = {read=FOnLogoffUser, write=FOnLogoffUser};
	
public:
	virtual System::UnicodeString __fastcall ChallengeUser(bool &VIsSafe, const System::UnicodeString AUserName);
	bool __fastcall AuthenticateUser(const System::UnicodeString AUsername, const System::UnicodeString APassword)/* overload */;
	int __fastcall AuthenticateUser(const System::UnicodeString AUsername, const System::UnicodeString APassword, unsigned &VUserHandle)/* overload */;
	__classmethod bool __fastcall IsRegisteredUser(int AUserAccess);
	virtual void __fastcall LogoffUser(unsigned AUserHandle);
	virtual void __fastcall UserDisconnected(const System::UnicodeString AUser);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomUserManager(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdCustomUserManager(void) { }
	
};


class DELPHICLASS TIdSimpleUserManager;
class PASCALIMPLEMENTATION TIdSimpleUserManager : public TIdCustomUserManager
{
	typedef TIdCustomUserManager inherited;
	
protected:
	TIdCustomUserManagerOptions FOptions;
	TIdUserManagerAuthenticationEvent FOnAuthentication;
	virtual void __fastcall DoAuthentication(const System::UnicodeString AUsername, System::UnicodeString &VPassword, unsigned &VUserHandle, int &VUserAccess);
	virtual TIdCustomUserManagerOptions __fastcall GetOptions(void);
	virtual void __fastcall SetOptions(const TIdCustomUserManagerOptions AValue);
	
__published:
	__property Domain;
	__property Options;
	__property OnBeforeAuthentication;
	__property TIdUserManagerAuthenticationEvent OnAuthentication = {read=FOnAuthentication, write=FOnAuthentication};
	__property OnAfterAuthentication;
	__property OnLogoffUser;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSimpleUserManager(Classes::TComponent* AOwner)/* overload */ : TIdCustomUserManager(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdSimpleUserManager(void) { }
	
};


class DELPHICLASS TIdUserAccount;
class PASCALIMPLEMENTATION TIdUserAccount : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	Classes::TStrings* FAttributes;
	System::TObject* FData;
	System::UnicodeString FUserName;
	System::UnicodeString FPassword;
	System::UnicodeString FRealName;
	int FAccess;
	void __fastcall SetAttributes(const Classes::TStrings* AValue);
	virtual void __fastcall SetPassword(const System::UnicodeString AValue);
	
public:
	__fastcall virtual TIdUserAccount(Classes::TCollection* ACollection);
	__fastcall virtual ~TIdUserAccount(void);
	virtual bool __fastcall CheckPassword(const System::UnicodeString APassword);
	__property System::TObject* Data = {read=FData, write=FData};
	
__published:
	__property int Access = {read=FAccess, write=FAccess, default=0};
	__property Classes::TStrings* Attributes = {read=FAttributes, write=SetAttributes};
	__property System::UnicodeString UserName = {read=FUserName, write=FUserName};
	__property System::UnicodeString Password = {read=FPassword, write=SetPassword};
	__property System::UnicodeString RealName = {read=FRealName, write=FRealName};
};


class DELPHICLASS TIdUserAccounts;
class DELPHICLASS TIdUserManager;
class PASCALIMPLEMENTATION TIdUserAccounts : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdUserAccount* operator[](const System::UnicodeString AUserName) { return UserNames[AUserName]; }
	
protected:
	bool FCaseSensitiveUsernames;
	bool FCaseSensitivePasswords;
	TIdUserAccount* __fastcall GetAccount(const int AIndex);
	TIdUserAccount* __fastcall GetByUsername(const System::UnicodeString AUsername);
	void __fastcall SetAccount(const int AIndex, TIdUserAccount* AAccountValue);
	
public:
	HIDESBASE TIdUserAccount* __fastcall Add(void);
	__fastcall TIdUserAccounts(TIdUserManager* AOwner);
	__property bool CaseSensitiveUsernames = {read=FCaseSensitiveUsernames, write=FCaseSensitiveUsernames, nodefault};
	__property bool CaseSensitivePasswords = {read=FCaseSensitivePasswords, write=FCaseSensitivePasswords, nodefault};
	__property TIdUserAccount* UserNames[const System::UnicodeString AUserName] = {read=GetByUsername/*, default*/};
	__property TIdUserAccount* Items[const int AIndex] = {read=GetAccount, write=SetAccount};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdUserAccounts(void) { }
	
};


class PASCALIMPLEMENTATION TIdUserManager : public TIdCustomUserManager
{
	typedef TIdCustomUserManager inherited;
	
protected:
	TIdUserAccounts* FAccounts;
	virtual void __fastcall DoAuthentication(const System::UnicodeString AUsername, System::UnicodeString &VPassword, unsigned &VUserHandle, int &VUserAccess);
	virtual TIdCustomUserManagerOptions __fastcall GetOptions(void);
	void __fastcall SetAccounts(TIdUserAccounts* AValue);
	virtual void __fastcall SetOptions(const TIdCustomUserManagerOptions AValue);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdUserManager(void);
	
__published:
	__property TIdUserAccounts* Accounts = {read=FAccounts, write=SetAccounts};
	__property Options;
	__property OnBeforeAuthentication;
	__property OnAfterAuthentication;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUserManager(Classes::TComponent* AOwner)/* overload */ : TIdCustomUserManager(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE unsigned IdUserHandleNone;
extern PACKAGE unsigned IdUserHandleBroadcast;
extern PACKAGE int IdUserAccessDenied;
static const ShortInt IdUserAccountDefaultAccess = 0x0;

}	/* namespace Iduseraccounts */
using namespace Iduseraccounts;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IduseraccountsHPP
