// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsslopenssl.pas' rev: 20.00

#ifndef IdsslopensslHPP
#define IdsslopensslHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbuffer.hpp>	// Pascal unit
#include <Idctypes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idsslopensslheaders.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idssl.hpp>	// Pascal unit
#include <Idsocks.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idserveriohandler.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsslopenssl
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdSSLVersion { sslvSSLv2, sslvSSLv23, sslvSSLv3, sslvTLSv1 };
#pragma option pop

#pragma option push -b-
enum TIdSSLMode { sslmUnassigned, sslmClient, sslmServer, sslmBoth };
#pragma option pop

#pragma option push -b-
enum TIdSSLVerifyMode { sslvrfPeer, sslvrfFailIfNoPeerCert, sslvrfClientOnce };
#pragma option pop

typedef Set<TIdSSLVerifyMode, sslvrfPeer, sslvrfClientOnce>  TIdSSLVerifyModeSet;

#pragma option push -b-
enum TIdSSLCtxMode { sslCtxClient, sslCtxServer };
#pragma option pop

#pragma option push -b-
enum TIdSSLAction { sslRead, sslWrite };
#pragma option pop

#pragma pack(push,1)
struct TULong
{
	
	union
	{
		struct 
		{
			unsigned C1;
			
		};
		struct 
		{
			int L1;
			
		};
		struct 
		{
			System::Word W1;
			System::Word W2;
			
		};
		struct 
		{
			System::Byte B1;
			System::Byte B2;
			System::Byte B3;
			System::Byte B4;
			
		};
		
	};
};
#pragma pack(pop)


struct TEVP_MD
{
	
public:
	unsigned Length;
	StaticArray<char, 64> MD;
};


struct TByteArray
{
	
public:
	int Length;
	char *Data;
};


typedef void __fastcall (__closure *TCallbackEvent)(const System::UnicodeString AMsg);

typedef void __fastcall (__closure *TPasswordEvent)(System::AnsiString &Password);

class DELPHICLASS TIdX509;
typedef bool __fastcall (__closure *TVerifyPeerEvent)(TIdX509* Certificate, bool AOk, int ADepth);

class DELPHICLASS TIdSSLIOHandlerSocketOpenSSL;
typedef void __fastcall (__closure *TIOHandlerNotify)(TIdSSLIOHandlerSocketOpenSSL* ASender);

class DELPHICLASS TIdSSLOptions;
class PASCALIMPLEMENTATION TIdSSLOptions : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString fsRootCertFile;
	System::UnicodeString fsCertFile;
	System::UnicodeString fsKeyFile;
	TIdSSLVersion fMethod;
	TIdSSLMode fMode;
	int fVerifyDepth;
	TIdSSLVerifyModeSet fVerifyMode;
	System::AnsiString fVerifyDirs;
	System::AnsiString fCipherList;
	virtual void __fastcall AssignTo(Classes::TPersistent* ASource);
	
public:
	__fastcall TIdSSLOptions(void);
	
__published:
	__property System::UnicodeString RootCertFile = {read=fsRootCertFile, write=fsRootCertFile};
	__property System::UnicodeString CertFile = {read=fsCertFile, write=fsCertFile};
	__property System::UnicodeString KeyFile = {read=fsKeyFile, write=fsKeyFile};
	__property TIdSSLVersion Method = {read=fMethod, write=fMethod, default=3};
	__property TIdSSLMode Mode = {read=fMode, write=fMode, nodefault};
	__property TIdSSLVerifyModeSet VerifyMode = {read=fVerifyMode, write=fVerifyMode, nodefault};
	__property int VerifyDepth = {read=fVerifyDepth, write=fVerifyDepth, nodefault};
	__property System::AnsiString VerifyDirs = {read=fVerifyDirs, write=fVerifyDirs};
	__property System::AnsiString CipherList = {read=fCipherList, write=fCipherList};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdSSLOptions(void) { }
	
};


class DELPHICLASS TIdSSLContext;
class PASCALIMPLEMENTATION TIdSSLContext : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TIdSSLVersion fMethod;
	TIdSSLMode fMode;
	System::AnsiString fsRootCertFile;
	System::AnsiString fsCertFile;
	System::AnsiString fsKeyFile;
	int fVerifyDepth;
	TIdSSLVerifyModeSet fVerifyMode;
	System::UnicodeString fVerifyDirs;
	System::AnsiString fCipherList;
	Idsslopensslheaders::SSL_CTX *fContext;
	bool fStatusInfoOn;
	bool fVerifyOn;
	int fSessionId;
	TIdSSLCtxMode fCtxMode;
	void __fastcall DestroyContext(void);
	Idsslopensslheaders::PSSL_METHOD __fastcall SetSSLMethod(void);
	void __fastcall SetVerifyMode(TIdSSLVerifyModeSet Mode, bool CheckRoutine);
	TIdSSLVerifyModeSet __fastcall GetVerifyMode(void);
	void __fastcall InitContext(TIdSSLCtxMode CtxMode);
	
public:
	System::TObject* Parent;
	__fastcall TIdSSLContext(void);
	__fastcall virtual ~TIdSSLContext(void);
	TIdSSLContext* __fastcall Clone(void);
	bool __fastcall LoadRootCert(void);
	bool __fastcall LoadCert(void);
	bool __fastcall LoadKey(void);
	__property bool StatusInfoOn = {read=fStatusInfoOn, write=fStatusInfoOn, nodefault};
	__property bool VerifyOn = {read=fVerifyOn, write=fVerifyOn, nodefault};
	__property TIdSSLVersion Method = {read=fMethod, write=fMethod, nodefault};
	__property TIdSSLMode Mode = {read=fMode, write=fMode, nodefault};
	__property System::AnsiString RootCertFile = {read=fsRootCertFile, write=fsRootCertFile};
	__property System::AnsiString CertFile = {read=fsCertFile, write=fsCertFile};
	__property System::AnsiString KeyFile = {read=fsKeyFile, write=fsKeyFile};
	__property TIdSSLVerifyModeSet VerifyMode = {read=fVerifyMode, write=fVerifyMode, nodefault};
	__property int VerifyDepth = {read=fVerifyDepth, write=fVerifyDepth, nodefault};
};


class DELPHICLASS TIdSSLSocket;
class DELPHICLASS TIdSSLCipher;
class PASCALIMPLEMENTATION TIdSSLSocket : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::TObject* fParent;
	TIdX509* fPeerCert;
	Idsslopensslheaders::SSL *fSSL;
	TIdSSLCipher* fSSLCipher;
	TIdSSLContext* fSSLContext;
	TIdX509* __fastcall GetPeerCert(void);
	int __fastcall GetSSLError(int retCode);
	TIdSSLCipher* __fastcall GetSSLCipher(void);
	
public:
	__fastcall TIdSSLSocket(System::TObject* Parent);
	__fastcall virtual ~TIdSSLSocket(void);
	void __fastcall Accept(const unsigned pHandle);
	void __fastcall Connect(const unsigned pHandle);
	int __fastcall Send(const Sysutils::TBytes ABuffer, int AOffset, int ALength);
	int __fastcall Recv(Sysutils::TBytes &ABuffer);
	TByteArray __fastcall GetSessionID();
	System::UnicodeString __fastcall GetSessionIDAsString();
	void __fastcall SetCipherList(System::UnicodeString CipherList);
	__property TIdX509* PeerCert = {read=GetPeerCert};
	__property TIdSSLCipher* Cipher = {read=GetSSLCipher};
};


class PASCALIMPLEMENTATION TIdSSLIOHandlerSocketOpenSSL : public Idssl::TIdSSLIOHandlerSocketBase
{
	typedef Idssl::TIdSSLIOHandlerSocketBase inherited;
	
protected:
	TIdSSLContext* fSSLContext;
	TIdSSLOptions* fxSSLOptions;
	TIdSSLSocket* fSSLSocket;
	TCallbackEvent fOnStatusInfo;
	TPasswordEvent fOnGetPassword;
	TVerifyPeerEvent fOnVerifyPeer;
	bool fSSLLayerClosed;
	TIOHandlerNotify fOnBeforeConnect;
	virtual void __fastcall SetPassThrough(const bool Value);
	virtual void __fastcall DoBeforeConnect(TIdSSLIOHandlerSocketOpenSSL* ASender);
	virtual void __fastcall DoStatusInfo(const System::UnicodeString AMsg);
	virtual void __fastcall DoGetPassword(System::AnsiString &Password);
	virtual bool __fastcall DoVerifyPeer(TIdX509* Certificate, bool AOk, int ADepth);
	virtual int __fastcall RecvEnc(Sysutils::TBytes &VBuffer);
	virtual int __fastcall SendEnc(const Sysutils::TBytes ABuffer, const int AOffset, const int ALength);
	void __fastcall Init(void);
	virtual void __fastcall OpenEncodedConnection(void);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall ConnectClient(void);
	
public:
	__fastcall virtual ~TIdSSLIOHandlerSocketOpenSSL(void);
	virtual Idssl::TIdSSLIOHandlerSocketBase* __fastcall Clone(void);
	virtual void __fastcall StartSSL(void);
	virtual void __fastcall AfterAccept(void);
	virtual void __fastcall Close(void);
	virtual void __fastcall Open(void);
	__property TIdSSLSocket* SSLSocket = {read=fSSLSocket, write=fSSLSocket};
	__property TIOHandlerNotify OnBeforeConnect = {read=fOnBeforeConnect, write=fOnBeforeConnect};
	__property TIdSSLContext* SSLContext = {read=fSSLContext, write=fSSLContext};
	
__published:
	__property TIdSSLOptions* SSLOptions = {read=fxSSLOptions, write=fxSSLOptions};
	__property TCallbackEvent OnStatusInfo = {read=fOnStatusInfo, write=fOnStatusInfo};
	__property TPasswordEvent OnGetPassword = {read=fOnGetPassword, write=fOnGetPassword};
	__property TVerifyPeerEvent OnVerifyPeer = {read=fOnVerifyPeer, write=fOnVerifyPeer};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSSLIOHandlerSocketOpenSSL(Classes::TComponent* AOwner)/* overload */ : Idssl::TIdSSLIOHandlerSocketBase(AOwner) { }
	
};


class DELPHICLASS TIdServerIOHandlerSSLOpenSSL;
class PASCALIMPLEMENTATION TIdServerIOHandlerSSLOpenSSL : public Idssl::TIdServerIOHandlerSSLBase
{
	typedef Idssl::TIdServerIOHandlerSSLBase inherited;
	
protected:
	TIdSSLOptions* fxSSLOptions;
	TIdSSLContext* fSSLContext;
	TCallbackEvent fOnStatusInfo;
	TPasswordEvent fOnGetPassword;
	TVerifyPeerEvent fOnVerifyPeer;
	virtual void __fastcall DoStatusInfo(const System::UnicodeString AMsg);
	virtual void __fastcall DoGetPassword(System::AnsiString &Password);
	virtual bool __fastcall DoVerifyPeer(TIdX509* Certificate, bool AOk, int ADepth);
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Init(void);
	virtual void __fastcall Shutdown(void);
	virtual Idiohandler::TIdIOHandler* __fastcall Accept(Idsockethandle::TIdSocketHandle* ASocket, Idthread::TIdThread* AListenerThread, Idyarn::TIdYarn* AYarn);
	__fastcall virtual ~TIdServerIOHandlerSSLOpenSSL(void);
	virtual Idssl::TIdSSLIOHandlerSocketBase* __fastcall MakeClientIOHandler(void)/* overload */;
	virtual Idssl::TIdSSLIOHandlerSocketBase* __fastcall MakeFTPSvrPort(void);
	virtual Idssl::TIdSSLIOHandlerSocketBase* __fastcall MakeFTPSvrPasv(void);
	__property TIdSSLContext* SSLContext = {read=fSSLContext};
	
__published:
	__property TIdSSLOptions* SSLOptions = {read=fxSSLOptions, write=fxSSLOptions};
	__property TCallbackEvent OnStatusInfo = {read=fOnStatusInfo, write=fOnStatusInfo};
	__property TPasswordEvent OnGetPassword = {read=fOnGetPassword, write=fOnGetPassword};
	__property TVerifyPeerEvent OnVerifyPeer = {read=fOnVerifyPeer, write=fOnVerifyPeer};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerIOHandlerSSLOpenSSL(Classes::TComponent* AOwner)/* overload */ : Idssl::TIdServerIOHandlerSSLBase(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline Idiohandler::TIdIOHandler* __fastcall  MakeClientIOHandler(Idyarn::TIdYarn* ATheThread){ return Idssl::TIdServerIOHandlerSSLBase::MakeClientIOHandler(ATheThread); }
	
};


class DELPHICLASS TIdX509Name;
class PASCALIMPLEMENTATION TIdX509Name : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Idsslopensslheaders::X509_NAME *fX509Name;
	System::UnicodeString __fastcall CertInOneLine();
	TULong __fastcall GetHash(void);
	System::UnicodeString __fastcall GetHashAsString();
	
public:
	__fastcall TIdX509Name(Idsslopensslheaders::PX509_NAME aX509Name);
	__property TULong Hash = {read=GetHash};
	__property System::UnicodeString HashAsString = {read=GetHashAsString};
	__property System::UnicodeString OneLine = {read=CertInOneLine};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdX509Name(void) { }
	
};


class DELPHICLASS TIdX509Info;
class PASCALIMPLEMENTATION TIdX509Info : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Idsslopensslheaders::X509 *FX509;
	
public:
	__fastcall TIdX509Info(Idsslopensslheaders::PX509 aX509);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdX509Info(void) { }
	
};


class DELPHICLASS TIdX509Fingerprints;
class PASCALIMPLEMENTATION TIdX509Fingerprints : public TIdX509Info
{
	typedef TIdX509Info inherited;
	
protected:
	TEVP_MD __fastcall GetMD5();
	System::UnicodeString __fastcall GetMD5AsString();
	TEVP_MD __fastcall GetSHA1();
	System::UnicodeString __fastcall GetSHA1AsString();
	TEVP_MD __fastcall GetSHA224();
	System::UnicodeString __fastcall GetSHA224AsString();
	TEVP_MD __fastcall GetSHA256();
	System::UnicodeString __fastcall GetSHA256AsString();
	TEVP_MD __fastcall GetSHA386();
	System::UnicodeString __fastcall GetSHA386AsString();
	TEVP_MD __fastcall GetSHA512();
	System::UnicodeString __fastcall GetSHA512AsString();
	
public:
	__property TEVP_MD MD5 = {read=GetMD5};
	__property System::UnicodeString MD5AsString = {read=GetMD5AsString};
	__property TEVP_MD SHA1 = {read=GetSHA1};
	__property System::UnicodeString SHA1AsString = {read=GetSHA1AsString};
	__property TEVP_MD SHA224 = {read=GetSHA224};
	__property System::UnicodeString SHA224AsString = {read=GetSHA224AsString};
	__property TEVP_MD SHA256 = {read=GetSHA256};
	__property System::UnicodeString SHA256AsString = {read=GetSHA256AsString};
	__property TEVP_MD SHA386 = {read=GetSHA386};
	__property System::UnicodeString SHA386AsString = {read=GetSHA386AsString};
	__property TEVP_MD SHA512 = {read=GetSHA512};
	__property System::UnicodeString SHA512AsString = {read=GetSHA512AsString};
public:
	/* TIdX509Info.Create */ inline __fastcall TIdX509Fingerprints(Idsslopensslheaders::PX509 aX509) : TIdX509Info(aX509) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdX509Fingerprints(void) { }
	
};


class DELPHICLASS TIdX509SigInfo;
class PASCALIMPLEMENTATION TIdX509SigInfo : public TIdX509Info
{
	typedef TIdX509Info inherited;
	
protected:
	System::UnicodeString __fastcall GetSignature();
	int __fastcall GetSigType(void);
	System::UnicodeString __fastcall GetSigTypeAsString();
	
public:
	__property System::UnicodeString Signature = {read=GetSignature};
	__property int SigType = {read=GetSigType, nodefault};
	__property System::UnicodeString SigTypeAsString = {read=GetSigTypeAsString};
public:
	/* TIdX509Info.Create */ inline __fastcall TIdX509SigInfo(Idsslopensslheaders::PX509 aX509) : TIdX509Info(aX509) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdX509SigInfo(void) { }
	
};


class PASCALIMPLEMENTATION TIdX509 : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TIdX509Fingerprints* FFingerprints;
	TIdX509SigInfo* FSigInfo;
	bool FCanFreeX509;
	Idsslopensslheaders::X509 *FX509;
	TIdX509Name* FSubject;
	TIdX509Name* FIssuer;
	Classes::TStrings* FDisplayInfo;
	TIdX509Name* __fastcall RSubject(void);
	TIdX509Name* __fastcall RIssuer(void);
	System::TDateTime __fastcall RnotBefore(void);
	System::TDateTime __fastcall RnotAfter(void);
	TEVP_MD __fastcall RFingerprint();
	System::UnicodeString __fastcall RFingerprintAsString();
	System::UnicodeString __fastcall GetSerialNumber();
	int __fastcall GetVersion(void);
	Classes::TStrings* __fastcall GetDisplayInfo(void);
	
public:
	__fastcall virtual TIdX509(Idsslopensslheaders::PX509 aX509, bool aCanFreeX509);
	__fastcall virtual ~TIdX509(void);
	__property int Version = {read=GetVersion, nodefault};
	__property TIdX509SigInfo* SigInfo = {read=FSigInfo};
	__property TIdX509Fingerprints* Fingerprints = {read=FFingerprints};
	__property TEVP_MD Fingerprint = {read=RFingerprint};
	__property System::UnicodeString FingerprintAsString = {read=RFingerprintAsString};
	__property TIdX509Name* Subject = {read=RSubject};
	__property TIdX509Name* Issuer = {read=RIssuer};
	__property System::TDateTime notBefore = {read=RnotBefore};
	__property System::TDateTime notAfter = {read=RnotAfter};
	__property System::UnicodeString SerialNumber = {read=GetSerialNumber};
	__property Classes::TStrings* DisplayInfo = {read=GetDisplayInfo};
};


class PASCALIMPLEMENTATION TIdSSLCipher : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TIdSSLSocket* FSSLSocket;
	System::UnicodeString __fastcall GetDescription();
	System::UnicodeString __fastcall GetName();
	int __fastcall GetBits(void);
	System::UnicodeString __fastcall GetVersion();
	
public:
	__fastcall TIdSSLCipher(TIdSSLSocket* AOwner);
	__fastcall virtual ~TIdSSLCipher(void);
	__property System::UnicodeString Description = {read=GetDescription};
	__property System::UnicodeString Name = {read=GetName};
	__property int Bits = {read=GetBits, nodefault};
	__property System::UnicodeString Version = {read=GetVersion};
};


class DELPHICLASS EIdOSSLCouldNotLoadSSLLibrary;
class PASCALIMPLEMENTATION EIdOSSLCouldNotLoadSSLLibrary : public Idsslopensslheaders::EIdOpenSSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLCouldNotLoadSSLLibrary(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLCouldNotLoadSSLLibrary(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLCouldNotLoadSSLLibrary(void) { }
	
};


class DELPHICLASS EIdOSSLModeNotSet;
class PASCALIMPLEMENTATION EIdOSSLModeNotSet : public Idsslopensslheaders::EIdOpenSSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLModeNotSet(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLModeNotSet(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLModeNotSet(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLModeNotSet(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLModeNotSet(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLModeNotSet(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLModeNotSet(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLModeNotSet(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLModeNotSet(void) { }
	
};


class DELPHICLASS EIdOSSLGetMethodError;
class PASCALIMPLEMENTATION EIdOSSLGetMethodError : public Idsslopensslheaders::EIdOpenSSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLGetMethodError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLGetMethodError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLGetMethodError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLGetMethodError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLGetMethodError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLGetMethodError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLGetMethodError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLGetMethodError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLGetMethodError(void) { }
	
};


class DELPHICLASS EIdOSSLCreatingContextError;
class PASCALIMPLEMENTATION EIdOSSLCreatingContextError : public Idsslopensslheaders::EIdOpenSSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLCreatingContextError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLCreatingContextError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLCreatingContextError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLCreatingContextError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLCreatingContextError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLCreatingContextError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLCreatingContextError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLCreatingContextError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLCreatingContextError(void) { }
	
};


class DELPHICLASS EIdOSSLLoadingRootCertError;
class PASCALIMPLEMENTATION EIdOSSLLoadingRootCertError : public Idsslopensslheaders::EIdOpenSSLAPICryptoError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPICryptoError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLLoadingRootCertError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLLoadingRootCertError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLLoadingRootCertError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLLoadingRootCertError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLLoadingRootCertError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLLoadingRootCertError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLLoadingRootCertError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLLoadingRootCertError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLLoadingRootCertError(void) { }
	
};


class DELPHICLASS EIdOSSLLoadingCertError;
class PASCALIMPLEMENTATION EIdOSSLLoadingCertError : public Idsslopensslheaders::EIdOpenSSLAPICryptoError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPICryptoError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLLoadingCertError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLLoadingCertError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLLoadingCertError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLLoadingCertError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLLoadingCertError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLLoadingCertError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLLoadingCertError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLLoadingCertError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLLoadingCertError(void) { }
	
};


class DELPHICLASS EIdOSSLLoadingKeyError;
class PASCALIMPLEMENTATION EIdOSSLLoadingKeyError : public Idsslopensslheaders::EIdOpenSSLAPICryptoError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPICryptoError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLLoadingKeyError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLLoadingKeyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLLoadingKeyError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLLoadingKeyError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLLoadingKeyError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLLoadingKeyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLLoadingKeyError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLLoadingKeyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPICryptoError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLLoadingKeyError(void) { }
	
};


class DELPHICLASS EIdOSSLSettingCipherError;
class PASCALIMPLEMENTATION EIdOSSLSettingCipherError : public Idsslopensslheaders::EIdOpenSSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLSettingCipherError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLSettingCipherError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLSettingCipherError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLSettingCipherError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLSettingCipherError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLSettingCipherError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLSettingCipherError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLSettingCipherError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLSettingCipherError(void) { }
	
};


class DELPHICLASS EIdOSSLFDSetError;
class PASCALIMPLEMENTATION EIdOSSLFDSetError : public Idsslopensslheaders::EIdOpenSSLAPISSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPISSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLFDSetError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLFDSetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLFDSetError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLFDSetError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLFDSetError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLFDSetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLFDSetError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLFDSetError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLFDSetError(void) { }
	
};


class DELPHICLASS EIdOSSLDataBindingError;
class PASCALIMPLEMENTATION EIdOSSLDataBindingError : public Idsslopensslheaders::EIdOpenSSLAPISSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPISSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLDataBindingError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLDataBindingError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLDataBindingError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLDataBindingError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLDataBindingError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLDataBindingError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLDataBindingError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLDataBindingError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLDataBindingError(void) { }
	
};


class DELPHICLASS EIdOSSLAcceptError;
class PASCALIMPLEMENTATION EIdOSSLAcceptError : public Idsslopensslheaders::EIdOpenSSLAPISSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPISSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLAcceptError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLAcceptError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLAcceptError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLAcceptError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLAcceptError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLAcceptError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLAcceptError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLAcceptError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLAcceptError(void) { }
	
};


class DELPHICLASS EIdOSSLConnectError;
class PASCALIMPLEMENTATION EIdOSSLConnectError : public Idsslopensslheaders::EIdOpenSSLAPISSLError
{
	typedef Idsslopensslheaders::EIdOpenSSLAPISSLError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLConnectError(const System::UnicodeString AMsg)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLConnectError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLConnectError(int Ident)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLConnectError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLConnectError(const System::UnicodeString Msg, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLConnectError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idsslopensslheaders::EIdOpenSSLAPISSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLConnectError(int Ident, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLConnectError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idsslopensslheaders::EIdOpenSSLAPISSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLConnectError(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const TIdSSLVersion DEF_SSLVERSION = (TIdSSLVersion)(3);
extern PACKAGE bool __fastcall LoadOpenSSLLibrary(void);
extern PACKAGE void __fastcall UnLoadOpenSSLLibrary(void);
extern PACKAGE bool __fastcall LogicalAnd(int A, int B);

}	/* namespace Idsslopenssl */
using namespace Idsslopenssl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsslopensslHPP
