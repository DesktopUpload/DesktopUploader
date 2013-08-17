// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idserveriohandler.pas' rev: 20.00

#ifndef IdserveriohandlerHPP
#define IdserveriohandlerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idserveriohandler
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdServerIOHandler;
class PASCALIMPLEMENTATION TIdServerIOHandler : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	Idscheduler::TIdScheduler* FScheduler;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual Idiohandler::TIdIOHandler* __fastcall Accept(Idsockethandle::TIdSocketHandle* ASocket, Idthread::TIdThread* AListenerThread, Idyarn::TIdYarn* AYarn);
	virtual Idiohandler::TIdIOHandler* __fastcall MakeClientIOHandler(Idyarn::TIdYarn* AYarn);
	virtual void __fastcall Init(void);
	virtual void __fastcall Shutdown(void);
	virtual void __fastcall SetScheduler(Idscheduler::TIdScheduler* AScheduler);
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdServerIOHandler(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerIOHandler(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idserveriohandler */
using namespace Idserveriohandler;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdserveriohandlerHPP
