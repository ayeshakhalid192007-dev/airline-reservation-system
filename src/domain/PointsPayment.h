// PointsPayment.h - Derived class for loyalty points payment processing
// This file defines the PointsPayment class that inherits from Payment

#ifndef POINTSPAYMENT_H // include guard to prevent multiple inclusion
#define POINTSPAYMENT_H // define the header guard

#include "Payment.h" // include the Payment base class header
#include <string> // include string library for string data type

using namespace std; // use standard namespace to avoid writing std:: prefix

// PointsPayment class - handles loyalty points payment transactions
// Inherits from Payment abstract base class using public inheritance
class PointsPayment : public Payment
{
private: // private members accessible only within this class
    int pointsUsed; // number of loyalty points used for this payment
    string customerId; // unique identifier of the customer using points
    double conversionRate; // conversion rate from points to currency (e.g., 100 points = $1)

public: // public methods accessible from outside the class
    // Constructor with parameters - calls base class constructor
    // Initializes points payment with payment details and points information
    PointsPayment(string id, double amt, string date, string status, int points, string custId, double rate);

    // Implementation of pure virtual method from Payment base class
    // Processes the points payment transaction
    // Returns true if payment successful, false otherwise
    bool processPayment();

    // Implementation of pure virtual method from Payment base class
    // Validates points payment details before processing
    // Returns true if customer has sufficient points, false otherwise
    bool validatePayment();

    // Override of virtual method from Payment base class
    // Displays payment information including points specific details
    void displayPaymentInfo();

    // Getter method to retrieve points used
    int getPointsUsed();

    // Setter method to update points used
    void setPointsUsed(int points);

    // Getter method to retrieve customer ID
    string getCustomerId();

    // Setter method to update customer ID
    void setCustomerId(string custId);

    // Getter method to retrieve conversion rate
    double getConversionRate();

    // Setter method to update conversion rate
    void setConversionRate(double rate);
};

#endif // end of include guard
