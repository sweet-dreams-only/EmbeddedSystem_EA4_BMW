setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

:generate
%COREDIR%TL119A_Python3\tools\python %COREDIR%TL125A_PAGe\src -vvvv -l %TARGETDIR%\%COMPONENT%_GenErrors.log --optimizedb %TARGETDIR%\.bac_page_database ^
    %COREDIR%%COMPONENT%\tools\template\SysTimeClassic_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\SysTimeClassic_Version.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\SysTime_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\SysTime_ext_interfaces.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\SysTime_interfaces.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\SysTime_internal.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\SysTime_Version.h.pgen ^
    %COREDIR% %ECUCFILE% -o %TARGETDIR% ^
    -i %COREDIR%%COMPONENT%\tools\template\ ^
    -i %COREDIR%BUtil\tools\template\
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
