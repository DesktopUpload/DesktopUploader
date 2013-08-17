// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idipmcastbase.pas' rev: 20.00

#ifndef IdipmcastbaseHPP
#define IdipmcastbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idipmcastbase
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdIPMv6Scope { IdIPv6MC_InterfaceLocal, IdIPv6MC_LinkLocal, IdIPv6MC_AdminLocal, IdIPv6MC_SiteLocal, IdIPv6MC_OrgLocal, IdIPv6MC_Global };
#pragma option pop

typedef ShortInt TIdIPMCValidScopes;

class DELPHICLASS TIdIPMCastBase;
class PASCALIMPLEMENTATION TIdIPMCastBase : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	bool FDsgnActive;
	System::UnicodeString FMulticastGroup;
	int FPort;
	Idglobal::TIdIPVersion FIPVersion;
	virtual void __fastcall CloseBinding(void) = 0 ;
	virtual bool __fastcall GetActive(void);
	virtual Idsockethandle::TIdSocketHandle* __fastcall GetBinding(void) = 0 ;
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetActive(const bool Value);
	virtual void __fastcall SetMulticastGroup(const System::UnicodeString Value);
	virtual void __fastcall SetPort(const int Value);
	virtual Idglobal::TIdIPVersion __fastcall GetIPVersion(void);
	virtual void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property System::UnicodeString MulticastGroup = {read=FMulticastGroup, write=SetMulticastGroup};
	__property int Port = {read=FPort, write=SetPort, nodefault};
	__property Idglobal::TIdIPVersion IPVersion = {read=GetIPVersion, write=SetIPVersion, default=0};
	virtual void __fastcall InitComponent(void);
	
public:
	bool __fastcall IsValidMulticastGroup(const System::UnicodeString Value);
	__classmethod System::UnicodeString __fastcall SetIPv6AddrScope(const System::UnicodeString AVarIPv6Addr, const TIdIPMv6Scope AScope)/* overload */;
	__classmethod System::UnicodeString __fastcall SetIPv6AddrScope(const System::UnicodeString AVarIPv6Addr, const TIdIPMCValidScopes AScope)/* overload */;
public:
	/* TIdComponent.Destroy */ inline __fastcall virtual ~TIdIPMCastBase(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIPMCastBase(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


class DELPHICLASS EIdMCastException;
class PASCALIMPLEMENTATION EIdMCastException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMCastException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMCastException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMCastException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMCastException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMCastException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMCastException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMCastException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMCastException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMCastException(void) { }
	
};


class DELPHICLASS EIdMCastNoBindings;
class PASCALIMPLEMENTATION EIdMCastNoBindings : public EIdMCastException
{
	typedef EIdMCastException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMCastNoBindings(const System::UnicodeString AMsg)/* overload */ : EIdMCastException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMCastNoBindings(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdMCastException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMCastNoBindings(int Ident)/* overload */ : EIdMCastException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMCastNoBindings(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdMCastException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMCastNoBindings(const System::UnicodeString Msg, int AHelpContext) : EIdMCastException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMCastNoBindings(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdMCastException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMCastNoBindings(int Ident, int AHelpContext)/* overload */ : EIdMCastException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMCastNoBindings(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMCastException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMCastNoBindings(void) { }
	
};


class DELPHICLASS EIdMCastNotValidAddress;
class PASCALIMPLEMENTATION EIdMCastNotValidAddress : public EIdMCastException
{
	typedef EIdMCastException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMCastNotValidAddress(const System::UnicodeString AMsg)/* overload */ : EIdMCastException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMCastNotValidAddress(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdMCastException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMCastNotValidAddress(int Ident)/* overload */ : EIdMCastException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMCastNotValidAddress(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdMCastException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMCastNotValidAddress(const System::UnicodeString Msg, int AHelpContext) : EIdMCastException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMCastNotValidAddress(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdMCastException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMCastNotValidAddress(int Ident, int AHelpContext)/* overload */ : EIdMCastException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMCastNotValidAddress(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMCastException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMCastNotValidAddress(void) { }
	
};


class DELPHICLASS EIdMCastReceiveErrorZeroBytes;
class PASCALIMPLEMENTATION EIdMCastReceiveErrorZeroBytes : public EIdMCastException
{
	typedef EIdMCastException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMCastReceiveErrorZeroBytes(const System::UnicodeString AMsg)/* overload */ : EIdMCastException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMCastReceiveErrorZeroBytes(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdMCastException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMCastReceiveErrorZeroBytes(int Ident)/* overload */ : EIdMCastException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMCastReceiveErrorZeroBytes(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdMCastException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMCastReceiveErrorZeroBytes(const System::UnicodeString Msg, int AHelpContext) : EIdMCastException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMCastReceiveErrorZeroBytes(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdMCastException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMCastReceiveErrorZeroBytes(int Ident, int AHelpContext)/* overload */ : EIdMCastException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMCastReceiveErrorZeroBytes(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMCastException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMCastReceiveErrorZeroBytes(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Byte IPMCastLo = 0xe0;
static const Byte IPMCastHi = 0xef;
#define DEF_IPv6_MGROUP L"FF01:0:0:0:0:0:0:1"

}	/* namespace Idipmcastbase */
using namespace Idipmcastbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdipmcastbaseHPP
