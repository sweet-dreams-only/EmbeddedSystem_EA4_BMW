setlocal

set COMPONENT=%1
set ECUCFILE=%2
set TARGETDIR=%3
set COREDIR=%4
set VALIDATE=%5

:generate
%COREDIR%TL119A_Python3\tools\python %COREDIR%TL125A_PAGe\src -vvvv -l %TARGETDIR%\%COMPONENT%_GenErrors.log --optimizedb %TARGETDIR%\.bac_page_database ^
    %COREDIR%%COMPONENT%\tools\template\CryptoClassic_Version.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Crypto_CertificateManagement.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Crypto_CertificateManagement.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Crypto_Cfg.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Crypto_JumpTable.c.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Crypto_JumpTable.h.pgen ^
    %COREDIR%%COMPONENT%\tools\template\Crypto_Version.h.pgen ^
    %COREDIR% %ECUCFILE% -o %TARGETDIR% ^
    -i %COREDIR%%COMPONENT%\tools\template\ ^
    -i %COREDIR%BUtil\tools\template\
IF %ERRORLEVEL% NEQ 0 GOTO error

:error
exit /B %ERRORLEVEL%

:end
endlocal
