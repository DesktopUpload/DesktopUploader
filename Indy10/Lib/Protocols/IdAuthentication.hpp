// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idauthentication.pas' rev: 20.00

#ifndef IdauthenticationHPP
#define IdauthenticationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idauthentication
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdAuthenticationSchemes { asBasic, asDigest, asNTLM, asUnknown };
#pragma option pop

typedef Set<TIdAuthenticationSchemes, asBasic, asUnknown>  TIdAuthSchemeSet;

#pragma option push -b-
enum TIdAuthWhatsNext { wnAskTheProgram, wnDoRequest, wnFail };
#pragma option pop

class DELPHICLASS TIdAuthentication;
class PASCALIMPLEMENTATION TIdAuthentication : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	int FCurrentStep;
	Idheaderlist::TIdHeaderList* FParams;
	Idheaderlist::TIdHeaderList* FAuthParams;
	System::UnicodeString __fastcall ReadAuthInfo(System::UnicodeString AuthName);
	virtual TIdAuthWhatsNext __fastcall DoNext(void) = 0 ;
	void __fastcall SetAuthParams(Idheaderlist::TIdHeaderList* AValue);
	System::UnicodeString __fastcall GetPassword();
	System::UnicodeString __fastcall GetUserName();
	virtual int __fastcall GetSteps(void);
	virtual void __fastcall SetPassword(const System::UnicodeString Value);
	virtual void __fastcall SetUserName(const System::UnicodeString Value);
	
public:
	__fastcall virtual TIdAuthentication(void);
	__fastcall virtual ~TIdAuthentication(void);
	virtual void __fastcall Reset(void);
	virtual System::UnicodeString __fastcall Authentication(void) = 0 ;
	virtual bool __fastcall KeepAlive(void);
	TIdAuthWhatsNext __fastcall Next(void);
	__property Idheaderlist::TIdHeaderList* AuthParams = {read=FAuthParams, write=SetAuthParams};
	__property Idheaderlist::TIdHeaderList* Params = {read=FParams};
	__property System::UnicodeString Username = {read=GetUserName, write=SetUserName};
	__property System::UnicodeString Password = {read=GetPassword, write=SetPassword};
	__property int Steps = {read=GetSteps, nodefault};
	__property int CurrentStep = {read=FCurrentStep, nodefault};
};


typedef TMetaClass* TIdAuthenticationClass;

class DELPHICLASS TIdBasicAuthentication;
class PASCALIMPLEMENTATION TIdBasicAuthentication : public TIdAuthentication
{
	typedef TIdAuthentication inherited;
	
protected:
	System::UnicodeString FRealm;
	virtual TIdAuthWhatsNext __fastcall DoNext(void);
	virtual int __fastcall GetSteps(void);
	
public:
	virtual System::UnicodeString __fastcall Authentication();
	__property System::UnicodeString Realm = {read=FRealm, write=FRealm};
public:
	/* TIdAuthentication.Create */ inline __fastcall virtual TIdBasicAuthentication(void) : TIdAuthentication() { }
	/* TIdAuthentication.Destroy */ inline __fastcall virtual ~TIdBasicAuthentication(void) { }
	
};


class DELPHICLASS EIdAlreadyRegisteredAuthenticationMethod;
class PASCALIMPLEMENTATION EIdAlreadyRegisteredAuthenticationMethod : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdAlreadyRegisteredAuthenticationMethod(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdAlreadyRegisteredAuthenticationMethod(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdAlreadyRegisteredAuthenticationMethod(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterAuthenticationMethod(const System::UnicodeString MethodName, const TIdAuthenticationClass AuthClass);
extern PACKAGE void __fastcall UnregisterAuthenticationMethod(const System::UnicodeString MethodName);
extern PACKAGE TIdAuthenticationClass __fastcall FindAuthClass(const System::UnicodeString AuthName);

}	/* namespace Idauthentication */
using namespace Idauthentication;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdauthenticationHPP
