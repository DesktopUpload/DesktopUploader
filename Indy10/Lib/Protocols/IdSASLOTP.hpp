// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsaslotp.pas' rev: 20.00

#ifndef IdsaslotpHPP
#define IdsaslotpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsasluserpass.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsaslotp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLOTP;
class PASCALIMPLEMENTATION TIdSASLOTP : public Idsasluserpass::TIdSASLUserPass
{
	typedef Idsasluserpass::TIdSASLUserPass inherited;
	
protected:
	System::UnicodeString __fastcall GenerateOTP(const System::UnicodeString AResponse, const System::UnicodeString APassword);
	virtual void __fastcall InitComponent(void);
	
public:
	__classmethod virtual Idsasl::TIdSASLServiceName __fastcall ServiceName();
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	virtual System::UnicodeString __fastcall ContinueAuthenticate(const System::UnicodeString ALastResponse, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLOTP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLOTP(Classes::TComponent* AOwner)/* overload */ : Idsasluserpass::TIdSASLUserPass(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsaslotp */
using namespace Idsaslotp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsaslotpHPP
