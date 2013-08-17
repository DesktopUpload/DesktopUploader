// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idzlibheaders.pas' rev: 20.00

#ifndef IdzlibheadersHPP
#define IdzlibheadersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idctypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idzlibheaders
{
//-- type declarations -------------------------------------------------------
typedef void * __cdecl (*alloc_func)(void * opaque, unsigned items, unsigned size);

typedef alloc_func TAlloc;

typedef void __cdecl (*free_func)(void * opaque, void * address);

typedef free_func TFree;

typedef unsigned __cdecl (*in_func)(void * opaque, System::PByte &buf);

typedef in_func TInFunc;

typedef int __cdecl (*out_func)(void * opaque, System::PByte buf, unsigned size);

typedef out_func TOutFunc;

struct z_stream;
typedef z_stream *z_streamp;

struct z_stream
{
	
public:
	char *next_in;
	unsigned avail_in;
	unsigned total_in;
	char *next_out;
	unsigned avail_out;
	unsigned total_out;
	char *msg;
	void *state;
	alloc_func zalloc;
	free_func zfree;
	void *opaque;
	int data_type;
	unsigned adler;
	unsigned reserved;
};


typedef z_stream TZStreamRec;

typedef z_streamp PZStreamRec;

struct gz_header;
typedef gz_header *gz_headerp;

struct gz_header
{
	
public:
	int text;
	unsigned time;
	int xflags;
	int os;
	System::Byte *extra;
	unsigned extra_len;
	unsigned extra_max;
	char *name;
	unsigned name_max;
	char *comment;
	unsigned comm_max;
	int hcrc;
	int done;
};


typedef gz_headerp PgzHeaderRec;

typedef gz_header TgzHeaderRec;

#pragma option push -b-
enum TZStreamType { zsZLib, zsGZip, zsRaw };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
#define ZLIB_VERSION L"1.2.3"
static const ShortInt Z_NO_FLUSH = 0x0;
static const ShortInt Z_PARTIAL_FLUSH = 0x1;
static const ShortInt Z_SYNC_FLUSH = 0x2;
static const ShortInt Z_FULL_FLUSH = 0x3;
static const ShortInt Z_FINISH = 0x4;
static const ShortInt Z_BLOCK = 0x5;
static const ShortInt Z_OK = 0x0;
static const ShortInt Z_STREAM_END = 0x1;
static const ShortInt Z_NEED_DICT = 0x2;
static const ShortInt Z_ERRNO = -1;
static const ShortInt Z_STREAM_ERROR = -2;
static const ShortInt Z_DATA_ERROR = -3;
static const ShortInt Z_MEM_ERROR = -4;
static const ShortInt Z_BUF_ERROR = -5;
static const ShortInt Z_VERSION_ERROR = -6;
static const ShortInt Z_NO_COMPRESSION = 0x0;
static const ShortInt Z_BEST_SPEED = 0x1;
static const ShortInt Z_BEST_COMPRESSION = 0x9;
static const ShortInt Z_DEFAULT_COMPRESSION = -1;
static const ShortInt Z_FILTERED = 0x1;
static const ShortInt Z_HUFFMAN_ONLY = 0x2;
static const ShortInt Z_RLE = 0x3;
static const ShortInt Z_DEFAULT_STRATEGY = 0x0;
static const ShortInt Z_BINARY = 0x0;
static const ShortInt Z_ASCII = 0x1;
static const ShortInt Z_UNKNOWN = 0x2;
static const ShortInt Z_DEFLATED = 0x8;
static const ShortInt MAX_WBITS = 0xf;
static const ShortInt MAX_MEM_LEVEL = 0x9;
static const ShortInt DEF_MEM_LEVEL = 0x8;
extern PACKAGE int __fastcall deflateInit(z_stream &strm, int level);
extern PACKAGE int __fastcall deflateInit2(z_stream &strm, int level, int method, int windowBits, int memLevel, int strategy);
extern PACKAGE int __fastcall deflateInitEx(z_stream &strm, int level, TZStreamType streamtype = (TZStreamType)(0x0));
extern PACKAGE int __fastcall inflateInitEx(z_stream &strm, TZStreamType streamtype = (TZStreamType)(0x0));
extern PACKAGE int __fastcall inflateInit(z_stream &strm);
extern PACKAGE int __fastcall inflateInit2(z_stream &strm, int windowBits);
extern PACKAGE int __fastcall inflateBackInit(z_stream &strm, int windowBits, char * window);
extern PACKAGE void * __cdecl _malloc(int Size);
extern PACKAGE void __cdecl _free(void * Block);
extern PACKAGE void __cdecl _memset(void * P, System::Byte B, int count);
extern PACKAGE void __cdecl _memcpy(void * dest, void * source, int count);
extern PACKAGE void * __cdecl zlibAllocMem(void * AppData, unsigned Items, unsigned Size);
extern PACKAGE void __cdecl zlibFreeMem(void * AppData, void * Block);
extern PACKAGE bool __fastcall Load(void);
extern PACKAGE void __fastcall Unload(void);
extern PACKAGE bool __fastcall Loaded(void);
extern PACKAGE unsigned __fastcall adler32(unsigned adler, const char * buf, unsigned len);
extern PACKAGE int __fastcall compress2(char * dest, unsigned &destLen, const char * source, unsigned sourceLen, int level);
extern PACKAGE int __fastcall compress(char * dest, unsigned &destLen, const char * source, unsigned sourceLen);
extern PACKAGE unsigned __fastcall compressBound(unsigned sourceLen);
extern PACKAGE Idctypes::PIdC_ULONG __fastcall get_crc_table(void);
extern PACKAGE unsigned __fastcall crc32(unsigned crc, const char * buf, unsigned len);
extern PACKAGE int __fastcall deflateInit_(z_stream &strm, int level, const char * version, int stream_size);
extern PACKAGE int __fastcall deflateInit2_(z_stream &strm, int level, int method, int windowBits, int memLevel, int strategy, const char * version, int stream_size);
extern PACKAGE int __fastcall deflateSetDictionary(z_stream &strm, const char * dictionary, unsigned dictLength);
extern PACKAGE int __fastcall deflateReset(z_stream &strm);
extern PACKAGE int __fastcall deflateSetHeader(z_stream &strm, gz_header &head);
extern PACKAGE int __fastcall deflatePrime(z_stream &strm, int bits, int value);
extern PACKAGE int __fastcall deflateParams(z_stream &strm, int level, int strategy);
extern PACKAGE int __fastcall deflateTune(z_stream &strm, int good_length, int max_lazy, int nice_length, int max_chain);
extern PACKAGE unsigned __fastcall deflateBound(z_stream &strm, unsigned sourceLen);
extern PACKAGE int __fastcall deflate(z_stream &strm, int flush);
extern PACKAGE int __fastcall deflateEnd(z_stream &strm);
extern PACKAGE int __fastcall deflateCopy(z_stream &dest, z_stream &source);
extern PACKAGE int __fastcall inflateBackInit_(z_stream &strm, int windowBits, char * window, const char * version, int stream_size);
extern PACKAGE int __fastcall inflateBack(z_stream &strm, in_func in_fn, void * in_desc, out_func out_fn, void * out_desc);
extern PACKAGE int __fastcall inflateBackEnd(z_stream &strm);
extern PACKAGE int __fastcall inflateReset(z_stream &strm);
extern PACKAGE int __fastcall inflateInit2_(z_stream &strm, int windowBits, const char * version, int stream_size);
extern PACKAGE int __fastcall inflateInit_(z_stream &strm, const char * version, int stream_size);
extern PACKAGE int __fastcall inflate(z_stream &strm, int flush);
extern PACKAGE int __fastcall inflateEnd(z_stream &strm);
extern PACKAGE int __fastcall inflateSetDictionary(z_stream &strm, const char * dictionary, unsigned dictLength);
extern PACKAGE int __fastcall inflateGetHeader(z_stream &strm, gz_header &head);
extern PACKAGE int __fastcall inflateSync(z_stream &strm);
extern PACKAGE int __fastcall inflateSyncPoint(z_stream &z);
extern PACKAGE int __fastcall inflateCopy(z_stream &dest, z_stream &source);
extern PACKAGE int __fastcall uncompress(char * dest, unsigned &destLen, const char * source, unsigned sourceLen);
extern PACKAGE char * __fastcall zlibVersion(void);
extern PACKAGE unsigned __fastcall zlibCompileFlags(void);
extern PACKAGE char * __fastcall zError(int err);

}	/* namespace Idzlibheaders */
using namespace Idzlibheaders;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdzlibheadersHPP
