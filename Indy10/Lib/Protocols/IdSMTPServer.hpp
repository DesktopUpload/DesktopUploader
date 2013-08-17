// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsmtpserver.pas' rev: 20.00

#ifndef IdsmtpserverHPP
#define IdsmtpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcmdtcpserver.hpp>	// Pascal unit
#include <Idcommandhandlers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Idreplysmtp.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsmtpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdSMTPServerError;
class PASCALIMPLEMENTATION EIdSMTPServerError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSMTPServerError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSMTPServerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSMTPServerError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSMTPServerError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSMTPServerError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSMTPServerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSMTPServerError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSMTPServerError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSMTPServerError(void) { }
	
};


class DELPHICLASS EIdSMTPServerNoRcptTo;
class PASCALIMPLEMENTATION EIdSMTPServerNoRcptTo : public EIdSMTPServerError
{
	typedef EIdSMTPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSMTPServerNoRcptTo(const System::UnicodeString AMsg)/* overload */ : EIdSMTPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSMTPServerNoRcptTo(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSMTPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSMTPServerNoRcptTo(int Ident)/* overload */ : EIdSMTPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSMTPServerNoRcptTo(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSMTPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSMTPServerNoRcptTo(const System::UnicodeString Msg, int AHelpContext) : EIdSMTPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSMTPServerNoRcptTo(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSMTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSMTPServerNoRcptTo(int Ident, int AHelpContext)/* overload */ : EIdSMTPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSMTPServerNoRcptTo(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSMTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSMTPServerNoRcptTo(void) { }
	
};


#pragma option push -b-
enum TIdMailFromReply { mAccept, mReject, mSystemFull, mLimitExceeded };
#pragma option pop

#pragma option push -b-
enum TIdRCPToReply { rAddressOk, rRelayDenied, rInvalid, rWillForward, rNoForward, rTooManyAddresses, rDisabledPerm, rDisabledTemp, rSystemFull, rLimitExceeded };
#pragma option pop

#pragma option push -b-
enum TIdDataReply { dOk, dMBFull, dSystemFull, dLocalProcessingError, dTransactionFailed, dLimitExceeded };
#pragma option pop

#pragma option push -b-
enum TIdSPFReply { spfNone, spfNeutral, spfPass, spfFail, spfSoftFail, spfTempError, spfPermError };
#pragma option pop

class DELPHICLASS TIdSMTPServerContext;
typedef void __fastcall (__closure *TOnMailFromEvent)(TIdSMTPServerContext* ASender, const System::UnicodeString AAddress, Classes::TStrings* AParams, TIdMailFromReply &VAction);

typedef void __fastcall (__closure *TOnMsgReceive)(TIdSMTPServerContext* ASender, Classes::TStream* AMsg, TIdDataReply &VAction);

typedef void __fastcall (__closure *TOnRcptToEvent)(TIdSMTPServerContext* ASender, const System::UnicodeString AAddress, Classes::TStrings* AParams, TIdRCPToReply &VAction, System::UnicodeString &VForward);

typedef void __fastcall (__closure *TOnReceived)(TIdSMTPServerContext* ASender, System::UnicodeString &AReceived);

typedef void __fastcall (__closure *TOnSMTPEvent)(TIdSMTPServerContext* ASender);

typedef void __fastcall (__closure *TOnSMTPUserLoginEvent)(TIdSMTPServerContext* ASender, const System::UnicodeString AUsername, const System::UnicodeString APassword, bool &VAuthenticated);

typedef void __fastcall (__closure *TOnSPFCheck)(TIdSMTPServerContext* ASender, const System::UnicodeString AIP, const System::UnicodeString ADomain, const System::UnicodeString AIdentity, TIdSPFReply &VAction);

class DELPHICLASS TIdSMTPServer;
class PASCALIMPLEMENTATION TIdSMTPServer : public Idexplicittlsclientserverbase::TIdExplicitTLSServer
{
	typedef Idexplicittlsclientserverbase::TIdExplicitTLSServer inherited;
	
protected:
	TOnMailFromEvent FOnMailFrom;
	TOnMsgReceive FOnMsgReceive;
	TOnRcptToEvent FOnRcptTo;
	TOnReceived FOnReceived;
	TOnSMTPEvent FOnReset;
	TOnSPFCheck FOnSPFCheck;
	TOnSMTPUserLoginEvent FOnUserLogin;
	System::UnicodeString FServerName;
	bool FAllowPipelining;
	int FMaxMsgSize;
	virtual Idreply::TIdReply* __fastcall CreateGreeting(void);
	virtual Idreply::TIdReply* __fastcall CreateReplyUnknownCommand(void);
	void __fastcall DoAuthLogin(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString Login);
	void __fastcall CommandNOOP(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandQUIT(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandEHLO(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandHELO(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandAUTH(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandMAIL(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandRCPT(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandDATA(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandRSET(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandSTARTTLS(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall AuthFailed(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CmdSyntaxError(Idcontext::TIdContext* AContext, System::UnicodeString ALine, const Idreply::TIdReply* AReply = (Idreply::TIdReply*)(0x0))/* overload */;
	void __fastcall CmdSyntaxError(Idcommandhandlers::TIdCommand* ASender)/* overload */;
	void __fastcall BadSequenceError(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall InvalidSyntax(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall NoHello(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MustUseTLS(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailFromAccept(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall MailFromReject(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall AddrValid(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall AddrInvalid(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall AddrWillForward(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"", const System::UnicodeString ATo = L"");
	void __fastcall AddrNotWillForward(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"", const System::UnicodeString ATo = L"");
	void __fastcall AddrDisabledPerm(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall AddrDisabledTemp(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall AddrNoRelaying(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AAddress = L"");
	void __fastcall AddrTooManyRecipients(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailSubmitOk(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailSubmitLimitExceeded(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailSubmitStorageExceededFull(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailSubmitTransactionFailed(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailSubmitLocalProcessingError(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall MailSubmitSystemFull(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall SetEnhReply(Idreply::TIdReply* AReply, const int ANumericCode, const System::UnicodeString AEnhReply, const System::UnicodeString AText, const bool IsEHLO);
	virtual Idreply::TIdReplyClass __fastcall GetReplyClass(void);
	virtual Idreply::TIdRepliesClass __fastcall GetRepliesClass(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall DoReplyUnknownCommand(Idcontext::TIdContext* AContext, System::UnicodeString ALine);
	virtual void __fastcall InitializeCommandHandlers(void);
	void __fastcall DoReset(TIdSMTPServerContext* AContext, bool AIsTLSReset = false);
	void __fastcall SetMaxMsgSize(int AValue);
	bool __fastcall SPFAuthOk(TIdSMTPServerContext* AContext, Idreply::TIdReply* AReply, const System::UnicodeString ACmd, const System::UnicodeString ADomain, const System::UnicodeString AIdentity);
	
__published:
	__property TOnMailFromEvent OnMailFrom = {read=FOnMailFrom, write=FOnMailFrom};
	__property TOnMsgReceive OnMsgReceive = {read=FOnMsgReceive, write=FOnMsgReceive};
	__property TOnRcptToEvent OnRcptTo = {read=FOnRcptTo, write=FOnRcptTo};
	__property TOnReceived OnReceived = {read=FOnReceived, write=FOnReceived};
	__property TOnSMTPEvent OnReset = {read=FOnReset, write=FOnReset};
	__property TOnSPFCheck OnSPFCheck = {read=FOnSPFCheck, write=FOnSPFCheck};
	__property TOnSMTPUserLoginEvent OnUserLogin = {read=FOnUserLogin, write=FOnUserLogin};
	__property bool AllowPipelining = {read=FAllowPipelining, write=FAllowPipelining, default=0};
	__property DefaultPort = {default=25};
	__property int MaxMsgSize = {read=FMaxMsgSize, write=SetMaxMsgSize, default=0};
	__property System::UnicodeString ServerName = {read=FServerName, write=FServerName};
	__property UseTLS = {default=0};
public:
	/* TIdCmdTCPServer.Destroy */ inline __fastcall virtual ~TIdSMTPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSMTPServer(Classes::TComponent* AOwner)/* overload */ : Idexplicittlsclientserverbase::TIdExplicitTLSServer(AOwner) { }
	
};


#pragma option push -b-
enum TIdSMTPState { idSMTPNone, idSMTPHelo, idSMTPMail, idSMTPRcpt, idSMTPData };
#pragma option pop

class PASCALIMPLEMENTATION TIdSMTPServerContext : public Idcustomtcpserver::TIdServerContext
{
	typedef Idcustomtcpserver::TIdServerContext inherited;
	
protected:
	TIdSMTPState FSMTPState;
	System::UnicodeString FFrom;
	Idemailaddress::TIdEMailAddressList* FRCPTList;
	bool FHELO;
	bool FEHLO;
	System::UnicodeString FHeloString;
	System::UnicodeString FUsername;
	System::UnicodeString FPassword;
	bool FLoggedIn;
	int FMsgSize;
	bool FPipeLining;
	bool FFinalStage;
	bool __fastcall GetUsingTLS(void);
	void __fastcall SetPipeLining(const bool AValue);
	
public:
	__fastcall virtual TIdSMTPServerContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__fastcall virtual ~TIdSMTPServerContext(void);
	void __fastcall CheckPipeLine(void);
	virtual void __fastcall Reset(bool AIsTLSReset = false);
	__property TIdSMTPState SMTPState = {read=FSMTPState, write=FSMTPState, nodefault};
	__property System::UnicodeString From = {read=FFrom, write=FFrom};
	__property Idemailaddress::TIdEMailAddressList* RCPTList = {read=FRCPTList};
	__property bool HELO = {read=FHELO, write=FHELO, nodefault};
	__property bool EHLO = {read=FEHLO, write=FEHLO, nodefault};
	__property System::UnicodeString HeloString = {read=FHeloString, write=FHeloString};
	__property System::UnicodeString Username = {read=FUsername, write=FUsername};
	__property System::UnicodeString Password = {read=FPassword, write=FPassword};
	__property bool LoggedIn = {read=FLoggedIn, write=FLoggedIn, nodefault};
	__property int MsgSize = {read=FMsgSize, write=FMsgSize, nodefault};
	__property bool FinalStage = {read=FFinalStage, write=FFinalStage, nodefault};
	__property bool UsingTLS = {read=GetUsingTLS, nodefault};
	__property bool PipeLining = {read=FPipeLining, write=SetPipeLining, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
#define IdSMTPSvrReceivedString L"Received: from $hostname[$ipaddress] (helo=$helo) by $svrh"\
	"ostname[$svripaddress] with $protocol ($servername)"

}	/* namespace Idsmtpserver */
using namespace Idsmtpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsmtpserverHPP
