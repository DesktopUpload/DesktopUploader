// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idlogstream.pas' rev: 20.00

#ifndef IdlogstreamHPP
#define IdlogstreamHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idlogbase.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogstream
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdLogStream;
class PASCALIMPLEMENTATION TIdLogStream : public Idlogbase::TIdLogBase
{
	typedef Idlogbase::TIdLogBase inherited;
	
protected:
	bool FFreeStreams;
	Classes::TStream* FReceiveStream;
	Classes::TStream* FSendStream;
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall LogStatus(const System::UnicodeString AText);
	virtual void __fastcall LogReceivedData(const System::UnicodeString AText, const System::UnicodeString AData);
	virtual void __fastcall LogSentData(const System::UnicodeString AText, const System::UnicodeString AData);
	
public:
	virtual void __fastcall Disconnect(void);
	__property bool FreeStreams = {read=FFreeStreams, write=FFreeStreams, nodefault};
	__property Classes::TStream* ReceiveStream = {read=FReceiveStream, write=FReceiveStream};
	__property Classes::TStream* SendStream = {read=FSendStream, write=FSendStream};
public:
	/* TIdLogBase.Destroy */ inline __fastcall virtual ~TIdLogStream(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdLogStream(Classes::TComponent* AOwner)/* overload */ : Idlogbase::TIdLogBase(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idlogstream */
using namespace Idlogstream;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdlogstreamHPP
