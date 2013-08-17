// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idblockcipherintercept.pas' rev: 20.00

#ifndef IdblockcipherinterceptHPP
#define IdblockcipherinterceptHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idresourcestringsprotocols.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idblockcipherintercept
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdBlockCipherIntercept;
class PASCALIMPLEMENTATION TIdBlockCipherIntercept : public Idintercept::TIdConnectionIntercept
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
protected:
	int FBlockSize;
	Sysutils::TBytes FIncoming;
	virtual void __fastcall Decrypt(Sysutils::TBytes &VData);
	virtual void __fastcall Encrypt(Sysutils::TBytes &VData);
	void __fastcall SetBlockSize(const int Value);
	virtual void __fastcall InitComponent(void);
	
public:
	virtual void __fastcall Receive(Sysutils::TBytes &VBuffer);
	virtual void __fastcall Send(Sysutils::TBytes &VBuffer);
	void __fastcall CopySettingsFrom(TIdBlockCipherIntercept* ASrcBlockCipherIntercept);
	
__published:
	__property int BlockSize = {read=FBlockSize, write=SetBlockSize, default=16};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdBlockCipherIntercept(Classes::TComponent* AOwner)/* overload */ : Idintercept::TIdConnectionIntercept(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdBlockCipherIntercept(void) { }
	
};


typedef Idexception::EIdException EIdBlockCipherInterceptException;

//-- var, const, procedure ---------------------------------------------------
static const ShortInt IdBlockCipherBlockSizeDefault = 0x10;
static const Word IdBlockCipherBlockSizeMax = 0x100;

}	/* namespace Idblockcipherintercept */
using namespace Idblockcipherintercept;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdblockcipherinterceptHPP
