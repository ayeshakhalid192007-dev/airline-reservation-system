# Airline Reservation System - User Guide for Non-Programmers

## 🎯 Quick Start Guide

This guide is for users who want to use the Airline Reservation System without any programming knowledge.

---

## 📥 How to Run the Application

### For Linux/Mac Users:

1. **Open Terminal** (search for "Terminal" in your applications)

2. **Navigate to the project folder:**
   ```
   cd /home/ayeshakhalid/OOP-PROJECT
   ```

3. **Run the application:**
   ```
   ./run.sh
   ```
   
   OR simply double-click the `run.sh` file in your file manager.

### For Windows Users:

1. **Navigate to the project folder** using File Explorer

2. **Double-click** the `run.bat` file

   OR open Command Prompt and type:
   ```
   cd C:\path\to\OOP-PROJECT
   run.bat
   ```

---

## 🖥️ Using the Application

### Main Menu

When you start the application, you'll see this menu:

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

Simply type the number of your choice and press Enter.

---

## 📖 Step-by-Step Instructions

### 1️⃣ View All Flights

**What it does:** Shows you all available flights

**How to use:**
1. Type `1` and press Enter
2. You'll see a list of all flights with:
   - Flight number (e.g., PK-301)
   - Route (e.g., Lahore → Karachi)
   - Date and time
   - Available seats

**Example:**
```
Flight Number: PK-301
Route: Lahore -> Karachi
Date: 2025-06-01
Departure: 10:00 | Arrival: 12:00
Total Seats: 50 | Available: 45
```

---

### 2️⃣ Search Flights by Route

**What it does:** Find flights between two cities

**How to use:**
1. Type `2` and press Enter
2. Enter the city you're flying FROM (e.g., Lahore)
3. Enter the city you're flying TO (e.g., Karachi)
4. The system will show all matching flights

**Example:**
```
Enter origin city: Lahore
Enter destination city: Karachi

Found 1 flight(s):
Flight PK-301: Lahore -> Karachi on 2025-06-01
```

---

### 3️⃣ Book a Seat

**What it does:** Reserve a seat on a flight

**How to use:**

**Step 1: Choose your flight**
```
Enter flight number: PK-301
```

**Step 2: Enter passenger information**
```
Enter passenger name: John Doe
Enter passenger age: 30
Enter passport ID: AB123456
Enter contact number: +1234567890
Enter email: john@example.com
```

**Step 3: Choose seat class**
```
Choose seat class (Economy/Business): Economy
```

**Step 4: Select payment method**
```
Select payment method:
1. Credit Card
2. Cash
3. Loyalty Points
Enter choice: 1
```

**Step 5: Complete payment**

**For Credit Card:**
```
Enter card number: 1234567812345678
Enter card holder name: John Doe
Enter expiry date (MM/YY): 12/25
Enter CVV: 123
```

**For Cash:**
```
Enter amount received: 200
(System will calculate change)
```

**For Loyalty Points:**
```
Enter customer ID: CUST001
(System will deduct points from your account)
```

**Step 6: Get your booking confirmation**
```
✅ Booking successful!
Your PNR: PNR001
Please save this number for future reference.
```

**💡 Important:** Write down your PNR number! You'll need it to view or cancel your booking.

---

### 4️⃣ Cancel Booking

**What it does:** Cancel an existing reservation

**How to use:**
1. Type `4` and press Enter
2. Enter your PNR number (e.g., PNR001)
3. Confirm cancellation

**Example:**
```
Enter PNR number: PNR001

Booking Details:
Passenger: John Doe
Flight: PK-301 (Lahore -> Karachi)
Seat: 5 (Economy)

✅ Booking cancelled successfully!
Your seat has been freed.
```

---

### 5️⃣ View Booking Details

**What it does:** View your ticket and booking information

**How to use:**
1. Type `5` and press Enter
2. Enter your PNR number (e.g., PNR001)
3. Your ticket will be displayed

**Example Ticket:**
```
+------------------------------------------+
|          BOARDING PASS / TICKET          |
+------------------------------------------+
|  PNR Number   : PNR001                   |
|  Passenger    : John Doe                 |
|  Flight       : PK-301                   |
|  From         : Lahore                   |
|  To           : Karachi                  |
|  Date         : 2025-06-01               |
|  Departure    : 10:00                    |
|  Arrival      : 12:00                    |
|  Seat Number  : 5                        |
|  Seat Class   : Economy                  |
|  Amount Paid  : $150.00                  |
+------------------------------------------+
|         HAVE A PLEASANT JOURNEY          |
+------------------------------------------+
```

**💡 Tip:** You can take a screenshot of this ticket for your records.

---

### 6️⃣ Display Flight Manifest

**What it does:** See all passengers on a specific flight

**How to use:**
1. Type `6` and press Enter
2. Enter the flight number (e.g., PK-301)
3. View the passenger list

**Example:**
```
========================================
  PASSENGER MANIFEST - Flight PK-301
========================================
1. John Doe | Seat: 5 (Economy) | PNR: PNR001
2. Jane Smith | Seat: 12 (Economy) | PNR: PNR002
3. Bob Johnson | Seat: 51 (Business) | PNR: PNR003
========================================
Total Passengers: 3
```

---

### 7️⃣ Test User Hierarchy

**What it does:** Demonstrates different user types (Admin vs Customer)

**How to use:**
1. Type `7` and press Enter
2. The system will show you how Admin and Customer accounts work differently
3. This is mainly for educational purposes

---

### 8️⃣ Test Payment Methods

**What it does:** Demonstrates different payment options

**How to use:**
1. Type `8` and press Enter
2. The system will show you how Credit Card, Cash, and Points payments work
3. This is mainly for educational purposes

---

### 0️⃣ Exit

**What it does:** Closes the application

**How to use:**
1. Type `0` and press Enter
2. The application will close

---

## 🎫 Sample Flights Available

The system comes with 2 pre-loaded flights:

### Flight PK-301
- **Route:** Lahore → Karachi
- **Date:** June 1, 2025
- **Departure:** 10:00 AM
- **Arrival:** 12:00 PM
- **Economy Seats:** 33 available
- **Business Seats:** 17 available

### Flight PK-502
- **Route:** Islamabad → Dubai
- **Date:** June 5, 2025
- **Departure:** 2:00 PM
- **Arrival:** 5:00 PM
- **Economy Seats:** 33 available
- **Business Seats:** 17 available

---

## 💡 Tips and Tricks

### ✅ Do's
- ✅ Write down your PNR number after booking
- ✅ Double-check passenger information before confirming
- ✅ Choose the correct seat class (Economy is cheaper, Business is more comfortable)
- ✅ Have your payment information ready before booking

### ❌ Don'ts
- ❌ Don't lose your PNR number (you need it to view/cancel bookings)
- ❌ Don't enter invalid information (the system will reject it)
- ❌ Don't try to book the same seat twice

---

## ❓ Frequently Asked Questions

### Q: What is a PNR number?
**A:** PNR stands for "Passenger Name Record". It's a unique booking reference number (like PNR001, PNR002) that identifies your reservation.

### Q: Can I change my booking after confirmation?
**A:** Currently, you need to cancel the old booking and create a new one.

### Q: What payment methods are accepted?
**A:** Credit Card, Cash, or Loyalty Points.

### Q: How do I earn loyalty points?
**A:** Points are earned automatically when you book as a Customer user type.

### Q: What's the difference between Economy and Business class?
**A:** Business class seats are more expensive but offer more comfort. Economy seats are budget-friendly.

### Q: Can I book multiple seats at once?
**A:** Currently, you need to book each seat separately.

### Q: What happens if I cancel my booking?
**A:** Your seat is freed and becomes available for other passengers.

---

## 🆘 Troubleshooting

### Problem: "Executable not found" error
**Solution:** The program needs to be compiled first. Ask a programmer to run `make` in the project directory.

### Problem: Can't find my booking
**Solution:** Make sure you're entering the correct PNR number (e.g., PNR001, not just 001).

### Problem: No seats available
**Solution:** Try a different flight or seat class. All seats might be booked.

### Problem: Payment failed
**Solution:** 
- For Credit Card: Check card number (16 digits), expiry date (MM/YY format), CVV (3-4 digits)
- For Cash: Make sure you're paying enough to cover the ticket price
- For Points: Make sure you have enough loyalty points

### Problem: Application closes immediately
**Solution:** Use the `run.sh` (Linux/Mac) or `run.bat` (Windows) launcher scripts instead of running the executable directly.

---

## 📞 Need Help?

If you encounter any issues:

1. **Check this guide** - Most common questions are answered here
2. **Try again** - Sometimes re-entering information helps
3. **Restart the application** - Close and reopen the program
4. **Ask a programmer** - If technical issues persist

---

## 🎓 Learning More

This is an educational project demonstrating Object-Oriented Programming concepts. If you're interested in learning how it works:

- Check the `README.md` file for technical details
- Look at the code in the `src/` directory
- Read the comments in the code (every line is explained!)

---

**Enjoy using the Airline Reservation System! ✈️**

---

*Last Updated: April 22, 2026*  
*Version: 1.0.0*  
*For Non-Programmers*
