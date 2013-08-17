// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecodermime.pas' rev: 20.00

#ifndef IdmessagecodermimeHPP
#define IdmessagecodermimeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idmessagecoder.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagecodermime
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMessageDecoderMIME;
class PASCALIMPLEMENTATION TIdMessageDecoderMIME : public Idmessagecoder::TIdMessageDecoder
{
	typedef Idmessagecoder::TIdMessageDecoder inherited;
	
protected:
	System::UnicodeString FFirstLine;
	bool FProcessFirstLine;
	bool FBodyEncoded;
	System::UnicodeString FMIMEBoundary;
	System::UnicodeString __fastcall GetProperHeaderItem(const System::UnicodeString Line);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall TIdMessageDecoderMIME(Classes::TComponent* AOwner, const System::UnicodeString ALine)/* overload */;
	virtual Idmessagecoder::TIdMessageDecoder* __fastcall ReadBody(Classes::TStream* ADestStream, bool &VMsgEnd);
	void __fastcall CheckAndSetType(const System::UnicodeString AContentType, System::UnicodeString AContentDisposition);
	virtual void __fastcall ReadHeader(void);
	System::UnicodeString __fastcall GetAttachmentFilename(const System::UnicodeString AContentType, const System::UnicodeString AContentDisposition);
	System::UnicodeString __fastcall RemoveInvalidCharsFromFilename(const System::UnicodeString AFilename);
	__property System::UnicodeString MIMEBoundary = {read=FMIMEBoundary, write=FMIMEBoundary};
	__property bool BodyEncoded = {read=FBodyEncoded, write=FBodyEncoded, nodefault};
public:
	/* TIdMessageDecoder.Destroy */ inline __fastcall virtual ~TIdMessageDecoderMIME(void) { }
	
};


class DELPHICLASS TIdMessageDecoderInfoMIME;
class PASCALIMPLEMENTATION TIdMessageDecoderInfoMIME : public Idmessagecoder::TIdMessageDecoderInfo
{
	typedef Idmessagecoder::TIdMessageDecoderInfo inherited;
	
public:
	virtual Idmessagecoder::TIdMessageDecoder* __fastcall CheckForStart(Idmessage::TIdMessage* ASender, const System::UnicodeString ALine);
public:
	/* TIdMessageDecoderInfo.Create */ inline __fastcall virtual TIdMessageDecoderInfoMIME(void) : Idmessagecoder::TIdMessageDecoderInfo() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageDecoderInfoMIME(void) { }
	
};


class DELPHICLASS TIdMessageEncoderMIME;
class PASCALIMPLEMENTATION TIdMessageEncoderMIME : public Idmessagecoder::TIdMessageEncoder
{
	typedef Idmessagecoder::TIdMessageEncoder inherited;
	
public:
	virtual void __fastcall Encode(Classes::TStream* ASrc, Classes::TStream* ADest)/* overload */;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoderMIME(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoderMIME(Classes::TComponent* AOwner)/* overload */ : Idmessagecoder::TIdMessageEncoder(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Encode(const System::UnicodeString AFilename, Classes::TStream* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(AFilename, ADest); }
	inline void __fastcall  Encode(Classes::TStream* ASrc, Classes::TStrings* ADest){ Idmessagecoder::TIdMessageEncoder::Encode(ASrc, ADest); }
	
};


class DELPHICLASS TIdMessageEncoderInfoMIME;
class PASCALIMPLEMENTATION TIdMessageEncoderInfoMIME : public Idmessagecoder::TIdMessageEncoderInfo
{
	typedef Idmessagecoder::TIdMessageEncoderInfo inherited;
	
public:
	__fastcall virtual TIdMessageEncoderInfoMIME(void);
	virtual void __fastcall InitializeHeaders(Idmessage::TIdMessage* AMsg);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageEncoderInfoMIME(void) { }
	
};


class DELPHICLASS TIdMIMEBoundaryStrings;
class PASCALIMPLEMENTATION TIdMIMEBoundaryStrings : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod System::WideChar __fastcall GenerateRandomChar();
	__classmethod System::UnicodeString __fastcall GenerateBoundary();
public:
	/* TObject.Create */ inline __fastcall TIdMIMEBoundaryStrings(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMIMEBoundaryStrings(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define MIMEGenericText L"text/"
#define MIMEGenericMultiPart L"multipart/"
#define MIME7Bit L"7bit"
#define MIMEAttachment L"attachment"
#define MIMEInline L"inline"
#define InvalidWindowsFilenameChars L"\\/:*?\"<>|"

}	/* namespace Idmessagecodermime */
using namespace Idmessagecodermime;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagecodermimeHPP
