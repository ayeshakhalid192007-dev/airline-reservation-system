// Admin.h - Header file for Admin class
// This class inherits from User base class (demonstrates inheritance)
// Admin users have additional privileges and department information

#ifndef ADMIN_H // include guard to prevent multiple inclusion
#define ADMIN_H // define the header guard

#include <string> // for string data type
#include "User.h" // include the User base class header

using namespace std; // to use string without std:: prefix

// Admin class - inherits from User base class (IS-A relationship)
class Admin : public User // public inheritance from User
{
private: // private members specific to Admin class
    string adminLevel; // level of admin access (Super, Manager, Support)
    string department; // department the admin belongs to

public: // public methods accessible from outside the class
    // constructor with parameters to initialize all admin data
    // calls the base class User constructor to initialize inherited members
    Admin(string id, string uname, string pass, string mail, string name, string phone, string level, string dept);

    // override displayInfo method from base class (demonstrates polymorphism)
    // displays both base User info and Admin-specific info
    void displayInfo();

    // override login method from base class (demonstrates polymorphism)
    // adds admin-specific login logic after base class login
    bool login(string inputUsername, string inputPassword);

    // admin-specific method to manage flights in the system
    void manageFlights();

    // admin-specific method to manage users in the system
    void manageUsers();

    // admin-specific method to view system reports
    void viewReports();

    // getter method for adminLevel
    string getAdminLevel(); // returns the admin level

    // getter method for department
    string getDepartment(); // returns the department

    // setter method for adminLevel
    void setAdminLevel(string level); // sets the admin level

    // setter method for department
    void setDepartment(string dept); // sets the department
};

#endif // end of include guard
