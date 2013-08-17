// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idlogdebug.pas' rev: 20.00

#ifndef IdlogdebugHPP
#define IdlogdebugHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idlogbase.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogdebug
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdLogDebug;
class PASCALIMPLEMENTATION TIdLogDebug : public Idlogbase::TIdLogBase
{
	typedef Idlogbase::TIdLogBase inherited;
	
protected:
	virtual void __fastcall LogStatus(const System::UnicodeString AText);
	virtual void __fastcall LogReceivedData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogSentData(const System::UnicodeString AText, const System::UnicodeString AData);
public:
	/* TIdLogBase.Destroy */ inline __fastcall virtual ~TIdLogDebug(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdLogDebug(Classes::TComponent* AOwner)/* overload */ : Idlogbase::TIdLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idlogdebug */
using namespace Idlogdebug;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdlogdebugHPP
