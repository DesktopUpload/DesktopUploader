object YoutubeGrabFormBase: TYoutubeGrabFormBase
  Left = 227
  Top = 108
  BorderIcons = [biSystemMenu]
  Caption = 'YouTube Grabber'
  ClientHeight = 417
  ClientWidth = 465
  Color = clBtnFace
  DoubleBuffered = True
  ParentFont = True
  Icon.Data = {
    0000010001001010000001001800680300001600000028000000100000002000
    0000010018000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000D9D9D8D9D9D8D9D9D8
    D9D9D8D9D9D8D9D9D8D9D9D8D9D9D8D9D9D8D9D9D80000000000000000000000
    00000000D9D9D8EDEDF5C2C2F98D8DFC8786FD8181FD8181FD8989FE8C8CFDCD
    CDFBEFEFEED9D9D8000000000000000000D9D9D8EFEFEEC2C2F93838FF5A5AFF
    6464FF6A6AFF7373FF5959FF7575FF5858FFB8B8FAEFEFEED9D9D80000000000
    00D9D9D8EFEFEE7C7CFA3535FFA5A5FF9B9BFFAFAFFFB0B0FFAEAEFFBABAFF6F
    6FFF9292FBEFEFEED9D9D8000000000000D9D9D8EFEFEE7676FA3232FFA1A1FF
    9292FFA4A4FFB2B2FFACACFFCFCFFF7D7DFF8584FBEFEFEED9D9D80000000000
    00D9D9D8EFEFEE8080F95252FFCBCBFF5E5EFF5757FFBDBDFF4C4CFF6D6DFF61
    61FF9E9EF9EFEFEED9D9D8000000000000D9D9D8EFEFEEC3C3F57070FD7A7AFF
    3B3BFF3232FF4D4DFF4040FF7676FFA0A0FDD5D5F5F1F1F0D9D9D80000000000
    00D9D9D8EEEDECEFEEEDE7E7EBAEAEC8D9D8EB8F8FB7C9C9E4A9A9CAAFAEC5EB
    EAECF0F0EFEFEFEED9D9D8000000000000D9D9D8ECEBEAEEEDECF0F0EF61605D
    D7D6D471716AA0A09A7E7E7A605F5DF3F2F2F2F1F0F0F0EFD9D9D80000000000
    00D9D9D8F2F1F0F4F3F2F0F0EF5E5E61CCCBCC9696989595968B8A8C777779F4
    F4F3F5F4F3F4F4F3D9D9D8000000000000D9D9D8F3F3F2F4F3F2DCDCDC252427
    CCCBCC5B5A5DA8A8A98A8A8B777678F4F3F3F4F4F3F4F4F3D9D9D80000000000
    00D9D9D8F4F3F3EFEFEE99999A8D8C8DB8B7B8E0DFDFF2F2F1E9E9E8E7E7E7F5
    F4F4F5F4F4F4F4F3D9D9D8000000000000000000D9D9D8E6E6E6B2B2B3E3E3E3
    BCBCBCF5F5F4F5F5F4F5F5F4F5F5F4F5F5F4F5F5F4D9D9D80000000000000000
    00000000000000D9D9D8D9D9D8D9D9D8D9D9D9DAD9D9DAD9D9DAD9D9DAD9D9D9
    D9D9D9D9D8000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000FFFF
    AC41E007AC41C003AC418001AC418001AC418001AC418001AC418001AC418001
    AC418001AC418001AC418001AC418001AC41C003AC41E007AC41FFFFAC41}
  OldCreateOrder = True
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 112
    Top = 272
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object pnlButtons: TPanel
    AlignWithMargins = True
    Left = 8
    Top = 368
    Width = 449
    Height = 41
    Margins.Left = 8
    Margins.Top = 0
    Margins.Right = 8
    Margins.Bottom = 8
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    DesignSize = (
      449
      41)
    object blvBottom: TBevel
      Left = 0
      Top = 0
      Width = 449
      Height = 10
      Anchors = [akLeft, akTop, akRight]
      Shape = bsTopLine
    end
    object btnOK: TButton
      Tag = 1
      Left = 293
      Top = 16
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Grab'
      Default = True
      TabOrder = 0
      OnClick = btnOKClick
    end
    object btnCancel: TButton
      Tag = 1
      Left = 374
      Top = 16
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
  end
  object pnlMain: TPanel
    AlignWithMargins = True
    Left = 8
    Top = 8
    Width = 449
    Height = 174
    Margins.Left = 8
    Margins.Top = 8
    Margins.Right = 8
    Margins.Bottom = 0
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      449
      174)
    inline UploadProperties: TUploadProperties
      Left = 293
      Top = 0
      Width = 156
      Height = 166
      Anchors = [akTop, akRight, akBottom]
      TabOrder = 2
      ExplicitLeft = 293
      ExplicitWidth = 156
      ExplicitHeight = 166
      DesignSize = (
        156
        166)
      inherited clbCategories: TCheckListBox
        Width = 156
        Height = 78
        ExplicitWidth = 156
        ExplicitHeight = 78
      end
      inherited rgpBroadcast: TRadioGroup
        Top = 122
        Width = 156
        Height = 44
        ExplicitTop = 122
        ExplicitWidth = 156
        ExplicitHeight = 44
      end
      inherited Title: TGroupTitle
        Width = 156
        ExplicitWidth = 156
        inherited Bevel: TBevel
          Width = 156
          ExplicitWidth = 156
        end
      end
      inherited cbxCategory: TComboBox
        Width = 156
        ExplicitWidth = 156
      end
    end
    object chkAutoUpload: TCheckBox
      Tag = 1
      Left = 0
      Top = 149
      Width = 281
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'Auto start upload when finished'
      TabOrder = 1
    end
    object pnlYouTube: TPanel
      Left = -3
      Top = 0
      Width = 281
      Height = 143
      Anchors = [akLeft, akTop, akRight, akBottom]
      BevelOuter = bvNone
      TabOrder = 0
      DesignSize = (
        281
        143)
      object lblGrabbingMethod: TLabel
        Left = 3
        Top = 98
        Width = 86
        Height = 13
        Anchors = [akLeft, akBottom]
        Caption = 'Grabbing Method:'
      end
      object lblQuality: TLabel
        Left = 3
        Top = 125
        Width = 67
        Height = 13
        Anchors = [akLeft, akBottom]
        Caption = 'Video Quality:'
        FocusControl = cmbQuality
      end
      object lblTitle: TLabel
        Left = 3
        Top = 0
        Width = 220
        Height = 13
        Caption = 'Paste YouTube links separated by line breaks:'
      end
      object cmbGrabbingMethod: TComboBox
        Left = 104
        Top = 95
        Width = 177
        Height = 21
        Style = csDropDownList
        Anchors = [akLeft, akRight, akBottom]
        ItemHeight = 13
        TabOrder = 1
        OnCloseUp = cmbGrabbingMethodCloseUp
        Items.Strings = (
          'Download'
          'Get Embed Code')
      end
      object cmbQuality: TComboBox
        Left = 104
        Top = 122
        Width = 177
        Height = 21
        Style = csDropDownList
        Anchors = [akLeft, akRight, akBottom]
        ItemHeight = 13
        TabOrder = 2
      end
      object memLinks: TMemo
        Left = 3
        Top = 19
        Width = 278
        Height = 70
        Anchors = [akLeft, akTop, akRight, akBottom]
        HideSelection = False
        ScrollBars = ssBoth
        TabOrder = 0
        WordWrap = False
      end
    end
  end
  inline pnlProgress: TProgressPanel
    Tag = 1
    AlignWithMargins = True
    Left = 8
    Top = 182
    Width = 449
    Height = 178
    Margins.Left = 8
    Margins.Top = 0
    Margins.Right = 8
    Margins.Bottom = 8
    Align = alBottom
    TabOrder = 1
    ExplicitLeft = 8
    ExplicitTop = 182
    ExplicitWidth = 449
    ExplicitHeight = 178
    inherited bvlTitle: TBevel
      Width = 452
      ExplicitWidth = 452
    end
    inherited lblOvrPercent: TLabel
      Left = 407
      ExplicitLeft = 407
    end
    inherited lblOperation: TLabel
      Width = 401
      ExplicitWidth = 401
    end
    inherited lblCurPercent: TLabel
      Left = 407
      ExplicitLeft = 407
    end
    inherited lblOvrCompleted: TLabel
      Width = 296
      ExplicitWidth = 296
    end
    inherited lblOvrTimeleft: TLabel
      Left = 311
      ExplicitLeft = 311
    end
    inherited lblCurCompleted: TLabel
      Width = 296
      ExplicitWidth = 296
    end
    inherited lblCurTimeleft: TLabel
      Left = 302
      ExplicitLeft = 302
    end
    inherited lblOvrElapsed: TLabel
      Left = 311
      ExplicitLeft = 311
    end
    inherited lblCurElapsed: TLabel
      Left = 311
      ExplicitLeft = 311
    end
    inherited pbOverall: TProgressBar
      Width = 449
      ExplicitWidth = 449
    end
    inherited pbCurrent: TProgressBar
      Width = 449
      ExplicitWidth = 449
    end
    inherited btnSkip: TButton
      Left = 293
      ExplicitLeft = 293
    end
    inherited btnStop: TButton
      Left = 374
      ExplicitLeft = 374
    end
  end
  object ProgressTimer: TTimer
    Enabled = False
    OnTimer = ProgressTimerTimer
    Left = 168
    Top = 48
  end
end
