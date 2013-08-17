// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idtcpstream.pas' rev: 20.00

#ifndef IdtcpstreamHPP
#define IdtcpstreamHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idtcpconnection.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtcpstream
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdTCPStream;
class PASCALIMPLEMENTATION TIdTCPStream : public Idglobal::TIdBaseStream
{
	typedef Idglobal::TIdBaseStream inherited;
	
protected:
	Idtcpconnection::TIdTCPConnection* FConnection;
	virtual int __fastcall IdRead(Sysutils::TBytes &VBuffer, int AOffset, int ACount);
	virtual int __fastcall IdWrite(const Sysutils::TBytes ABuffer, int AOffset, int ACount);
	virtual __int64 __fastcall IdSeek(const __int64 AOffset, Classes::TSeekOrigin AOrigin);
	virtual void __fastcall IdSetSize(__int64 ASize);
	
public:
	__fastcall TIdTCPStream(Idtcpconnection::TIdTCPConnection* AConnection);
	__property Idtcpconnection::TIdTCPConnection* Connection = {read=FConnection};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdTCPStream(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtcpstream */
using namespace Idtcpstream;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdtcpstreamHPP
