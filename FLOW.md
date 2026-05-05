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

The project follows a strict 4-file structure as per CLAUDE.md requirements:

```
OOP-PROJECT/
│
├── main.cpp          # Entry point - contains ONLY main() function and includes
├── classes.h         # ALL class definitions and implementations (13 classes)
├── helpers.h         # ALL helper functions for menus and operations
│
├── CLAUDE.md         # Project specification and rules
├── README.md         # Project documentation
└── FLOW.md           # This file - workflow explanation
```

**File Breakdown:**

**main.cpp** (133 lines)
- Contains ONLY: #include statements and main() function
- Creates the Airline object
- Loads sample data
- Runs the main menu loop
- Routes user choices to helper functions

**classes.h** (1603 lines)
- Contains ALL 13 class definitions and implementations
- Constants defined at the top (MAX_FLIGHTS, MAX_SEATS, etc.)
- All classes are fully implemented in this single file
- No separate .cpp files for classes

**helpers.h** (651 lines)
- Contains ALL helper functions
- Screen/menu functions (displayMainMenu, printSeparator, etc.)
- Input validation functions (readIntegerInput, isValidAge, etc.)
- Flight operation functions (viewAllFlights, bookSeat, etc.)
- OOP demonstration functions (demoUserHierarchy, demoPaymentMethods)

---

## 🏗️ CLASS HIERARCHY AND RELATIONSHIPS

### **ALL 13 CLASSES IN THE SYSTEM**

1. **Passenger** - Stores passenger information
2. **Seat** - Represents one airplane seat
3. **Booking** - Represents a booking transaction (has static PNR counter)
4. **Flight** - Represents a flight (contains Seats and Bookings)
5. **Airline** - Manages all flights (contains Flight array)
6. **User** - Base class for all system users
7. **Admin** - Derived from User (system administrator)
8. **Customer** - Derived from User (booking customer)
9. **Payment** - Base class for all payment methods
10. **OnlinePayment** - Derived from Payment (mid-level for online payments)
11. **CreditCardPayment** - Derived from OnlinePayment (multi-level inheritance)
12. **CashPayment** - Derived from Payment (cash transactions)
13. **LoyaltyPayment** - Derived from Payment (loyalty points, has friend function)

---

### **INHERITANCE HIERARCHIES**

#### **Hierarchy 1: User System (Single Inheritance)**
```
        User (BASE CLASS)
         /        \
        /          \
    Admin      Customer
  (DERIVED)    (DERIVED)
```

**Explanation:**
- `User` is the **base class** with protected members (userId, username, password, email, fullName, phoneNumber)
- `Admin` is a **derived class** that adds adminLevel and department
- `Customer` is a **derived class** that adds loyaltyPoints, membershipTier, and bookingHistory array

**Key OOP Concepts:**
- Single Inheritance (one base, one derived)
- Protected Members (accessible in derived classes)
- Virtual Functions (login, displayInfo)
- Polymorphism (User pointer can point to Admin or Customer)

---

#### **Hierarchy 2: Payment System (Multi-Level Inheritance)**
```
           Payment (BASE CLASS - Level 1)
              /       |        \
             /        |         \
    OnlinePayment   Cash      Loyalty
    (Level 2)     Payment    Payment
         |        (DERIVED)  (DERIVED)
         |
    CreditCard
     Payment
    (Level 3)
```

**Explanation:**
- `Payment` is the **base class** with virtual functions (processPayment, validatePayment, displayPaymentInfo)
- `OnlinePayment` inherits from Payment and adds transactionId and gatewayName
- `CreditCardPayment` inherits from OnlinePayment (3-level chain: Payment → OnlinePayment → CreditCardPayment)
- `CashPayment` inherits directly from Payment (2-level chain)
- `LoyaltyPayment` inherits directly from Payment and has a friend function

**Key OOP Concepts:**
- Multi-Level Inheritance (Payment → OnlinePayment → CreditCardPayment)
- Single Inheritance (Payment → CashPayment, Payment → LoyaltyPayment)
- Virtual Functions (overridden in each derived class)
- Polymorphism (Payment pointer can point to any payment type)
- Friend Function (showLoyaltyPointsUsed accesses private pointsUsed)

---

### **COMPOSITION RELATIONSHIPS**

#### **Composition 1: Airline contains Flights**
```
Airline
  └── Flight flights[MAX_FLIGHTS]  (array of 10 Flight objects)
```

**Explanation:**
- The `Airline` class **owns** an array of `Flight` objects
- MAX_FLIGHTS = 10 (defined in classes.h)
- When an Airline object is created, space for 10 Flight objects is allocated
- This is **composition** because Flights cannot exist without the Airline
- Airline has flightCount to track how many flights are actually in use

---

#### **Composition 2: Flight contains Seats and Bookings**
```
Flight
  ├── Seat seats[MAX_SEATS]        (array of 20 Seat objects)
  └── Booking bookings[MAX_BOOKINGS] (array of 20 Booking objects)
```

**Explanation:**
- The `Flight` class **owns** arrays of `Seat` and `Booking` objects
- MAX_SEATS = 20 (seats 1-14 are Economy, seats 15-20 are Business)
- MAX_BOOKINGS = 20 (maximum bookings per flight)
- When a Flight object is created, it automatically creates all 20 seats
- This is **composition** because Seats and Bookings belong to a specific Flight
- Flight has bookingCount to track active bookings

---

#### **Composition 3: Booking contains Passenger**
```
Booking
  └── Passenger passenger  (Passenger object)
```

**Explanation:**
- The `Booking` class **owns** a `Passenger` object
- Each booking is associated with exactly one passenger
- This is **composition** because the Passenger data is part of the Booking

---

#### **Composition 4: Customer contains Booking History**
```
Customer
  └── Booking bookingHistory[MAX_BOOKINGS]  (array of past bookings)
```

**Explanation:**
- The `Customer` class **owns** an array of `Booking` objects
- Stores the customer's booking history
- bookingHistoryCount tracks how many bookings are stored

---

### **STANDALONE CLASSES (No Inheritance)**

These classes do not inherit from any base class:

1. **Passenger** - Stores passenger details (name, age, ID)
   - Has constructor overloading (default + parameterized)
   - Has copy constructor
   - Demonstrates encapsulation with getters/setters

2. **Seat** - Represents one airplane seat
   - Has constructor overloading
   - Stores seatNumber, seatClass, isAvailable, basePrice

3. **Booking** - Represents a booking transaction
   - Has static member: bookingCounter (shared across all bookings)
   - Auto-generates unique PNR numbers (PNR001, PNR002, etc.)
   - Has operator overloading (== operator to compare bookings)

4. **Flight** - Represents a flight
   - Uses composition (contains Seat[] and Booking[])
   - Has copy constructor for safe copying
   - Manages seat availability and bookings

5. **Airline** - Top-level manager
   - Uses composition (contains Flight[])
   - Has static member: totalAirlinesCreated
   - Manages all flights in the system

---

## 🔗 HOW FILES CONNECT TO MAIN.CPP

### **Step-by-Step Connection Process:**

#### **Step 1: main.cpp includes header files**
```cpp
#include <iostream>   // for cout and cin
#include <string>     // for string data type
#include <cstring>    // for string utility functions
#include "classes.h"  // includes ALL 13 class definitions
#include "helpers.h"  // includes ALL helper functions
```

**What this does:**
- Brings in standard C++ libraries for input/output and strings
- Includes classes.h which contains all 13 class definitions and implementations
- Includes helpers.h which contains all menu and operation functions
- Allows main.cpp to create objects and call helper functions

---

#### **Step 2: classes.h provides all classes**

**classes.h contains (in order):**
1. Constants section (MAX_FLIGHTS, MAX_SEATS, MAX_BOOKINGS, ECONOMY_PRICE, BUSINESS_PRICE, ECONOMY_SEAT_LIMIT)
2. Class 1: Passenger (with copy constructor)
3. Class 2: Seat
4. Class 3: Booking (with static bookingCounter and operator==)
5. Class 4: Flight (with copy constructor, composition)
6. Class 5: Airline (with static totalAirlinesCreated)
7. Class 6: User (base class with virtual functions)
8. Class 7: Admin (derived from User)
9. Class 8: Customer (derived from User)
10. Class 9: Payment (base class with virtual functions)
11. Class 10: OnlinePayment (derived from Payment)
12. Class 11: CreditCardPayment (derived from OnlinePayment - multi-level)
13. Class 12: CashPayment (derived from Payment)
14. Class 13: LoyaltyPayment (derived from Payment, has friend function)
15. Friend function: showLoyaltyPointsUsed()

**Static member initializations:**
- `int Booking::bookingCounter = 0;`
- `int Airline::totalAirlinesCreated = 0;`

---

#### **Step 3: helpers.h provides all helper functions**

**helpers.h contains (in order):**

**Screen/Menu Functions:**
- `printSeparator()` - prints line of equal signs
- `printDivider()` - prints line of dashes
- `displayHeader(string)` - prints centered header
- `displayMainMenu()` - shows the main menu with 8 options
- `pauseScreen()` - waits for user to press Enter

**Input Validation Functions:**
- `clearInputBuffer()` - clears cin error state
- `readIntegerInput()` - reads and validates integer input
- `readLineInput()` - reads full line of text
- `isValidAge(int)` - validates age is between 1-149
- `isValidSeatClass(string)` - validates "economy" or "business"

**Flight Operation Functions:**
- `viewAllFlights(Airline&)` - displays all flights
- `searchFlightsByRoute(Airline&)` - searches by origin/destination
- `bookSeat(Airline&)` - handles complete booking process with payment
- `cancelBooking(Airline&)` - cancels a booking by PNR
- `viewBookingDetails(Airline&)` - displays ticket for a PNR
- `displayFlightManifest(Airline&)` - shows passenger list for a flight

**OOP Demonstration Functions:**
- `demoUserHierarchy()` - demonstrates User/Admin/Customer polymorphism
- `demoPaymentMethods()` - demonstrates Payment hierarchy polymorphism

---

#### **Step 4: Compilation links everything together**

When you compile with `g++ main.cpp -o airline`, the compiler:

1. Reads main.cpp
2. Follows #include "classes.h" and loads all 13 class definitions
3. Follows #include "helpers.h" and loads all helper function definitions
4. Compiles everything into one executable: `airline`

**Visual representation:**
```
main.cpp
   ↓ #include "classes.h"
classes.h (1603 lines)
   - Constants
   - 13 class definitions
   - All class implementations
   - Static member initializations
   ↓ #include "helpers.h"
helpers.h (651 lines)
   - Screen/menu functions
   - Input validation functions
   - Flight operation functions
   - OOP demo functions
   ↓ g++ compiler
airline (executable program)
```

---

## 🔄 COMPLETE PROGRAM WORKFLOW

### **Phase 1: Program Startup**

```
1. User runs: ./airline
2. main() function starts
3. Creates Airline object: Airline airline("Pakistan International Airlines", "PIA")
4. Calls airline.loadSampleData() to pre-load 3 sample flights:
   - PK-301: Lahore → Karachi (2026-06-01, 10:00-12:00, 18 seats)
   - PK-502: Islamabad → Dubai (2026-06-05, 14:00-17:30, 18 seats)
   - PK-786: Karachi → London (2026-06-10, 22:00-06:00, 18 seats)
5. Displays welcome message with airline name
6. Enters main menu loop (while keepRunning == true)
```

---

### **Phase 2: Main Menu Loop**

```
┌─────────────────────────────────────────────────────────┐
│  MAIN MENU LOOP (runs until user chooses 0 to exit)    │
├─────────────────────────────────────────────────────────┤
│  1. Display menu (displayMainMenu)                      │
│  2. Get user choice (cin >> menuChoice)                 │
│  3. Validate input (check cin.fail())                   │
│  4. Execute chosen operation (if/else chain)            │
│  5. Return to step 1 (unless menuChoice == 0)           │
└─────────────────────────────────────────────────────────┘
```

**Menu Options:**
```
1. View All Flights
2. Search Flights by Route
3. Book a Seat
4. Cancel a Booking
5. View Booking Details (Ticket)
6. View Passenger Manifest
7. Demo: User Hierarchy (OOP)
8. Demo: Payment Methods (OOP)
0. Exit
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
Airline loops through flights[] array (0 to flightCount-1)
   ↓
For each flight, calls flights[i].displayFlight()
   ↓
Flight displays:
   - Flight Number (e.g., PK-301)
   - Route (Lahore --> Karachi)
   - Date (2026-06-01)
   - Departure Time (10:00) and Arrival Time (12:00)
   - Total Seats (18) and Available Seats (e.g., 16)
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
Function prompts: "Enter origin city: "
   ↓
User types origin (e.g., "Lahore")
   ↓
Function prompts: "Enter destination city: "
   ↓
User types destination (e.g., "Karachi")
   ↓
Calls airline.searchFlights(origin, destination)
   ↓
Airline loops through flights[] array
   ↓
For each flight, compares:
   - flights[i].getOrigin() == origin
   - flights[i].getDestination() == destination
   ↓
If both match, calls flights[i].displayFlight()
   ↓
If no matches found, displays "No flights found from X to Y."
   ↓
Returns to main menu
```

---

#### **Operation 3: Book a Seat (Most Complex - 8 Steps)**
```
User selects option 3
   ↓
main() calls bookSeat(airline)
   ↓
STEP 1: Get Flight Number
   - Prompts: "Enter flight number (e.g. PK-301): "
   - User types flight number
   - Calls airline.findFlight(flightNumber)
   - If not found (-1), shows error and exits
   ↓
STEP 2: Display Selected Flight
   - Calls airline.getFlightAt(position).displayFlight()
   - Shows flight details to user
   ↓
STEP 3: Get Passenger Information
   - Prompts: "Enter passenger full name: "
   - Reads full name with getline()
   - Prompts: "Enter passenger age: "
   - Reads age with readIntegerInput()
   - Validates age with isValidAge() (1-149)
   - Prompts: "Enter passenger ID / Passport: "
   - Reads ID with getline()
   ↓
STEP 4: Get Seat Class Preference
   - Prompts: "Enter seat class (economy / business): "
   - Reads class with getline()
   - Validates with isValidSeatClass()
   - Must be exactly "economy" or "business"
   ↓
STEP 5: Set Price Based on Class
   - If "economy": ticketPrice = ECONOMY_PRICE (5000.0)
   - If "business": ticketPrice = BUSINESS_PRICE (12000.0)
   ↓
STEP 6: Get Payment Method Choice
   - Displays payment menu:
     1. Credit Card
     2. Cash
     3. Loyalty Points
   - Reads choice (1-3)
   - Validates choice is 1, 2, or 3
   ↓
STEP 7: Collect Payment Details and Process
   
   IF Credit Card (choice == 1):
      - Prompts: "Enter card number: "
      - Prompts: "Enter card holder name: "
      - Prompts: "Enter expiry (MM/YY): "
      - Creates CreditCardPayment object
      - Calls validatePayment() (checks card details not empty)
      - If valid, calls processPayment()
      - Shows: "Credit card payment of Rs.X charged to card Y."
   
   IF Cash (choice == 2):
      - Sets cashAmount = ticketPrice + 500.0 (customer pays extra)
      - Sets changeBack = 500.0
      - Creates CashPayment object
      - Calls validatePayment() (checks cashAmount >= ticketPrice)
      - If valid, calls processPayment()
      - Shows: "Cash payment of Rs.X received."
      - Shows: "Change returned: Rs.500."
   
   IF Loyalty Points (choice == 3):
      - Prompts: "Enter membership ID: "
      - Prompts: "Enter points to use: "
      - Validates points >= 0
      - Sets conversionRate = 0.1 (each point = Rs.0.10)
      - Creates LoyaltyPayment object
      - Calls validatePayment() (checks points * rate >= amount)
      - If valid, calls processPayment()
      - Shows: "X loyalty points redeemed. Payment of Rs.Y covered."
   
   If payment fails, shows error and exits without booking
   ↓
STEP 8: Find Available Seat and Create Booking
   - Converts "economy" → "Economy", "business" → "Business"
   - Calls selectedFlight.findAvailableSeat(capitalizedClass)
   - Loops through seats[] array to find first available seat of that class
   - If no seat available (-1), shows error and exits
   - Creates Passenger object: Passenger(name, age, id)
   - Creates Booking object: Booking(passenger, flightNum, seatNum, class, price)
   - Booking constructor auto-generates PNR (increments static bookingCounter)
   - Calls selectedFlight.addBooking(booking)
   - Flight marks seat as unavailable
   - Flight decrements availableSeats counter
   - Displays confirmation:
     * PNR Number (e.g., PNR001)
     * Seat Number (e.g., 5)
     * Seat Class (Economy or Business)
     * Amount Paid (Rs.5000 or Rs.12000)
     * "SAVE YOUR PNR NUMBER FOR FUTURE USE!"
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
Function prompts: "Enter your PNR number: "
   ↓
User types PNR (e.g., "PNR001")
   ↓
Function prompts: "Enter your flight number: "
   ↓
User types flight number (e.g., "PK-301")
   ↓
Calls airline.findFlight(flightNumber)
   ↓
If flight not found, shows error and exits
   ↓
Calls airline.getFlightAt(position).cancelBooking(pnr)
   ↓
Flight searches bookings[] array for matching PNR
   ↓
For each booking (0 to bookingCount-1):
   - Compares bookings[i].getPnr() == pnrToCancel
   - If match found:
     * Gets seat number from booking
     * Marks seat as available again (setIsAvailable(true))
     * Increments availableSeats counter
     * Sets booking status to "Cancelled"
     * Returns true
   ↓
If cancelled successfully:
   - Displays: "PNR X has been cancelled."
   - Displays: "The seat has been released for other passengers."
   ↓
If PNR not found:
   - Displays: "No active booking found with PNR X on flight Y."
   ↓
Returns to main menu
```

---

#### **Operation 5: View Booking Details (Ticket)**
```
User selects option 5
   ↓
main() calls viewBookingDetails(airline)
   ↓
Function prompts: "Enter your PNR number: "
   ↓
User types PNR (e.g., "PNR001")
   ↓
Loops through all flights (0 to airline.getFlightCount()-1)
   ↓
For each flight, loops through bookings (0 to flight.getBookingCount()-1)
   ↓
For each booking:
   - Gets currentPnr = booking.getPnr()
   - Gets status = booking.getStatus()
   - Checks if (currentPnr == searchPnr) AND (status != "Cancelled")
   - If match found:
     * Calls booking.printTicket()
     * Displays formatted boarding pass:
       +------------------------------------------+
       |          BOARDING PASS / TICKET          |
       +------------------------------------------+
       |  PNR Number   : PNR001                   |
       |  Passenger    : Ali Ahmed                |
       |  Age          : 25                       |
       |  ID Number    : 12345-6789012-3          |
       |  Flight       : PK-301                   |
       |  Date         : 2026-05-05               |
       |  Seat Number  : 5                        |
       |  Seat Class   : Economy                  |
       |  Amount Paid  : Rs.5000                  |
       |  Status       : Confirmed                |
       +------------------------------------------+
       |         HAVE A PLEASANT JOURNEY          |
       +------------------------------------------+
     * Breaks out of loops (booking found)
   ↓
If no active booking found with that PNR:
   - Displays: "No active booking found with PNR X."
   ↓
Returns to main menu
```

---

#### **Operation 6: View Passenger Manifest**
```
User selects option 6
   ↓
main() calls displayFlightManifest(airline)
   ↓
Function prompts: "Enter flight number: "
   ↓
User types flight number (e.g., "PK-301")
   ↓
Calls airline.findFlight(flightNumber)
   ↓
If flight not found, shows error and exits
   ↓
Calls airline.getFlightAt(position).displayManifest()
   ↓
Flight displays header: "PASSENGER MANIFEST - Flight PK-301"
   ↓
Loops through bookings[] array (0 to bookingCount-1)
   ↓
For each booking:
   - Gets status = bookings[i].getStatus()
   - If status != "Cancelled" (only show active bookings):
     * Gets passenger = bookings[i].getPassenger()
     * Displays: "1. Name: Ali Ahmed | Seat: 5 | Class: Economy | PNR: PNR001"
     * Increments display number
   ↓
If no active bookings found:
   - Displays: "No passengers are currently booked on this flight."
   ↓
Returns to main menu
```

---

#### **Operation 7: Demo User Hierarchy (OOP Demonstration)**
```
User selects option 7
   ↓
main() calls demoUserHierarchy()
   ↓
Creates Admin object:
   - Admin("A001", "admin_ali", "pass123", "ali@airline.com",
           "Ali Hassan", "0300-1234567", "SuperAdmin", "Operations")
   ↓
Creates Customer object:
   - Customer("C001", "sara_khan", "sara456", "sara@email.com",
              "Sara Khan", "0311-9876543")
   ↓
Demonstrates Polymorphism with Admin:
   - Creates User pointer: User* userPointer = &adminUser
   - Calls userPointer->displayInfo()
   - At runtime, calls Admin::displayInfo() (polymorphism)
   - Shows admin details including role, level, department
   ↓
Demonstrates Polymorphism with Customer:
   - Points userPointer to customerUser
   - Calls userPointer->displayInfo()
   - At runtime, calls Customer::displayInfo() (polymorphism)
   - Shows customer details including loyalty points, tier
   ↓
Demonstrates Login Method:
   - Calls adminUser.login("admin_ali", "pass123")
   - Shows: "Admin access granted to Ali Hassan."
   - Calls customerUser.login("sara_khan", "sara456")
   - Shows: "Welcome back, Sara Khan! Tier: Bronze"
   ↓
Displays OOP concepts shown:
   - "Inheritance, Polymorphism, Virtual Functions,"
   - "Protected Members, Method Overriding."
   ↓
Returns to main menu
```

---

#### **Operation 8: Demo Payment Methods (OOP Demonstration)**
```
User selects option 8
   ↓
main() calls demoPaymentMethods()
   ↓
Creates CreditCardPayment object (multi-level inheritance):
   - CreditCardPayment("PAY-CC-001", 15000.0, "2026-05-05", "Pending",
                       "TXN-CC-999", "BankGateway",
                       "1234-5678-9012-3456", "Ali Ahmed", "12/28", "123")
   ↓
Creates CashPayment object:
   - CashPayment("PAY-CASH-001", 8000.0, "2026-05-05", "Pending",
                 8500.0, 500.0)
   ↓
Creates LoyaltyPayment object:
   - LoyaltyPayment("PAY-PTS-001", 10000.0, "2026-05-05", "Pending",
                    120000, "MEM-12345", 0.1)
   ↓
Testing Credit Card Payment:
   - Creates Payment pointer: Payment* paymentPointer = &creditCardPayment
   - Calls paymentPointer->displayPaymentInfo()
   - Shows: "--- Credit Card Payment ---"
   - Shows: Payment ID, Amount, Date, Status, Transaction ID, Gateway, Card details
   - Calls paymentPointer->validatePayment()
   - Calls paymentPointer->processPayment()
   - Shows: "Credit card payment of Rs.15000 charged to card 1234-5678-9012-3456."
   ↓
Testing Cash Payment:
   - Points paymentPointer to cashPayment
   - Calls paymentPointer->displayPaymentInfo()
   - Shows: "--- Cash Payment ---"
   - Shows: Cash Received (Rs.8500), Change Given (Rs.500)
   - Calls validatePayment() and processPayment()
   - Shows: "Cash payment of Rs.8000 received."
   - Shows: "Change returned: Rs.500."
   ↓
Testing Loyalty Points Payment:
   - Points paymentPointer to loyaltyPayment
   - Calls paymentPointer->displayPaymentInfo()
   - Shows: "--- Loyalty Points Payment ---"
   - Shows: Points Used (120000), Membership ID, Rate (Rs.0.1 per point)
   - Calls validatePayment() and processPayment()
   - Shows: "120000 loyalty points redeemed. Payment of Rs.10000 covered."
   ↓
Demonstrates Friend Function:
   - Calls showLoyaltyPointsUsed(loyaltyPayment)
   - Friend function accesses private member pointsUsed
   - Shows: "Friend function sees: 120000 points were used."
   ↓
Displays OOP concepts shown:
   - "Polymorphism, Multi-level Inheritance,"
   - "Virtual Functions, Friend Functions."
   ↓
Returns to main menu
```

---

## 🎓 OOP CONCEPTS IMPLEMENTATION

### **1. ENCAPSULATION**
**Where:** All 13 classes

**How it works:**
- All data members are declared `private` or `protected`
- Public getter methods provide read access
- Public setter methods provide write access with validation
- Direct access to data from outside the class is prevented

**Example from Passenger class:**
```cpp
class Passenger {
private:
    string passengerName;  // Cannot be accessed directly from outside
    int    passengerAge;   // Cannot be accessed directly from outside
    string passengerId;    // Cannot be accessed directly from outside
    
public:
    // Getter - provides controlled read access
    string getName() { return passengerName; }
    
    // Setter - provides controlled write access with validation
    void setName(string name) {
        if (name == "") {
            cout << "Error: Passenger name cannot be empty." << endl;
        } else {
            passengerName = name;
        }
    }
};
```

**Benefits:**
- Data is protected from invalid modifications
- Internal implementation can change without affecting external code
- Validation logic is centralized in setter methods

---

### **2. CONSTRUCTOR OVERLOADING**
**Where:** Passenger, Seat, Booking, Flight, Airline, User, Admin, Customer, Payment classes

**How it works:**
- Multiple constructors with different parameter lists
- Allows object creation with different initialization options
- Compiler chooses the right constructor based on arguments provided

**Example from Passenger class:**
```cpp
class Passenger {
public:
    // Constructor 1 - Default constructor (no parameters)
    Passenger() {
        passengerName = "Unknown";
        passengerAge  = 0;
        passengerId   = "N/A";
    }
    
    // Constructor 2 - Parameterized constructor (3 parameters)
    Passenger(string name, int age, string id) {
        passengerName = name;
        passengerAge  = age;
        passengerId   = id;
    }
};

// Usage:
Passenger p1;                          // Uses default constructor
Passenger p2("Ali Ahmed", 25, "12345"); // Uses parameterized constructor
```

---

### **3. COPY CONSTRUCTOR**
**Where:** Passenger class, Flight class

**How it works:**
- Special constructor that creates a new object as a copy of an existing object
- Takes a reference to another object of the same class as parameter
- Performs deep copy of all member variables

**Example from Passenger class:**
```cpp
class Passenger {
public:
    // Copy Constructor - creates exact copy of another Passenger
    Passenger(const Passenger& other) {
        passengerName = other.passengerName;  // Copies name
        passengerAge  = other.passengerAge;   // Copies age
        passengerId   = other.passengerId;    // Copies ID
    }
};

// Usage:
Passenger original("Ali", 25, "12345");
Passenger copy(original);  // Creates a copy using copy constructor
```

**Why needed:**
- Ensures safe copying when passing objects by value
- Prevents shallow copy issues with complex objects
- Required by CLAUDE.md to demonstrate the concept

---

### **4. STATIC MEMBERS**
**Where:** Booking class (bookingCounter), Airline class (totalAirlinesCreated)

**How it works:**
- Static member is shared by ALL objects of the class
- Only one copy exists in memory (not per-object)
- Accessed using class name or through any object
- Must be initialized outside the class definition

**Example from Booking class:**
```cpp
class Booking {
private:
    static int bookingCounter;  // Shared by all Booking objects
    string pnrNumber;
    
public:
    Booking(...) {
        bookingCounter = bookingCounter + 1;  // Increments shared counter
        
        // Generate unique PNR using the counter
        if (bookingCounter < 10) {
            pnrNumber = "PNR00" + to_string(bookingCounter);
        } else if (bookingCounter < 100) {
            pnrNumber = "PNR0" + to_string(bookingCounter);
        } else {
            pnrNumber = "PNR" + to_string(bookingCounter);
        }
    }
    
    static int getBookingCounter() {
        return bookingCounter;  // Static method to access static member
    }
};

// Initialize static member outside class (required)
int Booking::bookingCounter = 0;

// Usage:
Booking b1(...);  // bookingCounter becomes 1, PNR = "PNR001"
Booking b2(...);  // bookingCounter becomes 2, PNR = "PNR002"
Booking b3(...);  // bookingCounter becomes 3, PNR = "PNR003"
```

**Benefits:**
- Generates unique PNR numbers across all bookings
- Tracks total number of bookings created
- Saves memory (one counter instead of one per object)

---

### **5. ARRAYS OF OBJECTS**
**Where:** Flight (contains Seat[] and Booking[]), Airline (contains Flight[]), Customer (contains Booking[])

**How it works:**
- Fixed-size arrays of class objects declared as member variables
- All objects in the array are created when the parent object is created
- Demonstrates composition (parent owns the child objects)

**Example from Flight class:**
```cpp
class Flight {
private:
    Seat    seats[MAX_SEATS];      // Array of 20 Seat objects
    Booking bookings[MAX_BOOKINGS]; // Array of 20 Booking objects
    int     bookingCount;           // Tracks how many bookings are active
    
public:
    Flight(...) {
        // Initialize all 20 seats when Flight is created
        for (int i = 0; i < MAX_SEATS; i++) {
            seats[i].setSeatNumber(i + 1);
            if (i < ECONOMY_SEAT_LIMIT) {
                seats[i].setSeatClass("Economy");
                seats[i].setBasePrice(ECONOMY_PRICE);
            } else {
                seats[i].setSeatClass("Business");
                seats[i].setBasePrice(BUSINESS_PRICE);
            }
            seats[i].setIsAvailable(true);
        }
        bookingCount = 0;  // No bookings initially
    }
};
```

**Benefits:**
- No dynamic memory allocation needed (no new/delete)
- All seats and bookings belong to the flight
- Simple memory management (automatic cleanup)

---

### **6. SINGLE INHERITANCE**
**Where:** User → Admin, User → Customer, Payment → CashPayment, Payment → LoyaltyPayment

**How it works:**
- Derived class inherits from one base class
- Derived class gets all public and protected members of base class
- Derived class can add new members and override base class methods
- Uses `public` inheritance to maintain access levels

**Example from User hierarchy:**
```cpp
// Base class
class User {
protected:  // Protected so derived classes can access
    string userId;
    string username;
    string password;
    string email;
    string fullName;
    string phoneNumber;
    
public:
    User(string id, string uname, string pass, string mail, string name, string phone) {
        userId      = id;
        username    = uname;
        password    = pass;
        email       = mail;
        fullName    = name;
        phoneNumber = phone;
    }
    
    virtual void displayInfo() {  // Virtual function (can be overridden)
        cout << "User ID   : " << userId   << endl;
        cout << "Username  : " << username << endl;
        cout << "Full Name : " << fullName << endl;
    }
};

// Derived class
class Admin : public User {  // Admin IS-A User (single inheritance)
private:
    string adminLevel;   // Admin-specific member
    string department;   // Admin-specific member
    
public:
    // Constructor calls base class constructor first
    Admin(string id, string uname, string pass, string mail, string name, string phone,
          string level, string dept)
          : User(id, uname, pass, mail, name, phone)  // Calls User constructor
    {
        adminLevel = level;
        department = dept;
    }
    
    // Override base class method
    void displayInfo() {
        User::displayInfo();  // Calls base class version first
        cout << "Role       : Admin"      << endl;
        cout << "Level      : " << adminLevel << endl;
        cout << "Department : " << department << endl;
    }
};
```

**Benefits:**
- Code reuse (Admin and Customer share User's code)
- Logical hierarchy (Admin IS-A User, Customer IS-A User)
- Polymorphism (User pointer can point to Admin or Customer)

---

### **7. MULTI-LEVEL INHERITANCE**
**Where:** Payment → OnlinePayment → CreditCardPayment (3-level chain)

**How it works:**
- Class B inherits from Class A
- Class C inherits from Class B
- Class C gets members from both A and B
- Each level adds its own specialized functionality

**Example from Payment hierarchy:**
```cpp
// Level 1: Base class
class Payment {
protected:
    string paymentId;
    double amount;
    string paymentDate;
    string paymentStatus;
    
public:
    Payment(string id, double amt, string date, string status) {
        paymentId     = id;
        amount        = amt;
        paymentDate   = date;
        paymentStatus = status;
    }
    
    virtual bool processPayment() {
        paymentStatus = "Completed";
        cout << "Payment of Rs." << amount << " processed." << endl;
        return true;
    }
};

// Level 2: Inherits from Payment
class OnlinePayment : public Payment {
protected:
    string transactionId;
    string gatewayName;
    
public:
    OnlinePayment(string id, double amt, string date, string status,
                  string transId, string gateway)
                  : Payment(id, amt, date, status)  // Calls Payment constructor
    {
        transactionId = transId;
        gatewayName   = gateway;
    }
};

// Level 3: Inherits from OnlinePayment (which inherits from Payment)
class CreditCardPayment : public OnlinePayment {
private:
    string cardNumber;
    string cardHolderName;
    string expiryDate;
    string cvv;
    
public:
    CreditCardPayment(string id, double amt, string date, string status,
                      string transId, string gateway,
                      string cardNum, string holderName, string expiry, string cvvCode)
                      : OnlinePayment(id, amt, date, status, transId, gateway)
    {
        cardNumber     = cardNum;
        cardHolderName = holderName;
        expiryDate     = expiry;
        cvv            = cvvCode;
    }
    
    // CreditCardPayment has access to:
    // - Payment members (paymentId, amount, paymentDate, paymentStatus)
    // - OnlinePayment members (transactionId, gatewayName)
    // - Its own members (cardNumber, cardHolderName, expiryDate, cvv)
};
```

**Benefits:**
- Logical progression (Payment → Online → CreditCard)
- Each level adds specific functionality
- Demonstrates 3-level inheritance chain as required by CLAUDE.md

---

### **8. PROTECTED MEMBERS**
**Where:** User base class, Payment base class, OnlinePayment class

**How it works:**
- Protected members are accessible in the class itself AND in derived classes
- Protected members are NOT accessible from outside the class hierarchy
- More restrictive than public, less restrictive than private

**Example:**
```cpp
class User {
protected:  // Protected members
    string userId;
    string username;
    string password;
    
public:
    User(...) { ... }
};

class Admin : public User {
public:
    void someMethod() {
        // Can access protected members from base class
        cout << userId << endl;    // OK - userId is protected in User
        cout << username << endl;  // OK - username is protected in User
    }
};

// Outside the class hierarchy:
Admin admin(...);
// admin.userId;  // ERROR - cannot access protected member from outside
```

**Benefits:**
- Derived classes can access base class data directly
- Still maintains encapsulation from external code
- Allows derived classes to work with base class internals

---

### **9. POLYMORPHISM (Virtual Functions)**
**Where:** User hierarchy (displayInfo, login), Payment hierarchy (processPayment, validatePayment, displayPaymentInfo)

**How it works:**
- Base class declares functions as `virtual`
- Derived classes override these virtual functions
- Base class pointer can point to derived class objects
- At runtime, the correct derived class function is called (dynamic binding)

**Example from User hierarchy:**
```cpp
// Create objects
Admin adminUser("A001", "admin_ali", "pass123", "ali@airline.com",
                "Ali Hassan", "0300-1234567", "SuperAdmin", "Operations");

Customer customerUser("C001", "sara_khan", "sara456", "sara@email.com",
                      "Sara Khan", "0311-9876543");

// Polymorphism demonstration
User* userPointer = nullptr;  // Base class pointer

userPointer = &adminUser;      // Points to Admin object
userPointer->displayInfo();    // Calls Admin::displayInfo() at runtime

userPointer = &customerUser;   // Points to Customer object
userPointer->displayInfo();    // Calls Customer::displayInfo() at runtime
```

**What happens:**
1. Compiler sees `userPointer->displayInfo()`
2. Checks that displayInfo() is virtual in User class
3. At runtime, looks at actual object type (Admin or Customer)
4. Calls the appropriate version (Admin::displayInfo or Customer::displayInfo)

**Benefits:**
- Same interface, different behavior
- Write generic code that works with any derived class
- Add new derived classes without changing existing code

---

### **10. OPERATOR OVERLOADING**
**Where:** Booking class (== operator)

**How it works:**
- Redefines the behavior of operators for class objects
- Allows natural syntax for comparing or manipulating objects
- Operator function can be member or non-member

**Example from Booking class:**
```cpp
class Booking {
private:
    string pnr;
    // ... other members
    
public:
    // Overload == operator to compare bookings by PNR
    bool operator==(const Booking& other) {
        bool samePnr = (pnr == other.pnr);
        return samePnr;
    }
};

// Usage:
Booking booking1(...);
Booking booking2(...);

if (booking1 == booking2) {  // Uses overloaded == operator
    cout << "Same booking" << endl;
}
```

**Benefits:**
- Natural syntax for comparing bookings
- Makes code more readable
- Demonstrates operator overloading concept

---

### **11. FRIEND FUNCTIONS**
**Where:** LoyaltyPayment class (showLoyaltyPointsUsed function)

**How it works:**
- Friend function is declared inside the class with `friend` keyword
- Friend function is NOT a member of the class
- Friend function can access private and protected members of the class
- Defined outside the class without `friend` keyword

**Example from LoyaltyPayment class:**
```cpp
class LoyaltyPayment : public Payment {
private:
    int pointsUsed;  // Private member
    
    // Friend function declaration
    friend void showLoyaltyPointsUsed(LoyaltyPayment& payment);
    
public:
    // ... constructors and methods
};

// Friend function definition (outside class, no "friend" keyword)
void showLoyaltyPointsUsed(LoyaltyPayment& payment) {
    // Can access private member pointsUsed
    cout << "Friend function sees: " << payment.pointsUsed << " points were used." << endl;
}

// Usage:
LoyaltyPayment loyaltyPayment(...);
showLoyaltyPointsUsed(loyaltyPayment);  // Calls friend function
```

**Why needed:**
- Sometimes external functions need access to private data
- Maintains encapsulation while allowing specific access
- Demonstrates friend function concept required by CLAUDE.md

---

### **12. COMPOSITION**
**Where:** Airline contains Flight[], Flight contains Seat[] and Booking[], Booking contains Passenger, Customer contains Booking[]

**How it works:**
- Parent class contains child objects as member variables (not pointers)
- Child objects are created when parent is created
- Child objects are destroyed when parent is destroyed
- Strong ownership relationship (child cannot exist without parent)

**Example:**
```cpp
class Flight {
private:
    Seat    seats[MAX_SEATS];      // Flight OWNS 20 Seat objects
    Booking bookings[MAX_BOOKINGS]; // Flight OWNS 20 Booking objects
};

class Airline {
private:
    Flight flights[MAX_FLIGHTS];   // Airline OWNS 10 Flight objects
};
```

**Relationship diagram:**
```
Airline
  └── owns Flight[10]
        └── owns Seat[20]
        └── owns Booking[20]
              └── owns Passenger
```

**Benefits:**
- Clear ownership hierarchy
- Automatic memory management (no new/delete needed)
- Logical structure (Airline has Flights, Flight has Seats)

---

### **13. VIRTUAL DESTRUCTOR**
**Where:** User class, Payment class

**How it works:**
- Destructor declared as `virtual` in base class
- Ensures derived class destructors are called when deleting through base class pointer
- Prevents memory leaks and ensures proper cleanup

**Example:**
```cpp
class User {
public:
    virtual ~User() {
        // Cleanup code for User
    }
};

class Admin : public User {
public:
    ~Admin() {
        // Cleanup code for Admin
        // User destructor will be called automatically after this
    }
};

// Usage:
User* userPtr = new Admin(...);
delete userPtr;  // Calls Admin destructor, then User destructor (because virtual)
```

**Why needed:**
- Without virtual destructor, only base class destructor would be called
- With virtual destructor, both derived and base destructors are called
- Ensures complete cleanup of derived class resources

---

## 📊 DATA FLOW DIAGRAM

### **Complete System Data Flow:**

```
┌─────────────────────────────────────────────────────────────────┐
│                         USER INPUT                               │
│                    (Terminal Console)                            │
│  User types menu choice, flight numbers, passenger details, etc. │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                         main.cpp                                 │
│  - Receives user input via cin                                   │
│  - Validates input (checks cin.fail())                           │
│  - Routes to appropriate helper function based on menuChoice     │
│  - Passes airline object by reference to helper functions        │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      helpers.h Functions                         │
│  - viewAllFlights(airline)                                       │
│  - searchFlightsByRoute(airline)                                 │
│  - bookSeat(airline)                                             │
│  - cancelBooking(airline)                                        │
│  - viewBookingDetails(airline)                                   │
│  - displayFlightManifest(airline)                                │
│  - demoUserHierarchy()                                           │
│  - demoPaymentMethods()                                          │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Airline Object                              │
│  - Contains: Flight flights[MAX_FLIGHTS] (10 flights)            │
│  - Contains: flightCount (tracks active flights)                 │
│  - Methods:                                                      │
│    * addFlight(Flight)                                           │
│    * findFlight(string flightNumber) → returns index             │
│    * searchFlights(string from, string to)                       │
│    * displayAllFlights()                                         │
│    * getFlightAt(int index) → returns Flight reference           │
│    * loadSampleData() → adds 3 pre-built flights                 │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Flight Objects                              │
│  - Contains: Seat seats[MAX_SEATS] (20 seats)                    │
│  - Contains: Booking bookings[MAX_BOOKINGS] (20 bookings)        │
│  - Contains: bookingCount (tracks active bookings)               │
│  - Methods:                                                      │
│    * findAvailableSeat(string seatClass) → returns seat number   │
│    * addBooking(Booking) → marks seat unavailable                │
│    * cancelBooking(string pnr) → marks seat available            │
│    * displayFlight() → shows flight details                      │
│    * displayManifest() → shows passenger list                    │
│    * getBookingAt(int index) → returns Booking                   │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                   Seat & Booking Objects                         │
│                                                                  │
│  Seat:                                                           │
│  - seatNumber (1-20)                                             │
│  - seatClass (Economy: 1-14, Business: 15-20)                    │
│  - isAvailable (true/false)                                      │
│  - basePrice (Rs.5000 for Economy, Rs.12000 for Business)        │
│                                                                  │
│  Booking:                                                        │
│  - pnr (auto-generated: PNR001, PNR002, etc.)                    │
│  - passenger (Passenger object)                                  │
│  - flightNumber (e.g., PK-301)                                   │
│  - seatNumber (1-20)                                             │
│  - seatClass (Economy or Business)                               │
│  - amountPaid (Rs.5000 or Rs.12000)                              │
│  - bookingDate (2026-05-05)                                      │
│  - status (Confirmed or Cancelled)                               │
│  - static bookingCounter (shared across all bookings)            │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Passenger Object                            │
│  - passengerName (full name)                                     │
│  - passengerAge (1-149)                                          │
│  - passengerId (ID or passport number)                           │
│  - Methods: getName(), getAge(), getId()                         │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      Payment Objects                             │
│  (Polymorphism - Payment pointer can point to any type)          │
│                                                                  │
│  CreditCardPayment (Multi-level: Payment→OnlinePayment→CC):      │
│  - Validates: card number, holder name, expiry date not empty   │
│  - Processes: charges card and shows confirmation               │
│                                                                  │
│  CashPayment (Payment→Cash):                                     │
│  - Validates: cashReceived >= amount                             │
│  - Processes: accepts cash and calculates change                │
│                                                                  │
│  LoyaltyPayment (Payment→Loyalty):                               │
│  - Validates: pointsUsed * conversionRate >= amount             │
│  - Processes: deducts points and confirms payment               │
│  - Has friend function: showLoyaltyPointsUsed()                 │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      User Objects (OOP Demo)                     │
│  (Polymorphism - User pointer can point to Admin or Customer)    │
│                                                                  │
│  Admin (User→Admin):                                             │
│  - Inherits: userId, username, password, email, fullName, phone │
│  - Adds: adminLevel, department                                 │
│  - Overrides: displayInfo(), login()                            │
│                                                                  │
│  Customer (User→Customer):                                       │
│  - Inherits: userId, username, password, email, fullName, phone │
│  - Adds: loyaltyPoints, membershipTier, bookingHistory[]        │
│  - Overrides: displayInfo(), login()                            │
└────────────────────────────┬────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      OUTPUT TO USER                              │
│  - Confirmation messages (booking confirmed, cancelled, etc.)    │
│  - Formatted tickets (boarding pass with box borders)            │
│  - Flight information (number, route, date, times, seats)        │
│  - Passenger manifests (list of passengers on a flight)          │
│  - Error messages (flight not found, invalid input, etc.)        │
│  - Payment confirmations (amount charged, change given, etc.)    │
│  - OOP demonstrations (polymorphism examples)                    │
└─────────────────────────────────────────────────────────────────┘
```

---

### **Detailed Booking Flow (Step-by-Step Data Movement):**

```
1. USER TYPES: "3" (Book a Seat)
   ↓
2. main.cpp: menuChoice = 3
   ↓
3. main.cpp: calls bookSeat(airline)
   ↓
4. helpers.h: bookSeat() function starts
   ↓
5. USER TYPES: "PK-301" (flight number)
   ↓
6. bookSeat(): calls airline.findFlight("PK-301")
   ↓
7. Airline: loops through flights[], finds match at index 0
   ↓
8. Airline: returns 0 (flight found)
   ↓
9. bookSeat(): calls airline.getFlightAt(0).displayFlight()
   ↓
10. Flight: displays flight details to screen
   ↓
11. USER TYPES: "Ali Ahmed" (passenger name)
   ↓
12. USER TYPES: 25 (passenger age)
   ↓
13. bookSeat(): validates age with isValidAge(25) → true
   ↓
14. USER TYPES: "12345-6789012-3" (passenger ID)
   ↓
15. USER TYPES: "economy" (seat class)
   ↓
16. bookSeat(): validates with isValidSeatClass("economy") → true
   ↓
17. bookSeat(): sets ticketPrice = ECONOMY_PRICE (5000.0)
   ↓
18. USER TYPES: "1" (credit card payment)
   ↓
19. USER TYPES: card details (number, holder, expiry)
   ↓
20. bookSeat(): creates CreditCardPayment object
   ↓
21. bookSeat(): calls creditCardPayment.validatePayment()
   ↓
22. CreditCardPayment: checks card details not empty → true
   ↓
23. bookSeat(): calls creditCardPayment.processPayment()
   ↓
24. CreditCardPayment: sets status to "Completed"
   ↓
25. CreditCardPayment: displays "Credit card payment of Rs.5000 charged..."
   ↓
26. bookSeat(): converts "economy" → "Economy"
   ↓
27. bookSeat(): calls selectedFlight.findAvailableSeat("Economy")
   ↓
28. Flight: loops through seats[], finds first available Economy seat
   ↓
29. Flight: returns seat number 5 (for example)
   ↓
30. bookSeat(): creates Passenger object: Passenger("Ali Ahmed", 25, "12345...")
   ↓
31. bookSeat(): creates Booking object: Booking(passenger, "PK-301", 5, "Economy", 5000.0)
   ↓
32. Booking constructor: increments static bookingCounter (0 → 1)
   ↓
33. Booking constructor: generates PNR = "PNR001"
   ↓
34. bookSeat(): calls selectedFlight.addBooking(booking)
   ↓
35. Flight: stores booking in bookings[0]
   ↓
36. Flight: increments bookingCount (0 → 1)
   ↓
37. Flight: marks seats[4].setIsAvailable(false) (seat 5 = index 4)
   ↓
38. Flight: decrements availableSeats (18 → 17)
   ↓
39. Flight: returns true (booking added successfully)
   ↓
40. bookSeat(): displays confirmation with PNR001, seat 5, Rs.5000
   ↓
41. bookSeat(): returns to main()
   ↓
42. main(): continues menu loop
```

---

## 🎯 SUMMARY

This Airline Reservation System demonstrates:

**1. Clean File Organization (CLAUDE.md Compliant)**
- Exactly 4 files: main.cpp, classes.h, helpers.h, README.md
- main.cpp contains ONLY main() function and includes
- classes.h contains ALL 13 class definitions and implementations
- helpers.h contains ALL helper functions (menu, validation, operations)
- No additional .cpp or .h files beyond the required structure

**2. Complete OOP Concept Coverage**
- ✅ Encapsulation (all 13 classes with private data + public getters/setters)
- ✅ Constructor Overloading (default + parameterized in multiple classes)
- ✅ Copy Constructor (Passenger, Flight)
- ✅ Arrays of Objects (Flight[], Seat[], Booking[])
- ✅ Static Members (Booking::bookingCounter, Airline::totalAirlinesCreated)
- ✅ Single Inheritance (User→Admin, User→Customer, Payment→Cash, Payment→Loyalty)
- ✅ Multi-Level Inheritance (Payment→OnlinePayment→CreditCardPayment)
- ✅ Protected Members (User base class, OnlinePayment class)
- ✅ Polymorphism (virtual functions in User and Payment hierarchies)
- ✅ Operator Overloading (Booking == operator)
- ✅ Friend Functions (showLoyaltyPointsUsed for LoyaltyPayment)
- ✅ Composition (Airline has Flights, Flight has Seats/Bookings)
- ✅ Virtual Destructor (User, Payment)

**3. Practical Functionality**
- View and search flights by route
- Book seats with passenger information
- Multiple payment methods (Credit Card, Cash, Loyalty Points)
- Cancel bookings and release seats
- View formatted tickets (boarding pass)
- Display passenger manifests
- OOP demonstration modes for learning

**4. Beginner-Friendly Implementation**
- Every line has a comment explaining what it does
- Simple, full English variable names (no abbreviations)
- No pointers except where necessary (polymorphism demos)
- Fixed-size arrays (no dynamic memory allocation)
- Clear input validation with error messages
- Clean terminal output with separators and headers

**5. Educational Value**
- Two OOP demonstration modes (User hierarchy, Payment hierarchy)
- Shows polymorphism in action with real examples
- Demonstrates all required OOP concepts in a working system
- Easy to explain and understand for project presentations

---

**Key Takeaway for Project Explanation:**

When explaining this project, follow this structure:

1. **Start with the big picture:** "This is an airline reservation system with 13 classes organized in a 3-file structure."

2. **Explain the class hierarchy:** "We have two inheritance chains - User (Admin/Customer) and Payment (CreditCard/Cash/Loyalty)."

3. **Show composition:** "The Airline contains Flights, each Flight contains Seats and Bookings."

4. **Demonstrate a booking flow:** "When a user books a seat, we create a Passenger, generate a unique PNR using a static counter, find an available seat, process payment using polymorphism, and store the booking."

5. **Highlight OOP concepts:** "This demonstrates all 13 required OOP concepts including encapsulation, inheritance, polymorphism, static members, operator overloading, friend functions, and more."

6. **Show the code structure:** "All classes are in classes.h, all helpers in helpers.h, and main.cpp just runs the menu loop."

---

**END OF FLOW.MD**

This document provides a complete guide to understanding and explaining the Airline Reservation System project.
