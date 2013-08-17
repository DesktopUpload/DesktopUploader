// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoderbinhex4.pas' rev: 20.00

#ifndef Idcoderbinhex4HPP
#define Idcoderbinhex4HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Idcoder3to4.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idstream.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoderbinhex4
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEncoderBinHex4;
class PASCALIMPLEMENTATION TIdEncoderBinHex4 : public Idcoder3to4::TIdEncoder3to4
{
	typedef Idcoder3to4::TIdEncoder3to4 inherited;
	
protected:
	System::UnicodeString FFileName;
	System::Word __fastcall GetCRC(const Sysutils::TBytes ABlock, const int AOffset = 0x0, const int ASize = 0xffffffff);
	void __fastcall AddByteCRC(System::Word &ACRC, System::Byte AByte);
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrcStream, Classes::TStream* ADestStream, const int ABytes = 0xffffffff)/* overload */;
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdEncoderBinHex4(Classes::TComponent* AOwner)/* overload */ : Idcoder3to4::TIdEncoder3to4(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdEncoderBinHex4(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline System::UnicodeString __fastcall  Encode(const System::UnicodeString AIn){ return Idcoder::TIdEncoder::Encode(AIn); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStrings* ADestStrings){ Idcoder::TIdEncoder::Encode(AIn, ADestStrings); }
	inline void __fastcall  Encode(const System::UnicodeString AIn, Classes::TStream* ADestStream){ Idcoder::TIdEncoder::Encode(AIn, ADestStream); }
	inline System::UnicodeString __fastcall  Encode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff){ return Idcoder::TIdEncoder::Encode(ASrcStream, ABytes); }
	inline void __fastcall  Encode(Classes::TStream* ASrcStream, Classes::TStrings* ADestStrings, const int ABytes = 0xffffffff){ Idcoder::TIdEncoder::Encode(ASrcStream, ADestStrings, ABytes); }
	
};


class DELPHICLASS TIdDecoderBinHex4;
class PASCALIMPLEMENTATION TIdDecoderBinHex4 : public Idcoder3to4::TIdDecoder4to3
{
	typedef Idcoder3to4::TIdDecoder4to3 inherited;
	
protected:
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Decode(Classes::TStream* ASrcStream, const int ABytes = 0xffffffff)/* overload */;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDecoderBinHex4(Classes::TComponent* AOwner)/* overload */ : Idcoder3to4::TIdDecoder4to3(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDecoderBinHex4(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Decode(const System::UnicodeString AIn){ Idcoder::TIdDecoder::Decode(AIn); }
	
};


class DELPHICLASS EIdMissingColon;
class PASCALIMPLEMENTATION EIdMissingColon : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMissingColon(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMissingColon(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMissingColon(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMissingColon(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMissingColon(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMissingColon(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMissingColon(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMissingColon(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMissingColon(void) { }
	
};


class DELPHICLASS EIdMissingFileName;
class PASCALIMPLEMENTATION EIdMissingFileName : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMissingFileName(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMissingFileName(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMissingFileName(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMissingFileName(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMissingFileName(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMissingFileName(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMissingFileName(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMissingFileName(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMissingFileName(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString GBinHex4CodeTable;
extern PACKAGE System::UnicodeString GBinHex4IdentificationString;
extern PACKAGE Idcoder3to4::TIdDecodeTable GBinHex4DecodeTable;

}	/* namespace Idcoderbinhex4 */
using namespace Idcoderbinhex4;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idcoderbinhex4HPP
