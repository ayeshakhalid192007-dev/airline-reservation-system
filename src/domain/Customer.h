// Customer.h - Header file for Customer class
// This class inherits from User base class (IS-A relationship)
// Demonstrates inheritance and polymorphism concepts

#ifndef CUSTOMER_H // include guard to prevent multiple inclusion
#define CUSTOMER_H // define the header guard

#include <string> // for string data type
#include "User.h" // include User base class for inheritance
#include "Booking.h" // include Booking class for booking history

using namespace std; // to use string without std:: prefix

// Customer class - inherits from User base class using public inheritance
class Customer : public User
{
private: // private members specific to Customer class
    int loyaltyPoints; // stores accumulated loyalty points for rewards
    string membershipTier; // stores tier level: Bronze, Silver, Gold, or Platinum
    Booking* bookingHistory; // dynamic array to store customer's booking history
    int bookingCount; // tracks current number of bookings in history
    int maxBookings; // maximum capacity of booking history array

public: // public methods accessible from outside the class
    // constructor with parameters - calls base class constructor
    Customer(string id, string uname, string pass, string mail, string name, string phone);

    // destructor - deallocates dynamic memory for booking history
    ~Customer();

    // override displayInfo from base class - demonstrates polymorphism
    void displayInfo();

    // override login from base class - demonstrates polymorphism
    bool login(string inputUsername, string inputPassword);

    // adds a booking to customer's booking history
    void addBookingToHistory(Booking b);

    // displays all bookings in customer's history
    void viewBookingHistory();

    // getter method for loyalty points
    int getLoyaltyPoints();

    // adds points to customer's loyalty account
    void addLoyaltyPoints(int points);

    // getter method for membership tier
    string getMembershipTier();

    // updates membership tier based on loyalty points
    void updateMembershipTier();

    // getter method for booking count
    int getBookingCount();

    // setter method for loyalty points
    void setLoyaltyPoints(int points);

    // setter method for membership tier
    void setMembershipTier(string tier);
};

#endif // end of include guard
