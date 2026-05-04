/*
 * File: helpers.cpp
 * Purpose: Helper functions for airline reservation operations
 * Description: Contains all service functions for booking, cancellation, viewing, etc.
 */

#ifndef HELPERS_CPP // header guard to prevent multiple inclusion
#define HELPERS_CPP // define the header guard

#include <iostream> // for input/output operations
#include <string> // for string data type
#include <limits> // for numeric_limits to clear input buffer
#include "../domain/Airline.h" // for Airline class
#include "../domain/Flight.h" // for Flight class
#include "../domain/Booking.h" // for Booking class
#include "../domain/Passenger.h" // for Passenger class
#include "../domain/User.h" // for User base class
#include "../domain/Admin.h" // for Admin derived class
#include "../domain/Customer.h" // for Customer derived class
#include "../domain/Payment.h" // for Payment base class
#include "../domain/CreditCardPayment.h" // for CreditCardPayment derived class
#include "../domain/CashPayment.h" // for CashPayment derived class
#include "../domain/PointsPayment.h" // for PointsPayment derived class

using namespace std; // use standard namespace

/*
 * Function: clearInputBuffer
 * Purpose: Clears the input buffer after invalid input
 */
void clearInputBuffer()
{
    cin.clear(); // clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore remaining characters in buffer until newline
}

/*
 * Function: viewAllFlights
 * Purpose: Displays all flights in the airline
 * Parameters: airline - reference to Airline object
 */
void viewAllFlights(Airline& airline)
{
    cout << "==========================================" << endl; // print separator
    cout << "         ALL AVAILABLE FLIGHTS" << endl; // print section title
    cout << "==========================================" << endl; // print separator

    airline.displayAllFlights(); // call airline method to display all flights

    cout << "==========================================" << endl; // print separator
}

/*
 * Function: searchFlightsByRoute
 * Purpose: Searches and displays flights by origin and destination
 * Parameters: airline - reference to Airline object
 */
void searchFlightsByRoute(Airline& airline)
{
    string origin = ""; // stores origin city input
    string destination = ""; // stores destination city input

    clearInputBuffer(); // clear input buffer before reading strings

    cout << "Enter origin city: "; // prompt for origin
    getline(cin, origin); // read full line including spaces

    cout << "Enter destination city: "; // prompt for destination
    getline(cin, destination); // read full line including spaces

    cout << "\n==========================================" << endl; // print separator
    cout << "         SEARCH RESULTS" << endl; // print section title
    cout << "==========================================" << endl; // print separator

    airline.searchFlights(origin, destination); // call airline method to search flights

    cout << "==========================================" << endl; // print separator
}

/*
 * Function: bookSeat
 * Purpose: Handles the seat booking process
 * Parameters: airline - reference to Airline object
 */
void bookSeat(Airline& airline)
{
    string flightNumber = ""; // stores flight number input
    string passengerName = ""; // stores passenger name input
    int passengerAge = 0; // stores passenger age input
    string passengerId = ""; // stores passenger ID input
    string seatClass = ""; // stores seat class preference

    clearInputBuffer(); // clear input buffer before reading strings

    cout << "Enter flight number: "; // prompt for flight number
    getline(cin, flightNumber); // read flight number

    int flightIndex = airline.findFlight(flightNumber); // find flight in airline

    if (flightIndex == -1) // check if flight not found
    {
        cout << "\nError: Flight not found!\n" << endl; // show error message
        return; // exit function
    }

    cout << "Enter passenger name: "; // prompt for passenger name
    getline(cin, passengerName); // read passenger name

    cout << "Enter passenger age: "; // prompt for passenger age
    cin >> passengerAge; // read passenger age

    if (cin.fail() || passengerAge < 0 || passengerAge > 150) // validate age input
    {
        clearInputBuffer(); // clear error state
        cout << "\nError: Invalid age! Please enter a valid age.\n" << endl; // show error
        return; // exit function
    }

    clearInputBuffer(); // clear buffer after reading integer

    cout << "Enter passenger ID: "; // prompt for passenger ID
    getline(cin, passengerId); // read passenger ID

    cout << "Enter seat class (economy/business): "; // prompt for seat class
    getline(cin, seatClass); // read seat class

    if (seatClass != "economy" && seatClass != "business") // validate seat class
    {
        cout << "\nError: Invalid seat class! Please enter 'economy' or 'business'.\n" << endl; // show error
        return; // exit function
    }

    Passenger newPassenger(passengerName, passengerAge, passengerId); // create passenger object

    cout << "\n--- Payment Information ---" << endl; // print payment section header
    cout << "Select payment method:" << endl; // prompt for payment method
    cout << "1. Credit Card" << endl; // option 1
    cout << "2. Cash" << endl; // option 2
    cout << "3. Loyalty Points" << endl; // option 3
    cout << "Enter choice: "; // prompt for choice

    int paymentChoice = 0; // stores payment method choice
    cin >> paymentChoice; // read payment choice

    if (cin.fail()) // check if input is invalid
    {
        clearInputBuffer(); // clear error state
        cout << "\nError: Invalid payment method!\n" << endl; // show error
        return; // exit function
    }

    clearInputBuffer(); // clear buffer after reading integer

    double amount = 0.0; // stores payment amount

    if (seatClass == "economy") // check if economy class
    {
        amount = 5000.0; // set economy class price
    }
    else // business class
    {
        amount = 12000.0; // set business class price
    }

    Payment* payment = nullptr; // pointer to Payment base class for polymorphism

    if (paymentChoice == 1) // credit card payment
    {
        string cardNumber = ""; // stores card number
        string cardHolder = ""; // stores card holder name
        string expiryDate = ""; // stores expiry date
        string cvv = ""; // stores CVV code

        cout << "Enter card number: "; // prompt for card number
        getline(cin, cardNumber); // read card number

        cout << "Enter card holder name: "; // prompt for card holder
        getline(cin, cardHolder); // read card holder name

        cout << "Enter expiry date (MM/YY): "; // prompt for expiry date
        getline(cin, expiryDate); // read expiry date

        cout << "Enter CVV: "; // prompt for CVV
        getline(cin, cvv); // read CVV

        payment = new CreditCardPayment("PAY-001", amount, "2026-04-23", "pending", cardNumber, cardHolder, expiryDate, cvv); // create credit card payment object
    }
    else if (paymentChoice == 2) // cash payment
    {
        string receiptNumber = ""; // stores receipt number
        string collectorName = ""; // stores collector name

        double cashReceived = amount + 500.0; // calculate cash received (amount plus extra)
        double changeAmount = 500.0; // calculate change to return

        payment = new CashPayment("PAY-002", amount, "2026-04-23", "pending", cashReceived, changeAmount); // create cash payment object
    }
    else if (paymentChoice == 3) // points payment
    {
        string membershipId = ""; // stores membership ID
        int pointsUsed = 0; // stores points to use
        double conversionRate = 0.01; // stores conversion rate (100 points = $1)

        cout << "Enter membership ID: "; // prompt for membership ID
        getline(cin, membershipId); // read membership ID

        cout << "Enter points to use: "; // prompt for points to use
        cin >> pointsUsed; // read points to use

        if (cin.fail() || pointsUsed < 0) // validate points input
        {
            clearInputBuffer(); // clear error state
            cout << "\nError: Invalid points!\n" << endl; // show error
            delete payment; // free memory if allocated
            return; // exit function
        }

        clearInputBuffer(); // clear buffer after reading integer

        payment = new PointsPayment("PAY-003", amount, "2026-04-23", "pending", pointsUsed, membershipId, conversionRate); // create points payment object
    }
    else // invalid payment choice
    {
        cout << "\nError: Invalid payment method!\n" << endl; // show error
        return; // exit function
    }

    if (payment != nullptr) // check if payment object created
    {
        cout << "\n--- Processing Payment ---" << endl; // print processing header

        if (payment->validatePayment()) // validate payment details
        {
            if (payment->processPayment()) // process the payment
            {
                cout << "\nPayment successful!" << endl; // show success message

                cout << "\n==========================================" << endl; // print separator
                cout << "         BOOKING IN PROGRESS" << endl; // print section title
                cout << "==========================================" << endl; // print separator

                Flight* flightPtr = &airline.flights[flightIndex]; // get pointer to the flight object

                int seatNumber = flightPtr->findAvailableSeat(seatClass); // find available seat of requested class

                if (seatNumber == -1) // check if no seat available
                {
                    cout << "\nError: No available seats in " << seatClass << " class!\n" << endl; // show error
                    delete payment; // free payment object
                    payment = nullptr; // set pointer to null
                    return; // exit function
                }

                Booking newBooking(newPassenger, flightNumber, seatNumber, seatClass, amount); // create booking object with assigned seat

                bool bookingAdded = flightPtr->addBooking(newBooking); // add booking to flight

                if (bookingAdded) // check if booking was added successfully
                {
                    cout << "\nBooking created successfully!" << endl; // show success message
                    cout << "PNR Number: " << newBooking.getPnr() << endl; // display PNR number
                    cout << "Seat Number: " << seatNumber << endl; // display seat number
                    cout << "Seat Class: " << seatClass << endl; // display seat class
                    cout << "Amount Paid: Rs. " << amount << endl; // display amount
                    cout << "Please save this PNR for future reference.\n" << endl; // remind user to save PNR
                }
                else // booking failed to add
                {
                    cout << "\nError: Failed to add booking to flight!\n" << endl; // show error
                }
            }
            else // payment processing failed
            {
                cout << "\nPayment processing failed!\n" << endl; // show error message
            }
        }
        else // payment validation failed
        {
            cout << "\nPayment validation failed!\n" << endl; // show error message
        }

        delete payment; // free dynamically allocated payment object
        payment = nullptr; // set pointer to null
    }
}

/*
 * Function: cancelBooking
 * Purpose: Handles booking cancellation
 * Parameters: airline - reference to Airline object
 */
void cancelBooking(Airline& airline)
{
    string pnr = ""; // stores PNR number input

    clearInputBuffer(); // clear input buffer before reading strings

    cout << "Enter PNR number: "; // prompt for PNR number
    getline(cin, pnr); // read PNR number

    cout << "\n==========================================" << endl; // print separator
    cout << "         CANCELLATION IN PROGRESS" << endl; // print section title
    cout << "==========================================" << endl; // print separator

    cout << "\nPlease provide the flight number for this booking." << endl; // ask for flight number

    string flightNumber = ""; // stores flight number
    cout << "Enter flight number: "; // prompt for flight number
    getline(cin, flightNumber); // read flight number

    int flightIndex = airline.findFlight(flightNumber); // find flight in airline

    if (flightIndex == -1) // check if flight not found
    {
        cout << "\nError: Flight not found!\n" << endl; // show error message
        return; // exit function
    }

    Flight* flightPtr = &airline.flights[flightIndex]; // get pointer to the flight object

    bool cancelled = flightPtr->cancelBooking(pnr); // attempt to cancel booking

    if (cancelled) // check if cancellation successful
    {
        cout << "\nBooking cancelled successfully!" << endl; // show success message
        cout << "PNR: " << pnr << endl; // display PNR
        cout << "Seat has been released and is now available.\n" << endl; // show seat released message
    }
    else // cancellation failed
    {
        cout << "\nError: Booking not found with PNR: " << pnr << "\n" << endl; // show error message
    }
}

/*
 * Function: viewBookingDetails
 * Purpose: Displays booking details and prints ticket
 * Parameters: airline - reference to Airline object
 */
void viewBookingDetails(Airline& airline)
{
    string pnr = ""; // stores PNR number input

    clearInputBuffer(); // clear input buffer before reading strings

    cout << "Enter PNR number: "; // prompt for PNR number
    getline(cin, pnr); // read PNR number

    cout << "\n==========================================" << endl; // print separator
    cout << "         BOOKING DETAILS" << endl; // print section title
    cout << "==========================================" << endl; // print separator

    bool bookingFound = false; // flag to track if booking is found
    int foundFlightIndex = -1; // stores index of flight containing the booking
    int foundBookingIndex = -1; // stores index of found booking

    int flightIdx = 0; // initialize flight loop counter
    while (flightIdx < airline.getFlightCount()) // loop through all flights
    {
        Flight* flightPtr = &airline.flights[flightIdx]; // get pointer to current flight

        if (flightPtr->bookings == nullptr) // check if bookings array is not allocated
        {
            flightIdx = flightIdx + 1; // move to next flight
            continue; // skip to next iteration
        }

        int bookingIdx = 0; // initialize booking loop counter
        while (bookingIdx < 50) // loop through maximum possible bookings
        {
            Booking currentBooking = flightPtr->bookings[bookingIdx]; // get booking at current index
            string currentPnr = currentBooking.getPnr(); // get PNR of current booking
            string status = currentBooking.getStatus(); // get booking status

            bool pnrMatches = (currentPnr == pnr); // check if PNR matches
            bool isActive = (status != "Cancelled"); // check if booking is active

            if (pnrMatches && isActive) // if PNR matches and booking is active
            {
                bookingFound = true; // set flag to true
                foundFlightIndex = flightIdx; // store the flight index
                foundBookingIndex = bookingIdx; // store the booking index
                break; // exit booking loop
            }

            bookingIdx = bookingIdx + 1; // increment booking counter
        }

        if (bookingFound) // if booking found, no need to check other flights
        {
            break; // exit flight loop
        }

        flightIdx = flightIdx + 1; // increment flight counter
    }

    if (bookingFound) // check if booking was found
    {
        Flight* flightPtr = &airline.flights[foundFlightIndex]; // get pointer to the flight
        Booking foundBooking = flightPtr->bookings[foundBookingIndex]; // get the found booking
        Passenger passenger = foundBooking.getPassenger(); // get passenger details

        cout << "+------------------------------------------+" << endl; // print ticket top border
        cout << "|          BOARDING PASS / TICKET          |" << endl; // print ticket header
        cout << "+------------------------------------------+" << endl; // print separator
        cout << "|  PNR Number   : " << foundBooking.getPnr() << "                  |" << endl; // print PNR
        cout << "|  Passenger    : " << passenger.getName() << "             |" << endl; // print passenger name
        cout << "|  Flight       : " << foundBooking.getFlightNumber() << "                   |" << endl; // print flight number
        cout << "|  From         : " << flightPtr->getOrigin() << "                   |" << endl; // print origin
        cout << "|  To           : " << flightPtr->getDestination() << "                  |" << endl; // print destination
        cout << "|  Date         : " << flightPtr->getDepartureDate() << "               |" << endl; // print date
        cout << "|  Seat Number  : " << foundBooking.getSeatNumber() << "                        |" << endl; // print seat number
        cout << "|  Seat Class   : " << foundBooking.getSeatClass() << "                  |" << endl; // print seat class
        cout << "|  Amount Paid  : Rs. " << foundBooking.getAmountPaid() << "              |" << endl; // print amount
        cout << "+------------------------------------------+" << endl; // print separator
        cout << "|         HAVE A PLEASANT JOURNEY          |" << endl; // print footer message
        cout << "+------------------------------------------+\n" << endl; // print ticket bottom border
    }
    else // booking not found
    {
        cout << "Error: Booking not found with PNR: " << pnr << "\n" << endl; // show error message
    }
}

/*
 * Function: displayFlightManifest
 * Purpose: Displays passenger manifest for a flight
 * Parameters: airline - reference to Airline object
 */
void displayFlightManifest(Airline& airline)
{
    string flightNumber = ""; // stores flight number input

    clearInputBuffer(); // clear input buffer before reading strings

    cout << "Enter flight number: "; // prompt for flight number
    getline(cin, flightNumber); // read flight number

    int flightIndex = airline.findFlight(flightNumber); // find flight in airline

    if (flightIndex == -1) // check if flight not found
    {
        cout << "\nError: Flight not found!\n" << endl; // show error message
        return; // exit function
    }

    cout << "\n==========================================" << endl; // print separator
    cout << "         PASSENGER MANIFEST" << endl; // print section title
    cout << "==========================================" << endl; // print separator

    Flight* flightPtr = &airline.flights[flightIndex]; // get pointer to the flight object

    flightPtr->displayManifest(); // call flight method to display manifest
}

/*
 * Function: testUserHierarchy
 * Purpose: Demonstrates polymorphism with User hierarchy (Admin and Customer)
 */
void testUserHierarchy()
{
    cout << "==========================================" << endl; // print separator
    cout << "      USER HIERARCHY DEMONSTRATION" << endl; // print section title
    cout << "==========================================" << endl; // print separator
    cout << "Demonstrating Polymorphism with User Base Class\n" << endl; // print description

    Admin admin("A001", "admin123", "admin@123", "admin@airline.com", "John Admin", "0300-1234567", "Super Admin", "Operations"); // create admin object
    Customer customer("C001", "customer123", "pass@123", "customer@email.com", "Sarah Customer", "0301-9876543"); // create customer object

    User* userPtr = nullptr; // pointer to User base class for polymorphism

    cout << "--- Testing Admin User ---" << endl; // print test section
    userPtr = &admin; // point to admin object (upcasting)
    userPtr->displayInfo(); // call virtual method - executes Admin version
    cout << endl; // blank line

    cout << "--- Testing Customer User ---" << endl; // print test section
    userPtr = &customer; // point to customer object (upcasting)
    userPtr->displayInfo(); // call virtual method - executes Customer version
    cout << endl; // blank line

    cout << "--- Testing Login Functionality ---" << endl; // print test section

    bool adminLogin = admin.login("admin123", "admin@123"); // test admin login
    if (adminLogin) // check if login successful
    {
        cout << "Admin login: SUCCESS" << endl; // show success
    }
    else // login failed
    {
        cout << "Admin login: FAILED" << endl; // show failure
    }

    bool customerLogin = customer.login("customer123", "pass@123"); // test customer login
    if (customerLogin) // check if login successful
    {
        cout << "Customer login: SUCCESS" << endl; // show success
    }
    else // login failed
    {
        cout << "Customer login: FAILED" << endl; // show failure
    }

    cout << "\n==========================================" << endl; // print separator
    cout << "Polymorphism demonstrated successfully!" << endl; // print success message
    cout << "==========================================" << endl; // print separator
}

/*
 * Function: testPaymentMethods
 * Purpose: Demonstrates polymorphism with Payment hierarchy
 */
void testPaymentMethods()
{
    cout << "==========================================" << endl; // print separator
    cout << "     PAYMENT METHODS DEMONSTRATION" << endl; // print section title
    cout << "==========================================" << endl; // print separator
    cout << "Demonstrating Polymorphism with Payment Base Class\n" << endl; // print description

    CreditCardPayment creditCard("PAY-CC-001", 15000.0, "2026-04-23", "pending", "1234-5678-9012-3456", "Ali Ahmed", "12/28", "123"); // create credit card payment
    CashPayment cash("PAY-CASH-001", 8000.0, "2026-04-23", "pending", 8500.0, 500.0); // create cash payment with received and change amounts
    PointsPayment points("PAY-PTS-001", 10000.0, "2026-04-23", "pending", 100000, "FREQ-12345", 0.01); // create points payment with points, customer ID, and rate

    Payment* paymentPtr = nullptr; // pointer to Payment base class for polymorphism

    cout << "--- Testing Credit Card Payment ---" << endl; // print test section
    paymentPtr = &creditCard; // point to credit card object (upcasting)
    paymentPtr->displayPaymentInfo(); // call virtual method - executes CreditCardPayment version

    if (paymentPtr->validatePayment()) // validate payment
    {
        cout << "Validation: PASSED" << endl; // show validation success

        if (paymentPtr->processPayment()) // process payment
        {
            cout << "Processing: SUCCESS" << endl; // show processing success
        }
        else // processing failed
        {
            cout << "Processing: FAILED" << endl; // show processing failure
        }
    }
    else // validation failed
    {
        cout << "Validation: FAILED" << endl; // show validation failure
    }
    cout << endl; // blank line

    cout << "--- Testing Cash Payment ---" << endl; // print test section
    paymentPtr = &cash; // point to cash object (upcasting)
    paymentPtr->displayPaymentInfo(); // call virtual method - executes CashPayment version

    if (paymentPtr->validatePayment()) // validate payment
    {
        cout << "Validation: PASSED" << endl; // show validation success

        if (paymentPtr->processPayment()) // process payment
        {
            cout << "Processing: SUCCESS" << endl; // show processing success
        }
        else // processing failed
        {
            cout << "Processing: FAILED" << endl; // show processing failure
        }
    }
    else // validation failed
    {
        cout << "Validation: FAILED" << endl; // show validation failure
    }
    cout << endl; // blank line

    cout << "--- Testing Points Payment ---" << endl; // print test section
    paymentPtr = &points; // point to points object (upcasting)
    paymentPtr->displayPaymentInfo(); // call virtual method - executes PointsPayment version

    if (paymentPtr->validatePayment()) // validate payment
    {
        cout << "Validation: PASSED" << endl; // show validation success

        if (paymentPtr->processPayment()) // process payment
        {
            cout << "Processing: SUCCESS" << endl; // show processing success
        }
        else // processing failed
        {
            cout << "Processing: FAILED" << endl; // show processing failure
        }
    }
    else // validation failed
    {
        cout << "Validation: FAILED" << endl; // show validation failure
    }
    cout << endl; // blank line

    cout << "==========================================" << endl; // print separator
    cout << "Polymorphism demonstrated successfully!" << endl; // print success message
    cout << "==========================================" << endl; // print separator
}

#endif // end of header guard
