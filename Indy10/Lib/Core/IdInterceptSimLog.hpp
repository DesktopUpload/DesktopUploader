// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idinterceptsimlog.pas' rev: 20.00

#ifndef IdinterceptsimlogHPP
#define IdinterceptsimlogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idinterceptsimlog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdInterceptSimLog;
class PASCALIMPLEMENTATION TIdInterceptSimLog : public Idintercept::TIdConnectionIntercept
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
protected:
	System::UnicodeString FFilename;
	Classes::TStream* FStream;
	void __fastcall SetFilename(const System::UnicodeString AValue);
	void __fastcall WriteRecord(const System::UnicodeString ATag, const Sysutils::TBytes ABuffer);
	
public:
	virtual void __fastcall Connect(Classes::TComponent* AConnection);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall Receive(Sysutils::TBytes &ABuffer);
	virtual void __fastcall Send(Sysutils::TBytes &ABuffer);
	
__published:
	__property System::UnicodeString Filename = {read=FFilename, write=SetFilename};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdInterceptSimLog(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdConnectionIntercept(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdInterceptSimLog(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idinterceptsimlog */
using namespace Idinterceptsimlog;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdinterceptsimlogHPP
