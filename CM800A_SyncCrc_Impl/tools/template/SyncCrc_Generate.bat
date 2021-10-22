@ECHO off

REM *******************************************************************************************************************
REM * Copyright 2016 Nxtr
REM * Nxtr Confidential
REM *
REM * Module File Name:   SyncCrc_Generate.bat
REM * Module Description: Generates component configuration files.  Generated from TL109A_SwcSuprt.
REM * Project:            CBD
REM * Author:             Owen Tosh
REM *******************************************************************************************************************

SETLOCAL

REM get arguments
SET ECUC_FILE=%1
SET GENDATA_FOLDER=%2

REM set up paths
SET ARTT_TOOLS_PATH=..\..\..\TL105A_Artt\tools

REM clean up existing configuration files
IF EXIST "%GENDATA_FOLDER%\CDD_SyncCrc_Cfg_private.h" DEL "%GENDATA_FOLDER%\CDD_SyncCrc_Cfg_private.h"

REM generate CDD_SyncCrc_Cfg_private.h.tt
SET ERRORLEVEL=
%ARTT_TOOLS_PATH%\artt.exe -d="%ECUC_FILE%" -t=.\CDD_SyncCrc_Cfg_private.h.tt -i=%ARTT_TOOLS_PATH%\include -u="http://autosar.org/schema/r4.0" -o="%GENDATA_FOLDER%" >> "%GENDATA_FOLDER%\CDD_SyncCrc_Cfg_private.h.tt.log" 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end


:end
EXIT %ERRORLEVEL%
ENDLOCAL
