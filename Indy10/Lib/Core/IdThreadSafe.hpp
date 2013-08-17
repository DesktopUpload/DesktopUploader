// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idthreadsafe.pas' rev: 20.00

#ifndef IdthreadsafeHPP
#define IdthreadsafeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idthreadsafe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdThreadSafe;
class PASCALIMPLEMENTATION TIdThreadSafe : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Idglobal::TIdCriticalSection* FCriticalSection;
	
public:
	__fastcall virtual TIdThreadSafe(void);
	__fastcall virtual ~TIdThreadSafe(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
};


class DELPHICLASS TIdThreadSafeInteger;
class PASCALIMPLEMENTATION TIdThreadSafeInteger : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	int FValue;
	int __fastcall GetValue(void);
	void __fastcall SetValue(const int AValue);
	
public:
	int __fastcall Decrement(void)/* overload */;
	int __fastcall Decrement(const int AValue)/* overload */;
	int __fastcall Increment(void)/* overload */;
	int __fastcall Increment(const int AValue)/* overload */;
	__property int Value = {read=GetValue, write=SetValue, nodefault};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeInteger(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeInteger(void) { }
	
};


class DELPHICLASS TIdThreadSafeBoolean;
class PASCALIMPLEMENTATION TIdThreadSafeBoolean : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	bool FValue;
	bool __fastcall GetValue(void);
	void __fastcall SetValue(const bool AValue);
	
public:
	bool __fastcall Toggle(void);
	__property bool Value = {read=GetValue, write=SetValue, nodefault};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeBoolean(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeBoolean(void) { }
	
};


class DELPHICLASS TIdThreadSafeCardinal;
class PASCALIMPLEMENTATION TIdThreadSafeCardinal : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	unsigned FValue;
	unsigned __fastcall GetValue(void);
	void __fastcall SetValue(const unsigned AValue);
	
public:
	unsigned __fastcall Decrement(void)/* overload */;
	unsigned __fastcall Decrement(const unsigned AValue)/* overload */;
	unsigned __fastcall Increment(void)/* overload */;
	unsigned __fastcall Increment(const unsigned AValue)/* overload */;
	__property unsigned Value = {read=GetValue, write=SetValue, nodefault};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeCardinal(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeCardinal(void) { }
	
};


class DELPHICLASS TIdThreadSafeInt64;
class PASCALIMPLEMENTATION TIdThreadSafeInt64 : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	__int64 FValue;
	__int64 __fastcall GetValue(void);
	void __fastcall SetValue(const __int64 AValue);
	
public:
	__int64 __fastcall Decrement(void)/* overload */;
	__int64 __fastcall Decrement(const __int64 AValue)/* overload */;
	__int64 __fastcall Increment(void)/* overload */;
	__int64 __fastcall Increment(const __int64 AValue)/* overload */;
	__property __int64 Value = {read=GetValue, write=SetValue};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeInt64(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeInt64(void) { }
	
};


class DELPHICLASS TIdThreadSafeString;
class PASCALIMPLEMENTATION TIdThreadSafeString : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	System::UnicodeString FValue;
	System::UnicodeString __fastcall GetValue();
	void __fastcall SetValue(const System::UnicodeString AValue);
	
public:
	void __fastcall Append(const System::UnicodeString AValue);
	void __fastcall Prepend(const System::UnicodeString AValue);
	__property System::UnicodeString Value = {read=GetValue, write=SetValue};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeString(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeString(void) { }
	
};


class DELPHICLASS TIdThreadSafeStringList;
class PASCALIMPLEMENTATION TIdThreadSafeStringList : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	Classes::TStringList* FValue;
	System::UnicodeString __fastcall GetValue(const System::UnicodeString AName);
	void __fastcall SetValue(const System::UnicodeString AName, const System::UnicodeString AValue);
	
public:
	__fastcall virtual TIdThreadSafeStringList(void);
	__fastcall virtual ~TIdThreadSafeStringList(void);
	void __fastcall Add(const System::UnicodeString AItem);
	void __fastcall AddObject(const System::UnicodeString AItem, System::TObject* AObject);
	void __fastcall Clear(void);
	bool __fastcall Empty(void);
	HIDESBASE Classes::TStringList* __fastcall Lock(void);
	System::TObject* __fastcall ObjectByItem(const System::UnicodeString AItem);
	void __fastcall Remove(const System::UnicodeString AItem);
	HIDESBASE void __fastcall Unlock(void);
	__property System::UnicodeString Values[const System::UnicodeString AName] = {read=GetValue, write=SetValue};
};


class DELPHICLASS TIdThreadSafeDateTime;
class PASCALIMPLEMENTATION TIdThreadSafeDateTime : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	System::TDateTime FValue;
	System::TDateTime __fastcall GetValue(void);
	void __fastcall SetValue(const System::TDateTime AValue);
	
public:
	void __fastcall Add(const System::TDateTime AValue);
	void __fastcall Subtract(const System::TDateTime AValue);
	__property System::TDateTime Value = {read=GetValue, write=SetValue};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeDateTime(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeDateTime(void) { }
	
};


class DELPHICLASS TIdThreadSafeDouble;
class PASCALIMPLEMENTATION TIdThreadSafeDouble : public TIdThreadSafe
{
	typedef TIdThreadSafe inherited;
	
protected:
	double FValue;
	double __fastcall GetValue(void);
	void __fastcall SetValue(const double AValue);
	
public:
	void __fastcall Add(const double AValue);
	void __fastcall Subtract(const double AValue);
	__property double Value = {read=GetValue, write=SetValue};
public:
	/* TIdThreadSafe.Create */ inline __fastcall virtual TIdThreadSafeDouble(void) : TIdThreadSafe() { }
	/* TIdThreadSafe.Destroy */ inline __fastcall virtual ~TIdThreadSafeDouble(void) { }
	
};


class DELPHICLASS TIdThreadSafeList;
class PASCALIMPLEMENTATION TIdThreadSafeList : public Classes::TThreadList
{
	typedef Classes::TThreadList inherited;
	
private:
	bool FOwnsObjects;
	
public:
	void __fastcall Assign(Classes::TThreadList* AThreadList)/* overload */;
	void __fastcall Assign(Classes::TList* AList)/* overload */;
	__fastcall virtual TIdThreadSafeList(void);
	__fastcall virtual ~TIdThreadSafeList(void);
	bool __fastcall IsCountLessThan(const unsigned AValue);
	int __fastcall Count(void);
	bool __fastcall IsEmpty(void);
	System::TObject* __fastcall Pop(void);
	System::TObject* __fastcall Pull(void);
	void __fastcall ClearAndFree(void);
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idthreadsafe */
using namespace Idthreadsafe;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdthreadsafeHPP
