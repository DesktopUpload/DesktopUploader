// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddict.pas' rev: 20.00

#ifndef IddictHPP
#define IddictHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Iddictcommon.hpp>	// Pascal unit
#include <Idsaslcollection.hpp>	// Pascal unit
#include <Idtcpclient.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddict
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdDICTAuthenticationType { datDefault, datSASL };
#pragma option pop

class DELPHICLASS TIdDICT;
class PASCALIMPLEMENTATION TIdDICT : public Idtcpclient::TIdTCPClient
{
	typedef Idtcpclient::TIdTCPClient inherited;
	
protected:
	bool FTryMIME;
	TIdDICTAuthenticationType FAuthType;
	Idsaslcollection::TIdSASLEntries* FSASLMechanisms;
	System::UnicodeString FServer;
	System::UnicodeString FClient;
	Classes::TStrings* FCapabilities;
	virtual void __fastcall InitComponent(void);
	bool __fastcall IsCapaSupported(const System::UnicodeString ACapa);
	void __fastcall SetClient(const System::UnicodeString AValue);
	void __fastcall InternalGetList(const System::UnicodeString ACmd, Classes::TCollection* AENtries);
	void __fastcall InternalGetStrs(const System::UnicodeString ACmd, Classes::TStrings* AStrs);
	
public:
	__fastcall virtual ~TIdDICT(void);
	virtual void __fastcall Connect(void)/* overload */;
	virtual void __fastcall DisconnectNotifyPeer(void);
	void __fastcall GetDictInfo(const System::UnicodeString ADict, Classes::TStrings* AResults);
	void __fastcall GetSvrInfo(Classes::TStrings* AResults);
	void __fastcall GetDBList(Iddictcommon::TIdDBList* ADB);
	void __fastcall GetStrategyList(Iddictcommon::TIdStrategyList* AStrats);
	void __fastcall Define(const System::UnicodeString AWord, const System::UnicodeString ADBName, Iddictcommon::TIdDefinitions* AResults)/* overload */;
	void __fastcall Define(const System::UnicodeString AWord, Iddictcommon::TIdDefinitions* AResults, const bool AGetAll = true)/* overload */;
	void __fastcall Match(const System::UnicodeString AWord, const System::UnicodeString ADBName, const System::UnicodeString AStrat, Iddictcommon::TIdMatchList* AResults)/* overload */;
	void __fastcall Match(const System::UnicodeString AWord, const System::UnicodeString AStrat, Iddictcommon::TIdMatchList* AResults, const bool AGetAll = true)/* overload */;
	void __fastcall Match(const System::UnicodeString AWord, Iddictcommon::TIdMatchList* AResults, const bool AGetAll = true)/* overload */;
	__property Classes::TStrings* Capabilities = {read=FCapabilities};
	__property System::UnicodeString Server = {read=FServer};
	
__published:
	__property bool TryMIME = {read=FTryMIME, write=FTryMIME, default=0};
	__property System::UnicodeString Client = {read=FClient, write=SetClient};
	__property TIdDICTAuthenticationType AuthType = {read=FAuthType, write=FAuthType, default=0};
	__property Idsaslcollection::TIdSASLEntries* SASLMechanisms = {read=FSASLMechanisms, write=FSASLMechanisms};
	__property Port = {default=2628};
	__property Username;
	__property Password;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDICT(Classes::TComponent* AOwner)/* overload */ : Idtcpclient::TIdTCPClient(AOwner) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Connect(const System::UnicodeString AHost){ Idtcpclient::TIdTCPClientCustom::Connect(AHost); }
	inline void __fastcall  Connect(const System::UnicodeString AHost, const System::Word APort){ Idtcpclient::TIdTCPClientCustom::Connect(AHost, APort); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const TIdDICTAuthenticationType DICT_AUTHDEF = (TIdDICTAuthenticationType)(0);
static const bool DEF_TRYMIME = false;

}	/* namespace Iddict */
using namespace Iddict;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddictHPP
