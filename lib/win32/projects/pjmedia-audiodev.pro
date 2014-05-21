Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjmedia-audiodev-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include

SOURCES += audiodev.c \
           audiotest.c \
           bdimad_dev.c \
           errno.c \
           legacy_dev.c \
           null_dev.c \
           pa_dev.c \
           wmme_dev.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
