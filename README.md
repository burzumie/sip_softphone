sip_softphone
=============

SIP soft-phone

This project based on GreenJ open-source SIP soft-phone (http://www.greenj.org).
Also QTJson and PJSIP libraries are used.

How to build project:
1. Go to 'lib/win32' directory, and set 'PATH' variable and path to 'vcvarsall.bat' in first lines of 'build_all.bat'.
   Then run 'build_all.bat'. When build process has finished, you'll see several .lib files in current directory.
2. Goto 'build' directory, and set 'PATH' variable and path to 'vcvarsall.bat' in first lines of 'build_all.bat'.
   In 'soft_phone.pro' set path to DirectX SDK ('LIBS' variable, currently on line 48)
   Run 'build_all.bat'. After it, in 'bin/win32' directory you'll find 'soft_phone.exe'.
