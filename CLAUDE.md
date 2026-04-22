# CLAUDE.md — Airline Reservation System
# Master Instruction File for Claude CLI

---

## SECTION 1: PROJECT IDENTITY

**Project Name:** Airline Reservation System

**Language:** C++ (Pure, Standard Only)

**Type:** Terminal-Based Console Application

**Output File:** main.cpp (single file, no splitting)

**Compiler Command:** `g++ main.cpp -o airline`

**Run Command:** `./airline`

**Difficulty Level:** Intermediate OOP (beginner-friendly syntax)

**Purpose:** Learn and demonstrate core OOP concepts through a real-world system

---

## SECTION 2: STRICT CODING RULES

Claude must follow every rule below — no exceptions.

### RULE 1 — LANGUAGE PURITY
- Use only pure standard C++
- Only these headers are allowed: `#include <iostream>`, `#include <string>`, `#include <cstring>`
- No Python, no Java, no other language mixed in
- No external libraries, no frameworks, no third-party code

### RULE 2 — NO STL CONTAINERS
- Never use vectors, maps, sets, lists, queues, stacks, or any STL container
- All collections must use plain C++ arrays of fixed size
- Example: `Seat seats[50]` not `vector<Seat> seats`

### RULE 3 — SINGLE FILE ONLY
- The entire project must live in one file: `main.cpp`
- No header files (.h), no separate source files (.cpp)
- No splitting of classes into multiple files

### RULE 4 — COMMENT EVERY LINE
- Every single line of code must have a comment explaining what it does
- Comments go on the same line using `//`
- No line of code is allowed to exist without a comment
- Example: `int seatNumber; // stores the unique number of this seat`

### RULE 5 — BEGINNER-FRIENDLY NAMING
- All variable names must be simple, full English words
- No abbreviations like arr, ptr, tmp, cnt, sz, idx
- Good examples: `seatNumber`, `passengerName`, `flightOrigin`, `bookingCounter`
- Bad examples: `arr[i]`, `ptr->x`, `tmpVal`, `cntSeats`

### RULE 6 — NO POINTERS UNLESS NECESSARY
- Avoid raw pointers wherever possible
- Use object instances and object arrays directly
- If a pointer is absolutely needed, explain why in a comment above it

### RULE 7 — FIXED ARRAY SIZES
- Maximum flights in Airline: 10
- Maximum seats per Flight: 50
- Maximum bookings per Flight: 50
- Maximum airlines in system: 1
- These sizes must be defined as constants at the top of the file

### RULE 8 — INPUT VALIDATION
- Every user input from cin must be checked for basic validity
- If invalid input is entered, show a clear error message and ask again
- Never let the program crash on bad input

### RULE 9 — NO DYNAMIC MEMORY
- Never use `new` or `delete` keywords
- No heap allocation of any kind
- All objects must be created on the stack

### RULE 10 — CLEAN TERMINAL OUTPUT
- Every output section must have a separator line of `=` or `-` characters
- All menus must be centered and clearly labeled
- All ticket output must be inside a box made of `|` and `-` characters
- Leave blank lines between sections for readability

---

## SECTION 3: OOP CONCEPTS MAP

Strict map of which OOP concept goes in which class.

### ENCAPSULATION
- Apply in ALL 6 classes: `Seat`, `Passenger`, `Flight`, `Booking`, `Ticket`, `Airline`
- All data members must be declared `private`
- All data members must have a public getter method (`getSeatNumber()`, `getName()`, etc.)
- All data members must have a public setter method (`setSeatNumber()`, `setName()`, etc.)
- No data member is ever accessed directly from outside the class

### COMPOSITION
- `Flight` class MUST contain: `Seat seats[50]` as a member (not a pointer, not a reference)
- `Flight` class MUST contain: `Booking bookings[50]` as a member
- `Airline` class MUST contain: `Flight flights[10]` as a member
- These are object arrays owned directly by the parent class

### STATIC MEMBERS
- `Booking` class MUST have: `static int pnrCounter` declared inside the class
- `Booking` class MUST have: `static int pnrCounter = 0` initialized outside the class
- Every new Booking object must increment `pnrCounter` and assign it as the PNR number
- PNR format: `PNR-001`, `PNR-002`, `PNR-003` and so on

