// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idnetworkcalculator.pas' rev: 20.00

#ifndef IdnetworkcalculatorHPP
#define IdnetworkcalculatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idstruct.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idnetworkcalculator
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TNetworkClass { ID_NET_CLASS_A, ID_NET_CLASS_B, ID_NET_CLASS_C, ID_NET_CLASS_D, ID_NET_CLASS_E };
#pragma option pop

#pragma option push -b-
enum TIdIPAddressType { IPLocalHost, IPLocalNetwork, IPReserved, IPInternetHost, IPPrivateNetwork, IPLoopback, IPMulticast, IPFutureUse, IPGlobalBroadcast };
#pragma option pop

class DELPHICLASS TIpProperty;
class PASCALIMPLEMENTATION TIpProperty : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	bool FReadOnly;
	StaticArray<bool, 32> FBitArray;
	StaticArray<System::Byte, 4> FValue;
	Classes::TNotifyEvent FOnChange;
	TIdIPAddressType __fastcall GetAddressType(void);
	System::UnicodeString __fastcall GetAsBinaryString();
	unsigned __fastcall GetAsDoubleWord(void);
	System::UnicodeString __fastcall GetAsString();
	bool __fastcall GetBit(System::Byte Index);
	System::Byte __fastcall GetByte(int Index);
	void __fastcall SetAsBinaryString(const System::UnicodeString Value);
	void __fastcall SetAsDoubleWord(const unsigned Value);
	void __fastcall SetAsString(const System::UnicodeString Value);
	void __fastcall SetBit(System::Byte Index, const bool Value);
	void __fastcall SetByte(int Index, const System::Byte Value);
	__property bool IsReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	
public:
	__fastcall virtual TIpProperty(void);
	__fastcall virtual ~TIpProperty(void);
	virtual void __fastcall SetAll(System::Byte One, System::Byte Two, System::Byte Three, System::Byte Four);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property bool Bits[System::Byte Index] = {read=GetBit, write=SetBit};
	__property TIdIPAddressType AddressType = {read=GetAddressType, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property System::Byte Byte1 = {read=GetByte, write=SetByte, stored=false, index=0, nodefault};
	__property System::Byte Byte2 = {read=GetByte, write=SetByte, stored=false, index=1, nodefault};
	__property System::Byte Byte3 = {read=GetByte, write=SetByte, stored=false, index=2, nodefault};
	__property System::Byte Byte4 = {read=GetByte, write=SetByte, stored=false, index=3, nodefault};
	__property unsigned AsDoubleWord = {read=GetAsDoubleWord, write=SetAsDoubleWord, stored=false, nodefault};
	__property System::UnicodeString AsBinaryString = {read=GetAsBinaryString, write=SetAsBinaryString, stored=false};
	__property System::UnicodeString AsString = {read=GetAsString, write=SetAsString};
};


class DELPHICLASS TIdNetworkCalculator;
class PASCALIMPLEMENTATION TIdNetworkCalculator : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Classes::TStrings* FListIP;
	unsigned FNetworkMaskLength;
	TIpProperty* FNetworkMask;
	TIpProperty* FNetworkAddress;
	TNetworkClass FNetworkClass;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnGenIPList;
	void __fastcall FillIPList(void);
	System::UnicodeString __fastcall GetNetworkClassAsString();
	bool __fastcall GetIsAddressRoutable(void);
	Classes::TStrings* __fastcall GetListIP(void);
	void __fastcall SetNetworkAddress(const TIpProperty* Value);
	void __fastcall SetNetworkMask(const TIpProperty* Value);
	void __fastcall SetNetworkMaskLength(const unsigned Value);
	void __fastcall NetMaskChanged(System::TObject* Sender);
	void __fastcall NetAddressChanged(System::TObject* Sender);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdNetworkCalculator(void);
	bool __fastcall IsAddressInNetwork(const System::UnicodeString Address);
	unsigned __fastcall NumIP(void);
	System::UnicodeString __fastcall StartIP();
	System::UnicodeString __fastcall EndIP();
	__property Classes::TStrings* ListIP = {read=GetListIP};
	__property TNetworkClass NetworkClass = {read=FNetworkClass, nodefault};
	__property System::UnicodeString NetworkClassAsString = {read=GetNetworkClassAsString};
	__property bool IsAddressRoutable = {read=GetIsAddressRoutable, nodefault};
	
__published:
	__property TIpProperty* NetworkAddress = {read=FNetworkAddress, write=SetNetworkAddress};
	__property TIpProperty* NetworkMask = {read=FNetworkMask, write=SetNetworkMask};
	__property unsigned NetworkMaskLength = {read=FNetworkMaskLength, write=SetNetworkMaskLength, default=32};
	__property Classes::TNotifyEvent OnGenIPList = {read=FOnGenIPList, write=FOnGenIPList};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdNetworkCalculator(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt ID_NC_MASK_LENGTH = 0x20;
static const TNetworkClass ID_NETWORKCLASS = (TNetworkClass)(0);

}	/* namespace Idnetworkcalculator */
using namespace Idnetworkcalculator;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdnetworkcalculatorHPP
