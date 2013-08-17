/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/

#pragma hdrstop

#include "XMLHelpers.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

_di_IXMLNode __fastcall XMLGetChildNode(_di_IXMLNode Node, UnicodeString Name)
{
	_di_IXMLNode result = NULL;

	_di_IXMLNodeList nodes = Node->ChildNodes;
	int count = nodes->Count;
	for (int i = 0; i < count; i++) {
		_di_IXMLNode node = nodes->Get(i);
		if (node->NodeType==ntElement && node->NodeName==Name) {
			result = node;
			break;
		}
	}
	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall XMLGetChildValue(_di_IXMLNode Node, UnicodeString Name,
	UnicodeString Def)
{
	UnicodeString result;
	_di_IXMLNode child = XMLGetChildNode(Node, Name);
	if (child) result = child->NodeValue.bstrVal;

	return result.IsEmpty()? Def : result;
}
//---------------------------------------------------------------------------
