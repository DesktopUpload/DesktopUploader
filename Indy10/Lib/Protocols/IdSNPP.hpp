// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsnpp.pas' rev: 20.00

#ifndef IdsnppHPP
#define IdsnppHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsnpp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TConnectionResult { crCanPost, crNoPost, crAuthRequired, crTempUnavailable };
#pragma option pop

struct TCheckResp
{
	
public:
	short Code;
	System::UnicodeString Resp;
};


class DELPHICLASS TIdSNPP;
class PASCALIMPLEMENTATION TIdSNPP : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	bool __fastcall Pager(System::UnicodeString APagerId);
	bool __fastcall SNPPMsg(System::UnicodeString AMsg);
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Connect(void)/* overload */;
	virtual void __fastcall DisconnectNotifyPeer(void);
	void __fastcall Reset(void);
	void __fastcall SendMessage(System::UnicodeString APagerId, System::UnicodeString AMsg);
	
__published:
	__property Port = {default=7777};
	__property Host;
public:
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdSNPP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSNPP(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	
};


class DELPHICLASS EIdSNPPException;
class PASCALIMPLEMENTATION EIdSNPPException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSNPPException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSNPPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSNPPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSNPPException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSNPPException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSNPPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSNPPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSNPPException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSNPPException(void) { }
	
};


class DELPHICLASS EIdSNPPConnectionRefused;
class PASCALIMPLEMENTATION EIdSNPPConnectionRefused : public Idreplyrfc::EIdReplyRFCError
{
	typedef Idreplyrfc::EIdReplyRFCError inherited;
	
public:
	/* EIdReplyRFCError.CreateError */ inline __fastcall virtual EIdSNPPConnectionRefused(const int AErrorCode, const System::UnicodeString AReplyMessage) : Idreplyrfc::EIdReplyRFCError(AErrorCode, AReplyMessage) { }
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSNPPConnectionRefused(const System::UnicodeString AMsg)/* overload */ : Idreplyrfc::EIdReplyRFCError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSNPPConnectionRefused(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSNPPConnectionRefused(int Ident)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSNPPConnectionRefused(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSNPPConnectionRefused(const System::UnicodeString Msg, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSNPPConnectionRefused(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSNPPConnectionRefused(int Ident, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSNPPConnectionRefused(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSNPPConnectionRefused(void) { }
	
};


class DELPHICLASS EIdSNPPProtocolError;
class PASCALIMPLEMENTATION EIdSNPPProtocolError : public Idreplyrfc::EIdReplyRFCError
{
	typedef Idreplyrfc::EIdReplyRFCError inherited;
	
public:
	/* EIdReplyRFCError.CreateError */ inline __fastcall virtual EIdSNPPProtocolError(const int AErrorCode, const System::UnicodeString AReplyMessage) : Idreplyrfc::EIdReplyRFCError(AErrorCode, AReplyMessage) { }
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSNPPProtocolError(const System::UnicodeString AMsg)/* overload */ : Idreplyrfc::EIdReplyRFCError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSNPPProtocolError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSNPPProtocolError(int Ident)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSNPPProtocolError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSNPPProtocolError(const System::UnicodeString Msg, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSNPPProtocolError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSNPPProtocolError(int Ident, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSNPPProtocolError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSNPPProtocolError(void) { }
	
};


class DELPHICLASS EIdSNPPNoMultiLineMessages;
class PASCALIMPLEMENTATION EIdSNPPNoMultiLineMessages : public EIdSNPPException
{
	typedef EIdSNPPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSNPPNoMultiLineMessages(const System::UnicodeString AMsg)/* overload */ : EIdSNPPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSNPPNoMultiLineMessages(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSNPPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSNPPNoMultiLineMessages(int Ident)/* overload */ : EIdSNPPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSNPPNoMultiLineMessages(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSNPPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSNPPNoMultiLineMessages(const System::UnicodeString Msg, int AHelpContext) : EIdSNPPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSNPPNoMultiLineMessages(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSNPPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSNPPNoMultiLineMessages(int Ident, int AHelpContext)/* overload */ : EIdSNPPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSNPPNoMultiLineMessages(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSNPPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSNPPNoMultiLineMessages(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsnpp */
using namespace Idsnpp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsnppHPP
