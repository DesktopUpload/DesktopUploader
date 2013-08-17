// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idstackconsts.pas' rev: 20.00

#ifndef IdstackconstsHPP
#define IdstackconstsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idwship6.hpp>	// Pascal unit
#include <Idwinsock2.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstackconsts
{
//-- type declarations -------------------------------------------------------
typedef unsigned TIdStackSocketHandle;

typedef unsigned TIdSocketType;

typedef int TIdSocketProtocol;

typedef int TIdSocketOption;

typedef int TIdSocketOptionLevel;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int Id_SO_True;
extern PACKAGE int Id_SO_False;
static const ShortInt Id_IPV6_HDRINCL = 0x2;
static const ShortInt Id_IPV6_UNICAST_HOPS = 0x4;
static const ShortInt Id_IPV6_MULTICAST_IF = 0x9;
static const ShortInt Id_IPV6_MULTICAST_HOPS = 0xa;
static const ShortInt Id_IPV6_MULTICAST_LOOP = 0xb;
static const ShortInt Id_IPV6_ADD_MEMBERSHIP = 0xc;
static const ShortInt Id_IPV6_DROP_MEMBERSHIP = 0xd;
static const ShortInt Id_IPV6_PKTINFO = 0x13;
static const ShortInt Id_IPV6_HOPLIMIT = 0x15;
static const ShortInt Id_IP_MULTICAST_TTL = 0xa;
static const ShortInt Id_IP_MULTICAST_LOOP = 0xb;
static const ShortInt Id_IP_ADD_MEMBERSHIP = 0xc;
static const ShortInt Id_IP_DROP_MEMBERSHIP = 0xd;
static const ShortInt Id_IP_HDR_INCLUDED = 0x2;
static const ShortInt Id_PF_INET4 = 0x2;
static const ShortInt Id_PF_INET6 = 0x17;
static const ShortInt Id_SOCK_STREAM = 0x1;
static const ShortInt Id_SOCK_DGRAM = 0x2;
static const ShortInt Id_SOCK_RAW = 0x3;
static const ShortInt Id_SOCK_RDM = 0x4;
static const ShortInt Id_SOCK_SEQPACKET = 0x5;
static const ShortInt Id_IPPROTO_GGP = 0x3;
static const ShortInt Id_IPPROTO_ICMP = 0x1;
static const ShortInt Id_IPPROTO_ICMPV6 = 0x3a;
static const ShortInt Id_IPPROTO_IDP = 0x16;
static const ShortInt Id_IPPROTO_IGMP = 0x2;
static const ShortInt Id_IPPROTO_IP = 0x0;
static const ShortInt Id_IPPROTO_IPv6 = 0x29;
static const ShortInt Id_IPPROTO_ND = 0x4d;
static const ShortInt Id_IPPROTO_PUP = 0xc;
static const Byte Id_IPPROTO_RAW = 0xff;
static const ShortInt Id_IPPROTO_TCP = 0x6;
static const ShortInt Id_IPPROTO_UDP = 0x11;
static const Word Id_IPPROTO_MAX = 0x100;
static const Word Id_SOL_SOCKET = 0xffff;
static const ShortInt Id_SOL_IP = 0x0;
static const ShortInt Id_SOL_IPv6 = 0x29;
static const ShortInt Id_SOL_TCP = 0x6;
static const ShortInt Id_SOL_UDP = 0x11;
static const ShortInt Id_SO_BROADCAST = 0x20;
static const ShortInt Id_SO_DEBUG = 0x1;
static const ShortInt Id_SO_DONTROUTE = 0x10;
static const ShortInt Id_SO_KEEPALIVE = 0x8;
static const Byte Id_SO_LINGER = 0x80;
static const Word Id_SO_OOBINLINE = 0x100;
static const Word Id_SO_RCVBUF = 0x1002;
static const ShortInt Id_SO_REUSEADDR = 0x4;
static const Word Id_SO_SNDBUF = 0x1001;
static const Word Id_SO_RCVTIMEO = 0x1006;
static const Word Id_SO_SNDTIMEO = 0x1005;
static const ShortInt Id_SO_IP_TTL = 0x4;
static const ShortInt Id_INADDR_ANY = 0x0;
static const unsigned Id_INADDR_NONE = 0xffffffff;
static const ShortInt Id_TCP_NODELAY = 0x1;
static const unsigned Id_INVALID_SOCKET = 0xffffffff;
static const ShortInt Id_SOCKET_ERROR = -1;
static const ShortInt Id_SOCKETOPTIONLEVEL_TCP = 0x6;
static const ShortInt Id_SD_Recv = 0x0;
static const ShortInt Id_SD_Send = 0x1;
static const ShortInt Id_SD_Both = 0x2;
static const Word Id_WSAEINTR = 0x2714;
static const Word Id_WSAEBADF = 0x2719;
static const Word Id_WSAEACCES = 0x271d;
static const Word Id_WSAEFAULT = 0x271e;
static const Word Id_WSAEINVAL = 0x2726;
static const Word Id_WSAEMFILE = 0x2728;
static const Word Id_WSAEWOULDBLOCK = 0x2733;
static const Word Id_WSAEINPROGRESS = 0x2734;
static const Word Id_WSAEALREADY = 0x2735;
static const Word Id_WSAENOTSOCK = 0x2736;
static const Word Id_WSAEDESTADDRREQ = 0x2737;
static const Word Id_WSAEMSGSIZE = 0x2738;
static const Word Id_WSAEPROTOTYPE = 0x2739;
static const Word Id_WSAENOPROTOOPT = 0x273a;
static const Word Id_WSAEPROTONOSUPPORT = 0x273b;
static const Word Id_WSAESOCKTNOSUPPORT = 0x273c;
static const Word Id_WSAEOPNOTSUPP = 0x273d;
static const Word Id_WSAEPFNOSUPPORT = 0x273e;
static const Word Id_WSAEAFNOSUPPORT = 0x273f;
static const Word Id_WSAEADDRINUSE = 0x2740;
static const Word Id_WSAEADDRNOTAVAIL = 0x2741;
static const Word Id_WSAENETDOWN = 0x2742;
static const Word Id_WSAENETUNREACH = 0x2743;
static const Word Id_WSAENETRESET = 0x2744;
static const Word Id_WSAECONNABORTED = 0x2745;
static const Word Id_WSAECONNRESET = 0x2746;
static const Word Id_WSAENOBUFS = 0x2747;
static const Word Id_WSAEISCONN = 0x2748;
static const Word Id_WSAENOTCONN = 0x2749;
static const Word Id_WSAESHUTDOWN = 0x274a;
static const Word Id_WSAETOOMANYREFS = 0x274b;
static const Word Id_WSAETIMEDOUT = 0x274c;
static const Word Id_WSAECONNREFUSED = 0x274d;
static const Word Id_WSAELOOP = 0x274e;
static const Word Id_WSAENAMETOOLONG = 0x274f;
static const Word Id_WSAEHOSTDOWN = 0x2750;
static const Word Id_WSAEHOSTUNREACH = 0x2751;
static const Word Id_WSAENOTEMPTY = 0x2752;

}	/* namespace Idstackconsts */
using namespace Idstackconsts;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdstackconstsHPP
