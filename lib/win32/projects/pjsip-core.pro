Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjsip-core-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include

SOURCES += sip_auth_aka.c \
           sip_auth_client.c \
           sip_auth_msg.c \
           sip_auth_parser.c \
           sip_auth_server.c \
           sip_config.c \
           sip_dialog.c \
           sip_endpoint.c \
           sip_errno.c \
           sip_msg.c \
           sip_multipart.c \
           sip_parser.c \
           sip_tel_uri.c \
           sip_uri.c \
           sip_util.c \
           sip_util_proxy.c \
           sip_resolve.c \
           sip_transport.c \
           sip_transport_loop.c \
           sip_transport_tcp.c \
           sip_transport_tls.c \
           sip_transport_udp.c \
           sip_transaction.c \
           sip_util_statefull.c \
           sip_ua_layer.c
