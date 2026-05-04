@echo off
REM Airline Reservation System Launcher for Windows
REM Double-click this file to run the application

title Airline Reservation System

REM Check if executable exists
if not exist "bin\airline.exe" (
    echo Error: Executable not found!
    echo Please compile the project first using: make
    echo.
    pause
    exit /b 1
)

REM Clear screen and run the application
cls
echo Starting Airline Reservation System...
echo.
bin\airline.exe

REM Keep window open after program exits
echo.
pause
