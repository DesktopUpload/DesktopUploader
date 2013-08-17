/*---------------------------------------------------------------------------
$Id: ConsoleProcess.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef ConsoleProcessH
#define ConsoleProcessH

#include <vcl.h>
#include <stdio.h>

//---------------------------------------------------------------------------
// TConsoleProcess
//---------------------------------------------------------------------------
class TConsoleProcess
{
	protected:
		HANDLE Pipe;
		PROCESS_INFORMATION ProcInfo;
	public:
		__fastcall TConsoleProcess();
		__fastcall ~TConsoleProcess();

		DWORD __fastcall Start(UnicodeString Command, UnicodeString WorkDir=L"",
			DWORD PriorityClass=NULL);
		bool __fastcall Terminate(int WaitTimeout=0);
		void __fastcall Clean();
		DWORD __fastcall Read(UnicodeString &Output);
		short __fastcall Wait(int Timeout=-1);
		DWORD __fastcall GetExitCode(DWORD &Code);
};
//---------------------------------------------------------------------------
#endif
