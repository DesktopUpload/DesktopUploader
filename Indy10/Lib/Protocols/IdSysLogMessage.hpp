// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsyslogmessage.pas' rev: 20.00

#ifndef IdsyslogmessageHPP
#define IdsyslogmessageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsyslogmessage
{
//-- type declarations -------------------------------------------------------
typedef Byte TIdSyslogPRI;

#pragma option push -b-
enum TIdSyslogFacility { sfKernel, sfUserLevel, sfMailSystem, sfSystemDaemon, sfSecurityOne, sfSysLogInternal, sfLPR, sfNNTP, sfUUCP, sfClockDaemonOne, sfSecurityTwo, sfFTPDaemon, sfNTP, sfLogAudit, sfLogAlert, sfClockDaemonTwo, sfLocalUseZero, sfLocalUseOne, sfLocalUseTwo, sfLocalUseThree, sfLocalUseFour, sfLocalUseFive, sfLocalUseSix, sfLocalUseSeven };
#pragma option pop

#pragma option push -b-
enum TIdSyslogSeverity { slEmergency, slAlert, slCritical, slError, slWarning, slNotice, slInformational, slDebug };
#pragma option pop

class DELPHICLASS TIdSysLogMsgPart;
class PASCALIMPLEMENTATION TIdSysLogMsgPart : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	bool FPIDAvailable;
	System::UnicodeString FProcess;
	int FPID;
	System::UnicodeString FContent;
	void __fastcall SetPID(int AValue);
	void __fastcall SetProcess(const System::UnicodeString AValue);
	System::UnicodeString __fastcall GetText();
	void __fastcall SetText(const System::UnicodeString AValue);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString Text = {read=GetText, write=SetText};
	__property bool PIDAvailable = {read=FPIDAvailable, write=FPIDAvailable, stored=false, nodefault};
	__property System::UnicodeString Process = {read=FProcess, write=SetProcess, stored=false};
	__property int PID = {read=FPID, write=SetPID, stored=false, nodefault};
	__property System::UnicodeString Content = {read=FContent, write=FContent, stored=false};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdSysLogMsgPart(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdSysLogMsgPart(void) : Classes::TPersistent() { }
	
};


class DELPHICLASS TIdSysLogMessage;
class PASCALIMPLEMENTATION TIdSysLogMessage : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TIdSysLogMsgPart* FMsg;
	TIdSyslogFacility FFacility;
	TIdSyslogSeverity FSeverity;
	System::UnicodeString FHostname;
	System::UnicodeString FMessage;
	System::TDateTime FTimeStamp;
	System::UnicodeString FRawMessage;
	System::UnicodeString FPeer;
	TIdSyslogPRI FPri;
	Idbasecomponent::TIdBaseComponent* FUDPCliComp;
	void __fastcall SetFacility(const TIdSyslogFacility AValue);
	void __fastcall SetSeverity(const TIdSyslogSeverity AValue);
	void __fastcall SetHostname(const System::UnicodeString AValue);
	void __fastcall SetRawMessage(const System::UnicodeString Value);
	void __fastcall SetTimeStamp(const System::TDateTime AValue);
	void __fastcall SetMsg(const TIdSysLogMsgPart* AValue);
	void __fastcall SetPri(const TIdSyslogPRI Value);
	System::UnicodeString __fastcall GetHeader();
	virtual void __fastcall CheckASCIIRange(System::UnicodeString &Data);
	virtual void __fastcall ReadPRI(int &StartPos);
	virtual void __fastcall ReadHeader(int &StartPos);
	virtual void __fastcall ReadMSG(int &StartPos);
	virtual void __fastcall Parse(void);
	virtual void __fastcall UpdatePRI(void);
	virtual System::TDateTime __fastcall DecodeTimeStamp(System::UnicodeString TimeStampString);
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall virtual ~TIdSysLogMessage(void);
	virtual System::UnicodeString __fastcall EncodeMessage();
	virtual void __fastcall ReadFromBytes(const Sysutils::TBytes ASrc, const System::UnicodeString APeer);
	__property System::UnicodeString RawMessage = {read=FRawMessage, write=SetRawMessage};
	void __fastcall SendToHost(const System::UnicodeString Dest);
	__property System::UnicodeString Peer = {read=FPeer, write=FPeer};
	__property System::TDateTime TimeStamp = {read=FTimeStamp, write=SetTimeStamp};
	
__published:
	__property TIdSyslogPRI Pri = {read=FPri, write=SetPri, default=13};
	__property TIdSyslogFacility Facility = {read=FFacility, write=SetFacility, stored=false, nodefault};
	__property TIdSyslogSeverity Severity = {read=FSeverity, write=SetSeverity, stored=false, nodefault};
	__property System::UnicodeString Hostname = {read=FHostname, write=SetHostname, stored=false};
	__property TIdSysLogMsgPart* Msg = {read=FMsg, write=SetMsg};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSysLogMessage(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Word __fastcall logFacilityToNo(TIdSyslogFacility AFac);
extern PACKAGE TIdSyslogFacility __fastcall NoToFacility(System::Word AFac);
extern PACKAGE System::Word __fastcall logSeverityToNo(TIdSyslogSeverity ASev);
extern PACKAGE TIdSyslogSeverity __fastcall NoToSeverity(System::Word ASev);
extern PACKAGE System::UnicodeString __fastcall SeverityToString(TIdSyslogSeverity ASec);
extern PACKAGE System::UnicodeString __fastcall FacilityToString(TIdSyslogFacility AFac);

}	/* namespace Idsyslogmessage */
using namespace Idsyslogmessage;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsyslogmessageHPP
