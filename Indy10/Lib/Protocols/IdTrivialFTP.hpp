// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtrivialftp.pas' rev: 20.00

#ifndef IdtrivialftpHPP
#define IdtrivialftpHPP

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
#include <Idtrivialftpbase.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtrivialftp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTrivialFTP;
class PASCALIMPLEMENTATION TIdTrivialFTP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	Idtrivialftpbase::TIdTFTPMode FMode;
	int FRequestedBlockSize;
	System::Word FPeerPort;
	System::UnicodeString FPeerIP;
	System::UnicodeString __fastcall ModeToStr();
	void __fastcall CheckOptionAck(const System::UnicodeString optionpacket);
	void __fastcall SendAck(const System::Word BlockNumber);
	void __fastcall RaiseError(const System::UnicodeString errorpacket);
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall Get(const System::UnicodeString ServerFile, Classes::TStream* DestinationStream)/* overload */;
	void __fastcall Get(const System::UnicodeString ServerFile, const System::UnicodeString LocalFile)/* overload */;
	void __fastcall Put(Classes::TStream* SourceStream, const System::UnicodeString ServerFile)/* overload */;
	void __fastcall Put(const System::UnicodeString LocalFile, const System::UnicodeString ServerFile)/* overload */;
	
__published:
	__property Idtrivialftpbase::TIdTFTPMode TransferMode = {read=FMode, write=FMode, default=1};
	__property int RequestedBlockSize = {read=FRequestedBlockSize, write=FRequestedBlockSize, default=1500};
	__property OnWork;
	__property OnWorkBegin;
	__property OnWorkEnd;
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdTrivialFTP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdTrivialFTP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Idtrivialftpbase::TIdTFTPMode GTransferMode = (Idtrivialftpbase::TIdTFTPMode)(1);
static const Word GFRequestedBlockSize = 0x5dc;
static const Word GReceiveTimeout = 0xfa0;

}	/* namespace Idtrivialftp */
using namespace Idtrivialftp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtrivialftpHPP
