/*---------------------------------------------------------------------------
$Id: YouTube.cpp 476 2010-05-10 01:19:03Z anton $
---------------------------------------------------------------------------*/
#include <StrUtils.hpp>
#include "Custom/Custom.h"
#include "Utils.h"

#pragma hdrstop

#include <HTTPApp.hpp>
#include <XMLDoc.hpp>

#include "XMLHelpers.h"

#include "YouTube.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#define YT_INFO_EMPTY_TITLE L"(Untitled)"
//---------------------------------------------------------------------------

void __fastcall YT_ExtractInfoXML(TMediaItem* MI, UnicodeString XML)
{
	_di_IXMLDocument doc = NULL;
	try {
		doc = LoadXMLData(XML);
		doc->Options >> doAttrNull;
	} catch (EDOMParseError& e) {
		throw UnicodeString("YouTube Error: ") + XML;
	}
	_di_IXMLNode root = doc->GetDocumentElement();

	_di_IXMLNode group = XMLGetChildNode(root, L"media:group");
	if (!group) throw UnicodeString("Invalid YouTube metadata");

	MI->Title = XMLGetChildValue(group, L"media:title", YT_INFO_EMPTY_TITLE);

	UnicodeString description = XMLGetChildValue(group, L"media:description", MI->Title);
	description = ReplaceStr(description, L"\n", L"\r\n");
	MI->Description = description;

	MI->Tags = XMLGetChildValue(group, L"media:keywords", MI->Title);

	MI->Metadata = new TMetadata;
	UnicodeString strDuration;
	_di_IXMLNode nodeDuration = XMLGetChildNode(group, L"yt:duration");
	if (nodeDuration) {
		strDuration = nodeDuration->GetAttribute(L"seconds");
	}
	MI->Metadata->Duration = StrToIntDef(strDuration, 0);

	doc.Release();
}
//---------------------------------------------------------------------------

UnicodeString __fastcall YT_ExtractInfoHTMLItem(UnicodeString HTML, UnicodeString Name, UnicodeString Default=L"")
{
	UnicodeString value = StrExtract(HTML,
		UnicodeString(L"<meta name=\"") + Name + L"\" content=\"", L"\">", true);
	return value.IsEmpty()? Default : HTMLDecode(value);
}

void __fastcall YT_ExtractInfoHTML(TMediaItem* MI, UnicodeString HTML)
{
	MI->Title = YT_ExtractInfoHTMLItem(HTML, L"title", YT_INFO_EMPTY_TITLE);
	MI->Description = YT_ExtractInfoHTMLItem(HTML, L"description", MI->Title);
	MI->Tags = YT_ExtractInfoHTMLItem(HTML, L"keywords", MI->Title);

	UnicodeString strDuration = StrExtract(HTML,
		L"\"length_seconds\": \"", L"\"", true);

	MI->Metadata = new TMetadata;
	MI->Metadata->Duration = StrToIntDef(strDuration, 0);
}
//---------------------------------------------------------------------------

UnicodeString __fastcall YT_ComposeDownloadLink(UnicodeString ID,
	UnicodeString Token, int Fmt)
{
	UnicodeString result = UnicodeString(L"http://www.youtube.com/get_video?video_id=")
		+ ID + L"&t=" + Token;

	if (Fmt) result += L"&fmt=" + IntToStr(Fmt);

	return result;
}
//---------------------------------------------------------------------------

TStringList* __fastcall YT_ParseFmtMap(UnicodeString Map)
{
	TStringList* result = StrExplode(Map, L",");
	result->NameValueSeparator = '|';

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall YT_ExpractID(UnicodeString URL)
{
	UnicodeString result;
	result = StrExtract(URL, L"?v=", "&", false);
	if (result.IsEmpty()) result = StrExtract(URL, L"&v=", "&", false);
	if (result.IsEmpty()) result = StrExtract(URL, L"#!v=", "&", false);

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall YT_FmtToStr(int Fmt)
{
	int Formats[] = YT_FORMATS;
	UnicodeString FormatsStr[] = YT_FORMATS_STR;

	for (int i = 0; i < YT_FORMATS_COUNT; i++) {
		if (Formats[i]==Fmt) {
			return FormatsStr[i];
		}
	}

	return "flv";
}
//---------------------------------------------------------------------------
