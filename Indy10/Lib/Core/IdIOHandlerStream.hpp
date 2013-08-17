// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idiohandlerstream.pas' rev: 20.00

#ifndef IdiohandlerstreamHPP
#define IdiohandlerstreamHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idstream.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idiohandlerstream
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdIOHandlerStreamType { stRead, stWrite, stReadWrite };
#pragma option pop

class DELPHICLASS TIdIOHandlerStream;
typedef void __fastcall (__closure *TIdOnGetStreams)(TIdIOHandlerStream* ASender, Classes::TStream* &VReceiveStream, Classes::TStream* &VSendStream);

class PASCALIMPLEMENTATION TIdIOHandlerStream : public Idiohandler::TIdIOHandler
{
	typedef Idiohandler::TIdIOHandler inherited;
	
protected:
	bool FFreeStreams;
	TIdOnGetStreams FOnGetStreams;
	Classes::TStream* FReceiveStream;
	Classes::TStream* FSendStream;
	TIdIOHandlerStreamType FStreamType;
	virtual void __fastcall InitComponent(void);
	virtual int __fastcall ReadDataFromSource(Sysutils::TBytes &VBuffer);
	virtual int __fastcall WriteDataToTarget(const Sysutils::TBytes ABuffer, const int AOffset, const int ALength);
	virtual bool __fastcall SourceIsAvailable(void);
	
public:
	virtual void __fastcall CheckForDisconnect(bool ARaiseExceptionIfDisconnected = true, bool AIgnoreBuffer = false);
	__fastcall virtual TIdIOHandlerStream(Classes::TComponent* AOwner, Classes::TStream* AReceiveStream, Classes::TStream* ASendStream)/* overload */;
	__fastcall TIdIOHandlerStream(Classes::TComponent* AOwner)/* overload */;
	virtual bool __fastcall Connected(void);
	virtual void __fastcall Close(void);
	virtual void __fastcall Open(void);
	virtual bool __fastcall Readable(int AMSec = 0xffffffff);
	__property Classes::TStream* ReceiveStream = {read=FReceiveStream};
	__property Classes::TStream* SendStream = {read=FSendStream};
	
__published:
	__property bool FreeStreams = {read=FFreeStreams, write=FFreeStreams, nodefault};
	__property TIdIOHandlerStreamType StreamType = {read=FStreamType, nodefault};
	__property TIdOnGetStreams OnGetStreams = {read=FOnGetStreams, write=FOnGetStreams};
public:
	/* TIdIOHandler.Destroy */ inline __fastcall virtual ~TIdIOHandlerStream(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idiohandlerstream */
using namespace Idiohandlerstream;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdiohandlerstreamHPP
