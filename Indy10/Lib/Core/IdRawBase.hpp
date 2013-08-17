// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrawbase.pas' rev: 20.00

#ifndef IdrawbaseHPP
#define IdrawbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idwship6.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrawbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdRawBase;
class PASCALIMPLEMENTATION TIdRawBase : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	System::UnicodeString FHost;
	System::Word FPort;
	int FReceiveTimeout;
	int FProtocol;
	int FProtocolIPv6;
	int FTTL;
	Idstack::TIdPacketInfo* FPkt;
	bool FConnected;
	Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	Idglobal::TIdIPVersion __fastcall GetIPVersion(void);
	virtual void __fastcall InitComponent(void);
	void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	void __fastcall SetTTL(const int Value);
	virtual void __fastcall SetHost(const System::UnicodeString AValue);
	__property Idglobal::TIdIPVersion IPVersion = {read=GetIPVersion, write=SetIPVersion, nodefault};
	__property System::Word Port = {read=FPort, write=FPort, default=0};
	__property int Protocol = {read=FProtocol, write=FProtocol, default=255};
	__property int ProtocolIPv6 = {read=FProtocolIPv6, write=FProtocolIPv6, nodefault};
	__property int TTL = {read=FTTL, write=SetTTL, default=128};
	
public:
	__fastcall virtual ~TIdRawBase(void);
	int __fastcall ReceiveBuffer(Sysutils::TBytes &VBuffer, int ATimeOut = 0xffffffff);
	virtual void __fastcall Send(const System::UnicodeString AData)/* overload */;
	virtual void __fastcall Send(const Sysutils::TBytes AData)/* overload */;
	virtual void __fastcall Send(const System::UnicodeString AHost, const System::Word APort, const System::UnicodeString AData)/* overload */;
	virtual void __fastcall Send(const System::UnicodeString AHost, const System::Word APort, const Sysutils::TBytes ABuffer)/* overload */;
	__property Idsockethandle::TIdSocketHandle* Binding = {read=GetBinding};
	__property int ReceiveTimeout = {read=FReceiveTimeout, write=FReceiveTimeout, default=0};
	
__published:
	__property System::UnicodeString Host = {read=FHost, write=SetHost};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRawBase(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt Id_TIdRawBase_Port = 0x0;
static const Word Id_TIdRawBase_BufferSize = 0x2000;
static const ShortInt GReceiveTimeout = 0x0;
static const Byte GFTTL = 0x80;

}	/* namespace Idrawbase */
using namespace Idrawbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrawbaseHPP
