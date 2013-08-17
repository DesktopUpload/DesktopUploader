// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcustomhttpserver.pas' rev: 20.00

#ifndef IdcustomhttpserverHPP
#define IdcustomhttpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idcookie.hpp>	// Pascal unit
#include <Idhttpheaderinfo.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcustomhttpserver
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum THTTPCommandType { hcUnknown, hcHEAD, hcGET, hcPOST, hcDELETE, hcPUT, hcTRACE, hcOPTION };
#pragma option pop

typedef StaticArray<System::UnicodeString, 8> Idcustomhttpserver__1;

class DELPHICLASS TIdHTTPSession;
typedef void __fastcall (__closure *TOnSessionEndEvent)(TIdHTTPSession* Sender);

typedef void __fastcall (__closure *TOnSessionStartEvent)(TIdHTTPSession* Sender);

typedef void __fastcall (__closure *TOnCreateSession)(Idcontext::TIdContext* ASender, TIdHTTPSession* &VHTTPSession);

typedef void __fastcall (__closure *TOnCreatePostStream)(Idcontext::TIdContext* AContext, Idheaderlist::TIdHeaderList* AHeaders, Classes::TStream* &VPostStream);

class DELPHICLASS TIdHTTPRequestInfo;
class DELPHICLASS TIdHTTPResponseInfo;
typedef void __fastcall (__closure *TIdHTTPCommandEvent)(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo);

typedef void __fastcall (__closure *TIdHTTPCommandError)(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo, Sysutils::Exception* AException);

typedef void __fastcall (__closure *TIdHTTPInvalidSessionEvent)(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo, bool &VContinueProcessing, const System::UnicodeString AInvalidSessionID);

typedef void __fastcall (__closure *TIdHTTPHeadersAvailableEvent)(Idcontext::TIdContext* AContext, Idheaderlist::TIdHeaderList* AHeaders, bool &VContinueProcessing);

typedef void __fastcall (__closure *TIdHTTPHeadersBlockedEvent)(Idcontext::TIdContext* AContext, Idheaderlist::TIdHeaderList* AHeaders, int &VResponseNo, System::UnicodeString &VResponseText, System::UnicodeString &VContentText);

typedef void __fastcall (__closure *TIdHTTPHeaderExpectationsEvent)(Idcontext::TIdContext* AContext, const System::UnicodeString AExpectations, bool &VContinueProcessing);

typedef void __fastcall (__closure *TIdHTTPQuerySSLPortEvent)(System::Word APort, bool &VUseSSL);

class DELPHICLASS EIdHTTPServerError;
class PASCALIMPLEMENTATION EIdHTTPServerError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHTTPServerError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPServerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHTTPServerError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPServerError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPServerError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPServerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPServerError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPServerError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHTTPServerError(void) { }
	
};


class DELPHICLASS EIdHTTPHeaderAlreadyWritten;
class PASCALIMPLEMENTATION EIdHTTPHeaderAlreadyWritten : public EIdHTTPServerError
{
	typedef EIdHTTPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHTTPHeaderAlreadyWritten(const System::UnicodeString AMsg)/* overload */ : EIdHTTPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHTTPHeaderAlreadyWritten(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPHeaderAlreadyWritten(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const System::UnicodeString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHTTPHeaderAlreadyWritten(void) { }
	
};


class DELPHICLASS EIdHTTPErrorParsingCommand;
class PASCALIMPLEMENTATION EIdHTTPErrorParsingCommand : public EIdHTTPServerError
{
	typedef EIdHTTPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHTTPErrorParsingCommand(const System::UnicodeString AMsg)/* overload */ : EIdHTTPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPErrorParsingCommand(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHTTPErrorParsingCommand(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPErrorParsingCommand(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPErrorParsingCommand(const System::UnicodeString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPErrorParsingCommand(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPErrorParsingCommand(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPErrorParsingCommand(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHTTPErrorParsingCommand(void) { }
	
};


class DELPHICLASS EIdHTTPUnsupportedAuthorisationScheme;
class PASCALIMPLEMENTATION EIdHTTPUnsupportedAuthorisationScheme : public EIdHTTPServerError
{
	typedef EIdHTTPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHTTPUnsupportedAuthorisationScheme(const System::UnicodeString AMsg)/* overload */ : EIdHTTPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const System::UnicodeString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHTTPUnsupportedAuthorisationScheme(void) { }
	
};


class DELPHICLASS EIdHTTPCannotSwitchSessionStateWhenActive;
class PASCALIMPLEMENTATION EIdHTTPCannotSwitchSessionStateWhenActive : public EIdHTTPServerError
{
	typedef EIdHTTPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHTTPCannotSwitchSessionStateWhenActive(const System::UnicodeString AMsg)/* overload */ : EIdHTTPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const System::UnicodeString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHTTPCannotSwitchSessionStateWhenActive(void) { }
	
};


class PASCALIMPLEMENTATION TIdHTTPRequestInfo : public Idhttpheaderinfo::TIdRequestHeaderInfo
{
	typedef Idhttpheaderinfo::TIdRequestHeaderInfo inherited;
	
protected:
	bool FAuthExists;
	Idcookie::TIdServerCookies* FCookies;
	Classes::TStrings* FParams;
	Classes::TStream* FPostStream;
	System::UnicodeString FRawHTTPCommand;
	System::UnicodeString FRemoteIP;
	TIdHTTPSession* FSession;
	System::UnicodeString FDocument;
	System::UnicodeString FCommand;
	System::UnicodeString FVersion;
	System::UnicodeString FAuthUsername;
	System::UnicodeString FAuthPassword;
	System::UnicodeString FUnparsedParams;
	System::UnicodeString FQueryParams;
	System::UnicodeString FFormParams;
	THTTPCommandType FCommandType;
	virtual void __fastcall DecodeAndSetParams(const System::UnicodeString AValue);
	
public:
	__fastcall virtual TIdHTTPRequestInfo(void);
	__fastcall virtual ~TIdHTTPRequestInfo(void);
	__property TIdHTTPSession* Session = {read=FSession};
	__property bool AuthExists = {read=FAuthExists, nodefault};
	__property System::UnicodeString AuthPassword = {read=FAuthPassword};
	__property System::UnicodeString AuthUsername = {read=FAuthUsername};
	__property System::UnicodeString Command = {read=FCommand};
	__property THTTPCommandType CommandType = {read=FCommandType, nodefault};
	__property Idcookie::TIdServerCookies* Cookies = {read=FCookies};
	__property System::UnicodeString Document = {read=FDocument, write=FDocument};
	__property Classes::TStrings* Params = {read=FParams};
	__property Classes::TStream* PostStream = {read=FPostStream, write=FPostStream};
	__property System::UnicodeString RawHTTPCommand = {read=FRawHTTPCommand};
	__property System::UnicodeString RemoteIP = {read=FRemoteIP};
	__property System::UnicodeString UnparsedParams = {read=FUnparsedParams, write=FUnparsedParams};
	__property System::UnicodeString FormParams = {read=FFormParams, write=FFormParams};
	__property System::UnicodeString QueryParams = {read=FQueryParams, write=FQueryParams};
	__property System::UnicodeString Version = {read=FVersion};
};


class DELPHICLASS TIdCustomHTTPServer;
class PASCALIMPLEMENTATION TIdHTTPResponseInfo : public Idhttpheaderinfo::TIdResponseHeaderInfo
{
	typedef Idhttpheaderinfo::TIdResponseHeaderInfo inherited;
	
protected:
	System::UnicodeString FAuthRealm;
	Idtcpconnection::TIdTCPConnection* FConnection;
	int FResponseNo;
	Idcookie::TIdServerCookies* FCookies;
	Classes::TStream* FContentStream;
	System::UnicodeString FContentText;
	bool FCloseConnection;
	bool FFreeContentStream;
	bool FHeaderHasBeenWritten;
	System::UnicodeString FResponseText;
	TIdCustomHTTPServer* FHTTPServer;
	TIdHTTPSession* FSession;
	void __fastcall ReleaseContentStream(void);
	void __fastcall SetCookies(const Idcookie::TIdServerCookies* AValue);
	virtual void __fastcall SetHeaders(void);
	void __fastcall SetResponseNo(const int AValue);
	void __fastcall SetCloseConnection(const bool Value);
	
public:
	System::UnicodeString __fastcall GetServer();
	void __fastcall SetServer(const System::UnicodeString Value);
	void __fastcall CloseSession(void);
	__fastcall TIdHTTPResponseInfo(Idtcpconnection::TIdTCPConnection* AConnection, TIdCustomHTTPServer* AServer);
	__fastcall virtual ~TIdHTTPResponseInfo(void);
	void __fastcall Redirect(const System::UnicodeString AURL);
	void __fastcall WriteHeader(void);
	void __fastcall WriteContent(void);
	virtual __int64 __fastcall ServeFile(Idcontext::TIdContext* AContext, const System::UnicodeString AFile);
	__int64 __fastcall SmartServeFile(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, const System::UnicodeString AFile);
	__property System::UnicodeString AuthRealm = {read=FAuthRealm, write=FAuthRealm};
	__property bool CloseConnection = {read=FCloseConnection, write=SetCloseConnection, nodefault};
	__property Classes::TStream* ContentStream = {read=FContentStream, write=FContentStream};
	__property System::UnicodeString ContentText = {read=FContentText, write=FContentText};
	__property Idcookie::TIdServerCookies* Cookies = {read=FCookies, write=SetCookies};
	__property bool FreeContentStream = {read=FFreeContentStream, write=FFreeContentStream, nodefault};
	__property bool HeaderHasBeenWritten = {read=FHeaderHasBeenWritten, write=FHeaderHasBeenWritten, nodefault};
	__property int ResponseNo = {read=FResponseNo, write=SetResponseNo, nodefault};
	__property System::UnicodeString ResponseText = {read=FResponseText, write=FResponseText};
	__property TIdCustomHTTPServer* HTTPServer = {read=FHTTPServer};
	__property System::UnicodeString ServerSoftware = {read=GetServer, write=SetServer};
	__property TIdHTTPSession* Session = {read=FSession};
};


class DELPHICLASS TIdHTTPCustomSessionList;
class PASCALIMPLEMENTATION TIdHTTPSession : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* FContent;
	System::TDateTime FLastTimeStamp;
	Idglobal::TIdCriticalSection* FLock;
	TIdHTTPCustomSessionList* FOwner;
	System::UnicodeString FSessionID;
	System::UnicodeString FRemoteHost;
	void __fastcall SetContent(const Classes::TStrings* Value);
	virtual bool __fastcall IsSessionStale(void);
	virtual void __fastcall DoSessionEnd(void);
	
public:
	__fastcall virtual TIdHTTPSession(TIdHTTPCustomSessionList* AOwner);
	__fastcall virtual TIdHTTPSession(TIdHTTPCustomSessionList* AOwner, const System::UnicodeString SessionID, const System::UnicodeString RemoteIP);
	__fastcall virtual ~TIdHTTPSession(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	__property Classes::TStrings* Content = {read=FContent, write=SetContent};
	__property System::TDateTime LastTimeStamp = {read=FLastTimeStamp};
	__property System::UnicodeString RemoteHost = {read=FRemoteHost};
	__property System::UnicodeString SessionID = {read=FSessionID};
};


class PASCALIMPLEMENTATION TIdHTTPCustomSessionList : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
private:
	int FSessionTimeout;
	TOnSessionEndEvent FOnSessionEnd;
	TOnSessionStartEvent FOnSessionStart;
	
protected:
	virtual void __fastcall RemoveSession(TIdHTTPSession* Session) = 0 ;
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall PurgeStaleSessions(bool PurgeAll = false) = 0 ;
	virtual TIdHTTPSession* __fastcall CreateUniqueSession(const System::UnicodeString RemoteIP) = 0 ;
	virtual TIdHTTPSession* __fastcall CreateSession(const System::UnicodeString RemoteIP, const System::UnicodeString SessionID) = 0 ;
	virtual TIdHTTPSession* __fastcall GetSession(const System::UnicodeString SessionID, const System::UnicodeString RemoteIP) = 0 ;
	virtual void __fastcall Add(TIdHTTPSession* ASession) = 0 ;
	
__published:
	__property int SessionTimeout = {read=FSessionTimeout, write=FSessionTimeout, nodefault};
	__property TOnSessionEndEvent OnSessionEnd = {read=FOnSessionEnd, write=FOnSessionEnd};
	__property TOnSessionStartEvent OnSessionStart = {read=FOnSessionStart, write=FOnSessionStart};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdHTTPCustomSessionList(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdHTTPCustomSessionList(void) { }
	
};


class PASCALIMPLEMENTATION TIdCustomHTTPServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	bool FAutoStartSession;
	bool FKeepAlive;
	bool FParseParams;
	System::UnicodeString FServerSoftware;
	Idglobalprotocols::TIdMimeTable* FMIMETable;
	TIdHTTPCustomSessionList* FSessionList;
	bool FSessionState;
	int FSessionTimeOut;
	TOnCreatePostStream FOnCreatePostStream;
	TOnCreateSession FOnCreateSession;
	TIdHTTPInvalidSessionEvent FOnInvalidSession;
	TOnSessionEndEvent FOnSessionEnd;
	TOnSessionStartEvent FOnSessionStart;
	TIdHTTPCommandEvent FOnCommandGet;
	TIdHTTPCommandEvent FOnCommandOther;
	TIdHTTPCommandError FOnCommandError;
	TIdHTTPHeadersAvailableEvent FOnHeadersAvailable;
	TIdHTTPHeadersBlockedEvent FOnHeadersBlocked;
	TIdHTTPHeaderExpectationsEvent FOnHeaderExpectations;
	TIdHTTPQuerySSLPortEvent FOnQuerySSLPort;
	Idthread::TIdThread* FSessionCleanupThread;
	int FMaximumHeaderLineCount;
	virtual void __fastcall CreatePostStream(Idcontext::TIdContext* ASender, Idheaderlist::TIdHeaderList* AHeaders, Classes::TStream* &VPostStream);
	virtual void __fastcall DoOnCreateSession(Idcontext::TIdContext* AContext, TIdHTTPSession* &VNewSession);
	virtual void __fastcall DoInvalidSession(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo, bool &VContinueProcessing, const System::UnicodeString AInvalidSessionID);
	virtual void __fastcall DoCommandGet(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo);
	virtual void __fastcall DoCommandOther(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo);
	virtual void __fastcall DoCommandError(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* ARequestInfo, TIdHTTPResponseInfo* AResponseInfo, Sysutils::Exception* AException);
	virtual void __fastcall DoConnect(Idcontext::TIdContext* AContext);
	virtual bool __fastcall DoHeadersAvailable(Idcontext::TIdContext* ASender, Idheaderlist::TIdHeaderList* AHeaders);
	virtual void __fastcall DoHeadersBlocked(Idcontext::TIdContext* ASender, Idheaderlist::TIdHeaderList* AHeaders, int &VResponseNo, System::UnicodeString &VResponseText, System::UnicodeString &VContentText);
	virtual bool __fastcall DoHeaderExpectations(Idcontext::TIdContext* ASender, const System::UnicodeString AExpectations);
	virtual bool __fastcall DoQuerySSLPort(System::Word APort);
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall SetActive(bool AValue);
	void __fastcall SetSessionState(const bool Value);
	TIdHTTPSession* __fastcall GetSessionFromCookie(Idcontext::TIdContext* AContext, TIdHTTPRequestInfo* AHTTPrequest, TIdHTTPResponseInfo* AHTTPResponse, bool &VContinueProcessing);
	virtual void __fastcall InitComponent(void);
	__property TOnCreatePostStream OnCreatePostStream = {read=FOnCreatePostStream, write=FOnCreatePostStream};
	__property TIdHTTPCommandEvent OnCommandGet = {read=FOnCommandGet, write=FOnCommandGet};
	
public:
	TIdHTTPSession* __fastcall CreateSession(Idcontext::TIdContext* AContext, TIdHTTPResponseInfo* HTTPResponse, TIdHTTPRequestInfo* HTTPRequest);
	__fastcall virtual ~TIdCustomHTTPServer(void);
	bool __fastcall EndSession(const System::UnicodeString SessionName);
	__property Idglobalprotocols::TIdMimeTable* MIMETable = {read=FMIMETable};
	__property TIdHTTPCustomSessionList* SessionList = {read=FSessionList};
	
__published:
	__property int MaximumHeaderLineCount = {read=FMaximumHeaderLineCount, write=FMaximumHeaderLineCount, default=1024};
	__property bool AutoStartSession = {read=FAutoStartSession, write=FAutoStartSession, default=0};
	__property DefaultPort = {default=80};
	__property TIdHTTPInvalidSessionEvent OnInvalidSession = {read=FOnInvalidSession, write=FOnInvalidSession};
	__property TOnSessionStartEvent OnSessionStart = {read=FOnSessionStart, write=FOnSessionStart};
	__property TOnSessionEndEvent OnSessionEnd = {read=FOnSessionEnd, write=FOnSessionEnd};
	__property TOnCreateSession OnCreateSession = {read=FOnCreateSession, write=FOnCreateSession};
	__property TIdHTTPHeadersAvailableEvent OnHeadersAvailable = {read=FOnHeadersAvailable, write=FOnHeadersAvailable};
	__property TIdHTTPHeadersBlockedEvent OnHeadersBlocked = {read=FOnHeadersBlocked, write=FOnHeadersBlocked};
	__property TIdHTTPHeaderExpectationsEvent OnHeaderExpectations = {read=FOnHeaderExpectations, write=FOnHeaderExpectations};
	__property bool KeepAlive = {read=FKeepAlive, write=FKeepAlive, default=0};
	__property bool ParseParams = {read=FParseParams, write=FParseParams, default=1};
	__property System::UnicodeString ServerSoftware = {read=FServerSoftware, write=FServerSoftware};
	__property bool SessionState = {read=FSessionState, write=SetSessionState, default=0};
	__property int SessionTimeOut = {read=FSessionTimeOut, write=FSessionTimeOut, default=0};
	__property TIdHTTPCommandEvent OnCommandOther = {read=FOnCommandOther, write=FOnCommandOther};
	__property TIdHTTPCommandError OnCommandError = {read=FOnCommandError, write=FOnCommandError};
	__property TIdHTTPQuerySSLPortEvent OnQuerySSLPort = {read=FOnQuerySSLPort, write=FOnQuerySSLPort};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomHTTPServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


class DELPHICLASS TIdHTTPDefaultSessionList;
class PASCALIMPLEMENTATION TIdHTTPDefaultSessionList : public TIdHTTPCustomSessionList
{
	typedef TIdHTTPCustomSessionList inherited;
	
protected:
	Classes::TThreadList* FSessionList;
	virtual void __fastcall RemoveSession(TIdHTTPSession* Session);
	void __fastcall RemoveSessionFromLockedList(int AIndex, Classes::TList* ALockedSessionList);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdHTTPDefaultSessionList(void);
	__property Classes::TThreadList* SessionList = {read=FSessionList};
	virtual void __fastcall Clear(void);
	virtual void __fastcall Add(TIdHTTPSession* ASession);
	virtual void __fastcall PurgeStaleSessions(bool PurgeAll = false);
	virtual TIdHTTPSession* __fastcall CreateUniqueSession(const System::UnicodeString RemoteIP);
	virtual TIdHTTPSession* __fastcall CreateSession(const System::UnicodeString RemoteIP, const System::UnicodeString SessionID);
	virtual TIdHTTPSession* __fastcall GetSession(const System::UnicodeString SessionID, const System::UnicodeString RemoteIP);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdHTTPDefaultSessionList(Classes::TComponent* AOwner)/* overload */ : TIdHTTPCustomSessionList(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool Id_TId_HTTPServer_KeepAlive = false;
static const bool Id_TId_HTTPServer_ParseParams = true;
static const bool Id_TId_HTTPServer_SessionState = false;
static const ShortInt Id_TId_HTTPSessionTimeOut = 0x0;
static const bool Id_TId_HTTPAutoStartSession = false;
static const Word Id_TId_HTTPMaximumHeaderLineCount = 0x400;
static const Byte GResponseNo = 0xc8;
static const ShortInt GFContentLength = -1;
#define GServerSoftware L"Indy/10.5.5"
#define GContentType L"text/html"
#define GSessionIDCookie L"IDHTTPSESSIONID"
extern PACKAGE Idcustomhttpserver__1 HTTPRequestStrings;

}	/* namespace Idcustomhttpserver */
using namespace Idcustomhttpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcustomhttpserverHPP
