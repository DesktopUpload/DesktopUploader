/*---------------------------------------------------------------------------
$Id: TFramework.h 475 2010-05-09 22:04:17Z anton $
---------------------------------------------------------------------------*/
#ifndef TFrameworkH
#define TFrameworkH
//---------------------------------------------------------------------------
#include <IniFiles.hpp>
#include <DdeMan.hpp>
#include <ComCtrls.hpp>
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TFramework : public TForm
{
__published:	// IDE-managed Components
	TDdeServerConv *System;
	void __fastcall SystemExecuteMacro(TObject *Sender, TStrings *Msg);
protected:	// User declarations
    TFormatSettings FNeutralFormatSettings;

public:		// User declarations
		__fastcall TFramework(TComponent* Owner);
		__fastcall ~TFramework();

		bool __fastcall InitLogin();

		UnicodeString DataDir, TempDir;

		TMemIniFile* IniFile;
		void __fastcall RestoreFormPosition(TForm *Form, UnicodeString SectionName = "", bool Cascade = false);
		void __fastcall SaveFormPosition(TForm *Form, UnicodeString SectionName = "");
		void __fastcall RestoreListViewColWidths(TListView* ListView, UnicodeString Section);
		void __fastcall SaveListViewColWidths(TListView* ListView, UnicodeString Section);
		bool __fastcall SaveIni(); //Provides error handling for UpdateFile method.

		UnicodeString FileToAdd;
		bool __fastcall ParseCommandLine();

		void __fastcall RegisterShellCommands(bool RegisterFlag);
		UnicodeString __fastcall GetNewTempFile();
		UnicodeString __fastcall GetNewTempDir();
		bool __fastcall RemoveDir(UnicodeString Dir);

		int __fastcall ShowMessageBox(UnicodeString Msg, UnicodeString Title=L"", int Options=NULL);
		void __fastcall ShowErrorMessage(UnicodeString Msg, UnicodeString Title=L"", bool Warining=false);

		void __fastcall BrowseURL(UnicodeString URL);

		bool __fastcall ExtractResourceToStream(AnsiString Resource, TStream* Stream);

		void __fastcall DeleteFileStream(TFileStream* &fs, bool Temp=true);
		void __fastcall CopyDir(UnicodeString Src, UnicodeString Dst);
		void __fastcall CopyFile(UnicodeString Src, UnicodeString Dst);

		__property TFormatSettings NeutralFormatSettings = {read=FNeutralFormatSettings};

	private:
		void __fastcall RegisterExt(UnicodeString Ext, bool RegisterFlag);
};

//---------------------------------------------------------------------------
// Exceptions
//---------------------------------------------------------------------------
class EFrameworkError: public Exception
{
public:
	__fastcall EFrameworkError(UnicodeString Message) : Exception(Message) {};
};

//---------------------------------------------------------------------------
extern PACKAGE TFramework *Framework;
//---------------------------------------------------------------------------
#endif
