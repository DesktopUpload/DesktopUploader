// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcontext.pas' rev: 20.00

#ifndef IdcontextHPP
#define IdcontextHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcontext
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass* TIdContextClass;

class DELPHICLASS TIdContext;
typedef bool __fastcall (__closure *TIdContextRun)(TIdContext* AContext);

typedef void __fastcall (__closure *TIdContextEvent)(TIdContext* AContext);

typedef void __fastcall (__closure *TIdContextExceptionEvent)(TIdContext* AContext, Sysutils::Exception* AException);

class PASCALIMPLEMENTATION TIdContext : public Idtask::TIdTask
{
	typedef Idtask::TIdTask inherited;
	
protected:
	Classes::TThreadList* FContextList;
	Idtcpconnection::TIdTCPConnection* FConnection;
	bool FOwnsConnection;
	TIdContextRun FOnRun;
	TIdContextEvent FOnBeforeRun;
	TIdContextEvent FOnAfterRun;
	TIdContextExceptionEvent FOnException;
	virtual void __fastcall BeforeRun(void);
	virtual bool __fastcall Run(void);
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall HandleException(Sysutils::Exception* AException);
	
public:
	__fastcall virtual TIdContext(Idtcpconnection::TIdTCPConnection* AConnection, Idyarn::TIdYarn* AYarn, Classes::TThreadList* AList);
	__fastcall virtual ~TIdContext(void);
	void __fastcall RemoveFromList(void);
	Idsockethandle::TIdSocketHandle* __fastcall Binding(void);
	__property Idtcpconnection::TIdTCPConnection* Connection = {read=FConnection};
	__property TIdContextEvent OnAfterRun = {read=FOnAfterRun, write=FOnAfterRun};
	__property TIdContextEvent OnBeforeRun = {read=FOnBeforeRun, write=FOnBeforeRun};
	__property TIdContextRun OnRun = {read=FOnRun, write=FOnRun};
	__property TIdContextExceptionEvent OnException = {read=FOnException, write=FOnException};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcontext */
using namespace Idcontext;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcontextHPP
