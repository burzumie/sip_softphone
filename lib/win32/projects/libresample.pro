Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libresample-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += ../include
INCLUDEPATH += ../../build/resample

SOURCES += resamplesubs.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
