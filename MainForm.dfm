object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'MiniPs'
  ClientHeight = 600
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
    Left = 0
    Top = 0
    Width = 801
    Height = 592
    Proportional = True
  end
  object MainMenu: TMainMenu
    object File: TMenuItem
      Caption = 'File'
      object New: TMenuItem
        Caption = 'New'
      end
      object Save: TMenuItem
        Caption = 'Save'
      end
      object Load: TMenuItem
        Caption = 'Load'
        OnClick = LoadClick
      end
    end
    object Edit: TMenuItem
      Caption = 'Edit'
    end
    object Filter1: TMenuItem
      Caption = 'Filter'
    end
  end
  object OpenDialogLoadImage: TOpenDialog
    Left = 32
  end
end
