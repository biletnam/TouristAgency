//---------------------------------------------------------------------------

#ifndef ConnectionH
#define ConnectionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TConModule : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection;
private:	// User declarations
public:		// User declarations
	__fastcall TConModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConModule *ConModule;
//---------------------------------------------------------------------------
#endif
