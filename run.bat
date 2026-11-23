@echo off
cd /d "%~dp0"

echo Compiling Online Shopping System...

g++ main.cpp product.cpp cart.cpp order.cpp -o main

if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b
)

echo.
echo Compilation successful!
echo Starting program...
echo.

main.exe

pause
