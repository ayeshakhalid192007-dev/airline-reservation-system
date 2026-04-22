/*
 * File: Flight.cpp
 * Purpose: Implementation file for Flight class
 * OOP Concepts: Encapsulation, Composition, Dynamic Memory Management
 */

#include "Flight.h" // include Flight header file
#include <iostream> // include iostream for console input/output

using namespace std; // use standard namespace

// Default constructor - creates empty flight with null pointers
Flight::Flight()
{
    flightNumber = ""; // initialize flight number to empty string
    origin = ""; // initialize origin city to empty string
    destination = ""; // initialize destination city to empty string
    departureDate = ""; // initialize departure date to empty string
    departureTime = ""; // initialize departure time to empty string
    arrivalTime = ""; // initialize arrival time to empty string
    totalSeats = 0; // initialize total seats to zero
    availableSeats = 0; // initialize available seats to zero
    seats = nullptr; // initialize seats pointer to null
    maxSeats = 50; // set maximum seats capacity to 50
    bookings = nullptr; // initialize bookings pointer to null
    bookingCount = 0; // initialize booking count to zero
    maxBookings = 50; // set maximum bookings capacity to 50
}

// Parameterized constructor - creates flight with given details
Flight::Flight(string num, string orig, string dest, string date, string depTime, string arrTime, int seatCount)
{
    flightNumber = num; // set flight number to provided value
    origin = orig; // set origin city to provided value
    destination = dest; // set destination city to provided value
    departureDate = date; // set departure date to provided value
    departureTime = depTime; // set departure time to provided value
    arrivalTime = arrTime; // set arrival time to provided value
    totalSeats = seatCount; // set total seats to provided count
    availableSeats = seatCount; // set available seats equal to total seats initially
    maxSeats = 50; // set maximum seats capacity to 50
    maxBookings = 50; // set maximum bookings capacity to 50
    bookingCount = 0; // initialize booking count to zero
    seats = nullptr; // initialize seats pointer to null (will be allocated later)
    bookings = new Booking[maxBookings]; // allocate dynamic array for bookings
}

// Destructor - cleans up dynamic memory when Flight object is destroyed
Flight::~Flight()
{
    if (seats != nullptr) // check if seats array was allocated
    {
        delete[] seats; // deallocate seats array memory
        seats = nullptr; // set pointer to null for safety
    }
    if (bookings != nullptr) // check if bookings array was allocated
    {
        delete[] bookings; // deallocate bookings array memory
        bookings = nullptr; // set pointer to null for safety
    }
}

// Copy constructor - creates deep copy of another Flight object
Flight::Flight(const Flight& other)
{
    flightNumber = other.flightNumber; // copy flight number
    origin = other.origin; // copy origin city
    destination = other.destination; // copy destination city
    departureDate = other.departureDate; // copy departure date
    departureTime = other.departureTime; // copy departure time
    arrivalTime = other.arrivalTime; // copy arrival time
    totalSeats = other.totalSeats; // copy total seats count
    availableSeats = other.availableSeats; // copy available seats count
    maxSeats = other.maxSeats; // copy max seats capacity
    maxBookings = other.maxBookings; // copy max bookings capacity
    bookingCount = other.bookingCount; // copy booking count

    if (other.seats != nullptr) // check if source has seats array
    {
        seats = new Seat[maxSeats]; // allocate new seats array
        int i = 0; // initialize loop counter
        while (i < maxSeats) // loop through all seats
        {
            seats[i] = other.seats[i]; // copy each seat object
            i = i + 1; // increment counter
        }
    }
    else // source has no seats array
    {
        seats = nullptr; // set seats pointer to null
    }

    if (other.bookings != nullptr) // check if source has bookings array
    {
        bookings = new Booking[maxBookings]; // allocate new bookings array
        int i = 0; // initialize loop counter
        while (i < bookingCount) // loop through all bookings
        {
            bookings[i] = other.bookings[i]; // copy each booking object
            i = i + 1; // increment counter
        }
    }
    else // source has no bookings array
    {
        bookings = nullptr; // set bookings pointer to null
    }
}

// Copy assignment operator - assigns deep copy of another Flight object
Flight& Flight::operator=(const Flight& other)
{
    if (this == &other) // check for self-assignment
    {
        return *this; // return current object without doing anything
    }

    if (seats != nullptr) // check if current object has seats array
    {
        delete[] seats; // deallocate old seats array
        seats = nullptr; // set pointer to null
    }

    if (bookings != nullptr) // check if current object has bookings array
    {
        delete[] bookings; // deallocate old bookings array
        bookings = nullptr; // set pointer to null
    }

    flightNumber = other.flightNumber; // copy flight number
    origin = other.origin; // copy origin city
    destination = other.destination; // copy destination city
    departureDate = other.departureDate; // copy departure date
    departureTime = other.departureTime; // copy departure time
    arrivalTime = other.arrivalTime; // copy arrival time
    totalSeats = other.totalSeats; // copy total seats count
    availableSeats = other.availableSeats; // copy available seats count
    maxSeats = other.maxSeats; // copy max seats capacity
    maxBookings = other.maxBookings; // copy max bookings capacity
    bookingCount = other.bookingCount; // copy booking count

    if (other.seats != nullptr) // check if source has seats array
    {
        seats = new Seat[maxSeats]; // allocate new seats array
        int i = 0; // initialize loop counter
        while (i < maxSeats) // loop through all seats
        {
            seats[i] = other.seats[i]; // copy each seat object
            i = i + 1; // increment counter
        }
    }
    else // source has no seats array
    {
        seats = nullptr; // set seats pointer to null
    }

    if (other.bookings != nullptr) // check if source has bookings array
    {
        bookings = new Booking[maxBookings]; // allocate new bookings array
        int i = 0; // initialize loop counter
        while (i < bookingCount) // loop through all bookings
        {
            bookings[i] = other.bookings[i]; // copy each booking object
            i = i + 1; // increment counter
        }
    }
    else // source has no bookings array
    {
        bookings = nullptr; // set bookings pointer to null
    }

    return *this; // return reference to current object
}

// Method to allocate and initialize seat array with given count
void Flight::initializeSeats(int count)
{
    if (seats != nullptr) // check if seats array already exists
    {
        delete[] seats; // deallocate old array first
    }
    seats = new Seat[maxSeats]; // allocate new dynamic array for seats
    int seatIndex = 0; // initialize seat index counter to zero
    for (seatIndex = 0; seatIndex < count; seatIndex = seatIndex + 1) // loop through each seat position
    {
        int seatNum = seatIndex + 1; // calculate seat number (1-based indexing)
        seats[seatIndex].setSeatNumber(seatNum); // set seat number for this seat
        seats[seatIndex].setIsAvailable(true); // mark seat as available initially
        if (seatIndex < count * 2 / 3) // first two-thirds are economy class
        {
            seats[seatIndex].setSeatClass("Economy"); // set seat class to Economy
            seats[seatIndex].setBasePrice(5000.0); // set economy base price
        }
        else // remaining one-third are business class
        {
            seats[seatIndex].setSeatClass("Business"); // set seat class to Business
            seats[seatIndex].setBasePrice(12000.0); // set business base price
        }
    }
}

// Method to add a new booking to the flight
bool Flight::addBooking(Booking b)
{
    if (bookingCount >= maxBookings) // check if bookings array is full
    {
        return false; // return false indicating booking failed
    }
    int seatNum = b.getSeatNumber(); // get seat number from booking
    int seatIndex = seatNum - 1; // convert to array index (0-based)
    if (seatIndex >= 0 && seatIndex < totalSeats) // check if seat index is valid
    {
        seats[seatIndex].setIsAvailable(false); // mark seat as unavailable
        availableSeats = availableSeats - 1; // decrement available seats count
    }
    bookings[bookingCount] = b; // add booking to bookings array
    bookingCount = bookingCount + 1; // increment booking count
    return true; // return true indicating booking succeeded
}

// Method to cancel a booking by PNR number
bool Flight::cancelBooking(string pnr)
{
    int i = 0; // initialize loop counter to zero
    for (i = 0; i < bookingCount; i = i + 1) // loop through all bookings
    {
        string currentPnr = bookings[i].getPnr(); // get PNR of current booking
        bool pnrMatches = (currentPnr == pnr); // check if PNR matches
        if (pnrMatches) // if PNR matches the one we're looking for
        {
            int seatNum = bookings[i].getSeatNumber(); // get seat number from booking
            int seatIndex = seatNum - 1; // convert to array index (0-based)
            if (seatIndex >= 0 && seatIndex < totalSeats) // check if seat index is valid
            {
                seats[seatIndex].setIsAvailable(true); // mark seat as available again
                availableSeats = availableSeats + 1; // increment available seats count
            }
            bookings[i].setStatus("Cancelled"); // update booking status to Cancelled
            return true; // return true indicating cancellation succeeded
        }
    }
    return false; // return false if PNR not found
}

// Method to find first available seat of given class
int Flight::findAvailableSeat(string seatClass)
{
    int i = 0; // initialize loop counter to zero
    for (i = 0; i < totalSeats; i = i + 1) // loop through all seats
    {
        bool seatIsFree = seats[i].getIsAvailable(); // check if seat is available
        string currentClass = seats[i].getSeatClass(); // get class of current seat
        bool classMatches = (currentClass == seatClass); // check if class matches
        if (seatIsFree && classMatches) // if seat is available and class matches
        {
            return seats[i].getSeatNumber(); // return seat number
        }
    }
    return -1; // return -1 if no available seat found
}

// Method to display flight summary information
void Flight::displayFlight()
{
    cout << "==========================================\n"; // print separator line
    cout << "Flight Number: " << flightNumber << "\n"; // print flight number
    cout << "Route: " << origin << " -> " << destination << "\n"; // print route
    cout << "Date: " << departureDate << "\n"; // print departure date
    cout << "Departure: " << departureTime << " | Arrival: " << arrivalTime << "\n"; // print times
    cout << "Total Seats: " << totalSeats << " | Available: " << availableSeats << "\n"; // print seat counts
    cout << "==========================================\n"; // print separator line
}

// Method to display all bookings on this flight
void Flight::displayManifest()
{
    cout << "==========================================\n"; // print separator line
    cout << "PASSENGER MANIFEST - Flight " << flightNumber << "\n"; // print header
    cout << "==========================================\n"; // print separator line
    if (bookingCount == 0) // check if there are no bookings
    {
        cout << "No bookings found for this flight.\n"; // print no bookings message
    }
    else // if there are bookings
    {
        int i = 0; // initialize loop counter to zero
        for (i = 0; i < bookingCount; i = i + 1) // loop through all bookings
        {
            string status = bookings[i].getStatus(); // get booking status
            bool isActive = (status != "Cancelled"); // check if booking is not cancelled
            if (isActive) // only display active bookings
            {
                int displayNum = i + 1; // calculate display number (1-based)
                cout << displayNum << ". "; // print booking number
                Passenger p = bookings[i].getPassenger(); // get passenger object
                cout << "Name: " << p.getName(); // print passenger name
                cout << " | Seat: " << bookings[i].getSeatNumber(); // print seat number
                cout << " | Class: " << bookings[i].getSeatClass(); // print seat class
                cout << " | PNR: " << bookings[i].getPnr() << "\n"; // print PNR number
            }
        }
    }
    cout << "==========================================\n"; // print separator line
}

// Getter method - returns flight number
string Flight::getFlightNumber()
{
    return flightNumber; // return flight number value
}

// Setter method - sets flight number
void Flight::setFlightNumber(string num)
{
    flightNumber = num; // assign provided value to flight number
}

// Getter method - returns origin city
string Flight::getOrigin()
{
    return origin; // return origin city value
}

// Setter method - sets origin city
void Flight::setOrigin(string orig)
{
    origin = orig; // assign provided value to origin city
}

// Getter method - returns destination city
string Flight::getDestination()
{
    return destination; // return destination city value
}

// Setter method - sets destination city
void Flight::setDestination(string dest)
{
    destination = dest; // assign provided value to destination city
}

// Getter method - returns departure date
string Flight::getDepartureDate()
{
    return departureDate; // return departure date value
}

// Setter method - sets departure date
void Flight::setDepartureDate(string date)
{
    departureDate = date; // assign provided value to departure date
}

// Getter method - returns departure time
string Flight::getDepartureTime()
{
    return departureTime; // return departure time value
}

// Setter method - sets departure time
void Flight::setDepartureTime(string time)
{
    departureTime = time; // assign provided value to departure time
}

// Getter method - returns arrival time
string Flight::getArrivalTime()
{
    return arrivalTime; // return arrival time value
}

// Setter method - sets arrival time
void Flight::setArrivalTime(string time)
{
    arrivalTime = time; // assign provided value to arrival time
}

// Getter method - returns total seats
int Flight::getTotalSeats()
{
    return totalSeats; // return total seats value
}

// Setter method - sets total seats
void Flight::setTotalSeats(int total)
{
    totalSeats = total; // assign provided value to total seats
}

// Getter method - returns available seats
int Flight::getAvailableSeats()
{
    return availableSeats; // return available seats value
}

// Setter method - sets available seats
void Flight::setAvailableSeats(int available)
{
    availableSeats = available; // assign provided value to available seats
}
