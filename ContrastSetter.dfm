object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Contrast'
  ClientHeight = 110
  ClientWidth = 324
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 123
    Top = 29
    Width = 102
    Height = 13
    Caption = 'Give a contrast value'
  end
  object ContrastInputValue: TEdit
    Left = 96
    Top = 48
    Width = 153
    Height = 21
    TabOrder = 0
  end
  object ConfirmContrast: TButton
    Left = 136
    Top = 77
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 1
    OnClick = ConfirmContrastClick
  end
end
