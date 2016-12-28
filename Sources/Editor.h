//---------------------------------------------------------------------------

#ifndef EditorH
#define EditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "Metadata.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------

enum CreateType {ADD, EDIT, REMOVE};

class TCellEditor : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSource;
	TADOQuery *ADOQuery;
	TBitBtn *SaveBtn;
	TBitBtn *CancelBtn;
	TGroupBox *EditPanel;
	TGroupBox *ControlPanel;
	void __fastcall SaveBtnClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CancelBtnClick(TObject *Sender);
private:	// User declarations
	TADOQuery *fADOQuery;
public:		// User declarations
	__fastcall TCellEditor(TComponent* Owner, CreateType aCType,
	const TTable &aTable, TADOQuery *aIBQuery);
};
//---------------------------------------------------------------------------
extern PACKAGE TCellEditor *CellEditor;
//---------------------------------------------------------------------------
#endif
