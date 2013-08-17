// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftpbasefilesystem.pas' rev: 20.00

#ifndef IdftpbasefilesystemHPP
#define IdftpbasefilesystemHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idbasecomponent.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idftplistoutput.hpp>	// Pascal unit
#include <Idftpservercontextbase.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftpbasefilesystem
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdFTPBaseFileSystem;
class PASCALIMPLEMENTATION TIdFTPBaseFileSystem : public Idbasecomponent::TIdBaseComponent
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	void __fastcall ErrPermissionDenied(void);
	void __fastcall ErrCantRemoveDir(void);
	void __fastcall ErrFileNotFound(void);
	void __fastcall ErrNotAFile(void);
	void __fastcall ErrNotADir(void);
	
public:
	virtual void __fastcall ChangeDir(Idftpservercontextbase::TIdFTPServerContextBase* AContext, System::UnicodeString &VDirectory) = 0 ;
	virtual void __fastcall GetFileSize(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString AFilename, __int64 &VFileSize) = 0 ;
	virtual void __fastcall GetFileDate(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString AFilename, System::TDateTime &VFileDate) = 0 ;
	virtual void __fastcall ListDirectory(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString APath, Idftplistoutput::TIdFTPListOutput* ADirectoryListing, const System::UnicodeString ACmd, const System::UnicodeString ASwitches) = 0 ;
	virtual void __fastcall RenameFile(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString ARenameToFile) = 0 ;
	virtual void __fastcall DeleteFile(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString APathName) = 0 ;
	virtual void __fastcall RetrieveFile(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString AFileName, Classes::TStream* &VStream) = 0 ;
	virtual void __fastcall StoreFile(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString AFileName, bool AAppend, Classes::TStream* &VStream) = 0 ;
	virtual void __fastcall MakeDirectory(Idftpservercontextbase::TIdFTPServerContextBase* AContext, System::UnicodeString &VDirectory) = 0 ;
	virtual void __fastcall RemoveDirectory(Idftpservercontextbase::TIdFTPServerContextBase* AContext, System::UnicodeString &VDirectory) = 0 ;
	virtual void __fastcall SetModifiedFileDate(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString AFileName, System::TDateTime &VDateTime) = 0 ;
	virtual void __fastcall GetCRCCalcStream(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString AFileName, Classes::TStream* &VStream) = 0 ;
	virtual void __fastcall CombineFiles(Idftpservercontextbase::TIdFTPServerContextBase* AContext, const System::UnicodeString ATargetFileName, Classes::TStrings* AParts) = 0 ;
public:
	/* TIdBaseComponent.Create */ inline __fastcall TIdFTPBaseFileSystem(Classes::TComponent* AOwner)/* overload */ : Idbasecomponent::TIdBaseComponent(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdFTPBaseFileSystem(void) { }
	
};


class DELPHICLASS EIdFileSystemException;
class PASCALIMPLEMENTATION EIdFileSystemException : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileSystemException(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileSystemException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileSystemException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileSystemException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileSystemException(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileSystemException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileSystemException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileSystemException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileSystemException(void) { }
	
};


class DELPHICLASS EIdFileSystemPermissionDenied;
class PASCALIMPLEMENTATION EIdFileSystemPermissionDenied : public EIdFileSystemException
{
	typedef EIdFileSystemException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileSystemPermissionDenied(const System::UnicodeString AMsg)/* overload */ : EIdFileSystemException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileSystemPermissionDenied(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFileSystemException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileSystemPermissionDenied(int Ident)/* overload */ : EIdFileSystemException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileSystemPermissionDenied(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFileSystemException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileSystemPermissionDenied(const System::UnicodeString Msg, int AHelpContext) : EIdFileSystemException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileSystemPermissionDenied(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFileSystemException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileSystemPermissionDenied(int Ident, int AHelpContext)/* overload */ : EIdFileSystemException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileSystemPermissionDenied(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFileSystemException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileSystemPermissionDenied(void) { }
	
};


class DELPHICLASS EIdFileSystemFileNotFound;
class PASCALIMPLEMENTATION EIdFileSystemFileNotFound : public EIdFileSystemException
{
	typedef EIdFileSystemException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileSystemFileNotFound(const System::UnicodeString AMsg)/* overload */ : EIdFileSystemException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileSystemFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFileSystemException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileSystemFileNotFound(int Ident)/* overload */ : EIdFileSystemException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileSystemFileNotFound(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFileSystemException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileSystemFileNotFound(const System::UnicodeString Msg, int AHelpContext) : EIdFileSystemException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileSystemFileNotFound(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFileSystemException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileSystemFileNotFound(int Ident, int AHelpContext)/* overload */ : EIdFileSystemException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileSystemFileNotFound(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFileSystemException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileSystemFileNotFound(void) { }
	
};


class DELPHICLASS EIdFileSystemNotAFile;
class PASCALIMPLEMENTATION EIdFileSystemNotAFile : public EIdFileSystemException
{
	typedef EIdFileSystemException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileSystemNotAFile(const System::UnicodeString AMsg)/* overload */ : EIdFileSystemException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileSystemNotAFile(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFileSystemException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileSystemNotAFile(int Ident)/* overload */ : EIdFileSystemException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileSystemNotAFile(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFileSystemException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileSystemNotAFile(const System::UnicodeString Msg, int AHelpContext) : EIdFileSystemException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileSystemNotAFile(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFileSystemException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileSystemNotAFile(int Ident, int AHelpContext)/* overload */ : EIdFileSystemException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileSystemNotAFile(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFileSystemException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileSystemNotAFile(void) { }
	
};


class DELPHICLASS EIdFileSystemNotADir;
class PASCALIMPLEMENTATION EIdFileSystemNotADir : public EIdFileSystemException
{
	typedef EIdFileSystemException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileSystemNotADir(const System::UnicodeString AMsg)/* overload */ : EIdFileSystemException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileSystemNotADir(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFileSystemException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileSystemNotADir(int Ident)/* overload */ : EIdFileSystemException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileSystemNotADir(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFileSystemException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileSystemNotADir(const System::UnicodeString Msg, int AHelpContext) : EIdFileSystemException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileSystemNotADir(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFileSystemException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileSystemNotADir(int Ident, int AHelpContext)/* overload */ : EIdFileSystemException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileSystemNotADir(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFileSystemException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileSystemNotADir(void) { }
	
};


class DELPHICLASS EIdFileSystemCannotRemoveDir;
class PASCALIMPLEMENTATION EIdFileSystemCannotRemoveDir : public EIdFileSystemException
{
	typedef EIdFileSystemException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdFileSystemCannotRemoveDir(const System::UnicodeString AMsg)/* overload */ : EIdFileSystemException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdFileSystemCannotRemoveDir(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdFileSystemException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdFileSystemCannotRemoveDir(int Ident)/* overload */ : EIdFileSystemException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdFileSystemCannotRemoveDir(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdFileSystemException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdFileSystemCannotRemoveDir(const System::UnicodeString Msg, int AHelpContext) : EIdFileSystemException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFileSystemCannotRemoveDir(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdFileSystemException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdFileSystemCannotRemoveDir(int Ident, int AHelpContext)/* overload */ : EIdFileSystemException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFileSystemCannotRemoveDir(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdFileSystemException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdFileSystemCannotRemoveDir(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftpbasefilesystem */
using namespace Idftpbasefilesystem;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftpbasefilesystemHPP
