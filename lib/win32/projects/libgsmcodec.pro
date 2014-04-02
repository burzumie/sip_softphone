Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libgsmcodec-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../inc

SOURCES += add.c \
           code.c \
           debug.c \
           decode.c \
           gsm_create.c \
           gsm_decode.c \
           gsm_destroy.c \
           gsm_encode.c \
           gsm_explode.c \
           gsm_implode.c \
           gsm_option.c \
           gsm_print.c \
           long_term.c \
           lpc.c \
           preprocess.c \
           rpe.c \
           short_term.c \
           table.c
