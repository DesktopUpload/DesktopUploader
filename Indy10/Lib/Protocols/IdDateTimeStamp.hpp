// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddatetimestamp.pas' rev: 20.00

#ifndef IddatetimestampHPP
#define IddatetimestampHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddatetimestamp
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<System::UnicodeString, 13> Iddatetimestamp__1;

typedef StaticArray<System::UnicodeString, 13> Iddatetimestamp__2;

typedef StaticArray<System::UnicodeString, 8> Iddatetimestamp__3;

typedef StaticArray<System::UnicodeString, 8> Iddatetimestamp__4;

#pragma option push -b-
enum TDays { TDaySun, TDayMon, TDayTue, TDayWed, TDayThu, TDayFri, TDaySat };
#pragma option pop

#pragma option push -b-
enum TMonths { TMthJan, TMthFeb, TMthMar, TMthApr, TMthMay, TMthJun, TMthJul, TMthAug, TMthSep, TMthOct, TMthNov, TMthDec };
#pragma option pop

class DELPHICLASS TIdDateTimeStamp;
class PASCALIMPLEMENTATION TIdDateTimeStamp : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	int FDay;
	bool FIsLeapYear;
	int FMillisecond;
	int FSecond;
	int FTimeZone;
	int FYear;
	void __fastcall CheckLeapYear(void);
	void __fastcall SetDateFromISO8601(System::UnicodeString AString);
	void __fastcall SetTimeFromISO8601(System::UnicodeString AString);
	virtual void __fastcall InitComponent(void);
	
public:
	void __fastcall AddDays(unsigned ANumber);
	void __fastcall AddHours(unsigned ANumber);
	void __fastcall AddMilliseconds(unsigned ANumber);
	void __fastcall AddMinutes(unsigned ANumber);
	void __fastcall AddMonths(unsigned ANumber);
	void __fastcall AddSeconds(unsigned ANumber);
	void __fastcall AddTDateTime(System::TDateTime ADateTime);
	void __fastcall AddTIdDateTimeStamp(TIdDateTimeStamp* AIdDateTime);
	void __fastcall AddTTimeStamp(TIdDateTimeStamp* ATimeStamp);
	void __fastcall AddWeeks(unsigned ANumber);
	void __fastcall AddYears(unsigned ANumber);
	System::UnicodeString __fastcall GetAsISO8601Calendar();
	System::UnicodeString __fastcall GetAsISO8601Ordinal();
	System::UnicodeString __fastcall GetAsISO8601Week();
	System::UnicodeString __fastcall GetAsRFC822();
	System::TDateTime __fastcall GetAsTDateTime(void);
	TIdDateTimeStamp* __fastcall GetAsTTimeStamp(void);
	System::UnicodeString __fastcall GetAsTimeOfDay();
	int __fastcall GetBeatOfDay(void);
	int __fastcall GetDaysInYear(void);
	int __fastcall GetDayOfMonth(void);
	int __fastcall GetDayOfWeek(void);
	System::UnicodeString __fastcall GetDayOfWeekName();
	System::UnicodeString __fastcall GetDayOfWeekShortName();
	int __fastcall GetHourOf12Day(void);
	int __fastcall GetHourOf24Day(void);
	bool __fastcall GetIsMorning(void);
	int __fastcall GetMinuteOfDay(void);
	int __fastcall GetMinuteOfHour(void);
	int __fastcall GetMonthOfYear(void);
	System::UnicodeString __fastcall GetMonthName();
	System::UnicodeString __fastcall GetMonthShortName();
	int __fastcall GetSecondsInYear(void);
	int __fastcall GetSecondOfMinute(void);
	System::UnicodeString __fastcall GetTimeZoneAsString();
	int __fastcall GetTimeZoneHour(void);
	int __fastcall GetTimeZoneMinutes(void);
	int __fastcall GetWeekOfYear(void);
	void __fastcall SetFromDOSDateTime(System::Word ADate, System::Word ATime);
	void __fastcall SetFromISO8601(System::UnicodeString AString);
	void __fastcall SetFromRFC822(System::UnicodeString AString);
	void __fastcall SetFromTDateTime(System::TDateTime ADateTime);
	void __fastcall SetFromTTimeStamp(TIdDateTimeStamp* ATimeStamp);
	void __fastcall SetDay(int ANumber);
	void __fastcall SetMillisecond(int ANumber);
	void __fastcall SetSecond(int ANumber);
	void __fastcall SetTimeZone(const int Value);
	void __fastcall SetYear(int ANumber);
	void __fastcall SubtractDays(unsigned ANumber);
	void __fastcall SubtractHours(unsigned ANumber);
	void __fastcall SubtractMilliseconds(unsigned ANumber);
	void __fastcall SubtractMinutes(unsigned ANumber);
	void __fastcall SubtractMonths(unsigned ANumber);
	void __fastcall SubtractSeconds(unsigned ANumber);
	void __fastcall SubtractTDateTime(System::TDateTime ADateTime);
	void __fastcall SubtractTIdDateTimeStamp(TIdDateTimeStamp* AIdDateTime);
	void __fastcall SubtractTTimeStamp(TIdDateTimeStamp* ATimeStamp);
	void __fastcall SubtractWeeks(unsigned ANumber);
	void __fastcall SubtractYears(unsigned ANumber);
	void __fastcall Zero(void);
	void __fastcall ZeroDate(void);
	void __fastcall ZeroTime(void);
	__property System::UnicodeString AsISO8601Calendar = {read=GetAsISO8601Calendar};
	__property System::UnicodeString AsISO8601Ordinal = {read=GetAsISO8601Ordinal};
	__property System::UnicodeString AsISO8601Week = {read=GetAsISO8601Week};
	__property System::UnicodeString AsRFC822 = {read=GetAsRFC822};
	__property System::TDateTime AsTDateTime = {read=GetAsTDateTime};
	__property TIdDateTimeStamp* AsTTimeStamp = {read=GetAsTTimeStamp};
	__property System::UnicodeString AsTimeOfDay = {read=GetAsTimeOfDay};
	__property int BeatOfDay = {read=GetBeatOfDay, nodefault};
	__property int Day = {read=FDay, write=SetDay, nodefault};
	__property int DaysInYear = {read=GetDaysInYear, nodefault};
	__property int DayOfMonth = {read=GetDayOfMonth, nodefault};
	__property int DayOfWeek = {read=GetDayOfWeek, nodefault};
	__property System::UnicodeString DayOfWeekName = {read=GetDayOfWeekName};
	__property System::UnicodeString DayOfWeekShortName = {read=GetDayOfWeekShortName};
	__property int HourOf12Day = {read=GetHourOf12Day, nodefault};
	__property int HourOf24Day = {read=GetHourOf24Day, nodefault};
	__property bool IsLeapYear = {read=FIsLeapYear, nodefault};
	__property bool IsMorning = {read=GetIsMorning, nodefault};
	__property int Millisecond = {read=FMillisecond, write=SetMillisecond, nodefault};
	__property int MinuteOfDay = {read=GetMinuteOfDay, nodefault};
	__property int MinuteOfHour = {read=GetMinuteOfHour, nodefault};
	__property int MonthOfYear = {read=GetMonthOfYear, nodefault};
	__property System::UnicodeString MonthName = {read=GetMonthName};
	__property System::UnicodeString MonthShortName = {read=GetMonthShortName};
	__property int Second = {read=FSecond, write=SetSecond, nodefault};
	__property int SecondsInYear = {read=GetSecondsInYear, nodefault};
	__property int SecondOfMinute = {read=GetSecondOfMinute, nodefault};
	__property int TimeZone = {read=FTimeZone, write=SetTimeZone, nodefault};
	__property int TimeZoneHour = {read=GetTimeZoneHour, nodefault};
	__property int TimeZoneMinutes = {read=GetTimeZoneMinutes, nodefault};
	__property System::UnicodeString TimeZoneAsString = {read=GetTimeZoneAsString};
	__property int Year = {read=FYear, write=SetYear, nodefault};
	__property int WeekOfYear = {read=GetWeekOfYear, nodefault};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdDateTimeStamp(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdDateTimeStamp(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word IdMilliSecondsInSecond = 0x3e8;
static const ShortInt IdSecondsInMinute = 0x3c;
static const ShortInt IdMinutesInHour = 0x3c;
static const ShortInt IdHoursInDay = 0x18;
static const ShortInt IdDaysInWeek = 0x7;
static const Word IdDaysInYear = 0x16d;
static const Word IdDaysInLeapYear = 0x16e;
static const ShortInt IdYearsInShortLeapYearCycle = 0x4;
static const Word IdDaysInShortLeapYearCycle = 0x5b5;
static const Word IdDaysInShortNonLeapYearCycle = 0x5b4;
static const Word IdDaysInFourYears = 0x5b5;
static const ShortInt IdYearsInCentury = 0x64;
static const Word IdDaysInCentury = 0x8eac;
static const Word IdDaysInLeapCentury = 0x8ead;
static const Word IdYearsInLeapYearCycle = 0x190;
static const int IdDaysInLeapYearCycle = 0x23ab1;
static const ShortInt IdMonthsInYear = 0xc;
static const Word IdBeatsInDay = 0x3e8;
static const ShortInt IdHoursInHalfDay = 0xc;
static const Word IdSecondsInHour = 0xe10;
static const int IdSecondsInDay = 0x15180;
static const Word IdSecondsInHalfDay = 0xa8c0;
static const int IdSecondsInWeek = 0x93a80;
static const int IdSecondsInYear = 0x1e13380;
static const int IdSecondsInLeapYear = 0x1e28500;
static const Word IdMillisecondsInMinute = 0xea60;
static const int IdMillisecondsInHour = 0x36ee80;
static const int IdMillisecondsInDay = 0x5265c00;
static const int IdMillisecondsInWeek = 0x240c8400;
#define SShortMonthNameJan L"Jan"
#define SShortMonthNameFeb L"Feb"
#define SShortMonthNameMar L"Mar"
#define SShortMonthNameApr L"Apr"
#define SShortMonthNameMay L"May"
#define SShortMonthNameJun L"Jun"
#define SShortMonthNameJul L"Jul"
#define SShortMonthNameAug L"Aug"
#define SShortMonthNameSep L"Sep"
#define SShortMonthNameOct L"Oct"
#define SShortMonthNameNov L"Nov"
#define SShortMonthNameDec L"Dec"
#define SLongMonthNameJan L"January"
#define SLongMonthNameFeb L"February"
#define SLongMonthNameMar L"March"
#define SLongMonthNameApr L"April"
#define SLongMonthNameMay L"May"
#define SLongMonthNameJun L"June"
#define SLongMonthNameJul L"July"
#define SLongMonthNameAug L"August"
#define SLongMonthNameSep L"September"
#define SLongMonthNameOct L"October"
#define SLongMonthNameNov L"November"
#define SLongMonthNameDec L"December"
#define SShortDayNameSun L"Sun"
#define SShortDayNameMon L"Mon"
#define SShortDayNameTue L"Tue"
#define SShortDayNameWed L"Wed"
#define SShortDayNameThu L"Thu"
#define SShortDayNameFri L"Fri"
#define SShortDayNameSat L"Sat"
#define SLongDayNameSun L"Sunday"
#define SLongDayNameMon L"Monday"
#define SLongDayNameTue L"Tuesday"
#define SLongDayNameWed L"Wednesday"
#define SLongDayNameThu L"Thursday"
#define SLongDayNameFri L"Friday"
#define SLongDayNameSat L"Saturday"
extern PACKAGE StaticArray<System::Byte, 12> IdDaysInMonth;
extern PACKAGE Iddatetimestamp__1 IdMonthNames;
extern PACKAGE Iddatetimestamp__2 IdMonthShortNames;
extern PACKAGE Iddatetimestamp__3 IdDayNames;
extern PACKAGE Iddatetimestamp__4 IdDayShortNames;
static const ShortInt TZ_NZDT = 0xd;
static const ShortInt TZ_IDLE = 0xc;
static const ShortInt TZ_NZST = 0xc;
static const ShortInt TZ_NZT = 0xc;
static const ShortInt TZ_EADT = 0xb;
static const ShortInt TZ_GST = 0xa;
static const ShortInt TZ_JST = 0x9;
static const ShortInt TZ_CCT = 0x8;
static const ShortInt TZ_WADT = 0x8;
static const ShortInt TZ_WAST = 0x7;
static const ShortInt TZ_ZP6 = 0x6;
static const ShortInt TZ_ZP5 = 0x5;
static const ShortInt TZ_ZP4 = 0x4;
static const ShortInt TZ_BT = 0x3;
static const ShortInt TZ_EET = 0x2;
static const ShortInt TZ_MEST = 0x2;
static const ShortInt TZ_MESZ = 0x2;
static const ShortInt TZ_SST = 0x2;
static const ShortInt TZ_FST = 0x2;
static const ShortInt TZ_CET = 0x1;
static const ShortInt TZ_FWT = 0x1;
static const ShortInt TZ_MET = 0x1;
static const ShortInt TZ_MEWT = 0x1;
static const ShortInt TZ_SWT = 0x1;
static const ShortInt TZ_GMT = 0x0;
static const ShortInt TZ_UT = 0x0;
static const ShortInt TZ_UTC = 0x0;
static const ShortInt TZ_WET = 0x0;
static const ShortInt TZ_WAT = -1;
static const ShortInt TZ_BST = -1;
static const ShortInt TZ_AT = -2;
static const ShortInt TZ_ADT = -3;
static const ShortInt TZ_AST = -4;
static const ShortInt TZ_EDT = -4;
static const ShortInt TZ_EST = -5;
static const ShortInt TZ_CDT = -5;
static const ShortInt TZ_CST = -6;
static const ShortInt TZ_MDT = -6;
static const ShortInt TZ_MST = -7;
static const ShortInt TZ_PDT = -7;
static const ShortInt TZ_PST = -8;
static const ShortInt TZ_YDT = -8;
static const ShortInt TZ_YST = -9;
static const ShortInt TZ_HDT = -9;
static const ShortInt TZ_AHST = -10;
static const ShortInt TZ_CAT = -10;
static const ShortInt TZ_HST = -10;
static const ShortInt TZ_EAST = -10;
static const ShortInt TZ_NT = -11;
static const ShortInt TZ_IDLW = -12;
static const ShortInt TZM_A = -1;
static const ShortInt TZM_Alpha = -1;
static const ShortInt TZM_B = -2;
static const ShortInt TZM_Bravo = -2;
static const ShortInt TZM_C = -3;
static const ShortInt TZM_Charlie = -3;
static const ShortInt TZM_D = -4;
static const ShortInt TZM_Delta = -4;
static const ShortInt TZM_E = -5;
static const ShortInt TZM_Echo = -5;
static const ShortInt TZM_F = -6;
static const ShortInt TZM_Foxtrot = -6;
static const ShortInt TZM_G = -7;
static const ShortInt TZM_Golf = -7;
static const ShortInt TZM_H = -8;
static const ShortInt TZM_Hotel = -8;
static const ShortInt TZM_J = -9;
static const ShortInt TZM_Juliet = -9;
static const ShortInt TZM_K = -10;
static const ShortInt TZM_Kilo = -10;
static const ShortInt TZM_L = -11;
static const ShortInt TZM_Lima = -11;
static const ShortInt TZM_M = -12;
static const ShortInt TZM_Mike = -12;
static const ShortInt TZM_N = 0x1;
static const ShortInt TZM_November = 0x1;
static const ShortInt TZM_O = 0x2;
static const ShortInt TZM_Oscar = 0x2;
static const ShortInt TZM_P = 0x3;
static const ShortInt TZM_Papa = 0x3;
static const ShortInt TZM_Q = 0x4;
static const ShortInt TZM_Quebec = 0x4;
static const ShortInt TZM_R = 0x5;
static const ShortInt TZM_Romeo = 0x5;
static const ShortInt TZM_S = 0x6;
static const ShortInt TZM_Sierra = 0x6;
static const ShortInt TZM_T = 0x7;
static const ShortInt TZM_Tango = 0x7;
static const ShortInt TZM_U = 0x8;
static const ShortInt TZM_Uniform = 0x8;
static const ShortInt TZM_V = 0x9;
static const ShortInt TZM_Victor = 0x9;
static const ShortInt TZM_W = 0xa;
static const ShortInt TZM_Whiskey = 0xa;
static const ShortInt TZM_X = -11;
static const ShortInt TZM_XRay = -11;
static const ShortInt TZM_Y = 0xc;
static const ShortInt TZM_Yankee = 0xc;
static const ShortInt TZM_Z = 0x0;
static const ShortInt TZM_Zulu = 0x0;

}	/* namespace Iddatetimestamp */
using namespace Iddatetimestamp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddatetimestampHPP
