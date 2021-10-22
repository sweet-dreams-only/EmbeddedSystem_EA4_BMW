setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set VALIDATE=%4

if [%VALIDATE%]==[] goto generate

:validation
del %TARGETDIR%\%COMPONENT%.autoverify
..\..\TL105A_Artt\tools\artt.exe -d=%ECUCFILE% -t=.\verify\%COMPONENT%.autoverify.tt           -i=..\..\..\TL105A_Artt\tools\include -u="http://autosar.org/schema/r4.0" -o=%TARGETDIR% >>%TARGETDIR%\%COMPONENT%_GenErrors.log 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO error

goto end

:generate
..\..\TL105A_Artt\tools\artt.exe -d=%ECUCFILE% -t=.\include\%COMPONENT%_Cfg.h.tt            -i=..\..\..\TL105A_Artt\tools\include -u="http://autosar.org/schema/r4.0" -o=%TARGETDIR% >>%TARGETDIR%\%COMPONENT%_GenErrors.log 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO error
..\..\TL105A_Artt\tools\artt.exe -d=%ECUCFILE% -t=.\include\%COMPONENT%_Version.h.tt        -i=..\..\..\TL105A_Artt\tools\include -u="http://autosar.org/schema/r4.0" -o=%TARGETDIR% >>%TARGETDIR%\%COMPONENT%_GenErrors.log 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO error
goto end

:error
exit /B %ERRORLEVEL%

:end
endlocal
