// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddnsserver.pas' rev: 20.00

#ifndef IddnsserverHPP
#define IddnsserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcontainers.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idiohandlersocket.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idresourcestrings.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Iddnsresolver.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idstackconsts.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Iddnscommon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddnsserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDomainExpireCheckThread;
class PASCALIMPLEMENTATION TIdDomainExpireCheckThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	unsigned FInterval;
	System::TObject* FSender;
	Classes::TNotifyEvent FTimerEvent;
	bool FBusy;
	System::UnicodeString FDomain;
	System::UnicodeString FHost;
	virtual void __fastcall Run(void);
	void __fastcall TimerEvent(void);
public:
	/* TIdThread.Create */ inline __fastcall virtual TIdDomainExpireCheckThread(bool ACreateSuspended, bool ALoop, const System::UnicodeString AName) : Idthread::TIdThread(ACreateSuspended, ALoop, AName) { }
	/* TIdThread.Destroy */ inline __fastcall virtual ~TIdDomainExpireCheckThread(void) { }
	
};


class DELPHICLASS TIdDomainNameServerMapping;
class DELPHICLASS TIdDNSMap;
class PASCALIMPLEMENTATION TIdDomainNameServerMapping : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FHost;
	System::UnicodeString FDomainName;
	bool FBusy;
	unsigned FInterval;
	TIdDNSMap* FList;
	void __fastcall SetHost(const System::UnicodeString Value);
	void __fastcall SetInterval(const unsigned Value);
	
protected:
	TIdDomainExpireCheckThread* CheckScheduler;
	__property unsigned Interval = {read=FInterval, write=SetInterval, nodefault};
	__property TIdDNSMap* List = {read=FList, write=FList};
	
public:
	__fastcall TIdDomainNameServerMapping(TIdDNSMap* AList);
	__fastcall virtual ~TIdDomainNameServerMapping(void);
	void __fastcall SyncAndUpdate(System::TObject* Sender);
	__property System::UnicodeString Host = {read=FHost, write=SetHost};
	__property System::UnicodeString DomainName = {read=FDomainName, write=FDomainName};
};


class DELPHICLASS TIdDNS_UDPServer;
class PASCALIMPLEMENTATION TIdDNSMap : public Idcontainers::TIdObjectList
{
	typedef Idcontainers::TIdObjectList inherited;
	
public:
	TIdDomainNameServerMapping* operator[](int Index) { return Items[Index]; }
	
private:
	TIdDNS_UDPServer* FServer;
	HIDESBASE TIdDomainNameServerMapping* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdDomainNameServerMapping* Value);
	void __fastcall SetServer(const TIdDNS_UDPServer* Value);
	
public:
	__fastcall TIdDNSMap(TIdDNS_UDPServer* Server);
	__fastcall virtual ~TIdDNSMap(void);
	__property TIdDNS_UDPServer* Server = {read=FServer, write=SetServer};
	__property TIdDomainNameServerMapping* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


typedef TMetaClass* TIdMWayTreeNodeClass;

class DELPHICLASS TIdMWayTreeNode;
class PASCALIMPLEMENTATION TIdMWayTreeNode : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Idcontainers::TIdObjectList* SubTree;
	TIdMWayTreeNodeClass FFundmentalClass;
	TIdMWayTreeNode* __fastcall GetTreeNode(int Index);
	void __fastcall SetFundmentalClass(const TIdMWayTreeNodeClass Value);
	void __fastcall SetTreeNode(int Index, const TIdMWayTreeNode* Value);
	
public:
	__fastcall virtual TIdMWayTreeNode(TIdMWayTreeNodeClass NodeClass);
	__fastcall virtual ~TIdMWayTreeNode(void);
	__property TIdMWayTreeNodeClass FundmentalClass = {read=FFundmentalClass, write=SetFundmentalClass};
	__property TIdMWayTreeNode* Children[int Index] = {read=GetTreeNode, write=SetTreeNode};
	TIdMWayTreeNode* __fastcall AddChild(void);
	TIdMWayTreeNode* __fastcall InsertChild(int Index);
	void __fastcall RemoveChild(int Index);
};


class DELPHICLASS TIdDNTreeNode;
class PASCALIMPLEMENTATION TIdDNTreeNode : public TIdMWayTreeNode
{
	typedef TIdMWayTreeNode inherited;
	
private:
	System::UnicodeString FCLabel;
	Iddnscommon::TIdTextModeRRs* FRRs;
	Classes::TStrings* FChildIndex;
	TIdDNTreeNode* FParentNode;
	bool FAutoSortChild;
	void __fastcall SetCLabel(const System::UnicodeString Value);
	void __fastcall SetRRs(const Iddnscommon::TIdTextModeRRs* Value);
	TIdDNTreeNode* __fastcall GetNode(int Index);
	void __fastcall SetNode(int Index, const TIdDNTreeNode* Value);
	void __fastcall SetChildIndex(const Classes::TStrings* Value);
	System::UnicodeString __fastcall GetFullName();
	System::UnicodeString __fastcall ConvertToDNString();
	Sysutils::TBytes __fastcall DumpAllBinaryData(int &RecordCount);
	
public:
	__property TIdDNTreeNode* ParentNode = {read=FParentNode, write=FParentNode};
	__property System::UnicodeString CLabel = {read=FCLabel, write=SetCLabel};
	__property Iddnscommon::TIdTextModeRRs* RRs = {read=FRRs, write=SetRRs};
	__property TIdDNTreeNode* Children[int Index] = {read=GetNode, write=SetNode};
	__property Classes::TStrings* ChildIndex = {read=FChildIndex, write=SetChildIndex};
	__property bool AutoSortChild = {read=FAutoSortChild, write=FAutoSortChild, nodefault};
	__property System::UnicodeString FullName = {read=GetFullName};
	__fastcall TIdDNTreeNode(TIdDNTreeNode* AParentNode);
	__fastcall virtual ~TIdDNTreeNode(void);
	HIDESBASE TIdDNTreeNode* __fastcall AddChild(void);
	HIDESBASE TIdDNTreeNode* __fastcall InsertChild(int Index);
	HIDESBASE void __fastcall RemoveChild(int Index);
	void __fastcall SortChildren(void);
	void __fastcall Clear(void);
	void __fastcall SaveToFile(System::UnicodeString Filename);
	int __fastcall IndexByLabel(System::UnicodeString CLabel);
	int __fastcall IndexByNode(TIdDNTreeNode* ANode);
};


class DELPHICLASS TIdDNS_TCPServer;
class PASCALIMPLEMENTATION TIdDNS_TCPServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	Classes::TStrings* FAccessList;
	bool FAccessControl;
	virtual void __fastcall DoConnect(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	void __fastcall SetAccessList(const Classes::TStrings* Value);
	
public:
	__fastcall virtual ~TIdDNS_TCPServer(void);
	
__published:
	__property Classes::TStrings* AccessList = {read=FAccessList, write=SetAccessList};
	__property bool AccessControl = {read=FAccessControl, write=FAccessControl, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDNS_TCPServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


class DELPHICLASS TIdDNS_ProcessThread;
class PASCALIMPLEMENTATION TIdDNS_ProcessThread : public Idthread::TIdThread
{
	typedef Idthread::TIdThread inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FMyBinding;
	Idsockethandle::TIdSocketHandle* FMainBinding;
	Classes::TStream* FMyData;
	System::UnicodeString FData;
	int FDataSize;
	TIdDNS_UDPServer* FServer;
	void __fastcall SetMyBinding(const Idsockethandle::TIdSocketHandle* Value);
	void __fastcall SetMyData(const Classes::TStream* Value);
	void __fastcall SetServer(const TIdDNS_UDPServer* Value);
	void __fastcall ComposeErrorResult(Sysutils::TBytes &VFinal, Iddnscommon::TDNSHeader* OriginalHeader, Sysutils::TBytes OriginalQuestion, int ErrorStatus);
	Sysutils::TBytes __fastcall CombineAnswer(Iddnscommon::TDNSHeader* Header, const Sysutils::TBytes EQuery, const Sysutils::TBytes Answer);
	void __fastcall InternalSearch(Iddnscommon::TDNSHeader* Header, System::UnicodeString QName, System::Word QType, Sysutils::TBytes &Answer, bool IfMainQuestion, bool IsSearchCache = false, bool IsAdditional = false, bool IsWildCard = false, System::UnicodeString WildCardOrgName = L"");
	void __fastcall ExternalSearch(Iddnsresolver::TIdDNSResolver* ADNSResolver, Iddnscommon::TDNSHeader* Header, Sysutils::TBytes Question, Sysutils::TBytes &Answer);
	System::UnicodeString __fastcall CompleteQuery(Iddnscommon::TDNSHeader* DNSHeader, System::UnicodeString Question, Sysutils::TBytes OriginalQuestion, Sysutils::TBytes &Answer, System::Word QType, System::Word QClass, Iddnsresolver::TIdDNSResolver* DNSResolver);
	void __fastcall SaveToCache(System::UnicodeString ResourceRecord, System::UnicodeString QueryName, System::Word OriginalQType);
	TIdDNTreeNode* __fastcall SearchTree(TIdDNTreeNode* Root, System::UnicodeString QName, System::Word QType);
	virtual void __fastcall Run(void);
	void __fastcall QueryDomain(void);
	void __fastcall SendData(void);
	
public:
	__property Idsockethandle::TIdSocketHandle* MyBinding = {read=FMyBinding, write=SetMyBinding};
	__property Classes::TStream* MyData = {read=FMyData, write=SetMyData};
	__property TIdDNS_UDPServer* Server = {read=FServer, write=SetServer};
	__fastcall TIdDNS_ProcessThread(bool ACreateSuspended, System::UnicodeString Data, int DataSize, Idsockethandle::TIdSocketHandle* MainBinding, Idsockethandle::TIdSocketHandle* Binding, TIdDNS_UDPServer* Server)/* overload */;
	__fastcall virtual ~TIdDNS_ProcessThread(void);
};


typedef void __fastcall (__closure *TIdDNSBeforeQueryEvent)(Idsockethandle::TIdSocketHandle* ABinding, Iddnscommon::TDNSHeader* ADNSHeader, System::UnicodeString &ADNSQuery);

typedef void __fastcall (__closure *TIdDNSAfterQueryEvent)(Idsockethandle::TIdSocketHandle* ABinding, Iddnscommon::TDNSHeader* ADNSHeader, System::UnicodeString &QueryResult, System::UnicodeString ResultCode, System::UnicodeString Query);

typedef void __fastcall (__closure *TIdDNSAfterCacheSaved)(TIdDNTreeNode* CacheRoot);

class PASCALIMPLEMENTATION TIdDNS_UDPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
private:
	bool FBusy;
	
protected:
	bool FAutoUpdateZoneInfo;
	Classes::TStrings* FZoneMasterFiles;
	Classes::TStrings* FRootDNS_NET;
	bool FCacheUnknowZone;
	TIdDNTreeNode* FCached_Tree;
	TIdDNTreeNode* FHanded_Tree;
	Classes::TStrings* FHanded_DomainList;
	bool FAutoLoadMasterFile;
	TIdDNSAfterQueryEvent FOnAfterQuery;
	TIdDNSBeforeQueryEvent FOnBeforeQuery;
	Idglobal::TIdCriticalSection* FCS;
	TIdDNSAfterQueryEvent FOnAfterSendBack;
	TIdDNSAfterCacheSaved FOnAfterCacheSaved;
	Idglobal::TIdCriticalSection* FGlobalCS;
	System::UnicodeString FDNSVersion;
	bool FofferDNSVersion;
	DYNAMIC void __fastcall DoBeforeQuery(Idsockethandle::TIdSocketHandle* ABinding, Iddnscommon::TDNSHeader* ADNSHeader, System::UnicodeString &ADNSQuery);
	DYNAMIC void __fastcall DoAfterQuery(Idsockethandle::TIdSocketHandle* ABinding, Iddnscommon::TDNSHeader* ADNSHeader, System::UnicodeString &QueryResult, System::UnicodeString ResultCode, System::UnicodeString Query);
	DYNAMIC void __fastcall DoAfterSendBack(Idsockethandle::TIdSocketHandle* ABinding, Iddnscommon::TDNSHeader* ADNSHeader, System::UnicodeString &QueryResult, System::UnicodeString ResultCode, System::UnicodeString Query);
	DYNAMIC void __fastcall DoAfterCacheSaved(TIdDNTreeNode* CacheRoot);
	void __fastcall SetZoneMasterFiles(const Classes::TStrings* Value);
	void __fastcall SetRootDNS_NET(const Classes::TStrings* Value);
	void __fastcall SetHanded_DomainList(const Classes::TStrings* Value);
	void __fastcall InternalSearch(Iddnscommon::TDNSHeader* Header, System::UnicodeString QName, System::Word QType, Sysutils::TBytes &Answer, bool IfMainQuestion, bool IsSearchCache = false, bool IsAdditional = false, bool IsWildCard = false, System::UnicodeString WildCardOrgName = L"");
	void __fastcall ExternalSearch(Iddnsresolver::TIdDNSResolver* ADNSResolver, Iddnscommon::TDNSHeader* Header, Sysutils::TBytes Question, Sysutils::TBytes &Answer);
	void __fastcall SaveToCache(System::UnicodeString ResourceRecord, System::UnicodeString QueryName, System::Word OriginalQType);
	virtual void __fastcall InitComponent(void);
	__property bool AutoUpdateZoneInfo = {read=FAutoUpdateZoneInfo, write=FAutoUpdateZoneInfo, nodefault};
	__property Idglobal::TIdCriticalSection* CS = {read=FCS};
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	
public:
	__fastcall virtual ~TIdDNS_UDPServer(void);
	System::UnicodeString __fastcall AXFR(Iddnscommon::TDNSHeader* Header, System::UnicodeString Question, Sysutils::TBytes &Answer);
	System::UnicodeString __fastcall CompleteQuery(Iddnscommon::TDNSHeader* DNSHeader, System::UnicodeString Question, Sysutils::TBytes OriginalQuestion, Sysutils::TBytes &Answer, System::Word QType, System::Word QClass, Iddnsresolver::TIdDNSResolver* DNSResolver);
	bool __fastcall LoadZoneFromMasterFile(System::UnicodeString MasterFileName);
	bool __fastcall LoadZoneStrings(Classes::TStrings* FileStrings, System::UnicodeString Filename, TIdDNTreeNode* TreeRoot);
	TIdDNTreeNode* __fastcall SearchTree(TIdDNTreeNode* Root, System::UnicodeString QName, System::Word QType);
	void __fastcall UpdateTree(TIdDNTreeNode* TreeRoot, Iddnscommon::TIdTextModeResourceRecord* RR)/* overload */;
	System::UnicodeString __fastcall FindNodeFullName(TIdDNTreeNode* Root, System::UnicodeString QName, System::Word QType);
	TIdDNTreeNode* __fastcall FindHandedNodeByName(System::UnicodeString QName, System::Word QType);
	void __fastcall UpdateTree(TIdDNTreeNode* TreeRoot, Iddnsresolver::TResultRecord* RR)/* overload */;
	__property Classes::TStrings* RootDNS_NET = {read=FRootDNS_NET, write=SetRootDNS_NET};
	__property TIdDNTreeNode* Cached_Tree = {read=FCached_Tree};
	__property TIdDNTreeNode* Handed_Tree = {read=FHanded_Tree};
	__property bool Busy = {read=FBusy, nodefault};
	__property Idglobal::TIdCriticalSection* GlobalCS = {read=FGlobalCS};
	
__published:
	__property DefaultPort = {default=53};
	__property bool AutoLoadMasterFile = {read=FAutoLoadMasterFile, write=FAutoLoadMasterFile, default=0};
	__property Classes::TStrings* ZoneMasterFiles = {read=FZoneMasterFiles, write=SetZoneMasterFiles};
	__property bool CacheUnknowZone = {read=FCacheUnknowZone, write=FCacheUnknowZone, default=0};
	__property Classes::TStrings* Handed_DomainList = {read=FHanded_DomainList, write=SetHanded_DomainList};
	__property System::UnicodeString DNSVersion = {read=FDNSVersion, write=FDNSVersion};
	__property bool offerDNSVersion = {read=FofferDNSVersion, write=FofferDNSVersion, nodefault};
	__property TIdDNSBeforeQueryEvent OnBeforeQuery = {read=FOnBeforeQuery, write=FOnBeforeQuery};
	__property TIdDNSAfterQueryEvent OnAfterQuery = {read=FOnAfterQuery, write=FOnAfterQuery};
	__property TIdDNSAfterQueryEvent OnAfterSendBack = {read=FOnAfterSendBack, write=FOnAfterSendBack};
	__property TIdDNSAfterCacheSaved OnAfterCacheSaved = {read=FOnAfterCacheSaved, write=FOnAfterCacheSaved};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDNS_UDPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


class DELPHICLASS TIdDNSServer;
class PASCALIMPLEMENTATION TIdDNSServer : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	bool FActive;
	bool FTCPACLActive;
	Iddnscommon::TDNSServerTypes FServerType;
	TIdDNS_TCPServer* FTCPTunnel;
	TIdDNS_UDPServer* FUDPTunnel;
	Classes::TStrings* FAccessList;
	Idsockethandle::TIdSocketHandles* FBindings;
	void __fastcall SetAccessList(const Classes::TStrings* Value);
	void __fastcall SetActive(const bool Value);
	void __fastcall SetTCPACLActive(const bool Value);
	void __fastcall SetBindings(const Idsockethandle::TIdSocketHandles* Value);
	void __fastcall TimeToUpdateNodeData(System::TObject* Sender);
	virtual void __fastcall InitComponent(void);
	
public:
	TIdDNSMap* BackupDNSMap;
	__fastcall virtual ~TIdDNSServer(void);
	void __fastcall CheckIfExpire(System::TObject* Sender);
	
__published:
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property Classes::TStrings* AccessList = {read=FAccessList, write=SetAccessList};
	__property Idsockethandle::TIdSocketHandles* Bindings = {read=FBindings, write=SetBindings};
	__property bool TCPACLActive = {read=FTCPACLActive, write=SetTCPACLActive, nodefault};
	__property Iddnscommon::TDNSServerTypes ServerType = {read=FServerType, write=FServerType, nodefault};
	__property TIdDNS_TCPServer* TCPTunnel = {read=FTCPTunnel, write=FTCPTunnel};
	__property TIdDNS_UDPServer* UDPTunnel = {read=FUDPTunnel, write=FUDPTunnel};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDNSServer(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall CompareItems(System::TObject* Item1, System::TObject* Item2);
extern PACKAGE int __fastcall PosBytes(const Sysutils::TBytes SubBytes, const Sysutils::TBytes SBytes);
extern PACKAGE Sysutils::TBytes __fastcall FetchBytes(Sysutils::TBytes &AInput, const Sysutils::TBytes ADelim, const bool ADelete = true);

}	/* namespace Iddnsserver */
using namespace Iddnsserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddnsserverHPP
