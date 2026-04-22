#ifndef AIRLINE_H // prevents multiple inclusion of this header file
#define AIRLINE_H // defines the header guard for Airline class

#include <string> // includes string class for airline name and code
#include "Flight.h" // includes Flight class for composition relationship

using namespace std; // allows use of string without std:: prefix

class Airline // defines the Airline class that manages multiple flights
{
private: // private section - data members hidden from outside access
    string airlineName; // stores the name of the airline
    string airlineCode; // stores the unique code of the airline
    Flight* flights; // pointer to dynamic array of Flight objects
    int maxFlights; // stores maximum capacity of flights array
    int flightCount; // stores current number of flights in the array

public: // public section - methods accessible from outside
    Airline(string name, string code); // constructor with airline name and code parameters
    ~Airline(); // destructor to free dynamically allocated memory

    bool addFlight(Flight newFlight); // adds a new flight to the airline
    bool removeFlight(string flightNumber); // removes a flight by flight number
    int findFlight(string flightNumber); // finds flight index by flight number
    void searchFlights(string origin, string destination); // searches flights by route
    void displayAllFlights(); // displays all flights in the airline
    void loadSampleData(); // loads pre-defined sample flights for testing

    string getAirlineName(); // returns the airline name
    void setAirlineName(string name); // sets the airline name
    string getAirlineCode(); // returns the airline code
    void setAirlineCode(string code); // sets the airline code
    int getFlightCount(); // returns current number of flights
    int getMaxFlights(); // returns maximum flight capacity
};

#endif // ends the header guard
