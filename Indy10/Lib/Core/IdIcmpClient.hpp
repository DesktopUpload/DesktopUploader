// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idicmpclient.pas' rev: 20.00

#ifndef IdicmpclientHPP
#define IdicmpclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idrawbase.hpp>	// Pascal unit
#include <Idrawclient.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idicmpclient
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TReplyStatusTypes { rsEcho, rsError, rsTimeOut, rsErrorUnreachable, rsErrorTTLExceeded, rsErrorPacketTooBig, rsErrorParameter, rsErrorDatagramConversion, rsErrorSecurityFailure, rsSourceQuench, rsRedirect, rsTimeStamp, rsInfoRequest, rsAddressMaskRequest, rsTraceRoute, rsMobileHostReg, rsMobileHostRedir, rsIPv6WhereAreYou, rsIPv6IAmHere, rsSKIP };
#pragma option pop

class DELPHICLASS TReplyStatus;
class PASCALIMPLEMENTATION TReplyStatus : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	int FBytesReceived;
	System::UnicodeString FFromIpAddress;
	System::UnicodeString FToIpAddress;
	System::Byte FMsgType;
	System::Byte FMsgCode;
	System::Word FSequenceId;
	unsigned FMsRoundTripTime;
	System::Byte FTimeToLive;
	TReplyStatusTypes FReplyStatusType;
	int FPacketNumber;
	System::UnicodeString FHostName;
	System::UnicodeString FMsg;
	System::UnicodeString FRedirectTo;
	
public:
	__property System::UnicodeString RedirectTo = {read=FRedirectTo, write=FRedirectTo};
	__property System::UnicodeString Msg = {read=FMsg, write=FMsg};
	__property int BytesReceived = {read=FBytesReceived, write=FBytesReceived, nodefault};
	__property System::UnicodeString FromIpAddress = {read=FFromIpAddress, write=FFromIpAddress};
	__property System::UnicodeString ToIpAddress = {read=FToIpAddress, write=FToIpAddress};
	__property System::Byte MsgType = {read=FMsgType, write=FMsgType, nodefault};
	__property System::Byte MsgCode = {read=FMsgCode, write=FMsgCode, nodefault};
	__property System::Word SequenceId = {read=FSequenceId, write=FSequenceId, nodefault};
	__property unsigned MsRoundTripTime = {read=FMsRoundTripTime, write=FMsRoundTripTime, nodefault};
	__property System::Byte TimeToLive = {read=FTimeToLive, write=FTimeToLive, nodefault};
	__property TReplyStatusTypes ReplyStatusType = {read=FReplyStatusType, write=FReplyStatusType, nodefault};
	__property System::UnicodeString HostName = {read=FHostName, write=FHostName};
	__property int PacketNumber = {read=FPacketNumber, write=FPacketNumber, nodefault};
public:
	/* TObject.Create */ inline __fastcall TReplyStatus(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TReplyStatus(void) { }
	
};


typedef void __fastcall (__closure *TOnReplyEvent)(Classes::TComponent* ASender, const TReplyStatus* AReplyStatus);

class DELPHICLASS TIdCustomIcmpClient;
class PASCALIMPLEMENTATION TIdCustomIcmpClient : public Idrawclient::TIdRawClient
{
	typedef Idrawclient::TIdRawClient inherited;
	
protected:
	unsigned FStartTime;
	int FPacketSize;
	Sysutils::TBytes FBufReceive;
	Sysutils::TBytes FBufIcmp;
	System::Word wSeqNo;
	int iDataSize;
	TReplyStatus* FReplyStatus;
	TOnReplyEvent FOnReply;
	System::UnicodeString FReplydata;
	bool __fastcall DecodeIPv6Packet(unsigned BytesRead);
	bool __fastcall DecodeIPv4Packet(unsigned BytesRead);
	bool __fastcall DecodeResponse(unsigned BytesRead);
	virtual void __fastcall DoReply(void);
	void __fastcall GetEchoReply(void);
	virtual void __fastcall InitComponent(void);
	void __fastcall PrepareEchoRequestIPv6(const System::UnicodeString ABuffer);
	void __fastcall PrepareEchoRequestIPv4(const System::UnicodeString ABuffer);
	void __fastcall PrepareEchoRequest(const System::UnicodeString ABuffer);
	void __fastcall SendEchoRequest(void)/* overload */;
	void __fastcall SendEchoRequest(const System::UnicodeString AIP)/* overload */;
	int __fastcall GetPacketSize(void);
	void __fastcall SetPacketSize(const int AValue);
	void __fastcall InternalPing(const System::UnicodeString AIP, const System::UnicodeString ABuffer = L"", System::Word SequenceID = (System::Word)(0x0))/* overload */;
	__property int PacketSize = {read=GetPacketSize, write=SetPacketSize, nodefault};
	__property System::UnicodeString ReplyData = {read=FReplydata};
	__property TReplyStatus* ReplyStatus = {read=FReplyStatus};
	
public:
	__fastcall virtual ~TIdCustomIcmpClient(void);
	virtual void __fastcall Send(const System::UnicodeString AHost, const System::Word APort, const Sysutils::TBytes ABuffer)/* overload */;
	virtual void __fastcall Send(const Sysutils::TBytes ABuffer)/* overload */;
	TReplyStatus* __fastcall Receive(int ATimeOut);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdCustomIcmpClient(Classes::TComponent* AOwner)/* overload */ : Idrawclient::TIdRawClient(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Send(const System::UnicodeString AData){ Idrawbase::TIdRawBase::Send(AData); }
	inline void __fastcall  Send(const System::UnicodeString AHost, const System::Word APort, const System::UnicodeString AData){ Idrawbase::TIdRawBase::Send(AHost, APort, AData); }
	
};


class DELPHICLASS TIdIcmpClient;
class PASCALIMPLEMENTATION TIdIcmpClient : public TIdCustomIcmpClient
{
	typedef TIdCustomIcmpClient inherited;
	
public:
	void __fastcall Ping(const System::UnicodeString ABuffer = L"", System::Word SequenceID = (System::Word)(0x0));
	__property ReplyData;
	__property ReplyStatus;
	
__published:
	__property Host;
	__property IPVersion;
	__property PacketSize;
	__property ReceiveTimeout = {default=5000};
	__property TOnReplyEvent OnReply = {read=FOnReply, write=FOnReply};
public:
	/* TIdCustomIcmpClient.Destroy */ inline __fastcall virtual ~TIdIcmpClient(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIcmpClient(Classes::TComponent* AOwner)/* overload */ : TIdCustomIcmpClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt DEF_PACKET_SIZE = 0x20;
static const Word MAX_PACKET_SIZE = 0x400;
static const Byte iDEFAULTPACKETSIZE = 0x80;
static const Word iDEFAULTREPLYBUFSIZE = 0x400;
static const Word Id_TIDICMP_ReceiveTimeout = 0x1388;

}	/* namespace Idicmpclient */
using namespace Idicmpclient;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdicmpclientHPP
