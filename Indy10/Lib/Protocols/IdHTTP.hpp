// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhttp.pas' rev: 20.00

#ifndef IdhttpHPP
#define IdhttpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idhttpheaderinfo.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Idssl.hpp>	// Pascal unit
#include <Idzlibcompressorbase.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Iduri.hpp>	// Pascal unit
#include <Idcookie.hpp>	// Pascal unit
#include <Idcookiemanager.hpp>	// Pascal unit
#include <Idauthentication.hpp>	// Pascal unit
#include <Idauthenticationmanager.hpp>	// Pascal unit
#include <Idmultipartformdata.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhttp
{
//-- type declarations -------------------------------------------------------
typedef System::UnicodeString TIdHTTPMethod;

#pragma option push -b-
enum TIdHTTPWhatsNext { wnGoToURL, wnJustExit, wnDontKnow, wnReadAndGo, wnAuthRequest };
#pragma option pop

#pragma option push -b-
enum TIdHTTPConnectionType { ctNormal, ctSSL, ctProxy, ctSSLProxy };
#pragma option pop

#pragma option push -b-
enum TIdHTTPOption { hoInProcessAuth, hoKeepOrigProtocol, hoForceEncodeParams };
#pragma option pop

typedef Set<TIdHTTPOption, hoInProcessAuth, hoForceEncodeParams>  TIdHTTPOptions;

#pragma option push -b-
enum TIdHTTPProtocolVersion { pv1_0, pv1_1 };
#pragma option pop

typedef void __fastcall (__closure *TIdHTTPOnRedirectEvent)(System::TObject* Sender, System::UnicodeString &dest, int &NumRedirect, bool &Handled, System::UnicodeString &VMethod);

typedef void __fastcall (__closure *TIdHTTPOnHeadersAvailable)(System::TObject* Sender, Idheaderlist::TIdHeaderList* AHeaders, bool &VContinue);

typedef void __fastcall (__closure *TIdOnSelectAuthorization)(System::TObject* Sender, Idauthentication::TIdAuthenticationClass &AuthenticationClass, Idheaderlist::TIdHeaderList* AuthInfo);

typedef void __fastcall (__closure *TIdOnAuthorization)(System::TObject* Sender, Idauthentication::TIdAuthentication* Authentication, bool &Handled);

class DELPHICLASS TIdHTTPResponse;
class DELPHICLASS TIdCustomHTTP;
class PASCALIMPLEMENTATION TIdHTTPResponse : public Idhttpheaderinfo::TIdResponseHeaderInfo
{
	typedef Idhttpheaderinfo::TIdResponseHeaderInfo inherited;
	
protected:
	TIdCustomHTTP* FHTTP;
	int FResponseCode;
	System::UnicodeString FResponseText;
	bool FKeepAlive;
	Classes::TStream* FContentStream;
	TIdHTTPProtocolVersion FResponseVersion;
	bool __fastcall GetKeepAlive(void);
	int __fastcall GetResponseCode(void);
	
public:
	__fastcall virtual TIdHTTPResponse(TIdCustomHTTP* AParent);
	__property bool KeepAlive = {read=GetKeepAlive, write=FKeepAlive, nodefault};
	__property System::UnicodeString ResponseText = {read=FResponseText, write=FResponseText};
	__property int ResponseCode = {read=GetResponseCode, write=FResponseCode, nodefault};
	__property TIdHTTPProtocolVersion ResponseVersion = {read=FResponseVersion, write=FResponseVersion, nodefault};
	__property Classes::TStream* ContentStream = {read=FContentStream, write=FContentStream};
public:
	/* TIdResponseHeaderInfo.Destroy */ inline __fastcall virtual ~TIdHTTPResponse(void) { }
	
};


class DELPHICLASS TIdHTTPRequest;
class PASCALIMPLEMENTATION TIdHTTPRequest : public Idhttpheaderinfo::TIdRequestHeaderInfo
{
	typedef Idhttpheaderinfo::TIdRequestHeaderInfo inherited;
	
protected:
	TIdCustomHTTP* FHTTP;
	System::UnicodeString FURL;
	System::UnicodeString FMethod;
	Classes::TStream* FSourceStream;
	TIdHTTPConnectionType FUseProxy;
	Idglobal::TIdIPVersion FIPVersion;
	
public:
	__fastcall virtual TIdHTTPRequest(TIdCustomHTTP* AHTTP);
	__property System::UnicodeString URL = {read=FURL, write=FURL};
	__property System::UnicodeString Method = {read=FMethod, write=FMethod};
	__property Classes::TStream* Source = {read=FSourceStream, write=FSourceStream};
	__property TIdHTTPConnectionType UseProxy = {read=FUseProxy, nodefault};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=FIPVersion, nodefault};
public:
	/* TIdRequestHeaderInfo.Destroy */ inline __fastcall virtual ~TIdHTTPRequest(void) { }
	
};


class DELPHICLASS TIdHTTPProtocol;
class PASCALIMPLEMENTATION TIdHTTPProtocol : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TIdCustomHTTP* FHTTP;
	int FResponseCode;
	TIdHTTPRequest* FRequest;
	TIdHTTPResponse* FResponse;
	__fastcall TIdHTTPProtocol(TIdCustomHTTP* AConnection);
	__fastcall virtual ~TIdHTTPProtocol(void);
	TIdHTTPWhatsNext __fastcall ProcessResponse(short *AIgnoreReplies, const int AIgnoreReplies_Size);
	void __fastcall BuildAndSendRequest(Iduri::TIdURI* AURI);
	void __fastcall RetrieveHeaders(int AMaxHeaderCount);
	__property int ResponseCode = {read=FResponseCode, nodefault};
	__property TIdHTTPRequest* Request = {read=FRequest};
	__property TIdHTTPResponse* Response = {read=FResponse};
};


class PASCALIMPLEMENTATION TIdCustomHTTP : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	int FAuthRetries;
	int FAuthProxyRetries;
	Idcookiemanager::TIdCookieManager* FCookieManager;
	Idzlibcompressorbase::TIdZLibCompressorBase* FCompressor;
	bool FFreeCookieManager;
	int FMaxAuthRetries;
	int FMaxHeaderLines;
	bool FAllowCookies;
	Idauthenticationmanager::TIdAuthenticationManager* FAuthenticationManager;
	TIdHTTPProtocolVersion FProtocolVersion;
	int FRedirectCount;
	int FRedirectMax;
	bool FHandleRedirects;
	TIdHTTPOptions FOptions;
	Iduri::TIdURI* FURI;
	TIdHTTPProtocol* FHTTPProto;
	Idhttpheaderinfo::TIdProxyConnectionInfo* FProxyParameters;
	TIdHTTPOnHeadersAvailable FOnHeadersAvailable;
	TIdHTTPOnRedirectEvent FOnRedirect;
	TIdOnSelectAuthorization FOnSelectAuthorization;
	TIdOnSelectAuthorization FOnSelectProxyAuthorization;
	TIdOnAuthorization FOnAuthorization;
	TIdOnAuthorization FOnProxyAuthorization;
	virtual void __fastcall DoRequest(const System::UnicodeString AMethod, System::UnicodeString AURL, Classes::TStream* ASource, Classes::TStream* AResponseContent, short *AIgnoreReplies, const int AIgnoreReplies_Size);
	virtual void __fastcall InitComponent(void);
	System::UnicodeString __fastcall InternalReadLn();
	void __fastcall SetAuthenticationManager(Idauthenticationmanager::TIdAuthenticationManager* Value);
	void __fastcall SetCookieManager(Idcookiemanager::TIdCookieManager* ACookieManager);
	void __fastcall SetAllowCookies(bool AValue);
	int __fastcall GetResponseCode(void);
	System::UnicodeString __fastcall GetResponseText();
	virtual bool __fastcall DoOnAuthorization(TIdHTTPRequest* ARequest, TIdHTTPResponse* AResponse);
	virtual bool __fastcall DoOnProxyAuthorization(TIdHTTPRequest* ARequest, TIdHTTPResponse* AResponse);
	virtual bool __fastcall DoOnRedirect(System::UnicodeString &Location, System::UnicodeString &VMethod, int RedirectCount);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall ProcessCookies(TIdHTTPRequest* ARequest, TIdHTTPResponse* AResponse);
	TIdHTTPConnectionType __fastcall SetHostAndPort(void);
	void __fastcall SetCookies(Iduri::TIdURI* AURL, TIdHTTPRequest* ARequest);
	void __fastcall ReadResult(TIdHTTPResponse* AResponse, int AUnexpectedContentTimeout = 0xffffffff);
	void __fastcall PrepareRequest(TIdHTTPRequest* ARequest);
	void __fastcall ConnectToHost(TIdHTTPRequest* ARequest, TIdHTTPResponse* AResponse);
	TIdHTTPResponse* __fastcall GetResponseHeaders(void);
	TIdHTTPRequest* __fastcall GetRequestHeaders(void);
	void __fastcall SetRequestHeaders(TIdHTTPRequest* Value);
	void __fastcall EncodeRequestParams(Classes::TStrings* AStrings);
	System::UnicodeString __fastcall SetRequestParams(Classes::TStrings* AStrings);
	void __fastcall CheckAndConnect(TIdHTTPResponse* AResponse);
	virtual void __fastcall DoOnDisconnected(void);
	
