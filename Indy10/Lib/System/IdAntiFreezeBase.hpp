// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idantifreezebase.pas' rev: 20.00

#ifndef IdantifreezebaseHPP
#define IdantifreezebaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idantifreezebase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAntiFreezeBase;
class PASCALIMPLEMENTATION TIdAntiFreezeBase : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	bool FActive;
	bool FApplicationHasPriority;
	int FIdleTimeOut;
	bool FOnlyWhenIdle;
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdAntiFreezeBase(void);
	virtual void __fastcall Process(void) = 0 ;
	__classmethod void __fastcall DoProcess(const bool AIdle = true, const bool AOverride = false);
	__classmethod bool __fastcall ShouldUse();
	__classmethod void __fastcall Sleep(int ATimeout);
	
__published:
	__property bool Active = {read=FActive, write=FActive, default=1};
	__property bool ApplicationHasPriority = {read=FApplicationHasPriority, write=FApplicationHasPriority, default=1};
	__property int IdleTimeOut = {read=FIdleTimeOut, write=FIdleTimeOut, default=250};
	__property bool OnlyWhenIdle = {read=FOnlyWhenIdle, write=FOnlyWhenIdle, default=1};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdAntiFreezeBase(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool ID_Default_TIdAntiFreezeBase_Active = true;
static const bool ID_Default_TIdAntiFreezeBase_ApplicationHasPriority = true;
static const Byte ID_Default_TIdAntiFreezeBase_IdleTimeOut = 0xfa;
static const bool ID_Default_TIdAntiFreezeBase_OnlyWhenIdle = true;
extern PACKAGE TIdAntiFreezeBase* GAntiFreeze;

}	/* namespace Idantifreezebase */
using namespace Idantifreezebase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdantifreezebaseHPP
