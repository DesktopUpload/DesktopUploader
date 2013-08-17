/*---------------------------------------------------------------------------
$Id: DdeClient.h 355 2009-11-21 22:23:55Z anton $
---------------------------------------------------------------------------*/
#ifndef DdeClientH
#define DdeClientH
//---------------------------------------------------------------------------
#include <DdeMan.hpp>
//---------------------------------------------------------------------------

class TDdeClient
{
	public:
		__fastcall TDdeClient();
		__fastcall ~TDdeClient();

		bool __fastcall Connect();
		void __fastcall Exec(UnicodeString Cmd);
	private:
		TDdeClientConv *Conv;
};
//---------------------------------------------------------------------------
#endif
