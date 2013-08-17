/*---------------------------------------------------------------------------
$Id: HTTP_begin.h 185 2009-05-01 12:58:01Z anton $
---------------------------------------------------------------------------*/

int SocketRetryCount = 0;
//Reset auth failed flags
this->FHTTPAuthFailed = false;
this->FProxyAuthFailed = false;

while (true) {
	try {
