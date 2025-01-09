@echo off
setlocal

if "%OS%"=="Windows_NT" (
    call build-windows.bat
)
else (
    bash build-linux.sh
)

endlocal
