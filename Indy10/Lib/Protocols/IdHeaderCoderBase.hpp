// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idheadercoderbase.pas' rev: 20.00

#ifndef IdheadercoderbaseHPP
#define IdheadercoderbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idheadercoderbase
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdHeaderCodingNeededEvent)(const System::UnicodeString ACharSet, const System::UnicodeString AData, System::UnicodeString &VResult);

class DELPHICLASS TIdHeaderCoder;
class PASCALIMPLEMENTATION TIdHeaderCoder : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall Decode(const System::UnicodeString ACharSet, const System::UnicodeString AData);
	__classmethod virtual System::UnicodeString __fastcall Encode(const System::UnicodeString ACharSet, const System::UnicodeString AData);
	__classmethod virtual bool __fastcall CanHandle(const System::UnicodeString ACharSet);
public:
	/* TObject.Create */ inline __fastcall TIdHeaderCoder(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdHeaderCoder(void) { }
	
};


typedef TMetaClass* TIdHeaderCoderClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIdHeaderCodingNeededEvent GHeaderEncodingNeeded;
extern PACKAGE TIdHeaderCodingNeededEvent GHeaderDecodingNeeded;
extern PACKAGE TIdHeaderCoderClass __fastcall HeaderCoderByCharSet(const System::UnicodeString ACharSet);
extern PACKAGE System::UnicodeString __fastcall DecodeHeaderData(const System::UnicodeString ACharSet, const System::UnicodeString AData);
extern PACKAGE System::UnicodeString __fastcall EncodeHeaderData(const System::UnicodeString ACharSet, const System::UnicodeString AData);
extern PACKAGE void __fastcall RegisterHeaderCoder(const TIdHeaderCoderClass ACoder);
extern PACKAGE void __fastcall UnregisterHeaderCoder(const TIdHeaderCoderClass ACoder);

}	/* namespace Idheadercoderbase */
using namespace Idheadercoderbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdheadercoderbaseHPP
