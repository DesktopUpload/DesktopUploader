// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsaslanonymous.pas' rev: 20.00

#ifndef IdsaslanonymousHPP
#define IdsaslanonymousHPP

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

namespace Idsaslanonymous
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLAnonymous;
class PASCALIMPLEMENTATION TIdSASLAnonymous : public Idsasl::TIdSASL
{
	typedef Idsasl::TIdSASL inherited;
	
protected:
	System::UnicodeString FTraceInfo;
	virtual void __fastcall InitComponent(void);
	
public:
	virtual bool __fastcall IsReadyToStart(void);
	__classmethod virtual Idsasl::TIdSASLServiceName __fastcall ServiceName();
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	
__published:
	__property System::UnicodeString TraceInfo = {read=FTraceInfo, write=FTraceInfo};
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLAnonymous(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLAnonymous(Classes::TComponent* AOwner)/* overload */ : Idsasl::TIdSASL(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsaslanonymous */
using namespace Idsaslanonymous;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsaslanonymousHPP
