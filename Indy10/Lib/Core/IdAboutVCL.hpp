// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idaboutvcl.pas' rev: 20.00

#ifndef IdaboutvclHPP
#define IdaboutvclHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idaboutvcl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmAbout;
class PASCALIMPLEMENTATION TfrmAbout : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
protected:
	Extctrls::TImage* FimLogo;
	Stdctrls::TLabel* FlblCopyRight;
	Stdctrls::TLabel* FlblName;
	Stdctrls::TLabel* FlblVersion;
	Stdctrls::TLabel* FlblPleaseVisitUs;
	Stdctrls::TLabel* FlblURL;
	Stdctrls::TButton* FbbtnOk;
	void __fastcall lblURLClick(System::TObject* Sender);
	System::UnicodeString __fastcall GetProductName();
	void __fastcall SetProductName(const System::UnicodeString AValue);
	System::UnicodeString __fastcall GetVersion();
	void __fastcall SetVersion(const System::UnicodeString AValue);
	
public:
	__classmethod void __fastcall ShowDlg();
	__classmethod void __fastcall ShowAboutBox(const System::UnicodeString AProductName, const System::UnicodeString AProductVersion);
	__fastcall virtual TfrmAbout(Classes::TComponent* AOwner)/* overload */;
	__fastcall TfrmAbout(void)/* overload */;
	__property System::UnicodeString ProductName = {read=GetProductName, write=SetProductName};
	__property System::UnicodeString Version = {read=GetVersion, write=SetVersion};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmAbout(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmAbout(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmAbout(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idaboutvcl */
using namespace Idaboutvcl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdaboutvclHPP
