// Customer.cpp - Implementation file for Customer derived class
// Contains all method definitions for the Customer class

#include "Customer.h" // include the Customer header file
#include <iostream> // for cout to display output

using namespace std; // to use cout and string without std:: prefix

// constructor implementation - calls base class constructor using initializer list
Customer::Customer(string id, string uname, string pass, string mail, string name, string phone)
    : User(id, uname, pass, mail, name, phone) // call User base class constructor
{
    loyaltyPoints = 0; // initialize loyalty points to zero for new customer
    membershipTier = "Bronze"; // set default membership tier to Bronze
    bookingCount = 0; // initialize booking count to zero
    maxBookings = 50; // set maximum booking history capacity to 50
    bookingHistory = new Booking[maxBookings]; // allocate dynamic array for booking history
}

// destructor implementation - deallocates dynamic memory
Customer::~Customer()
{
    delete[] bookingHistory; // free the dynamically allocated booking history array
    bookingHistory = nullptr; // set pointer to null for safety
}

// override displayInfo method - demonstrates polymorphism
void Customer::displayInfo()
{
    User::displayInfo(); // call base class displayInfo to display common user information
    cout << "Loyalty Points: " << loyaltyPoints << "\n"; // display customer's loyalty points
    cout << "Membership Tier: " << membershipTier << "\n"; // display customer's membership tier
    cout << "Total Bookings: " << bookingCount << "\n"; // display total number of bookings
    cout << "==========================================\n"; // print separator line
}

// override login method - demonstrates polymorphism
bool Customer::login(string inputUsername, string inputPassword)
{
    bool loginSuccess = User::login(inputUsername, inputPassword); // call base class login method

    if (loginSuccess) // if login was successful
    {
        cout << "\n==========================================\n"; // print separator line
        cout << "   Welcome back, " << getFullName() << "!\n"; // display personalized welcome message
        cout << "   Membership Tier: " << membershipTier << "\n"; // show customer's tier
        cout << "   Loyalty Points: " << loyaltyPoints << "\n"; // show customer's points
        cout << "==========================================\n"; // print separator line
        return true; // return true for successful login
    }

    return false; // return false if login failed
}

// addBookingToHistory method - adds a booking to customer's history
void Customer::addBookingToHistory(Booking b)
{
    if (bookingCount < maxBookings) // check if there is space in the booking history array
    {
        bookingHistory[bookingCount] = b; // add the booking to the array at current count index
        bookingCount = bookingCount + 1; // increment the booking count by one
        cout << "Booking added to your history.\n"; // confirm booking was added
    }
    else // if booking history array is full
    {
        cout << "Booking history is full. Cannot add more bookings.\n"; // display error message
    }
}

// viewBookingHistory method - displays all bookings in customer's history
void Customer::viewBookingHistory()
{
    cout << "\n==========================================\n"; // print separator line
    cout << "        YOUR BOOKING HISTORY\n"; // print header
    cout << "==========================================\n"; // print separator line

    if (bookingCount == 0) // check if customer has no bookings
    {
        cout << "You have no bookings yet.\n"; // display message for empty history
        cout << "==========================================\n"; // print separator line
        return; // exit the method
    }

    for (int i = 0; i < bookingCount; i = i + 1) // loop through all bookings in history
    {
        cout << "\nBooking #" << (i + 1) << ":\n"; // display booking number
        bookingHistory[i].displayBooking(); // call displayBooking method for this booking
    }

    cout << "==========================================\n"; // print separator line
}

// getter method for loyaltyPoints
int Customer::getLoyaltyPoints()
{
    return loyaltyPoints; // return the current loyalty points value
}

// addLoyaltyPoints method - adds points to customer's account
void Customer::addLoyaltyPoints(int points)
{
    if (points > 0) // check if points to add is a positive number
    {
        loyaltyPoints = loyaltyPoints + points; // add the points to current loyalty points
        cout << points << " loyalty points added. Total: " << loyaltyPoints << "\n"; // confirm points added
        updateMembershipTier(); // check if tier should be upgraded based on new points
    }
    else // if points is zero or negative
    {
        cout << "Invalid points value. Points must be positive.\n"; // display error message
    }
}

// getter method for membershipTier
string Customer::getMembershipTier()
{
    return membershipTier; // return the current membership tier
}

// updateMembershipTier method - upgrades tier based on loyalty points
void Customer::updateMembershipTier()
{
    string oldTier = membershipTier; // store the current tier before update

    if (loyaltyPoints >= 10000) // check if points qualify for Platinum tier
    {
        membershipTier = "Platinum"; // upgrade to Platinum tier
    }
    else if (loyaltyPoints >= 5000) // check if points qualify for Gold tier
    {
        membershipTier = "Gold"; // upgrade to Gold tier
    }
    else if (loyaltyPoints >= 2000) // check if points qualify for Silver tier
    {
        membershipTier = "Silver"; // upgrade to Silver tier
    }
    else // if points are below 2000
    {
        membershipTier = "Bronze"; // keep or set to Bronze tier
    }

    bool tierChanged = (oldTier != membershipTier); // check if tier was upgraded

    if (tierChanged) // if tier has changed
    {
        cout << "Congratulations! You have been upgraded to " << membershipTier << " tier!\n"; // display upgrade message
    }
}

// getter method for bookingCount
int Customer::getBookingCount()
{
    return bookingCount; // return the current number of bookings
}

// setter method for loyaltyPoints
void Customer::setLoyaltyPoints(int points)
{
    if (points >= 0) // check if points value is non-negative
    {
        loyaltyPoints = points; // set loyalty points to the specified value
    }
    else // if points is negative
    {
        cout << "Invalid points value. Points cannot be negative.\n"; // display error message
    }
}

// setter method for membershipTier
void Customer::setMembershipTier(string tier)
{
    membershipTier = tier; // set membership tier to the specified value
}
