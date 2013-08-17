/*---------------------------------------------------------------------------
$Id: Utils.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#pragma hdrstop

#include <StrUtils.hpp>
#include <Math.hpp>

#include "Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#define DATAUNIT_COUNT 5
#define DATASIZE_UNITS {L"B", L"KB", L"MB", L"GB", L"TB"}
#define DATASPEED_UNITS {L"B/s", L"KB/s", L"MB/s", L"GB/s", L"TB/s"}
//---------------------------------------------------------------------------

UnicodeString __fastcall StrExtract(UnicodeString Source, UnicodeString Begin,
	UnicodeString End, bool EndRequired)
{
	int begin = Begin.IsEmpty()? 1 : Pos(Begin, Source);
	int end;

	if (!begin) return L"";
	begin+=Begin.Length();

	if (End.IsEmpty() ) {
		end = Source.Length()+1;
	}
	else {
		end = PosEx(End, Source, begin);
		if (end == 0) {
			if (!EndRequired) {
				end = Source.Length()+1;
			}
			else {
				return L"";
			}
		}
	}

	return Source.SubString(begin, end-begin);
}
//---------------------------------------------------------------------------

TStringList* __fastcall StrExplode(UnicodeString Str, UnicodeString Delimiter,
	bool Trim)
{
	TStringList* result = new TStringList;
	if (!Delimiter.IsEmpty()) {
		Str = ReplaceStr(Str, Delimiter, L"\n");
	}

	result->Text = Str;

	if (Trim) {
		for (int i = 0; i < result->Count; i++) {
			result->Strings[i] = result->Strings[i].Trim();
			//UnicodeString aaa = result->Strings[i];
		}
	}

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall StrImplode(TStringList* List, UnicodeString Delimiter)
{
	if (List->Count == 0) return L"";

	UnicodeString result;
	for (int i=0; i < List->Count-1; i++) {
		result += List->Strings[i] + Delimiter;
	}
	result += List->Strings[List->Count-1];

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall FormatDataSize_GetUnit(unsigned short Index, bool Speed)
{
	if (Speed) {
		const UnicodeString Units[] = DATASPEED_UNITS;
		return Units[Index];
	}
	else {
		const UnicodeString Units[] = DATASIZE_UNITS;
		return Units[Index];
    }
}

UnicodeString __fastcall FormatDataSize(long double Size, bool Speed)
{
	if (Size <= 0) {
		return L"0";
	}

	UnicodeString Unit = L"";
	int i;
	for (i = 0; i < DATAUNIT_COUNT-1; i++) {
		if (Size < 1024.0) {
			Unit = FormatDataSize_GetUnit(i, Speed);
			break;
		}
		Size = Size / 1024.0;
	}
	if (Unit.IsEmpty()) Unit = FormatDataSize_GetUnit(DATAUNIT_COUNT-1, Speed);

	UnicodeString result = IntToStr((int)Int(Size));
	int need_decimals = 3-result.Length();
	if (need_decimals > 0 && i > 0) {
		result = FloatToStrF(RoundTo(Size, -need_decimals), ffFixed, 3, need_decimals);
	}

	return result + L" " + Unit;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall FormatDuration_AddLeadingZero(int Number)
{
	UnicodeString result = IntToStr(Number);
	if (Number < 10) result = UnicodeString(L"0") + result;
	return result;
}

UnicodeString __fastcall FormatDuration(double Duration)
{
	long duration = Round(Duration);

//	if (Duration <= 0.0) {
//		return L"0";
//	}

	int days, hours, mins, secs;
	days 	= duration/86400;	duration -= days*86400;
	hours 	= duration/3600; 	duration -= hours*3600;
	mins	= duration/60; 	duration -= mins*60;
	secs	= duration;

	UnicodeString result = FormatDuration_AddLeadingZero(secs);
	if (mins == 0 && hours==0 && days==0) return UnicodeString(L"0:") + result;
	if (hours == 0 && days==0) return IntToStr(mins) + L":" + result;
	result = IntToStr(hours) + L":" + FormatDuration_AddLeadingZero(mins) + L":" + result;
	if (days == 0) return result;
	return IntToStr(days) + L" d " + result;
}
//---------------------------------------------------------------------------

void __fastcall PrepareContainerToProgress(TWinControl* Container, bool Start, bool Repaint)
{
	TControl* ctrl;

	for (int i = 0; i < Container->ControlCount; i++) {
		ctrl = Container->Controls[i];
		if (ctrl->InheritsFrom(__classid(TWinControl)) \
			&& ((TWinControl *)ctrl)->ControlCount > 0 && ctrl->Tag == 0) {
			PrepareContainerToProgress((TWinControl *)ctrl, Start, false);
		}
		else if (ctrl->Tag == 0) {
			ctrl->Enabled = !Start;
		}
		else if (ctrl->Tag == 2) {
			ctrl->Visible = Start;
		}
	}

	if (Repaint) {
		Container->Repaint();
	}
}
//---------------------------------------------------------------------------

__int64 __fastcall FileGetSize(UnicodeString FileName)
{
	__int64 result = -1;

	TSearchRec sr;
	if (FindFirst(FileName, faAnyFile, sr) == 0) {
		result = sr.Size;
	}
	FindClose(sr);

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall BoolToYesNo(bool Val)
	{
		return Val? L"yes" : L"no";
	}
//---------------------------------------------------------------------------

#define SECPERDAY 86400
#define OFFSET1970 25569
__int64 _fastcall DateToUnixTimeStamp(TDate Date)
{
	return Int(((double)(Date - OFFSET1970)) * SECPERDAY);
}
//---------------------------------------------------------------------------

UnicodeString __fastcall AddSpace(UnicodeString Str)
{
	if (Str.IsEmpty()) return L"";
	else if (Str.SubString(Str.Length(), 1)  != L" ") return Str + L" ";
	else return Str;
}
//---------------------------------------------------------------------------

__int64 __fastcall Round(long double Val)
{
	return Floor(Val + 0.5);
}
//---------------------------------------------------------------------------

UnicodeString __fastcall GetFileExt(UnicodeString FileName)
{
	UnicodeString result = ExtractFileExt(FileName);
	result = result.SubString(2, result.Length()-1).LowerCase();

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall AddBS(UnicodeString Path)
{
	if (Path.IsEmpty()) return Path;
	if (Path.SubString(Path.Length(), 1) != L"\\") Path += L"\\";
	return Path;
}
//---------------------------------------------------------------------------
