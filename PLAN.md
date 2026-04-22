# PLAN.md — Airline Reservation System Implementation Plan
# Comprehensive Development Roadmap

---

## PROJECT OVERVIEW

**Project Name:** Airline Reservation System  
**Target File:** main.cpp (single file implementation)  
**Language:** Pure C++ (Standard Library Only)  
**Compiler:** g++ main.cpp -o airline  
**Execution:** ./airline  
**Development Date:** 2026-04-22  

**Core Purpose:**  
Build a terminal-based airline reservation system demonstrating fundamental OOP concepts including encapsulation, composition, static members, constructor overloading, and object arrays.

---

## PHASE 1: PROJECT SETUP AND CONSTANTS

### Task 1.1: File Header and Includes
- Create main.cpp file
- Add project header comment block with:
  - Project name and description
  - Author information
  - Date created
  - OOP concepts demonstrated
  - Compilation and execution instructions
- Include required headers:
  - `#include <iostream>`
  - `#include <string>`
  - `#include <cstring>`

### Task 1.2: Define Global Constants
- `const int MAX_FLIGHTS = 10;` — maximum flights in airline
- `const int MAX_SEATS = 50;` — maximum seats per flight
- `const int MAX_BOOKINGS = 50;` — maximum bookings per flight
- Add namespace declaration: `using namespace std;`

**Deliverable:** File structure with headers and constants ready

---

## PHASE 2: CLASS IMPLEMENTATION (Bottom-Up Approach)

### Task 2.1: Implement Seat Class

**Purpose:** Represents a single seat on a flight

**Private Members:**
- `int seatNumber` — unique identifier for the seat
- `string seatClass` — either "economy" or "business"
- `bool isAvailable` — true if seat can be booked, false if occupied

**Public Members:**
- `Seat()` — default constructor, initializes all members to default values
- `int getSeatNumber()` — returns seat number
- `string getSeatClass()` — returns seat class
- `bool getIsAvailable()` — returns availability status
- `void setSeatNumber(int number)` — sets seat number
- `void setSeatClass(string classType)` — sets seat class
- `void setIsAvailable(bool available)` — sets availability
- `void displaySeat()` — prints seat information in one line

**Implementation Notes:**
- Constructor should initialize seatNumber to 0, seatClass to empty string, isAvailable to true
- displaySeat() should show: "Seat #[number] | Class: [class] | Status: [Available/Occupied]"
- Every line must have inline comment

**Verification:**
- All data members are private
- All getters/setters are public
- Constructor initializes all members
- Display method formats output clearly

---

### Task 2.2: Implement Passenger Class

**Purpose:** Stores information about a passenger

**Private Members:**
- `string passengerName` — full name of passenger
- `int passengerAge` — age of passenger
- `string passengerId` — ID number (CNIC, passport, etc.)

**Public Members:**
- `Passenger(string name, int age, string id)` — parameterized constructor
- `Passenger()` — default constructor
- `string getName()` — returns passenger name
- `int getAge()` — returns passenger age
- `string getId()` — returns passenger ID
- `void setName(string name)` — sets passenger name
- `void setAge(int age)` — sets passenger age
- `void setId(string id)` — sets passenger ID
- `void displayPassenger()` — prints passenger information

**Implementation Notes:**
- Parameterized constructor assigns all three parameters to members
- Default constructor initializes name and id to empty strings, age to 0
- displayPassenger() should show: "Name: [name] | Age: [age] | ID: [id]"
- Demonstrates constructor overloading concept

**Verification:**
- Two constructors exist with different signatures
- All data members are private
- All getters/setters work correctly
- Both constructors initialize all members

---

### Task 2.3: Implement Booking Class

**Purpose:** Represents a single booking with unique PNR

**Private Members:**
- `string pnrNumber` — unique booking reference (format: PNR-001, PNR-002, etc.)
- `Passenger bookingPassenger` — passenger object (composition)
- `string bookedFlightNumber` — flight number for this booking
- `int bookedSeatNumber` — seat number assigned
- `string bookedSeatClass` — class of booked seat

**Static Member:**
- `static int pnrCounter` — shared counter across all Booking objects

**Public Members:**
- `Booking()` — default constructor
- `void createBooking(Passenger p, string flightNum, int seatNum, string seatClass)` — initializes booking
- `string getPnrNumber()` — returns PNR number
- `Passenger getPassenger()` — returns passenger object
- `string getFlightNumber()` — returns flight number
- `int getSeatNumber()` — returns seat number
- `string getSeatClass()` — returns seat class
- `void displayBooking()` — prints booking summary

**Implementation Notes:**
- Constructor initializes all members to default values
- createBooking() method:
  - Increments pnrCounter
  - Formats PNR as "PNR-" + padded counter (001, 002, etc.)
  - Assigns all parameters to members
- Static counter must be initialized outside class: `int Booking::pnrCounter = 0;`
- displayBooking() shows: PNR, passenger name, flight, seat number, seat class

**Verification:**
- Static member declared inside class
- Static member initialized outside class (after class definition)
- PNR format is correct (PNR-001, PNR-002, etc.)
- Each new booking increments counter

---

### Task 2.4: Implement Ticket Class

**Purpose:** Generates formatted boarding pass from booking

**Private Members:**
- `Booking ticketBooking` — booking object for this ticket

**Public Members:**
- `Ticket(Booking b)` — constructor taking booking object
- `void printTicket()` — prints formatted ticket in box

**Implementation Notes:**
- Constructor assigns booking parameter to member
- printTicket() must produce exact format:
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
- Use cout to print each line with proper spacing
- Extract data from ticketBooking member using getters

**Verification:**
- Box format is exact with proper alignment
- All booking details display correctly
- Spacing and borders are consistent

---

### Task 2.5: Implement Flight Class

**Purpose:** Manages a single flight with seats and bookings

**Private Members:**
- `string flightNumber` — unique flight identifier
- `string originCity` — departure city
- `string destinationCity` — arrival city
- `string flightDate` — date of flight
- `Seat seats[50]` — array of Seat objects (composition)
- `int totalSeats` — count of initialized seats
- `Booking bookings[50]` — array of Booking objects (composition)
- `int totalBookings` — count of active bookings

**Public Members:**
- `Flight(string number, string origin, string dest, string date)` — parameterized constructor
- `Flight()` — default constructor
- Getters: `getFlightNumber()`, `getOriginCity()`, `getDestinationCity()`, `getFlightDate()`, `getTotalSeats()`, `getTotalBookings()`
- Setters: `setFlightNumber()`, `setOriginCity()`, `setDestinationCity()`, `setFlightDate()`
- `void setupSeats(int economyCount, int businessCount)` — initializes seat array
- `void displayFlight()` — prints flight summary with available seats
- `int findAvailableSeat(string seatClass)` — searches for free seat, returns index or -1
- `bool addBooking(Booking newBooking)` — adds booking to array, marks seat unavailable
- `bool cancelBooking(string pnrNumber)` — finds and removes booking, frees seat
- `void displayManifest()` — prints all booked passengers

**Implementation Notes:**
- Parameterized constructor initializes flight details, sets totalSeats and totalBookings to 0
- Default constructor initializes all strings to empty, counters to 0
- setupSeats() method:
  - Creates economy seats numbered 1 to economyCount
  - Creates business seats numbered (economyCount+1) to (economyCount+businessCount)
  - Sets totalSeats = economyCount + businessCount
  - All seats initially available
- findAvailableSeat() method:
  - Loops through seats array
  - Checks if seat class matches AND isAvailable is true
  - Returns first match index, or -1 if none found
- addBooking() method:
  - Checks if totalBookings < MAX_BOOKINGS
  - Adds booking to bookings array
  - Finds seat by number and marks unavailable
  - Increments totalBookings
  - Returns true on success, false on failure
- cancelBooking() method:
  - Loops through bookings to find matching PNR
  - Gets seat number from booking
  - Marks seat as available
  - Shifts remaining bookings down in array
  - Decrements totalBookings
  - Returns true on success, false if PNR not found
- displayFlight() shows: flight number, route, date, available economy count, available business count
- displayManifest() shows numbered list of all bookings with passenger details

**Verification:**
- Object arrays (seats, bookings) are members, not pointers
- Composition is correctly implemented
- Both constructors exist
- All methods handle array boundaries correctly
- Seat availability updates correctly on booking/cancellation

---

### Task 2.6: Implement Airline Class

**Purpose:** Manages multiple flights and system operations

**Private Members:**
- `string airlineName` — name of the airline
- `Flight flights[10]` — array of Flight objects (composition)
- `int totalFlights` — count of flights in system

**Public Members:**
- `Airline(string name)` — constructor taking airline name
- `bool addFlight(Flight newFlight)` — adds flight to array
- `void searchFlights(string origin, string destination)` — displays matching flights
- `int findFlight(string flightNumber)` — returns flight index or -1
- `void displayAllFlights()` — shows all flights in system
- `void loadSampleData()` — pre-loads 2 sample flights

**Implementation Notes:**
- Constructor initializes airlineName, sets totalFlights to 0
- addFlight() method:
  - Checks if totalFlights < MAX_FLIGHTS
  - Adds flight to flights array at index totalFlights
  - Increments totalFlights
  - Returns true on success, false if array full
- searchFlights() method:
  - Loops through all flights
  - Compares origin and destination (case-sensitive)
  - Calls displayFlight() for each match
  - Shows "No flights found" if no matches
- findFlight() method:
  - Loops through flights array
  - Compares flight numbers
  - Returns index if found, -1 if not found
- displayAllFlights() method:
  - Loops through all flights
  - Calls displayFlight() for each
  - Shows total count at end
- loadSampleData() method:
  - Creates Flight 1: PK-301, Lahore to Karachi, 2025-06-01
    - Setup: 5 economy seats, 2 business seats
  - Creates Flight 2: PK-502, Islamabad to Dubai, 2025-06-05
    - Setup: 4 economy seats, 2 business seats
  - Adds both flights using addFlight()

**Verification:**
- Flight array is member, not pointer
- Composition correctly implemented
- All search and find methods work correctly
- Sample data loads on startup

---

### Task 2.7: Initialize Static Members

**Implementation:**
- After all class definitions, before any functions
- Write: `int Booking::pnrCounter = 0;`
- Add comment explaining this initializes the static counter

**Verification:**
- Static member initialized outside class
- Initialization happens before main()
- Counter starts at 0

---

## PHASE 3: MENU SYSTEM AND HELPER FUNCTIONS

### Task 3.1: Implement displayMenu() Function

**Purpose:** Shows main menu to user

**Implementation:**
- Print separator line of 42 equal signs
- Print centered title: "AIRLINE RESERVATION SYSTEM"
- Print separator line
- Print 7 menu options (1-6 and 0)
- Print separator line
- Print "Enter your choice: " prompt
- No newline after prompt

**Verification:**
- Menu format matches specification exactly
- Spacing and alignment correct
- All options numbered correctly

---

### Task 3.2: Implement handleAddFlight() Function

**Purpose:** Handles menu option 1 - Add New Flight

**Parameters:** `Airline& airline` (reference to airline object)

**Implementation:**
- Declare variables: flightNumber, origin, destination, date, economyCount, businessCount
- Prompt and read flight number
- Prompt and read origin city
- Prompt and read destination city
- Prompt and read flight date
- Prompt and read number of economy seats
- Validate: economyCount >= 0 and economyCount <= MAX_SEATS
- Prompt and read number of business seats
- Validate: businessCount >= 0 and (economyCount + businessCount) <= MAX_SEATS
- Create Flight object using parameterized constructor
- Call setupSeats() on flight object
- Call airline.addFlight() with flight object
- Display success or failure message

**Verification:**
- Input validation prevents invalid seat counts
- Flight is properly initialized before adding
- Success/failure feedback is clear

---

### Task 3.3: Implement handleSearchFlights() Function

**Purpose:** Handles menu option 2 - Search Flights by Route

**Parameters:** `Airline& airline`

**Implementation:**
- Declare variables: origin, destination
- Prompt and read origin city
- Prompt and read destination city
- Call airline.searchFlights(origin, destination)
- Method displays results automatically

**Verification:**
- Search is case-sensitive as specified
- Results display correctly
- "No flights found" message shows when appropriate

---

### Task 3.4: Implement handleBookSeat() Function

**Purpose:** Handles menu option 3 - Book a Seat

**Parameters:** `Airline& airline`

**Implementation:**
- Declare variables: flightNumber, passengerName, passengerAge, passengerId, seatClass
- Prompt and read flight number
- Call airline.findFlight(flightNumber) to get flight index
- If flight not found, display error and return
- Get reference to flight object from airline
- Prompt and read passenger name
- Prompt and read passenger age
- Validate: age > 0 and age < 150
- Prompt and read passenger ID
- Prompt and read seat class preference (economy or business)
- Validate: seatClass is either "economy" or "business"
- Call flight.findAvailableSeat(seatClass)
- If no seat available, display error and return
- Get seat number from seats array at returned index
- Create Passenger object using parameterized constructor
- Create Booking object using default constructor
- Call booking.createBooking() with passenger, flight number, seat number, seat class
- Call flight.addBooking() with booking object
- Display success message with PNR number

**Verification:**
- All inputs validated before processing
- Seat availability checked before booking
- PNR generated and displayed correctly
- Seat marked unavailable after booking

---

### Task 3.5: Implement handleCancelBooking() Function

**Purpose:** Handles menu option 4 - Cancel a Booking

**Parameters:** `Airline& airline`

**Implementation:**
- Declare variable: pnrNumber
- Prompt and read PNR number
- Loop through all flights in airline
- For each flight, call flight.cancelBooking(pnrNumber)
- If any flight returns true, display success message and return
- If loop completes without finding PNR, display error message

**Verification:**
- Searches all flights for PNR
- Seat freed correctly on cancellation
- Clear feedback on success or failure

---

### Task 3.6: Implement handleViewTicket() Function

**Purpose:** Handles menu option 5 - View Ticket

**Parameters:** `Airline& airline`

**Implementation:**
- Declare variable: pnrNumber
- Prompt and read PNR number
- Declare bool variable: bookingFound = false
- Loop through all flights in airline
- For each flight, loop through all bookings
- Compare booking PNR with input PNR
- If match found:
  - Set bookingFound = true
  - Create Ticket object with booking
  - Call ticket.printTicket()
  - Break out of both loops
- If bookingFound is false, display error message

**Verification:**
- Searches all flights and bookings
- Ticket displays in correct format
- Error message if PNR not found

---

### Task 3.7: Implement handleViewManifest() Function

**Purpose:** Handles menu option 6 - View Passenger Manifest

**Parameters:** `Airline& airline`

**Implementation:**
- Declare variable: flightNumber
- Prompt and read flight number
- Call airline.findFlight(flightNumber) to get index
- If flight not found, display error and return
- Get reference to flight object
- Call flight.displayManifest()

**Verification:**
- Flight lookup works correctly
- Manifest displays all bookings
- Clear error if flight not found

---

## PHASE 4: MAIN FUNCTION IMPLEMENTATION

### Task 4.1: Implement main() Function

**Purpose:** Entry point and main program loop

**Implementation:**
- Create Airline object with name "Pakistan International Airlines"
- Call airline.loadSampleData() to pre-load flights
- Display welcome message with separator lines
- Declare int variable: userChoice
- Start infinite while loop (while true)
- Call displayMenu()
- Read userChoice from cin
- Check if cin failed (invalid input)
  - If failed: clear error, ignore bad input, display error message, continue loop
- Use switch statement on userChoice:
  - Case 1: call handleAddFlight(airline), break
  - Case 2: call handleSearchFlights(airline), break
  - Case 3: call handleBookSeat(airline), break
  - Case 4: call handleCancelBooking(airline), break
  - Case 5: call handleViewTicket(airline), break
  - Case 6: call handleViewManifest(airline), break
  - Case 0: display goodbye message, return 0 (exit program)
  - Default: display invalid choice message, break
- Print blank line for spacing after each operation
- Loop continues until user enters 0

**Verification:**
- Sample data loads automatically
- Menu loops correctly
- Invalid input handled without crashing
- Program exits cleanly on choice 0
- All menu options call correct functions

---

## PHASE 5: CODE REVIEW AND COMPLIANCE CHECK

### Task 5.1: Verify All Coding Rules

**Checklist:**
- [ ] Only iostream, string, cstring headers used
- [ ] No STL containers (vectors, maps, etc.)
- [ ] Single file (main.cpp only)
- [ ] Every line has inline comment
- [ ] All variable names are full English words
- [ ] No pointers used
- [ ] Fixed array sizes with constants
- [ ] Input validation on all cin operations
- [ ] No new/delete keywords
- [ ] Clean terminal output with separators

### Task 5.2: Verify OOP Concepts

**Checklist:**
- [ ] Encapsulation: All 6 classes have private data, public getters/setters
- [ ] Composition: Flight contains Seat and Booking arrays, Airline contains Flight array
- [ ] Static members: Booking has static pnrCounter, initialized outside class
- [ ] Constructor overloading: Passenger and Flight have 2 constructors each
- [ ] Object arrays: All arrays are of objects, not pointers

### Task 5.3: Verify Syntax Simplicity Rules

**Checklist:**
- [ ] No complex expressions (one operation per line)
- [ ] No ternary operators
- [ ] No nested function calls
- [ ] One statement per line
- [ ] No advanced OOP (inheritance, templates, etc.)
- [ ] Simple if/else only (switch only for menu)
- [ ] Simple loops only (for and while)
- [ ] Simple string operations only
- [ ] Clear return statements
- [ ] Readable boolean variables
- [ ] Proper spacing and indentation (4 spaces)
- [ ] No confusing symbols (bitwise, pointer arithmetic)
- [ ] Functions under 30 lines
- [ ] No magic numbers (all constants defined)
- [ ] Code written for beginner readers

---

## PHASE 6: TESTING AND VERIFICATION

### Task 6.1: Compilation Test

**Steps:**
- Run: `g++ main.cpp -o airline`
- Verify: No compilation errors
- Verify: No warnings
- Verify: Executable file created

### Task 6.2: Functional Testing

**Test Case 1: Sample Data Loading**
- Run program
- Choose option 2 (Search Flights)
- Search: Lahore to Karachi
- Expected: PK-301 displayed with 5 economy, 2 business seats available

**Test Case 2: Book a Seat**
- Choose option 3 (Book a Seat)
- Enter: PK-301, passenger name, age 25, ID ABC123, economy
- Expected: Success message with PNR-001
- Verify: Seat count decreases

**Test Case 3: View Ticket**
- Choose option 5 (View Ticket)
- Enter: PNR-001
- Expected: Formatted ticket with all details in box

**Test Case 4: Cancel Booking**
- Choose option 4 (Cancel Booking)
- Enter: PNR-001
- Expected: Success message
- Verify: Seat count increases back

**Test Case 5: View Manifest**
- Book 2 seats on PK-301
- Choose option 6 (View Manifest)
- Enter: PK-301
- Expected: List of 2 passengers with seat details

**Test Case 6: Add New Flight**
- Choose option 1 (Add New Flight)
- Enter: PK-999, Karachi, London, 2025-07-01, 10 economy, 5 business
- Expected: Success message
- Verify: Flight appears in search

**Test Case 7: Invalid Input Handling**
- Enter non-numeric menu choice
- Expected: Error message, menu redisplays
- Enter invalid seat count (negative or > 50)
- Expected: Error message, re-prompt

**Test Case 8: Edge Cases**
- Try to book when all seats full
- Expected: No available seat message
- Try to cancel non-existent PNR
- Expected: Booking not found message
- Try to add 11th flight
- Expected: Cannot add flight message

### Task 6.3: Final Verification Checklist

**Complete Section 10 Checklist:**
- [ ] All 6 classes fully implemented
- [ ] Encapsulation applied everywhere
- [ ] Composition correctly used
- [ ] Static PNR counter works (PNR-001, PNR-002 format)
- [ ] Both constructors in Passenger and Flight
- [ ] Object arrays used (no vectors/maps)
- [ ] Every line has comment
- [ ] No abbreviated variable names
- [ ] All 6 menu options work without crashing
- [ ] Booking marks seat unavailable
- [ ] Cancellation marks seat available
- [ ] Ticket prints in box format
- [ ] Manifest shows correct data
- [ ] Sample data loads on startup
- [ ] Invalid input handled gracefully
- [ ] Compiles cleanly: `g++ main.cpp -o airline`
- [ ] Runs correctly: `./airline`

---

## PHASE 7: DOCUMENTATION

### Task 7.1: Complete Code Documentation

**Requirements:**
- Project header comment block at top of main.cpp
- Class comment block above each class definition
- Method comment block above each method
- Section comments in main() function
- Inline comments on every line of code

### Task 7.2: Create README.md

**Content Structure:**
1. Project Title and Description
2. OOP Concepts Demonstrated
   - Encapsulation
   - Composition
   - Static Members
   - Constructor Overloading
   - Object Arrays
3. Class List with Brief Descriptions
   - Seat
   - Passenger
   - Booking
   - Ticket
   - Flight
   - Airline
4. Feature List
   - Add flights
   - Search flights by route
   - Book seats
   - Cancel bookings
   - View tickets
   - View passenger manifest
5. How to Compile
   - Command: `g++ main.cpp -o airline`
6. How to Run
   - Command: `./airline`
7. Sample Session Walkthrough
   - Step-by-step example of booking a seat
   - Screenshots or text output examples
8. Technical Specifications
   - Maximum flights: 10
   - Maximum seats per flight: 50
   - Maximum bookings per flight: 50
9. Design Decisions
   - Why single file
   - Why no STL containers
   - Why fixed arrays
10. Future Enhancements (Optional)
    - Persistent storage
    - Multiple airlines
    - Dynamic pricing

---

## PHASE 8: FINAL DELIVERY

### Task 8.1: File Organization

**Deliverables:**
- main.cpp (complete implementation)
- README.md (comprehensive documentation)
- PLAN.md (this file)
- CLAUDE.md (specification file)

### Task 8.2: Final Quality Check

**Review:**
- Code compiles without errors or warnings
- All features work as specified
- Code is readable and well-commented
- Documentation is complete and accurate
- Project meets all requirements in CLAUDE.md

### Task 8.3: Submission Preparation

**Steps:**
- Test compilation one final time
- Run through all test cases
- Verify README accuracy
- Ensure all files are in project directory
- Project ready for submission or demonstration

---

## DEVELOPMENT TIMELINE ESTIMATE

**Phase 1:** 15 minutes (setup and constants)  
**Phase 2:** 120 minutes (all 6 classes + static initialization)  
**Phase 3:** 60 minutes (menu system and 7 helper functions)  
**Phase 4:** 20 minutes (main function)  
**Phase 5:** 30 minutes (code review and compliance)  
**Phase 6:** 45 minutes (testing and verification)  
**Phase 7:** 30 minutes (documentation)  
**Phase 8:** 15 minutes (final delivery)  

**Total Estimated Time:** 5.5 hours

---

## DEBUGGING STRATEGY

If issues arise during development, follow these steps:

1. **Compilation Errors:**
   - Read error message completely
   - Identify line number and error type
   - Check for missing semicolons, braces, or parentheses
   - Verify all class members are declared before use
   - Ensure static member initialized outside class

2. **Logic Errors:**
   - Trace data flow from input to output
   - Add temporary cout statements to track variable values
   - Verify array indices are within bounds
   - Check loop conditions and termination
   - Ensure getters/setters access correct members

3. **Runtime Crashes:**
   - Check for array out-of-bounds access
   - Verify all objects initialized before use
   - Ensure cin operations have validation
   - Check for infinite loops
   - Verify switch statement has break statements

4. **Incorrect Output:**
   - Compare actual output with expected format
   - Check spacing and alignment in display methods
   - Verify calculations and counters
   - Ensure correct data passed between functions
   - Check string comparisons are case-sensitive

---

## SUCCESS CRITERIA

Project is complete when:

1. All 17 items in Section 10 verification checklist are checked
2. All test cases in Phase 6 pass successfully
3. Code compiles and runs without errors
4. README.md is complete and accurate
5. All code follows CLAUDE.md specifications exactly
6. Every line of code has a comment
7. All variable names are clear and descriptive
8. No STL containers or advanced features used
9. Single file implementation (main.cpp only)
10. Sample data loads automatically on startup

---

**END OF PLAN.MD**

This plan provides a complete roadmap for implementing the Airline Reservation System.
Follow each phase in order, verify each task before moving to the next, and refer back to CLAUDE.md for detailed specifications.
