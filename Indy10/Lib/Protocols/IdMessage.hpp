// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmessage.pas' rev: 20.00

#ifndef IdmessageHPP
#define IdmessageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idattachment.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcoderheader.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idmessageparts.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessage
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdMessagePriority { mpHighest, mpHigh, mpNormal, mpLow, mpLowest };
#pragma option pop

class DELPHICLASS TIdMIMEBoundary;
class PASCALIMPLEMENTATION TIdMIMEBoundary : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* FBoundaryList;
	Classes::TStrings* FParentPartList;
	System::UnicodeString __fastcall GetBoundary();
	int __fastcall GetParentPart(void);
	
public:
	__fastcall TIdMIMEBoundary(void);
	__fastcall virtual ~TIdMIMEBoundary(void);
	void __fastcall Push(System::UnicodeString ABoundary, int AParentPart);
	void __fastcall Pop(void);
	void __fastcall Clear(void);
	int __fastcall Count(void);
	__property System::UnicodeString Boundary = {read=GetBoundary};
	__property int ParentPart = {read=GetParentPart, nodefault};
};


#pragma option push -b-
enum TIdMessageFlags { mfAnswered, mfFlagged, mfDeleted, mfDraft, mfSeen, mfRecent };
#pragma option pop

typedef Set<TIdMessageFlags, mfAnswered, mfRecent>  TIdMessageFlagsSet;

#pragma option push -b-
enum TIdMessageEncoding { meDefault, meMIME, mePlainText };
#pragma option pop

typedef void __fastcall (__closure *TIdInitializeIsoEvent)(System::WideChar &VHeaderEncoding, System::UnicodeString &VCharSet);

class DELPHICLASS TIdMessage;
typedef void __fastcall (__closure *TIdCreateAttachmentEvent)(const TIdMessage* AMsg, const Classes::TStrings* AHeaders, Idattachment::TIdAttachment* &AAttachment);

