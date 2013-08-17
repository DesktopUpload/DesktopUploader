// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idserveriohandlerstack.pas' rev: 20.00

#ifndef IdserveriohandlerstackHPP
#define IdserveriohandlerstackHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idserveriohandler.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idscheduler.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idserveriohandlersocket.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idserveriohandlerstack
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdServerIOHandlerStack;
class PASCALIMPLEMENTATION TIdServerIOHandlerStack : public Idserveriohandlersocket::TIdServerIOHandlerSocket
{
	typedef Idserveriohandlersocket::TIdServerIOHandlerSocket inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	virtual Idiohandler::TIdIOHandler* __fastcall MakeClientIOHandler(Idyarn::TIdYarn* ATheThread);
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdServerIOHandlerStack(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerIOHandlerStack(Classes::TComponent* AOwner)/* overload */ : Idserveriohandlersocket::TIdServerIOHandlerSocket(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idserveriohandlerstack */
using namespace Idserveriohandlerstack;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdserveriohandlerstackHPP
