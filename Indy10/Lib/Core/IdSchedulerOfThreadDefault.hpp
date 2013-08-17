// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idschedulerofthreaddefault.pas' rev: 20.00

#ifndef IdschedulerofthreaddefaultHPP
#define IdschedulerofthreaddefaultHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idschedulerofthread.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idschedulerofthreaddefault
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSchedulerOfThreadDefault;
class PASCALIMPLEMENTATION TIdSchedulerOfThreadDefault : public Idschedulerofthread::TIdSchedulerOfThread
{
	typedef Idschedulerofthread::TIdSchedulerOfThread inherited;
	
public:
	virtual Idyarn::TIdYarn* __fastcall AcquireYarn(void);
	virtual Idthread::TIdThreadWithTask* __fastcall NewThread(void);
public:
	/* TIdSchedulerOfThread.Destroy */ inline __fastcall virtual ~TIdSchedulerOfThreadDefault(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSchedulerOfThreadDefault(Classes::TComponent* AOwner)/* overload */ : Idschedulerofthread::TIdSchedulerOfThread(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idschedulerofthreaddefault */
using namespace Idschedulerofthreaddefault;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdschedulerofthreaddefaultHPP
