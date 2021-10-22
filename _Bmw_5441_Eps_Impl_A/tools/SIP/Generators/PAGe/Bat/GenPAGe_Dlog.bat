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
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_CfgCommon.h.pgen        ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_HweTable.h.pgen         ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_Nvm.h.pgen              ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_PBCfg.h.pgen            ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_SweTable.h.pgen         ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%_UDSAdapterAdd.h.pgen    ^
    %COREDIR%/%COMPONENT%/classic/generate/include/%COMPONENT%Classic_Version.h.pgen   ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_HweTable.c.pgen             ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_Nvm.c.pgen                  ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_PBCfg.c.pgen                ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_SweTable.c.pgen             ^
    %COREDIR%/%COMPONENT%/classic/generate/src/%COMPONENT%_UDSAdapter.c.pgen           ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/include/%COMPONENT%Sample_Cfg.h.pgen ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Cfg.h.pgen              ^
    %COREDIR%/%COMPONENT%/generic/generate/include/%COMPONENT%_Version.h.pgen          ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR% ^
    -i %COREDIR%/BUtil/classic/generate/pageinclude       ^
    -i %COREDIR%/%COMPONENT%/generic/generate/pageinclude ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_ext_interfaces.arxml.pgen ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_interfaces.arxml.pgen     ^
    %COREDIR%/%COMPONENT%/classic/generate/meta/%COMPONENT%_internal.arxml.pgen       ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd ^
    -i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

python -m page -vvv --optimizedb %TARGETDIR%/.page_database ^
    %COREDIR%/%COMPONENT%/classic.sample/generate/meta/%COMPONENT%Sample_internal.arxml.pgen ^
    %COREDIR%  %ECUCFILE%  -o %TARGETDIR%\swcd ^
	-i %COREDIR%/%COMPONENT%/classic/generate/pageinclude
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
