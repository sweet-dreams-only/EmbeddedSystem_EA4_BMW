@Echo Off
setlocal

for %%* in (../.) do set SWC=%%~n*

for /D %%G in ("..\..\*_EPS_*") do set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

echo Deleting Old Directory
rmdir %INTPJTDIR%\tools\SIP\BSWMD\ChkPt /s /q
echo Copying New Directory
mkdir %INTPJTDIR%\tools\SIP\BSWMD\ChkPt
xcopy ..\tools\IntegrationCopy\InternalBehavior	%INTPJTDIR%\autosar\Config\InternalBehavior /s /y
xcopy ..\autosar\ChkPt_bswmd.arxml	%INTPJTDIR%\tools\SIP\BSWMD\ChkPt /s

:end

pause

endlocal

