#!/bin/bash
# Git commit and push script for Airline Reservation System fixes
# Run this script to commit and push all changes to GitHub

echo "========================================"
echo "  Committing Fixes to GitHub"
echo "========================================"
echo ""

# Navigate to project directory
cd /home/ayeshakhalid/OOP-PROJECT

# Check git status
echo "Checking git status..."
git status
echo ""

# Add all modified files
echo "Adding modified files..."
git add src/domain/Airline.h
git add src/domain/Flight.h
git add src/services/helpers.cpp
git add FIXES_APPLIED.md
git add QUICK_REFERENCE.md
git add RUNNING_EXECUTABLES.md
git add airline.desktop
git add airline
git add airline.exe

echo ""
echo "Files staged for commit."
echo ""

# Create commit with detailed message
echo "Creating commit..."
git commit -m "$(cat <<'EOF'
fix: implement complete booking, cancellation, and viewing functionality

This commit fixes all major issues with the booking system:

- Fix booking not being saved to flight
  * Modified bookSeat() to call flight.addBooking()
  * Seat is now properly assigned and marked unavailable
  * Display assigned seat number and PNR to user

- Fix view booking details not working
  * Implemented actual PNR search in flight bookings
  * Display formatted ticket with all booking information
  * Show error message if booking not found

- Fix cancel booking not working
  * Call flight.cancelBooking() to actually cancel
  * Seat is released and marked available again
  * Display success/error messages appropriately

- Fix display flight manifest not working
  * Call flight.displayManifest() to show passengers
  * Display all active bookings with details

Technical changes:
- Added friend function declarations in Airline.h and Flight.h
- Added forward declaration for Airline class in Flight.h
- Rewrote 4 helper functions in helpers.cpp
- Fixed method name from getAmount() to getAmountPaid()

Documentation added:
- FIXES_APPLIED.md - Technical details of all changes
- QUICK_REFERENCE.md - User guide with examples
- RUNNING_EXECUTABLES.md - How to run on Linux/Windows

Executables updated:
- Recompiled airline (Linux 64-bit)
- Recompiled airline.exe (Windows 64-bit)
- Added airline.desktop launcher for Linux

All booking, viewing, and cancellation features now work correctly.

Co-Authored-By: Claude Sonnet 4 <noreply@anthropic.com>
EOF
)"

# Check if commit was successful
if [ $? -eq 0 ]; then
    echo ""
    echo "========================================"
    echo "  Commit Successful!"
    echo "========================================"
    echo ""
    echo "Pushing to GitHub..."

    # Push to remote repository
    git push origin master

    if [ $? -eq 0 ]; then
        echo ""
        echo "========================================"
        echo "  Push Successful!"
        echo "========================================"
        echo ""
        echo "All changes have been pushed to GitHub."
        echo ""
    else
        echo ""
        echo "========================================"
        echo "  Push Failed!"
        echo "========================================"
        echo ""
        echo "Please check your internet connection"
        echo "and GitHub credentials."
        echo ""
    fi
else
    echo ""
    echo "========================================"
    echo "  Commit Failed!"
    echo "========================================"
    echo ""
    echo "Please check the error messages above."
    echo ""
fi
