//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Main.cpp", Agency);
USEFORM("Editor.cpp", CellEditor);
USEFORM("Catalog.cpp", Directory);
USEFORM("BoxFrm.cpp", BoxFrame); /* TFrame: File Type */
USEFORM("EditFrm.cpp", EditFrame); /* TFrame: File Type */
USEFORM("Connection.cpp", ConModule); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TAgency), &Agency);
		Application->CreateForm(__classid(TConModule), &ConModule);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
