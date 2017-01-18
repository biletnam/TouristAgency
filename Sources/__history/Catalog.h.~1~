//---------------------------------------------------------------------------

#ifndef CatalogH
#define CatalogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "Metadata.h"
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TDirectory : public TForm
{
__published:	// IDE-managed Components
	TPanel *ControlPanel;
	TPanel *GridPanel;
	TSpeedButton *AddBtn;
	TSpeedButton *EditBtn;
	TSpeedButton *DelBtn;
	TDBGrid *DBGrid;
	TDataSource *DataSource;
	TADOQuery *ADOQuery;
	TLabel *OrderLabel;
	TFilterComboBox *OrderWay;
	TFilterComboBox *OrderField;
	TSpeedButton *SearchBtn;
	TLabel *FilterLabel;
	TPanel *FilterPanel;
	TFilterComboBox *FilterField;
	TFilterComboBox *FilterWay;
	TEdit *FilterEdit;
	TSpeedButton *RefreshBtn;
	void __fastcall AddBtnClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SearchBtnClick(TObject *Sender);
	void __fastcall RefreshBtnClick(TObject *Sender);
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall EditBtnClick(TObject *Sender);
	void __fastcall DelBtnClick(TObject *Sender);
private:	// User declarations
	String fQuery;
	const TTable &fTable;
public:		// User declarations
	__fastcall TDirectory(TComponent* Owner, const TTable &aTable);
};
//---------------------------------------------------------------------------
extern PACKAGE TDirectory *Directory;
//---------------------------------------------------------------------------
#endif
