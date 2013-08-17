// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idlpr.pas' rev: 20.00

#ifndef IdlprHPP
#define IdlprHPP

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
#include <Idexception.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlpr
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdLPRFileFormat { ffCIF, ffDVI, ffFormattedText, ffPlot, ffControlCharText, ffDitroff, ffPostScript, ffPR, ffFORTRAM, ffTroff, ffSunRaster };
#pragma option pop

class DELPHICLASS TIdLPRControlFile;
class PASCALIMPLEMENTATION TIdLPRControlFile : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FBannerClass;
	System::UnicodeString FHostName;
	int FIndentCount;
	System::UnicodeString FJobName;
	bool FBannerPage;
	System::UnicodeString FUserName;
	int FOutputWidth;
	TIdLPRFileFormat FFileFormat;
	System::UnicodeString FTroffRomanFont;
	System::UnicodeString FTroffItalicFont;
	System::UnicodeString FTroffBoldFont;
	System::UnicodeString FTroffSpecialFont;
	bool FMailWhenPrinted;
	
public:
	__fastcall TIdLPRControlFile(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::UnicodeString HostName = {read=FHostName, write=FHostName};
	
__published:
	__property System::UnicodeString BannerClass = {read=FBannerClass, write=FBannerClass};
	__property int IndentCount = {read=FIndentCount, write=FIndentCount, default=0};
	__property System::UnicodeString JobName = {read=FJobName, write=FJobName};
	__property bool BannerPage = {read=FBannerPage, write=FBannerPage, default=0};
	__property System::UnicodeString UserName = {read=FUserName, write=FUserName};
	__property int OutputWidth = {read=FOutputWidth, write=FOutputWidth, default=0};
	__property TIdLPRFileFormat FileFormat = {read=FFileFormat, write=FFileFormat, default=4};
	__property System::UnicodeString TroffRomanFont = {read=FTroffRomanFont, write=FTroffRomanFont};
	__property System::UnicodeString TroffItalicFont = {read=FTroffItalicFont, write=FTroffItalicFont};
	__property System::UnicodeString TroffBoldFont = {read=FTroffBoldFont, write=FTroffBoldFont};
	__property System::UnicodeString TroffSpecialFont = {read=FTroffSpecialFont, write=FTroffSpecialFont};
	__property bool MailWhenPrinted = {read=FMailWhenPrinted, write=FMailWhenPrinted, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdLPRControlFile(void) { }
	
};


#pragma option push -b-
enum TIdLPRStatus { psPrinting, psJobCompleted, psError, psGettingQueueState, psGotQueueState, psDeletingJobs, psJobsDeleted, psPrintingWaitingJobs, psPrintedWaitingJobs };
#pragma option pop

typedef void __fastcall (__closure *TIdLPRStatusEvent)(System::TObject* ASender, const TIdLPRStatus AStatus, const System::UnicodeString AStatusText);

class DELPHICLASS TIdLPR;
class PASCALIMPLEMENTATION TIdLPR : public Idtcpclient::TIdTCPClientCustom
{
	typedef Idtcpclient::TIdTCPClientCustom inherited;
	
protected:
	TIdLPRStatusEvent FOnLPRStatus;
	System::UnicodeString FQueue;
	int FJobId;
	TIdLPRControlFile* FControlFile;
	void __fastcall DoOnLPRStatus(const TIdLPRStatus AStatus, const System::UnicodeString AStatusText);
	void __fastcall SeTIdLPRControlFile(const TIdLPRControlFile* Value);
	void __fastcall CheckReply(void);
	System::UnicodeString __fastcall GetJobId();
	void __fastcall SetJobId(const System::UnicodeString Value);
	void __fastcall InternalPrint(Classes::TStream* Data);
	System::UnicodeString __fastcall GetControlData();
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdLPR(void);
	void __fastcall Print(const System::UnicodeString AText)/* overload */;
	void __fastcall Print(const Sysutils::TBytes ABuffer)/* overload */;
	void __fastcall PrintFile(const System::UnicodeString AFileName);
	System::UnicodeString __fastcall GetQueueState(const bool AShortFormat = false, const System::UnicodeString AList = L"");
	void __fastcall PrintWaitingJobs(void);
	void __fastcall RemoveJobList(const System::UnicodeString AList, const bool AAsRoot = false);
	__property System::UnicodeString JobId = {read=GetJobId, write=SetJobId};
	
__published:
	__property System::UnicodeString Queue = {read=FQueue, write=FQueue};
	__property TIdLPRControlFile* ControlFile = {read=FControlFile, write=SeTIdLPRControlFile};
	__property Host;
	__property Port = {default=515};
	__property TIdLPRStatusEvent OnLPRStatus = {read=FOnLPRStatus, write=FOnLPRStatus};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdLPR(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClientCustom(AOwner) { }
	
};


class DELPHICLASS EIdLPRErrorException;
class PASCALIMPLEMENTATION EIdLPRErrorException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdLPRErrorException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdLPRErrorException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdLPRErrorException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdLPRErrorException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdLPRErrorException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdLPRErrorException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdLPRErrorException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdLPRErrorException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdLPRErrorException(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const TIdLPRFileFormat DEF_FILEFORMAT = (TIdLPRFileFormat)(4);
static const ShortInt DEF_INDENTCOUNT = 0x0;
static const bool DEF_BANNERPAGE = false;
static const ShortInt DEF_OUTPUTWIDTH = 0x0;
static const bool DEF_MAILWHENPRINTED = false;

}	/* namespace Idlpr */
using namespace Idlpr;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdlprHPP
