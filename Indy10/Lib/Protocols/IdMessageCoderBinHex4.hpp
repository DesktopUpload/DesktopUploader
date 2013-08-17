// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecoderbinhex4.pas' rev: 20.00

#ifndef Idmessagecoderbinhex4HPP
#define Idmessagecoderbinhex4HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idmessagecoder.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagecoderbinhex4
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMessageEncoderBinHex4;
class PASCALIMPLEMENTATION TIdMessageEncoderBinHex4 : public Idmessagecoder::TIdMessageEncoder
{
	typedef Idmessagecoder::TIdMessageEncoder inherited;
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrc, Classes::TStream* ADest)/* overload */;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoderBinHex4(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoderBinHex4(Classes::TComponent* AOwner)/* overload */ : Idmessagecoder::TIdMessageEncoder(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Encode(const System::UnicodeString AFilename, Classes::TStream* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(AFilename, ADest); }
	inline void __fastcall  Encode(Classes::TStream* ASrc, Classes::TStrings* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(ASrc, ADest); }
	
};


class DELPHICLASS TIdMessageEncoderInfoBinHex4;
class PASCALIMPLEMENTATION TIdMessageEncoderInfoBinHex4 : public Idmessagecoder::TIdMessageEncoderInfo
{
	typedef Idmessagecoder::TIdMessageEncoderInfo inherited;
	
public:
	__fastcall virtual TIdMessageEncoderInfoBinHex4(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageEncoderInfoBinHex4(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessagecoderbinhex4 */
using namespace Idmessagecoderbinhex4;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idmessagecoderbinhex4HPP
