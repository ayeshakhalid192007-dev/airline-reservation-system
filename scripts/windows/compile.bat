@echo off
REM Compilation script for Windows
REM Double-click this file to compile the project

echo ========================================
echo   Compiling Airline Reservation System
echo ========================================
echo.

REM Compile the project
g++ -std=c++11 src/main.cpp src/domain/Seat.cpp src/domain/Passenger.cpp src/domain/Booking.cpp src/domain/Flight.cpp src/domain/Airline.cpp src/domain/User.cpp src/domain/Admin.cpp src/domain/Customer.cpp src/domain/Payment.cpp src/domain/CreditCardPayment.cpp src/domain/CashPayment.cpp src/domain/PointsPayment.cpp -o airline.exe -I src/domain

REM Check if compilation was successful
if %errorlevel% equ 0 (
    echo.
    echo ========================================
    echo   Compilation Successful!
    echo ========================================
    echo.
    echo Executable created: airline.exe
    echo.
    echo To run the program, type: airline.exe
    echo Or double-click airline.exe
    echo.
) else (
    echo.
    echo ========================================
    echo   Compilation Failed!
    echo ========================================
    echo.
    echo Please make sure:
    echo 1. MinGW or GCC is installed
    echo 2. g++ is in your system PATH
    echo 3. All source files are present
    echo.
)

pause
