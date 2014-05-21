Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = libsrtp-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += crypto/include
INCLUDEPATH += ../build/srtp
INCLUDEPATH += ../../pjlib/include
INCLUDEPATH += include

SOURCES += pjlib/srtp_err.c \
           srtp/srtp.c \
           crypto/ae_xfm/xfm.c \
           crypto/cipher/aes.c \
           crypto/cipher/aes_cbc.c \
           crypto/cipher/aes_icm.c \
           crypto/cipher/cipher.c \
           crypto/cipher/null_cipher.c \
           crypto/hash/auth.c \
           crypto/hash/hmac.c \
           crypto/hash/null_auth.c \
           crypto/hash/sha1.c \
           crypto/kernel/alloc.c \
           crypto/kernel/crypto_kernel.c \
           crypto/kernel/key.c \
           crypto/math/datatypes.c \
           crypto/math/gf2_8.c \
           crypto/math/math.c \
           crypto/math/stat.c \
           crypto/replay/rdb.c \
           crypto/replay/rdbx.c \
           crypto/rng/ctr_prng.c \
           crypto/rng/prng.c \
           crypto/rng/rand_source.c

win32
{
# include debug info into .lib, not in .pdb
Debug: QMAKE_LFLAGS += /Z7
}
