@echo off

for /D %%G in ("..\..\*_EPS_*") do set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

..\..\TL112A_Python\tools\python.exe OdxTest.py %INTPJTDIR%\generate\EnadMfgSrv.odx-d %INTPJTDIR%\autosar\Config\ECUC\EPS_NxtrSwIds_ecuc.arxml OdxTestReport.html --show