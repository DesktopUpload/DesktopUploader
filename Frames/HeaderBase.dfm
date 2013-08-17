object HeaderFrameBase: THeaderFrameBase
  Left = 0
  Top = 0
  Width = 386
  Height = 65
  Color = clWhite
  ParentBackground = False
  ParentColor = False
  TabOrder = 0
  DesignSize = (
    386
    65)
  object imgLogo: TImage
    Tag = 1
    Left = 8
    Top = 8
    Width = 137
    Height = 48
    Cursor = crHandPoint
    AutoSize = True
    Transparent = True
    OnClick = imgLogoClick
  end
  object lblVersion: TLabel
    Tag = 1
    Left = 151
    Top = 47
    Width = 224
    Height = 13
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Caption = 'Desktop Uploader v1.0'
    ShowAccelChar = False
  end
  object BottomLine: TBevel
    Left = 0
    Top = 58
    Width = 386
    Height = 7
    Anchors = [akLeft, akTop, akRight]
    Shape = bsBottomLine
  end
end
