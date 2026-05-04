# Fixes Applied to Airline Reservation System

## Date: May 4, 2026

---

## Issues Fixed

### Issue 1: Booking Not Actually Saved to Flight
**Problem:** When booking a seat, the booking was created but never added to the flight's booking array.

**Solution:** Modified `bookSeat()` function in `src/services/helpers.cpp` to:
1. Find an available seat using `flight.findAvailableSeat(seatClass)`
2. Create the booking with the assigned seat number
3. Call `flight.addBooking(newBooking)` to actually save it
4. Display the assigned seat number and PNR to the user

### Issue 2: View Booking Details Not Working
**Problem:** The function just displayed a note instead of actually searching for the booking.

**Solution:** Modified `viewBookingDetails()` function to:
1. Search through the flight's bookings array
2. Match the PNR number
3. Display a formatted ticket with all booking details
4. Show error if booking not found

### Issue 3: Cancel Booking Not Working
**Problem:** The function just displayed a note instead of actually canceling.

**Solution:** Modified `cancelBooking()` function to:
1. Call `flight.cancelBooking(pnr)` method
2. Mark the seat as available again
3. Update booking status to "Cancelled"
4. Display success or error message

### Issue 4: Display Flight Manifest Not Working
**Problem:** The function just displayed a note instead of showing passengers.

**Solution:** Modified `displayFlightManifest()` function to:
1. Call `flight.displayManifest()` method
2. Display all active bookings with passenger details

---

## Code Changes Made

### 1. src/domain/Airline.h
Added friend function declarations to allow helper functions to access private `flights` array:
```cpp
friend void bookSeat(Airline& airline);
friend void cancelBooking(Airline& airline);
friend void viewBookingDetails(Airline& airline);
friend void displayFlightManifest(Airline& airline);
```

### 2. src/domain/Flight.h
- Added forward declaration: `class Airline;`
- Added friend function declaration: `friend void viewBookingDetails(Airline& airline);`

### 3. src/services/helpers.cpp
Complete rewrite of four functions:
- `bookSeat()` - Now actually adds booking to flight
- `cancelBooking()` - Now actually cancels and frees seat
- `viewBookingDetails()` - Now searches and displays ticket
- `displayFlightManifest()` - Now displays passenger list

---

## How to Use the System

### Available Flight Numbers
The system loads two sample flights on startup:
- **PK-301**: Lahore → Karachi (7 seats: 5 Economy, 2 Business)
- **PK-502**: Islamabad → Dubai (6 seats: 4 Economy, 2 Business)

### Booking a Seat - Step by Step

1. **Select Option 3** from main menu
2. **Enter flight number**: Type `PK-301` or `PK-502`
3. **Enter passenger details**:
   - Name: e.g., `John Doe`
   - Age: e.g., `30`
   - ID: e.g., `12345-6789012-3`
4. **Enter seat class**: Type `economy` or `business` (lowercase)
5. **Select payment method**:
   - Option 1: Credit Card (requires card details)
   - Option 2: Cash (automatic calculation)
   - Option 3: Loyalty Points (requires membership ID)
6. **Save your PNR number** displayed after successful booking

### Viewing Booking Details

1. **Select Option 5** from main menu
2. **Enter PNR number**: e.g., `PNR-001`
3. **Enter flight number**: e.g., `PK-301`
4. System displays formatted ticket with all details

### Canceling a Booking

1. **Select Option 4** from main menu
2. **Enter PNR number**: e.g., `PNR-001`
3. **Enter flight number**: e.g., `PK-301`
4. System cancels booking and releases the seat

### Viewing Passenger Manifest

1. **Select Option 6** from main menu
2. **Enter flight number**: e.g., `PK-301`
3. System displays all passengers on that flight

---

## Compilation Instructions

### Linux
```bash
cd /home/ayeshakhalid/OOP-PROJECT

g++ -std=c++11 src/main.cpp src/domain/Seat.cpp src/domain/Passenger.cpp \
    src/domain/Booking.cpp src/domain/Flight.cpp src/domain/Airline.cpp \
    src/domain/User.cpp src/domain/Admin.cpp src/domain/Customer.cpp \
    src/domain/Payment.cpp src/domain/CreditCardPayment.cpp \
    src/domain/CashPayment.cpp src/domain/PointsPayment.cpp \
    -o airline -I src/domain
```

Or simply run:
```bash
./compile.sh
```

### Windows (Cross-compile from Linux)
```bash
x86_64-w64-mingw32-g++ -std=c++11 src/main.cpp src/domain/Seat.cpp \
    src/domain/Passenger.cpp src/domain/Booking.cpp src/domain/Flight.cpp \
    src/domain/Airline.cpp src/domain/User.cpp src/domain/Admin.cpp \
    src/domain/Customer.cpp src/domain/Payment.cpp \
    src/domain/CreditCardPayment.cpp src/domain/CashPayment.cpp \
    src/domain/PointsPayment.cpp -o airline.exe -I src/domain \
    -static-libgcc -static-libstdc++
```

### Windows (On Windows)
```cmd
compile.bat
```

---

## Testing the Fixes

### Test Case 1: Complete Booking Flow
1. Run the program: `./airline`
2. Select option 1 to view all flights
3. Select option 3 to book a seat
4. Enter flight number: `PK-301`
5. Enter passenger details
6. Complete payment
7. Note the PNR number (e.g., `PNR-001`)
8. Select option 5 to view booking
9. Enter the PNR and flight number
10. Verify ticket displays correctly

### Test Case 2: Cancellation
1. Book a seat (follow Test Case 1)
2. Select option 4 to cancel
3. Enter PNR and flight number
4. Verify cancellation success message
5. Select option 1 to view flights
6. Verify available seats increased by 1

### Test Case 3: Passenger Manifest
1. Book 2-3 seats on the same flight
2. Select option 6 to view manifest
3. Enter flight number
4. Verify all passengers are listed

---

## Summary of Changes

**Files Modified:**
- `src/domain/Airline.h` - Added friend declarations
- `src/domain/Flight.h` - Added forward declaration and friend
- `src/services/helpers.cpp` - Rewrote 4 functions completely

**Lines Changed:** ~150 lines

**Functionality Added:**
- ✅ Actual booking storage in flight
- ✅ Seat assignment and availability tracking
- ✅ Booking retrieval by PNR
- ✅ Ticket display with formatted output
- ✅ Booking cancellation with seat release
- ✅ Passenger manifest display

**All features now work as expected!**

---

## Notes

- The system uses **friend functions** to access private data while maintaining encapsulation
- PNR numbers are auto-generated starting from `PNR-001`
- Seat numbers are assigned automatically based on availability
- Economy seats: First 2/3 of total seats
- Business seats: Last 1/3 of total seats
- All bookings are stored in memory (not persistent across program restarts)

---

**Last Updated:** May 4, 2026
**Status:** All issues resolved and tested
