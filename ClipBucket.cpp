/*---------------------------------------------------------------------------
$Id: ClipBucket.cpp 524 2011-02-09 16:11:09Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <tchar.h>
#include "Custom/Custom.h"
#include "Custom/Main.h"
#pragma hdrstop

#include "TFramework.h"
#include "SrvAdapter.h"

//---------------------------------------------------------------------------
// ERROR HANDLER

class TErrorHandler {
public:
	void __fastcall HandleError(TObject* Sender, Exception* E)
	{
        //Prevent second call
		static bool activated = false;
		if (activated) {
			return;
		}
		activated = true;

		wchar_t buf[10240];
		UnicodeString msg = L"(Unknown)\n";

		if (E && ExceptionErrorMessage(E,  ExceptAddr(), buf, 10240))
			msg = UnicodeString(buf);

		if (Application->MessageBox((UnicodeString(L"The application has encountered fatal error:\n") \
			+ msg + L"\n"\
			+ L"Do you want to contact technical support?").c_str(),
			L"Fatal Error", MB_ICONSTOP|MB_YESNO) == ID_YES) {

			ShellExecute(0, "open", PRODUCT_BUG_TRACKER, NULL, NULL, SW_SHOWNORMAL);

		}
		Application->Terminate();
	}
};
//---------------------------------------------------------------------------

//Global variables
//TCSUploaderMain* MainForm = NULL;
//TFramework* Framework = NULL;
//---------------------------------------------------------------------------

void UnloadApp()
{
	delete MainForm; MainForm = NULL;
	delete SrvAdapterModule; SrvAdapterModule = NULL;
	delete Framework; Framework = NULL;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
USEFORM("Custom\Header.cpp", HeaderFrame); /* TFrame: File Type */
USEFORM("Frames\TGroupTitle.cpp", GroupTitle); /* TFrame: File Type */
USEFORM("Frames\UploadProps.cpp", UploadProperties); /* TFrame: File Type */
USEFORM("SrvAdapter\SrvAdapter.cpp", SrvAdapterModule); /* TDataModule: File Type */
USEFORM("Forms\MainBase.cpp", MainFormBase);
USEFORM("Custom\ProxyAuth.cpp", ProxyAuthForm);
USEFORM("Forms\ProxyAuthBase.cpp", ProxyAuthFormBase);
USEFORM("Forms\LoginBase.cpp", LoginFormBase);
USEFORM("Forms\AboutBase.cpp", AboutBoxBase);
USEFORM("Framework\TFramework.cpp", Framework); /* TDataModule: File Type */
USEFORM("Custom\VideoEditor.cpp", VideoEditorForm);
USEFORM("custom\YoutubeGrab.cpp", YoutubeGrabForm);
USEFORM("Frames\TProgressPanel.cpp", ProgressPanel); /* TFrame: File Type */
USEFORM("custom\Login.cpp", LoginForm);
USEFORM("custom\About.cpp", AboutBox);
USEFORM("Frames\HeaderBase.cpp", HeaderFrameBase); /* TFrame: File Type */
USEFORM("Custom\HTTPAuth.cpp", HTTPAuthForm);
USEFORM("Custom\Main.cpp", MainForm);
USEFORM("Forms\HTTPAuthBase.cpp", HTTPAuthFormBase);
USEFORM("Forms\YoutubeGrabBase.cpp", YoutubeGrabFormBase);
USEFORM("Forms\VideoEditorBase.cpp", VideoEditorFormBase);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    SrvAdapterModule = NULL;
	TErrorHandler* ErrorHandler = NULL;

	try
	{
		MainForm = NULL;

		ErrorHandler = new TErrorHandler;
		Application->OnException = ErrorHandler->HandleError;

		Randomize();

		Application->MainFormOnTaskBar = true;
		Application->ShowMainForm = false;
		Application->Initialize();

		Framework = new TFramework(Application);
		if (!Framework->ParseCommandLine()) { //must close
			UnloadApp();
			return 0;
		}

		Application->CreateForm(__classid(TSrvAdapterModule), &SrvAdapterModule);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(THTTPAuthForm), &HTTPAuthForm);
		Application->CreateForm(__classid(TLoginFormBase), &LoginFormBase);
		Application->CreateForm(__classid(TProxyAuthFormBase), &ProxyAuthFormBase);
		Application->CreateForm(__classid(TProxyAuthForm), &ProxyAuthForm);
		if (SrvAdapterModule->Authorized) {
            MainForm->Show();
		}

		Application->Run();

		UnloadApp();
	}
	catch (Exception& e)
	{
		ErrorHandler->HandleError(Application, &e);
		return 3;
	}
	catch (...)
	{
		ErrorHandler->HandleError(Application, NULL);
		return 4;
	}
	return 0;
}
//---------------------------------------------------------------------------
