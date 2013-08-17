// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtelnetserver.pas' rev: 20.00

#ifndef IdtelnetserverHPP
#define IdtelnetserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtelnetserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTelnetData;
class PASCALIMPLEMENTATION TTelnetData : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString Username;
	System::UnicodeString Password;
	unsigned HUserToken;
public:
	/* TObject.Create */ inline __fastcall TTelnetData(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TTelnetData(void) { }
	
};


class DELPHICLASS TIdTelnetServerContext;
class PASCALIMPLEMENTATION TIdTelnetServerContext : public Idcustomtcpserver::TIdServerContext
{
	typedef Idcustomtcpserver::TIdServerContext inherited;
	
private:
	TTelnetData* FTelnetData;
	
public:
	__fastcall virtual TIdTelnetServerContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__fastcall virtual ~TIdTelnetServerContext(void);
	__property TTelnetData* TelnetData = {read=FTelnetData};
};


typedef void __fastcall (__closure *TIdTelnetNegotiateEvent)(Idcontext::TIdContext* AContext);

typedef void __fastcall (__closure *TAuthenticationEvent)(Idcontext::TIdContext* AContext, const System::UnicodeString AUsername, const System::UnicodeString APassword, bool &AAuthenticated);

class DELPHICLASS TIdTelnetServer;
class PASCALIMPLEMENTATION TIdTelnetServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	int FLoginAttempts;
	TAuthenticationEvent FOnAuthentication;
	System::UnicodeString FLoginMessage;
	TIdTelnetNegotiateEvent FOnNegotiate;
	virtual void __fastcall DoConnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
public:
	virtual bool __fastcall DoAuthenticate(Idcontext::TIdContext* AContext, const System::UnicodeString AUsername, const System::UnicodeString APassword);
	virtual void __fastcall DoNegotiate(Idcontext::TIdContext* AContext);
	
__published:
	__property DefaultPort = {default=23};
	__property int LoginAttempts = {read=FLoginAttempts, write=FLoginAttempts, default=3};
	__property System::UnicodeString LoginMessage = {read=FLoginMessage, write=FLoginMessage};
	__property TAuthenticationEvent OnAuthentication = {read=FOnAuthentication, write=FOnAuthentication};
	__property TIdTelnetNegotiateEvent OnNegotiate = {read=FOnNegotiate, write=FOnNegotiate};
	__property OnExecute;
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdTelnetServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTelnetServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt GLoginAttempts = 0x3;

}	/* namespace Idtelnetserver */
using namespace Idtelnetserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtelnetserverHPP
