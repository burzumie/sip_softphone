set PATH=%PATH%;C:\Qt\5.2.0\5.2.0\msvc2010\bin
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"

qmake -makefile
rem nmake clean
nmake
nmake debug

if not exist ../bin/win32/settings.conf.sample copy ..\src\settings.conf.sample ..\bin\win32\
