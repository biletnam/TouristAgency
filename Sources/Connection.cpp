// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Connection.h"
	// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConModule *ConModule;

// ---------------------------------------------------------------------------
__fastcall TConModule::TConModule(TComponent* Owner) : TDataModule(Owner) {
}
// ---------------------------------------------------------------------------
