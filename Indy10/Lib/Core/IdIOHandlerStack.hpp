// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idiohandlerstack.pas' rev: 20.00

#ifndef IdiohandlerstackHPP
#define IdiohandlerstackHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idiohandlerstack
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIOHandlerStack;
class PASCALIMPLEMENTATION TIdIOHandlerStack : public Idiohandlersocket::TIdIOHandlerSocket
{
	typedef Idiohandlersocket::TIdIOHandlerSocket inherited;
	
protected:
	virtual void __fastcall ConnectClient(void);
	virtual int __fastcall ReadDataFromSource(Sysutils::TBytes &VBuffer);
	virtual int __fastcall WriteDataToTarget(const Sysutils::TBytes ABuffer, const int AOffset, const int ALength);
	
public:
	virtual void __fastcall CheckForDisconnect(bool ARaiseExceptionIfDisconnected = true, bool AIgnoreBuffer = false);
	virtual bool __fastcall Connected(void);
	virtual bool __fastcall Readable(int AMSec = 0xffffffff);
	
__published:
	__property ReadTimeout = {default=-1};
public:
	/* TIdIOHandlerSocket.Destroy */ inline __fastcall virtual ~TIdIOHandlerStack(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIOHandlerStack(Classes::TComponent* AOwner)/* overload */ : Idiohandlersocket::TIdIOHandlerSocket(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idiohandlerstack */
using namespace Idiohandlerstack;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdiohandlerstackHPP
