Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libilbccodec-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .

SOURCES += anaFilter.c \
           constants.c \
           createCB.c \
           doCPLC.c \
           enhancer.c \
           filter.c \
           FrameClassify.c \
           gainquant.c \
           getCBvec.c \
           helpfun.c \
           hpInput.c \
           hpOutput.c \
           iCBConstruct.c \
           iCBSearch.c \
           iLBC_decode.c \
           iLBC_encode.c \
           LPCdecode.c \
           LPCencode.c \
           lsf.c \
           packing.c \
           StateConstructW.c \
           StateSearchW.c \
           syntFilter.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
