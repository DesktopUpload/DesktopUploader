// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idlogevent.pas' rev: 20.00

#ifndef IdlogeventHPP
#define IdlogeventHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idlogbase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogevent
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TLogItemStatusEvent)(Classes::TComponent* ASender, const System::UnicodeString AText);

typedef void __fastcall (__closure *TLogItemDataEvent)(Classes::TComponent* ASender, const System::UnicodeString AText, const System::UnicodeString AData);

class DELPHICLASS TIdLogEvent;
class PASCALIMPLEMENTATION TIdLogEvent : public Idlogbase::TIdLogBase
{
	typedef Idlogbase::TIdLogBase inherited;
	
protected:
	TLogItemDataEvent FOnReceived;
	TLogItemDataEvent FOnSent;
	TLogItemStatusEvent FOnStatus;
	virtual void __fastcall LogStatus(const System::UnicodeString AText);
	virtual void __fastcall LogReceivedData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogSentData(const System::UnicodeString AText, const System::UnicodeString AData);
	
__published:
	__property TLogItemDataEvent OnReceived = {read=FOnReceived, write=FOnReceived};
	__property TLogItemDataEvent OnSent = {read=FOnSent, write=FOnSent};
	__property TLogItemStatusEvent OnStatus = {read=FOnStatus, write=FOnStatus};
public:
	/* TIdLogBase.Destroy */ inline __fastcall virtual ~TIdLogEvent(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdLogEvent(Classes::TComponent* AOwner)/* overload */ : Idlogbase::TIdLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idlogevent */
using namespace Idlogevent;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdlogeventHPP
