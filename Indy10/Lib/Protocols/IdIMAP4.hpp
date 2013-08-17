// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idimap4.pas' rev: 20.00

#ifndef Idimap4HPP
#define Idimap4HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idmailbox.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idmessageparts.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idmessagecoder.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idcoderheader.hpp>	// Pascal unit
#include <Idcodermime.hpp>	// Pascal unit
#include <Idcoderquotedprintable.hpp>	// Pascal unit
#include <Idcoderbinhex4.hpp>	// Pascal unit
#include <Idsaslcollection.hpp>	// Pascal unit
#include <Idmessagecollection.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idimap4
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EmUTF7Error;
class PASCALIMPLEMENTATION EmUTF7Error : public Idexception::EIdSilentException
{
	typedef Idexception::EIdSilentException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EmUTF7Error(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdSilentException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EmUTF7Error(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdSilentException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EmUTF7Error(int Ident)/* overload */ : Idexception::EIdSilentException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EmUTF7Error(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdSilentException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EmUTF7Error(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdSilentException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EmUTF7Error(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdSilentException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EmUTF7Error(int Ident, int AHelpContext)/* overload */ : Idexception::EIdSilentException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EmUTF7Error(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdSilentException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EmUTF7Error(void) { }
	
};


class DELPHICLASS EmUTF7Encode;
class PASCALIMPLEMENTATION EmUTF7Encode : public EmUTF7Error
{
	typedef EmUTF7Error inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EmUTF7Encode(const System::UnicodeString AMsg)/* overload */ : EmUTF7Error(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EmUTF7Encode(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EmUTF7Error(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EmUTF7Encode(int Ident)/* overload */ : EmUTF7Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EmUTF7Encode(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EmUTF7Error(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EmUTF7Encode(const System::UnicodeString Msg, int AHelpContext) : EmUTF7Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EmUTF7Encode(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EmUTF7Error(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EmUTF7Encode(int Ident, int AHelpContext)/* overload */ : EmUTF7Error(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EmUTF7Encode(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EmUTF7Error(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EmUTF7Encode(void) { }
	
};


class DELPHICLASS EmUTF7Decode;
class PASCALIMPLEMENTATION EmUTF7Decode : public EmUTF7Error
{
	typedef EmUTF7Error inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EmUTF7Decode(const System::UnicodeString AMsg)/* overload */ : EmUTF7Error(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EmUTF7Decode(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EmUTF7Error(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EmUTF7Decode(int Ident)/* overload */ : EmUTF7Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EmUTF7Decode(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EmUTF7Error(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EmUTF7Decode(const System::UnicodeString Msg, int AHelpContext) : EmUTF7Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EmUTF7Decode(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EmUTF7Error(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EmUTF7Decode(int Ident, int AHelpContext)/* overload */ : EmUTF7Error(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EmUTF7Decode(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EmUTF7Error(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EmUTF7Decode(void) { }
	
};


class DELPHICLASS TIdMUTF7;
class PASCALIMPLEMENTATION TIdMUTF7 : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString __fastcall Encode(System::UnicodeString aString);
	System::UnicodeString __fastcall Decode(System::UnicodeString aString);
	bool __fastcall Valid(System::UnicodeString aMUTF7String);
	System::UnicodeString __fastcall Append(const System::UnicodeString aMUTF7String, const System::UnicodeString aAnsiStr);
public:
	/* TObject.Create */ inline __fastcall TIdMUTF7(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdMUTF7(void) { }
	
};


#pragma option push -b-
enum TIdIMAP4FolderTreatment { ftAllowsTopLevelCreation, ftFoldersMustBeUnderInbox, ftDoesNotAllowFolderCreation, ftCannotTestBecauseHasNoInbox, ftCannotRetrieveAnyFolders };
#pragma option pop

#pragma option push -b-
enum TIdIMAP4AuthenticationType { iatUserPass, iatSASL };
#pragma option pop

class DELPHICLASS TIdImapMessagePart;
class PASCALIMPLEMENTATION TIdImapMessagePart : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FBodyType;
	System::UnicodeString FBodySubType;
	System::UnicodeString FFileName;
	System::UnicodeString FDescription;
	Idmessage::TIdMessageEncoding FEncoding;
	System::UnicodeString FContentTransferEncoding;
	int FSize;
	System::UnicodeString FUnparsedEntry;
	System::UnicodeString FBoundary;
	int FParentPart;
	System::UnicodeString FImapPartNumber;
	
public:
	__fastcall virtual TIdImapMessagePart(Classes::TCollection* Collection);
	__property System::UnicodeString BodyType = {read=FBodyType, write=FBodyType};
	__property System::UnicodeString BodySubType = {read=FBodySubType, write=FBodySubType};
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
	__property System::UnicodeString Description = {read=FDescription, write=FDescription};
	__property Idmessage::TIdMessageEncoding Encoding = {read=FEncoding, write=FEncoding, nodefault};
	__property System::UnicodeString ContentTransferEncoding = {read=FContentTransferEncoding, write=FContentTransferEncoding};
	__property int Size = {read=FSize, write=FSize, nodefault};
	__property System::UnicodeString UnparsedEntry = {read=FUnparsedEntry, write=FUnparsedEntry};
	__property System::UnicodeString Boundary = {read=FBoundary, write=FBoundary};
	__property int ParentPart = {read=FParentPart, write=FParentPart, nodefault};
	__property System::UnicodeString ImapPartNumber = {read=FImapPartNumber, write=FImapPartNumber};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdImapMessagePart(void) { }
	
};


class DELPHICLASS EIdNumberInvalid;
class PASCALIMPLEMENTATION EIdNumberInvalid : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNumberInvalid(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNumberInvalid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNumberInvalid(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNumberInvalid(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNumberInvalid(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNumberInvalid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNumberInvalid(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNumberInvalid(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNumberInvalid(void) { }
	
};


class DELPHICLASS EIdDisconnectedProbablyIdledOut;
class PASCALIMPLEMENTATION EIdDisconnectedProbablyIdledOut : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdDisconnectedProbablyIdledOut(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdDisconnectedProbablyIdledOut(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdDisconnectedProbablyIdledOut(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdDisconnectedProbablyIdledOut(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdDisconnectedProbablyIdledOut(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDisconnectedProbablyIdledOut(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdDisconnectedProbablyIdledOut(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDisconnectedProbablyIdledOut(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdDisconnectedProbablyIdledOut(void) { }
	
};


class DELPHICLASS TIdImapMessageParts;
class PASCALIMPLEMENTATION TIdImapMessageParts : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdImapMessagePart* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdImapMessagePart* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdImapMessagePart* Value);
	
public:
	HIDESBASE TIdImapMessagePart* __fastcall Add(void);
	__property TIdImapMessagePart* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TIdImapMessageParts(Classes::TPersistent* AOwner, Classes::TCollectionItemClass ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdImapMessageParts(void) { }
	
};


class DELPHICLASS TIdIMAPLineStruct;
class PASCALIMPLEMENTATION TIdIMAPLineStruct : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool HasStar;
	System::UnicodeString MessageNumber;
	System::UnicodeString Command;
	System::UnicodeString UID;
	Idmessage::TIdMessageFlagsSet Flags;
	bool Complete;
	int ByteCount;
	System::UnicodeString IMAPFunction;
	System::UnicodeString IMAPValue;
public:
	/* TObject.Create */ inline __fastcall TIdIMAPLineStruct(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdIMAPLineStruct(void) { }
	
};


#pragma option push -b-
enum TIdIMAP4Commands { cmdCAPABILITY, cmdNOOP, cmdLOGOUT, cmdAUTHENTICATE, cmdLOGIN, cmdSELECT, cmdEXAMINE, cmdCREATE, cmdDELETE, cmdRENAME, cmdSUBSCRIBE, cmdUNSUBSCRIBE, cmdLIST, cmdLSUB, cmdSTATUS, cmdAPPEND, cmdCHECK, cmdCLOSE, cmdEXPUNGE, cmdSEARCH, cmdFETCH, cmdSTORE, cmdCOPY, cmdUID, cmdXCmd };
#pragma option pop

#pragma option push -b-
enum TIdIMAP4ConnectionState { csAny, csNonAuthenticated, csAuthenticated, csSelected, csUnexpectedlyDisconnected };
#pragma option pop

#pragma option push -b-
enum TIdIMAP4SearchKey { skAll, skAnswered, skBcc, skBefore, skBody, skCc, skDeleted, skDraft, skFlagged, skFrom, skHeader, skKeyword, skLarger, skNew, skNot, skOld, skOn, skOr, skRecent, skSeen, skSentBefore, skSentOn, skSentSince, skSince, skSmaller, skSubject, skText, skTo, skUID, skUnanswered, skUndeleted, skUndraft, skUnflagged, skUnKeyWord, skUnseen };
#pragma option pop

typedef DynamicArray<TIdIMAP4SearchKey> TIdIMAP4SearchKeyArray;

struct TIdIMAP4SearchRec
{
	
public:
	System::TDateTime Date;
	int Size;
	System::UnicodeString Text;
	TIdIMAP4SearchKey SearchKey;
};


typedef DynamicArray<TIdIMAP4SearchRec> TIdIMAP4SearchRecArray;

#pragma option push -b-
enum TIdIMAP4StatusDataItem { mdMessages, mdRecent, mdUIDNext, mdUIDValidity, mdUnseen };
#pragma option pop

#pragma option push -b-
enum TIdIMAP4StoreDataItem { sdReplace, sdReplaceSilent, sdAdd, sdAddSilent, sdRemove, sdRemoveSilent };
#pragma option pop

#pragma option push -b-
enum TIdRetrieveOnSelect { rsDisabled, rsHeaders, rsMessages };
#pragma option pop

typedef void __fastcall (__closure *TIdAlertEvent)(System::TObject* ASender, const System::UnicodeString AAlertMsg);

class DELPHICLASS TIdIMAP4;
class PASCALIMPLEMENTATION TIdIMAP4 : public Idmessageclient::TIdMessageClient
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	int FCmdCounter;
	TIdIMAP4ConnectionState FConnectionState;
	Idmailbox::TIdMailBox* FMailBox;
	System::WideChar FMailBoxSeparator;
	TIdAlertEvent FOnAlert;
	TIdRetrieveOnSelect FRetrieveOnSelect;
	int FMilliSecsToWaitToClearBuffer;
	TIdMUTF7* FMUTF7;
	Idcomponent::TWorkEvent FOnWorkForPart;
	Idcomponent::TWorkBeginEvent FOnWorkBeginForPart;
	Idcomponent::TWorkEndEvent FOnWorkEndForPart;
	System::UnicodeString FGreetingBanner;
	bool FHasCapa;
	Idsaslcollection::TIdSASLEntries* FSASLMechanisms;
	TIdIMAP4AuthenticationType FAuthType;
	Classes::TStrings* FCapabilities;
	TIdIMAPLineStruct* FLineStruct;
	virtual Idreply::TIdReplyClass __fastcall GetReplyClass(void);
	TIdIMAP4ConnectionState __fastcall CheckConnectionState(TIdIMAP4ConnectionState AAllowedState)/* overload */;
	TIdIMAP4ConnectionState __fastcall CheckConnectionState(TIdIMAP4ConnectionState const *AAllowedStates, const int AAllowedStates_Size)/* overload */;
	void __fastcall BeginWorkForPart(System::TObject* ASender, Idcomponent::TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall DoWorkForPart(System::TObject* ASender, Idcomponent::TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall EndWorkForPart(System::TObject* ASender, Idcomponent::TWorkMode AWorkMode);
	System::UnicodeString __fastcall DoMUTFEncode(System::UnicodeString aString);
	System::UnicodeString __fastcall DoMUTFDecode(System::UnicodeString aString);
	System::UnicodeString __fastcall GetCmdCounter();
	System::UnicodeString __fastcall GetConnectionStateName();
	System::UnicodeString __fastcall GetNewCmdCounter();
	__property System::UnicodeString LastCmdCounter = {read=GetCmdCounter};
	__property System::UnicodeString NewCmdCounter = {read=GetNewCmdCounter};
	System::UnicodeString __fastcall ArrayToNumberStr(int const *AMsgNumList, const int AMsgNumList_Size);
	System::UnicodeString __fastcall MessageFlagSetToStr(const Idmessage::TIdMessageFlagsSet AFlags);
	System::UnicodeString __fastcall DateToIMAPDateStr(const System::TDateTime ADate);
	virtual void __fastcall StripCRLFs(System::UnicodeString &AText)/* overload */;
	void __fastcall StripCRLFs(Classes::TStream* ASourceStream, Classes::TStream* ADestStream)/* overload */;
	void __fastcall ParseImapPart(System::UnicodeString ABodyStructure, TIdImapMessageParts* AImapParts, TIdImapMessagePart* AThisImapPart, TIdImapMessagePart* AParentImapPart, int APartNumber);
	void __fastcall ParseMessagePart(System::UnicodeString ABodyStructure, Idmessageparts::TIdMessageParts* AMessageParts, Idmessageparts::TIdMessagePart* AThisMessagePart, Idmessageparts::TIdMessagePart* AParentMessagePart, int APartNumber);
	void __fastcall ParseBodyStructureResult(System::UnicodeString ABodyStructure, Idmessageparts::TIdMessageParts* ATheParts, TIdImapMessageParts* AImapParts);
	void __fastcall ParseBodyStructurePart(System::UnicodeString APartString, Idmessageparts::TIdMessagePart* AThePart, TIdImapMessagePart* AImapPart);
	void __fastcall ParseTheLine(System::UnicodeString ALine, Classes::TStrings* APartsList);
	void __fastcall ParseIntoParts(System::UnicodeString APartString, Classes::TStrings* AParams);
	void __fastcall ParseIntoBrackettedQuotedAndUnquotedParts(System::UnicodeString APartString, Classes::TStrings* AParams, bool AKeepBrackets);
	void __fastcall BreakApartParamsInQuotes(const System::UnicodeString AParam, Classes::TStrings* AParsedList);
	System::UnicodeString __fastcall GetNextWord(System::UnicodeString AParam);
	System::UnicodeString __fastcall GetNextQuotedParam(System::UnicodeString AParam, bool ARemoveQuotes);
	void __fastcall ParseExpungeResult(Idmailbox::TIdMailBox* AMB, Classes::TStrings* ACmdResultDetails);
	void __fastcall ParseListResult(Classes::TStrings* AMBList, Classes::TStrings* ACmdResultDetails);
	void __fastcall ParseLSubResult(Classes::TStrings* AMBList, Classes::TStrings* ACmdResultDetails);
	void __fastcall InternalParseListResult(System::UnicodeString ACmd, Classes::TStrings* AMBList, Classes::TStrings* ACmdResultDetails);
	void __fastcall ParseMailBoxAttributeString(System::UnicodeString AAttributesList, Idmailbox::TIdMailBoxAttributesSet &AAttributes);
	void __fastcall ParseMessageFlagString(System::UnicodeString AFlagsList, Idmessage::TIdMessageFlagsSet &AFlags);
	void __fastcall ParseSelectResult(Idmailbox::TIdMailBox* AMB, Classes::TStrings* ACmdResultDetails);
	void __fastcall ParseStatusResult(Idmailbox::TIdMailBox* AMB, Classes::TStrings* ACmdResultDetails);
	void __fastcall ParseSearchResult(Idmailbox::TIdMailBox* AMB, Classes::TStrings* ACmdResultDetails);
	void __fastcall ParseEnvelopeResult(Idmessage::TIdMessage* AMsg, System::UnicodeString ACmdResultStr);
	bool __fastcall ParseLastCmdResult(System::UnicodeString ALine, System::UnicodeString AExpectedCommand, System::UnicodeString *AExpectedIMAPFunction, const int AExpectedIMAPFunction_Size);
	void __fastcall ParseLastCmdResultButAppendInfo(System::UnicodeString ALine);
	bool __fastcall InternalRetrieve(const int AMsgNum, bool AUseUID, bool AUsePeek, Idmessage::TIdMessage* AMsg);
	bool __fastcall InternalRetrievePart(const int AMsgNum, const System::UnicodeString APartNum, bool AUseUID, bool AUsePeek, Classes::TStream* ADestStream, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString ADestFileNameAndPath = L"", System::UnicodeString AContentTransferEncoding = L"text");
	System::UnicodeString __fastcall ParseBodyStructureSectionAsEquates(System::UnicodeString AParam);
	System::UnicodeString __fastcall ParseBodyStructureSectionAsEquates2(System::UnicodeString AParam);
	bool __fastcall InternalRetrieveText(const int AMsgNum, System::UnicodeString &AText, bool AUseUID, bool AUsePeek, bool AUseFirstPartInsteadOfText);
	bool __fastcall IsCapabilityListed(System::UnicodeString ACapability);
	bool __fastcall InternalRetrieveEnvelope(const int AMsgNum, Idmessage::TIdMessage* AMsg, Classes::TStrings* ADestList);
	bool __fastcall UIDInternalRetrieveEnvelope(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg, Classes::TStrings* ADestList);
	bool __fastcall InternalRetrievePartHeader(const int AMsgNum, const System::UnicodeString APartNum, const bool AUseUID, Idheaderlist::TIdHeaderList* AHeaders);
	virtual System::UnicodeString __fastcall ReceiveHeader(Idmessage::TIdMessage* AMsg, const System::UnicodeString AAltTerm = L"");
	bool __fastcall IsNumberValid(const int ANumber);
	bool __fastcall IsUIDValid(const System::UnicodeString AUID);
	bool __fastcall IsImapPartNumberValid(const System::UnicodeString AUID);
	bool __fastcall IsItDigitsAndOptionallyPeriod(const System::UnicodeString AStr, bool AAllowPeriod);
	virtual void __fastcall ReceiveBody(Idmessage::TIdMessage* AMsg, const System::UnicodeString ADelim = L".");
	virtual void __fastcall InitComponent(void);
	void __fastcall SetMailBox(const Idmailbox::TIdMailBox* Value);
	void __fastcall SetSASLMechanisms(Idsaslcollection::TIdSASLEntries* AValue);
	
public:
	__fastcall virtual ~TIdIMAP4(void);
	bool __fastcall Capability(Classes::TStrings* ASlCapability)/* overload */;
	TIdIMAP4FolderTreatment __fastcall FindHowServerCreatesFolders(void);
	void __fastcall DoAlert(const System::UnicodeString AMsg);
	__property TIdIMAP4ConnectionState ConnectionState = {read=FConnectionState, nodefault};
	__property Idmailbox::TIdMailBox* MailBox = {read=FMailBox, write=SetMailBox};
	bool __fastcall AppendMsg(const System::UnicodeString AMBName, Idmessage::TIdMessage* AMsg, const Idmessage::TIdMessageFlagsSet AFlags = Idmessage::TIdMessageFlagsSet() )/* overload */;
	bool __fastcall AppendMsg(const System::UnicodeString AMBName, Idmessage::TIdMessage* AMsg, Idheaderlist::TIdHeaderList* AAlternativeHeaders, const Idmessage::TIdMessageFlagsSet AFlags = Idmessage::TIdMessageFlagsSet() )/* overload */;
	bool __fastcall AppendMsgNoEncodeFromFile(const System::UnicodeString AMBName, System::UnicodeString ASourceFile, const Idmessage::TIdMessageFlagsSet AFlags = Idmessage::TIdMessageFlagsSet() );
	bool __fastcall AppendMsgNoEncodeFromStream(const System::UnicodeString AMBName, Classes::TStream* AStream, const Idmessage::TIdMessageFlagsSet AFlags = Idmessage::TIdMessageFlagsSet() );
	bool __fastcall CheckMailBox(void);
	bool __fastcall CheckMsgSeen(const int AMsgNum);
	virtual void __fastcall Login(void);
	HIDESBASE virtual bool __fastcall Connect(const bool AAutoLogin = true);
	bool __fastcall CloseMailBox(void);
	bool __fastcall CreateMailBox(const System::UnicodeString AMBName);
	bool __fastcall DeleteMailBox(const System::UnicodeString AMBName);
	bool __fastcall DeleteMsgs(int const *AMsgNumList, const int AMsgNumList_Size);
	virtual void __fastcall Disconnect(bool ANotifyPeer)/* overload */;
	virtual void __fastcall DisconnectNotifyPeer(void);
	bool __fastcall ExamineMailBox(const System::UnicodeString AMBName, Idmailbox::TIdMailBox* AMB);
	bool __fastcall ExpungeMailBox(void);
	void __fastcall KeepAlive(void);
	bool __fastcall ListInferiorMailBoxes(Classes::TStrings* AMailBoxList, Classes::TStrings* AInferiorMailBoxList);
	bool __fastcall ListMailBoxes(Classes::TStrings* AMailBoxList);
	bool __fastcall ListSubscribedMailBoxes(Classes::TStrings* AMailBoxList);
	bool __fastcall RenameMailBox(const System::UnicodeString AOldMBName, const System::UnicodeString ANewMBName);
	bool __fastcall SearchMailBox(TIdIMAP4SearchRec const *ASearchInfo, const int ASearchInfo_Size);
	bool __fastcall SelectMailBox(const System::UnicodeString AMBName);
	bool __fastcall StatusMailBox(const System::UnicodeString AMBName, Idmailbox::TIdMailBox* AMB)/* overload */;
	bool __fastcall StatusMailBox(const System::UnicodeString AMBName, Idmailbox::TIdMailBox* AMB, TIdIMAP4StatusDataItem const *AStatusDataItems, const int AStatusDataItems_Size)/* overload */;
	bool __fastcall StoreFlags(int const *AMsgNumList, const int AMsgNumList_Size, const TIdIMAP4StoreDataItem AStoreMethod, const Idmessage::TIdMessageFlagsSet AFlags);
	bool __fastcall SubscribeMailBox(const System::UnicodeString AMBName);
	bool __fastcall CopyMsg(const int AMsgNum, const System::UnicodeString AMBName);
	bool __fastcall CopyMsgs(int const *AMsgNumList, const int AMsgNumList_Size, const System::UnicodeString AMBName);
	bool __fastcall Retrieve(const int AMsgNum, Idmessage::TIdMessage* AMsg);
	bool __fastcall RetrieveNoDecodeToFile(const int AMsgNum, System::UnicodeString ADestFile);
	bool __fastcall RetrieveNoDecodeToStream(const int AMsgNum, Classes::TStream* AStream);
	bool __fastcall RetrieveAllEnvelopes(Idmessagecollection::TIdMessageCollection* AMsgList);
	bool __fastcall RetrieveAllHeaders(Idmessagecollection::TIdMessageCollection* AMsgList);
	bool __fastcall RetrieveAllMsgs(Idmessagecollection::TIdMessageCollection* AMsgList);
	bool __fastcall RetrieveEnvelope(const int AMsgNum, Idmessage::TIdMessage* AMsg);
	bool __fastcall RetrieveEnvelopeRaw(const int AMsgNum, Classes::TStrings* ADestList);
	bool __fastcall RetrieveFlags(const int AMsgNum, Idmessage::TIdMessageFlagsSet &AFlags);
	bool __fastcall InternalRetrieveStructure(const int AMsgNum, Idmessage::TIdMessage* AMsg, TIdImapMessageParts* AParts);
	bool __fastcall RetrieveStructure(const int AMsgNum, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall RetrieveStructure(const int AMsgNum, TIdImapMessageParts* AParts)/* overload */;
	bool __fastcall RetrievePart(const int AMsgNum, const System::UnicodeString APartNum, Classes::TStream* ADestStream, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall RetrievePart(const int AMsgNum, const System::UnicodeString APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall RetrievePart(const int AMsgNum, const int APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall RetrievePartPeek(const int AMsgNum, const System::UnicodeString APartNum, Classes::TStream* ADestStream, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall RetrievePartPeek(const int AMsgNum, const System::UnicodeString APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall RetrievePartPeek(const int AMsgNum, const int APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall RetrievePartToFile(const int AMsgNum, const int APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall RetrievePartToFile(const int AMsgNum, const System::UnicodeString APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall RetrievePartToFilePeek(const int AMsgNum, const int APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall RetrievePartToFilePeek(const int AMsgNum, const System::UnicodeString APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall RetrieveText(const int AMsgNum, System::UnicodeString &AText);
	bool __fastcall RetrieveText2(const int AMsgNum, System::UnicodeString &AText);
	bool __fastcall RetrieveTextPeek(const int AMsgNum, System::UnicodeString &AText);
	bool __fastcall RetrieveTextPeek2(const int AMsgNum, System::UnicodeString &AText);
	bool __fastcall RetrieveHeader(const int AMsgNum, Idmessage::TIdMessage* AMsg);
	bool __fastcall RetrievePartHeader(const int AMsgNum, const System::UnicodeString APartNum, Idheaderlist::TIdHeaderList* AHeaders);
	int __fastcall RetrieveMailBoxSize(void);
	int __fastcall RetrieveMsgSize(const int AMsgNum);
	bool __fastcall RetrievePeek(const int AMsgNum, Idmessage::TIdMessage* AMsg);
	bool __fastcall GetUID(const int AMsgNum, System::UnicodeString &AUID);
	bool __fastcall UIDCopyMsg(const System::UnicodeString AMsgUID, const System::UnicodeString AMBName);
	bool __fastcall UIDCopyMsgs(const Classes::TStrings* AMsgUIDList, const System::UnicodeString AMBName);
	bool __fastcall UIDCheckMsgSeen(const System::UnicodeString AMsgUID);
	bool __fastcall UIDDeleteMsg(const System::UnicodeString AMsgUID);
	bool __fastcall UIDDeleteMsgs(System::UnicodeString const *AMsgUIDList, const int AMsgUIDList_Size);
	bool __fastcall UIDRetrieveAllEnvelopes(Idmessagecollection::TIdMessageCollection* AMsgList);
	bool __fastcall UIDRetrieve(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg);
	bool __fastcall UIDRetrieveNoDecodeToFile(const System::UnicodeString AMsgUID, System::UnicodeString ADestFile);
	bool __fastcall UIDRetrieveNoDecodeToStream(const System::UnicodeString AMsgUID, Classes::TStream* AStream);
	bool __fastcall UIDRetrieveEnvelope(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg);
	bool __fastcall UIDRetrieveEnvelopeRaw(const System::UnicodeString AMsgUID, Classes::TStrings* ADestList);
	bool __fastcall UIDRetrieveFlags(const System::UnicodeString AMsgUID, Idmessage::TIdMessageFlagsSet &AFlags);
	bool __fastcall UIDInternalRetrieveStructure(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg, TIdImapMessageParts* AParts);
	bool __fastcall UIDRetrieveStructure(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg)/* overload */;
	bool __fastcall UIDRetrieveStructure(const System::UnicodeString AMsgUID, TIdImapMessageParts* AParts)/* overload */;
	bool __fastcall UIDRetrievePart(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, Classes::TStream* &ADestStream, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall UIDRetrievePart(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall UIDRetrievePart(const System::UnicodeString AMsgUID, const int APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall UIDRetrievePartPeek(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, Classes::TStream* &ADestStream, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall UIDRetrievePartPeek(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall UIDRetrievePartPeek(const System::UnicodeString AMsgUID, const int APartNum, System::WideChar * &ABuffer, int &ABufferLength, System::UnicodeString AContentTransferEncoding = L"text")/* overload */;
	bool __fastcall UIDRetrievePartToFile(const System::UnicodeString AMsgUID, const int APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall UIDRetrievePartToFile(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall UIDRetrievePartToFilePeek(const System::UnicodeString AMsgUID, const int APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall UIDRetrievePartToFilePeek(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, int ALength, System::UnicodeString ADestFileNameAndPath, System::UnicodeString AContentTransferEncoding)/* overload */;
	bool __fastcall UIDRetrieveText(const System::UnicodeString AMsgUID, System::UnicodeString &AText);
	bool __fastcall UIDRetrieveText2(const System::UnicodeString AMsgUID, System::UnicodeString &AText);
	bool __fastcall UIDRetrieveTextPeek(const System::UnicodeString AMsgUID, System::UnicodeString &AText);
	bool __fastcall UIDRetrieveTextPeek2(const System::UnicodeString AMsgUID, System::UnicodeString &AText);
	bool __fastcall UIDRetrieveHeader(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg);
	bool __fastcall UIDRetrievePartHeader(const System::UnicodeString AMsgUID, const System::UnicodeString APartNum, Idheaderlist::TIdHeaderList* AHeaders);
	int __fastcall UIDRetrieveMailBoxSize(void);
	int __fastcall UIDRetrieveMsgSize(const System::UnicodeString AMsgUID);
	bool __fastcall UIDRetrievePeek(const System::UnicodeString AMsgUID, Idmessage::TIdMessage* AMsg);
	bool __fastcall UIDSearchMailBox(TIdIMAP4SearchRec const *ASearchInfo, const int ASearchInfo_Size);
	bool __fastcall UIDStoreFlags(const System::UnicodeString AMsgUID, const TIdIMAP4StoreDataItem AStoreMethod, const Idmessage::TIdMessageFlagsSet AFlags)/* overload */;
	bool __fastcall UIDStoreFlags(System::UnicodeString const *AMsgUIDList, const int AMsgUIDList_Size, const TIdIMAP4StoreDataItem AStoreMethod, const Idmessage::TIdMessageFlagsSet AFlags)/* overload */;
	bool __fastcall UnsubscribeMailBox(const System::UnicodeString AMBName);
	HIDESBASE System::UnicodeString __fastcall GetInternalResponse(const System::UnicodeString ATag, System::UnicodeString *AExpectedResponses, const int AExpectedResponses_Size, bool ASingleLineMode, bool ASingleLineMayBeSplit = false)/* overload */;
	HIDESBASE System::UnicodeString __fastcall GetResponse()/* overload */;
	HIDESBASE System::UnicodeString __fastcall SendCmd(const System::UnicodeString AOut, System::UnicodeString *AExpectedResponses, const int AExpectedResponses_Size)/* overload */;
	HIDESBASE System::UnicodeString __fastcall SendCmd(const System::UnicodeString ATag, const System::UnicodeString AOut, System::UnicodeString *AExpectedResponses, const int AExpectedResponses_Size)/* overload */;
	System::UnicodeString __fastcall ReadLnWait();
	void __fastcall WriteLn(const System::UnicodeString AOut = L"");
	
__published:
	__property TIdAlertEvent OnAlert = {read=FOnAlert, write=FOnAlert};
	__property Password;
	__property TIdRetrieveOnSelect RetrieveOnSelect = {read=FRetrieveOnSelect, write=FRetrieveOnSelect, default=0};
	__property Port = {default=143};
	__property Username;
	__property System::WideChar MailBoxSeparator = {read=FMailBoxSeparator, write=FMailBoxSeparator, default=47};
	__property System::UnicodeString GreetingBanner = {read=FGreetingBanner};
	__property Host;
	__property UseTLS = {default=0};
	__property Idsaslcollection::TIdSASLEntries* SASLMechanisms = {read=FSASLMechanisms, write=SetSASLMechanisms};
	__property TIdIMAP4AuthenticationType AuthType = {read=FAuthType, write=FAuthType, default=0};
	__property int MilliSecsToWaitToClearBuffer = {read=FMilliSecsToWaitToClearBuffer, write=FMilliSecsToWaitToClearBuffer, nodefault};
	__property Idcomponent::TWorkEvent OnWorkForPart = {read=FOnWorkForPart, write=FOnWorkForPart};
	__property Idcomponent::TWorkBeginEvent OnWorkBeginForPart = {read=FOnWorkBeginForPart, write=FOnWorkBeginForPart};
	__property Idcomponent::TWorkEndEvent OnWorkEndForPart = {read=FOnWorkEndForPart, write=FOnWorkEndForPart};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIMAP4(Classes::TComponent* AOwner)/* overload */ : Idmessageclient::TIdMessageClient(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Disconnect(void){ Idtcpconnection::TIdTCPConnection::Disconnect(); }
	inline short __fastcall  GetResponse(const short AAllowedResponse = (short)(0xffffffff), Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::GetResponse(AAllowedResponse, AEncoding); }
	inline short __fastcall  GetResponse(short const *AAllowedResponses, const int AAllowedResponses_Size, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::GetResponse(AAllowedResponses, AAllowedResponses_Size, AEncoding); }
	inline System::UnicodeString __fastcall  GetResponse(const System::UnicodeString AAllowedResponse, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::GetResponse(AAllowedResponse, AEncoding); }
	inline short __fastcall  SendCmd(System::UnicodeString AOut, const short AResponse = (short)(0xffffffff), Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::SendCmd(AOut, AResponse, AEncoding); }
	inline short __fastcall  SendCmd(System::UnicodeString AOut, short const *AResponse, const int AResponse_Size, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::SendCmd(AOut, AResponse, AResponse_Size, AEncoding); }
	inline System::UnicodeString __fastcall  SendCmd(System::UnicodeString AOut, const System::UnicodeString AResponse, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0)){ return Idtcpconnection::TIdTCPConnection::SendCmd(AOut, AResponse, AEncoding); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE StaticArray<System::WideChar, 64> b64Chars;
extern PACKAGE StaticArray<int, 128> b64Index;
extern PACKAGE StaticArray<int, 128> b64Table;
static const ShortInt wsOk = 0x1;
static const ShortInt wsNo = 0x2;
static const ShortInt wsBad = 0x3;
static const ShortInt wsPreAuth = 0x4;
static const ShortInt wsBye = 0x5;
static const ShortInt wsContinue = 0x6;
static const TIdIMAP4AuthenticationType DEF_IMAP4_AUTH = (TIdIMAP4AuthenticationType)(0);
static const ShortInt IDF_DEFAULT_MS_TO_WAIT_TO_CLEAR_BUFFER = 0xa;

}	/* namespace Idimap4 */
using namespace Idimap4;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Idimap4HPP
