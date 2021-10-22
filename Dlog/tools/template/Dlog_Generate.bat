setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

:generate
%COREDIR%TL119A_Python3\tools\python %COREDIR%TL125A_PAGe\src -vvvv -l %TARGETDIR%\%COMPONENT%_GenErrors.log --optimizedb %TARGETDIR%\.bac_page_database ^
    %COREDIR%%COMPONENT%\tools\template\include\DlogClassic_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\DlogClassic_Version.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_CfgCommon.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_ext_interfaces.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\pageinclude\Dlog_Help.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_HweTable.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_HweTable.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_interfaces.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_internal.arxml.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_Nvm.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_Nvm.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_PBCfg.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_PBCfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_SweTable.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_SweTable.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_UDSAdapter.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_UDSAdapterAdd.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Dlog_Version.h.pgen ^
    %COREDIR% %ECUCFILE% -o %TARGETDIR% ^
    -i %COREDIR%%COMPONENT%\tools\template\ ^
    -i %COREDIR%BUtil\tools\template\
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
