/*---------------------------------------------------------------------------
$Id: ConsoleProcess.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#pragma hdrstop

#include "ConsoleProcess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TConsoleProcess
//---------------------------------------------------------------------------
__fastcall TConsoleProcess::TConsoleProcess()
{
	ZeroMemory( &this->ProcInfo, sizeof(this->ProcInfo) );
}
//---------------------------------------------------------------------------

__fastcall TConsoleProcess::~TConsoleProcess()
{
	this->Terminate();
}
//---------------------------------------------------------------------------

DWORD __fastcall TConsoleProcess::Start(UnicodeString Command, UnicodeString WorkDir,
	DWORD PriorityClass)
{
	INT fSuccess;
	HANDLE hChildStdoutRd, hChildStdoutWr;
	STARTUPINFOW si;
	SECURITY_ATTRIBUTES saAttr = {sizeof(SECURITY_ATTRIBUTES), NULL, true};

	LPWSTR szCmdline=Command.c_str();

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&this->ProcInfo, sizeof(this->ProcInfo));

	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = true;
	saAttr.lpSecurityDescriptor = NULL;

	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	// Create a pipe for the child process's STDOUT.
	if (!CreatePipe(&hChildStdoutRd, &hChildStdoutWr, &saAttr, 0)) {
		return GetLastError();
	}
	// Create noninheritable read handle and close the inheritable read
	// handle.
	fSuccess = DuplicateHandle(GetCurrentProcess(), hChildStdoutRd,
		GetCurrentProcess(), &this->Pipe, 0, false, DUPLICATE_SAME_ACCESS);
	if(!fSuccess) return GetLastError();

	CloseHandle(hChildStdoutRd);
	si.hStdError = hChildStdoutWr;
	si.hStdOutput = hChildStdoutWr;
	si.hStdError = si.hStdOutput;

	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;

	// Start the child process.
	if(!CreateProcessW(NULL,   // No module name (use command line)
		szCmdline,      // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		TRUE,          	// Set handle inheritance to TRUE
		PriorityClass,  // No creation flags
		NULL,           // Use parent's environment block
		WorkDir.IsEmpty()? NULL : WorkDir.c_str(),           // Start Dir
		&si,            // Pointer to STARTUPINFO structure
		&this->ProcInfo)           // Pointer to PROCESS_INFORMATION structure
	)
	{
		return GetLastError();
	}
	WaitForInputIdle(this->ProcInfo.hProcess, INFINITE);

	CloseHandle(hChildStdoutWr);

	return 0;
}
//---------------------------------------------------------------------------

bool __fastcall TConsoleProcess::Terminate(int WaitTimeout)
{
	bool result = true;

	if (this->ProcInfo.hProcess) {
		TerminateProcess(this->ProcInfo.hProcess,0);
		if (WaitTimeout > 0) result = this->Wait(WaitTimeout)==1;
	}
	this->Clean();

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TConsoleProcess::Clean()
{
	if (this->ProcInfo.hProcess) {
		CloseHandle(this->ProcInfo.hProcess);
		CloseHandle(this->ProcInfo.hThread);
		this->ProcInfo.hProcess=NULL;
		this->Pipe=NULL;
	}
}
//---------------------------------------------------------------------------

DWORD __fastcall TConsoleProcess::Read(UnicodeString &Output)
{
	unsigned long BytesLeft = 0;
	if (!PeekNamedPipe(this->Pipe,0,0,0,&BytesLeft,0)) return GetLastError();

	if (BytesLeft > 0) {
		DWORD dwRead;
		char* buffer = (char*) malloc(BytesLeft+1);

		if (!ReadFile(this->Pipe, buffer, BytesLeft, &dwRead, NULL)) return GetLastError();
		buffer[BytesLeft] = 0;
		Output = UnicodeString(buffer);
		if (Output[Output.Length()] == '\r') {
			Output += '\n';
		}

		free(buffer);
		buffer=NULL;
	}
	else Output = L"";

	return 0;
}
//---------------------------------------------------------------------------

short __fastcall TConsoleProcess::Wait(int Timeout)
{
	switch (WaitForSingleObject(this->ProcInfo.hProcess,(Timeout==-1)?INFINITE:Timeout)) {
	case WAIT_OBJECT_0:
		return 1;
	case WAIT_TIMEOUT:
		return 0;
	default:
		return -1;
	}
}
//---------------------------------------------------------------------------

DWORD __fastcall TConsoleProcess::GetExitCode(DWORD &Code)
{
	Code = 0;
	if (GetExitCodeProcess(this->ProcInfo.hProcess, &Code)) return 0;
	else return GetLastError();
}
//---------------------------------------------------------------------------
