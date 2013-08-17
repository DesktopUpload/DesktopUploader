// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idattachmentmemory.pas' rev: 20.00

#ifndef IdattachmentmemoryHPP
#define IdattachmentmemoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idattachment.hpp>	// Pascal unit
#include <Idmessageparts.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idattachmentmemory
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAttachmentMemory;
class PASCALIMPLEMENTATION TIdAttachmentMemory : public Idattachment::TIdAttachment
{
	typedef Idattachment::TIdAttachment inherited;
	
protected:
	Classes::TStream* FDataStream;
	__int64 FDataStreamBeforeLoadPosition;
	System::UnicodeString __fastcall GetDataString();
	void __fastcall SetDataStream(const Classes::TStream* Value);
	void __fastcall SetDataString(const System::UnicodeString Value);
	
public:
	__fastcall virtual TIdAttachmentMemory(Classes::TCollection* Collection)/* overload */;
	__fastcall TIdAttachmentMemory(Idmessageparts::TIdMessageParts* Collection, const Classes::TStream* CopyFrom)/* overload */;
	__fastcall TIdAttachmentMemory(Idmessageparts::TIdMessageParts* Collection, const System::UnicodeString CopyFrom)/* overload */;
	__fastcall virtual ~TIdAttachmentMemory(void);
	__property Classes::TStream* DataStream = {read=FDataStream, write=SetDataStream};
	__property System::UnicodeString DataString = {read=GetDataString, write=SetDataString};
	virtual Classes::TStream* __fastcall OpenLoadStream(void);
	virtual void __fastcall CloseLoadStream(void);
	virtual void __fastcall FinishTempStream(void);
	virtual Classes::TStream* __fastcall PrepareTempStream(void);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idattachmentmemory */
using namespace Idattachmentmemory;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdattachmentmemoryHPP
