// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idfsp.pas' rev: 20.00

#ifndef IdfspHPP
#define IdfspHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idthreadsafe.hpp>	// Pascal unit
#include <Idudpclient.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idudpbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idfsp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdFSPException;
class PASCALIMPLEMENTATION EIdFSPException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFSPException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFSPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFSPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFSPException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFSPException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFSPException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFSPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFSPException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFSPException(void) { }
	
};


class DELPHICLASS EIdFSPFileAlreadyExists;
class PASCALIMPLEMENTATION EIdFSPFileAlreadyExists : public EIdFSPException
{
	typedef EIdFSPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFSPFileAlreadyExists(const System::UnicodeString AMsg)/* overload */ : EIdFSPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFSPFileAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFSPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFSPFileAlreadyExists(int Ident)/* overload */ : EIdFSPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFSPFileAlreadyExists(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFSPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFSPFileAlreadyExists(const System::UnicodeString Msg, int AHelpContext) : EIdFSPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFSPFileAlreadyExists(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFSPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFSPFileAlreadyExists(int Ident, int AHelpContext)/* overload */ : EIdFSPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFSPFileAlreadyExists(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFSPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFSPFileAlreadyExists(void) { }
	
};


class DELPHICLASS EIdFSPFileNotFound;
class PASCALIMPLEMENTATION EIdFSPFileNotFound : public EIdFSPException
{
	typedef EIdFSPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFSPFileNotFound(const System::UnicodeString AMsg)/* overload */ : EIdFSPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFSPFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFSPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFSPFileNotFound(int Ident)/* overload */ : EIdFSPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFSPFileNotFound(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFSPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFSPFileNotFound(const System::UnicodeString Msg, int AHelpContext) : EIdFSPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFSPFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFSPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFSPFileNotFound(int Ident, int AHelpContext)/* overload */ : EIdFSPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFSPFileNotFound(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFSPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFSPFileNotFound(void) { }
	
};


class DELPHICLASS EIdFSPProtException;
class PASCALIMPLEMENTATION EIdFSPProtException : public EIdFSPException
{
	typedef EIdFSPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFSPProtException(const System::UnicodeString AMsg)/* overload */ : EIdFSPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFSPProtException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFSPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFSPProtException(int Ident)/* overload */ : EIdFSPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFSPProtException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFSPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFSPProtException(const System::UnicodeString Msg, int AHelpContext) : EIdFSPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFSPProtException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFSPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFSPProtException(int Ident, int AHelpContext)/* overload */ : EIdFSPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFSPProtException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFSPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFSPProtException(void) { }
	
};


class DELPHICLASS EIdFSPPacketTooSmall;
class PASCALIMPLEMENTATION EIdFSPPacketTooSmall : public EIdFSPException
{
	typedef EIdFSPException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFSPPacketTooSmall(const System::UnicodeString AMsg)/* overload */ : EIdFSPException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFSPPacketTooSmall(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFSPException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFSPPacketTooSmall(int Ident)/* overload */ : EIdFSPException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFSPPacketTooSmall(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFSPException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFSPPacketTooSmall(const System::UnicodeString Msg, int AHelpContext) : EIdFSPException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFSPPacketTooSmall(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFSPException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFSPPacketTooSmall(int Ident, int AHelpContext)/* overload */ : EIdFSPException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFSPPacketTooSmall(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFSPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFSPPacketTooSmall(void) { }
	
};


class DELPHICLASS TIdFSPStatInfo;
class PASCALIMPLEMENTATION TIdFSPStatInfo : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::TDateTime FModifiedDateGMT;
	System::TDateTime FModifiedDate;
	__int64 FSize;
	Idftplist::TIdDirItemType FItemType;
	
__published:
	__property Idftplist::TIdDirItemType ItemType = {read=FItemType, write=FItemType, nodefault};
	__property __int64 Size = {read=FSize, write=FSize};
	__property System::TDateTime ModifiedDate = {read=FModifiedDate, write=FModifiedDate};
	__property System::TDateTime ModifiedDateGMT = {read=FModifiedDateGMT, write=FModifiedDateGMT};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdFSPStatInfo(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdFSPStatInfo(void) { }
	
};


class DELPHICLASS TIdFSPListItem;
class PASCALIMPLEMENTATION TIdFSPListItem : public TIdFSPStatInfo
{
	typedef TIdFSPStatInfo inherited;
	
protected:
	System::UnicodeString FFileName;
	
__published:
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TIdFSPListItem(Classes::TCollection* Collection) : TIdFSPStatInfo(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdFSPListItem(void) { }
	
};


class DELPHICLASS TIdFSPListItems;
class PASCALIMPLEMENTATION TIdFSPListItems : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
public:
	TIdFSPListItem* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	TIdFSPListItem* __fastcall GetItems(int AIndex);
	void __fastcall SetItems(int AIndex, const TIdFSPListItem* Value);
	
public:
	HIDESBASE TIdFSPListItem* __fastcall Add(void);
	__fastcall TIdFSPListItems(void);
	bool __fastcall ParseEntries(const Sysutils::TBytes AData, const unsigned ADataLen);
	int __fastcall IndexOf(TIdFSPListItem* AItem);
	__property TIdFSPListItem* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdFSPListItems(void) { }
	
};


class DELPHICLASS TIdFSPDirInfo;
class PASCALIMPLEMENTATION TIdFSPDirInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FOwnsDir;
	bool FCanDeleteFiles;
	bool FCanAddFiles;
	bool FCanMakeDir;
	bool FOnlyOwnerCanReadFiles;
	bool FHasReadMe;
	bool FCanBeListed;
	bool FCanRenameFiles;
	System::UnicodeString FReadMe;
	
public:
	__property bool OwnsDir = {read=FOwnsDir, write=FOwnsDir, nodefault};
	__property bool CanDeleteFiles = {read=FCanDeleteFiles, write=FCanDeleteFiles, nodefault};
	__property bool CanAddFiles = {read=FCanAddFiles, write=FCanAddFiles, nodefault};
	__property bool CanMakeDir = {read=FCanMakeDir, write=FCanMakeDir, nodefault};
	__property bool OnlyOwnerCanReadFiles = {read=FOnlyOwnerCanReadFiles, write=FOnlyOwnerCanReadFiles, nodefault};
	__property bool HasReadMe = {read=FHasReadMe, write=FHasReadMe, nodefault};
	__property bool CanBeListed = {read=FCanBeListed, write=FCanBeListed, nodefault};
	__property bool CanRenameFiles = {read=FCanRenameFiles, write=FCanRenameFiles, nodefault};
	__property System::UnicodeString ReadMe = {read=FReadMe, write=FReadMe};
public:
	/* TObject.Create */ inline __fastcall TIdFSPDirInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFSPDirInfo(void) { }
	
};


class DELPHICLASS TIdFSPPacket;
class PASCALIMPLEMENTATION TIdFSPPacket : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Byte FCmd;
	unsigned FFilePosition;
	Sysutils::TBytes FData;
	System::Word FDataLen;
	Sysutils::TBytes FExtraData;
	System::Word FSequence;
	System::Word FKey;
	bool FValid;
	
public:
	__fastcall TIdFSPPacket(void);
	Sysutils::TBytes __fastcall WritePacket();
	void __fastcall ReadPacket(const Sysutils::TBytes AData, const unsigned ALen);
	__property bool Valid = {read=FValid, nodefault};
	__property System::Byte Cmd = {read=FCmd, write=FCmd, nodefault};
	__property System::Word Key = {read=FKey, write=FKey, nodefault};
	__property System::Word Sequence = {read=FSequence, write=FSequence, nodefault};
	__property unsigned FilePosition = {read=FFilePosition, write=FFilePosition, nodefault};
	__property Sysutils::TBytes Data = {read=FData, write=FData};
	__property System::Word DataLen = {read=FDataLen, write=FDataLen, nodefault};
	__property Sysutils::TBytes ExtraData = {read=FExtraData, write=FExtraData};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFSPPacket(void) { }
	
};


typedef void __fastcall (__closure *TIdFSPLogEvent)(System::TObject* Sender, TIdFSPPacket* APacket);

class DELPHICLASS TIdFSP;
class PASCALIMPLEMENTATION TIdFSP : public Idudpclient::TIdUDPClient
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	bool FConEstablished;
	System::Word FSequence;
	System::Word FKey;
	System::UnicodeString FSystemDesc;
	bool FSystemServerLogs;
	bool FSystemReadOnly;
	bool FSystemReverseLookupRequired;
	bool FSystemPrivateMode;
	bool FSystemAcceptsExtraData;
	bool FThruputControl;
	unsigned FServerMaxThruPut;
	System::Word FServerMaxPacketSize;
	System::Word FClientMaxPacketSize;
	TIdFSPListItems* FDirectoryListing;
	TIdFSPDirInfo* FDirInfo;
	TIdFSPStatInfo* FStatInfo;
	TIdFSPLogEvent FOnRecv;
	TIdFSPLogEvent FOnSend;
	Idthreadsafe::TIdThreadSafeBoolean* FAbortFlag;
	Idthreadsafe::TIdThreadSafeBoolean* FInCmd;
	void __fastcall SendCmdOnce(TIdFSPPacket* ACmdPacket, TIdFSPPacket* ARecvPacket, Sysutils::TBytes &VTempBuf, const bool ARaiseException = true)/* overload */;
	void __fastcall SendCmdOnce(const System::Byte ACmd, const Sysutils::TBytes AData, const Sysutils::TBytes AExtraData, const __int64 AFilePosition, Sysutils::TBytes &VData, Sysutils::TBytes &VExtraData, const bool ARaiseException = true)/* overload */;
	void __fastcall SendCmd(TIdFSPPacket* ACmdPacket, TIdFSPPacket* ARecvPacket, Sysutils::TBytes &VTempBuf, const bool ARaiseException = true)/* overload */;
	void __fastcall SendCmd(const System::Byte ACmd, const Sysutils::TBytes AData, const Sysutils::TBytes AExtraData, const __int64 AFilePosition, Sysutils::TBytes &VData, Sysutils::TBytes &VExtraData, const bool ARaiseException = true)/* overload */;
	void __fastcall SendCmd(const System::Byte ACmd, const Sysutils::TBytes AData, const __int64 AFilePosition, Sysutils::TBytes &VData, Sysutils::TBytes &VExtraData, const bool ARaiseException = true)/* overload */;
	void __fastcall ParseDirInfo(const Sysutils::TBytes ABuf, const Sysutils::TBytes AExtraBuf, TIdFSPDirInfo* ADir);
	virtual void __fastcall InitComponent(void);
	System::Word __fastcall MaxBufferSize(void);
	System::Word __fastcall PrefPayloadSize(void);
	void __fastcall SetClientMaxPacketSize(const System::Word AValue);
	
public:
	__fastcall virtual ~TIdFSP(void);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	HIDESBASE void __fastcall Version(void);
	void __fastcall AbortCmd(void);
	void __fastcall Delete(const System::UnicodeString AFilename);
	void __fastcall RemoveDir(const System::UnicodeString ADirName);
	void __fastcall Rename(const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile);
	void __fastcall MakeDir(const System::UnicodeString ADirName);
	void __fastcall List(void)/* overload */;
	void __fastcall List(const System::UnicodeString ASpecifier)/* overload */;
	void __fastcall GetDirInfo(const System::UnicodeString ADIR)/* overload */;
	void __fastcall GetDirInfo(const System::UnicodeString ADIR, TIdFSPDirInfo* ADirInfo)/* overload */;
	void __fastcall GetStatInfo(const System::UnicodeString APath);
	void __fastcall Get(const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile, const bool ACanOverwrite = false, bool AResume = false)/* overload */;
	void __fastcall Get(const System::UnicodeString ASourceFile, Classes::TStream* ADest, bool AResume = false)/* overload */;
	void __fastcall Put(const Classes::TStream* ASource, const System::UnicodeString ADestFile, const System::TDateTime AGMTTime = 0.000000E+00)/* overload */;
	void __fastcall Put(const System::UnicodeString ASourceFile, const System::UnicodeString ADestFile = L"")/* overload */;
	__property System::UnicodeString SystemDesc = {read=FSystemDesc};
	__property bool SystemServerLogs = {read=FSystemServerLogs, nodefault};
	__property bool SystemReadOnly = {read=FSystemReadOnly, nodefault};
	__property bool SystemReverseLookupRequired = {read=FSystemReverseLookupRequired, nodefault};
	__property bool SystemPrivateMode = {read=FSystemPrivateMode, nodefault};
	__property bool SystemAcceptsExtraData = {read=FSystemAcceptsExtraData, nodefault};
	__property bool ThruputControl = {read=FThruputControl, nodefault};
	__property unsigned ServerMaxThruPut = {read=FServerMaxThruPut, nodefault};
	__property System::Word ServerMaxPacketSize = {read=FServerMaxPacketSize, nodefault};
	__property System::Word ClientMaxPacketSize = {read=FClientMaxPacketSize, write=SetClientMaxPacketSize, nodefault};
	__property TIdFSPListItems* DirectoryListing = {read=FDirectoryListing};
	__property TIdFSPDirInfo* DirInfo = {read=FDirInfo};
	__property TIdFSPStatInfo* StatInfo = {read=FStatInfo};
	
__published:
	__property Port = {default=21};
	__property OnWork;
	__property OnWorkBegin;
	__property OnWorkEnd;
	__property TIdFSPLogEvent OnRecv = {read=FOnRecv, write=FOnRecv};
	__property TIdFSPLogEvent OnSend = {read=FOnSend, write=FOnSend};
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdFSP(Classes::TComponent* AOwner)/* overload */ : Idudpclient::TIdUDPClient(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt IdPORT_FSP = 0x15;
static const ShortInt HSIZE = 0xc;
static const Word DEF_MAXSPACE = 0x3f4;
static const Word DEF_MAXSIZE = 0x400;
static const ShortInt CC_VERSION = 0x10;
static const ShortInt CC_INFO = 0x11;
static const ShortInt CC_ERR = 0x40;
static const ShortInt CC_GET_DIR = 0x41;
static const ShortInt CC_GET_FILE = 0x42;
static const ShortInt CC_UP_LOAD = 0x43;
static const ShortInt CC_INSTALL = 0x44;
static const ShortInt CC_DEL_FILE = 0x45;
static const ShortInt CC_DEL_DIR = 0x46;
static const ShortInt CC_GET_PRO = 0x47;
static const ShortInt CC_SET_PRO = 0x48;
static const ShortInt CC_MAKE_DIR = 0x49;
static const ShortInt CC_BYE = 0x4a;
static const ShortInt CC_GRAB_FILE = 0x4b;
static const ShortInt CC_GRAB_DONE = 0x4c;
static const ShortInt CC_STAT = 0x4d;
static const ShortInt CC_RENAME = 0x4e;
static const ShortInt CC_CH_PASSW = 0x4f;
static const Byte CC_LIMIT = 0x80;
static const Byte CC_TEST = 0x81;
static const ShortInt RDTYPE_END = 0x0;
static const ShortInt RDTYPE_FILE = 0x1;
static const ShortInt RDTYPE_DIR = 0x2;
static const ShortInt RDTYPE_SKIP = 0x2a;
static const Word MINTIMEOUT = 0x53c;
static const int MAXTIMEOUT = 0x493e0;

}	/* namespace Idfsp */
using namespace Idfsp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdfspHPP
