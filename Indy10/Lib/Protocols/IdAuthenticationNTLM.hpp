// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idauthenticationntlm.pas' rev: 20.00

#ifndef IdauthenticationntlmHPP
#define IdauthenticationntlmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idauthentication.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idauthenticationntlm
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdNTLMAuthentication;
class PASCALIMPLEMENTATION TIdNTLMAuthentication : public Idauthentication::TIdAuthentication
{
	typedef Idauthentication::TIdAuthentication inherited;
	
protected:
	System::UnicodeString FNTLMInfo;
	System::UnicodeString FHost;
	System::UnicodeString FDomain;
	System::UnicodeString FUser;
	virtual Idauthentication::TIdAuthWhatsNext __fastcall DoNext(void);
	virtual int __fastcall GetSteps(void);
	virtual void __fastcall SetUserName(const System::UnicodeString Value);
	
public:
	__fastcall virtual TIdNTLMAuthentication(void);
	virtual System::UnicodeString __fastcall Authentication();
	virtual bool __fastcall KeepAlive(void);
public:
	/* TIdAuthentication.Destroy */ inline __fastcall virtual ~TIdNTLMAuthentication(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idauthenticationntlm */
using namespace Idauthenticationntlm;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdauthenticationntlmHPP
