object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'MiniPS'
  ClientHeight = 480
  ClientWidth = 865
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
    Width = 601
    Height = 481
    Proportional = True
  end
  object HistogramChart: TChart
    Left = 607
    Top = 0
    Width = 257
    Height = 177
    Title.Text.Strings = (
      'Histogram')
    TabOrder = 0
    Visible = False
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TFastLineSeries
      SeriesColor = clRed
      Title = 'Red'
      LinePen.Color = clRed
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TFastLineSeries
      SeriesColor = clGreen
      Title = 'Green'
      LinePen.Color = clGreen
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series3: TFastLineSeries
      SeriesColor = clBlue
      Title = 'Blue'
      LinePen.Color = clBlue
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
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
    object Color1: TMenuItem
      Caption = 'Color'
      object RedChannel1: TMenuItem
        Caption = 'Red Channel'
        OnClick = RedChannel1Click
      end
      object GreenChannel1: TMenuItem
        Caption = 'Green Channel'
        OnClick = GreenChannel1Click
      end
      object BlueChannel1: TMenuItem
        Caption = 'Blue Channel'
        OnClick = BlueChannel1Click
      end
      object Grayscale1: TMenuItem
        Caption = 'Grayscale'
        OnClick = Grayscale1Click
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
        OnClick = Histogram1Click
      end
      object RecomputeHistogram1: TMenuItem
        Caption = 'Recompute Histogram'
        OnClick = RecomputeHistogram1Click
      end
      object Stretch1: TMenuItem
        Caption = 'Stretch'
        OnClick = Stretch1Click
      end
      object Proportional1: TMenuItem
        Caption = 'Proportional'
        OnClick = Proportional1Click
      end
      object ZoomIn1: TMenuItem
        Caption = 'Zoom In'
        OnClick = ZoomIn1Click
      end
      object ZoomOut1: TMenuItem
        Caption = 'Zoom Out'
        OnClick = ZoomOut1Click
      end
    end
    object Reset1: TMenuItem
      Caption = 'Reset'
      OnClick = Reset1Click
    end
    object About1: TMenuItem
      Caption = 'About'
      OnClick = About1Click
    end
  end
  object OpenDialogLoadImage: TOpenDialog
    Left = 32
  end
  object SaveDialog1: TSaveDialog
    Left = 64
  end
end
