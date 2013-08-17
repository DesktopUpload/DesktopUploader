// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddnsresolver.pas' rev: 20.00

#ifndef IddnsresolverHPP
#define IddnsresolverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idbuffer.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idnetworkcalculator.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Iddnscommon.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddnsresolver
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TQueryRecordTypes { qtA, qtNS, qtMD, qtMF, qtName, qtSOA, qtMB, qtMG, qtMR, qtNull, qtWKS, qtPTR, qtHINFO, qtMINFO, qtMX, qtTXT, qtRT, qtNSAP, qtNSAP_PTR, qtSIG, qtAAAA, qtService, qtNAPTR, qtCERT, qtV6Addr, qtDName, qtR40, qtOptional, qtIXFR, qtAXFR, qtSTAR };
#pragma option pop

typedef Set<TQueryRecordTypes, qtA, qtSTAR>  TQueryType;

#pragma option push -b-
enum TResultSection { rsAnswer, rsNameServer, rsAdditional };
#pragma option pop

typedef Set<TResultSection, rsAnswer, rsAdditional>  TResultSections;

class DELPHICLASS TResultRecord;
class PASCALIMPLEMENTATION TResultRecord : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	TQueryRecordTypes FRecType;
	System::Word FRecClass;
	System::UnicodeString FName;
	unsigned FTTL;
	int FRDataLength;
	Sysutils::TBytes FRData;
	TResultSection FSection;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	__property TQueryRecordTypes RecType = {read=FRecType, nodefault};
	__property System::Word RecClass = {read=FRecClass, nodefault};
	__property System::UnicodeString Name = {read=FName};
	__property unsigned TTL = {read=FTTL, nodefault};
	__property int RDataLength = {read=FRDataLength, nodefault};
	__property Sysutils::TBytes RData = {read=FRData};
	__property TResultSection Section = {read=FSection, nodefault};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TResultRecord(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TResultRecord(void) { }
	
};


typedef TMetaClass* TResultRecordClass;

class DELPHICLASS TRDATARecord;
class PASCALIMPLEMENTATION TRDATARecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	System::UnicodeString FIPAddress;
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString IPAddress = {read=FIPAddress};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TRDATARecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TRDATARecord(void) { }
	
};


class DELPHICLASS TARecord;
class PASCALIMPLEMENTATION TARecord : public TRDATARecord
{
	typedef TRDATARecord inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TARecord(Classes::TCollection* Collection) : TRDATARecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TARecord(void) { }
	
};


class DELPHICLASS TAAAARecord;
class PASCALIMPLEMENTATION TAAAARecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	System::UnicodeString FAddress;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	__property System::UnicodeString Address = {read=FAddress};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TAAAARecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TAAAARecord(void) { }
	
};


class DELPHICLASS TWKSRecord;
class PASCALIMPLEMENTATION TWKSRecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	int FByteCount;
	Sysutils::TBytes FData;
	System::UnicodeString FIPAddress;
	System::Word FProtocol;
	System::Byte __fastcall GetABit(int AIndex);
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString IPAddress = {read=FIPAddress};
	__property System::Word Protocol = {read=FProtocol, nodefault};
	__property System::Byte BitMap[int index] = {read=GetABit};
	__property int ByteCount = {read=FByteCount, nodefault};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TWKSRecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TWKSRecord(void) { }
	
};


class DELPHICLASS TMXRecord;
class PASCALIMPLEMENTATION TMXRecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	System::UnicodeString FExchangeServer;
	System::Word FPreference;
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString ExchangeServer = {read=FExchangeServer};
	__property System::Word Preference = {read=FPreference, nodefault};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TMXRecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TMXRecord(void) { }
	
};


class DELPHICLASS TTextRecord;
class PASCALIMPLEMENTATION TTextRecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	Classes::TStrings* FText;
	
public:
	__fastcall virtual TTextRecord(Classes::TCollection* Collection);
	__fastcall virtual ~TTextRecord(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	__property Classes::TStrings* Text = {read=FText};
};


class DELPHICLASS TErrorRecord;
class PASCALIMPLEMENTATION TErrorRecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TErrorRecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TErrorRecord(void) { }
	
};


class DELPHICLASS THINFORecord;
class PASCALIMPLEMENTATION THINFORecord : public TTextRecord
{
	typedef TTextRecord inherited;
	
protected:
	System::UnicodeString FCPU;
	System::UnicodeString FOS;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	__property System::UnicodeString CPU = {read=FCPU};
	__property System::UnicodeString OS = {read=FOS};
public:
	/* TTextRecord.Create */ inline __fastcall virtual THINFORecord(Classes::TCollection* Collection) : TTextRecord(Collection) { }
	/* TTextRecord.Destroy */ inline __fastcall virtual ~THINFORecord(void) { }
	
};


class DELPHICLASS TMINFORecord;
class PASCALIMPLEMENTATION TMINFORecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	System::UnicodeString FResponsiblePerson;
	System::UnicodeString FErrorMailbox;
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString ResponsiblePersonMailbox = {read=FResponsiblePerson};
	__property System::UnicodeString ErrorMailbox = {read=FErrorMailbox};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TMINFORecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TMINFORecord(void) { }
	
};


class DELPHICLASS TSOARecord;
class PASCALIMPLEMENTATION TSOARecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	unsigned FSerial;
	unsigned FMinimumTTL;
	unsigned FRefresh;
	unsigned FRetry;
	System::UnicodeString FMNAME;
	System::UnicodeString FRNAME;
	unsigned FExpire;
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString Primary = {read=FMNAME};
	__property System::UnicodeString ResponsiblePerson = {read=FRNAME};
	__property unsigned Serial = {read=FSerial, nodefault};
	__property unsigned Refresh = {read=FRefresh, nodefault};
	__property unsigned Retry = {read=FRetry, nodefault};
	__property unsigned Expire = {read=FExpire, nodefault};
	__property unsigned MinimumTTL = {read=FMinimumTTL, nodefault};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TSOARecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TSOARecord(void) { }
	
};


class DELPHICLASS TNAMERecord;
class PASCALIMPLEMENTATION TNAMERecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
protected:
	System::UnicodeString FHostName;
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString HostName = {read=FHostName};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TNAMERecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TNAMERecord(void) { }
	
};


class DELPHICLASS TNSRecord;
class PASCALIMPLEMENTATION TNSRecord : public TNAMERecord
{
	typedef TNAMERecord inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TNSRecord(Classes::TCollection* Collection) : TNAMERecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TNSRecord(void) { }
	
};


class DELPHICLASS TCNRecord;
class PASCALIMPLEMENTATION TCNRecord : public TNAMERecord
{
	typedef TNAMERecord inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TCNRecord(Classes::TCollection* Collection) : TNAMERecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TCNRecord(void) { }
	
};


class DELPHICLASS TSRVRecord;
class PASCALIMPLEMENTATION TSRVRecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
private:
	System::UnicodeString FService;
	System::UnicodeString FProtocol;
	int FPriority;
	int FWeight;
	int FPort;
	System::UnicodeString FTarget;
	System::UnicodeString FOriginalName;
	bool __fastcall IsValidIdent(const System::UnicodeString aStr);
	System::UnicodeString __fastcall CleanIdent(const System::UnicodeString aStr);
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString OriginalName = {read=FOriginalName};
	__property System::UnicodeString Service = {read=FService};
	__property System::UnicodeString Protocol = {read=FProtocol};
	__property int Priority = {read=FPriority, nodefault};
	__property int Weight = {read=FWeight, nodefault};
	__property int Port = {read=FPort, nodefault};
	__property System::UnicodeString Target = {read=FTarget};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TSRVRecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TSRVRecord(void) { }
	
};


class DELPHICLASS TNAPTRRecord;
class PASCALIMPLEMENTATION TNAPTRRecord : public TResultRecord
{
	typedef TResultRecord inherited;
	
private:
	int FOrder;
	int FPreference;
	System::UnicodeString FFlags;
	System::UnicodeString FService;
	System::UnicodeString FRegExp;
	System::UnicodeString FReplacement;
	
public:
	virtual void __fastcall Parse(Sysutils::TBytes CompleteMessage, int APos);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property int Order = {read=FOrder, nodefault};
	__property int Preference = {read=FPreference, nodefault};
	__property System::UnicodeString Flags = {read=FFlags};
	__property System::UnicodeString Service = {read=FService};
	__property System::UnicodeString RegExp = {read=FRegExp};
	__property System::UnicodeString Replacement = {read=FReplacement};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TNAPTRRecord(Classes::TCollection* Collection) : TResultRecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TNAPTRRecord(void) { }
	
};


class DELPHICLASS TQueryResult;
class PASCALIMPLEMENTATION TQueryResult : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TResultRecord* operator[](int Index) { return Items[Index]; }
	
protected:
	System::UnicodeString FDomainName;
	System::Word FQueryClass;
	System::Word FQueryType;
	Classes::TStringList* FQueryPointerList;
	HIDESBASE void __fastcall SetItem(int Index, TResultRecord* Value);
	HIDESBASE TResultRecord* __fastcall GetItem(int Index);
	
public:
	__fastcall TQueryResult(void);
	__fastcall virtual ~TQueryResult(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	HIDESBASE TResultRecord* __fastcall Add(Sysutils::TBytes Answer, int &APos);
	HIDESBASE void __fastcall Clear(void);
	void __fastcall FilterBySection(const TResultSections AKeep = (TResultSections() << rsAnswer ));
	void __fastcall FilterByClass(const TResultRecordClass AKeep);
	__property System::Word QueryClass = {read=FQueryClass, nodefault};
	__property System::Word QueryType = {read=FQueryType, nodefault};
	__property System::UnicodeString DomainName = {read=FDomainName};
	__property TResultRecord* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


class DELPHICLASS TPTRRecord;
class PASCALIMPLEMENTATION TPTRRecord : public TNAMERecord
{
	typedef TNAMERecord inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TPTRRecord(Classes::TCollection* Collection) : TNAMERecord(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TPTRRecord(void) { }
	
};


class DELPHICLASS TIdDNSResolver;
class PASCALIMPLEMENTATION TIdDNSResolver : public Idtcpconnection::TIdTCPConnection
{
	typedef Idtcpconnection::TIdTCPConnection inherited;
	
protected:
	bool FAllowRecursiveQueries;
	Sysutils::TBytes FInternalQuery;
	int FQuestionLength;
	System::UnicodeString FHost;
	Idglobal::TIdIPVersion FIPVersion;
	System::Word FPort;
	TQueryResult* FQueryResult;
	TQueryType FQueryType;
	int FWaitingTime;
	Sysutils::TBytes FPlainTextResult;
	Iddnscommon::TDNSHeader* FDNSHeader;
	void __fastcall SetInternalQuery(const Sysutils::TBytes Value);
	void __fastcall SetPlainTextResult(const Sysutils::TBytes Value);
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall SetIPVersion(const Idglobal::TIdIPVersion AValue);
	virtual void __fastcall SetPort(const System::Word AValue);
	
public:
	__property Iddnscommon::TDNSHeader* DNSHeader = {read=FDNSHeader};
	void __fastcall ClearInternalQuery(void);
	__fastcall virtual ~TIdDNSResolver(void);
	void __fastcall ParseAnswers(Iddnscommon::TDNSHeader* DNSHeader, Sysutils::TBytes Answer, bool ResetResult = true);
	void __fastcall CreateQuery(System::UnicodeString ADomain, Iddnscommon::TIdRR_SOA* SOARR, int QueryClass = 0x1);
	void __fastcall FillResult(Sysutils::TBytes AResult, bool checkID = true, bool ResetResult = true);
	void __fastcall FillResultWithOutCheckId(System::UnicodeString AResult);
	void __fastcall Resolve(System::UnicodeString ADomain, Iddnscommon::TIdRR_SOA* SOARR = (Iddnscommon::TIdRR_SOA*)(0x0), int QClass = 0x1);
	__property TQueryResult* QueryResult = {read=FQueryResult};
	__property Sysutils::TBytes InternalQuery = {read=FInternalQuery, write=SetInternalQuery};
	__property Sysutils::TBytes PlainTextResult = {read=FPlainTextResult, write=SetPlainTextResult};
	
__published:
	__property TQueryType QueryType = {read=FQueryType, write=FQueryType, nodefault};
	__property int WaitingTime = {read=FWaitingTime, write=FWaitingTime, nodefault};
	__property bool AllowRecursiveQueries = {read=FAllowRecursiveQueries, write=FAllowRecursiveQueries, nodefault};
	__property System::UnicodeString Host = {read=FHost, write=FHost};
	__property System::Word Port = {read=FPort, write=SetPort, default=53};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=SetIPVersion, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDNSResolver(Classes::TComponent* AOwner)/* overload */ : Idtcpconnection::TIdTCPConnection(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt QueryRecordCount = 0x1e;
extern PACKAGE StaticArray<System::Word, 31> QueryRecordValues;
extern PACKAGE StaticArray<TQueryRecordTypes, 31> QueryRecordTypes;
extern PACKAGE System::UnicodeString __fastcall DNSStrToDomain(const Sysutils::TBytes DNSStr, int &VPos);
extern PACKAGE System::UnicodeString __fastcall NextDNSLabel(const Sysutils::TBytes DNSStr, int &VPos);

}	/* namespace Iddnsresolver */
using namespace Iddnsresolver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddnsresolverHPP
