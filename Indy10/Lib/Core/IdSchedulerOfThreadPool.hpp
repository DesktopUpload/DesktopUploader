// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idschedulerofthreadpool.pas' rev: 20.00

#ifndef IdschedulerofthreadpoolHPP
#define IdschedulerofthreadpoolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idschedulerofthread.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idthreadsafe.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idschedulerofthreadpool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSchedulerOfThreadPool;
class PASCALIMPLEMENTATION TIdSchedulerOfThreadPool : public Idschedulerofthread::TIdSchedulerOfThread
{
	typedef Idschedulerofthread::TIdSchedulerOfThread inherited;
	
protected:
	int FPoolSize;
	Idthreadsafe::TIdThreadSafeList* FThreadPool;
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdSchedulerOfThreadPool(void);
	virtual Idyarn::TIdYarn* __fastcall AcquireYarn(void);
	virtual void __fastcall Init(void);
	virtual Idthread::TIdThreadWithTask* __fastcall NewThread(void);
	virtual void __fastcall ReleaseYarn(Idyarn::TIdYarn* AYarn);
	virtual void __fastcall TerminateAllYarns(void);
	
__published:
	__property int PoolSize = {read=FPoolSize, write=FPoolSize, default=0};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSchedulerOfThreadPool(Classes::TComponent* AOwner)/* overload */ : Idschedulerofthread::TIdSchedulerOfThread(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idschedulerofthreadpool */
using namespace Idschedulerofthreadpool;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdschedulerofthreadpoolHPP
