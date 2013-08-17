// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmappedpop3.pas' rev: 20.00

#ifndef Idmappedpop3HPP
#define Idmappedpop3HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idmappedporttcp.hpp>	// Pascal unit
#include <Idmappedtelnet.hpp>	// Pascal unit
#include <Idreplypop3.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmappedpop3
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMappedPOP3Thread;
class PASCALIMPLEMENTATION TIdMappedPOP3Thread : public Idmappedtelnet::TIdMappedTelnetThread
{
	typedef Idmappedtelnet::TIdMappedTelnetThread inherited;
	
protected:
	virtual void __fastcall OutboundConnect(void);
public:
	/* TIdMappedPortContext.Create */ inline __fastcall virtual TIdMappedPOP3Thread(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList) : Idmappedtelnet::TIdMappedTelnetThread(AConnection, AYarn, AList) { }
	/* TIdMappedPortContext.Destroy */ inline __fastcall virtual ~TIdMappedPOP3Thread(void) { }
	
};


class DELPHICLASS TIdMappedPOP3;
class PASCALIMPLEMENTATION TIdMappedPOP3 : public Idmappedtelnet::TIdMappedTelnet
{
	typedef Idmappedtelnet::TIdMappedTelnet inherited;
	
protected:
	Idreplypop3::TIdReplyPOP3* FReplyUnknownCommand;
	Idreplypop3::TIdReplyPOP3* FGreeting;
	System::UnicodeString FUserHostDelimiter;
	virtual void __fastcall InitComponent(void);
	void __fastcall SetGreeting(Idreplypop3::TIdReplyPOP3* AValue);
	void __fastcall SetReplyUnknownCommand(const Idreplypop3::TIdReplyPOP3* AValue);
	
public:
	__fastcall virtual ~TIdMappedPOP3(void);
	
__published:
	__property Idreplypop3::TIdReplyPOP3* Greeting = {read=FGreeting, write=SetGreeting};
	__property Idreplypop3::TIdReplyPOP3* ReplyUnknownCommand = {read=FReplyUnknownCommand, write=SetReplyUnknownCommand};
	__property DefaultPort = {default=110};
	__property MappedPort = {default=110};
	__property System::UnicodeString UserHostDelimiter = {read=FUserHostDelimiter, write=FUserHostDelimiter};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMappedPOP3(Classes::TComponent* AOwner)/* overload */ : Idmappedtelnet::TIdMappedTelnet(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmappedpop3 */
using namespace Idmappedpop3;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idmappedpop3HPP
