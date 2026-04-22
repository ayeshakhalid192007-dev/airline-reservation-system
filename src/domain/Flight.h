/*
 * File: Flight.h
 * Purpose: Header file for Flight class
 * OOP Concepts: Encapsulation, Composition (HAS-A relationship with Seat and Booking)
 */

#ifndef FLIGHT_H // include guard to prevent multiple inclusion
#define FLIGHT_H // define header guard macro

#include <string> // include string library for string type
#include "Seat.h" // include Seat class for composition
#include "Booking.h" // include Booking class for composition

using namespace std; // use standard namespace

/*
 * Class: Flight
 * Purpose: Represents a flight with seats and bookings
 * OOP Concepts: Encapsulation, Composition, Dynamic Memory Management
 */
class Flight
{
private: // private section - data hidden from outside
    string flightNumber; // unique identifier for this flight
    string origin; // departure city name
    string destination; // arrival city name
    string departureDate; // date of departure in YYYY-MM-DD format
    string departureTime; // time of departure in HH:MM format
    string arrivalTime; // time of arrival in HH:MM format
    int totalSeats; // total number of seats on this flight
    int availableSeats; // number of seats currently available for booking

    Seat* seats; // dynamic array pointer for Seat objects (composition)
    int maxSeats; // maximum capacity of seats array

    Booking* bookings; // dynamic array pointer for Booking objects (composition)
    int bookingCount; // current number of bookings made
    int maxBookings; // maximum capacity of bookings array

public: // public section - interface accessible from outside
    Flight(); // default constructor declaration
    Flight(string num, string orig, string dest, string date, string depTime, string arrTime, int seatCount); // parameterized constructor declaration
    Flight(const Flight& other); // copy constructor declaration for deep copy
    Flight& operator=(const Flight& other); // copy assignment operator declaration for deep copy
    ~Flight(); // destructor declaration for cleanup of dynamic memory

    void initializeSeats(int count); // method to allocate and initialize seat array
    bool addBooking(Booking b); // method to add a new booking to the flight
    bool cancelBooking(string pnr); // method to cancel a booking by PNR number
    int findAvailableSeat(string seatClass); // method to find first available seat of given class
    void displayFlight(); // method to display flight summary information
    void displayManifest(); // method to display all bookings on this flight

    string getFlightNumber(); // getter method for flight number
    void setFlightNumber(string num); // setter method for flight number
    string getOrigin(); // getter method for origin city
    void setOrigin(string orig); // setter method for origin city
    string getDestination(); // getter method for destination city
    void setDestination(string dest); // setter method for destination city
    string getDepartureDate(); // getter method for departure date
    void setDepartureDate(string date); // setter method for departure date
    string getDepartureTime(); // getter method for departure time
    void setDepartureTime(string time); // setter method for departure time
    string getArrivalTime(); // getter method for arrival time
    void setArrivalTime(string time); // setter method for arrival time
    int getTotalSeats(); // getter method for total seats
    void setTotalSeats(int total); // setter method for total seats
    int getAvailableSeats(); // getter method for available seats
    void setAvailableSeats(int available); // setter method for available seats
};

#endif // end of include guard
