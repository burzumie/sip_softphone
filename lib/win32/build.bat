@echo off

set PATH=%PATH%;C:\Qt\5.2.0\5.2.0\msvc2010\bin
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" > NUL

set PROJECTS=
set PROJECTS=%PROJECTS% pjsip/pjlib/src/pj/pjlib.pro
set PROJECTS=%PROJECTS% pjsip/pjlib-util/src/pjlib-util/pjlib-util.pro
set PROJECTS=%PROJECTS% pjsip/pjmedia/src/pjmedia/pjmedia.pro
set PROJECTS=%PROJECTS% pjsip/pjmedia/src/pjmedia-audiodev/pjmedia-audiodev.pro
set PROJECTS=%PROJECTS% pjsip/pjmedia/src/pjmedia-codec/pjmedia-codec.pro
set PROJECTS=%PROJECTS% pjsip/pjnath/src/pjnath/pjnath.pro
set PROJECTS=%PROJECTS% pjsip/pjsip/src/pjsip/pjsip-core.pro
set PROJECTS=%PROJECTS% pjsip/pjsip/src/pjsip-simple/pjsip-simple.pro
set PROJECTS=%PROJECTS% pjsip/pjsip/src/pjsip-ua/pjsip-ua.pro
set PROJECTS=%PROJECTS% pjsip/pjsip/src/pjsua-lib/pjsua-lib.pro
set PROJECTS=%PROJECTS% pjsip/pjsip-apps/src/pjsua/pjsua.pro
set PROJECTS=%PROJECTS% pjsip/third_party/g7221/libg7221codec.pro
set PROJECTS=%PROJECTS% pjsip/third_party/gsm/src/libgsmcodec.pro
set PROJECTS=%PROJECTS% pjsip/third_party/ilbc/libilbccodec.pro
set PROJECTS=%PROJECTS% pjsip/third_party/milenage/libmilenage.pro
set PROJECTS=%PROJECTS% pjsip/third_party/portaudio/src/libportaudio.pro
set PROJECTS=%PROJECTS% pjsip/third_party/resample/src/libresample.pro
set PROJECTS=%PROJECTS% pjsip/third_party/speex/libspeex.pro
set PROJECTS=%PROJECTS% pjsip/third_party/srtp/libsrtp.pro

GOTO MAIN


:MAKE
set FN=%1%2
set DD=%3
copy projects\%FN% %DD% > NUL
pushd %DD%
qmake -makefile
nmake /S debug
nmake /S release
popd
copy %DD%\debug\%1*.lib . > NUL
copy %DD%\release\%1*.lib . > NUL
GOTO :EOF

:BUILD
echo Building %1
for /F %%i in ("%1") do @CALL :MAKE %%~ni %%~xi %%~di%%~pi
GOTO :EOF


:MAIN
pushd pjsip\pjlib\include\pj
copy config_site_sample.h config_site.h > NUL
popd
for %%P in (%PROJECTS%) DO @CALL :BUILD "%%P"
