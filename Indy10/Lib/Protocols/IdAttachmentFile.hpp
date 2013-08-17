// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idattachmentfile.pas' rev: 20.00

#ifndef IdattachmentfileHPP
#define IdattachmentfileHPP

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

//-- user supplied -----------------------------------------------------------

namespace Idattachmentfile
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAttachmentFile;
class PASCALIMPLEMENTATION TIdAttachmentFile : public Idattachment::TIdAttachment
{
	typedef Idattachment::TIdAttachment inherited;
	
protected:
	Classes::TFileStream* FTempFileStream;
	System::UnicodeString FStoredPathName;
	bool FFileIsTempFile;
	bool FAttachmentBlocked;
	
public:
	__fastcall TIdAttachmentFile(Idmessageparts::TIdMessageParts* Collection, const System::UnicodeString AFileName);
	__fastcall virtual ~TIdAttachmentFile(void);
	virtual Classes::TStream* __fastcall OpenLoadStream(void);
	virtual void __fastcall CloseLoadStream(void);
	virtual Classes::TStream* __fastcall PrepareTempStream(void);
	virtual void __fastcall FinishTempStream(void);
	virtual void __fastcall SaveToFile(const System::UnicodeString FileName);
	__property bool FileIsTempFile = {read=FFileIsTempFile, write=FFileIsTempFile, nodefault};
	__property System::UnicodeString StoredPathName = {read=FStoredPathName, write=FStoredPathName};
	__property bool AttachmentBlocked = {read=FAttachmentBlocked, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idattachmentfile */
using namespace Idattachmentfile;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdattachmentfileHPP
