// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idsslopensslheaders.pas' rev: 20.00

#ifndef IdsslopensslheadersHPP
#define IdsslopensslheadersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idexception.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Idctypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <time.h>
#undef X509_NAME
#undef X509_EXTENSIONS
#undef X509_CERT_PAIR
#undef PKCS7_ISSUER_AND_SERIAL
#undef OCSP_RESPONSE
#undef OCSP_REQUEST
#undef PKCS7_SIGNER_INFO
#undef OCSP_REQUEST
#undef OCSP_RESPONSE

namespace Idsslopensslheaders
{
//-- type declarations -------------------------------------------------------
typedef int UInteger;

typedef int *PUInteger;

typedef void * PFunction;

typedef int *PLong;

typedef unsigned *PULong;

typedef System::Word *PUShort;

typedef System::PByte *PPByte;

typedef __int64 PQ_64BIT;

#pragma pack(push,1)
struct STACK
{
	
public:
	int num;
	char *data;
	int sorted;
	int num_alloc;
	int __cdecl (*comp)(System::PPAnsiChar _para1, System::PPAnsiChar _para2);
};
#pragma pack(pop)


typedef STACK *PSTACK;

typedef PSTACK *PPSTACK;

struct SSL;
typedef SSL *PSSL;

typedef unsigned MD2_INT;

typedef unsigned RC2_INT;

typedef unsigned RC4_INT;

typedef unsigned IDEA_INT;

#pragma pack(push,1)
struct ERR_string_data
{
	
public:
	unsigned error;
	char *_string;
};
#pragma pack(pop)


typedef ERR_string_data *PERR_string_data;

#pragma pack(push,1)
struct ERR_STATE
{
	
public:
	unsigned PID;
	StaticArray<int, 16> err_flags;
	StaticArray<unsigned, 16> err_buffer;
	StaticArray<char *, 16> err_data;
	StaticArray<int, 16> err_data_flags;
	StaticArray<char *, 16> err_file;
	StaticArray<int, 16> err_line;
	int top;
	int bottom;
};
#pragma pack(pop)


typedef ERR_STATE TERR_STATE;

typedef void * PERR_FNS;

#pragma pack(push,1)
struct RAND_METHOD
{
	
public:
	void __cdecl (*seed)(const void * buf, int num);
	int __cdecl (*bytes)(const char * buf, int num);
	void __cdecl (*cleanup)(void);
	void __cdecl (*add)(const void * buf, int num, double entropy);
	int __cdecl (*pseudorand)(char * buf, int num);
	int __cdecl (*status)(void);
};
#pragma pack(pop)


typedef __int64 BN_ULLONG;

typedef int BN_LONG;

typedef unsigned BN_ULONG;

typedef int *PBN_LONG;

typedef unsigned *PBN_ULONG;

#pragma pack(push,1)
struct BIGNUM
{
	
public:
	unsigned *d;
	int top;
	int dmax;
	int neg;
	int flags;
};
#pragma pack(pop)


typedef BIGNUM *PBIGNUM;

typedef void * PBN_CTX;

typedef void * *PPBN_CTX;

#pragma pack(push,1)
struct BN_MONT_CTX
{
	
public:
	int ri;
	BIGNUM RR;
	BIGNUM N;
	BIGNUM Ni;
	unsigned n0;
	int flags;
};
#pragma pack(pop)


typedef BN_MONT_CTX *PBN_MONT_CTX;

typedef void * PBN_BLINDING;

#pragma pack(push,1)
struct BN_RECP_CTX
{
	
public:
	BIGNUM N;
	BIGNUM Nr;
	int num_bits;
	int shift;
	int flags;
};
#pragma pack(pop)


typedef BN_RECP_CTX *PBN_RECP_CTX;

struct BN_GENCB;
typedef BN_GENCB *PBN_GENCB;

typedef PBN_GENCB *PPBN_GENCB;

typedef void __cdecl (*BN_cb_1)(int p1, int p2, void * p3);

typedef int __cdecl (*BN_cb_2)(int p1, int p2, PBN_GENCB p3);

#pragma pack(push,1)
struct BN_GENCB_union
{
	
	union
	{
		struct 
		{
			BN_cb_2 cb_2;
			
		};
		struct 
		{
			BN_cb_1 cb_1;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct BN_GENCB
{
	
public:
	unsigned ver;
	void *arg;
	BN_GENCB_union cb;
};
#pragma pack(pop)


#pragma pack(push,1)
struct MD2_CTX
{
	
public:
	unsigned num;
	StaticArray<char, 16> data;
	StaticArray<unsigned, 16> cksm;
	StaticArray<unsigned, 16> state;
};
#pragma pack(pop)


typedef MD2_CTX *PMD2_CTX;

typedef unsigned MD4_LONG;

#pragma pack(push,1)
struct MD4_CTX
{
	
public:
	unsigned A;
	unsigned B;
	unsigned C;
	unsigned D;
	unsigned Nl;
	unsigned Nh;
	StaticArray<unsigned, 16> data;
	unsigned num;
};
#pragma pack(pop)


typedef unsigned MD5_LONG;

#pragma pack(push,1)
struct MD5_CTX
{
	
public:
	unsigned A;
	unsigned B;
	unsigned C;
	unsigned D;
	unsigned Nl;
	unsigned Nh;
	StaticArray<unsigned, 16> data;
	unsigned num;
};
#pragma pack(pop)


typedef MD5_CTX *PMD5_CTX;

typedef unsigned SHA_LONG;

#pragma pack(push,1)
struct SHA_CTX
{
	
public:
	unsigned h0;
	unsigned h1;
	unsigned h2;
	unsigned h3;
	unsigned h4;
	unsigned Nl;
	unsigned Nh;
	StaticArray<unsigned, 17> data;
	int num;
};
#pragma pack(pop)


#pragma pack(push,1)
struct SHA256_CTX
{
	
public:
	StaticArray<unsigned, 8> h;
	unsigned Nl;
	unsigned Nh;
	StaticArray<unsigned, 16> data;
	unsigned num;
	unsigned md_len;
};
#pragma pack(pop)


typedef __int64 SHA_LONG64;

#pragma pack(push,1)
struct TSHA512_CTX_Union
{
	
	union
	{
		struct 
		{
			StaticArray<System::Byte, 128> p;
			
		};
		struct 
		{
			StaticArray<__int64, 16> d;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct SHA512_CTX
{
	
public:
	StaticArray<__int64, 8> h;
	__int64 Nl;
	__int64 Nh;
	TSHA512_CTX_Union u;
	unsigned num;
	unsigned md_len;
};
#pragma pack(pop)


typedef void * PUI_METHOD;

typedef void * PUI_STRING;

typedef PSTACK PSTACK_OF_UI_STRING;

#pragma option push -b-
enum UI_string_types { UIT_NONE, UIT_PROMPT, UIT_VERIFY, UIT_BOOLEAN, UIT_INFO, UIT_ERROR };
#pragma option pop

#pragma pack(push,1)
struct OPENSSL_ITEM
{
	
public:
	int code;
	void *value;
	unsigned value_size;
	unsigned *value_length;
};
#pragma pack(pop)


#pragma pack(push,1)
struct CRYPTO_EX_DATA
{
	
public:
	STACK *sk;
	int dummy;
};
#pragma pack(pop)


typedef CRYPTO_EX_DATA *PCRYPTO_EX_DATA;

typedef void * PCRYPTO_dynlock_value;

#pragma pack(push,1)
struct CRYPTO_dynlock
{
	
public:
	int references;
	void *data;
};
#pragma pack(pop)


typedef CRYPTO_dynlock *PCRYPTO_dynlock;

typedef int __cdecl (*CRYPTO_EX_new)(void * parent, void * ptr, const CRYPTO_EX_DATA ad, int idx, int arg1, void * argp);

typedef void __cdecl (*CRYPTO_EX_free)(void * parent, void * ptr, const CRYPTO_EX_DATA ad, int idx, int arg1, void * argp);

typedef int __cdecl (*CRYPTO_EX_dup)(PCRYPTO_EX_DATA _to, PCRYPTO_EX_DATA from, void * from_d, int idx, int arg1, void * argp);

#pragma pack(push,1)
struct CRYPTO_EX_DATA_FUNCS
{
	
public:
	int argl;
	void *argp;
	CRYPTO_EX_new new_func;
	CRYPTO_EX_free free_func;
	CRYPTO_EX_dup dup_func;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_CRYPTO_EX_DATA_FUNCS;

typedef void * PCRYPTO_EX_DATA_IMPL;

struct BIO;
typedef BIO *PBIO;

struct BIO_METHOD;
typedef BIO_METHOD *PBIO_METHOD;

typedef void __cdecl (*Pbio_info_cb)(PBIO _para1, int _para2, char * _para3, int _para4, int _para5, int _para6);

#pragma pack(push,1)
struct BIO_METHOD
{
	
public:
	int _type;
	char *name;
	int __cdecl (*bwrite)(PBIO _para1, char * _para2, int _para3);
	int __cdecl (*bread)(PBIO _para1, char * _para2, int _para3);
	int __cdecl (*bputs)(PBIO _para1, char * _para2);
	int __cdecl (*bgets)(PBIO _para1, char * _para2, int _para3);
	int __cdecl (*ctrl)(PBIO _para1, int _para2, int _para3, void * _para4);
	int __cdecl (*create)(PBIO _para1);
	int __cdecl (*destroy)(PBIO _para1);
	int __cdecl (*callback_ctrl)(PBIO _para1, int _para2, Pbio_info_cb _para3);
};
#pragma pack(pop)


#pragma pack(push,1)
struct BIO
{
	
public:
	BIO_METHOD *method;
	int __cdecl (*callback)(PBIO _para1, int _para2, char * _para3, int _para4, int _para5, int _para6);
	char *cb_arg;
	int init;
	int shutdown;
	int flags;
	int retry_reason;
	int num;
	void *ptr;
	BIO *next_bio;
	BIO *prev_bio;
	int references;
	unsigned num_read;
	unsigned num_write;
	CRYPTO_EX_DATA ex_data;
};
#pragma pack(pop)


typedef void * PENGINE;

typedef int __cdecl (*I2D_OF_void)(void * _para1, System::PPAnsiChar _para2);

typedef void * __cdecl (*D2I_OF_void)(void * &_para1, const System::PPAnsiChar _para2, int _para3);

typedef void * PASN1_VALUE;

typedef void * *PPASN1_VALUE;

typedef PSTACK PSTACK_OF_ASN1_VALUE;

#pragma pack(push,1)
struct ASN1_OBJECT
{
	
public:
	char *sn;
	char *ln;
	int nid;
	int length;
	char *data;
	int flags;
};
#pragma pack(pop)


typedef ASN1_OBJECT *PASN1_OBJECT;

typedef PASN1_OBJECT *PPASN1_OBJECT;

typedef PSTACK PSTACK_OF_ASN1_OBJECT;

typedef PSTACK *PPSTACK_OF_ASN1_OBJECT;

#pragma pack(push,1)
struct asn1_string_st
{
	
public:
	int length;
	int _type;
	char *data;
	int flags;
};
#pragma pack(pop)


struct ASN1_ITEM;
typedef ASN1_ITEM *PASN1_ITEM;

typedef int __stdcall (*asn1_output_data_fn)(PBIO AOut, PBIO data, void * val, int flags, PASN1_ITEM it);

typedef asn1_string_st ASN1_STRING;

typedef asn1_string_st *PASN1_STRING;

typedef PASN1_STRING *PPASN1_STRING;

typedef asn1_string_st ASN1_INTEGER;

typedef asn1_string_st *PASN1_INTEGER;

typedef PASN1_INTEGER *PPASN1_INTEGER;

typedef PSTACK PSTACK_OF_ASN1_INTEGER;

typedef asn1_string_st ASN1_ENUMERATED;

typedef asn1_string_st *PASN1_ENUMERATED;

typedef PASN1_ENUMERATED *PPASN1_ENUMERATED;

typedef asn1_string_st ASN1_BIT_STRING;

typedef asn1_string_st *PASN1_BIT_STRING;

typedef PASN1_BIT_STRING *PPASN1_BIT_STRING;

typedef asn1_string_st ASN1_OCTET_STRING;

typedef asn1_string_st *PASN1_OCTET_STRING;

typedef PASN1_OCTET_STRING *PPASN1_OCTET_STRING;

typedef asn1_string_st ASN1_PRINTABLESTRING;

typedef asn1_string_st *PASN1_PRINTABLESTRING;

typedef PASN1_PRINTABLESTRING *PPASN1_PRINTABLESTRING;

typedef asn1_string_st ASN1_T61STRING;

typedef asn1_string_st *PASN1_T61STRING;

typedef PASN1_T61STRING *PPASN1_T61STRING;

typedef asn1_string_st ASN1_IA5STRING;

typedef asn1_string_st *PASN1_IA5STRING;

typedef PASN1_IA5STRING *PPASN1_IA5STRING;

typedef asn1_string_st ASN1_UTCTIME;

typedef asn1_string_st *PASN1_UTCTIME;

typedef PASN1_UTCTIME *PPASN1_UTCTIME;

typedef asn1_string_st ASN1_GENERALIZEDTIME;

typedef asn1_string_st *PASN1_GENERALIZEDTIME;

typedef PASN1_GENERALIZEDTIME *PPASN1_GENERALIZEDTIME;

typedef asn1_string_st ASN1_TIME;

typedef asn1_string_st *PASN1_TIME;

typedef PASN1_TIME *PPASN1_TIME;

typedef asn1_string_st ASN1_GENERALSTRING;

typedef asn1_string_st *PASN1_GENERALSTRING;

typedef PASN1_GENERALSTRING *PPASN1_GENERALSTRING;

typedef PSTACK PSTACK_OF_ASN1_GENERALSTRING;

typedef asn1_string_st ASN1_UNIVERSALSTRING;

typedef asn1_string_st *PASN1_UNIVERSALSTRING;

typedef PASN1_UNIVERSALSTRING *PPASN1_UNIVERSALSTRING;

typedef asn1_string_st ASN1_BMPSTRING;

typedef asn1_string_st *PASN1_BMPSTRING;

typedef PASN1_BMPSTRING *PPASN1_BMPSTRING;

typedef asn1_string_st ASN1_VISIBLESTRING;

typedef asn1_string_st *PASN1_VISIBLESTRING;

typedef PASN1_VISIBLESTRING *PPASN1_VISIBLESTRING;

typedef asn1_string_st ASN1_UTF8STRING;

typedef asn1_string_st *PASN1_UTF8STRING;

typedef PASN1_UTF8STRING *PPASN1_UTF8STRING;

typedef int ASN1_BOOLEAN;

typedef int *PASN1_BOOLEAN;

typedef PASN1_BOOLEAN *PPASN1_BOOLEAN;

typedef int ASN1_NULL;

typedef int *PASN1_NULL;

typedef PASN1_NULL *PPASN1_NULL;

#pragma pack(push,1)
struct ASN1_TYPE
{
	
	union
	{
		struct 
		{
			asn1_string_st *sequence;
			
		};
		struct 
		{
			asn1_string_st *_set;
			
		};
		struct 
		{
			asn1_string_st *utf8string;
			
		};
		struct 
		{
			asn1_string_st *visiblestring;
			
		};
		struct 
		{
			asn1_string_st *generalizedtime;
			
		};
		struct 
		{
			asn1_string_st *utctime;
			
		};
		struct 
		{
			asn1_string_st *universalstring;
			
		};
		struct 
		{
			asn1_string_st *bmpstring;
			
		};
		struct 
		{
			asn1_string_st *generalstring;
			
		};
		struct 
		{
			asn1_string_st *ia5string;
			
		};
		struct 
		{
			asn1_string_st *t61string;
			
		};
		struct 
		{
			asn1_string_st *printablestring;
			
		};
		struct 
		{
			asn1_string_st *octet_string;
			
		};
		struct 
		{
			asn1_string_st *bit_string;
			
		};
		struct 
		{
			asn1_string_st *enumerated;
			
		};
		struct 
		{
			asn1_string_st *integer;
			
		};
		struct 
		{
			ASN1_OBJECT *_object;
			
		};
		struct 
		{
			asn1_string_st *asn1_string;
			
		};
		struct 
		{
			int boolean;
			
		};
		struct 
		{
			char *ptr;
			
		};
		
	};
};
#pragma pack(pop)


typedef ASN1_TYPE *PASN1_TYPE;

typedef PASN1_TYPE *PPASN1_TYPE;

typedef PSTACK *PSTACK_OF_ASN1_TYPE;

#pragma pack(push,1)
struct ASN1_CTX
{
	
public:
	char *p;
	int eos;
	int error;
	int inf;
	int tag;
	int xclass;
	int slen;
	char *max;
	char *q;
	char * *pp;
	int line;
};
#pragma pack(pop)


typedef ASN1_CTX *PASN1_CTX;

typedef PASN1_CTX *PPASN1_CTX;

#pragma pack(push,1)
struct ASN1_METHOD
{
	
public:
	I2D_OF_void i2d;
	I2D_OF_void d2i;
	void * __cdecl (*create)(void);
	void __cdecl (*destroy)(void * ptr);
};
#pragma pack(pop)


typedef ASN1_METHOD *PASN1_METHOD;

typedef PASN1_METHOD *PPASN1_METHOD;

#pragma pack(push,1)
struct ASN1_HEADER
{
	
public:
	asn1_string_st *header;
	void *data;
	ASN1_METHOD *meth;
};
#pragma pack(pop)


typedef ASN1_HEADER *PASN1_HEADER;

typedef PASN1_HEADER *PPASN1_HEADER;

#pragma pack(push,1)
struct ASN1_ENCODING
{
	
public:
	char *enc;
	int len;
	int modified;
};
#pragma pack(pop)


typedef ASN1_ENCODING *PASN1_ENCODING;

typedef ASN1_ENCODING *PPASN1_ENCODING;

#pragma pack(push,1)
struct ASN1_STRING_TABLE
{
	
public:
	int nid;
	int minsize;
	int maxsize;
	unsigned mask;
	unsigned flags;
};
#pragma pack(pop)


typedef ASN1_STRING_TABLE *PASN1_STRING_TABLE;

typedef ASN1_STRING_TABLE *PPASN1_STRING_TABLE;

typedef PSTACK PSTACK_OF_ASN1_STRING_TABLE;

typedef PASN1_ITEM PASN1_ITEM_EXP;

struct RSA;
typedef RSA *PRSA;

typedef PRSA *PPRSA;

#pragma pack(push,1)
struct RSA_METHOD
{
	
public:
	char *name;
	int __cdecl (*rsa_pub_enc)(int flen, const char * from, char * _to, PRSA rsa, int padding);
	int __cdecl (*rsa_pub_dec)(int flen, const char * from, char * _to, PRSA rsa, int padding);
	int __cdecl (*rsa_priv_enc)(int flen, const char * from, char * _to, PRSA rsa, int padding);
	int __cdecl (*rsa_priv_dec)(int flen, const char * from, char * _to, PRSA rsa, int padding);
	int __cdecl (*rsa_mod_exp)(PBIGNUM r0, const PBIGNUM I, PRSA rsa, void * ctx);
	int __cdecl (*bn_mod_exp)(PBIGNUM r, const PBIGNUM a, const PBIGNUM p, const PBIGNUM m, void * ctx, PBN_MONT_CTX m_ctx);
	int __cdecl (*init)(PRSA rsa);
	int __cdecl (*finish)(PRSA rsa);
	int flags;
	char *app_data;
	int __cdecl (*rsa_sign)(int _type, const char * m, unsigned m_length, char * sigret, Idctypes::PIdC_UINT siglen, const PRSA rsa);
	int __cdecl (*rsa_verify)(int dtype, const char * m, Idctypes::PIdC_UINT m_length, char * sigbuf, Idctypes::PIdC_UINT siglen, const PRSA rsa);
	int __cdecl (*rsa_keygen)(PRSA rsa, int bits, PBIGNUM e, PBN_GENCB cb);
};
#pragma pack(pop)


typedef void * PRSA_METHOD;

#pragma pack(push,1)
struct RSA
{
	
public:
	int pad;
	int version;
	void *engine;
	BIGNUM *n;
	BIGNUM *e;
	BIGNUM *d;
	BIGNUM *p;
	BIGNUM *q;
	BIGNUM *dmp1;
	BIGNUM *dmq1;
	BIGNUM *iqmp;
	CRYPTO_EX_DATA ex_data;
	int references;
	int flags;
	BN_MONT_CTX *_method_mod_n;
	BN_MONT_CTX *_method_mod_p;
	BN_MONT_CTX *_method_mod_q;
	char *bignum_data;
	void *blinding;
	void *mt_blinding;
};
#pragma pack(pop)


struct DH;
typedef DH *PDH;

#pragma pack(push,1)
struct DH_METHOD
{
	
public:
	char *name;
	int __cdecl (*generate_key)(PDH dh);
	int __cdecl (*compute_key)(char * key, const PBIGNUM pub_key, PDH dh);
	int __cdecl (*bn_mod_exp)(const PDH dh, PBIGNUM r, const PBIGNUM e, const PBIGNUM p, const PBIGNUM m, void * ctx, PBN_MONT_CTX m_ctx);
	int __cdecl (*init)(PDH dh);
	int __cdecl (*finish)(PDH dh);
	int flags;
	char *app_data;
	int __cdecl (*generate_params)(PDH dh, int prime_len, int generator, PBN_GENCB cb);
};
#pragma pack(pop)


#pragma pack(push,1)
struct DH
{
	
public:
	int pad;
	int version;
	void *meth;
	void *engine;
	BIGNUM *n;
	BIGNUM *e;
	BIGNUM *d;
	BIGNUM *p;
	BIGNUM *q;
	BIGNUM *dmp1;
	BIGNUM *dmq1;
	BIGNUM *iqmp;
	CRYPTO_EX_DATA ex_data;
	int references;
	int flags;
	BN_MONT_CTX _method_mod_n;
	BN_MONT_CTX _method_mod_p;
	BN_MONT_CTX _method_mod_q;
	char *bignum_data;
	void *blinding;
	void *mt_blinding;
};
#pragma pack(pop)


typedef PDH *PPDH;

#pragma pack(push,1)
struct DSA_SIG
{
	
public:
	BIGNUM *r;
	BIGNUM *s;
};
#pragma pack(pop)


typedef DSA_SIG *PDSA_SIG;

struct DSA;
typedef DSA *PDSA;

#pragma pack(push,1)
struct DSA_METHOD
{
	
public:
	char *name;
	PDSA_SIG __cdecl (*dsa_do_sign)(const char * dgst, int dlen, PDSA dsa);
	int __cdecl (*dsa_sign_setup)(PDSA dsa, void * ctx_in, PPBN_CTX kinvp, PPBN_CTX rp);
	int __cdecl (*dsa_do_verify)(char * dgst, int dgst_len, PDSA_SIG sig, PDSA dsa);
	int __cdecl (*dsa_mod_exp)(PDSA dsa, PBIGNUM rr, PBIGNUM a1, PBIGNUM p1, PBIGNUM a2, PBIGNUM p2, PBIGNUM m, void * ctx, PBN_MONT_CTX in_mont);
	int __cdecl (*bn_mod_exp)(PDSA dsa, PBIGNUM r, PBIGNUM a, const PBIGNUM p, const PBIGNUM m, void * ctx, void * m_ctx);
	int __cdecl (*init)(PDSA dsa);
	int __cdecl (*finish)(PDSA dsa);
	int flags;
	char *app_data;
	int __cdecl (*dsa_paramgen)(PDSA dsa, int bits, char * seed, int seed_len, Idctypes::PIdC_INT counter_ret, Idctypes::PIdC_ULONG h_ret, PBN_GENCB cb);
	int __cdecl (*dsa_keygen)(PDSA dsa);
};
#pragma pack(pop)


typedef DSA_METHOD *PDSA_METHOD;

#pragma pack(push,1)
struct DSA
{
	
public:
	int pad;
	int version;
	int write_params;
	BIGNUM *p;
	BIGNUM *q;
	BIGNUM *g;
	BIGNUM *pub_key;
	BIGNUM *priv_key;
	BIGNUM kinv;
	BIGNUM *r;
	int flags;
	BN_MONT_CTX *method_mont_p;
	int references;
	CRYPTO_EX_DATA ex_data;
	DSA_METHOD *meth;
	void *engine;
};
#pragma pack(pop)


typedef PDSA *PPDSA;

typedef void * PEC_METHOD;

typedef void * *PPEC_METHOD;

typedef void * PEC_GROUP;

typedef void * *PPEC_GROUP;

typedef void * PEC_POINT;

typedef void * *PPEC_POINT;

#pragma pack(push,1)
struct EC_builtin_curve
{
	
public:
	int nid;
	char *comment;
};
#pragma pack(pop)


typedef void * PEC_KEY;

typedef void * *PPEC_KEY;

typedef void * PEVP_PBE_KEYGEN;

struct EVP_PKEY;
typedef EVP_PKEY *PEVP_PKEY;

typedef PEVP_PKEY *PPEVP_PKEY;

#pragma pack(push,1)
struct EVP_PKEY_union
{
	
	union
	{
		struct 
		{
			void *ec;
			
		};
		struct 
		{
			DH *dh;
			
		};
		struct 
		{
			DSA *dsa;
			
		};
		struct 
		{
			RSA *rsa;
			
		};
		struct 
		{
			char *ptr;
			
		};
		
	};
};
#pragma pack(pop)


typedef PEVP_PKEY Pevp_pkey_st;

typedef PSTACK PSTACK_OF_X509_ATTRIBUTE;

typedef PSTACK *PPSTACK_OF_X509_ATTRIBUTE;

#pragma pack(push,1)
struct EVP_PKEY
{
	
public:
	int _type;
	int save_type;
	int references;
	EVP_PKEY_union pkey;
	STACK *attributes;
};
#pragma pack(pop)


struct EVP_MD;
typedef EVP_MD *PEVP_MD;

#pragma pack(push,1)
struct EVP_MD_CTX
{
	
public:
	EVP_MD *digest;
	void *engine;
	unsigned flags;
	void *md_data;
};
#pragma pack(pop)


typedef EVP_MD_CTX *PEVP_MD_CTX;

#pragma pack(push,1)
struct EVP_MD_SVCTX
{
	
public:
	EVP_MD_CTX *mctx;
	void *key;
};
#pragma pack(pop)


typedef EVP_MD_SVCTX *PEVP_MD_SVCTX;

#pragma pack(push,1)
struct EVP_MD
{
	
public:
	int _type;
	int pkey_type;
	int md_size;
	unsigned flags;
	int __cdecl (*init)(PEVP_MD_CTX ctx);
	int __cdecl (*update)(PEVP_MD_CTX ctx, void * data, unsigned count);
	int __cdecl (*_final)(PEVP_MD_CTX ctx, char * md);
	int __cdecl (*copy)(PEVP_MD_CTX _to, PEVP_MD_CTX from);
	int __cdecl (*cleanup)(PEVP_MD_CTX ctx);
	int __cdecl (*sign)(int _type, char * m, unsigned m_length, char * sigret, unsigned siglen, void * key);
	int __cdecl (*verify)(int _type, char * m, char * m_length, char * sigbuf, unsigned siglen, void * key);
	StaticArray<int, 5> required_pkey_type;
	int block_size;
	int ctx_size;
};
#pragma pack(pop)


struct EVP_CIPHER_CTX;
typedef EVP_CIPHER_CTX *PEVP_CIPHER_CTX;

typedef PEVP_CIPHER_CTX *PPEVP_CIPHER_CTX;

struct EVP_CIPHER;
typedef EVP_CIPHER *PEVP_CIPHER;

#pragma pack(push,1)
struct EVP_CIPHER
{
	
public:
	int nid;
	int block_size;
	int key_len;
	int iv_len;
	unsigned flags;
	int __cdecl (*init)(PEVP_CIPHER_CTX ctx, char * key, char * iv, int enc);
	int __cdecl (*do_cipher)(PEVP_CIPHER_CTX ctx, char * _out, char * _in, unsigned inl);
	int __cdecl (*cleanup)(PEVP_CIPHER_CTX _para1);
	int ctx_size;
	int __cdecl (*set_asn1_parameters)(PEVP_CIPHER_CTX _para1, PASN1_TYPE _para2);
	int __cdecl (*get_asn1_parameters)(PEVP_CIPHER_CTX _para1, PASN1_TYPE _para2);
	int __cdecl (*ctrl)(PEVP_CIPHER_CTX _para1, int _type, int arg, void * ptr);
	void *app_data;
};
#pragma pack(pop)


#pragma pack(push,1)
struct EVP_CIPHER_CTX
{
	
public:
	EVP_CIPHER *cipher;
	void *engine;
	int encrypt;
	int buf_len;
	StaticArray<char, 16> oiv;
	StaticArray<char, 16> iv;
	StaticArray<char, 32> buf;
	int num;
	void *app_data;
	int key_len;
	unsigned flags;
	void *cipher_data;
	int final_used;
	int block_mask;
	StaticArray<char, 32> _final;
};
#pragma pack(pop)


#pragma pack(push,1)
struct EVP_CIPHER_INFO
{
	
public:
	EVP_CIPHER *cipher;
	StaticArray<char, 16> iv;
};
#pragma pack(pop)


typedef EVP_CIPHER_INFO *PEVP_CIPHER_INFO;

#pragma pack(push,1)
struct EVP_ENCODE_CTX
{
	
public:
	int num;
	int length;
	StaticArray<char, 80> enc_data;
	int line_num;
	int expect_nl;
};
#pragma pack(pop)


typedef EVP_ENCODE_CTX *PEVP_ENCODE_CTX;

struct X509;
typedef X509 *PX509;

typedef PX509 *PPX509;

struct X509_CRL;
typedef X509_CRL *PX509_CRL;

struct X509_NAME;
typedef X509_NAME *PX509_NAME;

struct X509_NAME_ENTRY;
typedef X509_NAME_ENTRY *PX509_NAME_ENTRY;

struct X509_REQ;
typedef X509_REQ *PX509_REQ;

struct X509_REQ_INFO;
typedef X509_REQ_INFO *PX509_REQ_INFO;

typedef PX509_REQ_INFO *PPX509_REQ_INFO;

typedef PSTACK PSTACK_OF_X509_NAME_ENTRY;

typedef PSTACK PSTACK_OF_X509_REVOKED;

typedef PSTACK *PPSTACK_OF_X509_REVOKED;

typedef PX509_NAME *PPX509_NAME;

typedef PSTACK PSTACK_OF_X509_NAME;

typedef PSTACK *PPSTACK_OF_X509_NAME;

typedef PSTACK PSTACK_OF_X509_POLICY_DATA;

typedef PSTACK PSTACK_OF_X509_POLICY_REF;

typedef PSTACK PSTACK_OF_X509_POLICY_NODE;

typedef PSTACK PSTACK_OF_POLICYQUALINFO;

typedef PSTACK PSTACK_OF_X509V3_EXT_METHOD;

typedef PSTACK *PPSTACK_OF_X509V3_EXT_METHOD;

typedef PSTACK PSTACK_OF_X509;

typedef int __cdecl (*ENGINE_GEN_FUNC_PTR)(void);

typedef int __cdecl (*ENGINE_GEN_INT_FUNC_PTR)(void * Para1);

typedef void __cdecl (*ENGINE_CTRL_FUNC_PTR_F)(void);

typedef int __cdecl (*ENGINE_CTRL_FUNC_PTR)(void * Para1, int Para2, int Para3, void * Para4, ENGINE_CTRL_FUNC_PTR_F f);

typedef PEVP_PKEY __cdecl (*ENGINE_LOAD_KEY_PTR)(void * Para1, char * Para2, void * ui_method, void * callback_data);

typedef int __cdecl (*ENGINE_SSL_CLIENT_CERT_PTR)(void * Para1, PSSL ssl, PSTACK ca_dn, PX509 &pcert, PEVP_PKEY &pkey, PSTACK &pother, void * ui_method, void * callback_data);

typedef int __cdecl (*ENGINE_CIPHERS_PTR)(void * para1, PEVP_CIPHER &para2, Idctypes::PIdC_INT &para3, int para4);

typedef int __cdecl (*ENGINE_DIGESTS_PTR)(void * para1, PEVP_MD &Para2, Idctypes::PIdC_INT &Para3, int para);

typedef void * __cdecl (*dyn_MEM_malloc_cb)(unsigned para1);

typedef void * __cdecl (*dyn_MEM_realloc_cb)(void * para1, unsigned para2);

typedef void __cdecl (*dyn_MEM_free_cb)(void * para1);

#pragma pack(push,1)
struct dynamic_MEM_fns
{
	
public:
	dyn_MEM_malloc_cb malloc_cb;
	dyn_MEM_realloc_cb realloc_cb;
	dyn_MEM_free_cb free_cb;
};
#pragma pack(pop)


typedef void __cdecl (*dyn_lock_locking_cb)(int para1, int para2, char * para3, int para4);

typedef int __cdecl (*dyn_lock_add_lock_cb)(int &para1, int para2, int para3, char * para4, int para5);

typedef void * __cdecl (*dyn_dynlock_create_cb)(char * para1, int para2);

typedef void __cdecl (*dyn_dynlock_lock_cb)(int para1, void * para2);

typedef void __cdecl (*dyn_dynlock_destroy_cb)(void * para1, char * para2, int para3);

#pragma pack(push,1)
struct dynamic_LOCK_fns
{
	
public:
	dyn_lock_locking_cb lock_locking_cb;
	dyn_lock_add_lock_cb lock_add_lock_cb;
	dyn_dynlock_create_cb dynlock_create_cb;
	dyn_dynlock_lock_cb dynlock_lock_cb;
	dyn_dynlock_destroy_cb dynlock_destroy_cb;
};
#pragma pack(pop)


#pragma pack(push,1)
struct dynamic_fns
{
	
public:
	void *static_state;
	void *err_fns;
	void *ex_data_fns;
	dynamic_MEM_fns mem_fns;
	dynamic_LOCK_fns lock_fns;
};
#pragma pack(pop)


typedef unsigned __cdecl (*dynamic_v_check_fn)(unsigned ossl_version);

typedef int __cdecl (*dynamic_bind_engine)(void * e, char * id, const dynamic_fns fns);

#pragma pack(push,1)
struct ECDSA_SIG
{
	
public:
	BIGNUM *r;
	BIGNUM *s;
};
#pragma pack(pop)


typedef ECDSA_SIG *PECDSA_SIG;

typedef PECDSA_SIG *PPECDSA_SIG;

typedef void * PECDH_METHOD;

typedef void * *PPECDH_METHOD;

#pragma pack(push,1)
struct AES_KEY
{
	
public:
	StaticArray<unsigned, 60> rd_key;
	int rounds;
};
#pragma pack(pop)


typedef AES_KEY *PAES_KEY;

typedef PAES_KEY *PPAES_KEY;

struct LHASH_NODE;
typedef LHASH_NODE *PLHASH_NODE;

typedef PLHASH_NODE *PPLHASH_NODE;

#pragma pack(push,1)
struct LHASH_NODE
{
	
public:
	void *data;
	LHASH_NODE *next;
	unsigned hash;
};
#pragma pack(pop)


typedef int __cdecl (*LHASH_COMP_FN_TYPE)(const void * p1, const void * p2);

typedef LHASH_COMP_FN_TYPE *PLHASH_COMP_FN_TYPE;

typedef unsigned __cdecl (*LHASH_HASH_FN_TYPE)(const void * p1);

typedef void __cdecl (*LHASH_DOALL_FN_TYPE)(void * p1);

typedef void __cdecl (*LHASH_DOALL_ARG_FN_TYPE)(void * p1, void * p2);

#pragma pack(push,1)
struct LHASH
{
	
public:
	PLHASH_NODE *b;
	LHASH_COMP_FN_TYPE comp;
	LHASH_HASH_FN_TYPE hash;
	unsigned num_nodes;
	unsigned num_alloc_nodes;
	unsigned p;
	unsigned pmax;
	unsigned up_load;
	unsigned down_load;
	unsigned num_items;
	unsigned num_expands;
	unsigned num_expand_reallocs;
	unsigned num_contracts;
	unsigned num_contract_reallocs;
	unsigned num_hash_calls;
	unsigned num_comp_calls;
	unsigned num_insert;
	unsigned num_replace;
	unsigned num_delete;
	unsigned num_no_delete;
	unsigned num_retrieve;
	unsigned num_retrieve_miss;
	unsigned num_hash_comps;
	int error;
};
#pragma pack(pop)


typedef LHASH *PLHASH;

#pragma pack(push,1)
struct CONF_VALUE
{
	
public:
	char *section;
	char *name;
	char *value;
};
#pragma pack(pop)


typedef CONF_VALUE *PCONF_VALUE;

typedef PSTACK PSTACK_OF_CONF_VALUE;

#pragma pack(push,1)
struct BIT_STRING_BITNAME
{
	
public:
	int bitnum;
	char *lname;
	char *sname;
};
#pragma pack(pop)


typedef BIT_STRING_BITNAME *PBIT_STRING_BITNAME;

typedef PBIT_STRING_BITNAME *PPBIT_STRING_BITNAME;

#pragma pack(push,1)
struct buf_mem_st
{
	
public:
	int length;
	char *data;
	int max;
};
#pragma pack(pop)


typedef buf_mem_st BUF_MEM;

typedef buf_mem_st *PBUF_MEM;

typedef PBUF_MEM *PPBUF_MEM;

typedef void * PFILE;

#pragma pack(push,1)
struct ASN1_TEMPLATE
{
	
public:
	unsigned flags;
	int tag;
	unsigned offset;
	char *field_name;
	ASN1_ITEM *item;
};
#pragma pack(pop)


typedef ASN1_TEMPLATE *PASN1_TEMPLATE;

#pragma pack(push,1)
struct ASN1_ITEM
{
	
public:
	System::WideChar itype;
	int utype;
	ASN1_TEMPLATE *templates;
	int tcount;
	void *funcs;
	int size;
	char *sname;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_ASN1_ADB_TABLE;

typedef PSTACK *PPSTACK_OF_ASN1_ADB_TABLE;

struct ASN1_ADB_TABLE;
typedef ASN1_ADB_TABLE *PASN1_ADB_TABLE;

struct ASN1_ADB;
typedef ASN1_ADB *PASN1_ADB;

#pragma pack(push,1)
struct ASN1_ADB
{
	
public:
	unsigned flags;
	unsigned offset;
	PSTACK *app_items;
	ASN1_ADB_TABLE *tbl;
	int tblcount;
	ASN1_TEMPLATE *default_tt;
	ASN1_TEMPLATE *null_tt;
};
#pragma pack(pop)


#pragma pack(push,1)
struct ASN1_ADB_TABLE
{
	
public:
	int flags;
	int offset;
	PSTACK *app_items;
	ASN1_ADB_TABLE *tbl;
	int tblcount;
	ASN1_TEMPLATE *default_tt;
	ASN1_TEMPLATE *null_tt;
};
#pragma pack(pop)


struct ASN1_TLC;
typedef ASN1_TLC *PASN1_TLC;

#pragma pack(push,1)
struct ASN1_TLC
{
	
public:
	System::Byte valid;
	int ret;
	int plen;
	int ptag;
	int pclass;
	int hdrlen;
};
#pragma pack(pop)


typedef void * __cdecl (*ASN1_new_func)(void);

typedef void __cdecl (*ASN1_free_func)(void * a);

typedef void * __cdecl (*ASN1_d2i_func)(void * a, PPByte _in, int length);

typedef int __cdecl (*ASN1_i2d_func)(void * a, PPByte _in);

typedef int __cdecl (*ASN1_ex_d2i)(PPASN1_VALUE pval, PPByte _in, int len, PASN1_ITEM it, int tag, int aclass, System::Byte opt, PASN1_TLC ctx);

typedef int __cdecl (*ASN1_ex_i2d)(PPASN1_VALUE pval, PPByte _out, PASN1_ITEM it, int tag, int aclass);

typedef int __cdecl (*ASN1_ex_new_func)(PPASN1_VALUE pval, PASN1_ITEM it);

typedef void __cdecl (*ASN1_ex_free_func)(PPASN1_VALUE pval, PASN1_ITEM it);

typedef int __cdecl (*ASN1_primitive_i2c)(PPASN1_VALUE pval, System::PByte cont, Idctypes::PIdC_INT putype, PASN1_ITEM it);

typedef int __cdecl (*ASN1_primitive_c2i)(PPASN1_VALUE pval, System::PByte cont, int len, int utype, System::PByte free_cont, PASN1_ITEM it);

#pragma pack(push,1)
struct ASN1_COMPAT_FUNCS
{
	
public:
	ASN1_new_func asn1_new;
	ASN1_free_func asn1_free;
	ASN1_d2i_func asn1_d2i;
	ASN1_i2d_func asn1_i2d;
};
#pragma pack(pop)


typedef ASN1_COMPAT_FUNCS *PASN1_COMPAT_FUNCS;

#pragma pack(push,1)
struct ASN1_EXTERN_FUNCS
{
	
public:
	void *app_data;
	ASN1_ex_new_func asn1_ex_new;
	ASN1_ex_free_func asn1_ex_free;
	ASN1_ex_free_func asn1_ex_clear;
	ASN1_ex_d2i asn1_ex_d2i;
	ASN1_ex_i2d asn1_ex_i2d;
};
#pragma pack(pop)


typedef ASN1_EXTERN_FUNCS *PASN1_EXTERN_FUNCS;

#pragma pack(push,1)
struct ASN1_PRIMITIVE_FUNCS
{
	
public:
	void *app_data;
	unsigned flags;
	ASN1_ex_new_func prim_new;
	ASN1_ex_free_func prim_free;
	ASN1_ex_free_func prim_clear;
	ASN1_primitive_c2i prim_c2i;
	ASN1_primitive_i2c prim_i2c;
};
#pragma pack(pop)


typedef ASN1_PRIMITIVE_FUNCS *PASN1_PRIMITIVE_FUNCS;

typedef int __cdecl (*ASN1_aux_cb)(int operation, PPASN1_VALUE _in, PASN1_ITEM it);

#pragma pack(push,1)
struct ASN1_AUX
{
	
public:
	void *app_data;
	int flags;
	int ref_offset;
	int ref_lock;
	ASN1_aux_cb asn1_cb;
	int enc_offset;
};
#pragma pack(pop)


typedef ASN1_AUX *PASN1_AUX;

#pragma pack(push,1)
struct HMAC_CTX
{
	
public:
	EVP_MD *md;
	EVP_MD_CTX md_ctx;
	EVP_MD_CTX i_ctx;
	EVP_MD_CTX o_ctx;
	unsigned key_length;
	StaticArray<System::Byte, 128> key;
};
#pragma pack(pop)


typedef HMAC_CTX *PHMAC_CTX;

typedef PHMAC_CTX *PPHMAC_CTX;

typedef void * PX509_POLICY_DATA;

typedef void * PX509_POLICY_REF;

typedef void * PX509_POLICY_CACHE;

typedef PX509_NAME_ENTRY *PPX509_NAME_ENTRY;

struct V3_EXT_METHOD;
typedef V3_EXT_METHOD *PV3_EXT_METHOD;

struct V3_EXT_CTX;
typedef V3_EXT_CTX *PV3_EXT_CTX;

typedef void * __cdecl (*X509V3_EXT_NEW)(void);

typedef void __cdecl (*X509V3_EXT_FREE)(void * _para1);

typedef void * __cdecl (*X509V3_EXT_D2I)(void * _para1, const System::PPAnsiChar _para2, int para3);

typedef int __cdecl (*X509V3_EXT_I2D)(void * _para1, System::PPAnsiChar _para2);

typedef PSTACK __cdecl (*X509V3_EXT_I2V)(PV3_EXT_METHOD method, void * ext, PSTACK extlist);

typedef void * __cdecl (*X509V3_EXT_V2I)(PV3_EXT_METHOD method, PV3_EXT_CTX ctx, PSTACK values);

typedef char * __cdecl (*X509V3_EXT_I2S)(PV3_EXT_METHOD method, void * ext);

typedef void * __cdecl (*X509V3_EXT_S2I)(PV3_EXT_METHOD method, PV3_EXT_CTX ctx, const char * str);

typedef int __cdecl (*X509V3_EXT_I2R)(PV3_EXT_METHOD method, void * ext, PBIO _out, int indent);

typedef void * __cdecl (*X509V3_EXT_R2I)(PV3_EXT_METHOD method, PV3_EXT_CTX ctx, const char * str);

#pragma pack(push,1)
struct V3_EXT_METHOD
{
	
public:
	int ext_nid;
	int ext_flags;
	ASN1_ITEM *it;
	X509V3_EXT_NEW ext_new;
	X509V3_EXT_FREE ext_free;
	X509V3_EXT_D2I d2i;
	X509V3_EXT_I2D i2d;
	X509V3_EXT_I2S i2s;
	X509V3_EXT_S2I s2i;
	X509V3_EXT_I2V i2v;
	X509V3_EXT_V2I v2i;
	X509V3_EXT_I2R i2r;
	X509V3_EXT_R2I r2i;
	void *usr_data;
};
#pragma pack(pop)


typedef V3_EXT_METHOD X509V3_EXT_METHOD;

#pragma pack(push,1)
struct X509V3_CONF_METHOD
{
	
public:
	char * __cdecl (*get_string)(void * db, char * section, char * value);
	PSTACK __cdecl (*get_section)(void * db, char * section);
	void __cdecl (*free_string)(void * db, char * _string);
	void __fastcall (*free_section)(void * db, PSTACK section);
};
#pragma pack(pop)


#pragma pack(push,1)
struct V3_EXT_CTX
{
	
public:
	int flags;
	X509 *issuer_cert;
	X509 *subject_cert;
	X509_REQ *subject_req;
	X509_CRL *crl;
	X509V3_CONF_METHOD db_meth;
	void *db;
};
#pragma pack(pop)


typedef BIT_STRING_BITNAME ENUMERATED_NAMES;

#pragma pack(push,1)
struct BASIC_CONSTRAINTS
{
	
public:
	int ca;
	asn1_string_st *pathlen;
};
#pragma pack(pop)


typedef BASIC_CONSTRAINTS *PBASIC_CONSTRAINTS;

#pragma pack(push,1)
struct PKEY_USAGE_PERIOD
{
	
public:
	asn1_string_st notBefore;
	asn1_string_st *notAfter;
};
#pragma pack(pop)


typedef PKEY_USAGE_PERIOD *PPKEY_USAGE_PERIOD;

#pragma pack(push,1)
struct OTHERNAME
{
	
public:
	ASN1_OBJECT *type_id;
	ASN1_TYPE *value;
};
#pragma pack(pop)


typedef OTHERNAME *POTHERNAME;

#pragma pack(push,1)
struct EDIPARTYNAME
{
	
public:
	asn1_string_st *nameAssigner;
	asn1_string_st *partyName;
};
#pragma pack(pop)


typedef EDIPARTYNAME *PEDIPARTYNAME;

#pragma pack(push,1)
struct GENERAL_NAME_union
{
	
	union
	{
		struct 
		{
			ASN1_TYPE *other;
			
		};
		struct 
		{
			ASN1_OBJECT rid;
			
		};
		struct 
		{
			asn1_string_st *ia5;
			
		};
		struct 
		{
			X509_NAME *dirn;
			
		};
		struct 
		{
			asn1_string_st *ip;
			
		};
		struct 
		{
			ASN1_OBJECT *registeredID;
			
		};
		struct 
		{
			asn1_string_st *iPAddress;
			
		};
		struct 
		{
			asn1_string_st *uniformResourceIdentifier;
			
		};
		struct 
		{
			EDIPARTYNAME *ediPartyName;
			
		};
		struct 
		{
			X509_NAME *directoryName;
			
		};
		struct 
		{
			ASN1_TYPE *x400Address;
			
		};
		struct 
		{
			asn1_string_st *dNSName;
			
		};
		struct 
		{
			asn1_string_st *rfc822Name;
			
		};
		struct 
		{
			OTHERNAME *otherName;
			
		};
		struct 
		{
			char *ptr;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct GENERAL_NAME
{
	
public:
	int _type;
	GENERAL_NAME_union d;
};
#pragma pack(pop)


typedef GENERAL_NAME *PGENERAL_NAME;

typedef PSTACK PSTACK_OF_GENERAL_NAME;

typedef PSTACK PGENERAL_NAMES;

#pragma pack(push,1)
struct ACCESS_DESCRIPTION
{
	
public:
	ASN1_OBJECT *method;
	GENERAL_NAME *location;
};
#pragma pack(pop)


typedef ACCESS_DESCRIPTION *PACCESS_DESCRIPTION;

typedef PSTACK PSTACK_OF_ACCESS_DESCRIPTION;

typedef PSTACK PAUTHORITY_INFO_ACCESS;

typedef PSTACK PEXTENDED_KEY_USAGE;

#pragma pack(push,1)
struct DIST_POINT_NAME_union
{
	
	union
	{
		struct 
		{
			STACK *relativename;
			
		};
		struct 
		{
			STACK *fullname;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct DIST_POINT_NAME
{
	
public:
	int _type;
	DIST_POINT_NAME_union name;
};
#pragma pack(pop)


typedef DIST_POINT_NAME *PDIST_POINT_NAME;

#pragma pack(push,1)
struct DIST_POINT
{
	
public:
	DIST_POINT_NAME *distpoint;
	asn1_string_st *reasons;
	STACK *CRLissuer;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_DIST_POINT;

#pragma pack(push,1)
struct AUTHORITY_KEYID
{
	
public:
	asn1_string_st *keyid;
	STACK *issuer;
	asn1_string_st *serial;
};
#pragma pack(pop)


typedef AUTHORITY_KEYID *PAUTHORITY_KEYID;

#pragma pack(push,1)
struct SXNETID
{
	
public:
	asn1_string_st *zone;
	asn1_string_st *user;
};
#pragma pack(pop)


typedef SXNETID *PSXNETID;

typedef PSTACK PSTACK_OF_SXNETID;

#pragma pack(push,1)
struct SXNET
{
	
public:
	asn1_string_st *version;
	STACK *ids;
};
#pragma pack(pop)


typedef SXNET *PSXNET;

#pragma pack(push,1)
struct NOTICEREF
{
	
public:
	asn1_string_st *organization;
	STACK *noticenos;
};
#pragma pack(pop)


typedef NOTICEREF *PNOTICEREF;

#pragma pack(push,1)
struct USERNOTICE
{
	
public:
	NOTICEREF *noticeref;
	asn1_string_st *exptext;
};
#pragma pack(pop)


typedef USERNOTICE *PUSERNOTICE;

#pragma pack(push,1)
struct POLICYQUALINFO_union
{
	
	union
	{
		struct 
		{
			ASN1_TYPE *other;
			
		};
		struct 
		{
			USERNOTICE *usernotice;
			
		};
		struct 
		{
			asn1_string_st *cpsuri;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct POLICYQUALINFO
{
	
public:
	ASN1_OBJECT *pqualid;
	POLICYQUALINFO_union d;
};
#pragma pack(pop)


typedef POLICYQUALINFO *PPOLICYQUALINFO;

typedef PSTACK PSTACK_OF_POLICYINFO;

#pragma pack(push,1)
struct POLICYINFO
{
	
public:
	ASN1_OBJECT *policyid;
	STACK *qualifiers;
};
#pragma pack(pop)


typedef PSTACK CERTIFICATEPOLICIES;

#pragma pack(push,1)
struct POLICY_MAPPING
{
	
public:
	ASN1_OBJECT *issuerDomainPolicy;
	ASN1_OBJECT *subjectDomainPolicy;
};
#pragma pack(pop)


typedef POLICY_MAPPING *PPOLICY_MAPPING;

typedef PSTACK PSTACK_OF_POLICY_MAPPING;

typedef PSTACK *PPSTACK_OF_POLICY_MAPPING;

#pragma pack(push,1)
struct GENERAL_SUBTREE
{
	
public:
	GENERAL_NAME *base;
	asn1_string_st *minimum;
	asn1_string_st *maximum;
};
#pragma pack(pop)


typedef GENERAL_SUBTREE *PGENERAL_SUBTREE;

typedef PSTACK PSTACK_OF_GENERAL_SUBTREE;

#pragma pack(push,1)
struct NAME_CONSTRAINTS
{
	
public:
	STACK *permittedSubtrees;
	STACK *excludedSubtrees;
};
#pragma pack(pop)


typedef NAME_CONSTRAINTS *PNAME_CONSTRAINTS;

#pragma pack(push,1)
struct POLICY_CONSTRAINTS
{
	
public:
	asn1_string_st *requireExplicitPolicy;
	asn1_string_st inhibitPolicyMapping;
};
#pragma pack(pop)


typedef POLICY_CONSTRAINTS *PPOLICY_CONSTRAINTS;

#pragma pack(push,1)
struct PROXY_POLICY
{
	
public:
	ASN1_OBJECT *policyLanguage;
	asn1_string_st policy;
};
#pragma pack(pop)


typedef PROXY_POLICY *PPROXY_POLICY;

#pragma pack(push,1)
struct PROXY_CERT_INFO_EXTENSION
{
	
public:
	asn1_string_st *pcPathLengthConstraint;
	PROXY_POLICY *proxyPolicy;
};
#pragma pack(pop)


typedef PROXY_CERT_INFO_EXTENSION *PPROXY_CERT_INFO_EXTENSION;

struct X509_PURPOSE;
typedef X509_PURPOSE *PX509_PURPOSE;

typedef int __cdecl (*X509_PURPOSE_check_purpose)(const PX509_PURPOSE _para1, const PX509 _para2, int para3);

#pragma pack(push,1)
struct X509_PURPOSE
{
	
public:
	int purpose;
	int trust;
	int flags;
	X509_PURPOSE_check_purpose check_purpose;
	char *name;
	char *sname;
	void *usr_data;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_X509_PURPOSE;

#pragma pack(push,1)
struct X509_HASH_DIR_CTX
{
	
public:
	int num_dirs;
	char * *dirs;
	int *dirs_type;
	int num_dirs_alloced;
};
#pragma pack(pop)


typedef X509_HASH_DIR_CTX *PX509_HASH_DIR_CTX;

#pragma pack(push,1)
struct X509_CERT_FILE_CTX
{
	
public:
	int num_paths;
	int num_alloced;
	char * *paths;
	int path_type;
};
#pragma pack(pop)


typedef X509_CERT_FILE_CTX *PX509_CERT_FILE_CTX;

#pragma pack(push,1)
struct x509_object_union
{
	
	union
	{
		struct 
		{
			EVP_PKEY *pkey;
			
		};
		struct 
		{
			X509_CRL *crl;
			
		};
		struct 
		{
			X509 *_x509;
			
		};
		struct 
		{
			char *ptr;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct X509_OBJECT
{
	
public:
	int _type;
	x509_object_union data;
};
#pragma pack(pop)


typedef X509_OBJECT *PX509_OBJECT;

typedef PX509_OBJECT *PPX509_OBJECT;

typedef PSTACK PSTACK_OF_X509_OBJECT;

#pragma pack(push,1)
struct X509_ALGOR
{
	
public:
	ASN1_OBJECT *algorithm;
	ASN1_TYPE *parameter;
};
#pragma pack(pop)


typedef X509_ALGOR *PX509_ALGOR;

typedef PX509_ALGOR *PPX509_ALGOR;

typedef PSTACK PSTACK_OF_X509_ALGOR;

typedef PSTACK *PPSTACK_OF_X509_ALGOR;

#pragma pack(push,1)
struct X509_VAL
{
	
public:
	asn1_string_st *notBefore;
	asn1_string_st *notAfter;
};
#pragma pack(pop)


typedef X509_VAL *PX509_VAL;

typedef PX509_VAL *PPX509_VAL;

#pragma pack(push,1)
struct X509_PUBKEY
{
	
public:
	X509_ALGOR *algor;
	asn1_string_st *public_key;
	EVP_PKEY *pkey;
};
#pragma pack(pop)


typedef X509_PUBKEY *PX509_PUBKEY;

typedef PX509_PUBKEY *PPX509_PUBKEY;

#pragma pack(push,1)
struct X509_SIG
{
	
public:
	X509_ALGOR *algor;
	asn1_string_st *digest;
};
#pragma pack(pop)


typedef X509_SIG PX509_SIG;

typedef X509_SIG *PPX509_SIG;

#pragma pack(push,1)
struct X509_NAME_ENTRY
{
	
public:
	ASN1_OBJECT *_object;
	asn1_string_st *value;
	int _set;
	int size;
};
#pragma pack(pop)


#pragma pack(push,1)
struct X509_NAME
{
	
public:
	STACK *entries;
	int modified;
	buf_mem_st *bytes;
	unsigned hash;
};
#pragma pack(pop)


#pragma pack(push,1)
struct X509_EXTENSION
{
	
public:
	ASN1_OBJECT *_object;
	int critical;
	asn1_string_st *value;
};
#pragma pack(pop)


typedef X509_EXTENSION *PX509_EXTENSION;

typedef PX509_EXTENSION *PPX509_EXTENSION;

typedef PSTACK PSTACK_OF_X509_EXTENSION;

typedef PSTACK *PPSTACK_OF_X509_EXTENSION;

typedef PPSTACK_OF_X509_EXTENSION PX509_EXTENSIONS;

#pragma pack(push,1)
struct x509_attributes_union
{
	
	union
	{
		struct 
		{
			ASN1_TYPE *_single;
			
		};
		struct 
		{
			PSTACK *_set;
			
		};
		struct 
		{
			char *Ptr;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct X509_ATTRIBUTE
{
	
public:
	ASN1_OBJECT *_object;
	int single;
	x509_attributes_union value;
};
#pragma pack(pop)


typedef X509_ATTRIBUTE *PX509_ATTRIBUTE;

typedef PX509_ATTRIBUTE *PPX509_ATTRIBUTE;

#pragma pack(push,1)
struct X509_REQ_INFO
{
	
public:
	ASN1_ENCODING enc;
	asn1_string_st *version;
	X509_NAME *subject;
	X509_PUBKEY *pubkey;
	STACK *attributes;
};
#pragma pack(pop)


#pragma pack(push,1)
struct X509_REQ
{
	
public:
	X509_REQ_INFO *req_info;
	X509_ALGOR *sig_alg;
	asn1_string_st *signature;
	int references;
};
#pragma pack(pop)


typedef PX509_REQ *PPX509_REQ;

#pragma pack(push,1)
struct X509_CINF
{
	
public:
	asn1_string_st *version;
	asn1_string_st *serialNumber;
	X509_ALGOR *signature;
	X509_NAME *issuer;
	X509_VAL *validity;
	X509_NAME *subject;
	X509_PUBKEY *key;
	asn1_string_st *issuerUID;
	asn1_string_st *subjectUID;
	STACK *extensions;
};
#pragma pack(pop)


typedef X509_CINF *PX509_CINF;

#pragma pack(push,1)
struct X509_CERT_AUX
{
	
public:
	STACK *trust;
	STACK *reject;
	asn1_string_st *alias;
	asn1_string_st *keyid;
	STACK *other;
};
#pragma pack(pop)


typedef X509_CERT_AUX *PX509_CERT_AUX;

#pragma pack(push,1)
struct X509
{
	
public:
	X509_CINF *cert_info;
	X509_ALGOR *sig_alg;
	asn1_string_st *signature;
	int valid;
	int references;
	char *name;
	CRYPTO_EX_DATA ex_data;
	int ex_pathlen;
	int ex_pcpathlen;
	unsigned ex_flags;
	unsigned ex_kusage;
	unsigned ex_xkusage;
	unsigned ex_nscert;
	asn1_string_st *skid;
	AUTHORITY_KEYID *akid;
	void *policy_cache;
	StaticArray<char, 20> sha1_hash;
	X509_CERT_AUX *aux;
};
#pragma pack(pop)


#pragma pack(push,1)
struct X509_CRL_INFO
{
	
public:
	asn1_string_st *version;
	X509_ALGOR *sig_alg;
	X509_NAME *issuer;
	asn1_string_st *lastUpdate;
	asn1_string_st *nextUpdate;
	STACK *revoked;
	STACK *extensions;
	ASN1_ENCODING enc;
};
#pragma pack(pop)


typedef X509_CRL_INFO *PX509_CRL_INFO;

typedef PX509_CRL_INFO *PPX509_CRL_INFO;

typedef PSTACK PSTACK_OF_X509_CRL_INFO;

struct X509_LOOKUP;
typedef X509_LOOKUP *PX509_LOOKUP;

typedef PSTACK PSTACK_OF_X509_LOOKUP;

struct X509_VERIFY_PARAM;
typedef X509_VERIFY_PARAM *PX509_VERIFY_PARAM;

struct X509_STORE_CTX;
typedef X509_STORE_CTX *PX509_STORE_CTX;

typedef PX509_CRL *PPX509_CRL;

#pragma pack(push,1)
struct X509_STORE
{
	
public:
	int cache;
	STACK *objs;
	STACK *get_cert_methods;
	X509_VERIFY_PARAM *param;
	int __cdecl (*verify)(PX509_STORE_CTX ctx);
	int __cdecl (*verify_cb)(int ok, PX509_STORE_CTX ctx);
	int __cdecl (*get_issuer)(PPX509 issuer, PX509_STORE_CTX ctx, PX509 x);
	int __cdecl (*check_issued)(PX509_STORE_CTX ctx, PX509 x, PX509 issuer);
	int __cdecl (*check_revocation)(PX509_STORE_CTX ctx);
	int __cdecl (*get_crl)(PX509_STORE_CTX ctx, PPX509_CRL crl, PX509 x);
	int __cdecl (*check_crl)(PX509_STORE_CTX ctx, PX509_CRL crl);
	int __cdecl (*cert_crl)(PX509_STORE_CTX ctx, PX509_CRL crl, PX509 x);
	int __cdecl (*cleanup)(PX509_STORE_CTX ctx);
	CRYPTO_EX_DATA ex_data;
	int references;
};
#pragma pack(pop)


typedef X509_STORE *PX509_STORE;

#pragma pack(push,1)
struct X509_CRL
{
	
public:
	X509_CRL_INFO *crl;
	X509_ALGOR *sig_alg;
	asn1_string_st *signature;
	int references;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_X509_CRL;

#pragma pack(push,1)
struct X509_LOOKUP_METHOD
{
	
public:
	char *name;
	int __cdecl (*new_item)(PX509_LOOKUP ctx);
	void __cdecl (*free)(PX509_LOOKUP ctx);
	int __cdecl (*init)(PX509_LOOKUP ctx);
	int __cdecl (*shutdown)(PX509_LOOKUP ctx);
	int __cdecl (*ctrl)(PX509_LOOKUP ctx, int cmd, char * argc, int argl, /* out */ char * &ret);
	int __cdecl (*get_by_subject)(PX509_LOOKUP ctx, int _type, PX509_NAME name, const X509_OBJECT ret);
	int __cdecl (*get_by_issuer_serial)(PX509_LOOKUP ctx, int _type, PX509_NAME name, PASN1_INTEGER serial, PX509_OBJECT ret);
	int __cdecl (*get_by_fingerprint)(PX509_LOOKUP ctx, int _type, char * bytes, int len, PX509_OBJECT ret);
	int __cdecl (*get_by_alias)(PX509_LOOKUP ctx, int _type, char * str, PX509_OBJECT ret);
};
#pragma pack(pop)


typedef X509_LOOKUP_METHOD *PX509_LOOKUP_METHOD;

typedef PX509_LOOKUP_METHOD *PPX509_LOOKUP_METHOD;

#pragma pack(push,1)
struct X509_VERIFY_PARAM
{
	
public:
	char *name;
	int check_time;
	unsigned inh_flags;
	unsigned flags;
	int purpose;
	int trust;
	int depth;
	STACK *policies;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_X509_VERIFY_PARAM;

#pragma pack(push,1)
struct X509_LOOKUP
{
	
public:
	int init;
	int skip;
	X509_LOOKUP_METHOD *method;
	char *method_data;
	X509_STORE *store_ctx;
};
#pragma pack(pop)


typedef PSTACK *PPSTACK_OF_X509_LOOKUP;

#pragma pack(push,1)
struct X509_STORE_CTX
{
	
public:
	X509_STORE *ctx;
	int current_method;
	X509 *cert;
	STACK *untrusted;
	STACK *crls;
	X509_VERIFY_PARAM *param;
	void *other_ctx;
	int __cdecl (*verify)(PX509_STORE_CTX ctx);
	int __cdecl (*verify_cb)(int ok, PX509_STORE_CTX ctx);
	int __cdecl (*get_issuer)(PX509 &issuer, PX509_STORE_CTX ctx, PX509 x);
	int __cdecl (*check_issued)(PX509_STORE_CTX ctx, PX509 x, PX509 issuer);
	int __cdecl (*check_revocation)(PX509_STORE_CTX ctx);
	int __cdecl (*get_crl)(PX509_STORE_CTX ctx, X509_CRL &crl, PX509 x);
	int __cdecl (*check_crl)(PX509_STORE_CTX ctx, X509_CRL &crl);
	int __cdecl (*cert_crl)(PX509_STORE_CTX ctx, PX509_CRL crl, PX509 x);
	int __cdecl (*check_policy)(PX509_STORE_CTX ctx);
	int __cdecl (*cleanup)(PX509_STORE_CTX ctx);
};
#pragma pack(pop)


typedef void * PX509_EXTENSION_METHOD;

struct X509_TRUST;
typedef X509_TRUST *PX509_TRUST;

typedef int __cdecl (*X509_TRUST_check_trust)(PX509_TRUST _para1, PX509 para2, int _para3);

#pragma pack(push,1)
struct X509_TRUST
{
	
public:
	int trust;
	int flags;
	X509_TRUST_check_trust check_trust;
	char *name;
	int arg1;
	void *arg2;
};
#pragma pack(pop)


typedef PX509_TRUST *PPX509_TRUST;

typedef PSTACK PSTACK_OF_509_TRUST;

#pragma pack(push,1)
struct X509_REVOKED
{
	
public:
	asn1_string_st *serialNumber;
	asn1_string_st *revocationDate;
	STACK *extensions;
	int sequence;
};
#pragma pack(pop)


typedef X509_REVOKED *PX509_REVOKED;

typedef PX509_REVOKED *PPX509_REVOKED;

typedef void * PX509_PKEY;

typedef void * *PPX509_PKEY;

#pragma pack(push,1)
struct X509_INFO
{
	
public:
	X509 *x509;
	X509_CRL *crl;
	void *x_pkey;
	EVP_CIPHER_INFO enc_cipher;
	int enc_len;
	char *enc_data;
	int references;
};
#pragma pack(pop)


typedef X509_INFO *PX509_INFO;

typedef PX509_INFO *PPX509_INFO;

typedef PSTACK PSTACK_OF_X509_INFO;

#pragma pack(push,1)
struct NETSCAPE_SPKAC
{
	
public:
	X509_PUBKEY *pubkey;
	asn1_string_st *challenge;
};
#pragma pack(pop)


typedef NETSCAPE_SPKAC *PNETSCAPE_SPKAC;

typedef PNETSCAPE_SPKAC *PPNETSCAPE_SPKAC;

#pragma pack(push,1)
struct NETSCAPE_SPKI
{
	
public:
	NETSCAPE_SPKAC *spkac;
	X509_ALGOR *sig_algor;
	asn1_string_st *signature;
};
#pragma pack(pop)


typedef NETSCAPE_SPKI *PNETSCAPE_SPKI;

typedef PNETSCAPE_SPKI *PPNETSCAPE_SPKI;

#pragma pack(push,1)
struct NETSCAPE_CERT_SEQUENCE
{
	
public:
	ASN1_OBJECT *_type;
	STACK *certs;
};
#pragma pack(pop)


typedef NETSCAPE_CERT_SEQUENCE *PNETSCAPE_CERT_SEQUENCE;

typedef PNETSCAPE_CERT_SEQUENCE *PPNETSCAPE_CERT_SEQUENCE;

#pragma pack(push,1)
struct PBEPARAM
{
	
public:
	asn1_string_st *salt;
	asn1_string_st *iter;
};
#pragma pack(pop)


typedef PBEPARAM *PPBEPARAM;

typedef PPBEPARAM *PPPBEPARAM;

#pragma pack(push,1)
struct PBE2PARAM
{
	
public:
	X509_ALGOR *keyfunc;
	X509_ALGOR *encryption;
};
#pragma pack(pop)


typedef PBE2PARAM *PPBE2PARAM;

#pragma pack(push,1)
struct PBKDF2PARAM
{
	
public:
	ASN1_TYPE *salt;
	asn1_string_st *iter;
	asn1_string_st *keylength;
	X509_ALGOR *prf;
};
#pragma pack(pop)


typedef PBKDF2PARAM *PPBKDF2PARAM;

typedef PPBKDF2PARAM *PPPBKDF2PARAM;

#pragma pack(push,1)
struct PKCS8_PRIV_KEY_INFO
{
	
public:
	int broken;
	asn1_string_st *version;
	X509_ALGOR *pkeyalg;
	ASN1_TYPE *pkey;
	STACK *attributes;
};
#pragma pack(pop)


typedef PKCS8_PRIV_KEY_INFO *PPKCS8_PRIV_KEY_INFO;

typedef PPKCS8_PRIV_KEY_INFO *PPPKCS8_PRIV_KEY_INFO;

struct PKCS7_RECIP_INFO;
typedef PKCS7_RECIP_INFO *PPKCS7_RECIP_INFO;

typedef SHA_CTX *PSHA_CTX;

typedef unsigned RIPEMD160_LONG;

#pragma pack(push,1)
struct RIPEMD160_CTX
{
	
public:
	unsigned A;
	unsigned B;
	unsigned C;
	unsigned D;
	unsigned E;
	unsigned Nl;
	unsigned Nh;
	StaticArray<unsigned, 16> data;
	unsigned num;
};
#pragma pack(pop)


typedef RIPEMD160_CTX *PRIPEMD160_CTX;

#pragma pack(push,1)
struct RC4_KEY
{
	
public:
	unsigned x;
	unsigned y;
	StaticArray<unsigned, 256> data;
};
#pragma pack(pop)


typedef RC4_KEY *PRC4_KEY;

#pragma pack(push,1)
struct RC2_KEY
{
	
public:
	StaticArray<unsigned, 64> data;
};
#pragma pack(pop)


typedef RC2_KEY *PRC2_KEY;

typedef unsigned BF_LONG;

#pragma pack(push,1)
struct BF_KEY
{
	
public:
	StaticArray<unsigned, 18> P;
	StaticArray<unsigned, 1024> S;
};
#pragma pack(pop)


typedef BF_KEY *PBF_KEY;

typedef unsigned CAST_LONG;

#pragma pack(push,1)
struct CAST_KEY
{
	
public:
	StaticArray<unsigned, 32> data;
	int short_key;
};
#pragma pack(pop)


typedef CAST_KEY *PCAST_KEY;

#pragma pack(push,1)
struct IDEA_KEY_SCHEDULE
{
	
public:
	StaticArray<StaticArray<unsigned, 6>, 9> data;
};
#pragma pack(pop)


typedef IDEA_KEY_SCHEDULE *PIDEA_KEY_SCHEDULE;

#pragma pack(push,1)
struct OCSP_CERTID
{
	
public:
	X509_ALGOR *hashAlgorithm;
	asn1_string_st *issuerNameHash;
	asn1_string_st *issuerKeyHash;
	asn1_string_st *serialNumber;
};
#pragma pack(pop)


typedef OCSP_CERTID *POCSP_CERTID;

typedef POCSP_CERTID *PPOCSP_CERTID;

typedef PSTACK PSTACK_OF_OCSP_CERTID;

#pragma pack(push,1)
struct OCSP_ONEREQ
{
	
public:
	OCSP_CERTID *reqCert;
	STACK *singleRequestExtensions;
};
#pragma pack(pop)


typedef OCSP_ONEREQ *POCSP_ONEREQ;

typedef POCSP_ONEREQ *PPOCSP_ONEREQ;

typedef PSTACK PSTACK_OF_OCSP_ONEREQ;

#pragma pack(push,1)
struct OCSP_REQINFO
{
	
public:
	asn1_string_st *version;
	GENERAL_NAME *requestorName;
	STACK *requestList;
	STACK *requestExtensions;
};
#pragma pack(pop)


typedef OCSP_REQINFO *POCSP_REQINFO;

typedef POCSP_REQINFO *PPOCSP_REQINFO;

#pragma pack(push,1)
struct OCSP_SIGNATURE
{
	
public:
	X509_ALGOR *signatureAlgorithm;
	asn1_string_st *signature;
	STACK *certs;
};
#pragma pack(pop)


typedef OCSP_SIGNATURE *POCSP_SIGNATURE;

typedef POCSP_SIGNATURE *PPOCSP_SIGNATURE;

#pragma pack(push,1)
struct OCSP_REQUEST
{
	
public:
	OCSP_REQINFO *tbsRequest;
	OCSP_SIGNATURE *optionalSignature;
};
#pragma pack(pop)


typedef OCSP_REQUEST *POCSP_REQUEST;

typedef POCSP_REQUEST *PPOCSP_REQUEST;

#pragma pack(push,1)
struct OCSP_RESPBYTES
{
	
public:
	ASN1_OBJECT *responseType;
	asn1_string_st *response;
};
#pragma pack(pop)


typedef OCSP_RESPBYTES *POCSP_RESPBYTES;

typedef POCSP_RESPBYTES *PPOCSP_RESPBYTES;

#pragma pack(push,1)
struct OCSP_RESPONSE
{
	
public:
	asn1_string_st *responseStatus;
	OCSP_RESPBYTES *responseBytes;
};
#pragma pack(pop)


typedef OCSP_RESPONSE *POCSP_RESPONSE;

typedef POCSP_RESPONSE *PPOCSP_RESPONSE;

#pragma pack(push,1)
struct OCSP_RESPID_union
{
	
	union
	{
		struct 
		{
			asn1_string_st *byKey;
			
		};
		struct 
		{
			X509_NAME *byName;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct OCSP_RESPID
{
	
public:
	int _type;
	OCSP_RESPID_union value;
};
#pragma pack(pop)


typedef OCSP_RESPID *POCSP_RESPID;

typedef POCSP_RESPID *PPOCSP_RESPID;

typedef PSTACK PSTACK_OF_OCSP_RESPID;

#pragma pack(push,1)
struct OCSP_REVOKEDINFO
{
	
public:
	asn1_string_st *revocationTime;
	asn1_string_st *revocationReason;
};
#pragma pack(pop)


typedef OCSP_REVOKEDINFO *POCSP_REVOKEDINFO;

typedef POCSP_REVOKEDINFO *PPOCSP_REVOKEDINFO;

#pragma pack(push,1)
struct OCSP_CERTSTATUS_union
{
	
	union
	{
		struct 
		{
			int *unknown;
			
		};
		struct 
		{
			OCSP_REVOKEDINFO *revoked;
			
		};
		struct 
		{
			int *good;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct OCSP_CERTSTATUS
{
	
public:
	int _type;
	OCSP_CERTSTATUS_union value;
};
#pragma pack(pop)


typedef OCSP_CERTSTATUS *POCSP_CERTSTATUS;

typedef POCSP_CERTSTATUS *PPOCSP_CERTSTATUS;

#pragma pack(push,1)
struct OCSP_SINGLERESP
{
	
public:
	OCSP_CERTID *certId;
	OCSP_CERTSTATUS *certStatus;
	asn1_string_st *thisUpdate;
	asn1_string_st *nextUpdate;
	STACK *singleExtensions;
};
#pragma pack(pop)


typedef OCSP_SINGLERESP *POCSP_SINGLERESP;

typedef POCSP_SINGLERESP *PPOCSP_SINGLERESP;

typedef PSTACK PSTACK_OF_OCSP_SINGLERESP;

#pragma pack(push,1)
struct OCSP_RESPDATA
{
	
public:
	asn1_string_st *version;
	OCSP_RESPID *responderId;
	asn1_string_st *producedAt;
	STACK *responses;
	STACK *responseExtensions;
};
#pragma pack(pop)


typedef OCSP_RESPDATA *POCSP_RESPDATA;

typedef POCSP_RESPDATA *PPOCSP_RESPDATA;

#pragma pack(push,1)
struct OCSP_BASICRESP
{
	
public:
	OCSP_RESPDATA *tbsResponseData;
	X509_ALGOR *signatureAlgorithm;
	asn1_string_st *signature;
	STACK *certs;
};
#pragma pack(pop)


typedef OCSP_BASICRESP *POCSP_BASICRESP;

typedef POCSP_BASICRESP *PPOCSP_BASICRESP;

#pragma pack(push,1)
struct OCSP_CRLID
{
	
public:
	asn1_string_st *crlUrl;
	asn1_string_st *crlNum;
	asn1_string_st *crlTime;
};
#pragma pack(pop)


typedef OCSP_CRLID *POCSP_CRLID;

typedef POCSP_CRLID *PPOCSP_CRLID;

#pragma pack(push,1)
struct OCSP_SERVICELOC
{
	
public:
	X509_NAME *issuer;
	STACK *locator;
};
#pragma pack(pop)


typedef OCSP_SERVICELOC *POCSP_SERVICELOC;

typedef POCSP_SERVICELOC *PPOCSP_SERVICELOC;

typedef void * PMDC2_CTX;

typedef void * PMS_TM;

typedef void * *PPMS_TM;

typedef int __cdecl (*ppem_password_cb)(char * buf, int size, int rwflag, void * userdata);

#pragma pack(push,1)
struct PEM_ENCODE_SEAL_CTX
{
	
public:
	EVP_ENCODE_CTX encode;
	EVP_MD_CTX md;
	EVP_CIPHER_CTX cipher;
};
#pragma pack(pop)


typedef PEM_ENCODE_SEAL_CTX *PPEM_ENCODE_SEAL_CTX;

typedef PSTACK PSTACK_OF_SSL_COMP;

typedef PSTACK *PPSTACK_OF_SSL_COMP;

struct SSL_COMP;
typedef SSL_COMP *PSSL_COMP;

typedef void * Phostent2;

typedef StaticArray<System::Byte, 8> DES_cblock;

typedef DES_cblock *PDES_cblock;

typedef DES_cblock const_DES_cblock;

typedef DES_cblock *Pconst_DES_cblock;

typedef unsigned DES_LONG;

#pragma pack(push,1)
struct des_cblock_union
{
	
	union
	{
		struct 
		{
			StaticArray<unsigned, 2> deslong;
			
		};
		struct 
		{
			DES_cblock cblock;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct des_ks_struct
{
	
public:
	des_cblock_union ks;
	int weak_key;
};
#pragma pack(pop)


typedef StaticArray<des_ks_struct, 16> des_key_schedule;

typedef StaticArray<System::Byte, 8> des_cblocks;

typedef StaticArray<System::Byte, 8> _ossl_old_des_cblock;

typedef _ossl_old_des_cblock *P_ossl_old_des_cblock;

#pragma pack(push,1)
struct _ossl_old_des_ks_union
{
	
	union
	{
		struct 
		{
			StaticArray<unsigned, 2> pad;
			
		};
		struct 
		{
			_ossl_old_des_cblock _;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct _ossl_old_des_ks_struct
{
	
public:
	_ossl_old_des_ks_union ks;
};
#pragma pack(pop)


typedef StaticArray<_ossl_old_des_ks_struct, 16> _ossl_old_des_key_schedule;

typedef _ossl_old_des_key_schedule *P_ossl_old_des_key_schedule;

typedef DES_cblock _des_cblock;

typedef DES_cblock _const_des_cblock;

typedef des_key_schedule _des_key_schedule;

typedef void __cdecl (*TIdSslLockingCallback)(int mode, int n, char * Afile, int line);

typedef unsigned __cdecl (*TIdSslIdCallback)(void);

typedef void * PSSL3_ENC_METHOD;

typedef void * PCERT;

typedef void * *PPCERT;

typedef void * PSESS_CERT;

struct PKCS7;
typedef PKCS7 *PPKCS7;

#pragma pack(push,1)
struct PKCS7_ISSUER_AND_SERIAL
{
	
public:
	X509_NAME *issuer;
	asn1_string_st *serial;
};
#pragma pack(pop)


typedef PKCS7_ISSUER_AND_SERIAL *PPKCS7_ISSUER_AND_SERIAL;

#pragma pack(push,1)
struct PKCS7_SIGNER_INFO
{
	
public:
	asn1_string_st *version;
	PKCS7_ISSUER_AND_SERIAL *issuer_and_serial;
	X509_ALGOR *digest_alg;
	STACK *auth_attr;
	X509_ALGOR *digest_enc_alg;
	asn1_string_st *enc_digest;
	STACK *unauth_attr;
	EVP_PKEY *pkey;
};
#pragma pack(pop)


typedef PKCS7_SIGNER_INFO *PPKCS7_SIGNER_INFO;

typedef PSTACK PSTACK_OF_PKCS7_SIGNER_INFO;

#pragma pack(push,1)
struct PKCS7_RECIP_INFO
{
	
public:
	asn1_string_st *version;
	PKCS7_ISSUER_AND_SERIAL *issuer_and_serial;
	X509_ALGOR *key_enc_algor;
	asn1_string_st *enc_key;
	X509 *cert;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_PKCS7_RECIP_INFO;

typedef PSTACK *PPSTACK_OF_PKCS7_RECIP_INFO;

#pragma pack(push,1)
struct PKCS7_SIGNED
{
	
public:
	asn1_string_st *version;
	STACK *md_algs;
	STACK *cert;
	STACK *crl;
	STACK *signer_info;
	PKCS7 *contents;
};
#pragma pack(pop)


typedef PKCS7_SIGNED *PPKCS7_SIGNED;

typedef PPKCS7_SIGNED *PPPKCS7_SIGNED;

#pragma pack(push,1)
struct PKCS7_ENC_CONTENT
{
	
public:
	ASN1_OBJECT *content_type;
	X509_ALGOR *algorithm;
	asn1_string_st *enc_data;
	EVP_CIPHER *cipher;
};
#pragma pack(pop)


typedef PKCS7_ENC_CONTENT *PPKCS7_ENC_CONTENT;

#pragma pack(push,1)
struct PKCS7_ENVELOPE
{
	
public:
	asn1_string_st *version;
	STACK *recipientinfo;
	PKCS7_ENC_CONTENT *enc_data;
};
#pragma pack(pop)


typedef PKCS7_ENVELOPE *PPKCS7_ENVELOPE;

#pragma pack(push,1)
struct PKCS7_SIGN_ENVELOPE
{
	
public:
	asn1_string_st *version;
	STACK *md_algs;
	STACK *cert;
	STACK *crl;
	STACK *signer_info;
	PKCS7_ENC_CONTENT *enc_data;
	STACK *recipientinfo;
};
#pragma pack(pop)


typedef PKCS7_SIGN_ENVELOPE *PPKCS7_SIGN_ENVELOPE;

#pragma pack(push,1)
struct PKCS7_DIGEST
{
	
public:
	asn1_string_st *version;
	X509_ALGOR *md;
	PKCS7 *contents;
	asn1_string_st *digest;
};
#pragma pack(pop)


typedef PKCS7_DIGEST *PPKCS7_DIGEST;

#pragma pack(push,1)
struct PKCS7_ENCRYPT
{
	
public:
	asn1_string_st *version;
	PKCS7_ENC_CONTENT *enc_data;
};
#pragma pack(pop)


typedef PKCS7_ENCRYPT *PPKCS7_ENCRYPT;

#pragma pack(push,1)
struct PKCS7_union
{
	
	union
	{
		struct 
		{
			PKCS7_ENCRYPT *encrypted;
			
		};
		struct 
		{
			PKCS7_DIGEST *digest;
			
		};
		struct 
		{
			PKCS7_SIGN_ENVELOPE *signed_and_enveloped;
			
		};
		struct 
		{
			PKCS7_ENVELOPE *enveloped;
			
		};
		struct 
		{
			PKCS7_SIGNED *sign;
			
		};
		struct 
		{
			asn1_string_st *data;
			
		};
		struct 
		{
			char *ptr;
			
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct PKCS7
{
	
public:
	char *asn1;
	int length;
	int state;
	int detached;
	ASN1_OBJECT *_type;
	PKCS7_union d;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_PKCS7;

#pragma pack(push,1)
struct PKCS12_MAC_DATA
{
	
public:
	X509_SIG dinfo;
	asn1_string_st *salt;
	asn1_string_st *iter;
};
#pragma pack(pop)


typedef PKCS12_MAC_DATA *PPKCS12_MAC_DATA;

#pragma pack(push,1)
struct PKCS12
{
	
public:
	asn1_string_st *version;
	PKCS12_MAC_DATA *mac;
	PKCS7 *authsafes;
};
#pragma pack(pop)


typedef PKCS12 *PPKCS12;

struct COMP_CTX;
typedef COMP_CTX *PCOMP_CTX;

#pragma pack(push,1)
struct COMP_METHOD
{
	
public:
	int _type;
	char *name;
	int __cdecl (*init)(PCOMP_CTX ctx);
	void __cdecl (*finish)(PCOMP_CTX ctx);
	int __cdecl (*compress)(PCOMP_CTX ctx, char * _out, unsigned olen, char * _in, unsigned ilen);
	int __cdecl (*expand)(PCOMP_CTX ctx, char * _out, unsigned olen, char * _in, unsigned ilen);
	int __cdecl (*ctrl)(void);
	int __cdecl (*callback_ctrl)(void);
};
#pragma pack(pop)


typedef COMP_METHOD *PCOMP_METHOD;

#pragma pack(push,1)
struct COMP_CTX
{
	
public:
	COMP_METHOD *meth;
	unsigned compress_in;
	unsigned compress_out;
	unsigned expand_in;
	unsigned expand_out;
	CRYPTO_EX_DATA *ex_data;
};
#pragma pack(pop)


struct SSL_CIPHER;
typedef SSL_CIPHER *PSSL_CIPHER;

#pragma pack(push,1)
struct SSL_CIPHER
{
	
public:
	int valid;
	char *name;
	unsigned id;
	unsigned algorithms;
	unsigned algo_strength;
	unsigned algorithm2;
	int strength_bits;
	int alg_bits;
	unsigned mask;
	unsigned mask_strength;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_SSL_CIPHER;

#pragma pack(push,1)
struct SSL_SESSION
{
	
public:
	int ssl_version;
	unsigned key_arg_length;
	StaticArray<System::Byte, 8> key_arg;
	int master_key_length;
	StaticArray<System::Byte, 48> master_key;
	unsigned session_id_length;
	StaticArray<System::Byte, 32> session_id;
	unsigned sid_ctx_length;
	StaticArray<System::Byte, 32> sid_ctx;
	int not_resumable;
	void *sess_cert;
	char *tlsext_hostname;
	char *tlsext_tick;
	unsigned tlsext_ticklen;
	int tlsext_tick_lifetime_hint;
};
#pragma pack(pop)


typedef SSL_SESSION *PSSL_SESSION;

struct SSL_CTX;
typedef SSL_CTX *PSSL_CTX;

typedef void __cdecl (*SSL_METHOD_PROC)(void);

struct SSL_METHOD;
typedef SSL_METHOD *PSSL_METHOD;

#pragma pack(push,1)
struct SSL_METHOD
{
	
public:
	int version;
	int __cdecl (*ssl_new)(PSSL s);
	void __cdecl (*ssl_clear)(PSSL s);
	void __cdecl (*ssl_free)(PSSL s);
	int __cdecl (*ssl_accept)(PSSL s);
	int __cdecl (*ssl_connect)(PSSL s);
	int __cdecl (*ssl_read)(PSSL s, void * buf, int len);
	int __cdecl (*ssl_peek)(PSSL s, void * buf, int len);
	int __cdecl (*ssl_write)(PSSL s, const void * buf, int len);
	int __cdecl (*ssl_shutdown)(PSSL s);
	int __cdecl (*ssl_renegotiate)(PSSL s);
	int __cdecl (*ssl_renegotiate_check)(PSSL s);
	int __cdecl (*ssl_get_message)(PSSL s, int st1, int stn, int mt, int max, Idctypes::PIdC_INT ok);
	int __cdecl (*ssl_read_bytes)(PSSL s, int _type, System::PByte buf, int len, int peek);
	int __cdecl (*ssl_write_bytes)(PSSL s, int _type, const void * buf, int len);
	int __cdecl (*ssl_dispatch_alert)(PSSL s);
	int __cdecl (*ssl_ctrl)(PSSL s, int cmd, int larg, void * parg);
	int __cdecl (*ssl_ctx_ctrl)(PSSL_CTX ctx, int cmd, int larg, void * parg);
	PSSL_CIPHER __cdecl (*get_cipher_by_char)(const System::PByte ptr);
	int __cdecl (*put_cipher_by_char)(const PSSL_CIPHER cipher, System::PByte ptr);
	int __cdecl (*ssl_pending)(const PSSL s);
	int __cdecl (*num_ciphers)(void);
	PSSL_CIPHER __cdecl (*get_cipher)(unsigned ncipher);
	PSSL_METHOD __cdecl (*get_ssl_method)(int version);
	int __cdecl (*get_timeout)(void);
	void *ssl3_enc;
	int __cdecl (*ssl_version)(void);
	int __cdecl (*ssl_callback_ctrl)(PSSL s, int cb_id, SSL_METHOD_PROC fp);
	int __cdecl (*ssl_ctx_callback_ctrl)(PSSL_CTX s, int cb_id, SSL_METHOD_PROC fp);
};
#pragma pack(pop)


typedef PSSL_METHOD *PPSSL_METHOD;

typedef int __cdecl (*PGEN_SESSION_CB)(const PSSL SSL, System::PByte id, unsigned id_len);

#pragma pack(push,1)
struct SSL_COMP
{
	
public:
	int id;
	char *name;
	COMP_METHOD *method;
};
#pragma pack(pop)


typedef PSTACK PSTACK_OF_COMP;

typedef int __cdecl (*PSSL_CTEX_tlsext_servername_callback)(PSSL ssl, int Para1, void * Para2);

typedef void __cdecl (*PSSL_CTX_info_callback)(const PSSL ssl, int _type, int val);

typedef int __cdecl (*Ptlsext_ticket_key_cb)(PSSL ssl, char * name, char * iv, PEVP_CIPHER_CTX ectx, PHMAC_CTX hctx, int enc);

typedef int __cdecl (*Ptlsext_status_cb)(PSSL ssl, void * arg);

#pragma pack(push,1)
struct SSL_CTX
{
	
public:
	SSL_METHOD *method;
	STACK *cipher_list;
	STACK *cipher_list_by_id;
	X509_STORE *cert_store;
	LHASH *sessions;
	unsigned session_cache_size;
	SSL_SESSION *session_cache_head;
	SSL_SESSION *session_cache_tail;
	int session_cache_mode;
	int session_timeout;
	int __cdecl (*new_session_cb)(PSSL ssl, PSSL_SESSION sess);
	void __cdecl (*remove_session_cb)(PSSL_CTX ctx, PSSL_SESSION sess);
	PSSL_SESSION __cdecl (*get_session_cb)(PSSL ssl, System::PByte data, int len, Idctypes::PIdC_INT copy);
	int sess_connect;
	int sess_connect_renegotiate;
	int sess_connect_good;
	int sess_accept;
	int sess_accept_renegotiate;
	int sess_accept_good;
	int sess_miss;
	int sess_timeout;
	int sess_cache_full;
	int sess_hit;
	int sess_cb_hit;
	int references;
	int __cdecl (*app_verify_callback)(PX509_STORE_CTX _para1, void * _para2);
	void *app_verify_arg;
	ppem_password_cb default_passwd_callback;
	void *default_passwd_callback_userdata;
	int __cdecl (*client_cert_cb)(PSSL SSL, PPX509 x509, PPEVP_PKEY pkey);
	int __cdecl (*app_gen_cookie_cb)(PSSL ssl, System::PByte cookie, unsigned cookie_len);
	void *app_verify_cookie_cb;
	CRYPTO_EX_DATA ex_data;
	EVP_MD *rsa_md5;
	EVP_MD *md5;
	EVP_MD *sha1;
	STACK *extra_certs;
	STACK *comp_methods;
	PSSL_CTX_info_callback info_callback;
	STACK *client_CA;
	unsigned options;
	unsigned mode;
	int max_cert_list;
	void *cert;
	int read_ahead;
	void __cdecl (*msg_callback)(int write_p, int version, int content_type, const void * buf, unsigned len, PSSL ssl, void * arg);
	void *msg_callback_arg;
	int verify_mode;
	unsigned sid_ctx_length;
	StaticArray<char, 32> sid_ctx;
	int __cdecl (*default_verify_callback)(int ok, PX509_STORE_CTX ctx);
	PGEN_SESSION_CB generate_session_id;
	X509_VERIFY_PARAM *param;
	void *client_cert_engine;
	int quiet_shutdown;
	PSSL_CTEX_tlsext_servername_callback tlsext_servername_callback;
	void *tlsext_servername_arg;
	StaticArray<char, 16> tlsext_tick_key_name;
	StaticArray<char, 16> tlsext_tick_hmac_key;
	StaticArray<char, 16> tlsext_tick_aes_key;
	Ptlsext_ticket_key_cb tlsext_ticket_key_cb;
	Ptlsext_status_cb tlsext_status_cb;
	void *tlsext_status_arg;
};
#pragma pack(pop)


struct SSL2_STATE;
typedef SSL2_STATE *PSSL2_STATE;

struct SSL3_STATE;
typedef SSL3_STATE *PSSL3_STATE;

struct DTLS1_STATE;
typedef DTLS1_STATE *PDTLS1_STATE;

typedef void __cdecl (*PSSL_tlsext_debug_cb)(PSSL s, int client_server, int _type, char * data, int len, void * arg);

#pragma pack(push,1)
struct SSL
{
	
public:
	int version;
	int _type;
	SSL_METHOD *method;
	BIO *rbio;
	BIO *wbio;
	BIO *bbio;
	int rwstate;
	int in_handshake;
	int __cdecl (*handshake_func)(PSSL _para1);
	int server;
	int new_session;
	int quiet_shutdown;
	int shutdown;
	int state;
	int rstate;
	buf_mem_st *init_buf;
	void *init_msg;
	int init_num;
	int init_off;
	char *packet;
	unsigned packet_length;
	SSL2_STATE *s2;
	SSL3_STATE *s3;
	DTLS1_STATE *d1;
	int read_ahead;
	void __cdecl (*msg_callback)(int write_p, int version, int content_type, const void * buf, unsigned len, PSSL ssl, void * arg);
	void *msg_callback_arg;
	int hit;
	X509_VERIFY_PARAM *param;
	STACK *cipher_list;
	STACK *cipher_list_by_id;
	EVP_CIPHER_CTX *enc_read_ctx;
	EVP_MD *read_hash;
	COMP_CTX *expand;
	EVP_CIPHER_CTX *enc_write_ctx;
	EVP_MD *write_hash;
	COMP_CTX *compress;
	void *cert;
	unsigned sid_ctx_length;
	StaticArray<char, 32> sid_ctx;
	SSL_SESSION *session;
	PGEN_SESSION_CB generate_session_id;
	int verify_mode;
	int __cdecl (*verify_callback)(int ok, PX509_STORE_CTX ctx);
	void __cdecl (*info_callback)(const PSSL ssl, int _type, int val);
	int error;
	int error_code;
	SSL_CTX *ctx;
	int debug;
	int verify_result;
	CRYPTO_EX_DATA ex_data;
	STACK *client_CA;
	int references;
	unsigned options;
	unsigned mode;
	int max_cert_list;
	int first_packet;
	int client_version;
	PSSL_tlsext_debug_cb tlsext_debug_cb;
	void *tlsext_debug_arg;
	char *tlsext_hostname;
	int servername_done;
	int tlsext_status_type;
	int tlsext_status_expected;
	STACK *tlsext_ocsp_ids;
	PSTACK *tlsext_ocsp_exts;
	char *tlsext_ocsp_resp;
	int tlsext_ocsp_resplen;
	int tlsext_ticket_expected;
	SSL_CTX *initial_ctx;
};
#pragma pack(pop)


#pragma pack(push,1)
struct SSL2_STATE
{
	
public:
	int three_byte_header;
	int clear_text;
	int escape;
	int ssl2_rollback;
	unsigned wnum;
	int wpend_tot;
	System::Byte *wpend_buf;
	int wpend_off;
	int wpend_len;
	int wpend_ret;
	int rbuf_left;
	int rbuf_offs;
	char *rbuf;
	char *wbuf;
	char *write_ptr;
	unsigned padding;
	unsigned rlength;
	int ract_data_length;
	unsigned wlength;
	int wact_data_length;
	char *ract_data;
	char *wact_data;
	char *mac_data;
	char *read_key;
	char *write_key;
	unsigned challenge_length;
	StaticArray<char, 32> challenge;
	unsigned conn_id_length;
	StaticArray<char, 16> conn_id;
	unsigned key_material_length;
	StaticArray<char, 48> key_material;
	unsigned read_sequence;
	unsigned write_sequence;
	unsigned tmp_conn_id_length;
	unsigned tmp_cert_type;
	unsigned tmp_cert_length;
	unsigned tmp_csl;
	unsigned tmp_clear;
	unsigned tmp_enc;
	StaticArray<char, 32> tmp_ccl;
	unsigned tmp_cipher_spec_length;
	unsigned tmp_session_id_length;
	unsigned tmp_clen;
	unsigned tmp_rlen;
};
#pragma pack(pop)


struct SSL3_RECORD;
typedef SSL3_RECORD *PSSL3_RECORD;

#pragma pack(push,1)
struct SSL3_RECORD
{
	
public:
	int _type;
	unsigned length;
	unsigned off;
	char *data;
	char *input;
	char *comp;
	unsigned epoch;
	__int64 seq_num;
};
#pragma pack(pop)


struct SSL3_BUFFER;
typedef SSL3_BUFFER *PSSL3_BUFFER;

#pragma pack(push,1)
struct SSL3_BUFFER
{
	
public:
	char *buf;
	unsigned len;
	int offset;
	int left;
};
#pragma pack(pop)


#pragma pack(push,1)
struct SSL3_STATE
{
	
public:
	int flags;
	int delay_buf_pop_ret;
	StaticArray<char, 8> read_sequence;
	StaticArray<char, 64> read_mac_secret;
	StaticArray<char, 8> write_sequence;
	StaticArray<char, 65> write_mac_secret;
	StaticArray<char, 32> server_random;
	StaticArray<char, 32> client_random;
	int need_empty_fragments;
	int empty_fragment_done;
	SSL3_BUFFER *rbuf;
	SSL3_BUFFER *wbuf;
	SSL3_RECORD *rrec;
	SSL3_RECORD *wrec;
	StaticArray<char *, 2> alert_fragment;
	unsigned alert_fragment_len;
	StaticArray<char *, 4> handshake_fragment;
	unsigned handshake_fragment_len;
	unsigned wnum;
	int wpend_tot;
	int wpend_type;
	int wpend_ret;
	System::Byte *wpend_buf;
	EVP_MD_CTX *finish_dgst1;
	EVP_MD_CTX *finish_dgst2;
	int change_cipher_spec;
	int warn_alert;
	int fatal_alert;
	int alert_dispatch;
	StaticArray<char, 2> send_alert;
	int renegotiate;
	int total_renegotiations;
	int num_renegotiations;
	int in_read_app_data;
	StaticArray<char, 128> tmp_cert_verify_md;
	StaticArray<char, 128> tmp_finish_md;
	int tmp_finish_md_len;
	StaticArray<char, 128> tmp_peer_finish_md;
	int tmp_peer_finish_md_len;
	unsigned tmp_message_size;
	int tmp_message_type;
	SSL_CIPHER *tmp_new_cipher;
	DH *tmp_dh;
	void *tmp_ecdh;
	int tmp_next_state;
	int tmp_reuse_message;
	int tmp_cert_req;
	int tmp_ctype_num;
	StaticArray<char, 7> tmp_ctype;
	STACK *tmp_ca_names;
	int tmp_use_rsa_tmp;
	int tmp_key_block_length;
	char *tmp_key_block;
	EVP_CIPHER *tmp_new_sym_enc;
	EVP_MD *tmp_new_hash;
	SSL_COMP *tmp_new_compression;
	int tmp_cert_request;
};
#pragma pack(pop)


struct pitem;
typedef pitem *ppitem;

#pragma pack(push,1)
struct pitem
{
	
public:
	__int64 priority;
	void *data;
	pitem *next;
};
#pragma pack(pop)


#pragma pack(push,1)
struct pqueue
{
	
public:
	pitem *items;
	int count;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DTLS1_BITMAP
{
	
public:
	__int64 map;
	unsigned length;
	__int64 max_seq_num;
};
#pragma pack(pop)


typedef DTLS1_BITMAP *PDTLS1_BITMAP;

#pragma pack(push,1)
struct hm_header
{
	
public:
	char *_type;
	unsigned msg_len;
	System::Word seq;
	unsigned frag_off;
	unsigned frag_len;
	unsigned is_ccs;
};
#pragma pack(pop)


#pragma pack(push,1)
struct ccs_header_st
{
	
public:
	char *_type;
	System::Word seq;
};
#pragma pack(pop)


#pragma pack(push,1)
struct dtls1_timeout_st
{
	
public:
	unsigned read_timeouts;
	unsigned write_timeouts;
	unsigned num_alerts;
};
#pragma pack(pop)


#pragma pack(push,1)
struct record_pqueue
{
	
public:
	System::Word epoch;
	pqueue q;
};
#pragma pack(pop)


#pragma pack(push,1)
struct hm_fragment
{
	
public:
	hm_header msg_header;
	char *fragment;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DTLS1_STATE
{
	
public:
	unsigned send_cookie;
	StaticArray<char, 32> cookie;
	StaticArray<char, 32> rcvd_cookie;
	unsigned cookie_len;
	System::Word r_epoch;
	System::Word w_epoch;
	DTLS1_BITMAP bitmap;
	DTLS1_BITMAP next_bitmap;
	System::Word handshake_write_seq;
	System::Word next_handshake_write_seq;
	System::Word handshake_read_seq;
	record_pqueue unprocessed_rcds;
	record_pqueue processed_rcds;
	pqueue buffered_messages;
	pqueue sent_messages;
	unsigned mtu;
	hm_header w_msg_hdr;
	hm_header r_msg_hdr;
	dtls1_timeout_st timeout;
	StaticArray<char, 2> alert_fragment;
	unsigned alert_fragment_len;
	StaticArray<char, 12> handshake_fragment;
	unsigned handshake_fragment_len;
	unsigned retransmitting;
};
#pragma pack(pop)


typedef V3_EXT_CTX X509V3_CTX;

typedef V3_EXT_CTX *PX509V3_CTX;

typedef void __cdecl (*TRSA_generate_key_callback)(int p1, int p2, void * p3);

typedef void * __cdecl (*TCRYPTO_set_mem_functions_m)(unsigned size);

typedef void * __cdecl (*TCRYPTO_set_mem_functions_r)(void * ptr, unsigned size);

typedef void __cdecl (*TCRYPTO_set_mem_functions_f)(void * ptr);

typedef void * __cdecl (*TCRYPTO_set_mem_ex_functions_m)(unsigned size, const char * c, int i);

typedef void * __cdecl (*TCRYPTO_set_mem_ex_functions_r)(void * ptr, unsigned size, const char * c, int i);

typedef void __cdecl (*TCRYPTO_set_mem_ex_functions_f)(void * ptr);

typedef void __cdecl (*Tset_mem_debug_functions_m)(void * addr, int num, const char * _file, int line, int before_p);

typedef void __cdecl (*Tset_mem_debug_functions_r)(void * addr1, void * addr2, int num, const char * _file, int line, int before_p);

typedef void __cdecl (*Tset_mem_debug_functions_f)(void * addr, int before_p);

typedef void __cdecl (*Tset_mem_debug_functions_so)(int bits);

typedef int __cdecl (*Tset_mem_debug_functions_go)(void);

typedef int __cdecl (*TSSL_CTX_set_verify_callback)(int ok, PX509_STORE_CTX ctx);

typedef void __cdecl (*Tsk_pop_free_func)(void * p);

typedef void __cdecl (*SSL_callback_ctrl_fp)(void * p);

class DELPHICLASS EIdOpenSSLError;
#pragma pack(push,1)
class PASCALIMPLEMENTATION EIdOpenSSLError : public Idexception::EIdException
{
	typedef Idexception::EIdException inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOpenSSLError(const System::UnicodeString AMsg)/* overload */ : Idexception::EIdException(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOpenSSLError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOpenSSLError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOpenSSLError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOpenSSLError(const System::UnicodeString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOpenSSLError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOpenSSLError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOpenSSLError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOpenSSLError(void) { }
	
};

#pragma pack(pop)

typedef TMetaClass* TIdOpenSSLAPISSLError;

class DELPHICLASS EIdOpenSSLAPISSLError;
#pragma pack(push,1)
class PASCALIMPLEMENTATION EIdOpenSSLAPISSLError : public EIdOpenSSLError
{
	typedef EIdOpenSSLError inherited;
	
protected:
	int FErrorCode;
	int FRetCode;
	
public:
	__classmethod void __fastcall RaiseException(PSSL s, const int ARetCode, const System::UnicodeString AMsg = L"");
	__property int ErrorCode = {read=FErrorCode, nodefault};
	__property int RetCode = {read=FRetCode, nodefault};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOpenSSLAPISSLError(const System::UnicodeString AMsg)/* overload */ : EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOpenSSLAPISSLError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOpenSSLAPISSLError(int Ident)/* overload */ : EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOpenSSLAPISSLError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOpenSSLAPISSLError(const System::UnicodeString Msg, int AHelpContext) : EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOpenSSLAPISSLError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOpenSSLAPISSLError(int Ident, int AHelpContext)/* overload */ : EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOpenSSLAPISSLError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOpenSSLAPISSLError(void) { }
	
};

#pragma pack(pop)

typedef TMetaClass* TIdOpenSSLAPICryptoError;

class DELPHICLASS EIdOpenSSLAPICryptoError;
#pragma pack(push,1)
class PASCALIMPLEMENTATION EIdOpenSSLAPICryptoError : public EIdOpenSSLError
{
	typedef EIdOpenSSLError inherited;
	
protected:
	unsigned FErrorCode;
	
public:
	__classmethod void __fastcall RaiseExceptionCode(const unsigned AErrCode, const System::UnicodeString AMsg = L"");
	__classmethod void __fastcall RaiseException(const System::UnicodeString AMsg = L"");
	__property unsigned ErrorCode = {read=FErrorCode, nodefault};
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOpenSSLAPICryptoError(const System::UnicodeString AMsg)/* overload */ : EIdOpenSSLError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOpenSSLAPICryptoError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdOpenSSLError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOpenSSLAPICryptoError(int Ident)/* overload */ : EIdOpenSSLError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOpenSSLAPICryptoError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdOpenSSLError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOpenSSLAPICryptoError(const System::UnicodeString Msg, int AHelpContext) : EIdOpenSSLError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOpenSSLAPICryptoError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdOpenSSLError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOpenSSLAPICryptoError(int Ident, int AHelpContext)/* overload */ : EIdOpenSSLError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOpenSSLAPICryptoError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdOpenSSLError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOpenSSLAPICryptoError(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EIdOSSLUnderlyingCryptoError;
#pragma pack(push,1)
class PASCALIMPLEMENTATION EIdOSSLUnderlyingCryptoError : public EIdOpenSSLAPICryptoError
{
	typedef EIdOpenSSLAPICryptoError inherited;
	
public:
	/* EIdException.Create */ inline __fastcall virtual EIdOSSLUnderlyingCryptoError(const System::UnicodeString AMsg)/* overload */ : EIdOpenSSLAPICryptoError(AMsg) { }
	
public:
	/* Exception.CreateFmt */ inline __fastcall EIdOSSLUnderlyingCryptoError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EIdOpenSSLAPICryptoError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EIdOSSLUnderlyingCryptoError(int Ident)/* overload */ : EIdOpenSSLAPICryptoError(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EIdOSSLUnderlyingCryptoError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EIdOpenSSLAPICryptoError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EIdOSSLUnderlyingCryptoError(const System::UnicodeString Msg, int AHelpContext) : EIdOpenSSLAPICryptoError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EIdOSSLUnderlyingCryptoError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EIdOpenSSLAPICryptoError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EIdOSSLUnderlyingCryptoError(int Ident, int AHelpContext)/* overload */ : EIdOpenSSLAPICryptoError(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdOSSLUnderlyingCryptoError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EIdOpenSSLAPICryptoError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EIdOSSLUnderlyingCryptoError(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const ShortInt OPENSSL_CONF_MFLAGS_IGNORE_ERRORS = 0x1;
static const ShortInt OPENSSL_CONF_MFLAGS_IGNORE_RETURN_CODES = 0x2;
static const ShortInt OPENSSL_CONF_MFLAGS_SILENT = 0x4;
static const ShortInt OPENSSL_CONF_MFLAGS_NO_DSO = 0x8;
static const ShortInt OPENSSL_CONF_MFLAGS_IGNORE_MISSING_FILE = 0x10;
static const ShortInt OPENSSL_CONF_MFLAGS_DEFAULT_SECTION = 0x20;
static const ShortInt OPENSSL_CONF_F_CONF_DUMP_FP = 0x68;
static const ShortInt OPENSSL_CONF_F_CONF_LOAD = 0x64;
static const ShortInt OPENSSL_CONF_F_CONF_LOAD_BIO = 0x66;
static const ShortInt OPENSSL_CONF_F_CONF_LOAD_FP = 0x67;
static const ShortInt OPENSSL_CONF_F_CONF_MODULES_LOAD = 0x74;
static const ShortInt OPENSSL_CONF_F_DEF_LOAD = 0x78;
static const ShortInt OPENSSL_CONF_F_DEF_LOAD_BIO = 0x79;
static const ShortInt OPENSSL_CONF_F_MODULE_INIT = 0x73;
static const ShortInt OPENSSL_CONF_F_MODULE_LOAD_DSO = 0x75;
static const ShortInt OPENSSL_CONF_F_MODULE_RUN = 0x76;
static const ShortInt OPENSSL_CONF_F_NCONF_DUMP_BIO = 0x69;
static const ShortInt OPENSSL_CONF_F_NCONF_DUMP_FP = 0x6a;
static const ShortInt OPENSSL_CONF_F_NCONF_GET_NUMBER = 0x6b;
static const ShortInt OPENSSL_CONF_F_NCONF_GET_NUMBER_E = 0x70;
static const ShortInt OPENSSL_CONF_F_NCONF_GET_SECTION = 0x6c;
static const ShortInt OPENSSL_CONF_F_NCONF_GET_STRING = 0x6d;
static const ShortInt OPENSSL_CONF_F_NCONF_LOAD = 0x71;
static const ShortInt OPENSSL_CONF_F_NCONF_LOAD_BIO = 0x6e;
static const ShortInt OPENSSL_CONF_F_NCONF_LOAD_FP = 0x72;
static const ShortInt OPENSSL_CONF_F_NCONF_NEW = 0x6f;
static const ShortInt OPENSSL_CONF_F_STR_COPY = 0x65;
static const ShortInt OPENSSL_CONF_R_ERROR_LOADING_DSO = 0x6e;
static const ShortInt OPENSSL_CONF_R_MISSING_CLOSE_SQUARE_BRACKET = 0x64;
static const ShortInt OPENSSL_CONF_R_MISSING_EQUAL_SIGN = 0x65;
static const ShortInt OPENSSL_CONF_R_MISSING_FINISH_FUNCTION = 0x6f;
static const ShortInt OPENSSL_CONF_R_MISSING_INIT_FUNCTION = 0x70;
static const ShortInt OPENSSL_CONF_R_MODULE_INITIALIZATION_ERROR = 0x6d;
static const ShortInt OPENSSL_CONF_R_NO_CLOSE_BRACE = 0x66;
static const ShortInt OPENSSL_CONF_R_NO_CONF = 0x69;
static const ShortInt OPENSSL_CONF_R_NO_CONF_OR_ENVIRONMENT_VARIABLE = 0x6a;
static const ShortInt OPENSSL_CONF_R_NO_SECTION = 0x6b;
static const ShortInt OPENSSL_CONF_R_NO_SUCH_FILE = 0x72;
static const ShortInt OPENSSL_CONF_R_NO_VALUE = 0x6c;
static const ShortInt OPENSSL_CONF_R_UNABLE_TO_CREATE_NEW_SECTION = 0x67;
static const ShortInt OPENSSL_CONF_R_UNKNOWN_MODULE_NAME = 0x71;
static const ShortInt OPENSSL_CONF_R_VARIABLE_HAS_NO_VALUE = 0x68;
static const ShortInt OPENSSL_ASN1_F_A2D_ASN1_OBJECT = 0x64;
static const Byte OPENSSL_ASN1_F_A2I_ASN1_ENUMERATED = 0xec;
static const ShortInt OPENSSL_ASN1_F_A2I_ASN1_INTEGER = 0x65;
static const ShortInt OPENSSL_ASN1_F_A2I_ASN1_STRING = 0x66;
static const ShortInt OPENSSL_ASN1_F_ASN1_COLLATE_PRIMITIVE = 0x67;
static const ShortInt OPENSSL_ASN1_F_ASN1_D2I_BIO = 0x68;
static const ShortInt OPENSSL_ASN1_F_ASN1_D2I_FP = 0x69;
static const ShortInt OPENSSL_ASN1_F_ASN1_DUP = 0x6a;
static const Byte OPENSSL_ASN1_F_ASN1_ENUMERATED_SET = 0xe8;
static const Byte OPENSSL_ASN1_F_ASN1_ENUMERATED_TO_BN = 0xe9;
static const Byte OPENSSL_ASN1_F_ASN1_GENERALIZEDTIME_NEW = 0xde;
static const ShortInt OPENSSL_ASN1_F_ASN1_GET_OBJECT = 0x6b;
static const ShortInt OPENSSL_ASN1_F_ASN1_HEADER_NEW = 0x6c;
static const ShortInt OPENSSL_ASN1_F_ASN1_I2D_BIO = 0x6d;
static const ShortInt OPENSSL_ASN1_F_ASN1_I2D_FP = 0x6e;
static const ShortInt OPENSSL_ASN1_F_ASN1_INTEGER_SET = 0x6f;
static const ShortInt OPENSSL_ASN1_F_ASN1_INTEGER_TO_BN = 0x70;
static const ShortInt OPENSSL_ASN1_F_ASN1_OBJECT_NEW = 0x71;
static const Byte OPENSSL_ASN1_F_ASN1_OUTPUT_DATA = 0xcf;
static const Byte OPENSSL_ASN1_F_ASN1_PACK_STRING = 0xf5;
static const Byte OPENSSL_ASN1_F_ASN1_PBE_SET = 0xfd;
static const Byte OPENSSL_ASN1_F_ASN1_SEQ_PACK = 0xf6;
static const Byte OPENSSL_ASN1_F_ASN1_SEQ_UNPACK = 0xf7;
static const ShortInt OPENSSL_ASN1_F_ASN1_SIGN = 0x72;
static const ShortInt OPENSSL_ASN1_F_ASN1_STRING_NEW = 0x73;
static const ShortInt OPENSSL_ASN1_F_ASN1_STRING_TYPE_NEW = 0x74;
static const ShortInt OPENSSL_ASN1_F_ASN1_TYPE_GET_INT_OCTETSTRING = 0x75;
static const ShortInt OPENSSL_ASN1_F_ASN1_TYPE_GET_OCTETSTRING = 0x76;
static const ShortInt OPENSSL_ASN1_F_ASN1_TYPE_NEW = 0x77;
static const Byte OPENSSL_ASN1_F_ASN1_UNPACK_STRING = 0xf8;
static const ShortInt OPENSSL_ASN1_F_ASN1_UTCTIME_NEW = 0x78;
static const ShortInt OPENSSL_ASN1_F_ASN1_VERIFY = 0x79;
static const Byte OPENSSL_ASN1_F_B64_READ_ASN1 = 0xd0;
static const Byte OPENSSL_ASN1_F_B64_WRITE_ASN1 = 0xd1;
static const Byte OPENSSL_ASN1_F_BITSTR_CB = 0xb4;
static const Byte OPENSSL_ASN1_F_SMIME_READ_ASN1 = 0xd2;
static const Byte OPENSSL_ASN1_F_SMIME_TEXT = 0xd3;
static const Byte OPENSSL_ASN1_F_AUTHORITY_KEYID_NEW = 0xed;
static const Byte OPENSSL_ASN1_F_BASIC_CONSTRAINTS_NEW = 0xe2;
static const Byte OPENSSL_ASN1_F_BN_TO_ASN1_ENUMERATED = 0xea;
static const ShortInt OPENSSL_ASN1_F_BN_TO_ASN1_INTEGER = 0x7a;
static const ShortInt OPENSSL_ASN1_F_D2I_ASN1_BIT_STRING = 0x7b;
static const ShortInt OPENSSL_ASN1_F_D2I_ASN1_BMPSTRING = 0x7c;
static const ShortInt OPENSSL_ASN1_F_D2I_ASN1_BOOLEAN = 0x7d;
static const ShortInt OPENSSL_ASN1_F_D2I_ASN1_BYTES = 0x7e;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_ENUMERATED = 0xeb;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_GENERALIZEDTIME = 0xdf;
static const ShortInt OPENSSL_ASN1_F_D2I_ASN1_HEADER = 0x7f;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_INTEGER = 0x80;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_OBJECT = 0x81;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_OCTET_STRING = 0x82;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_PRINT_TYPE = 0x83;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_SET = 0x84;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_TIME = 0xe0;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_TYPE = 0x85;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_TYPE_BYTES = 0x86;
static const Word OPENSSL_ASN1_F_D2I_ASN1_UINTEGER = 0x118;
static const Byte OPENSSL_ASN1_F_D2I_ASN1_UTCTIME = 0x87;
static const Word OPENSSL_ASN1_F_D2I_ASN1_UTF8STRING = 0x10a;
static const Word OPENSSL_ASN1_F_D2I_ASN1_VISIBLESTRING = 0x10b;
static const Byte OPENSSL_ASN1_F_D2I_AUTHORITY_KEYID = 0xee;
static const Byte OPENSSL_ASN1_F_D2I_BASIC_CONSTRAINTS = 0xe3;
static const Byte OPENSSL_ASN1_F_D2I_DHPARAMS = 0x88;
static const Word OPENSSL_ASN1_F_D2I_DIST_POINT = 0x114;
static const Word OPENSSL_ASN1_F_D2I_DIST_POINT_NAME = 0x115;
static const Byte OPENSSL_ASN1_F_D2I_DSAPARAMS = 0x89;
static const Byte OPENSSL_ASN1_F_D2I_DSAPRIVATEKEY = 0x8a;
static const Byte OPENSSL_ASN1_F_D2I_DSAPUBLICKEY = 0x8b;
static const Byte OPENSSL_ASN1_F_D2I_GENERAL_NAME = 0xe6;
static const Byte OPENSSL_ASN1_F_D2I_NETSCAPE_CERT_SEQUENCE = 0xe4;
static const Byte OPENSSL_ASN1_F_D2I_NETSCAPE_PKEY = 0x8c;
static const Byte OPENSSL_ASN1_F_D2I_NETSCAPE_RSA = 0x8d;
static const Byte OPENSSL_ASN1_F_D2I_NETSCAPE_RSA_2 = 0x8e;
static const Byte OPENSSL_ASN1_F_D2I_NETSCAPE_SPKAC = 0x8f;
static const Byte OPENSSL_ASN1_F_D2I_NETSCAPE_SPKI = 0x90;
static const Word OPENSSL_ASN1_F_D2I_NOTICEREF = 0x10c;
static const Word OPENSSL_ASN1_F_D2I_PBE2PARAM = 0x106;
static const Byte OPENSSL_ASN1_F_D2I_PBEPARAM = 0xf9;
static const Word OPENSSL_ASN1_F_D2I_PBKDF2PARAM = 0x107;
static const Byte OPENSSL_ASN1_F_D2I_PKCS12 = 0xfe;
static const Byte OPENSSL_ASN1_F_D2I_PKCS12_BAGS = 0xff;
static const Word OPENSSL_ASN1_F_D2I_PKCS12_MAC_DATA = 0x100;
static const Word OPENSSL_ASN1_F_D2I_PKCS12_SAFEBAG = 0x101;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7 = 0x91;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_DIGEST = 0x92;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_ENCRYPT = 0x93;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_ENC_CONTENT = 0x94;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_ENVELOPE = 0x95;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_ISSUER_AND_SERIAL = 0x96;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_RECIP_INFO = 0x97;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_SIGNED = 0x98;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_SIGNER_INFO = 0x99;
static const Byte OPENSSL_ASN1_F_D2I_PKCS7_SIGN_ENVELOPE = 0x9a;
static const Byte OPENSSL_ASN1_F_D2I_PKCS8_PRIV_KEY_INFO = 0xfa;
static const Byte OPENSSL_ASN1_F_D2I_PKEY_USAGE_PERIOD = 0xef;
static const Word OPENSSL_ASN1_F_D2I_POLICYINFO = 0x10d;
static const Word OPENSSL_ASN1_F_D2I_POLICYQUALINFO = 0x10e;
static const Byte OPENSSL_ASN1_F_D2I_PRIVATEKEY = 0x9b;
static const Byte OPENSSL_ASN1_F_D2I_PUBLICKEY = 0x9c;
static const Byte OPENSSL_ASN1_F_D2I_RSAPRIVATEKEY = 0x9d;
static const Byte OPENSSL_ASN1_F_D2I_RSAPUBLICKEY = 0x9e;
static const Byte OPENSSL_ASN1_F_D2I_SXNET = 0xf1;
static const Byte OPENSSL_ASN1_F_D2I_SXNETID = 0xf3;
static const Word OPENSSL_ASN1_F_D2I_USERNOTICE = 0x10f;
static const Byte OPENSSL_ASN1_F_D2I_X509 = 0x9f;
static const Byte OPENSSL_ASN1_F_D2I_X509_ALGOR = 0xa0;
static const Byte OPENSSL_ASN1_F_D2I_X509_ATTRIBUTE = 0xa1;
static const Byte OPENSSL_ASN1_F_D2I_X509_CINF = 0xa2;
static const Byte OPENSSL_ASN1_F_D2I_X509_CRL = 0xa3;
static const Byte OPENSSL_ASN1_F_D2I_X509_CRL_INFO = 0xa4;
static const Byte OPENSSL_ASN1_F_D2I_X509_EXTENSION = 0xa5;
static const Byte OPENSSL_ASN1_F_D2I_X509_KEY = 0xa6;
static const Byte OPENSSL_ASN1_F_D2I_X509_NAME = 0xa7;
static const Byte OPENSSL_ASN1_F_D2I_X509_NAME_ENTRY = 0xa8;
static const Byte OPENSSL_ASN1_F_D2I_X509_PKEY = 0xa9;
static const Byte OPENSSL_ASN1_F_D2I_X509_PUBKEY = 0xaa;
static const Byte OPENSSL_ASN1_F_D2I_X509_REQ = 0xab;
static const Byte OPENSSL_ASN1_F_D2I_X509_REQ_INFO = 0xac;
static const Byte OPENSSL_ASN1_F_D2I_X509_REVOKED = 0xad;
static const Byte OPENSSL_ASN1_F_D2I_X509_SIG = 0xae;
static const Byte OPENSSL_ASN1_F_D2I_X509_VAL = 0xaf;
static const Word OPENSSL_ASN1_F_DIST_POINT_NAME_NEW = 0x116;
static const Word OPENSSL_ASN1_F_DIST_POINT_NEW = 0x117;
static const Byte OPENSSL_ASN1_F_GENERAL_NAME_NEW = 0xe7;
static const Byte OPENSSL_ASN1_F_I2D_ASN1_HEADER = 0xb0;
static const Byte OPENSSL_ASN1_F_I2D_ASN1_TIME = 0xe1;
static const Byte OPENSSL_ASN1_F_I2D_DHPARAMS = 0xb1;
static const Byte OPENSSL_ASN1_F_I2D_DSAPARAMS = 0xb2;
static const Byte OPENSSL_ASN1_F_I2D_DSAPRIVATEKEY = 0xb3;
static const Byte OPENSSL_ASN1_F_I2D_DSAPUBLICKEY = 0xb4;
static const Byte OPENSSL_ASN1_F_I2D_NETSCAPE_RSA = 0xb5;
static const Byte OPENSSL_ASN1_F_I2D_PKCS7 = 0xb6;
static const Byte OPENSSL_ASN1_F_I2D_PRIVATEKEY = 0xb7;
static const Byte OPENSSL_ASN1_F_I2D_PUBLICKEY = 0xb8;
static const Byte OPENSSL_ASN1_F_I2D_RSAPRIVATEKEY = 0xb9;
static const Byte OPENSSL_ASN1_F_I2D_RSAPUBLICKEY = 0xba;
static const Byte OPENSSL_ASN1_F_I2D_X509_ATTRIBUTE = 0xbb;
static const Byte OPENSSL_ASN1_F_I2T_ASN1_OBJECT = 0xbc;
static const Byte OPENSSL_ASN1_F_NETSCAPE_CERT_SEQUENCE_NEW = 0xe5;
static const Byte OPENSSL_ASN1_F_NETSCAPE_PKEY_NEW = 0xbd;
static const Byte OPENSSL_ASN1_F_NETSCAPE_SPKAC_NEW = 0xbe;
static const Byte OPENSSL_ASN1_F_NETSCAPE_SPKI_NEW = 0xbf;
static const Word OPENSSL_ASN1_F_NOTICEREF_NEW = 0x110;
static const Word OPENSSL_ASN1_F_PBE2PARAM_NEW = 0x108;
static const Byte OPENSSL_ASN1_F_PBEPARAM_NEW = 0xfb;
static const Word OPENSSL_ASN1_F_PBKDF2PARAM_NEW = 0x109;
static const Word OPENSSL_ASN1_F_PKCS12_BAGS_NEW = 0x102;
static const Word OPENSSL_ASN1_F_PKCS12_MAC_DATA_NEW = 0x103;
static const Word OPENSSL_ASN1_F_PKCS12_NEW = 0x104;
static const Word OPENSSL_ASN1_F_PKCS12_SAFEBAG_NEW = 0x105;
static const Word OPENSSL_ASN1_F_PKCS5_PBE2_SET = 0x119;
static const Byte OPENSSL_ASN1_F_PKCS7_DIGEST_NEW = 0xc0;
static const Byte OPENSSL_ASN1_F_PKCS7_ENCRYPT_NEW = 0xc1;
static const Byte OPENSSL_ASN1_F_PKCS7_ENC_CONTENT_NEW = 0xc2;
static const Byte OPENSSL_ASN1_F_PKCS7_ENVELOPE_NEW = 0xc3;
static const Byte OPENSSL_ASN1_F_PKCS7_ISSUER_AND_SERIAL_NEW = 0xc4;
static const Byte OPENSSL_ASN1_F_PKCS7_NEW = 0xc5;
static const Byte OPENSSL_ASN1_F_PKCS7_RECIP_INFO_NEW = 0xc6;
static const Byte OPENSSL_ASN1_F_PKCS7_SIGNED_NEW = 0xc7;
static const Byte OPENSSL_ASN1_F_PKCS7_SIGNER_INFO_NEW = 0xc8;
static const Byte OPENSSL_ASN1_F_PKCS7_SIGN_ENVELOPE_NEW = 0xc9;
static const Byte OPENSSL_ASN1_F_PKCS8_PRIV_KEY_INFO_NEW = 0xfc;
static const Byte OPENSSL_ASN1_F_PKEY_USAGE_PERIOD_NEW = 0xf0;
static const Word OPENSSL_ASN1_F_POLICYINFO_NEW = 0x111;
static const Word OPENSSL_ASN1_F_POLICYQUALINFO_NEW = 0x112;
static const Byte OPENSSL_ASN1_F_SXNETID_NEW = 0xf4;
static const Byte OPENSSL_ASN1_F_SXNET_NEW = 0xf2;
static const Word OPENSSL_ASN1_F_USERNOTICE_NEW = 0x113;
static const Byte OPENSSL_ASN1_F_X509_ALGOR_NEW = 0xca;
static const Byte OPENSSL_ASN1_F_X509_ATTRIBUTE_NEW = 0xcb;
static const Byte OPENSSL_ASN1_F_X509_CINF_NEW = 0xcc;
static const Byte OPENSSL_ASN1_F_X509_CRL_INFO_NEW = 0xcd;
static const Byte OPENSSL_ASN1_F_X509_CRL_NEW = 0xce;
static const Byte OPENSSL_ASN1_F_X509_DHPARAMS_NEW = 0xcf;
static const Byte OPENSSL_ASN1_F_X509_EXTENSION_NEW = 0xd0;
static const Byte OPENSSL_ASN1_F_X509_INFO_NEW = 0xd1;
static const Byte OPENSSL_ASN1_F_X509_KEY_NEW = 0xd2;
static const Byte OPENSSL_ASN1_F_X509_NAME_ENTRY_NEW = 0xd3;
static const Byte OPENSSL_ASN1_F_X509_NAME_NEW = 0xd4;
static const Byte OPENSSL_ASN1_F_X509_NEW = 0xd5;
static const Byte OPENSSL_ASN1_F_X509_PKEY_NEW = 0xd6;
static const Byte OPENSSL_ASN1_F_X509_PUBKEY_NEW = 0xd7;
static const Byte OPENSSL_ASN1_F_X509_REQ_INFO_NEW = 0xd8;
static const Byte OPENSSL_ASN1_F_X509_REQ_NEW = 0xd9;
static const Byte OPENSSL_ASN1_F_X509_REVOKED_NEW = 0xda;
static const Byte OPENSSL_ASN1_F_X509_SIG_NEW = 0xdb;
static const Byte OPENSSL_ASN1_F_X509_VAL_FREE = 0xdc;
static const Byte OPENSSL_ASN1_F_X509_VAL_NEW = 0xdd;
static const ShortInt OPENSSL_ASN1_OBJECT_FLAG_CRITICAL = 0x2;
static const ShortInt OPENSSL_ASN1_OBJECT_FLAG_DYNAMIC = 0x1;
static const ShortInt OPENSSL_ASN1_OBJECT_FLAG_DYNAMIC_DATA = 0x8;
static const ShortInt OPENSSL_ASN1_OBJECT_FLAG_DYNAMIC_STRINGS = 0x4;
static const Byte OPENSSL_ASN1_R_ADDING_OBJECT = 0xab;
static const Byte OPENSSL_ASN1_R_ASN1_PARSE_ERROR = 0xc6;
static const Byte OPENSSL_ASN1_R_ASN1_SIG_PARSE_ERROR = 0xc7;
static const ShortInt OPENSSL_ASN1_R_AUX_ERROR = 0x64;
static const ShortInt OPENSSL_ASN1_R_BAD_CLASS = 0x65;
static const ShortInt OPENSSL_ASN1_R_BAD_OBJECT_HEADER = 0x66;
static const ShortInt OPENSSL_ASN1_R_BAD_PASSWORD_READ = 0x67;
static const ShortInt OPENSSL_ASN1_R_BAD_TAG = 0x68;
static const ShortInt OPENSSL_ASN1_R_BN_LIB = 0x69;
static const ShortInt OPENSSL_ASN1_R_BOOLEAN_IS_WRONG_LENGTH = 0x6a;
static const ShortInt OPENSSL_ASN1_R_BUFFER_TOO_SMALL = 0x6b;
static const ShortInt OPENSSL_ASN1_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER = 0x6c;
static const ShortInt OPENSSL_ASN1_R_DATA_IS_WRONG = 0x6d;
static const ShortInt OPENSSL_ASN1_R_DECODE_ERROR = 0x6e;
static const ShortInt OPENSSL_ASN1_R_DECODING_ERROR = 0x6f;
static const Byte OPENSSL_ASN1_R_DEPTH_EXCEEDED = 0xae;
static const ShortInt OPENSSL_ASN1_R_ENCODE_ERROR = 0x70;
static const Byte OPENSSL_ASN1_R_ERROR_GETTING_TIME = 0xad;
static const Byte OPENSSL_ASN1_R_ERROR_LOADING_SECTION = 0xac;
static const ShortInt OPENSSL_ASN1_R_ERROR_PARSING_SET_ELEMENT = 0x71;
static const ShortInt OPENSSL_ASN1_R_ERROR_SETTING_CIPHER_PARAMS = 0x72;
static const ShortInt OPENSSL_ASN1_R_EXPECTING_AN_INTEGER = 0x73;
static const ShortInt OPENSSL_ASN1_R_EXPECTING_AN_OBJECT = 0x74;
static const ShortInt OPENSSL_ASN1_R_EXPECTING_A_BOOLEAN = 0x75;
static const ShortInt OPENSSL_ASN1_R_EXPECTING_A_TIME = 0x76;
static const ShortInt OPENSSL_ASN1_R_EXPLICIT_LENGTH_MISMATCH = 0x77;
static const ShortInt OPENSSL_ASN1_R_EXPLICIT_TAG_NOT_CONSTRUCTED = 0x78;
static const ShortInt OPENSSL_ASN1_R_FIELD_MISSING = 0x79;
static const ShortInt OPENSSL_ASN1_R_FIRST_NUM_TOO_LARGE = 0x7a;
static const ShortInt OPENSSL_ASN1_R_HEADER_TOO_LONG = 0x7b;
static const Byte OPENSSL_ASN1_R_ILLEGAL_BITSTRING_FORMAT = 0xaf;
static const Byte OPENSSL_ASN1_R_ILLEGAL_BOOLEAN = 0xb0;
static const ShortInt OPENSSL_ASN1_R_ILLEGAL_CHARACTERS = 0x7c;
static const Byte OPENSSL_ASN1_R_ILLEGAL_FORMAT = 0xb1;
static const Byte OPENSSL_ASN1_R_ILLEGAL_HEX = 0xb2;
static const Byte OPENSSL_ASN1_R_ILLEGAL_IMPLICIT_TAG = 0xb3;
static const Byte OPENSSL_ASN1_R_ILLEGAL_INTEGER = 0xb4;
static const Byte OPENSSL_ASN1_R_ILLEGAL_NESTED_TAGGING = 0xb5;
static const ShortInt OPENSSL_ASN1_R_ILLEGAL_NULL = 0x7d;
static const Byte OPENSSL_ASN1_R_ILLEGAL_NULL_VALUE = 0xb6;
static const Byte OPENSSL_ASN1_R_ILLEGAL_OBJECT = 0xb7;
static const ShortInt OPENSSL_ASN1_R_ILLEGAL_OPTIONAL_ANY = 0x7e;
static const Byte OPENSSL_ASN1_R_ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE = 0xaa;
static const ShortInt OPENSSL_ASN1_R_ILLEGAL_TAGGED_ANY = 0x7f;
static const Byte OPENSSL_ASN1_R_ILLEGAL_TIME_VALUE = 0xb8;
static const Byte OPENSSL_ASN1_R_INTEGER_NOT_ASCII_FORMAT = 0xb9;
static const Byte OPENSSL_ASN1_R_INTEGER_TOO_LARGE_FOR_LONG = 0x80;
static const Byte OPENSSL_ASN1_R_INVALID_BMPSTRING_LENGTH = 0x81;
static const Byte OPENSSL_ASN1_R_INVALID_DIGIT = 0x82;
static const Byte OPENSSL_ASN1_R_INVALID_MIME_TYPE = 0xc8;
static const Byte OPENSSL_ASN1_R_INVALID_MODIFIER = 0xba;
static const Byte OPENSSL_ASN1_R_INVALID_NUMBER = 0xbb;
static const Byte OPENSSL_ASN1_R_INVALID_SEPARATOR = 0x83;
static const Byte OPENSSL_ASN1_R_INVALID_TIME_FORMAT = 0x84;
static const Byte OPENSSL_ASN1_R_INVALID_UNIVERSALSTRING_LENGTH = 0x85;
static const Byte OPENSSL_ASN1_R_INVALID_UTF8STRING = 0x86;
static const Byte OPENSSL_ASN1_R_IV_TOO_LARGE = 0x87;
static const Byte OPENSSL_ASN1_R_LENGTH_ERROR = 0x88;
static const Byte OPENSSL_ASN1_R_LIST_ERROR = 0xbc;
static const Byte OPENSSL_ASN1_R_MIME_NO_CONTENT_TYPE = 0xc9;
static const Byte OPENSSL_ASN1_R_MIME_PARSE_ERROR = 0xca;
static const Byte OPENSSL_ASN1_R_MIME_SIG_PARSE_ERROR = 0xcb;
static const Byte OPENSSL_ASN1_R_MISSING_EOC = 0x89;
static const Byte OPENSSL_ASN1_R_MISSING_SECOND_NUMBER = 0x8a;
static const Byte OPENSSL_ASN1_R_MISSING_VALUE = 0xbd;
static const Byte OPENSSL_ASN1_R_MSTRING_NOT_UNIVERSAL = 0x8b;
static const Byte OPENSSL_ASN1_R_MSTRING_WRONG_TAG = 0x8c;
static const Byte OPENSSL_ASN1_R_NESTED_ASN1_STRING = 0xc5;
static const Byte OPENSSL_ASN1_R_NON_HEX_CHARACTERS = 0x8d;
static const Byte OPENSSL_ASN1_R_NOT_ASCII_FORMAT = 0xbe;
static const Byte OPENSSL_ASN1_R_NOT_ENOUGH_DATA = 0x8e;
static const Byte OPENSSL_ASN1_R_NO_CONTENT_TYPE = 0xcc;
static const Byte OPENSSL_ASN1_R_NO_MATCHING_CHOICE_TYPE = 0x8f;
static const Byte OPENSSL_ASN1_R_NO_MULTIPART_BODY_FAILURE = 0xcd;
static const Byte OPENSSL_ASN1_R_NO_MULTIPART_BOUNDARY = 0xce;
static const Byte OPENSSL_ASN1_R_NO_SIG_CONTENT_TYPE = 0xcf;
static const Byte OPENSSL_ASN1_R_NULL_IS_WRONG_LENGTH = 0x90;
static const Byte OPENSSL_ASN1_R_OBJECT_NOT_ASCII_FORMAT = 0xbf;
static const Byte OPENSSL_ASN1_R_ODD_NUMBER_OF_CHARS = 0x91;
static const Byte OPENSSL_ASN1_R_PRIVATE_KEY_HEADER_MISSING = 0x92;
static const Byte OPENSSL_ASN1_R_SECOND_NUMBER_TOO_LARGE = 0x93;
static const Byte OPENSSL_ASN1_R_SEQUENCE_LENGTH_MISMATCH = 0x94;
static const Byte OPENSSL_ASN1_R_SEQUENCE_NOT_CONSTRUCTED = 0x95;
static const Byte OPENSSL_ASN1_R_SEQUENCE_OR_SET_NEEDS_CONFIG = 0xc0;
static const Byte OPENSSL_ASN1_R_SHORT_LINE = 0x96;
static const Byte OPENSSL_ASN1_R_SIG_INVALID_MIME_TYPE = 0xd0;
static const Byte OPENSSL_ASN1_R_STREAMING_NOT_SUPPORTED = 0xd1;
static const Byte OPENSSL_ASN1_R_STRING_TOO_LONG = 0x97;
static const Byte OPENSSL_ASN1_R_STRING_TOO_SHORT = 0x98;
static const Byte OPENSSL_ASN1_R_TAG_VALUE_TOO_HIGH = 0x99;
static const Byte OPENSSL_ASN1_R_THE_ASN1_OBJECT_IDENTIFIER_IS_NOT_KNOWN_FOR_THIS_MD = 0x9a;
static const Byte OPENSSL_ASN1_R_TIME_NOT_ASCII_FORMAT = 0xc1;
static const Byte OPENSSL_ASN1_R_TOO_LONG = 0x9b;
static const Byte OPENSSL_ASN1_R_TYPE_NOT_CONSTRUCTED = 0x9c;
static const Byte OPENSSL_ASN1_R_UNABLE_TO_DECODE_RSA_KEY = 0x9d;
static const Byte OPENSSL_ASN1_R_UNABLE_TO_DECODE_RSA_PRIVATE_KEY = 0x9e;
static const Byte OPENSSL_ASN1_R_UNEXPECTED_EOC = 0x9f;
static const Byte OPENSSL_ASN1_R_UNKNOWN_FORMAT = 0xa0;
static const Byte OPENSSL_ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM = 0xa1;
static const Byte OPENSSL_ASN1_R_UNKNOWN_OBJECT_TYPE = 0xa2;
static const Byte OPENSSL_ASN1_R_UNKNOWN_PUBLIC_KEY_TYPE = 0xa3;
static const Byte OPENSSL_ASN1_R_UNKNOWN_TAG = 0xc2;
static const Byte OPENSSL_ASN1_R_UNKOWN_FORMAT = 0xc3;
static const Byte OPENSSL_ASN1_R_UNSUPPORTED_ANY_DEFINED_BY_TYPE = 0xa4;
static const Byte OPENSSL_ASN1_R_UNSUPPORTED_CIPHER = 0xa5;
static const Byte OPENSSL_ASN1_R_UNSUPPORTED_ENCRYPTION_ALGORITHM = 0xa6;
static const Byte OPENSSL_ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE = 0xa7;
static const Byte OPENSSL_ASN1_R_UNSUPPORTED_TYPE = 0xc4;
static const Byte OPENSSL_ASN1_R_WRONG_TAG = 0xa8;
static const Byte OPENSSL_ASN1_R_WRONG_TYPE = 0xa9;
static const ShortInt OPENSSL_ASN1_STRING_FLAG_BITS_LEFT = 0x8;
static const ShortInt OPENSSL_ASN1_STRING_FLAG_NDEF = 0x10;
static const ShortInt OPENSSL_ASN1_STRING_FLAG_CONT = 0x20;
static const int OPENSSL_ASN1_LONG_UNDEF = 0x7fffffff;
static const Word OPENSSL_UB_NAME = 0x8000;
static const ShortInt OPENSSL_UB_COMMON_NAME = 0x40;
static const Byte OPENSSL_UB_LOCALITY_NAME = 0x80;
static const Byte OPENSSL_UB_STATE_NAME = 0x80;
static const ShortInt OPENSSL_UB_ORGANIZATION_NAME = 0x40;
static const ShortInt OPENSSL_UB_ORGANIZATION_UNIT_NAME = 0x40;
static const ShortInt OPENSSL_UB_TITLE = 0x40;
static const Byte OPENSSL_UB_EMAIL_ADDRESS = 0x80;
static const ShortInt OPENSSL_ASN1_STRFLGS_ESC_2253 = 0x1;
static const ShortInt OPENSSL_ASN1_STRFLGS_ESC_CTRL = 0x2;
static const ShortInt OPENSSL_ASN1_STRFLGS_ESC_MSB = 0x4;
static const ShortInt OPENSSL_ASN1_STRFLGS_ESC_QUOTE = 0x8;
static const ShortInt OPENSSL_ASN1_STRFLGS_UTF8_CONVERT = 0x10;
static const ShortInt OPENSSL_ASN1_STRFLGS_IGNORE_TYPE = 0x20;
static const ShortInt OPENSSL_ASN1_STRFLGS_SHOW_TYPE = 0x40;
static const Byte OPENSSL_ASN1_STRFLGS_DUMP_ALL = 0x80;
static const Word OPENSSL_ASN1_STRFLGS_DUMP_UNKNOWN = 0x100;
static const Word OPENSSL_ASN1_STRFLGS_DUMP_DER = 0x200;
static const Word OPENSSL_ASN1_STRFLGS_RFC2253 = 0x317;
static const ShortInt OPENSSL_BIO_BIND_NORMAL = 0x0;
static const ShortInt OPENSSL_BIO_BIND_REUSEADDR = 0x2;
static const ShortInt OPENSSL_BIO_BIND_REUSEADDR_IF_UNUSED = 0x1;
static const ShortInt OPENSSL_BIO_CB_CTRL = 0x6;
static const ShortInt OPENSSL_BIO_CB_FREE = 0x1;
static const ShortInt OPENSSL_BIO_CB_GETS = 0x5;
static const ShortInt OPENSSL_BIO_CB_PUTS = 0x4;
static const ShortInt OPENSSL_BIO_CB_READ = 0x2;
static const Byte OPENSSL_BIO_CB_RETURN = 0x80;
static const ShortInt OPENSSL_BIO_CB_WRITE = 0x3;
static const ShortInt OPENSSL_BIO_CLOSE = 0x1;
static const ShortInt OPENSSL_BIO_CONN_S_BEFORE = 0x1;
static const ShortInt OPENSSL_BIO_CONN_S_BLOCKED_CONNECT = 0x7;
static const ShortInt OPENSSL_BIO_CONN_S_CONNECT = 0x5;
static const ShortInt OPENSSL_BIO_CONN_S_CREATE_SOCKET = 0x4;
static const ShortInt OPENSSL_BIO_CONN_S_GET_IP = 0x2;
static const ShortInt OPENSSL_BIO_CONN_S_GET_PORT = 0x3;
static const ShortInt OPENSSL_BIO_CONN_S_NBIO = 0x8;
static const ShortInt OPENSSL_BIO_CONN_S_OK = 0x6;
static const ShortInt OPENSSL_BIO_CTRL_DUP = 0xc;
static const ShortInt OPENSSL_BIO_CTRL_EOF = 0x2;
static const ShortInt OPENSSL_BIO_CTRL_FLUSH = 0xb;
static const ShortInt OPENSSL_BIO_CTRL_GET = 0x5;
static const ShortInt OPENSSL_BIO_CTRL_GET_CALLBACK = 0xf;
static const ShortInt OPENSSL_BIO_CTRL_GET_CLOSE = 0x8;
static const ShortInt OPENSSL_BIO_CTRL_INFO = 0x3;
static const ShortInt OPENSSL_BIO_CTRL_PENDING = 0xa;
static const ShortInt OPENSSL_BIO_CTRL_POP = 0x7;
static const ShortInt OPENSSL_BIO_CTRL_PUSH = 0x6;
static const ShortInt OPENSSL_BIO_CTRL_RESET = 0x1;
static const ShortInt OPENSSL_BIO_CTRL_SET = 0x4;
static const ShortInt OPENSSL_BIO_CTRL_SET_CALLBACK = 0xe;
static const ShortInt OPENSSL_BIO_CTRL_SET_CLOSE = 0x9;
static const ShortInt OPENSSL_BIO_CTRL_SET_FILENAME = 0x1e;
static const ShortInt OPENSSL_BIO_CTRL_WPENDING = 0xd;
static const Byte OPENSSL_BIO_C_DESTROY_BIO_PAIR = 0x8b;
static const ShortInt OPENSSL_BIO_C_DO_STATE_MACHINE = 0x65;
static const Byte OPENSSL_BIO_C_FILE_SEEK = 0x80;
static const Byte OPENSSL_BIO_C_FILE_TELL = 0x85;
static const ShortInt OPENSSL_BIO_C_GET_ACCEPT = 0x7c;
static const Byte OPENSSL_BIO_C_GET_BIND_MODE = 0x84;
static const ShortInt OPENSSL_BIO_C_GET_BUFF_NUM_LINES = 0x74;
static const ShortInt OPENSSL_BIO_C_GET_BUF_MEM_PTR = 0x73;
static const Byte OPENSSL_BIO_C_GET_CIPHER_CTX = 0x81;
static const ShortInt OPENSSL_BIO_C_GET_CIPHER_STATUS = 0x71;
static const ShortInt OPENSSL_BIO_C_GET_CONNECT = 0x7b;
static const ShortInt OPENSSL_BIO_C_GET_FD = 0x69;
static const ShortInt OPENSSL_BIO_C_GET_FILE_PTR = 0x6b;
static const ShortInt OPENSSL_BIO_C_GET_MD = 0x70;
static const ShortInt OPENSSL_BIO_C_GET_MD_CTX = 0x78;
static const ShortInt OPENSSL_BIO_C_GET_PROXY_PARAM = 0x79;
static const Byte OPENSSL_BIO_C_GET_READ_REQUEST = 0x8d;
static const Byte OPENSSL_BIO_C_GET_SOCKS = 0x86;
static const ShortInt OPENSSL_BIO_C_GET_SSL = 0x6e;
static const ShortInt OPENSSL_BIO_C_GET_SSL_NUM_RENEGOTIATES = 0x7e;
static const Byte OPENSSL_BIO_C_GET_WRITE_BUF_SIZE = 0x89;
static const Byte OPENSSL_BIO_C_GET_WRITE_GUARANTEE = 0x8c;
static const Byte OPENSSL_BIO_C_MAKE_BIO_PAIR = 0x8a;
static const ShortInt OPENSSL_BIO_C_SET_ACCEPT = 0x76;
static const Byte OPENSSL_BIO_C_SET_BIND_MODE = 0x83;
static const ShortInt OPENSSL_BIO_C_SET_BUFF_READ_DATA = 0x7a;
static const ShortInt OPENSSL_BIO_C_SET_BUFF_SIZE = 0x75;
static const ShortInt OPENSSL_BIO_C_SET_BUF_MEM = 0x72;
static const Byte OPENSSL_BIO_C_SET_BUF_MEM_EOF_RETURN = 0x82;
static const ShortInt OPENSSL_BIO_C_SET_CONNECT = 0x64;
static const ShortInt OPENSSL_BIO_C_SET_FD = 0x68;
static const ShortInt OPENSSL_BIO_C_SET_FILENAME = 0x6c;
static const ShortInt OPENSSL_BIO_C_SET_FILE_PTR = 0x6a;
static const ShortInt OPENSSL_BIO_C_SET_MD = 0x6f;
static const ShortInt OPENSSL_BIO_C_SET_NBIO = 0x66;
static const ShortInt OPENSSL_BIO_C_SET_PROXY_PARAM = 0x67;
static const Byte OPENSSL_BIO_C_SET_SOCKS = 0x87;
static const ShortInt OPENSSL_BIO_C_SET_SSL = 0x6d;
static const ShortInt OPENSSL_BIO_C_SET_SSL_RENEGOTIATE_BYTES = 0x7d;
static const ShortInt OPENSSL_BIO_C_SET_SSL_RENEGOTIATE_TIMEOUT = 0x7f;
static const Byte OPENSSL_BIO_C_SET_WRITE_BUF_SIZE = 0x88;
static const Byte OPENSSL_BIO_C_SHUTDOWN_WR = 0x8e;
static const ShortInt OPENSSL_BIO_C_SSL_MODE = 0x77;
static const Word OPENSSL_BIO_FLAGS_BASE64_NO_NL = 0x100;
static const ShortInt OPENSSL_BIO_FLAGS_IO_SPECIAL = 0x4;
static const ShortInt OPENSSL_BIO_FLAGS_READ = 0x1;
static const ShortInt OPENSSL_BIO_FLAGS_WRITE = 0x2;
static const ShortInt OPENSSL_BIO_FLAGS_RWS = 0x7;
static const ShortInt OPENSSL_BIO_FLAGS_SHOULD_RETRY = 0x8;
static const ShortInt OPENSSL_BIO_FP_APPEND = 0x8;
static const ShortInt OPENSSL_BIO_FP_READ = 0x2;
static const ShortInt OPENSSL_BIO_FP_TEXT = 0x10;
static const ShortInt OPENSSL_BIO_FP_WRITE = 0x4;
static const ShortInt OPENSSL_BIO_F_ACPT_STATE = 0x64;
static const ShortInt OPENSSL_BIO_F_BIO_ACCEPT = 0x65;
static const ShortInt OPENSSL_BIO_F_BIO_BER_GET_HEADER = 0x66;
static const ShortInt OPENSSL_BIO_F_BIO_CTRL = 0x67;
static const ShortInt OPENSSL_BIO_F_BIO_GETHOSTBYNAME = 0x78;
static const ShortInt OPENSSL_BIO_F_BIO_GETS = 0x68;
static const ShortInt OPENSSL_BIO_F_BIO_GET_ACCEPT_SOCKET = 0x69;
static const ShortInt OPENSSL_BIO_F_BIO_GET_HOST_IP = 0x6a;
static const ShortInt OPENSSL_BIO_F_BIO_GET_PORT = 0x6b;
static const ShortInt OPENSSL_BIO_F_BIO_MAKE_PAIR = 0x79;
static const ShortInt OPENSSL_BIO_F_BIO_NEW = 0x6c;
static const ShortInt OPENSSL_BIO_F_BIO_NEW_FILE = 0x6d;
static const ShortInt OPENSSL_BIO_F_BIO_PUTS = 0x6e;
static const ShortInt OPENSSL_BIO_F_BIO_READ = 0x6f;
static const ShortInt OPENSSL_BIO_F_BIO_SOCK_INIT = 0x70;
static const ShortInt OPENSSL_BIO_F_BIO_WRITE = 0x71;
static const ShortInt OPENSSL_BIO_F_BUFFER_CTRL = 0x72;
static const ShortInt OPENSSL_BIO_F_CONN_STATE = 0x73;
static const ShortInt OPENSSL_BIO_F_FILE_CTRL = 0x74;
static const ShortInt OPENSSL_BIO_F_MEM_WRITE = 0x75;
static const ShortInt OPENSSL_BIO_F_SSL_NEW = 0x76;
static const ShortInt OPENSSL_BIO_F_WSASTARTUP = 0x77;
static const ShortInt OPENSSL_BIO_GHBN_CTRL_CACHE_SIZE = 0x3;
static const ShortInt OPENSSL_BIO_GHBN_CTRL_FLUSH = 0x5;
static const ShortInt OPENSSL_BIO_GHBN_CTRL_GET_ENTRY = 0x4;
static const ShortInt OPENSSL_BIO_GHBN_CTRL_HITS = 0x1;
static const ShortInt OPENSSL_BIO_GHBN_CTRL_MISSES = 0x2;
static const ShortInt OPENSSL_BIO_NOCLOSE = 0x0;
static const ShortInt OPENSSL_BIO_RR_CONNECT = 0x2;
static const ShortInt OPENSSL_BIO_RR_SSL_X509_LOOKUP = 0x1;
static const ShortInt OPENSSL_BIO_R_ACCEPT_ERROR = 0x64;
static const ShortInt OPENSSL_BIO_R_BAD_FOPEN_MODE = 0x65;
static const ShortInt OPENSSL_BIO_R_BAD_HOSTNAME_LOOKUP = 0x66;
static const ShortInt OPENSSL_BIO_R_BROKEN_PIPE = 0x7c;
static const ShortInt OPENSSL_BIO_R_CONNECT_ERROR = 0x67;
static const ShortInt OPENSSL_BIO_R_ERROR_SETTING_NBIO = 0x68;
static const ShortInt OPENSSL_BIO_R_ERROR_SETTING_NBIO_ON_ACCEPTED_SOCKET = 0x69;
static const ShortInt OPENSSL_BIO_R_ERROR_SETTING_NBIO_ON_ACCEPT_SOCKET = 0x6a;
static const ShortInt OPENSSL_BIO_R_GETHOSTBYNAME_ADDR_IS_NOT_AF_INET = 0x6b;
static const ShortInt OPENSSL_BIO_R_INVALID_ARGUMENT = 0x7d;
static const ShortInt OPENSSL_BIO_R_INVALID_IP_ADDRESS = 0x6c;
static const ShortInt OPENSSL_BIO_R_IN_USE = 0x7b;
static const ShortInt OPENSSL_BIO_R_KEEPALIVE = 0x6d;
static const ShortInt OPENSSL_BIO_R_NBIO_CONNECT_ERROR = 0x6e;
static const ShortInt OPENSSL_BIO_R_NO_ACCEPT_PORT_SPECIFIED = 0x6f;
static const ShortInt OPENSSL_BIO_R_NO_HOSTNAME_SPECIFIED = 0x70;
static const ShortInt OPENSSL_BIO_R_NO_PORT_DEFINED = 0x71;
static const ShortInt OPENSSL_BIO_R_NO_PORT_SPECIFIED = 0x72;
static const ShortInt OPENSSL_BIO_R_NULL_PARAMETER = 0x73;
static const ShortInt OPENSSL_BIO_R_TAG_MISMATCH = 0x74;
static const ShortInt OPENSSL_BIO_R_UNABLE_TO_BIND_SOCKET = 0x75;
static const ShortInt OPENSSL_BIO_R_UNABLE_TO_CREATE_SOCKET = 0x76;
static const ShortInt OPENSSL_BIO_R_UNABLE_TO_LISTEN_SOCKET = 0x77;
static const ShortInt OPENSSL_BIO_R_UNINITIALIZED = 0x78;
static const ShortInt OPENSSL_BIO_R_UNSUPPORTED_METHOD = 0x79;
static const ShortInt OPENSSL_BIO_R_WSASTARTUP = 0x7a;
static const Word OPENSSL_BIO_TYPE_ACCEPT = 0x50d;
static const Word OPENSSL_BIO_TYPE_BASE64 = 0x20b;
static const Word OPENSSL_BIO_TYPE_BER = 0x212;
static const Word OPENSSL_BIO_TYPE_BIO = 0x413;
static const Word OPENSSL_BIO_TYPE_BUFFER = 0x209;
static const Word OPENSSL_BIO_TYPE_CIPHER = 0x20a;
static const Word OPENSSL_BIO_TYPE_CONNECT = 0x50c;
static const Word OPENSSL_BIO_TYPE_DESCRIPTOR = 0x100;
static const Word OPENSSL_BIO_TYPE_FD = 0x504;
static const Word OPENSSL_BIO_TYPE_FILE = 0x402;
static const Word OPENSSL_BIO_TYPE_FILTER = 0x200;
static const Word OPENSSL_BIO_TYPE_MD = 0x208;
static const Word OPENSSL_BIO_TYPE_MEM = 0x401;
static const Word OPENSSL_BIO_TYPE_NBIO_TEST = 0x210;
static const ShortInt OPENSSL_BIO_TYPE_NONE = 0x0;
static const Word OPENSSL_BIO_TYPE_NULL = 0x406;
static const Word OPENSSL_BIO_TYPE_NULL_FILTER = 0x211;
static const Word OPENSSL_BIO_TYPE_PROXY_CLIENT = 0x20e;
static const Word OPENSSL_BIO_TYPE_PROXY_SERVER = 0x20f;
static const Word OPENSSL_BIO_TYPE_SOCKET = 0x505;
static const Word OPENSSL_BIO_TYPE_SOURCE_SINK = 0x400;
static const Word OPENSSL_BIO_TYPE_SSL = 0x207;
static const Word OPENSSL_BIO_TYPE_LINEBUFFER = 0x214;
static const Word OPENSSL_BIO_TYPE_DGRAM = 0x515;
static const Word OPENSSL_BIO_TYPE_COMP = 0x217;
static const ShortInt OPENSSL_BN_BITS = 0x40;
static const ShortInt OPENSSL_BN_BYTES = 0x4;
static const ShortInt OPENSSL_BN_BITS2 = 0x20;
static const ShortInt OPENSSL_BN_BITS4 = 0x10;
#define OPENSSL_BN_DEC_FMT1 L"%lu"
#define OPENSSL_BN_DEC_FMT2 L"%09lu"
static const ShortInt OPENSSL_BN_DEC_NUM = 0x9;
static const ShortInt OPENSSL_BN_CTX_NUM = 0xc;
static const Word OPENSSL_BN_DEFAULT_BITS = 0x500;
static const Word OPENSSL_BN_FLG_FREE = 0x8000;
static const ShortInt OPENSSL_BN_FLG_MALLOCED = 0x1;
static const ShortInt OPENSSL_BN_FLG_STATIC_DATA = 0x2;
static const ShortInt OPENSSL_BN_FLG_CONSTTIME = 0x4;
static const ShortInt OPENSSL_BN_FLG_EXP_CONSTTIME = 0x4;
static const ShortInt OPENSSL_BN_F_BN_BLINDING_CONVERT = 0x64;
static const ShortInt OPENSSL_BN_F_BN_BLINDING_INVERT = 0x65;
static const ShortInt OPENSSL_BN_F_BN_BLINDING_NEW = 0x66;
static const ShortInt OPENSSL_BN_F_BN_BLINDING_UPDATE = 0x67;
static const ShortInt OPENSSL_BN_F_BN_BN2DEC = 0x68;
static const ShortInt OPENSSL_BN_F_BN_BN2HEX = 0x69;
static const ShortInt OPENSSL_BN_F_BN_CTX_NEW = 0x6a;
static const ShortInt OPENSSL_BN_F_BN_DIV = 0x6b;
static const Byte OPENSSL_BN_F_BN_DIV_NO_BRANCH = 0x8a;
static const ShortInt OPENSSL_BN_F_BN_EXPAND2 = 0x6c;
static const ShortInt OPENSSL_BN_F_BN_MOD_EXP_MONT = 0x6d;
static const ShortInt OPENSSL_BN_F_BN_MOD_INVERSE = 0x6e;
static const Byte OPENSSL_BN_F_BN_MOD_INVERSE_NO_BRANCH = 0x8b;
static const ShortInt OPENSSL_BN_F_BN_MOD_MUL_RECIPROCAL = 0x6f;
static const ShortInt OPENSSL_BN_F_BN_MPI2BN = 0x70;
static const ShortInt OPENSSL_BN_F_BN_NEW = 0x71;
static const ShortInt OPENSSL_BN_F_BN_RAND = 0x72;
static const ShortInt OPENSSL_BN_F_BN_USUB = 0x73;
static const unsigned OPENSSL_BN_MASK2 = 0xffffffff;
static const unsigned OPENSSL_BN_MASK2h = 0xffff0000;
static const unsigned OPENSSL_BN_MASK2h1 = 0xffff8000;
static const Word OPENSSL_BN_MASK2l = 0xffff;
static const ShortInt OPENSSL_BN_R_ARG2_LT_ARG3 = 0x64;
static const ShortInt OPENSSL_BN_R_BAD_RECIPROCAL = 0x65;
static const ShortInt OPENSSL_BN_R_CALLED_WITH_EVEN_MODULUS = 0x66;
static const ShortInt OPENSSL_BN_R_DIV_BY_ZERO = 0x67;
static const ShortInt OPENSSL_BN_R_ENCODING_ERROR = 0x68;
static const ShortInt OPENSSL_BN_R_EXPAND_ON_STATIC_BIGNUM_DATA = 0x69;
static const ShortInt OPENSSL_BN_R_INVALID_LENGTH = 0x6a;
static const ShortInt OPENSSL_BN_R_NOT_INITIALIZED = 0x6b;
static const ShortInt OPENSSL_BN_R_NO_INVERSE = 0x6c;
static const unsigned OPENSSL_BN_TBIT = 0x80000000;
static const Word OPENSSL_BUFSIZ = 0x400;
static const ShortInt OPENSSL_BUF_F_BUF_MEM_GROW = 0x64;
static const ShortInt OPENSSL_BUF_F_BUF_MEM_NEW = 0x65;
static const ShortInt OPENSSL_BUF_F_BUF_STRDUP = 0x66;
static const ShortInt OPENSSL_RAND_F_ENG_RAND_GET_RAND_METHOD = 0x6c;
static const ShortInt OPENSSL_RAND_F_FIPS_RAND = 0x67;
static const ShortInt OPENSSL_RAND_F_FIPS_RAND_BYTES = 0x66;
static const ShortInt OPENSSL_RAND_F_FIPS_RAND_GET_RAND_METHOD = 0x6d;
static const ShortInt OPENSSL_RAND_F_FIPS_RAND_SET_DT = 0x6a;
static const ShortInt OPENSSL_RAND_F_FIPS_SET_DT = 0x68;
static const ShortInt OPENSSL_RAND_F_FIPS_SET_PRNG_SEED = 0x6b;
static const ShortInt OPENSSL_RAND_F_FIPS_SET_TEST_MODE = 0x69;
static const ShortInt OPENSSL_RAND_F_RAND_GET_RAND_METHOD = 0x65;
static const ShortInt OPENSSL_RAND_F_SSLEAY_RAND_BYTES = 0x64;
static const ShortInt OPENSSL_RAND_R_NON_FIPS_METHOD = 0x69;
static const ShortInt OPENSSL_RAND_R_NOT_IN_TEST_MODE = 0x6a;
static const ShortInt OPENSSL_RAND_R_NO_KEY_SET = 0x6b;
static const ShortInt OPENSSL_RAND_R_PRNG_ASKING_FOR_TOO_MUCH = 0x65;
static const ShortInt OPENSSL_RAND_R_PRNG_ERROR = 0x6c;
static const ShortInt OPENSSL_RAND_R_PRNG_KEYED = 0x6d;
static const ShortInt OPENSSL_RAND_R_PRNG_NOT_REKEYED = 0x66;
static const ShortInt OPENSSL_RAND_R_PRNG_NOT_RESEEDED = 0x67;
static const ShortInt OPENSSL_RAND_R_PRNG_NOT_SEEDED = 0x64;
static const ShortInt OPENSSL_RAND_R_PRNG_SEED_MUST_NOT_MATCH_KEY = 0x6e;
static const ShortInt OPENSSL_RAND_R_PRNG_STUCK = 0x68;
static const Word OPENSSL_B_ASN1_BIT_STRING = 0x400;
static const Word OPENSSL_B_ASN1_BMPSTRING = 0x800;
static const Byte OPENSSL_B_ASN1_GENERALSTRING = 0x80;
static const ShortInt OPENSSL_B_ASN1_GRAPHICSTRING = 0x20;
static const ShortInt OPENSSL_B_ASN1_IA5STRING = 0x10;
static const ShortInt OPENSSL_B_ASN1_ISO64STRING = 0x40;
static const ShortInt OPENSSL_B_ASN1_NUMERICSTRING = 0x1;
static const Word OPENSSL_B_ASN1_OCTET_STRING = 0x200;
static const ShortInt OPENSSL_B_ASN1_PRINTABLESTRING = 0x2;
static const ShortInt OPENSSL_B_ASN1_T61STRING = 0x4;
static const ShortInt OPENSSL_B_ASN1_TELETEXSTRING = 0x8;
static const Word OPENSSL_B_ASN1_UNIVERSALSTRING = 0x100;
static const Word OPENSSL_B_ASN1_UNKNOWN = 0x1000;
static const Word OPENSSL_B_ASN1_UTF8STRING = 0x2000;
static const ShortInt OPENSSL_B_ASN1_VIDEOTEXSTRING = 0x8;
static const ShortInt OPENSSL_B_ASN1_VISIBLESTRING = 0x40;
static const Word OPENSSL_B_ASN1_UTCTIME = 0x4000;
static const Word OPENSSL_B_ASN1_GENERALIZEDTIME = 0x8000;
static const int OPENSSL_B_ASN1_SEQUENCE = 0x10000;
static const Word OPENSSL_B_ASN1_TIME = 0xc000;
static const int OPENSSL_B_ASN1_PRINTABLE = 0x13d16;
static const Word OPENSSL_B_ASN1_DIRECTORYSTRING = 0x290a;
static const Word OPENSSL_B_ASN1_DISPLAYTEXT = 0x2850;
static const Word OPENSSL_MBSTRING_FLAG = 0x1000;
static const Word OPENSSL_MBSTRING_UTF8 = 0x1000;
static const Word OPENSSL_MBSTRING_ASC = 0x1001;
static const Word OPENSSL_MBSTRING_BMP = 0x1002;
static const Word OPENSSL_MBSTRING_UNIV = 0x1004;
static const Word OPENSSL_SMIME_OLDMIME = 0x400;
static const Word OPENSSL_SMIME_CRLFEOL = 0x800;
static const Word OPENSSL_SMIME_STREAM = 0x1000;
static const Word OPENSSL__CLOCKS_PER_SEC_ = 0x3e8;
static const Word OPENSSL_CLOCKS_PER_SEC = 0x3e8;
static const Word OPENSSL_CLK_TCK = 0x3e8;
static const ShortInt OPENSSL_COMP_F_BIO_ZLIB_FLUSH = 0x63;
static const ShortInt OPENSSL_COMP_F_BIO_ZLIB_NEW = 0x64;
static const ShortInt OPENSSL_COMP_F_BIO_ZLIB_READ = 0x65;
static const ShortInt OPENSSL_COMP_F_BIO_ZLIB_WRITE = 0x66;
static const ShortInt OPENSSL_COMP_R_ZLIB_DEFLATE_ERROR = 0x63;
static const ShortInt OPENSSL_COMP_R_ZLIB_INFLATE_ERROR = 0x64;
static const ShortInt OPENSSL_COMP_R_ZLIB_NOT_SUPPORTED = 0x65;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_BIO = 0x0;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_SSL = 0x1;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_SSL_CTX = 0x2;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_SSL_SESSION = 0x3;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_X509_STORE = 0x4;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_X509_STORE_CTX = 0x5;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_RSA = 0x6;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_DSA = 0x7;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_DH = 0x8;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_ENGINE = 0x9;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_X509 = 0xa;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_UI = 0xb;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_ECDSA = 0xc;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_ECDH = 0xd;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_COMP = 0xe;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_STORE = 0xf;
static const ShortInt OPENSSL_CRYPTO_EX_INDEX_USER = 0x64;
static const ShortInt OPENSSL_CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX = 0x64;
static const ShortInt OPENSSL_CRYPTO_F_CRYPTO_GET_NEW_DYNLOCKID = 0x67;
static const ShortInt OPENSSL_CRYPTO_F_CRYPTO_GET_NEW_LOCKID = 0x65;
static const ShortInt OPENSSL_CRYPTO_F_CRYPTO_SET_EX_DATA = 0x66;
static const ShortInt OPENSSL_CRYPTO_F_DEF_ADD_INDEX = 0x68;
static const ShortInt OPENSSL_CRYPTO_F_DEF_GET_CLASS = 0x69;
static const ShortInt OPENSSL_CRYPTO_F_INT_DUP_EX_DATA = 0x6a;
static const ShortInt OPENSSL_CRYPTO_F_INT_FREE_EX_DATA = 0x6b;
static const ShortInt OPENSSL_CRYPTO_F_INT_NEW_EX_DATA = 0x6c;
static const ShortInt OPENSSL_CRYPTO_R_NO_DYNLOCK_CREATE_CALLBACK = 0x64;
static const ShortInt OPENSSL_CRYPTO_LOCK = 0x1;
static const ShortInt OPENSSL_CRYPTO_LOCK_ERR = 0x1;
static const ShortInt OPENSSL_CRYPTO_LOCK_ERR_HASH = 0x2;
static const ShortInt OPENSSL_CRYPTO_LOCK_X509 = 0x3;
static const ShortInt OPENSSL_CRYPTO_LOCK_X509_INFO = 0x4;
static const ShortInt OPENSSL_CRYPTO_LOCK_X509_PKEY = 0x5;
static const ShortInt OPENSSL_CRYPTO_LOCK_X509_CRL = 0x6;
static const ShortInt OPENSSL_CRYPTO_LOCK_X509_REQ = 0x7;
static const ShortInt OPENSSL_CRYPTO_LOCK_DSA = 0x8;
static const ShortInt OPENSSL_CRYPTO_LOCK_RSA = 0x9;
static const ShortInt OPENSSL_CRYPTO_LOCK_EVP_PKEY = 0xa;
static const ShortInt OPENSSL_CRYPTO_LOCK_X509_STORE = 0xb;
static const ShortInt OPENSSL_CRYPTO_LOCK_SSL_CTX = 0xc;
static const ShortInt OPENSSL_CRYPTO_LOCK_SSL_CERT = 0xd;
static const ShortInt OPENSSL_CRYPTO_LOCK_SSL_SESSION = 0xe;
static const ShortInt OPENSSL_CRYPTO_LOCK_SSL_SESS_CERT = 0xf;
static const ShortInt OPENSSL_CRYPTO_LOCK_SSL = 0x10;
static const ShortInt OPENSSL_CRYPTO_LOCK_SSL_METHOD = 0x11;
static const ShortInt OPENSSL_CRYPTO_LOCK_RAND = 0x12;
static const ShortInt OPENSSL_CRYPTO_LOCK_RAND2 = 0x13;
static const ShortInt OPENSSL_CRYPTO_LOCK_MALLOC = 0x14;
static const ShortInt OPENSSL_CRYPTO_LOCK_BIO = 0x15;
static const ShortInt OPENSSL_CRYPTO_LOCK_GETHOSTBYNAME = 0x16;
static const ShortInt OPENSSL_CRYPTO_LOCK_GETSERVBYNAME = 0x17;
static const ShortInt OPENSSL_CRYPTO_LOCK_READDIR = 0x18;
static const ShortInt OPENSSL_CRYPTO_LOCK_RSA_BLINDING = 0x19;
static const ShortInt OPENSSL_CRYPTO_LOCK_DH = 0x1a;
static const ShortInt OPENSSL_CRYPTO_LOCK_MALLOC2 = 0x1b;
static const ShortInt OPENSSL_CRYPTO_LOCK_DSO = 0x1c;
static const ShortInt OPENSSL_CRYPTO_LOCK_DYNLOCK = 0x1d;
static const ShortInt OPENSSL_CRYPTO_LOCK_ENGINE = 0x1e;
static const ShortInt OPENSSL_CRYPTO_LOCK_UI = 0x1f;
static const ShortInt OPENSSL_CRYPTO_LOCK_ECDSA = 0x20;
static const ShortInt OPENSSL_CRYPTO_LOCK_EC = 0x21;
static const ShortInt OPENSSL_CRYPTO_LOCK_ECDH = 0x22;
static const ShortInt OPENSSL_CRYPTO_LOCK_BN = 0x23;
static const ShortInt OPENSSL_CRYPTO_LOCK_EC_PRE_COMP = 0x24;
static const ShortInt OPENSSL_CRYPTO_LOCK_STORE = 0x25;
static const ShortInt OPENSSL_CRYPTO_LOCK_COMP = 0x26;
static const ShortInt OPENSSL_CRYPTO_NUM_LOCKS = 0x27;
static const ShortInt OPENSSL_CRYPTO_MEM_CHECK_DISABLE = 0x3;
static const ShortInt OPENSSL_CRYPTO_MEM_CHECK_ENABLE = 0x2;
static const ShortInt OPENSSL_CRYPTO_MEM_CHECK_OFF = 0x0;
static const ShortInt OPENSSL_CRYPTO_MEM_CHECK_ON = 0x1;
static const ShortInt OPENSSL_CRYPTO_READ = 0x4;
static const ShortInt OPENSSL_CRYPTO_UNLOCK = 0x2;
static const ShortInt OPENSSL_CRYPTO_WRITE = 0x8;
static const ShortInt OPENSSL_V_CRYPTO_MDEBUG_TIME = 0x1;
static const ShortInt OPENSSL_V_CRYPTO_MDEBUG_THREAD = 0x2;
static const ShortInt OPENSSL_AES_ENCRYPT = 0x1;
static const ShortInt OPENSSL_AES_DECRYPT = 0x0;
static const ShortInt OPENSSL_AES_MAXNR = 0xe;
static const ShortInt OPENSSL_AES_BLOCK_SIZE = 0x10;
static const ShortInt OPENSSL_CAST_BLOCK = 0x8;
static const ShortInt OPENSSL_CAST_DECRYPT = 0x0;
static const ShortInt OPENSSL_CAST_ENCRYPT = 0x1;
static const ShortInt OPENSSL_CAST_KEY_LENGTH = 0x10;
static const ShortInt OPENSSL_DES_CBC_MODE = 0x0;
static const ShortInt OPENSSL_DES_DECRYPT = 0x0;
static const ShortInt OPENSSL_DES_ENCRYPT = 0x1;
static const ShortInt OPENSSL_DES_PCBC_MODE = 0x1;
static const Word OPENSSL_DH_MAX_MODULUS_BITS = 0x2710;
static const Word OPENSSL_DH_FIPS_MIN_MODULUS_BITS = 0x400;
static const ShortInt OPENSSL_DH_FLAG_CACHE_MONT_P = 0x1;
static const ShortInt OPENSSL_DH_FLAG_NO_EXP_CONSTTIME = 0x2;
static const ShortInt OPENSSL_DH_GENERATOR_2 = 0x2;
static const ShortInt OPENSSL_DH_GENERATOR_5 = 0x5;
static const ShortInt OPENSSL_DH_CHECK_P_NOT_PRIME = 0x1;
static const ShortInt OPENSSL_DH_CHECK_P_NOT_STRONG_PRIME = 0x2;
static const ShortInt OPENSSL_DH_UNABLE_TO_CHECK_GENERATOR = 0x4;
static const ShortInt OPENSSL_DH_NOT_SUITABLE_GENERATOR = 0x8;
static const ShortInt OPENSSL_DH_CHECK_PUBKEY_TOO_SMALL = 0x1;
static const ShortInt OPENSSL_DH_CHECK_PUBKEY_TOO_LARGE = 0x2;
static const ShortInt OPENSSL_DH_CHECK_P_NOT_SAFE_PRIME = 0x2;
static const ShortInt OPENSSL_DH_F_DHPARAMS_PRINT = 0x64;
static const ShortInt OPENSSL_DH_F_DHPARAMS_PRINT_FP = 0x65;
static const ShortInt OPENSSL_DH_F_COMPUTE_KEY = 0x66;
static const ShortInt OPENSSL_DH_F_GENERATE_KEY = 0x67;
static const ShortInt OPENSSL_DH_F_GENERATE_PARAMETERS = 0x68;
static const ShortInt OPENSSL_DH_F_DH_NEW_METHOD = 0x69;
static const ShortInt OPENSSL_DH_F_DH_NEW = 0x69;
static const ShortInt OPENSSL_DH_F_DH_BUILTIN_GENPARAMS = 0x6a;
static const ShortInt OPENSSL_DH_F_DH_COMPUTE_KEY = 0x6b;
static const ShortInt OPENSSL_DH_F_DH_GENERATE_KEY = 0x6c;
static const ShortInt OPENSSL_DH_F_DH_GENERATE_PARAMETERS = 0x6d;
static const ShortInt OPENSSL_DH_R_NO_PRIVATE_VALUE = 0x64;
static const ShortInt OPENSSL_DH_R_BAD_GENERATOR = 0x65;
static const ShortInt OPENSSL_DH_R_INVALID_PUBKEY = 0x66;
static const ShortInt OPENSSL_DH_R_MODULUS_TOO_LARGE = 0x67;
static const ShortInt OPENSSL_DH_R_KEY_SIZE_TOO_SMALL = 0x68;
static const Word OPENSSL_DSA_MAX_MODULUS_BITS = 0x2710;
static const Word OPENSSL_DSA_FIPS_MIN_MODULUS_BITS = 0x400;
static const ShortInt OPENSSL_DSA_FLAG_CACHE_MONT_P = 0x1;
static const ShortInt OPENSSL_DSA_FLAG_NO_EXP_CONSTTIME = 0x2;
static const Word OPENSSL_DSA_FLAG_FIPS_METHOD = 0x400;
static const Word OPENSSL_DSA_FLAG_NON_FIPS_ALLOW = 0x400;
static const ShortInt OPENSSL_DSA_F_D2I_DSA_SIG = 0x6e;
static const ShortInt OPENSSL_DSA_F_DSAPARAMS_PRINT = 0x64;
static const ShortInt OPENSSL_DSA_F_DSAPARAMS_PRINT_FP = 0x65;
static const ShortInt OPENSSL_DSA_F_DSA_BUILTIN_KEYGEN = 0x77;
static const ShortInt OPENSSL_DSA_F_DSA_BUILTIN_PARAMGEN = 0x76;
static const ShortInt OPENSSL_DSA_F_DSA_DO_SIGN = 0x70;
static const ShortInt OPENSSL_DSA_F_DSA_DO_VERIFY = 0x71;
static const ShortInt OPENSSL_DSA_F_DSA_IS_PRIME = 0x66;
static const ShortInt OPENSSL_DSA_F_DSA_NEW = 0x67;
static const ShortInt OPENSSL_DSA_F_DSA_PRINT = 0x68;
static const ShortInt OPENSSL_DSA_F_DSA_PRINT_FP = 0x69;
static const ShortInt OPENSSL_DSA_F_DSA_SIGN = 0x6a;
static const ShortInt OPENSSL_DSA_F_DSA_SIGN_SETUP = 0x6b;
static const ShortInt OPENSSL_DSA_F_DSA_SIG_NEW = 0x6d;
static const ShortInt OPENSSL_DSA_F_DSA_VERIFY = 0x6c;
static const ShortInt OPENSSL_DSA_F_DSA_GENERATE_PARAMETERS = 0x75;
static const ShortInt OPENSSL_DSA_F_I2D_DSA_SIG = 0x6f;
static const ShortInt OPENSSL_DSA_F_SIG_CB = 0x72;
static const ShortInt OPENSSL_DSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE = 0x64;
static const ShortInt OPENSSL_DSA_R_MISSING_PARAMETERS = 0x65;
static const ShortInt OPENSSL_DSA_R_BAD_Q_VALUE = 0x66;
static const ShortInt OPENSSL_DSA_R_MODULUS_TOO_LARGE = 0x67;
static const ShortInt OPENSSL_DSA_R_NON_FIPS_METHOD = 0x68;
static const ShortInt OPENSSL_DSA_R_OPERATION_NOT_ALLOWED_IN_FIPS_MODE = 0x69;
static const ShortInt OPENSSL_DSA_R_KEY_SIZE_TOO_SMALL = 0x6a;
static const Word OPENSSL_ECC_MAX_FIELD_BITS = 0x295;
static const ShortInt OPENSSL_EC_NAMED_CURVE = 0x1;
static const ShortInt OPENSSL_POINT_CONVERSION_COMPRESSED = 0x2;
static const ShortInt OPENSSL_POINT_CONVERSION_UNCOMPRESSED = 0x4;
static const ShortInt OPENSSL_POINT_CONVERSION_HYBRID = 0x6;
static const ShortInt OPENSSL_EC_PKEY_NO_PARAMETERS = 0x1;
static const ShortInt OPENSSL_EC_PKEY_NO_PUBKEY = 0x2;
static const Byte OPENSSL_EC_F_COMPUTE_WNAF = 0x8f;
static const Byte OPENSSL_EC_F_D2I_ECPARAMETERS = 0x90;
static const Byte OPENSSL_EC_F_D2I_ECPKPARAMETERS = 0x91;
static const Byte OPENSSL_EC_F_D2I_ECPRIVATEKEY = 0x92;
static const Byte OPENSSL_EC_F_ECPARAMETERS_PRINT = 0x93;
static const Byte OPENSSL_EC_F_ECPARAMETERS_PRINT_FP = 0x94;
static const Byte OPENSSL_EC_F_ECPKPARAMETERS_PRINT = 0x95;
static const Byte OPENSSL_EC_F_ECPKPARAMETERS_PRINT_FP = 0x96;
static const Byte OPENSSL_EC_F_ECP_NIST_MOD_192 = 0xcb;
static const Byte OPENSSL_EC_F_ECP_NIST_MOD_224 = 0xcc;
static const Byte OPENSSL_EC_F_ECP_NIST_MOD_256 = 0xcd;
static const Byte OPENSSL_EC_F_ECP_NIST_MOD_521 = 0xce;
static const Byte OPENSSL_EC_F_EC_ASN1_GROUP2CURVE = 0x99;
static const Byte OPENSSL_EC_F_EC_ASN1_GROUP2FIELDID = 0x9a;
static const Byte OPENSSL_EC_F_EC_ASN1_GROUP2PARAMETERS = 0x9b;
static const Byte OPENSSL_EC_F_EC_ASN1_GROUP2PKPARAMETERS = 0x9c;
static const Byte OPENSSL_EC_F_EC_ASN1_PARAMETERS2GROUP = 0x9d;
static const Byte OPENSSL_EC_F_EC_ASN1_PKPARAMETERS2GROUP = 0x9e;
static const Byte OPENSSL_EC_F_EC_EX_DATA_SET_DATA = 0xd3;
static const Byte OPENSSL_EC_F_EC_GF2M_MONTGOMERY_POINT_MULTIPLY = 0xd0;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_GROUP_CHECK_DISCRIMINANT = 0x9f;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_GROUP_SET_CURVE = 0xc3;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_OCT2POINT = 0xa0;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_POINT2OCT = 0xa1;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_POINT_GET_AFFINE_COORDINATES = 0xa2;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_POINT_SET_AFFINE_COORDINATES = 0xa3;
static const Byte OPENSSL_EC_F_EC_GF2M_SIMPLE_SET_COMPRESSED_COORDINATES = 0xa4;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_FIELD_DECODE = 0x85;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_FIELD_ENCODE = 0x86;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_FIELD_MUL = 0x83;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_FIELD_SET_TO_ONE = 0xd1;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_FIELD_SQR = 0x84;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_GROUP_SET_CURVE = 0xbd;
static const Byte OPENSSL_EC_F_EC_GFP_MONT_GROUP_SET_CURVE_GFP = 0x87;
static const Byte OPENSSL_EC_F_EC_GFP_NIST_FIELD_MUL = 0xc8;
static const Byte OPENSSL_EC_F_EC_GFP_NIST_FIELD_SQR = 0xc9;
static const Byte OPENSSL_EC_F_EC_GFP_NIST_GROUP_SET_CURVE = 0xca;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_GROUP_CHECK_DISCRIMINANT = 0xa5;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_GROUP_SET_CURVE = 0xa6;
static const ShortInt OPENSSL_EC_F_EC_GFP_SIMPLE_GROUP_SET_CURVE_GFP = 0x64;
static const ShortInt OPENSSL_EC_F_EC_GFP_SIMPLE_GROUP_SET_GENERATOR = 0x65;
static const ShortInt OPENSSL_EC_F_EC_GFP_SIMPLE_MAKE_AFFINE = 0x66;
static const ShortInt OPENSSL_EC_F_EC_GFP_SIMPLE_OCT2POINT = 0x67;
static const ShortInt OPENSSL_EC_F_EC_GFP_SIMPLE_POINT2OCT = 0x68;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_POINTS_MAKE_AFFINE = 0x89;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_POINT_GET_AFFINE_COORDINATES = 0xa7;
static const ShortInt OPENSSL_EC_F_EC_GFP_SIMPLE_POINT_GET_AFFINE_COORDINATES_GFP = 0x69;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_POINT_SET_AFFINE_COORDINATES = 0xa8;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_POINT_SET_AFFINE_COORDINATES_GFP = 0x80;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES = 0xa9;
static const Byte OPENSSL_EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES_GFP = 0x81;
static const Byte OPENSSL_EC_F_EC_GROUP_CHECK = 0xaa;
static const Byte OPENSSL_EC_F_EC_GROUP_CHECK_DISCRIMINANT = 0xab;
static const ShortInt OPENSSL_EC_F_EC_GROUP_COPY = 0x6a;
static const Byte OPENSSL_EC_F_EC_GROUP_GET0_GENERATOR = 0x8b;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_COFACTOR = 0x8c;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_CURVE_GF2M = 0xac;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_CURVE_GFP = 0x82;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_DEGREE = 0xad;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_ORDER = 0x8d;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_PENTANOMIAL_BASIS = 0xc1;
static const Byte OPENSSL_EC_F_EC_GROUP_GET_TRINOMIAL_BASIS = 0xc2;
static const ShortInt OPENSSL_EC_F_EC_GROUP_NEW = 0x6c;
static const Byte OPENSSL_EC_F_EC_GROUP_NEW_BY_CURVE_NAME = 0xae;
static const Byte OPENSSL_EC_F_EC_GROUP_NEW_FROM_DATA = 0xaf;
static const Byte OPENSSL_EC_F_EC_GROUP_PRECOMPUTE_MULT = 0x8e;
static const Byte OPENSSL_EC_F_EC_GROUP_SET_CURVE_GF2M = 0xb0;
static const ShortInt OPENSSL_EC_F_EC_GROUP_SET_CURVE_GFP = 0x6d;
static const ShortInt OPENSSL_EC_F_EC_GROUP_SET_EXTRA_DATA = 0x6e;
static const ShortInt OPENSSL_EC_F_EC_GROUP_SET_GENERATOR = 0x6f;
static const Byte OPENSSL_EC_F_EC_KEY_CHECK_KEY = 0xb1;
static const Byte OPENSSL_EC_F_EC_KEY_COPY = 0xb2;
static const Byte OPENSSL_EC_F_EC_KEY_GENERATE_KEY = 0xb3;
static const Byte OPENSSL_EC_F_EC_KEY_NEW = 0xb6;
static const Byte OPENSSL_EC_F_EC_KEY_PRINT = 0xb4;
static const Byte OPENSSL_EC_F_EC_KEY_PRINT_FP = 0xb5;
static const Byte OPENSSL_EC_F_EC_POINTS_MAKE_AFFINE = 0x88;
static const Byte OPENSSL_EC_F_EC_POINTS_MUL = 0x8a;
static const ShortInt OPENSSL_EC_F_EC_POINT_ADD = 0x70;
static const ShortInt OPENSSL_EC_F_EC_POINT_CMP = 0x71;
static const ShortInt OPENSSL_EC_F_EC_POINT_COPY = 0x72;
static const ShortInt OPENSSL_EC_F_EC_POINT_DBL = 0x73;
static const Byte OPENSSL_EC_F_EC_POINT_GET_AFFINE_COORDINATES_GF2M = 0xb7;
static const ShortInt OPENSSL_EC_F_EC_POINT_GET_AFFINE_COORDINATES_GFP = 0x74;
static const ShortInt OPENSSL_EC_F_EC_POINT_GET_JPROJECTIVE_COORDINATES_GFP = 0x75;
static const Byte OPENSSL_EC_F_EC_POINT_INVERT = 0xd2;
static const ShortInt OPENSSL_EC_F_EC_POINT_IS_AT_INFINITY = 0x76;
static const ShortInt OPENSSL_EC_F_EC_POINT_IS_ON_CURVE = 0x77;
static const ShortInt OPENSSL_EC_F_EC_POINT_MAKE_AFFINE = 0x78;
static const Byte OPENSSL_EC_F_EC_POINT_MUL = 0xb8;
static const ShortInt OPENSSL_EC_F_EC_POINT_NEW = 0x79;
static const ShortInt OPENSSL_EC_F_EC_POINT_OCT2POINT = 0x7a;
static const ShortInt OPENSSL_EC_F_EC_POINT_POINT2OCT = 0x7b;
static const Byte OPENSSL_EC_F_EC_POINT_SET_AFFINE_COORDINATES_GF2M = 0xb9;
static const ShortInt OPENSSL_EC_F_EC_POINT_SET_AFFINE_COORDINATES_GFP = 0x7c;
static const Byte OPENSSL_EC_F_EC_POINT_SET_COMPRESSED_COORDINATES_GF2M = 0xba;
static const ShortInt OPENSSL_EC_F_EC_POINT_SET_COMPRESSED_COORDINATES_GFP = 0x7d;
static const ShortInt OPENSSL_EC_F_EC_POINT_SET_JPROJECTIVE_COORDINATES_GFP = 0x7e;
static const ShortInt OPENSSL_EC_F_EC_POINT_SET_TO_INFINITY = 0x7f;
static const Byte OPENSSL_EC_F_EC_PRE_COMP_DUP = 0xcf;
static const Byte OPENSSL_EC_F_EC_PRE_COMP_NEW = 0xc4;
static const Byte OPENSSL_EC_F_EC_WNAF_MUL = 0xbb;
static const Byte OPENSSL_EC_F_EC_WNAF_PRECOMPUTE_MULT = 0xbc;
static const Byte OPENSSL_EC_F_I2D_ECPARAMETERS = 0xbe;
static const Byte OPENSSL_EC_F_I2D_ECPKPARAMETERS = 0xbf;
static const Byte OPENSSL_EC_F_I2D_ECPRIVATEKEY = 0xc0;
static const Byte OPENSSL_EC_F_I2O_ECPUBLICKEY = 0x97;
static const Byte OPENSSL_EC_F_O2I_ECPUBLICKEY = 0x98;
static const ShortInt OPENSSL_EC_R_ASN1_ERROR = 0x73;
static const ShortInt OPENSSL_EC_R_ASN1_UNKNOWN_FIELD = 0x74;
static const ShortInt OPENSSL_EC_R_BUFFER_TOO_SMALL = 0x64;
static const ShortInt OPENSSL_EC_R_D2I_ECPKPARAMETERS_FAILURE = 0x75;
static const ShortInt OPENSSL_EC_R_DISCRIMINANT_IS_ZERO = 0x76;
static const ShortInt OPENSSL_EC_R_EC_GROUP_NEW_BY_NAME_FAILURE = 0x77;
static const Byte OPENSSL_EC_R_FIELD_TOO_LARGE = 0x8a;
static const ShortInt OPENSSL_EC_R_GROUP2PKPARAMETERS_FAILURE = 0x78;
static const ShortInt OPENSSL_EC_R_I2D_ECPKPARAMETERS_FAILURE = 0x79;
static const ShortInt OPENSSL_EC_R_INCOMPATIBLE_OBJECTS = 0x65;
static const ShortInt OPENSSL_EC_R_INVALID_ARGUMENT = 0x70;
static const ShortInt OPENSSL_EC_R_INVALID_COMPRESSED_POINT = 0x6e;
static const ShortInt OPENSSL_EC_R_INVALID_COMPRESSION_BIT = 0x6d;
static const ShortInt OPENSSL_EC_R_INVALID_ENCODING = 0x66;
static const ShortInt OPENSSL_EC_R_INVALID_FIELD = 0x67;
static const ShortInt OPENSSL_EC_R_INVALID_FORM = 0x68;
static const ShortInt OPENSSL_EC_R_INVALID_GROUP_ORDER = 0x7a;
static const Byte OPENSSL_EC_R_INVALID_PENTANOMIAL_BASIS = 0x84;
static const ShortInt OPENSSL_EC_R_INVALID_PRIVATE_KEY = 0x7b;
static const Byte OPENSSL_EC_R_INVALID_TRINOMIAL_BASIS = 0x89;
static const ShortInt OPENSSL_EC_R_MISSING_PARAMETERS = 0x7c;
static const ShortInt OPENSSL_EC_R_MISSING_PRIVATE_KEY = 0x7d;
static const Byte OPENSSL_EC_R_NOT_A_NIST_PRIME = 0x87;
static const Byte OPENSSL_EC_R_NOT_A_SUPPORTED_NIST_PRIME = 0x88;
static const ShortInt OPENSSL_EC_R_NOT_IMPLEMENTED = 0x7e;
static const ShortInt OPENSSL_EC_R_NOT_INITIALIZED = 0x6f;
static const Byte OPENSSL_EC_R_NO_FIELD_MOD = 0x85;
static const Byte OPENSSL_EC_R_PASSED_NULL_PARAMETER = 0x86;
static const ShortInt OPENSSL_EC_R_PKPARAMETERS2GROUP_FAILURE = 0x7f;
static const ShortInt OPENSSL_EC_R_POINT_AT_INFINITY = 0x6a;
static const ShortInt OPENSSL_EC_R_POINT_IS_NOT_ON_CURVE = 0x6b;
static const ShortInt OPENSSL_EC_R_SLOT_FULL = 0x6c;
static const ShortInt OPENSSL_EC_R_UNDEFINED_GENERATOR = 0x71;
static const Byte OPENSSL_EC_R_UNDEFINED_ORDER = 0x80;
static const Byte OPENSSL_EC_R_UNKNOWN_GROUP = 0x81;
static const ShortInt OPENSSL_EC_R_UNKNOWN_ORDER = 0x72;
static const Byte OPENSSL_EC_R_UNSUPPORTED_FIELD = 0x83;
static const Byte OPENSSL_EC_R_WRONG_ORDER = 0x82;
static const ShortInt OPENSSL_ECDSA_F_ECDSA_DATA_NEW_METHOD = 0x64;
static const ShortInt OPENSSL_ECDSA_F_ECDSA_DO_SIGN = 0x65;
static const ShortInt OPENSSL_ECDSA_F_ECDSA_DO_VERIFY = 0x66;
static const ShortInt OPENSSL_ECDSA_F_ECDSA_SIGN_SETUP = 0x67;
static const ShortInt OPENSSL_ECDSA_R_BAD_SIGNATURE = 0x64;
static const ShortInt OPENSSL_ECDSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE = 0x65;
static const ShortInt OPENSSL_ECDSA_R_ERR_EC_LIB = 0x66;
static const ShortInt OPENSSL_ECDSA_R_MISSING_PARAMETERS = 0x67;
static const ShortInt OPENSSL_ECDSA_R_RANDOM_NUMBER_GENERATION_FAILED = 0x68;
static const ShortInt OPENSSL_ECDSA_R_SIGNATURE_MALLOC_FAILED = 0x69;
static const ShortInt OPENSSL_ECDH_F_ECDH_COMPUTE_KEY = 0x64;
static const ShortInt OPENSSL_ECDH_F_ECDH_DATA_NEW_METHOD = 0x65;
static const ShortInt OPENSSL_ECDH_R_KDF_FAILED = 0x66;
static const ShortInt OPENSSL_ECDH_R_NO_PRIVATE_VALUE = 0x64;
static const ShortInt OPENSSL_ECDH_R_POINT_ARITHMETIC_FAILURE = 0x65;
static const ShortInt OPENSSL_BF_BLOCK = 0x8;
static const ShortInt OPENSSL_BF_DECRYPT = 0x0;
static const ShortInt OPENSSL_BF_ENCRYPT = 0x1;
static const ShortInt OPENSSL_BF_ROUNDS = 0x10;
static const ShortInt OPENSSL_EVP_MAX_MD_SIZE = 0x40;
static const ShortInt OPENSSL_EVP_MAX_KEY_LENGTH = 0x20;
static const ShortInt OPENSSL_EVP_MAX_IV_LENGTH = 0x10;
static const ShortInt OPENSSL_EVP_MAX_BLOCK_LENGTH = 0x20;
static const ShortInt OPENSSL_NID_dhKeyAgreement = 0x1c;
static const ShortInt OPENSSL_EVP_PKEY_DH = 0x1c;
static const ShortInt OPENSSL_NID_dsa = 0x74;
static const ShortInt OPENSSL_EVP_PKEY_DSA = 0x74;
static const ShortInt OPENSSL_NID_dsa_2 = 0x43;
static const ShortInt OPENSSL_EVP_PKEY_DSA1 = 0x43;
static const ShortInt OPENSSL_NID_dsaWithSHA = 0x42;
static const ShortInt OPENSSL_EVP_PKEY_DSA2 = 0x42;
static const ShortInt OPENSSL_NID_dsaWithSHA1 = 0x71;
static const ShortInt OPENSSL_EVP_PKEY_DSA3 = 0x71;
static const ShortInt OPENSSL_NID_dsaWithSHA1_2 = 0x46;
static const ShortInt OPENSSL_EVP_PKEY_DSA4 = 0x46;
static const ShortInt OPENSSL_EVP_PKEY_MO_DECRYPT = 0x8;
static const ShortInt OPENSSL_EVP_PKEY_MO_ENCRYPT = 0x4;
static const ShortInt OPENSSL_EVP_PKEY_MO_SIGN = 0x1;
static const ShortInt OPENSSL_EVP_PKEY_MO_VERIFY = 0x2;
static const Word OPENSSL_EVP_MD_FLAG_FIPS = 0x400;
static const Word OPENSSL_EVP_MD_FLAG_SVCTX = 0x800;
static const ShortInt OPENSSL_NID_undef = 0x0;
static const ShortInt OPENSSL_EVP_PKEY_NONE = 0x0;
static const ShortInt OPENSSL_NID_rsaEncryption = 0x6;
static const ShortInt OPENSSL_EVP_PKEY_RSA = 0x6;
static const ShortInt OPENSSL_NID_rsa = 0x13;
static const ShortInt OPENSSL_EVP_PKEY_RSA2 = 0x13;
static const Word OPENSSL_EVP_PKS_DSA = 0x200;
static const Word OPENSSL_EVP_PKS_RSA = 0x100;
static const ShortInt OPENSSL_EVP_PKT_ENC = 0x20;
static const ShortInt OPENSSL_EVP_PKT_EXCH = 0x40;
static const Word OPENSSL_EVP_PKT_EXP = 0x1000;
static const ShortInt OPENSSL_EVP_PKT_SIGN = 0x10;
static const ShortInt OPENSSL_EVP_PK_DH = 0x4;
static const ShortInt OPENSSL_EVP_PK_DSA = 0x2;
static const ShortInt OPENSSL_EVP_PK_RSA = 0x1;
static const ShortInt OPENSSL_EVP_BLOWFISH_KEY_SIZE = 0x10;
static const ShortInt OPENSSL_EVP_CAST5_KEY_SIZE = 0x10;
static const ShortInt OPENSSL_EVP_RC2_KEY_SIZE = 0x10;
static const ShortInt OPENSSL_EVP_RC4_KEY_SIZE = 0x10;
static const ShortInt OPENSSL_EVP_RC5_32_12_16_KEY_SIZE = 0x10;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_ONESHOT = 0x1;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_CLEANED = 0x2;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_REUSE = 0x4;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_NON_FIPS_ALLOW = 0x8;
static const Byte OPENSSL_EVP_MD_CTX_FLAG_PAD_MASK = 0xf0;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_PAD_PKCS1 = 0x0;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_PAD_X931 = 0x10;
static const ShortInt OPENSSL_EVP_MD_CTX_FLAG_PAD_PSS = 0x20;
static const Word OPENSSL_EVP_MD_CTX_FLAG_PSS_MDLEN = 0xffff;
static const Word OPENSSL_EVP_MD_CTX_FLAG_PSS_MREC = 0xfffe;
static const ShortInt OPENSSL_EVP_CIPH_STREAM_CIPHER = 0x0;
static const ShortInt OPENSSL_EVP_CIPH_ECB_MODE = 0x1;
static const ShortInt OPENSSL_EVP_CIPH_CBC_MODE = 0x2;
static const ShortInt OPENSSL_EVP_CIPH_CFB_MODE = 0x3;
static const ShortInt OPENSSL_EVP_CIPH_OFB_MODE = 0x4;
static const ShortInt OPENSSL_EVP_CIPH_MODE = 0x7;
static const ShortInt OPENSSL_EVP_CIPH_VARIABLE_LENGTH = 0x8;
static const ShortInt OPENSSL_EVP_CIPH_CUSTOM_IV = 0x10;
static const ShortInt OPENSSL_EVP_CIPH_ALWAYS_CALL_INIT = 0x20;
static const ShortInt OPENSSL_EVP_CIPH_CTRL_INIT = 0x40;
static const Byte OPENSSL_EVP_CIPH_CUSTOM_KEY_LENGTH = 0x80;
static const Word OPENSSL_EVP_CIPH_NO_PADDING = 0x100;
static const Word OPENSSL_EVP_CIPH_RAND_KEY = 0x200;
static const Word OPENSSL_EVP_CIPH_FLAG_FIPS = 0x400;
static const Word OPENSSL_EVP_CIPH_FLAG_NON_FIPS_ALLOW = 0x800;
static const Word OPENSSL_EVP_CIPH_FLAG_DEFAULT_ASN1 = 0x1000;
static const Word OPENSSL_EVP_CIPH_FLAG_LENGTH_BITS = 0x2000;
static const ShortInt OPENSSL_EVP_CTRL_INIT = 0x0;
static const ShortInt OPENSSL_EVP_CTRL_SET_KEY_LENGTH = 0x1;
static const ShortInt OPENSSL_EVP_CTRL_GET_RC2_KEY_BITS = 0x2;
static const ShortInt OPENSSL_EVP_CTRL_SET_RC2_KEY_BITS = 0x3;
static const ShortInt OPENSSL_EVP_CTRL_GET_RC5_ROUNDS = 0x4;
static const ShortInt OPENSSL_EVP_CTRL_SET_RC5_ROUNDS = 0x5;
static const ShortInt OPENSSL_EVP_CTRL_RAND_KEY = 0x6;
static const Byte OPENSSL_EVP_F_AES_INIT_KEY = 0x85;
static const Byte OPENSSL_EVP_F_ALG_MODULE_INIT = 0x8a;
static const Byte OPENSSL_EVP_F_CAMELLIA_INIT_KEY = 0x9f;
static const ShortInt OPENSSL_EVP_F_D2I_PKEY = 0x64;
static const Byte OPENSSL_EVP_F_DO_EVP_ENC_ENGINE = 0x8c;
static const Byte OPENSSL_EVP_F_DO_EVP_ENC_ENGINE_FULL = 0x8d;
static const Byte OPENSSL_EVP_F_DO_EVP_MD_ENGINE = 0x8b;
static const Byte OPENSSL_EVP_F_DO_EVP_MD_ENGINE_FULL = 0x8e;
static const Byte OPENSSL_EVP_F_DSAPKEY2PKCS8 = 0x86;
static const Byte OPENSSL_EVP_F_DSA_PKEY2PKCS8 = 0x87;
static const Byte OPENSSL_EVP_F_ECDSA_PKEY2PKCS8 = 0x81;
static const Byte OPENSSL_EVP_F_ECKEY_PKEY2PKCS8 = 0x84;
static const Byte OPENSSL_EVP_F_EVP_CIPHERINIT = 0x89;
static const ShortInt OPENSSL_EVP_F_EVP_CIPHERINIT_EX = 0x7b;
static const ShortInt OPENSSL_EVP_F_EVP_CIPHER_CTX_CTRL = 0x7c;
static const ShortInt OPENSSL_EVP_F_EVP_CIPHER_CTX_SET_KEY_LENGTH = 0x7a;
static const ShortInt OPENSSL_EVP_F_EVP_DECRYPTFINAL_EX = 0x65;
static const Byte OPENSSL_EVP_F_EVP_DIGESTINIT = 0x88;
static const Byte OPENSSL_EVP_F_EVP_DIGESTINIT_EX = 0x80;
static const ShortInt OPENSSL_EVP_F_EVP_ENCRYPTFINAL_EX = 0x7f;
static const ShortInt OPENSSL_EVP_F_EVP_MD_CTX_COPY_EX = 0x6e;
static const ShortInt OPENSSL_EVP_F_EVP_OPENINIT = 0x66;
static const ShortInt OPENSSL_EVP_F_EVP_PBE_ALG_ADD = 0x73;
static const ShortInt OPENSSL_EVP_F_EVP_PBE_CIPHERINIT = 0x74;
static const ShortInt OPENSSL_EVP_F_EVP_PKCS82PKEY = 0x6f;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY2PKCS8_BROKEN = 0x71;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_COPY_PARAMETERS = 0x67;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_DECRYPT = 0x68;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_ENCRYPT = 0x69;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_GET1_DH = 0x77;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_GET1_DSA = 0x78;
static const Byte OPENSSL_EVP_F_EVP_PKEY_GET1_ECDSA = 0x82;
static const Byte OPENSSL_EVP_F_EVP_PKEY_GET1_EC_KEY = 0x83;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_GET1_RSA = 0x79;
static const ShortInt OPENSSL_EVP_F_EVP_PKEY_NEW = 0x6a;
static const ShortInt OPENSSL_EVP_F_EVP_RIJNDAEL = 0x7e;
static const ShortInt OPENSSL_EVP_F_EVP_SIGNFINAL = 0x6b;
static const ShortInt OPENSSL_EVP_F_EVP_VERIFYFINAL = 0x6c;
static const ShortInt OPENSSL_EVP_F_PKCS5_PBE_KEYIVGEN = 0x75;
static const ShortInt OPENSSL_EVP_F_PKCS5_V2_PBE_KEYIVGEN = 0x76;
static const ShortInt OPENSSL_EVP_F_PKCS8_SET_BROKEN = 0x70;
static const ShortInt OPENSSL_EVP_F_RC2_MAGIC_TO_METH = 0x6d;
static const ShortInt OPENSSL_EVP_F_RC5_CTRL = 0x7d;
static const ShortInt OPENSSL_EVP_R_BAD_DECRYPT = 0x64;
static const ShortInt OPENSSL_EVP_R_BN_DECODE_ERROR = 0x70;
static const ShortInt OPENSSL_EVP_R_BN_PUBKEY_ERROR = 0x71;
static const ShortInt OPENSSL_EVP_R_CIPHER_PARAMETER_ERROR = 0x7a;
static const ShortInt OPENSSL_EVP_R_DECODE_ERROR = 0x72;
static const ShortInt OPENSSL_EVP_R_DIFFERENT_KEY_TYPES = 0x65;
static const Byte OPENSSL_EVP_R_DISABLED_FOR_FIPS = 0x90;
static const ShortInt OPENSSL_EVP_R_ENCODE_ERROR = 0x73;
static const Byte OPENSSL_EVP_R_ERROR_LOADING_SECTION = 0x91;
static const Byte OPENSSL_EVP_R_ERROR_SETTING_FIPS_MODE = 0x92;
static const ShortInt OPENSSL_EVP_R_EVP_PBE_CIPHERINIT_ERROR = 0x77;
static const ShortInt OPENSSL_EVP_R_EXPECTING_AN_RSA_KEY = 0x7f;
static const Byte OPENSSL_EVP_R_EXPECTING_A_DH_KEY = 0x80;
static const Byte OPENSSL_EVP_R_EXPECTING_A_DSA_KEY = 0x81;
static const Byte OPENSSL_EVP_R_EXPECTING_A_ECDSA_KEY = 0x8d;
static const Byte OPENSSL_EVP_R_EXPECTING_A_EC_KEY = 0x8e;
static const Byte OPENSSL_EVP_R_FIPS_MODE_NOT_SUPPORTED = 0x93;
static const Byte OPENSSL_EVP_R_INITIALIZATION_ERROR = 0x86;
static const ShortInt OPENSSL_EVP_R_INPUT_NOT_INITIALIZED = 0x6f;
static const Byte OPENSSL_EVP_R_INVALID_FIPS_MODE = 0x94;
static const ShortInt OPENSSL_EVP_R_IV_TOO_LARGE = 0x66;
static const ShortInt OPENSSL_EVP_R_KEYGEN_FAILURE = 0x78;
static const ShortInt OPENSSL_EVP_R_MISSING_PARMATERS = 0x67;
static const ShortInt OPENSSL_EVP_R_NO_DSA_PARAMETERS = 0x74;
static const ShortInt OPENSSL_EVP_R_NO_SIGN_FUNCTION_CONFIGURED = 0x68;
static const ShortInt OPENSSL_EVP_R_NO_VERIFY_FUNCTION_CONFIGURED = 0x69;
static const ShortInt OPENSSL_EVP_R_PKCS8_UNKNOWN_BROKEN_TYPE = 0x75;
static const ShortInt OPENSSL_EVP_R_PUBLIC_KEY_NOT_RSA = 0x6a;
static const Byte OPENSSL_EVP_R_UNKNOWN_OPTION = 0x95;
static const ShortInt OPENSSL_EVP_R_UNKNOWN_PBE_ALGORITHM = 0x79;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_CIPHER = 0x6b;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_KEYLENGTH = 0x7b;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_KEY_DERIVATION_FUNCTION = 0x7c;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_KEY_SIZE = 0x6c;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_PRF = 0x7d;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_PRIVATE_KEY_ALGORITHM = 0x76;
static const ShortInt OPENSSL_EVP_R_UNSUPPORTED_SALT_TYPE = 0x7e;
static const ShortInt OPENSSL_EVP_R_WRONG_FINAL_BLOCK_LENGTH = 0x6d;
static const ShortInt OPENSSL_EVP_R_WRONG_PUBLIC_KEY_TYPE = 0x6e;
static const Byte OPENSSL_EVP_R_SEED_KEY_SETUP_FAILED = 0xa2;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_RSA;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_DSA;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_DH;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_RAND;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_ECDH;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_ECDSA;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_CIPHERS;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_DIGESTS;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_STORE;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_ALL;
extern PACKAGE unsigned OPENSSL_ENGINE_METHOD_NONE;
extern PACKAGE unsigned OPENSSL_ENGINE_TABLE_FLAG_NOINIT;
extern PACKAGE int OPENSSL_ENGINE_FLAGS_MANUAL_CMD_CTRL;
extern PACKAGE int OPENSSL_ENGINE_FLAGS_BY_ID_COPY;
extern PACKAGE unsigned OPENSSL_ENGINE_CMD_FLAG_NUMERIC;
extern PACKAGE unsigned OPENSSL_ENGINE_CMD_FLAG_STRING;
extern PACKAGE unsigned OPENSSL_ENGINE_CMD_FLAG_NO_INPUT;
extern PACKAGE unsigned OPENSSL_ENGINE_CMD_FLAG_INTERNAL;
static const ShortInt OPENSSL_ENGINE_CTRL_SET_LOGSTREAM = 0x1;
static const ShortInt OPENSSL_ENGINE_CTRL_SET_PASSWORD_CALLBACK = 0x2;
static const ShortInt OPENSSL_ENGINE_CTRL_HUP = 0x3;
static const ShortInt OPENSSL_ENGINE_CTRL_SET_USER_INTERFACE = 0x4;
static const ShortInt OPENSSL__CALLBACK_DATA = 0x5;
static const ShortInt OPENSSL_D_CONFIGURATION = 0x6;
static const ShortInt OPENSSL_D_SECTION = 0x7;
static const ShortInt OPENSSL_ENGINE_CTRL_HAS_CTRL_FUNCTION = 0xa;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_FIRST_CMD_TYPE = 0xb;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_NEXT_CMD_TYPE = 0xc;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_CMD_FROM_NAME = 0xd;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_NAME_LEN_FROM_CMD = 0xe;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_NAME_FROM_CMD = 0xf;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_DESC_LEN_FROM_CMD = 0x10;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_DESC_FROM_CMD = 0x11;
static const ShortInt OPENSSL_ENGINE_CTRL_GET_CMD_FLAGS = 0x12;
static const Byte OPENSSL_ENGINE_CMD_BASE = 0xc8;
static const ShortInt OPENSSL_ENGINE_CTRL_CHIL_SET_FORKCHECK = 0x64;
static const ShortInt OPENSSL_ENGINE_CTRL_CHIL_NO_LOCKING = 0x65;
extern PACKAGE unsigned OPENSSL_OSSL_DYNAMIC_VERSION;
extern PACKAGE unsigned OPENSSL_OSSL_DYNAMIC_OLDEST;
static const Byte OPENSSL_ENGINE_F_DYNAMIC_CTRL = 0xb4;
static const Byte OPENSSL_ENGINE_F_DYNAMIC_GET_DATA_CTX = 0xb5;
static const Byte OPENSSL_ENGINE_F_DYNAMIC_LOAD = 0xb6;
static const Byte OPENSSL_ENGINE_F_DYNAMIC_SET_DATA_CTX = 0xb7;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_ADD = 0x69;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_BY_ID = 0x6a;
static const Byte OPENSSL_ENGINE_F_ENGINE_CMD_IS_EXECUTABLE = 0xaa;
static const Byte OPENSSL_ENGINE_F_ENGINE_CTRL = 0x8e;
static const Byte OPENSSL_ENGINE_F_ENGINE_CTRL_CMD = 0xb2;
static const Byte OPENSSL_ENGINE_F_ENGINE_CTRL_CMD_STRING = 0xab;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_FINISH = 0x6b;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_FREE_UTIL = 0x6c;
static const Byte OPENSSL_ENGINE_F_ENGINE_GET_CIPHER = 0xb9;
static const Byte OPENSSL_ENGINE_F_ENGINE_GET_DEFAULT_TYPE = 0xb1;
static const Byte OPENSSL_ENGINE_F_ENGINE_GET_DIGEST = 0xba;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_GET_NEXT = 0x73;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_GET_PREV = 0x74;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_INIT = 0x77;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_LIST_ADD = 0x78;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_LIST_REMOVE = 0x79;
static const Byte OPENSSL_ENGINE_F_ENGINE_LOAD_PRIVATE_KEY = 0x96;
static const Byte OPENSSL_ENGINE_F_ENGINE_LOAD_PUBLIC_KEY = 0x97;
static const Byte OPENSSL_ENGINE_F_ENGINE_LOAD_SSL_CLIENT_CERT = 0xc0;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_NEW = 0x7a;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_REMOVE = 0x7b;
static const Byte OPENSSL_ENGINE_F_ENGINE_SET_DEFAULT_STRING = 0xbd;
static const ShortInt OPENSSL_ENGINE_F_ENGINE_SET_DEFAULT_TYPE = 0x7e;
static const Byte OPENSSL_ENGINE_F_ENGINE_SET_ID = 0x81;
static const Byte OPENSSL_ENGINE_F_ENGINE_SET_NAME = 0x82;
static const Byte OPENSSL_ENGINE_F_ENGINE_TABLE_REGISTER = 0xb8;
static const Byte OPENSSL_ENGINE_F_ENGINE_UNLOAD_KEY = 0x98;
static const Byte OPENSSL_ENGINE_F_ENGINE_UNLOCKED_FINISH = 0xbf;
static const Byte OPENSSL_ENGINE_F_ENGINE_UP_REF = 0xbe;
static const Byte OPENSSL_ENGINE_F_INT_CTRL_HELPER = 0xac;
static const Byte OPENSSL_ENGINE_F_INT_ENGINE_CONFIGURE = 0xbc;
static const Byte OPENSSL_ENGINE_F_INT_ENGINE_MODULE_INIT = 0xbb;
static const Byte OPENSSL_ENGINE_F_LOG_MESSAGE = 0x8d;
static const ShortInt OPENSSL_ENGINE_R_ALREADY_LOADED = 0x64;
static const Byte OPENSSL_ENGINE_R_ARGUMENT_IS_NOT_A_NUMBER = 0x85;
static const Byte OPENSSL_ENGINE_R_CMD_NOT_EXECUTABLE = 0x86;
static const Byte OPENSSL_ENGINE_R_COMMAND_TAKES_INPUT = 0x87;
static const Byte OPENSSL_ENGINE_R_COMMAND_TAKES_NO_INPUT = 0x88;
static const ShortInt OPENSSL_ENGINE_R_CONFLICTING_ENGINE_ID = 0x67;
static const ShortInt OPENSSL_ENGINE_R_CTRL_COMMAND_NOT_IMPLEMENTED = 0x77;
static const Byte OPENSSL_ENGINE_R_DH_NOT_IMPLEMENTED = 0x8b;
static const Byte OPENSSL_ENGINE_R_DSA_NOT_IMPLEMENTED = 0x8c;
static const ShortInt OPENSSL_ENGINE_R_DSO_FAILURE = 0x68;
static const Byte OPENSSL_ENGINE_R_DSO_NOT_FOUND = 0x84;
static const Byte OPENSSL_ENGINE_R_ENGINES_SECTION_ERROR = 0x94;
static const ShortInt OPENSSL_ENGINE_R_ENGINE_IS_NOT_IN_LIST = 0x69;
static const Byte OPENSSL_ENGINE_R_ENGINE_SECTION_ERROR = 0x95;
static const Byte OPENSSL_ENGINE_R_FAILED_LOADING_PRIVATE_KEY = 0x80;
static const Byte OPENSSL_ENGINE_R_FAILED_LOADING_PUBLIC_KEY = 0x81;
static const ShortInt OPENSSL_ENGINE_R_FINISH_FAILED = 0x6a;
static const ShortInt OPENSSL_ENGINE_R_GET_HANDLE_FAILED = 0x6b;
static const ShortInt OPENSSL_ENGINE_R_ID_OR_NAME_MISSING = 0x6c;
static const ShortInt OPENSSL_ENGINE_R_INIT_FAILED = 0x6d;
static const ShortInt OPENSSL_ENGINE_R_INTERNAL_LIST_ERROR = 0x6e;
static const Byte OPENSSL_ENGINE_R_INVALID_ARGUMENT = 0x8f;
static const Byte OPENSSL_ENGINE_R_INVALID_CMD_NAME = 0x89;
static const Byte OPENSSL_ENGINE_R_INVALID_CMD_NUMBER = 0x8a;
static const Byte OPENSSL_ENGINE_R_INVALID_INIT_VALUE = 0x97;
static const Byte OPENSSL_ENGINE_R_INVALID_STRING = 0x96;
static const ShortInt OPENSSL_ENGINE_R_NOT_INITIALISED = 0x75;
static const ShortInt OPENSSL_ENGINE_R_NOT_LOADED = 0x70;
static const ShortInt OPENSSL_ENGINE_R_NO_CONTROL_FUNCTION = 0x78;
static const Byte OPENSSL_ENGINE_R_NO_INDEX = 0x90;
static const ShortInt OPENSSL_ENGINE_R_NO_LOAD_FUNCTION = 0x7d;
static const Byte OPENSSL_ENGINE_R_NO_REFERENCE = 0x82;
static const ShortInt OPENSSL_ENGINE_R_NO_SUCH_ENGINE = 0x74;
static const ShortInt OPENSSL_ENGINE_R_NO_UNLOAD_FUNCTION = 0x7e;
static const ShortInt OPENSSL_ENGINE_R_PROVIDE_PARAMETERS = 0x71;
static const Byte OPENSSL_ENGINE_R_RSA_NOT_IMPLEMENTED = 0x8d;
static const Byte OPENSSL_ENGINE_R_UNIMPLEMENTED_CIPHER = 0x92;
static const Byte OPENSSL_ENGINE_R_UNIMPLEMENTED_DIGEST = 0x93;
static const Byte OPENSSL_ENGINE_R_VERSION_INCOMPATIBILITY = 0x91;
static const ShortInt OPENSSL_MSS_EXIT_FAILURE = 0x1;
static const ShortInt OPENSSL_MSS_EXIT_SUCCESS = 0x0;
static const Word OPENSSL_FILENAME_MAX = 0x400;
static const ShortInt OPENSSL_FOPEN_MAX = 0x14;
static const ShortInt OPENSSL_IDEA_BLOCK = 0x8;
static const ShortInt OPENSSL_IDEA_DECRYPT = 0x0;
static const ShortInt OPENSSL_IDEA_ENCRYPT = 0x1;
static const ShortInt OPENSSL_IDEA_KEY_LENGTH = 0x10;
static const ShortInt OPENSSL_IS_SEQUENCE = 0x0;
static const ShortInt OPENSSL_IS_SET = 0x1;
static const ShortInt OPENSSL_KRBDES_DECRYPT = 0x0;
static const ShortInt OPENSSL_KRBDES_ENCRYPT = 0x1;
static const Word OPENSSL_LH_LOAD_MULT = 0x100;
static const ShortInt OPENSSL_L_ctermid = 0x10;
static const ShortInt OPENSSL_L_cuserid = 0x9;
static const Word OPENSSL_L_tmpnam = 0x400;
static const ShortInt OPENSSL_MD2_BLOCK = 0x10;
static const ShortInt OPENSSL_MD2_DIGEST_LENGTH = 0x10;
static const ShortInt OPENSSL_MD4_CBLOCK = 0x40;
static const ShortInt OPENSSL_MD4_LBLOCK = 0x10;
static const ShortInt OPENSSL_MD4_DIGEST_LENGTH = 0x10;
static const ShortInt OPENSSL_MD5_CBLOCK = 0x40;
static const ShortInt OPENSSL_MD5_LBLOCK = 0x10;
static const ShortInt OPENSSL_MD5_DIGEST_LENGTH = 0x10;
static const ShortInt OPENSSL_SHA_LBLOCK = 0x10;
static const ShortInt OPENSSL_SHA_CBLOCK = 0x40;
static const ShortInt OPENSSL_SHA_DIGEST_LENGTH = 0x14;
static const ShortInt OPENSSL_SHA_LAST_BLOCK = 0x38;
static const ShortInt OPENSSL_SHA256_CBLOCK = 0x40;
static const ShortInt OPENSSL_SHA224_DIGEST_LENGTH = 0x1c;
static const ShortInt OPENSSL_SHA256_DIGEST_LENGTH = 0x20;
static const ShortInt OPENSSL_SHA384_DIGEST_LENGTH = 0x30;
static const ShortInt OPENSSL_SHA512_DIGEST_LENGTH = 0x40;
static const Byte OPENSSL_SHA512_CBLOCK = 0x80;
#define OPENSSL_LN_SMIMECapabilities L"S/MIME Capabilities"
#define OPENSSL_LN_X500 L"X500"
#define OPENSSL_LN_X509 L"X509"
#define OPENSSL_LN_algorithm L"algorithm"
#define OPENSSL_LN_authority_key_identifier L"X509v3 Authority Key Identifier"
#define OPENSSL_LN_basic_constraints L"X509v3 Basic Constraints"
#define OPENSSL_LN_bf_cbc L"bf-cbc"
#define OPENSSL_LN_bf_cfb64 L"bf-cfb"
#define OPENSSL_LN_bf_ecb L"bf-ecb"
#define OPENSSL_LN_bf_ofb64 L"bf-ofb"
#define OPENSSL_LN_cast5_cbc L"cast5-cbc"
#define OPENSSL_LN_cast5_cfb64 L"cast5-cfb"
#define OPENSSL_LN_cast5_ecb L"cast5-ecb"
#define OPENSSL_LN_cast5_ofb64 L"cast5-ofb"
#define OPENSSL_LN_certBag L"certBag"
#define OPENSSL_LN_certificate_policies L"X509v3 Certificate Policies"
#define OPENSSL_LN_client_auth L"TLS Web Client Authentication"
#define OPENSSL_LN_code_sign L"Code Signing"
#define OPENSSL_LN_commonName L"commonName"
#define OPENSSL_LN_countryName L"countryName"
#define OPENSSL_LN_crlBag L"crlBag"
#define OPENSSL_LN_crl_distribution_points L"X509v3 CRL Distribution Points"
#define OPENSSL_LN_crl_number L"X509v3 CRL Number"
#define OPENSSL_LN_crl_reason L"CRL Reason Code"
#define OPENSSL_LN_delta_crl L"X509v3 Delta CRL Indicator"
#define OPENSSL_LN_des_cbc L"des-cbc"
#define OPENSSL_LN_des_cfb64 L"des-cfb"
#define OPENSSL_LN_des_ecb L"des-ecb"
#define OPENSSL_LN_des_ede L"des-ede"
#define OPENSSL_LN_des_ede3 L"des-ede3"
#define OPENSSL_LN_des_ede3_cbc L"des-ede3-cbc"
#define OPENSSL_LN_des_ede3_cfb64 L"des-ede3-cfb"
#define OPENSSL_LN_des_ede3_ofb64 L"des-ede3-ofb"
#define OPENSSL_LN_des_ede_cbc L"des-ede-cbc"
#define OPENSSL_LN_des_ede_cfb64 L"des-ede-cfb"
#define OPENSSL_LN_des_ede_ofb64 L"des-ede-ofb"
#define OPENSSL_LN_des_ofb64 L"des-ofb"
#define OPENSSL_LN_description L"description"
#define OPENSSL_LN_desx_cbc L"desx-cbc"
#define OPENSSL_LN_dhKeyAgreement L"dhKeyAgreement"
#define OPENSSL_LN_dsa L"dsaEncryption"
#define OPENSSL_LN_dsaWithSHA L"dsaWithSHA"
#define OPENSSL_LN_dsaWithSHA1 L"dsaWithSHA1"
#define OPENSSL_LN_dsaWithSHA1_2 L"dsaWithSHA1-old"
#define OPENSSL_LN_dsa_2 L"dsaEncryption-old"
#define OPENSSL_LN_email_protect L"E-mail Protection"
#define OPENSSL_LN_ext_key_usage L"X509v3 Extended Key Usage"
#define OPENSSL_LN_friendlyName L"friendlyName"
#define OPENSSL_LN_givenName L"givenName"
#define OPENSSL_LN_hmacWithSHA1 L"hmacWithSHA1"
#define OPENSSL_LN_id_pbkdf2 L"PBKDF2"
#define OPENSSL_LN_id_qt_cps L"Policy Qualifier CPS"
#define OPENSSL_LN_id_qt_unotice L"Policy Qualifier User Notice"
#define OPENSSL_LN_idea_cbc L"idea-cbc"
#define OPENSSL_LN_idea_cfb64 L"idea-cfb"
#define OPENSSL_LN_idea_ecb L"idea-ecb"
#define OPENSSL_LN_idea_ofb64 L"idea-ofb"
#define OPENSSL_LN_initials L"initials"
#define OPENSSL_LN_invalidity_date L"Invalidity Date"
#define OPENSSL_LN_issuer_alt_name L"X509v3 Issuer Alternative Name"
#define OPENSSL_LN_keyBag L"keyBag"
#define OPENSSL_LN_key_usage L"X509v3 Key Usage"
#define OPENSSL_LN_localKeyID L"localKeyID"
#define OPENSSL_LN_localityName L"localityName"
#define OPENSSL_LN_md2 L"md2"
#define OPENSSL_LN_md2WithRSAEncryption L"md2WithRSAEncryption"
#define OPENSSL_LN_md4 L"md4"
#define OPENSSL_LN_md5 L"md5"
#define OPENSSL_LN_md5WithRSA L"md5WithRSA"
#define OPENSSL_LN_md5WithRSAEncryption L"md5WithRSAEncryption"
#define OPENSSL_LN_md5_sha1 L"md5-sha1"
#define OPENSSL_LN_mdc2 L"mdc2"
#define OPENSSL_LN_mdc2WithRSA L"mdc2withRSA"
#define OPENSSL_LN_ms_code_com L"Microsoft Commercial Code Signing"
#define OPENSSL_LN_ms_code_ind L"Microsoft Individual Code Signing"
#define OPENSSL_LN_ms_ctl_sign L"Microsoft Trust List Signing"
#define OPENSSL_LN_ms_efs L"Microsoft Encrypted File System"
#define OPENSSL_LN_ms_sgc L"Microsoft Server Gated Crypto"
#define OPENSSL_LN_netscape L"Netscape Communications Corp."
#define OPENSSL_LN_netscape_base_url L"Netscape Base Url"
#define OPENSSL_LN_netscape_ca_policy_url L"Netscape CA Policy Url"
#define OPENSSL_LN_netscape_ca_revocation_url L"Netscape CA Revocation Url"
#define OPENSSL_LN_netscape_cert_extension L"Netscape Certificate Extension"
#define OPENSSL_LN_netscape_cert_sequence L"Netscape Certificate Sequence"
#define OPENSSL_LN_netscape_cert_type L"Netscape Cert Type"
#define OPENSSL_LN_netscape_comment L"Netscape Comment"
#define OPENSSL_LN_netscape_data_type L"Netscape Data Type"
#define OPENSSL_LN_netscape_renewal_url L"Netscape Renewal Url"
#define OPENSSL_LN_netscape_revocation_url L"Netscape Revocation Url"
#define OPENSSL_LN_netscape_ssl_server_name L"Netscape SSL Server Name"
#define OPENSSL_LN_ns_sgc L"Netscape Server Gated Crypto"
#define OPENSSL_LN_organizationName L"organizationName"
#define OPENSSL_LN_organizationalUnitName L"organizationalUnitName"
#define OPENSSL_LN_pbeWithMD2AndDES_CBC L"pbeWithMD2AndDES-CBC"
#define OPENSSL_LN_pbeWithMD2AndRC2_CBC L"pbeWithMD2AndRC2-CBC"
#define OPENSSL_LN_pbeWithMD5AndCast5_CBC L"pbeWithMD5AndCast5CBC"
#define OPENSSL_LN_pbeWithMD5AndDES_CBC L"pbeWithMD5AndDES-CBC"
#define OPENSSL_LN_pbeWithMD5AndRC2_CBC L"pbeWithMD5AndRC2-CBC"
#define OPENSSL_LN_pbeWithSHA1AndDES_CBC L"pbeWithSHA1AndDES-CBC"
#define OPENSSL_LN_pbeWithSHA1AndRC2_CBC L"pbeWithSHA1AndRC2-CBC"
#define OPENSSL_LN_pbe_WithSHA1And128BitRC2_CBC L"pbeWithSHA1And128BitRC2-CBC"
#define OPENSSL_LN_pbe_WithSHA1And128BitRC4 L"pbeWithSHA1And128BitRC4"
#define OPENSSL_LN_pbe_WithSHA1And2_Key_TripleDES_CBC L"pbeWithSHA1And2-KeyTripleDES-CBC"
#define OPENSSL_LN_pbe_WithSHA1And3_Key_TripleDES_CBC L"pbeWithSHA1And3-KeyTripleDES-CBC"
#define OPENSSL_LN_pbe_WithSHA1And40BitRC2_CBC L"pbeWithSHA1And40BitRC2-CBC"
#define OPENSSL_LN_pbe_WithSHA1And40BitRC4 L"pbeWithSHA1And40BitRC4"
#define OPENSSL_LN_pbes2 L"PBES2"
#define OPENSSL_LN_pbmac1 L"PBMAC1"
#define OPENSSL_LN_pkcs L"pkcs"
#define OPENSSL_LN_pkcs3 L"pkcs3"
#define OPENSSL_LN_pkcs7 L"pkcs7"
#define OPENSSL_LN_pkcs7_data L"pkcs7-data"
#define OPENSSL_LN_pkcs7_digest L"pkcs7-digestData"
#define OPENSSL_LN_pkcs7_encrypted L"pkcs7-encryptedData"
#define OPENSSL_LN_pkcs7_enveloped L"pkcs7-envelopedData"
#define OPENSSL_LN_pkcs7_signed L"pkcs7-signedData"
#define OPENSSL_LN_pkcs7_signedAndEnveloped L"pkcs7-signedAndEnvelopedData"
#define OPENSSL_LN_pkcs8ShroudedKeyBag L"pkcs8ShroudedKeyBag"
#define OPENSSL_LN_pkcs9 L"pkcs9"
#define OPENSSL_LN_pkcs9_challengePassword L"challengePassword"
#define OPENSSL_LN_pkcs9_contentType L"contentType"
#define OPENSSL_LN_pkcs9_countersignature L"countersignature"
#define OPENSSL_LN_pkcs9_emailAddress L"emailAddress"
#define OPENSSL_LN_pkcs9_extCertAttributes L"extendedCertificateAttributes"
#define OPENSSL_LN_pkcs9_messageDigest L"messageDigest"
#define OPENSSL_LN_pkcs9_signingTime L"signingTime"
#define OPENSSL_LN_pkcs9_unstructuredAddress L"unstructuredAddress"
#define OPENSSL_LN_pkcs9_unstructuredName L"unstructuredName"
#define OPENSSL_LN_private_key_usage_period L"X509v3 Private Key Usage Period"
#define OPENSSL_LN_rc2_40_cbc L"rc2-40-cbc"
#define OPENSSL_LN_rc2_64_cbc L"rc2-64-cbc"
#define OPENSSL_LN_rc2_cbc L"rc2-cbc"
#define OPENSSL_LN_rc2_cfb64 L"rc2-cfb"
#define OPENSSL_LN_rc2_ecb L"rc2-ecb"
#define OPENSSL_LN_rc2_ofb64 L"rc2-ofb"
#define OPENSSL_LN_rc4 L"rc4"
#define OPENSSL_LN_rc4_40 L"rc4-40"
#define OPENSSL_LN_rc5_cbc L"rc5-cbc"
#define OPENSSL_LN_rc5_cfb64 L"rc5-cfb"
#define OPENSSL_LN_rc5_ecb L"rc5-ecb"
#define OPENSSL_LN_rc5_ofb64 L"rc5-ofb"
#define OPENSSL_LN_ripemd160 L"ripemd160"
#define OPENSSL_LN_ripemd160WithRSA L"ripemd160WithRSA"
#define OPENSSL_LN_rle_compression L"run length compression"
#define OPENSSL_LN_rsa L"rsa"
#define OPENSSL_LN_rsaEncryption L"rsaEncryption"
#define OPENSSL_LN_rsadsi L"rsadsi"
#define OPENSSL_LN_safeContentsBag L"safeContentsBag"
#define OPENSSL_LN_sdsiCertificate L"sdsiCertificate"
#define OPENSSL_LN_secretBag L"secretBag"
#define OPENSSL_LN_serialNumber L"serialNumber"
#define OPENSSL_LN_server_auth L"TLS Web Server Authentication"
#define OPENSSL_LN_sha L"sha"
#define OPENSSL_LN_sha1 L"sha1"
#define OPENSSL_LN_sha1WithRSA L"sha1WithRSA"
#define OPENSSL_LN_sha1WithRSAEncryption L"sha1WithRSAEncryption"
#define OPENSSL_LN_shaWithRSAEncryption L"shaWithRSAEncryption"
#define OPENSSL_LN_sha256WithRSAEncryption L"sha256WithRSAEncryption"
#define OPENSSL_LN_sha384WithRSAEncryption L"sha384WithRSAEncryption"
#define OPENSSL_LN_sha512WithRSAEncryption L"sha512WithRSAEncryption"
#define OPENSSL_LN_sha224WithRSAEncryption L"sha224WithRSAEncryption"
#define OPENSSL_LN_stateOrProvinceName L"stateOrProvinceName"
#define OPENSSL_LN_subject_alt_name L"X509v3 Subject Alternative Name"
#define OPENSSL_LN_subject_key_identifier L"X509v3 Subject Key Identifier"
#define OPENSSL_LN_surname L"surname"
#define OPENSSL_LN_sxnet L"Strong Extranet ID"
#define OPENSSL_LN_time_stamp L"Time Stamping"
#define OPENSSL_LN_title L"title"
#define OPENSSL_LN_undef L"undefined"
#define OPENSSL_LN_uniqueIdentifier L"uniqueIdentifier"
#define OPENSSL_LN_x509Certificate L"x509Certificate"
#define OPENSSL_LN_x509Crl L"x509Crl"
#define OPENSSL_LN_zlib_compression L"zlib compression"
static const Byte OPENSSL_NID_SMIMECapabilities = 0xa7;
static const ShortInt OPENSSL_NID_X500 = 0xb;
static const ShortInt OPENSSL_NID_X509 = 0xc;
static const ShortInt OPENSSL_NID_algorithm = 0x26;
static const ShortInt OPENSSL_NID_authority_key_identifier = 0x5a;
static const ShortInt OPENSSL_NID_basic_constraints = 0x57;
static const ShortInt OPENSSL_NID_bf_cbc = 0x5b;
static const ShortInt OPENSSL_NID_bf_cfb64 = 0x5d;
static const ShortInt OPENSSL_NID_bf_ecb = 0x5c;
static const ShortInt OPENSSL_NID_bf_ofb64 = 0x5e;
static const ShortInt OPENSSL_NID_cast5_cbc = 0x6c;
static const ShortInt OPENSSL_NID_cast5_cfb64 = 0x6e;
static const ShortInt OPENSSL_NID_cast5_ecb = 0x6d;
static const ShortInt OPENSSL_NID_cast5_ofb64 = 0x6f;
static const Byte OPENSSL_NID_certBag = 0x98;
static const ShortInt OPENSSL_NID_certificate_policies = 0x59;
static const Byte OPENSSL_NID_client_auth = 0x82;
static const Byte OPENSSL_NID_code_sign = 0x83;
static const ShortInt OPENSSL_NID_commonName = 0xd;
static const ShortInt OPENSSL_NID_countryName = 0xe;
static const Byte OPENSSL_NID_crlBag = 0x99;
static const ShortInt OPENSSL_NID_crl_distribution_points = 0x67;
static const ShortInt OPENSSL_NID_crl_number = 0x58;
static const Byte OPENSSL_NID_crl_reason = 0x8d;
static const Byte OPENSSL_NID_delta_crl = 0x8c;
static const ShortInt OPENSSL_NID_des_cbc = 0x1f;
static const ShortInt OPENSSL_NID_des_cfb64 = 0x1e;
static const ShortInt OPENSSL_NID_des_ecb = 0x1d;
static const ShortInt OPENSSL_NID_des_ede = 0x20;
static const ShortInt OPENSSL_NID_des_ede3 = 0x21;
static const ShortInt OPENSSL_NID_des_ede3_cbc = 0x2c;
static const ShortInt OPENSSL_NID_des_ede3_cfb64 = 0x3d;
static const ShortInt OPENSSL_NID_des_ede3_ofb64 = 0x3f;
static const ShortInt OPENSSL_NID_des_ede_cbc = 0x2b;
static const ShortInt OPENSSL_NID_des_ede_cfb64 = 0x3c;
static const ShortInt OPENSSL_NID_des_ede_ofb64 = 0x3e;
static const ShortInt OPENSSL_NID_des_ofb64 = 0x2d;
static const ShortInt OPENSSL_NID_description = 0x6b;
static const ShortInt OPENSSL_NID_desx_cbc = 0x50;
static const Byte OPENSSL_NID_email_protect = 0x84;
static const ShortInt OPENSSL_NID_ext_key_usage = 0x7e;
static const Byte OPENSSL_NID_friendlyName = 0x9c;
static const ShortInt OPENSSL_NID_givenName = 0x63;
static const Byte OPENSSL_NID_hmacWithSHA1 = 0xa3;
static const Byte OPENSSL_NID_id_kp = 0x80;
static const ShortInt OPENSSL_NID_id_pbkdf2 = 0x45;
static const ShortInt OPENSSL_NID_id_pkix = 0x7f;
static const Byte OPENSSL_NID_id_qt_cps = 0xa4;
static const Byte OPENSSL_NID_id_qt_unotice = 0xa5;
static const ShortInt OPENSSL_NID_idea_cbc = 0x22;
static const ShortInt OPENSSL_NID_idea_cfb64 = 0x23;
static const ShortInt OPENSSL_NID_idea_ecb = 0x24;
static const ShortInt OPENSSL_NID_idea_ofb64 = 0x2e;
static const ShortInt OPENSSL_NID_initials = 0x65;
static const Byte OPENSSL_NID_invalidity_date = 0x8e;
static const ShortInt OPENSSL_NID_issuer_alt_name = 0x56;
static const Byte OPENSSL_NID_keyBag = 0x96;
static const ShortInt OPENSSL_NID_key_usage = 0x53;
static const ShortInt OPENSSL_NID_ld_ce = 0x51;
static const Byte OPENSSL_NID_localKeyID = 0x9d;
static const ShortInt OPENSSL_NID_localityName = 0xf;
static const ShortInt OPENSSL_NID_md2 = 0x3;
static const ShortInt OPENSSL_NID_md2WithRSAEncryption = 0x7;
static const Word OPENSSL_NID_md4 = 0x101;
static const Word OPENSSL_NID_md4WithRSAEncryption = 0x18c;
static const ShortInt OPENSSL_NID_md5 = 0x4;
static const ShortInt OPENSSL_NID_md5WithRSA = 0x68;
static const ShortInt OPENSSL_NID_md5WithRSAEncryption = 0x8;
static const ShortInt OPENSSL_NID_md5_sha1 = 0x72;
static const ShortInt OPENSSL_NID_mdc2 = 0x5f;
static const ShortInt OPENSSL_NID_mdc2WithRSA = 0x60;
static const Byte OPENSSL_NID_ms_code_com = 0x87;
static const Byte OPENSSL_NID_ms_code_ind = 0x86;
static const Byte OPENSSL_NID_ms_ctl_sign = 0x88;
static const Byte OPENSSL_NID_ms_efs = 0x8a;
static const Byte OPENSSL_NID_ms_sgc = 0x89;
static const ShortInt OPENSSL_NID_netscape = 0x39;
static const ShortInt OPENSSL_NID_netscape_base_url = 0x48;
static const ShortInt OPENSSL_NID_netscape_ca_policy_url = 0x4c;
static const ShortInt OPENSSL_NID_netscape_ca_revocation_url = 0x4a;
static const ShortInt OPENSSL_NID_netscape_cert_extension = 0x3a;
static const ShortInt OPENSSL_NID_netscape_cert_sequence = 0x4f;
static const ShortInt OPENSSL_NID_netscape_cert_type = 0x47;
static const ShortInt OPENSSL_NID_netscape_comment = 0x4e;
static const ShortInt OPENSSL_NID_netscape_data_type = 0x3b;
static const ShortInt OPENSSL_NID_netscape_renewal_url = 0x4b;
static const ShortInt OPENSSL_NID_netscape_revocation_url = 0x49;
static const ShortInt OPENSSL_NID_netscape_ssl_server_name = 0x4d;
static const Byte OPENSSL_NID_ns_sgc = 0x8b;
static const ShortInt OPENSSL_NID_organizationName = 0x11;
static const ShortInt OPENSSL_NID_organizationalUnitName = 0x12;
static const ShortInt OPENSSL_NID_pbeWithMD2AndDES_CBC = 0x9;
static const Byte OPENSSL_NID_pbeWithMD2AndRC2_CBC = 0xa8;
static const ShortInt OPENSSL_NID_pbeWithMD5AndCast5_CBC = 0x70;
static const ShortInt OPENSSL_NID_pbeWithMD5AndDES_CBC = 0xa;
static const Byte OPENSSL_NID_pbeWithMD5AndRC2_CBC = 0xa9;
static const Byte OPENSSL_NID_pbeWithSHA1AndDES_CBC = 0xaa;
static const ShortInt OPENSSL_NID_pbeWithSHA1AndRC2_CBC = 0x44;
static const Byte OPENSSL_NID_pbe_WithSHA1And128BitRC2_CBC = 0x94;
static const Byte OPENSSL_NID_pbe_WithSHA1And128BitRC4 = 0x90;
static const Byte OPENSSL_NID_pbe_WithSHA1And2_Key_TripleDES_CBC = 0x93;
static const Byte OPENSSL_NID_pbe_WithSHA1And3_Key_TripleDES_CBC = 0x92;
static const Byte OPENSSL_NID_pbe_WithSHA1And40BitRC2_CBC = 0x95;
static const Byte OPENSSL_NID_pbe_WithSHA1And40BitRC4 = 0x91;
static const Byte OPENSSL_NID_pbes2 = 0xa1;
static const Byte OPENSSL_NID_pbmac1 = 0xa2;
static const ShortInt OPENSSL_NID_pkcs = 0x2;
static const ShortInt OPENSSL_NID_pkcs3 = 0x1b;
static const ShortInt OPENSSL_NID_pkcs7 = 0x14;
static const ShortInt OPENSSL_NID_pkcs7_data = 0x15;
static const ShortInt OPENSSL_NID_pkcs7_digest = 0x19;
static const ShortInt OPENSSL_NID_pkcs7_encrypted = 0x1a;
static const ShortInt OPENSSL_NID_pkcs7_enveloped = 0x17;
static const ShortInt OPENSSL_NID_pkcs7_signed = 0x16;
static const ShortInt OPENSSL_NID_pkcs7_signedAndEnveloped = 0x18;
static const Byte OPENSSL_NID_pkcs8ShroudedKeyBag = 0x97;
static const ShortInt OPENSSL_NID_pkcs9 = 0x2f;
static const ShortInt OPENSSL_NID_pkcs9_challengePassword = 0x36;
static const ShortInt OPENSSL_NID_pkcs9_contentType = 0x32;
static const ShortInt OPENSSL_NID_pkcs9_countersignature = 0x35;
static const ShortInt OPENSSL_NID_pkcs9_emailAddress = 0x30;
static const ShortInt OPENSSL_NID_pkcs9_extCertAttributes = 0x38;
static const ShortInt OPENSSL_NID_pkcs9_messageDigest = 0x33;
static const ShortInt OPENSSL_NID_pkcs9_signingTime = 0x34;
static const ShortInt OPENSSL_NID_pkcs9_unstructuredAddress = 0x37;
static const ShortInt OPENSSL_NID_pkcs9_unstructuredName = 0x31;
static const ShortInt OPENSSL_NID_private_key_usage_period = 0x54;
static const ShortInt OPENSSL_NID_rc2_40_cbc = 0x62;
static const Byte OPENSSL_NID_rc2_64_cbc = 0xa6;
static const ShortInt OPENSSL_NID_rc2_cbc = 0x25;
static const ShortInt OPENSSL_NID_rc2_cfb64 = 0x27;
static const ShortInt OPENSSL_NID_rc2_ecb = 0x26;
static const ShortInt OPENSSL_NID_rc2_ofb64 = 0x28;
static const ShortInt OPENSSL_NID_rc4 = 0x5;
static const ShortInt OPENSSL_NID_rc4_40 = 0x61;
static const ShortInt OPENSSL_NID_rc5_cbc = 0x78;
static const ShortInt OPENSSL_NID_rc5_cfb64 = 0x7a;
static const ShortInt OPENSSL_NID_rc5_ecb = 0x79;
static const ShortInt OPENSSL_NID_rc5_ofb64 = 0x7b;
static const ShortInt OPENSSL_NID_ripemd160 = 0x75;
static const ShortInt OPENSSL_NID_ripemd160WithRSA = 0x77;
static const ShortInt OPENSSL_NID_rle_compression = 0x7c;
static const ShortInt OPENSSL_NID_rsadsi = 0x1;
static const Byte OPENSSL_NID_safeContentsBag = 0x9b;
static const Byte OPENSSL_NID_sdsiCertificate = 0x9f;
static const Byte OPENSSL_NID_secretBag = 0x9a;
static const ShortInt OPENSSL_NID_serialNumber = 0x69;
static const Byte OPENSSL_NID_server_auth = 0x81;
static const ShortInt OPENSSL_NID_sha = 0x29;
static const ShortInt OPENSSL_NID_sha1 = 0x40;
static const ShortInt OPENSSL_NID_sha1WithRSA = 0x73;
static const ShortInt OPENSSL_NID_sha1WithRSAEncryption = 0x41;
static const Word OPENSSL_NID_sha256WithRSAEncryption = 0x29c;
static const Word OPENSSL_NID_sha384WithRSAEncryption = 0x29d;
static const Word OPENSSL_NID_sha512WithRSAEncryption = 0x29e;
static const Word OPENSSL_NID_sha224WithRSAEncryption = 0x29f;
static const ShortInt OPENSSL_NID_shaWithRSAEncryption = 0x2a;
static const ShortInt OPENSSL_NID_stateOrProvinceName = 0x10;
static const ShortInt OPENSSL_NID_subject_alt_name = 0x55;
static const ShortInt OPENSSL_NID_subject_key_identifier = 0x52;
static const ShortInt OPENSSL_NID_surname = 0x64;
static const Byte OPENSSL_NID_sxnet = 0x8f;
static const Byte OPENSSL_NID_time_stamp = 0x85;
static const ShortInt OPENSSL_NID_title = 0x6a;
static const ShortInt OPENSSL_NID_uniqueIdentifier = 0x66;
static const Byte OPENSSL_NID_x509Certificate = 0x9e;
static const Byte OPENSSL_NID_x509Crl = 0xa0;
static const ShortInt OPENSSL_NID_zlib_compression = 0x7d;
static const ShortInt OPENSSL_OBJ_F_OBJ_CREATE = 0x64;
static const ShortInt OPENSSL_OBJ_F_OBJ_DUP = 0x65;
static const ShortInt OPENSSL_OBJ_F_OBJ_NID2LN = 0x66;
static const ShortInt OPENSSL_OBJ_F_OBJ_NID2OBJ = 0x67;
static const ShortInt OPENSSL_OBJ_F_OBJ_NID2SN = 0x68;
static const Word OPENSSL_OBJ_NAME_ALIAS = 0x8000;
static const ShortInt OPENSSL_OBJ_NAME_TYPE_CIPHER_METH = 0x2;
static const ShortInt OPENSSL_OBJ_NAME_TYPE_COMP_METH = 0x4;
static const ShortInt OPENSSL_OBJ_NAME_TYPE_MD_METH = 0x1;
static const ShortInt OPENSSL_OBJ_NAME_TYPE_NUM = 0x5;
static const ShortInt OPENSSL_OBJ_NAME_TYPE_PKEY_METH = 0x3;
static const ShortInt OPENSSL_OBJ_NAME_TYPE_UNDEF = 0x0;
static const ShortInt OPENSSL_OBJ_R_MALLOC_FAILURE = 0x64;
static const ShortInt OPENSSL_OBJ_R_UNKNOWN_NID = 0x65;
static const int OPENSSL_OPENSSL_VERSION_NUMBER = 0x9080af;
#define OPENSSL_OPENSSL_VERSION_TEXT L"OpenSSL 0.9.8j 07 Jan 2009"
static const Word OPENSSL_PEM_BUFSIZE = 0x400;
static const ShortInt OPENSSL_PEM_DEK_DES_CBC = 0x28;
static const ShortInt OPENSSL_PEM_DEK_DES_ECB = 0x3c;
static const ShortInt OPENSSL_PEM_DEK_DES_EDE = 0x32;
static const ShortInt OPENSSL_PEM_DEK_IDEA_CBC = 0x2d;
static const ShortInt OPENSSL_PEM_DEK_RSA = 0x46;
static const ShortInt OPENSSL_PEM_DEK_RSA_MD2 = 0x50;
static const ShortInt OPENSSL_PEM_DEK_RSA_MD5 = 0x5a;
static const ShortInt OPENSSL_PEM_ERROR = 0x1e;
static const ShortInt OPENSSL_PEM_F_DEF_CALLBACK = 0x64;
static const ShortInt OPENSSL_PEM_F_LOAD_IV = 0x65;
static const ShortInt OPENSSL_PEM_F_PEM_ASN1_READ = 0x66;
static const ShortInt OPENSSL_PEM_F_PEM_ASN1_READ_BIO = 0x67;
static const ShortInt OPENSSL_PEM_F_PEM_ASN1_WRITE = 0x68;
static const ShortInt OPENSSL_PEM_F_PEM_ASN1_WRITE_BIO = 0x69;
static const ShortInt OPENSSL_PEM_F_PEM_DO_HEADER = 0x6a;
static const ShortInt OPENSSL_PEM_F_PEM_F_PEM_WRITE_PKCS8PRIVATEKEY = 0x76;
static const ShortInt OPENSSL_PEM_F_PEM_GET_EVP_CIPHER_INFO = 0x6b;
static const ShortInt OPENSSL_PEM_F_PEM_READ = 0x6c;
static const ShortInt OPENSSL_PEM_F_PEM_READ_BIO = 0x6d;
static const ShortInt OPENSSL_PEM_F_PEM_SEALFINAL = 0x6e;
static const ShortInt OPENSSL_PEM_F_PEM_SEALINIT = 0x6f;
static const ShortInt OPENSSL_PEM_F_PEM_SIGNFINAL = 0x70;
static const ShortInt OPENSSL_PEM_F_PEM_WRITE = 0x71;
static const ShortInt OPENSSL_PEM_F_PEM_WRITE_BIO = 0x72;
static const ShortInt OPENSSL_PEM_F_PEM_WRITE_BIO_PKCS8PRIVATEKEY = 0x77;
static const ShortInt OPENSSL_PEM_F_PEM_X509_INFO_READ = 0x73;
static const ShortInt OPENSSL_PEM_F_PEM_X509_INFO_READ_BIO = 0x74;
static const ShortInt OPENSSL_PEM_F_PEM_X509_INFO_WRITE_BIO = 0x75;
static const ShortInt OPENSSL_PEM_MD_MD2 = 0x3;
static const ShortInt OPENSSL_PEM_MD_MD2_RSA = 0x7;
static const ShortInt OPENSSL_PEM_MD_MD5 = 0x4;
static const ShortInt OPENSSL_PEM_MD_MD5_RSA = 0x8;
static const ShortInt OPENSSL_PEM_MD_SHA = 0x29;
static const ShortInt OPENSSL_PEM_MD_SHA_RSA = 0x41;
static const ShortInt OPENSSL_PEM_OBJ_UNDEF = 0x0;
static const ShortInt OPENSSL_PEM_OBJ_X509 = 0x1;
static const ShortInt OPENSSL_PEM_OBJ_X509_REQ = 0x2;
static const ShortInt OPENSSL_PEM_OBJ_CRL = 0x3;
static const ShortInt OPENSSL_PEM_OBJ_SSL_SESSION = 0x4;
static const ShortInt OPENSSL_PEM_OBJ_PRIV_KEY = 0xa;
static const ShortInt OPENSSL_PEM_OBJ_PRIV_RSA = 0xb;
static const ShortInt OPENSSL_PEM_OBJ_PRIV_DSA = 0xc;
static const ShortInt OPENSSL_PEM_OBJ_PRIV_DH = 0xd;
static const ShortInt OPENSSL_PEM_OBJ_PUB_RSA = 0xe;
static const ShortInt OPENSSL_PEM_OBJ_PUB_DSA = 0xf;
static const ShortInt OPENSSL_PEM_OBJ_PUB_DH = 0x10;
static const ShortInt OPENSSL_PEM_OBJ_DHPARAMS = 0x11;
static const ShortInt OPENSSL_PEM_OBJ_DSAPARAMS = 0x12;
static const ShortInt OPENSSL_PEM_OBJ_PRIV_RSA_PUBLIC = 0x13;
static const ShortInt OPENSSL_PEM_OBJ_PRIV_ECDSA = 0x14;
static const ShortInt OPENSSL_PEM_OBJ_PUB_ECDSA = 0x15;
static const ShortInt OPENSSL_PEM_OBJ_ECPARAMETERS = 0x16;
static const ShortInt OPENSSL_PEM_R_BAD_BASE64_DECODE = 0x64;
static const ShortInt OPENSSL_PEM_R_BAD_DECRYPT = 0x65;
static const ShortInt OPENSSL_PEM_R_BAD_END_LINE = 0x66;
static const ShortInt OPENSSL_PEM_R_BAD_IV_CHARS = 0x67;
static const ShortInt OPENSSL_PEM_R_BAD_PASSWORD_READ = 0x68;
static const ShortInt OPENSSL_PEM_R_ERROR_CONVERTING_PRIVATE_KEY = 0x73;
static const ShortInt OPENSSL_PEM_R_NOT_DEK_INFO = 0x69;
static const ShortInt OPENSSL_PEM_R_NOT_ENCRYPTED = 0x6a;
static const ShortInt OPENSSL_PEM_R_NOT_PROC_TYPE = 0x6b;
static const ShortInt OPENSSL_PEM_R_NO_START_LINE = 0x6c;
static const ShortInt OPENSSL_PEM_R_PROBLEMS_GETTING_PASSWORD = 0x6d;
static const ShortInt OPENSSL_PEM_R_PUBLIC_KEY_NO_RSA = 0x6e;
static const ShortInt OPENSSL_PEM_R_READ_KEY = 0x6f;
static const ShortInt OPENSSL_PEM_R_SHORT_HEADER = 0x70;
static const ShortInt OPENSSL_PEM_R_UNSUPPORTED_CIPHER = 0x71;
static const ShortInt OPENSSL_PEM_R_UNSUPPORTED_ENCRYPTION = 0x72;
#define OPENSSL_PEM_STRING_EVP_PKEY L"ANY PRIVATE KEY"
#define OPENSSL_PEM_STRING_X509_OLD L"X509 CERTIFICATE"
#define OPENSSL_PEM_STRING_X509 L"CERTIFICATE"
#define OPENSSL_PEM_STRING_X509_PAIR L"CERTIFICATE PAIR"
#define OPENSSL_PEM_STRING_X509_TRUSTED L"TRUSTED CERTIFICATE"
#define OPENSSL_PEM_STRING_X509_REQ_OLD L"NEW CERTIFICATE REQUEST"
#define OPENSSL_PEM_STRING_X509_REQ L"CERTIFICATE REQUEST"
#define OPENSSL_PEM_STRING_X509_CRL L"X509 CRL"
#define OPENSSL_PEM_STRING_PUBLIC L"PUBLIC KEY"
#define OPENSSL_PEM_STRING_RSA L"RSA PRIVATE KEY"
#define OPENSSL_PEM_STRING_RSA_PUBLIC L"RSA PUBLIC KEY"
#define OPENSSL_PEM_STRING_DSA L"DSA PRIVATE KEY"
#define OPENSSL_PEM_STRING_DSA_PUBLIC L"DSA PUBLIC KEY"
#define OPENSSL_PEM_STRING_PKCS7 L"PKCS7"
#define OPENSSL_PEM_STRING_PKCS7_SIGNED L"PKCS #7 SIGNED DATA"
#define OPENSSL_PEM_STRING_PKCS8 L"ENCRYPTED PRIVATE KEY"
#define OPENSSL_PEM_STRING_PKCS8INF L"PRIVATE KEY"
#define OPENSSL_PEM_STRING_DHPARAMS L"DH PARAMETERS"
#define OPENSSL_PEM_STRING_SSL_SESSION L"SSL SESSION PARAMETERS"
#define OPENSSL_PEM_STRING_DSAPARAMS L"DSA PARAMETERS"
#define OPENSSL_PEM_STRING_ECDSA_PUBLIC L"ECDSA PUBLIC KEY"
#define OPENSSL_PEM_STRING_ECPARAMETERS L"EC PARAMETERS"
#define OPENSSL_PEM_STRING_ECPRIVATEKEY L"EC PRIVATE KEY"
#define OPENSSL_PEM_STRING_CMS L"CMS"
static const ShortInt OPENSSL_PEM_TYPE_CLEAR = 0x28;
static const ShortInt OPENSSL_PEM_TYPE_ENCRYPTED = 0xa;
static const ShortInt OPENSSL_PEM_TYPE_MIC_CLEAR = 0x1e;
static const ShortInt OPENSSL_PEM_TYPE_MIC_ONLY = 0x14;
static const Word OPENSSL_PKCS5_DEFAULT_ITER = 0x800;
static const ShortInt OPENSSL_PKCS5_SALT_LEN = 0x8;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_ADD_CERTIFICATE = 0x64;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_ADD_CRL = 0x65;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_ADD_RECIPIENT_INFO = 0x66;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_ADD_SIGNER = 0x67;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_CTRL = 0x68;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_DATADECODE = 0x70;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_DATAINIT = 0x69;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_DATASIGN = 0x6a;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_DATAVERIFY = 0x6b;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_SET_CIPHER = 0x6c;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_SET_CONTENT = 0x6d;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_SET_TYPE = 0x6e;
static const ShortInt OPENSSL_PKCS7_F_PKCS7_SIGNATUREVERIFY = 0x71;
static const ShortInt OPENSSL_PKCS7_OP_GET_DETACHED_SIGNATURE = 0x2;
static const ShortInt OPENSSL_PKCS7_OP_SET_DETACHED_SIGNATURE = 0x1;
static const ShortInt OPENSSL_PKCS7_R_CIPHER_NOT_INITIALIZED = 0x74;
static const ShortInt OPENSSL_PKCS7_R_DECRYPTED_KEY_IS_WRONG_LENGTH = 0x64;
static const ShortInt OPENSSL_PKCS7_R_DIGEST_FAILURE = 0x65;
static const ShortInt OPENSSL_PKCS7_R_INTERNAL_ERROR = 0x66;
static const ShortInt OPENSSL_PKCS7_R_MISSING_CERIPEND_INFO = 0x67;
static const ShortInt OPENSSL_PKCS7_R_NO_RECIPIENT_MATCHES_CERTIFICATE = 0x73;
static const ShortInt OPENSSL_PKCS7_R_OPERATION_NOT_SUPPORTED_ON_THIS_TYPE = 0x68;
static const ShortInt OPENSSL_PKCS7_R_SIGNATURE_FAILURE = 0x69;
static const ShortInt OPENSSL_PKCS7_R_UNABLE_TO_FIND_CERTIFICATE = 0x6a;
static const ShortInt OPENSSL_PKCS7_R_UNABLE_TO_FIND_MEM_BIO = 0x6b;
static const ShortInt OPENSSL_PKCS7_R_UNABLE_TO_FIND_MESSAGE_DIGEST = 0x6c;
static const ShortInt OPENSSL_PKCS7_R_UNKNOWN_DIGEST_TYPE = 0x6d;
static const ShortInt OPENSSL_PKCS7_R_UNKNOWN_OPERATION = 0x6e;
static const ShortInt OPENSSL_PKCS7_R_UNSUPPORTED_CIPHER_TYPE = 0x6f;
static const ShortInt OPENSSL_PKCS7_R_UNSUPPORTED_CONTENT_TYPE = 0x70;
static const ShortInt OPENSSL_PKCS7_R_WRONG_CONTENT_TYPE = 0x71;
static const ShortInt OPENSSL_PKCS7_R_WRONG_PKCS7_TYPE = 0x72;
static const ShortInt OPENSSL_PKCS7_S_BODY = 0x1;
static const ShortInt OPENSSL_PKCS7_S_HEADER = 0x0;
static const ShortInt OPENSSL_PKCS7_S_TAIL = 0x2;
static const ShortInt OPENSSL_PKCS8_NS_DB = 0x3;
static const ShortInt OPENSSL_PKCS8_EMBEDDED_PARAM = 0x2;
static const ShortInt OPENSSL_PKCS8_NO_OCTET = 0x1;
static const ShortInt OPENSSL_PKCS8_OK = 0x0;
#define OPENSSL_P_tmpdir L"/tmp"
static const int OPENSSL_MSS_RAND_MAX = 0x7fffffff;
static const ShortInt OPENSSL_RC2_BLOCK = 0x8;
static const ShortInt OPENSSL_RC2_DECRYPT = 0x0;
static const ShortInt OPENSSL_RC2_ENCRYPT = 0x1;
static const ShortInt OPENSSL_RC2_KEY_LENGTH = 0x10;
static const Byte OPENSSL_HMAC_MAX_MD_CBLOCK = 0x80;
static const ShortInt OPENSSL_RIPEMD160_BLOCK = 0x10;
static const ShortInt OPENSSL_RIPEMD160_CBLOCK = 0x40;
static const ShortInt OPENSSL_RIPEMD160_DIGEST_LENGTH = 0x14;
static const ShortInt OPENSSL_RIPEMD160_LAST_BLOCK = 0x38;
static const ShortInt OPENSSL_RIPEMD160_LBLOCK = 0x10;
static const ShortInt OPENSSL_RIPEMD160_LENGTH_BLOCK = 0x8;
static const Word OPENSSL_RSA_FLAG_FIPS_METHOD = 0x400;
static const Word OPENSSL_RSA_FLAG_NON_FIPS_ALLOW = 0x400;
static const ShortInt OPENSSL_RSA_3 = 0x3;
static const int OPENSSL_RSA_F4 = 0x10001;
static const ShortInt OPENSSL_RSA_FLAG_BLINDING = 0x8;
static const ShortInt OPENSSL_RSA_FLAG_CACHE_PRIVATE = 0x4;
static const ShortInt OPENSSL_RSA_FLAG_CACHE_PUBLIC = 0x2;
static const ShortInt OPENSSL_RSA_FLAG_EXT_PKEY = 0x20;
static const ShortInt OPENSSL_RSA_FLAG_SIGN_VER = 0x40;
static const Byte OPENSSL_RSA_FLAG_NO_BLINDING = 0x80;
static const Word OPENSSL_RSA_FLAG_NO_CONSTTIME = 0x100;
static const Word OPENSSL_RSA_FLAG_NO_EXP_CONSTTIME = 0x100;
static const Word OPENSSL_RSA_MAX_MODULUS_BITS = 0x4000;
static const Word OPENSSL_RSA_FIPS_MIN_MODULUS_BITS = 0x400;
static const Word OPENSSL_RSA_SMALL_MODULUS_BITS = 0xc00;
static const ShortInt OPENSSL_RSA_MAX_PUBEXP_BITS = 0x40;
static const ShortInt OPENSSL_RSA_FLAG_THREAD_SAFE = 0x10;
static const Byte OPENSSL_RSA_F_FIPS_RSA_SIGN = 0x8c;
static const Byte OPENSSL_RSA_F_FIPS_RSA_VERIFY = 0x8d;
static const ShortInt OPENSSL_RSA_F_MEMORY_LOCK = 0x64;
static const ShortInt OPENSSL_RSA_F_RSA_CHECK_KEY = 0x7b;
static const ShortInt OPENSSL_RSA_F_RSA_EAY_PRIVATE_DECRYPT = 0x65;
static const ShortInt OPENSSL_RSA_F_RSA_EAY_PRIVATE_ENCRYPT = 0x66;
static const ShortInt OPENSSL_RSA_F_RSA_EAY_PUBLIC_DECRYPT = 0x67;
static const ShortInt OPENSSL_RSA_F_RSA_EAY_PUBLIC_ENCRYPT = 0x68;
static const ShortInt OPENSSL_RSA_F_RSA_GENERATE_KEY = 0x69;
static const ShortInt OPENSSL_RSA_F_RSA_NEW_METHOD = 0x6a;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_ADD_NONE = 0x6b;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_ADD_PKCS1_OAEP = 0x79;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_ADD_PKCS1_TYPE_1 = 0x6c;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_ADD_PKCS1_TYPE_2 = 0x6d;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_ADD_SSLV23 = 0x6e;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_CHECK_NONE = 0x6f;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_CHECK_PKCS1_OAEP = 0x7a;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_1 = 0x70;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_2 = 0x71;
static const ShortInt OPENSSL_RSA_F_RSA_PADDING_CHECK_SSLV23 = 0x72;
static const ShortInt OPENSSL_RSA_F_RSA_PRINT = 0x73;
static const ShortInt OPENSSL_RSA_F_RSA_PRINT_FP = 0x74;
static const Byte OPENSSL_RSA_F_RSA_PRIVATE_ENCRYPT = 0x89;
static const Byte OPENSSL_RSA_F_RSA_PUBLIC_DECRYPT = 0x8a;
static const Byte OPENSSL_RSA_F_RSA_SETUP_BLINDING = 0x88;
static const Byte OPENSSL_RSA_F_RSA_SET_DEFAULT_METHOD = 0x8b;
static const Byte OPENSSL_RSA_F_RSA_SET_METHOD = 0x8e;
static const ShortInt OPENSSL_RSA_F_RSA_SIGN = 0x75;
static const ShortInt OPENSSL_RSA_F_RSA_SIGN_ASN1_OCTET_STRING = 0x76;
static const ShortInt OPENSSL_RSA_F_RSA_VERIFY = 0x77;
static const ShortInt OPENSSL_RSA_F_RSA_VERIFY_ASN1_OCTET_STRING = 0x78;
static const ShortInt OPENSSL_RSA_F_RSA_VERIFY_PKCS1_PSS = 0x7e;
static const ShortInt OPENSSL_RSA_METHOD_FLAG_NO_CHECK = 0x1;
static const ShortInt OPENSSL_RSA_NO_PADDING = 0x3;
static const ShortInt OPENSSL_RSA_PKCS1_OAEP_PADDING = 0x4;
static const ShortInt OPENSSL_RSA_PKCS1_PADDING = 0x1;
static const ShortInt OPENSSL_RSA_R_ALGORITHM_MISMATCH = 0x64;
static const ShortInt OPENSSL_RSA_R_BAD_E_VALUE = 0x65;
static const ShortInt OPENSSL_RSA_R_BAD_FIXED_HEADER_DECRYPT = 0x66;
static const ShortInt OPENSSL_RSA_R_BAD_PAD_BYTE_COUNT = 0x67;
static const ShortInt OPENSSL_RSA_R_BAD_SIGNATURE = 0x68;
static const ShortInt OPENSSL_RSA_R_BLOCK_TYPE_IS_NOT_01 = 0x6a;
static const ShortInt OPENSSL_RSA_R_BLOCK_TYPE_IS_NOT_02 = 0x6b;
static const ShortInt OPENSSL_RSA_R_DATA_GREATER_THAN_MOD_LEN = 0x6c;
static const ShortInt OPENSSL_RSA_R_DATA_TOO_LARGE = 0x6d;
static const ShortInt OPENSSL_RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE = 0x6e;
static const ShortInt OPENSSL_RSA_R_DATA_TOO_SMALL = 0x6f;
static const ShortInt OPENSSL_RSA_R_DATA_TOO_SMALL_FOR_KEY_SIZE = 0x7a;
static const ShortInt OPENSSL_RSA_R_DIGEST_TOO_BIG_FOR_RSA_KEY = 0x70;
static const ShortInt OPENSSL_RSA_R_DMP1_NOT_CONGRUENT_TO_D = 0x7c;
static const ShortInt OPENSSL_RSA_R_DMQ1_NOT_CONGRUENT_TO_D = 0x7d;
static const ShortInt OPENSSL_RSA_R_D_E_NOT_CONGRUENT_TO_1 = 0x7b;
static const ShortInt OPENSSL_RSA_R_IQMP_NOT_INVERSE_OF_Q = 0x7e;
static const ShortInt OPENSSL_RSA_R_KEY_SIZE_TOO_SMALL = 0x78;
static const Byte OPENSSL_RSA_R_LAST_OCTET_INVALID = 0x86;
static const ShortInt OPENSSL_RSA_R_MODULUS_TOO_LARGE = 0x69;
static const Byte OPENSSL_RSA_R_NON_FIPS_METHOD = 0x8d;
static const Byte OPENSSL_RSA_R_NO_PUBLIC_EXPONENT = 0x8c;
static const ShortInt OPENSSL_RSA_R_NULL_BEFORE_BLOCK_MISSING = 0x71;
static const ShortInt OPENSSL_RSA_R_N_DOES_NOT_EQUAL_P_Q = 0x7f;
static const ShortInt OPENSSL_RSA_R_OAEP_DECODING_ERROR = 0x79;
static const Byte OPENSSL_RSA_R_OPERATION_NOT_ALLOWED_IN_FIPS_MODE = 0x8e;
static const ShortInt OPENSSL_RSA_R_PADDING_CHECK_FAILED = 0x72;
static const Byte OPENSSL_RSA_R_P_NOT_PRIME = 0x80;
static const Byte OPENSSL_RSA_R_Q_NOT_PRIME = 0x81;
static const Byte OPENSSL_RSA_R_SLEN_CHECK_FAILED = 0x88;
static const Byte OPENSSL_RSA_R_SLEN_RECOVERY_FAILED = 0x87;
static const ShortInt OPENSSL_RSA_R_SSLV3_ROLLBACK_ATTACK = 0x73;
static const ShortInt OPENSSL_RSA_R_THE_ASN1_OBJECT_IDENTIFIER_IS_NOT_KNOWN_FOR_THIS_MD = 0x74;
static const ShortInt OPENSSL_RSA_R_UNKNOWN_ALGORITHM_TYPE = 0x75;
static const ShortInt OPENSSL_RSA_R_UNKNOWN_PADDING_TYPE = 0x76;
static const ShortInt OPENSSL_RSA_R_WRONG_SIGNATURE_LENGTH = 0x77;
static const ShortInt OPENSSL_RSA_SSLV23_PADDING = 0x2;
static const ShortInt OPENSSL_SEEK_CUR = 0x1;
static const ShortInt OPENSSL_SEEK_END = 0x2;
static const ShortInt OPENSSL_SEEK_SET = 0x0;
#define OPENSSL_SN_Algorithm L"Algorithm"
#define OPENSSL_SN_SMIMECapabilities L"SMIME-CAPS"
#define OPENSSL_SN_authority_key_identifier L"authorityKeyIdentifier"
#define OPENSSL_SN_basic_constraints L"basicConstraints"
#define OPENSSL_SN_bf_cbc L"BF-CBC"
#define OPENSSL_SN_bf_cfb64 L"BF-CFB"
#define OPENSSL_SN_bf_ecb L"BF-ECB"
#define OPENSSL_SN_bf_ofb64 L"BF-OFB"
#define OPENSSL_SN_cast5_cbc L"CAST5-CBC"
#define OPENSSL_SN_cast5_cfb64 L"CAST5-CFB"
#define OPENSSL_SN_cast5_ecb L"CAST5-ECB"
#define OPENSSL_SN_cast5_ofb64 L"CAST5-OFB"
#define OPENSSL_SN_certificate_policies L"certificatePolicies"
#define OPENSSL_SN_client_auth L"clientAuth"
#define OPENSSL_SN_code_sign L"codeSigning"
#define OPENSSL_SN_commonName L"CN"
static const WideChar OPENSSL_SN_countryName = (WideChar)(0x43);
#define OPENSSL_SN_crl_distribution_points L"crlDistributionPoints"
#define OPENSSL_SN_crl_number L"crlNumber"
#define OPENSSL_SN_crl_reason L"CRLReason"
#define OPENSSL_SN_delta_crl L"deltaCRL"
#define OPENSSL_SN_des_cbc L"DES-CBC"
#define OPENSSL_SN_des_cfb64 L"DES-CFB"
#define OPENSSL_SN_des_ecb L"DES-ECB"
#define OPENSSL_SN_des_ede L"DES-EDE"
#define OPENSSL_SN_des_ede3 L"DES-EDE3"
#define OPENSSL_SN_des_ede3_cbc L"DES-EDE3-CBC"
#define OPENSSL_SN_des_ede3_cfb64 L"DES-EDE3-CFB"
#define OPENSSL_SN_des_ede3_ofb64 L"DES-EDE3-OFB"
#define OPENSSL_SN_des_ede_cbc L"DES-EDE-CBC"
#define OPENSSL_SN_des_ede_cfb64 L"DES-EDE-CFB"
#define OPENSSL_SN_des_ede_ofb64 L"DES-EDE-OFB"
#define OPENSSL_SN_des_ofb64 L"DES-OFB"
static const WideChar OPENSSL_SN_description = (WideChar)(0x44);
#define OPENSSL_SN_desx_cbc L"DESX-CBC"
#define OPENSSL_SN_dsa L"DSA"
#define OPENSSL_SN_dsaWithSHA L"DSA-SHA"
#define OPENSSL_SN_dsaWithSHA1 L"DSA-SHA1"
#define OPENSSL_SN_dsaWithSHA1_2 L"DSA-SHA1-old"
#define OPENSSL_SN_dsa_2 L"DSA-old"
#define OPENSSL_SN_email_protect L"emailProtection"
#define OPENSSL_SN_ext_key_usage L"extendedKeyUsage"
static const WideChar OPENSSL_SN_givenName = (WideChar)(0x47);
#define OPENSSL_SN_id_kp L"id-kp"
#define OPENSSL_SN_id_pkix L"PKIX"
#define OPENSSL_SN_id_qt_cps L"id-qt-cps"
#define OPENSSL_SN_id_qt_unotice L"id-qt-unotice"
#define OPENSSL_SN_idea_cbc L"IDEA-CBC"
#define OPENSSL_SN_idea_cfb64 L"IDEA-CFB"
#define OPENSSL_SN_idea_ecb L"IDEA-ECB"
#define OPENSSL_SN_idea_ofb64 L"IDEA-OFB"
#define OPENSSL_SN_identified_organization L"identified-organization"
static const WideChar OPENSSL_SN_initials = (WideChar)(0x49);
#define OPENSSL_SN_invalidity_date L"invalidityDate"
#define OPENSSL_SN_iso L"ISO"
#define OPENSSL_SN_issuer_alt_name L"issuerAltName"
#define OPENSSL_SN_itu_t L"ITU-T"
#define OPENSSL_SN_joint_iso_itu_t L"JOINT-ISO-ITU-T"
#define OPENSSL_SN_key_usage L"keyUsage"
#define OPENSSL_SN_ld_ce L"ld-ce"
static const WideChar OPENSSL_SN_localityName = (WideChar)(0x4c);
#define OPENSSL_SN_md2 L"MD2"
#define OPENSSL_SN_md2WithRSAEncryption L"RSA-MD2"
#define OPENSSL_SN_md5 L"MD5"
#define OPENSSL_SN_md5WithRSA L"RSA-NP-MD5"
#define OPENSSL_SN_md5WithRSAEncryption L"RSA-MD5"
#define OPENSSL_SN_md5_sha1 L"MD5-SHA1"
#define OPENSSL_SN_mdc2 L"MDC2"
#define OPENSSL_SN_mdc2WithRSA L"RSA-MDC2"
#define OPENSSL_SN_member_body L"member-body"
#define OPENSSL_SN_ms_code_com L"msCodeCom"
#define OPENSSL_SN_ms_code_ind L"msCodeInd"
#define OPENSSL_SN_ms_ctl_sign L"msCTLSign"
#define OPENSSL_SN_ms_efs L"msEFS"
#define OPENSSL_SN_ms_sgc L"msSGC"
#define OPENSSL_SN_netscape L"Netscape"
#define OPENSSL_SN_netscape_base_url L"nsBaseUrl"
#define OPENSSL_SN_netscape_ca_policy_url L"nsCaPolicyUrl"
#define OPENSSL_SN_netscape_ca_revocation_url L"nsCaRevocationUrl"
#define OPENSSL_SN_netscape_cert_extension L"nsCertExt"
#define OPENSSL_SN_netscape_cert_sequence L"nsCertSequence"
#define OPENSSL_SN_netscape_cert_type L"nsCertType"
#define OPENSSL_SN_netscape_comment L"nsComment"
#define OPENSSL_SN_netscape_data_type L"nsDataType"
#define OPENSSL_SN_netscape_renewal_url L"nsRenewalUrl"
#define OPENSSL_SN_netscape_revocation_url L"nsRevocationUrl"
#define OPENSSL_SN_netscape_ssl_server_name L"nsSslServerName"
#define OPENSSL_SN_ns_sgc L"nsSGC"
static const WideChar OPENSSL_SN_organizationName = (WideChar)(0x4f);
#define OPENSSL_SN_organizationalUnitName L"OU"
#define OPENSSL_SN_pkcs9_emailAddress L"Email"
#define OPENSSL_SN_private_key_usage_period L"privateKeyUsagePeriod"
#define OPENSSL_SN_rc2_40_cbc L"RC2-40-CBC"
#define OPENSSL_SN_rc2_64_cbc L"RC2-64-CBC"
#define OPENSSL_SN_rc2_cbc L"RC2-CBC"
#define OPENSSL_SN_rc2_cfb64 L"RC2-CFB"
#define OPENSSL_SN_rc2_ecb L"RC2-ECB"
#define OPENSSL_SN_rc2_ofb64 L"RC2-OFB"
#define OPENSSL_SN_rc4 L"RC4"
#define OPENSSL_SN_rc4_40 L"RC4-40"
#define OPENSSL_SN_rc5_cbc L"RC5-CBC"
#define OPENSSL_SN_rc5_cfb64 L"RC5-CFB"
#define OPENSSL_SN_rc5_ecb L"RC5-ECB"
#define OPENSSL_SN_rc5_ofb64 L"RC5-OFB"
#define OPENSSL_SN_ripemd160 L"RIPEMD160"
#define OPENSSL_SN_ripemd160WithRSA L"RSA-RIPEMD160"
#define OPENSSL_SN_rle_compression L"RLE"
#define OPENSSL_SN_rsa L"RSA"
#define OPENSSL_SN_serialNumber L"SN"
#define OPENSSL_SN_server_auth L"serverAuth"
#define OPENSSL_SN_sha L"SHA"
#define OPENSSL_SN_sha1 L"SHA1"
#define OPENSSL_SN_sha1WithRSA L"RSA-SHA1-2"
#define OPENSSL_SN_sha1WithRSAEncryption L"RSA-SHA1"
#define OPENSSL_SN_shaWithRSAEncryption L"RSA-SHA"
#define OPENSSL_SN_stateOrProvinceName L"ST"
#define OPENSSL_SN_subject_alt_name L"subjectAltName"
#define OPENSSL_SN_subject_key_identifier L"subjectKeyIdentifier"
static const WideChar OPENSSL_SN_surname = (WideChar)(0x53);
#define OPENSSL_SN_sxnet L"SXNetID"
#define OPENSSL_SN_time_stamp L"timeStamping"
static const WideChar OPENSSL_SN_title = (WideChar)(0x54);
#define OPENSSL_SN_undef L"UNDEF"
#define OPENSSL_SN_uniqueIdentifier L"UID"
#define OPENSSL_SN_zlib_compression L"ZLIB"
static const ShortInt OPENSSL_OCSP_DEFAULT_NONCE_LENGTH = 0x10;
static const ShortInt OPENSSL_OCSP_NOCERTS = 0x1;
static const ShortInt OPENSSL_OCSP_NOINTERN = 0x2;
static const ShortInt OPENSSL_OCSP_NOSIGS = 0x4;
static const ShortInt OPENSSL_OCSP_NOCHAIN = 0x8;
static const ShortInt OPENSSL_OCSP_NOVERIFY = 0x10;
static const ShortInt OPENSSL_OCSP_NOEXPLICIT = 0x20;
static const ShortInt OPENSSL_OCSP_NOCASIGN = 0x40;
static const Byte OPENSSL_OCSP_NODELEGATED = 0x80;
static const Word OPENSSL_OCSP_NOCHECKS = 0x100;
static const Word OPENSSL_OCSP_TRUSTOTHER = 0x200;
static const Word OPENSSL_OCSP_RESPID_KEY = 0x400;
static const Word OPENSSL_OCSP_NOTIME = 0x800;
static const ShortInt OPENSSL_OCSP_RESPONSE_STATUS_SUCCESSFUL = 0x0;
static const ShortInt OPENSSL_OCSP_RESPONSE_STATUS_MALFORMEDREQUEST = 0x1;
static const ShortInt OPENSSL_OCSP_RESPONSE_STATUS_INTERNALERROR = 0x2;
static const ShortInt OPENSSL_OCSP_RESPONSE_STATUS_TRYLATER = 0x3;
static const ShortInt OPENSSL_OCSP_RESPONSE_STATUS_SIGREQUIRED = 0x5;
static const ShortInt OPENSSL_OCSP_RESPONSE_STATUS_UNAUTHORIZED = 0x6;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_NOSTATUS = -1;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_UNSPECIFIED = 0x0;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_KEYCOMPROMISE = 0x1;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_CACOMPROMISE = 0x2;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_AFFILIATIONCHANGED = 0x3;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_SUPERSEDED = 0x4;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_CESSATIONOFOPERATION = 0x5;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_CERTIFICATEHOLD = 0x6;
static const ShortInt OPENSSL_OCSP_REVOKED_STATUS_REMOVEFROMCRL = 0x8;
static const ShortInt OPENSSL_V_OCSP_CERTSTATUS_GOOD = 0x0;
static const ShortInt OPENSSL_V_OCSP_CERTSTATUS_REVOKED = 0x1;
static const ShortInt OPENSSL_V_OCSP_CERTSTATUS_UNKNOWN = 0x2;
static const ShortInt OPENSSL_OCSP_F_ASN1_STRING_ENCODE = 0x64;
static const ShortInt OPENSSL_OCSP_F_D2I_OCSP_NONCE = 0x66;
static const ShortInt OPENSSL_OCSP_F_OCSP_BASIC_ADD1_STATUS = 0x67;
static const ShortInt OPENSSL_OCSP_F_OCSP_BASIC_SIGN = 0x68;
static const ShortInt OPENSSL_OCSP_F_OCSP_BASIC_VERIFY = 0x69;
static const ShortInt OPENSSL_OCSP_F_OCSP_CERT_ID_NEW = 0x65;
static const ShortInt OPENSSL_OCSP_F_OCSP_CHECK_DELEGATED = 0x6a;
static const ShortInt OPENSSL_OCSP_F_OCSP_CHECK_IDS = 0x6b;
static const ShortInt OPENSSL_OCSP_F_OCSP_CHECK_ISSUER = 0x6c;
static const ShortInt OPENSSL_OCSP_F_OCSP_CHECK_VALIDITY = 0x73;
static const ShortInt OPENSSL_OCSP_F_OCSP_MATCH_ISSUERID = 0x6d;
static const ShortInt OPENSSL_OCSP_F_OCSP_PARSE_URL = 0x72;
static const ShortInt OPENSSL_OCSP_F_OCSP_REQUEST_SIGN = 0x6e;
static const ShortInt OPENSSL_OCSP_F_OCSP_REQUEST_VERIFY = 0x74;
static const ShortInt OPENSSL_OCSP_F_OCSP_RESPONSE_GET1_BASIC = 0x6f;
static const ShortInt OPENSSL_OCSP_F_OCSP_SENDREQ_BIO = 0x70;
static const ShortInt OPENSSL_OCSP_F_PARSE_HTTP_LINE1 = 0x75;
static const ShortInt OPENSSL_OCSP_F_REQUEST_VERIFY = 0x71;
static const ShortInt OPENSSL_OCSP_R_BAD_DATA = 0x64;
static const ShortInt OPENSSL_OCSP_R_CERTIFICATE_VERIFY_ERROR = 0x65;
static const ShortInt OPENSSL_OCSP_R_DIGEST_ERR = 0x66;
static const ShortInt OPENSSL_OCSP_R_ERROR_IN_NEXTUPDATE_FIELD = 0x7a;
static const ShortInt OPENSSL_OCSP_R_ERROR_IN_THISUPDATE_FIELD = 0x7b;
static const ShortInt OPENSSL_OCSP_R_ERROR_PARSING_URL = 0x79;
static const ShortInt OPENSSL_OCSP_R_MISSING_OCSPSIGNING_USAGE = 0x67;
static const ShortInt OPENSSL_OCSP_R_NEXTUPDATE_BEFORE_THISUPDATE = 0x7c;
static const ShortInt OPENSSL_OCSP_R_NOT_BASIC_RESPONSE = 0x68;
static const ShortInt OPENSSL_OCSP_R_NO_CERTIFICATES_IN_CHAIN = 0x69;
static const ShortInt OPENSSL_OCSP_R_NO_CONTENT = 0x6a;
static const ShortInt OPENSSL_OCSP_R_NO_PUBLIC_KEY = 0x6b;
static const ShortInt OPENSSL_OCSP_R_NO_RESPONSE_DATA = 0x6c;
static const ShortInt OPENSSL_OCSP_R_NO_REVOKED_TIME = 0x6d;
static const ShortInt OPENSSL_OCSP_R_PRIVATE_KEY_DOES_NOT_MATCH_CERTIFICATE = 0x6e;
static const Byte OPENSSL_OCSP_R_REQUEST_NOT_SIGNED = 0x80;
static const ShortInt OPENSSL_OCSP_R_RESPONSE_CONTAINS_NO_REVOCATION_DATA = 0x6f;
static const ShortInt OPENSSL_OCSP_R_ROOT_CA_NOT_TRUSTED = 0x70;
static const ShortInt OPENSSL_OCSP_R_SERVER_READ_ERROR = 0x71;
static const ShortInt OPENSSL_OCSP_R_SERVER_RESPONSE_ERROR = 0x72;
static const ShortInt OPENSSL_OCSP_R_SERVER_RESPONSE_PARSE_ERROR = 0x73;
static const ShortInt OPENSSL_OCSP_R_SERVER_WRITE_ERROR = 0x74;
static const ShortInt OPENSSL_OCSP_R_SIGNATURE_FAILURE = 0x75;
static const ShortInt OPENSSL_OCSP_R_SIGNER_CERTIFICATE_NOT_FOUND = 0x76;
static const ShortInt OPENSSL_OCSP_R_STATUS_EXPIRED = 0x7d;
static const ShortInt OPENSSL_OCSP_R_STATUS_NOT_YET_VALID = 0x7e;
static const ShortInt OPENSSL_OCSP_R_STATUS_TOO_OLD = 0x7f;
static const ShortInt OPENSSL_OCSP_R_UNKNOWN_MESSAGE_DIGEST = 0x77;
static const ShortInt OPENSSL_OCSP_R_UNKNOWN_NID = 0x78;
static const Byte OPENSSL_OCSP_R_UNSUPPORTED_REQUESTORNAME_TYPE = 0x81;
static const Word OPENSSL_SSL_ST_CONNECT = 0x1000;
static const Word OPENSSL_SSL23_ST_CR_SRVR_HELLO_A = 0x1220;
static const Word OPENSSL_SSL23_ST_CR_SRVR_HELLO_B = 0x1221;
static const Word OPENSSL_SSL23_ST_CW_CLNT_HELLO_A = 0x1210;
static const Word OPENSSL_SSL23_ST_CW_CLNT_HELLO_B = 0x1211;
static const Word OPENSSL_SSL_ST_ACCEPT = 0x2000;
static const Word OPENSSL_SSL23_ST_SR_CLNT_HELLO_A = 0x2210;
static const Word OPENSSL_SSL23_ST_SR_CLNT_HELLO_B = 0x2211;
static const ShortInt OPENSSL_SSL2_AT_MD5_WITH_RSA_ENCRYPTION = 0x1;
static const ShortInt OPENSSL_SSL2_CF_5_BYTE_ENC = 0x1;
static const ShortInt OPENSSL_SSL2_CF_8_BYTE_ENC = 0x2;
static const ShortInt OPENSSL_SSL2_CHALLENGE_LENGTH = 0x10;
static const int OPENSSL_SSL2_CK_DES_192_EDE3_CBC_WITH_MD5 = 0x20700c0;
static const int OPENSSL_SSL2_CK_DES_192_EDE3_CBC_WITH_SHA = 0x20701c0;
static const int OPENSSL_SSL2_CK_DES_64_CBC_WITH_MD5 = 0x2060040;
static const int OPENSSL_SSL2_CK_DES_64_CBC_WITH_SHA = 0x2060140;
static const int OPENSSL_SSL2_CK_DES_64_CFB64_WITH_MD5_1 = 0x2ff0800;
static const int OPENSSL_SSL2_CK_IDEA_128_CBC_WITH_MD5 = 0x2050080;
static const int OPENSSL_SSL2_CK_NULL = 0x2ff0810;
static const int OPENSSL_SSL2_CK_NULL_WITH_MD5 = 0x2000000;
static const int OPENSSL_SSL2_CK_RC2_128_CBC_EXPORT40_WITH_MD5 = 0x2040080;
static const int OPENSSL_SSL2_CK_RC2_128_CBC_WITH_MD5 = 0x2030080;
static const int OPENSSL_SSL2_CK_RC4_128_EXPORT40_WITH_MD5 = 0x2020080;
static const int OPENSSL_SSL2_CK_RC4_128_WITH_MD5 = 0x2010080;
static const int OPENSSL_SSL2_CK_RC4_64_WITH_MD5 = 0x2080080;
static const ShortInt OPENSSL_SSL2_CONNECTION_ID_LENGTH = 0x10;
static const ShortInt OPENSSL_SSL2_CT_X509_CERTIFICATE = 0x1;
static const ShortInt OPENSSL_SSL2_MAX_CERT_CHALLENGE_LENGTH = 0x20;
static const ShortInt OPENSSL_SSL2_MAX_CHALLENGE_LENGTH = 0x20;
static const ShortInt OPENSSL_SSL2_MAX_CONNECTION_ID_LENGTH = 0x10;
static const ShortInt OPENSSL_SSL2_MAX_KEY_MATERIAL_LENGTH = 0x18;
static const Word OPENSSL_SSL2_MAX_MASTER_KEY_LENGTH_IN_BITS = 0x100;
static const Word OPENSSL_SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER = 0x3fff;
static const ShortInt OPENSSL_SSL2_MAX_SSL_SESSION_ID_LENGTH = 0x20;
static const ShortInt OPENSSL_SSL2_MIN_CERT_CHALLENGE_LENGTH = 0x10;
static const ShortInt OPENSSL_SSL2_MIN_CHALLENGE_LENGTH = 0x10;
static const ShortInt OPENSSL_SSL2_MT_CLIENT_CERTIFICATE = 0x8;
static const ShortInt OPENSSL_SSL2_MT_CLIENT_FINISHED = 0x3;
static const ShortInt OPENSSL_SSL2_MT_CLIENT_HELLO = 0x1;
static const ShortInt OPENSSL_SSL2_MT_CLIENT_MASTER_KEY = 0x2;
static const ShortInt OPENSSL_SSL2_MT_ERROR = 0x0;
static const ShortInt OPENSSL_SSL2_MT_REQUEST_CERTIFICATE = 0x7;
static const ShortInt OPENSSL_SSL2_MT_SERVER_FINISHED = 0x6;
static const ShortInt OPENSSL_SSL2_MT_SERVER_HELLO = 0x4;
static const ShortInt OPENSSL_SSL2_MT_SERVER_VERIFY = 0x5;
static const ShortInt OPENSSL_SSL2_PE_BAD_CERTIFICATE = 0x4;
static const ShortInt OPENSSL_SSL2_PE_NO_CERTIFICATE = 0x2;
static const ShortInt OPENSSL_SSL2_PE_NO_CIPHER = 0x1;
static const ShortInt OPENSSL_SSL2_PE_UNDEFINED_ERROR = 0x0;
static const ShortInt OPENSSL_SSL2_PE_UNSUPPORTED_CERTIFICATE_TYPE = 0x6;
static const ShortInt OPENSSL_SSL2_SSL_SESSION_ID_LENGTH = 0x10;
static const Word OPENSSL_SSL2_ST_CLIENT_START_ENCRYPTION = 0x1080;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_FINISHED_A = 0x2050;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_FINISHED_B = 0x2051;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_HELLO_A = 0x2010;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_HELLO_B = 0x2011;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_HELLO_C = 0x2012;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_MASTER_KEY_A = 0x2030;
static const Word OPENSSL_SSL2_ST_GET_CLIENT_MASTER_KEY_B = 0x2031;
static const Word OPENSSL_SSL2_ST_GET_SERVER_FINISHED_A = 0x1070;
static const Word OPENSSL_SSL2_ST_GET_SERVER_FINISHED_B = 0x1071;
static const Word OPENSSL_SSL2_ST_GET_SERVER_HELLO_A = 0x1020;
static const Word OPENSSL_SSL2_ST_GET_SERVER_HELLO_B = 0x1021;
static const Word OPENSSL_SSL2_ST_GET_SERVER_VERIFY_A = 0x1060;
static const Word OPENSSL_SSL2_ST_GET_SERVER_VERIFY_B = 0x1061;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_CERTIFICATE_A = 0x1050;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_CERTIFICATE_B = 0x1051;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_CERTIFICATE_C = 0x1052;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_CERTIFICATE_D = 0x1053;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_FINISHED_A = 0x1040;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_FINISHED_B = 0x1041;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_HELLO_A = 0x1010;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_HELLO_B = 0x1011;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_MASTER_KEY_A = 0x1030;
static const Word OPENSSL_SSL2_ST_SEND_CLIENT_MASTER_KEY_B = 0x1031;
static const Word OPENSSL_SSL2_ST_SEND_REQUEST_CERTIFICATE_A = 0x2070;
static const Word OPENSSL_SSL2_ST_SEND_REQUEST_CERTIFICATE_B = 0x2071;
static const Word OPENSSL_SSL2_ST_SEND_REQUEST_CERTIFICATE_C = 0x2072;
static const Word OPENSSL_SSL2_ST_SEND_REQUEST_CERTIFICATE_D = 0x2073;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_FINISHED_A = 0x2060;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_FINISHED_B = 0x2061;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_HELLO_A = 0x2020;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_HELLO_B = 0x2021;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_VERIFY_A = 0x2040;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_VERIFY_B = 0x2041;
static const Word OPENSSL_SSL2_ST_SEND_SERVER_VERIFY_C = 0x2042;
static const Word OPENSSL_SSL2_ST_SERVER_START_ENCRYPTION = 0x2080;
static const Word OPENSSL_SSL2_ST_X509_GET_CLIENT_CERTIFICATE = 0x1090;
static const Word OPENSSL_SSL2_ST_X509_GET_SERVER_CERTIFICATE = 0x2090;
#define OPENSSL_SSL2_TXT_DES_192_EDE3_CBC_WITH_MD5 L"DES-CBC3-MD5"
#define OPENSSL_SSL2_TXT_DES_192_EDE3_CBC_WITH_SHA L"DES-CBC3-SHA"
#define OPENSSL_SSL2_TXT_DES_64_CBC_WITH_MD5 L"DES-CBC-MD5"
#define OPENSSL_SSL2_TXT_DES_64_CBC_WITH_SHA L"DES-CBC-SHA"
#define OPENSSL_SSL2_TXT_DES_64_CFB64_WITH_MD5_1 L"DES-CFB-M1"
#define OPENSSL_SSL2_TXT_IDEA_128_CBC_WITH_MD5 L"IDEA-CBC-MD5"
#define OPENSSL_SSL2_TXT_NULL L"NULL"
#define OPENSSL_SSL2_TXT_NULL_WITH_MD5 L"NULL-MD5"
#define OPENSSL_SSL2_TXT_RC2_128_CBC_EXPORT40_WITH_MD5 L"EXP-RC2-CBC-MD5"
#define OPENSSL_SSL2_TXT_RC2_128_CBC_WITH_MD5 L"RC2-CBC-MD5"
#define OPENSSL_SSL2_TXT_RC4_128_EXPORT40_WITH_MD5 L"EXP-RC4-MD5"
#define OPENSSL_SSL2_TXT_RC4_128_WITH_MD5 L"RC4-MD5"
#define OPENSSL_SSL2_TXT_RC4_64_WITH_MD5 L"RC4-64-MD5"
static const ShortInt OPENSSL_SSL2_VERSION = 0x2;
static const ShortInt OPENSSL_SSL2_VERSION_MAJOR = 0x0;
static const ShortInt OPENSSL_SSL2_VERSION_MINOR = 0x2;
static const ShortInt OPENSSL_SSL3_AD_BAD_CERTIFICATE = 0x2a;
static const ShortInt OPENSSL_SSL3_AD_BAD_RECORD_MAC = 0x14;
static const ShortInt OPENSSL_SSL3_AD_CERTIFICATE_EXPIRED = 0x2d;
static const ShortInt OPENSSL_SSL3_AD_CERTIFICATE_REVOKED = 0x2c;
static const ShortInt OPENSSL_SSL3_AD_CERTIFICATE_UNKNOWN = 0x2e;
static const ShortInt OPENSSL_SSL3_AD_CLOSE_NOTIFY = 0x0;
static const ShortInt OPENSSL_SSL3_AD_DECOMPRESSION_FAILURE = 0x1e;
static const ShortInt OPENSSL_SSL3_AD_HANDSHAKE_FAILURE = 0x28;
static const ShortInt OPENSSL_SSL3_AD_ILLEGAL_PARAMETER = 0x2f;
static const ShortInt OPENSSL_SSL3_AD_NO_CERTIFICATE = 0x29;
static const ShortInt OPENSSL_SSL3_AD_UNEXPECTED_MESSAGE = 0xa;
static const ShortInt OPENSSL_SSL3_AD_UNSUPPORTED_CERTIFICATE = 0x2b;
static const ShortInt OPENSSL_SSL3_AL_FATAL = 0x2;
static const ShortInt OPENSSL_SSL3_AL_WARNING = 0x1;
static const ShortInt OPENSSL_SSL3_CC_CLIENT = 0x10;
static const ShortInt OPENSSL_SSL3_CC_READ = 0x1;
static const ShortInt OPENSSL_SSL3_CC_SERVER = 0x20;
static const ShortInt OPENSSL_SSL3_CC_WRITE = 0x2;
static const ShortInt OPENSSL_SSL3_CHANGE_CIPHER_CLIENT_READ = 0x11;
static const ShortInt OPENSSL_SSL3_CHANGE_CIPHER_CLIENT_WRITE = 0x12;
static const ShortInt OPENSSL_SSL3_CHANGE_CIPHER_SERVER_READ = 0x21;
static const ShortInt OPENSSL_SSL3_CHANGE_CIPHER_SERVER_WRITE = 0x22;
static const int OPENSSL_SSL3_CK_ADH_DES_192_CBC_SHA = 0x300001b;
static const int OPENSSL_SSL3_CK_ADH_DES_40_CBC_SHA = 0x3000019;
static const int OPENSSL_SSL3_CK_ADH_DES_64_CBC_SHA = 0x300001a;
static const int OPENSSL_SSL3_CK_ADH_RC4_128_MD5 = 0x3000018;
static const int OPENSSL_SSL3_CK_ADH_RC4_40_MD5 = 0x3000017;
static const int OPENSSL_SSL3_CK_DH_DSS_DES_192_CBC3_SHA = 0x300000d;
static const int OPENSSL_SSL3_CK_DH_DSS_DES_40_CBC_SHA = 0x300000b;
static const int OPENSSL_SSL3_CK_DH_DSS_DES_64_CBC_SHA = 0x300000c;
static const int OPENSSL_SSL3_CK_DH_RSA_DES_192_CBC3_SHA = 0x3000010;
static const int OPENSSL_SSL3_CK_DH_RSA_DES_40_CBC_SHA = 0x300000e;
static const int OPENSSL_SSL3_CK_DH_RSA_DES_64_CBC_SHA = 0x300000f;
static const int OPENSSL_SSL3_CK_EDH_DSS_DES_192_CBC3_SHA = 0x3000013;
static const int OPENSSL_SSL3_CK_EDH_DSS_DES_40_CBC_SHA = 0x3000011;
static const int OPENSSL_SSL3_CK_EDH_DSS_DES_64_CBC_SHA = 0x3000012;
static const int OPENSSL_SSL3_CK_EDH_RSA_DES_192_CBC3_SHA = 0x3000016;
static const int OPENSSL_SSL3_CK_EDH_RSA_DES_40_CBC_SHA = 0x3000014;
static const int OPENSSL_SSL3_CK_EDH_RSA_DES_64_CBC_SHA = 0x3000015;
static const int OPENSSL_SSL3_CK_FZA_DMS_FZA_SHA = 0x300001d;
static const int OPENSSL_SSL3_CK_FZA_DMS_NULL_SHA = 0x300001c;
static const int OPENSSL_SSL3_CK_FZA_DMS_RC4_SHA = 0x300001e;
static const int OPENSSL_SSL3_CK_RSA_DES_192_CBC3_SHA = 0x300000a;
static const int OPENSSL_SSL3_CK_RSA_DES_40_CBC_SHA = 0x3000008;
static const int OPENSSL_SSL3_CK_RSA_DES_64_CBC_SHA = 0x3000009;
static const int OPENSSL_SSL3_CK_RSA_IDEA_128_SHA = 0x3000007;
static const int OPENSSL_SSL3_CK_RSA_NULL_MD5 = 0x3000001;
static const int OPENSSL_SSL3_CK_RSA_NULL_SHA = 0x3000002;
static const int OPENSSL_SSL3_CK_RSA_RC2_40_MD5 = 0x3000006;
static const int OPENSSL_SSL3_CK_RSA_RC4_128_MD5 = 0x3000004;
static const int OPENSSL_SSL3_CK_RSA_RC4_128_SHA = 0x3000005;
static const int OPENSSL_SSL3_CK_RSA_RC4_40_MD5 = 0x3000003;
static const ShortInt OPENSSL_SSL3_CT_DSS_EPHEMERAL_DH = 0x6;
static const ShortInt OPENSSL_SSL3_CT_DSS_FIXED_DH = 0x4;
static const ShortInt OPENSSL_SSL3_CT_DSS_SIGN = 0x2;
static const ShortInt OPENSSL_SSL3_CT_FORTEZZA_DMS = 0x14;
static const ShortInt OPENSSL_SSL3_CT_NUMBER = 0x7;
static const ShortInt OPENSSL_SSL3_CT_RSA_EPHEMERAL_DH = 0x5;
static const ShortInt OPENSSL_SSL3_CT_RSA_FIXED_DH = 0x3;
static const ShortInt OPENSSL_SSL3_CT_RSA_SIGN = 0x1;
static const ShortInt OPENSSL_SSL3_FLAGS_DELAY_CLIENT_FINISHED = 0x2;
static const ShortInt OPENSSL_SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS = 0x1;
static const ShortInt OPENSSL_SSL3_FLAGS_POP_BUFFER = 0x4;
static const ShortInt OPENSSL_SSL3_MASTER_SECRET_SIZE = 0x30;
static const ShortInt OPENSSL_SSL3_MAX_SSL_SESSION_ID_LENGTH = 0x20;
static const ShortInt OPENSSL_SSL3_MT_HELLO_REQUEST = 0x0;
static const ShortInt OPENSSL_SSL3_MT_CLIENT_REQUEST = 0x0;
static const ShortInt OPENSSL_SSL3_MT_CLIENT_HELLO = 0x1;
static const ShortInt OPENSSL_SSL3_MT_SERVER_HELLO = 0x2;
static const ShortInt OPENSSL_SSL3_MT_NEWSESSION_TICKET = 0x4;
static const ShortInt OPENSSL_SSL3_MT_CERTIFICATE = 0xb;
static const ShortInt OPENSSL_SSL3_MT_SERVER_KEY_EXCHANGE = 0xc;
static const ShortInt OPENSSL_SSL3_MT_CERTIFICATE_REQUEST = 0xd;
static const ShortInt OPENSSL_SSL3_MT_SERVER_DONE = 0xe;
static const ShortInt OPENSSL_SSL3_MT_CERTIFICATE_VERIFY = 0xf;
static const ShortInt OPENSSL_SSL3_MT_CLIENT_KEY_EXCHANGE = 0x10;
static const ShortInt OPENSSL_SSL3_MT_FINISHED = 0x14;
static const ShortInt OPENSSL_SSL3_MT_CERTIFICATE_STATUS = 0x16;
static const ShortInt OPENSSL_DTLS1_MT_HELLO_VERIFY_REQUEST = 0x3;
static const ShortInt OPENSSL_SSL3_MT_CCS = 0x1;
static const ShortInt OPENSSL_SSL3_RANDOM_SIZE = 0x20;
static const ShortInt OPENSSL_SSL3_RS_BLANK = 0x1;
static const ShortInt OPENSSL_SSL3_RS_ENCODED = 0x2;
static const ShortInt OPENSSL_SSL3_RS_PART_READ = 0x4;
static const ShortInt OPENSSL_SSL3_RS_PART_WRITE = 0x5;
static const ShortInt OPENSSL_SSL3_RS_PLAIN = 0x3;
static const ShortInt OPENSSL_SSL3_RS_READ_MORE = 0x3;
static const ShortInt OPENSSL_SSL3_RT_ALERT = 0x15;
static const ShortInt OPENSSL_SSL3_RT_APPLICATION_DATA = 0x17;
static const ShortInt OPENSSL_SSL3_RT_CHANGE_CIPHER_SPEC = 0x14;
static const ShortInt OPENSSL_SSL3_RT_HANDSHAKE = 0x16;
static const ShortInt OPENSSL_SSL3_RT_HEADER_LENGTH = 0x5;
static const Word OPENSSL_SSL3_RT_MAX_PLAIN_LENGTH = 0x4000;
static const Word OPENSSL_SSL3_RT_MAX_COMPRESSED_LENGTH = 0x4400;
static const int OPENSSL_SSL3_RT_MAX_DATA_SIZE = 0x100000;
static const Word OPENSSL_SSL3_RT_MAX_ENCRYPTED_LENGTH = 0x4800;
static const Word OPENSSL_SSL3_RT_MAX_EXTRA = 0x4000;
static const Word OPENSSL_SSL3_RT_MAX_PACKET_SIZE = 0x4805;
static const ShortInt OPENSSL_SSL3_SESSION_ID_SIZE = 0x20;
static const ShortInt OPENSSL_SSL3_SSL_SESSION_ID_LENGTH = 0x20;
static const Word OPENSSL_SSL3_ST_CR_CERT_A = 0x1130;
static const Word OPENSSL_SSL3_ST_CR_CERT_B = 0x1131;
static const Word OPENSSL_SSL3_ST_CR_CERT_REQ_A = 0x1150;
static const Word OPENSSL_SSL3_ST_CR_CERT_REQ_B = 0x1151;
static const Word OPENSSL_SSL3_ST_CR_CHANGE_A = 0x11c0;
static const Word OPENSSL_SSL3_ST_CR_CHANGE_B = 0x11c1;
static const Word OPENSSL_SSL3_ST_CR_FINISHED_A = 0x11d0;
static const Word OPENSSL_SSL3_ST_CR_FINISHED_B = 0x11d1;
static const Word OPENSSL_SSL3_ST_CR_SESSION_TICKET_A = 0x11e0;
static const Word OPENSSL_SSL3_ST_CR_SESSION_TICKET_B = 0x11e1;
static const Word OPENSSL_SSL3_ST_CR_CERT_STATUS_A = 0x11f0;
static const Word OPENSSL_SSL3_ST_CR_CERT_STATUS_B = 0x11f1;
static const Word OPENSSL_SSL3_ST_CR_KEY_EXCH_A = 0x1140;
static const Word OPENSSL_SSL3_ST_CR_KEY_EXCH_B = 0x1141;
static const Word OPENSSL_SSL3_ST_CR_SRVR_DONE_A = 0x1160;
static const Word OPENSSL_SSL3_ST_CR_SRVR_DONE_B = 0x1161;
static const Word OPENSSL_SSL3_ST_CR_SRVR_HELLO_A = 0x1120;
static const Word OPENSSL_SSL3_ST_CR_SRVR_HELLO_B = 0x1121;
static const Word OPENSSL_SSL3_ST_CW_CERT_A = 0x1170;
static const Word OPENSSL_SSL3_ST_CW_CERT_B = 0x1171;
static const Word OPENSSL_SSL3_ST_CW_CERT_C = 0x1172;
static const Word OPENSSL_SSL3_ST_CW_CERT_D = 0x1173;
static const Word OPENSSL_SSL3_ST_CW_CERT_VRFY_A = 0x1190;
static const Word OPENSSL_SSL3_ST_CW_CERT_VRFY_B = 0x1191;
static const Word OPENSSL_SSL3_ST_CW_CHANGE_A = 0x11a0;
static const Word OPENSSL_SSL3_ST_CW_CHANGE_B = 0x11a1;
static const Word OPENSSL_SSL3_ST_CW_CLNT_HELLO_A = 0x1110;
static const Word OPENSSL_SSL3_ST_CW_CLNT_HELLO_B = 0x1111;
static const Word OPENSSL_SSL3_ST_CW_FINISHED_A = 0x11b0;
static const Word OPENSSL_SSL3_ST_CW_FINISHED_B = 0x11b1;
static const Word OPENSSL_SSL3_ST_CW_FLUSH = 0x1100;
static const Word OPENSSL_SSL3_ST_CW_KEY_EXCH_A = 0x1180;
static const Word OPENSSL_SSL3_ST_CW_KEY_EXCH_B = 0x1181;
static const Word OPENSSL_SSL3_ST_SR_CERT_A = 0x2180;
static const Word OPENSSL_SSL3_ST_SR_CERT_B = 0x2181;
static const Word OPENSSL_SSL3_ST_SR_CERT_VRFY_A = 0x21a0;
static const Word OPENSSL_SSL3_ST_SR_CERT_VRFY_B = 0x21a1;
static const Word OPENSSL_SSL3_ST_SR_CHANGE_A = 0x21b0;
static const Word OPENSSL_SSL3_ST_SR_CHANGE_B = 0x21b1;
static const Word OPENSSL_SSL3_ST_SR_CLNT_HELLO_A = 0x2110;
static const Word OPENSSL_SSL3_ST_SR_CLNT_HELLO_B = 0x2111;
static const Word OPENSSL_SSL3_ST_SR_CLNT_HELLO_C = 0x2112;
static const Word OPENSSL_SSL3_ST_SR_FINISHED_A = 0x21c0;
static const Word OPENSSL_SSL3_ST_SR_FINISHED_B = 0x21c1;
static const Word OPENSSL_SSL3_ST_SR_KEY_EXCH_A = 0x2190;
static const Word OPENSSL_SSL3_ST_SR_KEY_EXCH_B = 0x2191;
static const Word OPENSSL_SSL3_ST_SW_CERT_A = 0x2140;
static const Word OPENSSL_SSL3_ST_SW_CERT_B = 0x2141;
static const Word OPENSSL_SSL3_ST_SW_CERT_REQ_A = 0x2160;
static const Word OPENSSL_SSL3_ST_SW_CERT_REQ_B = 0x2161;
static const Word OPENSSL_SSL3_ST_SW_CHANGE_A = 0x21d0;
static const Word OPENSSL_SSL3_ST_SW_CHANGE_B = 0x21d1;
static const Word OPENSSL_SSL3_ST_SW_FINISHED_A = 0x21e0;
static const Word OPENSSL_SSL3_ST_SW_FINISHED_B = 0x21e1;
static const Word OPENSSL_SSL3_ST_SW_SESSION_TICKET_A = 0x21f0;
static const Word OPENSSL_SSL3_ST_SW_SESSION_TICKET_B = 0x21f1;
static const Word OPENSSL_SSL3_ST_SW_CERT_STATUS_A = 0x2200;
static const Word OPENSSL_SSL3_ST_SW_CERT_STATUS_B = 0x2201;
static const Word OPENSSL_SSL3_ST_SW_FLUSH = 0x2100;
static const Word OPENSSL_SSL3_ST_SW_HELLO_REQ_A = 0x2120;
static const Word OPENSSL_SSL3_ST_SW_HELLO_REQ_B = 0x2121;
static const Word OPENSSL_SSL3_ST_SW_HELLO_REQ_C = 0x2122;
static const Word OPENSSL_SSL3_ST_SW_KEY_EXCH_A = 0x2150;
static const Word OPENSSL_SSL3_ST_SW_KEY_EXCH_B = 0x2151;
static const Word OPENSSL_SSL3_ST_SW_SRVR_DONE_A = 0x2170;
static const Word OPENSSL_SSL3_ST_SW_SRVR_DONE_B = 0x2171;
static const Word OPENSSL_SSL3_ST_SW_SRVR_HELLO_A = 0x2130;
static const Word OPENSSL_SSL3_ST_SW_SRVR_HELLO_B = 0x2131;
#define OPENSSL_SSL3_TXT_ADH_DES_192_CBC_SHA L"ADH-DES-CBC3-SHA"
#define OPENSSL_SSL3_TXT_ADH_DES_40_CBC_SHA L"EXP-ADH-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_ADH_DES_64_CBC_SHA L"ADH-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_ADH_RC4_128_MD5 L"ADH-RC4-MD5"
#define OPENSSL_SSL3_TXT_ADH_RC4_40_MD5 L"EXP-ADH-RC4-MD5"
#define OPENSSL_SSL3_TXT_DH_DSS_DES_192_CBC3_SHA L"DH-DSS-DES-CBC3-SHA"
#define OPENSSL_SSL3_TXT_DH_DSS_DES_40_CBC_SHA L"EXP-DH-DSS-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_DH_DSS_DES_64_CBC_SHA L"DH-DSS-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_DH_RSA_DES_192_CBC3_SHA L"DH-RSA-DES-CBC3-SHA"
#define OPENSSL_SSL3_TXT_DH_RSA_DES_40_CBC_SHA L"EXP-DH-RSA-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_DH_RSA_DES_64_CBC_SHA L"DH-RSA-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_EDH_DSS_DES_192_CBC3_SHA L"EDH-DSS-DES-CBC3-SHA"
#define OPENSSL_SSL3_TXT_EDH_DSS_DES_40_CBC_SHA L"EXP-EDH-DSS-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_EDH_DSS_DES_64_CBC_SHA L"EDH-DSS-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_EDH_RSA_DES_192_CBC3_SHA L"EDH-RSA-DES-CBC3-SHA"
#define OPENSSL_SSL3_TXT_EDH_RSA_DES_40_CBC_SHA L"EXP-EDH-RSA-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_EDH_RSA_DES_64_CBC_SHA L"EDH-RSA-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_FZA_DMS_FZA_SHA L"FZA-FZA-CBC-SHA"
#define OPENSSL_SSL3_TXT_FZA_DMS_NULL_SHA L"FZA-NULL-SHA"
#define OPENSSL_SSL3_TXT_FZA_DMS_RC4_SHA L"FZA-RC4-SHA"
#define OPENSSL_SSL3_TXT_RSA_DES_192_CBC3_SHA L"DES-CBC3-SHA"
#define OPENSSL_SSL3_TXT_RSA_DES_40_CBC_SHA L"EXP-DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_RSA_DES_64_CBC_SHA L"DES-CBC-SHA"
#define OPENSSL_SSL3_TXT_RSA_IDEA_128_SHA L"IDEA-CBC-SHA"
#define OPENSSL_SSL3_TXT_RSA_NULL_MD5 L"NULL-MD5"
#define OPENSSL_SSL3_TXT_RSA_NULL_SHA L"NULL-SHA"
#define OPENSSL_SSL3_TXT_RSA_RC2_40_MD5 L"EXP-RC2-CBC-MD5"
#define OPENSSL_SSL3_TXT_RSA_RC4_128_MD5 L"RC4-MD5"
#define OPENSSL_SSL3_TXT_RSA_RC4_128_SHA L"RC4-SHA"
#define OPENSSL_SSL3_TXT_RSA_RC4_40_MD5 L"EXP-RC4-MD5"
static const Word OPENSSL_SSL3_VERSION = 0x300;
static const ShortInt OPENSSL_SSL3_VERSION_MAJOR = 0x3;
static const ShortInt OPENSSL_SSL3_VERSION_MINOR = 0x0;
static const ShortInt OPENSSL_SSLEAY_VERSION = 0x0;
static const ShortInt OPENSSL_SSLEAY_CFLAGS = 0x2;
static const ShortInt OPENSSL_SSLEAY_BUILT_ON = 0x3;
static const ShortInt OPENSSL_SSLEAY_PLATFORM = 0x4;
static const ShortInt OPENSSL_SSLEAY_DIR = 0x5;
static const ShortInt OPENSSL_TLS1_AD_DECRYPTION_FAILED = 0x15;
static const ShortInt OPENSSL_TLS1_AD_RECORD_OVERFLOW = 0x16;
static const ShortInt OPENSSL_TLS1_AD_UNKNOWN_CA = 0x30;
static const ShortInt OPENSSL_TLS1_AD_ACCESS_DENIED = 0x31;
static const ShortInt OPENSSL_TLS1_AD_DECODE_ERROR = 0x32;
static const ShortInt OPENSSL_TLS1_AD_DECRYPT_ERROR = 0x33;
static const ShortInt OPENSSL_TLS1_AD_EXPORT_RESTRICTION = 0x3c;
static const ShortInt OPENSSL_TLS1_AD_PROTOCOL_VERSION = 0x46;
static const ShortInt OPENSSL_TLS1_AD_INSUFFICIENT_SECURITY = 0x47;
static const ShortInt OPENSSL_TLS1_AD_INTERNAL_ERROR = 0x50;
static const ShortInt OPENSSL_TLS1_AD_USER_CANCELLED = 0x5a;
static const ShortInt OPENSSL_TLS1_AD_NO_RENEGOTIATION = 0x64;
static const ShortInt OPENSSL_TLS1_AD_UNSUPPORTED_EXTENSION = 0x6e;
static const ShortInt OPENSSL_TLS1_AD_CERTIFICATE_UNOBTAINABLE = 0x6f;
static const ShortInt OPENSSL_TLS1_AD_UNRECOGNIZED_NAME = 0x70;
static const ShortInt OPENSSL_TLS1_AD_BAD_CERTIFICATE_STATUS_RESPONSE = 0x71;
static const ShortInt OPENSSL_TLS1_AD_BAD_CERTIFICATE_HASH_VALUE = 0x72;
static const ShortInt OPENSSL_TLS1_AD_UNKNOWN_PSK_IDENTITY = 0x73;
static const ShortInt OPENSSL_TLSEXT_TYPE_server_name = 0x0;
static const ShortInt OPENSSL_TLSEXT_TYPE_max_fragment_length = 0x1;
static const ShortInt OPENSSL_TLSEXT_TYPE_client_certificate_url = 0x2;
static const ShortInt OPENSSL_TLSEXT_TYPE_trusted_ca_keys = 0x3;
static const ShortInt OPENSSL_TLSEXT_TYPE_truncated_hmac = 0x4;
static const ShortInt OPENSSL_TLSEXT_TYPE_status_request = 0x5;
static const ShortInt OPENSSL_TLSEXT_TYPE_elliptic_curves = 0xa;
static const ShortInt OPENSSL_TLSEXT_TYPE_ec_point_formats = 0xb;
static const ShortInt OPENSSL_TLSEXT_TYPE_session_ticket = 0x23;
static const ShortInt OPENSSL_TLSEXT_NAMETYPE_host_name = 0x0;
static const ShortInt OPENSSL_TLSEXT_STATUSTYPE_ocsp = 0x1;
static const Byte OPENSSL_TLSEXT_MAXLEN_host_name = 0xff;
static const ShortInt OPENSSL_SSL_TLSEXT_ERR_OK = 0x0;
static const ShortInt OPENSSL_SSL_TLSEXT_ERR_ALERT_WARNING = 0x1;
static const ShortInt OPENSSL_SSL_TLSEXT_ERR_ALERT_FATAL = 0x2;
static const ShortInt OPENSSL_SSL_TLSEXT_ERR_NOACK = 0x3;
static const int OPENSSL_SSLEAY_VERSION_NUMBER = 0x9080af;
static const Word OPENSSL_SSL_AD_REASON_OFFSET = 0x3e8;
static const ShortInt OPENSSL_SSL_AD_CLOSE_NOTIFY = 0x0;
static const ShortInt OPENSSL_SSL_AD_UNEXPECTED_MESSAGE = 0xa;
static const ShortInt OPENSSL_SSL_AD_BAD_RECORD_MAC = 0x14;
static const ShortInt OPENSSL_SSL_AD_DECRYPTION_FAILED = 0x15;
static const ShortInt OPENSSL_SSL_AD_RECORD_OVERFLOW = 0x16;
static const ShortInt OPENSSL_SSL_AD_DECOMPRESSION_FAILURE = 0x1e;
static const ShortInt OPENSSL_SSL_AD_HANDSHAKE_FAILURE = 0x28;
static const ShortInt OPENSSL_SSL_AD_NO_CERTIFICATE = 0x29;
static const ShortInt OPENSSL_SSL_AD_BAD_CERTIFICATE = 0x2a;
static const ShortInt OPENSSL_SSL_AD_UNSUPPORTED_CERTIFICATE = 0x2b;
static const ShortInt OPENSSL_SSL_AD_CERTIFICATE_REVOKED = 0x2c;
static const ShortInt OPENSSL_SSL_AD_CERTIFICATE_EXPIRED = 0x2d;
static const ShortInt OPENSSL_SSL_AD_CERTIFICATE_UNKNOWN = 0x2e;
static const ShortInt OPENSSL_SSL_AD_ILLEGAL_PARAMETER = 0x2f;
static const ShortInt OPENSSL_SSL_AD_UNKNOWN_CA = 0x30;
static const ShortInt OPENSSL_SSL_AD_ACCESS_DENIED = 0x31;
static const ShortInt OPENSSL_SSL_AD_DECODE_ERROR = 0x32;
static const ShortInt OPENSSL_SSL_AD_DECRYPT_ERROR = 0x33;
static const ShortInt OPENSSL_SSL_AD_EXPORT_RESTRICTION = 0x3c;
static const ShortInt OPENSSL_SSL_AD_PROTOCOL_VERSION = 0x46;
static const ShortInt OPENSSL_SSL_AD_INSUFFICIENT_SECURITY = 0x47;
static const ShortInt OPENSSL_SSL_AD_INTERNAL_ERROR = 0x50;
static const ShortInt OPENSSL_SSL_AD_USER_CANCELLED = 0x5a;
static const ShortInt OPENSSL_SSL_AD_NO_RENEGOTIATION = 0x64;
static const ShortInt OPENSSL_SSL_AD_UNSUPPORTED_EXTENSION = 0x6e;
static const ShortInt OPENSSL_SSL_AD_CERTIFICATE_UNOBTAINABLE = 0x6f;
static const ShortInt OPENSSL_SSL_AD_UNRECOGNIZED_NAME = 0x70;
static const ShortInt OPENSSL_SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE = 0x71;
static const ShortInt OPENSSL_SSL_CB_EXIT = 0x2;
static const Word OPENSSL_SSL_CB_ACCEPT_EXIT = 0x2002;
static const ShortInt OPENSSL_SSL_CB_LOOP = 0x1;
static const Word OPENSSL_SSL_CB_ACCEPT_LOOP = 0x2001;
static const Word OPENSSL_SSL_CB_ALERT = 0x4000;
static const Word OPENSSL_SSL_CB_CONNECT_EXIT = 0x1002;
static const Word OPENSSL_SSL_CB_CONNECT_LOOP = 0x1001;
static const ShortInt OPENSSL_SSL_CB_HANDSHAKE_DONE = 0x20;
static const ShortInt OPENSSL_SSL_CB_HANDSHAKE_START = 0x10;
static const ShortInt OPENSSL_SSL_CB_READ = 0x4;
static const Word OPENSSL_SSL_CB_READ_ALERT = 0x4004;
static const ShortInt OPENSSL_SSL_CB_WRITE = 0x8;
static const Word OPENSSL_SSL_CB_WRITE_ALERT = 0x4008;
static const ShortInt OPENSSL_SSL_CTRL_NEED_TMP_RSA = 0x1;
static const ShortInt OPENSSL_SSL_CTRL_SET_TMP_RSA = 0x2;
static const ShortInt OPENSSL_SSL_CTRL_SET_TMP_DH = 0x3;
static const ShortInt OPENSSL_SSL_CTRL_SET_TMP_ECDH = 0x4;
static const ShortInt OPENSSL_SSL_CTRL_SET_TMP_RSA_CB = 0x5;
static const ShortInt OPENSSL_SSL_CTRL_SET_TMP_DH_CB = 0x6;
static const ShortInt OPENSSL_SSL_CTRL_SET_TMP_ECDH_CB = 0x7;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_SERVERNAME_CB = 0x35;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_SERVERNAME_ARG = 0x36;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_HOSTNAME = 0x37;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_DEBUG_CB = 0x38;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_DEBUG_ARG = 0x39;
static const ShortInt OPENSSL_SSL_CTRL_GET_TLSEXT_TICKET_KEYS = 0x3a;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_TICKET_KEYS = 0x3b;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB = 0x3f;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB_ARG = 0x40;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_STATUS_REQ_TYPE = 0x41;
static const ShortInt OPENSSL_SSL_CTRL_GET_TLSEXT_STATUS_REQ_EXTS = 0x42;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_STATUS_REQ_EXTS = 0x43;
static const ShortInt OPENSSL_SSL_CTRL_GET_TLSEXT_STATUS_REQ_IDS = 0x44;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_STATUS_REQ_IDS = 0x45;
static const ShortInt OPENSSL_SSL_CTRL_GET_TLSEXT_STATUS_REQ_OCSP_RESP = 0x46;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_STATUS_REQ_OCSP_RESP = 0x47;
static const ShortInt OPENSSL_SSL_CTRL_SET_TLSEXT_TICKET_KEY_CB = 0x48;
static const ShortInt OPENSSL_SSL_CTRL_GET_SESSION_REUSED = 0x8;
static const ShortInt OPENSSL_SSL_CTRL_GET_CLIENT_CERT_REQUEST = 0x9;
static const ShortInt OPENSSL_SSL_CTRL_GET_NUM_RENEGOTIATIONS = 0xa;
static const ShortInt OPENSSL_SSL_CTRL_CLEAR_NUM_RENEGOTIATIONS = 0xb;
static const ShortInt OPENSSL_SSL_CTRL_GET_TOTAL_RENEGOTIATIONS = 0xc;
static const ShortInt OPENSSL_SSL_CTRL_GET_FLAGS = 0xd;
static const ShortInt OPENSSL_SSL_CTRL_EXTRA_CHAIN_CERT = 0xe;
static const ShortInt OPENSSL_SSL_CTRL_SET_MSG_CALLBACK = 0xf;
static const ShortInt OPENSSL_SSL_CTRL_SET_MSG_CALLBACK_ARG = 0x10;
static const ShortInt OPENSSL_SSL_CTRL_SET_MTU = 0x11;
static const ShortInt OPENSSL_SSL_CTRL_SESS_NUMBER = 0x14;
static const ShortInt OPENSSL_SSL_CTRL_SESS_CONNECT = 0x15;
static const ShortInt OPENSSL_SSL_CTRL_SESS_CONNECT_GOOD = 0x16;
static const ShortInt OPENSSL_SSL_CTRL_SESS_CONNECT_RENEGOTIATE = 0x17;
static const ShortInt OPENSSL_SSL_CTRL_SESS_ACCEPT = 0x18;
static const ShortInt OPENSSL_SSL_CTRL_SESS_ACCEPT_GOOD = 0x19;
static const ShortInt OPENSSL_SSL_CTRL_SESS_ACCEPT_RENEGOTIATE = 0x1a;
static const ShortInt OPENSSL_SSL_CTRL_SESS_HIT = 0x1b;
static const ShortInt OPENSSL_SSL_CTRL_SESS_CB_HIT = 0x1c;
static const ShortInt OPENSSL_SSL_CTRL_SESS_MISSES = 0x1d;
static const ShortInt OPENSSL_SSL_CTRL_SESS_TIMEOUTS = 0x1e;
static const ShortInt OPENSSL_SSL_CTRL_SESS_CACHE_FULL = 0x1f;
static const ShortInt OPENSSL_SSL_CTRL_OPTIONS = 0x20;
static const ShortInt OPENSSL_SSL_CTRL_MODE = 0x21;
static const ShortInt OPENSSL_SSL_CTRL_GET_READ_AHEAD = 0x28;
static const ShortInt OPENSSL_SSL_CTRL_SET_READ_AHEAD = 0x29;
static const ShortInt OPENSSL_SSL_CTRL_SET_SESS_CACHE_SIZE = 0x2a;
static const ShortInt OPENSSL_SSL_CTRL_GET_SESS_CACHE_SIZE = 0x2b;
static const ShortInt OPENSSL_SSL_CTRL_SET_SESS_CACHE_MODE = 0x2c;
static const ShortInt OPENSSL_SSL_CTRL_GET_SESS_CACHE_MODE = 0x2d;
static const ShortInt OPENSSL_SSL_CTRL_GET_MAX_CERT_LIST = 0x32;
static const ShortInt OPENSSL_SSL_CTRL_SET_MAX_CERT_LIST = 0x33;
#define OPENSSL_SSL_DEFAULT_CIPHER_LIST L"AES:ALL:!aNULL:!eNULL:+RC4:@STRENGTH"
static const ShortInt OPENSSL_SSL_ERROR_NONE = 0x0;
static const ShortInt OPENSSL_SSL_ERROR_SSL = 0x1;
static const ShortInt OPENSSL_SSL_ERROR_WANT_READ = 0x2;
static const ShortInt OPENSSL_SSL_ERROR_WANT_WRITE = 0x3;
static const ShortInt OPENSSL_SSL_ERROR_WANT_X509_LOOKUP = 0x4;
static const ShortInt OPENSSL_SSL_ERROR_SYSCALL = 0x5;
static const ShortInt OPENSSL_SSL_ERROR_ZERO_RETURN = 0x6;
static const ShortInt OPENSSL_SSL_ERROR_WANT_CONNECT = 0x7;
static const ShortInt OPENSSL_SSL_ERROR_WANT_ACCEPT = 0x8;
static const ShortInt OPENSSL_X509_FILETYPE_ASN1 = 0x2;
static const ShortInt OPENSSL_SSL_FILETYPE_ASN1 = 0x2;
static const ShortInt OPENSSL_X509_FILETYPE_PEM = 0x1;
static const ShortInt OPENSSL_SSL_FILETYPE_PEM = 0x1;
static const ShortInt OPENSSL_SSL_F_CLIENT_CERTIFICATE = 0x64;
static const ShortInt OPENSSL_SSL_F_CLIENT_HELLO = 0x65;
static const ShortInt OPENSSL_SSL_F_CLIENT_MASTER_KEY = 0x66;
static const ShortInt OPENSSL_SSL_F_D2I_SSL_SESSION = 0x67;
static const ShortInt OPENSSL_SSL_F_DO_SSL3_WRITE = 0x68;
static const Byte OPENSSL_SSL_F_DTLS1_ACCEPT = 0xf6;
static const Byte OPENSSL_SSL_F_DTLS1_BUFFER_RECORD = 0xf7;
static const Byte OPENSSL_SSL_F_DTLS1_CLIENT_HELLO = 0xf8;
static const Byte OPENSSL_SSL_F_DTLS1_CONNECT = 0xf9;
static const Byte OPENSSL_SSL_F_DTLS1_ENC = 0xfa;
static const Byte OPENSSL_SSL_F_DTLS1_GET_HELLO_VERIFY = 0xfb;
static const Byte OPENSSL_SSL_F_DTLS1_GET_MESSAGE = 0xfc;
static const Byte OPENSSL_SSL_F_DTLS1_GET_MESSAGE_FRAGMENT = 0xfd;
static const Byte OPENSSL_SSL_F_DTLS1_GET_RECORD = 0xfe;
static const Byte OPENSSL_SSL_F_DTLS1_OUTPUT_CERT_CHAIN = 0xff;
static const Word OPENSSL_SSL_F_DTLS1_PREPROCESS_FRAGMENT = 0x115;
static const Word OPENSSL_SSL_F_DTLS1_PROCESS_OUT_OF_SEQ_MESSAGE = 0x100;
static const Word OPENSSL_SSL_F_DTLS1_PROCESS_RECORD = 0x101;
static const Word OPENSSL_SSL_F_DTLS1_READ_BYTES = 0x102;
static const Word OPENSSL_SSL_F_DTLS1_READ_FAILED = 0x103;
static const Word OPENSSL_SSL_F_DTLS1_SEND_CERTIFICATE_REQUEST = 0x104;
static const Word OPENSSL_SSL_F_DTLS1_SEND_CLIENT_CERTIFICATE = 0x105;
static const Word OPENSSL_SSL_F_DTLS1_SEND_CLIENT_KEY_EXCHANGE = 0x106;
static const Word OPENSSL_SSL_F_DTLS1_SEND_CLIENT_VERIFY = 0x107;
static const Word OPENSSL_SSL_F_DTLS1_SEND_HELLO_VERIFY_REQUEST = 0x108;
static const Word OPENSSL_SSL_F_DTLS1_SEND_SERVER_CERTIFICATE = 0x109;
static const Word OPENSSL_SSL_F_DTLS1_SEND_SERVER_HELLO = 0x10a;
static const Word OPENSSL_SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE = 0x10b;
static const Word OPENSSL_SSL_F_DTLS1_WRITE_APP_DATA_BYTES = 0x10c;
static const ShortInt OPENSSL_SSL_F_GET_CLIENT_FINISHED = 0x69;
static const ShortInt OPENSSL_SSL_F_GET_CLIENT_HELLO = 0x6a;
static const ShortInt OPENSSL_SSL_F_GET_CLIENT_MASTER_KEY = 0x6b;
static const ShortInt OPENSSL_SSL_F_GET_SERVER_FINISHED = 0x6c;
static const ShortInt OPENSSL_SSL_F_GET_SERVER_HELLO = 0x6d;
static const ShortInt OPENSSL_SSL_F_GET_SERVER_VERIFY = 0x6e;
static const ShortInt OPENSSL_SSL_F_I2D_SSL_SESSION = 0x6f;
static const ShortInt OPENSSL_SSL_F_READ_N = 0x70;
static const ShortInt OPENSSL_SSL_F_REQUEST_CERTIFICATE = 0x71;
static const ShortInt OPENSSL_SSL_F_SERVER_HELLO = 0x72;
static const ShortInt OPENSSL_SSL_F_SSL23_ACCEPT = 0x73;
static const ShortInt OPENSSL_SSL_F_SSL23_CLIENT_HELLO = 0x74;
static const ShortInt OPENSSL_SSL_F_SSL23_CONNECT = 0x75;
static const ShortInt OPENSSL_SSL_F_SSL23_GET_CLIENT_HELLO = 0x76;
static const ShortInt OPENSSL_SSL_F_SSL23_GET_SERVER_HELLO = 0x77;
static const ShortInt OPENSSL_SSL_F_SSL23_READ = 0x78;
static const ShortInt OPENSSL_SSL_F_SSL23_WRITE = 0x79;
static const ShortInt OPENSSL_SSL_F_SSL2_ACCEPT = 0x7a;
static const ShortInt OPENSSL_SSL_F_SSL2_CONNECT = 0x7b;
static const ShortInt OPENSSL_SSL_F_SSL2_ENC_INIT = 0x7c;
static const ShortInt OPENSSL_SSL_F_SSL2_READ = 0x7d;
static const ShortInt OPENSSL_SSL_F_SSL2_SET_CERTIFICATE = 0x7e;
static const ShortInt OPENSSL_SSL_F_SSL2_WRITE = 0x7f;
static const Byte OPENSSL_SSL_F_SSL3_ACCEPT = 0x80;
static const Byte OPENSSL_SSL_F_SSL3_CHANGE_CIPHER_STATE = 0x81;
static const Byte OPENSSL_SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM = 0x82;
static const Byte OPENSSL_SSL_F_SSL3_CLIENT_HELLO = 0x83;
static const Byte OPENSSL_SSL_F_SSL3_CONNECT = 0x84;
static const Byte OPENSSL_SSL_F_SSL3_CTRL = 0xd5;
static const Byte OPENSSL_SSL_F_SSL3_CTX_CTRL = 0x85;
static const Word OPENSSL_SSL_F_SSL3_DO_CHANGE_CIPHER_SPEC = 0x117;
static const Byte OPENSSL_SSL_F_SSL3_ENC = 0x86;
static const Byte OPENSSL_SSL_F_SSL3_GET_CERTIFICATE_REQUEST = 0x87;
static const Word OPENSSL_SSL_F_SSL3_GET_CERT_STATUS = 0x120;
static const Byte OPENSSL_SSL_F_SSL3_GET_CERT_VERIFY = 0x88;
static const Byte OPENSSL_SSL_F_SSL3_GET_CLIENT_CERTIFICATE = 0x89;
static const Byte OPENSSL_SSL_F_SSL3_GET_CLIENT_HELLO = 0x8a;
static const Byte OPENSSL_SSL_F_SSL3_GET_CLIENT_KEY_EXCHANGE = 0x8b;
static const Byte OPENSSL_SSL_F_SSL3_GET_FINISHED = 0x8c;
static const Byte OPENSSL_SSL_F_SSL3_GET_KEY_EXCHANGE = 0x8d;
static const Byte OPENSSL_SSL_F_SSL3_GET_MESSAGE = 0x8e;
static const Word OPENSSL_SSL_F_SSL3_GET_NEW_SESSION_TICKET = 0x11b;
static const Byte OPENSSL_SSL_F_SSL3_GET_RECORD = 0x8f;
static const Byte OPENSSL_SSL_F_SSL3_GET_SERVER_CERTIFICATE = 0x90;
static const Byte OPENSSL_SSL_F_SSL3_GET_SERVER_DONE = 0x91;
static const Byte OPENSSL_SSL_F_SSL3_GET_SERVER_HELLO = 0x92;
static const Word OPENSSL_SSL_F_SSL3_NEW_SESSION_TICKET = 0x11c;
static const Byte OPENSSL_SSL_F_SSL3_OUTPUT_CERT_CHAIN = 0x93;
static const Byte OPENSSL_SSL_F_SSL3_READ_BYTES = 0x94;
static const Byte OPENSSL_SSL_F_SSL3_READ_N = 0x95;
static const Byte OPENSSL_SSL_F_SSL3_SEND_CERTIFICATE_REQUEST = 0x96;
static const Byte OPENSSL_SSL_F_SSL3_SEND_CLIENT_CERTIFICATE = 0x97;
static const Byte OPENSSL_SSL_F_SSL3_SEND_CLIENT_KEY_EXCHANGE = 0x98;
static const Byte OPENSSL_SSL_F_SSL3_SEND_CLIENT_VERIFY = 0x99;
static const Byte OPENSSL_SSL_F_SSL3_SEND_SERVER_CERTIFICATE = 0x9a;
static const Byte OPENSSL_SSL_F_SSL3_SEND_SERVER_KEY_EXCHANGE = 0x9b;
static const Byte OPENSSL_SSL_F_SSL3_SETUP_BUFFERS = 0x9c;
static const Byte OPENSSL_SSL_F_SSL3_SETUP_KEY_BLOCK = 0x9d;
static const Byte OPENSSL_SSL_F_SSL3_WRITE_BYTES = 0x9e;
static const Byte OPENSSL_SSL_F_SSL3_WRITE_PENDING = 0x9f;
static const Word OPENSSL_SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT = 0x110;
static const Byte OPENSSL_SSL_F_SSL_ADD_DIR_CERT_SUBJECTS_TO_STACK = 0xd7;
static const Byte OPENSSL_SSL_F_SSL_ADD_FILE_CERT_SUBJECTS_TO_STACK = 0xd8;
static const Word OPENSSL_SSL_F_SSL_ADD_SERVERHELLO_TLSEXT = 0x111;
static const Byte OPENSSL_SSL_F_SSL_BAD_METHOD = 0xa0;
static const Byte OPENSSL_SSL_F_SSL_BYTES_TO_CIPHER_LIST = 0xa1;
static const Byte OPENSSL_SSL_F_SSL_CERT_DUP = 0xdd;
static const Byte OPENSSL_SSL_F_SSL_CERT_INST = 0xde;
static const Byte OPENSSL_SSL_F_SSL_CERT_INSTANTIATE = 0xd6;
static const Byte OPENSSL_SSL_F_SSL_CERT_NEW = 0xa2;
static const Byte OPENSSL_SSL_F_SSL_CHECK_PRIVATE_KEY = 0xa3;
static const Word OPENSSL_SSL_F_SSL_CHECK_SERVERHELLO_TLSEXT = 0x112;
static const Byte OPENSSL_SSL_F_SSL_CIPHER_PROCESS_RULESTR = 0xe6;
static const Byte OPENSSL_SSL_F_SSL_CIPHER_STRENGTH_SORT = 0xe7;
static const Byte OPENSSL_SSL_F_SSL_CLEAR = 0xa4;
static const Byte OPENSSL_SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD = 0xa5;
static const Byte OPENSSL_SSL_F_SSL_CREATE_CIPHER_LIST = 0xa6;
static const Byte OPENSSL_SSL_F_SSL_CTRL = 0xe8;
static const Byte OPENSSL_SSL_F_SSL_CTX_CHECK_PRIVATE_KEY = 0xa8;
static const Byte OPENSSL_SSL_F_SSL_CTX_NEW = 0xa9;
static const Word OPENSSL_SSL_F_SSL_CTX_SET_CIPHER_LIST = 0x10d;
static const Word OPENSSL_SSL_F_SSL_CTX_SET_CLIENT_CERT_ENGINE = 0x116;
static const Byte OPENSSL_SSL_F_SSL_CTX_SET_PURPOSE = 0xe2;
static const Byte OPENSSL_SSL_F_SSL_CTX_SET_SESSION_ID_CONTEXT = 0xdb;
static const Byte OPENSSL_SSL_F_SSL_CTX_SET_SSL_VERSION = 0xaa;
static const Byte OPENSSL_SSL_F_SSL_CTX_SET_TRUST = 0xe5;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_CERTIFICATE = 0xab;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_CERTIFICATE_ASN1 = 0xac;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_CERTIFICATE_CHAIN_FILE = 0xdc;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_CERTIFICATE_FILE = 0xad;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_PRIVATEKEY = 0xae;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_PRIVATEKEY_ASN1 = 0xaf;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_PRIVATEKEY_FILE = 0xb0;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_RSAPRIVATEKEY = 0xb1;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_ASN1 = 0xb2;
static const Byte OPENSSL_SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_FILE = 0xb3;
static const Byte OPENSSL_SSL_F_SSL_DO_HANDSHAKE = 0xb4;
static const Byte OPENSSL_SSL_F_SSL_GET_NEW_SESSION = 0xb5;
static const Byte OPENSSL_SSL_F_SSL_GET_PREV_SESSION = 0xd9;
static const Byte OPENSSL_SSL_F_SSL_GET_SERVER_SEND_CERT = 0xb6;
static const Byte OPENSSL_SSL_F_SSL_GET_SIGN_PKEY = 0xb7;
static const Byte OPENSSL_SSL_F_SSL_INIT_WBIO_BUFFER = 0xb8;
static const Byte OPENSSL_SSL_F_SSL_LOAD_CLIENT_CA_FILE = 0xb9;
static const Byte OPENSSL_SSL_F_SSL_NEW = 0xba;
static const Word OPENSSL_SSL_F_SSL_PREPARE_CLIENTHELLO_TLSEXT = 0x113;
static const Word OPENSSL_SSL_F_SSL_PREPARE_SERVERHELLO_TLSEXT = 0x114;
static const Byte OPENSSL_SSL_F_SSL_READ = 0xdf;
static const Word OPENSSL_SSL_F_SSL_PEEK = 0x10e;
static const Byte OPENSSL_SSL_F_SSL_RSA_PRIVATE_DECRYPT = 0xbb;
static const Byte OPENSSL_SSL_F_SSL_RSA_PUBLIC_ENCRYPT = 0xbc;
static const Byte OPENSSL_SSL_F_SSL_SESSION_NEW = 0xbd;
static const Byte OPENSSL_SSL_F_SSL_SESSION_PRINT_FP = 0xbe;
static const Byte OPENSSL_SSL_F_SSL_SESS_CERT_NEW = 0xe1;
static const Byte OPENSSL_SSL_F_SSL_SET_CERT = 0xbf;
static const Byte OPENSSL_SSL_F_SSL_SET_FD = 0xc0;
static const Byte OPENSSL_SSL_F_SSL_SET_PKEY = 0xc1;
static const Byte OPENSSL_SSL_F_SSL_SET_RFD = 0xc2;
static const Byte OPENSSL_SSL_F_SSL_SET_SESSION = 0xc3;
static const Byte OPENSSL_SSL_F_SSL_SET_SESSION_ID_CONTEXT = 0xda;
static const Byte OPENSSL_SSL_F_SSL_SET_WFD = 0xc4;
static const Byte OPENSSL_SSL_F_SSL_SHUTDOWN = 0xe0;
static const Byte OPENSSL_SSL_F_SSL_UNDEFINED_FUNCTION = 0xc5;
static const Byte OPENSSL_SSL_F_SSL_USE_CERTIFICATE = 0xc6;
static const Byte OPENSSL_SSL_F_SSL_USE_CERTIFICATE_ASN1 = 0xc7;
static const Byte OPENSSL_SSL_F_SSL_USE_CERTIFICATE_FILE = 0xc8;
static const Byte OPENSSL_SSL_F_SSL_USE_PRIVATEKEY = 0xc9;
static const Byte OPENSSL_SSL_F_SSL_USE_PRIVATEKEY_ASN1 = 0xca;
static const Byte OPENSSL_SSL_F_SSL_USE_PRIVATEKEY_FILE = 0xcb;
static const Byte OPENSSL_SSL_F_SSL_USE_RSAPRIVATEKEY = 0xcc;
static const Byte OPENSSL_SSL_F_SSL_USE_RSAPRIVATEKEY_ASN1 = 0xcd;
static const Byte OPENSSL_SSL_F_SSL_USE_RSAPRIVATEKEY_FILE = 0xce;
static const Byte OPENSSL_SSL_F_SSL_VERIFY_CERT_CHAIN = 0xcf;
static const Byte OPENSSL_SSL_F_SSL_WRITE = 0xd0;
static const Byte OPENSSL_SSL_F_TLS1_CHANGE_CIPHER_STATE = 0xd1;
static const Byte OPENSSL_SSL_F_TLS1_ENC = 0xd2;
static const Byte OPENSSL_SSL_F_TLS1_SETUP_KEY_BLOCK = 0xd3;
static const Byte OPENSSL_SSL_F_WRITE_PENDING = 0xd4;
static const ShortInt OPENSSL_SSL_MAX_KEY_ARG_LENGTH = 0x8;
static const ShortInt OPENSSL_SSL_MAX_MASTER_KEY_LENGTH = 0x30;
static const ShortInt OPENSSL_SSL_MAX_SID_CTX_LENGTH = 0x20;
static const Word OPENSSL_SSL_MAX_KRB5_PRINCIPAL_LENGTH = 0x100;
static const ShortInt OPENSSL_SSL_MAX_SSL_SESSION_ID_LENGTH = 0x20;
static const ShortInt OPENSSL_SSL_MODE_ENABLE_PARTIAL_WRITE = 0x1;
static const ShortInt OPENSSL_SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER = 0x2;
static const ShortInt OPENSSL_SSL_MODE_AUTO_RETRY = 0x4;
static const ShortInt OPENSSL_SSL_MODE_NO_AUTO_CHAIN = 0x8;
static const ShortInt OPENSSL_SSL_NOTHING = 0x1;
static const ShortInt OPENSSL_SSL_OP_MICROSOFT_SESS_ID_BUG = 0x1;
static const ShortInt OPENSSL_SSL_OP_NETSCAPE_CHALLENGE_BUG = 0x2;
static const ShortInt OPENSSL_SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG = 0x8;
static const ShortInt OPENSSL_SSL_OP_SSLREF2_REUSE_CERT_TYPE_BUG = 0x10;
static const ShortInt OPENSSL_SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER = 0x20;
static const ShortInt OPENSSL_SSL_OP_MSIE_SSLV2_RSA_PADDING = 0x40;
static const Byte OPENSSL_SSL_OP_SSLEAY_080_CLIENT_DH_BUG = 0x80;
static const Word OPENSSL_SSL_OP_TLS_D5_BUG = 0x100;
static const Word OPENSSL_SSL_OP_TLS_BLOCK_PADDING_BUG = 0x200;
static const Word OPENSSL_SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS = 0x800;
static const Word OPENSSL_SSL_OP_ALL = 0xfff;
static const Word OPENSSL_SSL_OP_NO_QUERY_MTU = 0x1000;
static const Word OPENSSL_SSL_OP_COOKIE_EXCHANGE = 0x2000;
static const Word OPENSSL_SSL_OP_NO_TICKET = 0x4000;
static const int OPENSSL_SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION = 0x10000;
static const int OPENSSL_SSL_OP_SINGLE_ECDH_USE = 0x80000;
static const int OPENSSL_SSL_OP_SINGLE_DH_USE = 0x100000;
static const int OPENSSL_SSL_OP_EPHEMERAL_RSA = 0x200000;
static const int OPENSSL_SSL_OP_CIPHER_SERVER_PREFERENCE = 0x400000;
static const int OPENSSL_SSL_OP_TLS_ROLLBACK_BUG = 0x800000;
static const int OPENSSL_SSL_OP_NO_SSLv2 = 0x1000000;
static const int OPENSSL_SSL_OP_NO_SSLv3 = 0x2000000;
static const int OPENSSL_SSL_OP_NO_TLSv1 = 0x4000000;
static const int OPENSSL_SSL_OP_PKCS1_CHECK_1 = 0x8000000;
static const int OPENSSL_SSL_OP_PKCS1_CHECK_2 = 0x10000000;
static const int OPENSSL_SSL_OP_NETSCAPE_CA_DN_BUG = 0x20000000;
static const int OPENSSL_SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG = 0x40000000;
static const ShortInt OPENSSL_SSL_READING = 0x3;
static const ShortInt OPENSSL_SSL_RECEIVED_SHUTDOWN = 0x2;
static const ShortInt OPENSSL_SSL_R_APP_DATA_IN_HANDSHAKE = 0x64;
static const Word OPENSSL_SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT = 0x110;
static const ShortInt OPENSSL_SSL_R_BAD_ALERT_RECORD = 0x65;
static const ShortInt OPENSSL_SSL_R_BAD_AUTHENTICATION_TYPE = 0x66;
static const ShortInt OPENSSL_SSL_R_BAD_CHANGE_CIPHER_SPEC = 0x67;
static const ShortInt OPENSSL_SSL_R_BAD_CHECKSUM = 0x68;
static const ShortInt OPENSSL_SSL_R_BAD_CLIENT_REQUEST = 0x69;
static const ShortInt OPENSSL_SSL_R_BAD_DATA_RETURNED_BY_CALLBACK = 0x6a;
static const ShortInt OPENSSL_SSL_R_BAD_DECOMPRESSION = 0x6b;
static const ShortInt OPENSSL_SSL_R_BAD_DH_G_LENGTH = 0x6c;
static const ShortInt OPENSSL_SSL_R_BAD_DH_PUB_KEY_LENGTH = 0x6d;
static const ShortInt OPENSSL_SSL_R_BAD_DH_P_LENGTH = 0x6e;
static const ShortInt OPENSSL_SSL_R_BAD_DIGEST_LENGTH = 0x6f;
static const ShortInt OPENSSL_SSL_R_BAD_DSA_SIGNATURE = 0x70;
static const Word OPENSSL_SSL_R_BAD_LENGTH = 0x10f;
static const ShortInt OPENSSL_SSL_R_BAD_MAC_DECODE = 0x71;
static const ShortInt OPENSSL_SSL_R_BAD_MESSAGE_TYPE = 0x72;
static const ShortInt OPENSSL_SSL_R_BAD_PACKET_LENGTH = 0x73;
static const ShortInt OPENSSL_SSL_R_BAD_PROTOCOL_VERSION_NUMBER = 0x74;
static const ShortInt OPENSSL_SSL_R_BAD_RESPONSE_ARGUMENT = 0x75;
static const ShortInt OPENSSL_SSL_R_BAD_RSA_DECRYPT = 0x76;
static const ShortInt OPENSSL_SSL_R_BAD_RSA_ENCRYPT = 0x77;
static const ShortInt OPENSSL_SSL_R_BAD_RSA_E_LENGTH = 0x78;
static const ShortInt OPENSSL_SSL_R_BAD_RSA_MODULUS_LENGTH = 0x79;
static const ShortInt OPENSSL_SSL_R_BAD_RSA_SIGNATURE = 0x7a;
static const ShortInt OPENSSL_SSL_R_BAD_SIGNATURE = 0x7b;
static const ShortInt OPENSSL_SSL_R_BAD_SSL_FILETYPE = 0x7c;
static const ShortInt OPENSSL_SSL_R_BAD_SSL_SESSION_ID_LENGTH = 0x7d;
static const ShortInt OPENSSL_SSL_R_BAD_STATE = 0x7e;
static const ShortInt OPENSSL_SSL_R_BAD_WRITE_RETRY = 0x7f;
static const Byte OPENSSL_SSL_R_BIO_NOT_SET = 0x80;
static const Byte OPENSSL_SSL_R_BLOCK_CIPHER_PAD_IS_WRONG = 0x81;
static const Byte OPENSSL_SSL_R_BN_LIB = 0x82;
static const Byte OPENSSL_SSL_R_CA_DN_LENGTH_MISMATCH = 0x83;
static const Byte OPENSSL_SSL_R_CA_DN_TOO_LONG = 0x84;
static const Byte OPENSSL_SSL_R_CCS_RECEIVED_EARLY = 0x85;
static const Byte OPENSSL_SSL_R_CERTIFICATE_VERIFY_FAILED = 0x86;
static const Byte OPENSSL_SSL_R_CERT_LENGTH_MISMATCH = 0x87;
static const Byte OPENSSL_SSL_R_CHALLENGE_IS_DIFFERENT = 0x88;
static const Byte OPENSSL_SSL_R_CIPHER_CODE_WRONG_LENGTH = 0x89;
static const Byte OPENSSL_SSL_R_CIPHER_OR_HASH_UNAVAILABLE = 0x8a;
static const Byte OPENSSL_SSL_R_CIPHER_TABLE_SRC_ERROR = 0x8b;
static const Byte OPENSSL_SSL_R_CLIENTHELLO_TLSEXT = 0x9d;
static const Byte OPENSSL_SSL_R_COMPRESSED_LENGTH_TOO_LONG = 0x8c;
static const Byte OPENSSL_SSL_R_COMPRESSION_FAILURE = 0x8d;
static const Byte OPENSSL_SSL_R_COMPRESSION_LIBRARY_ERROR = 0x8e;
static const Byte OPENSSL_SSL_R_CONNECTION_ID_IS_DIFFERENT = 0x8f;
static const Byte OPENSSL_SSL_R_CONNECTION_TYPE_NOT_SET = 0x90;
static const Byte OPENSSL_SSL_R_DATA_BETWEEN_CCS_AND_FINISHED = 0x91;
static const Byte OPENSSL_SSL_R_DATA_LENGTH_TOO_LONG = 0x92;
static const Byte OPENSSL_SSL_R_DECRYPTION_FAILED = 0x93;
static const Byte OPENSSL_SSL_R_DH_PUBLIC_VALUE_LENGTH_IS_WRONG = 0x94;
static const Byte OPENSSL_SSL_R_DIGEST_CHECK_FAILED = 0x95;
static const Byte OPENSSL_SSL_R_ENCRYPTED_LENGTH_TOO_LONG = 0x96;
static const Byte OPENSSL_SSL_R_ERROR_IN_RECEIVED_CIPHER_LIST = 0x97;
static const Byte OPENSSL_SSL_R_EXCESSIVE_MESSAGE_SIZE = 0x98;
static const Byte OPENSSL_SSL_R_EXTRA_DATA_IN_MESSAGE = 0x99;
static const Byte OPENSSL_SSL_R_GOT_A_FIN_BEFORE_A_CCS = 0x9a;
static const Byte OPENSSL_SSL_R_HTTPS_PROXY_REQUEST = 0x9b;
static const Byte OPENSSL_SSL_R_HTTP_REQUEST = 0x9c;
static const Byte OPENSSL_SSL_R_INTERNAL_ERROR = 0x9d;
static const Byte OPENSSL_SSL_R_INVALID_CHALLENGE_LENGTH = 0x9e;
static const Word OPENSSL_SSL_R_INVALID_COMMAND = 0x118;
static const Word OPENSSL_SSL_R_INVALID_PURPOSE = 0x116;
static const Word OPENSSL_SSL_R_INVALID_STATUS_RESPONSE = 0x13c;
static const Word OPENSSL_SSL_R_INVALID_TICKET_KEYS_LENGTH = 0x113;
static const Word OPENSSL_SSL_R_INVALID_TRUST = 0x117;
static const Byte OPENSSL_SSL_R_LENGTH_MISMATCH = 0x9f;
static const Byte OPENSSL_SSL_R_LENGTH_TOO_SHORT = 0xa0;
static const Word OPENSSL_SSL_R_LIBRARY_BUG = 0x112;
static const Byte OPENSSL_SSL_R_LIBRARY_HAS_NO_CIPHERS = 0xa1;
static const Byte OPENSSL_SSL_R_MISSING_DH_DSA_CERT = 0xa2;
static const Byte OPENSSL_SSL_R_MISSING_DH_KEY = 0xa3;
static const Byte OPENSSL_SSL_R_MISSING_DH_RSA_CERT = 0xa4;
static const Byte OPENSSL_SSL_R_MISSING_DSA_SIGNING_CERT = 0xa5;
static const Byte OPENSSL_SSL_R_MISSING_EXPORT_TMP_DH_KEY = 0xa6;
static const Byte OPENSSL_SSL_R_MISSING_EXPORT_TMP_RSA_KEY = 0xa7;
static const Byte OPENSSL_SSL_R_MISSING_RSA_CERTIFICATE = 0xa8;
static const Byte OPENSSL_SSL_R_MISSING_RSA_ENCRYPTING_CERT = 0xa9;
static const Byte OPENSSL_SSL_R_MISSING_RSA_SIGNING_CERT = 0xaa;
static const Byte OPENSSL_SSL_R_MISSING_TMP_DH_KEY = 0xab;
static const Byte OPENSSL_SSL_R_MISSING_TMP_RSA_KEY = 0xac;
static const Byte OPENSSL_SSL_R_MISSING_TMP_RSA_PKEY = 0xad;
static const Byte OPENSSL_SSL_R_MISSING_VERIFY_MESSAGE = 0xae;
static const Byte OPENSSL_SSL_R_NON_SSLV2_INITIAL_PACKET = 0xaf;
static const Byte OPENSSL_SSL_R_NO_CERTIFICATES_RETURNED = 0xb0;
static const Byte OPENSSL_SSL_R_NO_CERTIFICATE_ASSIGNED = 0xb1;
static const Byte OPENSSL_SSL_R_NO_CERTIFICATE_RETURNED = 0xb2;
static const Byte OPENSSL_SSL_R_NO_CERTIFICATE_SET = 0xb3;
static const Byte OPENSSL_SSL_R_NO_CERTIFICATE_SPECIFIED = 0xb4;
static const Byte OPENSSL_SSL_R_NO_CIPHERS_AVAILABLE = 0xb5;
static const Byte OPENSSL_SSL_R_NO_CIPHERS_PASSED = 0xb6;
static const Byte OPENSSL_SSL_R_NO_CIPHERS_SPECIFIED = 0xb7;
static const Byte OPENSSL_SSL_R_NO_CIPHER_LIST = 0xb8;
static const Byte OPENSSL_SSL_R_NO_CIPHER_MATCH = 0xb9;
static const Word OPENSSL_SSL_R_NO_CLIENT_CERT_METHOD = 0x13d;
static const Byte OPENSSL_SSL_R_NO_CLIENT_CERT_RECEIVED = 0xba;
static const Byte OPENSSL_SSL_R_NO_COMPRESSION_SPECIFIED = 0xbb;
static const Byte OPENSSL_SSL_R_NO_METHOD_SPECIFIED = 0xbc;
static const Byte OPENSSL_SSL_R_NO_PRIVATEKEY = 0xbd;
static const Byte OPENSSL_SSL_R_NO_PRIVATE_KEY_ASSIGNED = 0xbe;
static const Byte OPENSSL_SSL_R_NO_PROTOCOLS_AVAILABLE = 0xbf;
static const Byte OPENSSL_SSL_R_NO_PUBLICKEY = 0xc0;
static const Byte OPENSSL_SSL_R_NO_SHARED_CIPHER = 0xc1;
static const Byte OPENSSL_SSL_R_NO_VERIFY_CALLBACK = 0xc2;
static const Byte OPENSSL_SSL_R_NULL_SSL_CTX = 0xc3;
static const Byte OPENSSL_SSL_R_NULL_SSL_METHOD_PASSED = 0xc4;
static const Byte OPENSSL_SSL_R_OLD_SESSION_CIPHER_NOT_RETURNED = 0xc5;
static const Word OPENSSL_SSL_R_ONLY_TLS_ALLOWED_IN_FIPS_MODE = 0x129;
static const Byte OPENSSL_SSL_R_PACKET_LENGTH_TOO_LONG = 0xc6;
static const Byte OPENSSL_SSL_R_PARSE_TLSEXT = 0xdf;
static const Word OPENSSL_SSL_R_PATH_TOO_LONG = 0x10e;
static const Byte OPENSSL_SSL_R_PEER_DID_NOT_RETURN_A_CERTIFICATE = 0xc7;
static const Byte OPENSSL_SSL_R_PEER_ERROR = 0xc8;
static const Byte OPENSSL_SSL_R_PEER_ERROR_CERTIFICATE = 0xc9;
static const Byte OPENSSL_SSL_R_PEER_ERROR_NO_CERTIFICATE = 0xca;
static const Byte OPENSSL_SSL_R_PEER_ERROR_NO_CIPHER = 0xcb;
static const Byte OPENSSL_SSL_R_PEER_ERROR_UNSUPPORTED_CERTIFICATE_TYPE = 0xcc;
static const Byte OPENSSL_SSL_R_PRE_MAC_LENGTH_TOO_LONG = 0xcd;
static const Byte OPENSSL_SSL_R_PROBLEMS_MAPPING_CIPHER_FUNCTIONS = 0xce;
static const Byte OPENSSL_SSL_R_PROTOCOL_IS_SHUTDOWN = 0xcf;
static const Byte OPENSSL_SSL_R_PUBLIC_KEY_ENCRYPT_ERROR = 0xd0;
static const Byte OPENSSL_SSL_R_PUBLIC_KEY_IS_NOT_RSA = 0xd1;
static const Byte OPENSSL_SSL_R_PUBLIC_KEY_NOT_RSA = 0xd2;
static const Byte OPENSSL_SSL_R_READ_BIO_NOT_SET = 0xd3;
static const Byte OPENSSL_SSL_R_READ_WRONG_PACKET_TYPE = 0xd4;
static const Byte OPENSSL_SSL_R_RECORD_LENGTH_MISMATCH = 0xd5;
static const Byte OPENSSL_SSL_R_RECORD_TOO_LARGE = 0xd6;
static const Byte OPENSSL_SSL_R_REQUIRED_CIPHER_MISSING = 0xd7;
static const Byte OPENSSL_SSL_R_REUSE_CERT_LENGTH_NOT_ZERO = 0xd8;
static const Byte OPENSSL_SSL_R_REUSE_CERT_TYPE_NOT_ZERO = 0xd9;
static const Byte OPENSSL_SSL_R_REUSE_CIPHER_LIST_NOT_ZERO = 0xda;
static const Byte OPENSSL_SSL_R_SERVERHELLO_TLSEXT = 0xe0;
static const Word OPENSSL_SSL_R_SESSION_ID_CONTEXT_UNINITIALIZED = 0x115;
static const Byte OPENSSL_SSL_R_SHORT_READ = 0xdb;
static const Byte OPENSSL_SSL_R_SIGNATURE_FOR_NON_SIGNING_CERTIFICATE = 0xdc;
static const Byte OPENSSL_SSL_R_SSL23_DOING_SESSION_ID_REUSE = 0xdd;
static const Word OPENSSL_SSL_R_SSL2_CONNECTION_ID_TOO_LONG = 0x12b;
static const Byte OPENSSL_SSL_R_SSL3_EXT_INVALID_SERVERNAME = 0xe1;
static const Byte OPENSSL_SSL_R_SSL3_EXT_INVALID_SERVERNAME_TYPE = 0xe2;
static const Word OPENSSL_SSL_R_SSL3_SESSION_ID_TOO_LONG = 0x12c;
static const Byte OPENSSL_SSL_R_SSL3_SESSION_ID_TOO_SHORT = 0xde;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_BAD_CERTIFICATE = 0x412;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_BAD_RECORD_MAC = 0x3fc;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_CERTIFICATE_EXPIRED = 0x415;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_CERTIFICATE_REVOKED = 0x414;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_CERTIFICATE_UNKNOWN = 0x416;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_DECOMPRESSION_FAILURE = 0x406;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_HANDSHAKE_FAILURE = 0x410;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_ILLEGAL_PARAMETER = 0x417;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_NO_CERTIFICATE = 0x411;
static const Byte OPENSSL_SSL_R_SSLV3_ALERT_PEER_ERROR_CERTIFICATE = 0xdf;
static const Byte OPENSSL_SSL_R_SSLV3_ALERT_PEER_ERROR_NO_CERTIFICATE = 0xe0;
static const Byte OPENSSL_SSL_R_SSLV3_ALERT_PEER_ERROR_NO_CIPHER = 0xe1;
static const Byte OPENSSL_SSL_R_SSLV3_ALERT_PEER_ERROR_UNSUPPORTED_CERTIFICATE_TYPE = 0xe2;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_UNEXPECTED_MESSAGE = 0x3f2;
static const Byte OPENSSL_SSL_R_SSLV3_ALERT_UNKNOWN_REMOTE_ERROR_TYPE = 0xe3;
static const Word OPENSSL_SSL_R_SSLV3_ALERT_UNSUPPORTED_CERTIFICATE = 0x413;
static const Byte OPENSSL_SSL_R_SSL_CTX_HAS_NO_DEFAULT_SSL_VERSION = 0xe4;
static const Byte OPENSSL_SSL_R_SSL_HANDSHAKE_FAILURE = 0xe5;
static const Byte OPENSSL_SSL_R_SSL_LIBRARY_HAS_NO_CIPHERS = 0xe6;
static const Word OPENSSL_SSL_R_SSL_SESSION_ID_CONTEXT_TOO_LONG = 0x111;
static const Byte OPENSSL_SSL_R_SSL_SESSION_ID_IS_DIFFERENT = 0xe7;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_ACCESS_DENIED = 0x419;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_DECODE_ERROR = 0x41a;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_DECRYPTION_FAILED = 0x3fd;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_DECRYPT_ERROR = 0x41b;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_EXPORT_RESTRICION = 0x424;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_INSUFFICIENT_SECURITY = 0x42f;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_INTERNAL_ERROR = 0x438;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_NO_RENEGOTIATION = 0x44c;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_PROTOCOL_VERSION = 0x42e;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_RECORD_OVERFLOW = 0x3fe;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_UNKNOWN_CA = 0x418;
static const Word OPENSSL_SSL_R_TLSV1_ALERT_USER_CANCLED = 0x442;
static const Byte OPENSSL_SSL_R_TLS_CLIENT_CERT_REQ_WITH_ANON_CIPHER = 0xe8;
static const Byte OPENSSL_SSL_R_TLS_INVALID_ECPOINTFORMAT_LIST = 0xe3;
static const Byte OPENSSL_SSL_R_TLS_PEER_DID_NOT_RESPOND_WITH_CERTIFICATE_LIST = 0xe9;
static const Byte OPENSSL_SSL_R_TLS_RSA_ENCRYPTED_VALUE_LENGTH_IS_WRONG = 0xea;
static const Byte OPENSSL_SSL_R_TRIED_TO_USE_UNSUPPORTED_CIPHER = 0xeb;
static const Byte OPENSSL_SSL_R_UNABLE_TO_DECODE_DH_CERTS = 0xec;
static const Byte OPENSSL_SSL_R_UNABLE_TO_EXTRACT_PUBLIC_KEY = 0xed;
static const Byte OPENSSL_SSL_R_UNABLE_TO_FIND_DH_PARAMETERS = 0xee;
static const Byte OPENSSL_SSL_R_UNABLE_TO_FIND_PUBLIC_KEY_PARAMETERS = 0xef;
static const Byte OPENSSL_SSL_R_UNABLE_TO_FIND_SSL_METHOD = 0xf0;
static const Byte OPENSSL_SSL_R_UNABLE_TO_LOAD_SSL2_MD5_ROUTINES = 0xf1;
static const Byte OPENSSL_SSL_R_UNABLE_TO_LOAD_SSL3_MD5_ROUTINES = 0xf2;
static const Byte OPENSSL_SSL_R_UNABLE_TO_LOAD_SSL3_SHA1_ROUTINES = 0xf3;
static const Byte OPENSSL_SSL_R_UNEXPECTED_MESSAGE = 0xf4;
static const Byte OPENSSL_SSL_R_UNEXPECTED_RECORD = 0xf5;
static const Word OPENSSL_SSL_R_UNINITIALIZED = 0x114;
static const Byte OPENSSL_SSL_R_UNKNOWN_ALERT_TYPE = 0xf6;
static const Byte OPENSSL_SSL_R_UNKNOWN_CERTIFICATE_TYPE = 0xf7;
static const Byte OPENSSL_SSL_R_UNKNOWN_CIPHER_RETURNED = 0xf8;
static const Byte OPENSSL_SSL_R_UNKNOWN_CIPHER_TYPE = 0xf9;
static const Byte OPENSSL_SSL_R_UNKNOWN_KEY_EXCHANGE_TYPE = 0xfa;
static const Byte OPENSSL_SSL_R_UNKNOWN_PKEY_TYPE = 0xfb;
static const Byte OPENSSL_SSL_R_UNKNOWN_PROTOCOL = 0xfc;
static const Byte OPENSSL_SSL_R_UNKNOWN_REMOTE_ERROR_TYPE = 0xfd;
static const Byte OPENSSL_SSL_R_UNKNOWN_SSL_VERSION = 0xfe;
static const Word OPENSSL_SSL_R_UNSUPPORTED_STATUS_TYPE = 0x149;
static const Byte OPENSSL_SSL_R_UNKNOWN_STATE = 0xff;
static const Word OPENSSL_SSL_R_UNSUPPORTED_CIPHER = 0x100;
static const Word OPENSSL_SSL_R_UNSUPPORTED_COMPRESSION_ALGORITHM = 0x101;
static const Word OPENSSL_SSL_R_UNSUPPORTED_PROTOCOL = 0x102;
static const Word OPENSSL_SSL_R_UNSUPPORTED_SSL_VERSION = 0x103;
static const Word OPENSSL_SSL_R_WRITE_BIO_NOT_SET = 0x104;
static const Word OPENSSL_SSL_R_WRONG_CIPHER_RETURNED = 0x105;
static const Word OPENSSL_SSL_R_WRONG_MESSAGE_TYPE = 0x106;
static const Word OPENSSL_SSL_R_WRONG_NUMBER_OF_KEY_BITS = 0x107;
static const Word OPENSSL_SSL_R_WRONG_SIGNATURE_LENGTH = 0x108;
static const Word OPENSSL_SSL_R_WRONG_SIGNATURE_SIZE = 0x109;
static const Word OPENSSL_SSL_R_WRONG_SSL_VERSION = 0x10a;
static const Word OPENSSL_SSL_R_WRONG_VERSION_NUMBER = 0x10b;
static const Word OPENSSL_SSL_R_X509_LIB = 0x10c;
static const Word OPENSSL_SSL_R_X509_VERIFICATION_SETUP_PROBLEMS = 0x10d;
static const ShortInt OPENSSL_SSL_SENT_SHUTDOWN = 0x1;
static const ShortInt OPENSSL_SSL_SESSION_ASN1_VERSION = 0x1;
static const Word OPENSSL_SSL_SESSION_CACHE_MAX_SIZE_DEFAULT = 0x5000;
static const ShortInt OPENSSL_SSL_SESS_CACHE_CLIENT = 0x1;
static const ShortInt OPENSSL_SSL_SESS_CACHE_SERVER = 0x2;
static const ShortInt OPENSSL_SSL_SESS_CACHE_BOTH = 0x3;
static const Byte OPENSSL_SSL_SESS_CACHE_NO_AUTO_CLEAR = 0x80;
static const Word OPENSSL_SSL_SESS_CACHE_NO_INTERNAL_LOOKUP = 0x100;
static const ShortInt OPENSSL_SSL_SESS_CACHE_OFF = 0x0;
static const Word OPENSSL_SSL_ST_BEFORE = 0x4000;
static const Word OPENSSL_SSL_ST_INIT = 0x3000;
static const Word OPENSSL_SSL_ST_MASK = 0xfff;
static const ShortInt OPENSSL_SSL_ST_OK = 0x3;
static const Byte OPENSSL_SSL_ST_READ_BODY = 0xf1;
static const Byte OPENSSL_SSL_ST_READ_DONE = 0xf2;
static const Byte OPENSSL_SSL_ST_READ_HEADER = 0xf0;
static const Word OPENSSL_SSL_ST_RENEGOTIATE = 0x3004;
#define OPENSSL_SSL_TXT_LOW L"LOW"
#define OPENSSL_SSL_TXT_MEDIUM L"MEDIUM"
#define OPENSSL_SSL_TXT_HIGH L"HIGH"
#define OPENSSL_SSL_TXT_FIPS L"FIPS"
#define OPENSSL_SSL_TXT_kFZA L"kFZA"
#define OPENSSL_SSL_TXT_aFZA L"aFZA"
#define OPENSSL_SSL_TXT_eFZA L"eFZA"
#define OPENSSL_SSL_TXT_FZA L"FZA"
#define OPENSSL_SSL_TXT_aNULL L"aNULL"
#define OPENSSL_SSL_TXT_eNULL L"eNULL"
#define OPENSSL_SSL_TXT_NULL L"NULL"
#define OPENSSL_SSL_TXT_kKRB5 L"kKRB5"
#define OPENSSL_SSL_TXT_aKRB5 L"aKRB5"
#define OPENSSL_SSL_TXT_KRB5 L"KRB5"
#define OPENSSL_SSL_TXT_kRSA L"kRSA"
#define OPENSSL_SSL_TXT_kDHr L"kDHr"
#define OPENSSL_SSL_TXT_kDHd L"kDHd"
#define OPENSSL_SSL_TXT_kEDH L"kEDH"
#define OPENSSL_SSL_TXT_aRSA L"aRSA"
#define OPENSSL_SSL_TXT_aDSS L"aDSS"
#define OPENSSL_SSL_TXT_aDH L"aDH"
#define OPENSSL_SSL_TXT_RSA L"RSA"
#define OPENSSL_SSL_TXT_DH L"DH"
#define OPENSSL_SSL_TXT_EDH L"EDH"
#define OPENSSL_SSL_TXT_ADH_C L"ADH"
#define OPENSSL_SSL_TXT_aDH_S L"aDH"
#define OPENSSL_SSL_TXT_DSS L"DSS"
#define OPENSSL_SSL_TXT_DES L"DES"
#define OPENSSL_SSL_TXT_3DES L"3DES"
#define OPENSSL_SSL_TXT_RC4 L"RC4"
#define OPENSSL_SSL_TXT_RC2 L"RC2"
#define OPENSSL_SSL_TXT_IDEA L"IDEA"
#define OPENSSL_SSL_TXT_SEED L"SEED"
#define OPENSSL_SSL_TXT_AES L"AES"
#define OPENSSL_SSL_TXT_CAMELLIA L"CAMELLIA"
#define OPENSSL_SSL_TXT_MD5 L"MD5"
#define OPENSSL_SSL_TXT_SHA1 L"SHA1"
#define OPENSSL_SSL_TXT_SHA L"SHA"
#define OPENSSL_SSL_TXT_EXP L"EXP"
#define OPENSSL_SSL_TXT_EXPORT L"EXPORT"
#define OPENSSL_SSL_TXT_EXP40 L"EXPORT40"
#define OPENSSL_SSL_TXT_EXP56 L"EXPORT56"
#define OPENSSL_SSL_TXT_SSLV2 L"SSLv2"
#define OPENSSL_SSL_TXT_SSLV3 L"SSLv3"
#define OPENSSL_SSL_TXT_TLSV1 L"TLSv1"
#define OPENSSL_SSL_TXT_ALL L"ALL"
#define OPENSSL_SSL_TXT_ECC L"ECCdraft"
#define OPENSSL_SSL_TXT_DES_192_EDE3_CBC_WITH_MD5 L"DES-CBC3-MD5"
#define OPENSSL_SSL_TXT_DES_192_EDE3_CBC_WITH_SHA L"DES-CBC3-SHA"
#define OPENSSL_SSL_TXT_DES_64_CBC_WITH_MD5 L"DES-CBC-MD5"
#define OPENSSL_SSL_TXT_DES_64_CBC_WITH_SHA L"DES-CBC-SHA"
#define OPENSSL_SSL_TXT_IDEA_128_CBC_WITH_MD5 L"IDEA-CBC-MD5"
#define OPENSSL_SSL_TXT_NULL_WITH_MD5 L"NULL-MD5"
#define OPENSSL_SSL_TXT_RC2_128_CBC_EXPORT40_WITH_MD5 L"EXP-RC2-CBC-MD5"
#define OPENSSL_SSL_TXT_RC2_128_CBC_WITH_MD5 L"RC2-CBC-MD5"
#define OPENSSL_SSL_TXT_RC4_128_EXPORT40_WITH_MD5 L"EXP-RC4-MD5"
#define OPENSSL_SSL_TXT_RC4_128_WITH_MD5 L"RC4-MD5"
static const ShortInt OPENSSL_SSL_VERIFY_CLIENT_ONCE = 0x4;
static const ShortInt OPENSSL_SSL_VERIFY_FAIL_IF_NO_PEER_CERT = 0x2;
static const ShortInt OPENSSL_SSL_VERIFY_NONE = 0x0;
static const ShortInt OPENSSL_SSL_VERIFY_PEER = 0x1;
static const ShortInt OPENSSL_SSL_WRITING = 0x2;
static const ShortInt OPENSSL_SSL_X509_LOOKUP = 0x4;
static const ShortInt OPENSSL_TLS1_ALLOW_EXPERIMENTAL_CIPHERSUITES = 0x0;
static const Word OPENSSL_TLS1_VERSION = 0x301;
static const ShortInt OPENSSL_TLS1_VERSION_MAJOR = 0x3;
static const ShortInt OPENSSL_TLS1_VERSION_MINOR = 0x1;
static const int OPENSSL_TLS1_CK_RSA_EXPORT1024_WITH_RC4_56_MD5 = 0x3000060;
static const int OPENSSL_TLS1_CK_RSA_EXPORT1024_WITH_RC2_CBC_56_MD5 = 0x3000061;
static const int OPENSSL_TLS1_CK_RSA_EXPORT1024_WITH_DES_CBC_SHA = 0x3000062;
static const int OPENSSL_TLS1_CK_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA = 0x3000063;
static const int OPENSSL_TLS1_CK_RSA_EXPORT1024_WITH_RC4_56_SHA = 0x3000064;
static const int OPENSSL_TLS1_CK_DHE_DSS_EXPORT1024_WITH_RC4_56_SHA = 0x3000065;
static const int OPENSSL_TLS1_CK_DHE_DSS_WITH_RC4_128_SHA = 0x3000066;
static const int OPENSSL_TLS1_CK_RSA_WITH_AES_128_SHA = 0x300002f;
static const int OPENSSL_TLS1_CK_DH_DSS_WITH_AES_128_SHA = 0x3000030;
static const int OPENSSL_TLS1_CK_DH_RSA_WITH_AES_128_SHA = 0x3000031;
static const int OPENSSL_TLS1_CK_DHE_DSS_WITH_AES_128_SHA = 0x3000032;
static const int OPENSSL_TLS1_CK_DHE_RSA_WITH_AES_128_SHA = 0x3000033;
static const int OPENSSL_TLS1_CK_ADH_WITH_AES_128_SHA = 0x3000034;
static const int OPENSSL_TLS1_CK_RSA_WITH_AES_256_SHA = 0x3000035;
static const int OPENSSL_TLS1_CK_DH_DSS_WITH_AES_256_SHA = 0x3000036;
static const int OPENSSL_TLS1_CK_DH_RSA_WITH_AES_256_SHA = 0x3000037;
static const int OPENSSL_TLS1_CK_DHE_DSS_WITH_AES_256_SHA = 0x3000038;
static const int OPENSSL_TLS1_CK_DHE_RSA_WITH_AES_256_SHA = 0x3000039;
static const int OPENSSL_TLS1_CK_ADH_WITH_AES_256_SHA = 0x300003a;
static const int OPENSSL_TLS1_CK_RSA_WITH_CAMELLIA_128_CBC_SHA = 0x3000041;
static const int OPENSSL_TLS1_CK_DH_DSS_WITH_CAMELLIA_128_CBC_SHA = 0x3000042;
static const int OPENSSL_TLS1_CK_DH_RSA_WITH_CAMELLIA_128_CBC_SHA = 0x3000043;
static const int OPENSSL_TLS1_CK_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA = 0x3000044;
static const int OPENSSL_TLS1_CK_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA = 0x3000045;
static const int OPENSSL_TLS1_CK_ADH_WITH_CAMELLIA_128_CBC_SHA = 0x3000046;
static const int OPENSSL_TLS1_CK_RSA_WITH_CAMELLIA_256_CBC_SHA = 0x3000084;
static const int OPENSSL_TLS1_CK_DH_DSS_WITH_CAMELLIA_256_CBC_SHA = 0x3000085;
static const int OPENSSL_TLS1_CK_DH_RSA_WITH_CAMELLIA_256_CBC_SHA = 0x3000086;
static const int OPENSSL_TLS1_CK_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA = 0x3000087;
static const int OPENSSL_TLS1_CK_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA = 0x3000088;
static const int OPENSSL_TLS1_CK_ADH_WITH_CAMELLIA_256_CBC_SHA = 0x3000089;
static const int OPENSSL_TLS1_CK_RSA_WITH_SEED_SHA = 0x3000096;
static const int OPENSSL_TLS1_CK_DH_DSS_WITH_SEED_SHA = 0x3000097;
static const int OPENSSL_TLS1_CK_DH_RSA_WITH_SEED_SHA = 0x3000098;
static const int OPENSSL_TLS1_CK_DHE_DSS_WITH_SEED_SHA = 0x3000099;
static const int OPENSSL_TLS1_CK_DHE_RSA_WITH_SEED_SHA = 0x300009a;
static const int OPENSSL_TLS1_CK_ADH_WITH_SEED_SHA = 0x300009b;
static const int OPENSSL_TLS1_CK_ECDH_ECDSA_WITH_NULL_SHA = 0x300c001;
static const int OPENSSL_TLS1_CK_ECDH_ECDSA_WITH_RC4_128_SHA = 0x300c002;
static const int OPENSSL_TLS1_CK_ECDH_ECDSA_WITH_DES_192_CBC3_SHA = 0x300c003;
static const int OPENSSL_TLS1_CK_ECDH_ECDSA_WITH_AES_128_CBC_SHA = 0x300c004;
static const int OPENSSL_TLS1_CK_ECDH_ECDSA_WITH_AES_256_CBC_SHA = 0x300c005;
static const int OPENSSL_TLS1_CK_ECDHE_ECDSA_WITH_NULL_SHA = 0x300c006;
static const int OPENSSL_TLS1_CK_ECDHE_ECDSA_WITH_RC4_128_SHA = 0x300c007;
static const int OPENSSL_TLS1_CK_ECDHE_ECDSA_WITH_DES_192_CBC3_SHA = 0x300c008;
static const int OPENSSL_TLS1_CK_ECDHE_ECDSA_WITH_AES_128_CBC_SHA = 0x300c009;
static const int OPENSSL_TLS1_CK_ECDHE_ECDSA_WITH_AES_256_CBC_SHA = 0x300c00a;
static const int OPENSSL_TLS1_CK_ECDH_RSA_WITH_NULL_SHA = 0x300c00b;
static const int OPENSSL_TLS1_CK_ECDH_RSA_WITH_RC4_128_SHA = 0x300c00c;
static const int OPENSSL_TLS1_CK_ECDH_RSA_WITH_DES_192_CBC3_SHA = 0x300c00d;
static const int OPENSSL_TLS1_CK_ECDH_RSA_WITH_AES_128_CBC_SHA = 0x300c00e;
static const int OPENSSL_TLS1_CK_ECDH_RSA_WITH_AES_256_CBC_SHA = 0x300c00f;
static const int OPENSSL_TLS1_CK_ECDHE_RSA_WITH_NULL_SHA = 0x300c010;
static const int OPENSSL_TLS1_CK_ECDHE_RSA_WITH_RC4_128_SHA = 0x300c011;
static const int OPENSSL_TLS1_CK_ECDHE_RSA_WITH_DES_192_CBC3_SHA = 0x300c012;
static const int OPENSSL_TLS1_CK_ECDHE_RSA_WITH_AES_128_CBC_SHA = 0x300c013;
static const int OPENSSL_TLS1_CK_ECDHE_RSA_WITH_AES_256_CBC_SHA = 0x300c014;
static const int OPENSSL_TLS1_CK_ECDH_anon_WITH_NULL_SHA = 0x300c015;
static const int OPENSSL_TLS1_CK_ECDH_anon_WITH_RC4_128_SHA = 0x300c016;
static const int OPENSSL_TLS1_CK_ECDH_anon_WITH_DES_192_CBC3_SHA = 0x300c017;
static const int OPENSSL_TLS1_CK_ECDH_anon_WITH_AES_128_CBC_SHA = 0x300c018;
static const int OPENSSL_TLS1_CK_ECDH_anon_WITH_AES_256_CBC_SHA = 0x300c019;
static const ShortInt OPENSSL_TLS1_FINISH_MAC_LENGTH = 0xc;
static const ShortInt OPENSSL_TLS1_FLAGS_TLS_PADDING_BUG = 0x8;
#define OPENSSL_TLS1_TXT_RSA_EXPORT1024_WITH_RC4_56_MD5 L"EXP1024-RC4-MD5"
#define OPENSSL_TLS1_TXT_RSA_EXPORT1024_WITH_RC2_CBC_56_MD5 L"EXP1024-RC2-CBC-MD5"
#define OPENSSL_TLS1_TXT_RSA_EXPORT1024_WITH_DES_CBC_SHA L"EXP1024-DES-CBC-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA L"EXP1024-DHE-DSS-DES-CBC-SHA"
#define OPENSSL_TLS1_TXT_RSA_EXPORT1024_WITH_RC4_56_SHA L"EXP1024-RC4-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_EXPORT1024_WITH_RC4_56_SHA L"EXP1024-DHE-DSS-RC4-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_WITH_RC4_128_SHA L"DHE-DSS-RC4-SHA"
#define OPENSSL_TLS1_TXT_RSA_WITH_AES_128_SHA L"AES128-SHA"
#define OPENSSL_TLS1_TXT_DH_DSS_WITH_AES_128_SHA L"DH-DSS-AES128-SHA"
#define OPENSSL_TLS1_TXT_DH_RSA_WITH_AES_128_SHA L"DH-RSA-AES128-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_WITH_AES_128_SHA L"DHE-DSS-AES128-SHA"
#define OPENSSL_TLS1_TXT_DHE_RSA_WITH_AES_128_SHA L"DHE-RSA-AES128-SHA"
#define OPENSSL_TLS1_TXT_ADH_WITH_AES_128_SHA L"ADH-AES128-SHA"
#define OPENSSL_TLS1_TXT_RSA_WITH_AES_256_SHA L"AES256-SHA"
#define OPENSSL_TLS1_TXT_DH_DSS_WITH_AES_256_SHA L"DH-DSS-AES256-SHA"
#define OPENSSL_TLS1_TXT_DH_RSA_WITH_AES_256_SHA L"DH-RSA-AES256-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_WITH_AES_256_SHA L"DHE-DSS-AES256-SHA"
#define OPENSSL_TLS1_TXT_DHE_RSA_WITH_AES_256_SHA L"DHE-RSA-AES256-SHA"
#define OPENSSL_TLS1_TXT_ADH_WITH_AES_256_SHA L"ADH-AES256-SHA"
#define OPENSSL_TLS1_TXT_ECDH_ECDSA_WITH_NULL_SHA L"ECDH-ECDSA-NULL-SHA"
#define OPENSSL_TLS1_TXT_ECDH_ECDSA_WITH_RC4_128_SHA L"ECDH-ECDSA-RC4-SHA"
#define OPENSSL_TLS1_TXT_ECDH_ECDSA_WITH_DES_192_CBC3_SHA L"ECDH-ECDSA-DES-CBC3-SHA"
#define OPENSSL_TLS1_TXT_ECDH_ECDSA_WITH_AES_128_CBC_SHA L"ECDH-ECDSA-AES128-SHA"
#define OPENSSL_TLS1_TXT_ECDH_ECDSA_WITH_AES_256_CBC_SHA L"ECDH-ECDSA-AES256-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_ECDSA_WITH_NULL_SHA L"ECDHE-ECDSA-NULL-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_ECDSA_WITH_RC4_128_SHA L"ECDHE-ECDSA-RC4-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_ECDSA_WITH_DES_192_CBC3_SHA L"ECDHE-ECDSA-DES-CBC3-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_ECDSA_WITH_AES_128_CBC_SHA L"ECDHE-ECDSA-AES128-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_ECDSA_WITH_AES_256_CBC_SHA L"ECDHE-ECDSA-AES256-SHA"
#define OPENSSL_TLS1_TXT_ECDH_RSA_WITH_NULL_SHA L"ECDH-RSA-NULL-SHA"
#define OPENSSL_TLS1_TXT_ECDH_RSA_WITH_RC4_128_SHA L"ECDH-RSA-RC4-SHA"
#define OPENSSL_TLS1_TXT_ECDH_RSA_WITH_DES_192_CBC3_SHA L"ECDH-RSA-DES-CBC3-SHA"
#define OPENSSL_TLS1_TXT_ECDH_RSA_WITH_AES_128_CBC_SHA L"ECDH-RSA-AES128-SHA"
#define OPENSSL_TLS1_TXT_ECDH_RSA_WITH_AES_256_CBC_SHA L"ECDH-RSA-AES256-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_RSA_WITH_NULL_SHA L"ECDHE-RSA-NULL-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_RSA_WITH_RC4_128_SHA L"ECDHE-RSA-RC4-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_RSA_WITH_DES_192_CBC3_SHA L"ECDHE-RSA-DES-CBC3-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_RSA_WITH_AES_128_CBC_SHA L"ECDHE-RSA-AES128-SHA"
#define OPENSSL_TLS1_TXT_ECDHE_RSA_WITH_AES_256_CBC_SHA L"ECDHE-RSA-AES256-SHA"
#define OPENSSL_TLS1_TXT_ECDH_anon_WITH_NULL_SHA L"AECDH-NULL-SHA"
#define OPENSSL_TLS1_TXT_ECDH_anon_WITH_RC4_128_SHA L"AECDH-RC4-SHA"
#define OPENSSL_TLS1_TXT_ECDH_anon_WITH_DES_192_CBC3_SHA L"AECDH-DES-CBC3-SHA"
#define OPENSSL_TLS1_TXT_ECDH_anon_WITH_AES_128_CBC_SHA L"AECDH-AES128-SHA"
#define OPENSSL_TLS1_TXT_ECDH_anon_WITH_AES_256_CBC_SHA L"AECDH-AES256-SHA"
#define OPENSSL_TLS1_TXT_RSA_WITH_CAMELLIA_128_CBC_SHA L"CAMELLIA128-SHA"
#define OPENSSL_TLS1_TXT_DH_DSS_WITH_CAMELLIA_128_CBC_SHA L"DH-DSS-CAMELLIA128-SHA"
#define OPENSSL_TLS1_TXT_DH_RSA_WITH_CAMELLIA_128_CBC_SHA L"DH-RSA-CAMELLIA128-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA L"DHE-DSS-CAMELLIA128-SHA"
#define OPENSSL_TLS1_TXT_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA L"DHE-RSA-CAMELLIA128-SHA"
#define OPENSSL_TLS1_TXT_ADH_WITH_CAMELLIA_128_CBC_SHA L"ADH-CAMELLIA128-SHA"
#define OPENSSL_TLS1_TXT_RSA_WITH_CAMELLIA_256_CBC_SHA L"CAMELLIA256-SHA"
#define OPENSSL_TLS1_TXT_DH_DSS_WITH_CAMELLIA_256_CBC_SHA L"DH-DSS-CAMELLIA256-SHA"
#define OPENSSL_TLS1_TXT_DH_RSA_WITH_CAMELLIA_256_CBC_SHA L"DH-RSA-CAMELLIA256-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA L"DHE-DSS-CAMELLIA256-SHA"
#define OPENSSL_TLS1_TXT_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA L"DHE-RSA-CAMELLIA256-SHA"
#define OPENSSL_TLS1_TXT_ADH_WITH_CAMELLIA_256_CBC_SHA L"ADH-CAMELLIA256-SHA"
#define OPENSSL_TLS1_TXT_RSA_WITH_SEED_SHA L"SEED-SHA"
#define OPENSSL_TLS1_TXT_DH_DSS_WITH_SEED_SHA L"DH-DSS-SEED-SHA"
#define OPENSSL_TLS1_TXT_DH_RSA_WITH_SEED_SHA L"DH-RSA-SEED-SHA"
#define OPENSSL_TLS1_TXT_DHE_DSS_WITH_SEED_SHA L"DHE-DSS-SEED-SHA"
#define OPENSSL_TLS1_TXT_DHE_RSA_WITH_SEED_SHA L"DHE-RSA-SEED-SHA"
#define OPENSSL_TLS1_TXT_ADH_WITH_SEED_SHA L"ADH-SEED-SHA"
static const ShortInt OPENSSL_TLS_CT_DSS_FIXED_DH = 0x4;
static const ShortInt OPENSSL_TLS_CT_DSS_SIGN = 0x2;
static const ShortInt OPENSSL_TLS_CT_NUMBER = 0x4;
static const ShortInt OPENSSL_TLS_CT_RSA_FIXED_DH = 0x3;
static const ShortInt OPENSSL_TLS_CT_RSA_SIGN = 0x1;
#define OPENSSL_TLS_MD_CLIENT_FINISH_CONST L"client finished"
static const ShortInt OPENSSL_TLS_MD_CLIENT_FINISH_CONST_SIZE = 0xf;
#define OPENSSL_TLS_MD_CLIENT_WRITE_KEY_CONST L"client write key"
static const ShortInt OPENSSL_TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE = 0x10;
#define OPENSSL_TLS_MD_IV_BLOCK_CONST L"IV block"
static const ShortInt OPENSSL_TLS_MD_IV_BLOCK_CONST_SIZE = 0x8;
#define OPENSSL_TLS_MD_KEY_EXPANSION_CONST L"key expansion"
static const ShortInt OPENSSL_TLS_MD_KEY_EXPANSION_CONST_SIZE = 0xd;
#define OPENSSL_TLS_MD_MASTER_SECRET_CONST L"master secret"
static const ShortInt OPENSSL_TLS_MD_MASTER_SECRET_CONST_SIZE = 0xd;
static const ShortInt OPENSSL_TLS_MD_MAX_CONST_SIZE = 0x14;
#define OPENSSL_TLS_MD_SERVER_FINISH_CONST L"server finished"
static const ShortInt OPENSSL_TLS_MD_SERVER_FINISH_CONST_SIZE = 0xf;
#define OPENSSL_TLS_MD_SERVER_WRITE_KEY_CONST L"server write key"
static const ShortInt OPENSSL_TLS_MD_SERVER_WRITE_KEY_CONST_SIZE = 0x10;
static const ShortInt OPENSSL_TMP_MAX = 0x1a;
static const ShortInt OPENSSL_V_ASN1_APPLICATION = 0x40;
static const ShortInt OPENSSL_V_ASN1_APP_CHOOSE = -2;
static const ShortInt OPENSSL_V_ASN1_BIT_STRING = 0x3;
static const ShortInt OPENSSL_V_ASN1_BMPSTRING = 0x1e;
static const ShortInt OPENSSL_V_ASN1_BOOLEAN = 0x1;
static const ShortInt OPENSSL_V_ASN1_CONSTRUCTED = 0x20;
static const Byte OPENSSL_V_ASN1_CONTEXT_SPECIFIC = 0x80;
static const ShortInt OPENSSL_V_ASN1_ENUMERATED = 0xa;
static const ShortInt OPENSSL_V_ASN1_EOC = 0x0;
static const ShortInt OPENSSL_V_ASN1_EXTERNAL = 0x8;
static const ShortInt OPENSSL_V_ASN1_GENERALIZEDTIME = 0x18;
static const ShortInt OPENSSL_V_ASN1_GENERALSTRING = 0x1b;
static const ShortInt OPENSSL_V_ASN1_GRAPHICSTRING = 0x19;
static const ShortInt OPENSSL_V_ASN1_IA5STRING = 0x16;
static const ShortInt OPENSSL_V_ASN1_INTEGER = 0x2;
static const ShortInt OPENSSL_V_ASN1_ISO64STRING = 0x1a;
static const Word OPENSSL_V_ASN1_NEG_ENUMERATED = 0x10a;
static const Word OPENSSL_V_ASN1_NEG_INTEGER = 0x102;
static const ShortInt OPENSSL_V_ASN1_NULL = 0x5;
static const ShortInt OPENSSL_V_ASN1_NUMERICSTRING = 0x12;
static const ShortInt OPENSSL_V_ASN1_OBJECT = 0x6;
static const ShortInt OPENSSL_V_ASN1_OBJECT_DESCRIPTOR = 0x7;
static const ShortInt OPENSSL_V_ASN1_OCTET_STRING = 0x4;
static const ShortInt OPENSSL_V_ASN1_PRIMATIVE_TAG = 0x1f;
static const ShortInt OPENSSL_V_ASN1_PRIMITIVE_TAG = 0x1f;
static const ShortInt OPENSSL_V_ASN1_PRINTABLESTRING = 0x13;
static const Byte OPENSSL_V_ASN1_PRIVATE = 0xc0;
static const ShortInt OPENSSL_V_ASN1_REAL = 0x9;
static const ShortInt OPENSSL_V_ASN1_SEQUENCE = 0x10;
static const ShortInt OPENSSL_V_ASN1_SET = 0x11;
static const ShortInt OPENSSL_V_ASN1_T61STRING = 0x14;
static const ShortInt OPENSSL_V_ASN1_TELETEXSTRING = 0x14;
static const ShortInt OPENSSL_V_ASN1_UNDEF = -1;
static const ShortInt OPENSSL_V_ASN1_UNIVERSAL = 0x0;
static const ShortInt OPENSSL_V_ASN1_UNIVERSALSTRING = 0x1c;
static const ShortInt OPENSSL_V_ASN1_UTCTIME = 0x17;
static const ShortInt OPENSSL_V_ASN1_UTF8STRING = 0xc;
static const ShortInt OPENSSL_V_ASN1_VIDEOTEXSTRING = 0x15;
static const ShortInt OPENSSL_V_ASN1_VISIBLESTRING = 0x1a;
static const ShortInt OPENSSL_WINNT = 0x1;
static const ShortInt OPENSSL_X509_EXT_PACK_STRING = 0x2;
static const ShortInt OPENSSL_X509_EXT_PACK_UNKNOWN = 0x1;
static const ShortInt OPENSSL_X509_EX_V_INIT = 0x1;
static const Word OPENSSL_X509_EX_V_NETSCAPE_HACK = 0x8000;
static const ShortInt OPENSSL_X509_FILETYPE_DEFAULT = 0x3;
static const ShortInt OPENSSL_X509_F_ADD_CERT_DIR = 0x64;
static const ShortInt OPENSSL_X509_F_BY_FILE_CTRL = 0x65;
static const ShortInt OPENSSL_X509_F_DIR_CTRL = 0x66;
static const ShortInt OPENSSL_X509_F_GET_CERT_BY_SUBJECT = 0x67;
static const ShortInt OPENSSL_X509_F_X509V3_ADD_EXT = 0x68;
static const Byte OPENSSL_X509_F_X509_CHECK_PRIVATE_KEY = 0x80;
static const ShortInt OPENSSL_X509_F_X509_EXTENSION_CREATE_BY_NID = 0x6c;
static const ShortInt OPENSSL_X509_F_X509_EXTENSION_CREATE_BY_OBJ = 0x6d;
static const ShortInt OPENSSL_X509_F_X509_GET_PUBKEY_PARAMETERS = 0x6e;
static const ShortInt OPENSSL_X509_F_X509_LOAD_CERT_FILE = 0x6f;
static const ShortInt OPENSSL_X509_F_X509_LOAD_CRL_FILE = 0x70;
static const ShortInt OPENSSL_X509_F_X509_NAME_ADD_ENTRY = 0x71;
static const ShortInt OPENSSL_X509_F_X509_NAME_ENTRY_CREATE_BY_NID = 0x72;
static const ShortInt OPENSSL_X509_F_X509_NAME_ENTRY_SET_OBJECT = 0x73;
static const ShortInt OPENSSL_X509_F_X509_NAME_ONELINE = 0x74;
static const ShortInt OPENSSL_X509_F_X509_NAME_PRINT = 0x75;
static const ShortInt OPENSSL_X509_F_X509_PRINT_FP = 0x76;
static const ShortInt OPENSSL_X509_F_X509_PUBKEY_GET = 0x77;
static const ShortInt OPENSSL_X509_F_X509_PUBKEY_SET = 0x78;
static const ShortInt OPENSSL_X509_F_X509_REQ_PRINT = 0x79;
static const ShortInt OPENSSL_X509_F_X509_REQ_PRINT_FP = 0x7a;
static const ShortInt OPENSSL_X509_F_X509_REQ_TO_X509 = 0x7b;
static const ShortInt OPENSSL_X509_F_X509_STORE_ADD_CERT = 0x7c;
static const ShortInt OPENSSL_X509_F_X509_STORE_ADD_CRL = 0x7d;
static const ShortInt OPENSSL_X509_F_X509_TO_X509_REQ = 0x7e;
static const ShortInt OPENSSL_X509_F_X509_VERIFY_CERT = 0x7f;
static const ShortInt OPENSSL_X509_LU_CRL = 0x2;
static const ShortInt OPENSSL_X509_LU_FAIL = 0x0;
static const ShortInt OPENSSL_X509_LU_PKEY = 0x3;
static const ShortInt OPENSSL_X509_LU_RETRY = -1;
static const ShortInt OPENSSL_X509_LU_X509 = 0x1;
static const ShortInt OPENSSL_X509_L_ADD_DIR = 0x2;
static const ShortInt OPENSSL_X509_L_FILE_LOAD = 0x1;
static const ShortInt OPENSSL_X509_R_BAD_X509_FILETYPE = 0x64;
static const ShortInt OPENSSL_X509_R_BASE64_DECODE_ERROR = 0x76;
static const ShortInt OPENSSL_X509_R_CANT_CHECK_DH_KEY = 0x72;
static const ShortInt OPENSSL_X509_R_CERT_ALREADY_IN_HASH_TABLE = 0x65;
static const ShortInt OPENSSL_X509_R_ERR_ASN1_LIB = 0x66;
static const ShortInt OPENSSL_X509_R_INVALID_DIRECTORY = 0x71;
static const ShortInt OPENSSL_X509_R_INVALID_FIELD_NAME = 0x77;
static const ShortInt OPENSSL_X509_R_INVALID_TRUST = 0x7b;
static const ShortInt OPENSSL_X509_R_KEY_TYPE_MISMATCH = 0x73;
static const ShortInt OPENSSL_X509_R_KEY_VALUES_MISMATCH = 0x74;
static const ShortInt OPENSSL_X509_R_LOADING_CERT_DIR = 0x67;
static const ShortInt OPENSSL_X509_R_LOADING_DEFAULTS = 0x68;
static const ShortInt OPENSSL_X509_R_NO_CERT_SET_FOR_US_TO_VERIFY = 0x69;
static const ShortInt OPENSSL_X509_R_SHOULD_RETRY = 0x6a;
static const ShortInt OPENSSL_X509_R_UNABLE_TO_FIND_PARAMETERS_IN_CHAIN = 0x6b;
static const ShortInt OPENSSL_X509_R_UNABLE_TO_GET_CERTS_PUBLIC_KEY = 0x6c;
static const ShortInt OPENSSL_X509_R_UNKNOWN_KEY_TYPE = 0x75;
static const ShortInt OPENSSL_X509_R_UNKNOWN_NID = 0x6d;
static const ShortInt OPENSSL_X509_R_UNKNOWN_PURPOSE_ID = 0x79;
static const ShortInt OPENSSL_X509_R_UNSUPPORTED_ALGORITHM = 0x6f;
static const ShortInt OPENSSL_X509_R_WRONG_LOOKUP_TYPE = 0x70;
static const ShortInt OPENSSL_X509_R_WRONG_TYPE = 0x7a;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT = 0x2;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_GET_CRL = 0x3;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE = 0x4;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE = 0x5;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY = 0x6;
static const ShortInt OPENSSL_X509_V_ERR_CERT_SIGNATURE_FAILURE = 0x7;
static const ShortInt OPENSSL_X509_V_ERR_CRL_SIGNATURE_FAILURE = 0x8;
static const ShortInt OPENSSL_X509_V_ERR_CERT_NOT_YET_VALID = 0x9;
static const ShortInt OPENSSL_X509_V_ERR_CERT_HAS_EXPIRED = 0xa;
static const ShortInt OPENSSL_X509_V_ERR_CRL_NOT_YET_VALID = 0xb;
static const ShortInt OPENSSL_X509_V_ERR_CRL_HAS_EXPIRED = 0xc;
static const ShortInt OPENSSL_X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD = 0xd;
static const ShortInt OPENSSL_X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD = 0xe;
static const ShortInt OPENSSL_X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD = 0xf;
static const ShortInt OPENSSL_X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD = 0x10;
static const ShortInt OPENSSL_X509_V_ERR_OUT_OF_MEM = 0x11;
static const ShortInt OPENSSL_X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT = 0x12;
static const ShortInt OPENSSL_X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN = 0x13;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY = 0x14;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE = 0x15;
static const ShortInt OPENSSL_X509_V_ERR_CERT_CHAIN_TOO_LONG = 0x16;
static const ShortInt OPENSSL_X509_V_ERR_CERT_REVOKED = 0x17;
static const ShortInt OPENSSL_X509_V_ERR_INVALID_CA = 0x18;
static const ShortInt OPENSSL_X509_V_ERR_PATH_LENGTH_EXCEEDED = 0x19;
static const ShortInt OPENSSL_X509_V_ERR_INVALID_PURPOSE = 0x1a;
static const ShortInt OPENSSL_X509_V_ERR_CERT_UNTRUSTED = 0x1b;
static const ShortInt OPENSSL_X509_V_ERR_CERT_REJECTED = 0x1c;
static const ShortInt OPENSSL_X509_V_ERR_SUBJECT_ISSUER_MISMATCH = 0x1d;
static const ShortInt OPENSSL_X509_V_ERR_AKID_SKID_MISMATCH = 0x1e;
static const ShortInt OPENSSL_X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH = 0x1f;
static const ShortInt OPENSSL_X509_V_ERR_KEYUSAGE_NO_CERTSIGN = 0x20;
static const ShortInt OPENSSL_X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER = 0x21;
static const ShortInt OPENSSL_X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION = 0x22;
static const ShortInt OPENSSL_X509_V_ERR_KEYUSAGE_NO_CRL_SIGN = 0x23;
static const ShortInt OPENSSL_X509_V_ERR_UNHANDLED_CRITICAL_CRL_EXTENSION = 0x24;
static const ShortInt OPENSSL_X509_V_ERR_INVALID_NON_CA = 0x25;
static const ShortInt OPENSSL_X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED = 0x26;
static const ShortInt OPENSSL_X509_V_ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE = 0x27;
static const ShortInt OPENSSL_X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED = 0x28;
static const ShortInt OPENSSL_X509_V_ERR_INVALID_EXTENSION = 0x29;
static const ShortInt OPENSSL_X509_V_ERR_INVALID_POLICY_EXTENSION = 0x2a;
static const ShortInt OPENSSL_X509_V_ERR_NO_EXPLICIT_POLICY = 0x2b;
static const ShortInt OPENSSL_X509_V_ERR_UNNESTED_RESOURCE = 0x2c;
static const ShortInt OPENSSL_X509_V_ERR_APPLICATION_VERIFICATION = 0x32;
static const ShortInt OPENSSL_X509_V_OK = 0x0;
static const ShortInt OPENSSL_X509v3_KU_CRL_SIGN = 0x2;
static const ShortInt OPENSSL_X509v3_KU_DATA_ENCIPHERMENT = 0x10;
static const Word OPENSSL_X509v3_KU_DECIPHER_ONLY = 0x8000;
static const Byte OPENSSL_X509v3_KU_DIGITAL_SIGNATURE = 0x80;
static const ShortInt OPENSSL_X509v3_KU_ENCIPHER_ONLY = 0x1;
static const ShortInt OPENSSL_X509v3_KU_KEY_AGREEMENT = 0x8;
static const ShortInt OPENSSL_X509v3_KU_KEY_CERT_SIGN = 0x4;
static const ShortInt OPENSSL_X509v3_KU_KEY_ENCIPHERMENT = 0x20;
static const ShortInt OPENSSL_X509v3_KU_NON_REPUDIATION = 0x40;
static const Word OPENSSL_X509v3_KU_UNDEF = 0xffff;
static const ShortInt OPENSSL_X509V3_EXT_DYNAMIC = 0x1;
static const ShortInt OPENSSL_X509V3_EXT_CTX_DEP = 0x2;
static const ShortInt OPENSSL_X509V3_EXT_MULTILINE = 0x4;
static const ShortInt OPENSSL_GEN_OTHERNAME = 0x0;
static const ShortInt OPENSSL_GEN_EMAIL = 0x1;
static const ShortInt OPENSSL_GEN_DNS = 0x2;
static const ShortInt OPENSSL_GEN_X400 = 0x3;
static const ShortInt OPENSSL_GEN_DIRNAME = 0x4;
static const ShortInt OPENSSL_GEN_EDIPARTY = 0x5;
static const ShortInt OPENSSL_GEN_URI = 0x6;
static const ShortInt OPENSSL_GEN_IPADD = 0x7;
static const ShortInt OPENSSL_GEN_RID = 0x8;
static const ShortInt OPENSSL_EXFLAG_BCONS = 0x1;
static const ShortInt OPENSSL_EXFLAG_KUSAGE = 0x2;
static const ShortInt OPENSSL_EXFLAG_XKUSAGE = 0x4;
static const ShortInt OPENSSL_EXFLAG_NSCERT = 0x8;
static const ShortInt OPENSSL_EXFLAG_CA = 0x10;
static const ShortInt OPENSSL_EXFLAG_SI = 0x20;
static const ShortInt OPENSSL_EXFLAG_SS = 0x20;
static const ShortInt OPENSSL_EXFLAG_V1 = 0x40;
static const Byte OPENSSL_EXFLAG_INVALID = 0x80;
static const Word OPENSSL_EXFLAG_SET = 0x100;
static const Word OPENSSL_EXFLAG_CRITICAL = 0x200;
static const Word OPENSSL_EXFLAG_PROXY = 0x400;
static const Word OPENSSL_EXFLAG_INVALID_POLICY = 0x800;
static const Byte OPENSSL_KU_DIGITAL_SIGNATURE = 0x80;
static const ShortInt OPENSSL_KU_NON_REPUDIATION = 0x40;
static const ShortInt OPENSSL_KU_KEY_ENCIPHERMENT = 0x20;
static const ShortInt OPENSSL_KU_DATA_ENCIPHERMENT = 0x10;
static const ShortInt OPENSSL_KU_KEY_AGREEMENT = 0x8;
static const ShortInt OPENSSL_KU_KEY_CERT_SIGN = 0x4;
static const ShortInt OPENSSL_KU_CRL_SIGN = 0x2;
static const ShortInt OPENSSL_KU_ENCIPHER_ONLY = 0x1;
static const Word OPENSSL_KU_DECIPHER_ONLY = 0x8000;
static const Byte OPENSSL_NS_SSL_CLIENT = 0x80;
static const ShortInt OPENSSL_NS_SSL_SERVER = 0x40;
static const ShortInt OPENSSL_NS_SMIME = 0x20;
static const ShortInt OPENSSL_NS_OBJSIGN = 0x10;
static const ShortInt OPENSSL_NS_SSL_CA = 0x4;
static const ShortInt OPENSSL_NS_SMIME_CA = 0x2;
static const ShortInt OPENSSL_NS_OBJSIGN_CA = 0x1;
static const ShortInt OPENSSL_NS_ANY_CA = 0x7;
static const ShortInt OPENSSL_XKU_SSL_SERVER = 0x1;
static const ShortInt OPENSSL_XKU_SSL_CLIENT = 0x2;
static const ShortInt OPENSSL_XKU_SMIME = 0x4;
static const ShortInt OPENSSL_XKU_CODE_SIGN = 0x8;
static const ShortInt OPENSSL_XKU_SGC = 0x10;
static const ShortInt OPENSSL_XKU_OCSP_SIGN = 0x20;
static const ShortInt OPENSSL_XKU_TIMESTAMP = 0x40;
static const Byte OPENSSL_XKU_DVCS = 0x80;
static const ShortInt OPENSSL_X509_PURPOSE_DYNAMIC = 0x1;
static const ShortInt OPENSSL_X509_PURPOSE_DYNAMIC_NAME = 0x2;
static const ShortInt OPENSSL__ATEXIT_SIZE = 0x20;
static const ShortInt OPENSSL__IOFBF = 0x0;
static const ShortInt OPENSSL__IOLBF = 0x1;
static const ShortInt OPENSSL__IONBF = 0x2;
static const ShortInt OPENSSL__N_LISTS = 0x1e;
static const ShortInt OPENSSL__MSS_WIN32 = 0x1;
static const ShortInt OPENSSL__MSS_X86_ = 0x1;
static const ShortInt OPENSSL___CYGWIN32__ = 0x1;
static const ShortInt OPENSSL___CYGWIN__ = 0x1;
static const ShortInt OPENSSL___GNUC_MINOR__ = 0x5b;
static const ShortInt OPENSSL___GNUC__ = 0x2;
static const Word OPENSSL___SAPP = 0x100;
static const ShortInt OPENSSL___SEOF = 0x20;
static const ShortInt OPENSSL___SERR = 0x40;
static const ShortInt OPENSSL___SLBF = 0x1;
static const Byte OPENSSL___SMBF = 0x80;
static const Word OPENSSL___SMOD = 0x2000;
static const ShortInt OPENSSL___SNBF = 0x2;
static const Word OPENSSL___SNPT = 0x800;
static const Word OPENSSL___SOFF = 0x1000;
static const Word OPENSSL___SOPT = 0x400;
static const ShortInt OPENSSL___SRD = 0x4;
static const ShortInt OPENSSL___SRW = 0x10;
static const Word OPENSSL___SSTR = 0x200;
static const ShortInt OPENSSL___STDC__ = 0x1;
static const ShortInt OPENSSL___SWR = 0x8;
static const ShortInt OPENSSL___WINNT = 0x1;
static const ShortInt OPENSSL___WINNT__ = 0x1;
static const ShortInt OPENSSL___i386 = 0x1;
static const ShortInt OPENSSL___i386__ = 0x1;
static const ShortInt OPENSSL___i586 = 0x1;
static const ShortInt OPENSSL___i586__ = 0x1;
static const ShortInt OPENSSL___pentium = 0x1;
static const ShortInt OPENSSL___pentium__ = 0x1;
static const ShortInt OPENSSL_i386 = 0x1;
static const ShortInt OPENSSL_i586 = 0x1;
static const ShortInt OPENSSL_pentium = 0x1;
static const ShortInt OPENSSL_ERR_TXT_MALLOCED = 0x1;
static const ShortInt OPENSSL_ERR_TXT_STRING = 0x2;
static const ShortInt OPENSSL_ERR_NUM_ERRORS = 0x10;
static const ShortInt OPENSSL_ERR_LIB_NONE = 0x1;
static const ShortInt OPENSSL_ERR_LIB_SYS = 0x2;
static const ShortInt OPENSSL_ERR_LIB_BN = 0x3;
static const ShortInt OPENSSL_ERR_LIB_RSA = 0x4;
static const ShortInt OPENSSL_ERR_LIB_DH = 0x5;
static const ShortInt OPENSSL_ERR_LIB_EVP = 0x6;
static const ShortInt OPENSSL_ERR_LIB_BUF = 0x7;
static const ShortInt OPENSSL_ERR_LIB_OBJ = 0x8;
static const ShortInt OPENSSL_ERR_LIB_PEM = 0x9;
static const ShortInt OPENSSL_ERR_LIB_DSA = 0xa;
static const ShortInt OPENSSL_ERR_LIB_X509 = 0xb;
static const ShortInt OPENSSL_ERR_LIB_ASN1 = 0xd;
static const ShortInt OPENSSL_ERR_LIB_CONF = 0xe;
static const ShortInt OPENSSL_ERR_LIB_CRYPTO = 0xf;
static const ShortInt OPENSSL_ERR_LIB_EC = 0x10;
static const ShortInt OPENSSL_ERR_LIB_SSL = 0x14;
static const ShortInt OPENSSL_ERR_LIB_BIO = 0x20;
static const ShortInt OPENSSL_ERR_LIB_PKCS7 = 0x21;
static const ShortInt OPENSSL_ERR_LIB_X509V3 = 0x22;
static const ShortInt OPENSSL_ERR_LIB_PKCS12 = 0x23;
static const ShortInt OPENSSL_ERR_LIB_RAND = 0x24;
static const ShortInt OPENSSL_ERR_LIB_DSO = 0x25;
static const ShortInt OPENSSL_ERR_LIB_ENGINE = 0x26;
static const ShortInt OPENSSL_ERR_LIB_OCSP = 0x27;
static const ShortInt OPENSSL_ERR_LIB_UI = 0x28;
static const ShortInt OPENSSL_ERR_LIB_COMP = 0x29;
static const ShortInt OPENSSL_ERR_LIB_ECDSA = 0x2a;
static const ShortInt OPENSSL_ERR_LIB_ECDH = 0x2b;
static const ShortInt OPENSSL_ERR_LIB_STORE = 0x2c;
static const ShortInt OPENSSL_ERR_LIB_FIPS = 0x2d;
static const ShortInt OPENSSL_ERR_LIB_CMS = 0x2e;
static const ShortInt OPENSSL_ERR_LIB_JPAKE = 0x2f;
static const ShortInt OPENSSL_ERR_R_FATAL = 0x40;
static const ShortInt OPENSSL_ERR_R_MALLOC_FAILURE = 0x41;
static const ShortInt OPENSSL_ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED = 0x42;
static const ShortInt OPENSSL_ERR_R_PASSED_NULL_PARAMETER = 0x43;
static const ShortInt OPENSSL_ERR_R_INTERNAL_ERROR = 0x44;
static const ShortInt OPENSSL_ERR_R_DISABLED = 0x45;
static const Byte OPENSSL_ERR_LIB_USER = 0x80;
static const ShortInt OPENSSL_SYS_F_FOPEN = 0x1;
static const ShortInt OPENSSL_SYS_F_CONNECT = 0x2;
static const ShortInt OPENSSL_SYS_F_GETSERVBYNAME = 0x3;
static const ShortInt OPENSSL_SYS_F_SOCKET = 0x4;
static const ShortInt OPENSSL_SYS_F_IOCTLSOCKET = 0x5;
static const ShortInt OPENSSL_SYS_F_BIND = 0x6;
static const ShortInt OPENSSL_SYS_F_LISTEN = 0x7;
static const ShortInt OPENSSL_SYS_F_ACCEPT = 0x8;
static const ShortInt OPENSSL_SYS_F_WSASTARTUP = 0x9;
static const ShortInt OPENSSL_SYS_F_OPENDIR = 0xa;
static const ShortInt OPENSSL_SYS_F_FREAD = 0xb;
static const ShortInt OPENSSL_UI_INPUT_FLAG_ECHO = 0x1;
static const ShortInt OPENSSL_UI_INPUT_FLAG_DEFAULT_PWD = 0x2;
static const ShortInt OPENSSL_UI_INPUT_FLAG_USER_BASE = 0x10;
static const ShortInt OPENSSL_UI_CTRL_PRINT_ERRORS = 0x1;
static const ShortInt OPENSSL_UI_CTRL_IS_REDOABLE = 0x2;
static const ShortInt OPENSSL_UI_F_GENERAL_ALLOCATE_BOOLEAN = 0x6c;
static const ShortInt OPENSSL_UI_F_GENERAL_ALLOCATE_PROMPT = 0x6d;
static const ShortInt OPENSSL_UI_F_GENERAL_ALLOCATE_STRING = 0x64;
static const ShortInt OPENSSL_UI_F_UI_CTRL = 0x6f;
static const ShortInt OPENSSL_UI_F_UI_DUP_ERROR_STRING = 0x65;
static const ShortInt OPENSSL_UI_F_UI_DUP_INFO_STRING = 0x66;
static const ShortInt OPENSSL_UI_F_UI_DUP_INPUT_BOOLEAN = 0x6e;
static const ShortInt OPENSSL_UI_F_UI_DUP_INPUT_STRING = 0x67;
static const ShortInt OPENSSL_UI_F_UI_DUP_VERIFY_STRING = 0x6a;
static const ShortInt OPENSSL_UI_F_UI_GET0_RESULT = 0x6b;
static const ShortInt OPENSSL_UI_F_UI_NEW_METHOD = 0x68;
static const ShortInt OPENSSL_UI_F_UI_SET_RESULT = 0x69;
static const ShortInt OPENSSL_UI_R_COMMON_OK_AND_CANCEL_CHARACTERS = 0x68;
static const ShortInt OPENSSL_UI_R_INDEX_TOO_LARGE = 0x66;
static const ShortInt OPENSSL_UI_R_INDEX_TOO_SMALL = 0x67;
static const ShortInt OPENSSL_UI_R_NO_RESULT_BUFFER = 0x69;
static const ShortInt OPENSSL_UI_R_RESULT_TOO_LARGE = 0x64;
static const ShortInt OPENSSL_UI_R_RESULT_TOO_SMALL = 0x65;
static const ShortInt OPENSSL_UI_R_UNKNOWN_CONTROL_COMMAND = 0x6a;
static const ShortInt OPENSSL_ERR_R_SYS_LIB = 0x2;
static const ShortInt OPENSSL_ERR_R_BN_LIB = 0x3;
static const ShortInt OPENSSL_ERR_R_RSA_LIB = 0x4;
static const ShortInt OPENSSL_ERR_R_DH_LIB = 0x5;
static const ShortInt OPENSSL_ERR_R_EVP_LIB = 0x6;
static const ShortInt OPENSSL_ERR_R_BUF_LIB = 0x7;
static const ShortInt OPENSSL_ERR_R_OBJ_LIB = 0x8;
static const ShortInt OPENSSL_ERR_R_PEM_LIB = 0x9;
static const ShortInt OPENSSL_ERR_R_DSA_LIB = 0xa;
static const ShortInt OPENSSL_ERR_R_X509_LIB = 0xb;
static const ShortInt OPENSSL_ERR_R_ASN1_LIB = 0xd;
static const ShortInt OPENSSL_ERR_R_CONF_LIB = 0xe;
static const ShortInt OPENSSL_ERR_R_CRYPTO_LIB = 0xf;
static const ShortInt OPENSSL_ERR_R_EC_LIB = 0x10;
static const ShortInt OPENSSL_ERR_R_SSL_LIB = 0x14;
static const ShortInt OPENSSL_ERR_R_BIO_LIB = 0x20;
static const ShortInt OPENSSL_ERR_R_PKCS7_LIB = 0x21;
static const ShortInt OPENSSL_ERR_R_X509V3_LIB = 0x22;
static const ShortInt OPENSSL_ERR_R_PKCS12_LIB = 0x23;
static const ShortInt OPENSSL_ERR_R_RAND_LIB = 0x24;
static const ShortInt OPENSSL_ERR_R_DSO_LIB = 0x25;
static const ShortInt OPENSSL_ERR_R_ENGINE_LIB = 0x26;
static const ShortInt OPENSSL_ERR_R_OCSP_LIB = 0x27;
static const ShortInt OPENSSL_ERR_R_UI_LIB = 0x28;
static const ShortInt OPENSSL_ERR_R_COMP_LIB = 0x29;
static const ShortInt OPENSSL_ERR_R_ECDSA_LIB = 0x2a;
static const ShortInt OPENSSL_ERR_R_ECDH_LIB = 0x2b;
static const ShortInt OPENSSL_ERR_R_STORE_LIB = 0x2c;
static const ShortInt OPENSSL_ERR_R_NESTED_ASN1_ERROR = 0x3a;
static const ShortInt OPENSSL_ERR_R_BAD_ASN1_OBJECT_HEADER = 0x3b;
static const ShortInt OPENSSL_ERR_R_BAD_GET_ASN1_OBJECT_CALL = 0x3c;
static const ShortInt OPENSSL_ERR_R_EXPECTING_AN_ASN1_SEQUENCE = 0x3d;
static const ShortInt OPENSSL_ERR_R_ASN1_LENGTH_MISMATCH = 0x3e;
static const ShortInt OPENSSL_ERR_R_MISSING_ASN1_EOS = 0x3f;
static const Word OPENSSL_DTLS1_VERSION = 0xfeff;
static const Word OPENSSL_DTLS1_BAD_VER = 0x100;
static const ShortInt OPENSSL_DTLS1_COOKIE_LENGTH = 0x20;
static const ShortInt OPENSSL_DTLS1_RT_HEADER_LENGTH = 0xd;
static const ShortInt OPENSSL_DTLS1_HM_HEADER_LENGTH = 0xc;
static const ShortInt OPENSSL_DTLS1_HM_BAD_FRAGMENT = -2;
static const ShortInt OPENSSL_DTLS1_HM_FRAGMENT_RETRY = -3;
static const ShortInt OPENSSL_DTLS1_CCS_HEADER_LENGTH = 0x1;
static const ShortInt OPENSSL_DTLS1_AL_HEADER_LENGTH = 0x2;
extern PACKAGE void __cdecl (*IdSslAddAllAlgorithms)(void);
extern PACKAGE void __cdecl (*IdSslAddAllCiphers)(void);
extern PACKAGE void __cdecl (*IdSslAddAllDigests)(void);
extern PACKAGE void __cdecl (*IdSslEvpCleanup)(void);
extern PACKAGE char * __cdecl (*IdSslSSLeay_version)(int _type);
extern PACKAGE unsigned __cdecl (*IdSsleay)(void);
extern PACKAGE int __cdecl (*IdSslCryptoSetMemFunctions)(TCRYPTO_set_mem_functions_m m, TCRYPTO_set_mem_functions_r r, TCRYPTO_set_mem_functions_f f);
extern PACKAGE void * __cdecl (*IdSslCryptoMalloc)(int num, const char * _file, int line);
extern PACKAGE void __cdecl (*IdSslCryptoFree)(void * ptr);
extern PACKAGE void __cdecl (*IdSslCryptoMemLeaks)(PBIO b);
extern PACKAGE int __cdecl (*IdSslCryptoMemCtrl)(int mode);
extern PACKAGE void __cdecl (*IdSslCryptoSetMemDebugFunctions)(Tset_mem_debug_functions_m m, Tset_mem_debug_functions_r r, Tset_mem_debug_functions_f f, Tset_mem_debug_functions_so so, Tset_mem_debug_functions_go go);
extern PACKAGE void __cdecl (*IdSslCryptoDbgMalloc)(void * addr, int num, const char * _file, int line, int before);
extern PACKAGE void __cdecl (*IdSslCryptoDbgRealloc)(void * arrd1, void * addr2, int num, const char * _file, int line, int before);
extern PACKAGE void __cdecl (*IdSslCryptoDbgFree)(void * addr, int before);
extern PACKAGE void __cdecl (*IdSslCryptoDbgSetOptions)(int bits);
extern PACKAGE int __cdecl (*IdSslCryptoDbgGetOptions)(void);
extern PACKAGE PSTACK __cdecl (*IdSslSkNewNull)(void);
extern PACKAGE int __cdecl (*IdSslSkPush)(PSTACK st, char * data);
extern PACKAGE void __cdecl (*IdSslRsaFree)(PRSA rsa);
extern PACKAGE PRSA __cdecl (*IdSslRsaGenerateKey)(int bits, unsigned e, TRSA_generate_key_callback callback, void * cb_arg);
extern PACKAGE int __cdecl (*IdSslRsaGenerateKeyEx)(PRSA rsa, int bits, PBIGNUM e, PBN_GENCB cb);
extern PACKAGE int __cdecl (*IdSslRsaCheckKey)(const PRSA rsa);
extern PACKAGE PBIO __cdecl (*IdSslBioNew)(PBIO_METHOD _type);
extern PACKAGE int __cdecl (*IdSslBioFree)(PBIO bio);
extern PACKAGE PBIO_METHOD __cdecl (*IdSslBioSMem)(void);
extern PACKAGE PBIO_METHOD __cdecl (*IdSslBioSFile)(void);
extern PACKAGE int __cdecl (*IdSslBioCtrl)(PBIO bp, int cmd, int larg, void * parg);
extern PACKAGE PBIO __cdecl (*IdSslBioNewFile)(const char * filename, const char * mode);
extern PACKAGE int __cdecl (*IdSslBioPutS)(PBIO b, const char * txt);
extern PACKAGE int __cdecl (*IdSslBioRead)(PBIO b, void * data, int len);
extern PACKAGE int __cdecl (*IdSslBioWrite)(PBIO b, const void * buf, int len);
extern PACKAGE int __cdecl (*IdSslPemWriteBioX509Req)(PBIO bp, PX509_REQ x);
extern PACKAGE int __cdecl (*IdSslPemWriteBioPKCS8PrivateKey)(PBIO bp, PEVP_PKEY key, PEVP_CIPHER enc, char * kstr, int klen, ppem_password_cb cb, void * u);
extern PACKAGE int __cdecl (*IdSslPemAsn1WriteBio)(D2I_OF_void i2d, const char * name, PBIO bp, char * x, const PEVP_CIPHER enc, char * kstr, int klen, ppem_password_cb cb, void * u);
extern PACKAGE void * __cdecl (*IdSslPemAsn1ReadBio)(D2I_OF_void d2i, const char * name, PBIO bp, void * &x, ppem_password_cb cb, char * u);
extern PACKAGE PEVP_PKEY __cdecl (*IdSslPemReadBioPrivateKey)(PBIO bio, PEVP_PKEY &x, ppem_password_cb cb, void * u);
extern PACKAGE int __cdecl (*IdSslEvpDigestInitEx)(PEVP_MD_CTX ctx, const PEVP_MD AType, void * impl);
extern PACKAGE int __cdecl (*IdSslEvpDigestUpdate)(PEVP_MD_CTX ctx, void * d, unsigned cnt);
extern PACKAGE int __cdecl (*IdSslEvpDigestFinalEx)(PEVP_MD_CTX ctx, char * md, unsigned &s);
extern PACKAGE void __cdecl (*IdSslEvpMDCtxInit)(PEVP_MD_CTX ctx);
extern PACKAGE int __cdecl (*IdSslEvpMDCtxCleanup)(PEVP_MD_CTX ctx);
extern PACKAGE PEVP_CIPHER __cdecl (*IdSslEvpDesEde3Cbc)(void);
extern PACKAGE PEVP_PKEY __cdecl (*IdSslEvpPKeyNew)(void);
extern PACKAGE void __cdecl (*IdSslEvpPKeyFree)(PEVP_PKEY pkey);
extern PACKAGE int __cdecl (*IdSslEvpPKeyAssign)(PEVP_MD pkey, int _type, char * key);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpGetDigestByName)(const char * name);
extern PACKAGE int __cdecl (*IdSslAsn1IntegerSet)(PASN1_INTEGER a, int v);
extern PACKAGE int __cdecl (*IdSslAsn1IntegerGet)(PASN1_INTEGER a);
extern PACKAGE PASN1_STRING __cdecl (*IdSslAsn1StringTypeNew)(int _type);
extern PACKAGE void __cdecl (*IdSslAsn1StringFree)(PASN1_STRING a);
extern PACKAGE int __cdecl (*IdSslI2dX509)(PX509 x, System::PByte &buf);
extern PACKAGE PX509 __cdecl (*IdSslD2iX509)(PX509 pr, PPByte _in, int len);
extern PACKAGE PX509 __cdecl (*IdSslD2iX509Bio)(PBIO bp, PPX509 x);
extern PACKAGE int __cdecl (*IdSslI2dX509ReqBio)(PX509_REQ x, PBIO bp);
extern PACKAGE int __cdecl (*IdSslI2dX509Bio)(PBIO bp, PX509 x509);
extern PACKAGE int __cdecl (*IdSslI2dPrivateKeyBio)(PBIO b, PEVP_PKEY pkey);
extern PACKAGE PPX509 __cdecl (*IdSslX509New)(void);
extern PACKAGE void __cdecl (*IdSslX509Free)(PX509 x);
extern PACKAGE PX509_REQ __cdecl (*IdSslX509ReqNew)(void);
extern PACKAGE void __cdecl (*IdSslX509ReqFree)(PX509_REQ x);
extern PACKAGE PX509_REQ __cdecl (*IdSslX509ToX509Req)(PX509 x, PEVP_PKEY pkey, const PEVP_MD md);
extern PACKAGE int __cdecl (*IdSslX509NameAddEntryByTxt)(PX509_NAME name, const char * field, int _type, const char * bytes, int len, int loc, int _set);
extern PACKAGE int __cdecl (*IdSslX509SetVersion)(PX509 x, int version);
extern PACKAGE PASN1_INTEGER __cdecl (*IdSslX509GetSerialNumber)(PX509 x);
extern PACKAGE PASN1_TIME __cdecl (*IdSslX509GmTimeAdj)(PASN1_TIME s, int adj);
extern PACKAGE int __cdecl (*IdSslX509SetNotBefore)(PX509 x, PASN1_TIME tm);
extern PACKAGE int __cdecl (*IdSslX509SetNotAfter)(PX509 x, PASN1_TIME tm);
extern PACKAGE int __cdecl (*IdSslX509SetPubKey)(PX509 x, PEVP_PKEY pkey);
extern PACKAGE int __cdecl (*IdSslX509ReqSetPubKey)(PX509_REQ x, PEVP_PKEY pkey);
extern PACKAGE int __cdecl (*IdSslX509Sign)(PX509 x, PEVP_PKEY pkey, const PEVP_MD md);
extern PACKAGE int __cdecl (*IdSslX509ReqSign)(PX509_REQ x, PEVP_PKEY pkey, const PEVP_MD md);
extern PACKAGE int __cdecl (*IdSslX509ReqAddExtensions)(PX509_REQ req, PSTACK exts);
extern PACKAGE PX509_EXTENSION __cdecl (*IdSslX509V3ExtConfNid)(PLHASH conf, PX509V3_CTX ctx, int ext_nid, char * value);
extern PACKAGE PX509_EXTENSION __cdecl (*IdSslX509ExtensionCreateByNid)(PPX509_EXTENSION ex, int nid, int crit, PASN1_OCTET_STRING data);
extern PACKAGE void __cdecl (*IdSslX509V3SetCtx)(PX509V3_CTX ctx, PX509 issuer, PX509 subject, PX509_REQ req, PX509_CRL crl, int flags);
extern PACKAGE void __cdecl (*IdSslX509ExtensionFree)(PX509_EXTENSION ex);
extern PACKAGE int __cdecl (*IdSslX509AddExt)(PX509 cert, PX509_EXTENSION ext, int loc);
extern PACKAGE int __cdecl (*IdSslX509Print)(PBIO bp, PX509 x);
extern PACKAGE int __cdecl (*IdSslCtxSetCipherList)(PSSL_CTX _para1, const char * str);
extern PACKAGE PSSL_CTX __cdecl (*IdSslCtxNew)(PSSL_METHOD meth);
extern PACKAGE void __cdecl (*IdSslCtxFree)(PSSL_CTX _para1);
extern PACKAGE int __cdecl (*IdSslSetFd)(PSSL s, int fd);
extern PACKAGE int __cdecl (*IdSslCtxUsePrivateKeyFile)(PSSL_CTX ctx, const char * _file, int _type);
extern PACKAGE int __cdecl (*IdSslCtxUsePrivateKey)(PSSL_CTX ctx, PEVP_PKEY pkey);
extern PACKAGE int __cdecl (*IdSslCtxUseCertificate)(PSSL_CTX ctx, PX509 x);
extern PACKAGE int __cdecl (*IdSslCtxUseCertificateFile)(PSSL_CTX ctx, const char * _file, int _type);
extern PACKAGE void __cdecl (*IdSslLoadErrorStrings)(void);
extern PACKAGE char * __cdecl (*IdSslStateStringLong)(PSSL s);
extern PACKAGE PX509 __cdecl (*IdSslGetPeerCertificate)(PSSL s);
extern PACKAGE void __cdecl (*IdSslCtxSetVerify)(PSSL_CTX ctx, int mode, TSSL_CTX_set_verify_callback callback);
extern PACKAGE void __cdecl (*IdSslCtxSetVerifyDepth)(PSSL_CTX ctx, int depth);
extern PACKAGE int __cdecl (*IdSslCtxGetVerifyDepth)(PSSL_CTX ctx);
extern PACKAGE void __cdecl (*IdSslCtxSetDefaultPasswdCb)(PSSL_CTX ctx, ppem_password_cb cb);
extern PACKAGE void __cdecl (*IdSslCtxSetDefaultPasswdCbUserdata)(PSSL_CTX ctx, void * u);
extern PACKAGE int __cdecl (*IdSslCtxCheckPrivateKeyFile)(PSSL_CTX ctx);
extern PACKAGE PSSL __cdecl (*IdSslNew)(PSSL_CTX ctx);
extern PACKAGE void __cdecl (*IdSslFree)(PSSL ssl);
extern PACKAGE int __cdecl (*IdSslAccept)(PSSL ssl);
extern PACKAGE int __cdecl (*IdSslConnect)(PSSL ssl);
extern PACKAGE int __cdecl (*IdSslRead)(PSSL ssl, void * buf, int num);
extern PACKAGE int __cdecl (*IdSslPeek)(PSSL ssl, void * buf, int num);
extern PACKAGE int __cdecl (*IdSslWrite)(PSSL ssl, const void * buf, int num);
extern PACKAGE int __cdecl (*IdSslPending)(PSSL ssl);
extern PACKAGE int __cdecl (*IdSslCtxCtrl)(PSSL_CTX ssl, int cmd, int larg, void * parg);
extern PACKAGE int __cdecl (*IdSslCtrl)(PSSL ssl, int cmd, int larg, void * parg);
extern PACKAGE int __cdecl (*IdSslCallbackCtrl)(PSSL ssl, int cmd, SSL_callback_ctrl_fp fp);
extern PACKAGE int __cdecl (*IdSslCtxCallbackCtrl)(PSSL_CTX ssl, int cmd, SSL_callback_ctrl_fp fp);
extern PACKAGE int __cdecl (*IdSslGetError)(PSSL s, int ret_code);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodV2)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodServerV2)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodClientV2)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodV3)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodServerV3)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodClientV3)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodV23)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodServerV23)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodClientV23)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodTLSV1)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodServerTLSV1)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodClientTLSV1)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodDTLSv1)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodServerDTLSv1)(void);
extern PACKAGE PSSL_METHOD __cdecl (*IdSslMethodClientDTLSv1)(void);
extern PACKAGE int __cdecl (*IdSslShutdown)(PSSL s);
extern PACKAGE void __cdecl (*IdSslSetConnectState)(PSSL s);
extern PACKAGE void __cdecl (*IdSslSetAcceptState)(PSSL s);
extern PACKAGE void __cdecl (*IdSslSetShutdown)(PSSL ssl, int mode);
extern PACKAGE int __cdecl (*IdSslCtxLoadVerifyLocations)(PSSL_CTX ctx, const char * CAfile, const char * CApath);
extern PACKAGE PSSL_SESSION __cdecl (*IdSslGetSession)(const PSSL ssl);
extern PACKAGE int __cdecl (*IdSslAddSslAlgorithms)(void);
extern PACKAGE char * __cdecl (*IdSslSessionGetId)(const PSSL_SESSION s, System::PPAnsiChar id, Idctypes::PIdC_INT length);
extern PACKAGE char * __cdecl (*IdSslX509NameOneline)(PX509_NAME a, char * buf, int size);
extern PACKAGE unsigned __cdecl (*IdSslX509NameHash)(PX509_NAME x);
extern PACKAGE int __cdecl (*IdSslX509SetIssuerName)(PX509 x, PX509_NAME name);
extern PACKAGE PX509_NAME __cdecl (*IdSslX509GetIssuerName)(PX509 a);
extern PACKAGE int __cdecl (*IdSslX509SetSubjectName)(PX509 x, PX509_NAME name);
extern PACKAGE PX509_NAME __cdecl (*IdSslX509GetSubjectName)(PX509 a);
extern PACKAGE int __cdecl (*IdSslOBJObj2Nid)(const PASN1_OBJECT o);
extern PACKAGE PASN1_OBJECT __cdecl (*IdSslOBJNid2Obj)(int n);
extern PACKAGE char * __cdecl (*IdSslOBJNid2ln)(int n);
extern PACKAGE char * __cdecl (*IdSslOBJNid2sn)(int n);
extern PACKAGE int __cdecl (*IdSslX509Digest)(const PX509 data, const PEVP_MD _type, System::PByte md, unsigned &len);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpSHA512)(void);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpSHA386)(void);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpSHA256)(void);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpSHA224)(void);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpSHA1)(void);
extern PACKAGE PEVP_MD __cdecl (*IdSslEvpMd5)(void);
extern PACKAGE int __cdecl (*IdSslEvpPKEYType)(int _type);
extern PACKAGE void * __cdecl (*IdSslX509StoreCtxGetExData)(PX509_STORE_CTX ctx, int idx);
extern PACKAGE int __cdecl (*IdSslX509StoreCtxGetError)(PX509_STORE_CTX ctx);
extern PACKAGE void __cdecl (*IdSslX509StoreCtxSetError)(PX509_STORE_CTX ctx, int s);
extern PACKAGE int __cdecl (*IdSslX509StoreCtxGetErrorDepth)(PX509_STORE_CTX ctx);
extern PACKAGE PX509 __cdecl (*IdSslX509StoreCtxGetCurrentCert)(PX509_STORE_CTX ctx);
extern PACKAGE int __cdecl (*IdSslCryptoNumLocks)(void);
extern PACKAGE void __cdecl (*IdSslSetLockingCallback)(TIdSslLockingCallback func);
extern PACKAGE void __cdecl (*IdSslSetIdCallback)(TIdSslIdCallback func);
extern PACKAGE void __cdecl (*IdDES_set_odd_parity)(PDES_cblock key);
extern PACKAGE int __cdecl (*IdDES_set_key)(Pconst_DES_cblock key, des_ks_struct *schedule);
extern PACKAGE void __cdecl (*IdDES_ecb_encrypt)(Pconst_DES_cblock input, Pconst_DES_cblock output, des_ks_struct *ks, int enc);
extern PACKAGE void __cdecl (*Id_ossl_old_des_set_odd_parity)(P_ossl_old_des_cblock key);
extern PACKAGE int __cdecl (*Id_ossl_old_des_set_key)(P_ossl_old_des_cblock key, _ossl_old_des_ks_struct *schedule);
extern PACKAGE void __cdecl (*Id_ossl_old_des_ecb_encrypt)(P_ossl_old_des_cblock input, P_ossl_old_des_cblock output, P_ossl_old_des_key_schedule ks, int enc);
extern PACKAGE int __cdecl (*IdSSL_set_ex_data)(PSSL ssl, int idx, void * data);
extern PACKAGE void * __cdecl (*IdSSL_get_ex_data)(PSSL ssl, int idx);
extern PACKAGE PPKCS12 __cdecl (*IdSSLPKCS12Create)(char * pass, char * name, PEVP_PKEY pkey, PX509 cert, PSTACK ca, int nid_key, int nid_cert, int iter, int mac_iter, int keytype);
extern PACKAGE int __cdecl (*IdSSLI2dPKCS12Bio)(PBIO b, PPKCS12 p12);
extern PACKAGE void __cdecl (*IdSSLPKCS12Free)(PPKCS12 p12);
extern PACKAGE PSTACK __cdecl (*IdSSLLoadClientCAFile)(const char * _file);
extern PACKAGE void __cdecl (*IdSSLCtxSetClientCAList)(PSSL_CTX ctx, PSTACK list);
extern PACKAGE int __cdecl (*IdSSLCtxSetDefaultVerifyPaths)(PSSL_CTX ctx);
extern PACKAGE int __cdecl (*IdSSLCtxSetSessionIdContext)(PSSL_CTX ctx, const System::PByte sid_ctx, unsigned sid_ctx_len);
extern PACKAGE char * __cdecl (*IdSSLCipherDescription)(PSSL_CIPHER _para1, char * buf, int size);
extern PACKAGE PSSL_CIPHER __cdecl (*IdSSLGetCurrentCipher)(const PSSL s);
extern PACKAGE char * __cdecl (*IdSSLCipherGetName)(const PSSL_CIPHER c);
extern PACKAGE char * __cdecl (*IdSSLCipherGetVersion)(const PSSL_CIPHER c);
extern PACKAGE int __cdecl (*IdSSLCipherGetBits)(const PSSL_CIPHER c, int &alg_bits);
extern PACKAGE void __cdecl (*IdSSLERR_error_string_n)(unsigned e, char * buf, unsigned len);
extern PACKAGE unsigned __cdecl (*IdSSLERR_get_err)(void);
extern PACKAGE unsigned __cdecl (*IdSSLERR_peek_err)(void);
extern PACKAGE void __cdecl (*IdSSLERR_clear_error)(void);
extern PACKAGE char * __cdecl (*IdSSLERR_error_string)(unsigned e, char * buf);
extern PACKAGE char * __cdecl (*IdSSLERR_lib_error_string)(unsigned e);
extern PACKAGE char * __cdecl (*IdSSLERR_func_error_string)(unsigned e);
extern PACKAGE char * __cdecl (*IdSSLERR_reason_error_string)(unsigned e);
extern PACKAGE void __cdecl (*IdSSLERR_load_ERR_strings)(void);
extern PACKAGE void __cdecl (*IdSSLERR_load_crypto_strings)(void);
extern PACKAGE void __cdecl (*IdSSLERR_free_strings)(void);
extern PACKAGE void __cdecl (*IdSslErrRemoveState)(unsigned pid);
extern PACKAGE void __cdecl (*IdSslCryptoCleanupAllExData)(void);
extern PACKAGE PSTACK __cdecl (*IdSslCompGetCompressionMethods)(void);
extern PACKAGE void __cdecl (*IdSslSkPopFree)(PSTACK st, Tsk_pop_free_func func);
extern PACKAGE int __fastcall GetCryptLibHandle(void);
extern PACKAGE System::AnsiString __fastcall ErrMsg(unsigned AErr);
extern PACKAGE bool __fastcall Load(void);
extern PACKAGE void __fastcall Unload(void);
extern PACKAGE System::UnicodeString __fastcall WhichFailedToLoad();
extern PACKAGE int __fastcall IdSslUCTTimeDecode(PASN1_UTCTIME UCTtime, System::Word &year, System::Word &month, System::Word &day, System::Word &hour, System::Word &min, System::Word &sec, int &tz_hour, int &tz_min);
extern PACKAGE int __fastcall IdSslSetAppData(PSSL s, void * arg);
extern PACKAGE void * __fastcall IdSslGetAppData(PSSL s);
extern PACKAGE void __fastcall InitializeRandom(void);
extern PACKAGE int __fastcall IdSslMASN1StringLength(PASN1_STRING x);
extern PACKAGE void __fastcall IdSslMASN1StringLengthSet(PASN1_STRING x, int n);
extern PACKAGE int __fastcall IdSslMASN1StringType(PASN1_STRING x);
extern PACKAGE char * __fastcall IdSslMASN1StringData(PASN1_STRING x);
extern PACKAGE void * __fastcall IdSslX509StoreCtxGetAppData(PX509_STORE_CTX ctx);
extern PACKAGE int __fastcall IdSslX509GetVersion(PX509 x);
extern PACKAGE int __fastcall IdSslX509GetSignatureType(PX509 x);
extern PACKAGE PX509_NAME __fastcall IdSslX509ReqGetSubjectName(PX509_REQ x);
extern PACKAGE PASN1_TIME __fastcall IdSslX509GetNotBefore(PX509 x509);
extern PACKAGE PASN1_TIME __fastcall IdSslX509GetNotAfter(PX509 x509);
extern PACKAGE int __fastcall IdX509ReqGetVersion(PX509_REQ x);
extern PACKAGE int __fastcall IdSslX509CRLGetVersion(PX509_CRL x);
extern PACKAGE PASN1_TIME __fastcall IdSslX509CRLGetLastUpdate(PX509_CRL x);
extern PACKAGE PASN1_TIME __fastcall IdSslX509CRLGetNextUpdate(PX509_CRL x);
extern PACKAGE PX509_NAME __fastcall IdX509CRLGetIssuer(PX509_CRL x);
extern PACKAGE PSTACK __fastcall IdSslCRLGetRevoked(PX509_CRL x);
extern PACKAGE void __fastcall IdSslCtxSetInfoCallback(PSSL_CTX ctx, PSSL_CTX_info_callback cb);
extern PACKAGE int __fastcall IdSslCtxSetOptions(PSSL_CTX ctx, int op);
extern PACKAGE int __fastcall IdSslCtxSetMode(PSSL_CTX ctx, int op);
extern PACKAGE int __fastcall IdSslCtxGetMode(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslSetMtu(PSSL ssl, int mtu);
extern PACKAGE int __fastcall IdSslCtxSessNumber(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessConnect(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessConnectionGood(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessConnectionRenegotiate(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessAccept(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessAcceptRenegotiate(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessAcceptGood(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessBits(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessCbBit(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessMisses(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessTimeouts(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessCacheFull(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSessSetCacheSize(PSSL_CTX ctx, int t);
extern PACKAGE int __fastcall IdSslCtxSessGetCacheSize(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSetSessionCacheMode(PSSL_CTX ctx, int m);
extern PACKAGE int __fastcall IdSslCtxGetSessionCacheMode(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxGetReadAhead(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSetReadAhead(PSSL_CTX ctx, int m);
extern PACKAGE int __fastcall IdSSlCtxGetMaxCertList(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslCtxSetMaxCertList(PSSL_CTX ctx, int m);
extern PACKAGE int __fastcall IdSslGetMaxCertList(PSSL ssl);
extern PACKAGE int __fastcall IdSslSetMaxCertList(PSSL ssl, int m);
extern PACKAGE int __fastcall IdSslSetTlsExtHostName(PSSL s, System::AnsiString name);
extern PACKAGE int __fastcall IdSslSetTlsExtDebugCallback(PSSL ssl, SSL_callback_ctrl_fp cb);
extern PACKAGE int __fastcall IdSslSetTlsExtDebugArg(PSSL ssl, void * arg);
extern PACKAGE int __fastcall IdSslSetTlsExtStatusType(PSSL ssl, int _type);
extern PACKAGE int __fastcall IdSslGetTlsExtStatusExts(PSSL ssl, void * arg);
extern PACKAGE int __fastcall IdSslSetTlsExtStatusExts(PSSL ssl, void * arg);
extern PACKAGE int __fastcall IdSslGetTlsextStatusIds(PSSL ssl, void * arg);
extern PACKAGE int __fastcall IdSslSetTlsExtStatusIds(PSSL ssl, void * arg);
extern PACKAGE int __fastcall IdSslGetTlsExtStatusOcspResp(PSSL ssl, void * arg);
extern PACKAGE int __fastcall IdSslSetTlsExtStatusOcspResp(PSSL ssl, void * arg, int arglen);
extern PACKAGE int __fastcall IdSslSslCtxSetTlsExtServerNameCallback(PSSL_CTX ctx, SSL_callback_ctrl_fp cb);
extern PACKAGE int __fastcall IdSslCtxGetVersion(PSSL_CTX ctx);
extern PACKAGE int __fastcall IdSslBioSetClose(PBIO b, int c);
extern PACKAGE void __fastcall IdSslBioGetMemPtr(PBIO b, void * pp);
extern PACKAGE int __fastcall IdSslBioPending(PBIO b);
extern PACKAGE PX509 __fastcall IdSslPemReadBio(PBIO bp, void * x, ppem_password_cb cb, char * u);
extern PACKAGE int __fastcall IdSslPemWriteBio(PBIO b, char * x);
extern PACKAGE void * __fastcall IdSslMalloc(int aSize);
extern PACKAGE void __fastcall IdSslMemCheck(const bool aEnabled);
extern PACKAGE int __fastcall IdSslEvpPKeyAssignRsa(PEVP_MD pkey, char * rsa);
extern PACKAGE void __fastcall IdSslX509V3SetCtxNoDb(const V3_EXT_CTX &ctx);

}	/* namespace Idsslopensslheaders */
using namespace Idsslopensslheaders;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdsslopensslheadersHPP
