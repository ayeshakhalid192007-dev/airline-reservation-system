/*
 * File: main.cpp
 * Purpose: Entry point for Airline Reservation System
 * Description: Main function that orchestrates the entire application
 * OOP Concepts Demonstrated: Encapsulation, Composition, Inheritance, Polymorphism, Static Members
 */

#include <iostream> // for input/output operations
#include <string> // for string data type
#include <limits> // for numeric_limits to clear input buffer

// Include domain class headers
#include "domain/Airline.h" // for Airline class
#include "domain/Flight.h" // for Flight class
#include "domain/Booking.h" // for Booking class
#include "domain/Passenger.h" // for Passenger class
#include "domain/Seat.h" // for Seat class
#include "domain/User.h" // for User base class
#include "domain/Admin.h" // for Admin derived class
#include "domain/Customer.h" // for Customer derived class
#include "domain/Payment.h" // for Payment base class
#include "domain/CreditCardPayment.h" // for CreditCardPayment derived class
#include "domain/CashPayment.h" // for CashPayment derived class
#include "domain/PointsPayment.h" // for PointsPayment derived class

// Include utility files
#include "constants.cpp" // for constant definitions
#include "ui/menu.cpp" // for menu display functions
#include "services/helpers.cpp" // for all helper functions

using namespace std; // use standard namespace

/*
 * Function: main
 * Purpose: Entry point of the program
 * Returns: 0 on successful execution
 */
int main()
{
    Airline airline("Pakistan International Airlines", "PK"); // create airline object with name and code

    airline.loadSampleData(); // load pre-defined sample flights for testing

    int choice = 0; // stores user menu choice
    bool running = true; // flag to control main loop

    cout << "\n========================================" << endl; // print separator line
    cout << "  WELCOME TO AIRLINE RESERVATION SYSTEM" << endl; // print welcome message
    cout << "========================================\n" << endl; // print separator line

    while (running) // main program loop - continues until user exits
    {
        displayMainMenu(); // show menu options to user

        cout << "Enter your choice: "; // prompt for user input
        cin >> choice; // read user choice

        if (cin.fail()) // check if input is invalid (non-integer)
        {
            clearInputBuffer(); // clear the error state and buffer
            cout << "\nInvalid input! Please enter a number between 0 and 8.\n" << endl; // show error message
            continue; // skip to next iteration
        }

        cout << endl; // print blank line for readability

        switch (choice) // execute action based on user choice
        {
            case 1: // option to view all flights
                viewAllFlights(airline); // call function to display all flights
                break; // exit switch statement

            case 2: // option to search flights by route
                searchFlightsByRoute(airline); // call function to search flights
                break; // exit switch statement

            case 3: // option to book a seat
                bookSeat(airline); // call function to handle booking
                break; // exit switch statement

            case 4: // option to cancel booking
                cancelBooking(airline); // call function to handle cancellation
                break; // exit switch statement

            case 5: // option to view booking details
                viewBookingDetails(airline); // call function to display booking and ticket
                break; // exit switch statement

            case 6: // option to display flight manifest
                displayFlightManifest(airline); // call function to show passenger list
                break; // exit switch statement

            case 7: // option to test user hierarchy
                testUserHierarchy(); // call function to demonstrate polymorphism with users
                break; // exit switch statement

            case 8: // option to test payment methods
                testPaymentMethods(); // call function to demonstrate polymorphism with payments
                break; // exit switch statement

            case 0: // option to exit program
                running = false; // set flag to false to exit loop
                cout << "========================================" << endl; // print separator
                cout << "  Thank you for using our system!" << endl; // print goodbye message
                cout << "========================================\n" << endl; // print separator
                break; // exit switch statement

            default: // handle invalid menu choice
                cout << "Invalid choice! Please enter a number between 0 and 8.\n" << endl; // show error message
                break; // exit switch statement
        }
    }

    return 0; // return success code
}
