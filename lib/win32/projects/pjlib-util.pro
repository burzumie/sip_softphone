Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjlib-util-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Include"
#LIBS        += -lwsock32 -lws2_32 -lOle32

SOURCES += base64.c \
           cli.c \
           cli_console.c \
           cli_telnet.c \
           crc32.c \
           dns.c \
           dns_dump.c \
           dns_server.c \
           errno.c \
           getopt.c \
           hmac_md5.c \
           hmac_sha1.c \
           http_client.c \
           json.c \
           md5.c \
           pcap.c \
           resolver.c \
           scanner.c \
           scanner_cis_bitwise.c \
           scanner_cis_uint.c \
           sha1.c \
           srv_resolver.c \
           string.c \
           stun_simple.c \
           stun_simple_client.c \
#           symbols.c \
           xml.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
