// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BoxFrm.h"
#include "Connection.h"
#include "Editor.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBoxFrame *BoxFrame;

// ---------------------------------------------------------------------------
__fastcall TBoxFrame::TBoxFrame(TWinControl* Owner, const TColumns &aColumn)
	: TFrame(Owner) {
	Parent = Owner;
	Name = "_" + UIntToStr(Cardinal(this)); ;
	FieldName->Caption = aColumn.CaptionField;
	FieldLookup->DataField = aColumn.DataField;
	FieldLookup->KeyField = aColumn.KeyField;
	FieldLookup->ListField = aColumn.ListField;
	ADOQuery->SQL->Append(Format("SELECT %s, %s FROM %s", OPENARRAY(TVarRec,
		(aColumn.KeyField, aColumn.ListField, aColumn.KeyTable))));
	ADOQuery->Open();
}
// ---------------------------------------------------------------------------
