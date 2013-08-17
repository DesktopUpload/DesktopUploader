/*---------------------------------------------------------------------------
$Id:$
---------------------------------------------------------------------------*/

http->Request->UserAgent = this->UserAgent_YT;

UnicodeString oldUserName = http->Request->Username;
UnicodeString oldPassword = http->Request->Password;
bool oldBasicAuthentication = http->Request->BasicAuthentication;
TIdAuthentication* oldAuthentication = http->Request->Authentication;

http->Request->Username = L"";
http->Request->Password = L"";
http->Request->Authentication = NULL;
http->Request->BasicAuthentication = false;
