@echo off

:: Check if gcc is installed
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo gcc not found, installing via Chocolatey...
    powershell -Command "Set-ExecutionPolicy Bypass -Scope Process; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
    choco install mingw -y
)

:: Compile the C program
gcc -o PopupWindowsAPI.exe PopupWindowsAPI.c -mwindows

:: Notify the user
if exist PopupWindowsAPI.exe (
    echo Compilation successful. PopupWindowsAPI.exe created.
) else (
    echo Compilation failed.
)

pause
