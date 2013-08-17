// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idpop3.pas' rev: 20.00

#ifndef Idpop3HPP
#define Idpop3HPP

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
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsaslcollection.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Iduserpassprovider.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idpop3
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdPOP3AuthenticationType { patUserPass, patAPOP, patSASL };
#pragma option pop

class DELPHICLASS TIdPOP3;
class PASCALIMPLEMENTATION TIdPOP3 : public Idmessageclient::TIdMessageClient
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	TIdPOP3AuthenticationType FAuthType;
	bool FAutoLogin;
	System::UnicodeString FAPOPToken;
	bool FHasAPOP;
	bool FHasCAPA;
	Idsaslcollection::TIdSASLEntries* FSASLMechanisms;
	virtual Idreply::TIdReplyClass __fastcall GetReplyClass(void);
	virtual bool __fastcall GetSupportsTLS(void);
	void __fastcall SetSASLMechanisms(Idsaslcollection::TIdSASLEntries* AValue);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	int __fastcall CheckMessages(void);
	virtual void __fastcall Connect(void)/* overload */;
	virtual void __fastcall Login(void);
	__fastcall virtual ~TIdPOP3(void);
	bool __fastcall Delete(const int MsgNum);
	virtual void __fastcall DisconnectNotifyPeer(void);
	void __fastcall KeepAlive(void);
	bool __fastcall Reset(void);
	bool __fastcall Retrieve(const int MsgNum, Idmessage::TIdMessage* AMsg);
	bool __fastcall RetrieveHeader(const int MsgNum, Idmessage::TIdMessage* AMsg);
	int __fastcall RetrieveMsgSize(const int MsgNum);
	int __fastcall RetrieveMailBoxSize(void);
	bool __fastcall RetrieveRaw(const int aMsgNo, const Classes::TStrings* aDest)/* overload */;
	bool __fastcall RetrieveRaw(const int aMsgNo, const Classes::TStream* aDest)/* overload */;
	bool __fastcall UIDL(const Classes::TStrings* ADest, const int AMsgNum = 0xffffffff);
	bool __fastcall Top(const int AMsgNum, const Classes::TStrings* ADest, const int AMaxLines = 0x0);
	bool __fastcall CAPA(void);
	__property bool HasAPOP = {read=FHasAPOP, nodefault};
	__property bool HasCAPA = {read=FHasCAPA, nodefault};
	
__published:
	__property TIdPOP3AuthenticationType AuthType = {read=FAuthType, write=FAuthType, default=0};
	__property bool AutoLogin = {read=FAutoLogin, write=FAutoLogin, nodefault};
	__property Host;
	__property Username;
	__property UseTLS = {default=0};
	__property Password;
	__property Port = {default=110};
	__property Idsaslcollection::TIdSASLEntries* SASLMechanisms = {read=FSASLMechanisms, write=SetSASLMechanisms};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdPOP3(Classes::TComponent* AOwner)/* overload */ : Idmessageclient::TIdMessageClient(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	
};


class DELPHICLASS EIdPOP3Exception;
class PASCALIMPLEMENTATION EIdPOP3Exception : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdPOP3Exception(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdPOP3Exception(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdPOP3Exception(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdPOP3Exception(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdPOP3Exception(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdPOP3Exception(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdPOP3Exception(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdPOP3Exception(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdPOP3Exception(void) { }
	
};


class DELPHICLASS EIdDoesNotSupportAPOP;
class PASCALIMPLEMENTATION EIdDoesNotSupportAPOP : public EIdPOP3Exception
{
	typedef EIdPOP3Exception inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDoesNotSupportAPOP(const System::UnicodeString AMsg)/* overload */ : EIdPOP3Exception(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDoesNotSupportAPOP(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdPOP3Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDoesNotSupportAPOP(int Ident)/* overload */ : EIdPOP3Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDoesNotSupportAPOP(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdPOP3Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDoesNotSupportAPOP(const System::UnicodeString Msg, int AHelpContext) : EIdPOP3Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDoesNotSupportAPOP(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdPOP3Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDoesNotSupportAPOP(int Ident, int AHelpContext)/* overload */ : EIdPOP3Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDoesNotSupportAPOP(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdPOP3Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDoesNotSupportAPOP(void) { }
	
};


class DELPHICLASS EIdUnrecognizedReply;
class PASCALIMPLEMENTATION EIdUnrecognizedReply : public EIdPOP3Exception
{
	typedef EIdPOP3Exception inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdUnrecognizedReply(const System::UnicodeString AMsg)/* overload */ : EIdPOP3Exception(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdUnrecognizedReply(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdPOP3Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdUnrecognizedReply(int Ident)/* overload */ : EIdPOP3Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdUnrecognizedReply(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdPOP3Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdUnrecognizedReply(const System::UnicodeString Msg, int AHelpContext) : EIdPOP3Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdUnrecognizedReply(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdPOP3Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdUnrecognizedReply(int Ident, int AHelpContext)/* overload */ : EIdPOP3Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdUnrecognizedReply(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdPOP3Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdUnrecognizedReply(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool DEF_POP3USE_IMPLICIT_TLS = false;
static const TIdPOP3AuthenticationType DEF_ATYPE = (TIdPOP3AuthenticationType)(0);

}	/* namespace Idpop3 */
using namespace Idpop3;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idpop3HPP
