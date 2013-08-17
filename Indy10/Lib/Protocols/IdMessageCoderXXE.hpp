// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecoderxxe.pas' rev: 20.00

#ifndef IdmessagecoderxxeHPP
#define IdmessagecoderxxeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idmessagecoderuue.hpp>	// Pascal unit
#include <Idmessagecoder.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagecoderxxe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMessageEncoderXXE;
class PASCALIMPLEMENTATION TIdMessageEncoderXXE : public Idmessagecoderuue::TIdMessageEncoderUUEBase
{
	typedef Idmessagecoderuue::TIdMessageEncoderUUEBase inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoderXXE(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoderXXE(Classes::TComponent* AOwner)/* overload */ : Idmessagecoderuue::TIdMessageEncoderUUEBase(AOwner) { }
	
};


class DELPHICLASS TIdMessageEncoderInfoXXE;
class PASCALIMPLEMENTATION TIdMessageEncoderInfoXXE : public Idmessagecoder::TIdMessageEncoderInfo
{
	typedef Idmessagecoder::TIdMessageEncoderInfo inherited;
	
public:
	__fastcall virtual TIdMessageEncoderInfoXXE(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageEncoderInfoXXE(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessagecoderxxe */
using namespace Idmessagecoderxxe;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagecoderxxeHPP
