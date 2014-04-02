Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjmedia-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += ../../../pjlib/include
INCLUDEPATH += ../../../pjlib-util/include
INCLUDEPATH += ../../../third_party/speex/include
INCLUDEPATH += ../../..
INCLUDEPATH += ../../../pjnath/include
INCLUDEPATH += ../../../third_party/srtp/include
INCLUDEPATH += ../../../third_party/srtp/crypto/include
INCLUDEPATH += ../../../third_party/build/srtp

SOURCES += alaw_ulaw.c \
           alaw_ulaw_table.c \
           avi_player.c \
           bidirectional.c \
           clock_thread.c \
           codec.c \
           conf_switch.c \
           conference.c \
           converter.c \
           converter_libswscale.c \
           delaybuf.c \
           echo_common.c \
           echo_port.c \
           echo_speex.c \
           echo_suppress.c \
           endpoint.c \
           errno.c \
           event.c \
           ffmpeg_util.c \
           format.c \
           g711.c \
           jbuf.c \
           master_port.c \
           mem_capture.c \
           mem_player.c \
           null_port.c \
           plc_common.c \
           port.c \
           resample_libsamplerate.c \
           resample_port.c \
           resample_resample.c \
           resample_speex.c \
           rtcp.c \
           rtcp_xr.c \
           rtp.c \
           sdp.c \
           sdp_cmp.c \
           sdp_neg.c \
           silencedet.c \
           sound_legacy.c \
           sound_port.c \
           splitcomb.c \
           stereo_port.c \
           stream.c \
           stream_common.c \
           stream_info.c \
           tonegen.c \
           transport_adapter_sample.c \
           transport_ice.c \
           transport_loop.c \
           transport_srtp.c \
           transport_udp.c \
           types.c \
           vid_codec.c \
           vid_codec_util.c \
           vid_port.c \
           vid_stream.c \
           vid_stream_info.c \
           vid_tee.c \
           wav_player.c \
           wav_playlist.c \
           wav_writer.c \
           wave.c \
           wsola.c
