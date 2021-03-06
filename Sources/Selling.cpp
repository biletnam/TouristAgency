// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Selling.h"
#include "Connection.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSellingTickets *SellingTickets;

// ---------------------------------------------------------------------------
__fastcall TSellingTickets::TSellingTickets(TComponent* Owner) : TForm(Owner) {
	for (int i = 0; i < SaleGrid->Columns->Count; i++) {
		TColumn *itm = SaleGrid->Columns->Items[i];
		itm->Width = 10 + Canvas->TextWidth(itm->Title->Caption);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TSellingTickets::SaleGridDrawColumnCell(TObject *Sender,
	const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State) {
	int MaxWidth = 10 + Canvas->TextWidth(Column->Field->Text);
	if (MaxWidth > Column->Width)
		Column->Width = MaxWidth;
}

// ---------------------------------------------------------------------------
void __fastcall TSellingTickets::SellBtnClick(TObject *Sender) {
	String param = SaleADODataSet->FieldByName("���")->Text;
	if (param.IsEmpty())
		return;

	SaleADODataSet->Close();
	PriceADODataSet->Close();

	SellADOCommand->Parameters->ParamByName("id")->Value = param;
	SellADOCommand->Execute();

	SaleADODataSet->Open();
	PriceADODataSet->Open();
}

// ---------------------------------------------------------------------------
void __fastcall TSellingTickets::FormShow(TObject *Sender) {
	SaleADODataSet->Open();
	PriceADODataSet->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TSellingTickets::FormClose(TObject *Sender,
	TCloseAction &Action) {
	SaleADODataSet->Close();
	PriceADODataSet->Close();
}
// ---------------------------------------------------------------------------
