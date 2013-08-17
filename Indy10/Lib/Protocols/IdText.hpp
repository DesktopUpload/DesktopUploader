// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtext.pas' rev: 20.00

#ifndef IdtextHPP
#define IdtextHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idmessageparts.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtext
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdText;
class PASCALIMPLEMENTATION TIdText : public Idmessageparts::TIdMessagePart
{
	typedef Idmessageparts::TIdMessagePart inherited;
	
protected:
	Classes::TStrings* FBody;
	virtual System::UnicodeString __fastcall GetContentDisposition();
	virtual System::UnicodeString __fastcall GetContentType();
	virtual void __fastcall SetBody(const Classes::TStrings* AStrs);
	
public:
	__fastcall TIdText(Idmessageparts::TIdMessageParts* Collection, Classes::TStrings* ABody);
	__fastcall virtual ~TIdText(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall IsBodyEncodingRequired(void);
	__classmethod virtual Idmessageparts::TIdMessagePartType __fastcall PartType();
	__property Classes::TStrings* Body = {read=FBody, write=SetBody};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtext */
using namespace Idtext;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtextHPP
