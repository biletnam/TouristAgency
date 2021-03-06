// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Catalog.h"
#include "Metadata.h"
#include "Selling.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAgency *Agency;

// ---------------------------------------------------------------------------
class TDBMenuItem : public TMenuItem {
private:
	TDirectory *fModalWin;
	const TTable &fTable;

public:
	__fastcall TDBMenuItem(TComponent* Owner, const TTable &aTable)
		: TMenuItem(Owner), fTable(aTable) {
		Caption = aTable.NameTable;
	}

	void __fastcall Click(void) {
		if (!Checked) {
			fModalWin = new TDirectory(this, fTable);
			Checked = true;
		}

		fModalWin->Show();
	}
};

// ---------------------------------------------------------------------------
__fastcall TAgency::TAgency(TComponent* Owner) : TForm(Owner) {
	for (size_t i = 0; i < Mdata.size(); i++) {
		TDBMenuItem *menu = new TDBMenuItem(this, Mdata[i]);
		if (Mdata[i].ReadOnly)
			ReportItem->Add(menu);
		else
			CatalogItem->Add(menu);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TAgency::SaleItemClick(TObject *Sender) {
	SellingTickets->ShowModal();
}
// ---------------------------------------------------------------------------
