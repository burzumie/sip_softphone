Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjsip-simple-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include

SOURCES += errno.c \
           evsub.c \
           evsub_msg.c \
           iscomposing.c \
           mwi.c \
           pidf.c \
           presence.c \
           presence_body.c \
           publishc.c \
           rpid.c \
           xpidf.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
