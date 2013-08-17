// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddsnsasllisteditorformvcl.pas' rev: 20.00

#ifndef IddsnsasllisteditorformvclHPP
#define IddsnsasllisteditorformvclHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Actnlist.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idsaslcollection.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddsnsasllisteditorformvcl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmSASLListEditorVCL;
class PASCALIMPLEMENTATION TfrmSASLListEditorVCL : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
protected:
	Stdctrls::TListBox* lbAvailable;
	Stdctrls::TListBox* lbAssigned;
	Buttons::TSpeedButton* sbAdd;
	Buttons::TSpeedButton* sbRemove;
	Stdctrls::TButton* BtnCancel;
	Stdctrls::TButton* BtnOk;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Buttons::TSpeedButton* sbUp;
	Buttons::TSpeedButton* sbDown;
	Idsaslcollection::TIdSASLEntries* SASLList;
	Classes::TComponent* FListOwner;
	Actnlist::TActionList* actEditor;
	Actnlist::TAction* actAdd;
	Actnlist::TAction* actRemove;
	Actnlist::TAction* actMoveUp;
	Actnlist::TAction* actMoveDown;
	void __fastcall actAddUpdate(System::TObject* Sender);
	void __fastcall actAddExecute(System::TObject* Sender);
	void __fastcall actRemoveUpdate(System::TObject* Sender);
	void __fastcall actRemoveExecute(System::TObject* Sender);
	void __fastcall actMoveUpUpdate(System::TObject* Sender);
	void __fastcall actMoveUpExecute(System::TObject* Sender);
	void __fastcall actMoveDownExecute(System::TObject* Sender);
	void __fastcall actMoveDownUpdate(System::TObject* Sender);
	void __fastcall FormCreate(void);
	void __fastcall UpdateList(void);
	
public:
	__fastcall virtual TfrmSASLListEditorVCL(Classes::TComponent* AOwner);
	bool __fastcall Execute(void);
	void __fastcall SetList(const Idsaslcollection::TIdSASLEntries* CopyFrom);
	void __fastcall GetList(const Idsaslcollection::TIdSASLEntries* CopyTo);
	void __fastcall SetComponentName(const System::UnicodeString Name);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmSASLListEditorVCL(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmSASLListEditorVCL(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmSASLListEditorVCL(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddsnsasllisteditorformvcl */
using namespace Iddsnsasllisteditorformvcl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddsnsasllisteditorformvclHPP
