// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Indyprotocols130.pas' rev: 20.00

#ifndef Indyprotocols130HPP
#define Indyprotocols130HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Idasn1util.hpp>	// Pascal unit
#include <Idallauthentications.hpp>	// Pascal unit
#include <Idallftplistparsers.hpp>	// Pascal unit
#include <Idallheadercoders.hpp>	// Pascal unit
#include <Idattachment.hpp>	// Pascal unit
#include <Idattachmentfile.hpp>	// Pascal unit
#include <Idattachmentmemory.hpp>	// Pascal unit
#include <Idauthentication.hpp>	// Pascal unit
#include <Idauthenticationdigest.hpp>	// Pascal unit
#include <Idauthenticationmanager.hpp>	// Pascal unit
#include <Idauthenticationntlm.hpp>	// Pascal unit
#include <Idblockcipherintercept.hpp>	// Pascal unit
#include <Idchargenserver.hpp>	// Pascal unit
#include <Idchargenudpserver.hpp>	// Pascal unit
#include <Idcharsets.hpp>	// Pascal unit
#include <Idcoder.hpp>	// Pascal unit
#include <Idcoder00e.hpp>	// Pascal unit
#include <Idcoder3to4.hpp>	// Pascal unit
#include <Idcoderbinhex4.hpp>	// Pascal unit
#include <Idcoderheader.hpp>	// Pascal unit
#include <Idcodermime.hpp>	// Pascal unit
#include <Idcoderquotedprintable.hpp>	// Pascal unit
#include <Idcoderuue.hpp>	// Pascal unit
#include <Idcoderxxe.hpp>	// Pascal unit
#include <Idcompressionintercept.hpp>	// Pascal unit
#include <Idcompressorzlib.hpp>	// Pascal unit
#include <Idconnectthroughhttpproxy.hpp>	// Pascal unit
#include <Idcontainers.hpp>	// Pascal unit
#include <Idcookie.hpp>	// Pascal unit
#include <Idcookiemanager.hpp>	// Pascal unit
#include <Idcustomhttpserver.hpp>	// Pascal unit
#include <Iddict.hpp>	// Pascal unit
#include <Iddictcommon.hpp>	// Pascal unit
#include <Iddictserver.hpp>	// Pascal unit
#include <Iddnscommon.hpp>	// Pascal unit
#include <Iddnsresolver.hpp>	// Pascal unit
#include <Iddnsserver.hpp>	// Pascal unit
#include <Iddatetimestamp.hpp>	// Pascal unit
#include <Iddaytime.hpp>	// Pascal unit
#include <Iddaytimeserver.hpp>	// Pascal unit
#include <Iddaytimeudp.hpp>	// Pascal unit
#include <Iddaytimeudpserver.hpp>	// Pascal unit
#include <Iddiscardserver.hpp>	// Pascal unit
#include <Iddiscardudpserver.hpp>	// Pascal unit
#include <Idemailaddress.hpp>	// Pascal unit
#include <Idecho.hpp>	// Pascal unit
#include <Idechoserver.hpp>	// Pascal unit
#include <Idechoudp.hpp>	// Pascal unit
#include <Idechoudpserver.hpp>	// Pascal unit
#include <Idexplicittlsclientserverbase.hpp>	// Pascal unit
#include <Idfsp.hpp>	// Pascal unit
#include <Idftp.hpp>	// Pascal unit
#include <Idftpbasefilesystem.hpp>	// Pascal unit
#include <Idftpcommon.hpp>	// Pascal unit
#include <Idftplist.hpp>	// Pascal unit
#include <Idftplistoutput.hpp>	// Pascal unit
#include <Idftplistparseas400.hpp>	// Pascal unit
#include <Idftplistparsebase.hpp>	// Pascal unit
#include <Idftplistparsebullgcos7.hpp>	// Pascal unit
#include <Idftplistparsebullgcos8.hpp>	// Pascal unit
#include <Idftplistparsechameleonnewt.hpp>	// Pascal unit
#include <Idftplistparseciscoios.hpp>	// Pascal unit
#include <Idftplistparsedistincttcpip.hpp>	// Pascal unit
#include <Idftplistparseeplf.hpp>	// Pascal unit
#include <Idftplistparsehellsoft.hpp>	// Pascal unit
#include <Idftplistparseka9q.hpp>	// Pascal unit
#include <Idftplistparsempeix.hpp>	// Pascal unit
#include <Idftplistparsemvs.hpp>	// Pascal unit
#include <Idftplistparsemicrowareos9.hpp>	// Pascal unit
#include <Idftplistparsemusic.hpp>	// Pascal unit
#include <Idftplistparsencsafordos.hpp>	// Pascal unit
#include <Idftplistparsencsaformacos.hpp>	// Pascal unit
#include <Idftplistparsenovellnetware.hpp>	// Pascal unit
#include <Idftplistparsenovellnetwarepsu.hpp>	// Pascal unit
#include <Idftplistparseos2.hpp>	// Pascal unit
#include <Idftplistparsepcnfsd.hpp>	// Pascal unit
#include <Idftplistparsestercomos390exp.hpp>	// Pascal unit
#include <Idftplistparsestercomunixent.hpp>	// Pascal unit
#include <Idftplistparsestratusvos.hpp>	// Pascal unit
#include <Idftplistparsesupertcp.hpp>	// Pascal unit
#include <Idftplistparsetops20.hpp>	// Pascal unit
#include <Idftplistparsetsxplus.hpp>	// Pascal unit
#include <Idftplistparsetandemguardian.hpp>	// Pascal unit
#include <Idftplistparseunisysclearpath.hpp>	// Pascal unit
#include <Idftplistparseunix.hpp>	// Pascal unit
#include <Idftplistparsevm.hpp>	// Pascal unit
#include <Idftplistparsevms.hpp>	// Pascal unit
#include <Idftplistparsevse.hpp>	// Pascal unit
#include <Idftplistparsevxworks.hpp>	// Pascal unit
#include <Idftplistparsewfftp.hpp>	// Pascal unit
#include <Idftplistparsewinqvtnet.hpp>	// Pascal unit
#include <Idftplistparsewindowsnt.hpp>	// Pascal unit
#include <Idftplistparsexecommicrortos.hpp>	// Pascal unit
#include <Idftplisttypes.hpp>	// Pascal unit
#include <Idftpserver.hpp>	// Pascal unit
#include <Idftpservercontextbase.hpp>	// Pascal unit
#include <Idfinger.hpp>	// Pascal unit
#include <Idfingerserver.hpp>	// Pascal unit
#include <Idglobalprotocols.hpp>	// Pascal unit
#include <Idgopher.hpp>	// Pascal unit
#include <Idgopherconsts.hpp>	// Pascal unit
#include <Idgopherserver.hpp>	// Pascal unit
#include <Idhmac.hpp>	// Pascal unit
#include <Idhmacmd5.hpp>	// Pascal unit
#include <Idhmacsha1.hpp>	// Pascal unit
#include <Idhttp.hpp>	// Pascal unit
#include <Idhttpheaderinfo.hpp>	// Pascal unit
#include <Idhttpproxyserver.hpp>	// Pascal unit
#include <Idhttpserver.hpp>	// Pascal unit
#include <Idhash.hpp>	// Pascal unit
#include <Idhashcrc.hpp>	// Pascal unit
#include <Idhashelf.hpp>	// Pascal unit
#include <Idhashmessagedigest.hpp>	// Pascal unit
#include <Idhashsha1.hpp>	// Pascal unit
#include <Idheadercoder2022jp.hpp>	// Pascal unit
#include <Idheadercoderbase.hpp>	// Pascal unit
#include <Idheadercoderindy.hpp>	// Pascal unit
#include <Idheadercoderplain.hpp>	// Pascal unit
#include <Idheadercoderutf.hpp>	// Pascal unit
#include <Idheaderlist.hpp>	// Pascal unit
#include <Idimap4.hpp>	// Pascal unit
#include <Idimap4server.hpp>	// Pascal unit
#include <Idipaddrmon.hpp>	// Pascal unit
#include <Idipwatch.hpp>	// Pascal unit
#include <Idirc.hpp>	// Pascal unit
#include <Idident.hpp>	// Pascal unit
#include <Ididentserver.hpp>	// Pascal unit
#include <Idircserver.hpp>	// Pascal unit
#include <Idlpr.hpp>	// Pascal unit
#include <Idmailbox.hpp>	// Pascal unit
#include <Idmappedftp.hpp>	// Pascal unit
#include <Idmappedpop3.hpp>	// Pascal unit
#include <Idmappedporttcp.hpp>	// Pascal unit
#include <Idmappedportudp.hpp>	// Pascal unit
#include <Idmappedtelnet.hpp>	// Pascal unit
#include <Idmessage.hpp>	// Pascal unit
#include <Idmessagebuilder.hpp>	// Pascal unit
#include <Idmessageclient.hpp>	// Pascal unit
#include <Idmessagecoder.hpp>	// Pascal unit
#include <Idmessagecoderbinhex4.hpp>	// Pascal unit
#include <Idmessagecodermime.hpp>	// Pascal unit
#include <Idmessagecoderquotedprintable.hpp>	// Pascal unit
#include <Idmessagecoderuue.hpp>	// Pascal unit
#include <Idmessagecoderxxe.hpp>	// Pascal unit
#include <Idmessagecoderyenc.hpp>	// Pascal unit
#include <Idmessagecollection.hpp>	// Pascal unit
#include <Idmessageparts.hpp>	// Pascal unit
#include <Idmultipartformdata.hpp>	// Pascal unit
#include <Idnntp.hpp>	// Pascal unit
#include <Idnntpserver.hpp>	// Pascal unit
#include <Idntlm.hpp>	// Pascal unit
#include <Idnetworkcalculator.hpp>	// Pascal unit
#include <Idosfilename.hpp>	// Pascal unit
#include <Idotpcalculator.hpp>	// Pascal unit
#include <Idpop3.hpp>	// Pascal unit
#include <Idpop3server.hpp>	// Pascal unit
#include <Idqotdudp.hpp>	// Pascal unit
#include <Idqotdudpserver.hpp>	// Pascal unit
#include <Idqotd.hpp>	// Pascal unit
#include <Idqotdserver.hpp>	// Pascal unit
#include <Idrsh.hpp>	// Pascal unit
#include <Idrshserver.hpp>	// Pascal unit
#include <Idremotecmdclient.hpp>	// Pascal unit
#include <Idremotecmdserver.hpp>	// Pascal unit
#include <Idreplyftp.hpp>	// Pascal unit
#include <Idreplyimap4.hpp>	// Pascal unit
#include <Idreplypop3.hpp>	// Pascal unit
#include <Idreplysmtp.hpp>	// Pascal unit
#include <Idresourcestringsprotocols.hpp>	// Pascal unit
#include <Idrexec.hpp>	// Pascal unit
#include <Idrexecserver.hpp>	// Pascal unit
#include <Idsasl.hpp>	// Pascal unit
#include <Idsaslanonymous.hpp>	// Pascal unit
#include <Idsaslcollection.hpp>	// Pascal unit
#include <Idsasldigest.hpp>	// Pascal unit
#include <Idsaslexternal.hpp>	// Pascal unit
#include <Idsasllogin.hpp>	// Pascal unit
#include <Idsaslotp.hpp>	// Pascal unit
#include <Idsaslplain.hpp>	// Pascal unit
#include <Idsaslskey.hpp>	// Pascal unit
#include <Idsasluserpass.hpp>	// Pascal unit
#include <Idsasl_crambase.hpp>	// Pascal unit
#include <Idsasl_cram_md5.hpp>	// Pascal unit
#include <Idsasl_cram_sha1.hpp>	// Pascal unit
#include <Idsmtp.hpp>	// Pascal unit
#include <Idsmtpbase.hpp>	// Pascal unit
#include <Idsmtprelay.hpp>	// Pascal unit
#include <Idsmtpserver.hpp>	// Pascal unit
#include <Idsnmp.hpp>	// Pascal unit
#include <Idsnpp.hpp>	// Pascal unit
#include <Idsntp.hpp>	// Pascal unit
#include <Idssl.hpp>	// Pascal unit
#include <Idsslopenssl.hpp>	// Pascal unit
#include <Idsslopensslheaders.hpp>	// Pascal unit
#include <Idserverinterceptlogbase.hpp>	// Pascal unit
#include <Idserverinterceptlogevent.hpp>	// Pascal unit
#include <Idserverinterceptlogfile.hpp>	// Pascal unit
#include <Idsocksserver.hpp>	// Pascal unit
#include <Idstrings.hpp>	// Pascal unit
#include <Idsyslog.hpp>	// Pascal unit
#include <Idsyslogmessage.hpp>	// Pascal unit
#include <Idsyslogserver.hpp>	// Pascal unit
#include <Idsystat.hpp>	// Pascal unit
#include <Idsystatserver.hpp>	// Pascal unit
#include <Idsystatudp.hpp>	// Pascal unit
#include <Idsystatudpserver.hpp>	// Pascal unit
#include <Idtelnet.hpp>	// Pascal unit
#include <Idtelnetserver.hpp>	// Pascal unit
#include <Idtext.hpp>	// Pascal unit
#include <Idtime.hpp>	// Pascal unit
#include <Idtimeserver.hpp>	// Pascal unit
#include <Idtimeudp.hpp>	// Pascal unit
#include <Idtimeudpserver.hpp>	// Pascal unit
#include <Idtrivialftp.hpp>	// Pascal unit
#include <Idtrivialftpbase.hpp>	// Pascal unit
#include <Idtrivialftpserver.hpp>	// Pascal unit
#include <Iduri.hpp>	// Pascal unit
#include <Idunixtime.hpp>	// Pascal unit
#include <Idunixtimeserver.hpp>	// Pascal unit
#include <Idunixtimeudp.hpp>	// Pascal unit
#include <Idunixtimeudpserver.hpp>	// Pascal unit
#include <Iduseraccounts.hpp>	// Pascal unit
#include <Iduserpassprovider.hpp>	// Pascal unit
#include <Idvcard.hpp>	// Pascal unit
#include <Idwebdav.hpp>	// Pascal unit
#include <Idwhoisserver.hpp>	// Pascal unit
#include <Idwhois.hpp>	// Pascal unit
#include <Idzlib.hpp>	// Pascal unit
#include <Idzlibcompressorbase.hpp>	// Pascal unit
#include <Idzlibconst.hpp>	// Pascal unit
#include <Idzlibheaders.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Varutils.hpp>	// Pascal unit
#include <Typinfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Syncobjs.hpp>	// Pascal unit
#include <Idglobal.hpp>	// Pascal unit
#include <Inifiles.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <Idwinsock2.hpp>	// Pascal unit
#include <Idwship6.hpp>	// Pascal unit
#include <Idstackwindows.hpp>	// Pascal unit
#include <Idstack.hpp>	// Pascal unit
#include <Idcomponent.hpp>	// Pascal unit
#include <Idiohandler.hpp>	// Pascal unit
#include <Idiohandlerstack.hpp>	// Pascal unit
#include <Idthread.hpp>	// Pascal unit
#include <Ansistrings.hpp>	// Pascal unit
#include <Idlogbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Indyprotocols130
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------

}	/* namespace Indyprotocols130 */
using namespace Indyprotocols130;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Indyprotocols130HPP
