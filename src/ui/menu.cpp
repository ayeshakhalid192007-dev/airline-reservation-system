/*
 * File: menu.cpp
 * Purpose: Menu display functions for the airline reservation system
 * Description: Contains all menu-related display functions
 */

#ifndef MENU_CPP // header guard to prevent multiple inclusion
#define MENU_CPP // define the header guard

#include <iostream> // for input/output operations

using namespace std; // use standard namespace

/*
 * Function: displayMainMenu
 * Purpose: Displays the main menu options to the user
 */
void displayMainMenu()
{
    cout << "==========================================" << endl; // print top border
    cout << "      AIRLINE RESERVATION SYSTEM" << endl; // print title
    cout << "==========================================" << endl; // print separator
    cout << "  1. View All Flights" << endl; // option 1
    cout << "  2. Search Flights by Route" << endl; // option 2
    cout << "  3. Book a Seat" << endl; // option 3
    cout << "  4. Cancel Booking" << endl; // option 4
    cout << "  5. View Booking Details" << endl; // option 5
    cout << "  6. Display Flight Manifest" << endl; // option 6
    cout << "  7. Test User Hierarchy (Admin/Customer)" << endl; // option 7
    cout << "  8. Test Payment Methods" << endl; // option 8
    cout << "  0. Exit" << endl; // option 0
    cout << "==========================================" << endl; // print bottom border
}

#endif // end of header guard
