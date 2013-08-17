// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhttpheaderinfo.pas' rev: 20.00

#ifndef IdhttpheaderinfoHPP
#define IdhttpheaderinfoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idauthentication.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhttpheaderinfo
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEntityHeaderInfo;
class PASCALIMPLEMENTATION TIdEntityHeaderInfo : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FCacheControl;
	Idheaderlist::TIdHeaderList* FRawHeaders;
	System::UnicodeString FCharSet;
	System::UnicodeString FConnection;
	System::UnicodeString FContentDisposition;
	System::UnicodeString FContentEncoding;
	System::UnicodeString FContentLanguage;
	__int64 FContentLength;
	__int64 FContentRangeEnd;
	__int64 FContentRangeStart;
	__int64 FContentRangeInstanceLength;
	System::UnicodeString FContentType;
	System::UnicodeString FContentVersion;
	Idheaderlist::TIdHeaderList* FCustomHeaders;
	System::TDateTime FDate;
	System::TDateTime FExpires;
	System::UnicodeString FETag;
	System::TDateTime FLastModified;
	System::UnicodeString FPragma;
	bool FHasContentLength;
	virtual void __fastcall AssignTo(Classes::TPersistent* Destination);
	virtual void __fastcall ProcessHeaders(void);
	virtual void __fastcall SetHeaders(void);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall SetContentLength(const __int64 AValue);
	void __fastcall SetContentType(const System::UnicodeString AValue);
	void __fastcall SetCustomHeaders(const Idheaderlist::TIdHeaderList* AValue);
	bool __fastcall GetHasContentRange(void);
	bool __fastcall GetHasContentRangeInstance(void);
	
public:
	virtual void __fastcall Clear(void);
	__fastcall virtual TIdEntityHeaderInfo(void);
	__fastcall virtual ~TIdEntityHeaderInfo(void);
	__property bool HasContentLength = {read=FHasContentLength, nodefault};
	__property bool HasContentRange = {read=GetHasContentRange, nodefault};
	__property bool HasContentRangeInstance = {read=GetHasContentRangeInstance, nodefault};
	__property Idheaderlist::TIdHeaderList* RawHeaders = {read=FRawHeaders};
	
__published:
	__property System::UnicodeString CacheControl = {read=FCacheControl, write=FCacheControl};
	__property System::UnicodeString CharSet = {read=FCharSet, write=FCharSet};
	__property System::UnicodeString Connection = {read=FConnection, write=FConnection};
	__property System::UnicodeString ContentDisposition = {read=FContentDisposition, write=FContentDisposition};
	__property System::UnicodeString ContentEncoding = {read=FContentEncoding, write=FContentEncoding};
	__property System::UnicodeString ContentLanguage = {read=FContentLanguage, write=FContentLanguage};
	__property __int64 ContentLength = {read=FContentLength, write=SetContentLength};
	__property __int64 ContentRangeEnd = {read=FContentRangeEnd, write=FContentRangeEnd};
	__property __int64 ContentRangeStart = {read=FContentRangeStart, write=FContentRangeStart};
	__property __int64 ContentRangeInstanceLength = {read=FContentRangeInstanceLength, write=FContentRangeInstanceLength};
	__property System::UnicodeString ContentType = {read=FContentType, write=SetContentType};
	__property System::UnicodeString ContentVersion = {read=FContentVersion, write=FContentVersion};
	__property Idheaderlist::TIdHeaderList* CustomHeaders = {read=FCustomHeaders, write=SetCustomHeaders};
	__property System::TDateTime Date = {read=FDate, write=FDate};
	__property System::UnicodeString ETag = {read=FETag, write=FETag};
	__property System::TDateTime Expires = {read=FExpires, write=FExpires};
	__property System::TDateTime LastModified = {read=FLastModified, write=FLastModified};
	__property System::UnicodeString Pragma = {read=FPragma, write=FPragma};
};


class DELPHICLASS TIdProxyConnectionInfo;
class PASCALIMPLEMENTATION TIdProxyConnectionInfo : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	Idauthentication::TIdAuthentication* FAuthentication;
	System::UnicodeString FPassword;
	int FPort;
	System::UnicodeString FServer;
	System::UnicodeString FUsername;
	bool FBasicByDefault;
	virtual void __fastcall AssignTo(Classes::TPersistent* Destination);
	void __fastcall SetProxyPort(const int Value);
	void __fastcall SetProxyServer(const System::UnicodeString Value);
	
public:
	__fastcall TIdProxyConnectionInfo(void);
	void __fastcall Clear(void);
	__fastcall virtual ~TIdProxyConnectionInfo(void);
	void __fastcall SetHeaders(Idheaderlist::TIdHeaderList* Headers);
	__property Idauthentication::TIdAuthentication* Authentication = {read=FAuthentication, write=FAuthentication};
	
