Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libspeex-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += include
INCLUDEPATH += win32
DEFINES     += "HAVE_CONFIG_H=1"
DEFINES     += "FIXED_POINT=1"

SOURCES += libspeex/bits.c \
           libspeex/cb_search.c \
           libspeex/exc_10_16_table.c \
           libspeex/exc_10_32_table.c \
           libspeex/exc_20_32_table.c \
           libspeex/exc_5_256_table.c \
           libspeex/exc_5_64_table.c \
           libspeex/exc_8_128_table.c \
           libspeex/fftwrap.c \
           libspeex/filterbank.c \
           libspeex/filters.c \
           libspeex/gain_table.c \
           libspeex/gain_table_lbr.c \
           libspeex/hexc_10_32_table.c \
           libspeex/hexc_table.c \
           libspeex/high_lsp_tables.c \
           libspeex/kiss_fft.c \
           libspeex/kiss_fftr.c \
           libspeex/lpc.c \
           libspeex/lsp.c \
           libspeex/lsp_tables_nb.c \
           libspeex/ltp.c \
           libspeex/mdf.c \
           libspeex/modes.c \
           libspeex/modes_wb.c \
           libspeex/nb_celp.c \
           libspeex/preprocess.c \
           libspeex/quant_lsp.c \
           libspeex/resample.c \
           libspeex/sb_celp.c \
           libspeex/smallft.c \
           libspeex/speex.c \
           libspeex/speex_callbacks.c \
           libspeex/speex_header.c \
           libspeex/stereo.c \
           libspeex/vbr.c \
           libspeex/vq.c \
           libspeex/window.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