class PASCALIMPLEMENTATION TIdMessage : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	System::UnicodeString FAttachmentTempDirectory;
	Idemailaddress::TIdEMailAddressList* FBccList;
	Classes::TStrings* FBody;
	System::UnicodeString FCharSet;
	Idemailaddress::TIdEMailAddressList* FCcList;
	System::UnicodeString FContentType;
	System::UnicodeString FContentTransferEncoding;
	System::UnicodeString FContentDisposition;
	System::TDateTime FDate;
	bool FIsEncoded;
	Idheaderlist::TIdHeaderList* FExtraHeaders;
	TIdMessageEncoding FEncoding;
	TIdMessageFlagsSet FFlags;
	Idemailaddress::TIdEMailAddressList* FFromList;
	Idheaderlist::TIdHeaderList* FHeaders;
	Idmessageparts::TIdMessageParts* FMessageParts;
	TIdMIMEBoundary* FMIMEBoundary;
	System::UnicodeString FMsgId;
	Classes::TStrings* FNewsGroups;
	bool FNoEncode;
	bool FNoDecode;
	TIdInitializeIsoEvent FOnInitializeISO;
	System::UnicodeString FOrganization;
	TIdMessagePriority FPriority;
	System::UnicodeString FSubject;
	Idemailaddress::TIdEMailAddressItem* FReceiptRecipient;
	Idemailaddress::TIdEMailAddressList* FRecipients;
	System::UnicodeString FReferences;
	System::UnicodeString FInReplyTo;
	Idemailaddress::TIdEMailAddressList* FReplyTo;
	Idemailaddress::TIdEMailAddressItem* FSender;
	System::UnicodeString FUID;
	System::UnicodeString FXProgram;
	TIdCreateAttachmentEvent FOnCreateAttachment;
	Idheaderlist::TIdHeaderList* FLastGeneratedHeaders;
	bool FConvertPreamble;
	bool FSavingToFile;
	bool FIsMsgSinglePartMime;
	bool FExceptionOnBlockedAttachments;
	virtual void __fastcall DoInitializeISO(System::WideChar &VHeaderEncoding, System::UnicodeString &VCharSet);
	System::UnicodeString __fastcall GetAttachmentEncoding();
	System::UnicodeString __fastcall GetInReplyTo();
	bool __fastcall GetUseNowForDate(void);
	Idemailaddress::TIdEMailAddressItem* __fastcall GetFrom(void);
	void __fastcall SetAttachmentEncoding(const System::UnicodeString AValue);
	void __fastcall SetAttachmentTempDirectory(const System::UnicodeString Value);
	void __fastcall SetBccList(const Idemailaddress::TIdEMailAddressList* AValue);
	void __fastcall SetBody(const Classes::TStrings* AValue);
	void __fastcall SetCCList(const Idemailaddress::TIdEMailAddressList* AValue);
	void __fastcall SetContentType(const System::UnicodeString AValue);
	void __fastcall SetEncoding(const TIdMessageEncoding AValue);
	void __fastcall SetExtraHeaders(const Idheaderlist::TIdHeaderList* AValue);
	void __fastcall SetFrom(const Idemailaddress::TIdEMailAddressItem* AValue);
	void __fastcall SetFromList(const Idemailaddress::TIdEMailAddressList* AValue);
	void __fastcall SetHeaders(const Idheaderlist::TIdHeaderList* AValue);
	void __fastcall SetInReplyTo(const System::UnicodeString AValue);
	void __fastcall SetMsgID(const System::UnicodeString AValue);
	void __fastcall SetNewsGroups(const Classes::TStrings* AValue);
	void __fastcall SetReceiptRecipient(const Idemailaddress::TIdEMailAddressItem* AValue);
	void __fastcall SetRecipients(const Idemailaddress::TIdEMailAddressList* AValue);
	void __fastcall SetReplyTo(const Idemailaddress::TIdEMailAddressList* AValue);
	void __fastcall SetSender(const Idemailaddress::TIdEMailAddressItem* AValue);
	void __fastcall SetUseNowForDate(const bool AValue);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdMessage(void);
	void __fastcall AddHeader(const System::UnicodeString AValue);
	virtual void __fastcall Clear(void);
	void __fastcall ClearBody(void);
	void __fastcall ClearHeader(void);
	void __fastcall GenerateHeader(void);
	void __fastcall InitializeISO(System::WideChar &VHeaderEncoding, System::UnicodeString &VCharSet);
	bool __fastcall IsBodyEncodingRequired(void);
	bool __fastcall IsBodyEmpty(void);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName, const bool AHeadersOnly = false);
	void __fastcall LoadFromStream(Classes::TStream* AStream, const bool AHeadersOnly = false);
	void __fastcall ProcessHeaders(void);
	void __fastcall SaveToFile(const System::UnicodeString AFileName, const bool AHeadersOnly = false);
	void __fastcall SaveToStream(Classes::TStream* AStream, const bool AHeadersOnly = false);
	virtual void __fastcall DoCreateAttachment(const Classes::TStrings* AHeaders, Idattachment::TIdAttachment* &VAttachment);
	__property TIdMessageFlagsSet Flags = {read=FFlags, write=FFlags, nodefault};
	__property bool IsEncoded = {read=FIsEncoded, write=FIsEncoded, nodefault};
	__property System::UnicodeString MsgId = {read=FMsgId, write=SetMsgID};
	__property Idheaderlist::TIdHeaderList* Headers = {read=FHeaders, write=SetHeaders};
	__property Idmessageparts::TIdMessageParts* MessageParts = {read=FMessageParts};
	__property TIdMIMEBoundary* MIMEBoundary = {read=FMIMEBoundary, write=FMIMEBoundary};
	__property System::UnicodeString UID = {read=FUID, write=FUID};
	__property bool IsMsgSinglePartMime = {read=FIsMsgSinglePartMime, write=FIsMsgSinglePartMime, nodefault};
	
__published:
	__property System::UnicodeString AttachmentEncoding = {read=GetAttachmentEncoding, write=SetAttachmentEncoding};
	__property Classes::TStrings* Body = {read=FBody, write=SetBody};
	__property Idemailaddress::TIdEMailAddressList* BccList = {read=FBccList, write=SetBccList};
	__property System::UnicodeString CharSet = {read=FCharSet, write=FCharSet};
	__property Idemailaddress::TIdEMailAddressList* CCList = {read=FCcList, write=SetCCList};
	__property System::UnicodeString ContentType = {read=FContentType, write=SetContentType};
	__property System::UnicodeString ContentTransferEncoding = {read=FContentTransferEncoding, write=FContentTransferEncoding};
	__property System::UnicodeString ContentDisposition = {read=FContentDisposition, write=FContentDisposition};
	__property System::TDateTime Date = {read=FDate, write=FDate};
	__property TIdMessageEncoding Encoding = {read=FEncoding, write=SetEncoding, nodefault};
	__property Idheaderlist::TIdHeaderList* ExtraHeaders = {read=FExtraHeaders, write=SetExtraHeaders};
	__property Idemailaddress::TIdEMailAddressList* FromList = {read=FFromList, write=SetFromList};
	__property Idemailaddress::TIdEMailAddressItem* From = {read=GetFrom, write=SetFrom};
	__property Classes::TStrings* NewsGroups = {read=FNewsGroups, write=SetNewsGroups};
	__property bool NoEncode = {read=FNoEncode, write=FNoEncode, default=0};
	__property bool NoDecode = {read=FNoDecode, write=FNoDecode, default=0};
	__property System::UnicodeString Organization = {read=FOrganization, write=FOrganization};
	__property TIdMessagePriority Priority = {read=FPriority, write=FPriority, default=2};
	__property Idemailaddress::TIdEMailAddressItem* ReceiptRecipient = {read=FReceiptRecipient, write=SetReceiptRecipient};
	__property Idemailaddress::TIdEMailAddressList* Recipients = {read=FRecipients, write=SetRecipients};
	__property System::UnicodeString References = {read=FReferences, write=FReferences};
	__property System::UnicodeString InReplyTo = {read=GetInReplyTo, write=SetInReplyTo};
	__property Idemailaddress::TIdEMailAddressList* ReplyTo = {read=FReplyTo, write=SetReplyTo};
	__property System::UnicodeString Subject = {read=FSubject, write=FSubject};
	__property Idemailaddress::TIdEMailAddressItem* Sender = {read=FSender, write=SetSender};
	__property bool UseNowForDate = {read=GetUseNowForDate, write=SetUseNowForDate, default=1};
	__property Idheaderlist::TIdHeaderList* LastGeneratedHeaders = {read=FLastGeneratedHeaders};
	__property bool ConvertPreamble = {read=FConvertPreamble, write=FConvertPreamble, nodefault};
	__property bool ExceptionOnBlockedAttachments = {read=FExceptionOnBlockedAttachments, write=FExceptionOnBlockedAttachments, default=0};
	__property System::UnicodeString AttachmentTempDirectory = {read=FAttachmentTempDirectory, write=SetAttachmentTempDirectory};
	__property TIdInitializeIsoEvent OnInitializeISO = {read=FOnInitializeISO, write=FOnInitializeISO};
	__property TIdCreateAttachmentEvent OnCreateAttachment = {read=FOnCreateAttachment, write=FOnCreateAttachment};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdMessage(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


typedef void __fastcall (__closure *TIdMessageEvent)(Classes::TComponent* ASender, TIdMessage* &AMsg);

class DELPHICLASS EIdTextInvalidCount;
class PASCALIMPLEMENTATION EIdTextInvalidCount : public Idexceptioncore::EIdMessageException
{
	typedef Idexceptioncore::EIdMessageException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTextInvalidCount(const System::UnicodeString AMsg)/* overload */ : Idexceptioncore::EIdMessageException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTextInvalidCount(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexceptioncore::EIdMessageException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTextInvalidCount(int Ident)/* overload */ : Idexceptioncore::EIdMessageException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTextInvalidCount(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexceptioncore::EIdMessageException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTextInvalidCount(const System::UnicodeString Msg, int AHelpContext) : Idexceptioncore::EIdMessageException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTextInvalidCount(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexceptioncore::EIdMessageException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTextInvalidCount(int Ident, int AHelpContext)/* overload */ : Idexceptioncore::EIdMessageException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTextInvalidCount(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexceptioncore::EIdMessageException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTextInvalidCount(void) { }
	
};


class DELPHICLASS EIdMessageCannotLoad;
class PASCALIMPLEMENTATION EIdMessageCannotLoad : public Idexceptioncore::EIdMessageException
{
	typedef Idexceptioncore::EIdMessageException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdMessageCannotLoad(const System::UnicodeString AMsg)/* overload */ : Idexceptioncore::EIdMessageException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdMessageCannotLoad(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexceptioncore::EIdMessageException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdMessageCannotLoad(int Ident)/* overload */ : Idexceptioncore::EIdMessageException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageCannotLoad(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexceptioncore::EIdMessageException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdMessageCannotLoad(const System::UnicodeString Msg, int AHelpContext) : Idexceptioncore::EIdMessageException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageCannotLoad(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexceptioncore::EIdMessageException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageCannotLoad(int Ident, int AHelpContext)/* overload */ : Idexceptioncore::EIdMessageException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageCannotLoad(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexceptioncore::EIdMessageException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdMessageCannotLoad(void) { }
	
};


typedef StaticArray<System::UnicodeString, 6> Idmessage__5;

//-- var, const, procedure ---------------------------------------------------
static const bool ID_MSG_NODECODE = false;
static const bool ID_MSG_USESNOWFORDATE = true;
static const TIdMessagePriority ID_MSG_PRIORITY = (TIdMessagePriority)(2);
extern PACKAGE Idmessage__5 MessageFlags;
#define INREPLYTO L"In-Reply-To"

}	/* namespace Idmessage */
using namespace Idmessage;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmessageHPP
