// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtrivialftpserver.pas' rev: 20.00

#ifndef IdtrivialftpserverHPP
#define IdtrivialftpserverHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idassignednumbers.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idthreadsafe.hpp>	// Pascal unit
#include <Idtrivialftpbase.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idudpserver.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtrivialftpserver
{
//-- type declarations -------------------------------------------------------
struct TPeerInfo
{
	
public:
	System::UnicodeString PeerIP;
	int PeerPort;
};


typedef void __fastcall (__closure *TAccessFileEvent)(System::TObject* Sender, System::UnicodeString &FileName, const TPeerInfo &PeerInfo, bool &GrantAccess, Classes::TStream* &AStream, bool &FreeStreamOnComplete);

typedef void __fastcall (__closure *TTransferCompleteEvent)(System::TObject* Sender, const bool Success, const TPeerInfo &PeerInfo, Classes::TStream* &AStream, const bool WriteOperation);

class DELPHICLASS TIdTrivialFTPServer;
class PASCALIMPLEMENTATION TIdTrivialFTPServer : public Idudpserver::TIdUDPServer
{
	typedef Idudpserver::TIdUDPServer inherited;
	
protected:
	Idthreadsafe::TIdThreadSafeList* FThreadList;
	TTransferCompleteEvent FOnTransferComplete;
	TAccessFileEvent FOnReadFile;
	TAccessFileEvent FOnWriteFile;
	Idtrivialftpbase::TIdTFTPMode __fastcall StrToMode(System::UnicodeString mode);
	virtual void __fastcall DoReadFile(System::UnicodeString FileName, const Idtrivialftpbase::TIdTFTPMode Mode, const TPeerInfo &PeerInfo, int RequestedBlockSize = 0x0);
	virtual void __fastcall DoWriteFile(System::UnicodeString FileName, const Idtrivialftpbase::TIdTFTPMode Mode, const TPeerInfo &PeerInfo, int RequestedBlockSize = 0x0);
	virtual void __fastcall DoTransferComplete(const bool Success, const TPeerInfo &PeerInfo, Classes::TStream* &SourceStream, const bool WriteOperation);
	virtual void __fastcall DoUDPRead(Idudpserver::TIdUDPListenerThread* AThread, const Sysutils::TBytes AData, Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall InitComponent(void);
	
public:
	int __fastcall ActiveThreads(void);
	__fastcall virtual ~TIdTrivialFTPServer(void);
	
__published:
	__property TAccessFileEvent OnReadFile = {read=FOnReadFile, write=FOnReadFile};
	__property TAccessFileEvent OnWriteFile = {read=FOnWriteFile, write=FOnWriteFile};
	__property TTransferCompleteEvent OnTransferComplete = {read=FOnTransferComplete, write=FOnTransferComplete};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTrivialFTPServer(Classes::TComponent* AOwner)/* overload */ : Idudpserver::TIdUDPServer(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtrivialftpserver */
using namespace Idtrivialftpserver;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtrivialftpserverHPP
