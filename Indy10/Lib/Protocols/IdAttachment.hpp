// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idattachment.pas' rev: 20.00

#ifndef IdattachmentHPP
#define IdattachmentHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idmessageparts.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idattachment
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAttachment;
class PASCALIMPLEMENTATION TIdAttachment : public Idmessageparts::TIdMessagePart
{
	typedef Idmessageparts::TIdMessagePart inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetContentDisposition();
	virtual System::UnicodeString __fastcall GetContentType();
	
public:
	virtual Classes::TStream* __fastcall OpenLoadStream(void) = 0 ;
	virtual void __fastcall CloseLoadStream(void) = 0 ;
	virtual Classes::TStream* __fastcall PrepareTempStream(void) = 0 ;
	virtual void __fastcall FinishTempStream(void) = 0 ;
	virtual void __fastcall LoadFromFile(const System::UnicodeString FileName);
	virtual void __fastcall LoadFromStream(Classes::TStream* AStream);
	virtual void __fastcall SaveToFile(const System::UnicodeString FileName);
	virtual void __fastcall SaveToStream(Classes::TStream* AStream);
	__classmethod virtual Idmessageparts::TIdMessagePartType __fastcall PartType();
public:
	/* TIdMessagePart.Create */ inline __fastcall virtual TIdAttachment(Classes::TCollection* Collection) : Idmessageparts::TIdMessagePart(Collection) { }
	/* TIdMessagePart.Destroy */ inline __fastcall virtual ~TIdAttachment(void) { }
	
};


typedef TMetaClass* TIdAttachmentClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idattachment */
using namespace Idattachment;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdattachmentHPP
