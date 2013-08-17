// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsntp.pas' rev: 20.00

#ifndef IdsntpHPP
#define IdsntpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsntp
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct TNTPGram
{
	
public:
	System::Byte Head1;
	System::Byte Head2;
	System::Byte Head3;
	System::Byte Head4;
	unsigned RootDelay;
	unsigned RootDispersion;
	unsigned RefID;
	unsigned Ref1;
	unsigned Ref2;
	unsigned Org1;
	unsigned Org2;
	unsigned Rcv1;
	unsigned Rcv2;
	unsigned Xmit1;
	unsigned Xmit2;
};
#pragma pack(pop)


class DELPHICLASS TIdSNTP;
class PASCALIMPLEMENTATION TIdSNTP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	System::TDateTime FDestinationTimestamp;
	System::TDateTime FLocalClockOffset;
	System::TDateTime FOriginateTimestamp;
	System::TDateTime FReceiveTimestamp;
	System::TDateTime FRoundTripDelay;
	System::TDateTime FTransmitTimestamp;
	bool FCheckStratum;
	void __fastcall DateTimeToNTP(System::TDateTime ADateTime, unsigned &Second, unsigned &Fraction);
	System::TDateTime __fastcall NTPToDateTime(unsigned Second, unsigned Fraction);
	bool __fastcall Disregard(const TNTPGram &ANTPMessage);
	System::TDateTime __fastcall GetAdjustmentTime(void);
	System::TDateTime __fastcall GetDateTime(void);
	virtual void __fastcall InitComponent(void);
	
public:
	bool __fastcall SyncTime(void);
	__property System::TDateTime AdjustmentTime = {read=GetAdjustmentTime};
	__property System::TDateTime DateTime = {read=GetDateTime};
	__property System::TDateTime RoundTripDelay = {read=FRoundTripDelay};
	__property bool CheckStratum = {read=FCheckStratum, write=FCheckStratum, default=1};
public:
	/* TIdUDPClient.Destroy */ inline __fastcall virtual ~TIdSNTP(void) { }
	
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdSNTP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define NTPMaxInt  (4.294967E+09)

}	/* namespace Idsntp */
using namespace Idsntp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsntpHPP
