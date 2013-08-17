// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idbasecomponent.pas' rev: 20.00

#ifndef IdbasecomponentHPP
#define IdbasecomponentHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idbasecomponent
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdInitializerComponent;
class PASCALIMPLEMENTATION TIdInitializerComponent : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
protected:
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsDesignTime(void);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall TIdInitializerComponent(void)/* overload */;
	__fastcall virtual TIdInitializerComponent(Classes::TComponent* AOwner)/* overload */;
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdInitializerComponent(void) { }
	
};


class DELPHICLASS TIdBaseComponent;
class PASCALIMPLEMENTATION TIdBaseComponent : public TIdInitializerComponent
{
	typedef TIdInitializerComponent inherited;
	
protected:
	System::UnicodeString __fastcall GetIndyVersion();
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsDesignTime = {read=GetIsDesignTime, nodefault};
	
public:
	__fastcall TIdBaseComponent(Classes::TComponent* AOwner)/* overload */;
	__property System::UnicodeString Version = {read=GetIndyVersion};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdBaseComponent(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idbasecomponent */
using namespace Idbasecomponent;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdbasecomponentHPP
