/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/

#ifndef XMLHelpersH
#define XMLHelpersH

#include <XMLDoc.hpp>
//---------------------------------------------------------------------------

_di_IXMLNode __fastcall XMLGetChildNode(_di_IXMLNode Node, UnicodeString Name);
UnicodeString __fastcall XMLGetChildValue(_di_IXMLNode Node, UnicodeString Name,
	UnicodeString Def=L"");

//---------------------------------------------------------------------------
#endif
