object EditFrame: TEditFrame
  Left = 0
  Top = 0
  Width = 451
  Height = 27
  Align = alTop
  AutoSize = True
  Padding.Bottom = 6
  TabOrder = 0
  object FieldName: TLabel
    Left = 10
    Top = 3
    Width = 49
    Height = 13
    Caption = 'FieldName'
  end
  object FieldEditor: TDBEdit
    Left = 100
    Top = 0
    Width = 250
    Height = 21
    DataSource = CellEditor.DataSource
    TabOrder = 0
  end
end
