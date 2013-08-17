// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idreplyftp.pas' rev: 20.00

#ifndef IdreplyftpHPP
#define IdreplyftpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idreplyftp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdReplyRFCFormat { rfNormal, rfIndentMidLines };
#pragma option pop

class DELPHICLASS TIdReplyFTP;
class PASCALIMPLEMENTATION TIdReplyFTP : public Idreplyrfc::TIdReplyRFC
{
	typedef Idreplyrfc::TIdReplyRFC inherited;
	
protected:
	TIdReplyRFCFormat FReplyFormat;
	virtual Classes::TStrings* __fastcall GetFormattedReply(void);
	virtual void __fastcall SetFormattedReply(const Classes::TStrings* AValue);
	virtual void __fastcall AssignTo(Classes::TPersistent* ADest);
	
public:
	__fastcall virtual TIdReplyFTP(Classes::TCollection* ACollection, Idreply::TIdReplies* AReplyTexts);
	virtual void __fastcall Clear(void);
	__classmethod virtual bool __fastcall IsEndMarker(const System::UnicodeString ALine);
	
__published:
	__property TIdReplyRFCFormat ReplyFormat = {read=FReplyFormat, write=FReplyFormat, default=0};
public:
	/* TIdReply.Create */ inline __fastcall virtual TIdReplyFTP(Classes::TCollection* ACollection) : Idreplyrfc::TIdReplyRFC(ACollection) { }
	/* TIdReply.Destroy */ inline __fastcall virtual ~TIdReplyFTP(void) { }
	
};


class DELPHICLASS TIdRepliesFTP;
class PASCALIMPLEMENTATION TIdRepliesFTP : public Idreplyrfc::TIdRepliesRFC
{
	typedef Idreplyrfc::TIdRepliesRFC inherited;
	
public:
	__fastcall virtual TIdRepliesFTP(Classes::TPersistent* AOwner)/* overload */;
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdRepliesFTP(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const TIdReplyRFCFormat DEF_ReplyFormat = (TIdReplyRFCFormat)(0);

}	/* namespace Idreplyftp */
using namespace Idreplyftp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdreplyftpHPP
