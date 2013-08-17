// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrexec.pas' rev: 20.00

#ifndef IdrexecHPP
#define IdrexecHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idremotecmdclient.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrexec
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdRexec;
class PASCALIMPLEMENTATION TIdRexec : public Idremotecmdclient::TIdRemoteCMDClient
{
	typedef Idremotecmdclient::TIdRemoteCMDClient inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	virtual System::UnicodeString __fastcall Execute(System::UnicodeString ACommand);
	
__published:
	__property Username;
	__property Password;
	__property Port = {default=512};
	__property Host;
public:
	/* TIdRemoteCMDClient.Destroy */ inline __fastcall virtual ~TIdRexec(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRexec(Classes::TComponent* AOwner)/* overload */ : Idremotecmdclient::TIdRemoteCMDClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idrexec */
using namespace Idrexec;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrexecHPP
