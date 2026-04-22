# Modular File Structure

## Overview
The codebase has been reorganized into a clean modular structure with separation of concerns.

## Directory Structure

```
src/
├── main.cpp                    # Entry point - only contains main() function
├── constants.cpp               # All constant definitions
├── domain/                     # Domain classes (business logic)
│   ├── Admin.cpp/h
│   ├── Airline.cpp/h
│   ├── Booking.cpp/h
│   ├── CashPayment.cpp/h
│   ├── CreditCardPayment.cpp/h
│   ├── Customer.cpp/h
│   ├── Flight.cpp/h
│   ├── Passenger.cpp/h
│   ├── Payment.cpp/h
│   ├── PointsPayment.cpp/h
│   ├── Seat.cpp/h
│   └── User.cpp/h
├── services/                   # Service layer functions
│   └── helpers.cpp            # All helper functions (booking, cancellation, etc.)
├── ui/                        # User interface components
│   └── menu.cpp              # Menu display functions
└── manager/                   # Reserved for future manager classes
```

## File Responsibilities

### main.cpp
- Contains only the main() function
- Includes all necessary headers
- Orchestrates the application flow
- Handles the main menu loop

### constants.cpp
- Defines all system constants
- MAX_FLIGHTS, MAX_SEATS, MAX_BOOKINGS
- ECONOMY_PRICE, BUSINESS_PRICE

### ui/menu.cpp
- displayMainMenu() - Shows the main menu

### services/helpers.cpp
- clearInputBuffer() - Clears input buffer
- viewAllFlights() - Displays all flights
- searchFlightsByRoute() - Searches flights by route
- bookSeat() - Handles seat booking with payment
- cancelBooking() - Handles booking cancellation
- viewBookingDetails() - Displays booking details
- displayFlightManifest() - Shows passenger manifest
- testUserHierarchy() - Demonstrates polymorphism with User classes
- testPaymentMethods() - Demonstrates polymorphism with Payment classes

### domain/
Contains all business logic classes with their implementations

## Compilation

```bash
g++ src/main.cpp src/domain/*.cpp -o airline
```

## Benefits

1. **Separation of Concerns**: Each file has a clear, single responsibility
2. **Maintainability**: Easy to locate and modify specific functionality
3. **Readability**: main.cpp is now clean and easy to understand
4. **Scalability**: Easy to add new services or UI components
5. **Organization**: Logical grouping of related functionality

## Future Enhancements

- Add manager classes in src/manager/ for business logic coordination
- Add more service modules as needed
- Keep domain classes focused on data and core business rules
