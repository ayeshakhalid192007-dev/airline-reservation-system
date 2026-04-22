#ifndef PASSENGER_H // header guard to prevent multiple inclusion
#define PASSENGER_H // define the header guard macro

#include <string> // include string library for string data type

using namespace std; // use standard namespace to avoid writing std:: prefix

// Passenger class represents a passenger in the airline system
// Demonstrates: Encapsulation (private data members with public getters/setters)
// Demonstrates: Constructor Overloading (two different constructors)
class Passenger
{
private: // private section - data members are hidden from outside access
    string passengerName; // stores the full name of the passenger
    int passengerAge; // stores the age of the passenger in years
    string passengerId; // stores the unique identification number of the passenger

public: // public section - methods accessible from outside the class
    // Constructor 1: Parameterized constructor that takes name, age, and ID
    // This constructor is used when creating a passenger with known details
    Passenger(string name, int age, string id);

    // Constructor 2: Default constructor that takes no parameters
    // This constructor is used when creating an empty passenger object
    Passenger();

    // Getter method: returns the passenger's name
    string getName();

    // Getter method: returns the passenger's age
    int getAge();

    // Getter method: returns the passenger's ID number
    string getId();

    // Setter method: sets the passenger's name to the provided value
    void setName(string name);

    // Setter method: sets the passenger's age to the provided value
    void setAge(int age);

    // Setter method: sets the passenger's ID to the provided value
    void setId(string id);

    // Display method: prints all passenger information to the console
    void displayPassenger();
};

#endif // end of header guard
