// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idconnectthroughhttpproxy.pas' rev: 20.00

#ifndef IdconnectthroughhttpproxyHPP
#define IdconnectthroughhttpproxyHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcustomtransparentproxy.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idconnectthroughhttpproxy
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdConnectThroughHttpProxy;
class PASCALIMPLEMENTATION TIdConnectThroughHttpProxy : public Idcustomtransparentproxy::TIdCustomTransparentProxy
{
	typedef Idcustomtransparentproxy::TIdCustomTransparentProxy inherited;
	
protected:
	bool FEnabled;
	virtual bool __fastcall GetEnabled(void);
	virtual void __fastcall SetEnabled(bool AValue);
	virtual void __fastcall MakeConnection(Idiohandler::TIdIOHandler* AIOHandler, const System::UnicodeString AHost, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	virtual void __fastcall DoMakeConnection(Idiohandler::TIdIOHandler* AIOHandler, const System::UnicodeString AHost, const System::Word APort, const bool ALogin, const Idglobal::TIdIPVersion AIPVersion = (Idglobal::TIdIPVersion)(0x0));
	
__published:
	__property Enabled;
	__property Host;
	__property Port;
	__property ChainedProxy;
	__property Username;
	__property Password;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdConnectThroughHttpProxy(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdConnectThroughHttpProxy(Classes::TComponent* AOwner)/* overload */ : Idcustomtransparentproxy::TIdCustomTransparentProxy(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idconnectthroughhttpproxy */
using namespace Idconnectthroughhttpproxy;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdconnectthroughhttpproxyHPP
