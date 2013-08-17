// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idnntp.pas' rev: 20.00

#ifndef IdnntpHPP
#define IdnntpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idnntp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdModeType { mtStream, mtIHAVE, mtReader };
#pragma option pop

#pragma option push -b-
enum TIdNNTPPermission { crCanPost, crNoPost, crAuthRequired, crTempUnavailable };
#pragma option pop

#pragma option push -b-
enum TIdModeSetResult { mrCanStream, mrNoStream, mrCanIHAVE, mrNoIHAVE, mrCanPost, mrNoPost };
#pragma option pop

typedef void __fastcall (__closure *TIdEventStreaming)(System::UnicodeString AMesgID, bool &AAccepted);

typedef void __fastcall (__closure *TIdNewsTransporTIdEvent)(Classes::TStrings* AMsg);

typedef void __fastcall (__closure *TIdEvenTIdNewsgroupList)(System::UnicodeString ANewsgroup, int ALow, int AHigh, System::UnicodeString AType, bool &ACanContinue);

typedef void __fastcall (__closure *TIdEventXOVER)(int AArticleIndex, System::UnicodeString ASubject, System::UnicodeString AFrom, System::TDateTime ADate, System::UnicodeString AMsgId, System::UnicodeString AReferences, int AByteCount, int ALineCount, System::UnicodeString AExtraData, bool &VCanContinue);

typedef void __fastcall (__closure *TIdEventNewNewsList)(System::UnicodeString AMsgID, bool &ACanContinue);

typedef void __fastcall (__closure *TIdEventXHDREntry)(System::UnicodeString AHeader, System::UnicodeString AMsg, System::UnicodeString AHeaderData, bool &ACanContinue);

class DELPHICLASS TIdNNTP;
class PASCALIMPLEMENTATION TIdNNTP : public Idmessageclient::TIdMessageClient
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	int FGreetingCode;
	int FMsgHigh;
	int FMsgLow;
	int FMsgCount;
	System::UnicodeString FNewsAgent;
	TIdEvenTIdNewsgroupList FOnNewsgroupList;
	TIdEvenTIdNewsgroupList FOnNewGroupsList;
	TIdEventNewNewsList FOnNewNewsList;
	TIdEventXHDREntry FOnXHDREntry;
	TIdEventXOVER FOnXOVER;
	TIdModeType FModeType;
	TIdModeSetResult FModeResult;
	TIdNNTPPermission FPermission;
	bool FForceAuth;
	bool FHDRSupported;
	bool FOVERSupported;
	void __fastcall AfterConnect(void);
	void __fastcall GetCapability(void);
	System::UnicodeString __fastcall ConvertDateTimeDist(System::TDateTime ADate, bool AGMT, System::UnicodeString ADistributions);
	virtual bool __fastcall GetSupportsTLS(void);
	virtual void __fastcall InitComponent(void);
	void __fastcall ProcessGroupList(System::UnicodeString ACmd, int AResponse, TIdEvenTIdNewsgroupList ALisTIdEvent);
	void __fastcall XHDRCommon(System::UnicodeString AHeader, System::UnicodeString AParam);
	void __fastcall XOVERCommon(System::UnicodeString AParam);
	void __fastcall StartTLS(void);
	
public:
	void __fastcall Check(Classes::TStrings* AMsgIDs, Classes::TStrings* AResponses);
	virtual void __fastcall Connect(void)/* overload */;
	__fastcall virtual ~TIdNNTP(void);
	virtual void __fastcall DisconnectNotifyPeer(void);
	bool __fastcall GetArticle(Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetArticle(int AMsgNo, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetArticle(System::UnicodeString AMsgID, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetArticle(Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetArticle(int AMsgNo, Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetArticle(System::UnicodeString AMsgID, Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetArticle(Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetArticle(int AMsgNo, Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetArticle(System::UnicodeString AMsgID, Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetBody(Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetBody(int AMsgNo, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetBody(System::UnicodeString AMsgID, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetBody(Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetBody(int AMsgNo, Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetBody(System::UnicodeString AMsgID, Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetBody(Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetBody(int AMsgNo, Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetBody(System::UnicodeString AMsgID, Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetHeader(Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetHeader(int AMsgNo, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetHeader(System::UnicodeString AMsgID, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall GetHeader(Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetHeader(int AMsgNo, Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetHeader(System::UnicodeString AMsgID, Classes::TStrings* AMsg)/* overload */;
	bool __fastcall GetHeader(Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetHeader(int AMsgNo, Classes::TStream* AMsg)/* overload */;
	bool __fastcall GetHeader(System::UnicodeString AMsgID, Classes::TStream* AMsg)/* overload */;
	void __fastcall GetNewsgroupList(void)/* overload */;
	void __fastcall GetNewsgroupList(Classes::TStrings* AList)/* overload */;
	void __fastcall GetNewsgroupList(Classes::TStream* AStream)/* overload */;
	void __fastcall GetNewGroupsList(System::TDateTime ADate, bool AGMT, System::UnicodeString ADistributions)/* overload */;
	void __fastcall GetNewGroupsList(System::TDateTime ADate, bool AGMT, System::UnicodeString ADistributions, Classes::TStrings* AList)/* overload */;
	void __fastcall GetNewNewsList(System::UnicodeString ANewsgroups, System::TDateTime ADate, bool AGMT, System::UnicodeString ADistributions)/* overload */;
	void __fastcall GetNewNewsList(System::UnicodeString ANewsgroups, System::TDateTime ADate, bool AGMT, System::UnicodeString ADistributions, Classes::TStrings* AList)/* overload */;
	void __fastcall GetOverviewFMT(Classes::TStrings* AResponse);
	bool __fastcall IsExtCmdSupported(System::UnicodeString AExtension);
	void __fastcall IHAVE(Classes::TStrings* AMsg);
	bool __fastcall Next(void);
	bool __fastcall Previous(void);
	void __fastcall ParseXOVER(System::UnicodeString Aline, int &AArticleIndex, System::UnicodeString &ASubject, System::UnicodeString &AFrom, System::TDateTime &ADate, System::UnicodeString &AMsgId, System::UnicodeString &AReferences, int &AByteCount, int &ALineCount, System::UnicodeString &AExtraData);
	void __fastcall ParseNewsGroup(System::UnicodeString ALine, /* out */ System::UnicodeString &ANewsGroup, /* out */ int &AHi, /* out */ int &ALo, /* out */ System::UnicodeString &AStatus);
	void __fastcall ParseXHDRLine(System::UnicodeString ALine, /* out */ System::UnicodeString &AMsg, /* out */ System::UnicodeString &AHeaderData);
	void __fastcall Post(Idmessage::TIdMessage* AMsg)/* overload */;
	void __fastcall Post(Classes::TStream* AStream)/* overload */;
	virtual short __fastcall SendCmd(System::UnicodeString AOut, short const *AResponse, const int AResponse_Size, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	bool __fastcall SelectArticle(int AMsgNo);
	void __fastcall SelectGroup(System::UnicodeString AGroup);
	System::UnicodeString __fastcall TakeThis(System::UnicodeString AMsgID, Classes::TStream* AMsg);
	void __fastcall XHDR(System::UnicodeString AHeader, System::UnicodeString AParam, Classes::TStrings* AResponse)/* overload */;
	void __fastcall XHDR(System::UnicodeString AHeader, System::UnicodeString AParam)/* overload */;
	void __fastcall XOVER(System::UnicodeString AParam, Classes::TStrings* AResponse)/* overload */;
	void __fastcall XOVER(System::UnicodeString AParam, Classes::TStream* AResponse)/* overload */;
	void __fastcall XOVER(System::UnicodeString AParam)/* overload */;
	void __fastcall SendAuth(void);
	__property TIdModeSetResult ModeResult = {read=FModeResult, write=FModeResult, nodefault};
	__property int MsgCount = {read=FMsgCount, nodefault};
	__property int MsgHigh = {read=FMsgHigh, nodefault};
	__property int MsgLow = {read=FMsgLow, nodefault};
	__property TIdNNTPPermission Permission = {read=FPermission, nodefault};
	
__published:
	__property System::UnicodeString NewsAgent = {read=FNewsAgent, write=FNewsAgent};
	__property TIdModeType Mode = {read=FModeType, write=FModeType, default=2};
	__property Password;
	__property Username;
	__property TIdEvenTIdNewsgroupList OnNewsgroupList = {read=FOnNewsgroupList, write=FOnNewsgroupList};
	__property TIdEvenTIdNewsgroupList OnNewGroupsList = {read=FOnNewGroupsList, write=FOnNewGroupsList};
	__property TIdEventNewNewsList OnNewNewsList = {read=FOnNewNewsList, write=FOnNewNewsList};
	__property TIdEventXHDREntry OnXHDREntry = {read=FOnXHDREntry, write=FOnXHDREntry};
	__property TIdEventXOVER OnXOVER = {read=FOnXOVER, write=FOnXOVER};
	__property OnTLSNotAvailable;
	__property Port = {default=119};
	__property Host;
	__property UseTLS = {default=0};
	__property bool ForceAuth = {read=FForceAuth, write=FForceAuth, default=0};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdNNTP(Classes::TComponent* AOwner)/* overload */ : Idmessageclient::TIdMessageClient(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	inline short __fastcall  SendCmd(System::UnicodeString AOut, const short AResponse = (short)(0xffffffff), Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::SendCmd(AOut, AResponse, AEncoding); }
	inline System::UnicodeString __fastcall  SendCmd(System::UnicodeString AOut, const System::UnicodeString AResponse, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::SendCmd(AOut, AResponse, AEncoding); }
	
};


class DELPHICLASS EIdNNTPException;
class PASCALIMPLEMENTATION EIdNNTPException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPException(void) { }
	
};


class DELPHICLASS EIdNNTPNoOnNewGroupsList;
class PASCALIMPLEMENTATION EIdNNTPNoOnNewGroupsList : public EIdNNTPException
{
	typedef EIdNNTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPNoOnNewGroupsList(const System::UnicodeString AMsg)/* overload */ : EIdNNTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnNewGroupsList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnNewGroupsList(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnNewGroupsList(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnNewGroupsList(void) { }
	
};


class DELPHICLASS EIdNNTPNoOnNewNewsList;
class PASCALIMPLEMENTATION EIdNNTPNoOnNewNewsList : public EIdNNTPException
{
	typedef EIdNNTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPNoOnNewNewsList(const System::UnicodeString AMsg)/* overload */ : EIdNNTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnNewNewsList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnNewNewsList(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnNewNewsList(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnNewNewsList(void) { }
	
};


class DELPHICLASS EIdNNTPNoOnNewsgroupList;
class PASCALIMPLEMENTATION EIdNNTPNoOnNewsgroupList : public EIdNNTPException
{
	typedef EIdNNTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPNoOnNewsgroupList(const System::UnicodeString AMsg)/* overload */ : EIdNNTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnNewsgroupList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnNewsgroupList(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnNewsgroupList(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnNewsgroupList(void) { }
	
};


class DELPHICLASS EIdNNTPNoOnXHDREntry;
class PASCALIMPLEMENTATION EIdNNTPNoOnXHDREntry : public EIdNNTPException
{
	typedef EIdNNTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPNoOnXHDREntry(const System::UnicodeString AMsg)/* overload */ : EIdNNTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnXHDREntry(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnXHDREntry(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnXHDREntry(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnXHDREntry(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnXHDREntry(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnXHDREntry(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnXHDREntry(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnXHDREntry(void) { }
	
};


class DELPHICLASS EIdNNTPNoOnXOVER;
class PASCALIMPLEMENTATION EIdNNTPNoOnXOVER : public EIdNNTPException
{
	typedef EIdNNTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPNoOnXOVER(const System::UnicodeString AMsg)/* overload */ : EIdNNTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnXOVER(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnXOVER(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnXOVER(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnXOVER(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnXOVER(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnXOVER(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnXOVER(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnXOVER(void) { }
	
};


class DELPHICLASS EIdNNTPStringListNotInitialized;
class PASCALIMPLEMENTATION EIdNNTPStringListNotInitialized : public EIdNNTPException
{
	typedef EIdNNTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPStringListNotInitialized(const System::UnicodeString AMsg)/* overload */ : EIdNNTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPStringListNotInitialized(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPStringListNotInitialized(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPStringListNotInitialized(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPStringListNotInitialized(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPStringListNotInitialized(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPStringListNotInitialized(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPStringListNotInitialized(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPStringListNotInitialized(void) { }
	
};


class DELPHICLASS EIdNNTPConnectionRefused;
class PASCALIMPLEMENTATION EIdNNTPConnectionRefused : public Idreplyrfc::EIdReplyRFCError
{
	typedef Idreplyrfc::EIdReplyRFCError inherited;
	
public:
	/* EIdReplyRFCError.CreateError */ inline __fastcall virtual EIdNNTPConnectionRefused(const int AErrorCode, const System::UnicodeString AReplyMessage) : Idreplyrfc::EIdReplyRFCError(AErrorCode, AReplyMessage) { }
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPConnectionRefused(const System::UnicodeString AMsg)/* overload */ : Idreplyrfc::EIdReplyRFCError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPConnectionRefused(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPConnectionRefused(int Ident)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPConnectionRefused(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPConnectionRefused(const System::UnicodeString Msg, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPConnectionRefused(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPConnectionRefused(int Ident, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPConnectionRefused(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPConnectionRefused(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idnntp */
using namespace Idnntp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdnntpHPP
