// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idipaddress.pas' rev: 20.00

#ifndef IdipaddressHPP
#define IdipaddressHPP

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

namespace Idipaddress
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIPAddress;
class PASCALIMPLEMENTATION TIdIPAddress : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	unsigned FIPv4;
	Idglobal::TIdIPVersion FAddrType;
	System::UnicodeString __fastcall GetIPv4AsString();
	System::UnicodeString __fastcall GetIPv6AsString();
	System::UnicodeString __fastcall GetIPAddress();
	
public:
	Idglobal::TIdIPv6Address IPv6;
	__fastcall virtual TIdIPAddress(void);
	__classmethod TIdIPAddress* __fastcall MakeAddressObject(const System::UnicodeString AIP)/* overload */;
	__classmethod TIdIPAddress* __fastcall MakeAddressObject(const System::UnicodeString AIP, const Idglobal::TIdIPVersion AIPVersion)/* overload */;
	int __fastcall CompareAddress(const System::UnicodeString AIP, bool &VErr);
	Sysutils::TBytes __fastcall HToNBytes();
	__property unsigned IPv4 = {read=FIPv4, write=FIPv4, nodefault};
	__property System::UnicodeString IPv4AsString = {read=GetIPv4AsString};
	__property System::UnicodeString IPv6AsString = {read=GetIPv6AsString};
	__property Idglobal::TIdIPVersion AddrType = {read=FAddrType, write=FAddrType, nodefault};
	__property System::UnicodeString IPAsString = {read=GetIPAddress};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdIPAddress(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idipaddress */
using namespace Idipaddress;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdipaddressHPP
