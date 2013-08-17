// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idfingerserver.pas' rev: 20.00

#ifndef IdfingerserverHPP
#define IdfingerserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idfingerserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdFingerGetEvent)(Idcontext::TIdContext* AContext, const System::UnicodeString AUserName, System::UnicodeString &VResponse);

class DELPHICLASS TIdFingerServer;
class PASCALIMPLEMENTATION TIdFingerServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	TIdFingerGetEvent FOnCommandFinger;
	TIdFingerGetEvent FOnCommandVerboseFinger;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
__published:
	__property TIdFingerGetEvent OnCommandFinger = {read=FOnCommandFinger, write=FOnCommandFinger};
	__property TIdFingerGetEvent OnCommandVerboseFinger = {read=FOnCommandVerboseFinger, write=FOnCommandVerboseFinger};
	__property DefaultPort = {default=79};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdFingerServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdFingerServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idfingerserver */
using namespace Idfingerserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdfingerserverHPP
