// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idipmcastclient.pas' rev: 20.00

#ifndef IdipmcastclientHPP
#define IdipmcastclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idipmcastbase.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idipmcastclient
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIPMCastReadEvent)(System::TObject* Sender, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);

class DELPHICLASS TIdIPMCastListenerThread;
class DELPHICLASS TIdIPMCastClient;
class PASCALIMPLEMENTATION TIdIPMCastListenerThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* IncomingData;
	int FAcceptWait;
	Sysutils::TBytes FBuffer;
	int FBufferSize;
	virtual void __fastcall Run(void);
	
public:
	TIdIPMCastClient* FServer;
	__fastcall TIdIPMCastListenerThread(TIdIPMCastClient* AOwner);
	__fastcall virtual ~TIdIPMCastListenerThread(void);
	void __fastcall IPMCastRead(void);
	__property int AcceptWait = {read=FAcceptWait, write=FAcceptWait, nodefault};
};


class PASCALIMPLEMENTATION TIdIPMCastClient : public Idipmcastbase::TIdIPMCastBase
{
	typedef Idipmcastbase::TIdIPMCastBase inherited;
	
protected:
	Idsockethandle::TIdSocketHandles* FBindings;
	int FBufferSize;
	Idsockethandle::TIdSocketHandle* FCurrentBinding;
	TIdIPMCastListenerThread* FListenerThread;
	TIPMCastReadEvent FOnIPMCastRead;
	bool FThreadedEvent;
	virtual void __fastcall CloseBinding(void);
	virtual void __fastcall DoIPMCastRead(const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual bool __fastcall GetActive(void);
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void);
	int __fastcall GetDefaultPort(void);
	void __fastcall PacketReceived(const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	void __fastcall SetBindings(const Idsockethandle::TIdSocketHandles* Value);
	void __fastcall SetDefaultPort(const int AValue);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdIPMCastClient(void);
	
__published:
	__property IPVersion = {default=0};
	__property Active = {default=0};
	__property Idsockethandle::TIdSocketHandles* Bindings = {read=FBindings, write=SetBindings};
	__property int BufferSize = {read=FBufferSize, write=FBufferSize, default=8192};
	__property int DefaultPort = {read=GetDefaultPort, write=SetDefaultPort, nodefault};
	__property MulticastGroup;
	__property TIPMCastReadEvent OnIPMCastRead = {read=FOnIPMCastRead, write=FOnIPMCastRead};
	__property bool ThreadedEvent = {read=FThreadedEvent, write=FThreadedEvent, default=0};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIPMCastClient(Classes::TComponent* AOwner)/* overload */ : Idipmcastbase::TIdIPMCastBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool DEF_IMP_THREADEDEVENT = false;

}	/* namespace Idipmcastclient */
using namespace Idipmcastclient;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdipmcastclientHPP
