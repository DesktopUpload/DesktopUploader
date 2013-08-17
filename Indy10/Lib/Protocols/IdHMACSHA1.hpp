// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhmacsha1.pas' rev: 20.00

#ifndef Idhmacsha1HPP
#define Idhmacsha1HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit
#include <Idhashsha1.hpp>	// Pascal unit
#include <Idhmac.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhmacsha1
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHMACSHA1;
class PASCALIMPLEMENTATION TIdHMACSHA1 : public Idhmac::TIdHMAC
{
	typedef Idhmac::TIdHMAC inherited;
	
protected:
	virtual void __fastcall InitHash(void);
public:
	/* TIdHMAC.Create */ inline __fastcall virtual TIdHMACSHA1(void) : Idhmac::TIdHMAC() { }
	/* TIdHMAC.Destroy */ inline __fastcall virtual ~TIdHMACSHA1(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhmacsha1 */
using namespace Idhmacsha1;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idhmacsha1HPP
