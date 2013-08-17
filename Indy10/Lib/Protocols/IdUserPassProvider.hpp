// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iduserpassprovider.pas' rev: 20.00

#ifndef IduserpassproviderHPP
#define IduserpassproviderHPP

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

namespace Iduserpassprovider
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdUserPassProvider;
class PASCALIMPLEMENTATION TIdUserPassProvider : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	System::UnicodeString FUsername;
	System::UnicodeString FPassword;
	
__published:
	__property System::UnicodeString Username = {read=FUsername, write=FUsername};
	__property System::UnicodeString Password = {read=FPassword, write=FPassword};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdUserPassProvider(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdUserPassProvider(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iduserpassprovider */
using namespace Iduserpassprovider;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IduserpassproviderHPP
