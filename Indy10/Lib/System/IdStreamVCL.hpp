// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idstreamvcl.pas' rev: 20.00

#ifndef IdstreamvclHPP
#define IdstreamvclHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstreamvcl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdStreamHelperVCL;
class PASCALIMPLEMENTATION TIdStreamHelperVCL : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod int __fastcall ReadBytes(const Classes::TStream* AStream, Sysutils::TBytes &VBytes, const int ACount = 0xffffffff, const int AOffset = 0x0);
	__classmethod int __fastcall Write(const Classes::TStream* AStream, const Sysutils::TBytes ABytes, const int ACount = 0xffffffff, const int AOffset = 0x0);
	__classmethod __int64 __fastcall Seek(const Classes::TStream* AStream, const __int64 AOffset, const Classes::TSeekOrigin AOrigin);
public:
	/* TObject.Create */ inline __fastcall TIdStreamHelperVCL(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdStreamHelperVCL(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idstreamvcl */
using namespace Idstreamvcl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdstreamvclHPP
