/*---------------------------------------------------------------------------
$Id: HeaderBase.h 185 2009-05-01 12:58:01Z anton $
---------------------------------------------------------------------------*/
#ifndef HeaderBaseH
#define HeaderBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class THeaderFrameBase : public TFrame
{
__published:	// IDE-managed Components
	TImage *imgLogo;
	TLabel *lblVersion;
	TBevel *BottomLine;
	void __fastcall imgLogoClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THeaderFrameBase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THeaderFrameBase *HeaderFrameBase;
//---------------------------------------------------------------------------
#endif
