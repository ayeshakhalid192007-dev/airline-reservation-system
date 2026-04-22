#ifndef BOOKING_H // prevents multiple inclusion of this header file
#define BOOKING_H // defines the header guard for Booking class

#include <string> // includes string library for string data type
#include "Passenger.h" // includes Passenger class for composition

using namespace std; // allows use of standard library without std:: prefix

class Booking // defines the Booking class
{
private: // private section - data members cannot be accessed directly from outside
    string pnr; // stores the unique PNR number for this booking
    Passenger passenger; // stores the passenger object (composition - Booking HAS-A Passenger)
    string flightNumber; // stores the flight number for this booking
    int seatNumber; // stores the seat number assigned to this booking
    string seatClass; // stores the class of seat (economy or business)
    double amountPaid; // stores the amount paid for this booking
    string bookingDate; // stores the date when booking was made
    string status; // stores the status of booking (Pending, Confirmed, Cancelled)

    static int bookingCounter; // static member - shared across all Booking objects for generating unique PNR

public: // public section - methods can be accessed from outside the class
    Booking(); // default constructor - creates booking with default values
    Booking(Passenger p, string flight, int seat, string sc, double amount); // parameterized constructor - creates booking with given values

    void generatePNR(); // generates unique PNR number using static counter

    string getPnr(); // returns the PNR number of this booking
    Passenger getPassenger(); // returns the passenger object of this booking
    string getFlightNumber(); // returns the flight number of this booking
    int getSeatNumber(); // returns the seat number of this booking
    string getSeatClass(); // returns the seat class of this booking
    double getAmountPaid(); // returns the amount paid for this booking
    string getBookingDate(); // returns the booking date
    string getStatus(); // returns the status of this booking

    void setPnr(string p); // sets the PNR number of this booking
    void setPassenger(Passenger p); // sets the passenger object of this booking
    void setFlightNumber(string flight); // sets the flight number of this booking
    void setSeatNumber(int seat); // sets the seat number of this booking
    void setSeatClass(string sc); // sets the seat class of this booking
    void setAmountPaid(double amount); // sets the amount paid for this booking
    void setBookingDate(string date); // sets the booking date
    void setStatus(string s); // sets the status of this booking

    void displayBooking(); // displays all booking details in one line
    void printTicket(); // prints formatted ticket in a box with borders

    static int getBookingCounter(); // returns the current value of booking counter
};

#endif // ends the header guard
