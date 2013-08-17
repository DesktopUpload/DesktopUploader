// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idftplistparsemvs.pas' rev: 20.00

#ifndef IdftplistparsemvsHPP
#define IdftplistparsemvsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idftplistparsebase.hpp>	// Pascal unit
#include <Idftplisttypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "IdFTPListParseMVS"

namespace Idftplistparsemvs
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdJESJobStatus { IdJESNotApplicable, IdJESReceived, IdJESHold, IdJESRunning, IdJESOuptutAvailable };
#pragma option pop

class DELPHICLASS TIdMVSFTPListItem;
class PASCALIMPLEMENTATION TIdMVSFTPListItem : public Idftplisttypes::TIdRecFTPListItem
{
	typedef Idftplisttypes::TIdRecFTPListItem inherited;
	
protected:
	int FBlockSize;
	bool FMigrated;
	System::UnicodeString FVolume;
	System::UnicodeString FUnit;
	System::UnicodeString FOrg;
	int FMVSNumberExtents;
	int FMVSNumberTracks;
	
public:
	__fastcall virtual TIdMVSFTPListItem(Classes::TCollection* AOwner);
	__property bool Migrated = {read=FMigrated, write=FMigrated, nodefault};
	__property int BlockSize = {read=FBlockSize, write=FBlockSize, nodefault};
	__property RecLength;
	__property RecFormat;
	__property NumberRecs;
	__property System::UnicodeString Volume = {read=FVolume, write=FVolume};
	__property System::UnicodeString Units = {read=FUnit, write=FUnit};
	__property System::UnicodeString Org = {read=FOrg, write=FOrg};
	__property int NumberExtents = {read=FMVSNumberExtents, write=FMVSNumberExtents, nodefault};
	__property int NumberTracks = {read=FMVSNumberTracks, write=FMVSNumberTracks, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMVSFTPListItem(void) { }
	
};


class DELPHICLASS TIdMVSJESFTPListItem;
class PASCALIMPLEMENTATION TIdMVSJESFTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	TIdJESJobStatus FMVSJobStatus;
	int FMVSJobSpoolFiles;
	
public:
	__fastcall virtual TIdMVSJESFTPListItem(Classes::TCollection* AOwner);
	__property TIdJESJobStatus JobStatus = {read=FMVSJobStatus, write=FMVSJobStatus, nodefault};
	__property int JobSpoolFiles = {read=FMVSJobSpoolFiles, write=FMVSJobSpoolFiles, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdMVSJESFTPListItem(void) { }
	
};


class DELPHICLASS TIdMVSJESIntF2FTPListItem;
class PASCALIMPLEMENTATION TIdMVSJESIntF2FTPListItem : public Idftplisttypes::TIdOwnerFTPListItem
{
	typedef Idftplisttypes::TIdOwnerFTPListItem inherited;
	
protected:
	TIdJESJobStatus FJobStatus;
	int FJobSpoolFiles;
	Classes::TStrings* FDetails;
	void __fastcall SetDetails(Classes::TStrings* AValue);
	
public:
	__fastcall virtual TIdMVSJESIntF2FTPListItem(Classes::TCollection* AOwner);
	__fastcall virtual ~TIdMVSJESIntF2FTPListItem(void);
	__property Classes::TStrings* Details = {read=FDetails, write=SetDetails};
	__property TIdJESJobStatus JobStatus = {read=FJobStatus, write=FJobStatus, nodefault};
	__property int JobSpoolFiles = {read=FJobSpoolFiles, write=FJobSpoolFiles, nodefault};
};


class DELPHICLASS TIdFTPLPMVS;
class PASCALIMPLEMENTATION TIdFTPLPMVS : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMVS(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMVS(void) { }
	
};


class DELPHICLASS TIdFTPLPMVSPartitionedDataSet;
class PASCALIMPLEMENTATION TIdFTPLPMVSPartitionedDataSet : public Idftplistparsebase::TIdFTPListBaseHeader
{
	typedef Idftplistparsebase::TIdFTPListBaseHeader inherited;
	
protected:
	__classmethod virtual bool __fastcall IsHeader(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMVSPartitionedDataSet(void) : Idftplistparsebase::TIdFTPListBaseHeader() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMVSPartitionedDataSet(void) { }
	
};


class DELPHICLASS TIdFTPLPMVSJESInterface1;
class PASCALIMPLEMENTATION TIdFTPLPMVSJESInterface1 : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod virtual bool __fastcall IsMVS_JESNoJobsMsg(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMVSJESInterface1(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMVSJESInterface1(void) { }
	
};


class DELPHICLASS TIdFTPLPMVSJESInterface2;
class PASCALIMPLEMENTATION TIdFTPLPMVSJESInterface2 : public Idftplistparsebase::TIdFTPListBase
{
	typedef Idftplistparsebase::TIdFTPListBase inherited;
	
protected:
	__classmethod virtual Idftplist::TIdFTPListItem* __fastcall MakeNewItem(Idftplist::TIdFTPListItems* AOwner);
	__classmethod bool __fastcall IsMVS_JESIntF2Header(const System::UnicodeString AData);
	__classmethod virtual bool __fastcall ParseLine(const Idftplist::TIdFTPListItem* AItem, const System::UnicodeString APath = L"");
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIdent();
	__classmethod virtual bool __fastcall CheckListing(Classes::TStrings* AListing, const System::UnicodeString ASysDescript = L"", const bool ADetails = true);
	__classmethod virtual bool __fastcall ParseListing(Classes::TStrings* AListing, Idftplist::TIdFTPListItems* ADir);
public:
	/* TObject.Create */ inline __fastcall TIdFTPLPMVSJESInterface2(void) : Idftplistparsebase::TIdFTPListBase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIdFTPLPMVSJESInterface2(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idftplistparsemvs */
using namespace Idftplistparsemvs;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdftplistparsemvsHPP
