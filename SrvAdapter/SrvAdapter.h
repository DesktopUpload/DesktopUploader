/*---------------------------------------------------------------------------
$Id: SrvAdapter.h 524 2011-02-09 16:11:09Z anton $
---------------------------------------------------------------------------*/
#ifndef SrvAdapterH
#define SrvAdapterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdCompressorZLib.hpp>
#include <IdZLibCompressorBase.hpp>
#include <IdZLib.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <IdIntercept.hpp>
#include <IdLogBase.hpp>
#include <IdLogFile.hpp>
#include <IdLogDebug.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
//---------------------------------------------------------------------------
#include <IdHashSHA1.hpp>
#include <IdCoderMIME.hpp>
#include <IdHashMessageDigest.hpp>
#include <IdCookieManager.hpp>
//---------------------------------------------------------------------------
#include "Config.h"
#include "MediaItem.h"
#include "YouTube.h"
#include "SrvInfo.h"
#include "XMLMsg.h"
#include "RSA.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define SRVADAPTER_OK 					0
#define SRVADAPTER_ERROR_TERMINATED 	-1
#define SRVADAPTER_ERROR_HTTP 			-2
#define SRVADAPTER_ERROR_PARSE 			-3
#define SRVADAPTER_ERROR_MAXCOUNT 		-4
#define SRVADAPTER_ERROR_CRYPT			-5

#define PROGRESSMETER_MODE_HTTP			1

#define OPENMODE_INPUTFILE 			fmOpenRead|fmShareDenyWrite
#define OPENMODE_TMPFILE 			fmOpenReadWrite|fmShareExclusive
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TProgressMeter
//---------------------------------------------------------------------------
enum TProgressMeterMode {pmmManual=0, pmmAuxiliary=1, pmmMain=2};

class TProgressMeter
{
public:
	__fastcall TProgressMeter(UnicodeString SubOperation=L"", float Min=0.00, float Max=1.00,
		TProgressMeterMode Mode=pmmManual);

	__property UnicodeString SubOperation = {read=FSubOperation, write=FSubOperation};
	__property float Min = {read=FMin};
	__property float Max = {read=FMax};
	__property float Gain = {read=FGain};
	__property TProgressMeterMode Mode = {read=FMode};

	__property __int64 TotalCount = {read=FTotalCount};
	__property __int64 LastCount = {read=FLastCount, write=setLastCount};

	__property float Value = {read=getValue, write=setValue};

	void __fastcall StartCounter(__int64 TotalCount);
	void __fastcall StopCounter();
	void __fastcall SetRelative(float RelativeValue);

protected:
	float __fastcall getValue();
	void __fastcall setValue(float Val);
	void __fastcall setLastCount(__int64 Val);

	UnicodeString FSubOperation;
	float FMin, FMax, FGain, FExplicitValue;
	TProgressMeterMode FMode;

	__int64 FTotalCount, FLastCount;
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSrvSession
//---------------------------------------------------------------------------
class TSrvSession
{
public:
	__fastcall TSrvSession();
	__fastcall ~TSrvSession();

	__property TSrvSettings* Settings = {read=FSettings};
	__property TRSA* RSA = {read=FRSA};

	void __fastcall Start(TSrvSettings* Settings);

protected:
	TSrvSettings* FSettings;
	TRSA* FRSA;
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// ECommunicationError
//---------------------------------------------------------------------------
enum TCommunicationErrorType {cetNoError=-1, cetHTTP=0, cetTCP=1, cetOS=2};
class ECommunicationError: public Exception
{
public:
	TCommunicationErrorType Type;
	__fastcall ECommunicationError(UnicodeString Message, TCommunicationErrorType Type=cetNoError)
	: Exception(Message)
	{
		this->Type = Type;
	};
};

//---------------------------------------------------------------------------
// TSrvAdapterModule
//---------------------------------------------------------------------------
class TSrvAdapterModule : public TDataModule
{
__published:	// IDE-managed Components
	TIdHTTP *HTTPClient;
	TIdCompressorZLib *CompressorZLib;
	TIdAntiFreeze *AntiFreeze;
	TIdIOHandlerStack *IOHandlerStack;
	TIdCookieManager *Cookies;
	TIdHTTP *HTTPClientAux;
	TTimer *PingTimer;
	TIdIOHandlerStack *IOHandlerStackAux;
	void __fastcall HTTPClientWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall HTTPClientWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	//void __fastcall HTTPClientWorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall HTTPClientHeadersAvailable(TObject *Sender, TIdHeaderList *AHeaders,
		  bool &VContinue);
	void __fastcall HTTPClientAuxHeadersAvailable(TObject *Sender, TIdHeaderList *AHeaders,
          bool &VContinue);
	void __fastcall OnPingTimer(TObject *Sender);
	void __fastcall HTTPClientAuthorization(TObject *Sender, TIdAuthentication *Authentication,
          bool &Handled);
	void __fastcall HTTPClientConnected(TObject *Sender);
	void __fastcall HTTPClientProxyAuthorization(TObject *Sender, TIdAuthentication *Authentication,
          bool &Handled);

public:
	__fastcall TSrvAdapterModule(TComponent* Owner);
	__fastcall ~TSrvAdapterModule();

	__property TSrvSession* Session = {read=FSession};
	//__property TSrvSettings* Settings = { read=FSettings };

	__property TProgressMeter* Progress = { read=FProgress };

	__property UnicodeString Username = { read=FUsername };
	__property UnicodeString Password = { read=FPassword };
	__property bool RememberUser = { read=FRememberUser };
	__property bool Authorized = { read=getAuthorized };

	__property TGraphic* Avatar = {read=FAvatar};

	bool __fastcall FFmpegProgress(float Ratio);

//Uploader protocol implementation
	int __fastcall Login(UnicodeString Username, UnicodeString Password, bool RememberUser);
	void __fastcall Logout(bool ClearCredentials=true);
	int __fastcall ReLogin();
	int __fastcall Upload(TMediaItem* MI);
	void __fastcall Ping();
//Conversion methods
	bool __fastcall PrepareMedia(TMediaItem* MI);
//YouTube methods
	#ifdef CUSTOM_YOUTUBE
		bool __fastcall YT_Download(TMediaItem* MI, UnicodeString ID, int Quality=0);
		bool __fastcall YT_Embed(TMediaItem* MI, UnicodeString ID);
		__int64 __fastcall YT_GetFileSize(UnicodeString ID, int Quality);
	#endif
//Execution control
	int Busy;
	void __fastcall Terminate();
	void __fastcall Disconnect();
//Hash methods
	AnsiString __fastcall sha1(UnicodeString Val);
	AnsiString __fastcall sha1(TStream* Stream, __int64 StartPos=0, __int64 Size=0);
	AnsiString __fastcall md5(UnicodeString Val);
	AnsiString __fastcall md5(TStream* Stream, __int64 StartPos=0, __int64 Size=0);
	AnsiString __fastcall HashMedia(TStream* Stream);
//MIME methods
	AnsiString __fastcall base64_encode(TStream* Source);
	bool __fastcall base64_decode(AnsiString Source, TStream* Dest);

	__property TFileStream* Watermark = {read=FWatermark};

protected:
	TSrvSession* FSession;
	//TSrvSettings* FSettings;

	TProgressMeter* FProgress;

	int __fastcall CS_Post(UnicodeString &ResponseText,
		TIdMultiPartFormDataStream* PostData, unsigned int Flags=0);
	int __fastcall CS_Login(UnicodeString &ResponseText,
		UnicodeString Username, UnicodeString Password);
	int __fastcall CS_PreUpload(UnicodeString &ResponseText,
		TMediaItem* MI, AnsiString FileName);
	int __fastcall CS_Upload(UnicodeString &ResponseText,
		TMediaItem* MI, UnicodeString FileName);
	void __fastcall CS_Logout();
	int __fastcall CS_Ping();


	UnicodeString FUsername, FPassword;
	bool __fastcall getAuthorized() {return this->Session!=NULL && this->Session->Settings!=NULL;};
	bool FRememberUser;

	//HTTP method wrappers
	UnicodeString __fastcall Get(UnicodeString URL, bool HandleRedirects = false);
	void __fastcall Get(UnicodeString URL, TStream* Stream, bool HandleRedirects = false);
	void __fastcall Head(UnicodeString URL);
	UnicodeString __fastcall Post(UnicodeString URL, TStringList* PostData, bool HandleRedirects = false);
	UnicodeString __fastcall Post(UnicodeString URL, TIdMultiPartFormDataStream* PostData, bool HandleRedirects = false);
	void __fastcall Post(UnicodeString URL, TIdMultiPartFormDataStream* PostData, TStream* Response, bool HandleRedirects = false);

	void __fastcall HTTPWorkEnd();

	void __fastcall HandleHTTPError(UnicodeString Msg=L"", TCommunicationErrorType Type=cetNoError);
	void __fastcall HTTPSetup(String Cmd, bool HandleRedirects);
	bool __fastcall IsRedirected(int StatusCode);
	bool __fastcall IsAuthFailed(int StatusCode);

	void __fastcall StartProgress(UnicodeString SubOperation=L"", float Min=0.00, float Max=1.00,
		TProgressMeterMode Mode=pmmManual);
	void __fastcall StopProgress();

	bool Terminated;

	AnsiString UserAgent_YT;

	//Mime coders
	TIdEncoderMIME* encoderBase64;
	TIdDecoderMIME* decoderBase64;

	//YT constnts
	#ifdef CUSTOM_YOUTUBE
		const UnicodeString YT_Formats[];

		//YouTube helper methods
		UnicodeString __fastcall YT_GetDownloadURL(UnicodeString ID,
			int Quality, __int64 &Size, int &Fmt);
		UnicodeString __fastcall YT_GetDownloadURLAlt(UnicodeString ID,
			int Quality, __int64 &Size, int &Fmt);
		UnicodeString __fastcall YT_GetDownloadToken(UnicodeString ID);
		UnicodeString __fastcall YT_GetFmtMap(UnicodeString ID);
		void __fastcall YT_GetInfo(TMediaItem* MI, UnicodeString ID);
		void __fastcall YT_GetInfoNormal(TMediaItem* MI, UnicodeString ID);
		void __fastcall YT_GetInfoAlt(TMediaItem* MI, UnicodeString ID);
	#endif

	//Conversion
	bool __fastcall PrepareVideo(TMediaItem* MI, TSrvMediaFormat* Format);
	bool __fastcall PrepareAudio(TMediaItem* MI, TSrvMediaFormat* Format);
	bool __fastcall PrepareImage(TMediaItem* MI);

	void __fastcall MakeThumbnail(TFileStream* &Data, TFFmpegConsole* FC,
		UnicodeString Options=L"", long double Duration=-1);
	TFileStream* __fastcall MakeThumbnailCopy(TFileStream* Source);
	TFileStream* __fastcall MakeDefaultThumbnail(bool Big=false);
	void __fastcall MakeThumbnailList(bool Big, TList* List, UnicodeString Options,
		int Count, long double Duration,
		TFFmpegConsole* FC, TFFmpegConsole* FallbackFC=NULL);
	bool __fastcall CopyFile(TFileStream* Source, UnicodeString TargetFileName);

	TGraphic* FAvatar;

	//Security
	AnsiString __fastcall GetUserAgent();
	#ifdef CFG_LOGIN_REQUEST_VERSION_SHA1
		AnsiString __fastcall GetVersionSHA1();
	#endif
	#ifdef CFG_LOGIN_REQUEST_EXECUTABLE_SHA1
		AnsiString __fastcall GetExecutableSHA1();
	#endif

	AnsiString __fastcall Encrypt(UnicodeString Text);
	UnicodeString __fastcall Decrypt(AnsiString Text, bool Login=false);

	AnsiString __fastcall EncryptPassword(UnicodeString Text);
	UnicodeString __fastcall DecryptPassword(AnsiString Text);
	void __fastcall MaskPassword(AnsiString &Text);

	bool __fastcall WriteXMLData(TXMLMessage* Msg,
		TIdMultiPartFormDataStream* PostData);

	//Watermark
	TFileStream* FWatermark;

	bool FHTTPAuthFailed;
	bool FProxyAuthFailed;
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
extern PACKAGE TSrvAdapterModule *SrvAdapterModule;
//---------------------------------------------------------------------------
#endif
