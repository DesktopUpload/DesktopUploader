/*---------------------------------------------------------------------------
$Id: About.h 185 2009-05-01 12:58:01Z anton $
---------------------------------------------------------------------------*/
#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AboutBase.h"
#include <pngimage.hpp>
#include "Header.h"
#include "HeaderBase.h"
//---------------------------------------------------------------------------
class TAboutBox : public TAboutBoxBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TAboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutBox *AboutBox;
//---------------------------------------------------------------------------
#endif
