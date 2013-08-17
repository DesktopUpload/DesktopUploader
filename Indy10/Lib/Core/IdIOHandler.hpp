// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idiohandler.pas' rev: 20.00

#ifndef IdiohandlerHPP
#define IdiohandlerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idantifreezebase.hpp>	// Pascal unit
#include <Idbuffer.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idexceptioncore.hpp>	// Pascal unit
#include <Idintercept.hpp>	// Pascal unit
#include <Idresourcestringscore.hpp>	// Pascal unit
#include <Idstream.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idiohandler
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdIOHandler;
class PASCALIMPLEMENTATION EIdIOHandler : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIOHandler(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIOHandler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIOHandler(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIOHandler(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIOHandler(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIOHandler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIOHandler(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIOHandler(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIOHandler(void) { }
	
};


class DELPHICLASS EIdIOHandlerRequiresLargeStream;
class PASCALIMPLEMENTATION EIdIOHandlerRequiresLargeStream : public EIdIOHandler
{
	typedef EIdIOHandler inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIOHandlerRequiresLargeStream(const System::UnicodeString AMsg)/* overload */ : EIdIOHandler(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIOHandlerRequiresLargeStream(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIOHandler(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIOHandlerRequiresLargeStream(int Ident)/* overload */ : EIdIOHandler(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIOHandlerRequiresLargeStream(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIOHandler(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIOHandlerRequiresLargeStream(const System::UnicodeString Msg, int AHelpContext) : EIdIOHandler(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIOHandlerRequiresLargeStream(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIOHandler(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIOHandlerRequiresLargeStream(int Ident, int AHelpContext)/* overload */ : EIdIOHandler(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIOHandlerRequiresLargeStream(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIOHandler(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIOHandlerRequiresLargeStream(void) { }
	
};


class DELPHICLASS EIdIOHandlerStreamDataTooLarge;
class PASCALIMPLEMENTATION EIdIOHandlerStreamDataTooLarge : public EIdIOHandler
{
	typedef EIdIOHandler inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdIOHandlerStreamDataTooLarge(const System::UnicodeString AMsg)/* overload */ : EIdIOHandler(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdIOHandlerStreamDataTooLarge(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdIOHandler(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdIOHandlerStreamDataTooLarge(int Ident)/* overload */ : EIdIOHandler(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdIOHandlerStreamDataTooLarge(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdIOHandler(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdIOHandlerStreamDataTooLarge(const System::UnicodeString Msg, int AHelpContext) : EIdIOHandler(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIOHandlerStreamDataTooLarge(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdIOHandler(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdIOHandlerStreamDataTooLarge(int Ident, int AHelpContext)/* overload */ : EIdIOHandler(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIOHandlerStreamDataTooLarge(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdIOHandler(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdIOHandlerStreamDataTooLarge(void) { }
	
};


typedef TMetaClass* TIdIOHandlerClass;

class DELPHICLASS TIdIOHandler;
class PASCALIMPLEMENTATION TIdIOHandler : public Idcomponent::TIdComponent
{
	typedef Idcomponent::TIdComponent inherited;
	
private:
	bool FLargeStream;
	
protected:
	bool FClosedGracefully;
	int FConnectTimeout;
	System::UnicodeString FDestination;
	System::UnicodeString FHost;
	Idbuffer::TIdBuffer* FInputBuffer;
	Idintercept::TIdConnectionIntercept* FIntercept;
	int FMaxCapturedLines;
	Idglobal::TIdMaxLineAction FMaxLineAction;
	int FMaxLineLength;
	bool FOpened;
	int FPort;
	bool FReadLnSplit;
	bool FReadLnTimedOut;
	int FReadTimeOut;
	int FRecvBufferSize;
	int FSendBufferSize;
	Idbuffer::TIdBuffer* FWriteBuffer;
	int FWriteBufferThreshold;
	Sysutils::TEncoding* FDefStringEncoding;
	void __fastcall SetDefStringEncoding(const Sysutils::TEncoding* AEncoding);
	void __fastcall BufferRemoveNotify(System::TObject* ASender, int ABytes);
	virtual System::UnicodeString __fastcall GetDestination();
	virtual void __fastcall InitComponent(void);
	void __fastcall InterceptReceive(Sysutils::TBytes &VBuffer);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall PerformCapture(const System::TObject* ADest, /* out */ int &VLineCount, const System::UnicodeString ADelim, bool AIsRFCMessage, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	void __fastcall RaiseConnClosedGracefully(void);
	virtual void __fastcall SetDestination(const System::UnicodeString AValue);
	virtual void __fastcall SetHost(const System::UnicodeString AValue);
	virtual void __fastcall SetPort(int AValue);
	virtual void __fastcall SetIntercept(Idintercept::TIdConnectionIntercept* AValue);
	int __fastcall ReadFromSource(bool ARaiseExceptionIfDisconnected = true, int ATimeout = 0xffffffff, bool ARaiseExceptionOnTimeout = true);
	virtual int __fastcall ReadDataFromSource(Sysutils::TBytes &VBuffer) = 0 ;
	virtual int __fastcall WriteDataToTarget(const Sysutils::TBytes ABuffer, const int AOffset, const int ALength) = 0 ;
	virtual bool __fastcall SourceIsAvailable(void) = 0 ;
	
public:
	virtual void __fastcall AfterAccept(void);
	virtual bool __fastcall Connected(void);
	__fastcall virtual ~TIdIOHandler(void);
	virtual void __fastcall CheckForDisconnect(bool ARaiseExceptionIfDisconnected = true, bool AIgnoreBuffer = false) = 0 ;
	virtual bool __fastcall CheckForDataOnSource(int ATimeout = 0x0);
	virtual void __fastcall Close(void);
	virtual void __fastcall CloseGracefully(void);
	__classmethod TIdIOHandler* __fastcall MakeDefaultIOHandler(Classes::TComponent* AOwner = (Classes::TComponent*)(0x0));
	__classmethod TIdIOHandler* __fastcall MakeIOHandler(TIdIOHandlerClass ABaseType, Classes::TComponent* AOwner = (Classes::TComponent*)(0x0));
	__classmethod void __fastcall RegisterIOHandler();
	__classmethod void __fastcall SetDefaultClass();
	System::UnicodeString __fastcall WaitFor(const System::UnicodeString AString, bool ARemoveFromBuffer = true, bool AInclusive = false, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0), int ATimeout = 0xffffffff);
	virtual void __fastcall Write(const Sysutils::TBytes ABuffer, const int ALength = 0xffffffff, const int AOffset = 0x0)/* overload */;
	void __fastcall WriteDirect(const Sysutils::TBytes ABuffer, const int ALength = 0xffffffff, const int AOffset = 0x0);
	virtual void __fastcall Open(void);
	virtual bool __fastcall Readable(int AMSec = 0xffffffff);
	virtual void __fastcall Write(const System::UnicodeString AOut, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall WriteLn(Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual void __fastcall WriteLn(const System::UnicodeString AOut, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual void __fastcall WriteLnRFC(const System::UnicodeString AOut = L"", Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	virtual void __fastcall Write(Classes::TStrings* AValue, bool AWriteLinesCount = false, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Write(System::Byte AValue)/* overload */;
	void __fastcall Write(System::WideChar AValue, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Write(unsigned AValue, bool AConvert = true)/* overload */;
	void __fastcall Write(int AValue, bool AConvert = true)/* overload */;
	void __fastcall Write(short AValue, bool AConvert = true)/* overload */;
	void __fastcall Write(__int64 AValue, bool AConvert = true)/* overload */;
	virtual void __fastcall Write(Classes::TStream* AStream, __int64 ASize = 0x000000000, bool AWriteByteCount = false)/* overload */;
	void __fastcall WriteRFCStrings(Classes::TStrings* AStrings, bool AWriteTerminator = true, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	virtual __int64 __fastcall WriteFile(const System::UnicodeString AFile, bool AEnableTransferFile = false);
	virtual System::UnicodeString __fastcall AllData(Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	virtual System::UnicodeString __fastcall InputLn(const System::UnicodeString AMask = L"", bool AEcho = true, int ATabWidth = 0x8, int AMaxLineLength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	void __fastcall Capture(Classes::TStream* ADest, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Capture(Classes::TStream* ADest, System::UnicodeString ADelim, bool AIsRFCMessage = true, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Capture(Classes::TStream* ADest, /* out */ int &VLineCount, const System::UnicodeString ADelim = L".", bool AIsRFCMessage = true, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Capture(Classes::TStrings* ADest, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Capture(Classes::TStrings* ADest, const System::UnicodeString ADelim, bool AIsRFCMessage = true, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	void __fastcall Capture(Classes::TStrings* ADest, /* out */ int &VLineCount, const System::UnicodeString ADelim = L".", bool AIsRFCMessage = true, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual void __fastcall ReadBytes(Sysutils::TBytes &VBuffer, int AByteCount, bool AAppend = true);
	System::UnicodeString __fastcall ReadLn(Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::UnicodeString __fastcall ReadLn(System::UnicodeString ATerminator, Sysutils::TEncoding* AEncoding)/* overload */;
	virtual System::UnicodeString __fastcall ReadLn(System::UnicodeString ATerminator, int ATimeout = 0xffffffff, int AMaxLineLength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::UnicodeString __fastcall ReadLnRFC(bool &VMsgEnd, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	System::UnicodeString __fastcall ReadLnRFC(bool &VMsgEnd, const System::UnicodeString ALineTerminator, const System::UnicodeString ADelim = L".", Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0))/* overload */;
	virtual System::UnicodeString __fastcall ReadLnWait(int AFailCount = 0x7fffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	System::UnicodeString __fastcall ReadLnSplit(bool &AWasSplit, System::UnicodeString ATerminator = L"\n", int ATimeout = 0xffffffff, int AMaxLineLength = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	System::WideChar __fastcall ReadChar(Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	System::Byte __fastcall ReadByte(void);
	System::UnicodeString __fastcall ReadString(int ABytes, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	unsigned __fastcall ReadLongWord(bool AConvert = true);
	int __fastcall ReadLongInt(bool AConvert = true);
	__int64 __fastcall ReadInt64(bool AConvert = true);
	short __fastcall ReadSmallInt(bool AConvert = true);
	virtual void __fastcall ReadStream(Classes::TStream* AStream, __int64 AByteCount = 0xffffffffffffffff, bool AReadUntilDisconnect = false);
	void __fastcall ReadStrings(Classes::TStrings* ADest, int AReadLinesCount = 0xffffffff, Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	virtual void __fastcall WriteBufferCancel(void);
	virtual void __fastcall WriteBufferClear(void);
	virtual void __fastcall WriteBufferClose(void);
	void __fastcall WriteBufferFlush(void)/* overload */;
	virtual void __fastcall WriteBufferFlush(int AByteCount)/* overload */;
	void __fastcall WriteBufferOpen(void)/* overload */;
	virtual void __fastcall WriteBufferOpen(int AThreshold)/* overload */;
	bool __fastcall WriteBufferingActive(void);
	bool __fastcall InputBufferIsEmpty(void);
	void __fastcall InputBufferToStream(Classes::TStream* AStream, int AByteCount = 0xffffffff);
	System::UnicodeString __fastcall InputBufferAsString(Sysutils::TEncoding* AEncoding = (Sysutils::TEncoding*)(0x0));
	__property int ConnectTimeout = {read=FConnectTimeout, write=FConnectTimeout, default=0};
	__property bool ClosedGracefully = {read=FClosedGracefully, nodefault};
	__property Idbuffer::TIdBuffer* InputBuffer = {read=FInputBuffer};
	__property bool LargeStream = {read=FLargeStream, write=FLargeStream, nodefault};
	__property int MaxCapturedLines = {read=FMaxCapturedLines, write=FMaxCapturedLines, default=-1};
	__property bool Opened = {read=FOpened, nodefault};
	__property int ReadTimeout = {read=FReadTimeOut, write=FReadTimeOut, default=-1};
	__property bool ReadLnTimedout = {read=FReadLnTimedOut, nodefault};
	__property int WriteBufferThreshold = {read=FWriteBufferThreshold, nodefault};
	__property Sysutils::TEncoding* DefStringEncoding = {read=FDefStringEncoding, write=SetDefStringEncoding};
	__property OnWork;
	__property OnWorkBegin;
	__property OnWorkEnd;
	
__published:
	__property System::UnicodeString Destination = {read=GetDestination, write=SetDestination};
	__property System::UnicodeString Host = {read=FHost, write=SetHost};
	__property Idintercept::TIdConnectionIntercept* Intercept = {read=FIntercept, write=SetIntercept};
	__property int MaxLineLength = {read=FMaxLineLength, write=FMaxLineLength, default=16384};
	__property Idglobal::TIdMaxLineAction MaxLineAction = {read=FMaxLineAction, write=FMaxLineAction, nodefault};
	__property int Port = {read=FPort, write=SetPort, nodefault};
	__property int RecvBufferSize = {read=FRecvBufferSize, write=FRecvBufferSize, default=32768};
	__property int SendBufferSize = {read=FSendBufferSize, write=FSendBufferSize, default=32768};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdIOHandler(Classes::TComponent* AOwner)/* overload */ : Idcomponent::TIdComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word GRecvBufferSizeDefault = 0x8000;
static const Word GSendBufferSizeDefault = 0x8000;
static const Word IdMaxLineLengthDefault = 0x4000;
static const ShortInt Id_IOHandler_MaxCapturedLines = -1;

}	/* namespace Idiohandler */
using namespace Idiohandler;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdiohandlerHPP
