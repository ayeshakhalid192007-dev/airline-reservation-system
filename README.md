# Airline Reservation System

**A beginner-friendly C++ OOP project demonstrating core object-oriented programming concepts**

---

## Project Description

This is a terminal-based airline reservation system built in pure standard C++ to demonstrate fundamental Object-Oriented Programming (OOP) concepts. The system allows users to view flights, search by route, book seats, cancel bookings, view tickets, and see passenger manifests.

The project is designed for learning purposes with:
- **Every line of code commented** for educational clarity
- **Beginner-friendly syntax** with no complex expressions
- **Pure C++ only** - no external libraries or frameworks
- **Fixed-size arrays** instead of STL containers
- **No dynamic memory allocation** (no `new`/`delete`)

---

## How to Compile

Use the standard g++ compiler with this simple command:

```bash
g++ main.cpp -o airline
```

**Requirements:**
- g++ compiler (any standard version)
- No external libraries needed
- Works on Linux, macOS, and Windows (with MinGW)

---

## How to Run

After compiling, run the program:

```bash
./airline
```

On Windows:
```bash
airline.exe
```

---

## File Structure

The project consists of **exactly 4 files** as per the project requirements:

1. **main.cpp** - Entry point containing only the main() function and includes
2. **classes.h** - All 13 class definitions and implementations
3. **helpers.h** - All helper functions for menus and operations
4. **README.md** - This documentation file

---

## OOP Concepts Demonstrated

This project demonstrates **all major OOP concepts** required for an intermediate-level C++ course:

### 1. Classes and Objects
- **13 classes** representing real-world entities
- Objects created and used throughout the program

### 2. Encapsulation
- All data members are **private**
- Public **getter and setter methods** for controlled access
- Implementation details hidden from outside code

### 3. Constructor Overloading
- **Default constructors** (no parameters)
- **Parameterized constructors** (with initialization values)
- Every class demonstrates constructor overloading

### 4. Copy Constructor
- Implemented in `Passenger` and `Flight` classes
- Creates deep copies of objects safely

### 5. Arrays of Objects
- `Flight` contains arrays of `Seat[]` and `Booking[]`
- `Airline` contains array of `Flight[]`
- Demonstrates composition relationships

### 6. Static Class Members
- `Booking::bookingCounter` - shared counter for generating unique PNR numbers
- `Airline::totalAirlinesCreated` - tracks total airline objects created
- Static member functions to access static data

### 7. Inheritance - Single Level
- `Admin` inherits from `User` (User → Admin)
- `Customer` inherits from `User` (User → Customer)
- `CashPayment` inherits from `Payment` (Payment → CashPayment)
- `LoyaltyPayment` inherits from `Payment` (Payment → LoyaltyPayment)

### 8. Inheritance - Multi-Level
- `Payment` → `OnlinePayment` → `CreditCardPayment`
- Three-level inheritance chain demonstrating hierarchical relationships

### 9. Protected Members
- `User` base class uses **protected** members
- Accessible in derived classes (`Admin`, `Customer`)
- Not accessible from outside the class hierarchy

### 10. Polymorphism
- **Virtual functions** in base classes
- **Overridden methods** in derived classes
- Runtime polymorphism demonstrated in OOP demo menus

### 11. Operator Overloading
- `Booking` class overloads the `==` operator
- Allows comparing two bookings by their PNR number

### 12. Friend Functions
- `showLoyaltyPointsUsed()` is a friend of `LoyaltyPayment`
- Accesses private `pointsUsed` member directly
- Demonstrates controlled access to private data

### 13. Abstraction
- Complex operations hidden inside class methods
- Simple public interfaces for users of the classes

### 14. Composition
- `Flight` **HAS-A** `Seat[]` array (composition)
- `Flight` **HAS-A** `Booking[]` array (composition)
- `Airline` **HAS-A** `Flight[]` array (composition)
- `Booking` **HAS-A** `Passenger` object (composition)

---

## Class List

The system contains **13 classes**:

1. **Passenger** - Stores passenger information (name, age, ID)
2. **Seat** - Represents one seat on a flight (number, class, availability, price)
3. **Booking** - Stores one reservation (PNR, passenger, seat, payment)
4. **Flight** - Represents one flight with seats and bookings
5. **Airline** - Manages multiple flights
6. **User** - Base class for all system users
7. **Admin** - Inherits from User, represents admin users
8. **Customer** - Inherits from User, represents customer users
9. **Payment** - Base class for all payment methods
10. **OnlinePayment** - Inherits from Payment, base for online payments
11. **CreditCardPayment** - Inherits from OnlinePayment (multi-level)
12. **CashPayment** - Inherits from Payment, handles cash transactions
13. **LoyaltyPayment** - Inherits from Payment, handles points redemption

---

## Features

### Main Features:
1. **View All Flights** - Display all available flights with details
2. **Search Flights by Route** - Find flights from origin to destination
3. **Book a Seat** - Complete booking process with payment
4. **Cancel a Booking** - Cancel using PNR number
5. **View Booking Details** - Display formatted boarding pass ticket
6. **View Passenger Manifest** - Show all passengers on a flight

### Payment Methods:
- **Credit Card Payment** (demonstrates multi-level inheritance)
- **Cash Payment** (with change calculation)
- **Loyalty Points Payment** (with friend function demonstration)

### OOP Demonstrations:
- **Demo 7: User Hierarchy** - Shows polymorphism with Admin and Customer
- **Demo 8: Payment Methods** - Shows polymorphism with payment types

---

## Sample Data

The system loads 3 sample flights on startup:

1. **PK-301**: Lahore → Karachi (2026-06-01, 10:00-12:00, 18 seats)
2. **PK-502**: Islamabad → Dubai (2026-06-05, 14:00-17:30, 18 seats)
3. **PK-786**: Karachi → London (2026-06-10, 22:00-06:00, 18 seats)

Each flight has:
- **14 Economy seats** (Rs. 5,000 each)
- **4 Business seats** (Rs. 12,000 each)

---

## Usage Example

```
==========================================
      AIRLINE RESERVATION SYSTEM
==========================================
  1. View All Flights
  2. Search Flights by Route
  3. Book a Seat
  4. Cancel a Booking
  5. View Booking Details (Ticket)
  6. View Passenger Manifest
  7. Demo: User Hierarchy (OOP)
  8. Demo: Payment Methods (OOP)
  0. Exit
==========================================
Enter your choice : 3

==========================================
  BOOK A SEAT
==========================================
Enter flight number (e.g. PK-301) : PK-301
Enter passenger full name : Ali Ahmed
Enter passenger age       : 28
Enter passenger ID / Passport : PK-1234567
Enter seat class (economy / business) : economy

Payment Method:
  1. Credit Card
  2. Cash
  3. Loyalty Points
Enter your choice (1-3) : 2

Cash payment of Rs.5000 received.
Change returned: Rs.500.

==========================================
  BOOKING CONFIRMED
==========================================
  PNR Number  : PNR001
  Seat Number : 1
  Seat Class  : Economy
  Amount Paid : Rs.5000
  SAVE YOUR PNR NUMBER FOR FUTURE USE!
==========================================
```

---

## Code Quality Standards

This project follows strict coding standards for educational purposes:

✅ **Every line has a comment** explaining what it does  
✅ **No abbreviations** - all variable names are full English words  
✅ **No pointers** except where absolutely necessary  
✅ **No dynamic memory** - all objects on the stack  
✅ **Fixed array sizes** defined as constants  
✅ **Input validation** on all user inputs  
✅ **Clean terminal output** with separators and formatting  
✅ **Beginner-friendly syntax** - no complex expressions  

---

## Learning Objectives

After studying this project, you will understand:

- How to design classes for real-world entities
- How to implement encapsulation with private data and public methods
- How to use inheritance to create class hierarchies
- How to implement polymorphism with virtual functions
- How to overload operators for custom behavior
- How to use friend functions for controlled access
- How to manage relationships between classes (composition)
- How to use static members for class-level data
- How to write clean, commented, beginner-friendly code

---

## Project Constraints

This project intentionally follows these constraints for educational purposes:

- **Only 3 headers allowed**: `<iostream>`, `<string>`, `<cstring>`
- **No STL containers**: No vectors, maps, lists, etc.
- **No dynamic memory**: No `new` or `delete` keywords
- **Fixed arrays only**: All collections use plain C++ arrays
- **No external libraries**: Pure standard C++ only
- **Exactly 4 files**: main.cpp, classes.h, helpers.h, README.md

---

## Author

OOP Project - Airline Reservation System  
Created for educational purposes to demonstrate C++ OOP concepts  
Date: 2026-05-05

---

## License

This is an educational project. Feel free to use it for learning purposes.

---

**End of README**
