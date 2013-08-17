// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsaslexternal.pas' rev: 20.00

#ifndef IdsaslexternalHPP
#define IdsaslexternalHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsaslexternal
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLExternal;
class PASCALIMPLEMENTATION TIdSASLExternal : public Idsasl::TIdSASL
{
	typedef Idsasl::TIdSASL inherited;
	
protected:
	System::UnicodeString FAuthIdentity;
	virtual void __fastcall InitComponent(void);
	
public:
	virtual bool __fastcall IsReadyToStart(void);
	__classmethod virtual Idsasl::TIdSASLServiceName __fastcall ServiceName();
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	
__published:
	__property System::UnicodeString AuthorizationIdentity = {read=FAuthIdentity, write=FAuthIdentity};
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLExternal(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLExternal(Classes::TComponent* AOwner)/* overload */ : Idsasl::TIdSASL(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsaslexternal */
using namespace Idsaslexternal;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsaslexternalHPP
