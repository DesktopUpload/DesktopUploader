// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idgopherserver.pas' rev: 20.00

#ifndef IdgopherserverHPP
#define IdgopherserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idcontext.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idgopherserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TRequestEvent)(Idcontext::TIdContext* AContext, System::UnicodeString ARequest);

typedef void __fastcall (__closure *TPlusRequestEvent)(Idcontext::TIdContext* AContext, System::UnicodeString ARequest, System::UnicodeString APlusData);

class DELPHICLASS TIdGopherServer;
class PASCALIMPLEMENTATION TIdGopherServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
private:
	System::UnicodeString fAdminEmail;
	TRequestEvent fOnRequest;
	TPlusRequestEvent fOnPlusRequest;
	bool fTruncateUserFriendly;
	int fTruncateLength;
	
protected:
	virtual bool __fastcall DoExecute(Idcontext::TIdContext* AContext);
	virtual void __fastcall InitComponent(void);
	
public:
	System::UnicodeString __fastcall ReturnGopherItem(System::WideChar ItemType, System::UnicodeString UserFriendlyName, System::UnicodeString RealResourceName, System::UnicodeString HostServer, System::Word HostPort);
	void __fastcall SendDirectoryEntry(Idcontext::TIdContext* AContext, System::WideChar ItemType, System::UnicodeString UserFriendlyName, System::UnicodeString RealResourceName, System::UnicodeString HostServer, System::Word HostPort);
	
__published:
	__property System::UnicodeString AdminEmail = {read=fAdminEmail, write=fAdminEmail};
	__property TRequestEvent OnRequest = {read=fOnRequest, write=fOnRequest};
	__property TPlusRequestEvent OnPlusRequest = {read=fOnPlusRequest, write=fOnPlusRequest};
	__property bool TruncateUserFriendlyName = {read=fTruncateUserFriendly, write=fTruncateUserFriendly, default=1};
	__property int TruncateLength = {read=fTruncateLength, write=fTruncateLength, default=70};
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdGopherServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdGopherServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idgopherserver */
using namespace Idgopherserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdgopherserverHPP
