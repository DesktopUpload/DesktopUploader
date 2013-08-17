// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtelnet.pas' rev: 20.00

#ifndef IdtelnetHPP
#define IdtelnetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtelnet
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdTelnetState { tnsDATA, tnsIAC, tnsIAC_SB, tnsIAC_WILL, tnsIAC_DO, tnsIAC_WONT, tnsIAC_DONT, tnsIAC_SBIAC, tnsIAC_SBDATA, tnsSBDATA_IAC };
#pragma option pop

#pragma option push -b-
enum TIdTelnetCommand { tncNoLocalEcho, tncLocalEcho, tncEcho };
#pragma option pop

class DELPHICLASS TIdTelnet;
typedef void __fastcall (__closure *TIdTelnetDataAvailEvent)(TIdTelnet* Sender, const System::UnicodeString Buffer);

typedef void __fastcall (__closure *TIdTelnetCommandEvent)(TIdTelnet* Sender, TIdTelnetCommand Status);

class DELPHICLASS TIdTelnetReadThread;
class PASCALIMPLEMENTATION TIdTelnetReadThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	TIdTelnet* FClient;
	virtual void __fastcall Run(void);
	void __fastcall HandleIncomingData(void);
	
public:
	__fastcall TIdTelnetReadThread(TIdTelnet* AClient);
	__property TIdTelnet* Client = {read=FClient};
public:
	/* TIdThread.Destroy */ inline __fastcall virtual ~TIdTelnetReadThread(void) { }
	
};


class PASCALIMPLEMENTATION TIdTelnet : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	TIdTelnetState fState;
	System::WideChar fReply;
	System::UnicodeString fSentDoDont;
	System::UnicodeString fSentWillWont;
	System::UnicodeString fReceivedDoDont;
	System::UnicodeString fReceivedWillWont;
	System::UnicodeString fTerminal;
	bool fThreadedEvent;
	TIdTelnetDataAvailEvent FOnDataAvailable;
	bool fIamTelnet;
	TIdTelnetCommandEvent FOnTelnetCommand;
	TIdTelnetReadThread* FTelnetThread;
	void __fastcall DoOnDataAvailable(const System::UnicodeString Buf);
	__property TIdTelnetState State = {read=fState, write=fState, nodefault};
	__property System::WideChar Reply = {read=fReply, write=fReply, nodefault};
	__property System::UnicodeString SentDoDont = {read=fSentDoDont, write=fSentDoDont};
	__property System::UnicodeString SentWillWont = {read=fSentWillWont, write=fSentWillWont};
	__property System::UnicodeString ReceivedDoDont = {read=fReceivedDoDont, write=fReceivedDoDont};
	__property System::UnicodeString ReceivedWillWont = {read=fReceivedWillWont, write=fReceivedWillWont};
	__property bool IamTelnet = {read=fIamTelnet, write=fIamTelnet, nodefault};
	void __fastcall Negotiate(const System::UnicodeString Buf);
	void __fastcall Handle_SB(System::Byte CurrentSb, System::UnicodeString sbData, int sbCount);
	void __fastcall SendNegotiationResp(System::UnicodeString &Resp);
	void __fastcall DoTelnetCommand(TIdTelnetCommand Status);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdTelnet(void);
	virtual void __fastcall Connect(void)/* overload */;
	virtual void __fastcall Disconnect(bool ANotifyPeer)/* overload */;
	void __fastcall SendCh(System::WideChar Ch);
	__property TIdTelnetReadThread* TelnetThread = {read=FTelnetThread};
	
__published:
	__property Host;
	__property Port = {default=23};
	__property TIdTelnetCommandEvent OnTelnetCommand = {read=FOnTelnetCommand, write=FOnTelnetCommand};
	__property TIdTelnetDataAvailEvent OnDataAvailable = {read=FOnDataAvailable, write=FOnDataAvailable};
	__property System::UnicodeString Terminal = {read=fTerminal, write=fTerminal};
	__property bool ThreadedEvent = {read=fThreadedEvent, write=fThreadedEvent, default=0};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTelnet(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	inline void __fastcall  Disconnect(void){ Idtcpconnection::TIdTCPConnection::Disconnect(); }
	
};


class DELPHICLASS EIdTelnetError;
class PASCALIMPLEMENTATION EIdTelnetError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTelnetError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTelnetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTelnetError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTelnetError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTelnetError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTelnetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTelnetError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTelnetError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTelnetError(void) { }
	
};


class DELPHICLASS EIdTelnetClientConnectError;
class PASCALIMPLEMENTATION EIdTelnetClientConnectError : public EIdTelnetError
{
	typedef EIdTelnetError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTelnetClientConnectError(const System::UnicodeString AMsg)/* overload */ : EIdTelnetError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTelnetClientConnectError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTelnetError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTelnetClientConnectError(int Ident)/* overload */ : EIdTelnetError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTelnetClientConnectError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTelnetError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTelnetClientConnectError(const System::UnicodeString Msg, int AHelpContext) : EIdTelnetError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTelnetClientConnectError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTelnetError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTelnetClientConnectError(int Ident, int AHelpContext)/* overload */ : EIdTelnetError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTelnetClientConnectError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTelnetError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTelnetClientConnectError(void) { }
	
};


class DELPHICLASS EIdTelnetServerOnDataAvailableIsNil;
class PASCALIMPLEMENTATION EIdTelnetServerOnDataAvailableIsNil : public EIdTelnetError
{
	typedef EIdTelnetError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTelnetServerOnDataAvailableIsNil(const System::UnicodeString AMsg)/* overload */ : EIdTelnetError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdTelnetError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(int Ident)/* overload */ : EIdTelnetError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdTelnetError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(const System::UnicodeString Msg, int AHelpContext) : EIdTelnetError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdTelnetError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(int Ident, int AHelpContext)/* overload */ : EIdTelnetError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTelnetServerOnDataAvailableIsNil(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTelnetError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTelnetServerOnDataAvailableIsNil(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::WideChar TNC_EOR = (System::WideChar)(0xef);
static const System::WideChar TNC_SE = (System::WideChar)(0xf0);
static const System::WideChar TNC_NOP = (System::WideChar)(0xf1);
static const System::WideChar TNC_DATA_MARK = (System::WideChar)(0xf2);
static const System::WideChar TNC_BREAK = (System::WideChar)(0xf3);
static const System::WideChar TNC_IP = (System::WideChar)(0xf4);
static const System::WideChar TNC_AO = (System::WideChar)(0xf5);
static const System::WideChar TNC_AYT = (System::WideChar)(0xf6);
static const System::WideChar TNC_EC = (System::WideChar)(0xf7);
static const System::WideChar TNC_EL = (System::WideChar)(0xf8);
static const System::WideChar TNC_GA = (System::WideChar)(0xf9);
static const System::WideChar TNC_SB = (System::WideChar)(0xfa);
static const System::WideChar TNC_WILL = (System::WideChar)(0xfb);
static const System::WideChar TNC_WONT = (System::WideChar)(0xfc);
static const System::WideChar TNC_DO = (System::WideChar)(0xfd);
static const System::WideChar TNC_DONT = (System::WideChar)(0xfe);
static const System::WideChar TNC_IAC = (System::WideChar)(0xff);
static const WideChar TNO_BINARY = (WideChar)(0x0);
static const WideChar TNO_ECHO = (WideChar)(0x1);
static const WideChar TNO_RECONNECT = (WideChar)(0x2);
static const WideChar TNO_SGA = (WideChar)(0x3);
static const WideChar TNO_AMSN = (WideChar)(0x4);
static const WideChar TNO_STATUS = (WideChar)(0x5);
static const WideChar TNO_TIMING_MARK = (WideChar)(0x6);
static const WideChar TNO_RCTE = (WideChar)(0x7);
static const WideChar TNO_OLW = (WideChar)(0x8);
static const WideChar TNO_OPS = (WideChar)(0x9);
static const WideChar TNO_OCRD = (WideChar)(0xa);
static const WideChar TNO_OHTS = (WideChar)(0xb);
static const WideChar TNO_OHTD = (WideChar)(0xc);
static const WideChar TNO_OFD = (WideChar)(0xd);
static const WideChar TNO_OVT = (WideChar)(0xe);
static const WideChar TNO_OVTD = (WideChar)(0xf);
static const WideChar TNO_OLD = (WideChar)(0x10);
static const WideChar TNO_EA = (WideChar)(0x11);
static const WideChar TNO_LOGOUT = (WideChar)(0x12);
static const WideChar TNO_BYTE_MACRO = (WideChar)(0x13);
static const WideChar TNO_DET = (WideChar)(0x14);
static const WideChar TNO_SUPDUP = (WideChar)(0x15);
static const WideChar TNO_SUPDUP_OUTPUT = (WideChar)(0x16);
static const WideChar TNO_SL = (WideChar)(0x17);
static const WideChar TNO_TERMTYPE = (WideChar)(0x18);
static const WideChar TNO_EOR = (WideChar)(0x19);
static const WideChar TNO_TACACS_ID = (WideChar)(0x1a);
static const WideChar TNO_OM = (WideChar)(0x1b);
static const WideChar TNO_TLN = (WideChar)(0x1c);
static const WideChar TNO_3270REGIME = (WideChar)(0x1d);
static const WideChar TNO_X3PAD = (WideChar)(0x1e);
static const WideChar TNO_NAWS = (WideChar)(0x1f);
static const WideChar TNO_TERM_SPEED = (WideChar)(0x20);
static const WideChar TNO_RFLOW = (WideChar)(0x21);
static const WideChar TNO_LINEMODE = (WideChar)(0x22);
static const WideChar TNO_XDISPLOC = (WideChar)(0x23);
static const WideChar TNO_AUTH = (WideChar)(0x25);
static const WideChar TNO_ENCRYPT = (WideChar)(0x26);
static const System::WideChar TNO_EOL = (System::WideChar)(0xff);
static const WideChar TNOS_TERM_IS = (WideChar)(0x0);
static const WideChar TNOS_TERMTYPE_SEND = (WideChar)(0x1);
static const WideChar TNOS_REPLY = (WideChar)(0x2);
static const WideChar TNOS_NAME = (WideChar)(0x3);

}	/* namespace Idtelnet */
using namespace Idtelnet;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtelnetHPP
