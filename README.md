# Airline Reservation System

A comprehensive C++ console application demonstrating core Object-Oriented Programming (OOP) concepts through a real-world airline reservation system.

## Project Overview

This project is an educational implementation of an airline reservation system built in pure C++ (C++11 standard). It demonstrates fundamental OOP concepts including encapsulation, inheritance, polymorphism, composition, abstraction, and more.

**Difficulty Level:** Intermediate  
**Language:** C++ (Pure Standard, No External Libraries)  
**Type:** Terminal-Based Console Application

## Features

- **Flight Management:** View, search, and manage flights
- **Booking System:** Book seats, cancel bookings, view booking details
- **User Management:** Admin and Customer user types with different privileges
- **Payment Processing:** Multiple payment methods (Credit Card, Cash, Loyalty Points)
- **Loyalty Program:** Customer loyalty points and tier system
- **Passenger Manifest:** View all passengers on a flight

## OOP Concepts Demonstrated

### 1. Encapsulation
- All classes use private data members with public getter/setter methods
- Implemented in: `Seat`, `Passenger`, `Booking`, `Flight`, `Airline`, `User`, `Payment`

### 2. Composition (HAS-A Relationship)
- `Flight` contains arrays of `Seat` and `Booking` objects
- `Airline` contains array of `Flight` objects
- `Booking` contains a `Passenger` object

### 3. Inheritance (IS-A Relationship)
- `Admin` and `Customer` inherit from `User` base class
- `CreditCardPayment`, `CashPayment`, `PointsPayment` inherit from `Payment` base class

### 4. Polymorphism
- Virtual methods in base classes overridden by derived classes
- Runtime polymorphism demonstrated with base class pointers

### 5. Abstraction
- `Payment` is an abstract base class with pure virtual methods
- Forces derived classes to implement `processPayment()` and `validatePayment()`

### 6. Constructor Overloading
- Multiple constructors in `Passenger` and `Flight` classes
- Default and parameterized constructors

### 7. Static Members
- `Booking` class uses static counter for unique PNR generation
- Generates PNR numbers: PNR001, PNR002, PNR003, etc.

### 8. Dynamic Memory Management
- `Flight` and `Airline` classes use dynamic arrays
- Proper memory allocation and deallocation with constructors/destructors

## Project Structure

```
OOP-PROJECT/
├── src/
│   ├── domain/              # Domain layer classes
│   │   ├── Seat.h/cpp
│   │   ├── Passenger.h/cpp
│   │   ├── Booking.h/cpp
│   │   ├── Flight.h/cpp
│   │   ├── Airline.h/cpp
│   │   ├── User.h/cpp
│   │   ├── Admin.h/cpp
│   │   ├── Customer.h/cpp
│   │   ├── Payment.h/cpp
│   │   ├── CreditCardPayment.h/cpp
│   │   ├── CashPayment.h/cpp
│   │   └── PointsPayment.h/cpp
│   ├── main.cpp             # Main entry point
│   └── test_user_hierarchy.cpp  # Test program
├── bin/                     # Compiled binaries and object files
├── docs/                    # Documentation
│   └── superpowers/
│       ├── specs/           # Design specifications
│       └── plans/           # Implementation plans
├── Makefile                 # Build automation
├── README.md                # This file
└── CLAUDE.md                # Project instructions
```

## Class Hierarchy

### User Hierarchy
```
User (base class)
├── Admin (derived)
└── Customer (derived)
```

### Payment Hierarchy
```
Payment (abstract base class)
├── CreditCardPayment (derived)
├── CashPayment (derived)
└── PointsPayment (derived)
```

## How to Compile and Run

### Using Makefile (Recommended)

```bash
# Build the project
make

# Run the program
make run

# Clean build artifacts
make clean

# Rebuild from scratch
make rebuild

# Build and run tests
make test

# Display help
make help
```

### Manual Compilation

```bash
# Compile all source files
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o bin/airline -I src/domain

# Run the program
./bin/airline
```

## Sample Data

The system comes pre-loaded with 2 sample flights:

**Flight 1:**
- Flight Number: PK-301
- Route: Lahore → Karachi
- Date: 2026-04-22
- Seats: 33 Economy, 17 Business

**Flight 2:**
- Flight Number: PK-502
- Route: Islamabad → Dubai
- Date: 2026-04-25
- Seats: 33 Economy, 17 Business

## Menu Options

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

## Usage Examples

### Booking a Seat
1. Select option 3 from the main menu
2. Enter flight number (e.g., PK-301)
3. Enter passenger details (name, age, passport ID, contact, email)
4. Choose seat class (Economy or Business)
5. Select payment method (CreditCard, Cash, or Points)
6. Complete payment details
7. Receive PNR number for your booking

### Viewing a Ticket
1. Select option 5 from the main menu
2. Enter your PNR number (e.g., PNR001)
3. View formatted ticket with all booking details

### Canceling a Booking
1. Select option 4 from the main menu
2. Enter your PNR number
3. Booking will be canceled and seat freed

## Testing

A test program is included to verify the user hierarchy and polymorphism:

```bash
# Build and run tests
make test

# Or manually
g++ -std=c++11 src/test_user_hierarchy.cpp src/domain/User.cpp src/domain/Admin.cpp src/domain/Customer.cpp src/domain/Booking.cpp src/domain/Passenger.cpp -o bin/test_user_hierarchy -I src/domain
./bin/test_user_hierarchy
```

## Code Standards

- **Every line of code has a comment** explaining its purpose
- **Simple, beginner-friendly syntax** - no complex expressions or advanced features
- **Full English variable names** - no abbreviations
- **No STL containers** - uses plain C++ arrays with dynamic memory
- **Input validation** on all user inputs
- **Clean formatted output** with separators and boxes

## Technical Specifications

- **Compiler:** g++ with C++11 standard
- **Maximum Flights:** 10 per airline
- **Maximum Seats:** 50 per flight
- **Maximum Bookings:** 50 per flight
- **Seat Classes:** Economy, Business
- **Payment Methods:** Credit Card, Cash, Loyalty Points
- **User Types:** Admin, Customer

## Learning Objectives

This project helps students understand:
1. How to design class hierarchies
2. When to use composition vs inheritance
3. How polymorphism enables flexible code
4. How to manage dynamic memory safely
5. How to implement abstract interfaces
6. How static members work across instances
7. How to overload constructors effectively

## Future Enhancements

Potential improvements for advanced learners:
- Persistent storage (file I/O or database)
- Multi-airline support
- Flight scheduling and time management
- Seat selection interface
- Discount codes and promotions
- Email notifications
- Reporting and analytics

## Author

Created as an educational project to demonstrate OOP concepts in C++.

## License

This is an educational project. Feel free to use and modify for learning purposes.

## Acknowledgments

Built with Claude Code using the Subagent-Driven Development workflow.