### CONSTRUCTOR OVERLOADING
- `Passenger` class MUST have Constructor 1: takes `name`, `age`, `idNumber` as parameters
- `Passenger` class MUST have Constructor 2: takes no parameters (default constructor)
- `Flight` class MUST have Constructor 1: takes `flightNumber`, `origin`, `destination`, `date`
- `Flight` class MUST have Constructor 2: takes no parameters (default constructor)
- Both constructors in each class must initialize all member variables

### OBJECT ARRAYS
- `Seat seats[50]` inside `Flight` — array of Seat objects (not pointers)
- `Booking bookings[50]` inside `Flight` — array of Booking objects (not pointers)
- `Flight flights[10]` inside `Airline` — array of Flight objects (not pointers)

---

## SECTION 4: CLASS BLUEPRINT

Exact structure Claude must follow.

### CLASS 1 — Seat

**Private members:**
- `int seatNumber`
- `string seatClass` (values: "economy" or "business")
- `bool isAvailable`

**Public members:**
- Constructor: `Seat()`
- Getters: `getSeatNumber()`, `getSeatClass()`, `getIsAvailable()`
- Setters: `setSeatNumber()`, `setSeatClass()`, `setIsAvailable()`
- Method: `void displaySeat()` — prints seat info in one line

### CLASS 2 — Passenger

**Private members:**
- `string passengerName`
- `int passengerAge`
- `string passengerId`

**Public members:**
- Constructor 1: `Passenger(string name, int age, string id)`
- Constructor 2: `Passenger()`
- Getters: `getName()`, `getAge()`, `getId()`
- Setters: `setName()`, `setAge()`, `setId()`
- Method: `void displayPassenger()` — prints passenger info

### CLASS 3 — Flight

**Private members:**
- `string flightNumber`
- `string originCity`
- `string destinationCity`
- `string flightDate`
- `Seat seats[50]`
- `int totalSeats`
- `Booking bookings[50]`
- `int totalBookings`

**Public members:**
- Constructor 1: `Flight(string number, string origin, string dest, string date)`
- Constructor 2: `Flight()`
- Getters and Setters for all primitive members
- Method: `void setupSeats(int economyCount, int businessCount)`
- Method: `void displayFlight()` — prints flight summary
- Method: `int findAvailableSeat(string seatClass)` — returns seat index or -1
- Method: `bool addBooking(Booking newBooking)` — adds booking to array
- Method: `bool cancelBooking(string pnrNumber)` — removes booking, frees seat
- Method: `void displayManifest()` — prints all booked passengers

### CLASS 4 — Booking

**Private members:**
- `string pnrNumber`
- `Passenger bookingPassenger`
- `string bookedFlightNumber`
- `int bookedSeatNumber`
- `string bookedSeatClass`

**Static member:**
- `static int pnrCounter`

**Public members:**
- Constructor: `Booking()`
- Method: `void createBooking(Passenger p, string flightNum, int seatNum, string seatClass)`
- Getters: `getPnrNumber()`, `getPassenger()`, `getFlightNumber()`, `getSeatNumber()`, `getSeatClass()`
- Method: `void displayBooking()` — prints booking summary

### CLASS 5 — Ticket

**Private members:**
- `Booking ticketBooking`

**Public members:**
- Constructor: `Ticket(Booking b)`
- Method: `void printTicket()` — prints a fully formatted ticket inside a box

### CLASS 6 — Airline

**Private members:**
- `string airlineName`
- `Flight flights[10]`
- `int totalFlights`

**Public members:**
- Constructor: `Airline(string name)`
- Method: `bool addFlight(Flight newFlight)` — adds flight to array
- Method: `void searchFlights(string origin, string destination)` — displays matches
- Method: `int findFlight(string flightNumber)` — returns index or -1
- Method: `void displayAllFlights()` — shows all flights
- Method: `void loadSampleData()` — pre-loads 2 sample flights on startup

---

## SECTION 5: FEATURE IMPLEMENTATION PLAN

Step-by-step build order Claude must follow in exact order:

1. Write all constants at the top (`MAX_FLIGHTS`, `MAX_SEATS`, `MAX_BOOKINGS`)
2. Write the `Seat` class completely with all comments
3. Write the `Passenger` class completely with both constructors and all comments
4. Write the `Booking` class with static counter and all comments
5. Write the `Ticket` class with formatted box print method and all comments
6. Write the `Flight` class with object arrays and all methods and all comments
7. Write the `Airline` class with all methods and all comments
8. Write the static member initialization: `int Booking::pnrCounter = 0;`
9. Write all standalone helper functions for the menu
10. Write the `main()` function with the looping menu
11. Call `loadSampleData()` at the very start of `main()`
12. Test all features mentally by tracing through the code once

---

## SECTION 6: MENU SYSTEM SPECIFICATION

The menu must loop forever until the user enters 0.

Display this exact layout:

```
==========================================
      AIRLINE RESERVATION SYSTEM
==========================================
  1. Add New Flight
  2. Search Flights by Route
  3. Book a Seat
  4. Cancel a Booking
  5. View Ticket
  6. View Passenger Manifest
  0. Exit
==========================================
Enter your choice:
```

### Each menu option must:

**Option 1 — Add New Flight:**
- Ask for: flight number, origin city, destination city, date, number of economy seats, number of business seats
- Then call: `airline.addFlight()` and `flight.setupSeats()`

**Option 2 — Search Flights by Route:**
- Ask for: origin city, destination city
- Then call: `airline.searchFlights()`
- Show: flight number, route, date, available seat counts

**Option 3 — Book a Seat:**
- Ask for: flight number, passenger name, age, ID number, seat class preference
- Then call: `flight.findAvailableSeat()`, create Booking, call `flight.addBooking()`
- Show: success message with assigned PNR number

**Option 4 — Cancel a Booking:**
- Ask for: PNR number
- Then call: `flight.cancelBooking()`
- Show: success message confirming cancellation and freed seat

**Option 5 — View Ticket:**
- Ask for: PNR number
- Then find the booking, create Ticket object, call `ticket.printTicket()`
- Show: full formatted ticket inside a box

**Option 6 — View Passenger Manifest:**
- Ask for: flight number
- Then call: `flight.displayManifest()`
- Show: numbered list with passenger name, seat number, seat class

---

## SECTION 7: TICKET FORMAT SPECIFICATION

Claude must print the ticket in exactly this box format:

```
+------------------------------------------+
|          BOARDING PASS / TICKET          |
+------------------------------------------+
|  PNR Number   : PNR-001                  |
|  Passenger    : Muhammad Ali             |
|  Flight       : PK-301                   |
|  From         : Lahore                   |
|  To           : Karachi                  |
|  Date         : 2025-06-01               |
|  Seat Number  : 3                        |
|  Seat Class   : Economy                  |
+------------------------------------------+
|         HAVE A PLEASANT JOURNEY          |
+------------------------------------------+
```

---

## SECTION 8: SAMPLE DATA SPECIFICATION

Claude must pre-load exactly this data when the program starts:

**Flight 1:**
- `flightNumber` = "PK-301"
- `originCity` = "Lahore"
- `destinationCity` = "Karachi"
- `flightDate` = "2025-06-01"
- Economy seats = 5 (seat numbers 1 to 5)
- Business seats = 2 (seat numbers 6 and 7)

**Flight 2:**
- `flightNumber` = "PK-502"
- `originCity` = "Islamabad"
- `destinationCity` = "Dubai"
- `flightDate` = "2025-06-05"
- Economy seats = 4 (seat numbers 1 to 4)
- Business seats = 2 (seat numbers 5 and 6)

---

## SECTION 9: DEBUGGING RULES

Mandatory debugging steps Claude must follow:

- **RULE D1:** Never apply a fix without first identifying the root cause
- **RULE D2:** Read every error message completely before doing anything
- **RULE D3:** Reproduce the bug with a specific test case before fixing
- **RULE D4:** Trace the data flow backward from the error to the source
- **RULE D5:** Write the hypothesis as a comment before applying the fix
- **RULE D6:** Make the smallest possible change to test the hypothesis
- **RULE D7:** If 3 fixes fail in a row, stop and reconsider the class design
- **RULE D8:** Never stack multiple fixes at the same time
- **RULE D9:** After every fix, re-verify the entire affected class works
- **RULE D10:** Never say the bug is fixed without actually testing it

---

## SECTION 10: VERIFICATION CHECKLIST

Must all be true before project is complete:

- [ ] All 6 classes are fully implemented with private data and public methods
- [ ] Encapsulation is applied in every class
- [ ] Composition is correctly used (object arrays, not pointers)
- [ ] Static PNR counter works and generates unique PNR-001, PNR-002 format
- [ ] Both constructors exist in Passenger and Flight classes
- [ ] Object arrays are used everywhere (no vectors, no maps)
- [ ] Every line of code has a comment
- [ ] No variable name is abbreviated or unclear
- [ ] All 6 menu options work without crashing
- [ ] Booking correctly marks the seat as unavailable
- [ ] Cancellation correctly marks the seat as available again
- [ ] Ticket prints inside a properly formatted box
- [ ] Passenger manifest shows correct data per flight
- [ ] Sample data loads automatically on startup
- [ ] Program handles invalid menu input without crashing
- [ ] Code compiles cleanly with: `g++ main.cpp -o airline`
- [ ] Program runs correctly with: `./airline`

---

## SECTION 11: DOCUMENTATION RULES

Rules for documentation:

- **DOC RULE 1:** Write a full project header comment block at the very top of main.cpp
- **DOC RULE 2:** Every class must have a comment block above it describing its purpose
- **DOC RULE 3:** Every method must have a comment above it describing what it does
- **DOC RULE 4:** Every section of main() must have a comment describing what that section does
- **DOC RULE 5:** A README.md file must be created alongside main.cpp
- **DOC RULE 6:** README.md must include: project description, how to compile, how to run, OOP concepts used, class list, feature list, and sample session walkthrough

---

## SECTION 12: FINAL INSTRUCTION TO CLAUDE

When working on this project, Claude must:

1. Read this entire CLAUDE.md file before writing a single line of code
2. Follow every rule in every section without exception
3. Complete the project in the exact phase order:
   **Plan → Build class by class → Test each class → Debug → Verify checklist → Document**
4. Never skip a phase even if the task seems simple
5. Never mark the project as complete unless every item in Section 10 is confirmed
6. If any rule conflicts with a user request, follow the rule and explain why
7. Always prioritize correctness over speed
8. This CLAUDE.md file is the single source of truth for this entire project

---

## SECTION 13: SYNTAX SIMPLICITY RULES

Mandatory syntax rules Claude must never violate:

### SIMPLE SYNTAX RULE 1 — NO COMPLEX EXPRESSIONS
- Never write two operations on the same line
- **Bad:** `seats[++index].setAvailable(flag == true ? 1 : 0);`
- **Good:**
  ```cpp
  index = index + 1;
  seats[index].setAvailable(false);
  ```

### SIMPLE SYNTAX RULE 2 — NO TERNARY OPERATORS
- Never use the ternary operator `? :`
- Always use a full if/else block instead
- **Bad:** `string result = (x > 0) ? "yes" : "no";`
- **Good:**
  ```cpp
  string result = "";
  if (x > 0)
  {
      result = "yes";
  }
  else
  {
      result = "no";
  }
  ```

### SIMPLE SYNTAX RULE 3 — NO NESTED FUNCTION CALLS
- Never call a function inside another function call on the same line
- **Bad:** `flight.addBooking(createBooking(getPassenger(name, age)));`
- **Good:**
  ```cpp
  Passenger newPassenger = getPassenger(name, age);
  Booking newBooking = createBooking(newPassenger);
  flight.addBooking(newBooking);
  ```

### SIMPLE SYNTAX RULE 4 — ONE STATEMENT PER LINE
- Every statement must be on its own separate line
- Never chain multiple statements with semicolons on one line
- **Bad:** `int x = 0; int y = 0; int z = 0;`
- **Good:**
  ```cpp
  int x = 0;
  int y = 0;
  int z = 0;
  ```

### SIMPLE SYNTAX RULE 5 — NO ADVANCED OOP FEATURES
- Never use inheritance or virtual functions
- Never use templates or generic programming
- Never use operator overloading
- Never use friend classes or friend functions
- Never use abstract classes or interfaces
- Only use the basic OOP: classes, objects, constructors, methods

### SIMPLE SYNTAX RULE 6 — SIMPLE IF/ELSE ONLY
- Use only simple if, else if, else blocks for all decisions
- Switch/case is allowed only for the main menu
- Never nest more than 2 levels of if/else inside each other
- If logic is getting deeply nested, break it into a separate method

### SIMPLE SYNTAX RULE 7 — SIMPLE LOOPS ONLY
- Use only for loops and while loops
- Never use do-while loops
- Never use complex loop conditions with multiple `&&` or `||` on one line
- Break complex conditions into separate bool variables first
- **Bad:** `while (i < total && seats[i].getIsAvailable() && count < max)`
- **Good:**
  ```cpp
  bool notAtEnd = (i < total);
  bool seatFree = seats[i].getIsAvailable();
  bool spaceLeft = (count < max);
  while (notAtEnd && seatFree && spaceLeft)
  ```

### SIMPLE SYNTAX RULE 8 — SIMPLE STRING OPERATIONS ONLY
- Only use `==` to compare strings
- Only use `=` to assign strings
- Only use `+` to join strings
- Never use string iterators or string algorithms
- Never use substr, find, replace unless absolutely necessary
- If substr or find is needed, write a comment explaining exactly what it does

### SIMPLE SYNTAX RULE 9 — CLEAR RETURN STATEMENTS
- Every function that returns a value must have one clear return statement
- Never return complex expressions
- **Bad:** `return (count > 0) ? seats[count-1].getSeatNumber() : -1;`
- **Good:**
  ```cpp
  if (count > 0)
  {
      return seats[count - 1].getSeatNumber();
  }
  return -1;
  ```

### SIMPLE SYNTAX RULE 10 — READABLE BOOLEAN VARIABLES
- Never use raw true/false in conditions without a named variable
- Always assign bool results to a clearly named variable first
- **Bad:** `if (bookings[i].getPnrNumber() == pnrInput && seats[j].getIsAvailable())`
- **Good:**
  ```cpp
  bool pnrMatches = (bookings[i].getPnrNumber() == pnrInput);
  bool seatIsFree = seats[j].getIsAvailable();
  if (pnrMatches && seatIsFree)
  ```

### SIMPLE SYNTAX RULE 11 — SPACING AND INDENTATION
- Use 4 spaces for every level of indentation (no tabs)
- Always put opening curly brace `{` on its own new line
- Always put closing curly brace `}` on its own new line
- Leave one blank line between every method definition
- Leave one blank line between every major block inside a method

### SIMPLE SYNTAX RULE 12 — AVOID CONFUSING SYMBOLS
- Never use bitwise operators: `&`, `|`, `^`, `~`, `<<`, `>>`
- Never use pointer arithmetic: `*`, `->`, `&variable`
- Never use increment/decrement inside expressions: `array[i++]`, `*ptr++`
- Always increment/decrement on a separate line
- **Bad:** `cout << array[i++];`
- **Good:**
  ```cpp
  cout << array[i];
  i = i + 1;
  ```

### SIMPLE SYNTAX RULE 13 — FUNCTION SIZE LIMIT
- No single function or method should be longer than 30 lines
- If a method is getting longer than 30 lines, break it into 2 smaller helper methods
- This keeps every function easy to read in one glance

### SIMPLE SYNTAX RULE 14 — NO MAGIC NUMBERS
- Never use raw numbers directly in logic
- Always define them as named constants at the top
- **Bad:** `if (totalFlights >= 10)`
- **Good:**
  ```cpp
  const int MAX_FLIGHTS = 10;
  if (totalFlights >= MAX_FLIGHTS)
  ```

### SIMPLE SYNTAX RULE 15 — WRITE FOR A BEGINNER READER
- Imagine the person reading this code has only 3 months of C++ experience
- Every piece of logic must be so clear that a beginner can understand it without asking any questions
- If a block of code feels clever or tricky, rewrite it to be simpler
- Simple and correct is always better than clever and confusing

---

**END OF CLAUDE.MD**

This file is the single source of truth for the Airline Reservation System project.
All development must strictly adhere to these specifications.
