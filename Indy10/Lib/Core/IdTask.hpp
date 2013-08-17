// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtask.pas' rev: 20.00

#ifndef IdtaskHPP
#define IdtaskHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtask
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTask;
class PASCALIMPLEMENTATION TIdTask : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FBeforeRunDone;
	System::TObject* FData;
	Idyarn::TIdYarn* FYarn;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall BeforeRun(void);
	virtual bool __fastcall Run(void) = 0 ;
	virtual void __fastcall HandleException(Sysutils::Exception* AException);
	
public:
	__fastcall virtual TIdTask(Idyarn::TIdYarn* AYarn);
	__fastcall virtual ~TIdTask(void);
	void __fastcall DoAfterRun(void);
	void __fastcall DoBeforeRun(void);
	bool __fastcall DoRun(void);
	void __fastcall DoException(Sysutils::Exception* AException);
	__property bool BeforeRunDone = {read=FBeforeRunDone, nodefault};
	__property System::TObject* Data = {read=FData, write=FData};
	__property Idyarn::TIdYarn* Yarn = {read=FYarn};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtask */
using namespace Idtask;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtaskHPP
