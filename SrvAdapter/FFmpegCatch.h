catch (EFFmpegError& e) {
	throw EFFmpegError(e);
}
catch (EWinAPIError& e) {
	throw EFFmpegError(e.Message);
}

if (Terminated) Abort();
