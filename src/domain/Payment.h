// Payment.h - Abstract base class for all payment types
// This file defines the Payment class interface

#ifndef PAYMENT_H // include guard to prevent multiple inclusion
#define PAYMENT_H // define the header guard

#include <string> // include string library for string data type

using namespace std; // use standard namespace to avoid writing std:: prefix

// Payment class - abstract base class for payment processing
// This class cannot be instantiated directly (has pure virtual methods)
// Derived classes: CreditCardPayment, CashPayment, PointsPayment
class Payment
{
protected: // protected members can be accessed by derived classes
    string paymentId; // unique identifier for this payment
    double amount; // payment amount in currency units
    string paymentDate; // date when payment was made (format: YYYY-MM-DD)
    string paymentStatus; // status of payment (pending, completed, failed, refunded)

public: // public methods accessible from outside the class
    // Constructor with parameters to initialize payment details
    Payment(string id, double amt, string date, string status);

    // Virtual destructor - must be virtual in base class for proper cleanup
    virtual ~Payment();

    // Pure virtual method - must be implemented by derived classes
    // Processes the payment transaction and returns success status
    virtual bool processPayment() = 0;

    // Pure virtual method - must be implemented by derived classes
    // Validates payment details before processing
    virtual bool validatePayment() = 0;

    // Virtual method with default implementation - can be overridden
    // Displays payment information to console
    virtual void displayPaymentInfo();

    // Getter method to retrieve payment ID
    string getPaymentId();

    // Setter method to update payment ID
    void setPaymentId(string id);

    // Getter method to retrieve payment amount
    double getAmount();

    // Setter method to update payment amount
    void setAmount(double amt);

    // Getter method to retrieve payment date
    string getPaymentDate();

    // Setter method to update payment date
    void setPaymentDate(string date);

    // Getter method to retrieve payment status
    string getPaymentStatus();

    // Setter method to update payment status
    void setPaymentStatus(string status);
};

#endif // end of include guard
