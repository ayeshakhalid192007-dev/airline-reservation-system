// CashPayment.h - Derived class for cash payment processing
// This file defines the CashPayment class that inherits from Payment

#ifndef CASHPAYMENT_H // include guard to prevent multiple inclusion
#define CASHPAYMENT_H // define the header guard

#include "Payment.h" // include the Payment base class header
#include <string> // include string library for string data type

using namespace std; // use standard namespace to avoid writing std:: prefix

// CashPayment class - handles cash payment transactions
// Inherits from Payment abstract base class using public inheritance
class CashPayment : public Payment
{
private: // private members accessible only within this class
    double amountReceived; // total cash amount received from customer
    double changeGiven; // change amount returned to customer

public: // public methods accessible from outside the class
    // Constructor with parameters - calls base class constructor
    // Initializes cash payment with payment details and cash amounts
    CashPayment(string id, double amt, string date, string status, double received, double change);

    // Implementation of pure virtual method from Payment base class
    // Processes the cash payment transaction
    // Returns true if payment successful, false otherwise
    bool processPayment();

    // Implementation of pure virtual method from Payment base class
    // Validates cash payment details before processing
    // Returns true if cash amount is sufficient, false otherwise
    bool validatePayment();

    // Override of virtual method from Payment base class
    // Displays payment information including cash specific details
    void displayPaymentInfo();

    // Getter method to retrieve amount received
    double getAmountReceived();

    // Setter method to update amount received
    void setAmountReceived(double received);

    // Getter method to retrieve change given
    double getChangeGiven();

    // Setter method to update change given
    void setChangeGiven(double change);
};

#endif // end of include guard
