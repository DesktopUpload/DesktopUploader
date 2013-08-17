/*---------------------------------------------------------------------------
$Id: TFramework.cpp 475 2010-05-09 22:04:17Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <SysUtils.hpp>
#include <System.hpp>
#include <StrUtils.hpp>

#include "Config.h"
#include "Product.h"
#include "Custom/Custom.h"
#include "Custom/Main.h"
#include "TFramework.h"
#include "SrvAdapter.h"
#include "Utils.h"
#pragma hdrstop

#include <IniFiles.hpp>
#include <ShlObj.h>
#include <Registry.hpp>

#include "DdeClient.h"
#include "Custom/Login.h"

extern TSrvAdapterModule* TSrvAdapterModule;
extern TMainForm* MainForm;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFramework *Framework;
//---------------------------------------------------------------------------

__fastcall TFramework::TFramework(TComponent* Owner)
	: TForm(Owner)
{
	GetLocaleFormatSettings(1033, this->FNeutralFormatSettings); //neutral
	this->FileToAdd = L"";

//Get Application Data folder:
	UnicodeString dir = L"";
	bool OK = false;
	WCHAR szPath[MAX_PATH];
	if(SUCCEEDED(SHGetFolderPathW(NULL, \
							 CSIDL_APPDATA|CSIDL_FLAG_CREATE,\
							 NULL, \
							 0, \
							 szPath))) {

	dir = UnicodeString(szPath);
	if (dir.SubString(dir.Length(), 1) != L"\\") dir += L"\\";
		dir += UnicodeString(PRODUCT_NAME) + L"\\" + UnicodeString(CUSTOM_EXE_NAME) + L"\\";
		OK = DirectoryExists(dir) ? true : ForceDirectories(dir);
	}
	this->DataDir = OK ? dir : ExtractFilePath(Application->ExeName);

//App settings INI file
	this->IniFile = new TMemIniFile(DataDir + L"Settings.ini");

//Get Temp folder
    DWORD dwRetVal;
	char szTempName[MAX_PATH];
	WCHAR lpPathBuffer[MAX_PATH];
	OK = false;

	dwRetVal = GetTempPathW(MAX_PATH, lpPathBuffer);
	if (dwRetVal <= MAX_PATH) {
		dir = UnicodeString(lpPathBuffer);
		if (dir.SubString(dir.Length(), 1) != L"\\") dir += L"\\";
		OK = DirectoryExists(dir) ? true : ForceDirectories(dir);
	}
	this->TempDir = OK ? dir : ExtractFilePath(Application->ExeName);
}
//---------------------------------------------------------------------------

__fastcall TFramework::~TFramework()
{
	this->SaveIni();
	delete this->IniFile;
}
//---------------------------------------------------------------------------

bool __fastcall TFramework::InitLogin()
{
	TLoginForm* dlg = new TLoginForm(Application);
	dlg->ShowModal();

	return dlg->ModalResult==mrOk;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TFramework::GetNewTempFile()
{
	WCHAR szTempName[MAX_PATH];

	UINT uRetVal = GetTempFileNameW(TempDir.w_str(), // directory for tmp files
							  L"CSU",        // temp file name prefix
							  0,            // create unique name
							  szTempName);  // buffer for name
	if (uRetVal == 0) throw EFrameworkError(L"Failed to generate temporary file name.");
	return UnicodeString(szTempName);
}
//--------------------------------------------------------------------------

UnicodeString __fastcall TFramework::GetNewTempDir()
{
	UnicodeString path = GetNewTempFile();
	DeleteFile(path);
	CreateDir(path);

	return path;
}
//--------------------------------------------------------------------------

bool __fastcall TFramework::RemoveDir(UnicodeString Dir)
{
	return WinExec(UnicodeString(L"cmd /c rmdir /S /Q \"" + Dir + L"\"").t_str(), SW_HIDE) > 31;
}
//--------------------------------------------------------------------------

void __fastcall TFramework::RestoreFormPosition(TForm *Form, UnicodeString Section, bool Cascade)
{
	UnicodeString name = Section.IsEmpty()? Form->Name : Section;
	if (this->IniFile->SectionExists(name)) {
		Form->Position = poDesigned;

		long left = this->IniFile->ReadInteger(name, "Left", Form->Left);
		long top = this->IniFile->ReadInteger(name, "Top", Form->Top);
		long width = this->IniFile->ReadInteger(name, "Width", Form->Width);
		long height = this->IniFile->ReadInteger(name, "Height", Form->Height);

		//long MaxWidth = GetSystemMetrics(SM_CXMAXIMIZED);
		//long MaxHeight = GetSystemMetrics(SM_CYMAXIMIZED);
		long max_width = GetSystemMetrics(SM_CXVIRTUALSCREEN);
		long max_height = GetSystemMetrics(SM_CYVIRTUALSCREEN);

		if (Cascade) {
			long slide = GetSystemMetrics(SM_CYSIZEFRAME) + GetSystemMetrics(SM_CYCAPTION);
			left += slide;
			top += slide;

			if (left+width > max_width) left = 0;
			if (top+height > max_height) top  = 0;
			this->SaveFormPosition(Form, name);
		}

		if (left < 0) left = 0;
		else if (left+width > max_width) left = max_width-width;
		if (top < 0) top = 0;
		else if (top+height > max_height) top = max_height-height;

		if (width > max_width) width = max_width;
		if (width < Form->Constraints->MinWidth)
			width = Form->Constraints->MinWidth;

		if (height > max_height) height = max_height;
		if (height < Form->Constraints->MinHeight)
			height = Form->Constraints->MinHeight;

		Form->SetBounds(left, top, width, height);

		if (Cascade) {
			this->SaveFormPosition(Form, name);
		}

		if (Form->BorderIcons.Contains(biMaximize))
			Form->WindowState = (TWindowState)this->IniFile->ReadInteger(name, "WindowState", Form->WindowState);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFramework::SaveFormPosition(TForm *Form, UnicodeString Section)
{
	UnicodeString name = Section.IsEmpty()? Form->Name : Section;

	if (Form->WindowState != wsMinimized) {
		if (Form->BorderIcons.Contains(biMaximize))
			this->IniFile->WriteInteger(name, "WindowState", Form->WindowState);
		if (Form->WindowState == wsNormal) {
			this->IniFile->WriteInteger(name, "Left", Form->Left);
			this->IniFile->WriteInteger(name, "Top", Form->Top);
			this->IniFile->WriteInteger(name, "Width", Form->Width);
			this->IniFile->WriteInteger(name, "Height", Form->Height);
		}
	}
}
//---------------------------------------------------------------------------

bool __fastcall TFramework::SaveIni()
{
	bool result = false;

	try {
		this->IniFile->UpdateFile();
		result = true;
	} catch (Exception& e) {
		this->ShowErrorMessage(
			UnicodeString(L"Cannot save application settings: ")
			+ e.Message, CUSTOM_PRODUCT_NAME, true);
	}

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TFramework::RestoreListViewColWidths(TListView* ListView, UnicodeString Section)
{
	for (int i = 0; i < ListView->Columns->Count; i++) {
		ListView->Column[i]->Width = this->IniFile->ReadInteger(Section,
			ListView->Name+L".Column["+IntToStr(i)+L"].Width",
			ListView->Column[i]->Width);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFramework::SaveListViewColWidths(TListView* ListView, UnicodeString Section)
{
	for (int i = 0; i < ListView->Columns->Count; i++) {
		this->IniFile->WriteInteger(Section,
			ListView->Name+L".Column["+IntToStr(i)+L"].Width",
			ListView->Column[i]->Width);
	}
}
//---------------------------------------------------------------------------

bool __fastcall TFramework::ParseCommandLine()
{
	//read command line
	UnicodeString cmd = "";
	if (ParamCount() > 0) {
		cmd = ParamStr(1).Trim();

		if (cmd[1] == '-') {
			//We have an option, not file name
			UnicodeString lower_cmd = LowerCase(cmd);

			if (lower_cmd == L"-reg") RegisterShellCommands(true);
			else if (lower_cmd == L"-unreg") RegisterShellCommands(false);
			else if (lower_cmd == L"-nsh") {
				TFileStream* fs = new TFileStream(ExtractFilePath(Application->ExeName) + L"Product.nsh", fmCreate);
				AnsiString text = "";

				text += AnsiString("!define PRODUCT_VERSION \"")
					+ PRODUCT_VERSION + "\"\r\n";
				text += AnsiString("!define PRODUCT_VERSION_STRICT \"")
					+ PRODUCT_VERSION_STRICT + "\"\r\n";
				text += AnsiString("!define VER_MAJOR \"")
					+ VER_MAJOR + "\"\r\n";
				text += AnsiString("!define VER_MINOR \"")
					+ VER_MINOR + "\"\r\n";
				text += AnsiString("!define VER_RELEASE \"")
					+ VER_RELEASE + "\"\r\n";
				text += AnsiString("!define VER_BUILD \"")
					+ VER_BUILD + "\"\r\n";

				text += AnsiString("!define CUSTOM_EXE_NAME \"")
					+ CUSTOM_EXE_NAME + "\"\r\n";
				text += AnsiString("!define CUSTOM_PRODUCT_NAME \"")
					+ CUSTOM_PRODUCT_NAME + "\"\r\n";
				text += AnsiString("!define INTALLER_NAME \"")
					+ CUSTOM_PRODUCT_NAME + L" - Installer" + L"\"\r\n";

				text += "\r\n";

				text += AnsiString("!define PRODUCT_NAME \"")
					+ PRODUCT_NAME + "\"\r\n";
				text += AnsiString("!define PRODUCT_COMPANYNAME \"")
					+ PRODUCT_COMPANYNAME + "\"\r\n";
				text += AnsiString("!define PRODUCT_COPYRIGHT \"")
					+ PRODUCT_COPYRIGHT + "\"\r\n";
				/*text += AnsiString("!define PRODUCT_COMMENTS \"")
					+ PRODUCT_COMMENTS + "\"\r\n";*/
				text += AnsiString("!define PRODUCT_ORIGINAL_DEVELOPER \"")
					+ PRODUCT_ORIGINAL_DEVELOPER + "\"\r\n";
				text += AnsiString("!define PRODUCT_PROJECT_MANAGER \"")
					+ PRODUCT_PROJECT_MANAGER + "\"\r\n";

				text += "\r\n";

				text += AnsiString("!define PRODUCT_SITE_NAME \"")
					+ PRODUCT_SITE_NAME + "\"\r\n";
				text += AnsiString("!define PRODUCT_SITE_URL \"")
					+ PRODUCT_SITE_URL + "\"\r\n";
				text += AnsiString("!define PRODUCT_BUG_TRACKER \"")
					+ PRODUCT_BUG_TRACKER + "\"\r\n";
				text += AnsiString("!define PRODUCT_CONTACT_URL \"")
					+ PRODUCT_CONTACT_URL + "\"\r\n";
				text += AnsiString("!define PRODUCT_SUPPORT_URL \"")
					+ PRODUCT_SUPPORT_URL + "\"\r\n";

				text += "\r\n";

				text += AnsiString("!define CUSTOM_SITE_NAME \"")
					+ CUSTOM_SITE_NAME + "\"\r\n";
				text += AnsiString("!define CUSTOM_SITE_URL \"")
					+ CUSTOM_SITE_URL + "\"\r\n";

				fs->Write(text.c_str(), text.Length());
				delete fs;
			}
			else {
				UnicodeString msg = UnicodeString(L"Unknown command-line option \"") + lower_cmd + "\".";
				Application->MessageBox(msg.c_str(), CUSTOM_PRODUCT_NAME, MB_ICONSTOP);
			}

			return false;
		}
	}

	#ifndef _DEBUG
	if (FindWindowW(this->ClassName().c_str(), UnicodeString(CUSTOM_EXE_NAME).c_str())) {
		//check DDE connection
		TDdeClient* dde = new TDdeClient;
		if (dde->Connect()) { //another instance is running
			if (!cmd.IsEmpty()) dde->Exec("Add(\"" + cmd + "\")");
			else dde->Exec("Activate");

			return false; //exit application
		}
		delete dde;

	}
	#endif

	FileToAdd = cmd;

	this->Caption = CUSTOM_EXE_NAME;
	return true;
}
//---------------------------------------------------------------------------

