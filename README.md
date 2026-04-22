# Airline Reservation System

A comprehensive C++ console application demonstrating core Object-Oriented Programming (OOP) concepts through a real-world airline reservation system.

## 📋 Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [OOP Concepts Demonstrated](#oop-concepts-demonstrated)
- [Project Structure](#project-structure)
- [Class Hierarchy](#class-hierarchy)
- [Installation](#installation)
- [How to Compile and Run](#how-to-compile-and-run)
- [Usage Guide](#usage-guide)
- [Sample Data](#sample-data)
- [Menu Options](#menu-options)
- [Code Standards](#code-standards)
- [Technical Specifications](#technical-specifications)
- [Testing](#testing)
- [Known Limitations](#known-limitations)
- [Future Enhancements](#future-enhancements)
- [Learning Objectives](#learning-objectives)
- [Contributing](#contributing)
- [License](#license)

---

## 🎯 Project Overview

This project is an educational implementation of an airline reservation system built in pure C++ (C++11 standard). It demonstrates fundamental OOP concepts including encapsulation, inheritance, polymorphism, composition, abstraction, and more through a practical, real-world application.

**Difficulty Level:** Intermediate  
**Language:** C++ (Pure Standard, No External Libraries)  
**Type:** Terminal-Based Console Application  
**Development Approach:** Subagent-Driven Development  
**Completion Date:** April 22, 2026

---

## ✨ Features

### Core Functionality
- ✅ **Flight Management** - View all flights, search by route
- ✅ **Booking System** - Book seats, cancel bookings, view booking details
- ✅ **Seat Selection** - Choose between Economy and Business class
- ✅ **Payment Processing** - Multiple payment methods (Credit Card, Cash, Loyalty Points)
- ✅ **User Management** - Admin and Customer user types with different privileges
- ✅ **Loyalty Program** - Customer loyalty points and automatic tier upgrades
- ✅ **Passenger Manifest** - View all passengers on a specific flight
- ✅ **Ticket Generation** - Print formatted boarding passes

### User Types
- **Admin** - Manage flights, users, and view reports
- **Customer** - Book flights, earn loyalty points, redeem rewards

### Payment Methods
- **Credit Card** - Card validation and processing
- **Cash** - Cash payment with change calculation
- **Loyalty Points** - Points redemption with conversion rate

---

## 🎓 OOP Concepts Demonstrated

### 1. Encapsulation
All classes use private data members with public getter/setter methods for controlled access.

**Implemented in:** `Seat`, `Passenger`, `Booking`, `Flight`, `Airline`, `User`, `Admin`, `Customer`, `Payment`, `CreditCardPayment`, `CashPayment`, `PointsPayment`

**Example:**
```cpp
class Seat {
private:
    int seatNumber;        // Private data member
    string seatClass;      // Private data member
    bool isAvailable;      // Private data member
    
public:
    int getSeatNumber();   // Public getter
    void setSeatNumber(int num);  // Public setter
};
```

### 2. Composition (HAS-A Relationship)
Objects contain other objects as members, demonstrating ownership relationships.

**Examples:**
- `Flight` HAS-A array of `Seat` objects
- `Flight` HAS-A array of `Booking` objects
- `Airline` HAS-A array of `Flight` objects
- `Booking` HAS-A `Passenger` object

```cpp
class Flight {
private:
    Seat* seats;           // Flight contains Seats
    Booking* bookings;     // Flight contains Bookings
};
```

### 3. Inheritance (IS-A Relationship)
Derived classes inherit properties and methods from base classes.

**User Hierarchy:**
- `Admin` IS-A `User`
- `Customer` IS-A `User`

**Payment Hierarchy:**
- `CreditCardPayment` IS-A `Payment`
- `CashPayment` IS-A `Payment`
- `PointsPayment` IS-A `Payment`

```cpp
class Admin : public User {
    // Admin inherits all User properties and methods
};
```

### 4. Polymorphism
Virtual methods in base classes can be overridden by derived classes, enabling runtime polymorphism.

**Example:**
```cpp
class User {
public:
    virtual void displayInfo();  // Virtual method
};

class Admin : public User {
public:
    void displayInfo() override;  // Overridden in derived class
};

// Runtime polymorphism
User* user = new Admin();
user->displayInfo();  // Calls Admin's version
```

### 5. Abstraction
Abstract base classes with pure virtual methods force derived classes to implement specific functionality.

**Example:**
```cpp
class Payment {
public:
    virtual bool processPayment() = 0;    // Pure virtual method
    virtual bool validatePayment() = 0;   // Pure virtual method
};

// Derived classes MUST implement these methods
class CreditCardPayment : public Payment {
public:
    bool processPayment() override;       // Implementation required
    bool validatePayment() override;      // Implementation required
};
```

### 6. Constructor Overloading
Multiple constructors with different parameters provide flexible object initialization.

**Example:**
```cpp
class Passenger {
public:
    Passenger();  // Default constructor
    Passenger(string name, int age, string id);  // Parameterized constructor
};
```

### 7. Static Members
Static members are shared across all instances of a class.

**Example:**
```cpp
class Booking {
private:
    static int bookingCounter;  // Shared across all Booking objects
    
public:
    string generatePNR();  // Uses static counter to generate unique PNRs
};

// Generates: PNR001, PNR002, PNR003, etc.
```

### 8. Dynamic Memory Management
Proper allocation and deallocation of memory using constructors, destructors, and copy operations.

**Example:**
```cpp
class Flight {
private:
    Seat* seats;  // Dynamic array
    
public:
    Flight();                              // Constructor allocates memory
    ~Flight();                             // Destructor deallocates memory
    Flight(const Flight& other);           // Copy constructor
    Flight& operator=(const Flight& other); // Copy assignment operator
};
```

---

## 📁 Project Structure

```
OOP-PROJECT/
├── src/
│   ├── domain/                    # Domain layer classes
│   │   ├── Seat.h                 # Seat class header
│   │   ├── Seat.cpp               # Seat class implementation
│   │   ├── Passenger.h            # Passenger class header
│   │   ├── Passenger.cpp          # Passenger class implementation
│   │   ├── Booking.h              # Booking class header
│   │   ├── Booking.cpp            # Booking class implementation
│   │   ├── Flight.h               # Flight class header
│   │   ├── Flight.cpp             # Flight class implementation
│   │   ├── Airline.h              # Airline class header
│   │   ├── Airline.cpp            # Airline class implementation
│   │   ├── User.h                 # User base class header
│   │   ├── User.cpp               # User base class implementation
│   │   ├── Admin.h                # Admin derived class header
│   │   ├── Admin.cpp              # Admin derived class implementation
│   │   ├── Customer.h             # Customer derived class header
│   │   ├── Customer.cpp           # Customer derived class implementation
│   │   ├── Payment.h              # Payment abstract base class header
│   │   ├── Payment.cpp            # Payment abstract base class implementation
│   │   ├── CreditCardPayment.h    # Credit card payment header
│   │   ├── CreditCardPayment.cpp  # Credit card payment implementation
│   │   ├── CashPayment.h          # Cash payment header
│   │   ├── CashPayment.cpp        # Cash payment implementation
│   │   ├── PointsPayment.h        # Points payment header
│   │   └── PointsPayment.cpp      # Points payment implementation
│   ├── main.cpp                   # Main entry point
│   └── test_user_hierarchy.cpp    # Test program for user hierarchy
├── bin/                           # Compiled binaries and object files
│   ├── airline                    # Main executable
│   ├── test_user_hierarchy        # Test executable
│   └── *.o                        # Object files
├── docs/                          # Documentation
│   └── superpowers/
│       ├── specs/                 # Design specifications
│       │   └── 2026-04-22-airline-reservation-system-design.md
│       └── plans/                 # Implementation plans
│           └── 2026-04-22-airline-reservation-system-implementation.md
├── Makefile                       # Build automation
├── README.md                      # This file
├── PROJECT_SUMMARY.md             # Project completion summary
├── CLAUDE.md                      # Project instructions
└── .gitignore                     # Git ignore file
```

---

## 🏗️ Class Hierarchy

### User Hierarchy
```
User (base class)
├── Admin (derived class)
│   ├── adminLevel: string
│   ├── department: string
│   ├── manageFlights()
│   ├── manageUsers()
│   └── viewReports()
│
└── Customer (derived class)
    ├── loyaltyPoints: int
    ├── membershipTier: string
    ├── earnPoints()
    ├── redeemPoints()
    └── upgradeTier()
```

### Payment Hierarchy
```
Payment (abstract base class)
├── processPayment() = 0 (pure virtual)
├── validatePayment() = 0 (pure virtual)
│
├── CreditCardPayment (derived class)
│   ├── cardNumber: string
│   ├── cardHolderName: string
│   ├── expiryDate: string
│   └── cvv: string
│
├── CashPayment (derived class)
│   ├── amountReceived: double
│   └── changeGiven: double
│
└── PointsPayment (derived class)
    ├── pointsUsed: int
    ├── customerId: string
    └── conversionRate: double
```

### Composition Relationships
```
Airline
└── contains Flight[] (array of Flight objects)
    ├── contains Seat[] (array of Seat objects)
    └── contains Booking[] (array of Booking objects)
        └── contains Passenger (single Passenger object)
```

---

## 🚀 Installation

### Prerequisites
- **C++ Compiler:** g++ with C++11 support or later
- **Operating System:** Linux, macOS, or Windows (with MinGW/Cygwin)
- **Make:** GNU Make (optional, for using Makefile)

### Clone the Repository
```bash
git clone <repository-url>
cd OOP-PROJECT
```

---

## 🔨 How to Compile and Run

### Method 1: Using Makefile (Recommended)

```bash
# Build the project
make

# Run the application
make run

# Build and run tests
make test

# Clean build artifacts
make clean

# Rebuild from scratch
make rebuild

# Display help
make help
```

### Method 2: Manual Compilation

```bash
# Create bin directory if it doesn't exist
mkdir -p bin

# Compile all source files
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o bin/airline -I src/domain

# Run the program
./bin/airline
```

### Method 3: Compile Individual Components

```bash
# Compile domain classes to object files
g++ -std=c++11 -c src/domain/Seat.cpp -o bin/Seat.o -I src/domain
g++ -std=c++11 -c src/domain/Passenger.cpp -o bin/Passenger.o -I src/domain
# ... (repeat for all domain classes)

# Compile main.cpp
g++ -std=c++11 -c src/main.cpp -o bin/main.o -I src/domain

# Link all object files
g++ -std=c++11 bin/*.o -o bin/airline

# Run the program
./bin/airline
```

---

## 📖 Usage Guide

### Starting the Application

```bash
make run
# or
./bin/airline
```

### Main Menu

Upon starting, you'll see:

```
========================================
  WELCOME TO AIRLINE RESERVATION SYSTEM
========================================

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
Enter your choice:
```

---

## 📊 Sample Data

The system comes pre-loaded with 2 sample flights:

### Flight 1: PK-301
- **Route:** Lahore → Karachi
- **Date:** June 1, 2025
- **Departure:** 10:00
- **Arrival:** 12:00
- **Seats:** 50 total (33 Economy, 17 Business)

### Flight 2: PK-502
- **Route:** Islamabad → Dubai
- **Date:** June 5, 2025
- **Departure:** 14:00
- **Arrival:** 17:00
- **Seats:** 50 total (33 Economy, 17 Business)

---

## 🎮 Menu Options

### Option 1: View All Flights
Displays all available flights with details including flight number, route, date, departure/arrival times, and seat availability.

### Option 2: Search Flights by Route
Search for flights by entering origin and destination cities. The system will display all matching flights.

**Example:**
```
Enter origin city: Lahore
Enter destination city: Karachi
```

### Option 3: Book a Seat
Complete booking process with the following steps:

1. Enter flight number (e.g., PK-301)
2. Enter passenger details:
   - Full name
   - Age
   - Passport ID
   - Contact number
   - Email address
3. Choose seat class (Economy or Business)
4. Select payment method:
   - Credit Card
   - Cash
   - Loyalty Points
5. Complete payment details
6. Receive PNR number (e.g., PNR001)

**Example Booking:**
```
Enter flight number: PK-301
Enter passenger name: John Doe
Enter passenger age: 30
Enter passport ID: AB123456
Enter contact number: +1234567890
Enter email: john@example.com
Choose seat class (Economy/Business): Economy

Select payment method:
1. Credit Card
2. Cash
3. Loyalty Points
Enter choice: 1

Enter card number: 1234567812345678
Enter card holder name: John Doe
Enter expiry date (MM/YY): 12/25
Enter CVV: 123

Booking successful! Your PNR: PNR001
```

### Option 4: Cancel Booking
Cancel an existing booking by entering the PNR number. The seat will be freed and made available for other passengers.

**Example:**
```
Enter PNR number: PNR001
Booking PNR001 cancelled successfully!
```

### Option 5: View Booking Details
View complete booking details and print a formatted ticket.

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

### Option 6: Display Flight Manifest
View all passengers booked on a specific flight.

**Example:**
```
Enter flight number: PK-301

========================================
  PASSENGER MANIFEST - Flight PK-301
========================================
1. John Doe | Seat: 5 (Economy) | PNR: PNR001
2. Jane Smith | Seat: 12 (Economy) | PNR: PNR002
3. Bob Johnson | Seat: 51 (Business) | PNR: PNR003
========================================
Total Passengers: 3
```

### Option 7: Test User Hierarchy
Demonstrates polymorphism with User, Admin, and Customer classes. Shows how virtual methods work with base class pointers.

### Option 8: Test Payment Methods
Demonstrates polymorphism with Payment hierarchy. Shows how different payment methods implement the same interface.

### Option 0: Exit
Exits the application gracefully.

---

## 📝 Code Standards

This project follows strict coding standards for educational purposes:

### ✅ Documentation
- **Every line of code has a comment** explaining its purpose
- Class-level comments describe the purpose and OOP concepts
- Method-level comments describe functionality

### ✅ Naming Conventions
- **Full English variable names** - no abbreviations
- **camelCase** for variables and methods
- **PascalCase** for class names
- **UPPER_CASE** for constants

**Good Examples:**
```cpp
int seatNumber;           // Clear, descriptive
string passengerName;     // Full words
double amountPaid;        // Self-explanatory
```

**Bad Examples (Avoided):**
```cpp
int sn;                   // Abbreviation
string pName;             // Unclear
double amt;               // Abbreviated
```

### ✅ Syntax Simplicity
- **No complex expressions** - one operation per line
- **No ternary operators** - use full if/else blocks
- **No nested function calls** - break into separate statements
- **Simple loops only** - for and while loops
- **Clear boolean variables** - named conditions

### ✅ Memory Management
- **No memory leaks** - proper destructors
- **Copy constructors** - safe object copying
- **Copy assignment operators** - safe object assignment
- **RAII principles** - resource acquisition is initialization

### ✅ Input Validation
- All user inputs are validated
- Clear error messages for invalid input
- Program never crashes on bad input

---

## 🔧 Technical Specifications

### Language and Standards
- **Language:** C++ (Pure Standard)
- **Standard:** C++11
- **Compiler:** g++ (GCC)
- **No External Libraries:** Only standard C++ headers

### Allowed Headers
```cpp
#include <iostream>   // Input/output
#include <string>     // String operations
#include <iomanip>    // Formatting
```

### System Limits
- **Maximum Flights per Airline:** 10
- **Maximum Seats per Flight:** 50
- **Maximum Bookings per Flight:** 50
- **Seat Classes:** Economy, Business
- **User Types:** Admin, Customer
- **Payment Methods:** Credit Card, Cash, Loyalty Points

### Membership Tiers
- **Bronze:** 0-1,999 points (default)
- **Silver:** 2,000-4,999 points
- **Gold:** 5,000-9,999 points
- **Platinum:** 10,000+ points

### PNR Format
- **Format:** PNR001, PNR002, PNR003, etc.
- **Generation:** Static counter in Booking class
- **Uniqueness:** Guaranteed unique across all bookings

---

## 🧪 Testing

### Unit Testing

A comprehensive test program is included to verify the user hierarchy and polymorphism:

```bash
# Build and run tests
make test

# Or manually
g++ -std=c++11 src/test_user_hierarchy.cpp src/domain/User.cpp src/domain/Admin.cpp src/domain/Customer.cpp src/domain/Booking.cpp src/domain/Passenger.cpp -o bin/test_user_hierarchy -I src/domain
./bin/test_user_hierarchy
```

### Test Coverage

The test program verifies:
1. ✅ Admin object creation and displayInfo()
2. ✅ Customer object creation and displayInfo()
3. ✅ Polymorphism with base class pointers (User* → Admin/Customer)
4. ✅ Virtual login method through base pointers
5. ✅ Admin-specific methods (manageFlights, manageUsers, viewReports)
6. ✅ Customer-specific methods (loyalty points, tier updates)
7. ✅ Array of base class pointers (advanced polymorphism)
8. ✅ Login validation with wrong credentials

### Integration Testing

Manual testing checklist:
- ✅ View all flights
- ✅ Search flights by route
- ✅ Book a seat with all payment methods
- ✅ Cancel a booking
- ✅ View booking details and print ticket
- ✅ Display passenger manifest
- ✅ Test user hierarchy polymorphism
- ✅ Test payment method polymorphism

### Memory Testing

```bash
# Check for memory leaks (Linux/macOS)
valgrind --leak-check=full ./bin/airline

# Expected result: No memory leaks detected
```

---

## ⚠️ Known Limitations

These limitations are intentional for educational purposes:

1. **In-memory only** - No persistent storage (no file I/O or database)
2. **Single airline** - System manages one airline at a time
3. **Fixed capacities** - 10 flights max, 50 seats per flight, 50 bookings per flight
4. **No date validation** - Dates are stored as strings without validation
5. **Simplified payment** - No real payment gateway integration
6. **No seat map** - Seats are assigned automatically, no visual seat selection
7. **No time zones** - All times are stored as strings without timezone handling
8. **No email notifications** - Booking confirmations are displayed only
9. **No multi-threading** - Single-threaded application
10. **No network support** - Standalone application, no client-server architecture

---

## 🚀 Future Enhancements

For advanced learners, consider adding:

### Persistence Layer
- File I/O for saving/loading data
- SQLite database integration
- JSON/XML data serialization

### Advanced Features
- Multi-airline support
- Visual seat map selection
- Flight scheduling with time zones
- Email/SMS notifications
- Discount codes and promotions
- Reporting and analytics dashboard
- Booking history and statistics

### User Interface
- GUI interface using Qt or GTK
- Web interface using CGI or embedded server
- Mobile app integration

### Architecture
- Multi-threading for concurrent bookings
- Network support (client-server architecture)
- RESTful API for external integrations
- Microservices architecture

### Security
- Password encryption
- Secure payment processing
- User authentication tokens
- Role-based access control (RBAC)

---

## 🎯 Learning Objectives

Students working with this project will learn:

### OOP Concepts
1. ✅ How to design class hierarchies
2. ✅ When to use composition vs inheritance
3. ✅ How polymorphism enables flexible code
4. ✅ How to implement abstract interfaces
5. ✅ How static members work across instances
6. ✅ How to overload constructors effectively

### C++ Skills
7. ✅ How to manage dynamic memory safely
8. ✅ How to implement copy constructors and assignment operators
9. ✅ How to use virtual methods and pure virtual methods
10. ✅ How to organize code in a modular structure

### Software Engineering
11. ✅ How to build a complete application from scratch
12. ✅ How to use Makefiles for build automation
13. ✅ How to write clean, documented code
14. ✅ How to test and debug C++ applications
15. ✅ How to design user-friendly interfaces

---

## 🤝 Contributing

This is an educational project. Contributions are welcome for:

- Bug fixes
- Code improvements
- Documentation enhancements
- Additional test cases
- New features (as learning exercises)

### Contribution Guidelines
1. Fork the repository
2. Create a feature branch
3. Follow the existing code standards
4. Add comments to every line
5. Test your changes thoroughly
6. Submit a pull request

---

## 📄 License

This is an educational project. Feel free to use and modify for learning purposes.

**Educational Use:** ✅ Allowed  
**Commercial Use:** ❌ Not intended  
**Modification:** ✅ Encouraged  
**Distribution:** ✅ Allowed with attribution

---

## 🙏 Acknowledgments

- **Development Approach:** Subagent-Driven Development
- **Built with:** Claude Code (Claude Sonnet 4)
- **Completion Date:** April 22, 2026
- **Purpose:** Educational demonstration of OOP concepts in C++

---

## 📞 Support

For questions, issues, or suggestions:

1. Check the documentation in `docs/` directory
2. Review the `PROJECT_SUMMARY.md` file
3. Examine the code comments (every line is documented)
4. Run the test program to understand polymorphism
5. Experiment with the code and learn by doing

---

## 📚 Additional Resources

### Documentation Files
- `README.md` - This file (complete project documentation)
- `PROJECT_SUMMARY.md` - Project completion summary
- `CLAUDE.md` - Project instructions and specifications
- `docs/superpowers/specs/` - Design specifications
- `docs/superpowers/plans/` - Implementation plans

### Code Examples
- `src/main.cpp` - Main application with all features
- `src/test_user_hierarchy.cpp` - Polymorphism demonstration
- `src/domain/*.cpp` - All class implementations with comments

---

## 🎓 Educational Value

This project is ideal for:

- **Computer Science Students** - Learning OOP concepts
- **C++ Beginners** - Understanding C++ syntax and features
- **Intermediate Programmers** - Practicing design patterns
- **Self-Learners** - Building a complete project from scratch
- **Instructors** - Teaching OOP concepts with a real-world example

---

**Happy Learning! 🚀**

---

*Last Updated: April 22, 2026*  
*Version: 1.0.0*  
*Status: Production Ready*
