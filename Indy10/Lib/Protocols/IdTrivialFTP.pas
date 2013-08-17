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
  Rev 1.7    2/8/05 6:08:04 PM  RLebeau
  Changed CheckOptionAck() to use TextIsSame() instead of SameText()

  Rev 1.6    7/23/04 6:41:50 PM  RLebeau
  TFileStream access right tweak for Put()

  Rev 1.5    2/7/2004 7:25:58 PM  JPMugaas
  Deleted error msg code in error packet.  OOPS!!!

  Rev 1.4    2/7/2004 7:20:16 PM  JPMugaas
  DotNET to go!! and YES - I want fries with that :-).

  Rev 1.3    2004.02.03 5:44:38 PM  czhower
  Name changes

  Rev 1.2    1/21/2004 4:21:04 PM  JPMugaas
  InitComponent

  Rev 1.1    2003.10.12 6:36:46 PM  czhower
  Now compiles.

  Rev 1.0    11/13/2002 08:03:32 AM  JPMugaas
}

unit IdTrivialFTP;

interface

{$i IdCompilerDefines.inc}

uses
  Classes,
  IdAssignedNumbers,
  IdGlobal,
  IdTrivialFTPBase,
  IdUDPClient;

const
  GTransferMode = tfOctet;
  GFRequestedBlockSize = 1500;
  GReceiveTimeout = 4000;

type
  TIdTrivialFTP = class(TIdUDPClient)
  protected
    FMode: TIdTFTPMode;
    FRequestedBlockSize: Integer;
    FPeerPort: TIdPort;
    FPeerIP: String;
    function ModeToStr: string;
    procedure CheckOptionAck(const optionpacket: string);
  protected
    procedure SendAck(const BlockNumber: Word);
    procedure RaiseError(const errorpacket: string);
    procedure InitComponent; override;
  public
    procedure Get(const ServerFile: String; DestinationStream: TStream); overload;
    procedure Get(const ServerFile, LocalFile: String); overload;
    procedure Put(SourceStream: TStream; const ServerFile: String); overload;
    procedure Put(const LocalFile, ServerFile: String); overload;
  published
    property TransferMode: TIdTFTPMode read FMode write FMode Default GTransferMode;
    property RequestedBlockSize: Integer read FRequestedBlockSize write FRequestedBlockSize default 1500;
    property OnWork;
    property OnWorkBegin;
    property OnWorkEnd;
  end;

implementation

uses
  IdComponent,
  IdExceptionCore,
  IdGlobalProtocols,
  IdResourceStringsProtocols,
  IdStack,
  SysUtils;

procedure TIdTrivialFTP.CheckOptionAck(const optionpacket: string);
var
  LBuf : String;
  LOptName : String;
//The packet is in a form such as this:
//
//1-2  - command reply
// followed by a #0
// followed by an option name
// which is terminated by a #0
//followed by a number in ASCII terminated by a #0
begin
  LBuf := optionpacket;
  //strip off reply code
  IdDelete(LBuf,1,2);
  //now see what the option is
  LOptName := Fetch(LBuf,#0);
  if TextIsSame(LOptName, 'blksize') then begin    {Do not Localize}
  //
    BufferSize := IndyStrToInt(Fetch(LBuf,#0)) + hdrsize;
  end;
end;

procedure TIdTrivialFTP.InitComponent;
begin
  inherited;
  TransferMode := GTransferMode;
  Port := IdPORT_TFTP;
  FRequestedBlockSize := GFRequestedBlockSize;
  ReceiveTimeout := GReceiveTimeout;
end;

procedure TIdTrivialFTP.Get(const ServerFile: String; DestinationStream: TStream);
var
  s: string;
  RcvTimeout,
  DataLen: Integer;
  PrevBlockCtr,
  BlockCtr: Integer;
  TerminateTransfer: Boolean;
begin
  BeginWork(wmRead);
  try
    BufferSize := 516;   // BufferSize as specified by RFC 1350
    Send(WordToStr(GStack.HostToNetwork(Word(TFTP_RRQ))) + ServerFile + #0 + ModeToStr + #0 +
      sBlockSize + IntToStr(FRequestedBlockSize) + #0);
    PrevBlockCtr := -1;
    BlockCtr := 0;
    TerminateTransfer := False;
    RcvTimeout := ReceiveTimeout;
    while true do
    begin
      if TerminateTransfer then begin
        RcvTimeout := IndyMin(500, ReceiveTimeout);
      end;
      s := ReceiveString(FPeerIP, FPeerPort, RcvTimeout);
      if (s = '') then begin    {Do not Localize}
        if TerminateTransfer then begin
          break;
        end
        else begin
          raise EIdTFTPException.Create(RSTimeOut);
        end;
      end;
      case GStack.HostToNetwork(StrToWord(s)) of
        TFTP_DATA:
          begin
            BlockCtr := GStack.HostToNetwork(StrToWord(Copy(s, 3, 2)));
            if TerminateTransfer then  // hang around just once more
            begin
              SendAck(BlockCtr);
              Break;
            end;
            if (BlockCtr <= 1) and (PrevBlockCtr = MaxWord) then begin
              PrevBlockCtr := -1; // counter wrapped around (1-65535 blocks)
            end;
            if BlockCtr > PrevBlockCtr then
            begin
              DataLen := Length(s) - 4;
              try
                WriteStringToStream(DestinationStream, s, DataLen, 5);
                DoWork(wmRead, DataLen)
              except
                on E:Exception do
                begin
                  SendError(self, FPeerIP, FPeerPort, E);
                  raise;
                end;
              end;
              TerminateTransfer := DataLen < BufferSize - hdrsize;
              PrevBlockCtr := BlockCtr;
            end;  { if }
          end;
        TFTP_ERROR: RaiseError(s);
        TFTP_OACK:
        begin
          CheckOptionAck(s);
          BlockCtr := 0;
        end;
        else
          raise EIdTFTPException.CreateFmt(RSTFTPUnexpectedOp, [Host, Port]);
      end;  { case }
      SendAck(BlockCtr);
    end;  { while }
  finally
    EndWork(wmRead);
    Binding.CloseSocket;
  end;
end;

procedure TIdTrivialFTP.Get(const ServerFile, LocalFile: String);
var
  fs: TFileStream;
begin
  fs := TIdFileCreateStream.Create(LocalFile);
  try
    Get(ServerFile, fs);
  finally
    FreeAndNil(fs);
  end;
end;

function TIdTrivialFTP.ModeToStr: string;
begin
  case TransferMode of
    tfNetAscii: result := 'netascii';    {Do not Localize}
    tfOctet:    result := 'octet';    {Do not Localize}
  end;
end;

procedure TIdTrivialFTP.Put(SourceStream: TStream; const ServerFile: String);
var
  CurrentDataBlk,
  s: string;
  DataLen: Integer;
  PrevBlockCtr,
  BlockCtr: Integer;
  TerminateTransfer: Boolean;
begin
  BeginWork(wmWrite, SourceStream.Size - SourceStream.Position);
  try
    BufferSize := 516;   // BufferSize as specified by RFC 1350
    Send(WordToStr(GStack.HostToNetwork(Word(TFTP_WRQ))) + ServerFile + #0 + ModeToStr + #0 +
      sBlockSize + IntToStr(FRequestedBlockSize) + #0);
    PrevBlockCtr := 0;
    BlockCtr := 1;
    TerminateTransfer := False;
    repeat
      s := ReceiveString(FPeerIP, FPeerPort);
      if s = '' then begin    {Do not Localize}
        if TerminateTransfer then begin
          Break;
        end;
        raise EIdTFTPException.Create(RSTimeOut);
      end;
      case GStack.HostToNetwork(StrToWord(s)) of
        TFTP_ACK:
          begin
            BlockCtr := GStack.HostToNetwork(StrToWord(Copy(s, 3, 2)));
            Inc(BlockCtr);
            if Word(BlockCtr) = 0 then begin
              BlockCtr := 0;
              PrevBlockCtr := -1; // counter wrapped around (1-65535 blocks)
            end;
            if TerminateTransfer then begin
              Break;
            end;
          end;
        TFTP_ERROR: RaiseError(s);
        TFTP_OACK: CheckOptionAck(s);
      end;
      if BlockCtr > PrevBlockCtr then
      begin
        DataLen := IndyMin(BufferSize - hdrsize, SourceStream.Size - SourceStream.Position);
        SetLength(CurrentDataBlk, DataLen + hdrsize);
        CurrentDataBlk := WordToStr(GStack.HostToNetwork(Word(TFTP_DATA))) + WordToStr(GStack.HostToNetwork(BlockCtr));
        SetLength(CurrentDataBlk, DataLen + hdrsize);
        //SourceStream.ReadBuffer(CurrentDataBlk[hdrsize+1], DataLen);
        DoWork(wmWrite, DataLen);
        TerminateTransfer := DataLen < BufferSize - hdrsize;
        PrevBlockCtr := BlockCtr;
      end;
      Send(FPeerIP, FPeerPort, CurrentDataBlk);
    until False;  { repeat }
  finally
    EndWork(wmWrite);
    Binding.CloseSocket;
  end;
end;

procedure TIdTrivialFTP.Put(const LocalFile, ServerFile: String);
var
  fs: TIdReadFileExclusiveStream;
begin
  fs := TIdReadFileExclusiveStream.Create(LocalFile);
  try
    Put(fs, ServerFile);
  finally
    fs.Free;
  end;
end;

procedure TIdTrivialFTP.RaiseError(const errorpacket: string);
var
  errmsg: string;
{RFC 1350 defines the error packet as:

       2 bytes  2 bytes     string   1 byte
----------------------------------------
ERROR | 05    | ErrorCode | ErrMsg | 0 |
----------------------------------------
}
begin
  errmsg := errorpacket;
  IdDelete(errmsg,1,2);
  errmsg := Fetch(errmsg,#0,False);
  case GStack.HostToNetwork(StrToWord(Copy(errorpacket, 3, 2))) of
    ErrFileNotFound:            raise EIdTFTPFileNotFound.Create(errmsg);
    ErrAccessViolation:         raise EIdTFTPAccessViolation.Create(errmsg);
    ErrAllocationExceeded:      raise EIdTFTPAllocationExceeded.Create(errmsg);
    ErrIllegalOperation:        raise EIdTFTPIllegalOperation.Create(errmsg);
    ErrUnknownTransferID:       raise EIdTFTPUnknownTransferID.Create(errmsg);
    ErrFileAlreadyExists:       raise EIdTFTPFileAlreadyExists.Create(errmsg);
    ErrNoSuchUser:              raise EIdTFTPNoSuchUser.Create(errmsg);
    ErrOptionNegotiationFailed: raise EIdTFTPOptionNegotiationFailed.Create(errmsg);
    else  // usually ErrUndefined (see EIdTFTPException.Message if any)
      raise EIdTFTPException.Create(errmsg);
  end;
end;

procedure TIdTrivialFTP.SendAck(const BlockNumber: Word);
begin
  Send(FPeerIP, FPeerPort, MakeAckPkt(BlockNumber));
end;

end.