void __fastcall TFramework::RegisterExt(UnicodeString Ext, bool RegisterFlag)
{
	UnicodeString verb = LowerCase(CUSTOM_EXE_NAME);

	TRegistry* reg = new TRegistry;
	reg->RootKey = HKEY_CLASSES_ROOT;

	if (RegisterFlag) {
//Register Ext
		reg->OpenKey("." + Ext, true);
		UnicodeString ext_class = reg->ReadString("");
		if (ext_class.IsEmpty()) {
			ext_class = UnicodeString(CUSTOM_EXE_NAME) + "." + Ext;
			reg->WriteString("", ext_class);
		}
		reg->CloseKey();

		reg->OpenKey(ext_class + "\\Shell\\" + verb, true);
		reg->WriteString("", "Upload to " + UnicodeString(CUSTOM_SITE_NAME));
		reg->CloseKey();

		reg->OpenKey(ext_class + "\\Shell\\" + verb + "\\command", true);
		reg->WriteString("", "\"" + Application->ExeName + "\" \"%1\"");
		reg->CloseKey();

		//DDE
		//[REM _DDE_Direct][FileOpen("%1")]
		reg->OpenKey(ext_class + "\\Shell\\" + verb + "\\ddeexec", true);
		reg->WriteString("", "Add(\"%1\")");
		reg->CloseKey();

		reg->OpenKey(ext_class + "\\Shell\\" + verb + "\\ddeexec\\Application", true);
		reg->WriteString("", CUSTOM_EXE_NAME);
		reg->CloseKey();

		reg->OpenKey(ext_class + "\\Shell\\" + verb + "\\ddeexec\\Topic", true);
		reg->WriteString("", L"System");
		reg->CloseKey();

		}
	else {
//Unregister Ext
		if (!reg->OpenKeyReadOnly("." + Ext)) return;
		UnicodeString ext_class = reg->ReadString("");
		reg->CloseKey();

		if (ext_class.IsEmpty()) return; //no class identifier
		if (ext_class == UnicodeString(CUSTOM_EXE_NAME) + "." + Ext) { //Create by this app
			reg->DeleteKey("." + Ext);
			reg->DeleteKey(ext_class);
			return;
		}

		reg->DeleteKey(ext_class + "\\Shell\\" + verb);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFramework::RegisterShellCommands(bool RegisterFlag)
{
	TStringList* Exts = new TStringList;
	Exts->CommaText = UnicodeString(CFG_DEFAULT_VIDEO_ALLOWEXTENSIONS);

	for (int i = 0; i < Exts->Count; i++) {
		try {
			this->RegisterExt(Exts->Strings[i], RegisterFlag);
		} catch (ERegistryException&) {
        	__asm nop;
		}
	}

	delete Exts;
}
//---------------------------------------------------------------------------

int __fastcall TFramework::ShowMessageBox(UnicodeString Msg, UnicodeString Title, int Options)
{
	if (Title.IsEmpty()) {
		Title = CUSTOM_PRODUCT_NAME;
	}
	if (MainForm) {
		MainForm->Reactivate();
		//MainForm->BringToFront();
	}

	int result = Application->MessageBox(Msg.c_str(),
		Title.IsEmpty()? NULL : Title.c_str(), Options);

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TFramework::ShowErrorMessage(UnicodeString Msg, UnicodeString Title,
	bool Warning)
{
	if (Title.IsEmpty()) {
		Title = Warning? L"Warning" : L"Error";
	}

	this->ShowMessageBox(Msg, Title, Warning? MB_ICONEXCLAMATION : MB_ICONSTOP);
}
//---------------------------------------------------------------------------

void __fastcall TFramework::BrowseURL(UnicodeString URL)
{
	ShellExecuteW(Application->Handle, L"open", URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

bool __fastcall TFramework::ExtractResourceToStream(AnsiString Resource, TStream* Stream)
{
	HGLOBAL hResLoad;   // handle to loaded resource
	HRSRC hRes;         // handle/ptr. to res. info. in hExe
	LPVOID lpResLock;   // pointer to resource data
	BOOL result;

	hRes = FindResource(NULL, Resource.c_str(), RT_RCDATA);
	if (hRes == NULL) return false;

	hResLoad = LoadResource(NULL, hRes);
	if (hResLoad == NULL) return false;

	lpResLock = LockResource(hResLoad);
	if (lpResLock == NULL) return false;

	Stream->Write(lpResLock, SizeofResource(NULL, hRes));
	//Housekeeping
	Stream->Position = 0;

	return true;
}
//---------------------------------------------------------------------------

void __fastcall TFramework::SystemExecuteMacro(TObject *Sender, TStrings *Msg)
{
	if (MainForm) MainForm->ExecuteDDEMacro(Msg);
}
//---------------------------------------------------------------------------

void __fastcall TFramework::DeleteFileStream(TFileStream* &fs, bool Temp)
{
	if (fs) {
		if (Temp) {
			UnicodeString file = fs->FileName;
			delete fs;
			DeleteFile(file);
		}
		else {
			delete fs;
		}
		fs = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFramework::CopyDir(UnicodeString Src, UnicodeString Dst)
{
	Src = AddBS(Src);
	Dst = AddBS(Dst);

	if (!ForceDirectories(Dst))
		throw new EFrameworkError(L"Cannot create directory \"" + Dst + "\".");

	TSearchRec sr;
	try {
		if (FindFirst(Src + L"*.*", faAnyFile, sr) == 0) {
			do {
				UnicodeString name = sr.Name;
				if (name == L"." || name == L"..") continue;
				if (sr.Attr & faDirectory) {
					this->CopyDir(Src + name, Dst + name);
				}
				else {
					this->CopyFile(Src + name, Dst + name);
				}
			} while (FindNext(sr) == 0);
		}
	}
	catch (EAbort&) {
		FindClose(sr);
		Abort();
	}
	catch (Exception& e) {
		FindClose(sr);
		throw EFrameworkError(e.Message);
	}

	FindClose(sr);
}
//---------------------------------------------------------------------------

void __fastcall TFramework::CopyFile(UnicodeString Src, UnicodeString Dst)
{
	TFileStream* source = NULL;
	TFileStream* target = NULL;

	try {
		source = new TFileStream(Src, fmOpenRead);
		target = new TFileStream(Dst, fmCreate);
		__int64 cnt = 0;
		__int64 max = source->Size;
		source->Position = 0;

		__int64 dod;
		do {
			dod = COPY_FILE_BUFFER; // Block size
			if (cnt+dod > max) {
				dod = max-cnt;
			}
			if (dod > 0) {
				__int64 did = target->CopyFrom(source, dod);
				cnt = cnt+did;
			}
		} while (dod > 0);
	}
	catch (EFOpenError &e) {
		delete source; source = NULL;
		delete target; target = NULL;
		DeleteFile(Dst);
		throw EFrameworkError(e.Message);
	}
	catch (EStreamError &e) {
		delete source; source = NULL;
		delete target; target = NULL;
		DeleteFile(Dst);
		throw EFrameworkError(e.Message);
	}
	delete source;
	delete target;
 }
 //---------------------------------------------------------------------------