__published:
	__property bool BasicAuthentication = {read=FBasicByDefault, write=FBasicByDefault, nodefault};
	__property System::UnicodeString ProxyPassword = {read=FPassword, write=FPassword};
	__property int ProxyPort = {read=FPort, write=SetProxyPort, nodefault};
	__property System::UnicodeString ProxyServer = {read=FServer, write=SetProxyServer};
	__property System::UnicodeString ProxyUsername = {read=FUsername, write=FUsername};
};


class DELPHICLASS TIdRequestHeaderInfo;
class PASCALIMPLEMENTATION TIdRequestHeaderInfo : public TIdEntityHeaderInfo
{
	typedef TIdEntityHeaderInfo inherited;
	
protected:
	System::UnicodeString FAccept;
	System::UnicodeString FAcceptCharSet;
	System::UnicodeString FAcceptEncoding;
	System::UnicodeString FAcceptLanguage;
	System::UnicodeString FExpect;
	System::UnicodeString FFrom;
	System::UnicodeString FPassword;
	System::UnicodeString FReferer;
	System::UnicodeString FUserAgent;
	System::UnicodeString FUserName;
	System::UnicodeString FHost;
	System::UnicodeString FProxyConnection;
	System::UnicodeString FRange;
	bool FBasicByDefault;
	Idauthentication::TIdAuthentication* FAuthentication;
	virtual void __fastcall AssignTo(Classes::TPersistent* Destination);
	virtual void __fastcall ProcessHeaders(void);
	virtual void __fastcall SetHeaders(void);
	
public:
	virtual void __fastcall Clear(void);
	__property Idauthentication::TIdAuthentication* Authentication = {read=FAuthentication, write=FAuthentication};
	__fastcall virtual ~TIdRequestHeaderInfo(void);
	
__published:
	__property System::UnicodeString Accept = {read=FAccept, write=FAccept};
	__property System::UnicodeString AcceptCharSet = {read=FAcceptCharSet, write=FAcceptCharSet};
	__property System::UnicodeString AcceptEncoding = {read=FAcceptEncoding, write=FAcceptEncoding};
	__property System::UnicodeString AcceptLanguage = {read=FAcceptLanguage, write=FAcceptLanguage};
	__property bool BasicAuthentication = {read=FBasicByDefault, write=FBasicByDefault, nodefault};
	__property System::UnicodeString Host = {read=FHost, write=FHost};
	__property System::UnicodeString From = {read=FFrom, write=FFrom};
	__property System::UnicodeString Password = {read=FPassword, write=FPassword};
	__property System::UnicodeString Referer = {read=FReferer, write=FReferer};
	__property System::UnicodeString UserAgent = {read=FUserAgent, write=FUserAgent};
	__property System::UnicodeString Username = {read=FUserName, write=FUserName};
	__property System::UnicodeString ProxyConnection = {read=FProxyConnection, write=FProxyConnection};
	__property System::UnicodeString Range = {read=FRange, write=FRange};
public:
	/* TIdEntityHeaderInfo.Create */ inline __fastcall virtual TIdRequestHeaderInfo(void) : TIdEntityHeaderInfo() { }
	
};


class DELPHICLASS TIdResponseHeaderInfo;
class PASCALIMPLEMENTATION TIdResponseHeaderInfo : public TIdEntityHeaderInfo
{
	typedef TIdEntityHeaderInfo inherited;
	
protected:
	System::UnicodeString FAcceptRanges;
	System::UnicodeString FLocation;
	System::UnicodeString FServer;
	System::UnicodeString FProxyConnection;
	Idheaderlist::TIdHeaderList* FProxyAuthenticate;
	Idheaderlist::TIdHeaderList* FWWWAuthenticate;
	void __fastcall SetProxyAuthenticate(const Idheaderlist::TIdHeaderList* Value);
	void __fastcall SetWWWAuthenticate(const Idheaderlist::TIdHeaderList* Value);
	void __fastcall SetAcceptRanges(const System::UnicodeString Value);
	virtual void __fastcall ProcessHeaders(void);
	virtual void __fastcall SetHeaders(void);
	
public:
	virtual void __fastcall Clear(void);
	__fastcall virtual TIdResponseHeaderInfo(void);
	__fastcall virtual ~TIdResponseHeaderInfo(void);
	
__published:
	__property System::UnicodeString AcceptRanges = {read=FAcceptRanges, write=SetAcceptRanges};
	__property System::UnicodeString Location = {read=FLocation, write=FLocation};
	__property System::UnicodeString ProxyConnection = {read=FProxyConnection, write=FProxyConnection};
	__property Idheaderlist::TIdHeaderList* ProxyAuthenticate = {read=FProxyAuthenticate, write=SetProxyAuthenticate};
	__property System::UnicodeString Server = {read=FServer, write=FServer};
	__property Idheaderlist::TIdHeaderList* WWWAuthenticate = {read=FWWWAuthenticate, write=SetWWWAuthenticate};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhttpheaderinfo */
using namespace Idhttpheaderinfo;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhttpheaderinfoHPP
