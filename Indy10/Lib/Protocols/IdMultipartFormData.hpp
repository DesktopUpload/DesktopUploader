// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idmultipartformdata.pas' rev: 20.00

#ifndef IdmultipartformdataHPP
#define IdmultipartformdataHPP

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
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmultipartformdata
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdFormDataField;
class PASCALIMPLEMENTATION TIdFormDataField : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FFieldValue;
	System::UnicodeString FFileName;
	System::UnicodeString FContentType;
	System::UnicodeString FFieldName;
	System::TObject* FFieldObject;
	bool FCanFreeFieldObject;
	int __fastcall GetFieldSize(void);
	Classes::TStream* __fastcall GetFieldStream(void);
	Classes::TStrings* __fastcall GetFieldStrings(void);
	void __fastcall SetContentType(const System::UnicodeString Value);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	void __fastcall SetFieldStream(const Classes::TStream* Value);
	void __fastcall SetFieldStrings(const Classes::TStrings* Value);
	void __fastcall SetFieldValue(const System::UnicodeString Value);
	void __fastcall SetFieldObject(const System::TObject* Value);
	void __fastcall SetFileName(const System::UnicodeString Value);
	
public:
	__fastcall virtual TIdFormDataField(Classes::TCollection* Collection);
	__fastcall virtual ~TIdFormDataField(void);
	System::UnicodeString __fastcall FormatField();
	__property System::UnicodeString ContentType = {read=FContentType, write=SetContentType};
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
	__property Classes::TStream* FieldStream = {read=GetFieldStream, write=SetFieldStream};
	__property Classes::TStrings* FieldStrings = {read=GetFieldStrings, write=SetFieldStrings};
	__property System::TObject* FieldObject = {read=FFieldObject, write=SetFieldObject};
	__property System::UnicodeString FileName = {read=FFileName, write=SetFileName};
	__property System::UnicodeString FieldValue = {read=FFieldValue, write=SetFieldValue};
	__property int FieldSize = {read=GetFieldSize, nodefault};
};


class DELPHICLASS TIdFormDataFields;
class DELPHICLASS TIdMultiPartFormDataStream;
class PASCALIMPLEMENTATION TIdFormDataFields : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
protected:
	TIdMultiPartFormDataStream* FParentStream;
	TIdFormDataField* __fastcall GetFormDataField(int AIndex);
	
public:
	__fastcall TIdFormDataFields(TIdMultiPartFormDataStream* AMPStream);
	HIDESBASE TIdFormDataField* __fastcall Add(void);
	__property TIdMultiPartFormDataStream* MultipartFormDataStream = {read=FParentStream};
	__property TIdFormDataField* Items[int AIndex] = {read=GetFormDataField};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdFormDataFields(void) { }
	
};


class PASCALIMPLEMENTATION TIdMultiPartFormDataStream : public Idglobal::TIdBaseStream
{
	typedef Idglobal::TIdBaseStream inherited;
	
protected:
	Classes::TStream* FInputStream;
	System::UnicodeString FBoundary;
	System::UnicodeString FRequestContentType;
	int FCurrentItem;
	bool FInitialized;
	Sysutils::TBytes FInternalBuffer;
	__int64 FPosition;
	__int64 FSize;
	TIdFormDataFields* FFields;
	System::UnicodeString __fastcall GenerateUniqueBoundary();
	System::UnicodeString __fastcall PrepareStreamForDispatch();
	virtual int __fastcall IdRead(Sysutils::TBytes &VBuffer, int AOffset, int ACount);
	virtual int __fastcall IdWrite(const Sysutils::TBytes ABuffer, int AOffset, int ACount);
	virtual __int64 __fastcall IdSeek(const __int64 AOffset, Classes::TSeekOrigin AOrigin);
	virtual void __fastcall IdSetSize(__int64 ASize);
	
public:
	__fastcall TIdMultiPartFormDataStream(void);
	__fastcall virtual ~TIdMultiPartFormDataStream(void);
	void __fastcall AddFormField(const System::UnicodeString AFieldName, const System::UnicodeString AFieldValue);
	void __fastcall AddObject(const System::UnicodeString AFieldName, const System::UnicodeString AContentType, System::TObject* AFileData, const System::UnicodeString AFileName = L"");
	void __fastcall AddFile(const System::UnicodeString AFieldName, const System::UnicodeString AFileName, const System::UnicodeString AContentType);
	__property System::UnicodeString Boundary = {read=FBoundary};
	__property System::UnicodeString RequestContentType = {read=FRequestContentType};
};


class DELPHICLASS EIdInvalidObjectType;
class PASCALIMPLEMENTATION EIdInvalidObjectType : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdInvalidObjectType(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidObjectType(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdInvalidObjectType(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidObjectType(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidObjectType(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidObjectType(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidObjectType(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidObjectType(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdInvalidObjectType(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define sContentTypeFormData L"multipart/form-data; boundary="
#define sContentTypeOctetStream L"application/octet-stream"
#define crlf L"\r\n"
#define sContentDisposition L"Content-Disposition: form-data; name=\"%s\""
#define sFileNamePlaceHolder L"; filename=\"%s\""
#define sContentTypePlaceHolder L"Content-Type: %s"

}	/* namespace Idmultipartformdata */
using namespace Idmultipartformdata;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdmultipartformdataHPP
