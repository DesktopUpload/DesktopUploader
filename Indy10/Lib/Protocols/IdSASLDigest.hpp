// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsasldigest.pas' rev: 20.00

#ifndef IdsasldigestHPP
#define IdsasldigestHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsasluserpass.hpp>	// Pascal unit
#include <Iduserpassprovider.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsasldigest
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLDigest;
class PASCALIMPLEMENTATION TIdSASLDigest : public Idsasluserpass::TIdSASLUserPass
{
	typedef Idsasluserpass::TIdSASLUserPass inherited;
	
protected:
	System::UnicodeString Fauthzid;
	
public:
	virtual System::UnicodeString __fastcall StartAuthenticate(const System::UnicodeString AChallenge, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	virtual System::UnicodeString __fastcall ContinueAuthenticate(const System::UnicodeString ALastResponse, const System::UnicodeString AHost, const System::UnicodeString AProtocolName);
	__classmethod virtual Idsasl::TIdSASLServiceName __fastcall ServiceName();
	
__published:
	__property System::UnicodeString authzid = {read=Fauthzid, write=Fauthzid};
public:
	/* TIdSASL.Destroy */ inline __fastcall virtual ~TIdSASLDigest(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSASLDigest(Classes::TComponent* AOwner)/* overload */ : Idsasluserpass::TIdSASLUserPass(AOwner) { }
	
};


class DELPHICLASS EIdSASLDigestException;
class PASCALIMPLEMENTATION EIdSASLDigestException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLDigestException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLDigestException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLDigestException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLDigestException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLDigestException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLDigestException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLDigestException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLDigestException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLDigestException(void) { }
	
};


class DELPHICLASS EIdSASLDigestChallException;
class PASCALIMPLEMENTATION EIdSASLDigestChallException : public EIdSASLDigestException
{
	typedef EIdSASLDigestException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLDigestChallException(const System::UnicodeString AMsg)/* overload */ : EIdSASLDigestException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLDigestChallException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLDigestException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLDigestChallException(int Ident)/* overload */ : EIdSASLDigestException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLDigestChallException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLDigestException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLDigestChallException(const System::UnicodeString Msg, int AHelpContext) : EIdSASLDigestException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLDigestChallException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLDigestException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLDigestChallException(int Ident, int AHelpContext)/* overload */ : EIdSASLDigestException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLDigestChallException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLDigestException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLDigestChallException(void) { }
	
};


class DELPHICLASS EIdSASLDigestChallNoAlgorithm;
class PASCALIMPLEMENTATION EIdSASLDigestChallNoAlgorithm : public EIdSASLDigestChallException
{
	typedef EIdSASLDigestChallException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLDigestChallNoAlgorithm(const System::UnicodeString AMsg)/* overload */ : EIdSASLDigestChallException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLDigestChallNoAlgorithm(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLDigestChallException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLDigestChallNoAlgorithm(int Ident)/* overload */ : EIdSASLDigestChallException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLDigestChallNoAlgorithm(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLDigestChallException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLDigestChallNoAlgorithm(const System::UnicodeString Msg, int AHelpContext) : EIdSASLDigestChallException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLDigestChallNoAlgorithm(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLDigestChallException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLDigestChallNoAlgorithm(int Ident, int AHelpContext)/* overload */ : EIdSASLDigestChallException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLDigestChallNoAlgorithm(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLDigestChallException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLDigestChallNoAlgorithm(void) { }
	
};


class DELPHICLASS EIdSASLDigestChallInvalidAlg;
class PASCALIMPLEMENTATION EIdSASLDigestChallInvalidAlg : public EIdSASLDigestChallException
{
	typedef EIdSASLDigestChallException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLDigestChallInvalidAlg(const System::UnicodeString AMsg)/* overload */ : EIdSASLDigestChallException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLDigestChallInvalidAlg(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLDigestChallException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLDigestChallInvalidAlg(int Ident)/* overload */ : EIdSASLDigestChallException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLDigestChallInvalidAlg(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLDigestChallException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLDigestChallInvalidAlg(const System::UnicodeString Msg, int AHelpContext) : EIdSASLDigestChallException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLDigestChallInvalidAlg(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLDigestChallException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLDigestChallInvalidAlg(int Ident, int AHelpContext)/* overload */ : EIdSASLDigestChallException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLDigestChallInvalidAlg(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLDigestChallException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLDigestChallInvalidAlg(void) { }
	
};


class DELPHICLASS EIdSASLDigestAuthConfNotSupported;
class PASCALIMPLEMENTATION EIdSASLDigestAuthConfNotSupported : public EIdSASLDigestException
{
	typedef EIdSASLDigestException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLDigestAuthConfNotSupported(const System::UnicodeString AMsg)/* overload */ : EIdSASLDigestException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLDigestAuthConfNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLDigestException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLDigestAuthConfNotSupported(int Ident)/* overload */ : EIdSASLDigestException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLDigestAuthConfNotSupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLDigestException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLDigestAuthConfNotSupported(const System::UnicodeString Msg, int AHelpContext) : EIdSASLDigestException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLDigestAuthConfNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLDigestException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLDigestAuthConfNotSupported(int Ident, int AHelpContext)/* overload */ : EIdSASLDigestException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLDigestAuthConfNotSupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLDigestException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLDigestAuthConfNotSupported(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall CalcDigestResponse(const System::UnicodeString AUserName, const System::UnicodeString APassword, const System::UnicodeString ARealm, const System::UnicodeString ANonce, const System::UnicodeString ACNonce, const int ANC, const System::UnicodeString AQop, const System::UnicodeString ADigestURI, const System::UnicodeString AAuthzid = L"");

}	/* namespace Idsasldigest */
using namespace Idsasldigest;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsasldigestHPP
