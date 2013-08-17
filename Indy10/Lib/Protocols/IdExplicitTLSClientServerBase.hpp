// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idexplicittlsclientserverbase.pas' rev: 20.00

#ifndef IdexplicittlsclientserverbaseHPP
#define IdexplicittlsclientserverbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcmdtcpserver.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idserveriohandler.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idexplicittlsclientserverbase
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdUseTLS { utNoTLSSupport, utUseImplicitTLS, utUseRequireTLS, utUseExplicitTLS };
#pragma option pop

typedef void __fastcall (__closure *TIdOnTLSNegotiationFailure)(System::TObject* Asender, bool &VContinue);

class DELPHICLASS TIdExplicitTLSServer;
class PASCALIMPLEMENTATION TIdExplicitTLSServer : public Idcmdtcpserver::TIdCmdTCPServer
{
	typedef Idcmdtcpserver::TIdCmdTCPServer inherited;
	
protected:
	System::Word FRegularProtPort;
	System::Word FImplicitTLSProtPort;
	TIdUseTLS FUseTLS;
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetIOHandler(const Idserveriohandler::TIdServerIOHandler* AValue);
	virtual void __fastcall SetUseTLS(TIdUseTLS AValue);
	__property TIdUseTLS UseTLS = {read=FUseTLS, write=SetUseTLS, default=0};
	virtual void __fastcall InitComponent(void);
public:
	/* TIdCmdTCPServer.Destroy */ inline __fastcall virtual ~TIdExplicitTLSServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdExplicitTLSServer(Classes::TComponent* AOwner)/* overload */ : Idcmdtcpserver::TIdCmdTCPServer(AOwner) { }
	
};


class DELPHICLASS TIdExplicitTLSClient;
class PASCALIMPLEMENTATION TIdExplicitTLSClient : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	System::Word FRegularProtPort;
	System::Word FImplicitTLSProtPort;
	TIdUseTLS FUseTLS;
	TIdOnTLSNegotiationFailure FOnTLSNotAvailable;
	TIdOnTLSNegotiationFailure FOnTLSNegCmdFailed;
	TIdOnTLSNegotiationFailure FOnTLSHandShakeFailed;
	Classes::TStrings* FCapabilities;
	virtual bool __fastcall GetSupportsTLS(void);
	virtual void __fastcall CheckIfCanUseTLS(void);
	virtual void __fastcall Loaded(void);
	void __fastcall TLSNotAvailable(void);
	void __fastcall DoOnTLSNotAvailable(void);
	void __fastcall ProcessTLSNotAvail(void);
	void __fastcall TLSNegCmdFailed(void);
	void __fastcall DoOnTLSNegCmdFailed(void);
	void __fastcall ProcessTLSNegCmdFailed(void);
	void __fastcall TLSHandShakeFailed(void);
	void __fastcall DoOnTLSHandShakeFailed(void);
	void __fastcall ProcessTLSHandShakeFailed(void);
	virtual void __fastcall SetIOHandler(Idiohandler::TIdIOHandler* AValue);
	virtual void __fastcall SetUseTLS(TIdUseTLS AValue);
	virtual void __fastcall TLSHandshake(void);
	virtual void __fastcall InitComponent(void);
	__property TIdUseTLS UseTLS = {read=FUseTLS, write=SetUseTLS, default=0};
	
public:
	__fastcall virtual ~TIdExplicitTLSClient(void);
	virtual void __fastcall Connect(void)/* overload */;
	__property bool SupportsTLS = {read=GetSupportsTLS, nodefault};
	__property Classes::TStrings* Capabilities = {read=FCapabilities};
	__property TIdOnTLSNegotiationFailure OnTLSHandShakeFailed = {read=FOnTLSHandShakeFailed, write=FOnTLSHandShakeFailed};
	__property TIdOnTLSNegotiationFailure OnTLSNotAvailable = {read=FOnTLSNotAvailable, write=FOnTLSNotAvailable};
	__property TIdOnTLSNegotiationFailure OnTLSNegCmdFailed = {read=FOnTLSNegCmdFailed, write=FOnTLSNegCmdFailed};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdExplicitTLSClient(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	
};


class DELPHICLASS EIdTLSClientException;
class PASCALIMPLEMENTATION EIdTLSClientException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientException(void) { }
	
};


class DELPHICLASS EIdTLSClientSSLIOHandlerRequred;
class PASCALIMPLEMENTATION EIdTLSClientSSLIOHandlerRequred : public EIdTLSClientException
{
	typedef EIdTLSClientException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientSSLIOHandlerRequred(const System::UnicodeString AMsg)/* overload */ : EIdTLSClientException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSClientException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(int Ident)/* overload */ : EIdTLSClientException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSClientException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(const System::UnicodeString Msg, int AHelpContext) : EIdTLSClientException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSClientException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(int Ident, int AHelpContext)/* overload */ : EIdTLSClientException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientSSLIOHandlerRequred(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSClientException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientSSLIOHandlerRequred(void) { }
	
};


class DELPHICLASS EIdTLSClientCanNotSetWhileConnected;
class PASCALIMPLEMENTATION EIdTLSClientCanNotSetWhileConnected : public EIdTLSClientException
{
	typedef EIdTLSClientException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientCanNotSetWhileConnected(const System::UnicodeString AMsg)/* overload */ : EIdTLSClientException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSClientException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(int Ident)/* overload */ : EIdTLSClientException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSClientException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(const System::UnicodeString Msg, int AHelpContext) : EIdTLSClientException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSClientException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(int Ident, int AHelpContext)/* overload */ : EIdTLSClientException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientCanNotSetWhileConnected(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSClientException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientCanNotSetWhileConnected(void) { }
	
};


class DELPHICLASS EIdTLSClientTLSNotAvailable;
class PASCALIMPLEMENTATION EIdTLSClientTLSNotAvailable : public EIdTLSClientException
{
	typedef EIdTLSClientException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientTLSNotAvailable(const System::UnicodeString AMsg)/* overload */ : EIdTLSClientException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientTLSNotAvailable(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSClientException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientTLSNotAvailable(int Ident)/* overload */ : EIdTLSClientException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientTLSNotAvailable(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSClientException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientTLSNotAvailable(const System::UnicodeString Msg, int AHelpContext) : EIdTLSClientException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientTLSNotAvailable(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSClientException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientTLSNotAvailable(int Ident, int AHelpContext)/* overload */ : EIdTLSClientException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientTLSNotAvailable(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSClientException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientTLSNotAvailable(void) { }
	
};


class DELPHICLASS EIdTLSClientTLSNegCmdFailed;
class PASCALIMPLEMENTATION EIdTLSClientTLSNegCmdFailed : public EIdTLSClientException
{
	typedef EIdTLSClientException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientTLSNegCmdFailed(const System::UnicodeString AMsg)/* overload */ : EIdTLSClientException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientTLSNegCmdFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSClientException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientTLSNegCmdFailed(int Ident)/* overload */ : EIdTLSClientException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientTLSNegCmdFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSClientException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientTLSNegCmdFailed(const System::UnicodeString Msg, int AHelpContext) : EIdTLSClientException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientTLSNegCmdFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSClientException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientTLSNegCmdFailed(int Ident, int AHelpContext)/* overload */ : EIdTLSClientException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientTLSNegCmdFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSClientException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientTLSNegCmdFailed(void) { }
	
};


class DELPHICLASS EIdTLSClientTLSHandShakeFailed;
class PASCALIMPLEMENTATION EIdTLSClientTLSHandShakeFailed : public EIdTLSClientException
{
	typedef EIdTLSClientException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientTLSHandShakeFailed(const System::UnicodeString AMsg)/* overload */ : EIdTLSClientException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientTLSHandShakeFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSClientException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientTLSHandShakeFailed(int Ident)/* overload */ : EIdTLSClientException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientTLSHandShakeFailed(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSClientException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientTLSHandShakeFailed(const System::UnicodeString Msg, int AHelpContext) : EIdTLSClientException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientTLSHandShakeFailed(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSClientException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientTLSHandShakeFailed(int Ident, int AHelpContext)/* overload */ : EIdTLSClientException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientTLSHandShakeFailed(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSClientException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientTLSHandShakeFailed(void) { }
	
};


class DELPHICLASS EIdTLSServerException;
class PASCALIMPLEMENTATION EIdTLSServerException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSServerException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSServerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSServerException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSServerException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSServerException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSServerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSServerException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSServerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSServerException(void) { }
	
};


class DELPHICLASS EIdTLSServerSSLIOHandlerRequired;
class PASCALIMPLEMENTATION EIdTLSServerSSLIOHandlerRequired : public EIdTLSServerException
{
	typedef EIdTLSServerException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSServerSSLIOHandlerRequired(const System::UnicodeString AMsg)/* overload */ : EIdTLSServerException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSServerException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(int Ident)/* overload */ : EIdTLSServerException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSServerException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(const System::UnicodeString Msg, int AHelpContext) : EIdTLSServerException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSServerException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(int Ident, int AHelpContext)/* overload */ : EIdTLSServerException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSServerSSLIOHandlerRequired(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSServerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSServerSSLIOHandlerRequired(void) { }
	
};


class DELPHICLASS EIdTLSClientCanNotSetWhileActive;
class PASCALIMPLEMENTATION EIdTLSClientCanNotSetWhileActive : public EIdTLSClientException
{
	typedef EIdTLSClientException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTLSClientCanNotSetWhileActive(const System::UnicodeString AMsg)/* overload */ : EIdTLSClientException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTLSClientCanNotSetWhileActive(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTLSClientException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTLSClientCanNotSetWhileActive(int Ident)/* overload */ : EIdTLSClientException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTLSClientCanNotSetWhileActive(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTLSClientException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTLSClientCanNotSetWhileActive(const System::UnicodeString Msg, int AHelpContext) : EIdTLSClientException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTLSClientCanNotSetWhileActive(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTLSClientException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTLSClientCanNotSetWhileActive(int Ident, int AHelpContext)/* overload */ : EIdTLSClientException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTLSClientCanNotSetWhileActive(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTLSClientException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTLSClientCanNotSetWhileActive(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define ExplicitTLSVals (Set<TIdUseTLS, utNoTLSSupport, utUseExplicitTLS> () << utUseRequireTLS << utUseExplicitTLS )
static const TIdUseTLS DEF_USETLS = (TIdUseTLS)(0);

}	/* namespace Idexplicittlsclientserverbase */
using namespace Idexplicittlsclientserverbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdexplicittlsclientserverbaseHPP
