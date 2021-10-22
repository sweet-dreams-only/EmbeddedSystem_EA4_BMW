@ECHO OFF

REM Set up script variables
SET PROJECT_DIR=%~dp1
SET CFG_DIR=%PROJECT_DIR%SweCfg
SET SWEGEN_DIR=%PROJECT_DIR%..\..\BmwBacSuprt\tools
SET OUTPUT_DIR=%PROJECT_DIR%..\output
SET OUTPUT_FILENAME=%~n2

ECHO ---------------------------------------------------------------
ECHO Building SWEs...
ECHO.

REM Copy rec as a srec. SWEgen fails if the extension is not correct. 
ECHO Creating %OUTPUT_FILENAME%.srec in %OUTPUT_DIR%
ECHO.
COPY /Y %OUTPUT_DIR%\%OUTPUT_FILENAME%.rec %OUTPUT_DIR%\%OUTPUT_FILENAME%.srec

ECHO Process Configuration Files
FOR %%F IN (%CFG_DIR%\*.cfg) DO (
    ECHO File: %%~nxF
    REM Process each SWE. 
    %SWEGEN_DIR%\SWE-Generator.exe -gui off -mode swegen -config %%F -outputpath %OUTPUT_DIR% -log %%~nF.log -par %OUTPUT_DIR%\%OUTPUT_FILENAME%.srec
    ECHO.
)

FOR %%F IN (%OUTPUT_DIR%\*.msr) DO (
    REM Convert msr to bsw
    %SWEGEN_DIR%\SWE-Generator.exe -mode compress -compressmode compressconvert -compressinput %OUTPUT_DIR%\%%~nxF -compressoutput %OUTPUT_DIR%\%%~nxF -efficiency 50 -log %OUTPUT_DIR%\%%~nxF.log -gui off -forcecompression off
    ECHO.
)

ECHO                                                            _   
ECHO Finished Building SWEs                                  __(.)^>
ECHO --------------------------------------------------------\___)--
