Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjsua-lib-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include
INCLUDEPATH += ../../../pjmedia/include
INCLUDEPATH += ../../../pjnath/include

SOURCES += pjsua_acc.c \
           pjsua_aud.c \
           pjsua_call.c \
           pjsua_core.c \
           pjsua_dump.c \
           pjsua_im.c \
           pjsua_media.c \
           pjsua_pres.c \
           pjsua_vid.c
