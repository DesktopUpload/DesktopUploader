// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsync.pas' rev: 20.00

#ifndef IdsyncHPP
#define IdsyncHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsync
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSync;
class PASCALIMPLEMENTATION TIdSync : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Idthread::TIdThread* FThread;
	virtual void __fastcall DoSynchronize(void) = 0 ;
	
public:
	__fastcall virtual TIdSync(void)/* overload */;
	__fastcall virtual TIdSync(Idthread::TIdThread* AThread)/* overload */;
	void __fastcall Synchronize(void);
	__classmethod void __fastcall SynchronizeMethod(Classes::TThreadMethod AMethod);
	__property Idthread::TIdThread* Thread = {read=FThread};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdSync(void) { }
	
};


class DELPHICLASS TIdNotify;
class PASCALIMPLEMENTATION TIdNotify : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FMainThreadUsesNotify;
	virtual void __fastcall DoNotify(void) = 0 ;
	
public:
	__fastcall virtual TIdNotify(void);
	void __fastcall Notify(void);
	__classmethod void __fastcall FreeThread();
	void __fastcall WaitFor(void);
	__classmethod void __fastcall NotifyMethod(Classes::TThreadMethod AMethod);
	__property bool MainThreadUsesNotify = {read=FMainThreadUsesNotify, write=FMainThreadUsesNotify, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdNotify(void) { }
	
};


class DELPHICLASS TIdNotifyMethod;
class PASCALIMPLEMENTATION TIdNotifyMethod : public TIdNotify
{
	typedef TIdNotify inherited;
	
protected:
	Classes::TThreadMethod FMethod;
	virtual void __fastcall DoNotify(void);
	
public:
	__fastcall virtual TIdNotifyMethod(Classes::TThreadMethod AMethod);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdNotifyMethod(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsync */
using namespace Idsync;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsyncHPP
