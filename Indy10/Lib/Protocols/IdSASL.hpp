// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsasl.pas' rev: 20.00

#ifndef IdsaslHPP
#define IdsaslHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsasl
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdSASLResult { srSuccess, srFailure, srAborted };
#pragma option pop

typedef SmallString<20>  TIdSASLServiceName;

class DELPHICLASS TIdSASL;
class PASCALIMPLEMENTATION TIdSASL : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	unsigned FSecurityLevel;
	unsigned __fastcall GetSecurityLevel(void);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdSASL(void);
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName) = 0 ;
	virtual System::UnicodeString __fastcall ContinueAuthenticate(const System::UnicodeString ALastResponse, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	virtual void __fastcall FinishAuthenticate(void);
	virtual bool __fastcall IsReadyToStart(void);
	virtual bool __fastcall IsAuthProtocolAvailable(Classes::TStrings* AFeatStrings);
	__property unsigned SecurityLevel = {read=GetSecurityLevel, nodefault};
	__classmethod virtual TIdSASLServiceName __fastcall ServiceName();
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASL(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Classes::TThreadList* GlobalSASLList;

}	/* namespace Idsasl */
using namespace Idsasl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsaslHPP
