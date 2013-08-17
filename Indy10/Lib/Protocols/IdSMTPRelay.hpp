// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsmtprelay.pas' rev: 20.00

#ifndef IdsmtprelayHPP
#define IdsmtprelayHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Iddnsresolver.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idsmtpbase.hpp>	// Pascal unit
#include <Idreplysmtp.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsmtprelay
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdSMTPRelayStatusAction { dmResolveMS, dmConnecting, dmConnected, dmSending, dmWorkBegin, dmWorkEndOK, dmWorkEndWithException };
#pragma option pop

typedef void __fastcall (__closure *TIdSMTPRelayStatus)(System::TObject* Sender, Idemailaddress::TIdEMailAddressItem* AEMailAddress, TIdSMTPRelayStatusAction Action);

class DELPHICLASS EIdDirectSMTPCannotAssignHost;
class PASCALIMPLEMENTATION EIdDirectSMTPCannotAssignHost : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDirectSMTPCannotAssignHost(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDirectSMTPCannotAssignHost(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDirectSMTPCannotAssignHost(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDirectSMTPCannotAssignHost(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDirectSMTPCannotAssignHost(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDirectSMTPCannotAssignHost(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDirectSMTPCannotAssignHost(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDirectSMTPCannotAssignHost(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDirectSMTPCannotAssignHost(void) { }
	
};


class DELPHICLASS EIdDirectSMTPCannotResolveMX;
class PASCALIMPLEMENTATION EIdDirectSMTPCannotResolveMX : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDirectSMTPCannotResolveMX(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDirectSMTPCannotResolveMX(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDirectSMTPCannotResolveMX(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDirectSMTPCannotResolveMX(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDirectSMTPCannotResolveMX(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDirectSMTPCannotResolveMX(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDirectSMTPCannotResolveMX(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDirectSMTPCannotResolveMX(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDirectSMTPCannotResolveMX(void) { }
	
};


#pragma option push -b-
enum TIdSSLSupport { NoSSL, SupportSSL, RequireSSL };
#pragma option pop

class DELPHICLASS TIdSMTPRelayStatusItem;
class PASCALIMPLEMENTATION TIdSMTPRelayStatusItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	bool FSent;
	System::UnicodeString FExceptionMessage;
	System::UnicodeString FEmailAddress;
	int FReplyCode;
	Idreplysmtp::TIdSMTPEnhancedCode* FEnhancedCode;
	void __fastcall SetEnhancedCode(const Idreplysmtp::TIdSMTPEnhancedCode* Value);
	
public:
	__fastcall virtual TIdSMTPRelayStatusItem(Classes::TCollection* Collection);
	__fastcall virtual ~TIdSMTPRelayStatusItem(void);
	
__published:
	__property System::UnicodeString EmailAddress = {read=FEmailAddress, write=FEmailAddress};
	__property System::UnicodeString ExceptionMessage = {read=FExceptionMessage, write=FExceptionMessage};
	__property bool Sent = {read=FSent, write=FSent, default=0};
	__property int ReplyCode = {read=FReplyCode, write=FReplyCode, default=0};
	__property Idreplysmtp::TIdSMTPEnhancedCode* EnhancedCode = {read=FEnhancedCode, write=SetEnhancedCode};
};


class DELPHICLASS TIdSMTPRelayStatusList;
class PASCALIMPLEMENTATION TIdSMTPRelayStatusList : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdSMTPRelayStatusItem* operator[](int Index) { return Items[Index]; }
	
protected:
	TIdSMTPRelayStatusItem* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, const TIdSMTPRelayStatusItem* Value);
	
public:
	HIDESBASE TIdSMTPRelayStatusItem* __fastcall Add(void);
	__property TIdSMTPRelayStatusItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TIdSMTPRelayStatusList(Classes::TPersistent* AOwner, Classes::TCollectionItemClass ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdSMTPRelayStatusList(void) { }
	
};


class DELPHICLASS TIdSSLSupportOptions;
class DELPHICLASS TIdSMTPRelay;
class PASCALIMPLEMENTATION TIdSSLSupportOptions : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TIdSSLSupport FSSLSupport;
	bool FTryImplicitTLS;
	TIdSMTPRelay* FOwner;
	void __fastcall SetSSLSupport(const TIdSSLSupport Value);
	void __fastcall SetTryImplicitTLS(const bool Value);
	
public:
	__fastcall TIdSSLSupportOptions(TIdSMTPRelay* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TIdSSLSupport SSLSupport = {read=FSSLSupport, write=SetSSLSupport, default=0};
	__property bool TryImplicitTLS = {read=FTryImplicitTLS, write=SetTryImplicitTLS, default=0};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdSSLSupportOptions(void) { }
	
};


class PASCALIMPLEMENTATION TIdSMTPRelay : public Idsmtpbase::TIdSMTPBase
{
	typedef Idsmtpbase::TIdSMTPBase inherited;
	
protected:
	Classes::TStrings* FMXServerList;
	TIdSMTPRelayStatusList* FStatusList;
	System::UnicodeString FDNSServer;
	TIdSMTPRelayStatus FOnDirectSMTPStatus;
	System::UnicodeString FMailAgent;
	System::UnicodeString FHeloName;
	bool FPipeline;
	bool FUseEHLO;
	TIdSSLSupportOptions* FSSLOptions;
	System::UnicodeString FRelaySender;
	HIDESBASE void __fastcall Connect(Idemailaddress::TIdEMailAddressItem* AEMailAddress);
	void __fastcall ResolveMXServers(System::UnicodeString AAddress);
	void __fastcall SetDNSServer(const System::UnicodeString Value);
	void __fastcall SetOnStatus(const TIdSMTPRelayStatus Value);
	virtual void __fastcall SetUseEhlo(const bool AValue);
	virtual void __fastcall SetHost(const System::UnicodeString Value);
	virtual bool __fastcall GetSupportsTLS(void);
	void __fastcall ProcessException(Sysutils::Exception* AException, Idemailaddress::TIdEMailAddressItem* AEMailAddress);
	void __fastcall SetSSLOptions(const TIdSSLSupportOptions* Value);
	void __fastcall SetRelaySender(const System::UnicodeString Value);
	virtual void __fastcall InitComponent(void);
	__property Port;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall virtual ~TIdSMTPRelay(void);
	virtual void __fastcall DisconnectNotifyPeer(void);
	virtual void __fastcall Send(Idmessage::TIdMessage* AMsg, Idemailaddress::TIdEMailAddressList* ARecipients)/* overload */;
	
__published:
	__property System::UnicodeString DNSServer = {read=FDNSServer, write=SetDNSServer};
	__property System::UnicodeString RelaySender = {read=FRelaySender, write=SetRelaySender};
	__property TIdSMTPRelayStatusList* StatusList = {read=FStatusList};
	__property TIdSSLSupportOptions* SSLOptions = {read=FSSLOptions, write=SetSSLOptions};
	__property TIdSMTPRelayStatus OnDirectSMTPStatus = {read=FOnDirectSMTPStatus, write=SetOnStatus};
	__property OnTLSHandShakeFailed;
	__property OnTLSNotAvailable;
	__property OnTLSNegCmdFailed;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSMTPRelay(Classes::TComponent* AOwner)/* overload */ : Idsmtpbase::TIdSMTPBase(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Send(Idmessage::TIdMessage* AMsg){ Idsmtpbase::TIdSMTPBase::Send(AMsg); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool DEF_OneConnectionPerDomain = true;
static const TIdSSLSupport DEF_SSL_SUPPORT = (TIdSSLSupport)(0);
static const bool DEF_TRY_IMPLICITTLS = false;
static const ShortInt DEF_REPLY_CODE = 0x0;
static const bool DEF_SENT = false;

}	/* namespace Idsmtprelay */
using namespace Idsmtprelay;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsmtprelayHPP
