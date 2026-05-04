# Airline Reservation System

A comprehensive C++ console application demonstrating core Object-Oriented Programming (OOP) concepts through a real-world airline reservation system.

## Overview

**Language:** C++11 (Pure Standard, No External Libraries)  
**Type:** Terminal-Based Console Application  
**Level:** Intermediate  
**Status:** Production Ready

Educational implementation showcasing encapsulation, inheritance, polymorphism, composition, and abstraction through practical airline booking functionality.

---

## Features

### Core Functionality
- **Flight Management** - View flights, search by route
- **Booking System** - Book seats, cancel reservations, view details
- **Seat Selection** - Economy and Business class options
- **Payment Processing** - Credit Card, Cash, Loyalty Points
- **User Management** - Admin and Customer roles with distinct privileges
- **Loyalty Program** - Points accumulation and tier upgrades
- **Passenger Manifest** - View all passengers per flight
- **Ticket Generation** - Formatted boarding passes

### User Roles
- **Admin** - Manage flights, users, and reports
- **Customer** - Book flights, earn points, redeem rewards

---

## Quick Start

### Prerequisites
- C++ compiler with C++11 support (g++, clang++)
- GNU Make (optional)
- Linux, macOS, or Windows (MinGW/Cygwin)

### Installation

```bash
git clone <repository-url>
cd airline-reservation-system
```

### Build and Run

**Using Make (Recommended):**
```bash
make              # Build project
make run          # Run application
make test         # Run tests
make clean        # Clean build artifacts
```

**Using Scripts:**
```bash
# Windows
scripts/windows/compile.bat
scripts/windows/run.bat

# Unix/Linux/macOS
scripts/unix/compile.sh
scripts/unix/run.sh
```

**Manual Compilation:**
```bash
mkdir -p bin
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o bin/airline -I src/domain
./bin/airline
```

---

## Project Structure

```
airline-reservation-system/
├── src/
│   ├── domain/                    # Core domain classes
│   │   ├── Seat.{h,cpp}          # Seat management
│   │   ├── Passenger.{h,cpp}     # Passenger information
│   │   ├── Booking.{h,cpp}       # Booking logic
│   │   ├── Flight.{h,cpp}        # Flight operations
│   │   ├── Airline.{h,cpp}       # Airline management
│   │   ├── User.{h,cpp}          # User base class
│   │   ├── Admin.{h,cpp}         # Admin functionality
│   │   ├── Customer.{h,cpp}      # Customer functionality
│   │   ├── Payment.{h,cpp}       # Payment abstract base
│   │   ├── CreditCardPayment.{h,cpp}
│   │   ├── CashPayment.{h,cpp}
│   │   └── PointsPayment.{h,cpp}
│   ├── main.cpp                   # Application entry point
│   └── test_user_hierarchy.cpp    # Unit tests
├── scripts/
│   ├── windows/                   # Windows build scripts
│   │   ├── compile.bat
│   │   └── run.bat
│   └── unix/                      # Unix/Linux/macOS scripts
│       ├── compile.sh
│       └── run.sh
├── bin/                           # Compiled binaries (generated)
├── docs/                          # Documentation
│   └── superpowers/
│       ├── specs/                 # Design specifications
│       └── plans/                 # Implementation plans
├── Makefile                       # Build automation
└── README.md                      # This file
```

---

## OOP Concepts Demonstrated

### 1. Encapsulation
Private data members with public getter/setter methods for controlled access.

```cpp
class Seat {
private:
    int seatNumber;
    string seatClass;
    bool isAvailable;
public:
    int getSeatNumber();
    void setSeatNumber(int num);
};
```

### 2. Composition (HAS-A)
Objects contain other objects as members.

- `Flight` HAS-A array of `Seat` objects
- `Flight` HAS-A array of `Booking` objects
- `Airline` HAS-A array of `Flight` objects
- `Booking` HAS-A `Passenger` object

### 3. Inheritance (IS-A)
Derived classes inherit from base classes.

**User Hierarchy:**
- `Admin` IS-A `User`
- `Customer` IS-A `User`

**Payment Hierarchy:**
- `CreditCardPayment` IS-A `Payment`
- `CashPayment` IS-A `Payment`
- `PointsPayment` IS-A `Payment`

### 4. Polymorphism
Virtual methods enable runtime polymorphism.

```cpp
User* user = new Admin();
user->displayInfo();  // Calls Admin's version
```

### 5. Abstraction
Pure virtual methods force derived class implementation.

```cpp
class Payment {
public:
    virtual bool processPayment() = 0;
    virtual bool validatePayment() = 0;
};
```

