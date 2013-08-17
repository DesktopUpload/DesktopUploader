// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idserverinterceptlogbase.pas' rev: 20.00

#ifndef IdserverinterceptlogbaseHPP
#define IdserverinterceptlogbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idlogbase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idserverinterceptlogbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdServerInterceptLogBase;
class PASCALIMPLEMENTATION TIdServerInterceptLogBase : public Idintercept::TIdServerIntercept
{
	typedef Idintercept::TIdServerIntercept inherited;
	
protected:
	Idglobal::TIdCriticalSection* FLock;
	bool FLogTime;
	bool FReplaceCRLF;
	bool FHasInit;
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Init(void);
	virtual Idintercept::TIdConnectionIntercept* __fastcall Accept(Classes::TComponent* AConnection);
	__fastcall virtual ~TIdServerInterceptLogBase(void);
	virtual void __fastcall DoLogWriteString(const System::UnicodeString AText) = 0 ;
	virtual void __fastcall LogWriteString(const System::UnicodeString AText);
	
__published:
	__property bool LogTime = {read=FLogTime, write=FLogTime, default=1};
	__property bool ReplaceCRLF = {read=FReplaceCRLF, write=FReplaceCRLF, default=1};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerInterceptLogBase(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdServerIntercept(AOwner) { }
	
};


class DELPHICLASS TIdServerInterceptLogFileConnection;
class PASCALIMPLEMENTATION TIdServerInterceptLogFileConnection : public Idlogbase::TIdLogBase
{
	typedef Idlogbase::TIdLogBase inherited;
	
protected:
	TIdServerInterceptLogBase* FServerInterceptLog;
	virtual void __fastcall LogReceivedData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogSentData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogStatus(const System::UnicodeString AText);
	virtual System::UnicodeString __fastcall GetConnectionID();
public:
	/* TIdLogBase.Destroy */ inline __fastcall virtual ~TIdServerInterceptLogFileConnection(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdServerInterceptLogFileConnection(Classes::TComponent* AOwner)/* overload */ : Idlogbase::TIdLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idserverinterceptlogbase */
using namespace Idserverinterceptlogbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdserverinterceptlogbaseHPP
