// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Catalog.h"
#include "Metadata.h"
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
		Caption = aTable.CaptionTable;
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
		CatalogItem->Add(new TDBMenuItem(this, Mdata[i]));
	}
}
// ---------------------------------------------------------------------------
