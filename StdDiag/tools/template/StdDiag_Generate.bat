setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

:generate
%COREDIR%TL119A_Python3\tools\python %COREDIR%TL125A_PAGe\src -vvvv -l %TARGETDIR%\%COMPONENT%_GenErrors.log --optimizedb %TARGETDIR%\.bac_page_database ^
    %COREDIR%%COMPONENT%\tools\template\StdDiagClassic_Cfg.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiagClassic_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiagClassic_PBCfg.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiagClassic_PBCfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiagClassic_Version.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_bswmd.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_Cfg.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_ext_interfaces.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_GetAdtConfig.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_GetIdrlConfig.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_interfaces.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_internal.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\StdDiag_Version.h.pgen ^
    %COREDIR% %ECUCFILE% -o %TARGETDIR% ^
    -i %COREDIR%%COMPONENT%\tools\template\ ^
    -i %COREDIR%BUtil\tools\template\
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
