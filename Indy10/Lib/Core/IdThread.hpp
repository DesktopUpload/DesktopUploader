// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idthread.pas' rev: 20.00

#ifndef IdthreadHPP
#define IdthreadHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idyarn.hpp>	// Pascal unit
#include <Idtask.hpp>	// Pascal unit
#include <Idthreadsafe.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idthread
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdThreadException;
class PASCALIMPLEMENTATION EIdThreadException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdThreadException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdThreadException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdThreadException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdThreadException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdThreadException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdThreadException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdThreadException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdThreadException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdThreadException(void) { }
	
};


class DELPHICLASS EIdThreadTerminateAndWaitFor;
class PASCALIMPLEMENTATION EIdThreadTerminateAndWaitFor : public EIdThreadException
{
	typedef EIdThreadException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdThreadTerminateAndWaitFor(const System::UnicodeString AMsg)/* overload */ : EIdThreadException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdThreadTerminateAndWaitFor(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdThreadException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdThreadTerminateAndWaitFor(int Ident)/* overload */ : EIdThreadException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdThreadTerminateAndWaitFor(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdThreadException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdThreadTerminateAndWaitFor(const System::UnicodeString Msg, int AHelpContext) : EIdThreadException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdThreadTerminateAndWaitFor(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdThreadException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdThreadTerminateAndWaitFor(int Ident, int AHelpContext)/* overload */ : EIdThreadException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdThreadTerminateAndWaitFor(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdThreadException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdThreadTerminateAndWaitFor(void) { }
	
};


#pragma option push -b-
enum TIdThreadStopMode { smTerminate, smSuspend };
#pragma option pop

class DELPHICLASS TIdThread;
typedef void __fastcall (__closure *TIdExceptionThreadEvent)(TIdThread* AThread, Sysutils::Exception* AException);

typedef void __fastcall (__closure *TIdNotifyThreadEvent)(TIdThread* AThread);

typedef void __fastcall (__closure *TIdSynchronizeThreadEvent)(TIdThread* AThread, void * AData);

#pragma option push -b-
enum Idthread__3 { itoStopped, itoReqCleanup, itoDataOwner, itoTag };
#pragma option pop

typedef Set<Idthread__3, itoStopped, itoTag>  TIdThreadOptions;

class PASCALIMPLEMENTATION TIdThread : public Classes::TThread
{
	typedef Classes::TThread inherited;
	
protected:
	System::TObject* FData;
	Idglobal::TIdCriticalSection* FLock;
	bool FLoop;
	System::UnicodeString FName;
	TIdThreadStopMode FStopMode;
	TIdThreadOptions FOptions;
	System::UnicodeString FTerminatingException;
	System::TClass FTerminatingExceptionClass;
	Idyarn::TIdYarn* FYarn;
	TIdExceptionThreadEvent FOnException;
	TIdNotifyThreadEvent FOnStopped;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall AfterExecute(void);
	virtual void __fastcall BeforeExecute(void);
	virtual void __fastcall BeforeRun(void);
	virtual void __fastcall Cleanup(void);
	virtual void __fastcall DoException(Sysutils::Exception* AException);
	virtual void __fastcall DoStopped(void);
	virtual void __fastcall Execute(void);
	bool __fastcall GetStopped(void);
	virtual bool __fastcall HandleRunException(Sysutils::Exception* AException);
	virtual void __fastcall Run(void) = 0 ;
	__classmethod void __fastcall WaitAllThreadsTerminated(int AMSec = 0xea60);
	
public:
	__fastcall virtual TIdThread(bool ACreateSuspended, bool ALoop, const System::UnicodeString AName);
	__fastcall virtual ~TIdThread(void);
	virtual void __fastcall Start(void);
	virtual void __fastcall Stop(void);
	HIDESBASE void __fastcall Synchronize(Classes::TThreadMethod Method)/* overload */;
	HIDESBASE virtual void __fastcall Terminate(void);
	virtual void __fastcall TerminateAndWaitFor(void);
	__property System::TObject* Data = {read=FData, write=FData};
	__property bool Loop = {read=FLoop, write=FLoop, nodefault};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property ReturnValue;
	__property TIdThreadStopMode StopMode = {read=FStopMode, write=FStopMode, nodefault};
	__property bool Stopped = {read=GetStopped, nodefault};
	__property Terminated;
	__property System::UnicodeString TerminatingException = {read=FTerminatingException};
	__property System::TClass TerminatingExceptionClass = {read=FTerminatingExceptionClass};
	__property Idyarn::TIdYarn* Yarn = {read=FYarn, write=FYarn};
	__property TIdExceptionThreadEvent OnException = {read=FOnException, write=FOnException};
	__property TIdNotifyThreadEvent OnStopped = {read=FOnStopped, write=FOnStopped};
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  Synchronize(Classes::_di_TThreadProcedure AThreadProc){ Classes::TThread::Synchronize(AThreadProc); }
	
public:
	inline void __fastcall  Synchronize(Classes::TThread* AThread, Classes::TThreadMethod AMethod){ Classes::TThread::Synchronize(AThread, AMethod); }
	inline void __fastcall  Synchronize(Classes::TThread* AThread, Classes::_di_TThreadProcedure AThreadProc){ Classes::TThread::Synchronize(AThread, AThreadProc); }
	
};


class DELPHICLASS TIdThreadWithTask;
class PASCALIMPLEMENTATION TIdThreadWithTask : public TIdThread
{
	typedef TIdThread inherited;
	
protected:
	Idtask::TIdTask* FTask;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall BeforeRun(void);
	virtual void __fastcall Run(void);
	virtual void __fastcall DoException(Sysutils::Exception* AException);
	void __fastcall SetTask(Idtask::TIdTask* AValue);
	
public:
	__fastcall virtual TIdThreadWithTask(Idtask::TIdTask* ATask, const System::UnicodeString AName);
	__fastcall virtual ~TIdThreadWithTask(void);
	__property Idtask::TIdTask* Task = {read=FTask, write=SetTask};
};


typedef TMetaClass* TIdThreadClass;

typedef TMetaClass* TIdThreadWithTaskClass;

//-- var, const, procedure ---------------------------------------------------
static const Word IdWaitAllThreadsTerminatedCount = 0xea60;
static const Byte IdWaitAllThreadsTerminatedStep = 0xfa;
extern PACKAGE Idthreadsafe::TIdThreadSafeInteger* GThreadCount;

}	/* namespace Idthread */
using namespace Idthread;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdthreadHPP
