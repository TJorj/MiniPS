object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'MiniPS'
  ClientHeight = 540
  ClientWidth = 800
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object MainImageContainer: TImage
    Left = 216
    Top = 96
    Width = 385
    Height = 345
    Proportional = True
  end
  object MainMenu: TMainMenu
    object File: TMenuItem
      Caption = 'File'
      object New: TMenuItem
        Caption = 'New'
        OnClick = NewClick
      end
      object Save: TMenuItem
        Caption = 'Save'
        OnClick = SaveClick
      end
      object Load: TMenuItem
        Caption = 'Load'
        OnClick = LoadClick
      end
    end
    object Modify1: TMenuItem
      Caption = 'Edit'
      object Mirror1: TMenuItem
        Caption = 'Mirror'
        OnClick = Mirror1Click
      end
      object Flip1: TMenuItem
        Caption = 'Flip'
        OnClick = Flip1Click
      end
      object RotateClockwise901: TMenuItem
        Caption = 'Rotate Counterclockwise 90'
        OnClick = RotateClockwise901Click
      end
      object RotateClockwise1801: TMenuItem
        Caption = 'Rotate Counterclockwise 180'
        OnClick = RotateClockwise1801Click
      end
    end
    object Filter1: TMenuItem
      Caption = 'Filter'
      object None1: TMenuItem
        Caption = 'None'
        OnClick = None1Click
      end
      object Sepia1: TMenuItem
        Caption = 'Sepia'
        OnClick = Sepia1Click
      end
      object Negative1: TMenuItem
        Caption = 'Negative'
        OnClick = Negative1Click
      end
      object Metalic1: TMenuItem
        Caption = 'Metalic'
        OnClick = Metalic1Click
      end
    end
    object View1: TMenuItem
      Caption = 'View'
      object Histogram1: TMenuItem
        Caption = 'Histogram'
      end
    end
  end
  object OpenDialogLoadImage: TOpenDialog
    Left = 32
  end
  object SaveDialog1: TSaveDialog
    Left = 104
    Top = 16
  end
end
