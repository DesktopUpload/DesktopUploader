// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsnmp.pas' rev: 20.00

#ifndef IdsnmpHPP
#define IdsnmpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idasn1util.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsnmp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSNMPInfo;
class DELPHICLASS TIdSNMP;
class PASCALIMPLEMENTATION TSNMPInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TIdSNMP* fOwner;
	System::UnicodeString fCommunity;
	System::UnicodeString __fastcall GetValue(int idx);
	int __fastcall GetValueCount(void);
	unsigned __fastcall GetValueType(int idx);
	System::UnicodeString __fastcall GetValueOID(int idx);
	void __fastcall SetCommunity(const System::UnicodeString Value);
	
protected:
	System::UnicodeString Buffer;
	void __fastcall SyncMIB(void);
	
public:
	System::UnicodeString Host;
	System::Word Port;
	System::UnicodeString Enterprise;
	int GenTrap;
	int SpecTrap;
	int Version;
	int PDUType;
	int TimeTicks;
	int ID;
	int ErrorStatus;
	int ErrorIndex;
	Classes::TStrings* MIBOID;
	Classes::TStrings* MIBValue;
	__fastcall TSNMPInfo(TIdSNMP* AOwner);
	__fastcall virtual ~TSNMPInfo(void);
	int __fastcall EncodeTrap(void);
	int __fastcall DecodeTrap(void);
	void __fastcall DecodeBuf(System::UnicodeString Buffer);
	System::UnicodeString __fastcall EncodeBuf();
	void __fastcall Clear(void);
	void __fastcall MIBAdd(System::UnicodeString MIB, System::UnicodeString Value, int ValueType = 0x4);
	void __fastcall MIBDelete(int Index);
	System::UnicodeString __fastcall MIBGet(System::UnicodeString MIB);
	__property TIdSNMP* Owner = {read=fOwner};
	__property System::UnicodeString Community = {read=fCommunity, write=SetCommunity};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property System::UnicodeString Value[int idx] = {read=GetValue};
	__property System::UnicodeString ValueOID[int idx] = {read=GetValueOID};
	__property unsigned ValueType[int idx] = {read=GetValueType};
};


class PASCALIMPLEMENTATION TIdSNMP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	System::UnicodeString fCommunity;
	System::Word fTrapPort;
	void __fastcall SetCommunity(const System::UnicodeString Value);
	virtual void __fastcall InitComponent(void);
	
public:
	TSNMPInfo* Query;
	TSNMPInfo* Reply;
	TSNMPInfo* Trap;
	__fastcall virtual ~TIdSNMP(void);
	bool __fastcall SendQuery(void);
	bool __fastcall QuickSend(const System::UnicodeString Mib, const System::UnicodeString DestCommunity, const System::UnicodeString DestHost, System::UnicodeString &Value);
	int __fastcall QuickSendTrap(const System::UnicodeString DestHost, const System::UnicodeString Enterprise, const System::UnicodeString DestCommunity, System::Word DestPort, int Generic, int Specific, Classes::TStrings* MIBName, Classes::TStrings* MIBValue);
	int __fastcall QuickReceiveTrap(System::UnicodeString &SrcHost, System::UnicodeString &Enterprise, System::UnicodeString &SrcCommunity, System::Word &SrcPort, int &Generic, int &Specific, int &Seconds, Classes::TStrings* MIBName, Classes::TStrings* MIBValue);
	int __fastcall SendTrap(void);
	int __fastcall ReceiveTrap(void);
	
__published:
	__property Port = {default=161};
	__property System::Word TrapPort = {read=fTrapPort, write=fTrapPort, default=162};
	__property System::UnicodeString Community = {read=fCommunity, write=SetCommunity};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSNMP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Byte PDUGetRequest = 0xa0;
static const Byte PDUGetNextRequest = 0xa1;
static const Byte PDUGetResponse = 0xa2;
static const Byte PDUSetRequest = 0xa3;
static const Byte PDUTrap = 0xa4;
static const ShortInt ENoError = 0x0;
static const ShortInt ETooBig = 0x1;
static const ShortInt ENoSuchName = 0x2;
static const ShortInt EBadValue = 0x3;
static const ShortInt EReadOnly = 0x4;
static const ShortInt EGenErr = 0x5;

}	/* namespace Idsnmp */
using namespace Idsnmp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsnmpHPP
