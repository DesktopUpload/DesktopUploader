// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftp.pas' rev: 20.00

#ifndef IdftpHPP
#define IdftpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcustomtransparentproxy.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idftpcommon.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idftplistparsebase.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idreplyftp.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idthreadsafe.hpp>	// Pascal unit
#include <Idzlibcompressorbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdFtpProxyType { fpcmNone, fpcmUserSite, fpcmSite, fpcmOpen, fpcmUserPass, fpcmTransparent, fpcmUserHostFireWallID, fpcmNovellBorder, fpcmHttpProxyWithFtp, fpcmCustomProxy };
#pragma option pop

#pragma option push -b-
enum TAuthCmd { tAuto, tAuthTLS, tAuthSSL, tAuthTLSC, tAuthTLSP };
#pragma option pop

typedef void __fastcall (__closure *TIdCreateFTPList)(System::TObject* ASender, Idftplist::TIdFTPListItems* &VFTPList);

typedef Classes::TNotifyEvent TOnAfterClientLogin;

typedef void __fastcall (__closure *TIdFtpAfterGet)(System::TObject* ASender, Classes::TStream* AStream);

typedef void __fastcall (__closure *TIdOnDataChannelCreate)(System::TObject* ASender, Idtcpconnection::TIdTCPConnection* ADataChannel);

typedef void __fastcall (__closure *TIdOnDataChannelDestroy)(System::TObject* ASender, Idtcpconnection::TIdTCPConnection* ADataChannel);

typedef void __fastcall (__closure *TIdNeedAccountEvent)(System::TObject* ASender, System::UnicodeString &VAcct);

typedef void __fastcall (__closure *TIdFTPBannerEvent)(System::TObject* ASender, const System::UnicodeString AMsg);

class DELPHICLASS TIdFTPClientIdentifier;
class PASCALIMPLEMENTATION TIdFTPClientIdentifier : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FClientName;
	System::UnicodeString FClientVersion;
	System::UnicodeString FPlatformDescription;
	void __fastcall SetClientName(const System::UnicodeString AValue);
	void __fastcall SetClientVersion(const System::UnicodeString AValue);
	void __fastcall SetPlatformDescription(const System::UnicodeString AValue);
	System::UnicodeString __fastcall GetClntOutput();
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString ClntOutput = {read=GetClntOutput};
	
__published:
	__property System::UnicodeString ClientName = {read=FClientName, write=SetClientName};
	__property System::UnicodeString ClientVersion = {read=FClientVersion, write=SetClientVersion};
	__property System::UnicodeString PlatformDescription = {read=FPlatformDescription, write=SetPlatformDescription};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdFTPClientIdentifier(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdFTPClientIdentifier(void) : Classes::TPersistent() { }
	
};


class DELPHICLASS TIdFtpProxySettings;
class PASCALIMPLEMENTATION TIdFtpProxySettings : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FHost;
	System::UnicodeString FUserName;
	System::UnicodeString FPassword;
	TIdFtpProxyType FProxyType;
	System::Word FPort;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TIdFtpProxyType ProxyType = {read=FProxyType, write=FProxyType, nodefault};
	__property System::UnicodeString Host = {read=FHost, write=FHost};
	__property System::UnicodeString UserName = {read=FUserName, write=FUserName};
	__property System::UnicodeString Password = {read=FPassword, write=FPassword};
	__property System::Word Port = {read=FPort, write=FPort, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdFtpProxySettings(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdFtpProxySettings(void) : Classes::TPersistent() { }
	
};


class DELPHICLASS TIdFTPTZInfo;
class PASCALIMPLEMENTATION TIdFTPTZInfo : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::TDateTime FGMTOffset;
	bool FGMTOffsetAvailable;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property System::TDateTime GMTOffset = {read=FGMTOffset, write=FGMTOffset};
	__property bool GMTOffsetAvailable = {read=FGMTOffsetAvailable, write=FGMTOffsetAvailable, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdFTPTZInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdFTPTZInfo(void) : Classes::TPersistent() { }
	
};


class DELPHICLASS TIdFTP;
class PASCALIMPLEMENTATION TIdFTP : public Idexplicittlsclientserverbase::TIdExplicitTLSClient
{
	typedef Idexplicittlsclientserverbase::TIdExplicitTLSClient inherited;
	
protected:
	bool FAutoLogin;
	bool FAutoIssueFEAT;
	Idftpcommon::TIdFTPTransferMode FCurrentTransferMode;
	TIdFTPClientIdentifier* FClientInfo;
	bool FUsingSFTP;
	bool FUsingCCC;
	bool FUseHOST;
	bool FCanUseMLS;
	bool FUsingExtDataPort;
	bool FUsingNATFastTrack;
	bool FCanResume;
	Classes::TStrings* FListResult;
	Idreplyftp::TIdReplyFTP* FLoginMsg;
	bool FPassive;
	bool FPassiveUseControlHost;
	Idftpcommon::TIdFTPDataPortSecurity FDataPortProtection;
	TAuthCmd FAUTHCmd;
	System::Word FDataPort;
	System::Word FDataPortMin;
	System::Word FDataPortMax;
	System::UnicodeString FExternalIP;
	bool FResumeTested;
	System::UnicodeString FSystemDesc;
	Idftpcommon::TIdFTPTransferType FTransferType;
	int FTransferTimeout;
	int FListenTimeout;
	Idtcpconnection::TIdTCPConnection* FDataChannel;
	Idftplist::TIdFTPListItems* FDirectoryListing;
	System::UnicodeString FDirFormat;
	Idftplistparsebase::TIdFTPListParseClass FListParserClass;
	Classes::TNotifyEvent FOnAfterClientLogin;
	TIdCreateFTPList FOnCreateFTPList;
	Classes::TNotifyEvent FOnBeforeGet;
	TIdFtpAfterGet FOnBeforePut;
	TIdFtpAfterGet FOnAfterGet;
	Classes::TNotifyEvent FOnAfterPut;
	TIdNeedAccountEvent FOnNeedAccount;
	Classes::TNotifyEvent FOnCustomFTPProxy;
	TIdOnDataChannelCreate FOnDataChannelCreate;
	TIdOnDataChannelDestroy FOnDataChannelDestroy;
	TIdFtpProxySettings* FProxySettings;
	bool FUseExtensionDataPort;
	bool FTryNATFastTrack;
	bool FUseMLIS;
	Classes::TStrings* FLangsSupported;
	bool FUseCCC;
	bool FSSCNOn;
	TIdFTPBannerEvent FOnBannerBeforeLogin;
	TIdFTPBannerEvent FOnBannerAfterLogin;
	TIdFTPBannerEvent FOnBannerWarning;
	TIdFTPTZInfo* FTZInfo;
	Idzlibcompressorbase::TIdZLibCompressorBase* FCompressor;
	int FZLibCompressionLevel;
	int FZLibWindowBits;
	int FZLibMemLevel;
	int FZLibStratagy;
	Classes::TNotifyEvent FOnRetrievedDir;
	Classes::TNotifyEvent FOnDirParseStart;
	Classes::TNotifyEvent FOnDirParseEnd;
	Idthreadsafe::TIdThreadSafeBoolean* FAbortFlag;
	System::UnicodeString FAccount;
	void __fastcall DoOnRetrievedDir(void);
	void __fastcall DoOnDirParseStart(void);
	void __fastcall DoOnDirParseEnd(void);
	void __fastcall FinalizeDataOperation(void);
	void __fastcall SetTZInfo(const TIdFTPTZInfo* Value);
	bool __fastcall IsSiteZONESupported(void);
	int __fastcall IndexOfFeatLine(const System::UnicodeString AFeatLine);
	void __fastcall ClearSSCN(void);
	bool __fastcall SetSSCNToOn(void);
	void __fastcall SendInternalPassive(const System::UnicodeString ACmd, System::UnicodeString &VIP, System::Word &VPort);
	void __fastcall SendCPassive(System::UnicodeString &VIP, System::Word &VPort);
	System::UnicodeString __fastcall FindAuthCmd();
	virtual Idreply::TIdReplyClass __fastcall GetReplyClass(void);
	void __fastcall ParseFTPList(void);
	void __fastcall SetPassive(const bool AValue);
	void __fastcall SetTryNATFastTrack(const bool AValue);
	void __fastcall DoTryNATFastTrack(void);
	void __fastcall SetUseExtensionDataPort(const bool AValue);
	virtual void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	virtual void __fastcall SetIOHandler(Idiohandler::TIdIOHandler* AValue);
	virtual bool __fastcall GetSupportsTLS(void);
	void __fastcall ConstructDirListing(void);
	void __fastcall DoAfterLogin(void);
	void __fastcall DoFTPList(void);
	void __fastcall DoCustomFTPProxy(void);
	void __fastcall DoOnBannerAfterLogin(Classes::TStrings* AText);
	void __fastcall DoOnBannerBeforeLogin(Classes::TStrings* AText);
	void __fastcall DoOnBannerWarning(Classes::TStrings* AText);
	void __fastcall SendPBSZ(void);
	void __fastcall SendPROT(void);
	void __fastcall SendDataSettings(void);
	Idftplist::TIdFTPListItems* __fastcall GetDirectoryListing(void);
	void __fastcall InitDataChannel(void);
	void __fastcall SendPret(const System::UnicodeString ACommand);
	void __fastcall InternalGet(const System::UnicodeString ACommand, Classes::TStream* ADest, bool AResume = false);
	void __fastcall InternalPut(const System::UnicodeString ACommand, Classes::TStream* ASource, bool AFromBeginning = true);
	void __fastcall SendPassive(System::UnicodeString &VIP, System::Word &VPort);
	void __fastcall SendPort(Idsockethandle::TIdSocketHandle* AHandle)/* overload */;
	void __fastcall SendPort(const System::UnicodeString AIP, const System::Word APort)/* overload */;
	void __fastcall ParseEPSV(const System::UnicodeString AReply, System::UnicodeString &VIP, System::Word &VPort);
	void __fastcall SendEPort(Idsockethandle::TIdSocketHandle* AHandle)/* overload */;
	void __fastcall SendEPort(const System::UnicodeString AIP, const System::Word APort, const Idglobal::TIdIPVersion AIPVersion)/* overload */;
	void __fastcall SendEPassive(System::UnicodeString &VIP, System::Word &VPort);
	void __fastcall SetProxySettings(const TIdFtpProxySettings* Value);
	void __fastcall SetClientInfo(const TIdFTPClientIdentifier* AValue);
	void __fastcall SendTransferType(void);
	void __fastcall SetTransferType(Idftpcommon::TIdFTPTransferType AValue);
	virtual void __fastcall DoBeforeGet(void);
	virtual void __fastcall DoBeforePut(Classes::TStream* AStream);
	virtual void __fastcall DoAfterGet(Classes::TStream* AStream);
	virtual void __fastcall DoAfterPut(void);
	void __fastcall FXPSetTransferPorts(TIdFTP* AFromSite, TIdFTP* AToSite, const bool ATargetUsesPasv);
	void __fastcall FXPSendFile(TIdFTP* AFromSite, TIdFTP* AToSite, const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile);
	bool __fastcall InternalEncryptedTLSFXP(TIdFTP* AFromSite, TIdFTP* AToSite, const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile, const bool ATargetUsesPasv);
	bool __fastcall InternalUnencryptedFXP(TIdFTP* AFromSite, TIdFTP* AToSite, const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile, const bool ATargetUsesPasv);
	bool __fastcall ValidateInternalIsTLSFXP(TIdFTP* AFromSite, TIdFTP* AToSite, const bool ATargetUsesPasv);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall SetUseTLS(Idexplicittlsclientserverbase::TIdUseTLS AValue);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetDataPortProtection(Idftpcommon::TIdFTPDataPortSecurity AValue);
	void __fastcall SetAUTHCmd(const TAuthCmd AValue);
	void __fastcall SetUseCCC(const bool AValue);
	void __fastcall IssueFEAT(void);
	bool __fastcall IsOldServU(void);
	bool __fastcall IsBPFTP(void);
	bool __fastcall IsTitan(void);
	bool __fastcall CheckAccount(void);
	bool __fastcall IsAccountNeeded(void);
	bool __fastcall GetSupportsVerification(void);
	
public:
	bool __fastcall IsExtSupported(const System::UnicodeString ACmd);
	void __fastcall ExtractFeatFacts(const System::UnicodeString ACmd, Classes::TStrings* AResults);
	System::UnicodeString __fastcall GetLoginPassword()/* overload */;
	System::UnicodeString __fastcall GetLoginPassword(const System::UnicodeString APrompt)/* overload */;
	virtual void __fastcall Abort(void);
	void __fastcall Allocate(int AAllocateBytes);
	void __fastcall ChangeDir(const System::UnicodeString ADirName);
	void __fastcall ChangeDirUp(void);
	virtual void __fastcall Connect(void)/* overload */;
	__fastcall virtual ~TIdFTP(void);
	void __fastcall Delete(const System::UnicodeString AFilename);
	void __fastcall FileStructure(Idftpcommon::TIdFTPDataStructure AStructure);
	void __fastcall Get(const System::UnicodeString ASourceFile, Classes::TStream* ADest, bool AResume = false)/* overload */;
	void __fastcall Get(const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile, const bool ACanOverwrite = false, bool AResume = false)/* overload */;
	void __fastcall Help(Classes::TStrings* AHelpContents, System::UnicodeString ACommand = L"");
	virtual void __fastcall KillDataChannel(void);
	void __fastcall List(void)/* overload */;
	void __fastcall List(const System::UnicodeString ASpecifier, bool ADetails = true)/* overload */;
	void __fastcall List(Classes::TStrings* ADest, const System::UnicodeString ASpecifier = L"", bool ADetails = true)/* overload */;
	void __fastcall ExtListDir(Classes::TStrings* ADest = (Classes::TStrings*)(0x0), const System::UnicodeString ADirectory = L"");
	void __fastcall ExtListItem(Classes::TStrings* ADest, Idftplist::TIdFTPListItems* AFList, const System::UnicodeString AItem = L"")/* overload */;
	void __fastcall ExtListItem(Classes::TStrings* ADest, const System::UnicodeString AItem = L"")/* overload */;
	void __fastcall ExtListItem(Idftplist::TIdFTPListItems* AFList, const System::UnicodeString AItem = L"")/* overload */;
	System::TDateTime __fastcall FileDate(const System::UnicodeString AFileName, const bool AsGMT = false);
	void __fastcall Login(void);
	void __fastcall MakeDir(const System::UnicodeString ADirName);
	void __fastcall Noop(void);
	void __fastcall SetCmdOpt(const System::UnicodeString ACMD, const System::UnicodeString AOptions);
	void __fastcall Put(const Classes::TStream* ASource, const System::UnicodeString ADestFile, const bool AAppend = false)/* overload */;
	void __fastcall Put(const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile = L"", const bool AAppend = false)/* overload */;
	void __fastcall StoreUnique(const Classes::TStream* ASource)/* overload */;
	void __fastcall StoreUnique(const System::UnicodeString ASourceFile)/* overload */;
	void __fastcall SiteToSiteUpload(const TIdFTP* AToSite, const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile = L"");
	void __fastcall SiteToSiteDownload(const TIdFTP* AFromSite, const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile = L"");
	virtual void __fastcall DisconnectNotifyPeer(void);
	void __fastcall Quit(void);
	short __fastcall Quote(const System::UnicodeString ACommand);
	void __fastcall RemoveDir(const System::UnicodeString ADirName);
	void __fastcall Rename(const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile);
	bool __fastcall ResumeSupported(void);
	System::UnicodeString __fastcall RetrieveCurrentDir();
	void __fastcall Site(const System::UnicodeString ACommand);
	__int64 __fastcall Size(const System::UnicodeString AFileName);
	void __fastcall Status(Classes::TStrings* AStatusList);
	void __fastcall StructureMount(System::UnicodeString APath);
	void __fastcall TransferMode(Idftpcommon::TIdFTPTransferMode ATransferMode);
	void __fastcall ReInitialize(unsigned ADelay = (unsigned)(0xa));
	void __fastcall SetLang(const System::UnicodeString ALangTag);
	__int64 __fastcall CRC(const System::UnicodeString AFIleName, const __int64 AStartPoint = 0x000000000, const __int64 AEndPoint = 0x000000000);
	bool __fastcall VerifyFile(Classes::TStream* ALocalFile, const System::UnicodeString ARemoteFile, const __int64 AStartPoint = 0x000000000, const __int64 AByteCount = 0x000000000)/* overload */;
	bool __fastcall VerifyFile(const System::UnicodeString ALocalFile, const System::UnicodeString ARemoteFile, const __int64 AStartPoint = 0x000000000, const __int64 AByteCount = 0x000000000)/* overload */;
	void __fastcall CombineFiles(const System::UnicodeString ATargetFile, Classes::TStrings* AFileParts);
	void __fastcall SetModTime(const System::UnicodeString AFileName, const System::TDateTime ALocalTime);
	void __fastcall SetModTimeGMT(const System::UnicodeString AFileName, const System::TDateTime AGMTTime);
	bool __fastcall IsServerMDTZAndListTForm(void);
	__property bool AutoIssueFEAT = {read=FAutoIssueFEAT, write=FAutoIssueFEAT, default=1};
	__property bool SupportsVerification = {read=GetSupportsVerification, nodefault};
	__property bool CanResume = {read=ResumeSupported, nodefault};
	__property Idftplist::TIdFTPListItems* DirectoryListing = {read=GetDirectoryListing};
	__property System::UnicodeString DirFormat = {read=FDirFormat};
	__property Classes::TStrings* LangsSupported = {read=FLangsSupported};
	__property Idftplistparsebase::TIdFTPListParseClass ListParserClass = {read=FListParserClass, write=FListParserClass};
	__property Idreplyftp::TIdReplyFTP* LoginMsg = {read=FLoginMsg};
	__property Classes::TStrings* ListResult = {read=FListResult};
	__property System::UnicodeString SystemDesc = {read=FSystemDesc};
	__property TIdFTPTZInfo* TZInfo = {read=FTZInfo, write=SetTZInfo};
	__property bool UsingExtDataPort = {read=FUsingExtDataPort, nodefault};
	__property bool UsingNATFastTrack = {read=FUsingNATFastTrack, nodefault};
	__property bool UsingSFTP = {read=FUsingSFTP, nodefault};
	__property Idftpcommon::TIdFTPTransferMode CurrentTransferMode = {read=FCurrentTransferMode, write=TransferMode, nodefault};
	
__published:
	__property IPVersion;
	__property bool AutoLogin = {read=FAutoLogin, write=FAutoLogin, nodefault};
	__property Idzlibcompressorbase::TIdZLibCompressorBase* Compressor = {read=FCompressor, write=FCompressor};
	__property Host;
	__property bool UseCCC = {read=FUseCCC, write=SetUseCCC, default=0};
	__property bool Passive = {read=FPassive, write=SetPassive, default=0};
	__property bool PassiveUseControlHost = {read=FPassiveUseControlHost, write=FPassiveUseControlHost, default=0};
	__property Idftpcommon::TIdFTPDataPortSecurity DataPortProtection = {read=FDataPortProtection, write=SetDataPortProtection, default=0};
	__property TAuthCmd AUTHCmd = {read=FAUTHCmd, write=SetAUTHCmd, default=0};
	__property System::Word DataPort = {read=FDataPort, write=FDataPort, default=0};
	__property System::Word DataPortMin = {read=FDataPortMin, write=FDataPortMin, default=0};
	__property System::Word DataPortMax = {read=FDataPortMax, write=FDataPortMax, default=0};
	__property System::UnicodeString ExternalIP = {read=FExternalIP, write=FExternalIP};
	__property Password;
	__property Idftpcommon::TIdFTPTransferType TransferType = {read=FTransferType, write=SetTransferType, default=0};
	__property int TransferTimeout = {read=FTransferTimeout, write=FTransferTimeout, default=0};
	__property int ListenTimeout = {read=FListenTimeout, write=FListenTimeout, default=10000};
	__property Username;
	__property Port = {default=21};
	__property bool UseExtensionDataPort = {read=FUseExtensionDataPort, write=SetUseExtensionDataPort, default=0};
	__property bool UseMLIS = {read=FUseMLIS, write=FUseMLIS, default=1};
	__property bool TryNATFastTrack = {read=FTryNATFastTrack, write=SetTryNATFastTrack, default=0};
	__property TIdFtpProxySettings* ProxySettings = {read=FProxySettings, write=SetProxySettings};
	__property System::UnicodeString Account = {read=FAccount, write=FAccount};
	__property TIdFTPClientIdentifier* ClientInfo = {read=FClientInfo, write=SetClientInfo};
	__property bool UseHOST = {read=FUseHOST, write=FUseHOST, default=1};
	__property UseTLS = {default=0};
	__property OnTLSNotAvailable;
	__property TIdFTPBannerEvent OnBannerBeforeLogin = {read=FOnBannerBeforeLogin, write=FOnBannerBeforeLogin};
	__property TIdFTPBannerEvent OnBannerAfterLogin = {read=FOnBannerAfterLogin, write=FOnBannerAfterLogin};
	__property TIdFTPBannerEvent OnBannerWarning = {read=FOnBannerWarning, write=FOnBannerWarning};
	__property Classes::TNotifyEvent OnAfterClientLogin = {read=FOnAfterClientLogin, write=FOnAfterClientLogin};
	__property TIdCreateFTPList OnCreateFTPList = {read=FOnCreateFTPList, write=FOnCreateFTPList};
	__property TIdFtpAfterGet OnAfterGet = {read=FOnAfterGet, write=FOnAfterGet};
	__property Classes::TNotifyEvent OnAfterPut = {read=FOnAfterPut, write=FOnAfterPut};
	__property TIdNeedAccountEvent OnNeedAccount = {read=FOnNeedAccount, write=FOnNeedAccount};
	__property Classes::TNotifyEvent OnCustomFTPProxy = {read=FOnCustomFTPProxy, write=FOnCustomFTPProxy};
	__property TIdOnDataChannelCreate OnDataChannelCreate = {read=FOnDataChannelCreate, write=FOnDataChannelCreate};
	__property TIdOnDataChannelDestroy OnDataChannelDestroy = {read=FOnDataChannelDestroy, write=FOnDataChannelDestroy};
	__property Classes::TNotifyEvent OnRetrievedDir = {read=FOnRetrievedDir, write=FOnRetrievedDir};
	__property Classes::TNotifyEvent OnDirParseStart = {read=FOnDirParseStart, write=FOnDirParseStart};
	__property Classes::TNotifyEvent OnDirParseEnd = {read=FOnDirParseEnd, write=FOnDirParseEnd};
	__property ReadTimeout = {default=60000};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdFTP(Classes::TComponent* AOwner)/* overload */ : Idexplicittlsclientserverbase::TIdExplicitTLSClient(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	
};


class DELPHICLASS EIdFTPException;
class PASCALIMPLEMENTATION EIdFTPException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPException(void) { }
	
};


class DELPHICLASS EIdFTPFileAlreadyExists;
class PASCALIMPLEMENTATION EIdFTPFileAlreadyExists : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPFileAlreadyExists(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPFileAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPFileAlreadyExists(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPFileAlreadyExists(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPFileAlreadyExists(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPFileAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPFileAlreadyExists(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPFileAlreadyExists(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPFileAlreadyExists(void) { }
	
};


class DELPHICLASS EIdFTPMustUseExtWithIPv6;
class PASCALIMPLEMENTATION EIdFTPMustUseExtWithIPv6 : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPMustUseExtWithIPv6(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPMustUseExtWithIPv6(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPMustUseExtWithIPv6(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPMustUseExtWithIPv6(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPMustUseExtWithIPv6(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPMustUseExtWithIPv6(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPMustUseExtWithIPv6(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPMustUseExtWithIPv6(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPMustUseExtWithIPv6(void) { }
	
};


class DELPHICLASS EIdFTPMustUseExtWithNATFastTrack;
class PASCALIMPLEMENTATION EIdFTPMustUseExtWithNATFastTrack : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPMustUseExtWithNATFastTrack(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPMustUseExtWithNATFastTrack(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPMustUseExtWithNATFastTrack(void) { }
	
};


class DELPHICLASS EIdFTPPassiveMustBeTrueWithNATFT;
class PASCALIMPLEMENTATION EIdFTPPassiveMustBeTrueWithNATFT : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPPassiveMustBeTrueWithNATFT(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPPassiveMustBeTrueWithNATFT(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPPassiveMustBeTrueWithNATFT(void) { }
	
};


class DELPHICLASS EIdFTPServerSentInvalidPort;
class PASCALIMPLEMENTATION EIdFTPServerSentInvalidPort : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPServerSentInvalidPort(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPServerSentInvalidPort(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPServerSentInvalidPort(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPServerSentInvalidPort(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPServerSentInvalidPort(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPServerSentInvalidPort(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPServerSentInvalidPort(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPServerSentInvalidPort(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPServerSentInvalidPort(void) { }
	
};


class DELPHICLASS EIdFTPSiteToSiteTransfer;
class PASCALIMPLEMENTATION EIdFTPSiteToSiteTransfer : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPSiteToSiteTransfer(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPSiteToSiteTransfer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPSiteToSiteTransfer(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPSiteToSiteTransfer(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPSiteToSiteTransfer(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPSiteToSiteTransfer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPSiteToSiteTransfer(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPSiteToSiteTransfer(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPSiteToSiteTransfer(void) { }
	
};


class DELPHICLASS EIdFTPSToSNATFastTrack;
class PASCALIMPLEMENTATION EIdFTPSToSNATFastTrack : public EIdFTPSiteToSiteTransfer
{
	typedef EIdFTPSiteToSiteTransfer inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPSToSNATFastTrack(const System::UnicodeString AMsg)/* overload */ : EIdFTPSiteToSiteTransfer(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPSToSNATFastTrack(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPSToSNATFastTrack(int Ident)/* overload */ : EIdFTPSiteToSiteTransfer(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPSToSNATFastTrack(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPSToSNATFastTrack(const System::UnicodeString Msg, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPSToSNATFastTrack(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPSToSNATFastTrack(int Ident, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPSToSNATFastTrack(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPSToSNATFastTrack(void) { }
	
};


class DELPHICLASS EIdFTPSToSNoDataProtection;
class PASCALIMPLEMENTATION EIdFTPSToSNoDataProtection : public EIdFTPSiteToSiteTransfer
{
	typedef EIdFTPSiteToSiteTransfer inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPSToSNoDataProtection(const System::UnicodeString AMsg)/* overload */ : EIdFTPSiteToSiteTransfer(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPSToSNoDataProtection(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPSToSNoDataProtection(int Ident)/* overload */ : EIdFTPSiteToSiteTransfer(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPSToSNoDataProtection(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPSToSNoDataProtection(const System::UnicodeString Msg, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPSToSNoDataProtection(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPSToSNoDataProtection(int Ident, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPSToSNoDataProtection(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPSToSNoDataProtection(void) { }
	
};


class DELPHICLASS EIdFTPSToSIPProtoMustBeSame;
class PASCALIMPLEMENTATION EIdFTPSToSIPProtoMustBeSame : public EIdFTPSiteToSiteTransfer
{
	typedef EIdFTPSiteToSiteTransfer inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPSToSIPProtoMustBeSame(const System::UnicodeString AMsg)/* overload */ : EIdFTPSiteToSiteTransfer(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(int Ident)/* overload */ : EIdFTPSiteToSiteTransfer(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(const System::UnicodeString Msg, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(int Ident, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPSToSIPProtoMustBeSame(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPSToSIPProtoMustBeSame(void) { }
	
};


class DELPHICLASS EIdFTPSToSBothMostSupportSSCN;
class PASCALIMPLEMENTATION EIdFTPSToSBothMostSupportSSCN : public EIdFTPSiteToSiteTransfer
{
	typedef EIdFTPSiteToSiteTransfer inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPSToSBothMostSupportSSCN(const System::UnicodeString AMsg)/* overload */ : EIdFTPSiteToSiteTransfer(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(int Ident)/* overload */ : EIdFTPSiteToSiteTransfer(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(const System::UnicodeString Msg, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(int Ident, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPSToSBothMostSupportSSCN(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPSToSBothMostSupportSSCN(void) { }
	
};


class DELPHICLASS EIdFTPSToSTransModesMustBeSame;
class PASCALIMPLEMENTATION EIdFTPSToSTransModesMustBeSame : public EIdFTPSiteToSiteTransfer
{
	typedef EIdFTPSiteToSiteTransfer inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPSToSTransModesMustBeSame(const System::UnicodeString AMsg)/* overload */ : EIdFTPSiteToSiteTransfer(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPSToSTransModesMustBeSame(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPSToSTransModesMustBeSame(int Ident)/* overload */ : EIdFTPSiteToSiteTransfer(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPSToSTransModesMustBeSame(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPSToSTransModesMustBeSame(const System::UnicodeString Msg, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPSToSTransModesMustBeSame(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPSiteToSiteTransfer(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPSToSTransModesMustBeSame(int Ident, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPSToSTransModesMustBeSame(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPSiteToSiteTransfer(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPSToSTransModesMustBeSame(void) { }
	
};


class DELPHICLASS EIdFTPOnCustomFTPProxyRequired;
class PASCALIMPLEMENTATION EIdFTPOnCustomFTPProxyRequired : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPOnCustomFTPProxyRequired(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPOnCustomFTPProxyRequired(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPOnCustomFTPProxyRequired(void) { }
	
};


class DELPHICLASS EIdFTPConnAssuranceFailure;
class PASCALIMPLEMENTATION EIdFTPConnAssuranceFailure : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPConnAssuranceFailure(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPConnAssuranceFailure(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPConnAssuranceFailure(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPConnAssuranceFailure(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPConnAssuranceFailure(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPConnAssuranceFailure(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPConnAssuranceFailure(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPConnAssuranceFailure(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPConnAssuranceFailure(void) { }
	
};


class DELPHICLASS EIdFTPWrongIOHandler;
class PASCALIMPLEMENTATION EIdFTPWrongIOHandler : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPWrongIOHandler(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPWrongIOHandler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPWrongIOHandler(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPWrongIOHandler(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPWrongIOHandler(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPWrongIOHandler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPWrongIOHandler(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPWrongIOHandler(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPWrongIOHandler(void) { }
	
};


class DELPHICLASS EIdFTPUploadFileNameCanNotBeEmpty;
class PASCALIMPLEMENTATION EIdFTPUploadFileNameCanNotBeEmpty : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPUploadFileNameCanNotBeEmpty(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPUploadFileNameCanNotBeEmpty(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPUploadFileNameCanNotBeEmpty(void) { }
	
};


class DELPHICLASS EIdFTPDataPortProtection;
class PASCALIMPLEMENTATION EIdFTPDataPortProtection : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPDataPortProtection(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPDataPortProtection(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPDataPortProtection(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPDataPortProtection(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPDataPortProtection(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPDataPortProtection(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPDataPortProtection(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPDataPortProtection(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPDataPortProtection(void) { }
	
};


class DELPHICLASS EIdFTPNoDataPortProtectionAfterCCC;
class PASCALIMPLEMENTATION EIdFTPNoDataPortProtectionAfterCCC : public EIdFTPDataPortProtection
{
	typedef EIdFTPDataPortProtection inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPNoDataPortProtectionAfterCCC(const System::UnicodeString AMsg)/* overload */ : EIdFTPDataPortProtection(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPDataPortProtection(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(int Ident)/* overload */ : EIdFTPDataPortProtection(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPDataPortProtection(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(const System::UnicodeString Msg, int AHelpContext) : EIdFTPDataPortProtection(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPDataPortProtection(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(int Ident, int AHelpContext)/* overload */ : EIdFTPDataPortProtection(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPNoDataPortProtectionAfterCCC(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPDataPortProtection(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPNoDataPortProtectionAfterCCC(void) { }
	
};


class DELPHICLASS EIdFTPNoDataPortProtectionWOEncryption;
class PASCALIMPLEMENTATION EIdFTPNoDataPortProtectionWOEncryption : public EIdFTPDataPortProtection
{
	typedef EIdFTPDataPortProtection inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPNoDataPortProtectionWOEncryption(const System::UnicodeString AMsg)/* overload */ : EIdFTPDataPortProtection(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPDataPortProtection(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(int Ident)/* overload */ : EIdFTPDataPortProtection(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPDataPortProtection(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(const System::UnicodeString Msg, int AHelpContext) : EIdFTPDataPortProtection(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPDataPortProtection(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(int Ident, int AHelpContext)/* overload */ : EIdFTPDataPortProtection(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPNoDataPortProtectionWOEncryption(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPDataPortProtection(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPNoDataPortProtectionWOEncryption(void) { }
	
};


class DELPHICLASS EIdFTPNoCCCWOEncryption;
class PASCALIMPLEMENTATION EIdFTPNoCCCWOEncryption : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPNoCCCWOEncryption(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPNoCCCWOEncryption(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPNoCCCWOEncryption(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPNoCCCWOEncryption(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPNoCCCWOEncryption(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPNoCCCWOEncryption(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPNoCCCWOEncryption(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPNoCCCWOEncryption(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPNoCCCWOEncryption(void) { }
	
};


class DELPHICLASS EIdFTPAUTHException;
class PASCALIMPLEMENTATION EIdFTPAUTHException : public EIdFTPException
{
	typedef EIdFTPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPAUTHException(const System::UnicodeString AMsg)/* overload */ : EIdFTPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPAUTHException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPAUTHException(int Ident)/* overload */ : EIdFTPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPAUTHException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPAUTHException(const System::UnicodeString Msg, int AHelpContext) : EIdFTPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPAUTHException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPAUTHException(int Ident, int AHelpContext)/* overload */ : EIdFTPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPAUTHException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPAUTHException(void) { }
	
};


class DELPHICLASS EIdFTPNoAUTHWOSSL;
class PASCALIMPLEMENTATION EIdFTPNoAUTHWOSSL : public EIdFTPAUTHException
{
	typedef EIdFTPAUTHException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPNoAUTHWOSSL(const System::UnicodeString AMsg)/* overload */ : EIdFTPAUTHException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPNoAUTHWOSSL(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPAUTHException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPNoAUTHWOSSL(int Ident)/* overload */ : EIdFTPAUTHException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPNoAUTHWOSSL(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPAUTHException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPNoAUTHWOSSL(const System::UnicodeString Msg, int AHelpContext) : EIdFTPAUTHException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPNoAUTHWOSSL(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPAUTHException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPNoAUTHWOSSL(int Ident, int AHelpContext)/* overload */ : EIdFTPAUTHException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPNoAUTHWOSSL(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPAUTHException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPNoAUTHWOSSL(void) { }
	
};


class DELPHICLASS EIdFTPCanNotSetAUTHCon;
class PASCALIMPLEMENTATION EIdFTPCanNotSetAUTHCon : public EIdFTPAUTHException
{
	typedef EIdFTPAUTHException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFTPCanNotSetAUTHCon(const System::UnicodeString AMsg)/* overload */ : EIdFTPAUTHException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFTPCanNotSetAUTHCon(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFTPAUTHException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFTPCanNotSetAUTHCon(int Ident)/* overload */ : EIdFTPAUTHException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPCanNotSetAUTHCon(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFTPAUTHException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFTPCanNotSetAUTHCon(const System::UnicodeString Msg, int AHelpContext) : EIdFTPAUTHException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPCanNotSetAUTHCon(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFTPAUTHException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPCanNotSetAUTHCon(int Ident, int AHelpContext)/* overload */ : EIdFTPAUTHException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPCanNotSetAUTHCon(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFTPAUTHException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFTPCanNotSetAUTHCon(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Idftpcommon::TIdFTPTransferType Id_TIdFTP_TransferType = (Idftpcommon::TIdFTPTransferType)(0);
static const bool Id_TIdFTP_Passive = false;
static const bool Id_TIdFTP_UseNATFastTrack = false;
static const WideChar Id_TIdFTP_HostPortDelimiter = (WideChar)(0x3a);
static const bool Id_TIdFTP_DataConAssurance = false;
static const Idftpcommon::TIdFTPDataPortSecurity Id_TIdFTP_DataPortProtection = (Idftpcommon::TIdFTPDataPortSecurity)(0);
static const bool DEF_Id_TIdFTP_Implicit = false;
static const bool DEF_Id_FTP_UseExtendedDataPort = false;
static const bool DEF_Id_TIdFTP_UseExtendedData = false;
static const bool DEF_Id_TIdFTP_UseMIS = true;
static const bool DEF_Id_FTP_UseCCC = false;
static const TAuthCmd DEF_Id_FTP_AUTH_CMD = (TAuthCmd)(0);
static const Word DEF_Id_FTP_ListenTimeout = 0x2710;
static const Word DEF_Id_FTP_READTIMEOUT = 0xea60;
static const bool DEF_Id_FTP_UseHOST = true;
static const bool DEF_Id_FTP_PassiveUseControlHost = false;
static const bool DEF_Id_FTP_AutoIssueFEAT = true;

}	/* namespace Idftp */
using namespace Idftp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftpHPP
