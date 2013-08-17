/*---------------------------------------------------------------------------
$Id: AboutBase.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef AboutBaseH
#define AboutBaseH
//----------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <pngimage.hpp>
#include "Custom/Custom.h"
#include "Header.h"
#include "HeaderBase.h"
#pragma hdrstop

#include "Product.h"

//----------------------------------------------------------------------------
class TAboutBoxBase : public TForm
{
__published:
	TButton *OKButton;
	THeaderFrame *pnlHeader;
	TLabel *lblProduct;
	TLabel *lblCopyright;
	TLabel *Label2;
	TLinkLabel *lnkWeb;
	TLabel *lblLicense;
	TLabel *lblComments;
	void __fastcall FormShow(TObject *Sender);
   	void __fastcall lnkWebLinkClick(TObject *Sender, const UnicodeString Link, TSysLinkType LinkType);
private:
public:
	virtual __fastcall TAboutBoxBase(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAboutBoxBase *AboutBoxBase;
//----------------------------------------------------------------------------
#endif    
