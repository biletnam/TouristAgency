// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Editor.h"
#include "Connection.h"
#include "EditFrm.h"
#include "BoxFrm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBQuery"
#pragma resource "*.dfm"
TCellEditor *CellEditor;

// ---------------------------------------------------------------------------
static const String GenSelectSQL(const TTable &aTable) {
	String res = "SELECT ";
	for (size_t i = 0; i < aTable.size(); i++) {
		if (i > 0)
			res += ", ";
		res += aTable[i].DataField;
	}
	return res;
}

// ---------------------------------------------------------------------------
static const String GenWhereSQL(const TTable &aTable, TADOQuery *aIBQuery) {
	String res = "WHERE ";
	for (size_t i = 0; i < aTable.size(); i++) {
		if (i > 0)
			res += " AND ";

		String field = aIBQuery->FieldByName(aTable[i].DataField)->Text;
		res += "CStr(" + aTable[i].DataField + ") = '" + field + "'";
	}
	return res;
}

// ---------------------------------------------------------------------------
static const String GenFromSQL(const TTable &aTable) {
	return "FROM " + aTable.NameTable;
}

// ---------------------------------------------------------------------------
__fastcall TCellEditor::TCellEditor(TComponent* Owner, CreateType aCType,
	const TTable &aTable, TADOQuery *aIBQuery)
	: TForm(Owner), fADOQuery(aIBQuery) {
	Caption = "�������� ������� \"" + aTable.NameTable + "\"";
	for (size_t i = 0; i < aTable.size(); i++) {
		if (!aTable[i].Visible)
			continue;
		if (aTable[i].Primary)
			TBoxFrame(EditPanel, aTable[i]);
		else
			TEditFrame(EditPanel, aTable[i]);
	}

	ADOQuery->SQL->Append(GenSelectSQL(aTable));
	ADOQuery->SQL->Append(GenFromSQL(aTable));
	ADOQuery->SQL->Append(GenWhereSQL(aTable, fADOQuery));
	ADOQuery->Open();

	switch (aCType) {
	case ADD:
		ADOQuery->Insert();
		break;
	case REMOVE:
		try {
			ADOQuery->Delete();
		}
		catch (...) {
			// TODO: ���������� ����������
		}
		SaveBtnClick(this);
		break;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TCellEditor::SaveBtnClick(TObject *Sender) {
	fADOQuery->Close();
	try {
		if (ADOQuery->Modified)
			ADOQuery->Post();
	}
	catch (...) {
		// TODO: ���������� ����������
	}
	fADOQuery->Open();
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TCellEditor::FormClose(TObject *Sender, TCloseAction &Action) {
	Action = caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TCellEditor::CancelBtnClick(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------
