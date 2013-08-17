// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddnscommon.pas' rev: 20.00

#ifndef IddnscommonHPP
#define IddnscommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idcontainers.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idresourcestrings.hpp>	// Pascal unit
#include <Idresourcestringsprotocols.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddnscommon
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<System::UnicodeString, 6> Iddnscommon__1;

#pragma option push -b-
enum TDNSQueryRecordTypes { DqtA, DqtNS, DqtMD, DqtMF, DqtName, DqtSOA, DqtMB, DqtMG, DqtMR, DqtNull, DqtWKS, DqtPTR, DqtHINFO, DqtMINFO, DqtMX, DqtTXT, DqtNSAP, DqtNSAP_PTR, DqtLOC, DqtIXFR, DqtAXFR, DqtSTAR, DqtAAAA };
#pragma option pop

#pragma option push -b-
enum TDNSServerTypes { stPrimary, stSecondary };
#pragma option pop

class DELPHICLASS EIdDNSServerSyncException;
class PASCALIMPLEMENTATION EIdDNSServerSyncException : public Idexception::EIdSilentException
{
	typedef Idexception::EIdSilentException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDNSServerSyncException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdSilentException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDNSServerSyncException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdSilentException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDNSServerSyncException(int Ident)/* overload */ : Idexception::EIdSilentException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDNSServerSyncException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdSilentException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDNSServerSyncException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdSilentException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDNSServerSyncException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdSilentException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDNSServerSyncException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdSilentException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDNSServerSyncException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdSilentException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDNSServerSyncException(void) { }
	
};


class DELPHICLASS EIdDNSServerSettingException;
class PASCALIMPLEMENTATION EIdDNSServerSettingException : public Idexception::EIdSilentException
{
	typedef Idexception::EIdSilentException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDNSServerSettingException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdSilentException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDNSServerSettingException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdSilentException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDNSServerSettingException(int Ident)/* overload */ : Idexception::EIdSilentException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDNSServerSettingException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdSilentException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDNSServerSettingException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdSilentException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDNSServerSettingException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdSilentException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDNSServerSettingException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdSilentException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDNSServerSettingException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdSilentException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDNSServerSettingException(void) { }
	
};


class DELPHICLASS TDNSHeader;
class PASCALIMPLEMENTATION TDNSHeader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Word FID;
	System::Word FBitCode;
	System::Word FQDCount;
	System::Word FANCount;
	System::Word FNSCount;
	System::Word FARCount;
	System::Word __fastcall GetAA(void);
	System::Word __fastcall GetOpCode(void);
	System::Word __fastcall GetQr(void);
	System::Word __fastcall GetRA(void);
	System::Word __fastcall GetRCode(void);
	System::Word __fastcall GetRD(void);
	System::Word __fastcall GetTC(void);
	void __fastcall SetAA(const System::Word Value);
	void __fastcall SetOpCode(const System::Word Value);
	void __fastcall SetQr(const System::Word Value);
	void __fastcall SetRA(const System::Word Value);
	void __fastcall SetRCode(const System::Word Value);
	void __fastcall SetRD(const System::Word Value);
	void __fastcall SetTC(const System::Word Value);
	void __fastcall SetBitCode(const System::Word Value);
	
public:
	__fastcall TDNSHeader(void);
	void __fastcall ClearByteCode(void);
	int __fastcall ParseQuery(Sysutils::TBytes Data);
	Sysutils::TBytes __fastcall GenerateBinaryHeader();
	__property System::Word ID = {read=FID, write=FID, nodefault};
	__property System::Word Qr = {read=GetQr, write=SetQr, nodefault};
	__property System::Word OpCode = {read=GetOpCode, write=SetOpCode, nodefault};
	__property System::Word AA = {read=GetAA, write=SetAA, nodefault};
	__property System::Word TC = {read=GetTC, write=SetTC, nodefault};
	__property System::Word RD = {read=GetRD, write=SetRD, nodefault};
	__property System::Word RA = {read=GetRA, write=SetRA, nodefault};
	__property System::Word RCode = {read=GetRCode, write=SetRCode, nodefault};
	__property System::Word BitCode = {read=FBitCode, write=SetBitCode, nodefault};
	__property System::Word QDCount = {read=FQDCount, write=FQDCount, nodefault};
	__property System::Word ANCount = {read=FANCount, write=FANCount, nodefault};
	__property System::Word NSCount = {read=FNSCount, write=FNSCount, nodefault};
	__property System::Word ARCount = {read=FARCount, write=FARCount, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TDNSHeader(void) { }
	
};


class DELPHICLASS TIdTextModeResourceRecord;
class PASCALIMPLEMENTATION TIdTextModeResourceRecord : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Sysutils::TBytes FAnswer;
	System::UnicodeString FRRName;
	Classes::TStrings* FRRDatas;
	int FTTL;
	int FTypeCode;
	System::UnicodeString FTimeOut;
	System::UnicodeString __fastcall FormatQName(const System::UnicodeString AFullName)/* overload */;
	System::UnicodeString __fastcall FormatQName(const System::UnicodeString AName, const System::UnicodeString AFullName)/* overload */;
	System::UnicodeString __fastcall FormatQNameFull(const System::UnicodeString AFullName);
	Sysutils::TBytes __fastcall FormatRecord(const System::UnicodeString AFullName, const Sysutils::TBytes ARRData);
	void __fastcall SetRRDatas(const Classes::TStrings* Value);
	void __fastcall SetTTL(const int Value);
	
public:
	__fastcall TIdTextModeResourceRecord(const System::UnicodeString ARRName, int ATypeCode);
	__fastcall virtual ~TIdTextModeResourceRecord(void);
	__property int TypeCode = {read=FTypeCode, nodefault};
	__property System::UnicodeString RRName = {read=FRRName, write=FRRName};
	__property Classes::TStrings* RRDatas = {read=FRRDatas, write=SetRRDatas};
	__property int TTL = {read=FTTL, write=SetTTL, nodefault};
	__property System::UnicodeString TimeOut = {read=FTimeOut, write=FTimeOut};
	bool __fastcall ifAddFullName(System::UnicodeString AFullName, System::UnicodeString AGivenName = L"");
	System::AnsiString __fastcall GetValue(const System::UnicodeString AName);
	void __fastcall SetValue(const System::UnicodeString AName, const System::AnsiString AValue);
	int __fastcall ItemCount(void);
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
	void __fastcall ClearAnswer(void);
public:
	/* TObject.Create */ inline __fastcall TIdTextModeResourceRecord(void) : System::TObject() { }
	
};


class DELPHICLASS TIdTextModeRRs;
class PASCALIMPLEMENTATION TIdTextModeRRs : public Idcontainers::TIdObjectList
{
	typedef Idcontainers::TIdObjectList inherited;
	
public:
	TIdTextModeResourceRecord* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TStrings* FItemNames;
	HIDESBASE TIdTextModeResourceRecord* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdTextModeResourceRecord* Value);
	void __fastcall SetItemNames(const Classes::TStrings* Value);
	
public:
	__fastcall TIdTextModeRRs(void);
	__fastcall virtual ~TIdTextModeRRs(void);
	__property Classes::TStrings* ItemNames = {read=FItemNames, write=SetItemNames};
	__property TIdTextModeResourceRecord* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


class DELPHICLASS TIdRR_CName;
class PASCALIMPLEMENTATION TIdRR_CName : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetCName();
	void __fastcall SetCName(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_CName(void);
	__property System::AnsiString CName = {read=GetCName, write=SetCName};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_CName(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_CName(void) { }
	
};


class DELPHICLASS TIdRR_HINFO;
class PASCALIMPLEMENTATION TIdRR_HINFO : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	void __fastcall SetCPU(const System::AnsiString Value);
	System::AnsiString __fastcall GetCPU();
	System::AnsiString __fastcall GetOS();
	void __fastcall SetOS(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_HINFO(void);
	__property System::AnsiString CPU = {read=GetCPU, write=SetCPU};
	__property System::AnsiString OS = {read=GetOS, write=SetOS};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_HINFO(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_HINFO(void) { }
	
};


class DELPHICLASS TIdRR_MB;
class PASCALIMPLEMENTATION TIdRR_MB : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetMADName();
	void __fastcall SetMADName(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_MB(void);
	__property System::AnsiString MADName = {read=GetMADName, write=SetMADName};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_MB(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_MB(void) { }
	
};


class DELPHICLASS TIdRR_MG;
class PASCALIMPLEMENTATION TIdRR_MG : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetMGMName();
	void __fastcall SetMGMName(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_MG(void);
	__property System::AnsiString MGMName = {read=GetMGMName, write=SetMGMName};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_MG(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_MG(void) { }
	
};


class DELPHICLASS TIdRR_MINFO;
class PASCALIMPLEMENTATION TIdRR_MINFO : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	void __fastcall SetErrorHandle_Mail(const System::AnsiString Value);
	void __fastcall SetResponsible_Mail(const System::AnsiString Value);
	System::AnsiString __fastcall GetEMail();
	System::AnsiString __fastcall GetRMail();
	
public:
	__fastcall TIdRR_MINFO(void);
	__property System::AnsiString Responsible_Mail = {read=GetRMail, write=SetResponsible_Mail};
	__property System::AnsiString ErrorHandle_Mail = {read=GetEMail, write=SetErrorHandle_Mail};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_MINFO(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_MINFO(void) { }
	
};


class DELPHICLASS TIdRR_MR;
class PASCALIMPLEMENTATION TIdRR_MR : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetNewName();
	void __fastcall SetNewName(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_MR(void);
	__property System::AnsiString NewName = {read=GetNewName, write=SetNewName};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_MR(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_MR(void) { }
	
};


class DELPHICLASS TIdRR_MX;
class PASCALIMPLEMENTATION TIdRR_MX : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetExchang();
	void __fastcall SetExchange(const System::AnsiString Value);
	System::AnsiString __fastcall GetPref();
	void __fastcall SetPref(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_MX(void);
	__property System::AnsiString Exchange = {read=GetExchang, write=SetExchange};
	__property System::AnsiString Preference = {read=GetPref, write=SetPref};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_MX(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_MX(void) { }
	
};


class DELPHICLASS TIdRR_NS;
class PASCALIMPLEMENTATION TIdRR_NS : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetNS();
	void __fastcall SetNS(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_NS(void);
	__property System::AnsiString NSDName = {read=GetNS, write=SetNS};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_NS(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_NS(void) { }
	
};


class DELPHICLASS TIdRR_PTR;
class PASCALIMPLEMENTATION TIdRR_PTR : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetPTRName();
	void __fastcall SetPTRName(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_PTR(void);
	__property System::AnsiString PTRDName = {read=GetPTRName, write=SetPTRName};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_PTR(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_PTR(void) { }
	
};


class DELPHICLASS TIdRR_SOA;
class PASCALIMPLEMENTATION TIdRR_SOA : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetName(const System::UnicodeString CLabel);
	void __fastcall SetName(const System::UnicodeString CLabel, const System::AnsiString Value);
	System::AnsiString __fastcall GetMName();
	System::AnsiString __fastcall GetRName();
	void __fastcall SetMName(const System::AnsiString Value);
	void __fastcall SetRName(const System::AnsiString Value);
	System::AnsiString __fastcall GetMin();
	System::AnsiString __fastcall GetRefresh();
	System::AnsiString __fastcall GetRetry();
	System::AnsiString __fastcall GetSerial();
	void __fastcall SetMin(const System::AnsiString Value);
	void __fastcall SetRefresh(const System::AnsiString Value);
	void __fastcall SetRetry(const System::AnsiString Value);
	void __fastcall SetSerial(const System::AnsiString Value);
	System::AnsiString __fastcall GetExpire();
	void __fastcall SetExpire(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_SOA(void);
	__property System::AnsiString MName = {read=GetMName, write=SetMName};
	__property System::AnsiString RName = {read=GetRName, write=SetRName};
	__property System::AnsiString Serial = {read=GetSerial, write=SetSerial};
	__property System::AnsiString Refresh = {read=GetRefresh, write=SetRefresh};
	__property System::AnsiString Retry = {read=GetRetry, write=SetRetry};
	__property System::AnsiString Expire = {read=GetExpire, write=SetExpire};
	__property System::AnsiString Minimum = {read=GetMin, write=SetMin};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_SOA(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_SOA(void) { }
	
};


class DELPHICLASS TIdRR_A;
class PASCALIMPLEMENTATION TIdRR_A : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetA();
	void __fastcall SetA(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_A(void);
	__property System::AnsiString Address = {read=GetA, write=SetA};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_A(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_A(void) { }
	
};


class DELPHICLASS TIdRR_AAAA;
class PASCALIMPLEMENTATION TIdRR_AAAA : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetA();
	void __fastcall SetA(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_AAAA(void);
	__property System::AnsiString Address = {read=GetA, write=SetA};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_AAAA(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_AAAA(void) { }
	
};


class DELPHICLASS TIdRR_WKS;
class PASCALIMPLEMENTATION TIdRR_WKS : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
public:
	__fastcall TIdRR_WKS(void);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_WKS(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_WKS(void) { }
	
};


class DELPHICLASS TIdRR_TXT;
class PASCALIMPLEMENTATION TIdRR_TXT : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
protected:
	System::AnsiString __fastcall GetTXT();
	void __fastcall SetTXT(const System::AnsiString Value);
	
public:
	__fastcall TIdRR_TXT(void);
	__property System::AnsiString TXT = {read=GetTXT, write=SetTXT};
	virtual Sysutils::TBytes __fastcall BinQueryRecord(System::UnicodeString AFullName);
	virtual System::UnicodeString __fastcall TextRecord(System::UnicodeString AFullName);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_TXT(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_TXT(void) { }
	
};


class DELPHICLASS TIdRR_Error;
class PASCALIMPLEMENTATION TIdRR_Error : public TIdTextModeResourceRecord
{
	typedef TIdTextModeResourceRecord inherited;
	
public:
	__fastcall TIdRR_Error(void);
public:
	/* TIdTextModeResourceRecord.CreateInit */ inline __fastcall TIdRR_Error(const System::UnicodeString ARRName, int ATypeCode) : TIdTextModeResourceRecord(ARRName, ATypeCode) { }
	/* TIdTextModeResourceRecord.Destroy */ inline __fastcall virtual ~TIdRR_Error(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define IdDNSServerVersion L"Indy DNSServer 20040121301"
static const ShortInt cRCodeNoError = 0x0;
static const ShortInt cRCodeFormatErr = 0x1;
static const ShortInt cRCodeServerErr = 0x2;
static const ShortInt cRCodeNameErr = 0x3;
static const ShortInt cRCodeNotImplemented = 0x4;
static const ShortInt cRCodeRefused = 0x5;
static const ShortInt iRCodeQueryNotImplement = 0x0;
static const ShortInt iRCodeQueryReturned = 0x1;
static const ShortInt iRCodeQueryOK = 0x2;
static const ShortInt iRCodeQueryNotFound = 0x3;
static const ShortInt iRCodeNoError = 0x0;
static const ShortInt iRCodeFormatError = 0x1;
static const ShortInt iRCodeServerFailure = 0x2;
static const ShortInt iRCodeNameError = 0x3;
static const ShortInt iRCodeNotImplemented = 0x4;
static const ShortInt iRCodeRefused = 0x5;
static const ShortInt iQr_Question = 0x0;
static const ShortInt iQr_Answer = 0x1;
static const ShortInt iAA_NotAuthoritative = 0x0;
static const ShortInt iAA_Authoritative = 0x1;
#define cRCodeQueryNotImplement L"NA"
#define cRCodeQueryReturned L"RC"
#define cRCodeQueryOK L"OK"
#define cRCodeQueryCacheOK L"COK"
#define cRCodeQueryNotFound L"NOTFOUND"
#define cRCodeQueryCacheFindError L"CFoundError"
#define RSDNSServerAXFRError_QuerySequenceError L"First record must be SOA!"
#define RSDNSServerSettingError_MappingHostError L"Host must be an IP address"
#define cOrigin L"$ORIGIN"
#define cInclude L"$INCLUDE"
#define cAAAA L"AAAA"
static const WideChar cAt = (WideChar)(0x40);
static const WideChar cA = (WideChar)(0x41);
#define cNS L"NS"
#define cMD L"MD"
#define cMF L"MF"
#define cCName L"CNAME"
#define cSOA L"SOA"
#define cMB L"MB"
#define cMG L"MG"
#define cMR L"MR"
#define cNULL L"NULL"
#define cWKS L"WKS"
#define cPTR L"PTR"
#define cHINFO L"HINFO"
#define cMINFO L"MINFO"
#define cMX L"MX"
#define cTXT L"TXT"
#define cNSAP L"NSAP"
#define cNSAP_PTR L"NSAP-PTR"
#define cLOC L"LOC"
#define cAXFR L"AXFR"
#define cIXFR L"IXFR"
#define cSTAR L"STAR"
extern PACKAGE Iddnscommon__1 cRCodeStrs;
static const ShortInt Class_IN = 0x1;
static const ShortInt Class_CHAOS = 0x3;
static const ShortInt TypeCode_A = 0x1;
static const ShortInt TypeCode_NS = 0x2;
static const ShortInt TypeCode_MD = 0x3;
static const ShortInt TypeCode_MF = 0x4;
static const ShortInt TypeCode_CName = 0x5;
static const ShortInt TypeCode_SOA = 0x6;
static const ShortInt TypeCode_MB = 0x7;
static const ShortInt TypeCode_MG = 0x8;
static const ShortInt TypeCode_MR = 0x9;
static const ShortInt TypeCode_NULL = 0xa;
static const ShortInt TypeCode_WKS = 0xb;
static const ShortInt TypeCode_PTR = 0xc;
static const ShortInt TypeCode_HINFO = 0xd;
static const ShortInt TypeCode_MINFO = 0xe;
static const ShortInt TypeCode_MX = 0xf;
static const ShortInt TypeCode_TXT = 0x10;
static const ShortInt TypeCode_RP = 0x11;
static const ShortInt TypeCode_AFSDB = 0x12;
static const ShortInt TypeCode_X25 = 0x13;
static const ShortInt TypeCode_ISDN = 0x14;
static const ShortInt TypeCode_RT = 0x15;
static const ShortInt TypeCode_NSAP = 0x16;
static const ShortInt TypeCode_NSAP_PTR = 0x17;
static const ShortInt TypeCode_SIG = 0x18;
static const ShortInt TypeCode_KEY = 0x19;
static const ShortInt TypeCode_PX = 0x1a;
static const ShortInt TypeCode_QPOS = 0x1b;
static const ShortInt TypeCode_AAAA = 0x1c;
static const ShortInt TypeCode_LOC = 0x1d;
static const ShortInt TypeCode_NXT = 0x1e;
static const ShortInt TypeCode_R31 = 0x1f;
static const ShortInt TypeCode_R32 = 0x20;
static const ShortInt TypeCode_Service = 0x21;
static const ShortInt TypeCode_R34 = 0x22;
static const ShortInt TypeCode_NAPTR = 0x23;
static const ShortInt TypeCode_KX = 0x24;
static const ShortInt TypeCode_CERT = 0x25;
static const ShortInt TypeCode_V6Addr = 0x26;
static const ShortInt TypeCode_DNAME = 0x27;
static const ShortInt TypeCode_R40 = 0x28;
static const ShortInt TypeCode_OPTIONAL = 0x29;
static const Byte TypeCode_IXFR = 0xfb;
static const Byte TypeCode_AXFR = 0xfc;
static const Byte TypeCode_STAR = 0xff;
static const ShortInt TypeCode_Error = 0x0;
extern PACKAGE Sysutils::TBytes __fastcall DomainNameToDNSStr(const System::AnsiString ADomain)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall DomainNameToDNSStr(const System::UnicodeString ADomain)/* overload */;
extern PACKAGE Sysutils::TBytes __fastcall NormalStrToDNSStr(const System::UnicodeString Str);
extern PACKAGE Sysutils::TBytes __fastcall IPAddrToDNSStr(const System::UnicodeString IPAddress);
extern PACKAGE Sysutils::TBytes __fastcall IPv6AAAAToDNSStr(const System::UnicodeString AIPv6Address);
extern PACKAGE bool __fastcall IsValidIPv6(const System::UnicodeString v6Address);
extern PACKAGE System::UnicodeString __fastcall ConvertToValidv6IP(const System::UnicodeString OrgIP);
extern PACKAGE System::UnicodeString __fastcall ConvertToCanonical6IP(const System::UnicodeString OrgIP);
extern PACKAGE System::UnicodeString __fastcall GetErrorStr(const int Code, const int Id);
extern PACKAGE System::UnicodeString __fastcall GetRCodeStr(int RCode);
extern PACKAGE System::UnicodeString __fastcall ReplaceSpecString(System::UnicodeString Source, System::UnicodeString Target, System::UnicodeString NewString, bool ReplaceAll = true);
extern PACKAGE bool __fastcall IsBig5(System::WideChar ch1, System::WideChar ch2);

}	/* namespace Iddnscommon */
using namespace Iddnscommon;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddnscommonHPP
