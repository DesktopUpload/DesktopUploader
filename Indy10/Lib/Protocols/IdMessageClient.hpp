// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessageclient.pas' rev: 20.00

#ifndef IdmessageclientHPP
#define IdmessageclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcodermime.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idiohandlerstream.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessageclient
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIOHandlerStreamMsg;
class PASCALIMPLEMENTATION TIdIOHandlerStreamMsg : public Idiohandlerstream::TIdIOHandlerStream
{
	typedef Idiohandlerstream::TIdIOHandlerStream inherited;
	
protected:
	bool FTerminatorWasRead;
	System::Byte FLastByteRecv;
	virtual int __fastcall ReadDataFromSource(Sysutils::TBytes &VBuffer);
	
public:
	__fastcall virtual TIdIOHandlerStreamMsg(Classes::TComponent* AOwner, Classes::TStream* AReceiveStream, Classes::TStream* ASendStream)/* overload */;
	virtual bool __fastcall Readable(int AMSec = 0xffffffff);
public:
	/* TIdIOHandler.Destroy */ inline __fastcall virtual ~TIdIOHandlerStreamMsg(void) { }
	
};


class DELPHICLASS TIdMessageClient;
class PASCALIMPLEMENTATION TIdMessageClient : public Idexplicittlsclientserverbase::TIdExplicitTLSClient
{
	typedef Idexplicittlsclientserverbase::TIdExplicitTLSClient inherited;
	
protected:
	int FMsgLineLength;
	System::UnicodeString FMsgLineFold;
	virtual void __fastcall ReceiveBody(Idmessage::TIdMessage* AMsg, const System::UnicodeString ADelim = L".");
	virtual System::UnicodeString __fastcall ReceiveHeader(Idmessage::TIdMessage* AMsg, const System::UnicodeString AAltTerm = L"");
	virtual void __fastcall SendBody(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall SendHeader(Idmessage::TIdMessage* AMsg);
	void __fastcall EncodeAndWriteText(const Classes::TStrings* ABody, Sysutils::TEncoding* AEncoding);
	void __fastcall WriteFoldedLine(const System::UnicodeString ALine);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdMessageClient(void);
	void __fastcall ProcessMessage(Idmessage::TIdMessage* AMsg, bool AHeaderOnly = false)/* overload */;
	void __fastcall ProcessMessage(Idmessage::TIdMessage* AMsg, Classes::TStream* AStream, bool AHeaderOnly = false)/* overload */;
	void __fastcall ProcessMessage(Idmessage::TIdMessage* AMsg, const System::UnicodeString AFilename, bool AHeaderOnly = false)/* overload */;
	virtual void __fastcall SendMsg(Idmessage::TIdMessage* AMsg, bool AHeadersOnly = false)/* overload */;
	__property int MsgLineLength = {read=FMsgLineLength, write=FMsgLineLength, nodefault};
	__property System::UnicodeString MsgLineFold = {read=FMsgLineFold, write=FMsgLineFold};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageClient(Classes::TComponent* AOwner)/* overload */ : Idexplicittlsclientserverbase::TIdExplicitTLSClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessageclient */
using namespace Idmessageclient;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessageclientHPP
