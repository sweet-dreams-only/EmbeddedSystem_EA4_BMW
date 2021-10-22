@echo off

set ERRORLEVEL=
..\..\TL112A_Python\tools\python.exe ..\..\TL113A_MfgSrvSuprt\tools\OdxGen.py ProgMfgSrv ..\doc\ProgMfgSrv.odx-d ..\src local\include\MfgSrvCfg.h -v
if %ERRORLEVEL% NEQ 0 goto error

set ERRORLEVEL=
..\..\TL112A_Python\tools\python.exe ..\..\TL113A_MfgSrvSuprt\tools\OdxArxml.py ..\doc\ProgMfgSrv.odx-d ProgMfgSrv ProgMfgSrvCfg.arxml -v
if %ERRORLEVEL% NEQ 0 goto error

REM exit

:error
pause
