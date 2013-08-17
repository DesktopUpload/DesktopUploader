// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhttpserver.pas' rev: 20.00

#ifndef IdhttpserverHPP
#define IdhttpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcustomhttpserver.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhttpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHTTPServer;
class PASCALIMPLEMENTATION TIdHTTPServer : public Idcustomhttpserver::TIdCustomHTTPServer
{
	typedef Idcustomhttpserver::TIdCustomHTTPServer inherited;
	
__published:
	__property OnCreatePostStream;
	__property OnCommandGet;
public:
	/* TIdCustomHTTPServer.Destroy */ inline __fastcall virtual ~TIdHTTPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdHTTPServer(Classes::TComponent* AOwner)/* overload */ : Idcustomhttpserver::TIdCustomHTTPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhttpserver */
using namespace Idhttpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdhttpserverHPP
