// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoder.pas' rev: 20.00

#ifndef IdcoderHPP
#define IdcoderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoder
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEncoder;
class PASCALIMPLEMENTATION TIdEncoder : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
public:
	System::UnicodeString __fastcall Encode(const System::UnicodeString AIn)/* overload */;
	void __fastcall Encode(const System::UnicodeString AIn, Classes::TStrings* ADestStrings)/* overload */;
	void __fastcall Encode(const System::UnicodeString AIn, Classes::TStream* ADestStream)/* overload */;
	System::UnicodeString __fastcall Encode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff)/* overload */;
	void __fastcall Encode(Classes::TStream* ASrcStream, Classes::TStrings* ADestStrings, const int ABytes = 0xffffffff)/* overload */;
	virtual void __fastcall Encode(Classes::TStream* ASrcStream, Classes::TStream* ADestStream, const int ABytes = 0xffffffff) = 0 /* overload */;
	__classmethod System::UnicodeString __fastcall EncodeString(const System::UnicodeString AIn)/* overload */;
	__classmethod void __fastcall EncodeString(const System::UnicodeString AIn, Classes::TStrings* ADestStrings)/* overload */;
	__classmethod void __fastcall EncodeString(const System::UnicodeString AIn, Classes::TStream* ADestStream)/* overload */;
	__classmethod System::UnicodeString __fastcall EncodeBytes(const Sysutils::TBytes ABytes);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoder(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoder(void) { }
	
};


typedef TMetaClass* TIdEncoderClass;

class DELPHICLASS TIdDecoder;
class PASCALIMPLEMENTATION TIdDecoder : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Classes::TStream* FStream;
	
public:
	virtual void __fastcall DecodeBegin(Classes::TStream* ADestStream);
	virtual void __fastcall DecodeEnd(void);
	void __fastcall Decode(const System::UnicodeString AIn)/* overload */;
	virtual void __fastcall Decode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff) = 0 /* overload */;
	__classmethod System::UnicodeString __fastcall DecodeString(const System::UnicodeString AIn);
	__classmethod Sysutils::TBytes __fastcall DecodeBytes(const System::UnicodeString AIn);
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoder(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoder(void) { }
	
};


typedef TMetaClass* TIdDecoderClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcoder */
using namespace Idcoder;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcoderHPP
