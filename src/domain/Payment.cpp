// Payment.cpp - Implementation of Payment abstract base class
// This file contains the method definitions for Payment class

#include "Payment.h" // include the Payment header file
#include <iostream> // include iostream for console output

using namespace std; // use standard namespace

// Constructor implementation - initializes all payment data members
Payment::Payment(string id, double amt, string date, string status)
{
    paymentId = id; // assign payment ID parameter to member variable
    amount = amt; // assign amount parameter to member variable
    paymentDate = date; // assign date parameter to member variable
    paymentStatus = status; // assign status parameter to member variable
}

// Virtual destructor implementation - ensures proper cleanup in derived classes
Payment::~Payment()
{
    // destructor body is empty but must exist for proper polymorphic deletion
}

// Display payment information - virtual method with default implementation
void Payment::displayPaymentInfo()
{
    cout << "========================================" << endl; // print separator line
    cout << "Payment ID: " << paymentId << endl; // display payment ID
    cout << "Amount: $" << amount << endl; // display payment amount with dollar sign
    cout << "Date: " << paymentDate << endl; // display payment date
    cout << "Status: " << paymentStatus << endl; // display payment status
    cout << "========================================" << endl; // print separator line
}

// Getter method - returns payment ID
string Payment::getPaymentId()
{
    return paymentId; // return the payment ID member variable
}

// Setter method - updates payment ID
void Payment::setPaymentId(string id)
{
    paymentId = id; // assign new ID to payment ID member variable
}

// Getter method - returns payment amount
double Payment::getAmount()
{
    return amount; // return the amount member variable
}

// Setter method - updates payment amount
void Payment::setAmount(double amt)
{
    amount = amt; // assign new amount to amount member variable
}

// Getter method - returns payment date
string Payment::getPaymentDate()
{
    return paymentDate; // return the payment date member variable
}

// Setter method - updates payment date
void Payment::setPaymentDate(string date)
{
    paymentDate = date; // assign new date to payment date member variable
}

// Getter method - returns payment status
string Payment::getPaymentStatus()
{
    return paymentStatus; // return the payment status member variable
}

// Setter method - updates payment status
void Payment::setPaymentStatus(string status)
{
    paymentStatus = status; // assign new status to payment status member variable
}

// NOTE: processPayment() and validatePayment() are NOT implemented here
// They are pure virtual methods (= 0) and MUST be implemented by derived classes
// CreditCardPayment, CashPayment, and PointsPayment will provide their own implementations
