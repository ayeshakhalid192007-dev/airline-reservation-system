/*
 * File: Seat.cpp
 * Purpose: Implementation file for Seat class
 */

#include "Seat.h"                 // include corresponding header file
#include <iostream>               // include iostream for console output
using namespace std;              // use standard namespace

/*
 * Constructor: Seat (Default)
 * Purpose: Creates a Seat object with default values
 */
Seat::Seat() {
    seatNumber = 0;               // initialize seat number to 0
    seatClass = "";               // initialize seat class to empty string
    isAvailable = true;           // initialize availability to true (available)
    basePrice = 0.0;              // initialize base price to 0.0
}

/*
 * Constructor: Seat (Parameterized)
 * Purpose: Creates a Seat object with specified values
 */
Seat::Seat(int num, string sc, double price) {
    seatNumber = num;             // initialize seat number with parameter
    seatClass = sc;               // initialize seat class with parameter
    basePrice = price;            // initialize base price with parameter
    isAvailable = true;           // new seats are available by default
}

/*
 * Method: getSeatNumber
 * Purpose: Returns the seat number
 */
int Seat::getSeatNumber() {
    return seatNumber;            // return the private seat number
}

/*
 * Method: setSeatNumber
 * Purpose: Sets the seat number
 */
void Seat::setSeatNumber(int num) {
    if (num > 0) {                // validate that seat number is positive
        seatNumber = num;         // set seat number to parameter value
    } else {                      // if invalid seat number
        cout << "Error: Invalid seat number" << endl;  // display error message
    }                             // end validation
}

/*
 * Method: getSeatClass
 * Purpose: Returns the seat class
 */
string Seat::getSeatClass() {
    return seatClass;             // return the private seat class
}

/*
 * Method: setSeatClass
 * Purpose: Sets the seat class
 */
void Seat::setSeatClass(string sc) {
    seatClass = sc;               // set seat class to parameter value
}

/*
 * Method: getIsAvailable
 * Purpose: Returns the availability status
 */
bool Seat::getIsAvailable() {
    return isAvailable;           // return the private availability status
}

/*
 * Method: setIsAvailable
 * Purpose: Sets the availability status
 */
void Seat::setIsAvailable(bool avail) {
    isAvailable = avail;          // set availability to parameter value
}

/*
 * Method: getBasePrice
 * Purpose: Returns the base price
 */
double Seat::getBasePrice() {
    return basePrice;             // return the private base price
}

/*
 * Method: setBasePrice
 * Purpose: Sets the base price
 */
void Seat::setBasePrice(double price) {
    if (price >= 0) {             // validate that price is non-negative
        basePrice = price;        // set base price to parameter value
    } else {                      // if invalid price
        cout << "Error: Invalid price" << endl;  // display error message
    }                             // end validation
}

/*
 * Method: displaySeat
 * Purpose: Displays seat information
 */
void Seat::displaySeat() {
    cout << "Seat #" << seatNumber;                    // print seat number
    cout << " | Class: " << seatClass;                 // print seat class
    cout << " | Price: $" << basePrice;                // print base price
    if (isAvailable) {                                 // check if seat is available
        cout << " | Status: Available";                // print available status
    } else {                                           // if seat is not available
        cout << " | Status: Occupied";                 // print occupied status
    }                                                  // end availability check
    cout << endl;                                      // move to next line
}
