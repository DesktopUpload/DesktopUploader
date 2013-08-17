// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idscheduler.pas' rev: 20.00

#ifndef IdschedulerHPP
#define IdschedulerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idthreadsafe.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idscheduler
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdScheduler;
class PASCALIMPLEMENTATION TIdScheduler : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Idthreadsafe::TIdThreadSafeList* FActiveYarns;
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdScheduler(void);
	virtual Idyarn::TIdYarn* __fastcall AcquireYarn(void) = 0 ;
	virtual void __fastcall Init(void);
	virtual void __fastcall ReleaseYarn(Idyarn::TIdYarn* AYarn);
	virtual void __fastcall StartYarn(Idyarn::TIdYarn* AYarn, Idtask::TIdTask* ATask) = 0 ;
	virtual void __fastcall TerminateYarn(Idyarn::TIdYarn* AYarn) = 0 ;
	virtual void __fastcall TerminateAllYarns(void);
	__property Idthreadsafe::TIdThreadSafeList* ActiveYarns = {read=FActiveYarns};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdScheduler(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idscheduler */
using namespace Idscheduler;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdschedulerHPP
