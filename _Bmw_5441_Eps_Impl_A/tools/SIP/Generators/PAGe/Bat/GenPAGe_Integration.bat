setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

set PYTHONPATH=%PYTHONPATH%;%COREDIR%\..\tools

:generate
python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/include/%COMPONENT%Sample_Cfg.h.pgen      ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/include/%COMPONENT%Sample_Version.h.pgen  ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/src/%COMPONENT%Sample_code.c.pgen         ^
	%COREDIR%  %ECUCFILE%  -o %TARGETDIR%
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_ext_interfaces.arxml.pgen  ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_interfaces.arxml.pgen      ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_internal.arxml.pgen        ^
	%COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
