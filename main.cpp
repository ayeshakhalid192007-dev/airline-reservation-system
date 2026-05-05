/*
 * ============================================================
 * File    : main.cpp
 * Project : Airline Reservation System
 * Author  : OOP Project
 * Date    : 2026-05-05
 *
 * Description:
 *   This is the entry point of the Airline Reservation System.
 *   It contains ONLY the main() function and include statements.
 *   All classes are in classes.h and all helper functions in helpers.h.
 *
 * Compile with: g++ main.cpp -o airline
 * Run with    : ./airline
 *
 * OOP Concepts Demonstrated:
 *   - Classes and Objects (13 classes)
 *   - Encapsulation (private data + public getters/setters)
 *   - Constructor Overloading (default + parameterized in every class)
 *   - Copy Constructor (Passenger, Flight)
 *   - Arrays of Objects (Flight[], Seat[], Booking[])
 *   - Static Members (Booking::bookingCounter, Airline::totalAirlinesCreated)
 *   - Inheritance - Single (User->Admin, User->Customer, Payment->CashPayment)
 *   - Inheritance - Multi-Level (Payment->OnlinePayment->CreditCardPayment)
 *   - Protected Members (User base class, OnlinePayment base class)
 *   - Polymorphism (virtual functions overridden in Admin, Customer, all Payment types)
 *   - Operator Overloading (Booking == operator)
 *   - Friend Functions (showLoyaltyPointsUsed, bookSeat, etc.)
 *   - Abstraction (complex logic hidden inside class methods)
 *   - Composition (Flight has Seat[], Booking[]; Airline has Flight[])
 * ============================================================
 */

#include <iostream>   // for cout and cin input/output
#include <string>     // for string data type
#include <cstring>    // for string utility functions
#include "classes.h"  // includes all class definitions and implementations
#include "helpers.h"  // includes all helper and menu functions

using namespace std; // allows use of cout, cin, string without std:: prefix

/*
 * Function : main
 * Purpose  : Entry point of the program - creates the airline and runs the menu loop
 * Returns  : 0 on successful exit
 */
int main()
{
    // Create the main Airline object using the parameterized constructor
    Airline airline("Pakistan International Airlines", "PIA"); // creates airline with name and code

    // Try to load saved data from file, if file doesn't exist load sample data instead
    try // starts exception handling block for file loading
    {
        airline.loadFromFile("airline_data.txt"); // attempts to load data from file
        cout << "Previous session data loaded successfully." << endl; // confirms loading
    }
    catch (FileIOException& fileError) // catches file-related errors
    {
        cout << "No saved data found. Loading sample flights..." << endl; // informs user of fallback
        airline.loadSampleData(); // loads the default sample flights
    }

    cout << endl; // blank line for spacing
    printSeparator();                                    // top border
    cout << "  WELCOME TO AIRLINE RESERVATION SYSTEM" << endl; // welcome message
    cout << "  " << airline.getAirlineName()          << endl; // shows airline name
    printSeparator();                                    // bottom border
    cout << endl; // blank line for spacing

    int menuChoice = 0;    // stores the number the user picks from the menu
    bool keepRunning = true; // controls whether the main loop continues

    while (keepRunning) // main program loop - runs until user chooses to exit
    {
        cout << endl;          // blank line before each menu display
        displayMainMenu();     // shows the list of options to the user

        cout << "Enter your choice : "; // prompts the user to enter a number
        cin >> menuChoice;              // reads the user's menu selection

        if (cin.fail()) // checks if the user typed something that is not a number
        {
            clearInputBuffer(); // clears the bad input from the stream
            cout << "Error: Please enter a number from the menu." << endl; // error message
            continue; // skips to the next loop iteration without doing anything
        }

        cout << endl; // blank line after user input for cleaner output

        if (menuChoice == 1) // user wants to view all flights
        {
            viewAllFlights(airline); // calls the helper function to display flights
        }
        else if (menuChoice == 2) // user wants to search by route
        {
            searchFlightsByRoute(airline); // calls the helper function to search
        }
        else if (menuChoice == 3) // user wants to book a seat
        {
            bookSeat(airline); // calls the helper function to handle booking
        }
        else if (menuChoice == 4) // user wants to cancel a booking
        {
            cancelBooking(airline); // calls the helper function for cancellation
        }
        else if (menuChoice == 5) // user wants to view booking details / ticket
        {
            viewBookingDetails(airline); // calls the helper function to show ticket
        }
        else if (menuChoice == 6) // user wants to see the flight passenger manifest
        {
            displayFlightManifest(airline); // calls the helper function for manifest
        }
        else if (menuChoice == 7) // user wants to view user profiles
        {
            displayUserProfiles(); // calls the helper function to show user account information
        }
        else if (menuChoice == 8) // user wants to view payment options
        {
            displayPaymentOptions(); // calls the helper function to show payment processing demo
        }
        else if (menuChoice == 0) // user wants to exit the program
        {
            keepRunning = false; // sets the flag to false so the loop will end

            // Save all flight and booking data to file before exiting
            try // starts exception handling block for file saving
            {
                airline.saveToFile("airline_data.txt"); // saves all data to file
                cout << endl; // blank line for spacing
                cout << "Data saved successfully." << endl; // confirms save operation
            }
            catch (FileIOException& fileError) // catches file-related errors
            {
                fileError.displayError(); // shows the error message to user
                cout << "Warning: Data was not saved." << endl; // warns user about data loss
            }

            cout << endl; // blank line for spacing
            printSeparator();                                // top border
            cout << "  Thank you for using our system!" << endl; // goodbye message
            cout << "  Have a safe journey!"            << endl; // farewell message
            printSeparator();                                // bottom border
            cout << endl; // blank line at the end
        }
        else // user typed a number that is not on the menu
        {
            cout << "Error: Invalid choice. Please enter a number from 0 to 8." << endl; // error
        }
    }

    return 0; // returns zero to the operating system to indicate successful exit
}
