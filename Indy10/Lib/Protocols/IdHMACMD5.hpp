// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idhmacmd5.pas' rev: 20.00

#ifndef Idhmacmd5HPP
#define Idhmacmd5HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit
#include <Idhashmessagedigest.hpp>	// Pascal unit
#include <Idhmac.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhmacmd5
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHMACMD5;
class PASCALIMPLEMENTATION TIdHMACMD5 : public Idhmac::TIdHMAC
{
	typedef Idhmac::TIdHMAC inherited;
	
protected:
	virtual void __fastcall InitHash(void);
public:
	/* TIdHMAC.Create */ inline __fastcall virtual TIdHMACMD5(void) : Idhmac::TIdHMAC() { }
	/* TIdHMAC.Destroy */ inline __fastcall virtual ~TIdHMACMD5(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idhmacmd5 */
using namespace Idhmacmd5;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idhmacmd5HPP
