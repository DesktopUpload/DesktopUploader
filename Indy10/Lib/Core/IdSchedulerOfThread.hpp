// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idschedulerofthread.pas' rev: 20.00

#ifndef IdschedulerofthreadHPP
#define IdschedulerofthreadHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idschedulerofthread
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdYarnOfThread;
class PASCALIMPLEMENTATION TIdYarnOfThread : public Idyarn::TIdYarn
{
	typedef Idyarn::TIdYarn inherited;
	
protected:
	Idscheduler::TIdScheduler* FScheduler;
	Idthread::TIdThreadWithTask* FThread;
	
public:
	__fastcall TIdYarnOfThread(Idscheduler::TIdScheduler* AScheduler, Idthread::TIdThreadWithTask* AThread);
	__fastcall virtual ~TIdYarnOfThread(void);
	__property Idthread::TIdThreadWithTask* Thread = {read=FThread};
};


class DELPHICLASS TIdSchedulerOfThread;
class PASCALIMPLEMENTATION TIdSchedulerOfThread : public Idscheduler::TIdScheduler
{
	typedef Idscheduler::TIdScheduler inherited;
	
protected:
	int FMaxThreads;
	Classes::TThreadPriority FThreadPriority;
	Idthread::TIdThreadWithTaskClass FThreadClass;
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdSchedulerOfThread(void);
	virtual Idthread::TIdThreadWithTask* __fastcall NewThread(void);
	TIdYarnOfThread* __fastcall NewYarn(Idthread::TIdThreadWithTask* AThread = (Idthread::TIdThreadWithTask*)(0x0));
	virtual void __fastcall StartYarn(Idyarn::TIdYarn* AYarn, Idtask::TIdTask* ATask);
	virtual void __fastcall TerminateYarn(Idyarn::TIdYarn* AYarn);
	__property Idthread::TIdThreadWithTaskClass ThreadClass = {read=FThreadClass, write=FThreadClass};
	
__published:
	__property int MaxThreads = {read=FMaxThreads, write=FMaxThreads, nodefault};
	__property Classes::TThreadPriority ThreadPriority = {read=FThreadPriority, write=FThreadPriority, default=3};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSchedulerOfThread(Classes::TComponent* AOwner)/* overload */ : Idscheduler::TIdScheduler(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idschedulerofthread */
using namespace Idschedulerofthread;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdschedulerofthreadHPP
