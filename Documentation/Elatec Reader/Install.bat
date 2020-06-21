@echo off

rem *******************************************************
rem ****** Determine Platform *****************************
rem *******************************************************

if "%PROCESSOR_ARCHITECTURE%" == "X86" goto Install32Bit
if "%PROCESSOR_ARCHITECTURE%" == "x86" goto Install32Bit
if "%PROCESSOR_ARCHITECTURE%" == "AMD64" goto Install64Bit
goto UnknownArchitecture

rem *******************************************************
rem ****** Install 32 Bit *********************************
rem *******************************************************

:Install32Bit
cd drivers
dpinst32 /f
goto End

rem *******************************************************
rem ****** Install 64 Bit *********************************
rem *******************************************************

:Install64Bit
cd drivers
dpinst64 /f
goto End

rem *******************************************************
rem ****** Display Error **********************************
rem *******************************************************

:UnknownArchitecture
echo Unknown Architecture
echo 
pause

rem *******************************************************
rem ****** End ********************************************
rem *******************************************************

:End
