object ProgressPanel: TProgressPanel
  Left = 0
  Top = 0
  Width = 354
  Height = 177
  TabOrder = 0
  DesignSize = (
    354
    177)
  object bvlTitle: TBevel
    Left = -3
    Top = 7
    Width = 357
    Height = 2
    Anchors = [akLeft, akTop, akRight]
    Shape = bsTopLine
  end
  object lblTitle: TLabel
    Left = 0
    Top = 0
    Width = 27
    Height = 13
    Caption = 'Title: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ShowAccelChar = False
    Transparent = False
  end
  object lblOverallProgress: TLabel
    Left = 0
    Top = 14
    Width = 83
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Overall Progress:'
  end
  object lblOvrPercent: TLabel
    Left = 312
    Top = 14
    Width = 42
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = '100%'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ShowAccelChar = False
  end
  object lblOperation: TLabel
    Left = 0
    Top = 81
    Width = 306
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    AutoSize = False
    Caption = 'Uploading clip 99 of 100: 1234567890'
    EllipsisPosition = epEndEllipsis
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ShowAccelChar = False
  end
  object lblCurPercent: TLabel
    Left = 312
    Top = 81
    Width = 42
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = '100%'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lblOvrCompleted: TLabel
    Left = 0
    Top = 48
    Width = 201
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    AutoSize = False
    Caption = 'Completed: 100 MB of 100 GB'
    ShowAccelChar = False
  end
  object lblOvrTimeleft: TLabel
    Left = 216
    Top = 62
    Width = 138
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = 'Time Left: 111 d 10:00:00'
    ShowAccelChar = False
  end
  object lblCurCompleted: TLabel
    Left = 0
    Top = 115
    Width = 201
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    AutoSize = False
    Caption = 'Completed: 100 MB of 100 GB'
    ShowAccelChar = False
  end
  object lblCurTimeleft: TLabel
    Left = 207
    Top = 129
    Width = 147
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = 'Time Left: 111 d 10:00:00'
    ShowAccelChar = False
  end
  object lblOvrElapsed: TLabel
    Left = 216
    Top = 48
    Width = 138
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = 'Elapsed: 111 d 10:00:00'
    ShowAccelChar = False
  end
  object lblCurElapsed: TLabel
    Left = 216
    Top = 115
    Width = 138
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = 'Elapsed: 111 d 10:00:00'
    ShowAccelChar = False
  end
  object pbOverall: TProgressBar
    Left = 0
    Top = 28
    Width = 354
    Height = 19
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
  end
  object pbCurrent: TProgressBar
    Left = 0
    Top = 95
    Width = 354
    Height = 19
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 1
  end
  object btnSkip: TButton
    Left = 198
    Top = 152
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Skip'
    TabOrder = 3
    OnClick = btnSkipClick
  end
  object btnStop: TButton
    Left = 279
    Top = 152
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    TabOrder = 2
    OnClick = btnStopClick
  end
end
