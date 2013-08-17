object HTTPAuthFormBase: THTTPAuthFormBase
  Left = 245
  Top = 108
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Authentication Required'
  ClientHeight = 169
  ClientWidth = 329
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  ShowHint = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lblPassword: TLabel
    Left = 32
    Top = 94
    Width = 50
    Height = 13
    Caption = 'Password:'
  end
  object lblUsername: TLabel
    Left = 32
    Top = 67
    Width = 52
    Height = 13
    Caption = 'Username:'
  end
  object lblNotice: TLabel
    Left = 8
    Top = 8
    Width = 313
    Height = 41
    AutoSize = False
    Caption = 
      'The server www.example-server.com at "Test Realm" requires usern' +
      'ame and password.  '
    WordWrap = True
  end
  object CancelBtn: TButton
    Tag = 1
    Left = 246
    Top = 136
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = CancelBtnClick
  end
  object OKBtn: TButton
    Left = 165
    Top = 136
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object edtPassword: TEdit
    Left = 112
    Top = 91
    Width = 185
    Height = 21
    PasswordChar = '*'
    TabOrder = 1
  end
  object edtUsername: TEdit
    Left = 112
    Top = 64
    Width = 185
    Height = 21
    TabOrder = 0
  end
end
