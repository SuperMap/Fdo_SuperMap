@ECHO OFF

REM
REM SuperMap FDO Provider 编译批处理
REM
REM Copyright (C)  1996-2007 SuperMap GIS Technologies,Inc.
REM All Rights Reserved
REM YuJiang(Leo)
REM

SET VC8DIR=
SET VC8EXPRESSDIR=
SET SDKDIR=
SET MSVCROOTKEY=HKLM\SOFTWARE\Microsoft\VisualStudio
SET MSVC8KEY=%MSVCROOTKEY%\8.0\Setup\VC
SET MSVC8EXPRESSKEY=HKLM\SOFTWARE\Microsoft\VCExpress\8.0\Setup\VC

REM First see if we can find MSVC, then set the variable
REM NOTE: delims=<tab><space>
REM NOTE: run the initial REQ QUERY outside of the if() to set ERRORLEVEL correctly

REG QUERY "%MSVC8KEY%" /v ProductDir >NUL 2>NUL
IF "%VC8DIR%"=="" (
  IF %ERRORLEVEL% EQU 0 (
    FOR /F "tokens=2* delims=	 " %%A IN ('REG QUERY "%MSVC8KEY%" /v ProductDir') DO SET VC8DIR=%%B
  )
)

REG QUERY "%MSVC8EXPRESSKEY%" /v ProductDir >NUL 2>NUL
IF "%VC8EXPRESSDIR%"=="" (
  IF %ERRORLEVEL% EQU 0 (
    FOR /F "tokens=2* delims=	 " %%A IN ('REG QUERY "%MSVC8EXPRESSKEY%" /v ProductDir') DO SET VC8EXPRESSDIR=%%B
  )
)

REM Look for Installed SDKs:
SET SDKROOTKEY=HKLM\SOFTWARE\Microsoft\MicrosoftSDK\InstalledSDKs
SET SDK2003SP1KEY=%SDKROOTKEY%\8F9E5EF3-A9A5-491B-A889-C58EFFECE8B3
SET SDK2003SP2KEY=%SDKROOTKEY%\D2FF9F89-8AA2-4373-8A31-C838BF4DBBE1

REG QUERY "%SDK2003SP2KEY%" /v "Install Dir" >NUL 2>NUL
IF "%SDKDIR%"=="" (
  IF %ERRORLEVEL% EQU 0 (
    FOR /F "tokens=3* delims=	 " %%A IN ('REG QUERY "%SDK2003SP2KEY%" /v "Install Dir"') DO SET SDKDIR=%%B
  )
)

REG QUERY "%SDK2003SP1KEY%" /v "Install Dir" >NUL 2>NUL
if "%SDKDIR%"=="" (
  IF %ERRORLEVEL% EQU 0 (
    FOR /F "tokens=3* delims=	 " %%A IN ('REG QUERY "%SDK2003SP1KEY%" /v "Install Dir"') DO SET SDKDIR=%%B
  )
)

ECHO Visual C++ 8 directory: %VC8DIR%
ECHO Visual C++ 8 Express directory: %VC8EXPRESSDIR%
ECHO SDK directory: %SDKDIR%

IF "%VC8DIR%"=="" (
    IF "%VC8EXPRESSDIR%"=="" (
        ECHO "Microsoft Visual C++ version 8 was not found. Exiting."
        PAUSE
        EXIT /B 1
    )

    IF "%SDKDIR%"=="" (
        ECHO "Microsoft Platform SDK was not found. Exiting."
        PAUSE
        EXIT /B 1
    )

    REM Prepend MSVC paths
    CALL "%VC8EXPRESSDIR%\Bin\vcvars32.bat"

    REM Don't set SDK paths in this block, because blocks are early-evaluated.
    
) ELSE (
    REM Prepend MSVC paths
    CALL "%VC8DIR%\Bin\vcvars32.bat"
)

REM DEL SET ACTIVENAMECHECK="Microsoft Visual Studio 8"
REM DEL SET ACTIVEPATHCHECK="C:\Program Files\Microsoft Visual Studio 8\VC"
REM DEL IF NOT EXIST %ACTIVEPATHCHECK% GOTO ERROR
REM DEL CALL %ACTIVEPATHCHECK%\vcvarsall.bat

SET MSACTION=Build

IF (%1)==() GOTO START_BUILD
SET MSACTION=%1

:START_BUILD

PUSHD install
msbuild Install.sln /t:%MSACTION% /p:Configuration=release /p:Platform=Win32 /nologo /consoleloggerparameters:NoSummary
POPD

PUSHD Providers\SuperMap\SuperMapFDOConnition
msbuild SuperMapConnectionPlugin.sln /t:%MSACTION% /p:Configuration=release /p:Platform="Any CPU" /nologo /consoleloggerparameters:NoSummary
POPD

PUSHD Providers\SuperMap
msbuild SuperMap.sln /t:%MSACTION% /p:Configuration=release /p:Platform=Win32 /nologo /consoleloggerparameters:NoSummary
POPD

EXIT /B 0

REM DEL :ERROR
REM DEL ECHO 不能找到 %ACTIVEPATHCHECK%
REM DEL EXIT /B 1