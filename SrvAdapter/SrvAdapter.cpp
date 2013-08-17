/*---------------------------------------------------------------------------
$Id: SrvAdapter.cpp 527 2011-02-11 11:01:47Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <typeinfo.h>
#include <StrUtils.hpp>
#include <Math.hpp>

#include "Product.h"
#include "Utils.h"
#include "MUI.h"

#pragma hdrstop

#include <HttpApp.hpp>
//Image classes needed for avatar handling:
#include <jpeg.hpp>
#include <pngimage.hpp>
#include <gifimg.hpp>

#include <IdAuthenticationDigest.hpp>

#include "MediaConversion.h"
#include "TFramework.h"
extern TFramework* Framework;
#include "Custom/HTTPAuth.h"
#include "Custom/ProxyAuth.h"

#include "SrvAdapter.h"
//---------------------------------------------------------------------------

//HTTP client settings
#define SOCKET_RETRY_COUNT				2
#define PREUPLOAD_MAX_ATTEMPTS 			10

#define PROGRESS_REQUEST				0.005
#define PROGRESS_SHORTRESPONSE			0.005+PROGRESS_REQUEST

//YouTube grabbing constants
#define YT_REDIRECT_MAXIMUM 			100
#define PROGRESS_DOWNLOAD_THUMB			0.01
#define YT_THUMBCOUNT					3
#define YT_BIGTHUMB_SIZEFACTOR			5

//Video converter settings
#define PROGRESS_GENERATE_THUMB			0.005
#define PROGRESS_POSTPROCESS_MP4 		0.025
#define PROGRESS_POSTPROCESS_FLV 		0.20

#define THUMB_TIME_OFFSET 				0.10

//Hashing settings
#define MAX_HASHING_SIZE				1073741824

//Post flags
#define POST_LOGIN 		0x01
#define POST_SILENT		0x02
#define POST_AUX		0x04

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdIOHandlerStream"
#pragma link "IdIOHandlerSocket"
#pragma link "IdAntiFreeze"
#pragma link "IdAntiFreezeBase"
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdCompressorZLib"
#pragma link "IdHTTP"
#pragma link "IdIOHandler"
#pragma link "IdIOHandlerStack"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "IdZLibCompressorBase"
#pragma resource "*.dfm"
TSrvAdapterModule *SrvAdapterModule;
//---------------------------------------------------------------------------

__fastcall TSrvAdapterModule::TSrvAdapterModule(TComponent* Owner)
	: TDataModule(Owner)
{
	//Base64
	this->encoderBase64 = new TIdEncoderMIME(NULL);
	this->encoderBase64->InitComponent(); //workaround for known bug:
	this->decoderBase64 = new TIdDecoderMIME(NULL);

    //Properties
	this->Busy = 0;
	this->FProgress = NULL;

	this->FSession = NULL;

	this->UserAgent_YT = "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0)";

	//Restore user info
	this->FUsername = Framework->IniFile->ReadString(L"Login", L"Username", L"");
	this->FPassword = this->DecryptPassword(
		Framework->IniFile->ReadString(L"Login", L"Password", L""));
	this->FRememberUser = !(this->FUsername.IsEmpty() || this->FPassword.IsEmpty());

	this->FAvatar = NULL;
	this->FWatermark = NULL;

	this->FHTTPAuthFailed = false;
	this->FProxyAuthFailed = false;
}
//---------------------------------------------------------------------------

__fastcall TSrvAdapterModule::~TSrvAdapterModule()
{
	delete this->FSession;
	delete this->FProgress;
	delete this->encoderBase64;
	delete this->decoderBase64;
	delete this->FAvatar;
	Framework->DeleteFileStream(this->FWatermark);
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::DataModuleCreate(TObject *Sender)
{
	AnsiString sec = this->EncryptPassword(L"dsfsdfsd");
	UnicodeString sec2 = this->DecryptPassword(sec);

//Get proxy info
	#ifdef CUSTOM_PROXY_SERVER
		this->HTTPClient->ProxyParams->ProxyServer = CUSTOM_PROXY_SERVER;
		this->HTTPClient->ProxyParams->ProxyPort   = CUSTOM_PROXY_PORT;
	#else
		//Read system settings

		/* get handle to dll */
		HINSTANCE hGetProcIDDLL = LoadLibrary("wininet.dll");

		/* get pointer to the function in the dll*/
		FARPROC lpfnGetProcessID = GetProcAddress(HMODULE (hGetProcIDDLL),
			"InternetQueryOptionA");

		typedef bool (__stdcall * pICFUNC)( HINTERNET, DWORD, LPVOID, LPDWORD);

		pICFUNC InternetQueryOption;
		InternetQueryOption = pICFUNC(lpfnGetProcessID);

		unsigned long        nSize = 4096;
		char                 szBuf[4096] = { 0 };
		INTERNET_PROXY_INFO* pInfo = (INTERNET_PROXY_INFO*)szBuf;

		if (InternetQueryOption(NULL, INTERNET_OPTION_PROXY, pInfo, &nSize)) {
			if (pInfo->dwAccessType == INTERNET_OPEN_TYPE_PROXY)  {
				UnicodeString Proxy = UnicodeString(pInfo->lpszProxy);
				int pos = Proxy.Pos(L":");
				if (pos) {
					this->HTTPClient->ProxyParams->ProxyServer = Proxy.SubString(1, pos-1);
					this->HTTPClient->ProxyParams->ProxyPort   = Proxy.SubString(pos+1, Proxy.Length()-pos).ToIntDef(80);
				}
			}
		}

		FreeLibrary(hGetProcIDDLL);
	#endif

	#ifdef CUSTOM_PROXY_USERNAME
    	// Set default username and password
		this->HTTPClient->ProxyParams->ProxyUsername = CUSTOM_PROXY_USERNAME;
		this->HTTPClient->ProxyParams->ProxyPassword = CUSTOM_PROXY_PASSWORD;
	#endif

	//Copy proxy config to aux client:
	this->HTTPClientAux->ProxyParams->ProxyServer =
		this->HTTPClient->ProxyParams->ProxyServer;
	this->HTTPClientAux->ProxyParams->ProxyPort =
		this->HTTPClient->ProxyParams->ProxyPort;
	this->HTTPClientAux->ProxyParams->ProxyUsername =
		this->HTTPClient->ProxyParams->ProxyUsername;
	this->HTTPClientAux->ProxyParams->ProxyPassword =
		this->HTTPClient->ProxyParams->ProxyPassword;

	//Setup Debug output
	#ifdef _DEBUG
		TIdLogDebug* log = new TIdLogDebug(this);
		log->Active = true;
		this->HTTPClient->Intercept = log;
		this->HTTPClientAux->Intercept = log;
	#endif

	//Setup pinger:
	#ifdef CUSTOM_PING_INTERVAL
		this->PingTimer->Interval = CUSTOM_PING_INTERVAL * 1000;
	#endif

	//Login
	Framework->InitLogin();
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::Login(UnicodeString Username,
	UnicodeString Password, bool RememberUser)
{
	this->Logout(false);

	UnicodeString text;
	int result = 0;
	TSrvResponse* info = NULL;
    #ifdef CLIPBUCKET_TARGET
		UnicodeString pass = md5(md5(sha1(sha1(md5(Password)))));
    #endif

	#if defined MD5_PASSWORD
	    UnicodeString pass = md5(Password);
    #endif

	#if defined PLAINTEXT_PASSWORD
		UnicodeString pass = Password;
	#endif

	this->FSession = new TSrvSession;

	try {
		result = this->CS_Login(text, Username, pass);

		if (result != 0) return result; //HTTP error or terminated
		try {
			info = new TSrvResponse(text);
		}
		catch (ESrvResponseError& e) {
			result = SRVADAPTER_ERROR_PARSE; //Parse error
			throw LoadStr(LANG_INVALID_SERVER_RESPONSE) + ":\n" + e.Message;
		}

		if (info->StatusCode > 0) {
			result = info->StatusCode; //Login error
			throw info->ErrorMessage;
		}

		//Read settings
		TSrvSettings* settings = NULL;
		try {
			settings = new TSrvSettings(info);
		}
		catch (ESrvResponseError& e) {
			result = SRVADAPTER_ERROR_PARSE; //Parse error
			throw LoadStr(LANG_INVALID_SERVER_RESPONSE) + ":\n" + e.Message;
		}
		this->FSession->Start(settings);

		//Download avatar
		delete this->FAvatar; this->FAvatar = NULL;

		if (settings->DisplayAvatar) {
			TMemoryStream* ms = NULL;
			TGraphic* graphic = NULL;

			if (!info->AvatarURL.IsEmpty()) {
				try {
					ms = new TMemoryStream;
					try {
						this->Get(info->AvatarURL, ms, true);
					}
					catch (...) {
						Abort();
					}
					UnicodeString mediatype = this->HTTPClient->Response->ContentType;
					if (StartsStr(L"image/", mediatype)) {
						graphic =
							(mediatype == L"image/jpeg")? 	(TGraphic*) new TJPEGImage :
							(mediatype == L"image/png")? 	(TGraphic*) new TPngImage :
							(mediatype == L"image/gif")?	(TGraphic*)	new TGIFImage :
							NULL;
					}
					if (!graphic) Abort();

					ms->Position = 0;
					try {
						graphic->LoadFromStream(ms);
					}
					catch (...) {
						Abort();
					}
				}
				catch (EAbort& e) {
					delete graphic;
				}
			}
			delete ms;

			if (graphic) {
				this->FAvatar = graphic;
			}
			else {  //Default avatar
				graphic = new TJPEGImage;
				ms = new TMemoryStream;
				if (Framework->ExtractResourceToStream("NoAvatar", ms)) {
					ms->Position = 0;
					graphic->LoadFromStream(ms);
				}
				else {
					delete graphic; graphic = NULL;
				}
				delete ms;
			}

			this->FAvatar = graphic;
		}

		//Extract or download watermark
		if (settings->Video && settings->Video->WatermarkEnabled) {
			Framework->DeleteFileStream(this->FWatermark);
			UnicodeString file = Framework->GetNewTempFile();
			TFileStream* fs = new TFileStream(file, OPENMODE_TMPFILE);

			bool loaded = false;
			if (!info->WatermarkURL.IsEmpty()) {
				//Download:
                try {
					this->Get(info->WatermarkURL, fs, true);
					loaded = true;
				}
				catch (...) {
					//Nothing
				}
			}
			if (!loaded) {
				Framework->ExtractResourceToStream("Watermark", fs);
			}

			delete fs;
			this->FWatermark = new TFileStream(file, OPENMODE_INPUTFILE);
		}

	}
	catch (UnicodeString Msg) {
		if (result>0 && result<100) {  //Fatal error
			Framework->ShowErrorMessage(Msg
				+ L"\n\nThe application cannot be used and will exit now.",
				"Login Error");
			Application->Terminate();
		}
		else Framework->ShowErrorMessage(Msg, L"Login Error");
	}

	if (result==0) {
		this->FUsername = Username;
		this->FPassword = Password;
		this->FRememberUser = RememberUser;

		if (RememberUser) {
			Framework->IniFile->WriteString(L"Login", L"Username", Username);
			Framework->IniFile->WriteString(L"Login", L"Password",
				this->EncryptPassword(Password));
			Framework->SaveIni();
		}

		//Enable ping timer
		this->PingTimer->Enabled = true;
	}
	else {
        delete this->FSession; this->FSession = NULL;
    }

	delete info;
	return result;
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::ReLogin()
{
	return this->Login(this->FUsername, this->FPassword, this->FRememberUser);
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::Logout(bool ClearCredentials)
{
	//Disable ping timer
	this->PingTimer->Enabled = false;
	this->AntiFreeze->Active = false;

	if (this->Authorized) {
        this->CS_Logout();
	}

	this->Cookies->CookieCollection->Clear();

	if (ClearCredentials) {
		this->FUsername = L"";
		this->FPassword = L"";
		this->FRememberUser = false;

		Framework->IniFile->EraseSection(L"Login");
		Framework->SaveIni();
	}

	if (this->FSession) {
		delete this->FSession;
		this->FSession = NULL;
	}

	this->AntiFreeze->Active = true;
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::Upload(TMediaItem *MI)
{
	TStream* torrent = MI->TorrentData;
	MI->TorrentMD5 = torrent? md5(torrent) : AnsiString("");

	UnicodeString text;
	TSrvResponse* info = NULL;
	int result = 0;
	float progress = 0.00;

	try {
		UnicodeString filename;
		for (short i = 0; i < PREUPLOAD_MAX_ATTEMPTS; i++) {
			delete info; info = NULL;
			filename = IntToStr(
				(__int64)Int(Random()*(1000000000000000.0-1000000.0)+1000000.0)
			);

			UnicodeString oper = L"Requesting upload";
			if (i>0) oper += L" (" + IntToStr(i+1) + L")";

			this->StartProgress(oper, progress+PROGRESS_REQUEST,
				progress+=PROGRESS_SHORTRESPONSE, pmmAuxiliary);

			result = this->CS_PreUpload(text, MI, filename);

			if (result != 0) return result; //HTTP error or terminated
			info = new TSrvResponse(text);

			if (info->StatusCode != 201) break;
		}
		if (!info) { //Max count exceeded
			result = SRVADAPTER_ERROR_MAXCOUNT;
			throw UnicodeString(L"Failed to get upload permission.");
		}

		if (info->StatusCode) {
			result = info->StatusCode; //Login error
			throw info->ErrorMessage;
		}
		delete info; info = NULL;

		this->StartProgress(L"", progress, 1.00, pmmMain);

		result = this->CS_Upload(text, MI, filename);
		if (result != 0) Abort(); //HTTP error or terminated
		info = new TSrvResponse(text);
		if (info->StatusCode) {
			result = info->StatusCode; //Login error
			throw info->ErrorMessage;
		}
	}
	catch (ESrvResponseError& e) {
		this->StopProgress();
		result = SRVADAPTER_ERROR_PARSE; //Parse error
		Framework->ShowErrorMessage(LoadStr(LANG_INVALID_SERVER_RESPONSE) + ":\n"
			+ e.Message, L"Upload Error");
	}
	catch (UnicodeString Msg) {
		this->StopProgress();
		if (result>0 && result<100) {  //Fatal error
			Framework->ShowErrorMessage(Msg
				+ L"\n\nThe application cannot be used and will exit now.",
				"Login Error");
			Application->Terminate();
		}
		else Framework->ShowErrorMessage(Msg, L"Upload Error");
	}
	catch (EAbort&) {
		__asm nop;
	}
	this->StopProgress();

	delete info; info = NULL;

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::Ping()
{
	this->AntiFreeze->Active = false;

	this->CS_Ping();

	this->AntiFreeze->Active = true;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Data transfer methods
//---------------------------------------------------------------------------
int __fastcall TSrvAdapterModule::CS_Post(UnicodeString &ResponseText,
		TIdMultiPartFormDataStream* PostData, unsigned int Flags)
{
	int result = SRVADAPTER_OK;

	TMemoryStream* response = new TMemoryStream;

	if (Flags & POST_AUX) {
		TIdHTTP* http = this->HTTPClientAux;
		http->Request->UserAgent = this->GetUserAgent();
		try {
			http->Post(CUSTOM_UPLOAD_URL, PostData, response);
		}
		catch (...) {
			result = SRVADAPTER_ERROR_HTTP;
			http->DisconnectNotifyPeer();
			http->IOHandler->Close();
		}
	}
	else {
		this->HTTPClient->Request->UserAgent = this->GetUserAgent();

		this->Busy = 1;
		try {
			this->Post(CUSTOM_UPLOAD_URL, PostData, response);
		}
		catch (ECommunicationError& e) {
			this->HandleHTTPError(Flags & POST_SILENT? UnicodeString(L"")
				: e.Message,
				e.Type
			);
			result = SRVADAPTER_ERROR_HTTP;
		}
		catch (EAbort&)	{
			result = SRVADAPTER_ERROR_TERMINATED; //Terminated
		}
		this->Busy = 0;
	}

	if (result==SRVADAPTER_OK) {
		#ifdef CFG_RESPONSE_VER2
			TStringStream* ss = new TStringStream(L"", TEncoding::ASCII, true);
			ss->LoadFromStream(response);

			#ifdef _DEBUG
				TStringStream* dbg = new TStringStream(L"", TEncoding::UTF8, true);
				dbg->LoadFromStream(response);
				MessageBoxW(Application->Handle,
					((Flags & POST_AUX?
						this->HTTPClientAux->Response->RawHeaders->Text
						: this->HTTPClient->Response->RawHeaders->Text)
					+ L"\n---------------------------------------------------------------------------\n"
					+ dbg->DataString).c_str(),
					L"Raw Server Response:", 0);
				delete dbg;
			#endif

			try {
				ResponseText = this->Decrypt(ss->DataString, Flags & POST_LOGIN);
			}
			catch (ERSAError& e) {
				delete ss;
				return SRVADAPTER_ERROR_CRYPT;
			}

            delete ss;
		#else
			TStringStream* ss = new TStringStream(L"", TEncoding::UTF8, true);
			ss->LoadFromStream(response);
			ResponseText = ss->DataString;
			delete ss;
		#endif


		#ifdef _DEBUG
			MessageBoxW(Application->Handle, ResponseText.c_str(),
				L"Decoded Server Response:", 0);
		#endif
	}

	return result;
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::CS_Login(UnicodeString &ResponseText,
	UnicodeString Username, UnicodeString Password)
{
	TIdMultiPartFormDataStream* PostData = new TIdMultiPartFormDataStream;

	#ifdef CFG_REQUEST_VER2	//New-style request
		TXMLRequest* msg = new TXMLRequest("login");
		#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
			msg->SetProperty("ExecutableSHA1", this->GetExecutableSHA1());
		#endif
		#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
			msg->SetProperty("VersionSHA1", this->GetVersionSHA1());
		#endif
		msg->SetProperty("UserName", Username);
		msg->SetProperty("Password", Password);

		//Send signature key
		TMemoryStream* ms = new TMemoryStream;
		this->Session->RSA->ExportClientSignKey(ms);
		msg->SetProperty("SignKey", base64_encode(ms));
		delete ms;

		bool res = this->WriteXMLData(msg, PostData);
		delete msg;
		if (!res) {
			delete PostData;
			return SRVADAPTER_ERROR_CRYPT;
		}
	#endif

	int result = this->CS_Post(ResponseText, PostData, POST_LOGIN);

	delete PostData;

	return result;
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::CS_PreUpload(UnicodeString &ResponseText,
	TMediaItem* MI, AnsiString FileName)
{
	TIdMultiPartFormDataStream* PostData = new TIdMultiPartFormDataStream;

	#ifdef CFG_REQUEST_VER2	//New-style request
		TXMLRequest* msg = new TXMLRequest("preupload");
		#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
			msg->SetProperty("ExecutableSHA1", this->GetExecutableSHA1());
		#endif
		#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
			msg->SetProperty("VersionSHA1", this->GetVersionSHA1());
		#endif
		if (MI->EmbedCode.IsEmpty()) {
			msg->SetProperty("FileName", FileName + L"." + MI->FileExt);
		}
		msg->SetProperty("FileSize", MI->GetUploadSize());

		if (!MI->MediaMD5.IsEmpty()) msg->SetProperty(L"MediaMD5", MI->MediaMD5);
		if (!MI->TorrentMD5.IsEmpty()) msg->SetProperty(L"TorrentMD5", MI->TorrentMD5);

		if (!MI->EmbedCode.IsEmpty()) {
			msg->SetProperty(L"IsEmbedCode", L"1");
			msg->SetProperty("FileName", FileName + L".flv");
		}

		bool res = this->WriteXMLData(msg, PostData);
		delete msg;
		if (!res) {
			delete PostData;
			return SRVADAPTER_ERROR_CRYPT;
		}
	#endif

	int result = this->CS_Post(ResponseText, PostData);

	delete PostData;

	return result;
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::CS_Upload(UnicodeString &ResponseText,
	TMediaItem* MI, UnicodeString FileName)
{
	//Preprocessing
	TMetadata* meta = MI->Metadata;
	bool has_torrent = MI->TorrentData!=NULL;
	bool has_picture = MI->PictureData!=NULL;

	TIdMultiPartFormDataStream* PostData = new TIdMultiPartFormDataStream;

	#ifdef CFG_REQUEST_VER2	//New-style request
		TXMLRequest* msg = new TXMLRequest("upload");

		#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
			msg->SetProperty("ExecutableSHA1", this->GetExecutableSHA1());
		#endif
		#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
			msg->SetProperty("VersionSHA1", this->GetVersionSHA1());
		#endif

        if (MI->EmbedCode.IsEmpty())
        {
            msg->SetProperty("FileName", FileName + L"." + MI->FileExt);
        }
		msg->SetProperty("FileSize", MI->GetUploadSize());

		if (meta) {
			msg->SetProperty(L"Duration", UnicodeString(Round(meta->Duration)));
			if (meta->Resolution) {
				msg->SetProperty(L"Width", meta->Resolution->Width);
				msg->SetProperty(L"Height", meta->Resolution->Height);
			}
			if (!meta->AspectRatio_String.IsEmpty()) {
				msg->SetProperty(L"AspectRatio", meta->AspectRatio_String);
			}
		}

		msg->SetProperty(L"Title", MI->Title);
		msg->SetProperty(L"Description", MI->Description);
		msg->SetProperty(L"Tags", MI->Tags);
		msg->SetProperty(L"Categories", MI->Categories->DelimitedText);
		msg->SetProperty(L"Broadcast", MI->Broadcast==0? L"public" : L"private");
		if (MI->hasDate) {
			msg->SetProperty(L"Date", IntToStr(DateToUnixTimeStamp(MI->Date)));
		}
		if (!MI->Country.IsEmpty())
        {
		    msg->SetProperty(L"Country", MI->Country);
        }
        if (!MI->Location.IsEmpty())
        {
		    msg->SetProperty(L"Location", MI->Location);
        }
		msg->SetProperty(L"AllowComments", BoolToYesNo(MI->AllowComments));
		msg->SetProperty(L"AllowVoting",  BoolToYesNo(MI->AllowVoting));
		msg->SetProperty(L"AllowRating",  BoolToYesNo(MI->AllowRating));
		msg->SetProperty(L"AllowEmbedding",  BoolToYesNo(MI->AllowEmbedding));

		if (MI->External && MI->YouTube_fmt >= 0) {
			msg->SetProperty(L"YoutubeFormat", MI->YouTube_fmt);
		}

		if (!MI->EmbedCode.IsEmpty()) {
			msg->SetProperty(L"EmbedCode", MI->EmbedCode);
			msg->SetProperty(L"EmbedURL", MI->EmbedURL);
			msg->SetProperty(L"EmbedFileName", FileName + L".flv");
			msg->SetProperty(L"FileName", FileName + L".flv");
			msg->SetProperty(L"IsEmbedCode", L"1");
		}

		if (MI->MediaMD5.IsEmpty()) throw Exception(L"Media MD5 not found"); //debug exception
		msg->SetProperty(L"MediaMD5", MI->MediaMD5);

		msg->SetProperty(L"HasTorrent", has_torrent? L"1" : L"0");
		if (has_torrent) {
			if (MI->TorrentMD5.IsEmpty()) throw Exception(L"Torrent MD5 not found"); //debug exception

			msg->SetProperty(L"TorrentMD5", MI->TorrentMD5);
		}

		msg->SetProperty(L"AudioHasPic", has_picture? L"1" : L"0");

		//thumbnail count:
		if (MI->Thumbs) {
			msg->SetProperty(L"ThumbCount", MI->Thumbs->List->Count);
			msg->SetProperty(L"ThumbCountBig", MI->Thumbs->BigList->Count);
		}

		bool res = this->WriteXMLData(msg, PostData);
		delete msg;
		if (!res) {
			delete PostData;
			return SRVADAPTER_ERROR_CRYPT;
		}
	#endif

	//Files:
		if (MI->EmbedCode.IsEmpty()) {
			PostData->AddObject(L"upfile", MI->InternetMediaType,
				MI->GetUploadData(), FileName + L"." + MI->FileExt);
		}
		if (MI->Thumbs) {
			int count = MI->Thumbs->List->Count;
			for (int i = 0; i < count; i++) {
				TFileStream* fs = (TFileStream*) MI->Thumbs->List->Items[i];
				UnicodeString sIndex = IntToStr(i+1);
				PostData->AddObject(L"thumb_" + sIndex, L"image/jpeg",
					fs, FileName + L"-" + sIndex + L".jpg");
			}

			int countBig = MI->Thumbs->BigList->Count;
			for (int i = 0; i < countBig; i++) {
				TFileStream* fs = (TFileStream*) MI->Thumbs->BigList->Items[i];
				UnicodeString sIndex = IntToStr(i+1);
				PostData->AddObject(L"thumb_big_" + sIndex, L"image/jpeg",
					fs, FileName + L"-big-" + sIndex + L".jpg");
			}
		}
		if (has_torrent) {
			PostData->AddObject(L"torrent", L"application/x-bittorrent", MI->TorrentData,
				FileName + L".torrent");
		}
		if (has_picture) {
			UnicodeString ext = GetFileExt(MI->PictureData->FileName);
			PostData->AddObject(L"audio_pic", L"image/" + ext,
				MI->PictureData, FileName + L"." + ext);
		}
	//End of files

	int result = this->CS_Post(ResponseText, PostData);

	delete PostData;

	return result;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::CS_Logout()
{
	TIdMultiPartFormDataStream* PostData = new TIdMultiPartFormDataStream;

	#ifdef CFG_REQUEST_VER2	//New-style request
		TXMLRequest* msg = new TXMLRequest("logout");

		#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
			msg->SetProperty("ExecutableSHA1", this->GetExecutableSHA1());
		#endif
		#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
			msg->SetProperty("VersionSHA1", this->GetVersionSHA1());
		#endif

		bool res = this->WriteXMLData(msg, PostData);
		delete msg;
		if (!res) {
			delete PostData;
			return;
		}
	#endif

	UnicodeString ResponseText;
	this->CS_Post(ResponseText, PostData, POST_SILENT);

	delete PostData;
}
//---------------------------------------------------------------------------

int __fastcall TSrvAdapterModule::CS_Ping()
{
	TIdMultiPartFormDataStream* PostData = new TIdMultiPartFormDataStream;

	#ifdef CFG_REQUEST_VER2	//New-style request
		TXMLRequest* msg = new TXMLRequest("ping");

		#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
			msg->SetProperty("ExecutableSHA1", this->GetExecutableSHA1());
		#endif
		#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
			msg->SetProperty("VersionSHA1", this->GetVersionSHA1());
		#endif

		bool res = this->WriteXMLData(msg, PostData);
		delete msg;
		if (!res) {
			delete PostData;
			return SRVADAPTER_ERROR_CRYPT;
		}
	#endif

	UnicodeString ResponseText;
	int result = this->CS_Post(ResponseText, PostData, POST_AUX|POST_SILENT);

	delete PostData;

	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// YouTube methods
//---------------------------------------------------------------------------
#ifdef CUSTOM_YOUTUBE

__int64 __fastcall TSrvAdapterModule::YT_GetFileSize(UnicodeString ID,
	int Quality)
{
	__int64 result = -1;
	int fmt = -1;

	TIdHTTP* http = this->HTTPClient;
	#include "YT_HTTP_begin.h"
	this->Busy = 1;
	try {
    	this->YT_GetDownloadURL(ID, Quality, result, fmt);
	}
	catch (UnicodeString msg) {
		result = -1;
		Framework->ShowErrorMessage(msg, L"YouTube Error");
	}
	catch (ECommunicationError& e) {
		result = -1;
		if (e.Type==cetHTTP && http->ResponseCode==400) {
			this->StopProgress();
			Framework->ShowErrorMessage(L"Invalid video ID.", L"YouTube Error");
		}
		else {
			this->HandleHTTPError(e.Message, e.Type);
		}
	}
	catch (EAbort&)	{
    	result = -1;
		__asm nop;
	}
	this->Busy = 0;
	#include "YT_HTTP_end.h"

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::YT_Download(TMediaItem* MI, UnicodeString ID,
	int Quality)
{
	TSrvSettings* s = this->FSession->Settings;
	TSrvVideoSettings* media = s->Video;

	MI->External = true;
	MI->TempInput = true;
	MI->UploadInput = !media->WatermarkEnabled;
	MI->Type = mitVideoYoutube;

	TFileStream* fs = NULL;
	UnicodeString file = L"";
	TThumbs* thumbs = NULL;
	TFFmpegConsole* fc = NULL;

	TIdHTTP* http = this->HTTPClient;
	#include "YT_HTTP_begin.h"
	bool result = false;
	this->Busy = 1;
	try {
		//Get download URL
		float progress = 0;
		this->StartProgress(L"Requesting video download",
			progress+PROGRESS_REQUEST, progress+=PROGRESS_SHORTRESPONSE,
			pmmAuxiliary
		);
		__int64 size = -1;
		int fmt = -1;
		UnicodeString url = this->YT_GetDownloadURL(ID, Quality, size, fmt);
		MI->UploadFormat = YT_FmtToStr(fmt);

		//Get info
		this->StartProgress(L"Retrieving video information",
			progress+PROGRESS_REQUEST, progress+=PROGRESS_SHORTRESPONSE,
			pmmAuxiliary
		);
		this->YT_GetInfo(MI, ID);

		//Download
		this->StartProgress(L"", progress+PROGRESS_REQUEST,
			progress = 1.00 - (YT_THUMBCOUNT * PROGRESS_DOWNLOAD_THUMB)
			- ((float)media->ThumbCountBig * PROGRESS_GENERATE_THUMB),
			pmmMain
		);
		file = Framework->GetNewTempFile();
		fs = new TFileStream(file, fmCreate);
		this->Get(url, fs, true);

		//Media type
		UnicodeString mt = HTTPClient->Response->ContentType;
		if (mt == L"video/flv" || mt == L"video/x-flv") {
			MI->InternetMediaType = L"video/flv";
			MI->FileExt = L"flv";
			MI->UploadFormat = L"flv";
			//Needs post processing:
			MI->UploadInput = false;
		}
		else if (mt == L"video/mp4" || mt == L"video/x-mp4") {
			MI->InternetMediaType = L"video/mp4";
			MI->FileExt = L"mp4";
			MI->UploadFormat = L"mp4";
		}
		else {
			throw UnicodeString(L"Invalid media type: ") + mt;
		}

		//Reopen with shared access
		delete fs;
		fs = new TFileStream(file, OPENMODE_INPUTFILE);

		//Hash
		//MI->MediaMD5 = this->HashMedia(fs);
		//Replaced with YouTube style ID:
		MI->MediaMD5 = ID + L"&" + (fmt==5? UnicodeString(L"0") : IntToStr(fmt));

		if (media->YTDownloadThumbnails) {
			// Download thumbnails
			thumbs = new TThumbs;
			for (int i = 0; i < YT_THUMBCOUNT; i++) {
				this->StartProgress(L"Downloading thumbnails (" + IntToStr(i+1) + L")",
					progress, progress+=PROGRESS_DOWNLOAD_THUMB, pmmAuxiliary);
				TFileStream* tfs = new TFileStream(Framework->GetNewTempFile(), fmCreate);
				this->Get(Format(YT_LINK_THUMB, ARRAYOFCONST((ID, IntToStr(i+1)))),
					tfs, true);
				thumbs->List->Add((void*) tfs);
			}

			//Generate big thumbs
			this->StartProgress(L"Generating big thumbnails", progress,
				progress += (float)media->ThumbCountBig * PROGRESS_GENERATE_THUMB
			);
			fc = new TFFmpegConsole(file, mtVideo, s->ExternalProcessPriority);
			this->MakeThumbnailList(true, thumbs->BigList, L"",
				media->ThumbCountBig, NULL, fc, NULL);

			delete fc; fc = NULL;
		}

		//Finish
		MI->InputData = fs;
		MI->Label = Format(YT_SHORT, ARRAYOFCONST((ID)));
		MI->Location = Format(YT_LINK, ARRAYOFCONST((ID)));
		MI->Thumbs = thumbs; thumbs = NULL;
		result = true;
	}
	catch (UnicodeString msg) {
		this->StopProgress();
		Framework->ShowErrorMessage(msg, L"YouTube Error");
	}
	catch (EFOpenError& e) {
		this->StopProgress();
		Framework->ShowErrorMessage(e.Message);
	}
	catch (EFrameworkError& e) {
		this->StopProgress();
		Framework->ShowErrorMessage(e.Message);
	}
	catch (EOSError& e) {
		this->StopProgress();
		Framework->ShowErrorMessage(e.Message);
	}
	catch (ECommunicationError& e) {
		if (e.Type==cetHTTP && http->ResponseCode==400) {
			this->StopProgress();
			Framework->ShowErrorMessage(L"Invalid video ID.", L"YouTube Error");
		}
		else {
			this->HandleHTTPError(e.Message, e.Type);
		}
	}
	catch (EAbort&)	{
		__asm nop;
	}
	#include "YT_HTTP_end.h"
	this->StopProgress();
	this->Busy = 0;

	if (!result) {
		delete fs;
		delete fc;
		if (!file.IsEmpty()) DeleteFile(file);
		delete thumbs;
	}

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::YT_Embed(TMediaItem* MI, UnicodeString ID)
{
	MI->External = true;
	MI->Type = mitVideoYoutubeEmbed;
	MI->EmbedURL = Format(YT_LINK, ARRAYOFCONST((ID)));
	MI->EmbedCode = Format(YT_EMBED_CODE, ARRAYOFCONST((ID)));
	MI->MediaMD5 = md5(MI->EmbedCode);

	TThumbs* thumbs = NULL;

	float progress_part = 1.00 / (1 + YT_THUMBCOUNT + YT_BIGTHUMB_SIZEFACTOR);
	float progress = 0.00;

	TIdHTTP* http = this->HTTPClient;
	#include "YT_HTTP_begin.h"
	bool result = false;
	this->Busy = 1;
	try {
//Get video info
		this->StartProgress(L"Retrieving video information",
			progress+PROGRESS_REQUEST, progress+=progress_part,
			pmmAuxiliary
		);
		this->YT_GetInfo(MI, ID);

// Download thumbnails
		thumbs = new TThumbs;
		for (int i = 0; i < YT_THUMBCOUNT; i++) {
			this->StartProgress(L"Downloading thumbnails (" + IntToStr(i+1) + L")",
				progress, progress+=PROGRESS_DOWNLOAD_THUMB, pmmAuxiliary);
			TFileStream* tfs = new TFileStream(Framework->GetNewTempFile(), fmCreate);
			this->Get(Format(YT_LINK_THUMB, ARRAYOFCONST((ID, IntToStr(i+1)))),
				tfs, true);
			thumbs->List->Add((void*) tfs);
		}
		//Download big thumbnail
		this->StartProgress(L"Downloading big thumbnail",
			progress+PROGRESS_REQUEST, progress+=progress_part*YT_BIGTHUMB_SIZEFACTOR,
			pmmAuxiliary
		);
		TFileStream* tfs = new TFileStream(Framework->GetNewTempFile(), fmCreate);
		thumbs->BigList->Add((void*) tfs);

		this->Get(Format(YT_LINK_THUMB, ARRAYOFCONST((ID, L"0"))),
			tfs, true);

		//Finish
		MI->Thumbs = thumbs; thumbs = NULL;
		MI->Label = Format(YT_SHORT, ARRAYOFCONST((ID)));
		MI->MediaLocation = Format(YT_LINK, ARRAYOFCONST((ID)));
		result = true;
	}
	catch (UnicodeString msg) {
		this->StopProgress();
		Framework->ShowErrorMessage(msg, L"YouTube Error");
	}
	catch (EFOpenError& e) {
		this->StopProgress();
		Framework->ShowErrorMessage(e.Message);
	}
	catch (EFrameworkError& e) {
		this->StopProgress();
		Framework->ShowErrorMessage(e.Message);
	}
	catch (ECommunicationError& e) {
		if (e.Type==cetHTTP && http->ResponseCode==400) {
			this->StopProgress();
			Framework->ShowErrorMessage(L"Invalid video ID.", L"YouTube Error");
		}
		else if (e.Type==cetHTTP && http->ResponseCode==404) {
			this->StopProgress();
			Framework->ShowErrorMessage(L"Video not found.", L"YouTube Error");
		}
		else {
			this->HandleHTTPError(e.Message, e.Type);
		}
	}
	catch (EAbort&)	{
		__asm nop;
	}
	#include "YT_HTTP_end.h"
	this->StopProgress();
	this->Busy = 0;

	if (!result) {
		delete thumbs;
	}

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::YT_GetDownloadURL(UnicodeString ID,
	int Quality, __int64 &Size, int &Fmt)
{
	Size = -1;
	int YT_Formats[] = YT_FORMATS;
	UnicodeString strMap;

	try {
		//Get download token
		 strMap = this->YT_GetFmtMap(ID);
	}
	catch (UnicodeString msg) {
		try {
			return this->YT_GetDownloadURLAlt(ID, Quality, Size, Fmt);
		}
		catch (...) {
			throw msg;
		}
	}

	TStringList* map = YT_ParseFmtMap(strMap);

	UnicodeString url;
	while (Quality >= 0) {
		Fmt = YT_Formats[Quality];
		url = map->Values[IntToStr(Fmt)];
		if (url.IsEmpty()) {
			Quality--;
		}
		else {
			break;
		}
	}
	if (url.IsEmpty()) {
		Fmt = 0;
		url = map->Values["5"];
		if (url.IsEmpty()) {
			url = map->ValueFromIndex[0];
			Fmt = StrToInt(map->Names[0]);
		}
	}

	delete map;

	int redirects = 0;
	while (redirects <= this->HTTPClient->RedirectMaximum) {
		this->Head(url);

		if (this->IsRedirected(this->HTTPClient->ResponseCode)) {
			redirects++;
			this->HTTPClient->Request->UserAgent = this->UserAgent_YT;
			url = this->HTTPClient->Response->Location;
			continue;
		}

		UnicodeString ct = HTTPClient->Response->ContentType;
		if (StartsStr(L"video/", ct)) {
			break;
		}
		else {
			throw UnicodeString(L"Invalid content type: ") + ct;
		}
	}
	if (redirects >= YT_REDIRECT_MAXIMUM) {
		throw UnicodeString ("Too many redirects.");
	}

	Size = this->HTTPClient->Response->ContentLength;

	//Check size
	__int64 max = this->Session->Settings->Video->MaxFileSize;
	if(max > 0) {
		if (this->HTTPClient->Response->ContentLength > max)
		{
			throw UnicodeString(L"Clip data size is ")
			+ FormatDataSize(this->HTTPClient->Response->ContentLength) + L".\r\n"
			+ L"Max file size " + FormatDataSize(max) + L" exceeded.";
		}
	}

	return this->HTTPClient->URL->URI;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::YT_GetDownloadURLAlt(UnicodeString ID,
	int Quality, __int64 &Size, int &Fmt)
{
	Size = -1;
	int YT_Formats[] = YT_FORMATS;

	UnicodeString pageUrl = Format(YT_LINK, ARRAYOFCONST((ID)));

	TStringStream* ss = new TStringStream(L"", TEncoding::UTF8, true);
	this->Get(pageUrl, ss, true);

	UnicodeString Response = ss->DataString;
	delete ss;

	UnicodeString strMap = StrExtract(Response, L"\"fmt_url_map\": \"", L"\"", true);
	strMap = ReplaceStr(strMap, L"\\/", "/");
	if (strMap.IsEmpty()) {
		throw Exception(L"Format map mot found.");
	}
	TStringList* map = YT_ParseFmtMap(HTTPDecode(strMap));

	UnicodeString url;
	while (Quality >= 0) {
		Fmt = YT_Formats[Quality];
		url = map->Values[IntToStr(Fmt)];
		if (url.IsEmpty()) {
			Quality--;
		}
		else {
			break;
		}
	}
	if (url.IsEmpty()) {
		Fmt = 0;
		url = map->Values["5"];
		if (url.IsEmpty()) {
			url = map->ValueFromIndex[0];
			Fmt = StrToInt(map->Names[0]);
		}
	}

	delete map;

	int redirects = 0;
	while (redirects <= this->HTTPClient->RedirectMaximum) {
		this->Head(url);

		if (this->IsRedirected(this->HTTPClient->ResponseCode)) {
			redirects++;
			this->HTTPClient->Request->UserAgent = this->UserAgent_YT;
			url = this->HTTPClient->Response->Location;
			continue;
		}

		UnicodeString ct = HTTPClient->Response->ContentType;
		if (StartsStr(L"video/", ct)) {
			break;
		}
		else {
			throw UnicodeString(L"Invalid content type: ") + ct;
		}
	}
	if (redirects >= YT_REDIRECT_MAXIMUM) {
		throw UnicodeString ("Too many redirects.");
	}

	Size = this->HTTPClient->Response->ContentLength;

	//Check size
	__int64 max = this->Session->Settings->Video->MaxFileSize;
	if(max > 0) {
		if (this->HTTPClient->Response->ContentLength > max)
		{
			throw UnicodeString(L"Clip data size is ")
			+ FormatDataSize(this->HTTPClient->Response->ContentLength) + L".\r\n"
			+ L"Max file size " + FormatDataSize(max) + L" exceeded.";
		}
	}

	return this->HTTPClient->URL->URI;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::YT_GetDownloadToken(UnicodeString ID)
{
	UnicodeString token;
	AnsiString url = Format(YT_LINK_TOKEN, ARRAYOFCONST((ID)));
	UnicodeString Response = L"&" + this->Get(url, false);

	UnicodeString status = StrExtract(Response, L"&status=", L"&", false);
	if (status=="ok") {
		token = StrExtract(Response, L"&token=", L"&", false);
	}
	else if (status!=L"fail") {
		throw UnicodeString(L"Invalid YouTube status: ")
		+ (status.IsEmpty()? UnicodeString(L"(empty)") : status) + L".";
	}
	else {
		UnicodeString msg = HTTPDecode(
			StrExtract(Response, L"&reason=", L"&", false)
		);
		if (msg.IsEmpty()) {
			msg = "Unknown YouTube error.";
		}
		else {
			msg = HTMLDecode(StrExtract(msg, L"", "<", false));
		}
		throw msg;
	}
	return token;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::YT_GetFmtMap(UnicodeString ID)
{
	UnicodeString result;
	AnsiString url = Format(YT_LINK_TOKEN, ARRAYOFCONST((ID)));
	UnicodeString Response = L"&" + this->Get(url, false);

	UnicodeString status = StrExtract(Response, L"&status=", L"&", false);
	if (status=="ok") {
		result = StrExtract(Response, L"&fmt_url_map=", L"&", false);
	}
	else if (status!=L"fail") {
		throw UnicodeString(L"Invalid YouTube status: ")
		+ (status.IsEmpty()? UnicodeString(L"(empty)") : status) + L".";
	}
	else {
		int errorCode = StrToIntDef(StrExtract(Response, L"&errorcode=", L"&", false), -1);
		UnicodeString msg;

		if (errorCode==150) {
			msg = "This file can not be downloaded due to YouTube API restrictions.";
		}
		else {
			msg = HTTPDecode(StrExtract(Response, L"&reason=", L"&", false));
            if (msg.IsEmpty()) {
				msg = "Unknown YouTube error.";
			}
			else {
				msg = HTMLDecode(StrExtract(msg, L"", "<", false));
			}
		}
		throw msg;
	}
	return HTTPDecode(result);
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::YT_GetInfo(TMediaItem* MI, UnicodeString ID)
{
	try {
		this->YT_GetInfoNormal(MI, ID);
	}
	catch (UnicodeString msg) {
		try {
			this->YT_GetInfoAlt(MI, ID);
		}
		catch (...) {
			throw msg;  //Show the message from the normal methos
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::YT_GetInfoNormal(TMediaItem* MI, UnicodeString ID)
{
	UnicodeString url = Format(YT_LINK_INFO, ARRAYOFCONST((ID)));

	TStringStream* ss = new TStringStream(L"", TEncoding::UTF8, true);
	try {
		this->Get(url, ss, true);
	}
	catch (EIdHTTPProtocolException& e) {
		if (e.ErrorCode>0 && e.ErrorCode<1000) { //HTTP error
			UnicodeString msg = e.Message.IsEmpty()?
				UnicodeString("YouTube HTTP Error: " + IntToStr(e.ErrorCode))
				: e.Message;
			throw msg;
		}
		else {
			throw e; //rethrow socket and other errors
		}
	}

	UnicodeString Response = ss->DataString;
	delete ss;

	YT_ExtractInfoXML(MI, Response);
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::YT_GetInfoAlt(TMediaItem* MI, UnicodeString ID)
{
	UnicodeString url = Format(YT_LINK, ARRAYOFCONST((ID)));

	TStringStream* ss = new TStringStream(L"", TEncoding::UTF8, true);
	this->Get(url, ss, true);

	UnicodeString Response = ss->DataString;
	delete ss;

	YT_ExtractInfoHTML(MI, Response);
}
//---------------------------------------------------------------------------

#endif //CUSTOM_YOUTUBE
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//HTTP method wrappers
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::Get(UnicodeString URL,
	bool HandleRedirects)
{
	this->HTTPSetup(L"\r\nGET " + URL + L"\r\n", HandleRedirects);
	this->HTTPClient->Request->ContentType = L"";

	UnicodeString result = L"";

	TIdHTTP* http = this->HTTPClient;
	#include "HTTP_begin.h"
		result = http->Get(URL);
	#include "HTTP_end.h"
	return result;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::Get(UnicodeString URL, TStream* Stream,
	bool HandleRedirects)
{
	this->HTTPSetup(L"\r\nGET " + URL + L"\r\n", HandleRedirects);
	this->HTTPClient->Request->ContentType = L"";

	TIdHTTP* http = this->HTTPClient;
	#include "HTTP_begin.h"
		http->Get(URL, Stream);
	#include "HTTP_end.h"
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::Head(UnicodeString URL)
{
	this->HTTPSetup(L"\r\nHEAD " + URL + L"\r\n", false);
	this->HTTPClient->Request->ContentType = L"";

	TIdHTTP* http = this->HTTPClient;
	#include "HTTP_begin.h"
		http->Head(URL);
	#include "HTTP_end.h"
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::Post(UnicodeString URL,
	TStringList* PostData, bool HandleRedirects)
{
	this->HTTPSetup(L"\r\nPOST " + URL + L"\r\n", HandleRedirects);

	UnicodeString result = L"";

	TIdHTTP* http = this->HTTPClient;
	#include "HTTP_begin.h"
		result = http->Post(URL, PostData);
	#include "HTTP_end.h"
	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::Post(UnicodeString URL,
	TIdMultiPartFormDataStream* PostData, bool HandleRedirects)
{
	this->HTTPSetup(L"\r\nPOST " + URL + L"\r\n", HandleRedirects);

	UnicodeString result = L"";

	TIdHTTP* http = this->HTTPClient;
	#include "HTTP_begin.h"
		result = http->Post(URL, PostData);
	#include "HTTP_end.h"
	return result;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::Post(UnicodeString URL,
	TIdMultiPartFormDataStream* PostData, TStream* Response, bool HandleRedirects)
{
	this->HTTPSetup(L"\r\nPOST " + URL + L"\r\n", HandleRedirects);

	TIdHTTP* http = this->HTTPClient;
	#include "HTTP_begin.h"
		http->Post(URL, PostData, Response);
	#include "HTTP_end.h"
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Execution control methods
//---------------------------------------------------------------------------
void __fastcall TSrvAdapterModule::Terminate()
{
	this->Terminated = true;
	if (this->Busy == 1) {
		this->Disconnect();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::Disconnect()
{
	this->HTTPClient->DisconnectNotifyPeer();
	this->HTTPClient->IOHandler->InputBuffer->Clear();
	this->HTTPClient->IOHandler->Close();
	this->HTTPClient->Disconnect();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Helpers
//---------------------------------------------------------------------------
void __fastcall TSrvAdapterModule::HandleHTTPError(UnicodeString Msg,
	TCommunicationErrorType Type)
{
	if (!Msg.IsEmpty()) {
		UnicodeString msg, title;
		switch (Type) {
		case cetHTTP:
			msg = L"Command \"" + this->HTTPClient->Request->Method + " "
			+ this->HTTPClient->Request->URL \
			+ L" failed with error:\r\n" + Msg + "\r\n\r\n"
			+ L"Please contact site administrator.";
			title = L"Communication Error";
			break;
		case cetTCP:
			msg = Msg + "\r\n\r\n"
			+ L"Please verify your Internet connection.";
			title = L"Internet Connection Error";
			break;
		default: //cetOS
            msg = Msg;
			title = L"Operating System Error";
		}

		Framework->ShowErrorMessage(msg, title);
	}
	this->StopProgress();

	this->HTTPClient->DisconnectNotifyPeer();
	this->HTTPClient->IOHandler->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPSetup(UnicodeString Cmd,
	bool HandleRedirects)
{
	this->HTTPClient->HandleRedirects = HandleRedirects;
	this->HTTPClient->Compressor = NULL;
	this->Terminated = false;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::IsRedirected(int StatusCode)
{
	return (StatusCode >= 300 && StatusCode <= 303) || StatusCode == 307;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::IsAuthFailed(int StatusCode)
{
	return StatusCode == 401 || StatusCode == 407;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Hash methods similar to php functions
//---------------------------------------------------------------------------
AnsiString __fastcall TSrvAdapterModule::sha1(UnicodeString Val)
{
	TIdHashSHA1* coderSHA1 = new TIdHashSHA1;

	AnsiString result = coderSHA1->HashStringAsHex(Val).LowerCase();

	delete coderSHA1;
	return result;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TSrvAdapterModule::sha1(TStream* Stream, __int64 StartPos,
	__int64 Size)
{
	TIdHashSHA1* coderSHA1 = new TIdHashSHA1;

	if (Size==0) Size = Stream->Size - StartPos;
	AnsiString result =  coderSHA1->HashStreamAsHex(Stream, StartPos, Size).LowerCase();

	delete coderSHA1;
	return result;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TSrvAdapterModule::md5(UnicodeString Val)
{
	TIdHashMessageDigest5* coderMD5 = new TIdHashMessageDigest5;

	AnsiString result = coderMD5->HashStringAsHex(Val).LowerCase();

	delete coderMD5;
	return result;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TSrvAdapterModule::md5(TStream* Stream, __int64 StartPos,
	__int64 Size)
{
	TIdHashMessageDigest5* coderMD5 = new TIdHashMessageDigest5;

	if (Size==0) Size = Stream->Size - StartPos;
	AnsiString result =  coderMD5->HashStreamAsHex(Stream, StartPos, Size).LowerCase();

	delete coderMD5;
	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Event handlers
//---------------------------------------------------------------------------
void __fastcall TSrvAdapterModule::HTTPClientWorkBegin(TObject *ASender,
	TWorkMode AWorkMode, __int64 AWorkCountMax)
{
	TProgressMeter* p = this->Progress;
	if (p && p->Mode!=pmmManual) {
		p->StartCounter(AWorkCountMax);
	}
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPClientWork(TObject *ASender,
	TWorkMode AWorkMode, __int64 AWorkCount)
{
	TProgressMeter* p = this->Progress;
	if (p && p->Mode!=pmmManual) {
		p->LastCount = AWorkCount;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPWorkEnd()
{
	TProgressMeter* p = this->Progress;
	if (p && p->Mode!=pmmManual) {
		p->LastCount = p->TotalCount;
		p->StopCounter();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPClientHeadersAvailable(TObject *Sender,
	TIdHeaderList *AHeaders, bool &VContinue)
{
	if (this->Terminated) {
		VContinue = false;
		return;
	}
	bool compress = false;
	UnicodeString method = HTTPClient->Request->Method;
	if (method == "GET" || method == "POST") {
		UnicodeString enc = AHeaders->Values[L"Content-Encoding"];
		if (!(enc.IsEmpty() || enc == "identity")) {
			compress = true;
		}
	}
	else if (method == "HEAD") {
		VContinue = false;
		this->Disconnect();
	}

	this->HTTPClient->Compressor = compress ? this->CompressorZLib : NULL;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPClientAuxHeadersAvailable(TObject *Sender,
	TIdHeaderList *AHeaders, bool &VContinue)
{
 	bool compress = false;
	UnicodeString method = HTTPClient->Request->Method;
	if (method == "GET" || method == "POST") {
		UnicodeString enc = AHeaders->Values[L"Content-Encoding"];
		if (!(enc.IsEmpty() || enc == "identity")) {
			compress = true;
		}
	}
	this->HTTPClientAux->Compressor = compress ? this->CompressorZLib : NULL;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::OnPingTimer(TObject *Sender)
{
	this->PingTimer->Enabled = false;
	if (this->Authorized) {
		this->Ping();
	}
	this->PingTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPClientAuthorization(TObject *Sender,
	TIdAuthentication *Authentication, bool &Handled)
{
	TIdHTTP* http = dynamic_cast<TIdHTTP*> (Sender);
	UnicodeString server = http->Request->Host;
	UnicodeString realm;

	if (AnsiString(typeid(*Authentication).name()) == "TIdDigestAuthentication") {
		TIdDigestAuthentication* auth =
			dynamic_cast<TIdDigestAuthentication*> (Authentication);
		realm = auth->Realm;
		auth->Uri = http->Request->URL;
		auth->Method = http->Request->Method;
	}
	else {
		realm = Authentication->Params->Values["realm"];
	}

	UnicodeString iniKey = realm + "@" + server + ".";

	UnicodeString username =
		Framework->IniFile->ReadString(L"HTTP Authentication",
			iniKey + "username", L"");
	UnicodeString password = this->DecryptPassword(
		Framework->IniFile->ReadString(L"HTTP Authentication",
		iniKey + "password", L""));

	if (!this->FHTTPAuthFailed && !password.IsEmpty()) {
		//Try stored credentials
		Authentication->Username = username;
		Authentication->Password = password;
		Handled = true;
		return;
	}

	THTTPAuthForm* dlg = new THTTPAuthForm(this, server, realm,
		username, password);

	bool oldActive = this->AntiFreeze->Active;
	this->AntiFreeze->Active = false;
	int res = dlg->ShowModal();
	this->AntiFreeze->Active = oldActive;

	if (res == mrOk) {
		username = dlg->Username;
		password = dlg->Password;

		Authentication->Username = username;
		Authentication->Password = password;
		Handled = true;

		Framework->IniFile->WriteString(L"HTTP Authentication",
			iniKey + "username", username);
		Framework->IniFile->WriteString(L"HTTP Authentication",
			iniKey + "password", this->EncryptPassword(password));
	}
	else {
		Handled = false;
		Abort();
	}

	delete dlg;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPClientProxyAuthorization(TObject *Sender,
	TIdAuthentication *Authentication, bool &Handled)
{
	TIdHTTP* http = dynamic_cast<TIdHTTP*> (Sender);

	UnicodeString server = http->ProxyParams->ProxyServer;
	UnicodeString port = UnicodeString(http->ProxyParams->ProxyPort);
	UnicodeString iniKey = server + ":" + port + ".";

	UnicodeString username =
		Framework->IniFile->ReadString(L"Proxy Authentication",
			iniKey + "username", L"");
	UnicodeString password = this->DecryptPassword(
		Framework->IniFile->ReadString(L"Proxy Authentication",
			iniKey + "password", L""));

	if (!this->FProxyAuthFailed && !password.IsEmpty()) {
		//Try stored credentials
		if (Authentication) {
			Authentication->Username = username;
			Authentication->Password = password;
		}
		http->ProxyParams->ProxyUsername = username;
		http->ProxyParams->ProxyPassword = password;

		Handled = true;
		return;
	}

	TProxyAuthForm* dlg = new TProxyAuthForm(this, server, port, username, password);

	bool oldActive = this->AntiFreeze->Active;
	this->AntiFreeze->Active = false;
	int res = dlg->ShowModal();
	this->AntiFreeze->Active = oldActive;

	if (res == mrOk) {
		username = dlg->Username;
		password = dlg->Password;

		if (Authentication) {
			Authentication->Username = username;
			Authentication->Password = password;
		}
		http->ProxyParams->ProxyUsername = username;
		http->ProxyParams->ProxyPassword = password;
		Handled = true;

		Framework->IniFile->WriteString(L"Proxy Authentication",
			iniKey + "username", username);
		Framework->IniFile->WriteString(L"Proxy Authentication",
			iniKey + "password", this->EncryptPassword(password));
	}
	else {
		Handled = false;
		this->Terminated = true;
		//this->Terminate();
	}

	delete dlg;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::HTTPClientConnected(TObject *Sender)
{
	TIdHTTP* http = dynamic_cast<TIdHTTP*> (Sender);
	TIdAuthentication* Authentication = http->Request->Authentication;

	if (Authentication
		&& AnsiString(typeid(*Authentication).name()) == "TIdDigestAuthentication"
		&& Authentication->CurrentStep==0)
	{
		TIdDigestAuthentication* auth =
			dynamic_cast<TIdDigestAuthentication*> (Authentication);
		auth->Uri = http->Request->URL;
		auth->Method = http->Request->Method;
		auth->Next();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Progress methods
//---------------------------------------------------------------------------
void __fastcall TSrvAdapterModule::StartProgress(UnicodeString SubOperation,
	float Min, float Max, TProgressMeterMode Mode)
{
	if (this->FProgress) delete this->FProgress;
	this->FProgress = new TProgressMeter(SubOperation, Min, Max, Mode);
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::StopProgress()
{
	delete this->FProgress;
	this->FProgress = NULL;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::FFmpegProgress(float Ratio)
{
	if (this->Progress) {
		if (Ratio >= 0.0) {
			this->Progress->SetRelative(Ratio);
		}
		Application->ProcessMessages();
		return !this->Terminated;
	}
	return true;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TProgressMeter
//---------------------------------------------------------------------------
__fastcall TProgressMeter::TProgressMeter(UnicodeString SubOperation,
	float Min, float Max, TProgressMeterMode Mode)
{
	this->FSubOperation = SubOperation;

	this->FMin = Min;
	this->FMax = Max;
	this->FGain = Max - Min;

	this->FMode = Mode;

	this->FExplicitValue = -1.0;

	this->FTotalCount = 0;
	this->FLastCount = -1;
}
//---------------------------------------------------------------------------

void __fastcall TProgressMeter::StartCounter(__int64 TotalCount)
{
	if (this->FMode == pmmManual)
		throw Exception("Attempt to start manual progress meter.");

	this->FTotalCount = TotalCount;
	this->FLastCount = 0;
}
//---------------------------------------------------------------------------

void __fastcall TProgressMeter::StopCounter()
{
	this->FMode = pmmManual;
}
//---------------------------------------------------------------------------

void __fastcall TProgressMeter::SetRelative(float RelativeValue)
{
	this->Value = this->Min + RelativeValue*this->FGain;
}
//---------------------------------------------------------------------------

float __fastcall TProgressMeter::getValue()
{
	if (this->FMode == pmmManual) {
		return this->FExplicitValue;
	}
	else if (this->FTotalCount <= 0) {
		return this->FMin;
	}

	return (this->FLastCount >= 0)?
		((float)(((long double) this->FLastCount)
			/ ((long double) this->FTotalCount)) * this->FGain) + this->FMin
		: this->FMin;
}
//---------------------------------------------------------------------------

void __fastcall TProgressMeter::setValue(float Val)
{
	switch (this->FMode) {
	case pmmAuxiliary:
	case pmmMain:
		throw Exception(L"Attempt to set progress value in automatic mode.");
	default:
		this->FExplicitValue = Val;
	}
}
//---------------------------------------------------------------------------

void __fastcall TProgressMeter::setLastCount(__int64 Val)
{
	if (this->FMode == pmmManual)
		throw Exception("Attempt to set count for manual progress meter.");

	this->FLastCount = Val;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Media conversion methods
//---------------------------------------------------------------------------
bool __fastcall TSrvAdapterModule::PrepareMedia(TMediaItem* MI)
{
    TSrvSettings* s = this->Session->Settings;
	TSrvMediaSettings* media = s->Media[MI->MediaType];
	if (!media) {
		Framework->ShowErrorMessage(L"Invalid media type.");
		return false;
	}

	TSrvMediaFormat* vf = NULL;
	if (!MI->External) {
		UnicodeString ext = GetFileExt(MI->InputData->FileName);
		if (ext.IsEmpty()) {
			Framework->ShowErrorMessage(L"Sorry, files without extension are not allowed.");
			return false;
		}
		if (media->AllowExts->IndexOf(ext) < 0) {
			Framework->ShowErrorMessage(L"Sorry, files with the extension \""
				+ ext + L"\" are not allowed.");
			return false;
		}
		if (MI->NativeFormat) {
        	MI->FileExt = ext;
		}
	}

	if (!MI->External && !media->AllNative) {
		int index = media->Formats->IndexOf(MI->UploadFormat);
		if (index < 0) {
			Framework->ShowErrorMessage(UnicodeString(L"Media format ")
				+ (MI->UploadFormat.IsEmpty()?
					UnicodeString(L"(empty)")
					: UnicodeString("\"") + MI->UploadFormat + "\"")
				+ L" is not allowed.", MI->Label);
			return false;
		}
		vf = (TSrvMediaFormat*)media->Formats->Objects[index];
	}

	TFileStream* upload = MI->GetUploadData();
	__int64 max_filesize = media->MaxFileSize;
	if (upload && max_filesize>0 && upload->Size > max_filesize) {
		Framework->ShowErrorMessage(L"Max file size exeeded.", MI->Label);
		return false;
	}

	return
		(MI->MediaType == mtVideo)? this->PrepareVideo(MI, vf) :
		(MI->MediaType == mtAudio)? this->PrepareAudio(MI, vf) :
		(MI->MediaType == mtImage)? this->PrepareImage(MI) :
		false;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::PrepareVideo(TMediaItem* MI,
	TSrvMediaFormat* Format)
{
	//Check if already converted
	bool need_transcode 	= !MI->IsReady(miwtTranscode);
	bool need_metadata		= !MI->IsReady(miwtMetadata);
	bool need_thumbs 		= !MI->IsReady(miwtThumbs);
	if (!(need_metadata || need_transcode || need_thumbs)) return true;

	TSrvSettings* s = this->Session->Settings;
	TSrvVideoSettings* media = s->Video;

	//Resizing conditions:
	bool no_resizing = MI->External || MI->NativeFormat
		|| media->ResizeType == srrtNoResize;
	bool keep_aspect = MI->NativeFormat
		|| media->ResizeType == srrtKeepAspectRatio
		|| media->ResizeType == srrtNoResize;

	TMetadata* meta = NULL;
	if (need_transcode || need_metadata) {
		delete MI->Metadata; MI->Metadata = NULL;
		meta = new TMetadata;
	}

	TFFmpegConsole* fc = NULL;
	TThumbs* thumbs = NULL;

	bool result = false;
	try {
		fc = new TFFmpegConsole(MI->InputData->FileName, mtVideo,
			s->ExternalProcessPriority);

		float video_progress = 1.00 -
			(PROGRESS_GENERATE_THUMB *
			((float)media->ThumbCount + (float)media->ThumbCountBig));

		this->Busy = 2;
		this->Terminated = false;

		if (need_transcode) {
			short postprocess = 0;
			if (MI->UploadFormat == L"mp4") {
				postprocess = 1; //mp4stream
				video_progress -= PROGRESS_POSTPROCESS_MP4;
			}
			else if (MI->UploadFormat  == L"flv") {
				postprocess = 2; //flv metadata
				video_progress -= PROGRESS_POSTPROCESS_FLV;
			}

			this->StartProgress(L"", 0.00, video_progress);

			//Prepare FFmpeg options
			UnicodeString outfile = Framework->GetNewTempFile();

			//Transcode
			if (!media->WatermarkEnabled && (MI->NativeFormat || MI->External)) {

				//Just copy
				if (!this->CopyFile(MI->InputData, outfile)) Abort();
				meta->Resolution = new TResolution(fc->MediaInfo->Video_Width,
					fc->MediaInfo->Video_Height);
			}
			else {
				UnicodeString video_opts, input_opts;
				bool pass2 = MI->Pass2 == 1;
				if (!MI->External) {
					video_opts = Format->FFmpegOptions;
					if (MI->Deinterlace == 1) video_opts += L" -deinterlace";

					UnicodeString resize_opts = fc->GetResizeOptions(
						no_resizing? NULL: media->Resolution, keep_aspect,
						"",
						media->WatermarkEnabled? FFMPEG_WATERMARK_REQUIRE_FILTER_PAD : FFMPEG_REQUIRE_FILTER_PAD);
					UnicodeString resolution = StrExtract(resize_opts, L"-s ", L" ", false);
					meta->Resolution = resolution.IsEmpty()?
						new TResolution(fc->MediaInfo->Video_Width,
						fc->MediaInfo->Video_Height)
						: new TResolution(resolution);
					video_opts += L" " + resize_opts;
					fc->SetOutputRates(video_opts);
				}
				else {
					video_opts = "-f " + MI->UploadFormat + " -sameq";
					input_opts = "-f " + MI->UploadFormat;
                }

				UnicodeString wmOpts;
				if (media->WatermarkEnabled) {
					wmOpts = fc->GetWatermarkOptions(no_resizing? NULL: media->Resolution,
					this->FWatermark->FileName, media->WatermarkPosition,
					media->WatermarkOffsetX, media->WatermarkOffsetY);
				}

				#ifdef DEMO_VIDEO_DURATION_LIMIT
				if (fc->MediaInfo->Duration > DEMO_VIDEO_DURATION_LIMIT) {
					fc->MediaInfo->Duration = DEMO_VIDEO_DURATION_LIMIT;
					video_opts += L" -t " + IntToStr(DEMO_VIDEO_DURATION_LIMIT);
				}
				#endif

				//Transcode
				fc->Transcode(outfile, input_opts, video_opts,
					media->MaxFileSize,
					MI->External? UnicodeString("") : pass2? Format->PresetPass1 : Format->Preset,
						MI->External? UnicodeString("") : Format->PresetPass2, pass2,
					wmOpts);
				if (this->Terminated) Abort();
			}

			//Hash
			if (!MI->External) {
				TFileStream* fs = new TFileStream(outfile, OPENMODE_INPUTFILE);
				MI->MediaMD5 = this->HashMedia(fs);
				delete fs;
			}

			//Post process
			if (postprocess) {
				try {
                	if (postprocess == 1) {
						this->StartProgress(L"Preparing metadata",
							video_progress, video_progress+=PROGRESS_POSTPROCESS_MP4
						);
						fc->PostProcessMP4(outfile);
					}
					else if (postprocess == 2) {
						this->StartProgress(L"Preparing metadata",
							video_progress, video_progress+=PROGRESS_POSTPROCESS_FLV
						);
						UnicodeString newfile = fc->PostProcessFLV(outfile);
						DeleteFile(outfile);
						outfile = newfile;
					}

					if (this->Terminated) {
						DeleteFile(outfile);
						Abort();
					}
				}
				catch (EMediaProcessingError& e) {
					if (s->ErrorHandling->Values[L"PostProcessing"] == L"warning") {
                        //this->StopProgress();

						if (Framework->ShowMessageBox(
							L"Video \'" + MI->Label
							+ L"\' may not stream properly through web players.\n\n"
							+ L"Continue upload?",
							L"Postprocessing Error",
							MB_ICONWARNING|MB_OKCANCEL|MB_DEFBUTTON2)!=IDOK)
						{
							DeleteFile(outfile);
							Abort();
						}
					}
					else {
						DeleteFile(outfile);
						throw EMediaProcessingError(e);
					}
				}
			}
			MI->UploadData = new TFileStream(outfile, OPENMODE_INPUTFILE);

			if (Format) {
				MI->InternetMediaType = Format->InternetMediaType;
				if (MI->NativeFormat
					&& GetFileExt(MI->InputData->FileName)=="mkv"
					&& media->MkvAsDivx)
				{   //Exception for MkvAsDivx:
					MI->FileExt = "mkv";
				}
				else {
					MI->FileExt = Format->FileExt;
				}
			}
		}
		//Set metadata
		if (meta) {
			meta->Duration = fc->MediaInfo->Duration;
			meta->Resolution = new TResolution(fc->MediaInfo->Video_Width,
				fc->MediaInfo->Video_Height);
			meta->AspectRatio_String = fc->MediaInfo->Video_DisplayAspectRatio_String;

			MI->Metadata = meta; meta = NULL;
		}

		//Generate thumbs
		if (need_thumbs) {
			this->StartProgress(L"Generating thumbnails", video_progress, 1.0);

			long double duration;
			TFFmpegConsole* outFC = NULL;

			if (!MI->UploadInput) {
				//Open output file for more correct duration
				// and fallback thumbnail generation
				outFC = new TFFmpegConsole(MI->UploadData->FileName,
					mtVideo,
					this->Session->Settings->ExternalProcessPriority);

				//Output file duration is morel ikely to be correct:
				duration = outFC->MediaInfo->Duration;
			} else {
				duration = fc->MediaInfo->Duration;
            }

			// Thumbnails
			thumbs = new TThumbs;
			UnicodeString thumbOpts;

			//Small thumbs
			thumbOpts = fc->GetResizeOptions(media->ThumbResolution,
				keep_aspect && media->ThumbPadding, CFG_PADCOLOR_THUMBS);
			this->MakeThumbnailList(false, thumbs->List, thumbOpts, media->ThumbCount,
				duration, fc, outFC);

			//Big thumbs
			thumbOpts = fc->GetResizeOptions(no_resizing
				? NULL
				: media->BigThumbResolution, keep_aspect);
			this->MakeThumbnailList(true, thumbs->BigList, thumbOpts,
				media->ThumbCountBig, duration, fc, outFC);

			delete outFC;

			MI->Thumbs = thumbs; thumbs = NULL;

			this->Progress->Value = 1.00;
		}

		result = true;

		#ifdef _DEBUG
		//Test
//		TFileStream* fs;
//		UnicodeString path = ExtractFilePath(Application->ExeName);
//
//		TFileStream* upload = MI->GetUploadData();
//		if (upload) {
//			fs = new TFileStream(path + "test_video." + MI->FileExt, fmCreate);
//			upload->Position = 0;
//			fs->CopyFrom(upload, upload->Size);
//			delete fs;
//		}
//
//		for (int i = 0; i < CFG_THUMBNAILCOUNT; i++) {
//			fs = new TFileStream(path + L"test_thumb_" + UnicodeString(i+1) + ".jpg", fmCreate);
//			MI->Thumbs->Items[i]->Position = 0;
//			fs->CopyFrom(MI->Thumbs->Items[i], MI->Thumbs->Items[i]->Size);
//			delete fs;
//		}
//
//		fs = new TFileStream(path + "test_thumb_big.jpg", fmCreate);
//		MI->Thumbs->Big->Position = 0;
//		fs->CopyFrom(MI->Thumbs->Big, MI->Thumbs->Big->Size);
//		delete fs;
		#endif

	}
	catch (EMediaProcessingError& e) {
		this->StopProgress();
		delete thumbs;
		delete meta;

		Framework->ShowErrorMessage((e.FailedOperation.IsEmpty()?
			UnicodeString(L"Video conversion failed") : e.FailedOperation) + L":\n"
			+ e.Message,
			MI->Label);
	}
	catch (UnicodeString msg) {
		this->StopProgress();
		delete thumbs;
		delete meta;

		Framework->ShowErrorMessage(msg, MI->Label);
	}
	catch (EFrameworkError& e) {
		this->StopProgress();
		delete thumbs;
		delete meta;

		Framework->ShowErrorMessage(e.Message, MI->Label);
	}
	catch (EAbort& e) {
		this->StopProgress();
		delete thumbs;
		delete meta;
	}
	this->StopProgress();
	this->Busy = 0;

	delete fc;

	return result;
 }
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::MakeThumbnailList(bool Big, TList* List,
	UnicodeString Options, int Count, long double Duration,
	TFFmpegConsole* FC, TFFmpegConsole* FallbackFC)
{
	for (int i = 0; i < Count; i++) {
		TFileStream* fs = NULL;
		try {
			try {
				this->MakeThumbnail(fs, FC, Options, Duration);
			}
			catch (EMediaProcessingErrorRecoverable& e) {
				if (FallbackFC) {
					this->MakeThumbnail(fs, FallbackFC, Options);
				} else {
					throw new EMediaProcessingErrorRecoverable(e);
				}
			}
		} catch (EMediaProcessingErrorRecoverable& e) {
			if (List->Count > 0) {
				fs = this->MakeThumbnailCopy(
					(TFileStream*)List->Items[List->Count-1]);
			} else {
				fs = this->MakeDefaultThumbnail(Big);
            }
		}
		if (fs) {
			List->Add((void*)fs);
		}
		this->Progress->Value += PROGRESS_GENERATE_THUMB;
	}
}
//---------------------------------------------------------------------------

long double __fastcall GenerateThumbPosition(long double Duration)
{
	return (Random()*(1.0-(THUMB_TIME_OFFSET*2.0)) + THUMB_TIME_OFFSET) * Duration;
}
//---------------------------------------------------------------------------

void __fastcall TSrvAdapterModule::MakeThumbnail(TFileStream* &Data,
	TFFmpegConsole* FC, UnicodeString Options, long double Duration)
{
	if (Duration <= 0) Duration = FC->MediaInfo->Duration;

	UnicodeString tmp = Framework->GetNewTempFile();
	FC->MakeThumbnail(tmp, GenerateThumbPosition(Duration), Options);
	if (this->Terminated) Abort();
	Data = new TFileStream(tmp, OPENMODE_TMPFILE);
}
//---------------------------------------------------------------------------

TFileStream* __fastcall TSrvAdapterModule::MakeThumbnailCopy(TFileStream* Source)
{
	UnicodeString tmp = Framework->GetNewTempFile();
	TFileStream* result = new TFileStream(tmp, OPENMODE_TMPFILE);
	Source->Position = 0;
	result->CopyFrom(Source, Source->Size);
	Source->Position = 0;

	return result;
}
//---------------------------------------------------------------------------

TFileStream* __fastcall TSrvAdapterModule::MakeDefaultThumbnail(bool Big)
{
	UnicodeString tmp = Framework->GetNewTempFile();
	TFileStream* result = new TFileStream(tmp, OPENMODE_TMPFILE);

	Framework->ExtractResourceToStream(
		Big? "DefaultThumbBig" : "DefaultThumb",
		result);

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::PrepareAudio(TMediaItem* MI,
	TSrvMediaFormat* Format)
 {
	//Check if already converted
	bool need_transcode 	= !MI->IsReady(miwtTranscode);
	bool need_metadata		= !MI->IsReady(miwtMetadata);
	if (!(need_metadata || need_transcode)) return true;

	TSrvSettings* s = this->Session->Settings;
	TSrvAudioSettings* media = s->Audio;

	TMetadata* meta = NULL;
	if (need_metadata) {
		delete MI->Metadata; MI->Metadata = NULL;
		meta = new TMetadata;
	}

	TFFmpegConsole* fc = NULL;

	bool result = false;
	try {
		fc = new TFFmpegConsole(MI->InputData->FileName, mtAudio,
			this->Session->Settings->ExternalProcessPriority);

		float audio_progress = 1.00;

		this->Busy = 2;
		this->Terminated = false;

		this->StartProgress(L"", 0.00, audio_progress);

		if (need_transcode) {
			UnicodeString outfile = Framework->GetNewTempFile();
			UnicodeString opts = Format->FFmpegOptions;
			fc->SetOutputRates(opts);
			//Transcode
			fc->Transcode(outfile, L"", opts,
				media->MaxFileSize);
			if (this->Terminated) Abort();

			MI->UploadData = new TFileStream(outfile, OPENMODE_TMPFILE);
		}

		if (Format) {
			MI->InternetMediaType = Format->InternetMediaType;
			MI->FileExt = Format->FileExt;
		}

		//Set metadata
		if (meta) {
			MI->MediaMD5 = this->HashMedia(MI->GetUploadData());

			meta->Duration = fc->MediaInfo->Duration;

			MI->Metadata = meta; meta = NULL;
		}

		this->Progress->Value = 1.00;
		result = true;
	}
	catch (EMediaProcessingError& e) {
		this->StopProgress();
		delete meta;

		Framework->ShowErrorMessage((e.FailedOperation.IsEmpty()?
			UnicodeString(L"Audio conversion failed") : e.FailedOperation) + L":\n"
			+ e.Message,
			MI->Label);
	}
	catch (UnicodeString msg) {
		this->StopProgress();
		delete meta;

		Framework->ShowErrorMessage(msg, MI->Label);
	}
	catch (EFrameworkError& e) {
		this->StopProgress();
		delete meta;

		Framework->ShowErrorMessage(e.Message, MI->Label);
	}
	catch (EAbort& e) {
		this->StopProgress();
		delete meta;
	}
	this->StopProgress();
	this->Busy = 0;

	delete fc;

	return result;
 }
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::PrepareImage(TMediaItem* MI)
 {
	//Check if already prepared
	bool need_metadata		= !MI->IsReady(miwtMetadata);
	if (!need_metadata) return true;

	MI->MediaMD5 = this->HashMedia(MI->GetUploadData());
	MI->FileExt = GetFileExt(MI->InputData->FileName);
	MI->InternetMediaType = L"image/" + MI->FileExt;

	MI->Metadata = new TMetadata;

	return true;
 }
//---------------------------------------------------------------------------

 bool __fastcall TSrvAdapterModule::CopyFile(TFileStream* Source,
	UnicodeString TargetFileName)
 {
	TFileStream* target = NULL;

	bool result = false;
	try {
		target = new TFileStream(TargetFileName, fmCreate);
		__int64 cnt = 0;
		__int64 max = Source->Size;
		Source->Position = 0;

		__int64 dod;
		do {
			dod = COPY_FILE_BUFFER; // Block size
			if (cnt+dod > max) {
				dod = max-cnt;
			}
			if (dod > 0) {
				__int64 did = target->CopyFrom(Source, dod);
				cnt = cnt+did;

				this->FFmpegProgress((double)cnt / (double)max);
				if (this->Terminated) {
					Abort();
				}
			}
		} while (dod > 0);

		result = true;
	}
	catch (EFOpenError &e) {
		delete target; target = NULL;
		DeleteFile(TargetFileName);
		throw UnicodeString(e.Message);
	}
	catch (EStreamError &e) {
		delete target; target = NULL;
		DeleteFile(TargetFileName);
		throw UnicodeString(e.Message);
	}
	catch (EAbort&) {
		delete target; target = NULL;
		DeleteFile(TargetFileName);
	}
	delete target;

	return result;
 }
 //---------------------------------------------------------------------------

 AnsiString __fastcall TSrvAdapterModule::HashMedia(TStream* Stream)
 {
	if (!Stream) return "";

	Stream->Position = 0;

	AnsiString result = this->md5(Stream, 0, Min(Stream->Size, (__int64)MAX_HASHING_SIZE));
	Stream->Position = 0;

	return result;
 }
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// MIME methods
//---------------------------------------------------------------------------
AnsiString __fastcall TSrvAdapterModule::base64_encode(TStream* Source)
{
	TStringStream* ss = new TStringStream("", TEncoding::ASCII, true);
	this->encoderBase64->Encode(Source, ss);
	AnsiString result = ss->DataString;
	delete ss;

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::base64_decode(AnsiString Source, TStream* Dest)
{
	TStringStream* ss = new TStringStream(Source, TEncoding::ASCII, true);
	TMemoryStream* out = new TMemoryStream;

	try {
    	this->decoderBase64->DecodeBegin(out);
		this->decoderBase64->Decode(ss, -1);
		this->decoderBase64->DecodeEnd();
	} catch (...) {
		delete out;
		return false;
	}

	out->Position = 0;
	Dest->CopyFrom(out, 0);

	delete ss;
	delete out;

	return true;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Security functions:
//---------------------------------------------------------------------------
AnsiString __fastcall TSrvAdapterModule::GetUserAgent()
{
	AnsiString guid = md5(sha1(md5(md5(CUSTOM_GUID))));
	#ifdef CUSTOM_SALT
		guid += md5(CUSTOM_SALT);
	#endif

	return AnsiString(CUSTOM_USERAGENT) + "/"
		+ PRODUCT_VERSION_STRICT
		+ " (" + guid + ")";
}
//---------------------------------------------------------------------------

#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
AnsiString __fastcall TSrvAdapterModule::GetExecutableSHA1()
{
	TFileStream* fs = new TFileStream(Application->ExeName,
		fmOpenRead|fmShareDenyWrite);
	AnsiString result = sha1(fs);
	delete fs;

	return result;
}
#endif
//---------------------------------------------------------------------------

#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
AnsiString __fastcall TSrvAdapterModule::GetVersionSHA1()
{
	return sha1(UnicodeString(CUSTOM_PRODUCT_NAME) + " " + PRODUCT_VERSION_STRICT);
}
#endif
//---------------------------------------------------------------------------

AnsiString __fastcall TSrvAdapterModule::Encrypt(UnicodeString Text)
{
    TRSA* rsa = this->Session->RSA;
	//Convert to UTF-8 stream
	TStringStream* message = new TStringStream(Text, TEncoding::UTF8, true);
	//Prepare signature & pack streams
	TMemoryStream* signature = new TMemoryStream;
	TMemoryStream* pack = new TMemoryStream;
	try {
		rsa->Sign(message, signature);
		rsa->JoinMessage(message, signature, pack);
		rsa->Encrypt(pack);
	}
	catch (ERSAError& e) {
		Framework->ShowErrorMessage((e.FailedOperation.IsEmpty()?
			UnicodeString(L"Encryption failed") : e.FailedOperation) + L":\n"
			+ e.Message,
			"Cryptography Error");

		delete message;
		delete signature;
		delete pack;

		throw new ERSAError(e);
	}

	pack->Position = 0;
	AnsiString result = this->base64_encode(pack);

	delete message;
	delete signature;
	delete pack;

	return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TSrvAdapterModule::Decrypt(AnsiString Text, bool Login)
{
	TRSA* rsa = this->Session->RSA;
	//Prepare streams
	TMemoryStream* pack = new TMemoryStream;
	TStringStream* message = new TStringStream(L"", TEncoding::UTF8, true);
	TMemoryStream* signature = new TMemoryStream;

	UnicodeString result;
	try {
		//Base64 decode
		if (!this->base64_decode(Text, pack)) {
            throw ERSAException(LoadStr(LANG_INVALID_SERVER_RESPONSE));
		}
		pack->Position = 0;

		rsa->Decrypt(pack);
		rsa->SplitMessage(message, signature, pack);
		result = message->DataString;

		bool needVerification = true;
		if (Login) {
			TSrvResponse* info = NULL;
			try {
				info = new TSrvResponse(result);

				if (info->StatusCode != 0) {
					needVerification = false;
				}
				else {
					//Read server sign key
					AnsiString signKey = info->ReadString(TSrvResponseValID(L"SignKey"), L"");
					if (signKey.IsEmpty()) {
						throw ERSAException(L"Signature key not found.");
					}
					TMemoryStream* ms = new TMemoryStream;
					if (!this->base64_decode(signKey, ms)) {
                    	throw ERSAError("Invalid key");
					}
					ms->Position = 0;
					this->FSession->RSA->ImportServerSignKey(ms);
					delete ms;
				}
        	}
			catch (ESrvResponseError& e) {
				needVerification = false;
			}
			delete info;
		}

		if (needVerification) {
			rsa->Verify(message, signature);
		}
	}
	catch (ERSAError& e) {
		Framework->ShowErrorMessage((e.FailedOperation.IsEmpty()?
			UnicodeString(L"Decryption failed") : e.FailedOperation) + L":\n"
			+ e.Message,
			"Cryptography Error");

		delete message;
		delete signature;
		delete pack;

		throw new ERSAError(e);
	}
	catch (ERSAException& e) {
		Framework->ShowErrorMessage(e.Message, "Communication Security Violation");

		delete message;
		delete signature;
		delete pack;

		throw new ERSAException(e);
	}

	delete message;
	delete signature;
	delete pack;

	return result;
}
//---------------------------------------------------------------------------

bool __fastcall TSrvAdapterModule::WriteXMLData(TXMLMessage* Msg,
	TIdMultiPartFormDataStream* PostData)
{
	UnicodeString xml = Msg->ToString();

	#ifdef _DEBUG
		MessageBoxW(NULL, FormatXMLData(xml).c_str(),
			L"XML Request:", 0);
	#endif

	AnsiString encoded;
	try {
		 encoded = this->Encrypt(xml);
	}
	catch (ERSAError& e) {
		return false;
	}

	PostData->AddFormField(L"xml_data", encoded);

	return true;
}
//---------------------------------------------------------------------------

void _fastcall TSrvAdapterModule::MaskPassword(AnsiString &text)
{
	AnsiString mask = sha1(CUSTOM_SALT);

	int len = text.Length();
	int maskLen = mask.Length();
	for (int i = 0; i < len; i++) {
		text[i+1] ^= mask[(i%maskLen) + 1];
	}
}
//---------------------------------------------------------------------------

AnsiString __fastcall TSrvAdapterModule::EncryptPassword(UnicodeString Text)
{
    if (Text.IsEmpty()) {
		return "";
	}

	TStringStream* ss = new TStringStream(Text);
	AnsiString buf = this->base64_encode(ss);
	delete ss;

	this->MaskPassword(buf);

	ss = new TStringStream(buf);
	buf = this->base64_encode(ss);
	delete ss;

	return buf;
}

//---------------------------------------------------------------------------
UnicodeString __fastcall TSrvAdapterModule::DecryptPassword(AnsiString Text)
{
	if (Text.IsEmpty()) {
		return L"";
	}

	TStringStream* ss = new TStringStream;
	if (!this->base64_decode(Text, ss)) {
		delete ss;
		return Text;
	}
	AnsiString buf = ss->DataString;
	ss->Clear();

	this->MaskPassword(buf);

	if (!this->base64_decode(buf, ss)) {
		delete ss;
		return Text;
	}

	UnicodeString result = ss->DataString;
	delete ss;

	return result;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//TSession
//---------------------------------------------------------------------------
__fastcall TSrvSession::TSrvSession()
{
	this->FSettings = NULL;
	this->FRSA = new TRSA;
}
//---------------------------------------------------------------------------

__fastcall TSrvSession::~TSrvSession()
{
	delete this->FSettings;
	delete this->FRSA;
}
//---------------------------------------------------------------------------

void __fastcall TSrvSession::Start(TSrvSettings* Settings)
{
	this->FSettings = Settings;
}
//---------------------------------------------------------------------------



