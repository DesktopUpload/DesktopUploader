//---------------------------------------------------------------------------

#ifndef TGroupTitleH
#define TGroupTitleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TGroupTitle : public TFrame
{
__published:	// IDE-managed Components
	TLabel *Label;
	TBevel *Bevel;
private:	// User declarations
public:		// User declarations
	__fastcall TGroupTitle(TComponent* Owner);
	void __fastcall Init();
};
//---------------------------------------------------------------------------
extern PACKAGE TGroupTitle *GroupTitle;
//---------------------------------------------------------------------------
#endif
