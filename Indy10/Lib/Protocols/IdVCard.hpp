// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idvcard.pas' rev: 20.00

#ifndef IdvcardHPP
#define IdvcardHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idvcard
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdVCardEmbeddedObject;
class PASCALIMPLEMENTATION TIdVCardEmbeddedObject : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FObjectType;
	System::UnicodeString FObjectURL;
	bool FBase64Encoded;
	Classes::TStrings* FEmbeddedData;
	void __fastcall SetEmbeddedData(const Classes::TStrings* Value);
	
public:
	__fastcall TIdVCardEmbeddedObject(void);
	__fastcall virtual ~TIdVCardEmbeddedObject(void);
	
__published:
	__property System::UnicodeString ObjectType = {read=FObjectType, write=FObjectType};
	__property System::UnicodeString ObjectURL = {read=FObjectURL, write=FObjectURL};
	__property bool Base64Encoded = {read=FBase64Encoded, write=FBase64Encoded, nodefault};
	__property Classes::TStrings* EmbeddedData = {read=FEmbeddedData, write=SetEmbeddedData};
};


class DELPHICLASS TIdVCardBusinessInfo;
class PASCALIMPLEMENTATION TIdVCardBusinessInfo : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FTitle;
	System::UnicodeString FRole;
	System::UnicodeString FOrganization;
	Classes::TStrings* FDivisions;
	void __fastcall SetDivisions(Classes::TStrings* Value);
	
public:
	__fastcall TIdVCardBusinessInfo(void);
	__fastcall virtual ~TIdVCardBusinessInfo(void);
	
__published:
	__property System::UnicodeString Organization = {read=FOrganization, write=FOrganization};
	__property Classes::TStrings* Divisions = {read=FDivisions, write=SetDivisions};
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
	__property System::UnicodeString Role = {read=FRole, write=FRole};
};


class DELPHICLASS TIdVCardGeog;
class PASCALIMPLEMENTATION TIdVCardGeog : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	double FLatitude;
	double FLongitude;
	System::UnicodeString FTimeZoneStr;
	
__published:
	__property double Latitude = {read=FLatitude, write=FLatitude};
	__property double Longitude = {read=FLongitude, write=FLongitude};
	__property System::UnicodeString TimeZoneStr = {read=FTimeZoneStr, write=FTimeZoneStr};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIdVCardGeog(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TIdVCardGeog(void) : Classes::TPersistent() { }
	
};


#pragma option push -b-
enum TIdPhoneAttribute { tpaHome, tpaVoiceMessaging, tpaWork, tpaPreferred, tpaVoice, tpaFax, tpaCellular, tpaVideo, tpaBBS, tpaModem, tpaCar, tpaISDN, tpaPCS, tpaPager };
#pragma option pop

typedef Set<TIdPhoneAttribute, tpaHome, tpaPager>  TIdPhoneAttributes;

class DELPHICLASS TIdCardPhoneNumber;
class PASCALIMPLEMENTATION TIdCardPhoneNumber : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	TIdPhoneAttributes FPhoneAttributes;
	System::UnicodeString FNumber;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TIdPhoneAttributes PhoneAttributes = {read=FPhoneAttributes, write=FPhoneAttributes, nodefault};
	__property System::UnicodeString Number = {read=FNumber, write=FNumber};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdCardPhoneNumber(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdCardPhoneNumber(void) { }
	
};


class DELPHICLASS TIdVCardTelephones;
class PASCALIMPLEMENTATION TIdVCardTelephones : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdCardPhoneNumber* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdCardPhoneNumber* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdCardPhoneNumber* Value);
	
public:
	__fastcall TIdVCardTelephones(Classes::TPersistent* AOwner);
	HIDESBASE TIdCardPhoneNumber* __fastcall Add(void);
	__property TIdCardPhoneNumber* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdVCardTelephones(void) { }
	
};


#pragma option push -b-
enum TIdCardAddressAttribute { tatHome, tatDomestic, tatInternational, tatPostal, tatParcel, tatWork, tatPreferred };
#pragma option pop

typedef Set<TIdCardAddressAttribute, tatHome, tatPreferred>  TIdCardAddressAttributes;

class DELPHICLASS TIdCardAddressItem;
class PASCALIMPLEMENTATION TIdCardAddressItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	TIdCardAddressAttributes FAddressAttributes;
	System::UnicodeString FPOBox;
	System::UnicodeString FExtendedAddress;
	System::UnicodeString FStreetAddress;
	System::UnicodeString FLocality;
	System::UnicodeString FRegion;
	System::UnicodeString FPostalCode;
	System::UnicodeString FNation;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TIdCardAddressAttributes AddressAttributes = {read=FAddressAttributes, write=FAddressAttributes, nodefault};
	__property System::UnicodeString POBox = {read=FPOBox, write=FPOBox};
	__property System::UnicodeString ExtendedAddress = {read=FExtendedAddress, write=FExtendedAddress};
	__property System::UnicodeString StreetAddress = {read=FStreetAddress, write=FStreetAddress};
	__property System::UnicodeString Locality = {read=FLocality, write=FLocality};
	__property System::UnicodeString Region = {read=FRegion, write=FRegion};
	__property System::UnicodeString PostalCode = {read=FPostalCode, write=FPostalCode};
	__property System::UnicodeString Nation = {read=FNation, write=FNation};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdCardAddressItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdCardAddressItem(void) { }
	
};


class DELPHICLASS TIdVCardAddresses;
class PASCALIMPLEMENTATION TIdVCardAddresses : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdCardAddressItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdCardAddressItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdCardAddressItem* Value);
	
public:
	__fastcall TIdVCardAddresses(Classes::TPersistent* AOwner);
	HIDESBASE TIdCardAddressItem* __fastcall Add(void);
	__property TIdCardAddressItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdVCardAddresses(void) { }
	
};


class DELPHICLASS TIdVCardMailingLabelItem;
class PASCALIMPLEMENTATION TIdVCardMailingLabelItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
private:
	TIdCardAddressAttributes FAddressAttributes;
	Classes::TStrings* FMailingLabel;
	void __fastcall SetMailingLabel(Classes::TStrings* Value);
	
public:
	__fastcall virtual TIdVCardMailingLabelItem(Classes::TCollection* Collection);
	__fastcall virtual ~TIdVCardMailingLabelItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TIdCardAddressAttributes AddressAttributes = {read=FAddressAttributes, write=FAddressAttributes, nodefault};
	__property Classes::TStrings* MailingLabel = {read=FMailingLabel, write=SetMailingLabel};
};


class DELPHICLASS TIdVCardMailingLabels;
class PASCALIMPLEMENTATION TIdVCardMailingLabels : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdVCardMailingLabelItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdVCardMailingLabelItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdVCardMailingLabelItem* Value);
	
public:
	__fastcall TIdVCardMailingLabels(Classes::TPersistent* AOwner);
	HIDESBASE TIdVCardMailingLabelItem* __fastcall Add(void);
	__property TIdVCardMailingLabelItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdVCardMailingLabels(void) { }
	
};


#pragma option push -b-
enum TIdVCardEMailType { ematAOL, ematAppleLink, ematATT, ematCIS, emateWorld, ematInternet, ematIBMMail, ematMCIMail, ematPowerShare, ematProdigy, ematTelex, ematX400 };
#pragma option pop

class DELPHICLASS TIdVCardEMailItem;
class PASCALIMPLEMENTATION TIdVCardEMailItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	TIdVCardEMailType FEMailType;
	bool FPreferred;
	System::UnicodeString FAddress;
	
public:
	__fastcall virtual TIdVCardEMailItem(Classes::TCollection* Collection);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TIdVCardEMailType EMailType = {read=FEMailType, write=FEMailType, nodefault};
	__property bool Preferred = {read=FPreferred, write=FPreferred, nodefault};
	__property System::UnicodeString Address = {read=FAddress, write=FAddress};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdVCardEMailItem(void) { }
	
};


class DELPHICLASS TIdVCardEMailAddresses;
class PASCALIMPLEMENTATION TIdVCardEMailAddresses : public Classes::TOwnedCollection
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdVCardEMailItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdVCardEMailItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdVCardEMailItem* Value);
	
public:
	__fastcall TIdVCardEMailAddresses(Classes::TPersistent* AOwner);
	HIDESBASE TIdVCardEMailItem* __fastcall Add(void);
	__property TIdVCardEMailItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdVCardEMailAddresses(void) { }
	
};


class DELPHICLASS TIdVCardName;
class PASCALIMPLEMENTATION TIdVCardName : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::UnicodeString FFirstName;
	System::UnicodeString FSurName;
	Classes::TStrings* FOtherNames;
	System::UnicodeString FPrefix;
	System::UnicodeString FSuffix;
	System::UnicodeString FFormattedName;
	System::UnicodeString FSortName;
	Classes::TStrings* FNickNames;
	void __fastcall SetOtherNames(Classes::TStrings* Value);
	void __fastcall SetNickNames(Classes::TStrings* Value);
	
public:
	__fastcall TIdVCardName(void);
	__fastcall virtual ~TIdVCardName(void);
	
__published:
	__property System::UnicodeString FirstName = {read=FFirstName, write=FFirstName};
	__property System::UnicodeString SurName = {read=FSurName, write=FSurName};
	__property Classes::TStrings* OtherNames = {read=FOtherNames, write=SetOtherNames};
	__property System::UnicodeString FormattedName = {read=FFormattedName, write=FFormattedName};
	__property System::UnicodeString Prefix = {read=FPrefix, write=FPrefix};
	__property System::UnicodeString Suffix = {read=FSuffix, write=FSuffix};
	__property System::UnicodeString SortName = {read=FSortName, write=FSortName};
	__property Classes::TStrings* NickNames = {read=FNickNames, write=SetNickNames};
};


class DELPHICLASS TIdVCard;
class PASCALIMPLEMENTATION TIdVCard : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Classes::TStrings* FComments;
	Classes::TStrings* FCategories;
	TIdVCardBusinessInfo* FBusinessInfo;
	TIdVCardGeog* FGeography;
	TIdVCardName* FFullName;
	Classes::TStrings* FRawForm;
	Classes::TStrings* FURLs;
	System::UnicodeString FEMailProgram;
	TIdVCardEMailAddresses* FEMailAddresses;
	TIdVCardAddresses* FAddresses;
	TIdVCardMailingLabels* FMailingLabels;
	TIdVCardTelephones* FTelephones;
	double FVCardVersion;
	System::UnicodeString FProductID;
	System::UnicodeString FUniqueID;
	System::UnicodeString FClassification;
	System::TDateTime FLastRevised;
	System::TDateTime FBirthDay;
	TIdVCardEmbeddedObject* FPhoto;
	TIdVCardEmbeddedObject* FLogo;
	TIdVCardEmbeddedObject* FSound;
	TIdVCardEmbeddedObject* FKey;
	void __fastcall SetComments(Classes::TStrings* Value);
	void __fastcall SetCategories(Classes::TStrings* Value);
	void __fastcall SetURLs(Classes::TStrings* Value);
	void __fastcall SetVariablesAfterRead(void);
	virtual void __fastcall InitComponent(void);
	
public:
	__fastcall virtual ~TIdVCard(void);
	void __fastcall ReadFromStrings(Classes::TStrings* s);
	__property Classes::TStrings* RawForm = {read=FRawForm};
	
__published:
	__property double VCardVersion = {read=FVCardVersion};
	__property Classes::TStrings* URLs = {read=FURLs, write=SetURLs};
	__property System::UnicodeString ProductID = {read=FProductID, write=FProductID};
	__property System::UnicodeString UniqueID = {read=FUniqueID, write=FUniqueID};
	__property System::UnicodeString Classification = {read=FClassification, write=FClassification};
	__property System::TDateTime BirthDay = {read=FBirthDay, write=FBirthDay};
	__property TIdVCardName* FullName = {read=FFullName, write=FFullName};
	__property System::UnicodeString EMailProgram = {read=FEMailProgram, write=FEMailProgram};
	__property TIdVCardEMailAddresses* EMailAddresses = {read=FEMailAddresses};
	__property TIdVCardTelephones* Telephones = {read=FTelephones};
	__property TIdVCardBusinessInfo* BusinessInfo = {read=FBusinessInfo};
	__property Classes::TStrings* Categories = {read=FCategories, write=SetCategories};
	__property TIdVCardAddresses* Addresses = {read=FAddresses};
	__property TIdVCardMailingLabels* MailingLabels = {read=FMailingLabels};
	__property Classes::TStrings* Comments = {read=FComments, write=SetComments};
	__property TIdVCardEmbeddedObject* Photo = {read=FPhoto};
	__property TIdVCardEmbeddedObject* Logo = {read=FLogo};
	__property TIdVCardEmbeddedObject* Sound = {read=FSound};
	__property TIdVCardEmbeddedObject* Key = {read=FKey};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdVCard(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::TDateTime __fastcall ParseDateTimeStamp(const System::UnicodeString DateString);

}	/* namespace Idvcard */
using namespace Idvcard;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdvcardHPP
