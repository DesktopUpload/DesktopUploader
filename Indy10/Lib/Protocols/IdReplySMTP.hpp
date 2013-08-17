// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idreplysmtp.pas' rev: 20.00

#ifndef IdreplysmtpHPP
#define IdreplysmtpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idreplysmtp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSMTPEnhancedCode;
class PASCALIMPLEMENTATION TIdSMTPEnhancedCode : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	unsigned FStatusClass;
	unsigned FSubject;
	unsigned FDetails;
	bool FAvailable;
	virtual void __fastcall AssignTo(Classes::TPersistent* ADest);
	bool __fastcall IsValidReplyCode(const System::UnicodeString AText);
	System::UnicodeString __fastcall GetReplyAsStr();
	void __fastcall SetReplyAsStr(const System::UnicodeString AText);
	void __fastcall SetStatusClass(const unsigned AValue);
	void __fastcall SetAvailable(const bool AValue);
	
public:
	__fastcall TIdSMTPEnhancedCode(void);
	
__published:
	__property unsigned StatusClass = {read=FStatusClass, write=SetStatusClass, default=2};
	__property unsigned Subject = {read=FSubject, write=FSubject, default=0};
	__property unsigned Details = {read=FDetails, write=FDetails, default=0};
	__property bool Available = {read=FAvailable, write=SetAvailable, default=0};
	__property System::UnicodeString ReplyAsStr = {read=GetReplyAsStr, write=SetReplyAsStr};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdSMTPEnhancedCode(void) { }
	
};


class DELPHICLASS TIdReplySMTP;
class PASCALIMPLEMENTATION TIdReplySMTP : public Idreplyrfc::TIdReplyRFC
{
	typedef Idreplyrfc::TIdReplyRFC inherited;
	
protected:
	TIdSMTPEnhancedCode* FEnhancedCode;
	virtual void __fastcall AssignTo(Classes::TPersistent* ADest);
	void __fastcall SetEnhancedCode(TIdSMTPEnhancedCode* AValue);
	virtual Classes::TStrings* __fastcall GetFormattedReply(void);
	virtual void __fastcall SetFormattedReply(const Classes::TStrings* AValue);
	
public:
	__fastcall virtual TIdReplySMTP(Classes::TCollection* ACollection)/* overload */;
	__fastcall virtual TIdReplySMTP(Classes::TCollection* ACollection, Idreply::TIdReplies* AReplyTexts)/* overload */;
	__fastcall virtual ~TIdReplySMTP(void);
	virtual void __fastcall RaiseReplyError(void);
	void __fastcall SetEnhReply(const int ANumericCode, const System::UnicodeString AEnhReply, const System::UnicodeString AText);
	
__published:
	__property TIdSMTPEnhancedCode* EnhancedCode = {read=FEnhancedCode, write=SetEnhancedCode};
};


class DELPHICLASS TIdRepliesSMTP;
class PASCALIMPLEMENTATION TIdRepliesSMTP : public Idreplyrfc::TIdRepliesRFC
{
	typedef Idreplyrfc::TIdRepliesRFC inherited;
	
public:
	__fastcall virtual TIdRepliesSMTP(Classes::TPersistent* AOwner)/* overload */;
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdRepliesSMTP(void) { }
	
};


class DELPHICLASS EIdSMTPReplyError;
class PASCALIMPLEMENTATION EIdSMTPReplyError : public Idreplyrfc::EIdReplyRFCError
{
	typedef Idreplyrfc::EIdReplyRFCError inherited;
	
protected:
	TIdSMTPEnhancedCode* FEnhancedCode;
	
public:
	__fastcall EIdSMTPReplyError(const int AErrCode, TIdSMTPEnhancedCode* AEnhanced, const System::UnicodeString AReplyMessage);
	__fastcall virtual ~EIdSMTPReplyError(void);
	__property TIdSMTPEnhancedCode* EnhancedCode = {read=FEnhancedCode};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSMTPReplyError(const System::UnicodeString AMsg)/* overload */ : Idreplyrfc::EIdReplyRFCError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSMTPReplyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSMTPReplyError(int Ident)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSMTPReplyError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSMTPReplyError(const System::UnicodeString Msg, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSMTPReplyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idreplyrfc::EIdReplyRFCError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSMTPReplyError(int Ident, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSMTPReplyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idreplyrfc::EIdReplyRFCError(ResStringRec, Args, Args_Size, AHelpContext) { }
	
};


class DELPHICLASS EIdSMTPReply;
class PASCALIMPLEMENTATION EIdSMTPReply : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSMTPReply(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSMTPReply(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSMTPReply(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSMTPReply(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSMTPReply(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSMTPReply(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSMTPReply(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSMTPReply(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSMTPReply(void) { }
	
};


class DELPHICLASS EIdSMTPReplyInvalidReplyString;
class PASCALIMPLEMENTATION EIdSMTPReplyInvalidReplyString : public EIdSMTPReply
{
	typedef EIdSMTPReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSMTPReplyInvalidReplyString(const System::UnicodeString AMsg)/* overload */ : EIdSMTPReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSMTPReplyInvalidReplyString(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSMTPReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSMTPReplyInvalidReplyString(int Ident)/* overload */ : EIdSMTPReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSMTPReplyInvalidReplyString(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSMTPReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSMTPReplyInvalidReplyString(const System::UnicodeString Msg, int AHelpContext) : EIdSMTPReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSMTPReplyInvalidReplyString(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSMTPReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSMTPReplyInvalidReplyString(int Ident, int AHelpContext)/* overload */ : EIdSMTPReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSMTPReplyInvalidReplyString(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSMTPReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSMTPReplyInvalidReplyString(void) { }
	
};


class DELPHICLASS EIdSMTPReplyInvalidClass;
class PASCALIMPLEMENTATION EIdSMTPReplyInvalidClass : public EIdSMTPReply
{
	typedef EIdSMTPReply inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSMTPReplyInvalidClass(const System::UnicodeString AMsg)/* overload */ : EIdSMTPReply(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSMTPReplyInvalidClass(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSMTPReply(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSMTPReplyInvalidClass(int Ident)/* overload */ : EIdSMTPReply(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSMTPReplyInvalidClass(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSMTPReply(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSMTPReplyInvalidClass(const System::UnicodeString Msg, int AHelpContext) : EIdSMTPReply(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSMTPReplyInvalidClass(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSMTPReply(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSMTPReplyInvalidClass(int Ident, int AHelpContext)/* overload */ : EIdSMTPReply(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSMTPReplyInvalidClass(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSMTPReply(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSMTPReplyInvalidClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define ValidClassChars L"245"
#define ValidClassVals (Set<Byte, 0, 255> () << 0x2 << 0x4 << 0x5 )
static const ShortInt CLASS_DEF = 0x2;
static const bool AVAIL_DEF = false;
static const ShortInt NODETAILS = 0x0;
static const WideChar PARTSEP = (WideChar)(0x2e);
#define Id_EHR_USE_STARTTLS L"5.7.0"
#define Id_EHR_GENERIC_OK L"2.0.0"
#define Id_EHR_GENERIC_TRANS L"4.0.0"
#define Id_EHR_GENERIC_PERM L"5.0.0"
#define Id_EHR_MSG_OTH_OK L"2.1.0"
#define Id_EHR_MSG_OTH_TRANS L"4.1.0"
#define Id_EHR_MSG_OTH_PERM L"5.1.0"
#define Id_EHR_MSG_BAD_DEST L"5.1.1"
#define Id_EHR_MSG_BAD_DEST_SYST L"5.1.2"
#define Id_EHR_MSG_BAD_DEST_SYNTAX L"5.1.3"
#define Id_EHR_MSG_AMBIG_DEST L"5.1.4"
#define Id_EHR_MSG_VALID_DEST L"2.1.5"
#define Id_EHR_MSG_DEST_MOVED_NOFORWARD L"2.1.6"
#define Id_EHR_MSG_SENDER_BOX_SYNTAX L"5.1.7"
#define Id_EHR_MSG_BAD_SENDER_ADDR L"5.1.8"
#define Id_EHR_MB_OTHER_STATUS_OK L"2.2.0"
#define Id_EHR_MB_OTHER_STATUS_TRANS L"4.2.0"
#define Id_EHR_MB_OTHER_STATUS_PERM L"5.2.0"
#define Id_EHR_MB_DISABLED_TEMP L"4.2.1"
#define Id_EHR_MB_DISABLED_PERM L"5.2.1"
#define Id_EHR_MB_FULL L"4.2.2"
#define Id_EHR_MB_MSG_LEN_LIMIT L"5.2.3"
#define Id_EHR_MB_ML_EXPAN_TEMP L"4.2.4"
#define Id_EHR_MB_ML_EXPAN_PERM L"5.2.4"
#define Id_EHR_MD_OTHER_OK L"2.3.0"
#define Id_EHR_MD_OTHER_TRANS L"4.3.0"
#define Id_EHR_MD_OTHER_PERM L"5.3.0"
#define Id_EHR_MD_MAIL_SYSTEM_FULL L"4.3.1"
#define Id_EHR_MD_NOT_EXCEPTING_TRANS L"4.3.2"
#define Id_EHR_MD_NOT_EXCEPTING_PERM L"5.3.2"
#define Id_EHR_MD_NOT_CAPABLE_FEAT_TRANS L"4.3.3"
#define Id_EHR_MD_NOT_CAPABLE_FEAT_PERM L"5.3.3"
#define Id_EHR_MD_TOO_BIG L"5.3.4"
#define Id_EHR_MD_INCORRECT_CONFIG_TRANS L"4.3.5"
#define Id_EHR_MD_INCORRECT_CONFIG_PERM L"5.3.5"
#define Id_EHR_NR_OTHER_OK L"2.4.0"
#define Id_EHR_NR_OTHER_TRANS L"4.4.0"
#define Id_EHR_NR_OTHER_PERM L"5.4.0"
#define Id_EHR_NR_NO_ANSWER L"4.4.1"
#define Id_EHR_NR_BAD_CONNECTION L"4.4.2"
#define Id_EHR_NR_DIR_SVR_FAILURE L"4.4.3"
#define Id_EHR_NR_UNABLE_TO_ROUTE_TRANS L"4.4.4"
#define Id_EHR_NR_UNABLE_TO_ROUTE_PERM L"5.4.4"
#define Id_EHR_NR_SYSTEM_CONGESTION L"4.4.5"
#define Id_EHR_NR_LOOP_DETECTED L"4.4.6"
#define Id_EHR_NR_DELIVERY_EXPIRED_TEMP L"4.4.7"
#define Id_EHR_NR_DELIVERY_EXPIRED_PERM L"5.4.7"
#define Id_EHR_PR_OTHER_OK L"2.5.0"
#define Id_EHR_PR_OTHER_TEMP L"4.5.0"
#define Id_EHR_PR_OTHER_PERM L"5.5.0"
#define Id_EHR_PR_INVALID_CMD L"5.5.1"
#define Id_EHR_PR_SYNTAX_ERR L"5.5.2"
#define Id_EHR_PR_TOO_MANY_RECIPIENTS_TEMP L"4.5.3"
#define Id_EHR_PR_TOO_MANY_RECIPIENTS_PERM L"5.5.3"
#define Id_EHR_PR_INVALID_CMD_ARGS L"5.5.4"
#define Id_EHR_PR_WRONG_VER_TRANS L"4.5.5"
#define Id_EHR_PR_WRONG_VER_PERM L"5.5.5"
#define Id_EHR_MED_OTHER_OK L"2.6.0"
#define Id_EHR_MED_OTHER_TRANS L"4.6.0"
#define Id_EHR_MED_OTHER_PERM L"5.6.0"
#define Id_EHR_MED_NOT_SUPPORTED L"5.6.1"
#define Id_EHR_MED_CONV_REQUIRED_PROHIB_TRANS L"4.6.2"
#define Id_EHR_MED_CONV_REQUIRED_PROHIB_PERM L"5.6.2"
#define Id_EHR_MED_CONV_REQUIRED_NOT_SUP_TRANS L"4.6.3"
#define Id_EHR_MED_CONV_REQUIRED_NOT_SUP_PERM L"5.6.3"
#define Id_EHR_MED_CONV_LOSS_WARNING L"2.6.4"
#define Id_EHR_MED_CONV_LOSS_ERROR L"5.6.4"
#define Id_EHR_MED_CONV_FAILED_TRANS L"4.6.5"
#define Id_EHR_MED_CONV_FAILED_PERM L"5.6.5"
#define Id_EHR_SEC_OTHER_OK L"2.7.0"
#define Id_EHR_SEC_OTHER_TRANS L"4.7.0"
#define Id_EHR_SEC_OTHER_PERM L"5.7.0"
#define Id_EHR_SEC_DEL_NOT_AUTH L"5.7.1"
#define Id_EHR_SEC_EXP_NOT_AUTH L"5.7.2"
#define Id_EHR_SEC_CONV_REQ_NOT_POSSIBLE L"5.7.3"
#define Id_EHR_SEC_NOT_SUPPORTED L"5.7.4"
#define Id_EHR_SEC_CRYPT_FAILURE_TRANS L"4.7.5"
#define Id_EHR_SEC_CRYPT_FAILURE_PERM L"5.7.5"
#define Id_EHR_SEC_CRYPT_ALG_NOT_SUP_TRANS L"4.7.6"
#define Id_EHR_SEC_CRYPT_ALG_NOT_SUP_PERM L"5.7.6"
#define Id_EHR_SEC_INTEGRETIY_FAILED_WARN L"2.7.7"
#define Id_EHR_SEC_INTEGRETIY_FAILED_TRANS L"4.7.7"

}	/* namespace Idreplysmtp */
using namespace Idreplysmtp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdreplysmtpHPP
