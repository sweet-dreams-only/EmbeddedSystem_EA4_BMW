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
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_Cfg.h.pgen            ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Version.h.pgen ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_Cfg.c.pgen                ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude  ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_bswmd.arxml.pgen ^
    %COREDIR%  %ECUCFILE%  -o %INTERNALBEHAVIORDIR% ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error
xcopy %COREDIR%\%COMPONENT%\\classic\meta\*.arxml %TARGETDIR%\swcd /I /Y /C

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/generic/generate/sm/%COMPONENT%_StateMachine.scxml  ^
    %COREDIR%/%COMPONENT%/generic/generate/sm/generateSM.sh                   ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd  ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
