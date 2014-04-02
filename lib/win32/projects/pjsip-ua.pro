Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjsip-ua-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include
INCLUDEPATH += ../../../pjmedia/include

SOURCES += sip_100rel.c \
           sip_inv.c \
           sip_reg.c \
           sip_replaces.c \
           sip_timer.c \
           sip_xfer.c
