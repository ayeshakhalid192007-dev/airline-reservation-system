#!/bin/bash
# Compilation script for Linux/Mac
# Run this file to compile the project

echo "========================================"
echo "  Compiling Airline Reservation System"
echo "========================================"
echo ""

# Compile the project
g++ -std=c++11 src/main.cpp src/domain/Seat.cpp src/domain/Passenger.cpp src/domain/Booking.cpp src/domain/Flight.cpp src/domain/Airline.cpp src/domain/User.cpp src/domain/Admin.cpp src/domain/Customer.cpp src/domain/Payment.cpp src/domain/CreditCardPayment.cpp src/domain/CashPayment.cpp src/domain/PointsPayment.cpp -o airline -I src/domain

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo ""
    echo "========================================"
    echo "  Compilation Successful!"
    echo "========================================"
    echo ""
    echo "Executable created: airline"
    echo ""
    echo "To run the program, type: ./airline"
    echo ""
else
    echo ""
    echo "========================================"
    echo "  Compilation Failed!"
    echo "========================================"
    echo ""
    echo "Please make sure:"
    echo "1. GCC/g++ is installed"
    echo "2. All source files are present"
    echo ""
fi
