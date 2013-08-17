// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idlogfile.pas' rev: 20.00

#ifndef IdlogfileHPP
#define IdlogfileHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idlogbase.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogfile
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdLogFile;
class PASCALIMPLEMENTATION TIdLogFile : public Idlogbase::TIdLogBase
{
	typedef Idlogbase::TIdLogBase inherited;
	
protected:
	System::UnicodeString FFilename;
	Classes::TStream* FFileStream;
	virtual void __fastcall LogFormat(const System::UnicodeString AFormat, System::TVarRec const *AArgs, const int AArgs_Size);
	virtual void __fastcall LogReceivedData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogSentData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogStatus(const System::UnicodeString AText);
	virtual void __fastcall LogWriteString(const System::UnicodeString AText);
	void __fastcall SetFilename(const System::UnicodeString AFilename);
	
public:
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(void);
	
__published:
	__property System::UnicodeString Filename = {read=FFilename, write=SetFilename};
public:
	/* TIdLogBase.Destroy */ inline __fastcall virtual ~TIdLogFile(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdLogFile(Classes::TComponent* AOwner)/* overload */ : Idlogbase::TIdLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idlogfile */
using namespace Idlogfile;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdlogfileHPP
