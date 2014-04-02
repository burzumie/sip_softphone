TEMPLATE = app
CONFIG += qt console
QT += core gui widgets multimedia network

Debug:   TARGET = soft_phone.debug
Release: TARGET = soft_phone.release

win32 {
  DESTDIR = ../bin/win32
  LIBDIR = ../lib/win32
  BUILDDIR = ../build/win32
  PJSIP_DIR = ../lib/win32/pjsip
Debug:   PJSIP_TARGET = i386-Win32-vc10-Debug
Release: PJSIP_TARGET = i386-Win32-vc10-Release
}

SOURCEDIR = ../src
VENDORDIR = ../vendor
RESOURCEDIR = ../res

#CONFIG += debug
CONFIG += ordered

#DEFINES += QT_LARGEFILE_SUPPORT
DEFINES += DEBUG

INCLUDEPATH += $$SOURCEDIR/GeneratedFiles \
    $$SOURCEDIR/GeneratedFiles/Debug \
    $$SOURCEDIR \
    $$VENDORDIR/qt-json \
    $$PJSIP_DIR \
    $$PJSIP_DIR/pjmedia/include \
    $$PJSIP_DIR/pjsip/include \
    $$PJSIP_DIR/pjnath/include \
    $$PJSIP_DIR/pjmedia/include/pjmedia-codec \
    $$PJSIP_DIR/pjmedia/include/pjmedia-audiodev \
    $$PJSIP_DIR/pjmedia/include/pjmedia \
    $$PJSIP_DIR/pjlib-util/include \
    $$PJSIP_DIR/pjlib/include

LIBS += -L/usr/lib/ \
  -L$$LIBDIR/ \
  -L$$PJSIP_DIR/third_party/lib \
  -L$$PJSIP_DIR/pjsip/lib \
  -L$$PJSIP_DIR/pjnath/lib \
  -L$$PJSIP_DIR/pjmedia/lib \
  -L$$PJSIP_DIR/pjlib-util/lib \
  -L$$PJSIP_DIR/pjlib/lib

win32: LIBS += "-LC:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64"
  
win32: LIBS += -lIphlpapi \
    -ldsound \
    -ldxguid \
    -lnetapi32 \
    -lmswsock \
    -lws2_32 \
    -lodbc32 \
    -lodbccp32 \
    -lole32 \
    -luser32 \
    -lgdi32 \
    -ladvapi32 \
    -lpjlib-$$PJSIP_TARGET \
    -lpjlib-util-$$PJSIP_TARGET \
    -lpjmedia-$$PJSIP_TARGET \
    -lpjmedia-codec-$$PJSIP_TARGET \
    -lpjmedia-audiodev-$$PJSIP_TARGET \
    -lpjnath-$$PJSIP_TARGET \
    -lpjsua-lib-$$PJSIP_TARGET \
    -lpjsip-ua-$$PJSIP_TARGET \
    -lpjsip-simple-$$PJSIP_TARGET \
    -lpjsip-core-$$PJSIP_TARGET \
    -llibilbccodec-$$PJSIP_TARGET \
    -llibgsmcodec-$$PJSIP_TARGET \
    -llibg7221codec-$$PJSIP_TARGET \
    -llibmilenage-$$PJSIP_TARGET \
    -llibportaudio-$$PJSIP_TARGET \
    -llibresample-$$PJSIP_TARGET \
    -llibspeex-$$PJSIP_TARGET \
    -llibsrtp-$$PJSIP_TARGET

DEPENDPATH += $$SOURCEDIR
MOC_DIR += $$SOURCEDIR/GeneratedFiles/debug
OBJECTS_DIR += $$BUILDDIR
UI_DIR += $$SOURCEDIR/GeneratedFiles
RCC_DIR += $$SOURCEDIR/GeneratedFiles

HEADERS += $$SOURCEDIR/phone/api/Interface.h \
    $$SOURCEDIR/phone/api/Sip.h \
    $$SOURCEDIR/phone/Account.h \
    $$SOURCEDIR/phone/Call.h \
    $$SOURCEDIR/phone/Phone.h \
    $$SOURCEDIR/Config.h \
    $$SOURCEDIR/Gui.h \
    $$SOURCEDIR/LogHandler.h \
    $$SOURCEDIR/Sound.h \
    $$VENDORDIR/qt-json/json.h \
    $$SOURCEDIR/e.h \
    $$SOURCEDIR/gui_handler.h \
    $$SOURCEDIR/VoiceCall_Controls.h

SOURCES += $$SOURCEDIR/main.cpp \
    $$SOURCEDIR/phone/api/Sip.cpp \
    $$SOURCEDIR/phone/Account.cpp \
    $$SOURCEDIR/phone/Call.cpp \
    $$SOURCEDIR/phone/Phone.cpp \
    $$SOURCEDIR/Config.cpp \
    $$SOURCEDIR/Gui.cpp \
    $$SOURCEDIR/LogHandler.cpp \
    $$SOURCEDIR/Sound.cpp \
    $$VENDORDIR/qt-json/json.cpp \
    $$SOURCEDIR/gui_handler.cpp \
    $$SOURCEDIR/VoiceCall_Controls.cpp

FORMS += $$SOURCEDIR/VoiceCall_Controls.ui
