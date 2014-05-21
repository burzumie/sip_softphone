Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjnath-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include

SOURCES += errno.c \
           ice_session.c \
           ice_strans.c \
           nat_detect.c \
           stun_auth.c \
           stun_msg.c \
           stun_msg_dump.c \
           stun_session.c \
           stun_sock.c \
           stun_transaction.c \
           turn_session.c \
           turn_sock.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
