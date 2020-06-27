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
dpinst32 -U twncdc.inf
dpinst32 -U twn4ccidslot.inf
dpinst32 -U twn4ccidbus.inf
goto End

rem *******************************************************
rem ****** Install 64 Bit *********************************
rem *******************************************************

:Install64Bit
dpinst64 -U twncdc.inf
dpinst64 -U twn4ccidslot.inf
dpinst64 -U twn4ccidbus.inf
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
