@ECHO Off
setlocal

REM Set project paths
set DPA_PATH=..\autosar\Eps.dpa
set SCRIPT_PATH=.\InpFileUpdSwt\InpFileUpdSwt.py
set PYTHON_PATH=..\..\TL112A_Python\tools\python.exe
set DAVINCI_PATH=..\..\TL102A_Davinci\tools\Developer\Bin\DaVinciDEV.exe

REM Prompt User
:MethodSelect
echo.
echo Please select method:
echo.
echo 1 = Import
echo 2 = Restore
echo.
set /p MethodSelection= Method Selection (1-2)?
echo.
if "%MethodSelection%" == "1" (
echo Method selected is import...applying patch.
goto import)
if "%MethodSelection%" == "2" (
echo Method selected is restore...removing patch.
goto restore)
echo Invalid Method Selected
goto MethodSelect


:import
%PYTHON_PATH% "%SCRIPT_PATH%" -p "%DPA_PATH%" -d "%DAVINCI_PATH%" -i
goto end

:restore
%PYTHON_PATH% "%SCRIPT_PATH%" -p "%DPA_PATH%" -d "%DAVINCI_PATH%" -r
goto end

:end
pause
endlocal