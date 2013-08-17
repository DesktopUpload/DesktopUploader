// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcomponent.pas' rev: 20.00

#ifndef IdcomponentHPP
#define IdcomponentHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idantifreezebase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idresourcestrings.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcomponent
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdStatus { hsResolving, hsConnecting, hsConnected, hsDisconnecting, hsDisconnected, hsStatusText, ftpTransfer, ftpReady, ftpAborted };
#pragma option pop

typedef StaticArray<System::UnicodeString, 9> Idcomponent__1;

typedef void __fastcall (__closure *TIdStatusEvent)(System::TObject* ASender, const TIdStatus AStatus, const System::UnicodeString AStatusText);

#pragma option push -b-
enum TWorkMode { wmRead, wmWrite };
#pragma option pop

struct TWorkInfo
{
	
public:
	__int64 Current;
	__int64 Max;
	int Level;
};


typedef void __fastcall (__closure *TWorkBeginEvent)(System::TObject* ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);

typedef void __fastcall (__closure *TWorkEndEvent)(System::TObject* ASender, TWorkMode AWorkMode);

typedef void __fastcall (__closure *TWorkEvent)(System::TObject* ASender, TWorkMode AWorkMode, __int64 AWorkCount);

class DELPHICLASS TIdComponent;
class PASCALIMPLEMENTATION TIdComponent : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TIdStatusEvent FOnStatus;
	TWorkEvent FOnWork;
	TWorkBeginEvent FOnWorkBegin;
	TWorkEndEvent FOnWorkEnd;
	StaticArray<TWorkInfo, 2> FWorkInfos;
	TIdComponent* FWorkTarget;
	void __fastcall DoStatus(TIdStatus AStatus)/* overload */;
	void __fastcall DoStatus(TIdStatus AStatus, System::TVarRec const *AArgs, const int AArgs_Size)/* overload */;
	virtual void __fastcall InitComponent(void);
	__property TWorkEvent OnWork = {read=FOnWork, write=FOnWork};
	__property TWorkBeginEvent OnWorkBegin = {read=FOnWorkBegin, write=FOnWorkBegin};
	__property TWorkEndEvent OnWorkEnd = {read=FOnWorkEnd, write=FOnWorkEnd};
	
public:
	virtual void __fastcall BeginWork(TWorkMode AWorkMode, const __int64 ASize = 0x000000000);
	__fastcall virtual ~TIdComponent(void);
	virtual void __fastcall DoWork(TWorkMode AWorkMode, const __int64 ACount);
	virtual void __fastcall EndWork(TWorkMode AWorkMode);
	__property TIdComponent* WorkTarget = {read=FWorkTarget, write=FWorkTarget};
	
__published:
	__property TIdStatusEvent OnStatus = {read=FOnStatus, write=FOnStatus};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdComponent(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Idcomponent__1 IdStati;

}	/* namespace Idcomponent */
using namespace Idcomponent;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcomponentHPP
