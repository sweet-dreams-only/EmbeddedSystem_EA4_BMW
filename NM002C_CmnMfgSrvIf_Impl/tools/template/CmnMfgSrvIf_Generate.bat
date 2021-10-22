@ECHO off

REM *******************************************************************************************************************
REM * Copyright 2016 Nxtr
REM * Nxtr Confidential
REM *
REM * Module File Name:   CmnMfgSrvIf_Generate.bat
REM * Module Description: Generates component configuration files.  Generated from TL109A_SwcSuprt.
REM * Project:            CBD
REM * Author:             Owen Tosh
REM *******************************************************************************************************************

SETLOCAL

REM get arguments
SET ECUC_FILE=%1
SET GENDATA_FOLDER=%2

REM set up paths
SET PYTHON_PATH=..\..\..\TL112A_Python\tools
SET ODX_FILE=%GENDATA_FOLDER%\EnadMfgSrv.odx-d
SET LOG_FILE=%GENDATA_FOLDER%\CmnMfgSrvIf_Cfg.log
SET SRC_FILE=%GENDATA_FOLDER%\CmnMfgSrvIf_Cfg.c
SET XML_FILE=%GENDATA_FOLDER%\CmnMfgSrvIf_DcmCfg.arxml
SET M_FILE=%GENDATA_FOLDER%\NM002C_CmnMfgSrvIf_DataDict.m

REM Delete existing log file
DEL %LOG_FILE%

REM clean up existing configuration files
IF EXIST "%GENDATA_FOLDER%\CmnMfgSrvIf_Cfg.c" DEL "%SRC_FILE%"

REM generate CmnMfgSrvIf_Cfg.c
SET ERRORLEVEL=
%PYTHON_PATH%\python.exe DcmSrcGen.py -v %ODX_FILE% "%SRC_FILE%" >> %LOG_FILE% 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end

REM generate CmnMfgSrvIf_DcmCfg.arxml
SET ERRORLEVEL=
%PYTHON_PATH%\python.exe DcmArxmlGen.py -v "%ODX_FILE%" "%XML_FILE%" >> %LOG_FILE% 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end

REM generate CmnMfgSrvIf_DcmCfg.arxml
SET ERRORLEVEL=
%PYTHON_PATH%\python.exe DataDictGen.py -v "%ODX_FILE%" "%M_FILE%" >> %LOG_FILE% 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end


:end
EXIT %ERRORLEVEL%
ENDLOCAL
