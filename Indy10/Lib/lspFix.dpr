{ $HDR$}
{**********************************************************************}
{ Unit archived using Team Coherence                                   }
{ Team Coherence is Copyright 2002 by Quality Software Components      }
{                                                                      }
{ For further information / comments, visit our WEB site at            }
{ http://www.TeamCoherence.com                                         }
{**********************************************************************}
{}
{ $Log:  13394: lspFix.dpr 
{
{   Rev 1.0    11/13/2002 02:52:12 PM  JPMugaas
}
program lspFix;

{$APPTYPE CONSOLE}

{This program fixes some problems with linker response files
generated by DCC32 which can cause TLIB to fail}

uses
  classes,
  SysUtils,
  Windows;

const
  BackupExt = '.BAK';
  //This symbol should be removed because it's not needed and
  //and may be problematic if in a LIB file.  It's a symbol used
  //in Borland's RTL library
  ProblemSymbol = 'SysInit.obj';
  ReplaceSymbol = '-+';

{from

http://community.borland.com/article/0,1410,15910,00.html

}
Procedure FileCopy( Const ASourceFilename, ATargetFilename: String );
Var
  S, T: TFileStream;
Begin
  S := TFileStream.Create( ASourceFilename, fmOpenRead );
  try
    T := TFileStream.Create( ATargetFilename,
                             fmOpenWrite or fmCreate );
    try
      T.CopyFrom(S, S.Size ) ;
    finally
      T.Free;
    end;
  finally
    S.Free;
  end;
End;

Procedure Error;
begin
  ExitCode := 1;
end;

function GetLSPFileName : String;
var i : Integer;
begin
  Result := '';
  for i := 1 to ParamCount do
  begin
    Result := Result + ParamStr(i)+' ';
  end;
  Result := Trim(Result);
end;

function FileContents(AFileName : String) : String;
var s : TStream;
    sz : Integer;
begin
  s := TFileStream.Create(AFileName,fmOpenRead);
  try
    sz := s.Size;
    SetLength(Result,sz);
    s.Read(Result[1],sz);
  finally
    FreeAndNil(s);
  end;
end;

function FixTLibEntry(const AOldStr : String) : String;
begin
//  Result := ExtractShortPathName(ExpandFileName(ExtractFilePath(AOldStr)));
//  Result := Result + ExtractFileName(AOldStr);
  Result := '"'+AOldStr+'"';
end;

function RepairLSPData(AOriginalData : String): String;
var s : TStrings;
    i : Integer;
begin
  s := TStringList.Create;
  try
    s.Text := Trim(StringReplace(AOriginalData,ReplaceSymbol,sLineBreak,[rfReplaceAll]));
    i := 0;
    while i < s.Count do
    begin
      if ExtractFileName(s[i])=ProblemSymbol then
      begin
        s.Delete(i);
      end
      else
      begin
        if Length(s[i])>0 then
        begin
          s[i] := ReplaceSymbol + FixTLibEntry(s[i]);
        end
        else
        begin
          s.Delete(i);
        end;
      end;
      Inc(i);
    end;
    Result := StringReplace(s.Text,sLineBreak,' ',[rfReplaceAll]);
  finally
    FreeAndNil(s);
  end;
end;

procedure FileCreate(AFilename, AText : String; AOverwrite : Boolean = True);
var s : TStream;
begin
  s := TFileStream.Create(AFileName,fmCreate);
  try
    s.Write(AText[1],Length(AText));
  finally
    FreeAndNil(s);
  end;
end;

var lspName : String;
begin
  try
    if ParamCount = 0 then
    begin
      WriteLn('This program requires that you pass the file name for the');
      WriteLn('linker response file that needs to be fixed.  For example:');
      WriteLn('');
      WriteLn('lspFix MyLispFile.lsp');
      Exit;
    end;
    lspName := GetLSPFileName;
    if ExtractFileExt(UpperCase(lspName)) = BackupExt then
    begin
      Raise Exception.Create('You can not fix a backup file.');
    end;
    FileCopy(lspName, ChangeFileExt(lspName,BackupExt));
    FileCreate(lspName, RepairLSPData( FileContents(lspName)));
  except
    on E: Exception do
    begin
      WriteLn(E.Message);
    end;
  end;
end.
 
