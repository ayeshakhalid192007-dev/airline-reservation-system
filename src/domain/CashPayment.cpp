// CashPayment.cpp - Implementation of CashPayment class
// This file contains the method definitions for CashPayment class

#include "CashPayment.h" // include the CashPayment header file
#include <iostream> // include iostream for console output

using namespace std; // use standard namespace

// Constructor implementation - initializes cash payment with all details
// Calls base class Payment constructor using initialization list
CashPayment::CashPayment(string id, double amt, string date, string status, double received, double change)
    : Payment(id, amt, date, status) // call Payment base class constructor
{
    amountReceived = received; // assign amount received parameter to member variable
    changeGiven = change; // assign change given parameter to member variable
}

// Implementation of processPayment pure virtual method
// Processes the cash payment transaction
bool CashPayment::processPayment()
{
    bool isValid = false; // declare boolean variable to store validation result
    isValid = validatePayment(); // call validatePayment to check if cash is sufficient

    if (isValid == false) // check if validation failed
    {
        cout << "Payment processing failed: Insufficient cash amount" << endl; // display error message
        setPaymentStatus("failed"); // update payment status to failed
        return false; // return false to indicate payment failed
    }

    // Calculate change to be given back to customer
    double calculatedChange = 0.0; // declare variable to store calculated change
    double paymentAmount = 0.0; // declare variable to store payment amount
    paymentAmount = getAmount(); // get payment amount from base class
    calculatedChange = amountReceived - paymentAmount; // calculate change by subtracting amount from received

    changeGiven = calculatedChange; // update change given member variable

    cout << "Processing cash payment..." << endl; // display processing message
    cout << "Amount Received: $" << amountReceived << endl; // display amount received
    cout << "Payment Amount: $" << paymentAmount << endl; // display payment amount
    cout << "Change to Return: $" << changeGiven << endl; // display change amount
    cout << "Cash payment completed successfully!" << endl; // display success message

    setPaymentStatus("completed"); // update payment status to completed
    return true; // return true to indicate payment successful
}

// Implementation of validatePayment pure virtual method
// Validates cash payment details before processing
bool CashPayment::validatePayment()
{
    double paymentAmount = 0.0; // declare variable to store payment amount
    paymentAmount = getAmount(); // get payment amount from base class

    bool isSufficient = false; // declare boolean for validation result

    // Check if amount received is greater than or equal to payment amount
    if (amountReceived >= paymentAmount) // compare received amount with required amount
    {
        isSufficient = true; // mark validation as passed
    }
    else // received amount is less than required amount
    {
        cout << "Insufficient cash: Received $" << amountReceived << " but need $" << paymentAmount << endl; // display error message
        isSufficient = false; // mark validation as failed
    }

    return isSufficient; // return validation result
}

// Override of displayPaymentInfo virtual method
// Displays payment information including cash specific details
void CashPayment::displayPaymentInfo()
{
    Payment::displayPaymentInfo(); // call base class method to display common payment info

    // Display cash payment specific information
    cout << "Payment Type: Cash" << endl; // display payment type
    cout << "Amount Received: $" << amountReceived << endl; // display amount received from customer
    cout << "Change Given: $" << changeGiven << endl; // display change returned to customer
    cout << "========================================" << endl; // print separator line
}

// Getter method - returns amount received
double CashPayment::getAmountReceived()
{
    return amountReceived; // return the amount received member variable
}

// Setter method - updates amount received
void CashPayment::setAmountReceived(double received)
{
    amountReceived = received; // assign new amount received to member variable
}

// Getter method - returns change given
double CashPayment::getChangeGiven()
{
    return changeGiven; // return the change given member variable
}

// Setter method - updates change given
void CashPayment::setChangeGiven(double change)
{
    changeGiven = change; // assign new change amount to member variable
}
