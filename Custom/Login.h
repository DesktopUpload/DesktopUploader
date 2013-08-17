/*---------------------------------------------------------------------------
$Id: Login.h 185 2009-05-01 12:58:01Z anton $
---------------------------------------------------------------------------*/
#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "LoginBase.h"
#include <ExtCtrls.hpp>
#include <GIFImg.hpp>
#include "Header.h"
#include "HeaderBase.h"
//---------------------------------------------------------------------------
class TLoginForm : public TLoginFormBase
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//---------------------------------------------------------------------------
#endif
