// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idantifreeze.pas' rev: 20.00

#ifndef IdantifreezeHPP
#define IdantifreezeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idantifreezebase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "IdAntiFreeze.obj"

namespace Idantifreeze
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAntiFreeze;
class PASCALIMPLEMENTATION TIdAntiFreeze : public Idantifreezebase::TIdAntiFreezeBase
{
	typedef Idantifreezebase::TIdAntiFreezeBase inherited;
	
public:
	virtual void __fastcall Process(void);
public:
	/* TIdAntiFreezeBase.Destroy */ inline __fastcall virtual ~TIdAntiFreeze(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdAntiFreeze(Classes::TComponent* AOwner)/* overload */ : Idantifreezebase::TIdAntiFreezeBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idantifreeze */
using namespace Idantifreeze;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdantifreezeHPP
