// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsockethandle.pas' rev: 20.00

#ifndef IdsockethandleHPP
#define IdsockethandleHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsockethandle
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSocketHandles;
class DELPHICLASS TIdSocketHandle;
class PASCALIMPLEMENTATION TIdSocketHandles : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdSocketHandle* operator[](int Index) { return Items[Index]; }
	
protected:
	System::Word FDefaultPort;
	HIDESBASE TIdSocketHandle* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdSocketHandle* Value);
	
public:
	__fastcall TIdSocketHandles(Classes::TComponent* AOwner);
	HIDESBASE TIdSocketHandle* __fastcall Add(void);
	TIdSocketHandle* __fastcall BindingByHandle(const unsigned AHandle);
	__property TIdSocketHandle* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property System::Word DefaultPort = {read=FDefaultPort, write=FDefaultPort, nodefault};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdSocketHandles(void) { }
	
};


class PASCALIMPLEMENTATION TIdSocketHandle : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::Word FClientPortMin;
	System::Word FClientPortMax;
	unsigned FHandle;
	bool FHandleAllocated;
	System::UnicodeString FIP;
	System::UnicodeString FPeerIP;
	System::Word FPort;
	System::Word FPeerPort;
	Idstack::TIdSocketList* FReadSocketList;
	bool FOverLapped;
	Idglobal::TIdIPVersion FIPVersion;
	Idglobal::TIdCriticalSection* FConnectionHandle;
	bool FBroadcastEnabled;
	bool __fastcall BindPortReserved(void);
	void __fastcall BroadcastEnabledChanged(void);
	void __fastcall SetBroadcastEnabled(const bool AValue);
	void __fastcall SetBroadcastFlag(const bool AEnabled);
	void __fastcall SetOverLapped(const bool AValue);
	void __fastcall SetHandle(unsigned AHandle);
	void __fastcall SetIPVersion(const Idglobal::TIdIPVersion Value);
	bool __fastcall TryBind(void);
	
public:
	bool __fastcall Accept(unsigned ASocket);
	void __fastcall AllocateSocket(const unsigned ASocketType = (unsigned)(0x1), const int AProtocol = 0x0);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Bind(void);
	void __fastcall Broadcast(const System::UnicodeString AData, const System::Word APort, const System::UnicodeString AIP = L"")/* overload */;
	void __fastcall Broadcast(const Sysutils::TBytes AData, const System::Word APort, const System::UnicodeString AIP = L"")/* overload */;
	virtual void __fastcall CloseSocket(void);
	virtual void __fastcall Connect(void);
	__fastcall virtual TIdSocketHandle(Classes::TCollection* ACollection);
	__fastcall virtual ~TIdSocketHandle(void);
	void __fastcall Listen(const int AQueueCount = 0x5);
	bool __fastcall Readable(int AMSec = 0xffffffff);
	int __fastcall Receive(Sysutils::TBytes &VBuffer);
	int __fastcall RecvFrom(Sysutils::TBytes &ABuffer, System::UnicodeString &VIP, System::Word &VPort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	void __fastcall Reset(const bool AResetLocal = true);
	int __fastcall Send(const Sysutils::TBytes ABuffer, const int AOffset = 0x0, const int ASize = 0xffffffff);
	void __fastcall SendTo(const System::UnicodeString AIP, const System::Word APort, const Sysutils::TBytes ABuffer, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0))/* overload */;
	void __fastcall SendTo(const System::UnicodeString AIP, const System::Word APort, const Sysutils::TBytes ABuffer, const int AOffset, const int ASize, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0))/* overload */;
	void __fastcall SetPeer(const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	void __fastcall SetBinding(const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	void __fastcall GetSockOpt(int ALevel, int AOptName, /* out */ int &VOptVal);
	void __fastcall SetSockOpt(int ALevel, int AOptName, int AOptVal);
	bool __fastcall Select(int ATimeout = 0xfffffffe);
	void __fastcall UpdateBindingLocal(void);
	void __fastcall UpdateBindingPeer(void);
	__property bool HandleAllocated = {read=FHandleAllocated, nodefault};
	__property unsigned Handle = {read=FHandle, nodefault};
	__property bool OverLapped = {read=FOverLapped, write=SetOverLapped, nodefault};
	__property System::UnicodeString PeerIP = {read=FPeerIP};
	__property System::Word PeerPort = {read=FPeerPort, nodefault};
	
__published:
	__property bool BroadcastEnabled = {read=FBroadcastEnabled, write=SetBroadcastEnabled, default=0};
	__property System::Word ClientPortMin = {read=FClientPortMin, write=FClientPortMin, default=0};
	__property System::Word ClientPortMax = {read=FClientPortMax, write=FClientPortMax, default=0};
	__property System::UnicodeString IP = {read=FIP, write=FIP};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=SetIPVersion, default=0};
	__property System::Word Port = {read=FPort, write=FPort, nodefault};
};


typedef void __fastcall (__closure *TIdSocketHandleEvent)(TIdSocketHandle* AHandle);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsockethandle */
using namespace Idsockethandle;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsockethandleHPP
