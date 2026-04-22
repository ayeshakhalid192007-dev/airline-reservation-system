// User.cpp - Implementation file for User base class
// Contains all method definitions for the User class

#include "User.h" // include the User header file
#include <iostream> // for cout to display output

using namespace std; // to use cout and string without std:: prefix

// constructor implementation - initializes all user data members
User::User(string id, string uname, string pass, string mail, string name, string phone)
{
    userId = id; // assign the user ID parameter to the member variable
    username = uname; // assign the username parameter to the member variable
    password = pass; // assign the password parameter to the member variable
    email = mail; // assign the email parameter to the member variable
    fullName = name; // assign the full name parameter to the member variable
    phoneNumber = phone; // assign the phone number parameter to the member variable
}

// virtual destructor implementation - allows proper cleanup in derived classes
User::~User()
{
    // destructor body is empty but must exist for proper inheritance
    // derived classes can override this to add their own cleanup code
}

// login method implementation - verifies username and password
bool User::login(string inputUsername, string inputPassword)
{
    bool usernameMatches = (inputUsername == username); // check if input username matches stored username
    bool passwordMatches = (inputPassword == password); // check if input password matches stored password

    if (usernameMatches && passwordMatches) // if both username and password are correct
    {
        return true; // login successful
    }

    return false; // login failed
}

// displayInfo method implementation - prints all user information
void User::displayInfo()
{
    cout << "==========================================\n"; // print separator line
    cout << "           USER INFORMATION\n"; // print header
    cout << "==========================================\n"; // print separator line
    cout << "User ID       : " << userId << "\n"; // display user ID
    cout << "Username      : " << username << "\n"; // display username
    cout << "Full Name     : " << fullName << "\n"; // display full name
    cout << "Email         : " << email << "\n"; // display email
    cout << "Phone Number  : " << phoneNumber << "\n"; // display phone number
    cout << "==========================================\n"; // print separator line
}

// getter method for userId
string User::getUserId()
{
    return userId; // return the user ID
}

// getter method for username
string User::getUsername()
{
    return username; // return the username
}

// getter method for password
string User::getPassword()
{
    return password; // return the password
}

// getter method for email
string User::getEmail()
{
    return email; // return the email
}

// getter method for fullName
string User::getFullName()
{
    return fullName; // return the full name
}

// getter method for phoneNumber
string User::getPhoneNumber()
{
    return phoneNumber; // return the phone number
}

// setter method for userId
void User::setUserId(string id)
{
    userId = id; // update the user ID with the new value
}

// setter method for username
void User::setUsername(string uname)
{
    username = uname; // update the username with the new value
}

// setter method for password
void User::setPassword(string pass)
{
    password = pass; // update the password with the new value
}

// setter method for email
void User::setEmail(string mail)
{
    email = mail; // update the email with the new value
}

// setter method for fullName
void User::setFullName(string name)
{
    fullName = name; // update the full name with the new value
}

// setter method for phoneNumber
void User::setPhoneNumber(string phone)
{
    phoneNumber = phone; // update the phone number with the new value
}
