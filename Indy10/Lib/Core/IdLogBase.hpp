// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idlogbase.pas' rev: 20.00

#ifndef IdlogbaseHPP
#define IdlogbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdLogBase;
class PASCALIMPLEMENTATION TIdLogBase : public Idintercept::TIdConnectionIntercept
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
protected:
	bool FActive;
	bool FLogTime;
	bool FReplaceCRLF;
	bool FStreamedActive;
	virtual void __fastcall InitComponent(void);
	virtual void __fastcall LogStatus(const System::UnicodeString AText) = 0 ;
	virtual void __fastcall LogReceivedData(const System::UnicodeString AText, const System::UnicodeString AData) = 0 ;
	virtual void __fastcall LogSentData(const System::UnicodeString AText, const System::UnicodeString AData) = 0 ;
	virtual void __fastcall SetActive(bool AValue);
	virtual void __fastcall Loaded(void);
	System::UnicodeString __fastcall ReplaceCR(const System::UnicodeString AString);
	
public:
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(void);
	virtual void __fastcall Connect(Classes::TComponent* AConnection);
	__fastcall virtual ~TIdLogBase(void);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall Receive(Sysutils::TBytes &ABuffer);
	virtual void __fastcall Send(Sysutils::TBytes &ABuffer);
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool LogTime = {read=FLogTime, write=FLogTime, default=1};
	__property bool ReplaceCRLF = {read=FReplaceCRLF, write=FReplaceCRLF, default=1};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdLogBase(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdConnectionIntercept(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idlogbase */
using namespace Idlogbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdlogbaseHPP
