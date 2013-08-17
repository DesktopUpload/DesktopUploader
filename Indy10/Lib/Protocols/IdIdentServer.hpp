// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ididentserver.pas' rev: 20.00

#ifndef IdidentserverHPP
#define IdidentserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ididentserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdIdentQueryEvent)(Idcontext::TIdContext* AContext, System::Word AServerPort, System::Word AClientPort);

#pragma option push -b-
enum TIdIdentErrorType { ieInvalidPort, ieNoUser, ieHiddenUser, ieUnknownError };
#pragma option pop

class DELPHICLASS TIdIdentServer;
class PASCALIMPLEMENTATION TIdIdentServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	TIdIdentQueryEvent FOnIdentQuery;
	int FQueryTimeOut;
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall ReplyError(Idcontext::TIdContext* AContext, System::Word AServerPort, System::Word AClientPort, TIdIdentErrorType AErr);
	void __fastcall ReplyIdent(Idcontext::TIdContext* AContext, System::Word AServerPort, System::Word AClientPort, System::UnicodeString AOS, System::UnicodeString AUserName, const System::UnicodeString ACharset = L"");
	void __fastcall ReplyOther(Idcontext::TIdContext* AContext, System::Word AServerPort, System::Word AClientPort, System::UnicodeString AOther);
	
__published:
	__property int QueryTimeOut = {read=FQueryTimeOut, write=FQueryTimeOut, default=60000};
	__property TIdIdentQueryEvent OnIdentQuery = {read=FOnIdentQuery, write=FOnIdentQuery};
	__property DefaultPort = {default=113};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdIdentServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIdentServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word IdDefIdentQueryTimeOut = 0xea60;

}	/* namespace Ididentserver */
using namespace Ididentserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdidentserverHPP
