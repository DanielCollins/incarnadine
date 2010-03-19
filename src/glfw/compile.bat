@echo off

REM **********************************************************************
REM * compile.bat - MS Windows compilation batch file
REM * $Date: 2007/03/15 03:20:18 $
REM * $Revision: 1.3 $
REM *
REM * This is a "helper" script for the top-level Makefile for GLFW.
REM * It was introduced to eliminate incompability issues between
REM * Windows NT, 2000 and 9x (it's easier to make a script/makefile
REM * run accross different unices from different vendors than to make
REM * a script/makefile run across different Windows versions from
REM * Microsoft!).
REM *
REM * This batch file has been tested under Windows 98, NT 4.0 and 2k.
REM *
REM * Usage 1: compile MAKEPROG SUFFIX
REM *
REM * MAKEPROG  Name of make program (e.g. make or nmake)
REM * SUFFIX    Makefile suffix for a specific compiler (e.g. msvc)
REM *
REM * Usage 2: compile CLEAN
REM **********************************************************************

REM ----------------------------------------------------------------------
REM Check input arguments
REM ----------------------------------------------------------------------

IF %1 == CLEAN GOTO Cleanup
IF %1 == "" GOTO Error1
IF "%2" == "" GOTO Error1
IF NOT EXIST .\lib\win32\Makefile.win32.%2 GOTO Error2
GOTO ArgsOK

:Error1
echo *************************************************************************
echo ***       NOTE: THIS PROGRAM IS USED BY THE TOP LEVEL MAKEFILE.       ***
echo *** PLEASE READ 'README.HTML' FOR INFORMATION ON HOW TO COMPILE GLFW! ***
echo *************************************************************************
echo Usage 1: %0 MAKEPROG SUFFIX
echo  MAKEPROG - Name of make program (e.g. make or nmake)
echo  SUFFIX   - Makefile suffix for a specific compiler (e.g. mgw or msvc)
echo Usage 2: %0 CLEAN
goto End

:Error2
echo "%2" is not a vaild Makefile suffix
goto End

:ArgsOK

REM ----------------------------------------------------------------------
REM Build GLFW library (both static and dynamic, where supported)
REM ----------------------------------------------------------------------

cd .\lib\win32
%1 -f Makefile.win32.%2


REM ----------------------------------------------------------------------
REM Return to root directory
REM ----------------------------------------------------------------------

cd ..
GOTO End



REM ----------------------------------------------------------------------
REM Clean up compiled files
REM ----------------------------------------------------------------------

:Cleanup

REM Library object files
IF EXIST .\lib\win32\enable.o             del .\lib\win32\enable.o
IF EXIST .\lib\win32\fullscreen.o         del .\lib\win32\fullscreen.o
IF EXIST .\lib\win32\glext.o              del .\lib\win32\glext.o
IF EXIST .\lib\win32\image.o              del .\lib\win32\image.o
IF EXIST .\lib\win32\init.o               del .\lib\win32\init.o
IF EXIST .\lib\win32\input.o              del .\lib\win32\input.o
IF EXIST .\lib\win32\joystick.o           del .\lib\win32\joystick.o
IF EXIST .\lib\win32\tga.o                del .\lib\win32\tga.o
IF EXIST .\lib\win32\thread.o             del .\lib\win32\thread.o
IF EXIST .\lib\win32\time.o               del .\lib\win32\time.o
IF EXIST .\lib\win32\window.o             del .\lib\win32\window.o
IF EXIST .\lib\win32\win32_enable.o       del .\lib\win32\win32_enable.o
IF EXIST .\lib\win32\win32_fullscreen.o   del .\lib\win32\win32_fullscreen.o
IF EXIST .\lib\win32\win32_glext.o        del .\lib\win32\win32_glext.o
IF EXIST .\lib\win32\win32_init.o         del .\lib\win32\win32_init.o
IF EXIST .\lib\win32\win32_joystick.o     del .\lib\win32\win32_joystick.o
IF EXIST .\lib\win32\win32_thread.o       del .\lib\win32\win32_thread.o
IF EXIST .\lib\win32\win32_time.o         del .\lib\win32\win32_time.o
IF EXIST .\lib\win32\win32_window.o       del .\lib\win32\win32_window.o

IF EXIST .\lib\win32\enable_dll.o         del .\lib\win32\enable_dll.o
IF EXIST .\lib\win32\fullscreen_dll.o     del .\lib\win32\fullscreen_dll.o
IF EXIST .\lib\win32\glext_dll.o          del .\lib\win32\glext_dll.o
IF EXIST .\lib\win32\image_dll.o          del .\lib\win32\image_dll.o
IF EXIST .\lib\win32\init_dll.o           del .\lib\win32\init_dll.o
IF EXIST .\lib\win32\input_dll.o          del .\lib\win32\input_dll.o
IF EXIST .\lib\win32\joystick_dll.o       del .\lib\win32\joystick_dll.o
IF EXIST .\lib\win32\tga_dll.o            del .\lib\win32\tga_dll.o
IF EXIST .\lib\win32\thread_dll.o         del .\lib\win32\thread_dll.o
IF EXIST .\lib\win32\time_dll.o           del .\lib\win32\time_dll.o
IF EXIST .\lib\win32\window_dll.o         del .\lib\win32\window_dll.o
IF EXIST .\lib\win32\win32_dllmain_dll.o    del .\lib\win32\win32_dllmain_dll.o
IF EXIST .\lib\win32\win32_enable_dll.o     del .\lib\win32\win32_enable_dll.o
IF EXIST .\lib\win32\win32_fullscreen_dll.o del .\lib\win32\win32_fullscreen_dll.o
IF EXIST .\lib\win32\win32_glext_dll.o      del .\lib\win32\win32_glext_dll.o
IF EXIST .\lib\win32\win32_init_dll.o       del .\lib\win32\win32_init_dll.o
IF EXIST .\lib\win32\win32_joystick_dll.o   del .\lib\win32\win32_joystick_dll.o
IF EXIST .\lib\win32\win32_thread_dll.o     del .\lib\win32\win32_thread_dll.o
IF EXIST .\lib\win32\win32_time_dll.o       del .\lib\win32\win32_time_dll.o
IF EXIST .\lib\win32\win32_window_dll.o     del .\lib\win32\win32_window_dll.o

IF EXIST .\lib\win32\enable.obj           del .\lib\win32\enable.obj
IF EXIST .\lib\win32\fullscreen.obj       del .\lib\win32\fullscreen.obj
IF EXIST .\lib\win32\glext.obj            del .\lib\win32\glext.obj
IF EXIST .\lib\win32\image.obj            del .\lib\win32\image.obj
IF EXIST .\lib\win32\init.obj             del .\lib\win32\init.obj
IF EXIST .\lib\win32\input.obj            del .\lib\win32\input.obj
IF EXIST .\lib\win32\joystick.obj         del .\lib\win32\joystick.obj
IF EXIST .\lib\win32\tga.obj              del .\lib\win32\tga.obj
IF EXIST .\lib\win32\thread.obj           del .\lib\win32\thread.obj
IF EXIST .\lib\win32\time.obj             del .\lib\win32\time.obj
IF EXIST .\lib\win32\window.obj           del .\lib\win32\window.obj
IF EXIST .\lib\win32\win32_enable.obj     del .\lib\win32\win32_enable.obj
IF EXIST .\lib\win32\win32_fullscreen.obj del .\lib\win32\win32_fullscreen.obj
IF EXIST .\lib\win32\win32_glext.obj      del .\lib\win32\win32_glext.obj
IF EXIST .\lib\win32\win32_init.obj       del .\lib\win32\win32_init.obj
IF EXIST .\lib\win32\win32_joystick.obj   del .\lib\win32\win32_joystick.obj
IF EXIST .\lib\win32\win32_thread.obj     del .\lib\win32\win32_thread.obj
IF EXIST .\lib\win32\win32_time.obj       del .\lib\win32\win32_time.obj
IF EXIST .\lib\win32\win32_window.obj     del .\lib\win32\win32_window.obj

IF EXIST .\lib\win32\enable_dll.obj       del .\lib\win32\enable_dll.obj
IF EXIST .\lib\win32\fullscreen_dll.obj   del .\lib\win32\fullscreen_dll.obj
IF EXIST .\lib\win32\glext_dll.obj        del .\lib\win32\glext_dll.obj
IF EXIST .\lib\win32\image_dll.obj        del .\lib\win32\image_dll.obj
IF EXIST .\lib\win32\init_dll.obj         del .\lib\win32\init_dll.obj
IF EXIST .\lib\win32\input_dll.obj        del .\lib\win32\input_dll.obj
IF EXIST .\lib\win32\joystick_dll.obj     del .\lib\win32\joystick_dll.obj
IF EXIST .\lib\win32\tga_dll.obj          del .\lib\win32\tga_dll.obj
IF EXIST .\lib\win32\thread_dll.obj       del .\lib\win32\thread_dll.obj
IF EXIST .\lib\win32\time_dll.obj         del .\lib\win32\time_dll.obj
IF EXIST .\lib\win32\window_dll.obj       del .\lib\win32\window_dll.obj
IF EXIST .\lib\win32\win32_dllmain_dll.obj    del .\lib\win32\win32_dllmain_dll.obj
IF EXIST .\lib\win32\win32_enable_dll.obj     del .\lib\win32\win32_enable_dll.obj
IF EXIST .\lib\win32\win32_fullscreen_dll.obj del .\lib\win32\win32_fullscreen_dll.obj
IF EXIST .\lib\win32\win32_glext_dll.obj      del .\lib\win32\win32_glext_dll.obj
IF EXIST .\lib\win32\win32_init_dll.obj       del .\lib\win32\win32_init_dll.obj
IF EXIST .\lib\win32\win32_joystick_dll.obj   del .\lib\win32\win32_joystick_dll.obj
IF EXIST .\lib\win32\win32_thread_dll.obj     del .\lib\win32\win32_thread_dll.obj
IF EXIST .\lib\win32\win32_time_dll.obj       del .\lib\win32\win32_time_dll.obj
IF EXIST .\lib\win32\win32_window_dll.obj     del .\lib\win32\win32_window_dll.obj

REM Library files
IF EXIST .\lib\win32\libglfw.a            del .\lib\win32\libglfw.a
IF EXIST .\lib\win32\libglfwdll.a         del .\lib\win32\libglfwdll.a
IF EXIST .\lib\win32\glfw.exp             del .\lib\win32\glfw.exp
IF EXIST .\lib\win32\glfwdll.exp          del .\lib\win32\glfwdll.exp
IF EXIST .\lib\win32\glfw.lib             del .\lib\win32\glfw.lib
IF EXIST .\lib\win32\glfwdll.lib          del .\lib\win32\glfwdll.lib
IF EXIST .\lib\win32\glfw.dll             del .\lib\win32\glfw.dll
IF EXIST .\lib\win32\glfw.tds             del .\lib\win32\glfw.tds
IF EXIST .\lib\win32\init.tds             del .\lib\win32\init.tds

:End
