@Echo Off
setlocal

for %%* in (../.) do set SWC=%%~n*

for /D %%G in ("..\..\*_EPS_*") do set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

echo Deleting Old Directory
rmdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC% /s /q
rmdir %INTPJTDIR%\tools\SIP\Generators\Components\_Schemes\%SWC% /s /q
rmdir %INTPJTDIR%\tools\SIP\Generators\Wdg /s /q
rmdir %INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s /q
rmdir %INTPJTDIR%\tools\SIP\Misc\Wdg /s /q

echo Copying New Directory
mkdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC%
mkdir %INTPJTDIR%\tools\SIP\Generators\Wdg
mkdir %INTPJTDIR%\tools\SIP\BSWMD\%SWC%
mkdir %INTPJTDIR%\tools\SIP\Misc\Wdg

xcopy ..\autosar								%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
xcopy ..\tools\IntegrationCopy\Configurator		%INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC% /s
xcopy ..\generate								%INTPJTDIR%\tools\SIP\Generators\Wdg /s
xcopy ..\tools\SafeWdg							%INTPJTDIR%\tools\SIP\Misc\Wdg /s

pause
endlocal

