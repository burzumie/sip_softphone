Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libmilenage-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += ../../pjlib/include

SOURCES += milenage.c \
           rijndael.c
