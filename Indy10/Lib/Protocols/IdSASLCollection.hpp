// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsaslcollection.pas' rev: 20.00

#ifndef IdsaslcollectionHPP
#define IdsaslcollectionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsaslcollection
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSASLListEntry;
class PASCALIMPLEMENTATION TIdSASLListEntry : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	Idsasl::TIdSASL* FSASL;
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Idsasl::TIdSASL* SASL = {read=FSASL, write=FSASL};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdSASLListEntry(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdSASLListEntry(void) { }
	
};


class DELPHICLASS TIdSASLEntries;
class PASCALIMPLEMENTATION TIdSASLEntries : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdSASLListEntry* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdSASLListEntry* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdSASLListEntry* Value);
	
public:
	__fastcall TIdSASLEntries(Classes::TPersistent* AOwner);
	HIDESBASE TIdSASLListEntry* __fastcall Add(void);
	bool __fastcall LoginSASL(const System::UnicodeString ACmd, const System::UnicodeString AHost, const System::UnicodeString AProtocolName, System::UnicodeString const *AOkReplies, const int AOkReplies_Size, System::UnicodeString const *AContinueReplies, const int AContinueReplies_Size, Idtcpconnection::TIdTCPConnection* AClient, Classes::TStrings* ACapaReply, const System::UnicodeString AAuthString = L"AUTH")/* overload */;
	bool __fastcall LoginSASL(const System::UnicodeString ACmd, const System::UnicodeString AHost, const System::UnicodeString AProtocolName, const System::UnicodeString AServiceName, System::UnicodeString const *AOkReplies, const int AOkReplies_Size, System::UnicodeString const *AContinueReplies, const int AContinueReplies_Size, Idtcpconnection::TIdTCPConnection* AClient, Classes::TStrings* ACapaReply, const System::UnicodeString AAuthString = L"AUTH")/* overload */;
	Classes::TStrings* __fastcall ParseCapaReply(Classes::TStrings* ACapaReply, const System::UnicodeString AAuthString = L"AUTH");
	Idsasl::TIdSASL* __fastcall FindSASL(const System::UnicodeString AServiceName);
	HIDESBASE TIdSASLListEntry* __fastcall Insert(int Index);
	void __fastcall RemoveByComp(Classes::TComponent* AComponent);
	int __fastcall IndexOfComp(Idsasl::TIdSASL* AItem);
	__property TIdSASLListEntry* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdSASLEntries(void) { }
	
};


class DELPHICLASS EIdSASLException;
class PASCALIMPLEMENTATION EIdSASLException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLException(void) { }
	
};


class DELPHICLASS EIdEmptySASLList;
class PASCALIMPLEMENTATION EIdEmptySASLList : public EIdSASLException
{
	typedef EIdSASLException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdEmptySASLList(const System::UnicodeString AMsg)/* overload */ : EIdSASLException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdEmptySASLList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdEmptySASLList(int Ident)/* overload */ : EIdSASLException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdEmptySASLList(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdEmptySASLList(const System::UnicodeString Msg, int AHelpContext) : EIdSASLException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdEmptySASLList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdEmptySASLList(int Ident, int AHelpContext)/* overload */ : EIdSASLException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdEmptySASLList(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdEmptySASLList(void) { }
	
};


class DELPHICLASS EIdSASLNotSupported;
class PASCALIMPLEMENTATION EIdSASLNotSupported : public EIdSASLException
{
	typedef EIdSASLException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLNotSupported(const System::UnicodeString AMsg)/* overload */ : EIdSASLException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLNotSupported(int Ident)/* overload */ : EIdSASLException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLNotSupported(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLNotSupported(const System::UnicodeString Msg, int AHelpContext) : EIdSASLException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLNotSupported(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLNotSupported(int Ident, int AHelpContext)/* overload */ : EIdSASLException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLNotSupported(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLNotSupported(void) { }
	
};


class DELPHICLASS EIdSASLMechNeeded;
class PASCALIMPLEMENTATION EIdSASLMechNeeded : public EIdSASLException
{
	typedef EIdSASLException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLMechNeeded(const System::UnicodeString AMsg)/* overload */ : EIdSASLException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLMechNeeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLMechNeeded(int Ident)/* overload */ : EIdSASLException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLMechNeeded(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLMechNeeded(const System::UnicodeString Msg, int AHelpContext) : EIdSASLException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLMechNeeded(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLMechNeeded(int Ident, int AHelpContext)/* overload */ : EIdSASLException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLMechNeeded(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLMechNeeded(void) { }
	
};


#pragma option push -b-
enum TAuthenticationType { atNone, atUserPass, atAPOP, atSASL };
#pragma option pop

typedef Set<TAuthenticationType, atNone, atSASL>  TAuthenticationTypes;

class DELPHICLASS EIdSASLMsg;
class PASCALIMPLEMENTATION EIdSASLMsg : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLMsg(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLMsg(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLMsg(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLMsg(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLMsg(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLMsg(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLMsg(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLMsg(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLMsg(void) { }
	
};


class DELPHICLASS EIdSASLNotValidForProtocol;
class PASCALIMPLEMENTATION EIdSASLNotValidForProtocol : public EIdSASLMsg
{
	typedef EIdSASLMsg inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdSASLNotValidForProtocol(const System::UnicodeString AMsg)/* overload */ : EIdSASLMsg(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdSASLNotValidForProtocol(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdSASLMsg(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdSASLNotValidForProtocol(int Ident)/* overload */ : EIdSASLMsg(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdSASLNotValidForProtocol(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdSASLMsg(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdSASLNotValidForProtocol(const System::UnicodeString Msg, int AHelpContext) : EIdSASLMsg(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSASLNotValidForProtocol(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdSASLMsg(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdSASLNotValidForProtocol(int Ident, int AHelpContext)/* overload */ : EIdSASLMsg(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSASLNotValidForProtocol(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSASLMsg(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdSASLNotValidForProtocol(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsaslcollection */
using namespace Idsaslcollection;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsaslcollectionHPP
