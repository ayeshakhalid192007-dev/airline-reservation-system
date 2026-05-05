// =============================================================
// File: classes.h
// Project: Airline Reservation System
// Purpose: Contains ALL class definitions and implementations
// OOP Concepts: Encapsulation, Inheritance, Polymorphism,
//               Operator Overloading, Friend Functions,
//               Static Members, Copy Constructors,
//               Multi-level Inheritance, Protected Members
// =============================================================

#ifndef CLASSES_H // prevents this file from being included twice
#define CLASSES_H // defines the include guard

#include <iostream>  // for cout and cin
#include <string>    // for string data type
#include <cstring>   // for string helper functions
#include <fstream>   // for file input and output operations

using namespace std; // allows use of cout, cin, string without std:: prefix

// =============================================================
// CONSTANTS - all fixed values defined here at the top
// =============================================================

const int MAX_FLIGHTS  = 10;    // maximum flights an airline can have
const int MAX_SEATS    = 20;    // maximum seats per flight
const int MAX_BOOKINGS = 20;    // maximum bookings per flight

const double ECONOMY_PRICE  = 5000.0;  // price for economy class seat in rupees
const double BUSINESS_PRICE = 12000.0; // price for business class seat in rupees

const int ECONOMY_SEAT_LIMIT = 14; // seats 1 to 14 are economy class
// seats 15 to 20 are business class

// =============================================================
// EXCEPTION CLASSES - for error handling throughout the system
// =============================================================

// Base Exception Class - parent class for all airline exceptions
class AirlineException
{
private: // private data members
    string errorMessage; // stores the error message text
    int    errorCode;    // stores the numeric error code

public: // public interface

    // Constructor - creates an exception with a message and code
    AirlineException(string message, int code)
    {
        errorMessage = message; // stores the error message
        errorCode    = code;    // stores the error code
    }

    // Getter - returns the error message
    string getErrorMessage()
    {
        return errorMessage; // returns the private error message
    }

    // Getter - returns the error code
    int getErrorCode()
    {
        return errorCode; // returns the private error code
    }

    // Display method - prints formatted error message to screen
    void displayError()
    {
        cout << "==========================================" << endl; // top border
        cout << "  ERROR [Code " << errorCode << "]" << endl;        // shows error code
        cout << "  " << errorMessage << endl;                        // shows error message
        cout << "==========================================" << endl; // bottom border
    }
};

// InputException - thrown when user input is invalid
class InputException : public AirlineException
{
public: // public interface

    // Constructor - creates an input exception
    InputException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// FlightNotFoundException - thrown when a flight number is not found
class FlightNotFoundException : public AirlineException
{
public: // public interface

    // Constructor - creates a flight not found exception
    FlightNotFoundException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// SeatUnavailableException - thrown when no seats of requested class are available
class SeatUnavailableException : public AirlineException
{
public: // public interface

    // Constructor - creates a seat unavailable exception
    SeatUnavailableException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// BookingNotFoundException - thrown when a PNR is not found
class BookingNotFoundException : public AirlineException
{
public: // public interface

    // Constructor - creates a booking not found exception
    BookingNotFoundException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// ArrayFullException - thrown when flight or booking arrays reach maximum capacity
class ArrayFullException : public AirlineException
{
public: // public interface

    // Constructor - creates an array full exception
    ArrayFullException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// FileIOException - thrown when file read or write operations fail
class FileIOException : public AirlineException
{
public: // public interface

    // Constructor - creates a file I/O exception
    FileIOException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// PaymentException - thrown when payment validation or processing fails
class PaymentException : public AirlineException
{
public: // public interface

    // Constructor - creates a payment exception
    PaymentException(string message, int code) : AirlineException(message, code)
    {
        // calls base class constructor to store message and code
    }
};

// =============================================================
// CLASS 1: Passenger
// Purpose: Stores passenger details for a booking
// OOP: Encapsulation (private data + public getters/setters)
//      Constructor Overloading (default + parameterized)
//      Copy Constructor (manual deep copy)
// =============================================================
class Passenger
{
private: // private data members - cannot be accessed from outside
    string passengerName; // stores the full name of the passenger
    int    passengerAge;  // stores the age of the passenger in years
    string passengerId;   // stores the national ID or passport number

public: // public methods - accessible from outside the class

    // Constructor 1 - Default constructor with no parameters
    // Used when creating an empty Passenger before filling details
    Passenger()
    {
        passengerName = "Unknown"; // sets default name to Unknown
        passengerAge  = 0;         // sets default age to zero
        passengerId   = "N/A";     // sets default ID to not available
    }

    // Constructor 2 - Parameterized constructor with all passenger details
    // Used when we already know the passenger name, age, and ID
    Passenger(string name, int age, string id)
    {
        passengerName = name; // stores the provided name
        passengerAge  = age;  // stores the provided age
        passengerId   = id;   // stores the provided ID
    }

    // Copy Constructor - creates an exact copy of another Passenger
    // Required by CLAUDE.md to demonstrate copy constructor concept
    Passenger(const Passenger& other)
    {
        passengerName = other.passengerName; // copies the name from the other object
        passengerAge  = other.passengerAge;  // copies the age from the other object
        passengerId   = other.passengerId;   // copies the ID from the other object
    }

    // Assignment Operator - assigns values from another Passenger object
    // Prevents compiler deprecation warnings when copy constructor is defined
    Passenger& operator=(const Passenger& other)
    {
        if (this != &other) // checks if not assigning to itself
        {
            passengerName = other.passengerName; // copies the name from the other object
            passengerAge  = other.passengerAge;  // copies the age from the other object
            passengerId   = other.passengerId;   // copies the ID from the other object
        }
        return *this; // returns reference to this object for chaining
    }

    // Getter method - returns the passenger name
    string getName()
    {
        return passengerName; // returns the private name value
    }

    // Getter method - returns the passenger age
    int getAge()
    {
        return passengerAge; // returns the private age value
    }

    // Getter method - returns the passenger ID
    string getId()
    {
        return passengerId; // returns the private ID value
    }

    // Setter method - sets the passenger name after validation
    void setName(string name)
    {
        bool nameIsEmpty = (name == ""); // checks if the name is empty
        if (nameIsEmpty)                 // if name is empty, show error
        {
            cout << "Error: Passenger name cannot be empty." << endl; // error message
        }
        else // name is valid
        {
            passengerName = name; // assigns the valid name to member variable
        }
    }

    // Setter method - sets the passenger age after validation
    void setAge(int age)
    {
        bool ageIsValid = (age > 0 && age < 150); // checks if age is in a reasonable range
        if (ageIsValid)                             // if age is valid
        {
            passengerAge = age; // assigns the valid age to member variable
        }
        else // age is out of range
        {
            cout << "Error: Age must be between 1 and 149." << endl; // error message
        }
    }

    // Setter method - sets the passenger ID
    void setId(string id)
    {
        passengerId = id; // assigns the provided ID to member variable
    }

    // Display method - prints all passenger details to the screen
    void displayPassenger()
    {
        cout << "  Name      : " << passengerName << endl; // prints name
        cout << "  Age       : " << passengerAge  << endl; // prints age
        cout << "  ID Number : " << passengerId   << endl; // prints ID
    }
};

// =============================================================
// CLASS 2: Seat
// Purpose: Represents one seat on an airplane
// OOP: Encapsulation, Constructor Overloading
// =============================================================
class Seat
{
private: // private data - hidden from outside access
    int    seatNumber;   // the number label for this seat (e.g. 1, 2, 3)
    string seatClass;    // the class of this seat: Economy or Business
    bool   isAvailable;  // true if seat is free, false if it is taken
    double basePrice;    // the ticket price for this seat class

public: // public interface accessible from outside

    // Default Constructor - creates an empty seat with default values
    Seat()
    {
        seatNumber  = 0;          // default seat number is zero
        seatClass   = "Economy";  // default class is economy
        isAvailable = true;       // new seat starts as available
        basePrice   = 0.0;        // default price is zero
    }

    // Parameterized Constructor - creates seat with specific values
    Seat(int number, string seatType, double price)
    {
        seatNumber  = number;    // assigns the provided seat number
        seatClass   = seatType;  // assigns the provided seat class
        isAvailable = true;      // new seat always starts as available
        basePrice   = price;     // assigns the provided price
    }

    // Getter - returns the seat number
    int getSeatNumber()
    {
        return seatNumber; // returns the private seat number
    }

    // Setter - changes the seat number
    void setSeatNumber(int number)
    {
        seatNumber = number; // assigns the new seat number
    }

    // Getter - returns the seat class name
    string getSeatClass()
    {
        return seatClass; // returns the private seat class
    }

    // Setter - changes the seat class
    void setSeatClass(string seatType)
    {
        seatClass = seatType; // assigns the new seat class
    }

    // Getter - returns whether this seat is currently available
    bool getIsAvailable()
    {
        return isAvailable; // returns true if available, false if taken
    }

    // Setter - marks the seat as available or unavailable
    void setIsAvailable(bool available)
    {
        isAvailable = available; // assigns the new availability status
    }

    // Getter - returns the base price of this seat
    double getBasePrice()
    {
        return basePrice; // returns the private base price
    }

    // Setter - changes the base price
    void setBasePrice(double price)
    {
        basePrice = price; // assigns the new price value
    }

    // Display - prints seat details to the screen
    void displaySeat()
    {
        cout << "  Seat " << seatNumber; // prints the seat number
        cout << " | Class: " << seatClass; // prints the seat class
        cout << " | Price: Rs." << basePrice; // prints the price

        if (isAvailable) // checks if the seat is free
        {
            cout << " | Status: Available" << endl; // prints available status
        }
        else // seat is taken
        {
            cout << " | Status: Taken" << endl; // prints taken status
        }
    }
};

// =============================================================
// CLASS 3: Booking
// Purpose: Stores one reservation made by a passenger
// OOP: Encapsulation, Static Members (booking counter + PNR),
//      Constructor Overloading, Operator Overloading (==)
// =============================================================
class Booking
{
private: // private data members
    string    pnr;          // unique booking reference number like PNR001
    Passenger passenger;    // the passenger who made this booking
    string    flightNumber; // the flight number this booking is for
    int       seatNumber;   // which seat number this passenger is assigned
    string    seatClass;    // economy or business class
    double    amountPaid;   // how much money was paid for this booking
    string    bookingDate;  // the date this booking was made
    string    status;       // Confirmed, Pending, or Cancelled

    static int bookingCounter; // shared counter used by all Booking objects to make unique PNRs

public: // public interface

    // Default Constructor - creates an empty booking with default values
    Booking()
    {
        pnr          = "";        // empty PNR for default booking
        flightNumber = "";        // empty flight number
        seatNumber   = 0;         // zero seat number
        seatClass    = "";        // empty seat class
        amountPaid   = 0.0;       // zero amount paid
        bookingDate  = "2026-01-01"; // default booking date
        status       = "Pending"; // default status is pending
    }

    // Parameterized Constructor - creates a confirmed booking with all details
    Booking(Passenger passengerData, string flight, int seat, string seatType, double amount)
    {
        passenger    = passengerData; // stores the passenger information
        flightNumber = flight;        // stores the flight number
        seatNumber   = seat;          // stores the assigned seat number
        seatClass    = seatType;      // stores the seat class
        amountPaid   = amount;        // stores the amount paid
        bookingDate  = "2026-05-05";  // stores today as booking date
        status       = "Confirmed";   // new bookings are confirmed immediately

        bookingCounter = bookingCounter + 1; // increments the shared counter by one

        string counterText = ""; // will hold the number part of the PNR

        if (bookingCounter < 10) // single digit number needs two leading zeros
        {
            counterText = "00" + to_string(bookingCounter); // adds two zeros before the number
        }
        else if (bookingCounter < 100) // two digit number needs one leading zero
        {
            counterText = "0" + to_string(bookingCounter); // adds one zero before the number
        }
        else // three or more digits need no leading zeros
        {
            counterText = to_string(bookingCounter); // uses the number as is
        }

        pnr = "PNR" + counterText; // combines the prefix with the counter text
    }

    // Copy Constructor - creates a new Booking object by copying another Booking
    // This is needed when passing Booking objects by value or returning them from functions
    Booking(const Booking& other)
    {
        pnr          = other.pnr;          // copies the PNR
        passenger    = other.passenger;    // copies the passenger information
        flightNumber = other.flightNumber; // copies the flight number
        seatNumber   = other.seatNumber;   // copies the seat number
        seatClass    = other.seatClass;    // copies the seat class
        amountPaid   = other.amountPaid;   // copies the amount paid
        bookingDate  = other.bookingDate;  // copies the booking date
        status       = other.status;       // copies the status
    }

    // Operator Overloading - == compares two bookings by their PNR number
    // This makes it easy to check if two bookings are the same booking
    bool operator==(const Booking& other)
    {
        bool samePnr = (pnr == other.pnr); // checks if both bookings have the same PNR
        return samePnr;                     // returns true if they are the same booking
    }

    // Assignment Operator - assigns values from another Booking object
    // Prevents compiler deprecation warnings when copy constructor is defined
    Booking& operator=(const Booking& other)
    {
        if (this != &other) // checks if not assigning to itself
        {
            pnr          = other.pnr;          // copies the PNR
            passenger    = other.passenger;    // copies the passenger information
            flightNumber = other.flightNumber; // copies the flight number
            seatNumber   = other.seatNumber;   // copies the seat number
            seatClass    = other.seatClass;    // copies the seat class
            amountPaid   = other.amountPaid;   // copies the amount paid
            bookingDate  = other.bookingDate;  // copies the booking date
            status       = other.status;       // copies the status
        }
        return *this; // returns reference to this object for chaining
    }

    // Getter - returns the PNR reference number
    string getPnr()
    {
        return pnr; // returns the booking reference number
    }

    // Getter - returns the passenger object
    Passenger getPassenger()
    {
        return passenger; // returns the passenger stored in this booking
    }

    // Getter - returns the flight number
    string getFlightNumber()
    {
        return flightNumber; // returns the flight number for this booking
    }

    // Getter - returns the seat number
    int getSeatNumber()
    {
        return seatNumber; // returns the assigned seat number
    }

    // Getter - returns the seat class
    string getSeatClass()
    {
        return seatClass; // returns economy or business class
    }

    // Getter - returns the amount paid
    double getAmountPaid()
    {
        return amountPaid; // returns how much was paid
    }

    // Getter - returns the booking date
    string getBookingDate()
    {
        return bookingDate; // returns when the booking was made
    }

    // Getter - returns the booking status
    string getStatus()
    {
        return status; // returns Confirmed, Pending, or Cancelled
    }

    // Setter - changes the booking status
    void setStatus(string newStatus)
    {
        status = newStatus; // assigns the new status value
    }

    // Static Getter - returns how many bookings have been created so far
    static int getBookingCounter()
    {
        return bookingCounter; // returns the shared static counter value
    }

    // Static Setter - sets the booking counter value (used when loading from file)
    static void setBookingCounter(int value)
    {
        bookingCounter = value; // assigns the counter to the provided value
    }

    // Display - prints a short summary of this booking on one line
    void displayBooking()
    {
        cout << "PNR: "    << pnr          << endl; // prints the booking reference
        cout << "Flight: " << flightNumber << endl; // prints the flight number
        cout << "Seat: "   << seatNumber   << " (" << seatClass << ")" << endl; // prints seat info
        cout << "Amount: Rs." << amountPaid << endl; // prints the amount paid
        cout << "Status: " << status       << endl; // prints the current status
    }

    // Print Ticket - displays a formatted boarding pass style ticket
    void printTicket()
    {
        cout << "+------------------------------------------+" << endl; // top border
        cout << "|          BOARDING PASS / TICKET          |" << endl; // title
        cout << "+------------------------------------------+" << endl; // separator

        cout << "|  PNR Number   : " << pnr              << endl; // prints PNR
        cout << "|  Passenger    : " << passenger.getName() << endl; // prints name
        cout << "|  Age          : " << passenger.getAge()  << endl; // prints age
        cout << "|  ID Number    : " << passenger.getId()   << endl; // prints ID
        cout << "|  Flight       : " << flightNumber      << endl; // prints flight
        cout << "|  Date         : " << bookingDate        << endl; // prints date
        cout << "|  Seat Number  : " << seatNumber         << endl; // prints seat number
        cout << "|  Seat Class   : " << seatClass          << endl; // prints seat class
        cout << "|  Amount Paid  : Rs." << amountPaid      << endl; // prints amount
        cout << "|  Status       : " << status             << endl; // prints status

        cout << "+------------------------------------------+" << endl; // separator
        cout << "|         HAVE A PLEASANT JOURNEY          |" << endl; // footer message
        cout << "+------------------------------------------+" << endl; // bottom border
    }
};

// Static member must be initialized outside the class body
// This creates the actual shared counter variable in memory
int Booking::bookingCounter = 0; // starts at zero before any bookings are made

// =============================================================
// CLASS 4: Flight
// Purpose: Represents one airplane flight with seats and bookings
// OOP: Encapsulation, Composition (has Seat array and Booking array)
//      Copy Constructor, Friend Functions (bookSeat, cancelBooking)
// =============================================================
class Flight
{
private: // private data - hidden from outside access
    string  flightNumber;              // unique identifier like PK-301
    string  origin;                    // city where flight departs from
    string  destination;               // city where flight arrives at
    string  departureDate;             // date of the flight in YYYY-MM-DD format
    string  departureTime;             // time the flight departs in HH:MM format
    string  arrivalTime;               // time the flight arrives in HH:MM format
    int     totalSeats;                // total number of seats on this flight
    int     availableSeats;            // how many seats are still free
    Seat    seats[MAX_SEATS];          // fixed array of Seat objects (composition)
    Booking bookings[MAX_BOOKINGS];    // fixed array of Booking objects (composition)
    int     bookingCount;              // how many bookings have been made so far

    // No private friend access needed from Flight - all booking access is through
    // public methods like getBookingAt() and getBookingCount()

public: // public interface

    // Default Constructor - creates an empty flight with no seats or bookings
    Flight()
    {
        flightNumber   = "";        // empty flight number
        origin         = "";        // empty origin city
        destination    = "";        // empty destination city
        departureDate  = "";        // empty departure date
        departureTime  = "";        // empty departure time
        arrivalTime    = "";        // empty arrival time
        totalSeats     = 0;         // zero total seats
        availableSeats = 0;         // zero available seats
        bookingCount   = 0;         // zero bookings made so far
    }

    // Parameterized Constructor - creates a flight with all details provided
    Flight(string number, string from, string to, string date, string depTime, string arrTime, int seatCount)
    {
        flightNumber   = number;   // stores the flight number
        origin         = from;     // stores the departure city
        destination    = to;       // stores the arrival city
        departureDate  = date;     // stores the flight date
        departureTime  = depTime;  // stores the departure time
        arrivalTime    = arrTime;  // stores the arrival time
        totalSeats     = seatCount; // stores total number of seats
        availableSeats = seatCount; // initially all seats are available
        bookingCount   = 0;         // no bookings made yet

        int seatIndex = 0; // loop counter starting from zero

        for (seatIndex = 0; seatIndex < seatCount; seatIndex = seatIndex + 1) // loops through each seat
        {
            int seatNum = seatIndex + 1; // seat numbers start at 1 not 0

            seats[seatIndex].setSeatNumber(seatNum); // assigns the seat number

            bool isEconomySeat = (seatIndex < ECONOMY_SEAT_LIMIT); // first 14 seats are economy

            if (isEconomySeat) // economy seat setup
            {
                seats[seatIndex].setSeatClass("Economy");      // marks as economy class
                seats[seatIndex].setBasePrice(ECONOMY_PRICE);  // sets economy price
            }
            else // business seat setup
            {
                seats[seatIndex].setSeatClass("Business");      // marks as business class
                seats[seatIndex].setBasePrice(BUSINESS_PRICE);  // sets business price
            }

            seats[seatIndex].setIsAvailable(true); // all seats start as available
        }
    }

    // Copy Constructor - creates an exact copy of another Flight object
    // Required to safely copy flights when storing them in the airline array
    Flight(const Flight& other)
    {
        flightNumber   = other.flightNumber;   // copies the flight number
        origin         = other.origin;         // copies the origin city
        destination    = other.destination;    // copies the destination city
        departureDate  = other.departureDate;  // copies the departure date
        departureTime  = other.departureTime;  // copies the departure time
        arrivalTime    = other.arrivalTime;    // copies the arrival time
        totalSeats     = other.totalSeats;     // copies the total seat count
        availableSeats = other.availableSeats; // copies the available seat count
        bookingCount   = other.bookingCount;   // copies the current booking count

        int seatIndex = 0; // loop counter for copying seats

        for (seatIndex = 0; seatIndex < MAX_SEATS; seatIndex = seatIndex + 1) // copies all seats
        {
            seats[seatIndex] = other.seats[seatIndex]; // copies each seat object
        }

        int bookIndex = 0; // loop counter for copying bookings

        for (bookIndex = 0; bookIndex < MAX_BOOKINGS; bookIndex = bookIndex + 1) // copies all bookings
        {
            bookings[bookIndex] = other.bookings[bookIndex]; // copies each booking object
        }
    }

    // Assignment Operator - assigns values from another Flight object
    // Prevents compiler deprecation warnings when copy constructor is defined
    Flight& operator=(const Flight& other)
    {
        if (this != &other) // checks if not assigning to itself
        {
            flightNumber   = other.flightNumber;   // copies the flight number
            origin         = other.origin;         // copies the origin city
            destination    = other.destination;    // copies the destination city
            departureDate  = other.departureDate;  // copies the departure date
            departureTime  = other.departureTime;  // copies the departure time
            arrivalTime    = other.arrivalTime;    // copies the arrival time
            totalSeats     = other.totalSeats;     // copies the total seat count
            availableSeats = other.availableSeats; // copies the available seat count
            bookingCount   = other.bookingCount;   // copies the current booking count

            int seatIndex = 0; // loop counter for copying seats

            for (seatIndex = 0; seatIndex < MAX_SEATS; seatIndex = seatIndex + 1) // copies all seats
            {
                seats[seatIndex] = other.seats[seatIndex]; // copies each seat object
            }

            int bookIndex = 0; // loop counter for copying bookings

            for (bookIndex = 0; bookIndex < MAX_BOOKINGS; bookIndex = bookIndex + 1) // copies all bookings
            {
                bookings[bookIndex] = other.bookings[bookIndex]; // copies each booking object
            }
        }
        return *this; // returns reference to this object for chaining
    }

    // Finds the first available seat of the requested class and returns its number
    // Returns -1 if no seat of that class is available
    int findAvailableSeat(string requestedClass)
    {
        int seatIndex = 0; // starts looking from the first seat

        for (seatIndex = 0; seatIndex < totalSeats; seatIndex = seatIndex + 1) // checks each seat
        {
            bool seatIsFree      = seats[seatIndex].getIsAvailable(); // checks if seat is free
            string currentClass  = seats[seatIndex].getSeatClass();   // gets the seat class
            bool classMatches    = (currentClass == requestedClass);  // compares the class names

            if (seatIsFree && classMatches) // if seat is free AND class matches
            {
                return seats[seatIndex].getSeatNumber(); // returns that seat's number
            }
        }

        return -1; // returns -1 to mean no seat was found
    }

    // Adds a new booking to this flight's booking list
    // Returns true if booking was added, false if there is no space
    bool addBooking(Booking newBooking)
    {
        bool bookingArrayFull = (bookingCount >= MAX_BOOKINGS); // checks if we have reached max bookings

        if (bookingArrayFull) // if no space left for more bookings
        {
            cout << "Error: This flight cannot accept any more bookings." << endl; // shows error
            return false; // reports failure
        }

        int assignedSeat  = newBooking.getSeatNumber(); // gets which seat was assigned
        int seatArrayIndex = assignedSeat - 1;           // converts to zero-based array index

        bool indexIsValid = (seatArrayIndex >= 0 && seatArrayIndex < totalSeats); // checks index is in range

        if (indexIsValid) // if the seat index is valid
        {
            seats[seatArrayIndex].setIsAvailable(false); // marks that seat as taken
            availableSeats = availableSeats - 1;          // reduces the available count by one
        }

        bookings[bookingCount] = newBooking; // stores the new booking in the array
        bookingCount = bookingCount + 1;     // increments the booking count by one

        return true; // reports success
    }

    // Cancels a booking by searching for the PNR number
    // Returns true if found and cancelled, false if PNR was not found
    bool cancelBooking(string pnrToCancel)
    {
        int bookIndex = 0; // starts searching from the first booking

        for (bookIndex = 0; bookIndex < bookingCount; bookIndex = bookIndex + 1) // checks each booking
        {
            string currentPnr = bookings[bookIndex].getPnr(); // gets PNR of current booking
            bool   pnrMatches = (currentPnr == pnrToCancel);  // compares with the target PNR

            if (pnrMatches) // if the PNR matches the one we want to cancel
            {
                int assignedSeat   = bookings[bookIndex].getSeatNumber(); // gets the seat number
                int seatArrayIndex = assignedSeat - 1;                    // converts to zero-based index

                bool indexIsValid = (seatArrayIndex >= 0 && seatArrayIndex < totalSeats); // validates index

                if (indexIsValid) // if seat index is valid
                {
                    seats[seatArrayIndex].setIsAvailable(true); // marks that seat as available again
                    availableSeats = availableSeats + 1;          // increases the available count by one
                }

                bookings[bookIndex].setStatus("Cancelled"); // marks the booking as cancelled

                return true; // reports successful cancellation
            }
        }

        return false; // returns false if PNR was not found in any booking
    }

    // Displays a short summary of this flight on the screen
    void displayFlight()
    {
        cout << "------------------------------------------" << endl;  // separator line
        cout << "Flight Number : " << flightNumber << endl;             // prints flight number
        cout << "Route         : " << origin << " --> " << destination << endl; // prints route
        cout << "Date          : " << departureDate << endl;            // prints date
        cout << "Departure     : " << departureTime << "  Arrival: " << arrivalTime << endl; // prints times
        cout << "Total Seats   : " << totalSeats << "  Available: " << availableSeats << endl; // prints seat info
        cout << "------------------------------------------" << endl;  // separator line
    }

    // Displays the list of all active (non-cancelled) bookings for this flight
    void displayManifest()
    {
        cout << "==========================================" << endl; // top border
        cout << "PASSENGER MANIFEST - Flight " << flightNumber << endl; // header
        cout << "==========================================" << endl; // separator

        bool hasActiveBookings = false; // tracks whether any active bookings exist

        int bookIndex = 0; // loop counter starting at zero

        for (bookIndex = 0; bookIndex < bookingCount; bookIndex = bookIndex + 1) // loops through all bookings
        {
            string currentStatus = bookings[bookIndex].getStatus(); // gets the status of this booking
            bool   notCancelled  = (currentStatus != "Cancelled");  // checks if it is still active

            if (notCancelled) // only shows bookings that are not cancelled
            {
                hasActiveBookings = true; // marks that we found at least one active booking

                Passenger passengerData = bookings[bookIndex].getPassenger(); // gets the passenger

                int displayNumber = bookIndex + 1; // creates a 1-based display number

                cout << displayNumber << ". Name: " << passengerData.getName(); // prints passenger name
                cout << " | Seat: "  << bookings[bookIndex].getSeatNumber();     // prints seat number
                cout << " | Class: " << bookings[bookIndex].getSeatClass();      // prints seat class
                cout << " | PNR: "   << bookings[bookIndex].getPnr() << endl;    // prints PNR
            }
        }

        if (!hasActiveBookings) // if no active bookings were found
        {
            cout << "No passengers are currently booked on this flight." << endl; // shows message
        }

        cout << "==========================================" << endl; // bottom border
    }

    // Getter - returns the flight number
    string getFlightNumber()
    {
        return flightNumber; // returns the private flight number
    }

    // Setter - changes the flight number
    void setFlightNumber(string number)
    {
        flightNumber = number; // assigns the new flight number
    }

    // Getter - returns the origin city
    string getOrigin()
    {
        return origin; // returns the private origin city
    }

    // Setter - changes the origin city
    void setOrigin(string city)
    {
        origin = city; // assigns the new origin city
    }

    // Getter - returns the destination city
    string getDestination()
    {
        return destination; // returns the private destination city
    }

    // Setter - changes the destination city
    void setDestination(string city)
    {
        destination = city; // assigns the new destination city
    }

    // Getter - returns the departure date
    string getDepartureDate()
    {
        return departureDate; // returns the private departure date
    }

    // Setter - changes the departure date
    void setDepartureDate(string date)
    {
        departureDate = date; // assigns the new departure date
    }

    // Getter - returns the departure time
    string getDepartureTime()
    {
        return departureTime; // returns the private departure time
    }

    // Getter - returns the arrival time
    string getArrivalTime()
    {
        return arrivalTime; // returns the private arrival time
    }

    // Getter - returns the total number of seats
    int getTotalSeats()
    {
        return totalSeats; // returns the total seat count
    }

    // Getter - returns the number of available seats
    int getAvailableSeats()
    {
        return availableSeats; // returns the available seat count
    }

    // Getter - returns how many bookings have been made on this flight
    int getBookingCount()
    {
        return bookingCount; // returns the current booking count
    }

    // Getter - returns the Booking object at a specific index position
    // Allows external code to read individual bookings without exposing the array
    Booking getBookingAt(int index)
    {
        return bookings[index]; // returns the booking stored at the given index
    }

    // Getter - returns a reference to the Seat object at a specific index position
    // Allows external code to access individual seats for file I/O operations
    Seat& getSeatAt(int index)
    {
        return seats[index]; // returns reference to the seat stored at the given index
    }
};

// =============================================================
// CLASS 5: Airline
// Purpose: Manages a collection of flights
// OOP: Encapsulation, Arrays of Objects (Flight array),
//      Static Member (total flights created counter),
//      Friend Functions (for searching and displaying flights)
// =============================================================
class Airline
{
private: // private data members
    string airlineName;             // the full name of this airline
    string airlineCode;             // the short code like PK or PIA
    Flight flights[MAX_FLIGHTS];    // fixed array of Flight objects
    int    flightCount;             // how many flights currently exist

    static int totalAirlinesCreated; // shared counter for all Airline objects

    // Friend function declarations - needed so helper functions can access flights[]
    friend void displayFlightManifest(Airline& airline); // needs access to flights array

public: // public interface

    // Default Constructor - creates an empty airline
    Airline()
    {
        airlineName  = "Unknown Airline"; // default airline name
        airlineCode  = "XX";              // default airline code
        flightCount  = 0;                 // starts with no flights

        totalAirlinesCreated = totalAirlinesCreated + 1; // counts this new airline
    }

    // Parameterized Constructor - creates airline with a real name and code
    Airline(string name, string code)
    {
        airlineName  = name;  // stores the airline name
        airlineCode  = code;  // stores the airline short code
        flightCount  = 0;     // starts with no flights

        totalAirlinesCreated = totalAirlinesCreated + 1; // counts this new airline
    }

    // Adds a flight to the airline's list of flights
    // Returns true if the flight was added, false if the list is full
    bool addFlight(Flight newFlight)
    {
        bool listIsFull = (flightCount >= MAX_FLIGHTS); // checks if the array is at capacity

        if (listIsFull) // if we already have the maximum number of flights
        {
            cout << "Error: Cannot add flight. Maximum limit of " << MAX_FLIGHTS << " reached." << endl; // error
            return false; // reports failure
        }

        flights[flightCount] = newFlight; // stores the new flight at the next open position
        flightCount = flightCount + 1;    // increments the flight count by one

        return true; // reports success
    }

    // Finds the position of a flight by its flight number
    // Returns the array index if found, or -1 if not found
    int findFlight(string flightNumber)
    {
        int searchIndex = 0; // starts searching from the beginning of the array

        for (searchIndex = 0; searchIndex < flightCount; searchIndex = searchIndex + 1) // checks each flight
        {
            string currentNumber = flights[searchIndex].getFlightNumber(); // gets this flight's number
            bool   numberMatches = (currentNumber == flightNumber);         // compares with search target

            if (numberMatches) // if this flight matches the search
            {
                return searchIndex; // returns the position of the found flight
            }
        }

        return -1; // returns -1 to mean the flight was not found
    }

    // Searches and displays all flights that match the given route
    void searchFlights(string fromCity, string toCity)
    {
        int foundCount = 0; // tracks how many matching flights are found

        int searchIndex = 0; // loop counter starting from zero

        for (searchIndex = 0; searchIndex < flightCount; searchIndex = searchIndex + 1) // checks each flight
        {
            string flightOrigin      = flights[searchIndex].getOrigin();      // gets origin of this flight
            string flightDestination = flights[searchIndex].getDestination(); // gets destination of this flight

            bool originMatches      = (flightOrigin == fromCity);  // checks if origin matches
            bool destinationMatches = (flightDestination == toCity); // checks if destination matches

            if (originMatches && destinationMatches) // if both origin and destination match
            {
                flights[searchIndex].displayFlight(); // displays this matching flight
                foundCount = foundCount + 1;          // increments found count
            }
        }

        if (foundCount == 0) // if no flights were found for this route
        {
            cout << "No flights found from " << fromCity << " to " << toCity << "." << endl; // shows message
        }
    }

    // Displays all flights currently in the airline's list
    void displayAllFlights()
    {
        if (flightCount == 0) // checks if there are any flights at all
        {
            cout << "No flights are currently available." << endl; // shows message
            return; // exits the function early
        }

        int displayIndex = 0; // loop counter starting from zero

        for (displayIndex = 0; displayIndex < flightCount; displayIndex = displayIndex + 1) // loops through all flights
        {
            int flightDisplayNumber = displayIndex + 1; // creates a 1-based number for display

            cout << "Flight " << flightDisplayNumber << ":" << endl; // shows the flight number label
            flights[displayIndex].displayFlight();                    // shows the flight details
            cout << endl;                                             // blank line between flights
        }
    }

    // Loads some pre-built sample flights into the airline for testing
    void loadSampleData()
    {
        // Create first sample flight: Lahore to Karachi
        Flight firstFlight("PK-301", "Lahore", "Karachi", "2026-06-01", "10:00", "12:00", 18); // builds flight with all details
        addFlight(firstFlight); // adds the first flight to the airline

        // Create second sample flight: Islamabad to Dubai
        Flight secondFlight("PK-502", "Islamabad", "Dubai", "2026-06-05", "14:00", "17:30", 18); // builds flight with all details
        addFlight(secondFlight); // adds the second flight to the airline

        // Create third sample flight: Karachi to London
        Flight thirdFlight("PK-786", "Karachi", "London", "2026-06-10", "22:00", "06:00", 18); // builds flight with all details
        addFlight(thirdFlight); // adds the third flight to the airline

        cout << "Sample data loaded: 3 flights added to " << airlineName << "." << endl; // confirms loading
    }

    // Saves all airline data to a file for persistence across program runs
    void saveToFile(string filename)
    {
        ofstream outputFile; // creates an output file stream object
        outputFile.open(filename); // opens the file for writing

        bool fileOpenFailed = !outputFile.is_open(); // checks if file failed to open

        if (fileOpenFailed) // if file could not be opened
        {
            throw FileIOException("Cannot open file for writing: " + filename, 601); // throws exception
        }

        // Save the booking counter first so PNR numbers continue correctly
        int currentCounter = Booking::getBookingCounter(); // gets the current counter value
        outputFile << "COUNTER:" << currentCounter << endl; // writes counter to file

        // Save the number of flights
        outputFile << "FLIGHTS:" << flightCount << endl; // writes flight count to file

        // Loop through each flight and save all its data
        int flightIndex = 0; // loop counter starting at zero

        for (flightIndex = 0; flightIndex < flightCount; flightIndex = flightIndex + 1) // loops through all flights
        {
            Flight currentFlight = flights[flightIndex]; // gets the current flight

            // Write flight details line
            outputFile << "FLIGHT:" << currentFlight.getFlightNumber() << "|"; // writes flight number
            outputFile << currentFlight.getOrigin() << "|"; // writes origin city
            outputFile << currentFlight.getDestination() << "|"; // writes destination city
            outputFile << currentFlight.getDepartureDate() << "|"; // writes departure date
            outputFile << currentFlight.getDepartureTime() << "|"; // writes departure time
            outputFile << currentFlight.getArrivalTime() << "|"; // writes arrival time
            outputFile << currentFlight.getTotalSeats() << "|"; // writes total seats
            outputFile << currentFlight.getAvailableSeats() << endl; // writes available seats

            // Save all seats for this flight
            int seatIndex = 0; // loop counter for seats

            for (seatIndex = 0; seatIndex < currentFlight.getTotalSeats(); seatIndex = seatIndex + 1) // loops through seats
            {
                Seat currentSeat = currentFlight.getSeatAt(seatIndex); // gets the seat at this index

                int availableFlag = 0; // will store 0 or 1 for availability

                if (currentSeat.getIsAvailable()) // if seat is available
                {
                    availableFlag = 1; // sets flag to 1
                }
                else // seat is taken
                {
                    availableFlag = 0; // sets flag to 0
                }

                outputFile << "SEAT:" << currentSeat.getSeatNumber() << "|"; // writes seat number
                outputFile << currentSeat.getSeatClass() << "|"; // writes seat class
                outputFile << availableFlag << "|"; // writes availability flag
                outputFile << currentSeat.getBasePrice() << endl; // writes seat price
            }

            // Save all bookings for this flight
            int bookingIndex = 0; // loop counter for bookings

            for (bookingIndex = 0; bookingIndex < currentFlight.getBookingCount(); bookingIndex = bookingIndex + 1) // loops through bookings
            {
                Booking currentBooking = currentFlight.getBookingAt(bookingIndex); // gets the booking at this index
                Passenger currentPassenger = currentBooking.getPassenger(); // gets the passenger from booking

                outputFile << "BOOKING:" << currentBooking.getPnr() << "|"; // writes PNR
                outputFile << currentPassenger.getName() << "|"; // writes passenger name
                outputFile << currentPassenger.getAge() << "|"; // writes passenger age
                outputFile << currentPassenger.getId() << "|"; // writes passenger ID
                outputFile << currentBooking.getFlightNumber() << "|"; // writes flight number
                outputFile << currentBooking.getSeatNumber() << "|"; // writes seat number
                outputFile << currentBooking.getSeatClass() << "|"; // writes seat class
                outputFile << currentBooking.getAmountPaid() << "|"; // writes amount paid
                outputFile << currentBooking.getBookingDate() << "|"; // writes booking date
                outputFile << currentBooking.getStatus() << endl; // writes booking status
            }
        }

        outputFile.close(); // closes the file after writing all data
    }

    // Loads all airline data from a file to restore previous session
    void loadFromFile(string filename)
    {
        ifstream inputFile; // creates an input file stream object
        inputFile.open(filename); // opens the file for reading

        bool fileDoesNotExist = !inputFile.is_open(); // checks if file failed to open

        if (fileDoesNotExist) // if file does not exist
        {
            throw FileIOException("File not found: " + filename, 602); // throws exception
        }

        string currentLine = ""; // will store each line read from file

        // Read the booking counter line
        getline(inputFile, currentLine); // reads the first line

        int colonPosition = currentLine.find(':'); // finds the colon position
        string counterText = currentLine.substr(colonPosition + 1); // extracts the number part
        int savedCounter = stoi(counterText); // converts string to integer

        Booking::setBookingCounter(savedCounter); // restores the booking counter

        // Read the flight count line
        getline(inputFile, currentLine); // reads the second line

        colonPosition = currentLine.find(':'); // finds the colon position
        string flightCountText = currentLine.substr(colonPosition + 1); // extracts the number part
        int savedFlightCount = stoi(flightCountText); // converts string to integer

        // Loop through each flight and load its data
        int flightIndex = 0; // loop counter starting at zero

        for (flightIndex = 0; flightIndex < savedFlightCount; flightIndex = flightIndex + 1) // loops through flights
        {
            // Read flight details line
            getline(inputFile, currentLine); // reads the FLIGHT line

            int startPosition = currentLine.find(':') + 1; // finds start of data after FLIGHT:
            string flightData = currentLine.substr(startPosition); // extracts the flight data

            // Parse flight data by splitting on pipe character
            string flightNumber = ""; // will store flight number
            string origin = ""; // will store origin city
            string destination = ""; // will store destination city
            string departureDate = ""; // will store departure date
            string departureTime = ""; // will store departure time
            string arrivalTime = ""; // will store arrival time
            int totalSeats = 0; // will store total seats

            int pipePosition = 0; // will track position of pipe character

            pipePosition = flightData.find('|'); // finds first pipe
            flightNumber = flightData.substr(0, pipePosition); // extracts flight number
            flightData = flightData.substr(pipePosition + 1); // removes processed part

            pipePosition = flightData.find('|'); // finds next pipe
            origin = flightData.substr(0, pipePosition); // extracts origin
            flightData = flightData.substr(pipePosition + 1); // removes processed part

            pipePosition = flightData.find('|'); // finds next pipe
            destination = flightData.substr(0, pipePosition); // extracts destination
            flightData = flightData.substr(pipePosition + 1); // removes processed part

            pipePosition = flightData.find('|'); // finds next pipe
            departureDate = flightData.substr(0, pipePosition); // extracts departure date
            flightData = flightData.substr(pipePosition + 1); // removes processed part

            pipePosition = flightData.find('|'); // finds next pipe
            departureTime = flightData.substr(0, pipePosition); // extracts departure time
            flightData = flightData.substr(pipePosition + 1); // removes processed part

            pipePosition = flightData.find('|'); // finds next pipe
            arrivalTime = flightData.substr(0, pipePosition); // extracts arrival time
            flightData = flightData.substr(pipePosition + 1); // removes processed part

            pipePosition = flightData.find('|'); // finds next pipe
            totalSeats = stoi(flightData.substr(0, pipePosition)); // extracts and converts total seats

            // Create the flight object with parsed data
            Flight loadedFlight(flightNumber, origin, destination, departureDate, departureTime, arrivalTime, totalSeats); // creates flight

            // Read and restore all seats for this flight
            int seatIndex = 0; // loop counter for seats

            for (seatIndex = 0; seatIndex < totalSeats; seatIndex = seatIndex + 1) // loops through seats
            {
                getline(inputFile, currentLine); // reads the SEAT line

                startPosition = currentLine.find(':') + 1; // finds start of data
                string seatData = currentLine.substr(startPosition); // extracts seat data

                int seatNumber = 0; // will store seat number
                string seatClass = ""; // will store seat class
                int availableFlag = 0; // will store availability flag
                double basePrice = 0.0; // will store base price

                pipePosition = seatData.find('|'); // finds first pipe
                seatNumber = stoi(seatData.substr(0, pipePosition)); // extracts seat number
                seatData = seatData.substr(pipePosition + 1); // removes processed part

                pipePosition = seatData.find('|'); // finds next pipe
                seatClass = seatData.substr(0, pipePosition); // extracts seat class
                seatData = seatData.substr(pipePosition + 1); // removes processed part

                pipePosition = seatData.find('|'); // finds next pipe
                availableFlag = stoi(seatData.substr(0, pipePosition)); // extracts availability flag
                seatData = seatData.substr(pipePosition + 1); // removes processed part

                basePrice = stod(seatData); // extracts and converts base price

                bool isAvailable = (availableFlag == 1); // converts flag to boolean

                int seatArrayIndex = seatNumber - 1; // converts to zero-based index

                loadedFlight.getSeatAt(seatArrayIndex).setSeatNumber(seatNumber); // sets seat number
                loadedFlight.getSeatAt(seatArrayIndex).setSeatClass(seatClass); // sets seat class
                loadedFlight.getSeatAt(seatArrayIndex).setIsAvailable(isAvailable); // sets availability
                loadedFlight.getSeatAt(seatArrayIndex).setBasePrice(basePrice); // sets base price
            }

            // Read and restore all bookings for this flight
            string nextLine = ""; // will peek at next line

            while (getline(inputFile, currentLine)) // reads lines until end of file
            {
                bool isBookingLine = (currentLine.find("BOOKING:") == 0); // checks if line starts with BOOKING:

                if (!isBookingLine) // if not a booking line
                {
                    inputFile.seekg(-currentLine.length() - 1, ios::cur); // moves file pointer back
                    break; // exits the booking loop
                }

                startPosition = currentLine.find(':') + 1; // finds start of data
                string bookingData = currentLine.substr(startPosition); // extracts booking data

                string pnr = ""; // will store PNR
                string passengerName = ""; // will store passenger name
                int passengerAge = 0; // will store passenger age
                string passengerId = ""; // will store passenger ID
                string bookingFlightNumber = ""; // will store flight number
                int seatNumber = 0; // will store seat number
                string seatClass = ""; // will store seat class
                double amountPaid = 0.0; // will store amount paid
                string bookingDate = ""; // will store booking date
                string status = ""; // will store booking status

                pipePosition = bookingData.find('|'); // finds first pipe
                pnr = bookingData.substr(0, pipePosition); // extracts PNR
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                passengerName = bookingData.substr(0, pipePosition); // extracts passenger name
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                passengerAge = stoi(bookingData.substr(0, pipePosition)); // extracts passenger age
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                passengerId = bookingData.substr(0, pipePosition); // extracts passenger ID
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                bookingFlightNumber = bookingData.substr(0, pipePosition); // extracts flight number
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                seatNumber = stoi(bookingData.substr(0, pipePosition)); // extracts seat number
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                seatClass = bookingData.substr(0, pipePosition); // extracts seat class
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                amountPaid = stod(bookingData.substr(0, pipePosition)); // extracts amount paid
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                pipePosition = bookingData.find('|'); // finds next pipe
                bookingDate = bookingData.substr(0, pipePosition); // extracts booking date
                bookingData = bookingData.substr(pipePosition + 1); // removes processed part

                status = bookingData; // extracts booking status

                // Recreate the passenger and booking objects
                Passenger loadedPassenger(passengerName, passengerAge, passengerId); // creates passenger
                Booking loadedBooking(loadedPassenger, bookingFlightNumber, seatNumber, seatClass, amountPaid); // creates booking

                loadedBooking.setStatus(status); // sets the booking status

                loadedFlight.addBooking(loadedBooking); // adds booking to flight
            }

            addFlight(loadedFlight); // adds the loaded flight to airline
        }

        inputFile.close(); // closes the file after reading all data
    }

    // Getter - returns the airline name
    string getAirlineName()
    {
        return airlineName; // returns the private airline name
    }

    // Getter - returns the airline code
    string getAirlineCode()
    {
        return airlineCode; // returns the private airline code
    }

    // Getter - returns how many flights this airline has
    int getFlightCount()
    {
        return flightCount; // returns the current number of flights
    }

    // Static Getter - returns how many Airline objects have been created in total
    static int getTotalAirlinesCreated()
    {
        return totalAirlinesCreated; // returns the shared static counter value
    }

    // Returns a reference to the flight at the given index position
    // Used by helper functions to access specific flights
    Flight& getFlightAt(int index)
    {
        return flights[index]; // returns reference to the flight at that position
    }
};

// Static member initialization - creates the actual counter variable in memory
// Starts at zero before any Airline objects are created
int Airline::totalAirlinesCreated = 0;

// =============================================================
// CLASS 6: User (Base Class)
// Purpose: Base class for all people who use the system
// OOP: Encapsulation, Protected Members, Virtual Functions,
//      Polymorphism (overridden in Admin and Customer)
// =============================================================
class User
{
protected: // protected members - accessible in this class AND derived classes
    string userId;      // unique ID for this user account
    string username;    // login username for this user
    string password;    // login password for this user
    string email;       // email address of this user
    string fullName;    // full real name of this user
    string phoneNumber; // contact phone number

public: // public interface

    // Constructor - creates a User with all account details
    User(string id, string uname, string pass, string mail, string name, string phone)
    {
        userId      = id;    // stores the user ID
        username    = uname; // stores the username
        password    = pass;  // stores the password
        email       = mail;  // stores the email address
        fullName    = name;  // stores the full name
        phoneNumber = phone; // stores the phone number
    }

    // Virtual Destructor - important so derived class destructors run correctly
    virtual ~User()
    {
        // nothing to clean up here - no dynamic memory used
    }

    // Virtual method - checks if the username and password are correct
    // Can be overridden in derived classes to add extra checks
    virtual bool login(string inputUsername, string inputPassword)
    {
        bool usernameCorrect = (inputUsername == username); // checks the username
        bool passwordCorrect = (inputPassword == password); // checks the password

        bool loginSuccess = (usernameCorrect && passwordCorrect); // both must be correct

        return loginSuccess; // returns true if login is valid
    }

    // Virtual method - displays the user's account information
    // Overridden in Admin and Customer to show their specific details
    virtual void displayInfo()
    {
        cout << "------------------------------------------" << endl; // separator
        cout << "User ID     : " << userId      << endl; // prints user ID
        cout << "Username    : " << username    << endl; // prints username
        cout << "Full Name   : " << fullName    << endl; // prints full name
        cout << "Email       : " << email       << endl; // prints email
        cout << "Phone       : " << phoneNumber << endl; // prints phone number
        cout << "------------------------------------------" << endl; // separator
    }

    // Getter - returns the user ID
    string getUserId()
    {
        return userId; // returns the private user ID
    }

    // Getter - returns the username
    string getUsername()
    {
        return username; // returns the private username
    }

    // Getter - returns the full name
    string getFullName()
    {
        return fullName; // returns the private full name
    }

    // Getter - returns the email address
    string getEmail()
    {
        return email; // returns the private email address
    }

    // Setter - changes the email address
    void setEmail(string newEmail)
    {
        email = newEmail; // assigns the new email value
    }

    // Setter - changes the phone number
    void setPhoneNumber(string newPhone)
    {
        phoneNumber = newPhone; // assigns the new phone number
    }
};

// =============================================================
// CLASS 7: Admin (inherits from User)
// Purpose: Represents an admin user with extra management powers
// OOP: Single Inheritance (User -> Admin), Polymorphism (overrides),
//      Protected members inherited from User
// =============================================================
class Admin : public User // Admin IS-A User (single inheritance)
{
private: // private members only for Admin - not in the User base class
    string adminLevel;  // the access level: SuperAdmin, Manager, or Support
    string department;  // which department this admin works in

public: // public interface

    // Constructor - creates an Admin by calling the User base constructor first
    Admin(string id, string uname, string pass, string mail, string name, string phone,
          string level, string dept)
          : User(id, uname, pass, mail, name, phone) // calls base class User constructor
    {
        adminLevel = level; // stores the admin access level
        department = dept;  // stores the department name
    }

    // Override - displays admin info including inherited User info plus admin extras
    // This overrides the User::displayInfo() method (demonstrates polymorphism)
    void displayInfo()
    {
        User::displayInfo();          // calls parent class method first to show base info
        cout << "Role       : Admin"  << endl; // shows this person is an admin
        cout << "Level      : " << adminLevel << endl; // shows the admin level
        cout << "Department : " << department << endl; // shows the department
        cout << "------------------------------------------" << endl; // separator
    }

    // Override - logs in and performs extra admin verification
    bool login(string inputUsername, string inputPassword)
    {
        bool baseLoginOk = User::login(inputUsername, inputPassword); // checks base credentials

        if (baseLoginOk) // if the basic login passed
        {
            cout << "Admin access granted to " << getFullName() << "." << endl; // shows access message
        }

        return baseLoginOk; // returns the login result
    }

    // Admin-specific method - shows what admin can manage
    void manageFlights()
    {
        cout << "Admin " << getFullName() << " is managing flights." << endl; // shows management action
    }

    // Getter - returns the admin level
    string getAdminLevel()
    {
        return adminLevel; // returns the private admin level
    }

    // Getter - returns the department name
    string getDepartment()
    {
        return department; // returns the private department name
    }

    // Setter - changes the admin level
    void setAdminLevel(string level)
    {
        adminLevel = level; // assigns the new admin level
    }
};

// =============================================================
// CLASS 8: Customer (inherits from User)
// Purpose: Represents a customer who can book flights
// OOP: Single Inheritance (User -> Customer), Polymorphism
//      Arrays of Objects (booking history array)
// =============================================================
class Customer : public User // Customer IS-A User (single inheritance)
{
private: // private members specific to customers
    int     loyaltyPoints;                 // reward points the customer has earned
    string  membershipTier;               // Bronze, Silver, Gold, or Platinum tier
    Booking bookingHistory[MAX_BOOKINGS]; // fixed array of past bookings
    int     bookingHistoryCount;          // how many bookings are in the history

public: // public interface

    // Constructor - creates a Customer by calling User constructor first
    Customer(string id, string uname, string pass, string mail, string name, string phone)
             : User(id, uname, pass, mail, name, phone) // calls the User base constructor
    {
        loyaltyPoints       = 0;        // new customer starts with zero points
        membershipTier      = "Bronze"; // new customer starts at the lowest tier
        bookingHistoryCount = 0;        // no booking history yet
    }

    // Override - displays customer info including inherited User info plus loyalty details
    void displayInfo()
    {
        User::displayInfo();             // calls parent class method to show base info
        cout << "Role           : Customer"           << endl; // shows this person is a customer
        cout << "Loyalty Points : " << loyaltyPoints  << endl; // shows loyalty points
        cout << "Tier           : " << membershipTier << endl; // shows membership tier
        cout << "------------------------------------------"   << endl; // separator
    }

    // Override - logs in and shows a welcome message for the customer
    bool login(string inputUsername, string inputPassword)
    {
        bool baseLoginOk = User::login(inputUsername, inputPassword); // checks base credentials

        if (baseLoginOk) // if credentials are correct
        {
            cout << "Welcome back, " << getFullName() << "! Tier: " << membershipTier << endl; // welcome
        }

        return baseLoginOk; // returns the login result
    }

    // Adds a completed booking to this customer's booking history
    void addBookingToHistory(Booking completedBooking)
    {
        bool historyFull = (bookingHistoryCount >= MAX_BOOKINGS); // checks if history is full

        if (!historyFull) // if there is space in the history
        {
            bookingHistory[bookingHistoryCount] = completedBooking; // stores the booking
            bookingHistoryCount = bookingHistoryCount + 1;          // increments the count

            loyaltyPoints = loyaltyPoints + 100; // adds 100 points per booking as reward
            updateMembershipTier();               // checks if tier should be upgraded
        }
    }

    // Updates the tier level based on total loyalty points earned
    void updateMembershipTier()
    {
        if (loyaltyPoints >= 1000) // gold threshold is 1000 points
        {
            membershipTier = "Gold"; // upgrades to gold tier
        }
        else if (loyaltyPoints >= 500) // silver threshold is 500 points
        {
            membershipTier = "Silver"; // upgrades to silver tier
        }
        else // below 500 points stays at bronze
        {
            membershipTier = "Bronze"; // keeps bronze tier
        }
    }

    // Displays all bookings in this customer's history
    void viewBookingHistory()
    {
        cout << "==========================================" << endl; // top border
        cout << "BOOKING HISTORY FOR " << getFullName()     << endl; // header
        cout << "==========================================" << endl; // separator

        if (bookingHistoryCount == 0) // checks if there are any past bookings
        {
            cout << "You have no past bookings." << endl; // shows empty history message
        }
        else // there are bookings to display
        {
            int histIndex = 0; // loop counter starting at zero

            for (histIndex = 0; histIndex < bookingHistoryCount; histIndex = histIndex + 1) // loops through history
            {
                int displayNumber = histIndex + 1; // creates a 1-based display number

                cout << "Booking " << displayNumber << ":" << endl; // shows booking number label
                bookingHistory[histIndex].displayBooking();          // shows the booking details
                cout << endl;                                        // blank line between bookings
            }
        }

        cout << "==========================================" << endl; // bottom border
    }

    // Getter - returns the loyalty points total
    int getLoyaltyPoints()
    {
        return loyaltyPoints; // returns the private loyalty points value
    }

    // Getter - returns the membership tier name
    string getMembershipTier()
    {
        return membershipTier; // returns the private membership tier
    }

    // Getter - returns how many bookings are in the history
    int getBookingHistoryCount()
    {
        return bookingHistoryCount; // returns the count of historical bookings
    }
};

// =============================================================
// CLASS 9: Payment (Base Class - Level 1 of multi-level chain)
// Purpose: Base class for all payment methods
// OOP: Protected Members, Virtual Functions (NOT pure virtual),
//      Multi-level Inheritance (Payment -> CreditCardPayment)
// NOTE: We do NOT use pure virtual functions as per CLAUDE.md rules
// =============================================================
class Payment
{
protected: // protected members accessible by derived payment classes
    string paymentId;     // unique ID for this payment transaction
    double amount;        // how much money is being paid
    string paymentDate;   // the date this payment is being processed
    string paymentStatus; // Pending, Completed, Failed, or Refunded

public: // public interface

    // Constructor - creates a Payment record with all basic details
    Payment(string id, double amt, string date, string status)
    {
        paymentId     = id;     // stores the payment ID
        amount        = amt;    // stores the amount
        paymentDate   = date;   // stores the payment date
        paymentStatus = status; // stores the initial status
    }

    // Virtual Destructor - needed so derived classes clean up properly
    virtual ~Payment()
    {
        // no dynamic memory to clean up here
    }

    // Virtual method - processes the payment transaction
    // Derived classes override this to implement their specific payment logic
    virtual bool processPayment()
    {
        paymentStatus = "Completed"; // marks the payment as completed
        cout << "Payment of Rs." << amount << " processed successfully." << endl; // success message
        return true; // returns success
    }

    // Virtual method - validates payment details before processing
    // Derived classes override this to check their specific requirements
    virtual bool validatePayment()
    {
        bool amountIsPositive = (amount > 0); // amount must be greater than zero
        return amountIsPositive;               // returns true if amount is valid
    }

    // Virtual method - displays payment information on screen
    // Derived classes override this to show their specific payment details
    virtual void displayPaymentInfo()
    {
        cout << "------------------------------------------" << endl; // separator
        cout << "Payment ID     : " << paymentId     << endl; // prints payment ID
        cout << "Amount         : Rs." << amount     << endl; // prints amount
        cout << "Date           : " << paymentDate   << endl; // prints date
        cout << "Status         : " << paymentStatus << endl; // prints status
        cout << "------------------------------------------" << endl; // separator
    }

    // Getter - returns the payment ID
    string getPaymentId()
    {
        return paymentId; // returns the private payment ID
    }

    // Getter - returns the payment amount
    double getAmount()
    {
        return amount; // returns the private amount
    }

    // Getter - returns the payment status
    string getPaymentStatus()
    {
        return paymentStatus; // returns the private payment status
    }

    // Setter - changes the payment status
    void setPaymentStatus(string newStatus)
    {
        paymentStatus = newStatus; // assigns the new status
    }
};

// =============================================================
// CLASS 10: OnlinePayment (inherits from Payment - Level 2)
// Purpose: Mid-level class for all payments done online
// OOP: Multi-level Inheritance chain (Payment -> OnlinePayment),
//      Protected members passed down to next level
// =============================================================
class OnlinePayment : public Payment // OnlinePayment IS-A Payment (first level of chain)
{
protected: // protected so the level-3 class can also access these
    string transactionId; // unique transaction ID from the payment gateway
    string gatewayName;   // name of the payment gateway used

public: // public interface

    // Constructor - creates an OnlinePayment by calling Payment constructor first
    OnlinePayment(string id, double amt, string date, string status,
                  string transId, string gateway)
                  : Payment(id, amt, date, status) // calls Payment base constructor
    {
        transactionId = transId;   // stores the transaction ID
        gatewayName   = gateway;   // stores the gateway name
    }

    // Override - adds online transaction info to the basic payment display
    virtual void displayPaymentInfo()
    {
        Payment::displayPaymentInfo(); // calls parent method to show base payment info
        cout << "Transaction ID : " << transactionId << endl; // shows the transaction ID
        cout << "Gateway        : " << gatewayName   << endl; // shows the gateway name
        cout << "------------------------------------------" << endl; // separator
    }

    // Override - validates the transaction ID is not empty in addition to base check
    virtual bool validatePayment()
    {
        bool baseIsValid     = Payment::validatePayment();  // checks the base conditions
        bool transIdNotEmpty = (transactionId != "");       // also checks transaction ID is set

        bool allValid = (baseIsValid && transIdNotEmpty);   // both conditions must be true

        return allValid; // returns combined validation result
    }

    // Getter - returns the transaction ID
    string getTransactionId()
    {
        return transactionId; // returns the private transaction ID
    }

