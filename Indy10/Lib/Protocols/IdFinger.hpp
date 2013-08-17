// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idfinger.pas' rev: 20.00

#ifndef IdfingerHPP
#define IdfingerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idfinger
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdFinger;
class PASCALIMPLEMENTATION TIdFinger : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	System::UnicodeString FQuery;
	bool FVerboseOutput;
	void __fastcall SetCompleteQuery(System::UnicodeString AQuery);
	System::UnicodeString __fastcall GetCompleteQuery();
	virtual void __fastcall InitComponent(void);
	
public:
	System::UnicodeString __fastcall Finger();
	
__published:
	__property Port = {default=79};
	__property Host;
	__property System::UnicodeString Query = {read=FQuery, write=FQuery};
	__property System::UnicodeString CompleteQuery = {read=GetCompleteQuery, write=SetCompleteQuery};
	__property bool VerboseOutput = {read=FVerboseOutput, write=FVerboseOutput, default=0};
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdFinger(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdFinger(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idfinger */
using namespace Idfinger;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdfingerHPP
