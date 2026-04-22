// User.h - Header file for User base class
// This is the base class for Admin, Customer, and Agent classes (inheritance)

#ifndef USER_H // include guard to prevent multiple inclusion
#define USER_H // define the header guard

#include <string> // for string data type

using namespace std; // to use string without std:: prefix

// User class - base class for all user types in the system
class User
{
protected: // protected members can be accessed by derived classes
    string userId; // unique identifier for the user
    string username; // username for login
    string password; // password for authentication
    string email; // email address of the user
    string fullName; // full name of the user
    string phoneNumber; // contact phone number

public: // public methods accessible from outside the class
    // constructor with parameters to initialize all user data
    User(string id, string uname, string pass, string mail, string name, string phone);

    // virtual destructor - important for proper cleanup in derived classes
    virtual ~User();

    // virtual login method - can be overridden by derived classes
    virtual bool login(string inputUsername, string inputPassword);

    // virtual displayInfo method - can be overridden by derived classes
    virtual void displayInfo();

    // getter methods to access protected data members
    string getUserId(); // returns the user ID
    string getUsername(); // returns the username
    string getPassword(); // returns the password
    string getEmail(); // returns the email
    string getFullName(); // returns the full name
    string getPhoneNumber(); // returns the phone number

    // setter methods to modify protected data members
    void setUserId(string id); // sets the user ID
    void setUsername(string uname); // sets the username
    void setPassword(string pass); // sets the password
    void setEmail(string mail); // sets the email
    void setFullName(string name); // sets the full name
    void setPhoneNumber(string phone); // sets the phone number
};

#endif // end of include guard