    // Getter - returns the gateway name
    string getGatewayName()
    {
        return gatewayName; // returns the private gateway name
    }
};

// =============================================================
// CLASS 11: CreditCardPayment (inherits from OnlinePayment - Level 3)
// Purpose: Handles credit card payment processing
// OOP: Multi-level Inheritance (Payment -> OnlinePayment -> CreditCardPayment)
//      Polymorphism (overrides processPayment, validatePayment, displayPaymentInfo)
// =============================================================
class CreditCardPayment : public OnlinePayment // Level 3 in the inheritance chain
{
private: // private members only for credit card payments
    string cardNumber;     // the 16-digit credit card number
    string cardHolderName; // name printed on the front of the card
    string expiryDate;     // expiry date in MM/YY format
    string cvv;            // 3-digit security code on the back of the card

public: // public interface

    // Constructor - creates a CreditCardPayment by calling OnlinePayment constructor
    CreditCardPayment(string id, double amt, string date, string status,
                      string transId, string gateway,
                      string cardNum, string holderName, string expiry, string cvvCode)
                      : OnlinePayment(id, amt, date, status, transId, gateway) // calls parent constructor
    {
        cardNumber     = cardNum;    // stores the card number
        cardHolderName = holderName; // stores the card holder name
        expiryDate     = expiry;     // stores the expiry date
        cvv            = cvvCode;    // stores the CVV code
    }

    // Override - validates that card details are not empty
    bool validatePayment()
    {
        bool baseIsValid       = OnlinePayment::validatePayment(); // checks parent conditions
        bool cardNumNotEmpty   = (cardNumber != "");               // card number must be set
        bool holderNotEmpty    = (cardHolderName != "");           // holder name must be set
        bool expiryNotEmpty    = (expiryDate != "");               // expiry date must be set

        bool allValid = (baseIsValid && cardNumNotEmpty && holderNotEmpty && expiryNotEmpty); // all must pass

        return allValid; // returns combined result
    }

    // Override - processes the credit card payment transaction
    bool processPayment()
    {
        bool isValid = validatePayment(); // validates before processing

        if (!isValid) // if validation failed
        {
            cout << "Credit card payment validation failed." << endl; // shows error
            return false; // reports failure
        }

        setPaymentStatus("Completed"); // marks payment as completed
        cout << "Credit card payment of Rs." << amount << " charged to card " << cardNumber << "." << endl; // success
        return true; // reports success
    }

    // Override - displays credit card payment details on screen
    void displayPaymentInfo()
    {
        cout << "--- Credit Card Payment ---" << endl;     // section header
        OnlinePayment::displayPaymentInfo();               // calls parent to show base and online info
        cout << "Card Number    : " << cardNumber     << endl; // shows card number
        cout << "Card Holder    : " << cardHolderName << endl; // shows holder name
        cout << "Expiry Date    : " << expiryDate     << endl; // shows expiry date
        cout << "------------------------------------------" << endl; // separator
    }

    // Getter - returns the card number
    string getCardNumber()
    {
        return cardNumber; // returns the private card number
    }

    // Getter - returns the card holder name
    string getCardHolderName()
    {
        return cardHolderName; // returns the private card holder name
    }
};

// =============================================================
// CLASS 12: CashPayment (inherits from Payment directly)
// Purpose: Handles cash payment transactions at the counter
// OOP: Single Inheritance (Payment -> CashPayment), Polymorphism
// =============================================================
class CashPayment : public Payment // CashPayment IS-A Payment
{
private: // private members specific to cash payments
    double cashReceived; // how much cash the customer physically handed over
    double changeGiven;  // how much change was given back to the customer

public: // public interface

    // Constructor - creates a CashPayment by calling Payment constructor
    CashPayment(string id, double amt, string date, string status,
                double received, double change)
                : Payment(id, amt, date, status) // calls parent Payment constructor
    {
        cashReceived = received; // stores how much cash was received
        changeGiven  = change;   // stores how much change was given
    }

    // Override - validates that enough cash was received
    bool validatePayment()
    {
        bool baseIsValid        = Payment::validatePayment(); // checks base conditions
        bool sufficientCash     = (cashReceived >= amount);   // cash must be at least the amount owed

        bool allValid = (baseIsValid && sufficientCash); // both must pass

        return allValid; // returns combined result
    }

    // Override - processes the cash payment transaction
    bool processPayment()
    {
        bool isValid = validatePayment(); // validates before processing

        if (!isValid) // if validation failed
        {
            cout << "Error: Insufficient cash received." << endl; // shows error
            return false; // reports failure
        }

        setPaymentStatus("Completed"); // marks payment as completed
        cout << "Cash payment of Rs." << amount << " received." << endl; // success message
        cout << "Change returned: Rs." << changeGiven << "." << endl;     // shows change amount
        return true; // reports success
    }

    // Override - displays cash payment details on screen
    void displayPaymentInfo()
    {
        cout << "--- Cash Payment ---"                         << endl; // section header
        Payment::displayPaymentInfo();                                  // shows base payment info
        cout << "Cash Received  : Rs." << cashReceived        << endl; // shows cash received
        cout << "Change Given   : Rs." << changeGiven         << endl; // shows change given
        cout << "------------------------------------------"  << endl; // separator
    }

    // Getter - returns the cash received amount
    double getCashReceived()
    {
        return cashReceived; // returns the private cash received value
    }

    // Getter - returns the change given amount
    double getChangeGiven()
    {
        return changeGiven; // returns the private change given value
    }
};

// =============================================================
// CLASS 13: LoyaltyPayment (inherits from Payment directly)
// Purpose: Handles payment using loyalty reward points
// OOP: Single Inheritance (Payment -> LoyaltyPayment), Polymorphism
//      Friend Function (to access private pointsUsed for display)
// =============================================================
class LoyaltyPayment : public Payment // LoyaltyPayment IS-A Payment
{
private: // private members specific to loyalty points payments
    int    pointsUsed;      // how many loyalty points the customer is using
    string membershipId;    // the membership ID of the customer
    double conversionRate;  // how much one point is worth (e.g. 0.1 = 10 points = Rs.1)

    // Friend function declaration - this function needs access to private pointsUsed
    friend void showLoyaltyPointsUsed(LoyaltyPayment& payment); // friend to access private data

public: // public interface

    // Constructor - creates a LoyaltyPayment by calling Payment constructor
    LoyaltyPayment(string id, double amt, string date, string status,
                   int points, string memberId, double rate)
                   : Payment(id, amt, date, status) // calls parent Payment constructor
    {
        pointsUsed     = points;   // stores the number of points being used
        membershipId   = memberId; // stores the customer membership ID
        conversionRate = rate;     // stores the points-to-money conversion rate
    }

    // Override - validates that enough points are available to cover the payment
    bool validatePayment()
    {
        bool baseIsValid    = Payment::validatePayment();               // checks base conditions
        double pointsValue  = pointsUsed * conversionRate;              // calculates money value of points
        bool enoughPoints   = (pointsValue >= amount);                  // checks if points cover the amount

        bool allValid = (baseIsValid && enoughPoints); // both must pass

        return allValid; // returns combined result
    }

    // Override - processes the loyalty points payment
    bool processPayment()
    {
        bool isValid = validatePayment(); // validates before processing

        if (!isValid) // if validation failed
        {
            cout << "Error: Not enough loyalty points to cover this payment." << endl; // shows error
            return false; // reports failure
        }

        setPaymentStatus("Completed"); // marks payment as completed
        cout << pointsUsed << " loyalty points redeemed. Payment of Rs." << amount << " covered." << endl; // success
        return true; // reports success
    }

    // Override - displays loyalty payment details on screen
    void displayPaymentInfo()
    {
        cout << "--- Loyalty Points Payment ---"                          << endl; // section header
        Payment::displayPaymentInfo();                                            // shows base payment info
        cout << "Points Used    : " << pointsUsed                        << endl; // shows points used
        cout << "Membership ID  : " << membershipId                      << endl; // shows membership ID
        cout << "Rate           : Rs." << conversionRate << " per point" << endl; // shows rate
        cout << "------------------------------------------"             << endl; // separator
    }

    // Getter - returns the number of points used
    int getPointsUsed()
    {
        return pointsUsed; // returns the private points used value
    }

    // Getter - returns the membership ID
    string getMembershipId()
    {
        return membershipId; // returns the private membership ID
    }
};

// Friend function for LoyaltyPayment - accesses private member pointsUsed
// This demonstrates the friend function concept required by CLAUDE.md
void showLoyaltyPointsUsed(LoyaltyPayment& payment)
{
    // This function is a friend so it can directly access payment.pointsUsed
    cout << "Friend function sees: " << payment.pointsUsed << " points were used." << endl; // accesses private
}

// =============================================================
// END OF CLASSES.H
// All 13 classes are fully defined and implemented above.
// =============================================================

#endif // ends the include guard started at the top of this file
