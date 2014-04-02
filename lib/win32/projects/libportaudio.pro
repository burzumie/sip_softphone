Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libportaudio-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += ../include
INCLUDEPATH += common
INCLUDEPATH += os/win

SOURCES += common/pa_allocation.c \
           common/pa_converters.c \
           common/pa_cpuload.c \
           common/pa_debugprint.c \
           common/pa_dither.c \
           common/pa_front.c \
           common/pa_process.c \
           common/pa_ringbuffer.c \
           common/pa_skeleton.c \
           common/pa_stream.c \
           common/pa_trace.c \
           hostapi/dsound/pa_win_ds.c \
           hostapi/dsound/pa_win_ds_dynlink.c \
           hostapi/wmme/pa_win_wmme.c \
#           hostapi/wasapi/pa_win_wasapi.cpp \
           os/win/pa_win_hostapis.c \
           os/win/pa_win_util.c \
           os/win/pa_win_waveformat.c \
           os/win/pa_win_wdmks_utils.c \
           os/win/pa_x86_plain_converters.c
