// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iddsnpropedbindingvcl.pas' rev: 20.00

#ifndef IddsnpropedbindingvclHPP
#define IddsnpropedbindingvclHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Actnlist.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Idsockethandle.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddsnpropedbindingvcl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDsnPropEdBindingVCL;
class PASCALIMPLEMENTATION TIdDsnPropEdBindingVCL : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* btnOk;
	Stdctrls::TButton* btnCancel;
	Stdctrls::TLabel* lblBindings;
	Stdctrls::TComboBox* edtPort;
	Extctrls::TRadioGroup* rdoBindingType;
	Stdctrls::TLabel* lblIPAddress;
	Stdctrls::TLabel* lblPort;
	Stdctrls::TButton* btnNew;
	Stdctrls::TButton* btnDelete;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* btnBindingsNew;
	Actnlist::TAction* btnBindingsDelete;
	Stdctrls::TComboBox* edtIPAddress;
	Stdctrls::TListBox* lbBindings;
	void __fastcall btnBindingsNewExecute(System::TObject* Sender);
	void __fastcall btnBindingsDeleteExecute(System::TObject* Sender);
	void __fastcall btnBindingsDeleteUpdate(System::TObject* Sender);
	void __fastcall edtPortKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall edtIPAddressChange(System::TObject* Sender);
	void __fastcall edtPortChange(System::TObject* Sender);
	void __fastcall rdoBindingTypeClick(System::TObject* Sender);
	void __fastcall lbBindingsClick(System::TObject* Sender);
	
private:
	void __fastcall SetHandles(const Idsockethandle::TIdSocketHandles* Value);
	void __fastcall SetIPv4Addresses(const Classes::TStrings* Value);
	void __fastcall SetIPv6Addresses(const Classes::TStrings* Value);
	void __fastcall UpdateBindingList(void);
	
protected:
	bool FInUpdateRoutine;
	Idsockethandle::TIdSocketHandles* FHandles;
	int FDefaultPort;
	Classes::TStrings* FIPv4Addresses;
	Classes::TStrings* FIPv6Addresses;
	bool fCreatedStack;
	Idsockethandle::TIdSocketHandle* FCurrentHandle;
	void __fastcall UpdateEditControls(void);
	System::UnicodeString __fastcall PortDescription(const int PortNumber);
	
public:
	__fastcall virtual TIdDsnPropEdBindingVCL(Classes::TComponent* AOwner)/* overload */;
	__fastcall TIdDsnPropEdBindingVCL(void)/* overload */;
	__fastcall virtual ~TIdDsnPropEdBindingVCL(void);
	bool __fastcall Execute(void);
	System::UnicodeString __fastcall GetList();
	void __fastcall SetList(const System::UnicodeString AList);
	__property Idsockethandle::TIdSocketHandles* Handles = {read=FHandles, write=SetHandles};
	__property int DefaultPort = {read=FDefaultPort, write=FDefaultPort, nodefault};
	__property Classes::TStrings* IPv4Addresses = {read=FIPv4Addresses, write=SetIPv4Addresses};
	__property Classes::TStrings* IPv6Addresses = {read=FIPv6Addresses, write=SetIPv6Addresses};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TIdDsnPropEdBindingVCL(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TIdDsnPropEdBindingVCL(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TIdDsnPropEdBindingVCL* IdPropEdBindingEntry;
extern PACKAGE void __fastcall FillHandleList(const System::UnicodeString AList, Idsockethandle::TIdSocketHandles* ADest);
extern PACKAGE System::UnicodeString __fastcall GetListValues(const Idsockethandle::TIdSocketHandles* ASocketHandles);

}	/* namespace Iddsnpropedbindingvcl */
using namespace Iddsnpropedbindingvcl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IddsnpropedbindingvclHPP
