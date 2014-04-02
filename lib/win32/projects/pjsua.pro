Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjsua-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjsip/include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include
INCLUDEPATH += ../../../pjmedia/include
INCLUDEPATH += ../../../pjnath/include

SOURCES += main.c \
           pjsua_app.c \
           pjsua_app_cli.c \
           pjsua_app_common.c \
           pjsua_app_config.c \
           pjsua_app_legacy.c
