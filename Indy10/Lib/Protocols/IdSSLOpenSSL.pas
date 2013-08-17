{
  $Project$
  $Workfile$
  $Revision$
  $DateUTC$
  $Id$

  This file is part of the Indy (Internet Direct) project, and is offered
  under the dual-licensing agreement described on the Indy website.
  (http://www.indyproject.org/)

  Copyright:
   (c) 1993-2005, Chad Z. Hower and the Indy Pit Crew. All rights reserved.
}
{
  $Log$
}
{
  Rev 1.40    03/11/2009 09:04:00  AWinkelsdorf
  Implemented fix for Vista+ SSL_Read and SSL_Write to allow connection
  timeout.

  Rev 1.39    16/02/2005 23:26:08  CCostelloe
  Changed OnVerifyPeer.  Breaks existing implementation of OnVerifyPeer.  See
  long comment near top of file.

  Rev 1.38    1/31/05 6:02:28 PM  RLebeau
  Updated _GetThreadId() callback to reflect changes in IdGlobal unit

  Rev 1.37    7/27/2004 1:54:26 AM  JPMugaas
  Now should use the Intercept property for sends.

  Rev 1.36    2004-05-18 21:38:36  Mattias
  Fixed unload bug

  Rev 1.35    2004-05-07 16:34:26  Mattias
  Implemented  OpenSSL locking callbacks

  Rev 1.34    27/04/2004 9:38:48  HHariri
  Added compiler directive so it works in BCB

  Rev 1.33    4/26/2004 12:41:10 AM  BGooijen
  Fixed WriteDirect

  Rev 1.32    2004.04.08 10:55:30 PM  czhower
  IOHandler changes.

  Rev 1.31    3/7/2004 9:02:58 PM  JPMugaas
  Fixed compiler warning about visibility.

  Rev 1.30    2004.03.07 11:46:40 AM  czhower
  Flushbuffer fix + other minor ones found

  Rev 1.29    2/7/2004 5:50:50 AM  JPMugaas
  Fixed Copyright.

  Rev 1.28    2/6/2004 3:45:56 PM  JPMugaas
  Only a start on NET porting.  This is not finished and will not compile on
  DotNET>

  Rev 1.27    2004.02.03 5:44:24 PM  czhower
  Name changes

  Rev 1.26    1/21/2004 4:03:48 PM  JPMugaas
  InitComponent

  Rev 1.25    1/14/2004 11:39:10 AM  JPMugaas
  Server IOHandler now works.  Accept was commented out.

  Rev 1.24    2003.11.29 10:19:28 AM  czhower
  Updated for core change to InputBuffer.

  Rev 1.23    10/21/2003 10:09:14 AM  JPMugaas
  Intercept enabled.

  Rev 1.22    10/21/2003 09:41:38 AM  JPMugaas
  Updated for new API.  Verified with TIdFTP with active and passive transfers
  as well as clear and protected data channels.

  Rev 1.21    10/21/2003 07:32:38 AM  JPMugaas
  Checked in what I have.  Porting still continues.

  Rev 1.20    10/17/2003 1:08:08 AM  DSiders
  Added localization comments.

  Rev 1.19    2003.10.12 6:36:44 PM  czhower
  Now compiles.

  Rev 1.18    9/19/2003 11:24:58 AM  JPMugaas
  Should compile.

  Rev 1.17    9/18/2003 10:20:32 AM  JPMugaas
  Updated for new API.

  Rev 1.16    2003.07.16 3:26:52 PM  czhower
  Fixed for a core change.

  Rev 1.15    6/30/2003 1:52:22 PM  BGooijen
  Changed for new buffer interface

  Rev 1.14    6/29/2003 5:42:02 PM  BGooijen
  fixed problem in TIdSSLIOHandlerSocketOpenSSL.SetPassThrough that Henrick
  Hellstrom reported

  Rev 1.13    5/7/2003 7:13:00 PM  BGooijen
  changed Connected to BindingAllocated in ReadFromSource

  Rev 1.12    3/30/2003 12:16:40 AM  BGooijen
  bugfixed+ added MakeFTPSvrPort/MakeFTPSvrPasv

  Rev 1.11    3/14/2003 06:56:08 PM  JPMugaas
  Added a clone method to the SSLContext.

  Rev 1.10    3/14/2003 05:29:10 PM  JPMugaas
  Change to prevent an AV when shutting down the FTP Server.

  Rev 1.9    3/14/2003 10:00:38 PM  BGooijen
  Removed TIdServerIOHandlerSSLBase.PeerPassthrough, the ssl is now enabled in
  the server-protocol-files

  Rev 1.8    3/13/2003 11:55:38 AM  JPMugaas
  Updated registration framework to give more information.

  Rev 1.7    3/13/2003 11:07:14 AM  JPMugaas
  OpenSSL classes renamed.

  Rev 1.6    3/13/2003 10:28:16 AM  JPMugaas
  Forgot the reegistration - OOPS!!!

  Rev 1.5    3/13/2003 09:49:42 AM  JPMugaas
  Now uses an abstract SSL base class instead of OpenSSL so 3rd-party vendors
  can plug-in their products.

  Rev 1.4    3/13/2003 10:20:08 AM  BGooijen
  Server side fibers

  Rev 1.3    2003.02.25 3:56:22 AM  czhower

  Rev 1.2    2/5/2003 10:27:46 PM  BGooijen
  Fixed bug in OpenEncodedConnection

  Rev 1.1    2/4/2003 6:31:22 PM  BGooijen
  Fixed for Indy 10

  Rev 1.0    11/13/2002 08:01:24 AM  JPMugaas
}
unit IdSSLOpenSSL;
{
  Author: Gregor Ibic (gregor.ibic@intelicom.si)
  Copyright: (c) Gregor Ibic, Intelicom d.o.o and Indy Working Group.
}

{
  Indy OpenSSL now uses the standard OpenSSL libraries
    for pre-compiled win32 dlls, see:
    http://www.openssl.org/related/binaries.html
    recommended v0.9.8a or later
}

{
  Important information concerning OnVerifyPeer:
    Rev 1.39 of February 2005 deliberately broke the OnVerifyPeer interface,
    which (obviously?) only affects programs that implemented that callback
    as part of the SSL negotiation.  Note that you really should always
    implement OnVerifyPeer, otherwise the certificate of the peer you are
    connecting to is NOT checked to ensure it is valid.

    Prior to this, if the SSL library detected a problem with a certificate
    or the Depth was insufficient (i.e. the "Ok" parameter in VerifyCallback
    is 0 / FALSE), then irrespective of whether your OnVerifyPeer returned True
    or False, the SSL connection would be deliberately failed.

    This created a problem in that even if there was only a very minor
    problem with one of the certificates in the chain (OnVerifyPeer is called
    once for each certificate in the certificate chain), which the user may
    have been happy to accept, the SSL negotiation would be failed.  However,
    changing the code to allow the SSL connection when a user returned True
    for OnVerifyPeer would have meant that existing code which depended on
    automatic rejection of invalid certificates would then be accepting
    invalid certificates, which would have been an unacceptable security
    change.

    Consequently, OnVerifyPeer was changed to deliberately break existing code
    by adding an AOk parameter.  To preserve the previous functionality, your
    OnVerifyPeer event should do "Result := AOk;".  If you wish to consider
    accepting certificates that the SSL library has considered invalid, then
    in your OnVerifyPeer, make sure you satisfy yourself that the certificate
    really is valid and then set Result to True.  In reality, in addition to
    checking AOk, you should always implement code that ensures you are only
    accepting certificates which are valid (at least from your point of view).

    Ciaran Costelloe, ccostelloe@flogas.ie
}

interface

{$I IdCompilerDefines.inc}
{$TYPEDADDRESS OFF}

uses
  Classes,
  IdBuffer,
  IdCTypes,
  IdGlobal,
  IdException,
  IdStackConsts,
  IdSocketHandle,
  IdSSLOpenSSLHeaders,
  IdComponent,
  IdIOHandler,
  IdGlobalProtocols,
  IdTCPServer,
  IdThread,
  IdTCPConnection,
  IdIntercept,
  IdIOHandlerSocket,
  IdSSL,
  IdSocks,
  IdScheduler,
  IdYarn;

type
  TIdSSLVersion = (sslvSSLv2, sslvSSLv23, sslvSSLv3, sslvTLSv1);
  TIdSSLMode = (sslmUnassigned, sslmClient, sslmServer, sslmBoth);
  TIdSSLVerifyMode = (sslvrfPeer, sslvrfFailIfNoPeerCert, sslvrfClientOnce);
  TIdSSLVerifyModeSet = set of TIdSSLVerifyMode;
  TIdSSLCtxMode = (sslCtxClient, sslCtxServer);
  TIdSSLAction = (sslRead, sslWrite);

const
  DEF_SSLVERSION = sslvTLSv1;
  
type
  TIdX509 = class;

  TULong = packed record
    case Byte of
      0: (B1,B2,B3,B4: Byte);
      1: (W1,W2: Word);
      2: (L1: Longint);
      3: (C1: LongWord);
  end;

  TEVP_MD = record
    Length: TIdC_UINT;
    MD: Array[0..OPENSSL_EVP_MAX_MD_SIZE-1] of AnsiChar;
  end;

  TByteArray = record
    Length: TIdC_INT;
    Data: PAnsiChar;
  End;

  TIdSSLIOHandlerSocketOpenSSL = class;
  TIdSSLCipher = class;

  TCallbackEvent  = procedure(const AMsg: String) of object;
  TPasswordEvent  = procedure(var Password: AnsiString) of object;
  TVerifyPeerEvent  = function(Certificate: TIdX509; AOk: Boolean; ADepth: Integer): Boolean of object;
  TIOHandlerNotify = procedure(ASender: TIdSSLIOHandlerSocketOpenSSL) of object;

  TIdSSLOptions = class(TPersistent)
  protected
    fsRootCertFile, fsCertFile, fsKeyFile: String;
    fMethod: TIdSSLVersion;
    fMode: TIdSSLMode;
    fVerifyDepth: Integer;
    fVerifyMode: TIdSSLVerifyModeSet;
    //fVerifyFile,
    fVerifyDirs, fCipherList: AnsiString;
    procedure AssignTo(ASource: TPersistent); override;
  public
    constructor Create;
  published
    property RootCertFile: String read fsRootCertFile write fsRootCertFile;
    property CertFile: String read fsCertFile write fsCertFile;
    property KeyFile: String read fsKeyFile write fsKeyFile;
    property Method: TIdSSLVersion read fMethod write fMethod default DEF_SSLVERSION;
    property Mode: TIdSSLMode read fMode write fMode;
    property VerifyMode: TIdSSLVerifyModeSet read fVerifyMode write fVerifyMode;
    property VerifyDepth: Integer read fVerifyDepth write fVerifyDepth;
//    property VerifyFile: String read fVerifyFile write fVerifyFile;
    property VerifyDirs: AnsiString read fVerifyDirs write fVerifyDirs;
    property CipherList: AnsiString read fCipherList write fCipherList;
  public
    // procedure Assign(ASource: TPersistent); override;
  end;

  TIdSSLContext = class(TObject)
  protected
    fMethod: TIdSSLVersion;
    fMode: TIdSSLMode;
    fsRootCertFile, fsCertFile, fsKeyFile: AnsiString;
    fVerifyDepth: Integer;
    fVerifyMode: TIdSSLVerifyModeSet;
//    fVerifyFile: String;
    fVerifyDirs: String;
    fCipherList: AnsiString;
    fContext: PSSL_CTX;
    fStatusInfoOn: Boolean;
//    fPasswordRoutineOn: Boolean;
    fVerifyOn: Boolean;
    fSessionId: Integer;
    fCtxMode: TIdSSLCtxMode;
    procedure DestroyContext;
    function SetSSLMethod: PSSL_METHOD;
    procedure SetVerifyMode(Mode: TIdSSLVerifyModeSet; CheckRoutine: Boolean);
    function GetVerifyMode: TIdSSLVerifyModeSet;
    procedure InitContext(CtxMode: TIdSSLCtxMode);
  public
    Parent: TObject;
    constructor Create;
    destructor Destroy; override;
    function Clone : TIdSSLContext;
    function LoadRootCert: Boolean;
    function LoadCert: Boolean;
    function LoadKey: Boolean;
    property StatusInfoOn: Boolean read fStatusInfoOn write fStatusInfoOn;
//    property PasswordRoutineOn: Boolean read fPasswordRoutineOn write fPasswordRoutineOn;
    property VerifyOn: Boolean read fVerifyOn write fVerifyOn;
//THese can't be published in a TObject without a compiler warning.
 // published
    property Method: TIdSSLVersion read fMethod write fMethod;
    property Mode: TIdSSLMode read fMode write fMode;
    property RootCertFile: AnsiString read fsRootCertFile write fsRootCertFile;
    property CertFile: AnsiString read fsCertFile write fsCertFile;
    property KeyFile: AnsiString read fsKeyFile write fsKeyFile;
//    property VerifyMode: TIdSSLVerifyModeSet read GetVerifyMode write SetVerifyMode;
    property VerifyMode: TIdSSLVerifyModeSet read fVerifyMode write fVerifyMode;
    property VerifyDepth: Integer read fVerifyDepth write fVerifyDepth;
  end;

  TIdSSLSocket = class(TObject)
  protected
    fParent: TObject;
    fPeerCert: TIdX509;
    fSSL: PSSL;
    fSSLCipher: TIdSSLCipher;
    fSSLContext: TIdSSLContext;
    function GetPeerCert: TIdX509;
    function GetSSLError(retCode: Integer): Integer;
    function GetSSLCipher: TIdSSLCipher;
  public
    constructor Create(Parent: TObject);
    destructor Destroy; override;
    procedure Accept(const pHandle: TIdStackSocketHandle);
    procedure Connect(const pHandle: TIdStackSocketHandle);
    function Send(const ABuffer : TIdBytes; AOffset, ALength: Integer): Integer;
    function Recv(var ABuffer : TIdBytes): Integer;
    function GetSessionID: TByteArray;
    function GetSessionIDAsString:String;
    procedure SetCipherList(CipherList: String);
    //
    property PeerCert: TIdX509 read GetPeerCert;
    property Cipher: TIdSSLCipher read GetSSLCipher;
  end;

  TIdSSLIOHandlerSocketOpenSSL = class(TIdSSLIOHandlerSocketBase)
  protected
    fSSLContext: TIdSSLContext;
    fxSSLOptions: TIdSSLOptions;
    fSSLSocket: TIdSSLSocket;
    //fPeerCert: TIdX509;
    fOnStatusInfo: TCallbackEvent;
    fOnGetPassword: TPasswordEvent;
    fOnVerifyPeer: TVerifyPeerEvent;
    fSSLLayerClosed: Boolean;
    fOnBeforeConnect: TIOHandlerNotify;
    // function GetPeerCert: TIdX509;
    //procedure CreateSSLContext(axMode: TIdSSLMode);
    //
    procedure SetPassThrough(const Value: Boolean); override;
    procedure DoBeforeConnect(ASender: TIdSSLIOHandlerSocketOpenSSL); virtual;
    procedure DoStatusInfo(const AMsg: String); virtual;
    procedure DoGetPassword(var Password: AnsiString); virtual;
    function DoVerifyPeer(Certificate: TIdX509; AOk: Boolean; ADepth: Integer): Boolean; virtual;
    function RecvEnc(var VBuffer: TIdBytes): Integer; override;
    function SendEnc(const ABuffer: TIdBytes; const AOffset, ALength: Integer): Integer; override;
    procedure Init;
    procedure OpenEncodedConnection; virtual;
    //some overrides from base classes
    procedure InitComponent; override;
    procedure ConnectClient; override;
  public
    destructor Destroy; override;
    function Clone :  TIdSSLIOHandlerSocketBase; override;
    procedure StartSSL; override;
    procedure AfterAccept; override;
    procedure Close; override;
    procedure Open; override;
    property SSLSocket: TIdSSLSocket read fSSLSocket write fSSLSocket;
    property OnBeforeConnect: TIOHandlerNotify read fOnBeforeConnect write fOnBeforeConnect;
    property SSLContext: TIdSSLContext read fSSLContext write fSSLContext;
  published
    property SSLOptions: TIdSSLOptions read fxSSLOptions write fxSSLOptions;
    property OnStatusInfo: TCallbackEvent read fOnStatusInfo write fOnStatusInfo;
    property OnGetPassword: TPasswordEvent read fOnGetPassword write fOnGetPassword;
    property OnVerifyPeer: TVerifyPeerEvent read fOnVerifyPeer write fOnVerifyPeer;
  end;

  TIdServerIOHandlerSSLOpenSSL = class(TIdServerIOHandlerSSLBase)
  protected
    fxSSLOptions: TIdSSLOptions;
    fSSLContext: TIdSSLContext;
    fOnStatusInfo: TCallbackEvent;
    fOnGetPassword: TPasswordEvent;
    fOnVerifyPeer: TVerifyPeerEvent;
    //
    //procedure CreateSSLContext(axMode: TIdSSLMode);
    //procedure CreateSSLContext;
    //
    procedure DoStatusInfo(const AMsg: String); virtual;
    procedure DoGetPassword(var Password: AnsiString); virtual;
    function DoVerifyPeer(Certificate: TIdX509; AOk: Boolean; ADepth: Integer): Boolean; virtual;
    procedure InitComponent; override;
  public
    procedure Init; override;
    procedure Shutdown; override;
    // AListenerThread is a thread and not a yarn. Its the listener thread.
    function Accept(ASocket: TIdSocketHandle; AListenerThread: TIdThread;
      AYarn: TIdYarn): TIdIOHandler; override;
//    function Accept(ASocket: TIdSocketHandle; AThread: TIdThread) : TIdIOHandler;  override;
    destructor Destroy; override;
    function MakeClientIOHandler : TIdSSLIOHandlerSocketBase; override;
    //
    function MakeFTPSvrPort : TIdSSLIOHandlerSocketBase; override;
    function MakeFTPSvrPasv : TIdSSLIOHandlerSocketBase; override;
    //
    property SSLContext: TIdSSLContext read fSSLContext;
  published
    property SSLOptions: TIdSSLOptions read fxSSLOptions write fxSSLOptions;
    property OnStatusInfo: TCallbackEvent read fOnStatusInfo write fOnStatusInfo;
    property OnGetPassword: TPasswordEvent read fOnGetPassword write fOnGetPassword;
    property OnVerifyPeer: TVerifyPeerEvent read fOnVerifyPeer write fOnVerifyPeer;
  end;

  TIdX509Name = class(TObject)
  protected
    fX509Name: PX509_NAME;
    function CertInOneLine: String;
    function GetHash: TULong;
    function GetHashAsString: String;
  public
    constructor Create(aX509Name: PX509_NAME);
    //
    property Hash: TULong read GetHash;
    property HashAsString: string read GetHashAsString;
    property OneLine: string read CertInOneLine;
  end;

  TIdX509Info = class(TObject)
  protected
    //Do not free this here because it belongs
    //to the X509 or something else.
    FX509 : PX509;
  public
    constructor Create( aX509: PX509);
  end;

  TIdX509Fingerprints = class(TIdX509Info)
  protected
    function GetMD5: TEVP_MD;
    function GetMD5AsString:String;
    function GetSHA1: TEVP_MD;
    function GetSHA1AsString:String;
    function GetSHA224 : TEVP_MD;
    function GetSHA224AsString : String;
    function GetSHA256 : TEVP_MD;
    function GetSHA256AsString : String;
    function GetSHA386 : TEVP_MD;
    function GetSHA386AsString : String;
    function GetSHA512 : TEVP_MD;
    function GetSHA512AsString : String;
  public
     property MD5 : TEVP_MD read GetMD5;
     property MD5AsString : String read  GetMD5AsString;
{IMPORTANT!!!

FIPS approves only these algorithms for hashing.
SHA-1
SHA-224
SHA-256
SHA-384
SHA-512

http://csrc.nist.gov/CryptoToolkit/tkhash.html
}
    property SHA1 : TEVP_MD read GetSHA1;
    property SHA1AsString : String read  GetSHA1AsString;
    property SHA224 : TEVP_MD read GetSHA224;
    property SHA224AsString : String read GetSHA224AsString;
    property SHA256 : TEVP_MD read GetSHA256;
    property SHA256AsString : String read GetSHA256AsString;
    property SHA386 : TEVP_MD read GetSHA386;
    property SHA386AsString : String read GetSHA386AsString;
    property SHA512 : TEVP_MD read GetSHA512;
    property SHA512AsString : String read GetSHA512AsString;
  end;

  TIdX509SigInfo = class(TIdX509Info)
  protected
    function GetSignature : String;
    function GetSigType : TIdC_INT;
    function GetSigTypeAsString : String;
  public
    property Signature : String read GetSignature;
    property SigType : TIdC_INT read  GetSigType ;
    property SigTypeAsString : String read GetSigTypeAsString;
  end;

  TIdX509 = class(TObject)
  protected
    FFingerprints : TIdX509Fingerprints;
    FSigInfo : TIdX509SigInfo;
    FCanFreeX509 : Boolean;
    FX509    : PX509;
    FSubject : TIdX509Name;
    FIssuer  : TIdX509Name;
    FDisplayInfo : TStrings;
    function RSubject:TIdX509Name;
    function RIssuer:TIdX509Name;
    function RnotBefore:TDateTime;
    function RnotAfter:TDateTime;
    function RFingerprint:TEVP_MD;
    function RFingerprintAsString:String;
    function GetSerialNumber: String;
    function GetVersion : TIdC_LONG;
    function GetDisplayInfo : TStrings;
  public
    Constructor Create(aX509: PX509; aCanFreeX509: Boolean = True); virtual;
    Destructor Destroy; override;
    property Version : TIdC_LONG read GetVersion;
    //
    property SigInfo : TIdX509SigInfo read FSigInfo;
    property Fingerprints : TIdX509Fingerprints read  FFingerprints;
    //
    property Fingerprint: TEVP_MD read RFingerprint;
    property FingerprintAsString: String read RFingerprintAsString;
    property Subject: TIdX509Name read RSubject;
    property Issuer: TIdX509Name read RIssuer;
    property notBefore: TDateTime read RnotBefore;
    property notAfter: TDateTime read RnotAfter;
    property SerialNumber : string read GetSerialNumber;
    property DisplayInfo : TStrings read GetDisplayInfo;
  end;

  TIdSSLCipher = class(TObject)
  protected
    FSSLSocket: TIdSSLSocket;
    function GetDescription: String;
    function GetName: String;
    function GetBits: Integer;
    function GetVersion: String;
  public
    constructor Create(AOwner: TIdSSLSocket);
    destructor Destroy; override;
 //These can't be published without a compiler warning.
 // published
    property Description: String read GetDescription;
    property Name: String read GetName;
    property Bits: Integer read GetBits;
    property Version: String read GetVersion;
  end;


  EIdOSSLCouldNotLoadSSLLibrary = class(EIdOpenSSLError);
  EIdOSSLModeNotSet             = class(EIdOpenSSLError);
  EIdOSSLGetMethodError         = class(EIdOpenSSLError);
  EIdOSSLCreatingContextError   = class(EIdOpenSSLError);
  

  EIdOSSLLoadingRootCertError = class(EIdOpenSSLAPICryptoError);
  EIdOSSLLoadingCertError = class(EIdOpenSSLAPICryptoError);
  EIdOSSLLoadingKeyError = class(EIdOpenSSLAPICryptoError);

  EIdOSSLSettingCipherError = class(EIdOpenSSLError);
  EIdOSSLFDSetError = class(EIdOpenSSLAPISSLError);
  EIdOSSLDataBindingError = class(EIdOpenSSLAPISSLError);
  EIdOSSLAcceptError = class(EIdOpenSSLAPISSLError);
  EIdOSSLConnectError = class(EIdOpenSSLAPISSLError);

function LogicalAnd(A, B: Integer): Boolean;

function LoadOpenSSLLibrary: Boolean;
procedure UnLoadOpenSSLLibrary;

implementation

uses
  IdResourceStringsCore,
  IdResourceStringsProtocols,
  IdStack,
  IdStackBSDBase,
  IdAntiFreezeBase,
  IdExceptionCore,
  IdResourceStrings,
  IdThreadSafe,
  SysUtils;

var
  SSLIsLoaded: TIdThreadSafeBoolean = nil;
  LockInfoCB: TIdCriticalSection = nil;
  LockPassCB: TIdCriticalSection = nil;
  LockVerifyCB: TIdCriticalSection = nil;
  CallbackLockList: TThreadList = nil;



function PasswordCallback(buf: PAnsiChar; size: TIdC_INT; rwflag: TIdC_INT; userdata: Pointer): TIdC_INT; cdecl;
var
  Password: AnsiString;
  IdSSLContext: TIdSSLContext;
begin
  LockPassCB.Enter;
  try
    Password := '';    {Do not Localize}
    IdSSLContext := TIdSSLContext(userdata);
    if (IdSSLContext.Parent is TIdSSLIOHandlerSocketOpenSSL) then begin
      TIdSSLIOHandlerSocketOpenSSL(IdSSLContext.Parent).DoGetPassword(Password);
    end;
    if (IdSSLContext.Parent is TIdServerIOHandlerSSLOpenSSL) then begin
      TIdServerIOHandlerSSLOpenSSL(IdSSLContext.Parent).DoGetPassword(Password);
    end;
    FillChar(buf^, size, 0);
    StrPLCopy(buf, Password, size);
    Result := Length(Password);
    buf[size-1] := #0; // RLebeau: truncate the password if needed
  finally
    LockPassCB.Leave;
  end;
end;

procedure InfoCallback(const sslSocket: PSSL; where, ret: TIdC_INT); cdecl;
var
  IdSSLSocket: TIdSSLSocket;
  StatusStr : String;
  LErr : Integer;
begin
{
You have to save the value of WSGetLastError as some Operating System API
function calls will reset that value and we can't know what a programmer will
do in this event.  We need the value of WSGetLastError so we can report
an underlying socket error when the OpenSSL function returns.

JPM.
}
  LErr := GStack.WSGetLastError;
  try
    LockInfoCB.Enter;
    try
      IdSSLSocket := TIdSSLSocket(IdSslGetAppData(sslSocket));
      StatusStr := IndyFormat(RSOSSLStatusString, [StrPas(IdSslStateStringLong(sslSocket))]);
      if (IdSSLSocket.fParent is TIdSSLIOHandlerSocketOpenSSL) then begin
        TIdSSLIOHandlerSocketOpenSSL(IdSSLSocket.fParent).DoStatusInfo(StatusStr);
      end;
      if (IdSSLSocket.fParent is TIdServerIOHandlerSSLOpenSSL) then begin
        TIdServerIOHandlerSSLOpenSSL(IdSSLSocket.fParent).DoStatusInfo(StatusStr);
      end;
    finally
      LockInfoCB.Leave;
    end;
  finally
    GStack.WSSetLastError(LErr);
  end;
end;

{function RSACallback(sslSocket: PSSL; e: Integer; KeyLength: Integer):PRSA; cdecl;
const
  RSA: PRSA = nil;
var
  SSLSocket: TSSLWSocket;
  IdSSLSocket: TIdSSLSocket;
begin
  IdSSLSocket := TIdSSLSocket(IdSslGetAppData(sslSocket));

  if Assigned(IdSSLSocket) then begin
    IdSSLSocket.TriggerSSLRSACallback(KeyLength);
  end;

  if not Assigned(RSA) then begin
    RSA := f_RSA_generate_key(KeyLength, RSA_F4, @RSAProgressCallback, ssl);
  end;
  Result := RSA;
end;}

function AddMins (const DT: TDateTime; const Mins: Extended): TDateTime;  {$IFDEF USEINLINE} inline; {$ENDIF}
begin
  Result := DT + Mins / (60 * 24)
end;

function AddHrs (const DT: TDateTime; const Hrs: Extended): TDateTime;  {$IFDEF USEINLINE} inline; {$ENDIF}
begin
  Result := DT + Hrs / 24.0;
end;

function GetLocalTime (const DT: TDateTime): TDateTime;   {$IFDEF USEINLINE} inline; {$ENDIF}
begin
  Result := DT - TimeZoneBias{ / (24 * 60)};
end;

procedure SslLockingCallback(mode, n : TIdC_INT; Afile : PAnsiChar; line : TIdC_INT) cdecl;
var
  Lock: TIdCriticalSection;
begin
  Assert(CallbackLockList<>nil);
  Lock := nil;

  with CallbackLockList.LockList do
  try
    if n < Count then begin
      Lock := TIdCriticalSection(Items[n]);
    end;
  finally
    CallbackLockList.UnlockList;
  end;
  Assert(Lock<>nil);
  if (mode and OPENSSL_CRYPTO_LOCK) = OPENSSL_CRYPTO_LOCK then begin
    Lock.Acquire;
  end else begin
    Lock.Release;
  end;
end;

procedure PrepareOpenSSLLocking;
var
  i, cnt : integer;
  Lock: TIdCriticalSection;
begin
  with CallbackLockList.LockList do
  try
    cnt := IdSslCryptoNumLocks;
    for i := 0 to cnt-1 do
    begin
      Lock := TIdCriticalSection.Create;
      try
        Add(Lock);
      except
        Lock.Free;
        raise;
      end;
    end;
  finally
    CallbackLockList.UnlockList;
  end;
end;

{$IFNDEF WIN32_OR_WIN64}
function _GetThreadID: TIdC_ULONG; cdecl;
begin
  // TODO: Verify how well this will work with fibers potentially running from
  // thread to thread or many on the same thread.
  Result := TIdC_ULONG(CurrentThreadId);
end;
{$ENDIF}

{$IFDEF IDOPENSSLMEMORY}
function IdMalloc(num:Cardinal):Pointer cdecl;
begin
  Result:=AllocMem(num);
end;

function IdRealloc(addr:Pointer;num:Cardinal):Pointer cdecl;
begin
  Result:=addr;
  ReallocMem(Result,num);
end;

procedure IdFree(addr:Pointer) cdecl;
begin
  FreeMem(addr);
end;

procedure IdSslCryptoMallocInit;
//replaces the actual alloc routines
//this is useful if you are using a memory manager that can report on leaks
//at shutdown time.
var
 r: Integer;
begin
 r := IdSslCryptoSetMemFunctions(@IdMalloc, @IdRealloc, @IdFree);
 Assert(r<>0);
end;
{$ENDIF}

function LoadOpenSSLLibrary: Boolean;
begin
  Assert(SSLIsLoaded<>nil);
  SSLIsLoaded.Lock;
  try
    if SSLIsLoaded.Value then
    begin
      Result := True;
      Exit;
    end;
    Result := IdSSLOpenSSLHeaders.Load;
    if not Result then 
    begin
      Exit;
    end;
    {$IFDEF IDOPENSSLMEMORY}
    //has to be done before anything that uses memory
    IdSslCryptoMallocInit;
    {$ENDIF}
    //required eg to encrypt a private key when writing
    IdSslAddAllCiphers;
    IdSslAddAllDigests;
    InitializeRandom;
    // IdSslRandScreen;
    IdSslLoadErrorStrings;
    // Successful loading if true
    Result := IdSslAddSslAlgorithms > 0;
    if not Result then 
    begin
      Exit;
    end;
    // Create locking structures, we need them for callback routines
    Assert(LockInfoCB=nil);
    LockInfoCB := TIdCriticalSection.Create;
    LockPassCB := TIdCriticalSection.Create;
    LockVerifyCB := TIdCriticalSection.Create;
    // Handle internal OpenSSL locking
    CallbackLockList := TThreadList.Create;
    PrepareOpenSSLLocking;
    IdSslSetLockingCallback(SslLockingCallback);
    {$IFNDEF WIN32_OR_WIN64}
    IdSslSetIdCallback(_GetThreadID);
    {$ENDIF}
    SSLIsLoaded.Value := True;
    Result := True;
  finally
    SSLIsLoaded.Unlock;
  end;
end;

procedure UnLoadOpenSSLLibrary;
//allow the user to call unload directly?
//will then need to implement reference count
var
  i : integer;
begin
  //ssl was never loaded
  if LockInfoCB=nil then 
  begin
    Exit;
  end;
  IdSslSetLockingCallback(nil);
  IdSSLOpenSSLHeaders.Unload;
  FreeAndNil(LockInfoCB);
  FreeAndNil(LockPassCB);
  FreeAndNil(LockVerifyCB);
  if Assigned(CallbackLockList) then
  begin
    with CallbackLockList.LockList do
      try
        for i := 0 to Count-1 do begin
          TObject(Items[i]).Free;
        end;
        Clear;
      finally
        CallbackLockList.UnlockList;
      end;
    FreeAndNil(CallbackLockList);
  end;
  SSLIsLoaded.Value := False;
end;

//Note that I define UCTTime as  PASN1_STRING
function UTCTime2DateTime(UCTTime: PASN1_UTCTIME):TDateTime; {$IFDEF USEINLINE} inline; {$ENDIF}
var
  year  : Word;
  month : Word;
  day   : Word;
  hour  : Word;
  min   : Word;
  sec   : Word;
  tz_h  : Integer;
  tz_m  : Integer;
begin
  Result := 0;
  if IdSslUCTTimeDecode(UCTTime, year, month, day, hour, min, sec, tz_h, tz_m) > 0 then begin
    Result := EncodeDate(year, month, day) + EncodeTime(hour, min, sec, 0);
    AddMins(Result, tz_m);
    AddHrs(Result, tz_h);
    Result := GetLocalTime(Result);
  end;
end;

function TranslateInternalVerifyToSSL(Mode: TIdSSLVerifyModeSet): Integer;  {$IFDEF USEINLINE} inline; {$ENDIF}
begin
  Result := OPENSSL_SSL_VERIFY_NONE;
  if sslvrfPeer in Mode then 
  begin
    Result := Result or OPENSSL_SSL_VERIFY_PEER;
  end;
  if sslvrfFailIfNoPeerCert in Mode then
  begin
    Result:= Result or OPENSSL_SSL_VERIFY_FAIL_IF_NO_PEER_CERT;
  end;
  if sslvrfClientOnce in Mode then
  begin 
    Result:= Result or OPENSSL_SSL_VERIFY_CLIENT_ONCE;
  end;
end;

function LogicalAnd(A, B: Integer): Boolean;
 {$IFDEF USEINLINE} inline; {$ENDIF}
begin
  Result := (A and B) = B;
end;

function BytesToHexString(APtr : Pointer; ALen : Integer) : String;
{$IFDEF USEINLINE} inline; {$ENDIF}
var
  i : PtrInt;
begin
  Result := '';
  for i := 0 to (ALen - 1) do
  begin
    if I <> 0 then
    begin
      Result := Result + ':';    {Do not Localize}
    end;
    Result := Result + IndyFormat('%.2x', [Byte(Pointer(PtrInt(APtr)+I)^)]);
  end;
end;

function MDAsString(const AMD : TEVP_MD) : String;
{$IFDEF USEINLINE} inline; {$ENDIF}
var
  I : Integer;
begin
  Result := '';
  for I := 0 to AMD.Length - 1 do begin
    if I <> 0 then begin
      Result := Result + ':';    {Do not Localize}
    end;
    Result := Result + IndyFormat('%.2x', [Byte(AMD.MD[I])]);  {do not localize}
  end;
end;

function VerifyCallback(Ok: TIdC_INT; ctx: PX509_STORE_CTX): TIdC_INT; cdecl;
var
  hcert: PX509;
  Certificate: TIdX509;
  hSSL: PSSL;
  IdSSLSocket: TIdSSLSocket;
  // str: String;
  VerifiedOK: Boolean;
  Depth: Integer;
  // Error: Integer;
  LOk: Boolean;
begin
  LockVerifyCB.Enter;
  try
    VerifiedOK := True;
    try
      hSSL := IdSslX509StoreCtxGetAppData(ctx);
      if hSSL = nil then begin
        Result := Ok;
        Exit;
      end;
      hcert := IdSslX509StoreCtxGetCurrentCert(ctx);
      Certificate := TIdX509.Create(hcert, False); // the certificate is owned by the store
      try
        IdSSLSocket := TIdSSLSocket(IdSslGetAppData(hSSL));
        IdSslX509StoreCtxGetError(ctx);
        Depth := IdSslX509StoreCtxGetErrorDepth(ctx);
        if not ((Ok > 0) and (IdSSLSocket.fSSLContext.VerifyDepth >= Depth)) then begin
          Ok := 0;
          {if Error = OPENSSL_X509_V_OK then begin
            Error := OPENSSL_X509_V_ERR_CERT_CHAIN_TOO_LONG;
          end;}
        end;
        LOk := False;
        if Ok = 1 then begin
          LOk := True;
        end;
        if (IdSSLSocket.fParent is TIdSSLIOHandlerSocketOpenSSL) then begin
          VerifiedOK := TIdSSLIOHandlerSocketOpenSSL(IdSSLSocket.fParent).DoVerifyPeer(Certificate, LOk, Depth);
        end;
        if (IdSSLSocket.fParent is TIdServerIOHandlerSSLOpenSSL) then begin
          VerifiedOK := TIdServerIOHandlerSSLOpenSSL(IdSSLSocket.fParent).DoVerifyPeer(Certificate, LOk, Depth);
        end;
      finally
        FreeAndNil(Certificate);
      end;
    except
    end;
    //if VerifiedOK and (Ok > 0) then begin
    if VerifiedOK {and (Ok > 0)} then begin
      Result := 1;
    end
    else begin
      Result := 0;
    end;
  //  Result := Ok; // testing
  finally
    LockVerifyCB.Leave;
  end;
end;

//////////////////////////////////////////////////////
//   TIdSSLOptions
///////////////////////////////////////////////////////

constructor TIdSSLOptions.Create;
begin
  inherited Create;
  Method := DEF_SSLVERSION;
end;

procedure TIdSSLOptions.AssignTo(ASource: TPersistent);
begin
  if ASource is TIdSSLOptions then
    with TIdSSLOptions(ASource) do begin
      RootCertFile := Self.RootCertFile;
      CertFile := Self.CertFile;
      KeyFile := Self.KeyFile;
      Method := Self.Method;
      Mode := Self.Mode;
      VerifyMode := Self.VerifyMode;
      VerifyDepth := Self.VerifyDepth;
      VerifyDirs := Self.VerifyDirs;
      CipherList := Self.CipherList;
    end
  else
    inherited AssignTo(ASource);
end;

///////////////////////////////////////////////////////
//   TIdServerIOHandlerSSLOpenSSL
///////////////////////////////////////////////////////

{ TIdServerIOHandlerSSLOpenSSL }

procedure TIdServerIOHandlerSSLOpenSSL.InitComponent;
begin
  inherited InitComponent;
  fxSSLOptions := TIdSSLOptions.Create;
end;

destructor TIdServerIOHandlerSSLOpenSSL.Destroy;
begin
  FreeAndNil(fxSSLOptions);
  inherited Destroy;
end;

procedure TIdServerIOHandlerSSLOpenSSL.Init;
//see also TIdSSLIOHandlerSocketOpenSSL.Init
begin
  //ensure Init isn't called twice
  Assert(fSSLContext = nil);
  fSSLContext := TIdSSLContext.Create;
  with fSSLContext do begin
    Parent := Self;
    {$IFDEF UNICODESTRING}
    // explicit convert to Ansi
    RootCertFile := AnsiString(SSLOptions.RootCertFile);
    CertFile := AnsiString(SSLOptions.CertFile);
    KeyFile := AnsiString(SSLOptions.KeyFile);
    {$ELSE}
    RootCertFile := SSLOptions.RootCertFile;
    CertFile := SSLOptions.CertFile;
    KeyFile := SSLOptions.KeyFile;
    {$ENDIF}
    fVerifyDepth := SSLOptions.fVerifyDepth;
    fVerifyMode := SSLOptions.fVerifyMode;
    // fVerifyFile := SSLOptions.fVerifyFile;
    fVerifyDirs := String(SSLOptions.fVerifyDirs);
    fCipherList := AnsiString(SSLOptions.fCipherList);
    VerifyOn := Assigned(fOnVerifyPeer);
    StatusInfoOn := Assigned(fOnStatusInfo);
    //PasswordRoutineOn := Assigned(fOnGetPassword);
    fMethod :=  SSLOptions.Method;
    fMode := SSLOptions.Mode;
    fSSLContext.InitContext(sslCtxServer);
  end;
end;

function TIdServerIOHandlerSSLOpenSSL.Accept(ASocket: TIdSocketHandle;
  // This is a thread and not a yarn. Its the listener thread.
  AListenerThread: TIdThread; AYarn: TIdYarn ): TIdIOHandler;
var
  LIO: TIdSSLIOHandlerSocketOpenSSL;
begin
  Assert(ASocket<>nil);
  Assert(fSSLContext<>nil);
  LIO := TIdSSLIOHandlerSocketOpenSSL.Create(nil);
  LIO.PassThrough := True;
  LIO.Open;
  if LIO.Binding.Accept(ASocket.Handle) then begin
    //we need to pass the SSLOptions for the socket from the server
    FreeAndNil(LIO.fxSSLOptions);
    LIO.IsPeer := True;
    LIO.fxSSLOptions := fxSSLOptions;
    LIO.fSSLSocket := TIdSSLSocket.Create(self);
    LIO.fSSLContext := fSSLContext;
  end else begin
    FreeAndNil(LIO);
  end;
  Result := LIO;
end;

procedure TIdServerIOHandlerSSLOpenSSL.DoStatusInfo(const AMsg: String);
begin
  if Assigned(fOnStatusInfo) then begin
    fOnStatusInfo(AMsg);
  end;
end;

procedure TIdServerIOHandlerSSLOpenSSL.DoGetPassword(var Password: AnsiString);
begin
  if Assigned(fOnGetPassword) then  begin
    fOnGetPassword(Password);
  end;
end;

function TIdServerIOHandlerSSLOpenSSL.DoVerifyPeer(Certificate: TIdX509;
  AOk: Boolean; ADepth: Integer): Boolean;
begin
  Result := True;
  if Assigned(fOnVerifyPeer) then begin
    Result := fOnVerifyPeer(Certificate, AOk, ADepth);
  end;
end;

function TIdServerIOHandlerSSLOpenSSL.MakeFTPSvrPort : TIdSSLIOHandlerSocketBase;
var
  LIO : TIdSSLIOHandlerSocketOpenSSL;
begin
  LIO := TIdSSLIOHandlerSocketOpenSSL.Create(nil);
  LIO.PassThrough := True;
  LIO.OnGetPassword := DoGetPassword;
  //todo memleak here - setting IsPeer causes SSLOptions to not free
  LIO.IsPeer := True;
  LIO.SSLOptions.Assign(SSLOptions);
  LIO.SSLOptions.Mode := sslmBoth;{doesn't really matter}
  LIO.SSLContext := SSLContext;
  Result := LIO;
end;

procedure TIdServerIOHandlerSSLOpenSSL.Shutdown;
begin
  FreeAndNil(fSSLContext);
  inherited Shutdown;
end;

function TIdServerIOHandlerSSLOpenSSL.MakeFTPSvrPasv : TIdSSLIOHandlerSocketBase;
var
  LIO : TIdSSLIOHandlerSocketOpenSSL;
begin
  LIO := TIdSSLIOHandlerSocketOpenSSL.Create(nil);
  LIO.PassThrough := True;
  LIO.OnGetPassword := DoGetPassword;
  //todo memleak here - setting IsPeer causes SSLOptions to not free
  LIO.IsPeer := True;
  LIO.SSLOptions.Assign(SSLOptions);
  LIO.SSLOptions.Mode := sslmBoth;{or sslmServer}
  LIO.SSLContext := nil;
  Result := LIO;
end;

///////////////////////////////////////////////////////
//   TIdSSLIOHandlerSocketOpenSSL
///////////////////////////////////////////////////////

function TIdServerIOHandlerSSLOpenSSL.MakeClientIOHandler: TIdSSLIOHandlerSocketBase;
var
  LIO : TIdSSLIOHandlerSocketOpenSSL;
begin
  LIO := TIdSSLIOHandlerSocketOpenSSL.Create(nil);
  LIO.PassThrough := True;
//  LIO.SSLOptions.Free;
//  LIO.SSLOptions := SSLOptions;
//  LIO.SSLContext := SSLContext;
  LIO.SSLOptions.Assign(SSLOptions);
//  LIO.SSLContext := SSLContext;
  LIO.SSLContext := nil;//SSLContext.Clone; // BGO: clone does not work, it must be either NIL, or SSLContext
  LIO.OnGetPassword := DoGetPassword;
  Result := LIO;
end;

{ TIdSSLIOHandlerSocketOpenSSL }

procedure TIdSSLIOHandlerSocketOpenSSL.InitComponent;
begin
  inherited;
  IsPeer := False;
  fxSSLOptions := TIdSSLOptions.Create;
  fSSLLayerClosed := True;
  fSSLContext := nil;
end;

destructor TIdSSLIOHandlerSocketOpenSSL.Destroy;
begin
  FreeAndNil(fSSLSocket);
  if not IsPeer then begin
    //we do not destroy these in IsPeer equals true
    //because these do not belong to us when we are in a server.
    FreeAndNil(fSSLContext);
    FreeAndNil(fxSSLOptions);
  end;
  inherited Destroy;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.ConnectClient;
var
  LPassThrough: Boolean;
begin
  // RLebeau 1/11/07: In case a proxy is being used, pass through
  // any data from the base class unencrypted when setting up that
  // connection.  We should do this anyway since SSL hasn't been
  // initialized yet!
  LPassThrough := fPassThrough;
  fPassThrough := True;
  try
    inherited ConnectClient;
  finally
    fPassThrough := LPassThrough;
  end;
  DoBeforeConnect(Self);
  // CreateSSLContext(sslmClient);
  // CreateSSLContext(SSLOptions.fMode);
  StartSSL;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.StartSSL;
begin
  try
    Init;
  except
    on EIdOSSLCouldNotLoadSSLLibrary do begin
      if not PassThrough then raise;
    end;
  end;
  if not PassThrough then begin
    OpenEncodedConnection;
  end;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.Close;
begin
  FreeAndNil(fSSLSocket);
  if not IsPeer then begin
    FreeAndNil(fSSLContext);
  end;
  inherited Close;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.Open;
begin
  FOpened := False;
  inherited Open;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.SetPassThrough(const Value: Boolean);
begin
  if fPassThrough <> Value then begin
    if not Value then begin
      if BindingAllocated then begin
        if Assigned(fSSLContext) then begin
          OpenEncodedConnection;
        end else begin
          raise EIdOSSLCouldNotLoadSSLLibrary.Create(RSOSSLCouldNotLoadSSLLibrary);
        end;
      end;
      {$IFDEF WIN32_OR_WIN64}
      // begin bug fix
      end
      else if BindingAllocated and (Win32MajorVersion >= 6) then
      begin
        // disables Vista+ SSL_Read and SSL_Write timeout fix
        Binding.SetSockOpt(Id_SOL_SOCKET, Id_SO_RCVTIMEO, 0);
        Binding.SetSockOpt(Id_SOL_SOCKET, Id_SO_SNDTIMEO, 0);
      // end bug fix
      {$ENDIF}
    end;
    fPassThrough := Value;
  end;
end;

function TIdSSLIOHandlerSocketOpenSSL.RecvEnc(var VBuffer: TIdBytes): Integer;
begin
  Result := fSSLSocket.Recv(VBuffer);
end;

function TIdSSLIOHandlerSocketOpenSSL.SendEnc(const ABuffer: TIdBytes;
  const AOffset, ALength: Integer): Integer;
begin
  Result := fSSLSocket.Send(ABuffer, AOffset, ALength);
end;

procedure TIdSSLIOHandlerSocketOpenSSL.AfterAccept;
begin
  try
    inherited AfterAccept;
    StartSSL;
  except
    Close;
    raise;
  end;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.Init;
//see also TIdServerIOHandlerSSLOpenSSL.Init
begin
  if not Assigned(fSSLContext) then begin
    fSSLContext := TIdSSLContext.Create;
    with fSSLContext do begin
      Parent := Self;
      {$IFDEF UNICODESTRING}
      // explicit convert to Ansi
      RootCertFile := AnsiString(SSLOptions.RootCertFile);
      CertFile := AnsiString(SSLOptions.CertFile);
      KeyFile := AnsiString(SSLOptions.KeyFile);
      {$ELSE}
      RootCertFile := SSLOptions.RootCertFile;
      CertFile := SSLOptions.CertFile;
      KeyFile := SSLOptions.KeyFile;
      {$ENDIF}
      fVerifyDepth := SSLOptions.fVerifyDepth;
      fVerifyMode := SSLOptions.fVerifyMode;
      // fVerifyFile := SSLOptions.fVerifyFile;
      fVerifyDirs := String(SSLOptions.fVerifyDirs);
      fCipherList := AnsiString(SSLOptions.fCipherList);
      VerifyOn := Assigned(fOnVerifyPeer);
      StatusInfoOn := Assigned(fOnStatusInfo);
      //PasswordRoutineOn := Assigned(fOnGetPassword);
      fMethod :=  SSLOptions.Method;
      fMode := SSLOptions.Mode;
      fSSLContext.InitContext(sslCtxClient);
    end;
  end;
end;
//}

procedure TIdSSLIOHandlerSocketOpenSSL.DoStatusInfo(const AMsg: String);
begin
  if Assigned(fOnStatusInfo) then begin
    fOnStatusInfo(AMsg);
  end;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.DoGetPassword(var Password: AnsiString);
begin
  if Assigned(fOnGetPassword) then begin
    fOnGetPassword(Password);
  end;
end;

function TIdSSLIOHandlerSocketOpenSSL.DoVerifyPeer(Certificate: TIdX509;
  AOk: Boolean; ADepth: Integer): Boolean;
begin
  Result := True;
  if Assigned(fOnVerifyPeer) then begin
    Result := fOnVerifyPeer(Certificate, AOk, ADepth);
  end;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.OpenEncodedConnection;
begin
  Assert(Binding<>nil);
  if not Assigned(fSSLSocket) then begin
    fSSLSocket := TIdSSLSocket.Create(Self);
  end;
  Assert(fSSLSocket.fSSLContext=nil);
  fSSLSocket.fSSLContext := fSSLContext;
  {$IFDEF WIN32_OR_WIN64}
    // begin bug fix
    if Win32MajorVersion >= 6 then
    begin
      // Note: Fix needed to allow SSL_Read and SSL_Write to timeout under
      // Vista+ when connection is dropped
      Binding.SetSockOpt(Id_SOL_SOCKET, Id_SO_RCVTIMEO, FReadTimeOut);
      Binding.SetSockOpt(Id_SOL_SOCKET, Id_SO_SNDTIMEO, FReadTimeOut);
    end;
    // end bug fix
  {$ENDIF}
  if IsPeer then begin
    fSSLSocket.Accept(Binding.Handle);
  end else begin
    fSSLSocket.Connect(Binding.Handle);
  end;
  fPassThrough := False;
end;

procedure TIdSSLIOHandlerSocketOpenSSL.DoBeforeConnect(ASender: TIdSSLIOHandlerSocketOpenSSL);
begin
  if Assigned(OnBeforeConnect) then begin
    OnBeforeConnect(Self);
  end;
end;

function TIdSSLIOHandlerSocketOpenSSL.Clone: TIdSSLIOHandlerSocketBase;
var
  LIO : TIdSSLIOHandlerSocketOpenSSL;
begin
  LIO := TIdSSLIOHandlerSocketOpenSSL.Create(nil);
  LIO.SSLOptions.Assign( SSLOptions );
  LIO.OnStatusInfo := DoStatusInfo;
  LIO.OnGetPassword := DoGetPassword;
  LIO.OnVerifyPeer := DoVerifyPeer;
  Result := LIO;
end;

{ TIdSSLContext }

constructor TIdSSLContext.Create;
begin
  inherited Create;
  //an exception here probably means that you are using the wrong version
  //of the openssl libraries. refer to comments at the top of this file.
  if not IdSSLOpenSSL.LoadOpenSSLLibrary then begin
    raise EIdOSSLCouldNotLoadSSLLibrary.Create(RSOSSLCouldNotLoadSSLLibrary);
  end;
  fVerifyMode := [];
  fMode := sslmUnassigned;
  fSessionId := 1;
end;

destructor TIdSSLContext.Destroy;
begin
  DestroyContext;
  inherited Destroy;
end;

procedure TIdSSLContext.DestroyContext;
begin
  if fContext <> nil then begin
    IdSslCtxFree(fContext);
    fContext := nil;
  end;
end;

procedure TIdSSLContext.InitContext(CtxMode: TIdSSLCtxMode);
var
  SSLMethod: PSSL_METHOD;
  error: TIdC_INT;
//  pCAname: PSTACK_X509_NAME;

begin
  // Destroy the context first
  DestroyContext;
  if fMode = sslmUnassigned then begin
    if CtxMode = sslCtxServer then begin
      fMode := sslmServer;
    end else begin
      fMode := sslmClient;
    end
  end;
  // get SSL method function (SSL2, SSL23, SSL3, TLS)
  SSLMethod := SetSSLMethod;
  // create new SSL context
  fContext := IdSslCtxNew(SSLMethod);
  if fContext = nil then begin
    raise EIdOSSLCreatingContextError.Create(RSSSLCreatingContextError);
  end;
  IdSslCtxSetMode(fContext,OPENSSL_SSL_MODE_AUTO_RETRY);
  // assign a password lookup routine
//  if PasswordRoutineOn then begin
    IdSslCtxSetDefaultPasswdCb(fContext, @PasswordCallback);
    IdSslCtxSetDefaultPasswdCbUserdata(fContext, Self);
//  end;
  IdSSLCtxSetDefaultVerifyPaths(fContext);
  // load key and certificate files
  if RootCertFile <> '' then begin    {Do not Localize}
    if not LoadRootCert then begin
       EIdOSSLLoadingRootCertError.RaiseException(RSSSLLoadingRootCertError);
    end;
  end;
  if CertFile <> '' then begin    {Do not Localize}
    if not LoadCert then begin
      EIdOSSLLoadingCertError.RaiseException(RSSSLLoadingCertError);
    end;
  end;
  if KeyFile <> '' then begin    {Do not Localize}
    if not LoadKey then begin
      EIdOSSLLoadingKeyError.RaiseException(RSSSLLoadingKeyError);
    end;
  end;
  if StatusInfoOn then begin
    IdSslCtxSetInfoCallback(fContext, InfoCallback);
  end;
  //if_SSL_CTX_set_tmp_rsa_callback(hSSLContext, @RSACallback);
  if fCipherList <> '' then begin    {Do not Localize}
    error := IdSslCtxSetCipherList(fContext, PAnsiChar(fCipherList));
  end
  else begin
    error := IdSslCtxSetCipherList(fContext, OPENSSL_SSL_DEFAULT_CIPHER_LIST);
  end;
  if error <= 0 then begin
    EIdOSSLLoadingKeyError.RaiseException(RSSSLSettingCipherError);
  end;
  if fVerifyMode <> [] then begin
    SetVerifyMode(fVerifyMode, VerifyOn);
  end;
  if CtxMode = sslCtxServer then begin
    IdSSLCtxSetSessionIdContext(fContext, PByte(@fSessionId), SizeOf(fSessionId));
  end;
  // CA list
  if RootCertFile <> '' then begin    {Do not Localize}
    IdSSLCtxSetClientCAList(fContext, IdSSLLoadClientCAFile(PAnsiChar(RootCertFile)));
  end
end;

procedure TIdSSLContext.SetVerifyMode(Mode: TIdSSLVerifyModeSet; CheckRoutine: Boolean);
var
  Func: TSSL_CTX_set_verify_callback;
begin
  if fContext<>nil then begin
//    IdSSLCtxSetDefaultVerifyPaths(fContext);
    if CheckRoutine then begin
      Func := VerifyCallback;
    end else begin
      Func := nil;
    end;
    IdSslCtxSetVerify(fContext, TranslateInternalVerifyToSSL(Mode), Func);
    IdSslCtxSetVerifyDepth(fContext, fVerifyDepth);
  end;
end;

function TIdSSLContext.GetVerifyMode: TIdSSLVerifyModeSet;
begin
  Result := fVerifyMode;
end;
{
function TIdSSLContext.LoadVerifyLocations(FileName: String; Dirs: String): Boolean;
begin
  Result := False;

  if (Dirs <> '') or (FileName <> '') then begin
    if IdSslCtxLoadVerifyLocations(fContext, PAnsiChar(FileName), PAnsiChar(Dirs)) <= 0 then begin
      raise EIdOSSLCouldNotLoadSSLLibrary.Create(RSOSSLCouldNotLoadSSLLibrary);
    end;
  end;

  Result := True;
end;
}
function TIdSSLContext.SetSSLMethod: PSSL_METHOD;
begin
  if fMode = sslmUnassigned then begin
    raise EIdOSSLModeNotSet.create(RSOSSLModeNotSet);
  end;
  case fMethod of
    sslvSSLv2:
      case fMode of
        sslmServer : Result := IdSslMethodServerV2;
        sslmClient : Result := IdSslMethodClientV2;
        sslmBoth   : Result := IdSslMethodV2;
      else
        Result := IdSslMethodV2;
      end;
    sslvSSLv23:
      case fMode of
        sslmServer : Result := IdSslMethodServerV23;
        sslmClient : Result := IdSslMethodClientV23;
        sslmBoth   : Result := IdSslMethodV23;
      else
        Result := IdSslMethodV23;
      end;
    sslvSSLv3:
      case fMode of
        sslmServer : Result := IdSslMethodServerV3;
        sslmClient : Result := IdSslMethodClientV3;
        sslmBoth   : Result := IdSslMethodV3;
      else
        Result := IdSslMethodV3;
      end;
    sslvTLSv1:
      case fMode of
        sslmServer : Result := IdSslMethodServerTLSV1;
        sslmClient : Result := IdSslMethodClientTLSV1;
        sslmBoth   : Result := IdSslMethodTLSV1;
      else
        Result := IdSslMethodTLSV1;
      end;
  else
    raise EIdOSSLGetMethodError.Create(RSSSLGetMethodError);
  end;
end;

function TIdSSLContext.LoadRootCert: Boolean;
begin
{  if fVerifyDirs <> '' then begin
    Result := IdSslCtxLoadVerifyLocations(
                   fContext,
                   PAnsiChar(RootCertFile),
                   PAnsiChar(fVerifyDirs)) > 0;
  end
  else begin
}
    Result := IdSslCtxLoadVerifyLocations(
                   fContext,
                   PAnsiChar(RootCertFile),
                   nil) > 0;
{  end;}
end;

function TIdSSLContext.LoadCert: Boolean;
begin
  Result := IdSslCtxUseCertificateFile(
                 fContext,
                 PAnsiChar(CertFile),
                 OPENSSL_SSL_FILETYPE_PEM) > 0;
end;

function TIdSSLContext.LoadKey: Boolean;
begin
  Result := IdSslCtxUsePrivateKeyFile(
                 fContext,
                 PAnsiChar(fsKeyFile),
                 OPENSSL_SSL_FILETYPE_PEM) > 0;
  if Result then begin
    Result := IdSslCtxCheckPrivateKeyFile(fContext) > 0;
  end;
end;

//////////////////////////////////////////////////////////////

function TIdSSLContext.Clone: TIdSSLContext;
begin
  Result := TIdSSLContext.Create;
  Result.StatusInfoOn := StatusInfoOn;
//    property PasswordRoutineOn: Boolean read fPasswordRoutineOn write fPasswordRoutineOn;
  Result.VerifyOn := VerifyOn;
  Result.Method := Method;
  Result.Mode := Mode;
  Result.RootCertFile := RootCertFile;
  Result.CertFile := CertFile;
  Result.KeyFile := KeyFile;
  Result.VerifyMode := VerifyMode;
  Result.VerifyDepth := VerifyDepth;
end;

{ TIdSSLSocket }

constructor TIdSSLSocket.Create(Parent: TObject);
begin
  inherited Create;
  fParent := Parent;
end;

destructor TIdSSLSocket.Destroy;
begin
  if fSSL <> nil then begin
    //IdSslSetShutdown(fSSL, OPENSSL_SSL_SENT_SHUTDOWN);
    IdSslShutdown(fSSL);
    IdSslFree(fSSL);
    fSSL := nil;
  end;
  FreeAndNil(fSSLCipher);
  FreeAndNil(fPeerCert);
  inherited Destroy;
end;

function TIdSSLSocket.GetSSLError(retCode: Integer): Integer;
begin
  // COMMENT!!!
  // I found out that SSL layer should not interpret errors, cause they will pop up
  // on the socket layer. Only thing that the SSL layer should consider is key
  // or protocol renegotiation. This is done by loop in read and write
  Result := IdSslGetError(fSSL, retCode);
  case Result of
    OPENSSL_SSL_ERROR_NONE:
      Result := OPENSSL_SSL_ERROR_NONE;
    OPENSSL_SSL_ERROR_WANT_WRITE:
      Result := OPENSSL_SSL_ERROR_WANT_WRITE;
    OPENSSL_SSL_ERROR_WANT_READ:
      Result := OPENSSL_SSL_ERROR_WANT_READ;
    OPENSSL_SSL_ERROR_ZERO_RETURN:
      Result := OPENSSL_SSL_ERROR_ZERO_RETURN;
      //Result := OPENSSL_SSL_ERROR_NONE;
      {
      // ssl layer has been disconnected, it is not necessary that also
      // socked has been closed
      case Mode of
        sslemClient: begin
          case Action of
            sslWrite: begin
              if retCode = 0 then begin
                Result := 0;
              end
              else begin
                raise EIdException.Create(RSOSSLConnectionDropped);
              end;
            end;
        end;
      end;}

        //raise EIdException.Create(RSOSSLConnectionDropped);
      // X509_LOOKUP event is not really an error, just an event
    // OPENSSL_SSL_ERROR_WANT_X509_LOOKUP:
        // raise EIdException.Create(RSOSSLCertificateLookup);
    OPENSSL_SSL_ERROR_SYSCALL:
      Result := OPENSSL_SSL_ERROR_SYSCALL;
      // Result := OPENSSL_SSL_ERROR_NONE;

        {//raise EIdException.Create(RSOSSLInternal);
        if (retCode <> 0) or (DataLen <> 0) then begin
          raise EIdException.Create(RSOSSLConnectionDropped);
        end
        else begin
          Result := 0;
        end;}

    OPENSSL_SSL_ERROR_SSL:
      // raise EIdException.Create(RSOSSLInternal);
      Result := OPENSSL_SSL_ERROR_SSL;
      // Result := OPENSSL_SSL_ERROR_NONE;
  end;
end;

procedure TIdSSLSocket.Accept(const pHandle: TIdStackSocketHandle);
//Accept and Connect have a lot of duplicated code
var
  error: Integer;
  StatusStr: String;
begin
  Assert(fSSL=nil);
  Assert(fSSLContext<>nil);
  fSSL := IdSslNew(fSSLContext.fContext);
  if fSSL = nil then exit;
  error := IdSslSetAppData(fSSL, Self);
  if error <= 0 then begin
    EIdOSSLDataBindingError.RaiseException(fSSL, error, RSSSLDataBindingError);
    Exit;
  end;
  IdSslSetFd(fSSL, pHandle);
  error := IdSslAccept(fSSL);
  if error <= 0 then begin
    EIdOSSLAcceptError.RaiseException(fSSL, error, RSSSLAcceptError);
  end;
  StatusStr := 'Cipher: name = ' + Cipher.Name + '; ' +    {Do not Localize}
               'description = ' + Cipher.Description + '; ' +    {Do not Localize}
               'bits = ' + IntToStr(Cipher.Bits) + '; ' +    {Do not Localize}
               'version = ' + Cipher.Version + '; ';    {Do not Localize}
  if fParent is TIdServerIOHandlerSSLOpenSSL then begin
    (fParent as TIdServerIOHandlerSSLOpenSSL).DoStatusInfo(StatusStr);
  end;
end;

procedure TIdSSLSocket.Connect(const pHandle: TIdStackSocketHandle);
var
  error: Integer;
  StatusStr: String;
begin
  Assert(fSSL=nil);
  Assert(fSSLContext<>nil);
  fSSL := IdSslNew(fSSLContext.fContext);
  if fSSL = nil then begin
    exit;
  end;
  error := IdSslSetAppData(fSSL, Self);
  if error <= 0 then begin
    EIdOSSLDataBindingError.RaiseException(fSSL, error, RSSSLDataBindingError);
  end;
  error :=  IdSslSetFd(fSSL, pHandle);
  if error <= 0 then begin
    EIdOSSLFDSetError.RaiseException(fSSL, error, RSSSLFDSetError);
  end;
  error := IdSslConnect(fSSL);
  if error <= 0 then begin
    EIdOSSLConnectError.RaiseException(fSSL, error, RSSSLConnectError);
  end;
  StatusStr := 'Cipher: name = ' + Cipher.Name + '; ' +    {Do not Localize}
               'description = ' + Cipher.Description + '; ' +    {Do not Localize}
               'bits = ' + IntToStr(Cipher.Bits) + '; ' +    {Do not Localize}
               'version = ' + Cipher.Version + '; ';    {Do not Localize}
  if fParent is TIdSSLIOHandlerSocketOpenSSL then begin
    (fParent as TIdSSLIOHandlerSocketOpenSSL).DoStatusInfo(StatusStr);
  end;
end;

function TIdSSLSocket.Recv(var ABuffer: TIdBytes): Integer;
var
  err: Integer;
begin
  repeat
    err := IdSslRead(fSSL, @ABuffer[0], Length(ABuffer));
    if err > 0 then begin
      Result := err;
      Exit;
    end;
    err := GetSSLError(err);
    if (err = OPENSSL_SSL_ERROR_WANT_READ) or (err = OPENSSL_SSL_ERROR_WANT_WRITE) then begin
      Continue;
    end;
    if err = OPENSSL_SSL_ERROR_ZERO_RETURN then begin
      Result := 0;
    end else begin
      Result := -1;
    end;
    Exit;
  until False;
end;

function TIdSSLSocket.Send(const ABuffer: TIdBytes; AOffset, ALength: Integer): Integer;
var
  err: Integer;
begin
  Result := 0;
  repeat
    err := IdSslWrite(fSSL, @ABuffer[AOffset], ALength);
    if err < 1 then begin
      err := GetSSLError(err);
      if (err = OPENSSL_SSL_ERROR_WANT_READ) or (err = OPENSSL_SSL_ERROR_WANT_WRITE) then begin
        Continue;
      end;
      if err = OPENSSL_SSL_ERROR_ZERO_RETURN then begin
        Result := 0;
      end else begin
        Result := -1;
      end;
      Exit;
    end;
    Inc(Result, err);
    Inc(AOffset, err);
    Dec(ALength, err);
  until ALength < 1;
end;

function TIdSSLSocket.GetPeerCert: TIdX509;
var
  LX509: PX509;
begin
  if fPeerCert = nil then begin
    LX509 := IdSslGetPeerCertificate(fSSL);
    if LX509 <> nil then begin
      fPeerCert := TIdX509.Create(LX509, False);
    end;
  end;
  Result := fPeerCert;
end;

function TIdSSLSocket.GetSSLCipher: TIdSSLCipher;
begin
  if (fSSLCipher = nil) and (fSSL<>nil) then begin
    fSSLCipher := TIdSSLCipher.Create(Self);
  end;
  Result := fSSLCipher;
end;

function TIdSSLSocket.GetSessionID: TByteArray;
var
  pSession: PSSL_SESSION;
  tmpArray: TByteArray;
begin
  Result.Length := 0;
  FillChar(tmpArray, SizeOf(TByteArray), 0);
  if Assigned(IdSslGetSession) then
  begin
    if fSSL<>nil then begin
      pSession := IdSslGetSession(fSSL);
      if pSession <> nil then begin
        IdSslSessionGetId(pSession, @tmpArray.Data, @tmpArray.Length);
        Result := tmpArray;
      end;
    end;
  end;
end;

function  TIdSSLSocket.GetSessionIDAsString:String;
var
  Data: TByteArray;
  i: Integer;
begin
  Result := '';    {Do not Localize}
  Data := GetSessionID;
  for i := 0 to Data.Length-1 do begin
    Result := Result+IndyFormat('%.2x', [Byte(Data.Data[I])]);{do not localize}
  end;
end;

procedure TIdSSLSocket.SetCipherList(CipherList: String);
//var
//  tmpPStr: PAnsiChar;
begin
{
  fCipherList := CipherList;
  fCipherList_Ch := True;
  aCipherList := aCipherList+#0;
  if hSSL <> nil then f_SSL_set_cipher_list(hSSL, @aCipherList[1]);
}
end;

///////////////////////////////////////////////////////////////
//  X509 Certificate
///////////////////////////////////////////////////////////////

{ TIdX509Name }

function TIdX509Name.CertInOneLine: String;
var
  LOneLine: array[0..2048] of AnsiChar;
begin
  if FX509Name = nil then begin
    Result := '';    {Do not Localize}
  end
  else begin
    Result := String(StrPas(IdSslX509NameOneline(FX509Name, PAnsiChar(@LOneLine), SizeOf(LOneLine))));
  end;
end;

function TIdX509Name.GetHash: TULong;
begin
  if FX509Name = nil then begin
    FillChar(Result, SizeOf(Result), 0)
  end
  else begin
    Result.C1 := IdSslX509NameHash(FX509Name);
  end;
end;

function TIdX509Name.GetHashAsString: String;
begin
  Result := IndyFormat('%.8x', [Hash.L1]); {do not localize}
end;

constructor TIdX509Name.Create(aX509Name: PX509_NAME);
begin
  Inherited Create;
  FX509Name := aX509Name;
end;


///////////////////////////////////////////////////////////////
//  X509 Certificate
///////////////////////////////////////////////////////////////

{ TIdX509Info }

constructor TIdX509Info.Create(aX509: PX509);
begin
  inherited Create;
  Self.FX509 :=  aX509;
end;

{ TIdX509Fingerprints }

function TIdX509Fingerprints.GetMD5: TEVP_MD;
begin
   IdSslX509Digest(FX509, IdSslEvpMd5, PByte(@Result.MD), Result.Length);
end;

function TIdX509Fingerprints.GetMD5AsString: String;
begin
  Result := MDAsString(MD5);
end;

function TIdX509Fingerprints.GetSHA1: TEVP_MD;
begin
  IdSslX509Digest(FX509, IdSslEvpSHA1, PByte(@Result.MD), Result.Length);
end;

function TIdX509Fingerprints.GetSHA1AsString: String;
begin
  Result := MDAsString(SHA1);
end;

function TIdX509Fingerprints.GetSHA224 : TEVP_MD;
begin
  if Assigned(IdSslEvpSHA224) then begin
    IdSslX509Digest(FX509, IdSslEvpSHA224, PByte(@Result.MD), Result.Length);
  end else begin
    FillChar(Result, SizeOf(Result), 0);
  end;
end;

function TIdX509Fingerprints.GetSHA224AsString : String;
begin
  if Assigned(IdSslEvpSHA224) then begin
    Result := MDAsString(SHA224);
  end else begin
    Result := '';
  end;
end;

function TIdX509Fingerprints.GetSHA256 : TEVP_MD;
begin
  if Assigned(IdSslEvpSHA256) then begin
    IdSslX509Digest(FX509, IdSslEvpSHA256, PByte(@Result.MD), Result.Length);
  end else begin
    FillChar(Result, SizeOf(Result), 0);
  end;
end;

function TIdX509Fingerprints.GetSHA256AsString : String;
begin
  if Assigned(IdSslEvpSHA256) then begin
    Result := MDAsString(SHA256);
  end else begin
    Result := '';
  end;
end;

function TIdX509Fingerprints.GetSHA386 : TEVP_MD;
begin
  if Assigned(IdSslEvpSHA386) then begin
    IdSslX509Digest(FX509, IdSslEvpSHA386, PByte(@Result.MD), Result.Length);
  end else begin
    FillChar(Result, SizeOf(Result), 0);
  end;
end;

function TIdX509Fingerprints.GetSHA386AsString : String;
begin
  if Assigned(IdSslEvpSHA386) then begin
    Result := MDAsString(SHA386);
  end else begin
    Result := '';
  end;
end;

function TIdX509Fingerprints.GetSHA512 : TEVP_MD;
begin
  if Assigned(IdSslEvpSHA512) then begin
    IdSslX509Digest(FX509, IdSslEvpSHA512, PByte(@Result.MD), Result.Length);
  end else begin
    FillChar(Result, SizeOf(Result), 0);
  end;
end;

function TIdX509Fingerprints.GetSHA512AsString : String;
begin
  if Assigned(IdSslEvpSHA512) then begin
    Result := MDAsString(SHA512);
  end else begin
    Result := '';
  end;
end;

{ TIdX509SigInfo }

function TIdX509SigInfo.GetSignature: String;
begin
  Result := BytesToHexString(FX509^.signature^.data, FX509^.signature^.length);
end;

function TIdX509SigInfo.GetSigType: TIdC_INT;
begin
  Result := IdSslX509GetSignatureType(FX509);
end;

function TIdX509SigInfo.GetSigTypeAsString: String;
begin
  Result := String(IdSslOBJNid2ln(SigType));
end;

{ TIdX509 }

constructor TIdX509.Create(aX509: PX509; aCanFreeX509: Boolean = True);
begin
  inherited Create;
  //don't create FDisplayInfo unless specifically requested.
  FDisplayInfo := nil;
  FX509 := aX509;
  FCanFreeX509 := aCanFreeX509;
  FFingerprints := TIdX509Fingerprints.Create(FX509);
  FSigInfo := TIdX509SigInfo.Create(FX509);
  FSubject := nil;
  FIssuer := nil;
end;

destructor TIdX509.Destroy;
begin
  FreeAndNil(FDisplayInfo);
  FreeAndNil(FSubject);
  FreeAndNil(FIssuer);
  { If the X.509 certificate handle was obtained from a certificate
  store or from the SSL connection as a peer certificate, then DO NOT
  free it here!  The memory is owned by the OpenSSL library and will
  crash the library if Indy tries to free its private memory here }
  if FCanFreeX509 then begin
    IdSslX509Free(FX509);
  end;
  inherited Destroy;
end;

procedure DumpCert(AOut : TStrings; AX509 : PX509);
  {$IFDEF USEINLINE} inline; {$ENDIF}
  {$IFNDEF OPENSSL_NO_BIO}
var LMem : pBIO;
  LBuf,s : AnsiString;
  LRes : TIdC_INT;
const
  LBUF_LEN = 1024;
begin
  LMem := IdSslBioNew(IdSslBioSMem);
  try
     if Assigned(IdSslX509Print) then begin
       IdSslX509Print(LMem,AX509);
       s := '';
       SetLength(LBuf,LBUF_LEN);
       repeat
         LRes := IdSslBioRead(LMem,@LBuf[1],LBUF_LEN);
         if LRes < 1 then begin
           Break;
         end;
         //do this indirectly because OpenSSL will format the output.
         s := s + Copy(LBuf,1,LRes);
       until False;
       AOut.Text := String(s);
     end;
  finally
    IdSslBioFree(LMem);
  end;
end;
{$ELSE}
begin
end;
{$ENDIF}

function TIdX509.GetDisplayInfo: TStrings;
begin
  if not Assigned(FDisplayInfo) then begin
    FDisplayInfo := TStringList.Create;
    DumpCert(FDisplayInfo, FX509);
  end;
  Result := FDisplayInfo;
end;

function TIdX509.GetSerialNumber: String;
var
  LSN : PASN1_INTEGER;
begin
  if FX509 <> nil then begin
    LSN := IdSslX509GetSerialNumber(FX509);
    Result := BytesToHexString(LSN.data, LSN.length);
  end else begin
    Result := '';
  end;
end;

function TIdX509.GetVersion : TIdC_LONG;
begin
  Result := IdSslX509GetVersion(FX509);
end;

function TIdX509.RSubject: TIdX509Name;
var
  Lx509_name: PX509_NAME;
Begin
  if not Assigned(FSubject) then begin
    if FX509 <> nil then begin
      Lx509_name := IdSslX509GetSubjectName(FX509);
    end else begin
      Lx509_name := nil;
    end;
    FSubject := TIdX509Name.Create(Lx509_name);
  end;
  Result := FSubject;
end;

function TIdX509.RIssuer: TIdX509Name;
var
  Lx509_name: PX509_NAME;
begin
  if not Assigned(FIssuer) then begin
    if FX509 <> nil then begin
      Lx509_name := IdSslX509GetIssuerName(FX509);
    end else begin
      Lx509_name := nil;
    end;
    FIssuer := TIdX509Name.Create(Lx509_name);
  End;
  Result := FIssuer;
end;

function TIdX509.RFingerprint: TEVP_MD;
begin
  IdSslX509Digest(FX509, IdSslEvpMd5, PByte(@Result.MD), Result.Length);
end;

function TIdX509.RFingerprintAsString: String;
begin
  Result := MDAsString(Fingerprint);
end;

function TIdX509.RnotBefore: TDateTime;
begin
  if FX509 = nil then begin
    Result := 0
  end else begin                                    
    //This is a safe typecast since PASN1_UTCTIME and PASN1_TIME are really
    //pointers to ASN1 strings since ASN1_UTCTIME amd ASM1_TIME are ASN1_STRING.
    Result := UTCTime2DateTime(PASN1_UTCTIME(IdSslX509GetNotBefore(FX509)));
  end;
end;

function TIdX509.RnotAfter:TDateTime;
begin
  if FX509 = nil then begin
    Result := 0
  end else begin
    Result := UTCTime2DateTime(PASN1_UTCTIME(IdSslX509GetNotAfter(FX509)));
  end;
end;

///////////////////////////////////////////////////////////////
//  TIdSSLCipher
///////////////////////////////////////////////////////////////
constructor TIdSSLCipher.Create(AOwner: TIdSSLSocket);
begin
  inherited Create;
  FSSLSocket := AOwner;
end;

destructor TIdSSLCipher.Destroy;
begin
  inherited Destroy;
end;

function TIdSSLCipher.GetDescription;
var
  Buf: Array[0..1024] of AnsiChar;
begin
  Result := String(StrPas(IdSSLCipherDescription(IdSSLGetCurrentCipher(FSSLSocket.fSSL), PAnsiChar(@Buf[0]), SizeOf(Buf)-1)));
end;

function TIdSSLCipher.GetName:String;
begin
  Result := String(StrPas(IdSSLCipherGetName(IdSSLGetCurrentCipher(FSSLSocket.fSSL))));
end;

function TIdSSLCipher.GetBits:TIdC_INT;
begin
  IdSSLCipherGetBits(IdSSLGetCurrentCipher(FSSLSocket.fSSL), Result);
end;

function TIdSSLCipher.GetVersion:String;
begin
  Result := String(StrPas(IdSSLCipherGetVersion(IdSSLGetCurrentCipher(FSSLSocket.fSSL))));
end;

initialization
  RegisterSSL('OpenSSL','Indy Pit Crew',                                  {do not localize}
    'Copyright '+Char(169)+' 1993 - 2009'#10#13 +                                     {do not localize}
    'Chad Z. Hower (Kudzu) and the Indy Pit Crew. All rights reserved.',  {do not localize}
    'Open SSL Support DLL Delphi and C++Builder interface',               {do not localize}
    'http://www.indyproject.org/'#10#13 +                                 {do not localize}
    'Original Author - Gregor Ibic',                                        {do not localize}
    TIdSSLIOHandlerSocketOpenSSL,
    TIdServerIOHandlerSSLOpenSSL);
  Assert(SSLIsLoaded=nil);
  SSLIsLoaded := TIdThreadSafeBoolean.Create;
finalization
  UnLoadOpenSSLLibrary;
  //free the lock last as unload makes calls that use it
  FreeAndNil(SSLIsLoaded);

end.
