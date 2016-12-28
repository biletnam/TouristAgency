Dim WshShell
Dim var

On Error Resume Next

Set WshShell = CreateObject("WScript.Shell")

var = WshShell.RegRead _ 
  ("HKEY_CURRENT_USER\Software\ODBC\ODBC.INI\ODBC Data Sources\TouristAgency Base")

If Not IsEmpty(var) Then
    MsgBox "Пользовательский DSN 'TouristAgency Base' существует."
Else
    MsgBox "Не существует."
End If