// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsasl_cram_sha1.pas' rev: 20.00

#ifndef Idsasl_cram_sha1HPP
#define Idsasl_cram_sha1HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsasl_crambase.hpp>	// Pascal unit
#include <Idsasluserpass.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsasl_cram_sha1
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLCRAMSHA1;
class PASCALIMPLEMENTATION TIdSASLCRAMSHA1 : public Idsasl_crambase::TIdSASLCRAMBase
{
	typedef Idsasl_crambase::TIdSASLCRAMBase inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall BuildKeydAuth(const System::UnicodeString APassword, const System::UnicodeString AChallenge);
	__classmethod virtual Idsasl::TIdSASLServiceName __fastcall ServiceName();
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLCRAMSHA1(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLCRAMSHA1(Classes::TComponent* AOwner)/* overload */ : Idsasl_crambase::TIdSASLCRAMBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsasl_cram_sha1 */
using namespace Idsasl_cram_sha1;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idsasl_cram_sha1HPP
