// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsmtp.pas' rev: 20.00

#ifndef IdsmtpHPP
#define IdsmtpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsaslcollection.hpp>	// Pascal unit
#include <Idsmtpbase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsmtp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdSMTPAuthenticationType { satNone, satDefault, satSASL };
#pragma option pop

class DELPHICLASS TIdSMTP;
class PASCALIMPLEMENTATION TIdSMTP : public Idsmtpbase::TIdSMTPBase
{
	typedef Idsmtpbase::TIdSMTPBase inherited;
	
protected:
	TIdSMTPAuthenticationType FAuthType;
	bool FDidAuthenticate;
	Idsaslcollection::TIdSASLEntries* FSASLMechanisms;
	void __fastcall SetAuthType(const TIdSMTPAuthenticationType AValue);
	virtual void __fastcall SetUseEhlo(const bool AValue);
	virtual void __fastcall SetUseTLS(Idexplicittlsclientserverbase::TIdUseTLS AValue);
	void __fastcall SetSASLMechanisms(Idsaslcollection::TIdSASLEntries* AValue);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property OnConnected;
	
public:
	__fastcall virtual ~TIdSMTP(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall Authenticate(void);
	virtual void __fastcall Connect(void)/* overload */;
	virtual void __fastcall Disconnect(bool ANotifyPeer)/* overload */;
	virtual void __fastcall DisconnectNotifyPeer(void);
	__classmethod void __fastcall QuickSend(const System::UnicodeString AHost, const System::UnicodeString ASubject, const System::UnicodeString ATo, const System::UnicodeString AFrom, const System::UnicodeString AText);
	virtual void __fastcall Send(Idmessage::TIdMessage* AMsg, Idemailaddress::TIdEMailAddressList* ARecipients)/* overload */;
	virtual void __fastcall Expand(System::UnicodeString AUserName, Classes::TStrings* AResults);
	virtual System::UnicodeString __fastcall Verify(System::UnicodeString AUserName);
	__property bool DidAuthenticate = {read=FDidAuthenticate, nodefault};
	
__published:
	__property TIdSMTPAuthenticationType AuthType = {read=FAuthType, write=FAuthType, default=1};
	__property Host;
	__property Password;
	__property Port = {default=25};
	__property Idsaslcollection::TIdSASLEntries* SASLMechanisms = {read=FSASLMechanisms, write=SetSASLMechanisms};
	__property UseTLS = {default=0};
	__property Username;
	__property OnTLSNotAvailable;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSMTP(Classes::TComponent* AOwner)/* overload */ : Idsmtpbase::TIdSMTPBase(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	inline void __fastcall  Disconnect(void){ Idtcpconnection::TIdTCPConnection::Disconnect(); }
	inline void __fastcall  Send(Idmessage::TIdMessage* AMsg){ Idsmtpbase::TIdSMTPBase::Send(AMsg); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const TIdSMTPAuthenticationType DEF_SMTP_AUTH = (TIdSMTPAuthenticationType)(1);

}	/* namespace Idsmtp */
using namespace Idsmtp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsmtpHPP
