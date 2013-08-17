// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrsh.pas' rev: 20.00

#ifndef IdrshHPP
#define IdrshHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idremotecmdclient.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrsh
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdRSH;
class PASCALIMPLEMENTATION TIdRSH : public Idremotecmdclient::TIdRemoteCMDClient
{
	typedef Idremotecmdclient::TIdRemoteCMDClient inherited;
	
protected:
	System::UnicodeString FClientUserName;
	System::UnicodeString FHostUserName;
	virtual void __fastcall InitComponent(void);
	
public:
	virtual System::UnicodeString __fastcall Execute(System::UnicodeString ACommand);
	
__published:
	__property System::UnicodeString ClientUserName = {read=FClientUserName, write=FClientUserName};
	__property System::UnicodeString HostUserName = {read=FHostUserName, write=FHostUserName};
	__property Port = {default=514};
	__property bool UseReservedPorts = {read=FUseReservedPorts, write=FUseReservedPorts, default=1};
public:
	/* TIdRemoteCMDClient.Destroy */ inline __fastcall virtual ~TIdRSH(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdRSH(Classes::TComponent* AOwner)/* overload */ : Idremotecmdclient::TIdRemoteCMDClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idrsh */
using namespace Idrsh;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrshHPP
