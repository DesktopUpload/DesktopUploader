// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsystatserver.pas' rev: 20.00

#ifndef IdsystatserverHPP
#define IdsystatserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsystatserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdSystatEvent)(Idcontext::TIdContext* AThread, Classes::TStrings* AResults);

class DELPHICLASS TIdSystatServer;
class PASCALIMPLEMENTATION TIdSystatServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	TIdSystatEvent FOnSystat;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AThread);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TIdSystatEvent OnSystat = {read=FOnSystat, write=FOnSystat};
	__property DefaultPort = {default=11};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdSystatServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSystatServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsystatserver */
using namespace Idsystatserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsystatserverHPP
