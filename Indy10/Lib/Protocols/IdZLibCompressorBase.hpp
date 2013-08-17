// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idzlibcompressorbase.pas' rev: 20.00

#ifndef IdzlibcompressorbaseHPP
#define IdzlibcompressorbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idstream.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idzlibcompressorbase
{
//-- type declarations -------------------------------------------------------
typedef ShortInt TIdCompressionLevel;

class DELPHICLASS TIdZLibCompressorBase;
class PASCALIMPLEMENTATION TIdZLibCompressorBase : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	virtual bool __fastcall GetIsReady(void);
	
public:
	virtual void __fastcall DeflateStream(Classes::TStream* AInStream, Classes::TStream* AOutStream, const TIdCompressionLevel ALevel = (TIdCompressionLevel)(0x0)) = 0 ;
	virtual void __fastcall InflateStream(Classes::TStream* AInStream, Classes::TStream* AOutStream) = 0 ;
	virtual void __fastcall CompressStream(Classes::TStream* AInStream, Classes::TStream* AOutStream, const TIdCompressionLevel ALevel, const int AWindowBits, const int AMemLevel, const int AStrategy) = 0 ;
	virtual void __fastcall DecompressStream(Classes::TStream* AInStream, Classes::TStream* AOutStream, const int AWindowBits) = 0 ;
	virtual void __fastcall DecompressDeflateStream(Classes::TStream* AInStream, Classes::TStream* AOutStream);
	void __fastcall CompressFTPDeflate(Classes::TStream* AInStream, Classes::TStream* AOutStream, const int ALevel, const int AWindowBits, const int AMemLevel, const int AStrategy);
	virtual void __fastcall CompressFTPToIO(Classes::TStream* AInStream, Idiohandler::TIdIOHandler* AIOHandler, const int ALevel, const int AWindowBits, const int AMemLevel, const int AStrategy) = 0 ;
	virtual void __fastcall DecompressFTPFromIO(Idiohandler::TIdIOHandler* AIOHandler, Classes::TStream* AOutputStream, const int AWindowBits) = 0 ;
	void __fastcall DecompressFTPDeflate(Classes::TStream* AInStream, Classes::TStream* AOutStream, const int AWindowBits);
	void __fastcall CompressHTTPDeflate(Classes::TStream* AInStream, Classes::TStream* AOutStream, const TIdCompressionLevel ALevel);
	void __fastcall DecompressHTTPDeflate(Classes::TStream* AInStream, Classes::TStream* AOutStream);
	virtual void __fastcall DecompressGZipStream(Classes::TStream* AInStream, Classes::TStream* AOutStream);
	__property bool IsReady = {read=GetIsReady, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdZLibCompressorBase(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdZLibCompressorBase(void) { }
	
};


typedef TMetaClass* TIdZLibCompressorBaseClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idzlibcompressorbase */
using namespace Idzlibcompressorbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdzlibcompressorbaseHPP
