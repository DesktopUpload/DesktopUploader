// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idheaderlist.pas' rev: 20.00

#ifndef IdheaderlistHPP
#define IdheaderlistHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idheaderlist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHeaderList;
class PASCALIMPLEMENTATION TIdHeaderList : public Classes::TStringList
{
	typedef Classes::TStringList inherited;
	
protected:
	System::UnicodeString FNameValueSeparator;
	bool FUnfoldLines;
	bool FFoldLines;
	int FFoldLinesLength;
	void __fastcall DeleteFoldedLines(int Index);
	Classes::TStrings* __fastcall FoldLine(System::UnicodeString AString);
	void __fastcall FoldAndInsert(System::UnicodeString AString, int Index);
	HIDESBASE System::UnicodeString __fastcall GetName(int Index);
	HIDESBASE System::UnicodeString __fastcall GetValue(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetParam(const System::UnicodeString AName, const System::UnicodeString AParam);
	HIDESBASE void __fastcall SetValue(const System::UnicodeString AName, const System::UnicodeString AValue);
	void __fastcall SetParam(const System::UnicodeString AName, const System::UnicodeString AParam, const System::UnicodeString AValue);
	System::UnicodeString __fastcall GetValueFromLine(int ALine);
	System::UnicodeString __fastcall GetNameFromLine(int ALine);
	
public:
	void __fastcall AddStdValues(Classes::TStrings* ASrc);
	void __fastcall AddValue(const System::UnicodeString AName, const System::UnicodeString AValue);
	void __fastcall ConvertToStdValues(Classes::TStrings* ADest);
	__fastcall TIdHeaderList(void);
	void __fastcall Extract(const System::UnicodeString AName, Classes::TStrings* ADest);
	HIDESBASE int __fastcall IndexOfName(const System::UnicodeString AName);
	__property System::UnicodeString Names[int Index] = {read=GetName};
	__property System::UnicodeString Values[const System::UnicodeString Name] = {read=GetValue, write=SetValue};
	__property System::UnicodeString Params[const System::UnicodeString Name][const System::UnicodeString Param] = {read=GetParam, write=SetParam};
	__property System::UnicodeString NameValueSeparator = {read=FNameValueSeparator, write=FNameValueSeparator};
	__property bool UnfoldLines = {read=FUnfoldLines, write=FUnfoldLines, nodefault};
	__property bool FoldLines = {read=FFoldLines, write=FFoldLines, nodefault};
	__property int FoldLength = {read=FFoldLinesLength, write=FFoldLinesLength, nodefault};
public:
	/* TStringList.Destroy */ inline __fastcall virtual ~TIdHeaderList(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idheaderlist */
using namespace Idheaderlist;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdheaderlistHPP
