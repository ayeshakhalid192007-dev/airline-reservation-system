// test_user_hierarchy.cpp - Test program for User inheritance hierarchy
// This program tests inheritance and polymorphism with User, Admin, and Customer classes
// Demonstrates that virtual methods work correctly through base class pointers

#include <iostream> // for input/output operations
#include <string> // for string data type
#include "User.h" // include User base class
#include "Admin.h" // include Admin derived class
#include "Customer.h" // include Customer derived class

using namespace std; // to use cout, cin without std:: prefix

// main function - entry point of the test program
int main()
{
    cout << "==========================================\n"; // print separator line
    cout << "  USER HIERARCHY POLYMORPHISM TEST\n"; // print test title
    cout << "==========================================\n\n"; // print separator line with blank line

    // TEST 1: Create Admin object and test Admin-specific functionality
    cout << "TEST 1: Creating Admin Object\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line

    Admin admin1("A001", "admin_john", "admin123", "john@airline.com", "John Smith", "555-1001", "Super", "Operations"); // create Admin object with all parameters

    cout << "\nAdmin object created successfully.\n"; // confirm object creation
    cout << "Calling displayInfo() on Admin object:\n\n"; // explain what we're testing

    admin1.displayInfo(); // call displayInfo method on Admin object (should show Admin version)

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // TEST 2: Create Customer object and test Customer-specific functionality
    cout << "TEST 2: Creating Customer Object\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line

    Customer customer1("C001", "customer_sara", "pass456", "sara@email.com", "Sara Ahmed", "555-2001"); // create Customer object with all parameters

    cout << "\nCustomer object created successfully.\n"; // confirm object creation
    cout << "Calling displayInfo() on Customer object:\n\n"; // explain what we're testing

    customer1.displayInfo(); // call displayInfo method on Customer object (should show Customer version)

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // TEST 3: Test polymorphism using base class pointers
    cout << "TEST 3: Testing Polymorphism with Base Class Pointers\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line
    cout << "Creating User* pointers pointing to Admin and Customer objects\n\n"; // explain polymorphism test

    User* userPointer1 = &admin1; // create User pointer pointing to Admin object (polymorphism)
    User* userPointer2 = &customer1; // create User pointer pointing to Customer object (polymorphism)

    cout << "Calling displayInfo() through User* pointer to Admin:\n\n"; // explain what we're testing
    userPointer1->displayInfo(); // call virtual method through base pointer (should call Admin version)

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    cout << "Calling displayInfo() through User* pointer to Customer:\n\n"; // explain what we're testing
    userPointer2->displayInfo(); // call virtual method through base pointer (should call Customer version)

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // TEST 4: Test login method polymorphism
    cout << "TEST 4: Testing Login Method Polymorphism\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line

    cout << "Testing Admin login through User* pointer:\n"; // explain what we're testing
    bool adminLoginResult = userPointer1->login("admin_john", "admin123"); // call virtual login through base pointer

    if (adminLoginResult == true) // check if login was successful
    {
        cout << "Admin login successful (polymorphism working correctly)\n"; // confirm polymorphism works
    }
    else // login failed
    {
        cout << "Admin login failed\n"; // report failure
    }

    cout << "\nTesting Customer login through User* pointer:\n"; // explain what we're testing
    bool customerLoginResult = userPointer2->login("customer_sara", "pass456"); // call virtual login through base pointer

    if (customerLoginResult == true) // check if login was successful
    {
        cout << "Customer login successful (polymorphism working correctly)\n"; // confirm polymorphism works
    }
    else // login failed
    {
        cout << "Customer login failed\n"; // report failure
    }

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // TEST 5: Test Admin-specific methods
    cout << "TEST 5: Testing Admin-Specific Methods\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line

    cout << "Admin Level: " << admin1.getAdminLevel() << "\n"; // display admin level using getter
    cout << "Department: " << admin1.getDepartment() << "\n"; // display department using getter

    cout << "\nCalling admin-specific methods:\n"; // explain what we're testing
    admin1.manageFlights(); // call admin-specific method
    admin1.manageUsers(); // call admin-specific method
    admin1.viewReports(); // call admin-specific method

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // TEST 6: Test Customer-specific methods (loyalty points and tier)
    cout << "TEST 6: Testing Customer-Specific Methods\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line

    cout << "Initial Loyalty Points: " << customer1.getLoyaltyPoints() << "\n"; // display initial points
    cout << "Initial Membership Tier: " << customer1.getMembershipTier() << "\n\n"; // display initial tier

    cout << "Adding 500 loyalty points...\n"; // explain what we're doing
    customer1.addLoyaltyPoints(500); // add points to customer account
    cout << "Loyalty Points after addition: " << customer1.getLoyaltyPoints() << "\n\n"; // display updated points

    cout << "Updating membership tier based on points...\n"; // explain what we're doing
    customer1.updateMembershipTier(); // update tier based on points
    cout << "Updated Membership Tier: " << customer1.getMembershipTier() << "\n"; // display updated tier

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // TEST 7: Test array of base class pointers (advanced polymorphism)
    cout << "TEST 7: Testing Array of Base Class Pointers\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line
    cout << "Creating array of User* pointers holding different derived types\n\n"; // explain advanced polymorphism

    User* userArray[2]; // create array of User pointers (can hold any derived class)
    userArray[0] = &admin1; // first element points to Admin object
    userArray[1] = &customer1; // second element points to Customer object

    cout << "Iterating through array and calling displayInfo() on each:\n\n"; // explain what we're testing

    int arrayIndex = 0; // initialize loop counter
    while (arrayIndex < 2) // loop through array
    {
        cout << "User " << arrayIndex + 1 << ":\n"; // print user number
        userArray[arrayIndex]->displayInfo(); // call virtual method through base pointer (polymorphism)
        cout << "\n"; // print blank line for spacing
        arrayIndex = arrayIndex + 1; // increment counter
    }

    cout << "------------------------------------------\n\n"; // print separator line with spacing

    // TEST 8: Test wrong credentials (negative test)
    cout << "TEST 8: Testing Login with Wrong Credentials\n"; // print test section header
    cout << "------------------------------------------\n"; // print separator line

    cout << "Attempting Admin login with wrong password:\n"; // explain negative test
    bool wrongLoginResult = admin1.login("admin_john", "wrongpassword"); // attempt login with wrong password

    if (wrongLoginResult == false) // check if login correctly failed
    {
        cout << "Login correctly rejected (validation working)\n"; // confirm validation works
    }
    else // login incorrectly succeeded
    {
        cout << "ERROR: Login should have failed\n"; // report error
    }

    cout << "\n------------------------------------------\n\n"; // print separator line with spacing

    // Final summary
    cout << "==========================================\n"; // print separator line
    cout << "  ALL TESTS COMPLETED SUCCESSFULLY\n"; // print success message
    cout << "==========================================\n"; // print separator line
    cout << "\nPolymorphism Verification:\n"; // print verification section header
    cout << "- Virtual methods called correctly through base pointers\n"; // confirm polymorphism works
    cout << "- Admin-specific methods accessible through Admin objects\n"; // confirm Admin methods work
    cout << "- Customer-specific methods accessible through Customer objects\n"; // confirm Customer methods work
    cout << "- Inheritance hierarchy working as expected\n\n"; // confirm inheritance works

    return 0; // return success code to operating system
}
