#include "Booking.h" // includes the Booking header file
#include <iostream> // includes input output stream library for console operations
#include <iomanip> // includes library for formatting output

using namespace std; // allows use of standard library without std:: prefix

int Booking::bookingCounter = 0; // initializes static member outside class - shared by all Booking objects

Booking::Booking() // default constructor implementation
{
    pnr = ""; // initializes PNR to empty string
    passenger = Passenger(); // initializes passenger with default Passenger constructor
    flightNumber = ""; // initializes flight number to empty string
    seatNumber = 0; // initializes seat number to zero
    seatClass = ""; // initializes seat class to empty string
    amountPaid = 0.0; // initializes amount paid to zero
    bookingDate = ""; // initializes booking date to empty string
    status = "Pending"; // initializes status to Pending by default
}

Booking::Booking(Passenger p, string flight, int seat, string sc, double amount) // parameterized constructor implementation
{
    passenger = p; // assigns the passenger object to this booking
    flightNumber = flight; // assigns the flight number to this booking
    seatNumber = seat; // assigns the seat number to this booking
    seatClass = sc; // assigns the seat class to this booking
    amountPaid = amount; // assigns the amount paid to this booking
    bookingDate = "2026-04-22"; // assigns current date to booking date
    status = "Confirmed"; // sets status to Confirmed for new bookings
    generatePNR(); // calls method to generate unique PNR number
}

void Booking::generatePNR() // generates unique PNR number using static counter
{
    bookingCounter = bookingCounter + 1; // increments the static counter by one

    string pnrNumber = ""; // creates empty string to build PNR number

    if (bookingCounter < 10) // checks if counter is single digit
    {
        pnrNumber = "PNR00"; // adds prefix for single digit numbers
    }
    else if (bookingCounter < 100) // checks if counter is two digits
    {
        pnrNumber = "PNR0"; // adds prefix for two digit numbers
    }
    else // counter is three or more digits
    {
        pnrNumber = "PNR"; // adds prefix for three or more digit numbers
    }

    pnrNumber = pnrNumber + to_string(bookingCounter); // converts counter to string and appends to prefix
    pnr = pnrNumber; // assigns the generated PNR to this booking
}

string Booking::getPnr() // returns the PNR number
{
    return pnr; // returns the PNR member variable
}

Passenger Booking::getPassenger() // returns the passenger object
{
    return passenger; // returns the passenger member variable
}

string Booking::getFlightNumber() // returns the flight number
{
    return flightNumber; // returns the flightNumber member variable
}

int Booking::getSeatNumber() // returns the seat number
{
    return seatNumber; // returns the seatNumber member variable
}

string Booking::getSeatClass() // returns the seat class
{
    return seatClass; // returns the seatClass member variable
}

double Booking::getAmountPaid() // returns the amount paid
{
    return amountPaid; // returns the amountPaid member variable
}

string Booking::getBookingDate() // returns the booking date
{
    return bookingDate; // returns the bookingDate member variable
}

string Booking::getStatus() // returns the booking status
{
    return status; // returns the status member variable
}

void Booking::setPnr(string p) // sets the PNR number
{
    pnr = p; // assigns the parameter value to pnr member variable
}

void Booking::setPassenger(Passenger p) // sets the passenger object
{
    passenger = p; // assigns the parameter value to passenger member variable
}

void Booking::setFlightNumber(string flight) // sets the flight number
{
    flightNumber = flight; // assigns the parameter value to flightNumber member variable
}

void Booking::setSeatNumber(int seat) // sets the seat number
{
    seatNumber = seat; // assigns the parameter value to seatNumber member variable
}

void Booking::setSeatClass(string sc) // sets the seat class
{
    seatClass = sc; // assigns the parameter value to seatClass member variable
}

void Booking::setAmountPaid(double amount) // sets the amount paid
{
    amountPaid = amount; // assigns the parameter value to amountPaid member variable
}

void Booking::setBookingDate(string date) // sets the booking date
{
    bookingDate = date; // assigns the parameter value to bookingDate member variable
}

void Booking::setStatus(string s) // sets the booking status
{
    status = s; // assigns the parameter value to status member variable
}

void Booking::displayBooking() // displays all booking details in one line
{
    cout << "PNR: " << pnr << " | "; // prints PNR number with separator
    cout << "Passenger: " << passenger.getName() << " | "; // prints passenger name with separator
    cout << "Flight: " << flightNumber << " | "; // prints flight number with separator
    cout << "Seat: " << seatNumber << " (" << seatClass << ") | "; // prints seat number and class with separator
    cout << "Amount: $" << fixed << setprecision(2) << amountPaid << " | "; // prints amount with two decimal places
    cout << "Date: " << bookingDate << " | "; // prints booking date with separator
    cout << "Status: " << status << endl; // prints status and ends line
}

void Booking::printTicket() // prints formatted ticket in a box with borders
{
    cout << "+------------------------------------------+" << endl; // prints top border of ticket box
    cout << "|          BOARDING PASS / TICKET          |" << endl; // prints ticket header centered
    cout << "+------------------------------------------+" << endl; // prints separator line

    cout << "|  PNR Number   : " << left << setw(23) << pnr << "|" << endl; // prints PNR with left alignment
    cout << "|  Passenger    : " << left << setw(23) << passenger.getName() << "|" << endl; // prints passenger name
    cout << "|  Age          : " << left << setw(23) << passenger.getAge() << "|" << endl; // prints passenger age
    cout << "|  ID Number    : " << left << setw(23) << passenger.getId() << "|" << endl; // prints passenger ID
    cout << "|  Flight       : " << left << setw(23) << flightNumber << "|" << endl; // prints flight number
    cout << "|  Date         : " << left << setw(23) << bookingDate << "|" << endl; // prints booking date
    cout << "|  Seat Number  : " << left << setw(23) << seatNumber << "|" << endl; // prints seat number
    cout << "|  Seat Class   : " << left << setw(23) << seatClass << "|" << endl; // prints seat class
    cout << "|  Amount Paid  : $" << left << setw(22) << fixed << setprecision(2) << amountPaid << "|" << endl; // prints amount
    cout << "|  Status       : " << left << setw(23) << status << "|" << endl; // prints booking status

    cout << "+------------------------------------------+" << endl; // prints separator line
    cout << "|         HAVE A PLEASANT JOURNEY          |" << endl; // prints farewell message centered
    cout << "+------------------------------------------+" << endl; // prints bottom border of ticket box
}

int Booking::getBookingCounter() // static method to return current booking counter value
{
    return bookingCounter; // returns the static bookingCounter variable
}
