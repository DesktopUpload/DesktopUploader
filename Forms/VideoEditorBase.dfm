object VideoEditorFormBase: TVideoEditorFormBase
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Add Video'
  ClientHeight = 401
  ClientWidth = 417
  Color = clBtnFace
  DoubleBuffered = True
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  ShowHint = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  DesignSize = (
    417
    401)
  PixelsPerInch = 96
  TextHeight = 13
  object btnOK: TButton
    Left = 251
    Top = 367
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object btnCancel: TButton
    Left = 334
    Top = 367
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object Pages: TPageControl
    Left = 8
    Top = 8
    Width = 401
    Height = 345
    ActivePage = Main
    Anchors = [akLeft, akTop, akRight, akBottom]
    DoubleBuffered = False
    ParentDoubleBuffered = False
    TabOrder = 0
    object Main: TTabSheet
      Caption = 'Main'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object pnlTorrent: TPanel
        Left = 0
        Top = 263
        Width = 393
        Height = 39
        Align = alBottom
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 3
        DesignSize = (
          393
          39)
        object lblTorrent: TLabel
          Left = 8
          Top = 19
          Width = 43
          Height = 13
          Caption = 'Torrent: '
          Transparent = True
          OnClick = btnTorrentBrowseClick
        end
        object Bevel5: TBevel
          Left = 8
          Top = 6
          Width = 377
          Height = 2
          Anchors = [akLeft, akTop, akRight]
          Shape = bsTopLine
          ExplicitWidth = 369
        end
        object btnTorrentBrowse: TButton
          Left = 309
          Top = 12
          Width = 75
          Height = 25
          Anchors = [akTop, akRight]
          Caption = 'Browse...'
          TabOrder = 1
          OnClick = btnTorrentBrowseClick
        end
        object edtTorrent: TEdit
          Left = 57
          Top = 14
          Width = 246
          Height = 21
          TabStop = False
          Anchors = [akLeft, akTop, akRight]
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnDblClick = btnTorrentBrowseClick
          OnEnter = edtTorrentEnter
          OnExit = edtTorrentExit
        end
      end
      object pnlMain: TPanel
        Left = 0
        Top = 0
        Width = 393
        Height = 163
        Align = alClient
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 0
        DesignSize = (
          393
          163)
        object lblTitle: TLabel
          Left = 8
          Top = 57
          Width = 24
          Height = 13
          Caption = 'Title:'
        end
        object lblDescription: TLabel
          Left = 8
          Top = 81
          Width = 57
          Height = 13
          Caption = 'Description:'
        end
        object lblTags: TLabel
          Left = 8
          Top = 144
          Width = 27
          Height = 13
          Anchors = [akLeft, akBottom]
          Caption = 'Tags:'
          ExplicitTop = 158
        end
        object lblFile: TLabel
          Left = 8
          Top = 11
          Width = 23
          Height = 13
          Caption = 'File: '
          Transparent = True
          OnClick = btnBrowseClick
        end
        object btnBrowse: TButton
          Left = 309
          Top = 6
          Width = 75
          Height = 25
          Anchors = [akTop, akRight]
          Caption = 'Browse...'
          TabOrder = 1
          OnClick = btnBrowseClick
        end
        object edtFile: TEdit
          Left = 57
          Top = 8
          Width = 245
          Height = 21
          TabStop = False
          Anchors = [akLeft, akTop, akRight]
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnDblClick = btnBrowseClick
          OnEnter = edtFileEnter
          OnExit = edtFileExit
        end
        object edtTags: TEdit
          Left = 57
          Top = 141
          Width = 168
          Height = 21
          Hint = 'Enter one or more tags separated by spaces.'
          Anchors = [akLeft, akRight, akBottom]
          TabOrder = 4
        end
        object edtTitle: TEdit
          Left = 57
          Top = 54
          Width = 168
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 2
        end
        object memDescription: TMemo
          Left = 8
          Top = 100
          Width = 217
          Height = 35
          Hint = 'Try to make description both relevant and lengthy.'
          Anchors = [akLeft, akTop, akRight, akBottom]
          ScrollBars = ssVertical
          TabOrder = 3
        end
        inline UploadProperties: TUploadProperties
          Left = 239
          Top = 35
          Width = 145
          Height = 127
          Anchors = [akTop, akRight, akBottom]
          TabOrder = 5
          ExplicitLeft = 239
          ExplicitTop = 35
          ExplicitWidth = 145
          ExplicitHeight = 127
          inherited clbCategories: TCheckListBox
            Width = 145
            Height = 44
            ExplicitWidth = 145
            ExplicitHeight = 44
          end
          inherited rgpBroadcast: TRadioGroup
            Top = 88
            Width = 145
            ExplicitTop = 88
            ExplicitWidth = 145
          end
          inherited Title: TGroupTitle
            Width = 145
            ExplicitWidth = 145
            inherited Bevel: TBevel
              Width = 145
              ExplicitWidth = 145
            end
          end
          inherited cbxCategory: TComboBox
            Width = 145
            ExplicitWidth = 145
          end
        end
        inline gtInfo: TGroupTitle
          Left = 8
          Top = 35
          Width = 217
          Height = 13
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 6
          ExplicitLeft = 8
          ExplicitTop = 35
          ExplicitWidth = 217
          inherited Bevel: TBevel
            Width = 254
            ExplicitWidth = 246
          end
          inherited Label: TLabel
            Width = 56
            Caption = 'Information'
            ExplicitWidth = 56
          end
        end
      end
      object pnlBottomField: TPanel
        Left = 0
        Top = 302
        Width = 393
        Height = 15
        Align = alBottom
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 4
      end
      object pnlFormat: TPanel
        Left = 0
        Top = 163
        Width = 393
        Height = 61
        Align = alBottom
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 1
        DesignSize = (
          393
          61)
        inline gtFormat: TGroupTitle
          Left = 8
          Top = 5
          Width = 377
          Height = 13
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 0
          ExplicitLeft = 8
          ExplicitTop = 5
          ExplicitWidth = 377
          inherited Bevel: TBevel
            Width = 414
            ExplicitWidth = 246
          end
          inherited Label: TLabel
            Width = 70
            Caption = 'Upload Format'
            ExplicitWidth = 70
          end
        end
        object cmbUploadFormat: TComboBox
          Left = 8
          Top = 24
          Width = 217
          Height = 21
          Style = csDropDownList
          Anchors = [akLeft, akTop, akRight]
          ItemHeight = 0
          TabOrder = 1
          OnChange = cmbUploadFormatChange
        end
        object pnlVideo: TPanel
          Left = 239
          Top = 24
          Width = 120
          Height = 40
          Anchors = [akTop, akRight]
          BevelEdges = []
          BevelOuter = bvNone
          TabOrder = 2
          object chkDeinterlace: TCheckBox
            Left = 0
            Top = 22
            Width = 89
            Height = 17
            Caption = 'Deinterlace'
            TabOrder = 1
            OnClick = chkDeinterlaceClick
          end
          object chkPass2: TCheckBox
            Left = 0
            Top = -1
            Width = 106
            Height = 17
            Caption = '2-Pass Encoding'
            TabOrder = 0
            OnClick = chkPass2Click
          end
        end
      end
      object pnlPicture: TPanel
        Left = 0
        Top = 224
        Width = 393
        Height = 39
        Align = alBottom
        BevelEdges = []
        BevelOuter = bvNone
        TabOrder = 2
        DesignSize = (
          393
          39)
        object lblPicture: TLabel
          Left = 8
          Top = 17
          Width = 37
          Height = 13
          Caption = 'Picture:'
          Transparent = True
          OnClick = btnPictureBrowseClick
        end
        object Bevel1: TBevel
          Left = 8
          Top = 6
          Width = 377
          Height = 2
          Anchors = [akLeft, akTop, akRight]
          Shape = bsTopLine
          ExplicitWidth = 369
        end
        object btnPictureBrowse: TButton
          Left = 310
          Top = 12
          Width = 75
          Height = 25
          Anchors = [akTop, akRight]
          Caption = 'Browse...'
          TabOrder = 1
          OnClick = btnPictureBrowseClick
        end
        object edtPicture: TEdit
          Left = 57
          Top = 14
          Width = 246
          Height = 21
          TabStop = False
          Anchors = [akLeft, akTop, akRight]
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnDblClick = btnPictureBrowseClick
          OnEnter = edtPictureEnter
          OnExit = edtPictureExit
        end
      end
    end
    object Optional: TTabSheet
      Caption = 'Optional'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      DesignSize = (
        393
        317)
      object lblDate: TLabel
        Left = 8
        Top = 32
        Width = 27
        Height = 13
        Caption = 'Date:'
      end
      object lblCountry: TLabel
        Left = 8
        Top = 58
        Width = 43
        Height = 13
        Caption = 'Country:'
      end
      object lblLocation: TLabel
        Left = 8
        Top = 85
        Width = 44
        Height = 13
        Caption = 'Location:'
      end
      object dtpDate: TDateTimePicker
        Left = 104
        Top = 27
        Width = 281
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        Date = 0.000011574074074074
        Time = 0.000011574074074074
        ShowCheckbox = True
        Checked = False
        TabOrder = 0
      end
      object cmbCountry: TComboBox
        Left = 104
        Top = 54
        Width = 281
        Height = 21
        Style = csDropDownList
        Anchors = [akLeft, akTop, akRight]
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 1
        Items.Strings = (
          ''
          'Afghanistan'
          'Albania'
          'Algeria'
          'Andorra'
          'Angola'
          'Antigua & Deps'
          'Argentina'
          'Armenia'
          'Australia'
          'Austria'
          'Azerbaijan'
          'Bahamas'
          'Bahrain'
          'Bangladesh'
          'Barbados'
          'Belarus'
          'Belgium'
          'Belize'
          'Benin'
          'Bhutan'
          'Bolivia'
          'Bosnia Herzegovina'
          'Botswana'
          'Brazil'
          'Brunei'
          'Bulgaria'
          'Burkina'
          'Burundi'
          'Cambodia'
          'Cameroon'
          'Canada'
          'Cape Verde'
          'Central African Rep'
          'Chad'
          'Chile'
          'China'
          'Colombia'
          'Comoros'
          'Congo'
          'Costa Rica'
          'Croatia'
          'Cuba'
          'Cyprus'
          'Czech Republic'
          'Denmark'
          'Djibouti'
          'Dominica'
          'Dominican Republic'
          'East Timor'
          'Ecuador'
          'Egypt'
          'El Salvador'
          'Equatorial Guinea'
          'Eritrea'
          'Estonia'
          'Ethiopia'
          'Fiji'
          'Finland'
          'France'
          'Gabon'
          'Gambia'
          'Georgia'
          'Germany'
          'Ghana'
          'Greece'
          'Grenada'
          'Guatemala'
          'Guinea'
          'Guinea-Bissau'
          'Guyana'
          'Haiti'
          'Honduras'
          'Hungary'
          'Iceland'
          'India'
          'Indonesia'
          'Iran'
          'Iraq'
          'Ireland'
          'Israel'
          'Italy'
          'Ivory Coast'
          'Jamaica'
          'Japan'
          'Jordan'
          'Kazakhstan'
          'Kenya'
          'Kiribati'
          'Korea North'
          'Korea South'
          'Kosovo'
          'Kuwait'
          'Kyrgyzstan'
          'Laos'
          'Latvia'
          'Lebanon'
          'Lesotho'
          'Liberia'
          'Libya'
          'Liechtenstein'
          'Lithuania'
          'Luxembourg'
          'Macedonia'
          'Madagascar'
          'Malawi'
          'Malaysia'
          'Maldives'
          'Mali'
          'Malta'
          'Marshall Islands'
          'Mauritania'
          'Mauritius'
          'Mexico'
          'Micronesia'
          'Moldova'
          'Monaco'
          'Mongolia'
          'Montenegro'
          'Morocco'
          'Mozambique'
          'Myanmar'
          'Namibia'
          'Nauru'
          'Nepal'
          'Netherlands'
          'New Zealand'
          'Nicaragua'
          'Niger'
          'Nigeria'
          'Norway'
          'Oman'
          'Pakistan'
          'Palau'
          'Panama'
          'Papua New Guinea'
          'Paraguay'
          'Peru'
          'Philippines'
          'Poland'
          'Portugal'
          'Qatar'
          'Romania'
          'Russian Federation'
          'Rwanda'
          'St Kitts & Nevis'
          'St Lucia'
          'Saint Vincent & the Grenadines'
          'Samoa'
          'San Marino'
          'Sao Tome & Principe'
          'Saudi Arabia'
          'Senegal'
          'Serbia'
          'Seychelles'
          'Sierra Leone'
          'Singapore'
          'Slovakia'
          'Slovenia'
          'Solomon Islands'
          'Somalia'
          'South Africa'
          'Spain'
          'Sri Lanka'
          'Sudan'
          'Suriname'
          'Swaziland'
          'Sweden'
          'Switzerland'
          'Syria'
          'Taiwan'
          'Tajikistan'
          'Tanzania'
          'Thailand'
          'Togo'
          'Tonga'
          'Trinidad & Tobago'
          'Tunisia'
          'Turkey'
          'Turkmenistan'
          'Tuvalu'
          'Uganda'
          'Ukraine'
          'United Arab Emirates'
          'United Kingdom'
          'United States'
          'Uruguay'
          'Uzbekistan'
          'Vanuatu'
          'Vatican City'
          'Venezuela'
          'Vietnam'
          'Yemen'
          'Zambia'
          'Zimbabwe')
      end
      object edtLocation: TEdit
        Left = 104
        Top = 81
        Width = 281
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 2
      end
      object chkAllowComment: TCheckBox
        Left = 8
        Top = 135
        Width = 369
        Height = 17
        Caption = 'Allow Comments'
        Checked = True
        State = cbChecked
        TabOrder = 3
      end
      object chkAllowVoting: TCheckBox
        Left = 8
        Top = 158
        Width = 369
        Height = 17
        Caption = 'Allow Comments Voting'
        Checked = True
        State = cbChecked
        TabOrder = 4
      end
      object chkAllowRating: TCheckBox
        Left = 8
        Top = 181
        Width = 369
        Height = 17
        Caption = 'Yes, Allow Rating on this video'
        Checked = True
        State = cbChecked
        TabOrder = 5
      end
      object chkAllowEmbedding: TCheckBox
        Left = 8
        Top = 204
        Width = 369
        Height = 17
        Caption = 'Yes, People can play this video on other websites'
        Checked = True
        State = cbChecked
        TabOrder = 6
      end
      inline gtOptional1: TGroupTitle
        Left = 8
        Top = 8
        Width = 377
        Height = 13
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 7
        ExplicitLeft = 8
        ExplicitTop = 8
        ExplicitWidth = 377
        inherited Bevel: TBevel
          Width = 414
          ExplicitWidth = 246
        end
        inherited Label: TLabel
          Width = 87
          Caption = 'Date and Location'
          ExplicitWidth = 87
        end
      end
      inline gtOptional2: TGroupTitle
        Left = 8
        Top = 116
        Width = 377
        Height = 13
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 8
        ExplicitLeft = 8
        ExplicitTop = 116
        ExplicitWidth = 377
        inherited Bevel: TBevel
          Width = 414
          ExplicitWidth = 246
        end
        inherited Label: TLabel
          Width = 76
          Caption = 'Sharing Options'
          ExplicitWidth = 76
        end
      end
    end
  end
  object dlgOpen: TOpenDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Title = 'Open Media File'
    Left = 152
    Top = 34
  end
  object dlgSave: TSaveDialog
    DefaultExt = 'flv'
    Filter = 'Flash Video files (*.flv)|*.FLV'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofEnableSizing, ofDontAddToRecent]
    Left = 200
    Top = 35
  end
  object dlgTorrent: TOpenDialog
    DefaultExt = 'torrent'
    Filter = 'Torrent files (*.torrent)|*.TORRENT'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Title = 'Open Torrent File'
    Left = 96
    Top = 306
  end
  object dlgPicture: TOpenDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Title = 'Open Picture File'
    Left = 200
    Top = 266
  end
end
