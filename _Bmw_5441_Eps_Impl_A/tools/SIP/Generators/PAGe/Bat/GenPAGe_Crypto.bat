setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

set PYTHONPATH=%PYTHONPATH%;%COREDIR%\..\tools

:generate
python -m page -vvv --optimizedb %TARGETDIR%/.page_database  ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_CertificateManagement.h.pgen ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_JumpTable.h.pgen             ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Version.h.pgen        ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_CertificateManagement.c.pgen     ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_JumpTable.c.pgen                 ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Cfg.h.pgen                   ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Version.h.pgen               ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/BUtil/classic/generate/pageinclude ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
