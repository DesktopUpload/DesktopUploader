// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idcontainers.pas' rev: 20.00

#ifndef IdcontainersHPP
#define IdcontainersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcontainers
{
//-- type declarations -------------------------------------------------------
typedef int __fastcall (*TIdSortCompare)(System::TObject* AItem1, System::TObject* AItem2);

class DELPHICLASS TIdObjectList;
class PASCALIMPLEMENTATION TIdObjectList : public Classes::TList
{
	typedef Classes::TList inherited;
	
public:
	System::TObject* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	bool FOwnsObjects;
	
protected:
	System::TObject* __fastcall GetItem(int AIndex);
	void __fastcall SetItem(int AIndex, System::TObject* AObject);
	virtual void __fastcall Notify(void * AItemPtr, Classes::TListNotification AAction);
	
public:
	__fastcall TIdObjectList(void)/* overload */;
	__fastcall TIdObjectList(bool AOwnsObjects)/* overload */;
	void __fastcall BubbleSort(TIdSortCompare ACompare);
	HIDESBASE int __fastcall Add(System::TObject* AObject);
	int __fastcall FindInstanceOf(System::TClass AClassRef, bool AMatchExact = true, int AStartPos = 0x0);
	HIDESBASE int __fastcall IndexOf(System::TObject* AObject);
	HIDESBASE int __fastcall Remove(System::TObject* AObject);
	HIDESBASE void __fastcall Insert(int AIndex, System::TObject* AObject);
	HIDESBASE void __fastcall Assign(TIdObjectList* Source);
	__property System::TObject* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TIdObjectList(void) { }
	
};


typedef int __fastcall (*TIdStringListSortCompare)(Classes::TStringList* List, int Index1, int Index2);

class DELPHICLASS TIdBubbleSortStringList;
class PASCALIMPLEMENTATION TIdBubbleSortStringList : public Classes::TStringList
{
	typedef Classes::TStringList inherited;
	
public:
	virtual void __fastcall BubbleSort(TIdStringListSortCompare ACompare);
public:
	/* TStringList.Create */ inline __fastcall TIdBubbleSortStringList(void)/* overload */ : Classes::TStringList() { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TIdBubbleSortStringList(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcontainers */
using namespace Idcontainers;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdcontainersHPP
