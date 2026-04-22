// CreditCardPayment.h - Derived class for credit card payment processing
// This file defines the CreditCardPayment class that inherits from Payment

#ifndef CREDITCARDPAYMENT_H // include guard to prevent multiple inclusion
#define CREDITCARDPAYMENT_H // define the header guard

#include "Payment.h" // include the Payment base class header
#include <string> // include string library for string data type

using namespace std; // use standard namespace to avoid writing std:: prefix

// CreditCardPayment class - handles credit card payment transactions
// Inherits from Payment abstract base class using public inheritance
class CreditCardPayment : public Payment
{
private: // private members accessible only within this class
    string cardNumber; // credit card number (16 digits)
    string cardHolderName; // name of the card holder as printed on card
    string expiryDate; // card expiry date in format MM/YY
    string cvv; // card verification value (3 or 4 digits on back of card)

public: // public methods accessible from outside the class
    // Constructor with parameters - calls base class constructor
    // Initializes credit card payment with payment details and card information
    CreditCardPayment(string id, double amt, string date, string status, string cardNum, string holderName, string expiry, string cvvCode);

    // Implementation of pure virtual method from Payment base class
    // Processes the credit card payment transaction
    // Returns true if payment successful, false otherwise
    bool processPayment();

    // Implementation of pure virtual method from Payment base class
    // Validates credit card details before processing payment
    // Returns true if card details are valid, false otherwise
    bool validatePayment();

    // Override of virtual method from Payment base class
    // Displays payment information including credit card specific details
    void displayPaymentInfo();

    // Getter method to retrieve card number
    string getCardNumber();

    // Setter method to update card number
    void setCardNumber(string cardNum);

    // Getter method to retrieve card holder name
    string getCardHolderName();

    // Setter method to update card holder name
    void setCardHolderName(string holderName);

    // Getter method to retrieve expiry date
    string getExpiryDate();

    // Setter method to update expiry date
    void setExpiryDate(string expiry);

    // Getter method to retrieve CVV code
    string getCvv();

    // Setter method to update CVV code
    void setCvv(string cvvCode);
};

#endif // end of include guard
