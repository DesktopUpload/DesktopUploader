// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecoderyenc.pas' rev: 20.00

#ifndef IdmessagecoderyencHPP
#define IdmessagecoderyencHPP

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
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagecoderyenc
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdMessageYencException;
class PASCALIMPLEMENTATION EIdMessageYencException : public Idexceptioncore::EIdMessageException
{
	typedef Idexceptioncore::EIdMessageException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMessageYencException(const System::UnicodeString AMsg)/* overload */ : Idexceptioncore::EIdMessageException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMessageYencException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexceptioncore::EIdMessageException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMessageYencException(int Ident)/* overload */ : Idexceptioncore::EIdMessageException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageYencException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexceptioncore::EIdMessageException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMessageYencException(const System::UnicodeString Msg, int AHelpContext) : Idexceptioncore::EIdMessageException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageYencException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexceptioncore::EIdMessageException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageYencException(int Ident, int AHelpContext)/* overload */ : Idexceptioncore::EIdMessageException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageYencException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexceptioncore::EIdMessageException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMessageYencException(void) { }
	
};


class DELPHICLASS EIdMessageYencInvalidSizeException;
class PASCALIMPLEMENTATION EIdMessageYencInvalidSizeException : public EIdMessageYencException
{
	typedef EIdMessageYencException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMessageYencInvalidSizeException(const System::UnicodeString AMsg)/* overload */ : EIdMessageYencException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMessageYencInvalidSizeException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdMessageYencException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMessageYencInvalidSizeException(int Ident)/* overload */ : EIdMessageYencException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageYencInvalidSizeException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdMessageYencException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMessageYencInvalidSizeException(const System::UnicodeString Msg, int AHelpContext) : EIdMessageYencException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageYencInvalidSizeException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdMessageYencException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageYencInvalidSizeException(int Ident, int AHelpContext)/* overload */ : EIdMessageYencException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageYencInvalidSizeException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMessageYencException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMessageYencInvalidSizeException(void) { }
	
};


class DELPHICLASS EIdMessageYencInvalidCRCException;
class PASCALIMPLEMENTATION EIdMessageYencInvalidCRCException : public EIdMessageYencException
{
	typedef EIdMessageYencException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMessageYencInvalidCRCException(const System::UnicodeString AMsg)/* overload */ : EIdMessageYencException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMessageYencInvalidCRCException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdMessageYencException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMessageYencInvalidCRCException(int Ident)/* overload */ : EIdMessageYencException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageYencInvalidCRCException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdMessageYencException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMessageYencInvalidCRCException(const System::UnicodeString Msg, int AHelpContext) : EIdMessageYencException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageYencInvalidCRCException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdMessageYencException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageYencInvalidCRCException(int Ident, int AHelpContext)/* overload */ : EIdMessageYencException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageYencInvalidCRCException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMessageYencException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMessageYencInvalidCRCException(void) { }
	
};


class DELPHICLASS EIdMessageYencCorruptionException;
class PASCALIMPLEMENTATION EIdMessageYencCorruptionException : public EIdMessageYencException
{
	typedef EIdMessageYencException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMessageYencCorruptionException(const System::UnicodeString AMsg)/* overload */ : EIdMessageYencException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMessageYencCorruptionException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdMessageYencException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMessageYencCorruptionException(int Ident)/* overload */ : EIdMessageYencException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageYencCorruptionException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdMessageYencException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMessageYencCorruptionException(const System::UnicodeString Msg, int AHelpContext) : EIdMessageYencException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageYencCorruptionException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdMessageYencException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageYencCorruptionException(int Ident, int AHelpContext)/* overload */ : EIdMessageYencException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageYencCorruptionException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMessageYencException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMessageYencCorruptionException(void) { }
	
};


class DELPHICLASS TIdMessageDecoderYenc;
class PASCALIMPLEMENTATION TIdMessageDecoderYenc : public Idmessagecoder::TIdMessageDecoder
{
	typedef Idmessagecoder::TIdMessageDecoder inherited;
	
protected:
	int FPart;
	int FLine;
	int FSize;
	
public:
	virtual Idmessagecoder::TIdMessageDecoder* __fastcall ReadBody(Classes::TStream* ADestStream, bool &AMsgEnd);
public:
	/* TIdMessageDecoder.Destroy */ inline __fastcall virtual ~TIdMessageDecoderYenc(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageDecoderYenc(Classes::TComponent* AOwner)/* overload */ : Idmessagecoder::TIdMessageDecoder(AOwner) { }
	
};


class DELPHICLASS TIdMessageDecoderInfoYenc;
class PASCALIMPLEMENTATION TIdMessageDecoderInfoYenc : public Idmessagecoder::TIdMessageDecoderInfo
{
	typedef Idmessagecoder::TIdMessageDecoderInfo inherited;
	
public:
	virtual Idmessagecoder::TIdMessageDecoder* __fastcall CheckForStart(Idmessage::TIdMessage* ASender, const System::UnicodeString ALine);
public:
	/* TIdMessageDecoderInfo.Create */ inline __fastcall virtual TIdMessageDecoderInfoYenc(void) : Idmessagecoder::TIdMessageDecoderInfo() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageDecoderInfoYenc(void) { }
	
};


class DELPHICLASS TIdMessageEncoderYenc;
class PASCALIMPLEMENTATION TIdMessageEncoderYenc : public Idmessagecoder::TIdMessageEncoder
{
	typedef Idmessagecoder::TIdMessageEncoder inherited;
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrc, Classes::TStream* ADest)/* overload */;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoderYenc(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoderYenc(Classes::TComponent* AOwner)/* overload */ : Idmessagecoder::TIdMessageEncoder(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Encode(const System::UnicodeString AFilename, Classes::TStream* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(AFilename, ADest); }
	inline void __fastcall  Encode(Classes::TStream* ASrc, Classes::TStrings* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(ASrc, ADest); }
	
};


class DELPHICLASS TIdMessageEncoderInfoYenc;
class PASCALIMPLEMENTATION TIdMessageEncoderInfoYenc : public Idmessagecoder::TIdMessageEncoderInfo
{
	typedef Idmessagecoder::TIdMessageEncoderInfo inherited;
	
public:
	__fastcall virtual TIdMessageEncoderInfoYenc(void);
	virtual void __fastcall InitializeHeaders(Idmessage::TIdMessage* AMsg);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageEncoderInfoYenc(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word BUFLEN = 0x1000;
static const ShortInt B_PERIOD = 0x2e;
static const ShortInt B_EQUALS = 0x3d;
static const ShortInt B_TAB = 0x9;
static const ShortInt B_LF = 0xa;
static const ShortInt B_CR = 0xd;
static const ShortInt B_NUL = 0x0;

}	/* namespace Idmessagecoderyenc */
using namespace Idmessagecoderyenc;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagecoderyencHPP
