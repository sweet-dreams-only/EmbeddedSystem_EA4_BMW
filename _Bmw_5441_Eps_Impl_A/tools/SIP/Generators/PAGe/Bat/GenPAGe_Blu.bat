setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

set PYTHONPATH=%PYTHONPATH%;%COREDIR%\..\tools

:generate
python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_StateFunctions.h.pgen  ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Cfg.h.pgen      ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Version.h.pgen  ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_StateFunctions.c.pgen ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/BUtil/classic/generate/pageinclude  ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
