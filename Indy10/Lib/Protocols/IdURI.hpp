// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Iduri.pas' rev: 20.00

#ifndef IduriHPP
#define IduriHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iduri
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdURIOptionalFields { ofAuthInfo, ofBookmark };
#pragma option pop

typedef Set<TIdURIOptionalFields, ofAuthInfo, ofBookmark>  TIdURIOptionalFieldsSet;

class DELPHICLASS TIdURI;
class PASCALIMPLEMENTATION TIdURI : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::UnicodeString FDocument;
	System::UnicodeString FProtocol;
	System::UnicodeString FURI;
	System::UnicodeString FPort;
	System::UnicodeString Fpath;
	System::UnicodeString FHost;
	System::UnicodeString FBookmark;
	System::UnicodeString FUserName;
	System::UnicodeString FPassword;
	System::UnicodeString FParams;
	Idglobal::TIdIPVersion FIPVersion;
	void __fastcall SetURI(const System::UnicodeString Value);
	System::UnicodeString __fastcall GetURI();
	
public:
	__fastcall virtual TIdURI(const System::UnicodeString AURI);
	System::UnicodeString __fastcall GetFullURI(const TIdURIOptionalFieldsSet AOptionalFields = (TIdURIOptionalFieldsSet() << ofAuthInfo << ofBookmark ));
	System::UnicodeString __fastcall GetPathAndParams();
	__classmethod void __fastcall NormalizePath(System::UnicodeString &APath);
	__classmethod System::UnicodeString __fastcall URLDecode(System::UnicodeString ASrc);
	__classmethod System::UnicodeString __fastcall URLEncode(const System::UnicodeString ASrc);
	__classmethod System::UnicodeString __fastcall ParamsEncode(const System::UnicodeString ASrc);
	__classmethod System::UnicodeString __fastcall PathEncode(const System::UnicodeString ASrc);
	__property System::UnicodeString Bookmark = {read=FBookmark, write=FBookmark};
	__property System::UnicodeString Document = {read=FDocument, write=FDocument};
	__property System::UnicodeString Host = {read=FHost, write=FHost};
	__property System::UnicodeString Password = {read=FPassword, write=FPassword};
	__property System::UnicodeString Path = {read=Fpath, write=Fpath};
	__property System::UnicodeString Params = {read=FParams, write=FParams};
	__property System::UnicodeString Port = {read=FPort, write=FPort};
	__property System::UnicodeString Protocol = {read=FProtocol, write=FProtocol};
	__property System::UnicodeString URI = {read=GetURI, write=SetURI};
	__property System::UnicodeString Username = {read=FUserName, write=FUserName};
	__property Idglobal::TIdIPVersion IPVersion = {read=FIPVersion, write=FIPVersion, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdURI(void) { }
	
};


class DELPHICLASS EIdURIException;
class PASCALIMPLEMENTATION EIdURIException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdURIException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdURIException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdURIException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdURIException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdURIException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdURIException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdURIException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdURIException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdURIException(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iduri */
using namespace Iduri;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IduriHPP
