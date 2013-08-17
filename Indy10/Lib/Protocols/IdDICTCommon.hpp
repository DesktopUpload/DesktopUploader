// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddictcommon.pas' rev: 20.00

#ifndef IddictcommonHPP
#define IddictcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddictcommon
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMatchItem;
class PASCALIMPLEMENTATION TIdMatchItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FDB;
	System::UnicodeString FWord;
	
__published:
	__property System::UnicodeString DB = {read=FDB, write=FDB};
	__property System::UnicodeString Word = {read=FWord, write=FWord};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdMatchItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMatchItem(void) { }
	
};


class DELPHICLASS TIdMatchList;
class PASCALIMPLEMENTATION TIdMatchList : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdMatchItem* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	TIdMatchItem* __fastcall GetItems(int AIndex);
	void __fastcall SetItems(int AIndex, const TIdMatchItem* AValue);
	
public:
	__fastcall virtual TIdMatchList(void);
	int __fastcall IndexOf(TIdMatchItem* AItem);
	HIDESBASE TIdMatchItem* __fastcall Add(void);
	__property TIdMatchItem* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdMatchList(void) { }
	
};


class DELPHICLASS TIdGeneric;
class PASCALIMPLEMENTATION TIdGeneric : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FName;
	System::UnicodeString FDesc;
	
__published:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property System::UnicodeString Desc = {read=FDesc, write=FDesc};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdGeneric(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdGeneric(void) { }
	
};


class DELPHICLASS TIdStrategy;
class PASCALIMPLEMENTATION TIdStrategy : public TIdGeneric
{
	typedef TIdGeneric inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdStrategy(Classes::TCollection* Collection) : TIdGeneric(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdStrategy(void) { }
	
};


class DELPHICLASS TIdStrategyList;
class PASCALIMPLEMENTATION TIdStrategyList : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdStrategy* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	TIdStrategy* __fastcall GetItems(int AIndex);
	void __fastcall SetItems(int AIndex, const TIdStrategy* AValue);
	
public:
	__fastcall virtual TIdStrategyList(void);
	int __fastcall IndexOf(TIdStrategy* AItem);
	HIDESBASE TIdStrategy* __fastcall Add(void);
	__property TIdStrategy* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdStrategyList(void) { }
	
};


class DELPHICLASS TIdDBInfo;
class PASCALIMPLEMENTATION TIdDBInfo : public TIdGeneric
{
	typedef TIdGeneric inherited;
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdDBInfo(Classes::TCollection* Collection) : TIdGeneric(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdDBInfo(void) { }
	
};


class DELPHICLASS TIdDBList;
class PASCALIMPLEMENTATION TIdDBList : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdDBInfo* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	TIdDBInfo* __fastcall GetItems(int AIndex);
	void __fastcall SetItems(int AIndex, const TIdDBInfo* AValue);
	
public:
	__fastcall virtual TIdDBList(void);
	int __fastcall IndexOf(TIdDBInfo* AItem);
	HIDESBASE TIdDBInfo* __fastcall Add(void);
	__property TIdDBInfo* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdDBList(void) { }
	
};


class DELPHICLASS TIdDefinition;
class PASCALIMPLEMENTATION TIdDefinition : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FWord;
	Classes::TStrings* FDefinition;
	TIdDBInfo* FDB;
	void __fastcall SetDefinition(Classes::TStrings* AValue);
	
public:
	__fastcall virtual TIdDefinition(Classes::TCollection* AOwner);
	__fastcall virtual ~TIdDefinition(void);
	
__published:
	__property System::UnicodeString Word = {read=FWord, write=FWord};
	__property TIdDBInfo* DB = {read=FDB, write=FDB};
	__property Classes::TStrings* Definition = {read=FDefinition, write=SetDefinition};
};


class DELPHICLASS TIdDefinitions;
class PASCALIMPLEMENTATION TIdDefinitions : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdDefinition* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	TIdDefinition* __fastcall GetItems(int AIndex);
	void __fastcall SetItems(int AIndex, const TIdDefinition* AValue);
	
public:
	__fastcall virtual TIdDefinitions(void);
	int __fastcall IndexOf(TIdDefinition* AItem);
	HIDESBASE TIdDefinition* __fastcall Add(void);
	__property TIdDefinition* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdDefinitions(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddictcommon */
using namespace Iddictcommon;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddictcommonHPP
