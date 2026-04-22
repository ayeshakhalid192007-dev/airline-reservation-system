#include "Passenger.h" // include the Passenger header file
#include <iostream> // include iostream for console input/output operations

using namespace std; // use standard namespace to avoid writing std:: prefix

// Constructor 1: Parameterized constructor implementation
// This constructor initializes a passenger object with provided name, age, and ID
Passenger::Passenger(string name, int age, string id)
{
    passengerName = name; // assign the provided name to the passengerName member
    passengerAge = age; // assign the provided age to the passengerAge member
    passengerId = id; // assign the provided ID to the passengerId member
}

// Constructor 2: Default constructor implementation
// This constructor initializes a passenger object with empty/default values
Passenger::Passenger()
{
    passengerName = ""; // initialize passengerName to empty string
    passengerAge = 0; // initialize passengerAge to zero
    passengerId = ""; // initialize passengerId to empty string
}

// Getter method implementation: returns the passenger's name
string Passenger::getName()
{
    return passengerName; // return the value of passengerName member variable
}

// Getter method implementation: returns the passenger's age
int Passenger::getAge()
{
    return passengerAge; // return the value of passengerAge member variable
}

// Getter method implementation: returns the passenger's ID
string Passenger::getId()
{
    return passengerId; // return the value of passengerId member variable
}

// Setter method implementation: sets the passenger's name
void Passenger::setName(string name)
{
    passengerName = name; // assign the provided name to passengerName member
}

// Setter method implementation: sets the passenger's age
void Passenger::setAge(int age)
{
    passengerAge = age; // assign the provided age to passengerAge member
}

// Setter method implementation: sets the passenger's ID
void Passenger::setId(string id)
{
    passengerId = id; // assign the provided ID to passengerId member
}

// Display method implementation: prints all passenger information
void Passenger::displayPassenger()
{
    cout << "==========================================\n"; // print top separator line
    cout << "         PASSENGER INFORMATION\n"; // print section title
    cout << "==========================================\n"; // print separator line
    cout << "  Name       : " << passengerName << "\n"; // print passenger name
    cout << "  Age        : " << passengerAge << "\n"; // print passenger age
    cout << "  ID Number  : " << passengerId << "\n"; // print passenger ID
    cout << "==========================================\n"; // print bottom separator line
}
