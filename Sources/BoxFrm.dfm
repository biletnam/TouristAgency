object BoxFrame: TBoxFrame
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
  object FieldLookup: TDBLookupComboBox
    Left = 100
    Top = 0
    Width = 250
    Height = 21
    DataSource = CellEditor.DataSource
    ListSource = ListSource
    TabOrder = 0
  end
  object ADOQuery: TADOQuery
    Connection = ConModule.ADOConnection
    Parameters = <>
    Left = 168
    Top = 32
  end
  object ListSource: TDataSource
    DataSet = ADOQuery
    Left = 64
    Top = 32
  end
end
