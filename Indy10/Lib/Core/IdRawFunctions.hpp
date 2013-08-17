// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrawfunctions.pas' rev: 20.00

#ifndef IdrawfunctionsHPP
#define IdrawfunctionsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idrawheaders.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrawfunctions
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall IdRawBuildArp(const System::Word AHwAddressFormat, const System::Word AProtocolFormat, const System::Byte AHwAddressLen, const System::Byte AProtocolLen, const System::Word AnOpType, Idrawheaders::TIdEtherAddr* ASenderHw, Idrawheaders::TIdInAddr* ASenderPr, Idrawheaders::TIdEtherAddr* ATargetHw, Idrawheaders::TIdInAddr* ATargetPr, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildDns(const System::Word AnId, const System::Word AFlags, const System::Word ANumQuestions, const System::Word ANumAnswerRecs, const System::Word ANumAuthRecs, const System::Word ANumAddRecs, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildEthernet(Idrawheaders::TIdEtherAddr* ADest, Idrawheaders::TIdEtherAddr* ASource, System::Word AType, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIp(System::Word ALen, System::Byte ATos, System::Word AnId, System::Word AFrag, System::Byte ATtl, System::Byte AProtocol, Idrawheaders::TIdInAddr* ASource, Idrawheaders::TIdInAddr* ADest, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer, const int AIdx = 0x0);
extern PACKAGE void __fastcall IdRawBuildIcmpEcho(System::Byte AType, System::Byte ACode, System::Word AnId, System::Word ASeq, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIcmpMask(System::Byte AType, System::Byte ACode, System::Word AnId, System::Word ASeq, unsigned AMask, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIcmpUnreach(System::Byte AType, System::Byte ACode, System::Word AnOrigLen, System::Byte AnOrigTos, System::Word AnOrigId, System::Word AnOrigFrag, System::Byte AnOrigTtl, System::Byte AnOrigProtocol, Idrawheaders::TIdInAddr* AnOrigSource, Idrawheaders::TIdInAddr* AnOrigDest, const int AnOrigPayload, const int APayloadSize, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIcmpTimeExceed(const System::Byte AType, const System::Byte ACode, const System::Word AnOrigLen, const System::Byte AnOrigTos, const System::Word AnOrigId, const System::Word AnOrigFrag, const System::Byte AnOrigTtl, const System::Byte AnOrigProtocol, const Idrawheaders::TIdInAddr* AnOrigSource, const Idrawheaders::TIdInAddr* AnOrigDest, const Sysutils::TBytes AnOrigPayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIcmpTimestamp(const System::Byte AType, const System::Byte ACode, const System::Word AnId, const System::Word ASeq, const unsigned AnOtime, const unsigned AnRtime, const unsigned ATtime, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIcmpRedirect(const System::Byte AType, const System::Byte ACode, Idrawheaders::TIdInAddr* AGateway, const System::Word AnOrigLen, const System::Byte AnOrigTos, const System::Word AnOrigId, const System::Word AnOrigFrag, const System::Byte AnOrigTtl, const System::Byte AnOrigProtocol, Idrawheaders::TIdInAddr* AnOrigSource, Idrawheaders::TIdInAddr* AnOrigDest, const Sysutils::TBytes AnOrigPayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildIgmp(System::Byte AType, System::Byte ACode, Idrawheaders::TIdInAddr* AnIp, const System::Word APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildRip(const System::Byte ACommand, const System::Byte AVersion, const System::Word ARoutingDomain, const System::Word AnAddressFamily, const System::Word ARoutingTag, const unsigned AnAddr, const unsigned AMask, const unsigned ANextHop, const unsigned AMetric, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildTcp(const System::Word ASourcePort, const System::Word ADestPort, const unsigned ASeq, const unsigned AnAck, const System::Byte AControl, const System::Word AWindowSize, const System::Word AnUrgent, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);
extern PACKAGE void __fastcall IdRawBuildUdp(const System::Word ASourcePort, const System::Word ADestPort, const Sysutils::TBytes APayload, Sysutils::TBytes &VBuffer);

}	/* namespace Idrawfunctions */
using namespace Idrawfunctions;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrawfunctionsHPP
