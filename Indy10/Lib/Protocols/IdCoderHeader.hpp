// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcoderheader.pas' rev: 20.00

#ifndef IdcoderheaderHPP
#define IdcoderheaderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idheadercoderbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoderheader
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall EncodeAddressItem(Idemailaddress::TIdEMailAddressItem* EmailAddr, const System::WideChar HeaderEncoding, const System::UnicodeString MimeCharSet, bool AUseAddressForNameIfNameMissing = false);
extern PACKAGE System::UnicodeString __fastcall DecodeHeader(const System::UnicodeString Header);
extern PACKAGE void __fastcall DecodeAddress(Idemailaddress::TIdEMailAddressItem* EMailAddr);
extern PACKAGE void __fastcall DecodeAddresses(System::UnicodeString AEMails, Idemailaddress::TIdEMailAddressList* EMailAddr);
extern PACKAGE System::UnicodeString __fastcall EncodeAddress(Idemailaddress::TIdEMailAddressList* EmailAddr, const System::WideChar HeaderEncoding, const System::UnicodeString MimeCharSet, bool AUseAddressForNameIfNameMissing = false);
extern PACKAGE System::UnicodeString __fastcall EncodeHeader(const System::UnicodeString Header, System::UnicodeString Specials, const System::WideChar HeaderEncoding, const System::UnicodeString MimeCharSet);

}	/* namespace Idcoderheader */
using namespace Idcoderheader;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcoderheaderHPP
