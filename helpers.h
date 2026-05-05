// =============================================================
// File: helpers.h
// Project: Airline Reservation System
// Purpose: Contains ALL helper functions for menus, input
//          validation, and airline operations
// Rules: Each function does ONE specific task, max ~20 lines
// =============================================================

#ifndef HELPERS_H // prevents this file from being included twice
#define HELPERS_H // defines the include guard

#include <iostream> // for cout and cin
#include <string>   // for string data type

using namespace std; // allows use of cout, cin, string without prefix

// =============================================================
// SCREEN AND MENU HELPER FUNCTIONS
// =============================================================

// Prints a line of equal signs to visually separate sections on screen
void printSeparator()
{
    cout << "==========================================" << endl; // prints the separator line
}

// Prints a line of dashes for a lighter separator between items
void printDivider()
{
    cout << "------------------------------------------" << endl; // prints the divider line
}

// Prints a centered section header with separators above and below it
void displayHeader(string titleText)
{
    printSeparator();                // prints separator line above the title
    cout << "  " << titleText << endl; // prints the title with two spaces of indent
    printSeparator();                // prints separator line below the title
}

// Displays the main menu options for the airline reservation system
void displayMainMenu()
{
    printSeparator();                                            // top border
    cout << "      AIRLINE RESERVATION SYSTEM" << endl;         // system title
    printSeparator();                                            // separator
    cout << "  1. View All Flights"              << endl;        // option 1
    cout << "  2. Search Flights by Route"       << endl;        // option 2
    cout << "  3. Book a Seat"                   << endl;        // option 3
    cout << "  4. Cancel a Booking"              << endl;        // option 4
    cout << "  5. View Booking Details (Ticket)" << endl;        // option 5
    cout << "  6. View Passenger Manifest"       << endl;        // option 6
    cout << "  7. Demo: User Hierarchy (OOP)"    << endl;        // option 7 - OOP demo
    cout << "  8. Demo: Payment Methods (OOP)"   << endl;        // option 8 - OOP demo
    cout << "  0. Exit"                          << endl;        // option 0 - exit
    printSeparator();                                            // bottom border
}

// Pauses the screen until the user presses Enter to continue
void pauseScreen()
{
    cout << endl; // blank line before the prompt
    cout << "Press Enter to continue..." << endl; // shows the continue prompt
    cin.ignore();  // waits for the user to press Enter
    cin.get();     // reads the Enter key press
}

// =============================================================
// INPUT VALIDATION HELPER FUNCTIONS
// =============================================================

// Clears any error state and leftover characters from the input buffer
// Called after bad input to prepare cin for the next read
void clearInputBuffer()
{
    cin.clear();          // clears any error flags on the input stream
    cin.ignore(1000, '\n'); // discards up to 1000 characters until a newline is found
}

// Reads an integer from the user and returns it
// If the user types something that is not a number, it returns -1
int readIntegerInput()
{
    int userValue = 0;    // will store what the user types

    cin >> userValue; // reads the integer from keyboard

    if (cin.fail()) // checks if the user typed something that is not a number
    {
        clearInputBuffer();    // clears the bad input from the buffer
        return -1;             // returns -1 to signal that input was invalid
    }

    clearInputBuffer(); // clears the newline character left in the buffer
    return userValue;   // returns the valid number the user typed
}

// Reads a full line of text from the user and returns it as a string
// The leading cin.ignore() makes sure there is no leftover newline in the buffer
string readLineInput()
{
    string userText = ""; // will store what the user types

    cin.ignore(1000, '\n'); // clears any leftover newline from previous cin >> operation
    getline(cin, userText); // reads the full line including spaces

    return userText; // returns the text the user typed
}

// Checks if a given age value is within a reasonable human range
bool isValidAge(int age)
{
    bool aboveZero    = (age > 0);   // age must be greater than zero
    bool belowMaximum = (age < 150); // age must be less than 150 years

    bool ageIsValid = (aboveZero && belowMaximum); // both conditions must be true

    return ageIsValid; // returns true if age is valid, false otherwise
}

// Checks if a seat class string is one of the two allowed values
bool isValidSeatClass(string seatClass)
{
    bool isEconomy  = (seatClass == "economy");  // checks if user typed economy
    bool isBusiness = (seatClass == "business"); // checks if user typed business

    bool classIsValid = (isEconomy || isBusiness); // one of them must match

    return classIsValid; // returns true if the class is valid
}

// =============================================================
// FLIGHT OPERATION HELPER FUNCTIONS
// =============================================================

// Displays all flights stored in the airline object
void viewAllFlights(Airline& airline)
{
    displayHeader("ALL AVAILABLE FLIGHTS"); // prints section header

    if (airline.getFlightCount() == 0) // checks if there are any flights at all
    {
        cout << "No flights are currently available." << endl; // shows empty message
    }
    else // there are flights to show
    {
        airline.displayAllFlights(); // calls the airline method to show all flights
    }
}

// Asks user for a route and shows matching flights
void searchFlightsByRoute(Airline& airline)
{
    displayHeader("SEARCH FLIGHTS BY ROUTE"); // prints section header

    string fromCity = ""; // will store the origin city the user types
    string toCity   = ""; // will store the destination city the user types

    cout << "Enter origin city      : "; // prompts user for departure city
    clearInputBuffer();                   // clears leftover newline from main's cin >> menuChoice
    getline(cin, fromCity);               // reads the full city name

    cout << "Enter destination city : "; // prompts user for arrival city
    getline(cin, toCity);                 // reads the full city name (no extra ignore needed here)

    cout << endl; // blank line for spacing
    displayHeader("SEARCH RESULTS"); // prints results header

    airline.searchFlights(fromCity, toCity); // calls the airline search method
}

// Handles the complete seat booking process step by step
void bookSeat(Airline& airline)
{
    displayHeader("BOOK A SEAT"); // prints section header

    // Step 1: Get the flight number from the user
    cout << "Enter flight number (e.g. PK-301) : "; // prompts for flight number
    string flightNumber = ""; // will store the flight number

    clearInputBuffer();         // clears the leftover newline from main's cin >> menuChoice
    getline(cin, flightNumber); // reads the flight number as a full line

    int flightPosition = airline.findFlight(flightNumber); // searches for the flight

    if (flightPosition == -1) // checks if the flight was not found
    {
        cout << "Error: Flight " << flightNumber << " was not found." << endl; // shows error
        return; // exits the function without booking
    }

    // Step 2: Display the selected flight details
    cout << endl;
    airline.getFlightAt(flightPosition).displayFlight(); // shows the selected flight

    // Step 3: Get passenger information
    cout << "Enter passenger full name : "; // prompts for name
    string passengerName = ""; // will store the name

    getline(cin, passengerName);    // reads the full name (no extra ignore needed)

    cout << "Enter passenger age       : "; // prompts for age
    int passengerAge = readIntegerInput();   // reads the age as a number

    if (!isValidAge(passengerAge)) // validates the age entered
    {
        cout << "Error: Please enter a valid age between 1 and 149." << endl; // error message
        return; // exits without booking
    }

    cout << "Enter passenger ID / Passport : "; // prompts for ID number
    string passengerId = ""; // will store the ID

    getline(cin, passengerId);   // reads the ID (clearInputBuffer already called in readIntegerInput)

    // Step 4: Get seat class preference
    cout << "Enter seat class (economy / business) : "; // prompts for class
    string seatClass = ""; // will store the seat class

    getline(cin, seatClass);   // reads the class preference

    if (!isValidSeatClass(seatClass)) // validates the seat class entered
    {
        cout << "Error: Please type 'economy' or 'business' exactly." << endl; // error message
        return; // exits without booking
    }

    // Step 5: Set price based on seat class
    double ticketPrice = 0.0; // will store the ticket price

    if (seatClass == "economy") // economy class pricing
    {
        ticketPrice = ECONOMY_PRICE; // uses the economy constant
    }
    else // business class pricing
    {
        ticketPrice = BUSINESS_PRICE; // uses the business constant
    }

    // Step 6: Get payment method choice
    printDivider(); // prints divider before payment section
    cout << "Payment Method:" << endl;          // section title
    cout << "  1. Credit Card" << endl;         // option 1
    cout << "  2. Cash"        << endl;         // option 2
    cout << "  3. Loyalty Points" << endl;      // option 3
    cout << "Enter your choice (1-3) : ";       // prompts for choice

    int paymentChoice = readIntegerInput(); // reads the payment method choice

    if (paymentChoice < 1 || paymentChoice > 3) // validates the choice is 1, 2, or 3
    {
        cout << "Error: Please choose 1, 2, or 3 for payment method." << endl; // error
        return; // exits without booking
    }

    // Step 7: Collect payment details and process payment
    bool paymentSucceeded = false; // tracks whether payment went through

    if (paymentChoice == 1) // credit card payment
    {
        cout << "Enter card number     : "; // prompts for card number
        string cardNumber = ""; // will store the card number

        getline(cin, cardNumber);  // reads the card number (clearInputBuffer already called in readIntegerInput)

        cout << "Enter card holder name: "; // prompts for holder name
        string holderName = ""; // will store the holder name

        getline(cin, holderName);   // reads the holder name

        cout << "Enter expiry (MM/YY)  : "; // prompts for expiry date
        string expiryDate = ""; // will store the expiry date

        getline(cin, expiryDate);  // reads the expiry date

        // Create credit card payment object using multi-level inheritance class
        CreditCardPayment cardPayment("PAY-CC-001", ticketPrice, "2026-05-05",
                                      "Pending", "TXN-001", "BankGateway",
                                      cardNumber, holderName, expiryDate, "000"); // creates payment object

        bool isValid = cardPayment.validatePayment(); // validates the payment details

        if (isValid) // if validation passed
        {
            paymentSucceeded = cardPayment.processPayment(); // processes the payment
        }
        else // validation failed
        {
            cout << "Error: Card details are incomplete. Please check and try again." << endl; // error
        }
    }
    else if (paymentChoice == 2) // cash payment
    {
        double cashAmount = ticketPrice + 500.0; // customer pays a bit more than needed
        double changeBack = 500.0;               // the change to give back

        CashPayment cashPayment("PAY-CASH-001", ticketPrice, "2026-05-05",
                                "Pending", cashAmount, changeBack); // creates cash payment object

        bool isValid = cashPayment.validatePayment(); // validates that enough cash given

        if (isValid) // if validation passed
        {
            paymentSucceeded = cashPayment.processPayment(); // processes the payment
        }
    }
    else // loyalty points payment (choice == 3)
    {
        cout << "Enter membership ID   : "; // prompts for membership ID
        string membershipId = ""; // will store the membership ID

        getline(cin, membershipId);   // reads the membership ID (clearInputBuffer already called in readIntegerInput)

        cout << "Enter points to use   : "; // prompts for number of points
        int pointsToUse = readIntegerInput(); // reads the points as a number

        if (pointsToUse < 0) // validates that points is a positive number
        {
            cout << "Error: Points must be a positive number." << endl; // error message
            return; // exits without booking
        }

        double conversionRate = 0.1; // each point is worth Rs.0.10

        LoyaltyPayment loyaltyPayment("PAY-PTS-001", ticketPrice, "2026-05-05",
                                      "Pending", pointsToUse, membershipId, conversionRate); // creates payment

        bool isValid = loyaltyPayment.validatePayment(); // validates that points are enough

        if (isValid) // if validation passed
        {
            paymentSucceeded = loyaltyPayment.processPayment(); // processes the payment
        }
        else // not enough points
        {
            cout << "Error: You do not have enough points. You need " << (int)(ticketPrice / conversionRate) << " points." << endl; // error
        }
    }

    if (!paymentSucceeded) // if payment did not go through
    {
        cout << "Booking cancelled because payment was not successful." << endl; // shows message
        return; // exits without booking
    }

    // Step 8: Find an available seat and create the booking
    Flight& selectedFlight = airline.getFlightAt(flightPosition); // gets the flight by reference

    string capitalizedClass = ""; // will store the class with capital first letter

    if (seatClass == "economy") // converts to match the stored class name format
    {
        capitalizedClass = "Economy"; // uses capital E to match seat class stored in Seat
    }
    else // business class
    {
        capitalizedClass = "Business"; // uses capital B to match seat class stored in Seat
    }

    int assignedSeatNumber = selectedFlight.findAvailableSeat(capitalizedClass); // finds a free seat

    if (assignedSeatNumber == -1) // checks if no seat was available
    {
        cout << "Error: No " << seatClass << " seats are available on this flight." << endl; // error
        return; // exits without booking
    }

    Passenger newPassenger(passengerName, passengerAge, passengerId); // creates the passenger object

    Booking newBooking(newPassenger, flightNumber, assignedSeatNumber, capitalizedClass, ticketPrice); // creates the booking

    bool bookingAdded = selectedFlight.addBooking(newBooking); // tries to add the booking to the flight

    if (bookingAdded) // if booking was successfully added
    {
        cout << endl;
        displayHeader("BOOKING CONFIRMED"); // shows success header
        cout << "  PNR Number  : " << newBooking.getPnr()    << endl; // shows PNR
        cout << "  Seat Number : " << assignedSeatNumber      << endl; // shows assigned seat
        cout << "  Seat Class  : " << capitalizedClass         << endl; // shows class
        cout << "  Amount Paid : Rs." << ticketPrice           << endl; // shows amount
        cout << "  SAVE YOUR PNR NUMBER FOR FUTURE USE!"       << endl; // important reminder
        printSeparator(); // bottom border
    }
    else // booking failed to add
    {
        cout << "Error: Could not complete booking. Please try again." << endl; // error message
    }
}

// Handles the booking cancellation process
void cancelBooking(Airline& airline)
{
    displayHeader("CANCEL A BOOKING"); // prints section header

    cout << "Enter your PNR number   : "; // prompts for PNR
    string pnrToCancel = ""; // will store the PNR to cancel

    clearInputBuffer();           // clears leftover newline from main's cin >> menuChoice
    getline(cin, pnrToCancel);    // reads the PNR

    cout << "Enter your flight number : "; // prompts for flight number
    string flightNumber = ""; // will store the flight number

    getline(cin, flightNumber);   // reads the flight number

    int flightPosition = airline.findFlight(flightNumber); // searches for the flight

    if (flightPosition == -1) // if the flight was not found
    {
        cout << "Error: Flight " << flightNumber << " was not found." << endl; // shows error
        return; // exits without cancelling
    }

    bool cancelled = airline.getFlightAt(flightPosition).cancelBooking(pnrToCancel); // tries to cancel

    if (cancelled) // if cancellation was successful
    {
        cout << endl;
        displayHeader("BOOKING CANCELLED"); // shows success header
        cout << "  PNR " << pnrToCancel << " has been cancelled." << endl; // confirms cancellation
        cout << "  The seat has been released for other passengers." << endl; // seat available again
        printSeparator(); // bottom border
    }
    else // PNR was not found on that flight
    {
        cout << "Error: No active booking found with PNR " << pnrToCancel << " on flight " << flightNumber << "." << endl; // error
    }
}

// Searches for a booking by PNR and displays the full ticket
void viewBookingDetails(Airline& airline)
{
    displayHeader("VIEW BOOKING DETAILS"); // prints section header

    cout << "Enter your PNR number : "; // prompts for PNR
    string searchPnr = ""; // will store the PNR to search for

    clearInputBuffer();        // clears leftover newline from main's cin >> menuChoice
    getline(cin, searchPnr);   // reads the PNR

    bool bookingFound = false; // tracks if the booking was found

    int flightIndex = 0; // loop counter for flights

    for (flightIndex = 0; flightIndex < airline.getFlightCount(); flightIndex = flightIndex + 1) // checks each flight
    {
        Flight& currentFlight = airline.getFlightAt(flightIndex); // gets this flight by reference

        int bookingIndex = 0; // loop counter for bookings on this flight

        for (bookingIndex = 0; bookingIndex < currentFlight.getBookingCount(); bookingIndex = bookingIndex + 1) // checks each booking
        {
            Booking currentBooking = currentFlight.getBookingAt(bookingIndex); // gets the booking at this index

            string currentPnr = currentBooking.getPnr();    // gets the PNR of this booking
            string status     = currentBooking.getStatus(); // gets the status of this booking

            bool pnrMatches  = (currentPnr == searchPnr); // checks if PNR matches what we are looking for
            bool isActive    = (status != "Cancelled");    // checks if booking is still active

            if (pnrMatches && isActive) // if found and active
            {
                bookingFound = true; // marks that we found it

                cout << endl;
                currentBooking.printTicket(); // prints the boarding pass ticket

                break; // stops searching this flight's bookings
            }
        }

        if (bookingFound) // if found, no need to check other flights
        {
            break; // stops searching other flights
        }
    }

    if (!bookingFound) // if the booking was not found anywhere
    {
        cout << "Error: No active booking found with PNR " << searchPnr << "." << endl; // shows error
    }
}

// Asks for a flight number and shows the passenger manifest for that flight
void displayFlightManifest(Airline& airline)
{
    displayHeader("FLIGHT PASSENGER MANIFEST"); // prints section header

    cout << "Enter flight number : "; // prompts for flight number
    string flightNumber = ""; // will store the flight number

    clearInputBuffer();           // clears leftover newline from main's cin >> menuChoice
    getline(cin, flightNumber);   // reads the flight number

    int flightPosition = airline.findFlight(flightNumber); // searches for the flight

    if (flightPosition == -1) // if not found
    {
        cout << "Error: Flight " << flightNumber << " was not found." << endl; // error message
        return; // exits the function
    }

    cout << endl;
    airline.getFlightAt(flightPosition).displayManifest(); // shows the passenger list for that flight
}

// =============================================================
// OOP DEMONSTRATION HELPER FUNCTIONS
// These show the OOP concepts working for the demo menu options
// =============================================================

// Demonstrates polymorphism using the User inheritance hierarchy
void demoUserHierarchy()
{
    displayHeader("OOP DEMO: USER HIERARCHY (Polymorphism)"); // section header

    cout << "Creating Admin and Customer objects..." << endl; // explains what is happening
    cout << endl;

    // Create an Admin object - inherits from User
    Admin adminUser("A001", "admin_ali", "pass123", "ali@airline.com",
                    "Ali Hassan", "0300-1234567", "SuperAdmin", "Operations"); // admin constructor

    // Create a Customer object - inherits from User
    Customer customerUser("C001", "sara_khan", "sara456", "sara@email.com",
                          "Sara Khan", "0311-9876543"); // customer constructor

    // Use a User pointer to demonstrate runtime polymorphism
    User* userPointer = nullptr; // base class pointer for polymorphism

    cout << "--- Demonstrating Polymorphism with Admin ---" << endl; // sub-section label
    userPointer = &adminUser;    // points to the Admin object (upcasting)
    userPointer->displayInfo();  // calls Admin::displayInfo() at runtime (polymorphism)

    cout << endl;

    cout << "--- Demonstrating Polymorphism with Customer ---" << endl; // sub-section label
    userPointer = &customerUser;  // points to the Customer object (upcasting)
    userPointer->displayInfo();   // calls Customer::displayInfo() at runtime (polymorphism)

    cout << endl;

    cout << "--- Demonstrating Login Method (Polymorphism) ---" << endl; // sub-section label

    bool adminLoginResult = adminUser.login("admin_ali", "pass123"); // tests admin login

    if (adminLoginResult) // checks if login succeeded
    {
        cout << "Admin login test: PASSED" << endl; // shows result
    }
    else // login failed
    {
        cout << "Admin login test: FAILED" << endl; // shows result
    }

    bool customerLoginResult = customerUser.login("sara_khan", "sara456"); // tests customer login

    if (customerLoginResult) // checks if login succeeded
    {
        cout << "Customer login test: PASSED" << endl; // shows result
    }
    else // login failed
    {
        cout << "Customer login test: FAILED" << endl; // shows result
    }

    cout << endl;
    cout << "OOP Concepts shown: Inheritance, Polymorphism, Virtual Functions," << endl; // lists concepts
    cout << "                    Protected Members, Method Overriding." << endl;           // continues list
    printSeparator(); // bottom border
}

