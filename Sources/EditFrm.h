//---------------------------------------------------------------------------

#ifndef EditFrmH
#define EditFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "Metadata.h"
//---------------------------------------------------------------------------
class TEditFrame : public TFrame
{
__published:	// IDE-managed Components
	TLabel *FieldName;
	TDBEdit *FieldEditor;
private:	// User declarations
public:		// User declarations
	    __fastcall TEditFrame(TWinControl* Owner, const TColumns &aColumn);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditFrame *EditFrame;
//---------------------------------------------------------------------------
#endif
