# Quick Reference Guide - Airline Reservation System

## Flight Numbers Available
- **PK-301** - Lahore to Karachi
- **PK-502** - Islamabad to Dubai

## How to Enter Flight Numbers
When the system asks for a flight number, type exactly:
```
PK-301
```
or
```
PK-502
```

**Important:** Type the flight number exactly as shown (with the dash).

---

## Complete Booking Example

### Step-by-Step Booking Process

1. **Start the program**
   ```bash
   ./airline
   ```

2. **Select option 3** (Book a Seat)
   ```
   Enter your choice: 3
   ```

3. **Enter flight number**
   ```
   Enter flight number: PK-301
   ```

4. **Enter passenger details**
   ```
   Enter passenger name: John Smith
   Enter passenger age: 30
   Enter passenger ID: 12345-6789012-3
   Enter seat class (economy/business): economy
   ```

5. **Select payment method**
   ```
   Select payment method:
   1. Credit Card
   2. Cash
   3. Loyalty Points
   Enter choice: 2
   ```

6. **Save your PNR**
   ```
   Booking created successfully!
   PNR Number: PNR-001
   Seat Number: 3
   Seat Class: economy
   Amount Paid: Rs. 5000
   Please save this PNR for future reference.
   ```

---

## View Your Ticket

1. **Select option 5** (View Booking Details)
   ```
   Enter your choice: 5
   ```

2. **Enter your PNR**
   ```
   Enter PNR number: PNR-001
   ```

3. **Enter flight number**
   ```
   Enter flight number: PK-301
   ```

4. **Your ticket will display**
   ```
   +------------------------------------------+
   |          BOARDING PASS / TICKET          |
   +------------------------------------------+
   |  PNR Number   : PNR-001                  |
   |  Passenger    : John Smith               |
   |  Flight       : PK-301                   |
   |  From         : Lahore                   |
   |  To           : Karachi                  |
   |  Date         : 2025-06-01               |
   |  Seat Number  : 3                        |
   |  Seat Class   : economy                  |
   |  Amount Paid  : Rs. 5000                 |
   +------------------------------------------+
   |         HAVE A PLEASANT JOURNEY          |
   +------------------------------------------+
   ```

---

## Cancel a Booking

1. **Select option 4** (Cancel Booking)
   ```
   Enter your choice: 4
   ```

2. **Enter PNR and flight number**
   ```
   Enter PNR number: PNR-001
   Enter flight number: PK-301
   ```

3. **Confirmation**
   ```
   Booking cancelled successfully!
   PNR: PNR-001
   Seat has been released and is now available.
   ```

---

## Common Issues and Solutions

### Issue: "Flight not found"
**Solution:** Make sure you type the flight number exactly:
- Correct: `PK-301`
- Wrong: `pk-301`, `PK301`, `pk 301`

### Issue: "Invalid seat class"
**Solution:** Type seat class in lowercase:
- Correct: `economy` or `business`
- Wrong: `Economy`, `ECONOMY`, `Business`

### Issue: "Booking not found"
**Solution:** 
- Make sure you saved the PNR number when booking
- Enter both PNR and flight number correctly
- Check if the booking was cancelled

### Issue: "No available seats"
**Solution:**
- Try the other flight (PK-502 instead of PK-301)
- Try different seat class (business instead of economy)
- Cancel some bookings to free up seats

---

## Seat Pricing

| Class    | Price      |
|----------|------------|
| Economy  | Rs. 5,000  |
| Business | Rs. 12,000 |

---

## Payment Methods

### 1. Credit Card
You'll need to enter:
- Card number (e.g., 1234-5678-9012-3456)
- Card holder name
- Expiry date (MM/YY format)
- CVV (3 digits)

### 2. Cash
- System automatically calculates change
- No additional details needed

### 3. Loyalty Points
You'll need to enter:
- Membership ID
- Number of points to use
- Conversion rate: 100 points = Rs. 1

---

## Compilation Commands

### Recompile after changes (Linux)
```bash
cd /home/ayeshakhalid/OOP-PROJECT
./compile.sh
```

### Recompile for Windows
```bash
x86_64-w64-mingw32-g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline.exe -I src/domain -static-libgcc -static-libstdc++
```

### Run the program
```bash
./airline
```

---

## All Menu Options

```
==========================================
      AIRLINE RESERVATION SYSTEM
==========================================
  1. View All Flights
  2. Search Flights by Route
  3. Book a Seat
  4. Cancel Booking
  5. View Booking Details
  6. Display Flight Manifest
  7. Test User Hierarchy (Admin/Customer)
  8. Test Payment Methods
  0. Exit
==========================================
```

---

**Quick Tip:** Always save your PNR number after booking! You'll need it to view or cancel your booking.
