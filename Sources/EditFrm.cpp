// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditFrm.h"
#include "Editor.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditFrame *EditFrame;

// ---------------------------------------------------------------------------
__fastcall TEditFrame::TEditFrame(TWinControl* Owner, const TColumns &aColumn)
	: TFrame(Owner) {
	Parent = Owner;
	Name = "_" + UIntToStr(Cardinal(this));
	FieldName->Caption = aColumn.DataField;
	FieldEditor->DataField = aColumn.DataField;
}
// ---------------------------------------------------------------------------
