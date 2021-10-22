@Echo Off
setlocal

for %%* in (../.) do set SWC=%%~n*

for /D %%G in ("..\..\*_EPS_*") do set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

echo Deleting Old Directory
rmdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC% /s /q
rmdir %INTPJTDIR%\tools\SIP\Generators\Components\_Schemes\%SWC% /s /q
rmdir %INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s /q
echo Copying New Directory
mkdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC%
mkdir %INTPJTDIR%\tools\SIP\Generators\Components\_Schemes\%SWC%\bswmd
mkdir %INTPJTDIR%\tools\SIP\BSWMD\%SWC%


:VariantSelection
echo.
echo Please Select Program Variant number to integrate:
echo.
echo 1 = Ford
echo 2 = GM
echo 3 = BMW
echo 4 = Generic
echo.
set /p ProgramVariant= Variant Number (1-3)? 
if "%ProgramVariant%" == "1" (
echo Variant selected is Ford
goto CopyVariant_Ford )
if "%ProgramVariant%" == "2" (
echo Variant selected is GM
goto CopyVariant_GM )
if "%ProgramVariant%" == "3" (
echo Variant selected is BMW
goto CopyVariant_BMW )
if "%ProgramVariant%" == "4" (
echo Variant selected is Generic
goto CopyVariant_Generic )
goto WrongVariant

:CopyVariant_Ford
xcopy ..\autosar\Ford       %INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
goto CopyCommon

:CopyVariant_BMW
xcopy ..\autosar\BMW        %INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
goto CopyCommon

:CopyVariant_GM
goto CopyCommon

:CopyVariant_Generic
xcopy ..\autosar\Generic        %INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
goto CopyCommon

:CopyCommon
xcopy ..\autosar\EcuC_bswmd.arxml					%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
xcopy ..\autosar\EcuC_preo_Rh850_GreenHills.arxml	%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
xcopy ..\tools\IntegrationCopy\Configurator			%INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC% /s
goto end

:WrongVariant
echo ATTENTION: Wrong variant selected. Existing files were deleted but no new file is copied.

:end

pause
endlocal
