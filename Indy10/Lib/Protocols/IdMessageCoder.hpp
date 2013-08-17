// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessagecoder.pas' rev: 20.00

#ifndef IdmessagecoderHPP
#define IdmessagecoderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessagecoder
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdMessageCoderPartType { mcptUnknown, mcptText, mcptAttachment, mcptIgnore };
#pragma option pop

class DELPHICLASS TIdMessageDecoder;
class PASCALIMPLEMENTATION TIdMessageDecoder : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	System::UnicodeString FFilename;
	bool FFreeSourceStream;
	Classes::TStrings* FHeaders;
	TIdMessageCoderPartType FPartType;
	Classes::TStream* FSourceStream;
	virtual void __fastcall InitComponent(void);
	
public:
	virtual TIdMessageDecoder* __fastcall ReadBody(Classes::TStream* ADestStream, bool &AMsgEnd) = 0 ;
	virtual void __fastcall ReadHeader(void);
	System::UnicodeString __fastcall ReadLn(const System::UnicodeString ATerminator = L"\n", Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	System::UnicodeString __fastcall ReadLnRFC(bool &VMsgEnd, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::UnicodeString __fastcall ReadLnRFC(bool &VMsgEnd, const System::UnicodeString ALineTerminator, const System::UnicodeString ADelim = L".", Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	__fastcall virtual ~TIdMessageDecoder(void);
	__property System::UnicodeString Filename = {read=FFilename};
	__property bool FreeSourceStream = {read=FFreeSourceStream, write=FFreeSourceStream, nodefault};
	__property Classes::TStrings* Headers = {read=FHeaders};
	__property TIdMessageCoderPartType PartType = {read=FPartType, nodefault};
	__property Classes::TStream* SourceStream = {read=FSourceStream, write=FSourceStream};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageDecoder(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


class DELPHICLASS TIdMessageDecoderInfo;
class PASCALIMPLEMENTATION TIdMessageDecoderInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual TIdMessageDecoder* __fastcall CheckForStart(Idmessage::TIdMessage* ASender, const System::UnicodeString ALine) = 0 ;
	__fastcall virtual TIdMessageDecoderInfo(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageDecoderInfo(void) { }
	
};


class DELPHICLASS TIdMessageDecoderList;
class PASCALIMPLEMENTATION TIdMessageDecoderList : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* FMessageCoders;
	
public:
	__classmethod TIdMessageDecoderInfo* __fastcall ByName(const System::UnicodeString AName);
	__classmethod TIdMessageDecoder* __fastcall CheckForStart(Idmessage::TIdMessage* ASender, const System::UnicodeString ALine);
	__fastcall TIdMessageDecoderList(void);
	__fastcall virtual ~TIdMessageDecoderList(void);
	__classmethod void __fastcall RegisterDecoder(const System::UnicodeString AMessageCoderName, TIdMessageDecoderInfo* AMessageCoderInfo);
};


class DELPHICLASS TIdMessageEncoder;
class PASCALIMPLEMENTATION TIdMessageEncoder : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	System::UnicodeString FFilename;
	int FPermissionCode;
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall Encode(const System::UnicodeString AFilename, Classes::TStream* ADest)/* overload */;
	void __fastcall Encode(Classes::TStream* ASrc, Classes::TStrings* ADest)/* overload */;
	virtual void __fastcall Encode(Classes::TStream* ASrc, Classes::TStream* ADest) = 0 /* overload */;
	
__published:
	__property System::UnicodeString Filename = {read=FFilename, write=FFilename};
	__property int PermissionCode = {read=FPermissionCode, write=FPermissionCode, nodefault};
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdMessageEncoder(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessageEncoder(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


typedef TMetaClass* TIdMessageEncoderClass;

class DELPHICLASS TIdMessageEncoderInfo;
class PASCALIMPLEMENTATION TIdMessageEncoderInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TIdMessageEncoderClass FMessageEncoderClass;
	
public:
	__fastcall virtual TIdMessageEncoderInfo(void);
	virtual void __fastcall InitializeHeaders(Idmessage::TIdMessage* AMsg);
	__property TIdMessageEncoderClass MessageEncoderClass = {read=FMessageEncoderClass};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMessageEncoderInfo(void) { }
	
};


class DELPHICLASS TIdMessageEncoderList;
class PASCALIMPLEMENTATION TIdMessageEncoderList : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* FMessageCoders;
	
public:
	__classmethod TIdMessageEncoderInfo* __fastcall ByName(const System::UnicodeString AName);
	__fastcall TIdMessageEncoderList(void);
	__fastcall virtual ~TIdMessageEncoderList(void);
	__classmethod void __fastcall RegisterEncoder(const System::UnicodeString AMessageEncoderName, TIdMessageEncoderInfo* AMessageEncoderInfo);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idmessagecoder */
using namespace Idmessagecoder;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessagecoderHPP
