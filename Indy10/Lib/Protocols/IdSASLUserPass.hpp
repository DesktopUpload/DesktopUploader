// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsasluserpass.pas' rev: 20.00

#ifndef IdsasluserpassHPP
#define IdsasluserpassHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Iduserpassprovider.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsasluserpass
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLUserPass;
class PASCALIMPLEMENTATION TIdSASLUserPass : public Idsasl::TIdSASL
{
	typedef Idsasl::TIdSASL inherited;
	
protected:
	Iduserpassprovider::TIdUserPassProvider* FUserPassProvider;
	void __fastcall SetUserPassProvider(const Iduserpassprovider::TIdUserPassProvider* Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	System::UnicodeString __fastcall GetUsername();
	System::UnicodeString __fastcall GetPassword();
	
public:
	virtual bool __fastcall IsReadyToStart(void);
	
__published:
	__property Iduserpassprovider::TIdUserPassProvider* UserPassProvider = {read=FUserPassProvider, write=SetUserPassProvider};
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLUserPass(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLUserPass(Classes::TComponent* AOwner)/* overload */ : Idsasl::TIdSASL(AOwner) { }
	
};


class DELPHICLASS EIdUserPassProviderUnassigned;
class PASCALIMPLEMENTATION EIdUserPassProviderUnassigned : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdUserPassProviderUnassigned(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdUserPassProviderUnassigned(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdUserPassProviderUnassigned(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdUserPassProviderUnassigned(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdUserPassProviderUnassigned(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdUserPassProviderUnassigned(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdUserPassProviderUnassigned(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdUserPassProviderUnassigned(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdUserPassProviderUnassigned(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsasluserpass */
using namespace Idsasluserpass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsasluserpassHPP
