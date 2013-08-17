/*---------------------------------------------------------------------------
$Id: Header.h 185 2009-05-01 12:58:01Z anton $
---------------------------------------------------------------------------*/
#ifndef HeaderH
#define HeaderH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "HeaderBase.h"
#include <ExtCtrls.hpp>
#include <GIFImg.hpp>
//---------------------------------------------------------------------------
class THeaderFrame : public THeaderFrameBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall THeaderFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THeaderFrame *HeaderFrame;
//---------------------------------------------------------------------------
#endif