### 6. Static Members
Shared across all instances for unique ID generation.

```cpp
class Booking {
private:
    static int bookingCounter;
public:
    string generatePNR();  // PNR001, PNR002, etc.
};
```

### 7. Dynamic Memory Management
Proper allocation/deallocation with constructors, destructors, copy operations.

---

## Usage

### Main Menu

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

### Sample Flights

**Flight PK-301:** Lahore → Karachi (June 1, 2025, 10:00-12:00)  
**Flight PK-502:** Islamabad → Dubai (June 5, 2025, 14:00-17:00)

Each flight: 50 seats (33 Economy, 17 Business)

### Booking Example

```
Enter flight number: PK-301
Enter passenger name: John Doe
Enter passenger age: 30
Enter passport ID: AB123456
Choose seat class (Economy/Business): Economy

Select payment method:
1. Credit Card
2. Cash
3. Loyalty Points

Booking successful! Your PNR: PNR001
```

### Ticket Format

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
|  Seat Number  : 5                        |
|  Seat Class   : Economy                  |
|  Amount Paid  : $150.00                  |
+------------------------------------------+
```

---

## Code Standards

### Documentation
- Every line commented for educational clarity
- Class-level comments explain OOP concepts
- Method-level comments describe functionality

### Naming Conventions
- **camelCase** - variables and methods
- **PascalCase** - class names
- **UPPER_CASE** - constants
- Full English names (no abbreviations)

### Syntax Simplicity
- One operation per line
- No ternary operators
- No nested function calls
- Clear boolean variables
- Simple loops only

### Memory Management
- No memory leaks
- Proper destructors
- Copy constructors and assignment operators
- RAII principles

---

## Testing

### Run Tests

```bash
make test
```

### Test Coverage
- Admin/Customer object creation
- Polymorphism with base class pointers
- Virtual method dispatch
- Admin-specific methods
- Customer loyalty system
- Payment method validation

### Memory Testing

```bash
valgrind --leak-check=full ./bin/airline
```

---

## Technical Specifications

**Language:** C++11  
**Compiler:** g++ (GCC)  
**Headers:** `<iostream>`, `<string>`, `<iomanip>` only

### System Limits
- Maximum flights per airline: 10
- Maximum seats per flight: 50
- Maximum bookings per flight: 50
- Seat classes: Economy, Business
- Payment methods: Credit Card, Cash, Loyalty Points

### Membership Tiers
- **Bronze:** 0-1,999 points
- **Silver:** 2,000-4,999 points
- **Gold:** 5,000-9,999 points
- **Platinum:** 10,000+ points

---

## Known Limitations

Intentional for educational purposes:

1. In-memory only (no persistence)
2. Single airline management
3. Fixed capacities
4. No date validation
5. Simplified payment (no gateway)
6. Automatic seat assignment (no visual map)
7. No timezone handling
8. No email notifications
9. Single-threaded
10. No network support

---

## Future Enhancements

### Persistence
- File I/O for data storage
- SQLite database integration
- JSON/XML serialization

### Advanced Features
- Multi-airline support
- Visual seat map
- Flight scheduling with timezones
- Email/SMS notifications
- Discount codes
- Analytics dashboard

### Architecture
- Multi-threading for concurrent bookings
- Client-server architecture
- RESTful API
- Microservices design

---

## Learning Objectives

Students will learn:

1. Class hierarchy design
2. Composition vs inheritance
3. Polymorphism implementation
4. Abstract interface design
5. Static member usage
6. Constructor overloading
7. Dynamic memory management
8. Copy constructors and assignment operators
9. Virtual and pure virtual methods
10. Modular code organization
11. Build automation with Make
12. Clean code documentation
13. Application testing and debugging

---

## Contributing

Contributions welcome for:
- Bug fixes
- Code improvements
- Documentation enhancements
- Additional test cases
- New features (learning exercises)

### Guidelines
1. Fork repository
2. Create feature branch
3. Follow existing code standards
4. Add comments to every line
5. Test thoroughly
6. Submit pull request

---

## License

Educational project for learning purposes.

**Educational Use:** ✅ Allowed  
**Commercial Use:** ❌ Not intended  
**Modification:** ✅ Encouraged  
**Distribution:** ✅ Allowed with attribution

---

## Support

For questions or issues:
1. Check `docs/` directory
2. Review code comments (every line documented)
3. Run test program
4. Experiment and learn by doing

---

*Last Updated: April 23, 2026*  
*Version: 1.1.0*
