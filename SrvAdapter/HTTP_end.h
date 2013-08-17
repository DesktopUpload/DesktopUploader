/*---------------------------------------------------------------------------
$Id: HTTP_end.h 515 2010-11-17 15:16:37Z anton $
---------------------------------------------------------------------------*/

	}
	catch (EIdHTTPProtocolException& e) {
		if (this->IsAuthFailed(e.ErrorCode)) {
			this->FHTTPAuthFailed = true;
			http->Request->Username = L"";
			http->Request->Password = L"";

			continue;
		}
		if (!this->IsRedirected(e.ErrorCode)) {  //redirect
			throw ECommunicationError(e.Message, cetHTTP);
		}
	}
	catch (EIdSocketError& e) {
		if (!http->ProxyParams->ProxyServer.IsEmpty()
			&& (e.LastError == 10053 || e.LastError == 10054)) {

			if (this->Terminated) {
				Abort();
			}

			this->FProxyAuthFailed = true;
			http->ProxyParams->ProxyUsername = L"";
			http->ProxyParams->ProxyPassword = L"";

			http->DisconnectNotifyPeer();
			if (http->IOHandler) {
				http->IOHandler->InputBuffer->Clear();
				http->IOHandler->Close();
			}
			http->Disconnect();

			continue;
		}
		if (SocketRetryCount < SOCKET_RETRY_COUNT) {
			SocketRetryCount++;
			this->Disconnect();
			continue;
		}
		else {
			throw ECommunicationError(e.Message, cetTCP);
		}
	}
	catch (EIdConnClosedGracefully& e) {
		if (!this->Terminated) {
			if (SocketRetryCount < SOCKET_RETRY_COUNT) {
				SocketRetryCount++;
				this->Disconnect();
				continue;
			}
			else {
				throw ECommunicationError(e.Message, cetTCP);
			}
		}
	}
	catch (EIdNotConnected& e) {
		if (!this->Terminated) throw ECommunicationError(e.Message, cetTCP);
	}
	catch (EIdDecompressionError& e) {
		if (!this->Terminated) throw ECommunicationError(e.Message, cetTCP);
	}
	catch (EZlibError& e) {
		if (!this->Terminated) throw ECommunicationError(e.Message, cetTCP);
	}	catch (EOSError& e) {  //Disk full		throw ECommunicationError(e.Message, cetOS);
	}
	if (this->Terminated) Abort();

	this->HTTPWorkEnd();
	break; //success
}
