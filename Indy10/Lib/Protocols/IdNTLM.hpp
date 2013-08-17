// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idntlm.pas' rev: 20.00

#ifndef IdntlmHPP
#define IdntlmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idstruct.hpp>	// Pascal unit
#include <Idsslopensslheaders.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idntlm
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct type_1_message_header
{
	
public:
	StaticArray<char, 8> protocol;
	System::Byte _type;
	StaticArray<System::Byte, 3> pad;
	System::Word flags;
	StaticArray<System::Byte, 2> pad2;
	System::Word dom_len1;
	System::Word dom_len2;
	unsigned dom_off;
	System::Word host_len1;
	System::Word host_len2;
	unsigned host_off;
};
#pragma pack(pop)


#pragma pack(push,1)
struct type_2_message_header
{
	
public:
	StaticArray<char, 8> protocol;
	System::Byte _type;
	StaticArray<System::Byte, 7> Pad;
	System::Word msg_len;
	StaticArray<System::Byte, 2> Pad2;
	System::Word flags;
	StaticArray<System::Byte, 2> Pad3;
	StaticArray<System::WideChar, 8> nonce;
	StaticArray<System::Byte, 8> pad4;
};
#pragma pack(pop)


#pragma pack(push,1)
struct type_3_message_header
{
	
public:
	StaticArray<char, 8> protocol;
	unsigned _type;
	System::Word lm_resp_len1;
	System::Word lm_resp_len2;
	unsigned lm_resp_off;
	System::Word nt_resp_len1;
	System::Word nt_resp_len2;
	unsigned nt_resp_off;
	System::Word dom_len1;
	System::Word dom_len2;
	unsigned dom_off;
	System::Word user_len1;
	System::Word user_len2;
	unsigned user_off;
	System::Word host_len1;
	System::Word host_len2;
	unsigned host_off;
	unsigned zero;
	unsigned msg_len;
	unsigned flags;
};
#pragma pack(pop)


typedef Idsslopensslheaders::des_key_schedule *Pdes_key_schedule;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Word MSG1_FLAGS;
extern PACKAGE unsigned MSG1_HOST_OFFS;
extern PACKAGE System::Word MSG3_LM_RESP_LEN;
extern PACKAGE System::Word MSG3_NT_RESP_LEN;
extern PACKAGE unsigned MSG3_DOM_OFFS;
extern PACKAGE unsigned MSG3_FLAGS;
extern PACKAGE unsigned MSG3_TYPE;
extern PACKAGE void __fastcall GetDomain(const System::UnicodeString AUserName, System::UnicodeString &VUserName, System::UnicodeString &VDomain);
extern PACKAGE bool __fastcall NTLMFunctionsLoaded(void);
extern PACKAGE System::UnicodeString __fastcall BuildType1Message(const System::UnicodeString ADomain, const System::UnicodeString AHost);
extern PACKAGE System::UnicodeString __fastcall BuildType3Message(const System::UnicodeString ADomain, const System::UnicodeString AHost, const System::UnicodeString AUsername, System::UnicodeString APassword, System::UnicodeString ANonce);

}	/* namespace Idntlm */
using namespace Idntlm;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdntlmHPP
