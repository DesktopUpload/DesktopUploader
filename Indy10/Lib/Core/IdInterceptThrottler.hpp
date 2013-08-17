// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idinterceptthrottler.pas' rev: 20.00

#ifndef IdinterceptthrottlerHPP
#define IdinterceptthrottlerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idinterceptthrottler
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdInterceptThrottler;
class PASCALIMPLEMENTATION TIdInterceptThrottler : public Idintercept::TIdConnectionIntercept
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
protected:
	int FBitsPerSec;
	int FRecvBitsPerSec;
	int FSendBitsPerSec;
	void __fastcall SetBitsPerSec(int AValue);
	
public:
	virtual void __fastcall Receive(Sysutils::TBytes &ABuffer);
	virtual void __fastcall Send(Sysutils::TBytes &ABuffer);
	
__published:
	__property int BitsPerSec = {read=FBitsPerSec, write=SetBitsPerSec, nodefault};
	__property int RecvBitsPerSec = {read=FRecvBitsPerSec, write=FRecvBitsPerSec, nodefault};
	__property int SendBitsPerSec = {read=FSendBitsPerSec, write=FSendBitsPerSec, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdInterceptThrottler(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdConnectionIntercept(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdInterceptThrottler(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idinterceptthrottler */
using namespace Idinterceptthrottler;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdinterceptthrottlerHPP
