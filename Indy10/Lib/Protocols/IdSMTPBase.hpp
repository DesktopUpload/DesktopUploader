// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsmtpbase.pas' rev: 20.00

#ifndef IdsmtpbaseHPP
#define IdsmtpbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsmtpbase
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdSMTPFailedRecipient)(System::TObject* Sender, const System::UnicodeString AAddress, const System::UnicodeString ACode, const System::UnicodeString AText, bool &VContinue);

class DELPHICLASS TIdSMTPBase;
class PASCALIMPLEMENTATION TIdSMTPBase : public Idmessageclient::TIdMessageClient
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	System::UnicodeString FMailAgent;
	System::UnicodeString FHeloName;
	bool FPipeline;
	bool FUseEHLO;
	TIdSMTPFailedRecipient FOnFailedRecipient;
	virtual bool __fastcall GetSupportsTLS(void);
	virtual Idreply::TIdReplyClass __fastcall GetReplyClass(void);
	virtual void __fastcall InitComponent(void);
	void __fastcall SendGreeting(void);
	virtual void __fastcall SetUseEhlo(const bool AValue);
	void __fastcall SetPipeline(const bool AValue);
	void __fastcall StartTLS(void);
	bool __fastcall FailedRecipientCanContinue(const System::UnicodeString AAddress);
	bool __fastcall WriteRecipientNoPipelining(const Idemailaddress::TIdEMailAddressItem* AEmailAddress);
	void __fastcall WriteRecipientsNoPipelining(Idemailaddress::TIdEMailAddressList* AList);
	void __fastcall SendNoPipelining(Idmessage::TIdMessage* AMsg, const System::UnicodeString AFrom, Idemailaddress::TIdEMailAddressList* ARecipients)/* overload */;
	void __fastcall WriteRecipientPipeLine(const Idemailaddress::TIdEMailAddressItem* AEmailAddress);
	void __fastcall WriteRecipientsPipeLine(Idemailaddress::TIdEMailAddressList* AList);
	void __fastcall SendPipelining(Idmessage::TIdMessage* AMsg, const System::UnicodeString AFrom, Idemailaddress::TIdEMailAddressList* ARecipients);
	void __fastcall InternalSend(Idmessage::TIdMessage* AMsg, const System::UnicodeString AFrom, Idemailaddress::TIdEMailAddressList* ARecipients)/* overload */;
	
public:
	virtual void __fastcall Send(Idmessage::TIdMessage* AMsg)/* overload */;
	virtual void __fastcall Send(Idmessage::TIdMessage* AMsg, Idemailaddress::TIdEMailAddressList* ARecipients)/* overload */;
	
__published:
	__property System::UnicodeString MailAgent = {read=FMailAgent, write=FMailAgent};
	__property System::UnicodeString HeloName = {read=FHeloName, write=FHeloName};
	__property bool UseEhlo = {read=FUseEHLO, write=SetUseEhlo, default=1};
	__property bool PipeLine = {read=FPipeline, write=SetPipeline, default=0};
	__property TIdSMTPFailedRecipient OnFailedRecipient = {read=FOnFailedRecipient, write=FOnFailedRecipient};
public:
	/* TIdMessageClient.Destroy */ inline __fastcall virtual ~TIdSMTPBase(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSMTPBase(Classes::TComponent* AOwner)/* overload */ : Idmessageclient::TIdMessageClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool DEF_SMTP_PIPELINE = false;
static const bool IdDEF_UseEhlo = true;
#define CAPAPIPELINE L"PIPELINING"
#define XMAILER_HEADER L"X-Mailer"
extern PACKAGE StaticArray<short, 2> RCPTTO_ACCEPT;
extern PACKAGE short MAILFROM_ACCEPT;
extern PACKAGE short DATA_ACCEPT;
extern PACKAGE short DATA_PERIOD_ACCEPT;
extern PACKAGE short RSET_ACCEPT;
#define RSET_CMD L"RSET"
#define MAILFROM_CMD L"MAIL FROM:"
#define RCPTTO_CMD L"RCPT TO:"
#define DATA_CMD L"DATA"

}	/* namespace Idsmtpbase */
using namespace Idsmtpbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsmtpbaseHPP
