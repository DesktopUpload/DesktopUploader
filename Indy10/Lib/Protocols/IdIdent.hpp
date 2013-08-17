// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idident.pas' rev: 20.00

#ifndef IdidentHPP
#define IdidentHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idident
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIdent;
class PASCALIMPLEMENTATION TIdIdent : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	int FQueryTimeOut;
	System::UnicodeString FReplyString;
	System::UnicodeString __fastcall GetReplyCharset();
	System::UnicodeString __fastcall GetReplyOS();
	System::UnicodeString __fastcall GetReplyOther();
	System::UnicodeString __fastcall GetReplyUserName();
	System::UnicodeString __fastcall FetchUserReply();
	System::UnicodeString __fastcall FetchOS();
	void __fastcall ParseError(void);
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall Query(System::Word APortOnServer, System::Word APortOnClient);
	__property System::UnicodeString Reply = {read=FReplyString};
	__property System::UnicodeString ReplyCharset = {read=GetReplyCharset};
	__property System::UnicodeString ReplyOS = {read=GetReplyOS};
	__property System::UnicodeString ReplyOther = {read=GetReplyOther};
	__property System::UnicodeString ReplyUserName = {read=GetReplyUserName};
	
__published:
	__property int QueryTimeOut = {read=FQueryTimeOut, write=FQueryTimeOut, default=60000};
	__property Port = {default=113};
	__property Host;
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdIdent(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIdent(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


class DELPHICLASS EIdIdentException;
class PASCALIMPLEMENTATION EIdIdentException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentException(void) { }
	
};


class DELPHICLASS EIdIdentReply;
class PASCALIMPLEMENTATION EIdIdentReply : public EIdIdentException
{
	typedef EIdIdentException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentReply(const System::UnicodeString AMsg)/* overload */ : EIdIdentException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentReply(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIdentException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentReply(int Ident)/* overload */ : EIdIdentException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentReply(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIdentException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentReply(const System::UnicodeString Msg, int AHelpContext) : EIdIdentException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentReply(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIdentException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentReply(int Ident, int AHelpContext)/* overload */ : EIdIdentException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentReply(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIdentException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentReply(void) { }
	
};


class DELPHICLASS EIdIdentInvalidPort;
class PASCALIMPLEMENTATION EIdIdentInvalidPort : public EIdIdentReply
{
	typedef EIdIdentReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentInvalidPort(const System::UnicodeString AMsg)/* overload */ : EIdIdentReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentInvalidPort(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIdentReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentInvalidPort(int Ident)/* overload */ : EIdIdentReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentInvalidPort(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIdentReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentInvalidPort(const System::UnicodeString Msg, int AHelpContext) : EIdIdentReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentInvalidPort(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIdentReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentInvalidPort(int Ident, int AHelpContext)/* overload */ : EIdIdentReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentInvalidPort(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIdentReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentInvalidPort(void) { }
	
};


class DELPHICLASS EIdIdentNoUser;
class PASCALIMPLEMENTATION EIdIdentNoUser : public EIdIdentReply
{
	typedef EIdIdentReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentNoUser(const System::UnicodeString AMsg)/* overload */ : EIdIdentReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentNoUser(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIdentReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentNoUser(int Ident)/* overload */ : EIdIdentReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentNoUser(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIdentReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentNoUser(const System::UnicodeString Msg, int AHelpContext) : EIdIdentReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentNoUser(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIdentReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentNoUser(int Ident, int AHelpContext)/* overload */ : EIdIdentReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentNoUser(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIdentReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentNoUser(void) { }
	
};


class DELPHICLASS EIdIdentHiddenUser;
class PASCALIMPLEMENTATION EIdIdentHiddenUser : public EIdIdentReply
{
	typedef EIdIdentReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentHiddenUser(const System::UnicodeString AMsg)/* overload */ : EIdIdentReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentHiddenUser(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIdentReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentHiddenUser(int Ident)/* overload */ : EIdIdentReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentHiddenUser(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIdentReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentHiddenUser(const System::UnicodeString Msg, int AHelpContext) : EIdIdentReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentHiddenUser(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIdentReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentHiddenUser(int Ident, int AHelpContext)/* overload */ : EIdIdentReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentHiddenUser(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIdentReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentHiddenUser(void) { }
	
};


class DELPHICLASS EIdIdentUnknownError;
class PASCALIMPLEMENTATION EIdIdentUnknownError : public EIdIdentReply
{
	typedef EIdIdentReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentUnknownError(const System::UnicodeString AMsg)/* overload */ : EIdIdentReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentUnknownError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIdentReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentUnknownError(int Ident)/* overload */ : EIdIdentReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentUnknownError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIdentReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentUnknownError(const System::UnicodeString Msg, int AHelpContext) : EIdIdentReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentUnknownError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIdentReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentUnknownError(int Ident, int AHelpContext)/* overload */ : EIdIdentReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentUnknownError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIdentReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentUnknownError(void) { }
	
};


class DELPHICLASS EIdIdentQueryTimeOut;
class PASCALIMPLEMENTATION EIdIdentQueryTimeOut : public EIdIdentReply
{
	typedef EIdIdentReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIdentQueryTimeOut(const System::UnicodeString AMsg)/* overload */ : EIdIdentReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIdentQueryTimeOut(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIdentReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIdentQueryTimeOut(int Ident)/* overload */ : EIdIdentReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIdentQueryTimeOut(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIdentReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIdentQueryTimeOut(const System::UnicodeString Msg, int AHelpContext) : EIdIdentReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIdentQueryTimeOut(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIdentReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIdentQueryTimeOut(int Ident, int AHelpContext)/* overload */ : EIdIdentReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIdentQueryTimeOut(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIdentReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIdentQueryTimeOut(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word IdIdentQryTimeout = 0xea60;

}	/* namespace Idident */
using namespace Idident;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdidentHPP
