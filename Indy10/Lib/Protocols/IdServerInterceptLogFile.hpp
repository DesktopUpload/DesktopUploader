// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idserverinterceptlogfile.pas' rev: 20.00

#ifndef IdserverinterceptlogfileHPP
#define IdserverinterceptlogfileHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idserverinterceptlogbase.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idserverinterceptlogfile
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdServerInterceptLogFile;
class PASCALIMPLEMENTATION TIdServerInterceptLogFile : public Idserverinterceptlogbase::TIdServerInterceptLogBase
{
	typedef Idserverinterceptlogbase::TIdServerInterceptLogBase inherited;
	
protected:
	Classes::TFileStream* FFileStream;
	System::UnicodeString FFilename;
	
public:
	virtual void __fastcall Init(void);
	__fastcall virtual ~TIdServerInterceptLogFile(void);
	virtual void __fastcall DoLogWriteString(const System::UnicodeString AText);
	
__published:
	__property System::UnicodeString Filename = {read=FFilename, write=FFilename};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerInterceptLogFile(Classes::TComponent* AOwner)/* overload */ : Idserverinterceptlogbase::TIdServerInterceptLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idserverinterceptlogfile */
using namespace Idserverinterceptlogfile;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdserverinterceptlogfileHPP
