/*
 * File: constants.cpp
 * Purpose: Define all constant values used throughout the system
 * Description: Contains maximum limits and fixed values for the airline system
 */

#ifndef CONSTANTS_CPP // header guard to prevent multiple inclusion
#define CONSTANTS_CPP // define the header guard

const int MAX_FLIGHTS = 10; // maximum number of flights in airline
const int MAX_SEATS = 50; // maximum number of seats per flight
const int MAX_BOOKINGS = 50; // maximum number of bookings per flight
const int MAX_AIRLINES = 1; // maximum number of airlines in system

const double ECONOMY_PRICE = 5000.0; // price for economy class seat
const double BUSINESS_PRICE = 12000.0; // price for business class seat

#endif // end of header guard
