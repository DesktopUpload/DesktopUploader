// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Idrawheaders.pas' rev: 20.00

#ifndef IdrawheadersHPP
#define IdrawheadersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Idstruct.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idrawheaders
{
//-- type declarations -------------------------------------------------------
typedef unsigned uint32_t;

typedef System::Word uint16_t;

typedef System::Byte uint8_t;

class DELPHICLASS TIdSunB;
class PASCALIMPLEMENTATION TIdSunB : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Byte Fs_b1;
	System::Byte Fs_b2;
	System::Byte Fs_b3;
	System::Byte Fs_b4;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Byte s_b1 = {read=Fs_b1, write=Fs_b1, nodefault};
	__property System::Byte s_b2 = {read=Fs_b2, write=Fs_b2, nodefault};
	__property System::Byte s_b3 = {read=Fs_b3, write=Fs_b3, nodefault};
	__property System::Byte s_b4 = {read=Fs_b4, write=Fs_b4, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdSunB(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdSunB(void) { }
	
};


class DELPHICLASS TIdSunW;
class PASCALIMPLEMENTATION TIdSunW : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Fs_w1;
	System::Word Fs_w2;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word s_w1 = {read=Fs_w1, write=Fs_w1, nodefault};
	__property System::Word s_w2 = {read=Fs_w2, write=Fs_w2, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdSunW(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdSunW(void) { }
	
};


class DELPHICLASS TIdInAddr;
class PASCALIMPLEMENTATION TIdInAddr : public Idstruct::TIdLongWord
{
	typedef Idstruct::TIdLongWord inherited;
	
public:
	void __fastcall CopyFrom(const TIdInAddr* ASource);
public:
	/* TIdLongWord.Create */ inline __fastcall virtual TIdInAddr(void) : Idstruct::TIdLongWord() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdInAddr(void) { }
	
};


typedef unsigned TIdNetTime;

class DELPHICLASS TIdICMPEcho;
class PASCALIMPLEMENTATION TIdICMPEcho : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Fid;
	System::Word Fseq;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word id = {read=Fid, write=Fid, nodefault};
	__property System::Word seq = {read=Fseq, write=Fseq, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdICMPEcho(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdICMPEcho(void) { }
	
};


class DELPHICLASS TIdICMPFrag;
class PASCALIMPLEMENTATION TIdICMPFrag : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Fpad;
	System::Word Fmtu;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word pad = {read=Fpad, write=Fpad, nodefault};
	__property System::Word mtu = {read=Fmtu, write=Fmtu, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdICMPFrag(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdICMPFrag(void) { }
	
};


class DELPHICLASS TIdICMPTs;
class PASCALIMPLEMENTATION TIdICMPTs : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	unsigned Fotime;
	unsigned Frtime;
	unsigned Fttime;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property unsigned otime = {read=Fotime, write=Fotime, nodefault};
	__property unsigned rtime = {read=Frtime, write=Frtime, nodefault};
	__property unsigned ttime = {read=Fttime, write=Fttime, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdICMPTs(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdICMPTs(void) { }
	
};


class DELPHICLASS TIdicmp_hun;
class PASCALIMPLEMENTATION TIdicmp_hun : public Idstruct::TIdUnion
{
	typedef Idstruct::TIdUnion inherited;
	
protected:
	System::Word __fastcall Getecho_id(void);
	System::Word __fastcall Getecho_seq(void);
	System::Word __fastcall Getfrag_mtu(void);
	System::Word __fastcall Getfrag_pad(void);
	System::Byte __fastcall Getgateway_s_b1(void);
	System::Byte __fastcall Getgateway_s_b2(void);
	System::Byte __fastcall Getgateway_s_b3(void);
	System::Byte __fastcall Getgateway_s_b4(void);
	unsigned __fastcall Getgateway_s_l(void);
	System::Word __fastcall Getgateway_s_w1(void);
	System::Word __fastcall Getgateway_s_w2(void);
	void __fastcall Setecho_id(const System::Word Value);
	void __fastcall Setecho_seq(const System::Word Value);
	void __fastcall Setfrag_mtu(const System::Word Value);
	void __fastcall Setfrag_pad(const System::Word Value);
	void __fastcall Setgateway_s_b1(const System::Byte Value);
	void __fastcall Setgateway_s_b2(const System::Byte Value);
	void __fastcall Setgateway_s_b3(const System::Byte Value);
	void __fastcall Setgateway_s_b4(const System::Byte Value);
	void __fastcall Setgateway_s_l(const unsigned Value);
	void __fastcall Setgateway_s_w1(const System::Word Value);
	void __fastcall Setgateway_s_w2(const System::Word Value);
	
public:
	__fastcall virtual TIdicmp_hun(void);
	__property System::Word echo_id = {read=Getecho_id, write=Setecho_id, nodefault};
	__property System::Word echo_seq = {read=Getecho_seq, write=Setecho_seq, nodefault};
	__property System::Byte gateway_s_b1 = {read=Getgateway_s_b1, write=Setgateway_s_b1, nodefault};
	__property System::Byte gateway_s_b2 = {read=Getgateway_s_b2, write=Setgateway_s_b2, nodefault};
	__property System::Byte gateway_s_b3 = {read=Getgateway_s_b3, write=Setgateway_s_b3, nodefault};
	__property System::Byte gateway_s_b4 = {read=Getgateway_s_b4, write=Setgateway_s_b4, nodefault};
	__property System::Word gateway_s_w1 = {read=Getgateway_s_w1, write=Setgateway_s_w1, nodefault};
	__property System::Word gateway_s_w2 = {read=Getgateway_s_w2, write=Setgateway_s_w2, nodefault};
	__property unsigned gateway_s_l = {read=Getgateway_s_l, write=Setgateway_s_l, nodefault};
	__property System::Word frag_pad = {read=Getfrag_pad, write=Setfrag_pad, nodefault};
	__property System::Word frag_mtu = {read=Getfrag_mtu, write=Setfrag_mtu, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdicmp_hun(void) { }
	
};


class DELPHICLASS TIdicmp_dun;
class PASCALIMPLEMENTATION TIdicmp_dun : public Idstruct::TIdUnion
{
	typedef Idstruct::TIdUnion inherited;
	
protected:
	System::Byte __fastcall Getdata(void);
	unsigned __fastcall Getmask(void);
	void __fastcall setdata(const System::Byte Value);
	void __fastcall Setmask(const unsigned Value);
	unsigned __fastcall Getts_otime(void);
	unsigned __fastcall Getts_rtime(void);
	unsigned __fastcall Getts_ttime(void);
	void __fastcall Setts_otime(const unsigned Value);
	void __fastcall Setts_rtime(const unsigned Value);
	void __fastcall Setts_ttime(const unsigned Value);
	
public:
	__fastcall virtual TIdicmp_dun(void);
	__property unsigned ts_otime = {read=Getts_otime, write=Setts_otime, nodefault};
	__property unsigned ts_rtime = {read=Getts_rtime, write=Setts_rtime, nodefault};
	__property unsigned ts_ttime = {read=Getts_ttime, write=Setts_ttime, nodefault};
	__property unsigned mask = {read=Getmask, write=Setmask, nodefault};
	__property System::Byte data = {read=Getdata, write=setdata, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdicmp_dun(void) { }
	
};


class DELPHICLASS TIdICMPHdr;
class PASCALIMPLEMENTATION TIdICMPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Byte Ficmp_type;
	System::Byte Ficmp_code;
	System::Word Ficmp_sum;
	TIdicmp_hun* Ficmp_hun;
	TIdicmp_dun* Ficmp_dun;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	__fastcall virtual TIdICMPHdr(void);
	__fastcall virtual ~TIdICMPHdr(void);
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Byte icmp_type = {read=Ficmp_type, write=Ficmp_type, nodefault};
	__property System::Byte icmp_code = {read=Ficmp_code, write=Ficmp_code, nodefault};
	__property System::Word icmp_sum = {read=Ficmp_sum, write=Ficmp_sum, nodefault};
	__property TIdicmp_hun* icmp_hun = {read=Ficmp_hun};
	__property TIdicmp_dun* icmp_dun = {read=Ficmp_dun};
};


class DELPHICLASS TIdicmp6_un;
class PASCALIMPLEMENTATION TIdicmp6_un : public Idstruct::TIdUnion
{
	typedef Idstruct::TIdUnion inherited;
	
protected:
	System::Word __fastcall Geticmp6_data16(void);
	System::Byte __fastcall Geticmp6_data8(void);
	void __fastcall Seticmp6_data16(const System::Word Value);
	void __fastcall Seticmp6_data8(const System::Byte Value);
	System::Word __fastcall Geticmp6_seq(void);
	void __fastcall Seticmp6_seq(const System::Word Value);
	System::Word __fastcall Geticmp6_un_data16(int Index);
	unsigned __fastcall Geticmp6_un_data32(void);
	System::Byte __fastcall Geticmp6_un_data8(int Index);
	void __fastcall Seticmp6_un_data16(int Index, const System::Word Value);
	void __fastcall Seticmp6_un_data32(const unsigned Value);
	void __fastcall Seticmp6_un_data8(int Index, const System::Byte Value);
	
public:
	__fastcall virtual TIdicmp6_un(void);
	__property unsigned icmp6_un_data32 = {read=Geticmp6_un_data32, write=Seticmp6_un_data32, nodefault};
	__property System::Word icmp6_un_data16[int Index] = {read=Geticmp6_un_data16, write=Seticmp6_un_data16};
	__property System::Byte icmp6_un_data8[int Index] = {read=Geticmp6_un_data8, write=Seticmp6_un_data8};
	__property unsigned icmp6_data32 = {read=Geticmp6_un_data32, write=Seticmp6_un_data32, nodefault};
	__property System::Word icmp6_data16 = {read=Geticmp6_data16, write=Seticmp6_data16, nodefault};
	__property System::Byte icmp6_data8 = {read=Geticmp6_data8, write=Seticmp6_data8, nodefault};
	__property unsigned icmp6_pptr = {read=Geticmp6_un_data32, write=Seticmp6_un_data32, nodefault};
	__property unsigned icmp6_mtu = {read=Geticmp6_un_data32, write=Seticmp6_un_data32, nodefault};
	__property System::Word icmp6_id = {read=Geticmp6_data16, write=Seticmp6_data16, nodefault};
	__property System::Word icmp6_seq = {read=Geticmp6_seq, write=Seticmp6_seq, nodefault};
	__property System::Word icmp6_maxdelay = {read=Geticmp6_data16, write=Seticmp6_data16, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdicmp6_un(void) { }
	
};


class DELPHICLASS TIdicmp6_hdr;
class PASCALIMPLEMENTATION TIdicmp6_hdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Byte Ficmp6_type;
	System::Byte FIcmp6_code;
	System::Word Ficmp6_cksum;
	TIdicmp6_un* Fdata;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	__fastcall virtual TIdicmp6_hdr(void);
	__fastcall virtual ~TIdicmp6_hdr(void);
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Byte icmp6_type = {read=Ficmp6_type, write=Ficmp6_type, nodefault};
	__property System::Byte icmp6_code = {read=FIcmp6_code, write=FIcmp6_code, nodefault};
	__property System::Word icmp6_cksum = {read=Ficmp6_cksum, write=Ficmp6_cksum, nodefault};
	__property TIdicmp6_un* data = {read=Fdata};
};


class DELPHICLASS TIdIPOptions;
class PASCALIMPLEMENTATION TIdIPOptions : public Idstruct::TIdUnion
{
	typedef Idstruct::TIdUnion inherited;
	
public:
	System::Byte operator[](int Index) { return ipopt_list[Index]; }
	
public:
	__fastcall virtual TIdIPOptions(void);
	System::Byte __fastcall get_ipopt_list(int Index);
	void __fastcall set_ipopt_list(int Index, const System::Byte Value);
	__property System::Byte ipopt_list[int Index] = {read=get_ipopt_list, write=set_ipopt_list/*, default*/};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdIPOptions(void) { }
	
};


class DELPHICLASS TIdIPHdr;
class PASCALIMPLEMENTATION TIdIPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Byte Fip_verlen;
	System::Byte Fip_tos;
	System::Word Fip_len;
	System::Word Fip_id;
	System::Word Fip_off;
	System::Byte Fip_ttl;
	System::Byte Fip_p;
	System::Word Fip_sum;
	TIdInAddr* Fip_src;
	TIdInAddr* Fip_dst;
	unsigned Fip_options;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	__fastcall virtual TIdIPHdr(void);
	__fastcall virtual ~TIdIPHdr(void);
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	void __fastcall CopyFrom(const TIdIPHdr* ASource);
	__property System::Byte ip_verlen = {read=Fip_verlen, write=Fip_verlen, nodefault};
	__property System::Byte ip_tos = {read=Fip_tos, write=Fip_tos, nodefault};
	__property System::Word ip_len = {read=Fip_len, write=Fip_len, nodefault};
	__property System::Word ip_id = {read=Fip_id, write=Fip_id, nodefault};
	__property System::Word ip_off = {read=Fip_off, write=Fip_off, nodefault};
	__property System::Byte ip_ttl = {read=Fip_ttl, write=Fip_ttl, nodefault};
	__property System::Byte ip_p = {read=Fip_p, write=Fip_p, nodefault};
	__property System::Word ip_sum = {read=Fip_sum, write=Fip_sum, nodefault};
	__property TIdInAddr* ip_src = {read=Fip_src};
	__property TIdInAddr* ip_dst = {read=Fip_dst};
	__property unsigned ip_options = {read=Fip_options, write=Fip_options, nodefault};
};


class DELPHICLASS TIdTCPOptions;
class PASCALIMPLEMENTATION TIdTCPOptions : public Idstruct::TIdUnion
{
	typedef Idstruct::TIdUnion inherited;
	
public:
	System::Byte operator[](int Index) { return tcpopt_list[Index]; }
	
public:
	__fastcall virtual TIdTCPOptions(void);
	System::Byte __fastcall gettcpopt_list(int Index);
	void __fastcall settcpopt_list(int Index, const System::Byte Value);
	__property System::Byte tcpopt_list[int Index] = {read=gettcpopt_list, write=settcpopt_list/*, default*/};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdTCPOptions(void) { }
	
};


class DELPHICLASS TIdTCPHdr;
class PASCALIMPLEMENTATION TIdTCPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Ftcp_sport;
	System::Word Ftcp_dport;
	unsigned Ftcp_seq;
	unsigned Ftcp_ack;
	System::Byte Ftcp_x2off;
	System::Byte Ftcp_flags;
	System::Word Ftcp_win;
	System::Word Ftcp_sum;
	System::Word Ftcp_urp;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word tcp_sport = {read=Ftcp_sport, write=Ftcp_sport, nodefault};
	__property System::Word tcp_dport = {read=Ftcp_dport, write=Ftcp_dport, nodefault};
	__property unsigned tcp_seq = {read=Ftcp_seq, write=Ftcp_seq, nodefault};
	__property unsigned tcp_ack = {read=Ftcp_ack, write=Ftcp_ack, nodefault};
	__property System::Byte tcp_x2off = {read=Ftcp_x2off, write=Ftcp_x2off, nodefault};
	__property System::Byte tcp_flags = {read=Ftcp_flags, write=Ftcp_flags, nodefault};
	__property System::Word tcp_win = {read=Ftcp_win, write=Ftcp_win, nodefault};
	__property System::Word tcp_sum = {read=Ftcp_sum, write=Ftcp_sum, nodefault};
	__property System::Word tcp_urp = {read=Ftcp_urp, write=Ftcp_urp, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdTCPHdr(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdTCPHdr(void) { }
	
};


class DELPHICLASS TIdUDPHdr;
class PASCALIMPLEMENTATION TIdUDPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Fudp_sport;
	System::Word Fudp_dport;
	System::Word Fudp_ulen;
	System::Word Fudp_sum;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word udp_sport = {read=Fudp_sport, write=Fudp_sport, nodefault};
	__property System::Word udp_dport = {read=Fudp_dport, write=Fudp_dport, nodefault};
	__property System::Word udp_ulen = {read=Fudp_ulen, write=Fudp_ulen, nodefault};
	__property System::Word udp_sum = {read=Fudp_sum, write=Fudp_sum, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdUDPHdr(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdUDPHdr(void) { }
	
};


class DELPHICLASS TIdIGMPHdr;
class PASCALIMPLEMENTATION TIdIGMPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Byte Figmp_type;
	System::Byte Figmp_code;
	System::Word Figmp_sum;
	TIdInAddr* Figmp_group;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	__fastcall virtual TIdIGMPHdr(void);
	__fastcall virtual ~TIdIGMPHdr(void);
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Byte igmp_type = {read=Figmp_type, write=Figmp_type, nodefault};
	__property System::Byte igmp_code = {read=Figmp_code, write=Figmp_code, nodefault};
	__property System::Word igmp_sum = {read=Figmp_sum, write=Figmp_sum, nodefault};
	__property TIdInAddr* igmp_group = {read=Figmp_group};
};


class DELPHICLASS TIdEtherAddr;
class PASCALIMPLEMENTATION TIdEtherAddr : public Idstruct::TIdUnion
{
	typedef Idstruct::TIdUnion inherited;
	
public:
	System::Byte operator[](int Index) { return ether_addr_octet[Index]; }
	
public:
	__fastcall virtual TIdEtherAddr(void);
	void __fastcall CopyFrom(const TIdEtherAddr* ASource);
	void __fastcall SetData(const Sysutils::TBytes Value);
	System::Byte __fastcall getether_addr_octet(int Index);
	void __fastcall setether_addr_octet(int Index, const System::Byte Value);
	__property System::Byte ether_addr_octet[int Index] = {read=getether_addr_octet, write=setether_addr_octet/*, default*/};
	__property Sysutils::TBytes Data = {read=FBuffer, write=SetData};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdEtherAddr(void) { }
	
};


class DELPHICLASS TIdEthernetHdr;
class PASCALIMPLEMENTATION TIdEthernetHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	TIdEtherAddr* Fether_dhost;
	TIdEtherAddr* Fether_shost;
	System::Word Fether_type;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	__fastcall virtual TIdEthernetHdr(void);
	__fastcall virtual ~TIdEthernetHdr(void);
	void __fastcall CopyFrom(const TIdEthernetHdr* ASource);
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property TIdEtherAddr* ether_dhost = {read=Fether_dhost};
	__property TIdEtherAddr* ether_shost = {read=Fether_shost};
	__property System::Word ether_type = {read=Fether_type, write=Fether_type, nodefault};
};


class DELPHICLASS TIdARPHdr;
class PASCALIMPLEMENTATION TIdARPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Farp_hrd;
	System::Word Farp_pro;
	System::Byte Farp_hln;
	System::Byte Farp_pln;
	System::Word Farp_op;
	TIdEtherAddr* Farp_sha;
	TIdInAddr* Farp_spa;
	TIdEtherAddr* Farp_tha;
	TIdInAddr* Farp_tpa;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	__fastcall virtual TIdARPHdr(void);
	__fastcall virtual ~TIdARPHdr(void);
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word arp_hrd = {read=Farp_hrd, write=Farp_hrd, nodefault};
	__property System::Word arp_pro = {read=Farp_pro, write=Farp_pro, nodefault};
	__property System::Byte arp_hln = {read=Farp_hln, write=Farp_hln, nodefault};
	__property System::Byte arp_pln = {read=Farp_pln, write=Farp_pln, nodefault};
	__property System::Word arp_op = {read=Farp_op, write=Farp_op, nodefault};
	__property TIdEtherAddr* arp_sha = {read=Farp_sha};
	__property TIdInAddr* arp_spa = {read=Farp_spa};
	__property TIdEtherAddr* arp_tha = {read=Farp_tha};
	__property TIdInAddr* arp_tpa = {read=Farp_tpa};
};


class DELPHICLASS TIdDNSHdr;
class PASCALIMPLEMENTATION TIdDNSHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Word Fdns_id;
	System::Word Fdns_flags;
	System::Word Fdns_num_q;
	System::Word Fdns_num_answ_rr;
	System::Word Fdns_num_auth_rr;
	System::Word Fdns_num_addi_rr;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Word dns_id = {read=Fdns_id, write=Fdns_id, nodefault};
	__property System::Word dns_flags = {read=Fdns_flags, write=Fdns_flags, nodefault};
	__property System::Word dns_num_q = {read=Fdns_num_q, write=Fdns_num_q, nodefault};
	__property System::Word dns_num_answ_rr = {read=Fdns_num_answ_rr, write=Fdns_num_answ_rr, nodefault};
	__property System::Word dns_num_auth_rr = {read=Fdns_num_auth_rr, write=Fdns_num_auth_rr, nodefault};
	__property System::Word dns_num_addi_rr = {read=Fdns_num_addi_rr, write=Fdns_num_addi_rr, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdDNSHdr(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdDNSHdr(void) { }
	
};


class DELPHICLASS TIdRIPHdr;
class PASCALIMPLEMENTATION TIdRIPHdr : public Idstruct::TIdStruct
{
	typedef Idstruct::TIdStruct inherited;
	
protected:
	System::Byte Frip_cmd;
	System::Byte Frip_ver;
	System::Word Frip_rd;
	System::Word Frip_af;
	System::Word Frip_rt;
	unsigned Frip_addr;
	unsigned Frip_mask;
	unsigned Frip_next_hop;
	unsigned Frip_metric;
	virtual unsigned __fastcall GetBytesLen(void);
	
public:
	virtual void __fastcall ReadStruct(const Sysutils::TBytes ABytes, unsigned &VIndex);
	virtual void __fastcall WriteStruct(Sysutils::TBytes &VBytes, unsigned &VIndex);
	__property System::Byte rip_cmd = {read=Frip_cmd, write=Frip_cmd, nodefault};
	__property System::Byte rip_ver = {read=Frip_ver, write=Frip_ver, nodefault};
	__property System::Word rip_rd = {read=Frip_rd, write=Frip_rd, nodefault};
	__property System::Word rip_af = {read=Frip_af, write=Frip_af, nodefault};
	__property System::Word rip_rt = {read=Frip_rt, write=Frip_rt, nodefault};
	__property unsigned rip_addr = {read=Frip_addr, write=Frip_addr, nodefault};
	__property unsigned rip_mask = {read=Frip_mask, write=Frip_mask, nodefault};
	__property unsigned rip_next_hop = {read=Frip_next_hop, write=Frip_next_hop, nodefault};
	__property unsigned rip_metric = {read=Frip_metric, write=Frip_metric, nodefault};
public:
	/* TIdStruct.Create */ inline __fastcall virtual TIdRIPHdr(void) : Idstruct::TIdStruct() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TIdRIPHdr(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt Id_ARP_HSIZE = 0x1c;
static const ShortInt Id_DNS_HSIZE = 0xc;
static const ShortInt Id_ETH_HSIZE = 0xe;
static const ShortInt Id_ICMP_HSIZE = 0x4;
static const ShortInt Id_ICMP_ECHO_HSIZE = 0x8;
static const ShortInt Id_ICMP6_ECHO_HSIZE = 0x8;
static const ShortInt Id_ICMP_MASK_HSIZE = 0xc;
static const ShortInt Id_ICMP_UNREACH_HSIZE = 0x8;
static const ShortInt Id_ICMP_TIMEXCEED_HSIZE = 0x8;
static const ShortInt Id_ICMP_REDIRECT_HSIZE = 0x8;
static const ShortInt Id_ICMP_TS_HSIZE = 0x14;
static const ShortInt Id_IGMP_HSIZE = 0x8;
static const ShortInt Id_IP_HSIZE = 0x14;
static const ShortInt Id_IPv6_HSIZE = 0x28;
static const ShortInt Id_RIP_HSIZE = 0x18;
static const ShortInt Id_TCP_HSIZE = 0x14;
static const ShortInt Id_UDP_HSIZE = 0x8;
static const Word Id_IP_RF = 0x8000;
static const Word Id_IP_DF = 0x4000;
static const Word Id_IP_MF = 0x2000;
static const Word Id_IP_OFFMASK = 0x1fff;
static const ShortInt Id_TCP_FIN = 0x1;
static const ShortInt Id_TCP_SYN = 0x2;
static const ShortInt Id_TCP_RST = 0x4;
static const ShortInt Id_TCP_PUSH = 0x8;
static const ShortInt Id_TCP_ACK = 0x10;
static const ShortInt Id_TCP_URG = 0x20;
static const ShortInt Id_ICMP_ECHOREPLY = 0x0;
static const ShortInt Id_ICMP_UNREACH = 0x3;
static const ShortInt Id_ICMP_SOURCEQUENCH = 0x4;
static const ShortInt Id_ICMP_REDIRECT = 0x5;
static const ShortInt Id_ICMP_ECHO = 0x8;
static const ShortInt Id_ICMP_ROUTERADVERT = 0x9;
static const ShortInt Id_ICMP_ROUTERSOLICIT = 0xa;
static const ShortInt Id_ICMP_TIMXCEED = 0xb;
static const ShortInt Id_ICMP_PARAMPROB = 0xc;
static const ShortInt Id_ICMP_TSTAMP = 0xd;
static const ShortInt Id_ICMP_TSTAMPREPLY = 0xe;
static const ShortInt Id_ICMP_IREQ = 0xf;
static const ShortInt Id_ICMP_IREQREPLY = 0x10;
static const ShortInt Id_ICMP_MASKREQ = 0x11;
static const ShortInt Id_ICMP_MASKREPLY = 0x12;
static const ShortInt Id_ICMP_TRACEROUTE = 0x1e;
static const ShortInt Id_ICMP_DATAGRAM_CONV = 0x1f;
static const ShortInt Id_ICMP_MOB_HOST_REDIR = 0x20;
static const ShortInt Id_ICMP_IPv6_WHERE_ARE_YOU = 0x21;
static const ShortInt Id_ICMP_IPv6_I_AM_HERE = 0x22;
static const ShortInt Id_ICMP_MOB_REG_REQ = 0x23;
static const ShortInt Id_ICMP_MOB_REG_REPLY = 0x24;
static const ShortInt Id_ICMP_SKIP = 0x27;
static const ShortInt Id_ICMP_PHOTURIS = 0x28;
static const ShortInt Id_ICMP_UNREACH_NET = 0x0;
static const ShortInt Id_ICMP_UNREACH_HOST = 0x1;
static const ShortInt Id_ICMP_UNREACH_PROTOCOL = 0x2;
static const ShortInt Id_ICMP_UNREACH_PORT = 0x3;
static const ShortInt Id_ICMP_UNREACH_NEEDFRAG = 0x4;
static const ShortInt Id_ICMP_UNREACH_SRCFAIL = 0x5;
static const ShortInt Id_ICMP_UNREACH_NET_UNKNOWN = 0x6;
static const ShortInt Id_ICMP_UNREACH_HOST_UNKNOWN = 0x7;
static const ShortInt Id_ICMP_UNREACH_ISOLATED = 0x8;
static const ShortInt Id_ICMP_UNREACH_NET_PROHIB = 0x9;
static const ShortInt Id_ICMP_UNREACH_HOST_PROHIB = 0xa;
static const ShortInt Id_ICMP_UNREACH_TOSNET = 0xb;
static const ShortInt Id_ICMP_UNREACH_TOSHOST = 0xc;
static const ShortInt Id_ICMP_UNREACH_FILTER_PROHIB = 0xd;
static const ShortInt Id_ICMP_UNREACH_HOST_PRECEDENCE = 0xe;
static const ShortInt Id_ICMP_UNREACH_PRECEDENCE_CUTOFF = 0xf;
static const ShortInt Id_ICMP_REDIRECT_NET = 0x0;
static const ShortInt Id_ICMP_REDIRECT_HOST = 0x1;
static const ShortInt Id_ICMP_REDIRECT_TOSNET = 0x2;
static const ShortInt Id_ICMP_REDIRECT_TOSHOST = 0x3;
static const ShortInt Id_ICMP_TIMXCEED_INTRANS = 0x0;
static const ShortInt Id_ICMP_TIMXCEED_REASS = 0x1;
static const ShortInt Id_ICMP_PARAMPROB_OPTABSENT = 0x1;
static const ShortInt Id_ICMP_TRACEROUTE_PACKET_FORWARDED = 0x0;
static const ShortInt Id_ICMP_TRACEROUTE_NO_ROUTE = 0x1;
static const ShortInt Id_ICMP_BAD_SPI = 0x0;
static const ShortInt Id_ICMP_AUTH_FAILED = 0x1;
static const ShortInt Id_ICMP_DECOMPRESS_FAILED = 0x2;
static const ShortInt Id_ICMP_DECRYPTION_FAILED = 0x3;
static const ShortInt Id_ICMP_NEED_AUTHENTICATION = 0x4;
static const ShortInt Id_ICMP_NEED_AUTHORIZATION = 0x5;
static const ShortInt Id_ICMP_CONV_UNSPEC = 0x0;
static const ShortInt Id_ICMP_CONV_DONTCONV_OPTION = 0x1;
static const ShortInt Id_ICMP_CONV_UNKNOWN_MAN_OPTION = 0x2;
static const ShortInt Id_ICMP_CONV_UNKNWON_UNSEP_OPTION = 0x3;
static const ShortInt Id_ICMP_CONV_UNSEP_TRANSPORT = 0x4;
static const ShortInt Id_ICMP_CONV_OVERALL_LENGTH_EXCEEDED = 0x5;
static const ShortInt Id_ICMP_CONV_IP_HEADER_LEN_EXCEEDED = 0x6;
static const ShortInt Id_ICMP_CONV_TRANS_PROT_255 = 0x7;
static const ShortInt Id_ICMP_CONV_PORT_OUT_OF_RANGE = 0x8;
static const ShortInt Id_ICMP_CONV_TRANS_HEADER_LEN_EXCEEDED = 0x9;
static const ShortInt Id_ICMP_CONV_32BIT_ROLLOVER_AND_ACK = 0xa;
static const ShortInt Id_ICMP_CONV_UNKNOWN_MAN_TRANS_OPTION = 0xb;
static const ShortInt ICMP_MIN = 0x8;
static const ShortInt ICMP6_DST_UNREACH = 0x1;
static const ShortInt ICMP6_PACKET_TOO_BIG = 0x2;
static const ShortInt ICMP6_TIME_EXCEEDED = 0x3;
static const ShortInt ICMP6_PARAM_PROB = 0x4;
static const Byte ICMP6_INFOMSG_MASK = 0x80;
static const Byte ICMP6_ECHO_REQUEST = 0x80;
static const Byte ICMP6_ECHO_REPLY = 0x81;
static const Byte ICMP6_MEMBERSHIP_QUERY = 0x82;
static const Byte ICMP6_MEMBERSHIP_REPORT = 0x83;
static const Byte ICMP6_MEMBERSHIP_REDUCTION = 0x84;
static const ShortInt ICMP6_DST_UNREACH_NOROUTE = 0x0;
static const ShortInt ICMP6_DST_UNREACH_ADMIN = 0x1;
static const ShortInt ICMP6_DST_UNREACH_NOTNEIGHBOR = 0x2;
static const ShortInt ICMP6_DST_UNREACH_ADDR = 0x3;
static const ShortInt ICMP6_DST_UNREACH_NOPORT = 0x4;
static const ShortInt ICMP6_DST_UNREACH_SOURCE_FILTERING = 0x5;
static const ShortInt ICMP6_DST_UNREACH_REJCT_DST = 0x6;
static const ShortInt ICMP6_TIME_EXCEED_TRANSIT = 0x0;
static const ShortInt ICMP6_TIME_EXCEED_REASSEMBLY = 0x1;
static const ShortInt ICMP6_PARAMPROB_HEADER = 0x0;
static const ShortInt ICMP6_PARAMPROB_NEXTHEADER = 0x1;
static const ShortInt ICMP6_PARAMPROB_OPTION = 0x2;
static const Byte ND_ROUTER_SOLICIT = 0x85;
static const Byte ND_ROUTER_ADVERT = 0x86;
static const Byte ND_NEIGHBOR_SOLICIT = 0x87;
static const Byte ND_NEIGHBOR_ADVERT = 0x88;
static const Byte ND_REDIRECT = 0x89;
static const ShortInt Id_IGMP_MEMBERSHIP_QUERY = 0x11;
static const ShortInt Id_IGMP_V1_MEMBERSHIP_REPORT = 0x12;
static const ShortInt Id_IGMP_V2_MEMBERSHIP_REPORT = 0x16;
static const ShortInt Id_IGMP_LEAVE_GROUP = 0x17;
static const Word Id_ETHERTYPE_PUP = 0x200;
static const Word Id_ETHERTYPE_IP = 0x800;
static const Word Id_ETHERTYPE_ARP = 0x806;
static const Word Id_ETHERTYPE_REVARP = 0x8035;
static const Word Id_ETHERTYPE_VLAN = 0x8100;
static const Word Id_ETHERTYPE_LOOPBACK = 0x9000;
static const ShortInt Id_ARPHRD_ETHER = 0x1;
static const ShortInt Id_ARPOP_REQUEST = 0x1;
static const ShortInt Id_ARPOP_REPLY = 0x2;
static const ShortInt Id_ARPOP_REVREQUEST = 0x3;
static const ShortInt Id_ARPOP_REVREPLY = 0x4;
static const ShortInt Id_ARPOP_INVREQUEST = 0x8;
static const ShortInt Id_ARPOP_INVREPLY = 0x9;
static const ShortInt Id_RIPCMD_REQUEST = 0x1;
static const ShortInt Id_RIPCMD_RESPONSE = 0x2;
static const ShortInt Id_RIPCMD_TRACEON = 0x3;
static const ShortInt Id_RIPCMD_TRACEOFF = 0x4;
static const ShortInt Id_RIPCMD_POLL = 0x5;
static const ShortInt Id_RIPCMD_POLLENTRY = 0x6;
static const ShortInt Id_RIPCMD_MAX = 0x7;
static const ShortInt Id_RIPVER_0 = 0x0;
static const ShortInt Id_RIPVER_1 = 0x1;
static const ShortInt Id_RIPVER_2 = 0x2;
static const ShortInt Id_MAX_IPOPTLEN = 0x28;
static const Word Id_IP_MAXPACKET = 0xffff;
static const ShortInt Id_ETHER_ADDR_LEN = 0x6;

}	/* namespace Idrawheaders */
using namespace Idrawheaders;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdrawheadersHPP
