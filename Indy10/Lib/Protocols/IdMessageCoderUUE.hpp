// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecoderuue.pas' rev: 20.00

#ifndef IdmessagecoderuueHPP
#define IdmessagecoderuueHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcoder3to4.hpp>	// Pascal unit
#include <Idmessagecoder.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagecoderuue
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMessageDecoderUUE;
class PASCALIMPLEMENTATION TIdMessageDecoderUUE : public Idmessagecoder::TIdMessageDecoder
{
	typedef Idmessagecoder::TIdMessageDecoder inherited;
	
protected:
	System::UnicodeString FCodingType;
	
public:
	virtual Idmessagecoder::TIdMessageDecoder* __fastcall ReadBody(Classes::TStream* ADestStream, bool &AMsgEnd);
	__property System::UnicodeString CodingType = {read=FCodingType};
public:
	/* TIdMessageDecoder.Destroy */ inline __fastcall virtual ~TIdMessageDecoderUUE(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageDecoderUUE(Classes::TComponent* AOwner)/* overload */ : Idmessagecoder::TIdMessageDecoder(AOwner) { }
	
};


class DELPHICLASS TIdMessageDecoderInfoUUE;
class PASCALIMPLEMENTATION TIdMessageDecoderInfoUUE : public Idmessagecoder::TIdMessageDecoderInfo
{
	typedef Idmessagecoder::TIdMessageDecoderInfo inherited;
	
public:
	virtual Idmessagecoder::TIdMessageDecoder* __fastcall CheckForStart(Idmessage::TIdMessage* ASender, const System::UnicodeString ALine);
public:
	/* TIdMessageDecoderInfo.Create */ inline __fastcall virtual TIdMessageDecoderInfoUUE(void) : Idmessagecoder::TIdMessageDecoderInfo() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageDecoderInfoUUE(void) { }
	
};


class DELPHICLASS TIdMessageEncoderUUEBase;
class PASCALIMPLEMENTATION TIdMessageEncoderUUEBase : public Idmessagecoder::TIdMessageEncoder
{
	typedef Idmessagecoder::TIdMessageEncoder inherited;
	
protected:
	Idcoder3to4::TIdEncoder3to4Class FEncoderClass;
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrc, Classes::TStream* ADest)/* overload */;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoderUUEBase(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoderUUEBase(Classes::TComponent* AOwner)/* overload */ : Idmessagecoder::TIdMessageEncoder(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Encode(const System::UnicodeString AFilename, Classes::TStream* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(AFilename, ADest); }
	inline void __fastcall  Encode(Classes::TStream* ASrc, Classes::TStrings* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(ASrc, ADest); }
	
};


class DELPHICLASS TIdMessageEncoderUUE;
class PASCALIMPLEMENTATION TIdMessageEncoderUUE : public TIdMessageEncoderUUEBase
{
	typedef TIdMessageEncoderUUEBase inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoderUUE(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoderUUE(Classes::TComponent* AOwner)/* overload */ : TIdMessageEncoderUUEBase(AOwner) { }
	
};


class DELPHICLASS TIdMessageEncoderInfoUUE;
class PASCALIMPLEMENTATION TIdMessageEncoderInfoUUE : public Idmessagecoder::TIdMessageEncoderInfo
{
	typedef Idmessagecoder::TIdMessageEncoderInfo inherited;
	
public:
	__fastcall virtual TIdMessageEncoderInfoUUE(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageEncoderInfoUUE(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessagecoderuue */
using namespace Idmessagecoderuue;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagecoderuueHPP
