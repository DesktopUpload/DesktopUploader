// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idserverinterceptlogevent.pas' rev: 20.00

#ifndef IdserverinterceptlogeventHPP
#define IdserverinterceptlogeventHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idserverinterceptlogbase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idserverinterceptlogevent
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdServerInterceptLogEvent;
typedef void __fastcall (__closure *TIdOnLogString)(TIdServerInterceptLogEvent* ASender, const System::UnicodeString AText);

class PASCALIMPLEMENTATION TIdServerInterceptLogEvent : public Idserverinterceptlogbase::TIdServerInterceptLogBase
{
	typedef Idserverinterceptlogbase::TIdServerInterceptLogBase inherited;
	
protected:
	TIdOnLogString FOnLogString;
	
public:
	virtual void __fastcall DoLogWriteString(const System::UnicodeString AText);
	
__published:
	__property TIdOnLogString OnLogString = {read=FOnLogString, write=FOnLogString};
public:
	/* TIdServerInterceptLogBase.Destroy */ inline __fastcall virtual ~TIdServerInterceptLogEvent(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerInterceptLogEvent(Classes::TComponent* AOwner)/* overload */ : Idserverinterceptlogbase::TIdServerInterceptLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idserverinterceptlogevent */
using namespace Idserverinterceptlogevent;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdserverinterceptlogeventHPP
