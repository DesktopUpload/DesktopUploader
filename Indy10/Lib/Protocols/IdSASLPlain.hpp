// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsaslplain.pas' rev: 20.00

#ifndef IdsaslplainHPP
#define IdsaslplainHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsasluserpass.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsaslplain
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLPlain;
class PASCALIMPLEMENTATION TIdSASLPlain : public Idsasluserpass::TIdSASLUserPass
{
	typedef Idsasluserpass::TIdSASLUserPass inherited;
	
protected:
	System::UnicodeString FLoginAs;
	
public:
	virtual bool __fastcall IsReadyToStart(void);
	__classmethod virtual Idsasl::TIdSASLServiceName __fastcall ServiceName();
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	
__published:
	__property System::UnicodeString LoginAs = {read=FLoginAs, write=FLoginAs};
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLPlain(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLPlain(Classes::TComponent* AOwner)/* overload */ : Idsasluserpass::TIdSASLUserPass(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsaslplain */
using namespace Idsaslplain;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsaslplainHPP
