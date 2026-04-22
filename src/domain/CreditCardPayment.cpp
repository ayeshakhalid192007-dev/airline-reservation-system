// CreditCardPayment.cpp - Implementation of CreditCardPayment class
// This file contains the method definitions for CreditCardPayment class

#include "CreditCardPayment.h" // include the CreditCardPayment header file
#include <iostream> // include iostream for console output

using namespace std; // use standard namespace

// Constructor implementation - initializes credit card payment with all details
// Calls base class Payment constructor using initialization list
CreditCardPayment::CreditCardPayment(string id, double amt, string date, string status, string cardNum, string holderName, string expiry, string cvvCode)
    : Payment(id, amt, date, status) // call Payment base class constructor
{
    cardNumber = cardNum; // assign card number parameter to member variable
    cardHolderName = holderName; // assign card holder name parameter to member variable
    expiryDate = expiry; // assign expiry date parameter to member variable
    cvv = cvvCode; // assign CVV code parameter to member variable
}

// Implementation of processPayment pure virtual method
// Processes the credit card payment transaction
bool CreditCardPayment::processPayment()
{
    bool isValid = false; // declare boolean variable to store validation result
    isValid = validatePayment(); // call validatePayment to check card details

    if (isValid == false) // check if validation failed
    {
        cout << "Payment processing failed: Invalid card details" << endl; // display error message
        setPaymentStatus("failed"); // update payment status to failed
        return false; // return false to indicate payment failed
    }

    // Simulate payment processing (in real system would connect to payment gateway)
    cout << "Processing credit card payment..." << endl; // display processing message
    cout << "Contacting payment gateway..." << endl; // display gateway connection message
    cout << "Transaction approved!" << endl; // display success message

    setPaymentStatus("completed"); // update payment status to completed
    return true; // return true to indicate payment successful
}

// Implementation of validatePayment pure virtual method
// Validates credit card details before processing
bool CreditCardPayment::validatePayment()
{
    bool isCardNumberValid = false; // declare boolean for card number validation
    bool isExpiryValid = false; // declare boolean for expiry date validation
    bool isCvvValid = false; // declare boolean for CVV validation

    // Validate card number length (should be 16 digits)
    int cardLength = 0; // declare variable to store card number length
    cardLength = cardNumber.length(); // get length of card number string

    if (cardLength == 16) // check if card number has exactly 16 digits
    {
        isCardNumberValid = true; // mark card number as valid
    }
    else // card number length is not 16
    {
        cout << "Invalid card number: Must be 16 digits" << endl; // display error message
        isCardNumberValid = false; // mark card number as invalid
    }

    // Validate expiry date format (should be MM/YY format, length 5)
    int expiryLength = 0; // declare variable to store expiry date length
    expiryLength = expiryDate.length(); // get length of expiry date string

    if (expiryLength == 5) // check if expiry date has correct length
    {
        isExpiryValid = true; // mark expiry date as valid
    }
    else // expiry date format is incorrect
    {
        cout << "Invalid expiry date: Must be in MM/YY format" << endl; // display error message
        isExpiryValid = false; // mark expiry date as invalid
    }

    // Validate CVV length (should be 3 or 4 digits)
    int cvvLength = 0; // declare variable to store CVV length
    cvvLength = cvv.length(); // get length of CVV string

    if (cvvLength == 3 || cvvLength == 4) // check if CVV has 3 or 4 digits
    {
        isCvvValid = true; // mark CVV as valid
    }
    else // CVV length is incorrect
    {
        cout << "Invalid CVV: Must be 3 or 4 digits" << endl; // display error message
        isCvvValid = false; // mark CVV as invalid
    }

    // Check if all validations passed
    bool allValid = false; // declare boolean for overall validation result
    if (isCardNumberValid && isExpiryValid && isCvvValid) // check if all three validations passed
    {
        allValid = true; // mark overall validation as passed
    }
    else // at least one validation failed
    {
        allValid = false; // mark overall validation as failed
    }

    return allValid; // return overall validation result
}

// Override of displayPaymentInfo virtual method
// Displays payment information including credit card specific details
void CreditCardPayment::displayPaymentInfo()
{
    Payment::displayPaymentInfo(); // call base class method to display common payment info

    // Display credit card specific information
    cout << "Payment Type: Credit Card" << endl; // display payment type
    cout << "Card Holder: " << cardHolderName << endl; // display card holder name

    // Display masked card number (show only last 4 digits for security)
    string maskedCard = ""; // declare string for masked card number
    maskedCard = "************"; // add 12 asterisks for first 12 digits
    int cardLength = 0; // declare variable for card number length
    cardLength = cardNumber.length(); // get card number length

    if (cardLength >= 4) // check if card number has at least 4 digits
    {
        string lastFour = ""; // declare string for last 4 digits
        lastFour = cardNumber.substr(cardLength - 4, 4); // extract last 4 digits
        maskedCard = maskedCard + lastFour; // append last 4 digits to masked card
    }

    cout << "Card Number: " << maskedCard << endl; // display masked card number
    cout << "Expiry Date: " << expiryDate << endl; // display expiry date
    cout << "========================================" << endl; // print separator line
}

// Getter method - returns card number
string CreditCardPayment::getCardNumber()
{
    return cardNumber; // return the card number member variable
}

// Setter method - updates card number
void CreditCardPayment::setCardNumber(string cardNum)
{
    cardNumber = cardNum; // assign new card number to member variable
}

// Getter method - returns card holder name
string CreditCardPayment::getCardHolderName()
{
    return cardHolderName; // return the card holder name member variable
}

// Setter method - updates card holder name
void CreditCardPayment::setCardHolderName(string holderName)
{
    cardHolderName = holderName; // assign new card holder name to member variable
}

// Getter method - returns expiry date
string CreditCardPayment::getExpiryDate()
{
    return expiryDate; // return the expiry date member variable
}

// Setter method - updates expiry date
void CreditCardPayment::setExpiryDate(string expiry)
{
    expiryDate = expiry; // assign new expiry date to member variable
}

// Getter method - returns CVV code
string CreditCardPayment::getCvv()
{
    return cvv; // return the CVV member variable
}

// Setter method - updates CVV code
void CreditCardPayment::setCvv(string cvvCode)
{
    cvv = cvvCode; // assign new CVV code to member variable
}
