// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idnntpserver.pas' rev: 20.00

#ifndef IdnntpserverHPP
#define IdnntpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idcommandhandlers.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idserveriohandler.hpp>	// Pascal unit
#include <Idcmdtcpserver.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpserver.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idnntpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdNNTPServerException;
class PASCALIMPLEMENTATION EIdNNTPServerException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPServerException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPServerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPServerException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPServerException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPServerException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPServerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPServerException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPServerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPServerException(void) { }
	
};


class DELPHICLASS EIdNNTPImplicitTLSRequiresSSL;
class PASCALIMPLEMENTATION EIdNNTPImplicitTLSRequiresSSL : public EIdNNTPServerException
{
	typedef EIdNNTPServerException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNNTPImplicitTLSRequiresSSL(const System::UnicodeString AMsg)/* overload */ : EIdNNTPServerException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdNNTPServerException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(int Ident)/* overload */ : EIdNNTPServerException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdNNTPServerException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(const System::UnicodeString Msg, int AHelpContext) : EIdNNTPServerException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdNNTPServerException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(int Ident, int AHelpContext)/* overload */ : EIdNNTPServerException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPImplicitTLSRequiresSSL(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPServerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNNTPImplicitTLSRequiresSSL(void) { }
	
};


#pragma option push -b-
enum TIdNNTPAuthType { atUserPass, atSimple, atGeneric };
#pragma option pop

typedef Set<TIdNNTPAuthType, atUserPass, atGeneric>  TIdNNTPAuthTypes;

#pragma option push -b-
enum TIdNNTPLookupType { ltLookupError, ltLookupByMsgId, ltLookupByMsgNo };
#pragma option pop

class DELPHICLASS TIdNNTPContext;
class PASCALIMPLEMENTATION TIdNNTPContext : public Idcustomtcpserver::TIdServerContext
{
	typedef Idcustomtcpserver::TIdServerContext inherited;
	
protected:
	bool FAuthenticated;
	System::UnicodeString FAuthenticator;
	System::UnicodeString FAuthEmail;
	System::UnicodeString FAuthParams;
	TIdNNTPAuthType FAuthType;
	int FCurrentArticle;
	System::UnicodeString FCurrentGroup;
	bool FModeReader;
	System::UnicodeString FPassword;
	System::UnicodeString FUserName;
	bool __fastcall GetUsingTLS(void);
	void __fastcall GenerateAuthEmail(void);
	
public:
	__fastcall virtual TIdNNTPContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__property bool Authenticated = {read=FAuthenticated, nodefault};
	__property System::UnicodeString Authenticator = {read=FAuthenticator};
	__property System::UnicodeString AuthEmail = {read=FAuthEmail};
	__property System::UnicodeString AuthParams = {read=FAuthParams};
	__property TIdNNTPAuthType AuthType = {read=FAuthType, nodefault};
	__property int CurrentArticle = {read=FCurrentArticle, nodefault};
	__property System::UnicodeString CurrentGroup = {read=FCurrentGroup};
	__property bool ModeReader = {read=FModeReader, nodefault};
	__property System::UnicodeString Password = {read=FPassword};
	__property System::UnicodeString UserName = {read=FUserName};
	__property bool UsingTLS = {read=GetUsingTLS, nodefault};
public:
	/* TIdContext.Destroy */ inline __fastcall virtual ~TIdNNTPContext(void) { }
	
};


typedef void __fastcall (__closure *TIdNNTPOnAuth)(TIdNNTPContext* AContext, bool &VAccept);

typedef void __fastcall (__closure *TIdNNTPOnNewGroupsList)(TIdNNTPContext* AContext, const System::TDateTime ADateStamp, const System::UnicodeString ADistributions);

typedef void __fastcall (__closure *TIdNNTPOnNewNews)(TIdNNTPContext* AContext, const System::UnicodeString Newsgroups, const System::TDateTime ADateStamp, const System::UnicodeString ADistributions);

typedef void __fastcall (__closure *TIdNNTPOnIHaveCheck)(TIdNNTPContext* AContext, const System::UnicodeString AMsgID, bool VAccept);

typedef void __fastcall (__closure *TIdNNTPOnMsgDataByNo)(TIdNNTPContext* AContext, const int AMsgNo);

typedef void __fastcall (__closure *TIdNNTPOnMsgDataByID)(TIdNNTPContext* AContext, const System::UnicodeString AMsgID);

typedef void __fastcall (__closure *TIdNNTPOnCheckMsgNo)(TIdNNTPContext* AContext, const int AMsgNo, System::UnicodeString &VMsgID);

typedef void __fastcall (__closure *TIdNNTPOnCheckMsgID)(TIdNNTPContext* AContext, const System::UnicodeString AMsgId, int &VMsgNo);

typedef void __fastcall (__closure *TIdNNTPOnMovePointer)(TIdNNTPContext* AContext, int &AMsgNo, System::UnicodeString &VMsgID);

typedef void __fastcall (__closure *TIdNNTPOnPost)(TIdNNTPContext* AContext, bool &VPostOk, System::UnicodeString &VErrorText);

typedef void __fastcall (__closure *TIdNNTPOnSelectGroup)(TIdNNTPContext* AContext, const System::UnicodeString AGroup, int &VMsgCount, int &VMsgFirst, int &VMsgLast, bool &VGroupExists);

typedef void __fastcall (__closure *TIdNNTPOnCheckListGroup)(TIdNNTPContext* AContext, const System::UnicodeString AGroup, bool &VCanJoin, int &VFirstArticle);

typedef void __fastcall (__closure *TIdNNTPOnXHdr)(TIdNNTPContext* AContext, const System::UnicodeString AHeaderName, const int AMsgFirst, const int AMsgLast, const System::UnicodeString AMsgID);

typedef void __fastcall (__closure *TIdNNTPOnXOver)(TIdNNTPContext* AContext, const int AMsgFirst, const int AMsgLast);

typedef void __fastcall (__closure *TIdNNTPOnXPat)(TIdNNTPContext* AContext, const System::UnicodeString AHeaderName, const int AMsgFirst, const int AMsgLast, const System::UnicodeString AMsgID, const System::UnicodeString AHeaderPattern);

typedef void __fastcall (__closure *TIdNNTPOnAuthRequired)(TIdNNTPContext* AContext, const System::UnicodeString ACommand, const System::UnicodeString AParams, bool &VRequired);

typedef void __fastcall (__closure *TIdNNTPOnListPattern)(TIdNNTPContext* AContext, const System::UnicodeString AGroupPattern);

class DELPHICLASS TIdNNTPServer;
class PASCALIMPLEMENTATION TIdNNTPServer : public Idexplicittlsclientserverbase::TIdExplicitTLSServer
{
	typedef Idexplicittlsclientserverbase::TIdExplicitTLSServer inherited;
	
protected:
	bool FImplicitTLS;
	Classes::TStrings* FHelp;
	Classes::TStrings* FDistributionPatterns;
	Classes::TStrings* FOverviewFormat;
	TIdNNTPAuthTypes FSupportedAuthTypes;
	TIdNNTPOnMsgDataByID FOnArticleById;
	TIdNNTPOnMsgDataByNo FOnArticleByNo;
	TIdNNTPOnMsgDataByID FOnBodyById;
	TIdNNTPOnMsgDataByNo FOnBodyByNo;
	TIdNNTPOnMsgDataByID FOnHeadById;
	TIdNNTPOnMsgDataByNo FOnHeadByNo;
	TIdNNTPOnCheckMsgID FOnCheckMsgId;
	TIdNNTPOnCheckMsgNo FOnCheckMsgNo;
	TIdNNTPOnMsgDataByID FOnStatMsgId;
	TIdNNTPOnMsgDataByNo FOnStatMsgNo;
	TIdNNTPOnMovePointer FOnNextArticle;
	TIdNNTPOnMovePointer FOnPrevArticle;
	TIdNNTPOnCheckListGroup FOnCheckListGroup;
	TIdNNTPOnListPattern FOnListActiveGroups;
	TIdNNTPOnListPattern FOnListActiveGroupTimes;
	TIdNNTPOnListPattern FOnListDescriptions;
	Idcustomtcpserver::TIdServerThreadEvent FOnListDistributions;
	Idcustomtcpserver::TIdServerThreadEvent FOnListExtensions;
	Idcustomtcpserver::TIdServerThreadEvent FOnListHeaders;
	Idcustomtcpserver::TIdServerThreadEvent FOnListSubscriptions;
	Idcustomtcpserver::TIdServerThreadEvent FOnListGroup;
	Idcustomtcpserver::TIdServerThreadEvent FOnListGroups;
	TIdNNTPOnNewGroupsList FOnListNewGroups;
	TIdNNTPOnPost FOnPost;
	TIdNNTPOnSelectGroup FOnSelectGroup;
	TIdNNTPOnXHdr FOnXHdr;
	TIdNNTPOnXOver FOnXOver;
	TIdNNTPOnXOver FOnXROver;
	TIdNNTPOnXPat FOnXPat;
	TIdNNTPOnNewNews FOnNewNews;
	TIdNNTPOnIHaveCheck FOnIHaveCheck;
	TIdNNTPOnPost FOnIHavePost;
	TIdNNTPOnAuth FOnAuth;
	TIdNNTPOnAuthRequired FOnAuthRequired;
	bool __fastcall SecLayerRequired(Idcommandhandlers::TIdCommand* ASender);
	bool __fastcall AuthRequired(Idcommandhandlers::TIdCommand* ASender);
	int __fastcall DoCheckMsgID(TIdNNTPContext* AContext, const System::UnicodeString AMsgID);
	System::UnicodeString __fastcall DoCheckMsgNo(TIdNNTPContext* AContext, const int AMsgNo);
	System::UnicodeString __fastcall RawNavigate(TIdNNTPContext* AContext, TIdNNTPOnMovePointer AEvent);
	void __fastcall CommandArticle(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandAuthInfoUser(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandAuthInfoPassword(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandAuthInfoSimple(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandAuthInfoGeneric(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandBody(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandDate(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandHead(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandHelp(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandGroup(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandIHave(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandLast(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandList(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListActiveGroups(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListActiveTimes(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListDescriptions(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListDistributions(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListDistribPats(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListExtensions(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListGroup(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListHeaders(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListOverview(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandListSubscriptions(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandModeReader(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandNewGroups(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandNewNews(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandNext(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandPost(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandSlave(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandStat(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandXHdr(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandXOver(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandXROver(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandXPat(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall CommandSTARTTLS(Idcommandhandlers::TIdCommand* ASender);
	void __fastcall DoListGroups(TIdNNTPContext* AContext);
	void __fastcall DoSelectGroup(TIdNNTPContext* AContext, const System::UnicodeString AGroup, int &VMsgCount, int &VMsgFirst, int &VMsgLast, bool &VGroupExists);
	virtual void __fastcall InitializeCommandHandlers(void);
	void __fastcall SetDistributionPatterns(Classes::TStrings* AValue);
	void __fastcall SetHelp(Classes::TStrings* AValue);
	void __fastcall SetOverviewFormat(Classes::TStrings* AValue);
	virtual void __fastcall SetIOHandler(const Idserveriohandler::TIdServerIOHandler* AValue);
	void __fastcall SetImplicitTLS(const bool AValue);
	virtual void __fastcall InitComponent(void);
	TIdNNTPLookupType __fastcall LookupMessage(Idcommandhandlers::TIdCommand* ASender, int &VNo, System::UnicodeString &VId);
	bool __fastcall LookupMessageRange(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AData, int &VMsgFirst, int &VMsgLast);
	bool __fastcall LookupMessageRangeOrID(Idcommandhandlers::TIdCommand* ASender, const System::UnicodeString AData, int &VMsgFirst, int &VMsgLast, System::UnicodeString &VMsgID);
	
public:
	__fastcall virtual ~TIdNNTPServer(void);
	__classmethod System::TDateTime __fastcall NNTPTimeToTime(const System::UnicodeString ATimeStamp);
	__classmethod System::TDateTime __fastcall NNTPDateTimeToDateTime(const System::UnicodeString ATimeStamp);
	
__published:
	__property DefaultPort = {default=119};
	__property Classes::TStrings* DistributionPatterns = {read=FDistributionPatterns, write=SetDistributionPatterns};
	__property Classes::TStrings* Help = {read=FHelp, write=SetHelp};
	__property bool ImplicitTLS = {read=FImplicitTLS, write=SetImplicitTLS, default=0};
	__property Classes::TStrings* OverviewFormat = {read=FOverviewFormat, write=SetOverviewFormat};
	__property TIdNNTPAuthTypes SupportedAuthTypes = {read=FSupportedAuthTypes, write=FSupportedAuthTypes, nodefault};
	__property TIdNNTPOnMsgDataByID OnArticleById = {read=FOnArticleById, write=FOnArticleById};
	__property TIdNNTPOnMsgDataByNo OnArticleByNo = {read=FOnArticleByNo, write=FOnArticleByNo};
	__property TIdNNTPOnAuth OnAuth = {read=FOnAuth, write=FOnAuth};
	__property TIdNNTPOnAuthRequired OnAuthRequired = {read=FOnAuthRequired, write=FOnAuthRequired};
	__property TIdNNTPOnMsgDataByID OnBodyById = {read=FOnBodyById, write=FOnBodyById};
	__property TIdNNTPOnMsgDataByNo OnBodyByNo = {read=FOnBodyByNo, write=FOnBodyByNo};
	__property TIdNNTPOnCheckMsgNo OnCheckMsgNo = {read=FOnCheckMsgNo, write=FOnCheckMsgNo};
	__property TIdNNTPOnCheckMsgID OnCheckMsgID = {read=FOnCheckMsgId, write=FOnCheckMsgId};
	__property TIdNNTPOnMsgDataByID OnHeadById = {read=FOnHeadById, write=FOnHeadById};
	__property TIdNNTPOnMsgDataByNo OnHeadByNo = {read=FOnHeadByNo, write=FOnHeadByNo};
	__property TIdNNTPOnIHaveCheck OnIHaveCheck = {read=FOnIHaveCheck, write=FOnIHaveCheck};
	__property TIdNNTPOnPost OnIHavePost = {read=FOnIHavePost, write=FOnIHavePost};
	__property TIdNNTPOnMsgDataByID OnStatMsgId = {read=FOnStatMsgId, write=FOnStatMsgId};
	__property TIdNNTPOnMsgDataByNo OnStatMsgNo = {read=FOnStatMsgNo, write=FOnStatMsgNo};
	__property TIdNNTPOnMovePointer OnNextArticle = {read=FOnNextArticle, write=FOnNextArticle};
	__property TIdNNTPOnMovePointer OnPrevArticle = {read=FOnPrevArticle, write=FOnPrevArticle};
	__property TIdNNTPOnCheckListGroup OnCheckListGroup = {read=FOnCheckListGroup, write=FOnCheckListGroup};
	__property TIdNNTPOnListPattern OnListActiveGroups = {read=FOnListActiveGroups, write=FOnListActiveGroups};
	__property TIdNNTPOnListPattern OnListActiveGroupTimes = {read=FOnListActiveGroupTimes, write=FOnListActiveGroupTimes};
	__property TIdNNTPOnListPattern OnListDescriptions = {read=FOnListDescriptions, write=FOnListDescriptions};
	__property Idcustomtcpserver::TIdServerThreadEvent OnListDistributions = {read=FOnListDistributions, write=FOnListDistributions};
	__property Idcustomtcpserver::TIdServerThreadEvent OnListExtensions = {read=FOnListExtensions, write=FOnListExtensions};
	__property Idcustomtcpserver::TIdServerThreadEvent OnListGroup = {read=FOnListGroup, write=FOnListGroup};
	__property Idcustomtcpserver::TIdServerThreadEvent OnListGroups = {read=FOnListGroups, write=FOnListGroups};
	__property Idcustomtcpserver::TIdServerThreadEvent OnListHeaders = {read=FOnListHeaders, write=FOnListHeaders};
	__property TIdNNTPOnNewGroupsList OnListNewGroups = {read=FOnListNewGroups, write=FOnListNewGroups};
	__property Idcustomtcpserver::TIdServerThreadEvent OnListSubscriptions = {read=FOnListSubscriptions, write=FOnListSubscriptions};
	__property TIdNNTPOnNewNews OnNewNews = {read=FOnNewNews, write=FOnNewNews};
	__property TIdNNTPOnSelectGroup OnSelectGroup = {read=FOnSelectGroup, write=FOnSelectGroup};
	__property TIdNNTPOnPost OnPost = {read=FOnPost, write=FOnPost};
	__property TIdNNTPOnXHdr OnXHdr = {read=FOnXHdr, write=FOnXHdr};
	__property TIdNNTPOnXOver OnXOver = {read=FOnXOver, write=FOnXOver};
	__property TIdNNTPOnXPat OnXPat = {read=FOnXPat, write=FOnXPat};
	__property TIdNNTPOnXOver OnXROver = {read=FOnXROver, write=FOnXROver};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdNNTPServer(Classes::TComponent* AOwner)/* overload */ : Idexplicittlsclientserverbase::TIdExplicitTLSServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool DEF_NNTP_IMPLICIT_TLS = false;

}	/* namespace Idnntpserver */
using namespace Idnntpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdnntpserverHPP
