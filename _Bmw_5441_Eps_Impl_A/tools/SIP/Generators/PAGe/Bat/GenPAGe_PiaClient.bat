setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

set PYTHONPATH=%PYTHONPATH%;%COREDIR%\..\tools

:generate
python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Cfg.h.pgen  ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Cfg.h.pgen ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Version.h.pgen ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error


python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_ApplicationAdapter.c.pgen  ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR%   ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%Classic_ext_interfaces.arxml.pgen       ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%Classic_interfaces.arxml.pgen           ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%Classic_internal.arxml.pgen             ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_internal.arxml.pgen       ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_ext_interfaces.arxml.pgen ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd  ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error


:error
exit /B %ERRORLEVEL%

:end
endlocal
