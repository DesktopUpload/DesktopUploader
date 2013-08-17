object SrvAdapterModule: TSrvAdapterModule
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 279
  Width = 320
  object HTTPClient: TIdHTTP
    IOHandler = IOHandlerStack
    OnWork = HTTPClientWork
    OnWorkBegin = HTTPClientWorkBegin
    OnConnected = HTTPClientConnected
    MaxAuthRetries = 1
    AllowCookies = True
    RedirectMaximum = 30
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.Connection = 'Keep-Alive'
    Request.ContentLength = -1
    Request.Accept = 'text/html, */*'
    Request.AcceptEncoding = 'gzip, deflate, compress'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/4.0 (compatible; MSIE 7.0)'
    HTTPOptions = [hoInProcessAuth, hoKeepOrigProtocol]
    OnHeadersAvailable = HTTPClientHeadersAvailable
    OnAuthorization = HTTPClientAuthorization
    OnProxyAuthorization = HTTPClientProxyAuthorization
    CookieManager = Cookies
    Left = 32
    Top = 8
  end
  object CompressorZLib: TIdCompressorZLib
    Left = 112
    Top = 200
  end
  object AntiFreeze: TIdAntiFreeze
    OnlyWhenIdle = False
    Left = 32
    Top = 200
  end
  object IOHandlerStack: TIdIOHandlerStack
    MaxLineLength = 65536
    MaxLineAction = maException
    Port = 0
    RecvBufferSize = 131072
    SendBufferSize = 131072
    DefaultPort = 0
    Left = 136
    Top = 8
  end
  object Cookies: TIdCookieManager
    Left = 184
    Top = 200
  end
  object HTTPClientAux: TIdHTTP
    IOHandler = IOHandlerStackAux
    OnConnected = HTTPClientConnected
    MaxAuthRetries = 1
    AllowCookies = True
    RedirectMaximum = 30
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.Connection = 'Keep-Alive'
    Request.ContentLength = -1
    Request.Accept = 'text/html, */*'
    Request.AcceptEncoding = 'gzip, deflate, compress'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/4.0 (compatible; MSIE 7.0)'
    HTTPOptions = [hoInProcessAuth, hoKeepOrigProtocol]
    OnHeadersAvailable = HTTPClientAuxHeadersAvailable
    OnAuthorization = HTTPClientAuthorization
    OnProxyAuthorization = HTTPClientProxyAuthorization
    CookieManager = Cookies
    Left = 32
    Top = 72
  end
  object PingTimer: TTimer
    Enabled = False
    OnTimer = OnPingTimer
    Left = 240
    Top = 200
  end
  object IOHandlerStackAux: TIdIOHandlerStack
    MaxLineLength = 65536
    MaxLineAction = maException
    Port = 0
    RecvBufferSize = 131072
    SendBufferSize = 131072
    DefaultPort = 0
    Left = 136
    Top = 72
  end
end
