object UploadProperties: TUploadProperties
  Left = 0
  Top = 0
  Width = 137
  Height = 153
  TabOrder = 0
  DesignSize = (
    137
    153)
  object lblCategories: TLabel
    Left = 0
    Top = 19
    Width = 48
    Height = 13
    Caption = 'Channels:'
  end
  object clbCategories: TCheckListBox
    Left = 0
    Top = 38
    Width = 137
    Height = 75
    Anchors = [akLeft, akTop, akRight, akBottom]
    DoubleBuffered = False
    ItemHeight = 13
    ParentDoubleBuffered = False
    TabOrder = 1
  end
  object rgpBroadcast: TRadioGroup
    Left = 0
    Top = 114
    Width = 137
    Height = 39
    Anchors = [akLeft, akRight, akBottom]
    Caption = ' Broadcast: '
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      'Public'
      'Private')
    TabOrder = 3
  end
  inline Title: TGroupTitle
    Left = 0
    Top = 0
    Width = 137
    Height = 13
    TabOrder = 0
    ExplicitWidth = 137
    inherited Bevel: TBevel
      Left = 0
      Width = 137
      ExplicitLeft = 0
      ExplicitWidth = 137
    end
    inherited Label: TLabel
      Width = 85
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Upload Properties'
      ExplicitWidth = 85
    end
  end
  object cbxCategory: TComboBox
    Left = 0
    Top = 38
    Width = 137
    Height = 21
    Style = csDropDownList
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 13
    TabOrder = 2
    Visible = False
  end
end
