//---------------------------------------------------------------------------

#ifndef BoxFrmH
#define BoxFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include "Metadata.h"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TBoxFrame : public TFrame
{
__published:	// IDE-managed Components
	TLabel *FieldName;
	TADOQuery *ADOQuery;
	TDataSource *ListSource;
	TDBLookupComboBox *FieldLookup;
private:	// User declarations
public:		// User declarations
	    __fastcall TBoxFrame(TWinControl* Owner, const TColumns &aColumn);
};
//---------------------------------------------------------------------------
extern PACKAGE TBoxFrame *BoxFrame;
//---------------------------------------------------------------------------
#endif
