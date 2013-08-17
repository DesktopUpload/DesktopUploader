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
  Rev 1.5    2004.10.27 9:17:46 AM  czhower
  For TIdStrings

  Rev 1.4    7/28/04 11:43:32 PM  RLebeau
  Bug fix for CleanupCookieList()

  Rev 1.3    2004.02.03 5:45:02 PM  czhower
  Name changes

  Rev 1.2    1/22/2004 7:10:02 AM  JPMugaas
  Tried to fix AnsiSameText depreciation.

  Rev 1.1    2004.01.21 1:04:54 PM  czhower
  InitComponenet

  Rev 1.0    11/14/2002 02:16:26 PM  JPMugaas

  2001-Mar-31 Doychin Bondzhev
  - Added new method AddCookie2 that is called when we have Set-Cookie2 as response
  - The common code in AddCookie and AddCookie2 is now in DoAdd

  2001-Mar-24 Doychin Bondzhev
  - Added OnNewCookie event
    This event is called for every new cookie. Can be used to ask the user program
    do we have to store this cookie in the cookie collection
  - Added new method AddCookie
    This calls the OnNewCookie event and if the result is true it adds the new cookie
    in the collection
}

unit IdCookieManager;

{
  Implementation of the HTTP State Management Mechanism as specified in RFC 2109, 2965.

  Author: Doychin Bondzhev (doychin@dsoft-bg.com)
  Copyright: (c) Chad Z. Hower and The Indy Team.
}

interface

{$i IdCompilerDefines.inc}

uses
  IdBaseComponent,
  IdCookie,
  IdURI;

Type
  TOnNewCookieEvent = procedure(ASender: TObject; ACookie: TIdCookieRFC2109; var VAccept: Boolean) of object;

  TOnCookieManagerEvent = procedure(ASender: TObject; ACookieCollection: TIdCookies) of object;
  TOnCookieCreateEvent = TOnCookieManagerEvent;
  TOnCookieDestroyEvent = TOnCookieManagerEvent;

  TIdCookieManager = class(TIdBaseComponent)
  protected
    FOnCreate: TOnCookieCreateEvent;
    FOnDestroy:  TOnCookieDestroyEvent;
    FOnNewCookie: TOnNewCookieEvent;
    FCookieCollection: TIdCookies;

    procedure CleanupCookieList;
    procedure DoAdd(ACookie: TIdCookieRFC2109; ACookieText, AHost: String);
    procedure DoOnCreate; virtual;
    procedure DoOnDestroy; virtual;
    function DoOnNewCookie(ACookie: TIdCookieRFC2109): Boolean; virtual;
    procedure InitComponent; override;
  public
    destructor Destroy; override;
    //
    procedure AddCookie(ACookie, AHost: String);
    procedure AddCookie2(ACookie, AHost: String);
    procedure AddCookies(ASource: TIdCookieManager);
    procedure CopyCookie(ACookie: TIdCookieRFC2109);
    //
    function GenerateCookieList(URL: TIdURI; SecureConnection: Boolean = false): String;
    //
    property CookieCollection: TIdCookies read FCookieCollection;
  published
    property OnCreate: TOnCookieCreateEvent read FOnCreate write FOnCreate;
    property OnDestroy: TOnCookieDestroyEvent read FOnDestroy write FOnDestroy;
    property OnNewCookie: TOnNewCookieEvent read FOnNewCookie write FOnNewCookie;
  end;

implementation

uses
  IdGlobal, IdGlobalProtocols, SysUtils;

function IsDomainMatch(const AHost, ADomain: String): Boolean;
begin
  {
  Per RFC 2965:
  
  ...

  Host names can be specified either as an IP address or a HDN string.
  Sometimes we compare one host name with another.  (Such comparisons
  SHALL be case-insensitive.)  Host A's name domain-matches host B's if

    * their host name strings string-compare equal; or

    * A is a HDN string and has the form NB, where N is a non-empty
      name string, B has the form .B', and B' is a HDN string.  (So,
      x.y.com domain-matches .Y.com but not Y.com.)

  Note that domain-match is not a commutative operation: a.b.c.com
  domain-matches .c.com, but not the reverse.
  }
  
  if IsValidIP(AHost) then
  begin
    Result := AHost = ADomain;
  end
  else if IsHostName(AHost) then
  begin
    if CharEquals(ADomain, 1, '.') then begin
      Result := TextEndsWith(AHost, ADomain);
    end else
    begin
      Result := TextIsSame(AHost, ADomain);
    end;
  end
  else begin
    Result := False;
  end;
end;

function IsRejectedCookie(ACookie: TIdCookieRFC2109; const AHost: string): Boolean;
begin
  {
  Per RFC 2965:

  ...

  A user agent rejects (SHALL NOT store its information) if the Version
  attribute is missing.  Moreover, a user agent rejects (SHALL NOT
  store its information) if any of the following is true of the
  attributes explicitly present in the Set-Cookie2 response header:

    *  The value for the Path attribute is not a prefix of the
       request-URI.

    *  The value for the Domain attribute contains no embedded dots,
       and the value is not .local.

    *  The effective host name that derives from the request-host does
       not domain-match the Domain attribute.

    *  The request-host is a HDN (not IP address) and has the form HD,
       where D is the value of the Domain attribute, and H is a string
       that contains one or more dots.

    *  The Port attribute has a "port-list", and the request-port was
       not in the list.
  }
  
  Result := not IsDomainMatch(AHost, ACookie.Domain);

  // TODO: validate other attribute values as well
end;

{ TIdCookieManager }

destructor TIdCookieManager.Destroy;
begin
  CleanupCookieList;
  DoOnDestroy;
  FreeAndNil(FCookieCollection);
  inherited Destroy;
end;

function TIdCookieManager.GenerateCookieList(URL: TIdURI; SecureConnection: Boolean = false): String;
Var
  S: String;
  i, j: Integer;
  LCookieList: TIdCookieList;
  LResultList: TIdCookieList;
  LCookiesByDomain: TIdCookieDomainList;
begin
  CleanupCookieList;
  S := '';    {Do not Localize}
  LCookiesByDomain := FCookieCollection.LockCookieListByDomain(caRead);
  try
    if LCookiesByDomain.Count > 0 then
    begin
      LResultList := TIdCookieList.Create;

      try
        // Search for cookies for this domain
        for i := 0 to LCookiesByDomain.Count - 1 do
        begin
          if IsDomainMatch(URL.Host, LCookiesByDomain.Strings[i]) then
          begin
            LCookieList := LCookiesByDomain.CookieList[i];

            for j := LCookieList.Count - 1 downto 0 do
            begin
              if Pos(LCookieList.Cookies[j].Path, URL.Path) = 1 then
              begin
                with LCookieList.Cookies[j] do
                begin
                  if ((Secure and SecureConnection) or (not Secure)) and (Value <> '') then    {Do not Localize}
                  begin
                    LResultList.AddObject(Path, LCookieList.Cookies[j]);
                  end;
                end;
              end;
            end;
          end;
        end;

        for i := LResultList.Count - 1 downto 0 do
        begin
          if Length(S) > 0  then S := S + '; ';    {Do not Localize}
          S := S + LResultList.Cookies[i].CookieName + '=' + LResultList.Cookies[i].Value;    {Do not Localize}
        end;
      finally
        LResultList.Free;
      end;
    end;
  finally
    FCookieCollection.UnlockCookieListByDomain(caRead);
  end;
  Result := S;
end;

procedure TIdCookieManager.DoAdd(ACookie: TIdCookieRFC2109; ACookieText, AHost: String);
begin
  ACookie.CookieText := ACookieText;

  if Length(ACookie.Domain) = 0 then begin
    ACookie.Domain := AHost;
  end
  else if not TextStartsWith(ACookie.Domain, '.') then begin {do not localize}
    ACookie.Domain := '.' + ACookie.Domain; {do not localize}
  end;

  if not IsRejectedCookie(ACookie, AHost) then
  begin
    if DoOnNewCookie(ACookie) then
    begin
      FCookieCollection.AddCookie(ACookie);
      Exit;
    end;
    ACookie.Collection := nil;
  end;

  ACookie.Free;
end;

procedure TIdCookieManager.AddCookie(ACookie, AHost: String);
var
  LCookie: TIdCookieRFC2109;
begin
  LCookie := FCookieCollection.Add;
  DoAdd(LCookie, ACookie, AHost);
end;

procedure TIdCookieManager.AddCookie2(ACookie, AHost: String);
var
  LCookie: TIdCookieRFC2965;
begin
  LCookie := FCookieCollection.Add2;
  DoAdd(LCookie, ACookie, AHost);
end;

procedure TIdCookieManager.AddCookies(ASource: TIdCookieManager);
begin
  if (ASource <> nil) and (ASource <> Self) then begin
    FCookieCollection.AddCookies(ASource.CookieCollection);
  end;
end;

procedure TIdCookieManager.CopyCookie(ACookie: TIdCookieRFC2109);
var
  LCookie: TIdCookieRFC2109;
begin
  LCookie := TIdCookieRFC2109Class(ACookie.ClassType).Create(FCookieCollection);
  try
    LCookie.Assign(ACookie);

    // RLebeau: copied from DoAdd()...
    if (Length(LCookie.Domain) > 0) and (not TextStartsWith(LCookie.Domain, '.')) then begin {do not localize}
      LCookie.Domain := '.' + LCookie.Domain; {do not localize}
    end;
    if Length(LCookie.Domain) > 0 then
    begin
      if DoOnNewCookie(LCookie) then
      begin
        FCookieCollection.AddCookie(LCookie);
        LCookie := nil;
      end;
    end;
  finally
    if LCookie <> nil then
    begin
      LCookie.Collection := nil;
      LCookie.Free;
    end;
  end;
end;

function TIdCookieManager.DoOnNewCookie(ACookie: TIdCookieRFC2109): Boolean;
begin
  Result := True;
  if Assigned(FOnNewCookie) then
  begin
    OnNewCookie(Self, ACookie, Result);
  end;
end;

procedure TIdCookieManager.DoOnCreate;
begin
  if Assigned(FOnCreate) then
  begin
    OnCreate(Self, FCookieCollection);
  end;
end;

procedure TIdCookieManager.DoOnDestroy;
begin
  if Assigned(FOnDestroy) then
  begin
    OnDestroy(Self, FCookieCollection);
  end;
end;

procedure TIdCookieManager.CleanupCookieList;
var
  S: String;
  i, j, LLastCount: Integer;
  LCookieList: TIdCookieList;
  LCookiesByDomain: TIdCookieDomainList;
begin
  LCookiesByDomain := FCookieCollection.LockCookieListByDomain(caReadWrite);
  try
    if LCookiesByDomain.Count > 0 then
    begin
      for i := 0 to LCookiesByDomain.Count - 1 do
      begin
        LCookieList := LCookiesByDomain.CookieList[i];

        for j := LCookieList.Count - 1 downto 0 do
        begin
          S := LCookieList.Cookies[j].Expires;
          if (Length(S) > 0) and (GMTToLocalDateTime(S) < Now) then
          begin
            // The Cookie has expired. It has to be removed from the collection
            LLastCount := LCookieList.Count; // RLebeau
            LCookieList.Cookies[j].Free;
            // RLebeau - the cookie may already be removed from the list via
            // its destructor.  If that happens then doing so again below can
            // cause an "index out of bounds" error, so don't do it if not needed.
            if LLastCount = LCookieList.Count then begin
              LCookieList.Delete(j);
            end;
          end;
        end;
      end;
    end;
  finally
    FCookieCollection.UnlockCookieListByDomain(caReadWrite);
  end;
end;

procedure TIdCookieManager.InitComponent;
begin
  inherited InitComponent;
  FCookieCollection := TIdCookies.Create(self);
  DoOnCreate;
end;

end.
