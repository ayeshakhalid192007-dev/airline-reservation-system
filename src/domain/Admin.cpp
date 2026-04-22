// Admin.cpp - Implementation file for Admin class
// Contains all method definitions for the Admin class

#include "Admin.h" // include the Admin header file
#include <iostream> // for cout to display output

using namespace std; // to use cout and string without std:: prefix

// constructor implementation - initializes all admin data members
// uses initializer list to call base class User constructor
Admin::Admin(string id, string uname, string pass, string mail, string name, string phone, string level, string dept)
    : User(id, uname, pass, mail, name, phone) // call base class constructor with first 6 parameters
{
    adminLevel = level; // assign the admin level parameter to the member variable
    department = dept; // assign the department parameter to the member variable
}

// override displayInfo method - demonstrates polymorphism
// calls base class displayInfo then adds admin-specific information
void Admin::displayInfo()
{
    User::displayInfo(); // call the base class displayInfo method to display user information

    cout << "           ADMIN INFORMATION\n"; // print admin section header
    cout << "==========================================\n"; // print separator line
    cout << "Admin Level   : " << adminLevel << "\n"; // display admin level
    cout << "Department    : " << department << "\n"; // display department
    cout << "==========================================\n"; // print separator line
}

// override login method - demonstrates polymorphism
// calls base class login then adds admin-specific login logic
bool Admin::login(string inputUsername, string inputPassword)
{
    bool loginSuccess = User::login(inputUsername, inputPassword); // call base class login method

    if (loginSuccess) // if base class login was successful
    {
        cout << "==========================================\n"; // print separator line
        cout << "     ADMIN LOGIN SUCCESSFUL\n"; // print admin login success message
        cout << "==========================================\n"; // print separator line
        cout << "Welcome, " << fullName << "\n"; // display welcome message with admin name
        cout << "Admin Level: " << adminLevel << "\n"; // display admin level
        cout << "Department: " << department << "\n"; // display department
        cout << "==========================================\n"; // print separator line
        return true; // return true to indicate successful login
    }

    return false; // return false if login failed
}

// manageFlights method - admin-specific functionality
// allows admin to manage flights in the system
void Admin::manageFlights()
{
    cout << "==========================================\n"; // print separator line
    cout << "        FLIGHT MANAGEMENT PANEL\n"; // print header
    cout << "==========================================\n"; // print separator line
    cout << "Admin: " << fullName << "\n"; // display admin name
    cout << "Level: " << adminLevel << "\n"; // display admin level
    cout << "==========================================\n"; // print separator line
    cout << "Flight management functionality will be implemented here.\n"; // placeholder message
    cout << "This includes: Add, Edit, Delete, View Flights\n"; // describe functionality
    cout << "==========================================\n"; // print separator line
}

// manageUsers method - admin-specific functionality
// allows admin to manage users in the system
void Admin::manageUsers()
{
    cout << "==========================================\n"; // print separator line
    cout << "         USER MANAGEMENT PANEL\n"; // print header
    cout << "==========================================\n"; // print separator line
    cout << "Admin: " << fullName << "\n"; // display admin name
    cout << "Level: " << adminLevel << "\n"; // display admin level
    cout << "==========================================\n"; // print separator line
    cout << "User management functionality will be implemented here.\n"; // placeholder message
    cout << "This includes: Add, Edit, Delete, View Users\n"; // describe functionality
    cout << "==========================================\n"; // print separator line
}

// viewReports method - admin-specific functionality
// allows admin to view system reports
void Admin::viewReports()
{
    cout << "==========================================\n"; // print separator line
    cout << "          SYSTEM REPORTS PANEL\n"; // print header
    cout << "==========================================\n"; // print separator line
    cout << "Admin: " << fullName << "\n"; // display admin name
    cout << "Department: " << department << "\n"; // display department
    cout << "==========================================\n"; // print separator line
    cout << "System reports functionality will be implemented here.\n"; // placeholder message
    cout << "This includes: Booking Reports, Revenue Reports, User Activity\n"; // describe functionality
    cout << "==========================================\n"; // print separator line
}

// getter method for adminLevel
string Admin::getAdminLevel()
{
    return adminLevel; // return the admin level
}

// getter method for department
string Admin::getDepartment()
{
    return department; // return the department
}

// setter method for adminLevel
void Admin::setAdminLevel(string level)
{
    adminLevel = level; // update the admin level with the new value
}

// setter method for department
void Admin::setDepartment(string dept)
{
    department = dept; // update the department with the new value
}
