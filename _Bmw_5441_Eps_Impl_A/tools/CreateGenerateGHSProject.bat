ECHO #!gbuild > generate.gpj
ECHO [Subproject] >> generate.gpj
for %%F in (../generate/*.c) do ECHO ..\generate\%%F >> generate.gpj

REM Added per Dio integration manaual
for %%F in (../generate/Dio/src/*.c) do (
ECHO ..\generate\Dio\src\%%F >> generate.gpj
ECHO # MCAL BUILD OPTIONS # >> generate.gpj
ECHO 	-c >> generate.gpj
ECHO 	-Osize >> generate.gpj
ECHO 	-g >> generate.gpj
ECHO 	-cpu=rh850g3m >> generate.gpj
ECHO 	-gsize >> generate.gpj
ECHO 	-prepare_dispose >> generate.gpj
ECHO 	-inline_prologue >> generate.gpj
ECHO 	-sda=all >> generate.gpj
ECHO 	-Wundef >> generate.gpj
ECHO 	-no_callt >> generate.gpj
ECHO 	-reserve_r2 >> generate.gpj
ECHO 	--short_enum >> generate.gpj
ECHO 	--prototype_errors >> generate.gpj
ECHO 	--diag_error 193 >> generate.gpj
ECHO 	-dual_debug >> generate.gpj
ECHO 	-large_sda >> generate.gpj
ECHO 	--no_commons >> generate.gpj
ECHO 	-shorten_loads >> generate.gpj
ECHO 	-shorten_moves >> generate.gpj
ECHO 	-Wshadow >> generate.gpj
ECHO 	-nofloatio >> generate.gpj
ECHO 	-ignore_callt_state_in_interrupts >> generate.gpj
ECHO 	-delete >> generate.gpj
)

REM Added per Fls integartion manaual
for %%F in (../generate/Fls/src/*.c) do (
ECHO ..\generate\Fls\src\%%F >> generate.gpj
ECHO # MCAL BUILD OPTIONS # >> generate.gpj
ECHO 	-c >> generate.gpj
ECHO 	-Osize >> generate.gpj
ECHO 	-g >> generate.gpj
ECHO 	-cpu=rh850g3m >> generate.gpj
ECHO 	-gsize >> generate.gpj
ECHO 	-prepare_dispose >> generate.gpj
ECHO 	-inline_prologue >> generate.gpj
ECHO 	-sda=all >> generate.gpj
ECHO 	-Wundef >> generate.gpj
ECHO 	-no_callt >> generate.gpj
ECHO 	-reserve_r2 >> generate.gpj
ECHO 	--short_enum >> generate.gpj
ECHO 	--prototype_errors >> generate.gpj
ECHO 	--diag_error 193 >> generate.gpj
ECHO 	-dual_debug >> generate.gpj
ECHO 	-large_sda >> generate.gpj
ECHO 	--no_commons >> generate.gpj
ECHO 	-shorten_loads >> generate.gpj
ECHO 	-shorten_moves >> generate.gpj
ECHO 	-Wshadow >> generate.gpj
ECHO 	-nofloatio >> generate.gpj
ECHO 	-ignore_callt_state_in_interrupts >> generate.gpj
ECHO 	-delete >> generate.gpj
)

REM Added per Mcu integartion manaual
for %%F in (../generate/Mcu/src/*.c) do (
ECHO ..\generate\Mcu\src\%%F >> generate.gpj
ECHO # MCAL BUILD OPTIONS # >> generate.gpj
ECHO 	-c >> generate.gpj
ECHO 	-Osize >> generate.gpj
ECHO 	-g >> generate.gpj
ECHO 	-cpu=rh850g3m >> generate.gpj
ECHO 	-gsize >> generate.gpj
ECHO 	-prepare_dispose >> generate.gpj
ECHO 	-inline_prologue >> generate.gpj
ECHO 	-sda=all >> generate.gpj
ECHO 	-Wundef >> generate.gpj
ECHO 	-no_callt >> generate.gpj
ECHO 	-reserve_r2 >> generate.gpj
ECHO 	--short_enum >> generate.gpj
ECHO 	--prototype_errors >> generate.gpj
ECHO 	--diag_error 193 >> generate.gpj
ECHO 	-dual_debug >> generate.gpj
ECHO 	-large_sda >> generate.gpj
ECHO 	--no_commons >> generate.gpj
ECHO 	-shorten_loads >> generate.gpj
ECHO 	-shorten_moves >> generate.gpj
ECHO 	-Wshadow >> generate.gpj
ECHO 	-nofloatio >> generate.gpj
ECHO 	-ignore_callt_state_in_interrupts >> generate.gpj
ECHO 	-delete >> generate.gpj
)

REM Added per Port integartion manaual
for %%F in (../generate/Port/src/*.c) do (
ECHO ..\generate\Port\src\%%F >> generate.gpj
ECHO # MCAL BUILD OPTIONS # >> generate.gpj
ECHO 	-c >> generate.gpj
ECHO 	-Osize >> generate.gpj
ECHO 	-g >> generate.gpj
ECHO 	-cpu=rh850g3m >> generate.gpj
ECHO 	-gsize >> generate.gpj
ECHO 	-prepare_dispose >> generate.gpj
ECHO 	-inline_prologue >> generate.gpj
ECHO 	-sda=all >> generate.gpj
ECHO 	-Wundef >> generate.gpj
ECHO 	-no_callt >> generate.gpj
ECHO 	-reserve_r2 >> generate.gpj
ECHO 	--short_enum >> generate.gpj
ECHO 	--prototype_errors >> generate.gpj
ECHO 	--diag_error 193 >> generate.gpj
ECHO 	-dual_debug >> generate.gpj
ECHO 	-large_sda >> generate.gpj
ECHO 	--no_commons >> generate.gpj
ECHO 	-shorten_loads >> generate.gpj
ECHO 	-shorten_moves >> generate.gpj
ECHO 	-Wshadow >> generate.gpj
ECHO 	-nofloatio >> generate.gpj
ECHO 	-ignore_callt_state_in_interrupts >> generate.gpj
ECHO 	-delete >> generate.gpj
)

REM Added per Spi integartion manaual
for %%F in (../generate/Spi/src/*.c) do (
ECHO ..\generate\Spi\src\%%F >> generate.gpj
ECHO # MCAL BUILD OPTIONS # >> generate.gpj
ECHO 	-c >> generate.gpj
ECHO 	-Osize >> generate.gpj
ECHO 	-g >> generate.gpj
ECHO 	-cpu=rh850g3m >> generate.gpj
ECHO 	-gsize >> generate.gpj
ECHO 	-prepare_dispose >> generate.gpj
ECHO 	-inline_prologue >> generate.gpj
ECHO 	-sda=all >> generate.gpj
ECHO 	-Wundef >> generate.gpj
ECHO 	-no_callt >> generate.gpj
ECHO 	-reserve_r2 >> generate.gpj
ECHO 	--short_enum >> generate.gpj
ECHO 	--prototype_errors >> generate.gpj
ECHO 	--diag_error 193 >> generate.gpj
ECHO 	-dual_debug >> generate.gpj
ECHO 	-large_sda >> generate.gpj
ECHO 	--no_commons >> generate.gpj
ECHO 	-shorten_loads >> generate.gpj
ECHO 	-shorten_moves >> generate.gpj
ECHO 	-Wshadow >> generate.gpj
ECHO 	-nofloatio >> generate.gpj
ECHO 	-ignore_callt_state_in_interrupts >> generate.gpj
ECHO 	-delete >> generate.gpj
)

REM Added per Wdg integartion manaual
for %%F in (../generate/Wdg/src/*.c) do (
ECHO ..\generate\Wdg\src\%%F >> generate.gpj
ECHO # MCAL BUILD OPTIONS # >> generate.gpj
ECHO 	-c >> generate.gpj
ECHO 	-Osize >> generate.gpj
ECHO 	-g >> generate.gpj
ECHO 	-cpu=rh850g3m >> generate.gpj
ECHO 	-gsize >> generate.gpj
ECHO 	-prepare_dispose >> generate.gpj
ECHO 	-inline_prologue >> generate.gpj
ECHO 	-sda=all >> generate.gpj
ECHO 	-Wundef >> generate.gpj
ECHO 	-no_callt >> generate.gpj
ECHO 	-reserve_r2 >> generate.gpj
ECHO 	--short_enum >> generate.gpj
ECHO 	--prototype_errors >> generate.gpj
ECHO 	--diag_error 193 >> generate.gpj
ECHO 	-dual_debug >> generate.gpj
ECHO 	-large_sda >> generate.gpj
ECHO 	--no_commons >> generate.gpj
ECHO 	-shorten_loads >> generate.gpj
ECHO 	-shorten_moves >> generate.gpj
ECHO 	-Wshadow >> generate.gpj
ECHO 	-nofloatio >> generate.gpj
ECHO 	-ignore_callt_state_in_interrupts >> generate.gpj
ECHO 	-delete >> generate.gpj
)

for %%F in (../generate/*.h) do ECHO ..\generate\%%F >> generate.gpj
for %%F in (../generate/Components/*.h) do ECHO ..\generate\Components\%%F >> generate.gpj
for %%F in (../generate/Dio/include/*.h) do ECHO ..\generate\Dio\include\%%F >> generate.gpj
for %%F in (../generate/Fls/include/*.h) do ECHO ..\generate\Fls\include\%%F >> generate.gpj
for %%F in (../generate/Mcu/include/*.h) do ECHO ..\generate\Mcu\include\%%F >> generate.gpj
for %%F in (../generate/Port/include/*.h) do ECHO ..\generate\Port\include\%%F >> generate.gpj
for %%F in (../generate/Spi/include/*.h) do ECHO ..\generate\Spi\include\%%F >> generate.gpj
for %%F in (../generate/Wdg/include/*.h) do ECHO ..\generate\Wdg\include\%%F >> generate.gpj
for %%F in (../generate/*.dld) do ECHO ..\generate\%%F >> generate.gpj