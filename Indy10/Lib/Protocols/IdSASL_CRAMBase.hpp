// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsasl_crambase.pas' rev: 20.00

#ifndef Idsasl_crambaseHPP
#define Idsasl_crambaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idhmacsha1.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsasluserpass.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsasl_crambase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLCRAMBase;
class PASCALIMPLEMENTATION TIdSASLCRAMBase : public Idsasluserpass::TIdSASLUserPass
{
	typedef Idsasluserpass::TIdSASLUserPass inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall BuildKeydAuth(const System::UnicodeString APassword, const System::UnicodeString AChallenge);
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	virtual System::UnicodeString __fastcall ContinueAuthenticate(const System::UnicodeString ALastResponse, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLCRAMBase(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLCRAMBase(Classes::TComponent* AOwner)/* overload */ : Idsasluserpass::TIdSASLUserPass(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsasl_crambase */
using namespace Idsasl_crambase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idsasl_crambaseHPP
