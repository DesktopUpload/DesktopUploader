// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idipaddrmon.pas' rev: 20.00

#ifndef IdipaddrmonHPP
#define IdipaddrmonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idipaddrmon
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdIPAddrMonEvent)(System::TObject* ASender, int AAdapter, System::UnicodeString AOldIP, System::UnicodeString ANewIP);

class DELPHICLASS TIdIPAddrMonThread;
class PASCALIMPLEMENTATION TIdIPAddrMonThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	System::TObject* FOwner;
	unsigned FInterval;
	Classes::TNotifyEvent FOnTimerEvent;
	virtual void __fastcall Run(void);
	void __fastcall DoTimerEvent(void);
public:
	/* TIdThread.Create */ inline __fastcall virtual TIdIPAddrMonThread(bool ACreateSuspended, bool ALoop, const System::UnicodeString AName) : Idthread::TIdThread(ACreateSuspended, ALoop, AName) { }
	/* TIdThread.Destroy */ inline __fastcall virtual ~TIdIPAddrMonThread(void) { }
	
};


class DELPHICLASS TIdIPAddrMon;
class PASCALIMPLEMENTATION TIdIPAddrMon : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
private:
	bool FActive;
	bool FBusy;
	unsigned FInterval;
	int FAdapterCount;
	TIdIPAddrMonThread* FThread;
	Classes::TStrings* FIPAddresses;
	Classes::TStrings* FPreviousIPAddresses;
	TIdIPAddrMonEvent FOnStatusChanged;
	void __fastcall SetActive(bool Value);
	void __fastcall SetInterval(unsigned Value);
	void __fastcall GetAdapterAddresses(void);
	void __fastcall DoStatusChanged(void);
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdIPAddrMon(void);
	void __fastcall CheckAdapters(System::TObject* Sender);
	void __fastcall ForceCheck(void);
	
__published:
	__property TIdIPAddrMonThread* Thread = {read=FThread};
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property bool Busy = {read=FBusy, write=FBusy, nodefault};
	__property unsigned Interval = {read=FInterval, write=SetInterval, default=500};
	__property int AdapterCount = {read=FAdapterCount, write=FAdapterCount, nodefault};
	__property Classes::TStrings* IPAddresses = {read=FIPAddresses};
	__property TIdIPAddrMonEvent OnStatusChanged = {read=FOnStatusChanged, write=FOnStatusChanged};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIPAddrMon(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word IdIPAddrMonInterval = 0x1f4;

}	/* namespace Idipaddrmon */
using namespace Idipaddrmon;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdipaddrmonHPP
