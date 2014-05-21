Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libg7221codec-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += ..
INCLUDEPATH += ../../pjlib/include
INCLUDEPATH += common/

SOURCES += common/basic_op.c \
           common/common.c \
           common/huff_tab.c \
           common/tables.c \
           decode/coef2sam.c \
           decode/dct4_s.c \
           decode/decoder.c \
           encode/dct4_a.c \
           encode/encoder.c \
           encode/sam2coef.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
