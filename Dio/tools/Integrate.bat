@Echo Off
setlocal

for %%* in (../.) do set SWC=%%~n*

for /D %%G in ("..\..\*_EPS_*") do set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

echo Deleting Old Directory
rmdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC% /s /q
rmdir %INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s /q
echo Copying New Directory
mkdir %INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC%
mkdir %INTPJTDIR%\tools\SIP\BSWMD\%SWC%
xcopy ..\tools\IntegrationCopy\Configurator	%INTPJTDIR%\tools\SIP\DaVinciConfigurator\Generators\%SWC% /s

:VariantSelection
echo.
echo Please Select Micro Variant number to integrate:
echo.
echo 1 = R7F701304
echo 2 = R7F701305
echo 3 = R7F701310
echo 4 = R7F701311
echo 5 = R7F701312
echo 6 = R7F701313
echo 7 = R7F701314
echo 8 = R7F701315
echo 9 = R7F701318
echo 10 = R7F701319
echo 11 = R7F701320
echo 12 = R7F701321
echo 13 = R7F701322
echo 14 = R7F701323
echo.
set /p MicroVariant= Variant Number (1-14)?
echo.
if "%MicroVariant%" == "1" (
echo Variant selected is R7F701304
goto CopyVariantA )
if "%MicroVariant%" == "2" (
echo Variant selected is R7F701305
goto CopyVariantA )
if "%MicroVariant%" == "3" (
echo Variant selected is R7F701310
goto CopyVariantB )
if "%MicroVariant%" == "4" (
echo Variant selected is R7F701311
goto CopyVariantB )
if "%MicroVariant%" == "5" (
echo Variant selected is R7F701312
goto CopyVariantA )
if "%MicroVariant%" == "6" (
echo Variant selected is R7F701313
goto CopyVariantA )
if "%MicroVariant%" == "7" (
echo Variant selected is R7F701314
goto CopyVariantB )
if "%MicroVariant%" == "8" (
echo Variant selected is R7F701315
goto CopyVariantB )
if "%MicroVariant%" == "9" (
echo Variant selected is R7F701318
goto CopyVariantB )
if "%MicroVariant%" == "10" (
echo Variant selected is R7F701319
goto CopyVariantB )
if "%MicroVariant%" == "11" (
echo Variant selected is R7F701320
goto CopyVariantA )
if "%MicroVariant%" == "12" (
echo Variant selected is R7F701321
goto CopyVariantA )
if "%MicroVariant%" == "13" (
echo Variant selected is R7F701322
goto CopyVariantB )
if "%MicroVariant%" == "14" (
echo Variant selected is R7F701323
goto CopyVariantB )
echo Invalid Variant Selected
goto VariantSelection )

:CopyVariantA
xcopy ..\autosar\R403_DIO_P1M_04_05_12_13_20_21.arxml	%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
xcopy ..\autosar\Dio_bswmd_Rec.arxml	%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
goto end
:CopyVariantB
xcopy ..\autosar\R403_DIO_P1M_10_11_14_15_18_19_22_23.arxml	%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
xcopy ..\autosar\Dio_bswmd_Rec.arxml	%INTPJTDIR%\tools\SIP\BSWMD\%SWC% /s
:end

pause

endlocal

