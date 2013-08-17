// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtraceroute.pas' rev: 20.00

#ifndef IdtracerouteHPP
#define IdtracerouteHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idicmpclient.hpp>	// Pascal unit
#include <Idrawbase.hpp>	// Pascal unit
#include <Idrawclient.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtraceroute
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTraceRoute;
class PASCALIMPLEMENTATION TIdTraceRoute : public Idicmpclient::TIdCustomIcmpClient
{
	typedef Idicmpclient::TIdCustomIcmpClient inherited;
	
protected:
	bool FResolveHostNames;
	virtual void __fastcall DoReply(void);
	
public:
	void __fastcall Trace(void);
	
__published:
	__property bool ResolveHostNames = {read=FResolveHostNames, write=FResolveHostNames, nodefault};
	__property Idicmpclient::TOnReplyEvent OnReply = {read=FOnReply, write=FOnReply};
public:
	/* TIdCustomIcmpClient.Destroy */ inline __fastcall virtual ~TIdTraceRoute(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTraceRoute(Classes::TComponent* AOwner)/* overload */ : Idicmpclient::TIdCustomIcmpClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtraceroute */
using namespace Idtraceroute;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtracerouteHPP
