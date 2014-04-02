Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release

TEMPLATE  = lib
TARGET    = pjlib-$$PJSIP_TARGET

CONFIG      += staticlib
INCLUDEPATH += .
INCLUDEPATH += ../../include
INCLUDEPATH += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Include"
LIBS        += -lwsock32 -lws2_32 -lOle32

SOURCES += activesock.c \
           addr_resolv_sock.c \
           array.c \
           config.c \
           ctype.c \
           errno.c \
           except.c \
           fifobuf.c \
           file_access_win32.c \
           file_io_win32.c \
           guid.c \
           guid_win32.c \
           hash.c \
           ioqueue_select.c \
           ip_helper_win32.c \
           list.c \
           lock.c \
           log.c \
           log_writer_stdout.c \
           os_core_win32.c \
           os_error_win32.c \
           os_info.c \
           os_time_win32.c \
           os_timestamp_common.c \
           os_timestamp_win32.c \
           pool.c \
           pool_buf.c \
           pool_caching.c \
           pool_dbg.c \
           pool_policy_malloc.c \
           rand.c \
           rbtree.c \
           sock_bsd.c \
           sock_common.c \
           sock_qos_bsd.c \
           sock_qos_common.c \
           sock_qos_dummy.c \
           sock_qos_wm.c \
           sock_select.c \
           ssl_sock_common.c \
           ssl_sock_dump.c \
           ssl_sock_ossl.c \
           string.c \
           timer.c \
           types.c \
           unicode_win32.c
