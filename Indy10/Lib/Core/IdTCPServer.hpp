// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtcpserver.pas' rev: 20.00

#ifndef IdtcpserverHPP
#define IdtcpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idcustomtcpserver.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtcpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdTCPNoOnExecute;
class PASCALIMPLEMENTATION EIdTCPNoOnExecute : public Idcustomtcpserver::EIdTCPServerError
{
	typedef Idcustomtcpserver::EIdTCPServerError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTCPNoOnExecute(const System::UnicodeString AMsg)/* overload */ : Idcustomtcpserver::EIdTCPServerError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTCPNoOnExecute(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idcustomtcpserver::EIdTCPServerError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTCPNoOnExecute(int Ident)/* overload */ : Idcustomtcpserver::EIdTCPServerError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTCPNoOnExecute(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idcustomtcpserver::EIdTCPServerError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTCPNoOnExecute(const System::UnicodeString Msg, int AHelpContext) : Idcustomtcpserver::EIdTCPServerError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTCPNoOnExecute(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idcustomtcpserver::EIdTCPServerError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTCPNoOnExecute(int Ident, int AHelpContext)/* overload */ : Idcustomtcpserver::EIdTCPServerError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTCPNoOnExecute(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idcustomtcpserver::EIdTCPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTCPNoOnExecute(void) { }
	
};


class DELPHICLASS TIdTCPServer;
class PASCALIMPLEMENTATION TIdTCPServer : public Idcustomtcpserver::TIdCustomTCPServer
{
	typedef Idcustomtcpserver::TIdCustomTCPServer inherited;
	
protected:
	virtual void __fastcall CheckOkToBeActive(void);
	
__published:
	__property OnExecute;
public:
	/* TIdCustomTCPServer.Destroy */ inline __fastcall virtual ~TIdTCPServer(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTCPServer(Classes::TComponent* AOwner)/* overload */ : Idcustomtcpserver::TIdCustomTCPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtcpserver */
using namespace Idtcpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtcpserverHPP
