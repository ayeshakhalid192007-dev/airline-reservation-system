# FLOW.md — Airline Reservation System Workflow

## 📋 TABLE OF CONTENTS
1. [Project Overview](#project-overview)
2. [File Structure and Organization](#file-structure-and-organization)
3. [Class Hierarchy and Relationships](#class-hierarchy-and-relationships)
4. [How Files Connect to main.cpp](#how-files-connect-to-maincpp)
5. [Complete Program Workflow](#complete-program-workflow)
6. [OOP Concepts Implementation](#oop-concepts-implementation)
7. [Data Flow Diagram](#data-flow-diagram)

---

## 🎯 PROJECT OVERVIEW

**Project Name:** Airline Reservation System

**Purpose:** A terminal-based console application that manages airline flight bookings, seat reservations, passenger information, and payment processing.

**Language:** Pure Standard C++ (No STL containers, no external libraries)

**Key Features:**
- View and search flights
- Book seats with passenger information
- Cancel bookings
- View tickets and passenger manifests
- Multiple payment methods (Credit Card, Cash, Points)
- User role management (Admin, Customer)

---

## 📁 FILE STRUCTURE AND ORGANIZATION

The project is organized into a clean, modular structure:

```
OOP-PROJECT/
│
├── src/
│   ├── main.cpp                    # Entry point - contains only main() function
│   ├── constants.cpp               # All constant definitions (MAX_FLIGHTS, MAX_SEATS, etc.)
│   │
│   ├── domain/                     # Core business logic classes
│   │   ├── User.h / User.cpp       # BASE CLASS for all users
│   │   ├── Admin.h / Admin.cpp     # DERIVED from User
│   │   ├── Customer.h / Customer.cpp # DERIVED from User
│   │   ├── Payment.h / Payment.cpp # ABSTRACT BASE CLASS for payments
│   │   ├── CreditCardPayment.h / CreditCardPayment.cpp # DERIVED from Payment
│   │   ├── CashPayment.h / CashPayment.cpp # DERIVED from Payment
│   │   ├── PointsPayment.h / PointsPayment.cpp # DERIVED from Payment
│   │   ├── Seat.h / Seat.cpp       # Standalone class
│   │   ├── Passenger.h / Passenger.cpp # Standalone class
│   │   ├── Booking.h / Booking.cpp # Standalone class with static members
│   │   ├── Flight.h / Flight.cpp   # Composition class (contains Seats and Bookings)
│   │   └── Airline.h / Airline.cpp # Top-level composition class (contains Flights)
│   │
│   ├── ui/
│   │   └── menu.cpp                # Menu display functions
│   │
│   └── services/
│       └── helpers.cpp             # All helper functions for operations
│
├── CLAUDE.md                       # Project specification and rules
├── README.md                       # Project documentation
└── FLOW.md                         # This file - workflow explanation
```

---

## 🏗️ CLASS HIERARCHY AND RELATIONSHIPS

### **INHERITANCE HIERARCHIES**

#### **Hierarchy 1: User System**
```
        User (BASE CLASS)
         /        \
        /          \
    Admin      Customer
  (DERIVED)    (DERIVED)
```

**Explanation:**
- `User` is the **base class** that contains common properties for all users (userId, username, password, email, fullName, phoneNumber)
- `Admin` is a **derived class** that inherits from User and adds admin-specific functionality (can manage flights, view all bookings)
- `Customer` is a **derived class** that inherits from User and adds customer-specific functionality (can book flights, view own bookings, earn loyalty points)

**Key Concept:** Inheritance allows Admin and Customer to reuse User's code while adding their own specialized behavior.

---

#### **Hierarchy 2: Payment System**
```
           Payment (ABSTRACT BASE CLASS)
              /       |        \
             /        |         \
    CreditCard    Cash      Points
     Payment    Payment    Payment
    (DERIVED)  (DERIVED)  (DERIVED)
```

**Explanation:**
- `Payment` is an **abstract base class** (has pure virtual functions) that defines the interface for all payment types
- `CreditCardPayment` is a **derived class** that implements credit card payment processing (validates card number, CVV, expiry date)
- `CashPayment` is a **derived class** that implements cash payment processing (validates cash amount, calculates change)
- `PointsPayment` is a **derived class** that implements loyalty points payment (validates points balance, deducts points)

**Key Concept:** Polymorphism allows different payment methods to be processed through the same interface.

---

### **COMPOSITION RELATIONSHIPS**

#### **Composition 1: Airline contains Flights**
```
Airline
  └── Flight flights[10]  (array of Flight objects)
```

**Explanation:**
- The `Airline` class **owns** an array of `Flight` objects
- When an Airline object is created, it automatically creates space for 10 Flight objects
- This is **composition** because Flights cannot exist without the Airline

---

#### **Composition 2: Flight contains Seats and Bookings**
```
Flight
  ├── Seat seats[50]      (array of Seat objects)
  └── Booking bookings[50] (array of Booking objects)
```

**Explanation:**
- The `Flight` class **owns** arrays of `Seat` and `Booking` objects
- When a Flight object is created, it automatically creates space for 50 Seats and 50 Bookings
- This is **composition** because Seats and Bookings belong to a specific Flight

---

#### **Composition 3: Booking contains Passenger**
```
Booking
  └── Passenger bookingPassenger  (Passenger object)
```

**Explanation:**
- The `Booking` class **owns** a `Passenger` object
- Each booking is associated with exactly one passenger
- This is **composition** because the Passenger data is part of the Booking

---

### **STANDALONE CLASSES**

These classes do not inherit from any base class and are not part of inheritance hierarchies:

1. **Seat** - Represents a single seat on a flight
2. **Passenger** - Represents passenger information
3. **Booking** - Represents a booking transaction (has static PNR counter)
4. **Flight** - Represents a flight (uses composition)
5. **Airline** - Represents the airline company (uses composition)

---

## 🔗 HOW FILES CONNECT TO MAIN.CPP

### **Step-by-Step Connection Process:**

#### **Step 1: main.cpp includes header files**
```cpp
#include "domain/Airline.h"
#include "domain/Flight.h"
#include "domain/Booking.h"
#include "domain/Passenger.h"
#include "domain/Seat.h"
#include "domain/User.h"
#include "domain/Admin.h"
#include "domain/Customer.h"
#include "domain/Payment.h"
#include "domain/CreditCardPayment.h"
#include "domain/CashPayment.h"
#include "domain/PointsPayment.h"
```

**What this does:**
- Tells the compiler about the class definitions
- Allows main.cpp to create objects of these classes
- Provides access to all public methods

---

#### **Step 2: main.cpp includes utility files**
```cpp
#include "constants.cpp"        // Brings in MAX_FLIGHTS, MAX_SEATS, etc.
#include "ui/menu.cpp"          // Brings in displayMainMenu() function
#include "services/helpers.cpp" // Brings in all helper functions
```

**What this does:**
- `constants.cpp` provides all constant values used throughout the program
- `menu.cpp` provides the function to display the menu
- `helpers.cpp` provides all the operational functions (bookSeat, cancelBooking, etc.)

---

#### **Step 3: Compilation links everything together**

When you compile with `g++ main.cpp -o airline`, the compiler:

1. Reads main.cpp
2. Follows all #include directives
3. Reads all header files (.h)
4. Reads all implementation files (.cpp)
5. Links all the code together into one executable

**Visual representation:**
```
main.cpp
   ↓ includes
constants.cpp → provides constants
   ↓ includes
menu.cpp → provides displayMainMenu()
   ↓ includes
helpers.cpp → provides bookSeat(), cancelBooking(), etc.
   ↓ includes
domain/*.h → provides class definitions
   ↓ compiler links
domain/*.cpp → provides class implementations
   ↓ result
airline.exe (executable program)
```

---

## 🔄 COMPLETE PROGRAM WORKFLOW

### **Phase 1: Program Startup**

```
1. User runs: ./airline
2. main() function starts
3. Creates Airline object: Airline airline("Pakistan International Airlines", "PK")
4. Calls airline.loadSampleData() to pre-load 2 sample flights
5. Displays welcome message
6. Enters main menu loop
```

---

### **Phase 2: Main Menu Loop**

```
┌─────────────────────────────────────┐
│  MAIN MENU LOOP (runs forever)      │
├─────────────────────────────────────┤
│  1. Display menu                    │
│  2. Get user choice                 │
│  3. Validate input                  │
│  4. Execute chosen operation        │
│  5. Return to step 1 (unless exit)  │
└─────────────────────────────────────┘
```

---

### **Phase 3: Operation Workflows**

#### **Operation 1: View All Flights**
```
User selects option 1
   ↓
main() calls viewAllFlights(airline)
   ↓
viewAllFlights() calls airline.displayAllFlights()
   ↓
Airline loops through flights[] array
   ↓
For each flight, calls flight.displayFlight()
   ↓
Flight displays: flight number, route, date, available seats
   ↓
Returns to main menu
```

---

#### **Operation 2: Search Flights by Route**
```
User selects option 2
   ↓
main() calls searchFlightsByRoute(airline)
   ↓
Function asks user for origin and destination cities
   ↓
Calls airline.searchFlights(origin, destination)
   ↓
Airline loops through flights[] array
   ↓
Compares each flight's origin and destination
   ↓
Displays matching flights
   ↓
Returns to main menu
```

---

#### **Operation 3: Book a Seat (Most Complex)**
```
User selects option 3
   ↓
main() calls bookSeat(airline)
   ↓
Function asks for: flight number, passenger details, seat class
   ↓
Calls airline.findFlight(flightNumber) to get flight index
   ↓
If flight found:
   ↓
   Calls flight.findAvailableSeat(seatClass)
   ↓
   If seat available:
      ↓
      Creates Passenger object with user input
      ↓
      Creates Booking object (auto-generates PNR using static counter)
      ↓
      Calls booking.createBooking(passenger, flightNum, seatNum, seatClass)
      ↓
      Calls flight.addBooking(booking)
      ↓
      Flight marks seat as unavailable
      ↓
      Displays success message with PNR number
      ↓
      Asks user to select payment method
      ↓
      Creates Payment object (CreditCard/Cash/Points)
      ↓
      Calls payment.processPayment()
      ↓
      Displays payment confirmation
   ↓
Returns to main menu
```

---

#### **Operation 4: Cancel a Booking**
```
User selects option 4
   ↓
main() calls cancelBooking(airline)
   ↓
Function asks for PNR number
   ↓
Loops through all flights in airline
   ↓
For each flight, calls flight.cancelBooking(pnrNumber)
   ↓
Flight searches bookings[] array for matching PNR
   ↓
If found:
   ↓
   Gets seat number from booking
   ↓
   Marks seat as available again
   ↓
   Removes booking from array
   ↓
   Displays success message
   ↓
Returns to main menu
```

---

#### **Operation 5: View Booking Details**
```
User selects option 5
   ↓
main() calls viewBookingDetails(airline)
   ↓
Function asks for PNR number
   ↓
Loops through all flights in airline
   ↓
For each flight, searches bookings[] array
   ↓
If booking found:
   ↓
   Calls booking.displayBooking()
   ↓
   Creates Ticket object: Ticket ticket(booking)
   ↓
   Calls ticket.printTicket()
   ↓
   Displays formatted ticket in a box
   ↓
Returns to main menu
```

---

#### **Operation 6: Display Flight Manifest**
```
User selects option 6
   ↓
main() calls displayFlightManifest(airline)
   ↓
Function asks for flight number
   ↓
Calls airline.findFlight(flightNumber)
   ↓
If flight found:
   ↓
   Calls flight.displayManifest()
   ↓
   Flight loops through bookings[] array
   ↓
   For each booking, displays:
      - Passenger name
      - Seat number
      - Seat class
   ↓
Returns to main menu
```

---

#### **Operation 7: Test User Hierarchy (Polymorphism Demo)**
```
User selects option 7
   ↓
main() calls testUserHierarchy()
   ↓
Creates Admin object
   ↓
Creates Customer object
   ↓
Creates User pointer array: User* users[2]
   ↓
Assigns users[0] = &admin
   ↓
Assigns users[1] = &customer
   ↓
Loops through array and calls users[i]->displayInfo()
   ↓
Demonstrates polymorphism (different behavior for Admin vs Customer)
   ↓
Returns to main menu
```

---

#### **Operation 8: Test Payment Methods (Polymorphism Demo)**
```
User selects option 8
   ↓
main() calls testPaymentMethods()
   ↓
Creates CreditCardPayment object
   ↓
Creates CashPayment object
   ↓
Creates PointsPayment object
   ↓
Creates Payment pointer array: Payment* payments[3]
   ↓
Assigns payments[0] = &creditCard
   ↓
Assigns payments[1] = &cash
   ↓
Assigns payments[2] = &points
   ↓
Loops through array and calls payments[i]->processPayment()
   ↓
Demonstrates polymorphism (different payment processing)
   ↓
Returns to main menu
```

---

## 🎓 OOP CONCEPTS IMPLEMENTATION

### **1. ENCAPSULATION**
**Where:** All 11 classes (User, Admin, Customer, Payment, CreditCardPayment, CashPayment, PointsPayment, Seat, Passenger, Flight, Booking, Airline)

**How it works:**
- All data members are declared `private` or `protected`
- Public getter methods provide read access: `getName()`, `getSeatNumber()`
- Public setter methods provide write access: `setName()`, `setSeatNumber()`
- Direct access to data from outside the class is prevented

**Example:**
```cpp
class Seat {
private:
    int seatNumber;        // Cannot be accessed directly
    string seatClass;      // Cannot be accessed directly
    bool isAvailable;      // Cannot be accessed directly
    
public:
    int getSeatNumber() { return seatNumber; }      // Controlled read access
    void setSeatNumber(int num) { seatNumber = num; } // Controlled write access
};
```

---

### **2. INHERITANCE**
**Where:** User hierarchy (User → Admin, Customer) and Payment hierarchy (Payment → CreditCardPayment, CashPayment, PointsPayment)

**How it works:**
- Base class defines common properties and methods
- Derived classes inherit all base class members
- Derived classes add their own specialized members
- Derived classes can override base class methods

**Example:**
```cpp
// Base class
class User {
protected:
    string userId;
    string username;
public:
    virtual void displayInfo();  // Can be overridden
};

// Derived class
class Admin : public User {
private:
    string adminLevel;  // Admin-specific property
public:
    void displayInfo();  // Overrides base class method
    void manageFlights();  // Admin-specific method
};
```

---

### **3. POLYMORPHISM**
**Where:** User hierarchy and Payment hierarchy

**How it works:**
- Base class pointers can point to derived class objects
- Virtual functions enable runtime polymorphism
- Same function call produces different behavior based on actual object type

**Example:**
```cpp
User* users[2];
users[0] = new Admin(...);
users[1] = new Customer(...);

for (int i = 0; i < 2; i++) {
    users[i]->displayInfo();  // Calls Admin::displayInfo() or Customer::displayInfo()
}
```

---

### **4. COMPOSITION**
**Where:** Airline contains Flights, Flight contains Seats and Bookings, Booking contains Passenger

**How it works:**
- Parent class contains child objects as members (not pointers)
- Child objects are created when parent is created
- Child objects are destroyed when parent is destroyed
- Strong ownership relationship

**Example:**
```cpp
class Flight {
private:
    Seat seats[50];        // Flight OWNS 50 Seat objects
    Booking bookings[50];  // Flight OWNS 50 Booking objects
};

class Airline {
private:
    Flight flights[10];    // Airline OWNS 10 Flight objects
};
```

---

### **5. STATIC MEMBERS**
**Where:** Booking class has static PNR counter

**How it works:**
- Static member is shared by ALL objects of the class
- Only one copy exists in memory
- Used to generate unique PNR numbers across all bookings

**Example:**
```cpp
class Booking {
private:
    static int pnrCounter;  // Shared by all Booking objects
    string pnrNumber;
    
public:
    void createBooking(...) {
        pnrCounter++;  // Increment shared counter
        pnrNumber = "PNR-" + to_string(pnrCounter);  // Generate unique PNR
    }
};

// Initialize static member outside class
int Booking::pnrCounter = 0;
```

---

### **6. CONSTRUCTOR OVERLOADING**
**Where:** Passenger and Flight classes

**How it works:**
- Multiple constructors with different parameter lists
- Allows object creation with different initialization options

**Example:**
```cpp
class Passenger {
public:
    Passenger();  // Default constructor (no parameters)
    Passenger(string name, int age, string id);  // Parameterized constructor
};

// Usage:
Passenger p1;  // Uses default constructor
Passenger p2("Ali", 25, "12345");  // Uses parameterized constructor
```

---

### **7. ABSTRACT CLASSES**
**Where:** Payment class

**How it works:**
- Contains pure virtual functions (= 0)
- Cannot be instantiated directly
- Forces derived classes to implement specific methods

**Example:**
```cpp
class Payment {
public:
    virtual bool processPayment() = 0;  // Pure virtual function
    virtual bool validatePayment() = 0;  // Pure virtual function
};

// Cannot do this:
// Payment p;  // ERROR: Cannot instantiate abstract class

// Must do this:
CreditCardPayment cc;  // OK: Derived class implements pure virtual functions
```

---

## 📊 DATA FLOW DIAGRAM

### **Complete System Data Flow:**

```
┌─────────────────────────────────────────────────────────────────┐
│                         USER INPUT                               │
│                    (Terminal Console)                            │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                         main.cpp                                 │
│  - Receives user input                                           │
│  - Validates input                                               │
│  - Routes to appropriate helper function                         │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      helpers.cpp                                 │
│  - viewAllFlights()                                              │
│  - searchFlightsByRoute()                                        │
│  - bookSeat()                                                    │
│  - cancelBooking()                                               │
│  - viewBookingDetails()                                          │
│  - displayFlightManifest()                                       │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Airline Object                              │
│  - Contains Flight flights[10]                                   │
│  - Methods: addFlight(), searchFlights(), findFlight()           │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Flight Objects                              │
│  - Contains Seat seats[50]                                       │
│  - Contains Booking bookings[50]                                 │
│  - Methods: setupSeats(), findAvailableSeat(), addBooking()      │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                   Seat & Booking Objects                         │
│  - Seat: seatNumber, seatClass, isAvailable                      │
│  - Booking: pnrNumber, Passenger, seatNumber                     │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Passenger Object                            │
│  - passengerName, passengerAge, passengerId                      │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Payment Objects                             │
│  - CreditCardPayment / CashPayment / PointsPayment               │
│  - Methods: processPayment(), validatePayment()                  │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      OUTPUT TO USER                              │
│  - Confirmation messages                                         │
│  - Formatted tickets                                             │
│  - Flight information                                            │
│  - Error messages                                                │
└─────────────────────────────────────────────────────────────────┘
```

---

## 🎯 SUMMARY

This Airline Reservation System demonstrates:

1. **Clean file organization** - Separate files for different concerns
2. **Proper OOP design** - Inheritance, polymorphism, encapsulation, composition
3. **Modular architecture** - Each class has a single responsibility
4. **Easy maintenance** - Changes to one class don't affect others
5. **Beginner-friendly code** - Simple syntax, extensive comments

**Key Takeaway:** The system uses composition to build complex structures (Airline → Flights → Seats/Bookings) and inheritance to create specialized behaviors (User → Admin/Customer, Payment → CreditCard/Cash/Points).

---

**END OF FLOW.MD**
