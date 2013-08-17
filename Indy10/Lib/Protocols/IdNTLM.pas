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
  Rev 1.1    6/29/04 12:51:10 PM  RLebeau
  Updatd SetupLanManagerPassword() to check the password length before
  referencing the password data

  Rev 1.0    11/13/2002 07:58:08 AM  JPMugaas

  S.G. 12/7/2002:
    - Rewrote Type 1 and Type 2 structures to be closer to the
                    document referenced in the above URL. (Easier to read and check)
                  - Corrected falgs accouring to bug ID 577895 and own packet traces.
                    This was actually only an adjustment to the new data types when
                    I rewrote the header.
                  - Initialized structures to #0 before using.
}
{
  Implementation of the NTLM authentication as specified in
  http://www.innovation.ch/java/ntlm.html with some fixes
                  
  Author: Doychin Bondzhev (doychin@dsoft-bg.com)
  Copyright: (c) Chad Z. Hower and The Winshoes Working Group.
}

unit IdNTLM;

interface

{$i IdCompilerDefines.inc}

uses
  IdGlobal,
  IdStruct
  {$IFNDEF DOTNET}, IdSSLOpenSSLHeaders{$ENDIF};

type
  {$IFDEF DOTNET}
  ProtocolArray = array [1..8] of Char;
  padArray2 = array[0..1] of Byte;
  padArray3 = Array[0..2] of Byte;
  padArray7 = Array[0..6] of Byte;
  padArray8 = Array[0..7] of Byte;
  nonceArray = Array[1..8] of Char;

  ntlm_base = class(TIdStruct)
  protected
    fprotocol : ProtocolArray;
    function GetBytesLen: LongWord; override;
  public
    procedure ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord); override;
    procedure WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);  override;

    property protocol: ProtocolArray read fprotocol write fprotocol; // array [1..8] of Char;     // 'N', 'T', 'L', 'M', 'S', 'S', 'P', '\0'    {Do not Localize}
  end;

  type_1_message_header = class(ntlm_base)
  protected
    f_type : Byte;
    fpad : padArray3;
    fflags : Word;
    fpad2 : padArray2;
    fdom_len1 : Word;
    fdom_len2 : Word;
    fdom_off : LongWord;
    fhost_len1 : Word;
    fhost_len2 : Word;
    fhost_off : LongWord;
    function GetBytesLen: LongWord; override;

  public
    procedure ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord); override;
    procedure WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);  override;

    property _type: Byte read f_type write f_type;                        // 0x01
    property pad  : padArray3 read fpad write fpad;  // 0x0
    property flags: Word read fflags write fflags;                        // 0xb203
    property pad2 : padArray2 read fpad2 write fpad2;  // 0x0
    property dom_len1: Word read fdom_len1 write fdom_len1;                     // domain string length
    property dom_len2: Word read fdom_len2 write fdom_len2;                     // domain string length
    property dom_off: LongWord read fdom_off write fdom_off;                  // domain string offset

    property host_len1: Word read fhost_len1 write fhost_len1;                    // host string length
    property host_len2: Word read fhost_len2 write fhost_len2;                    // host string length
    property host_off: LongWord read fhost_off write fhost_off;                 // host string offset (always 0x20)
  end;

  type_2_message_header = class(ntlm_base)
  protected
    f_type : Byte;
    fPad : padArray7;
    fmsg_len : Word;
    fPad2 : padArray2;
    fflags : Word;
    fPad3 : padArray2;
    fnonce : nonceArray;
    fpad4 : padArray8;
    function GetBytesLen: LongWord; override;
  public
    procedure ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord); override;
    procedure WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);  override;

    property _type: Byte read f_type write f_type;       // $2
    property Pad  : padArray7 read fPad write fPad; //packed Array[1..7] of byte;          // 0x0
    property msg_len: Word read fmsg_len write fmsg_len;                              // 0x28
    property Pad2 : padArray2 read fPad2 write fPad2;    // 0x0
    property flags: word read fflags write fflags;                                // 0x8201
    property Pad3: padArray2 read fPad3 write fPad3;          // 0x0
    property nonce: nonceArray read fnonce write fnonce;      // nonce
    property pad4: padArray8 read fpad4 write fpad4;            // 0x0
  end;

  type_3_message_header = class(ntlm_base)
  protected
    f_type: LongWord;
    flm_resp_len1: Word;
    flm_resp_len2: Word;
    flm_resp_off : LongWord;
    fnt_resp_len1: Word;
    fnt_resp_len2: Word;
    fnt_resp_off: LongWord;
    fdom_len1: Word;
    fdom_len2 : Word;
    fdom_off : LongWord;
    fuser_len1: Word;
    fuser_len2: Word;
    fuser_off: LongWord;
    fhost_len1: Word;
    fhost_len2: Word;
    fhost_off: LongWord;
    fzero: LongWord;
    fmsg_len: LongWord;
    fflags: LongWord;
    function GetBytesLen: LongWord; override;
  public
    procedure ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord); override;
    procedure WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);  override;

    property _type: LongWord read f_type write f_type;                    // 0x03

    property lm_resp_len1: Word read flm_resp_len1 write flm_resp_len1;                 // LanManager response length (always 0x18)
    property lm_resp_len2: Word read flm_resp_len2 write flm_resp_len2;                 // LanManager response length (always 0x18)
    property lm_resp_off: LongWord read flm_resp_off write flm_resp_off;              // LanManager response offset

    property nt_resp_len1: Word read fnt_resp_len1 write fnt_resp_len1;                 // NT response length (always 0x18)
    property nt_resp_len2: Word read fnt_resp_len2 write fnt_resp_len2;                 // NT response length (always 0x18)
    property nt_resp_off: LongWord read fnt_resp_off write fnt_resp_off;              // NT response offset

    property dom_len1: Word read fdom_len1 write fdom_len1;           // domain string length
    property dom_len2: Word read fdom_len2 write fdom_len2;           // domain string length
    property dom_off: LongWord read fdom_off write fdom_off;          // domain string offset (always 0x40)

    property user_len1: Word read fuser_len1 write fuser_len1;                    // username string length
    property user_len2: Word read fuser_len2 write fuser_len2;                    // username string length
    property user_off: LongWord read fuser_off write fuser_off;                 // username string offset

    property host_len1: Word read fhost_len1 write fhost_len1;                    // host string length
    property host_len2: Word read fhost_len2 write fhost_len2;                    // host string length
    property host_off: LongWord read fhost_off write fhost_off;                 // host string offset
    property zero: LongWord read fzero write fzero;

    property msg_len: LongWord read fmsg_len write fmsg_len;                  // message length

    property flags: LongWord read fflags write fflags;                    // 0xA0808205
  end;
{$ELSE}
  type_1_message_header = packed record
    protocol: array [1..8] of AnsiChar; // 'N', 'T', 'L', 'M', 'S', 'S', 'P', '\0'    {Do not Localize}
    _type: Byte;                        // 0x01
    pad  : packed Array[1..3] of Byte;  // 0x0
    flags: Word;                        // 0xb203
    pad2 : packed Array[1..2] of Byte;  // 0x0
    dom_len1: Word;                     // domain string length
    dom_len2: Word;                     // domain string length
    dom_off: LongWord;                  // domain string offset

    host_len1: Word;                    // host string length
    host_len2: Word;                    // host string length
    host_off: LongWord;                 // host string offset (always 0x20)
  end;

  type_2_message_header = packed record
    protocol: packed array [1..8] of AnsiChar;  // 'N', 'T', 'L', 'M', 'S', 'S', 'P', #0    {Do not Localize}
    _type: Byte;                                // $2
    Pad  : packed Array[1..7] of Byte;          // 0x0
    msg_len: Word;                              // 0x28
    Pad2 : packed Array [1..2] of Byte;         // 0x0
    flags: word;                                // 0x8201
    Pad3: Packed array [1..2] of Byte;          // 0x0
    nonce: Array[1..8] of char;                 // nonce
    pad4: packed Array[1..8] of Byte            // 0x0
  end;

  type_3_message_header = packed record
    protocol: array [1..8] of AnsiChar; // 'N', 'T', 'L', 'M', 'S', 'S', 'P', '\0'    {Do not Localize}
    _type: LongWord;                    // 0x03

    lm_resp_len1: Word;                 // LanManager response length (always 0x18)
    lm_resp_len2: Word;                 // LanManager response length (always 0x18)
    lm_resp_off: LongWord;              // LanManager response offset

    nt_resp_len1: Word;                 // NT response length (always 0x18)
    nt_resp_len2: Word;                 // NT response length (always 0x18)
    nt_resp_off: LongWord;              // NT response offset

    dom_len1: Word;                     // domain string length
    dom_len2: Word;                     // domain string length
    dom_off: LongWord;                  // domain string offset (always 0x40)

    user_len1: Word;                    // username string length
    user_len2: Word;                    // username string length
    user_off: LongWord;                 // username string offset

    host_len1: Word;                    // host string length
    host_len2: Word;                    // host string length
    host_off: LongWord;                 // host string offset
    zero: LongWord;

    msg_len: LongWord;                  // message length

    flags: LongWord;                    // 0xA0808205
  end;

  Pdes_key_schedule = ^des_key_schedule;

function BuildType1Message(const ADomain, AHost: String): String;
function BuildType3Message(const ADomain, AHost, AUsername: {$IFDEF UNICODESTRING}UnicodeString{$ELSE}WideString{$ENDIF}; APassword, ANonce: String): String;
{$ENDIF}

function NTLMFunctionsLoaded : Boolean;

procedure GetDomain(const AUserName : String; var VUserName, VDomain : String);

  //IMPORTANT!!!
  //
  //NTLM is a funny protocol because it was designed for little endian machines.
  //Some record values must be in little endian byte-orders.

const
  // S.G. 12/7/2002: Changed the flag to $B207 (from BugID 577895 and packet trace)
  //was $A000B207;     //b203;
  //JPM - note that this value has to be little endian.  We precalculate
  //this for big endian machines.
  MSG1_FLAGS : Word = {$IFDEF ENDIAN_LITTLE}$b207 {$ELSE}$07B2 {$ENDIF};
  MSG1_HOST_OFFS : LongWord =  {$IFDEF ENDIAN_LITTLE}$20 {$ELSE} $20000000{$ENDIF};
  // S.G. 12/7/2002: was: Length(lm_password);  (from BugID 577895)
  //JPM - ditto for this.
  MSG3_LM_RESP_LEN : Word = {$IFDEF ENDIAN_LITTLE}$18 {$ELSE}$1800 {$ENDIF};
  // S.G. 12/7/2002: was: Length(nt_password);  (from BugID 577895)
  //JPM - ditto for this.
  MSG3_NT_RESP_LEN : Word = {$IFDEF ENDIAN_LITTLE}$18 {$ELSE}$1800 {$ENDIF};
  MSG3_DOM_OFFS : LongWord = {$IFDEF ENDIAN_LITTLE}$40 {$ELSE}$40000000 {$ENDIF};
  // S.G. 12/7/2002: was: flags := $A0808205;  (from BugID 577895 and packet trace)
  MSG3_FLAGS : LongWord =  {$IFDEF ENDIAN_LITTLE}$018205 {$ELSE}$05820100 {$ENDIF};
  MSG3_TYPE : LongWord = {$IFDEF ENDIAN_LITTLE} 3 {$ELSE} $03000000 {$ENDIF};

implementation

uses
  {$IFDEF UNICODESTRING}
  AnsiStrings,
  {$ENDIF}
  SysUtils,
  {$IFDEF DOTNET}
  System.Text,
  {$ENDIF}
  IdHash,
  IdHashMessageDigest,
  IdCoderMIME;

const
  cProtocolStr: AnsiString = 'NTLMSSP'#0; {Do not Localize}

procedure GetDomain(const AUserName : String; var VUserName, VDomain : String);
{$IFDEF USEINLINE} inline; {$ENDIF}
var
  i: Integer;
begin
  i := Pos('\', AUsername);
  if i > -1 then
  begin
    VDomain := Copy(AUsername, 1, i - 1);
    VUserName := Copy(AUsername, i + 1, Length(AUserName));
  end else
  begin
    VDomain := ' ';         {do not localize}
    VUserName := AUserName;
  end;
end;

{$IFDEF DOTNET}
function NTLMFunctionsLoaded : Boolean;
{$IFDEF USEINLINE} inline; {$ENDIF}
begin
  Result := True;
end;
{$ELSE}
function NTLMFunctionsLoaded : Boolean;
begin
  Result := Assigned(iddes_set_odd_parity) and
    Assigned(IdDES_set_key) and
    Assigned(iddes_set_odd_parity) and
    Assigned(IdDES_ecb_encrypt) and
    Assigned(iddes_ecb_encrypt);
end;
{$ENDIF}

{$IFNDEF DOTNET}
{/*
 * turns a 56 bit key into the 64 bit, odd parity key and sets the key.
 * The key schedule ks is also set.
 */}
procedure setup_des_key(key_56: des_cblock; Var ks: des_key_schedule);
Var
  key: des_cblock;
begin
  key[0] := key_56[0];

  key[1] := ((key_56[0] SHL 7) and $FF) or (key_56[1] SHR 1);
  key[2] := ((key_56[1] SHL 6) and $FF) or (key_56[2] SHR 2);
  key[3] := ((key_56[2] SHL 5) and $FF) or (key_56[3] SHR 3);
  key[4] := ((key_56[3] SHL 4) and $FF) or (key_56[4] SHR 4);
  key[5] := ((key_56[4] SHL 3) and $FF) or (key_56[5] SHR 5);
  key[6] := ((key_56[5] SHL 2) and $FF) or (key_56[6] SHR 6);
  key[7] :=  (key_56[6] SHL 1) and $FF;

  iddes_set_odd_parity(@key);
  iddes_set_key(@key, ks);
end;

{/*
 * takes a 21 byte array and treats it as 3 56-bit DES keys. The
 * 8 byte plaintext is encrypted with each key and the resulting 24
 * bytes are stored in the results array.
 */}
procedure calc_resp(keys: PDES_cblock; const ANonce: AnsiString; results: Pdes_key_schedule);
Var
  ks: des_key_schedule;
  nonce: des_cblock;
begin
  setup_des_key(keys^, ks);
  Move(ANonce[1], nonce, 8);
  iddes_ecb_encrypt(@nonce, Pconst_DES_cblock(results), ks, OPENSSL_DES_ENCRYPT);

  setup_des_key(PDES_cblock(PtrUInt(keys) + 7)^, ks);
  iddes_ecb_encrypt(@nonce, Pconst_DES_cblock(PtrUInt(results) + 8), ks, OPENSSL_DES_ENCRYPT);

  setup_des_key(PDES_cblock(PtrUInt(keys) + 14)^, ks);
  iddes_ecb_encrypt(@nonce, Pconst_DES_cblock(PtrUInt(results) + 16), ks, OPENSSL_DES_ENCRYPT);
end;

Const
  Magic: des_cblock = ($4B, $47, $53, $21, $40, $23, $24, $25 );

//* setup LanManager password */
function SetupLanManagerPassword(const APassword, ANonce: AnsiString): TIdBytes;
var
  lm_hpw: array[1..21] of AnsiChar;
  lm_pw: array[1..14] of AnsiChar;
  idx, len: Integer;
  ks: des_key_schedule;
  lm_resp: array [1..24] of AnsiChar;
  lPassword: AnsiString;
begin
  lPassword := Copy(UpperCase(APassword), 1, 14);
  len := Length(lPassword);
  if len > 0 then begin
    Move(lPassword[1], lm_pw, len);
  end;
  if len < 14 then begin
    for idx := len + 1 to 14 do begin
      lm_pw[idx] := #0;
    end;
  end;

  //* create LanManager hashed password */

  setup_des_key(pdes_cblock(@lm_pw[1])^, ks);
  iddes_ecb_encrypt(@magic, Pconst_DES_cblock(@lm_hpw[1]), ks, OPENSSL_DES_ENCRYPT);

  setup_des_key(pdes_cblock(PtrUInt(@lm_pw[1]) + 7)^, ks);
  iddes_ecb_encrypt(@magic, Pconst_DES_cblock(PtrUInt(@lm_hpw[1]) + 8), ks, OPENSSL_DES_ENCRYPT);

  FillChar(lm_hpw[17], 5, 0);

  calc_resp(PDes_cblock(@lm_hpw[1]), ANonce, Pdes_key_schedule(@lm_resp[1]));

  SetLength(Result, SizeOf(lm_resp));
  Move(lm_resp[1], Result[0], SizeOf(lm_resp));
end;

function BuildUnicode(const S: String): TIdBytes;
{$IFNDEF UNICODESTRING}
var
  i: integer;
{$ENDIF}
begin
  Result := nil;
  if S = '' then begin
    Exit;
  end;
  SetLength(Result, Length(S) * SizeOf(WideChar));
  {$IFDEF UNICODESTRING}
  Move(S[1], Result[0], Length(Result));
  {$ELSE}
  for i := 0 to Length(S)-1 do begin
    Result[i*2] := Byte(S[i+1]);
    Result[(i*2)+1] := Byte(#0);
  end;
  {$ENDIF}
end;

//* create NT hashed password */
function CreateNTPassword(const APassword, ANonce: String): TIdBytes;
var
  nt_hpw: array [1..21] of AnsiChar;
  nt_hpw128: TIdBytes;
  nt_resp: array [1..24] of AnsiChar;
begin
  with TIdHashMessageDigest4.Create do
  try
    {$IFDEF UNICODESTRING}
    nt_hpw128 := HashString(APassword);
    {$ELSE}
    nt_hpw128 := HashBytes(BuildUnicode(APassword));
    {$ENDIF}
  finally
    Free;
  end;

  Move(nt_hpw128[0], nt_hpw[1], 16);
  FillChar(nt_hpw[17], 5, 0);

  calc_resp(pdes_cblock(@nt_hpw[1]),
    {$IFDEF UNICODESTRING}
    AnsiString(ANonce), // explicit convert to Ansi
    {$ELSE}
    ANonce,
    {$ENDIF}
    Pdes_key_schedule(@nt_resp[1]));

  SetLength(Result, SizeOf(nt_resp));
  Move(nt_resp[1], Result[0], SizeOf(nt_resp));
end;

function BuildType1Message(const ADomain, AHost: String): String;
var
  Type_1_Message: type_1_message_header;
  lDomain: TIdBytes;
  lHost: TIdBytes;
  buf: TIdBytes;
begin

  lDomain := ToBytes(UpperCase(ADomain), TIdTextEncoding.ASCII);
  lHost := ToBytes(UpperCase(AHost), TIdTextEncoding.ASCII);

  FillChar(Type_1_Message, SizeOf(Type_1_Message), #0);
  with Type_1_Message do
  begin
    StrPLCopy(@protocol[1], cProtocolStr, 8);
    _type := 1;
    // S.G. 12/7/2002: Changed the flag to $B207 (from BugID 577895 and packet trace)
    flags := MSG1_FLAGS; //was $A000B207;     //b203;

    dom_len1 := HostToLittleEndian(Word(Length(lDomain)));
    dom_len2 := dom_len1;
    // dom_off := 0;
    dom_off := HostToLittleEndian(LongWord(Length(lHost) + 32));

    host_len1 := HostToLittleEndian(Word(Length(lHost)));
    host_len2 := host_len1;
    host_off := MSG1_HOST_OFFS;
  end;

  buf := RawToBytes(Type_1_Message, SizeOf(Type_1_Message));
  AppendBytes(buf, lHost);
  AppendBytes(buf, lDomain);

  Result := TIdEncoderMIME.EncodeBytes(buf);
end;

function BuildType3Message(const ADomain, AHost, AUsername: {$IFDEF UNICODESTRING}UnicodeString{$ELSE}WideString{$ENDIF};
  APassword, ANonce: String): String;
var
  type3: type_3_message_header;
  buf: TIdBytes;
  lm_password: TIdBytes;
  nt_password: TIdBytes;
  lDomain: TIdBytes;
  lHost: TIdBytes;
  lUsername: TIdBytes;
begin
  lm_password := SetupLanManagerPassword(
    {$IFDEF UNICODESTRING}
    AnsiString(APassword), AnsiString(ANonce) // explicit convert to Ansi
    {$ELSE}
    APassword, ANonce
    {$ENDIF}
  );
  nt_password := CreateNTPassword(APassword, ANonce);

  lDomain := BuildUnicode(UpperCase(ADomain));
  lHost := BuildUnicode(UpperCase(AHost));
  lUsername := BuildUnicode(AUsername);

  with Type3 do begin
    StrPLCopy(@protocol[1], cProtocolStr, 8);
    _type := MSG3_TYPE;
    lm_resp_len1 := MSG3_LM_RESP_LEN;
    lm_resp_len2 := MSG3_LM_RESP_LEN;
    lm_resp_off := HostToLittleEndian(LongWord(Length(lDomain) + Length(lUsername) + Length(lHost) + $40));

    nt_resp_len1 := MSG3_NT_RESP_LEN;// S.G. 12/7/2002: was: Length(nt_password);  (from BugID 577895)
    nt_resp_len2 := MSG3_NT_RESP_LEN;// S.G. 12/7/2002: was: Length(nt_password);  (from BugID 577895)
    nt_resp_off := HostToLittleEndian(LongWord(Length(lDomain) + Length(lUsername) + Length(lHost) + Length(lm_password) + $40));

    dom_len1 := HostToLittleEndian(Word(Length(lDomain)));
    dom_len2 := dom_len1;
    dom_off :=  MSG3_DOM_OFFS;

    user_len1 := HostToLittleEndian(Word(Length(lUsername)));
    user_len2 := user_len1;
    user_off := HostToLittleEndian(LongWord(Length(lDomain) + $40));

    host_len1 := HostToLittleEndian(Word(Length(lHost)));
    host_len2 := host_len1;
    host_off := HostToLittleEndian(LongWord(Length(lDomain) + Length(lUsername) + $40));
    zero := 0;

    msg_len := HostToLittleEndian(LongWord(SizeOf(Type3) + Length(lDomain) + Length(lUsername) + Length(lHost) + Length(lm_password) + Length(nt_password)));
    flags := MSG3_FLAGS;
  end;

  buf := RawToBytes(Type3, SizeOf(Type3));
  AppendBytes(buf, lDomain);
  AppendBytes(buf, lUsername);
  AppendBytes(buf, lHost);
  AppendBytes(buf, lm_password);
  AppendBytes(buf, nt_password);

  Result := TIdEncoderMIME.EncodeBytes(buf);
end;

{$ELSE}
procedure BytesToCharArray(const ABytes : TIdBytes; var VArray : Array of Char; const AIndex : Integer = 0);
var
  i, ll, lh : Integer;
begin
  ll :=  Low(VArray);
  lh := High(Varray);
  for i := ll to lh do begin
    VArray[i] := Char(ABytes[ (i - ll)+ AIndex]);
  end;
end;

procedure BytesToByteArray(const ABytes : TIdBytes; var VArray : Array of Byte; const AIndex : Integer = 0);
var
  i, ll, lh : Integer;
begin
  ll :=  Low(VArray);
  lh := High(Varray);
  for i := ll to lh do begin
    VArray[i] := ABytes[ (i - ll)+ AIndex];
  end;
end;

procedure ByteArrayToBytes(const VArray : array of Byte; const ABytes : TIdBytes; const AIndex : Integer = 0);
var
  i, ll, lh : Integer;
begin
  ll :=  Low(VArray);
  lh := High(Varray);
  for i := ll to lh do begin
    ABytes[ (i - ll)+ AIndex] := VArray[i];
  end;
end;

function ntlm_base.GetBytesLen: LongWord;
begin
  Result := 8;
end;

procedure ntlm_base.ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord);
var
  i : Integer;
begin
  inherited ReadStruct(ABytes,VIndex);
  for i := 1 to Length(fprotocol) do
  begin
    fprotocol[i] := Char(ABytes[i+VIndex]);
  end;
  Inc(VIndex, Length(fprotocol));
end;

procedure ntlm_base.WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);
var
  LLen : Integer;
  LBytes : TIdBytes;
begin
  inherited WriteStruct(VBytes,VIndex);
  LBytes := System.Text.ASCIIEncoding.GetBytes(fprotocol);
  LLen := Length(fprotocol);
  CopyTIdBytes(LBytes, VIndex, VBytes, VIndex, LLen);
  Inc(VIndex, LLen);
end;

function type_1_message_header.GetBytesLen: LongWord;
begin
  Result := 32;
end;

procedure type_1_message_header.ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord);
{
var
  f_type : Byte;
  fpad : padArray3;
  fflags : Word;
  fpad2 : padArray2;
  fdom_len1 : Word;
  fdom_len2 : Word;
  fdom_off : LongWord;
  fhost_len1 : Word;
  fhost_len2 : Word;
  fhost_off : LongWord;
}
begin
  inherited ReadStruct(ABytes, VIndex);
  f_type := ABytes[VIndex];
  Inc(VIndex);
  BytesToByteArray(ABytes, fpad, VIndex);
  Inc(VIndex, Length(fpad));
  fflags := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  BytesToByteArray(ABytes, fpad2, VIndex);
  Inc(VIndex, Length(fpad2));
  fdom_len1 := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  fdom_len2 := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  fdom_off := IdGlobal.BytesToLongWord(ABytes, VIndex);
  Inc(VIndex, 4);
  fhost_len1 := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  fhost_len2 := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  fhost_off := IdGlobal.BytesToLongWord(ABytes, VIndex);
  Inc(VIndex, 4);
end;

procedure type_1_message_header.WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);
begin
  inherited WriteStruct(VBytes, VIndex);
  VBytes[VIndex] := f_type;
  Inc(VIndex);
  ByteArrayToBytes(fpad, VBytes, VIndex);
  Inc(VIndex, Length(fpad));
  CopyTIdWord(fflags, VBytes, VIndex);
  Inc(VIndex, 2);
  ByteArrayToBytes(fpad2, VBytes, VIndex);
  Inc(VIndex, Length(fpad2));
  CopyTIdWord(fdom_len1, VBytes, VIndex);
  Inc(VIndex, 2);
  CopyTIdWord(fdom_len2, VBytes, VIndex);
  Inc(VIndex, 2);
  CopyTIdLongWord(fdom_off, VBytes, VIndex);
  Inc(VIndex, 4);
  CopyTIdWord(fhost_len1, VBytes, VIndex);
  Inc(VIndex, 2);
  CopyTIdWord(fhost_len2, VBytes, VIndex);
  Inc(VIndex, 2);
  CopyTIdLongWord(fhost_off, VBytes, VIndex);
  Inc(VIndex, 4);
end;

function type_2_message_header.GetBytesLen: LongWord;
begin
end;

procedure type_2_message_header.ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord);
begin
  inherited ReadStruct(ABytes, VIndex);
  f_type := ABytes[VIndex];
  Inc(VIndex);
  BytesToByteArray(ABytes, fpad, VIndex);
  Inc(VIndex, Length(fpad));
  fmsg_len := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  BytesToByteArray(ABytes, fPad2, VIndex);
  Inc(VIndex, Length(fpad2));
  fflags := IdGlobal.BytesToWord(ABytes, VIndex);
  Inc(VIndex, 2);
  BytesToByteArray(ABytes, fPad3, VIndex);
  Inc(VIndex, Length(fpad3));
  BytesToCharArray(ABytes, fnonce, VIndex);
  Inc(VIndex, Length(fnonce));
  BytesToByteArray(ABytes, fPad4, VIndex);
  Inc(VIndex, Length(fpad4));
end;

procedure type_2_message_header.WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);
begin
  inherited WriteStruct(VBytes, VIndex);
  VBytes[VIndex] := f_type;
  Inc(VIndex);
  ByteArrayToBytes(fPad, VBytes, VIndex);
  Inc(VIndex, Length(fpad));
  CopyTIdWord(fmsg_len, VBytes, VIndex);
  Inc(VIndex, 2);
  ByteArrayToBytes(fPad2, VBytes, VIndex);
  Inc(VIndex, Length(fPad2));
  CopyTIdWord(fflags, VBytes, VIndex);
  Inc(VIndex, 2);
  ByteArrayToBytes(fPad3, VBytes, VIndex);
  Inc(VIndex, Length(fPad3));
  CharArrayToBytes(fnonce, VBytes, VIndex);
  Inc(VIndex, Length(fnonce));
  ByteArrayToBytes(fPad4, VBytes, VIndex);
  Inc(VIndex, Length(fPad4));
end;

function type_3_message_header.GetBytesLen: LongWord;
begin
end;

procedure type_3_message_header.ReadStruct(const ABytes : TIdBytes; var VIndex : LongWord);
begin
{
    _type: LongWord;                    // 0x03

    lm_resp_len1: Word;                 // LanManager response length (always 0x18)
    lm_resp_len2: Word;                 // LanManager response length (always 0x18)
    lm_resp_off: LongWord;              // LanManager response offset

    nt_resp_len1: Word;                 // NT response length (always 0x18)
    nt_resp_len2: Word;                 // NT response length (always 0x18)
    nt_resp_off: LongWord;              // NT response offset

    dom_len1: Word;                     // domain string length
    dom_len2: Word;                     // domain string length
    dom_off: LongWord;                  // domain string offset (always 0x40)

    user_len1: Word;                    // username string length
    user_len2: Word;                    // username string length
    user_off: LongWord;                 // username string offset

    host_len1: Word;                    // host string length
    host_len2: Word;                    // host string length
    host_off: LongWord;                 // host string offset
    zero: LongWord;

    msg_len: LongWord;                  // message length

    flags: LongWord;                    // 0xA0808205
    }
end;

procedure type_3_message_header.WriteStruct(var VBytes : TIdBytes; var VIndex : LongWord);
begin
{
    _type: LongWord;                    // 0x03

    lm_resp_len1: Word;                 // LanManager response length (always 0x18)
    lm_resp_len2: Word;                 // LanManager response length (always 0x18)
    lm_resp_off: LongWord;              // LanManager response offset

    nt_resp_len1: Word;                 // NT response length (always 0x18)
    nt_resp_len2: Word;                 // NT response length (always 0x18)
    nt_resp_off: LongWord;              // NT response offset

    dom_len1: Word;                     // domain string length
    dom_len2: Word;                     // domain string length
    dom_off: LongWord;                  // domain string offset (always 0x40)

    user_len1: Word;                    // username string length
    user_len2: Word;                    // username string length
    user_off: LongWord;                 // username string offset

    host_len1: Word;                    // host string length
    host_len2: Word;                    // host string length
    host_off: LongWord;                 // host string offset
    zero: LongWord;

    msg_len: LongWord;                  // message length

    flags: LongWord;                    // 0xA0808205
}
end;
{$ENDIF}

end.
