// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcommandhandlers.pas' rev: 20.00

#ifndef IdcommandhandlersHPP
#define IdcommandhandlersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idreply.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idreplyrfc.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcommandhandlers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdCommand;
typedef void __fastcall (__closure *TIdCommandEvent)(TIdCommand* ASender);

class DELPHICLASS TIdCommandHandlers;
typedef void __fastcall (__closure *TIdAfterCommandHandlerEvent)(TIdCommandHandlers* ASender, Idcontext::TIdContext* AContext);

typedef void __fastcall (__closure *TIdBeforeCommandHandlerEvent)(TIdCommandHandlers* ASender, System::UnicodeString &AData, Idcontext::TIdContext* AContext);

typedef void __fastcall (__closure *TIdCommandHandlersExceptionEvent)(System::UnicodeString ACommand, Idcontext::TIdContext* AContext);

class DELPHICLASS TIdCommandHandler;
class PASCALIMPLEMENTATION TIdCommandHandler : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::WideChar FCmdDelimiter;
	System::UnicodeString FCommand;
	System::TObject* FData;
	Classes::TStrings* FDescription;
	bool FDisconnect;
	bool FEnabled;
	Idreply::TIdReply* FExceptionReply;
	System::UnicodeString FHelpSuperScript;
	bool FHelpVisible;
	System::UnicodeString FName;
	Idreply::TIdReply* FNormalReply;
	TIdCommandEvent FOnCommand;
	System::WideChar FParamDelimiter;
	bool FParseParams;
	Idreply::TIdReplyClass FReplyClass;
	Classes::TStrings* FResponse;
	int FTag;
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetDescription(Classes::TStrings* AValue);
	void __fastcall SetExceptionReply(Idreply::TIdReply* AValue);
	void __fastcall SetNormalReply(Idreply::TIdReply* AValue);
	void __fastcall SetResponse(Classes::TStrings* AValue);
	
public:
	virtual bool __fastcall Check(const System::UnicodeString AData, Idcontext::TIdContext* AContext);
	virtual void __fastcall DoCommand(const System::UnicodeString AData, Idcontext::TIdContext* AContext, System::UnicodeString AUnparsedParams);
	virtual void __fastcall DoParseParams(System::UnicodeString AUnparsedParams, Classes::TStrings* AParams);
	__fastcall virtual TIdCommandHandler(Classes::TCollection* ACollection);
	__fastcall virtual ~TIdCommandHandler(void);
	bool __fastcall NameIs(const System::UnicodeString ACommand);
	__property System::TObject* Data = {read=FData, write=FData};
	
__published:
	__property System::WideChar CmdDelimiter = {read=FCmdDelimiter, write=FCmdDelimiter, nodefault};
	__property System::UnicodeString Command = {read=FCommand, write=FCommand};
	__property Classes::TStrings* Description = {read=FDescription, write=SetDescription};
	__property bool Disconnect = {read=FDisconnect, write=FDisconnect, nodefault};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property Idreply::TIdReply* ExceptionReply = {read=FExceptionReply, write=SetExceptionReply};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Idreply::TIdReply* NormalReply = {read=FNormalReply, write=SetNormalReply};
	__property System::WideChar ParamDelimiter = {read=FParamDelimiter, write=FParamDelimiter, nodefault};
	__property bool ParseParams = {read=FParseParams, write=FParseParams, nodefault};
	__property Classes::TStrings* Response = {read=FResponse, write=SetResponse};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	__property System::UnicodeString HelpSuperScript = {read=FHelpSuperScript, write=FHelpSuperScript};
	__property bool HelpVisible = {read=FHelpVisible, write=FHelpVisible, default=1};
	__property TIdCommandEvent OnCommand = {read=FOnCommand, write=FOnCommand};
};


typedef TMetaClass* TIdCommandHandlerClass;

class PASCALIMPLEMENTATION TIdCommandHandlers : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
protected:
	Idcomponent::TIdComponent* FBase;
	Idreply::TIdReply* FExceptionReply;
	TIdAfterCommandHandlerEvent FOnAfterCommandHandler;
	TIdBeforeCommandHandlerEvent FOnBeforeCommandHandler;
	TIdCommandHandlersExceptionEvent FOnCommandHandlersException;
	bool FParseParamsDef;
	bool FPerformReplies;
	Idreply::TIdReplyClass FReplyClass;
	Idreply::TIdReplies* FReplyTexts;
	void __fastcall DoAfterCommandHandler(Idcontext::TIdContext* AContext);
	void __fastcall DoBeforeCommandHandler(Idcontext::TIdContext* AContext, System::UnicodeString &VLine);
	void __fastcall DoOnCommandHandlersException(const System::UnicodeString ACommand, Idcontext::TIdContext* AContext);
	HIDESBASE TIdCommandHandler* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, const TIdCommandHandler* AValue);
	
public:
	HIDESBASE TIdCommandHandler* __fastcall Add(void);
	__fastcall TIdCommandHandlers(Idcomponent::TIdComponent* ABase, Idreply::TIdReplyClass AReplyClass, Idreply::TIdReplies* AReplyTexts, Idreply::TIdReply* AExceptionReply, TIdCommandHandlerClass ACommandHandlerClass);
	virtual bool __fastcall HandleCommand(Idcontext::TIdContext* AContext, System::UnicodeString &VCommand);
	__property Idcomponent::TIdComponent* Base = {read=FBase};
	__property TIdCommandHandler* Items[int AIndex] = {read=GetItem, write=SetItem};
	__property bool ParseParamsDefault = {read=FParseParamsDef, write=FParseParamsDef, nodefault};
	__property bool PerformReplies = {read=FPerformReplies, write=FPerformReplies, nodefault};
	__property Idreply::TIdReplyClass ReplyClass = {read=FReplyClass};
	__property Idreply::TIdReplies* ReplyTexts = {read=FReplyTexts};
	__property TIdAfterCommandHandlerEvent OnAfterCommandHandler = {read=FOnAfterCommandHandler, write=FOnAfterCommandHandler};
	__property TIdBeforeCommandHandlerEvent OnBeforeCommandHandler = {read=FOnBeforeCommandHandler, write=FOnBeforeCommandHandler};
	__property TIdCommandHandlersExceptionEvent OnCommandHandlersException = {read=FOnCommandHandlersException, write=FOnCommandHandlersException};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdCommandHandlers(void) { }
	
};


class PASCALIMPLEMENTATION TIdCommand : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TIdCommandHandler* FCommandHandler;
	bool FDisconnect;
	Classes::TStrings* FParams;
	bool FPerformReply;
	System::UnicodeString FRawLine;
	Idreply::TIdReply* FReply;
	Classes::TStrings* FResponse;
	Idcontext::TIdContext* FContext;
	System::UnicodeString FUnparsedParams;
	bool FSendEmptyResponse;
	virtual void __fastcall DoCommand(void);
	void __fastcall SetReply(Idreply::TIdReply* AValue);
	void __fastcall SetResponse(Classes::TStrings* AValue);
	
public:
	__fastcall virtual TIdCommand(TIdCommandHandler* AOwner);
	__fastcall virtual ~TIdCommand(void);
	void __fastcall SendReply(void);
	__property TIdCommandHandler* CommandHandler = {read=FCommandHandler};
	__property bool Disconnect = {read=FDisconnect, write=FDisconnect, nodefault};
	__property bool PerformReply = {read=FPerformReply, write=FPerformReply, nodefault};
	__property Classes::TStrings* Params = {read=FParams};
	__property System::UnicodeString RawLine = {read=FRawLine};
	__property Idreply::TIdReply* Reply = {read=FReply, write=SetReply};
	__property Classes::TStrings* Response = {read=FResponse, write=SetResponse};
	__property Idcontext::TIdContext* Context = {read=FContext};
	__property System::UnicodeString UnparsedParams = {read=FUnparsedParams};
	__property bool SendEmptyResponse = {read=FSendEmptyResponse, write=FSendEmptyResponse, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const bool IdEnabledDefault = true;
static const bool IdParseParamsDefault = true;
static const bool IdHelpVisibleDef = true;

}	/* namespace Idcommandhandlers */
using namespace Idcommandhandlers;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcommandhandlersHPP
