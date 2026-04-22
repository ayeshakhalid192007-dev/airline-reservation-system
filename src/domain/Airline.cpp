#include "Airline.h" // includes the Airline class header file
#include <iostream> // includes input/output stream for console operations

using namespace std; // allows use of cout, cin without std:: prefix

Airline::Airline(string name, string code) // constructor implementation with name and code parameters
{
    airlineName = name; // initializes airline name with provided parameter
    airlineCode = code; // initializes airline code with provided parameter
    maxFlights = 10; // sets maximum flight capacity to 10
    flightCount = 0; // initializes current flight count to zero
    flights = new Flight[maxFlights]; // allocates dynamic array of Flight objects
}

Airline::~Airline() // destructor implementation to free memory
{
    if (flights != nullptr) // checks if flights pointer is not null
    {
        delete[] flights; // deallocates the dynamic array of flights
        flights = nullptr; // sets pointer to null after deletion
    }
}

bool Airline::addFlight(Flight newFlight) // adds a new flight to the airline
{
    if (flightCount >= maxFlights) // checks if array is full
    {
        cout << "Cannot add flight. Maximum capacity reached." << endl; // displays error message
        return false; // returns false indicating failure
    }

    flights[flightCount] = newFlight; // adds new flight at current count index
    flightCount = flightCount + 1; // increments flight count by one
    cout << "Flight added successfully." << endl; // displays success message
    return true; // returns true indicating success
}

bool Airline::removeFlight(string flightNumber) // removes a flight by flight number
{
    int index = findFlight(flightNumber); // finds the index of the flight

    if (index == -1) // checks if flight was not found
    {
        cout << "Flight not found." << endl; // displays error message
        return false; // returns false indicating failure
    }

    int i = index; // initializes loop counter with found index
    while (i < flightCount - 1) // loops through remaining flights
    {
        flights[i] = flights[i + 1]; // shifts flight one position left
        i = i + 1; // increments loop counter
    }

    flightCount = flightCount - 1; // decrements flight count by one
    cout << "Flight removed successfully." << endl; // displays success message
    return true; // returns true indicating success
}

int Airline::findFlight(string flightNumber) // finds flight index by flight number
{
    int i = 0; // initializes loop counter to zero
    while (i < flightCount) // loops through all flights
    {
        string currentFlightNumber = flights[i].getFlightNumber(); // gets flight number at current index
        if (currentFlightNumber == flightNumber) // checks if flight number matches
        {
            return i; // returns the index of found flight
        }
        i = i + 1; // increments loop counter
    }
    return -1; // returns -1 if flight not found
}

void Airline::searchFlights(string origin, string destination) // searches flights by route
{
    cout << "===========================================" << endl; // displays separator line
    cout << "  SEARCH RESULTS: " << origin << " to " << destination << endl; // displays search header
    cout << "===========================================" << endl; // displays separator line

    int foundCount = 0; // initializes counter for found flights
    int i = 0; // initializes loop counter to zero

    while (i < flightCount) // loops through all flights
    {
        string flightOrigin = flights[i].getOrigin(); // gets origin city of current flight
        string flightDestination = flights[i].getDestination(); // gets destination city of current flight

        bool originMatches = (flightOrigin == origin); // checks if origin matches
        bool destinationMatches = (flightDestination == destination); // checks if destination matches

        if (originMatches && destinationMatches) // checks if both origin and destination match
        {
            flights[i].displayFlight(); // displays the matching flight details
            foundCount = foundCount + 1; // increments found counter
        }

        i = i + 1; // increments loop counter
    }

    if (foundCount == 0) // checks if no flights were found
    {
        cout << "No flights found for this route." << endl; // displays no results message
    }

    cout << "===========================================" << endl; // displays separator line
}

void Airline::displayAllFlights() // displays all flights in the airline
{
    cout << "===========================================" << endl; // displays separator line
    cout << "  ALL FLIGHTS - " << airlineName << " (" << airlineCode << ")" << endl; // displays airline header
    cout << "===========================================" << endl; // displays separator line

    if (flightCount == 0) // checks if no flights exist
    {
        cout << "No flights available." << endl; // displays no flights message
    }
    else // executes if flights exist
    {
        int i = 0; // initializes loop counter to zero
        while (i < flightCount) // loops through all flights
        {
            cout << "Flight " << (i + 1) << ":" << endl; // displays flight number
            flights[i].displayFlight(); // displays flight details
            cout << endl; // adds blank line for readability
            i = i + 1; // increments loop counter
        }
    }

    cout << "===========================================" << endl; // displays separator line
}

void Airline::loadSampleData() // loads pre-defined sample flights
{
    Flight flight1; // creates first sample flight object
    flight1.setFlightNumber("PK-301"); // sets flight number
    flight1.setOrigin("Lahore"); // sets origin city
    flight1.setDestination("Karachi"); // sets destination city
    flight1.setDepartureDate("2025-06-01"); // sets flight date
    flight1.setDepartureTime("10:00"); // sets departure time
    flight1.setArrivalTime("12:00"); // sets arrival time
    flight1.initializeSeats(7); // initializes 7 total seats

    Flight flight2; // creates second sample flight object
    flight2.setFlightNumber("PK-502"); // sets flight number
    flight2.setOrigin("Islamabad"); // sets origin city
    flight2.setDestination("Dubai"); // sets destination city
    flight2.setDepartureDate("2025-06-05"); // sets flight date
    flight2.setDepartureTime("14:00"); // sets departure time
    flight2.setArrivalTime("17:00"); // sets arrival time
    flight2.initializeSeats(6); // initializes 6 total seats

    addFlight(flight1); // adds first flight to airline
    addFlight(flight2); // adds second flight to airline

    cout << "Sample data loaded successfully." << endl; // displays success message
}

string Airline::getAirlineName() // returns the airline name
{
    return airlineName; // returns airline name value
}

void Airline::setAirlineName(string name) // sets the airline name
{
    airlineName = name; // assigns new name to airline name
}

string Airline::getAirlineCode() // returns the airline code
{
    return airlineCode; // returns airline code value
}

void Airline::setAirlineCode(string code) // sets the airline code
{
    airlineCode = code; // assigns new code to airline code
}

int Airline::getFlightCount() // returns current number of flights
{
    return flightCount; // returns flight count value
}

int Airline::getMaxFlights() // returns maximum flight capacity
{
    return maxFlights; // returns max flights value
}
