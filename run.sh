#!/bin/bash
# Airline Reservation System Launcher
# Double-click this file to run the application

# Get the directory where this script is located
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Change to project directory
cd "$DIR"

# Check if executable exists
if [ ! -f "bin/airline" ]; then
    echo "Error: Executable not found!"
    echo "Please compile the project first using: make"
    read -p "Press Enter to exit..."
    exit 1
fi

# Clear screen and run the application
clear
echo "Starting Airline Reservation System..."
echo ""
./bin/airline

# Keep terminal open after program exits
echo ""
read -p "Press Enter to exit..."
