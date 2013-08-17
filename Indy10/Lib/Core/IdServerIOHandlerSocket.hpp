// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idserveriohandlersocket.pas' rev: 20.00

#ifndef IdserveriohandlersocketHPP
#define IdserveriohandlersocketHPP

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
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idserveriohandlersocket
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass* TIdIOHandlerSocketClass;

class DELPHICLASS TIdServerIOHandlerSocket;
class PASCALIMPLEMENTATION TIdServerIOHandlerSocket : public Idserveriohandler::TIdServerIOHandler
{
	typedef Idserveriohandler::TIdServerIOHandler inherited;
	
protected:
	TIdIOHandlerSocketClass IOHandlerSocketClass;
	virtual void __fastcall InitComponent(void);
	
public:
	virtual Idiohandler::TIdIOHandler* __fastcall Accept(Idsockethandle::TIdSocketHandle* ASocket, Idthread::TIdThread* AListenerThread, Idyarn::TIdYarn* AYarn);
	virtual void __fastcall Init(void);
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdServerIOHandlerSocket(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerIOHandlerSocket(Classes::TComponent* AOwner)/* overload */ : Idserveriohandler::TIdServerIOHandler(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idserveriohandlersocket */
using namespace Idserveriohandlersocket;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdserveriohandlersocketHPP
