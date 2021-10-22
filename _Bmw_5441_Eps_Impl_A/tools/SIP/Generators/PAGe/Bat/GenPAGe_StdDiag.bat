setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set INTERNALBEHAVIORDIR=%5
set VALIDATE=%6

set PYTHONPATH=%PYTHONPATH%;%COREDIR%\..\tools

:generate
python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Cfg.h.pgen     ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_PBCfg.h.pgen   ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Version.h.pgen ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%Classic_Cfg.c.pgen         ^
	%COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%Classic_PBCfg.c.pgen       ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Cfg.h.pgen            ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Version.h.pgen        ^
    %COREDIR%/%COMPONENT%/generic/generate/src/%COMPONENT%_Cfg.c.pgen                ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_ext_interfaces.arxml.pgen   %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_interfaces.arxml.pgen  %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_internal.arxml.pgen   %COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd  -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_bswmd.arxml.pgen           ^
    %COREDIR%  %ECUCFILE%  -o %INTERNALBEHAVIORDIR% ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