// Demonstrates polymorphism using the Payment inheritance hierarchy
void demoPaymentMethods()
{
    displayHeader("OOP DEMO: PAYMENT METHODS (Polymorphism)"); // section header

    cout << "Creating three different payment objects..." << endl; // explains what is happening
    cout << endl;

    // Create a CreditCardPayment object (multi-level: Payment->OnlinePayment->CreditCardPayment)
    CreditCardPayment creditCardPayment("PAY-CC-001", 15000.0, "2026-05-05", "Pending",
                                        "TXN-CC-999", "BankGateway",
                                        "1234-5678-9012-3456", "Ali Ahmed", "12/28", "123"); // creates credit card payment

    // Create a CashPayment object (Payment->CashPayment)
    CashPayment cashPayment("PAY-CASH-001", 8000.0, "2026-05-05", "Pending",
                             8500.0, 500.0); // creates cash payment

    // Create a LoyaltyPayment object (Payment->LoyaltyPayment)
    LoyaltyPayment loyaltyPayment("PAY-PTS-001", 10000.0, "2026-05-05", "Pending",
                                   120000, "MEM-12345", 0.1); // creates loyalty payment

    // Use a Payment pointer to demonstrate runtime polymorphism
    Payment* paymentPointer = nullptr; // base class pointer for polymorphism

    cout << "--- Testing Credit Card Payment (Multi-Level Inheritance) ---" << endl; // sub-section
    paymentPointer = &creditCardPayment; // points to CreditCardPayment (upcasting)
    paymentPointer->displayPaymentInfo(); // calls CreditCardPayment::displayPaymentInfo() at runtime

    bool ccValid = paymentPointer->validatePayment(); // calls overridden validatePayment

    if (ccValid) // if validation passed
    {
        paymentPointer->processPayment(); // calls overridden processPayment
    }

    cout << endl;

    cout << "--- Testing Cash Payment ---" << endl; // sub-section
    paymentPointer = &cashPayment;         // points to CashPayment (upcasting)
    paymentPointer->displayPaymentInfo();  // calls CashPayment::displayPaymentInfo()

    bool cashValid = paymentPointer->validatePayment(); // validates the cash payment

    if (cashValid) // if valid
    {
        paymentPointer->processPayment(); // processes the payment
    }

    cout << endl;

    cout << "--- Testing Loyalty Points Payment (with Friend Function) ---" << endl; // sub-section
    paymentPointer = &loyaltyPayment;      // points to LoyaltyPayment (upcasting)
    paymentPointer->displayPaymentInfo();  // calls LoyaltyPayment::displayPaymentInfo()

    bool loyaltyValid = paymentPointer->validatePayment(); // validates the points payment

    if (loyaltyValid) // if valid
    {
        paymentPointer->processPayment(); // processes the payment
    }

    // Demonstrate the friend function concept
    cout << endl;
    cout << "--- Friend Function Demonstration ---" << endl; // sub-section
    showLoyaltyPointsUsed(loyaltyPayment); // calls friend function that accesses private member

    cout << endl;
    cout << "OOP Concepts shown: Polymorphism, Multi-level Inheritance," << endl; // lists concepts
    cout << "                    Virtual Functions, Friend Functions."    << endl; // continues
    printSeparator(); // bottom border
}

// =============================================================
// END OF HELPERS.H
// =============================================================

#endif // ends the include guard
