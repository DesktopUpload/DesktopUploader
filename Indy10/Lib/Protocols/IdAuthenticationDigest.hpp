// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idauthenticationdigest.pas' rev: 20.00

#ifndef IdauthenticationdigestHPP
#define IdauthenticationdigestHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idauthentication.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idhashmessagedigest.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idauthenticationdigest
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdInvalidAlgorithm;
class PASCALIMPLEMENTATION EIdInvalidAlgorithm : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidAlgorithm(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidAlgorithm(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidAlgorithm(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidAlgorithm(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidAlgorithm(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidAlgorithm(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidAlgorithm(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidAlgorithm(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidAlgorithm(void) { }
	
};


class DELPHICLASS TIdDigestAuthentication;
class PASCALIMPLEMENTATION TIdDigestAuthentication : public Idauthentication::TIdAuthentication
{
	typedef Idauthentication::TIdAuthentication inherited;
	
protected:
	System::UnicodeString FRealm;
	bool FStale;
	System::UnicodeString FOpaque;
	Classes::TStringList* FDomain;
	System::UnicodeString Fnonce;
	int FNoncecount;
	System::UnicodeString FAlgorithm;
	System::UnicodeString FMethod;
	System::UnicodeString FUri;
	Classes::TStringList* FPostbody;
	Classes::TStringList* FQopOptions;
	Classes::TStringList* FOther;
	virtual Idauthentication::TIdAuthWhatsNext __fastcall DoNext(void);
	virtual int __fastcall GetSteps(void);
	
public:
	__fastcall virtual ~TIdDigestAuthentication(void);
	virtual System::UnicodeString __fastcall Authentication();
	__property System::UnicodeString Method = {read=FMethod, write=FMethod};
	__property System::UnicodeString Uri = {read=FUri, write=FUri};
	__property Classes::TStringList* Postbody = {read=FPostbody, write=FPostbody};
	__property System::UnicodeString Realm = {read=FRealm};
public:
	/* TIdAuthentication.Create */ inline __fastcall virtual TIdDigestAuthentication(void) : Idauthentication::TIdAuthentication() { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idauthenticationdigest */
using namespace Idauthenticationdigest;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdauthenticationdigestHPP
