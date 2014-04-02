Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjmedia-codec-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../third_party/speex/include

SOURCES += amr_sdp_match.c \
           audio_codecs.c \
           ffmpeg_vid_codecs.c \
           g722.c \
           g7221.c \
           g7221_sdp_match.c \
           gsm.c \
           h263_packetizer.c \
           h264_packetizer.c \
           ilbc.c \
           l16.c \
           opencore_amr.c \
           passthrough.c \
           silk.c \
           speex_codec.c \
           g722/g722_dec.c \
           g722/g722_enc.c
