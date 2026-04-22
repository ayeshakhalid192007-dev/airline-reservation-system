/*
 * File: Seat.h
 * Purpose: Header file for Seat class
 * OOP Concept: Encapsulation (private data with public interface)
 */

#ifndef SEAT_H                    // include guard to prevent multiple inclusion
#define SEAT_H                    // define header guard macro

#include <string>                 // include string library for string type
using namespace std;              // use standard namespace

/*
 * Class: Seat
 * Purpose: Represents a single seat on a flight
 * OOP Concepts: Encapsulation, Constructor overloading
 */
class Seat {
private:                          // private section - data hidden from outside
    int seatNumber;               // unique identifier for this seat
    string seatClass;             // class type: Economy, Business, or First
    bool isAvailable;             // availability status of seat
    double basePrice;             // base price for this seat class

public:                           // public section - interface accessible from outside
    Seat();                       // default constructor declaration
    Seat(int num, string sc, double price);  // parameterized constructor declaration

    int getSeatNumber();          // getter method for seat number
    void setSeatNumber(int num);  // setter method for seat number
    string getSeatClass();        // getter method for seat class
    void setSeatClass(string sc); // setter method for seat class
    bool getIsAvailable();        // getter method for availability
    void setIsAvailable(bool avail);  // setter method for availability
    double getBasePrice();        // getter method for base price
    void setBasePrice(double price);  // setter method for base price

    void displaySeat();           // method to display seat information
};

#endif                            // end of include guard
