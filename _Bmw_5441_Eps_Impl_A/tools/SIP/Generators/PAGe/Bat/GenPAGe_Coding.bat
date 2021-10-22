setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

set PYTHONPATH=%PYTHONPATH%;%COREDIR%\..\tools

:generate
python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Cfg.h.pgen       ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Version.h.pgen   ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_ApplAdapter.c.pgen          ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_FuncAdapter.c.pgen          ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/src/%COMPONENT%Sample.c.pgen         ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/include/%COMPONENT%Sample.h.pgen     ^
    %COREDIR%/%COMPONENT%/classic.testclient/generate/src/%COMPONENT%TestClient.c.pgen ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Cfg.h.pgen              ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Function.h.pgen         ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Version.h.pgen          ^
    %COREDIR%/%COMPONENT%/generic/generate/src/%COMPONENT%_Cfg.c.pgen                  ^
    %COREDIR%/%COMPONENT%/generic/generate/src/%COMPONENT%_Function.c.pgen             ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/BUtil/classic/generate/pageinclude       ^
	-i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_ext_interfaces.arxml.pgen                      ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_interfaces.arxml.pgen                          ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_internal.arxml.pgen                            ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_ext_interfaces.arxml.pgen         ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_internal.arxml.pgen               ^
    %COREDIR%/%COMPONENT%/classic.testclient/generate/meta/%COMPONENT%TestClient_ext_interfaces.arxml.pgen ^
    %COREDIR%/%COMPONENT%/classic.testclient/generate/meta/%COMPONENT%TestClient_internal.arxml.pgen       ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd  ^
    -i %COREDIR%/BUtil/classic/generate/pageinclude       ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

xcopy %COREDIR%\%COMPONENT%\\classic.sample\meta\*.arxml %TARGETDIR%\swcd /I /Y /C

:error
exit /B %ERRORLEVEL%

:end
endlocal
