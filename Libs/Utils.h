/*---------------------------------------------------------------------------
$Id: Utils.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef UtilsH
#define UtilsH
//---------------------------------------------------------------------------
#include <Controls.hpp>
//---------------------------------------------------------------------------

//String manipulation:
UnicodeString __fastcall StrExtract(UnicodeString Source, UnicodeString Begin,
	UnicodeString End=L"", bool EndRequired=true);
TStringList* __fastcall StrExplode(UnicodeString Str,
	UnicodeString Delimiter=L"", bool Trim=true);
UnicodeString __fastcall StrImplode(TStringList* List,
	UnicodeString Delimiter=L"\n");
UnicodeString __fastcall AddSpace(UnicodeString Str);
UnicodeString __fastcall AddBS(UnicodeString Path);

//String formatting:
UnicodeString __fastcall FormatDataSize(long double Size, bool Speed=false);
UnicodeString __fastcall FormatDuration(double Duration);
UnicodeString __fastcall BoolToYesNo(bool Val);

//File handling:
__int64 __fastcall FileGetSize(UnicodeString FileName);
UnicodeString __fastcall GetFileExt(UnicodeString FileName);

//Misc:
void __fastcall PrepareContainerToProgress(TWinControl* Ctrl, bool Start = true, bool Repaint = true);
__int64 __fastcall DateToUnixTimeStamp(TDate Date);
__int64 __fastcall Round(long double Val);

//---------------------------------------------------------------------------
#endif
