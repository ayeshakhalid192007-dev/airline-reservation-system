// PointsPayment.cpp - Implementation of PointsPayment class
// This file contains the method definitions for PointsPayment class

#include "PointsPayment.h" // include the PointsPayment header file
#include <iostream> // include iostream for console output

using namespace std; // use standard namespace

// Constructor implementation - initializes points payment with all details
// Calls base class Payment constructor using initialization list
PointsPayment::PointsPayment(string id, double amt, string date, string status, int points, string custId, double rate)
    : Payment(id, amt, date, status) // call Payment base class constructor
{
    pointsUsed = points; // assign points used parameter to member variable
    customerId = custId; // assign customer ID parameter to member variable
    conversionRate = rate; // assign conversion rate parameter to member variable
}

// Implementation of processPayment pure virtual method
// Processes the points payment transaction
bool PointsPayment::processPayment()
{
    bool isValid = false; // declare boolean variable to store validation result
    isValid = validatePayment(); // call validatePayment to check if customer has enough points

    if (isValid == false) // check if validation failed
    {
        cout << "Payment processing failed: Insufficient loyalty points" << endl; // display error message
        setPaymentStatus("failed"); // update payment status to failed
        return false; // return false to indicate payment failed
    }

    // Simulate points deduction from customer account
    cout << "Processing points payment..." << endl; // display processing message
    cout << "Customer ID: " << customerId << endl; // display customer ID
    cout << "Deducting " << pointsUsed << " points from account..." << endl; // display points deduction message
    cout << "Points payment completed successfully!" << endl; // display success message

    setPaymentStatus("completed"); // update payment status to completed
    return true; // return true to indicate payment successful
}

// Implementation of validatePayment pure virtual method
// Validates points payment details before processing
bool PointsPayment::validatePayment()
{
    // Calculate required points based on payment amount and conversion rate
    double paymentAmount = 0.0; // declare variable to store payment amount
    paymentAmount = getAmount(); // get payment amount from base class

    int requiredPoints = 0; // declare variable to store required points
    double calculatedPoints = 0.0; // declare variable for calculation
    calculatedPoints = paymentAmount * conversionRate; // calculate points needed (amount * rate)
    requiredPoints = (int)calculatedPoints; // convert to integer points

    bool hasSufficientPoints = false; // declare boolean for validation result

    // Check if customer has enough points for this payment
    if (pointsUsed >= requiredPoints) // compare points used with required points
    {
        hasSufficientPoints = true; // mark validation as passed
    }
    else // customer does not have enough points
    {
        cout << "Insufficient points: Need " << requiredPoints << " points but only " << pointsUsed << " available" << endl; // display error message
        hasSufficientPoints = false; // mark validation as failed
    }

    return hasSufficientPoints; // return validation result
}

// Override of displayPaymentInfo virtual method
// Displays payment information including points specific details
void PointsPayment::displayPaymentInfo()
{
    Payment::displayPaymentInfo(); // call base class method to display common payment info

    // Display points payment specific information
    cout << "Payment Type: Loyalty Points" << endl; // display payment type
    cout << "Customer ID: " << customerId << endl; // display customer ID
    cout << "Points Used: " << pointsUsed << endl; // display number of points used
    cout << "Conversion Rate: " << conversionRate << " points per dollar" << endl; // display conversion rate
    cout << "========================================" << endl; // print separator line
}

// Getter method - returns points used
int PointsPayment::getPointsUsed()
{
    return pointsUsed; // return the points used member variable
}

// Setter method - updates points used
void PointsPayment::setPointsUsed(int points)
{
    pointsUsed = points; // assign new points value to member variable
}

// Getter method - returns customer ID
string PointsPayment::getCustomerId()
{
    return customerId; // return the customer ID member variable
}

// Setter method - updates customer ID
void PointsPayment::setCustomerId(string custId)
{
    customerId = custId; // assign new customer ID to member variable
}

// Getter method - returns conversion rate
double PointsPayment::getConversionRate()
{
    return conversionRate; // return the conversion rate member variable
}

// Setter method - updates conversion rate
void PointsPayment::setConversionRate(double rate)
{
    conversionRate = rate; // assign new conversion rate to member variable
}