public:
	__fastcall virtual ~TIdCustomHTTP(void);
	void __fastcall Delete(System::UnicodeString AURL);
	void __fastcall Options(System::UnicodeString AURL)/* overload */;
	void __fastcall Get(System::UnicodeString AURL, Classes::TStream* AResponseContent)/* overload */;
	void __fastcall Get(System::UnicodeString AURL, Classes::TStream* AResponseContent, short *AIgnoreReplies, const int AIgnoreReplies_Size)/* overload */;
	System::UnicodeString __fastcall Get(System::UnicodeString AURL)/* overload */;
	System::UnicodeString __fastcall Get(System::UnicodeString AURL, short *AIgnoreReplies, const int AIgnoreReplies_Size)/* overload */;
	void __fastcall Trace(System::UnicodeString AURL, Classes::TStream* AResponseContent)/* overload */;
	System::UnicodeString __fastcall Trace(System::UnicodeString AURL)/* overload */;
	void __fastcall Head(System::UnicodeString AURL);
	System::UnicodeString __fastcall Post(System::UnicodeString AURL, Classes::TStrings* ASource)/* overload */;
	System::UnicodeString __fastcall Post(System::UnicodeString AURL, Classes::TStream* ASource)/* overload */;
	System::UnicodeString __fastcall Post(System::UnicodeString AURL, Idmultipartformdata::TIdMultiPartFormDataStream* ASource)/* overload */;
	void __fastcall Post(System::UnicodeString AURL, Idmultipartformdata::TIdMultiPartFormDataStream* ASource, Classes::TStream* AResponseContent)/* overload */;
	void __fastcall Post(System::UnicodeString AURL, Classes::TStrings* ASource, Classes::TStream* AResponseContent)/* overload */;
	void __fastcall Post(System::UnicodeString AURL, Classes::TStream* ASource, Classes::TStream* AResponseContent)/* overload */;
	System::UnicodeString __fastcall Put(System::UnicodeString AURL, Classes::TStream* ASource)/* overload */;
	void __fastcall Put(System::UnicodeString AURL, Classes::TStream* ASource, Classes::TStream* AResponseContent)/* overload */;
	__property Idzlibcompressorbase::TIdZLibCompressorBase* Compressor = {read=FCompressor, write=FCompressor};
	__property int ResponseCode = {read=GetResponseCode, nodefault};
	__property System::UnicodeString ResponseText = {read=GetResponseText};
	__property TIdHTTPResponse* Response = {read=GetResponseHeaders};
	__property Iduri::TIdURI* URL = {read=FURI};
	__property int AuthRetries = {read=FAuthRetries, nodefault};
	__property int AuthProxyRetries = {read=FAuthProxyRetries, nodefault};
	__property int MaxAuthRetries = {read=FMaxAuthRetries, write=FMaxAuthRetries, default=3};
	__property bool AllowCookies = {read=FAllowCookies, write=SetAllowCookies, nodefault};
	__property bool HandleRedirects = {read=FHandleRedirects, write=FHandleRedirects, default=0};
	__property TIdHTTPProtocolVersion ProtocolVersion = {read=FProtocolVersion, write=FProtocolVersion, default=1};
	__property int RedirectCount = {read=FRedirectCount, nodefault};
	__property int RedirectMaximum = {read=FRedirectMax, write=FRedirectMax, default=15};
	__property int MaxHeaderLines = {read=FMaxHeaderLines, write=FMaxHeaderLines, default=255};
	__property Idhttpheaderinfo::TIdProxyConnectionInfo* ProxyParams = {read=FProxyParameters, write=FProxyParameters};
	__property TIdHTTPRequest* Request = {read=GetRequestHeaders, write=SetRequestHeaders};
	__property TIdHTTPOptions HTTPOptions = {read=FOptions, write=FOptions, nodefault};
	__property TIdHTTPOnHeadersAvailable OnHeadersAvailable = {read=FOnHeadersAvailable, write=FOnHeadersAvailable};
	__property TIdHTTPOnRedirectEvent OnRedirect = {read=FOnRedirect, write=FOnRedirect};
	__property TIdOnSelectAuthorization OnSelectAuthorization = {read=FOnSelectAuthorization, write=FOnSelectAuthorization};
	__property TIdOnSelectAuthorization OnSelectProxyAuthorization = {read=FOnSelectProxyAuthorization, write=FOnSelectProxyAuthorization};
	__property TIdOnAuthorization OnAuthorization = {read=FOnAuthorization, write=FOnAuthorization};
	__property TIdOnAuthorization OnProxyAuthorization = {read=FOnProxyAuthorization, write=FOnProxyAuthorization};
	__property Idcookiemanager::TIdCookieManager* CookieManager = {read=FCookieManager, write=SetCookieManager};
	__property Idauthenticationmanager::TIdAuthenticationManager* AuthenticationManager = {read=FAuthenticationManager, write=SetAuthenticationManager};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomHTTP(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


class DELPHICLASS TIdHTTP;
class PASCALIMPLEMENTATION TIdHTTP : public TIdCustomHTTP
{
	typedef TIdCustomHTTP inherited;
	
__published:
	__property MaxAuthRetries = {default=3};
	__property AllowCookies;
	__property HandleRedirects = {default=0};
	__property ProtocolVersion = {default=1};
	__property RedirectMaximum = {default=15};
	__property ProxyParams;
	__property Request;
	__property HTTPOptions;
	__property OnHeadersAvailable;
	__property OnRedirect;
	__property OnSelectAuthorization;
	__property OnSelectProxyAuthorization;
	__property OnAuthorization;
	__property OnProxyAuthorization;
	__property CookieManager;
	__property Compressor;
public:
	/* TIdCustomHTTP.Destroy */ inline __fastcall virtual ~TIdHTTP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdHTTP(Classes::TComponent* AOwner)/* overload */ : TIdCustomHTTP(AOwner) { }
	
};


class DELPHICLASS EIdUnknownProtocol;
class PASCALIMPLEMENTATION EIdUnknownProtocol : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdUnknownProtocol(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdUnknownProtocol(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdUnknownProtocol(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdUnknownProtocol(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdUnknownProtocol(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdUnknownProtocol(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdUnknownProtocol(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdUnknownProtocol(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdUnknownProtocol(void) { }
	
};


class DELPHICLASS EIdHTTPProtocolException;
class PASCALIMPLEMENTATION EIdHTTPProtocolException : public Idreplyrfc::EIdReplyRFCError
{
	typedef Idreplyrfc::EIdReplyRFCError inherited;
	
protected:
	System::UnicodeString FErrorMessage;
	
public:
	__fastcall virtual EIdHTTPProtocolException(const int anErrCode, const System::UnicodeString asReplyMessage, const System::UnicodeString asErrorMessage);
	__property System::UnicodeString ErrorMessage = {read=FErrorMessage};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdHTTPProtocolException(const System::UnicodeString AMsg)/* overload */ : Idreplyrfc::EIdReplyRFCError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPProtocolException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdHTTPProtocolException(int Ident)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPProtocolException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPProtocolException(const System::UnicodeString Msg, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPProtocolException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPProtocolException(int Ident, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPProtocolException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdHTTPProtocolException(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define Id_HTTPMethodHead L"HEAD"
#define Id_HTTPMethodGet L"GET"
#define Id_HTTPMethodPost L"POST"
#define Id_HTTPMethodOptions L"OPTIONS"
#define Id_HTTPMethodTrace L"TRACE"
#define Id_HTTPMethodPut L"PUT"
#define Id_HTTPMethodDelete L"DELETE"
#define Id_HTTPMethodConnect L"CONNECT"
static const TIdHTTPProtocolVersion Id_TIdHTTP_ProtocolVersion = (TIdHTTPProtocolVersion)(1);
static const ShortInt Id_TIdHTTP_RedirectMax = 0xf;
static const Byte Id_TIdHTTP_MaxHeaderLines = 0xff;
static const bool Id_TIdHTTP_HandleRedirects = false;
static const ShortInt Id_TIdHTTP_MaxAuthRetries = 0x3;

}	/* namespace Idhttp */
using namespace Idhttp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhttpHPP
