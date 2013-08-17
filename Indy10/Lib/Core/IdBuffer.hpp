// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idbuffer.pas' rev: 20.00

#ifndef IdbufferHPP
#define IdbufferHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idbuffer
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdNotEnoughDataInBuffer;
class PASCALIMPLEMENTATION EIdNotEnoughDataInBuffer : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdNotEnoughDataInBuffer(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdNotEnoughDataInBuffer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdNotEnoughDataInBuffer(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdNotEnoughDataInBuffer(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdNotEnoughDataInBuffer(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNotEnoughDataInBuffer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdNotEnoughDataInBuffer(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNotEnoughDataInBuffer(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdNotEnoughDataInBuffer(void) { }
	
};


class DELPHICLASS EIdTooMuchDataInBuffer;
class PASCALIMPLEMENTATION EIdTooMuchDataInBuffer : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdTooMuchDataInBuffer(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdTooMuchDataInBuffer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdTooMuchDataInBuffer(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdTooMuchDataInBuffer(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdTooMuchDataInBuffer(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTooMuchDataInBuffer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdTooMuchDataInBuffer(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTooMuchDataInBuffer(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdTooMuchDataInBuffer(void) { }
	
};


typedef void __fastcall (__closure *TIdBufferBytesRemoved)(System::TObject* ASender, int ABytes);

class DELPHICLASS TIdBuffer;
class PASCALIMPLEMENTATION TIdBuffer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString __fastcall GetAsString();
	
protected:
	Sysutils::TBytes FBytes;
	Sysutils::TEncoding* FEncoding;
	int FGrowthFactor;
	int FHeadIndex;
	TIdBufferBytesRemoved FOnBytesRemoved;
	int FSize;
	void __fastcall CheckAdd(int AByteCount, const int AIndex);
	void __fastcall CheckByteCount(int &VByteCount, const int AIndex);
	int __fastcall GetCapacity(void);
	void __fastcall SetCapacity(int AValue);
	
public:
	void __fastcall Clear(void);
	__fastcall TIdBuffer(void)/* overload */;
	__fastcall TIdBuffer(TIdBufferBytesRemoved AOnBytesRemoved)/* overload */;
	__fastcall TIdBuffer(int AGrowthFactor)/* overload */;
	__fastcall TIdBuffer(const Sysutils::TBytes ABytes, const int ALength)/* overload */;
	void __fastcall CompactHead(bool ACanShrink = true);
	__fastcall virtual ~TIdBuffer(void);
	System::UnicodeString __fastcall Extract(int AByteCount = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	void __fastcall ExtractToStream(const Classes::TStream* AStream, int AByteCount = 0xffffffff, const int AIndex = 0xffffffff);
	void __fastcall ExtractToIdBuffer(TIdBuffer* ABuffer, int AByteCount = 0xffffffff, const int AIndex = 0xffffffff);
	void __fastcall ExtractToBytes(Sysutils::TBytes &VBytes, int AByteCount = 0xffffffff, bool AAppend = true, int AIndex = 0xffffffff);
	System::Byte __fastcall ExtractToByte(const int AIndex);
	System::Word __fastcall ExtractToWord(const int AIndex);
	unsigned __fastcall ExtractToLongWord(const int AIndex);
	__int64 __fastcall ExtractToInt64(const int AIndex);
	void __fastcall ExtractToIPv6(const int AIndex, System::Word *VAddress);
	int __fastcall IndexOf(const Sysutils::TBytes ABytes, int AStartPos = 0x0)/* overload */;
	int __fastcall IndexOf(const System::UnicodeString AString, int AStartPos = 0x0, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::Byte __fastcall PeekByte(int AIndex);
	void __fastcall Remove(int AByteCount);
	void __fastcall SaveToStream(const Classes::TStream* AStream);
	void __fastcall Write(const System::UnicodeString AString, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0), const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(const Sysutils::TBytes ABytes, const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(const Sysutils::TBytes ABytes, const int ALength, const int AOffset, const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(Classes::TStream* AStream, int AByteCount = 0x0)/* overload */;
	void __fastcall Write(const __int64 AValue, const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(const unsigned AValue, const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(const System::Word AValue, const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(const System::Byte AValue, const int ADestIndex = 0xffffffff)/* overload */;
	void __fastcall Write(System::Word const *AValue, const int ADestIndex = 0xffffffff)/* overload */;
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property Sysutils::TEncoding* Encoding = {read=FEncoding, write=FEncoding};
	__property int GrowthFactor = {read=FGrowthFactor, write=FGrowthFactor, nodefault};
	__property int Size = {read=FSize, nodefault};
	__property System::UnicodeString AsString = {read=GetAsString};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idbuffer */
using namespace Idbuffer;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdbufferHPP
