// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idintercept.pas' rev: 20.00

#ifndef IdinterceptHPP
#define IdinterceptHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idbuffer.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idintercept
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdInterceptCircularLink;
class PASCALIMPLEMENTATION EIdInterceptCircularLink : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInterceptCircularLink(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInterceptCircularLink(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInterceptCircularLink(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInterceptCircularLink(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInterceptCircularLink(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInterceptCircularLink(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInterceptCircularLink(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInterceptCircularLink(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInterceptCircularLink(void) { }
	
};


class DELPHICLASS TIdConnectionIntercept;
typedef void __fastcall (__closure *TIdInterceptNotifyEvent)(TIdConnectionIntercept* ASender);

typedef void __fastcall (__closure *TIdInterceptStreamEvent)(TIdConnectionIntercept* ASender, Sysutils::TBytes &ABuffer);

class PASCALIMPLEMENTATION TIdConnectionIntercept : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Classes::TComponent* FConnection;
	TIdConnectionIntercept* FIntercept;
	bool FIsClient;
	System::TObject* FData;
	TIdInterceptNotifyEvent FOnConnect;
	TIdInterceptNotifyEvent FOnDisconnect;
	TIdInterceptStreamEvent FOnReceive;
	TIdInterceptStreamEvent FOnSend;
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetIntercept(TIdConnectionIntercept* AValue);
	
public:
	virtual void __fastcall Connect(Classes::TComponent* AConnection);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall Receive(Sysutils::TBytes &VBuffer);
	virtual void __fastcall Send(Sysutils::TBytes &VBuffer);
	__property Classes::TComponent* Connection = {read=FConnection};
	__property bool IsClient = {read=FIsClient, nodefault};
	__property System::TObject* Data = {read=FData, write=FData};
	
__published:
	__property TIdConnectionIntercept* Intercept = {read=FIntercept, write=SetIntercept};
	__property TIdInterceptNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property TIdInterceptNotifyEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
	__property TIdInterceptStreamEvent OnReceive = {read=FOnReceive, write=FOnReceive};
	__property TIdInterceptStreamEvent OnSend = {read=FOnSend, write=FOnSend};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdConnectionIntercept(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdConnectionIntercept(void) { }
	
};


class DELPHICLASS TIdServerIntercept;
class PASCALIMPLEMENTATION TIdServerIntercept : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
public:
	virtual void __fastcall Init(void) = 0 ;
	virtual TIdConnectionIntercept* __fastcall Accept(Classes::TComponent* AConnection) = 0 ;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerIntercept(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdServerIntercept(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idintercept */
using namespace Idintercept;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdinterceptHPP
