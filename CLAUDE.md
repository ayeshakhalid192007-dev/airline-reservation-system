# CLAUDE.md — C++ OOP Project Guidelines
---
## SECTION 1: LANGUAGE AND CODING STANDARDS

**Language:** C++ (Pure, Standard Only)

**Type:** Terminal-Based Console Application

**Compiler Command:** `g++ main.cpp -o <program_name>`

**Run Command:** `./<program_name>`

**Difficulty Level:** Intermediate OOP (beginner-friendly syntax)

**Purpose:** Learn and demonstrate core OOP concepts through practical projects

---

## SECTION 2: STRICT CODING RULES

Claude must follow every rule below — no exceptions.

### RULE 1 — LANGUAGE PURITY
- Use only pure standard C++
- Only these headers are allowed: `#include <iostream>`, `#include <string>`, `#include <cstring>`
- No Python, no Java, no other language mixed in
- No external libraries, no frameworks, no third-party code
- No advanced header files beyond the three allowed

### RULE 2 — NO STL CONTAINERS
- Never use vectors, maps, sets, lists, queues, stacks, or any STL container
- All collections must use plain C++ arrays of fixed size
- Example: Use `Student students[50]` not `vector<Student> students`

### RULE 3 — ORGANIZED FILE STRUCTURE
- Never write all code directly in `main.cpp`
- Create separate utility files for different components and import them into main
- Use `#include "filename.cpp"` to import utility files into main.cpp
- Organize code into logical utility files (e.g., classes.cpp, helpers.cpp, menu.cpp)
- The main.cpp file should only contain the main() function and necessary includes
- Keep the project structure clean and modular while avoiding unnecessary file creation

### RULE 4 — COMMENT EVERY LINE
- Every single line of code must have a comment explaining what it does
- Comments go on the same line using `//`
- No line of code is allowed to exist without a comment
- Example: `int studentAge; // stores the age of the student`

### RULE 5 — BEGINNER-FRIENDLY NAMING
- All variable names must be simple, full English words
- No abbreviations like arr, ptr, tmp, cnt, sz, idx
- Good examples: `studentName`, `bookTitle`, `accountBalance`, `itemCounter`
- Bad examples: `arr[i]`, `ptr->x`, `tmpVal`, `cntItems`

### RULE 6 — NO POINTERS UNLESS NECESSARY
- Avoid raw pointers wherever possible
- Use object instances and object arrays directly
- If a pointer is absolutely needed, explain why in a comment above it

### RULE 7 — FIXED ARRAY SIZES
- All array sizes must be defined as constants at the top of the file
- Use meaningful constant names like MAX_STUDENTS, MAX_BOOKS, MAX_ACCOUNTS
- Never use magic numbers directly in array declarations

### RULE 8 — INPUT VALIDATION
- Every user input from cin must be checked for basic validity
- If invalid input is entered, show a clear error message and ask again
- Never let the program crash on bad input

### RULE 9 — NO DYNAMIC MEMORY
- Never use `new` or `delete` keywords
- No heap allocation of any kind
- All objects must be created on the stack

### RULE 10 — CLEAN TERMINAL OUTPUT
- Every output section must have a separator line of `=` or `-` characters
- All menus must be centered and clearly labeled
- Leave blank lines between sections for readability

### RULE 11 — AVOID UNNECESSARY FILES
- Only create files that are absolutely essential for the project
- Do not create extra documentation files, notes, or temporary files unless explicitly requested
- Do not create backup files or duplicate versions
- Keep the project directory clean with only necessary source files and the README.md
- Every file created must serve a clear, specific purpose in the project

### RULE 12 — USE CONTEXT7 FOR AUTHENTIC C++ SYNTAX
- Before writing any C++ OOP code, query Context7 MCP server for authentic syntax
- Never hallucinate or invent C++ syntax from training data
- Verify syntax for: inheritance, polymorphism, operator overloading, friend functions, copy constructors
- Ensure all code follows standard C++ conventions
- Keep examples simple and beginner-friendly, not enterprise-level

---

## SECTION 3: REQUIRED OOP CONCEPTS

Every C++ OOP project must demonstrate these concepts:

### CONCEPT 1 — CLASSES AND OBJECTS
- Every project must have at least 3 classes
- Each class must represent a real-world entity
- Objects must be created from classes and used throughout the program

### CONCEPT 2 — ENCAPSULATION
- All data members in every class must be declared `private`
- Every private data member must have a public getter method
- Every private data member must have a public setter method
- No data member is ever accessed directly from outside the class

### CONCEPT 3 — CONSTRUCTORS AND DESTRUCTORS
- Every class must have at least one constructor
- Constructors must initialize all member variables
- Destructors should be defined if cleanup is needed
- Destructors must have a comment explaining what they clean up

### CONCEPT 4 — CONSTRUCTOR OVERLOADING
- At least two classes must demonstrate constructor overloading
- Each class must have: a default constructor (no parameters) and a parameterized constructor
- Both constructors must properly initialize all member variables

### CONCEPT 5 — COPY CONSTRUCTOR
- At least one class must implement a copy constructor
- The copy constructor must create a deep copy of all member variables
- Add a comment explaining why the copy constructor is needed

### CONCEPT 6 — ARRAYS OF OBJECTS
- At least one class must contain an array of objects as a member variable
- The array must be a fixed-size array, not a pointer
- Example: A School class containing `Student students[100]`

### CONCEPT 7 — STATIC CLASS MEMBERS
- At least one class must have a static data member
- The static member must be initialized outside the class definition
- At least one static member function must be defined
- Static members should be used for class-level data (like counters or shared values)

### CONCEPT 8 — INHERITANCE
- At least one pair of classes must demonstrate inheritance
- Use single inheritance (one base class, one derived class)
- The derived class must inherit from the base class using public inheritance
- The derived class must add new members or override base class behavior

### CONCEPT 9 — MULTI-LEVEL INHERITANCE
- At least one chain of classes must demonstrate multi-level inheritance
- Example: Class A → Class B → Class C (C inherits from B, B inherits from A)
- Each level must add meaningful functionality

### CONCEPT 10 — PROTECTED SPECIFIER
- Base classes in inheritance must use `protected` members
- Protected members should be accessible to derived classes but not to outside code
- Add comments explaining why certain members are protected

### CONCEPT 11 — POLYMORPHISM
- At least one base class must have virtual functions
- Derived classes must override these virtual functions
- Demonstrate runtime polymorphism by calling virtual functions through base class pointers or references

### CONCEPT 12 — OPERATOR OVERLOADING
- At least one class must overload at least one operator
- Common operators to overload: `+`, `-`, `==`, `<<`, `>>`
- The overloaded operator must make logical sense for the class
- Add comments explaining what the operator does

### CONCEPT 13 — FRIEND FUNCTIONS
- At least one class must declare a friend function
- The friend function must access private members of the class
- Add a comment explaining why the function needs to be a friend

### CONCEPT 14 — ABSTRACTION
- Classes must hide implementation details and expose only necessary interfaces
- Complex operations should be broken into private helper methods
- Public methods should provide simple, clear interfaces

### CONCEPT 15 — REUSABILITY
- Classes should be designed to be reusable in different contexts
- Avoid hardcoding values inside classes
- Use parameters and configuration to make classes flexible

### CONCEPT 16 — CLASS RELATIONSHIPS
- Demonstrate composition: one class contains objects of another class
- Demonstrate aggregation: one class has a reference to objects of another class
- Demonstrate association: classes interact with each other through method calls

---

## SECTION 4: OOP CONCEPTS IMPLEMENTATION GUIDE

### ENCAPSULATION IMPLEMENTATION
- Declare all data members as `private:`
- Create getter methods with names like `getName()`, `getAge()`, `getBalance()`
- Create setter methods with names like `setName()`, `setAge()`, `setBalance()`
- Getters should return the value of the private member
- Setters should take a parameter and assign it to the private member
- Add validation in setters if needed (e.g., age cannot be negative)

### CONSTRUCTOR IMPLEMENTATION
- Default constructor: takes no parameters, initializes members to default values
- Parameterized constructor: takes parameters, initializes members with those values
- Copy constructor: takes a reference to another object of the same class, copies all members
- Constructor overloading: multiple constructors with different parameter lists

### STATIC MEMBERS IMPLEMENTATION
- Declare static data member inside the class with `static` keyword
- Initialize static data member outside the class: `int ClassName::staticMember = 0;`
- Static member functions can only access static data members
- Call static functions using class name: `ClassName::staticFunction()`

### INHERITANCE IMPLEMENTATION
- Base class: the parent class that is inherited from
- Derived class: the child class that inherits from the base class
- Use syntax: `class Derived : public Base`
- Derived class automatically gets all public and protected members of base class
- Derived class can add new members and methods
- Derived class can override base class methods

### POLYMORPHISM IMPLEMENTATION
- Declare functions in base class as `virtual`
- Override virtual functions in derived classes
- Use base class pointer or reference to point to derived class objects
- When calling virtual function through base class pointer, derived class version is called
- This is runtime polymorphism (dynamic binding)

### OPERATOR OVERLOADING IMPLEMENTATION
- Define operator function inside or outside the class
- Syntax inside class: `ReturnType operator+(const ClassName& other)`
- Syntax outside class: `ReturnType operator+(const ClassName& obj1, const ClassName& obj2)`
- Return appropriate type (often the class itself or a bool for comparison operators)
- For `<<` and `>>` operators, declare as friend functions

### FRIEND FUNCTION IMPLEMENTATION
- Declare friend function inside the class using `friend` keyword
- Define the friend function outside the class (without `friend` keyword)
- Friend function can access private and protected members of the class
- Friend function is not a member of the class
- Use friend functions for operator overloading or when two classes need to access each other's private data

---

## SECTION 5: INHERITANCE AND POLYMORPHISM RULES

### INHERITANCE RULE 1 — SINGLE INHERITANCE
- One derived class inherits from one base class
- Use `public` inheritance: `class Derived : public Base`
- Derived class gets all public and protected members of base class
- Private members of base class are not accessible in derived class

### INHERITANCE RULE 2 — MULTI-LEVEL INHERITANCE
- Class B inherits from Class A
- Class C inherits from Class B
- Class C gets members from both A and B
- Each level should add meaningful functionality

### INHERITANCE RULE 3 — PROTECTED MEMBERS
- Use `protected:` access specifier in base class
- Protected members are accessible in derived classes
- Protected members are not accessible outside the class hierarchy
- Use protected for data that derived classes need to access

### INHERITANCE RULE 4 — CONSTRUCTOR CHAINING
- When creating a derived class object, base class constructor is called first
- Derived class constructor can explicitly call base class constructor
- Use initialization list to call base class constructor

### POLYMORPHISM RULE 1 — VIRTUAL FUNCTIONS
- Declare functions as `virtual` in base class
- Override virtual functions in derived classes
- Virtual functions enable runtime polymorphism

### POLYMORPHISM RULE 2 — PURE VIRTUAL FUNCTIONS (AVOID)
- Do not use pure virtual functions (abstract classes) in beginner projects
- Pure virtual functions make classes abstract and add complexity
- Stick to regular virtual functions that have implementations

### POLYMORPHISM RULE 3 — VIRTUAL DESTRUCTORS
- If a class has virtual functions, its destructor should also be virtual
- This ensures proper cleanup when deleting derived class objects through base class pointers

---

## SECTION 6: SPECIAL FEATURES GUIDE

### STATIC MEMBERS USAGE
- Use static data members for class-level counters (e.g., total number of objects created)
- Use static data members for shared configuration values
- Use static member functions for utility functions that don't need object state
- Static members belong to the class, not to individual objects

### FRIEND FUNCTIONS USAGE
- Use friend functions when a function needs to access private data of multiple classes
- Use friend functions for operator overloading (especially `<<` and `>>`)
- Use friend functions sparingly — they break encapsulation
- Always add a comment explaining why a function needs to be a friend

### OPERATOR OVERLOADING USAGE
- Overload `+` for adding two objects (e.g., adding two complex numbers)
- Overload `-` for subtracting two objects
- Overload `==` for comparing two objects for equality
- Overload `<<` for output (printing object to cout)
- Overload `>>` for input (reading object from cin)
- Make sure overloaded operators behave intuitively

### COPY CONSTRUCTOR USAGE
- Use copy constructor when an object contains dynamically allocated memory (though we avoid this)
- Use copy constructor when an object contains resources that need special copying
- Copy constructor is called when: passing object by value, returning object by value, initializing object with another object
- Syntax: `ClassName(const ClassName& other)`

---

## SECTION 7: SYNTAX SIMPLICITY RULES

Mandatory syntax rules Claude must never violate:

### SIMPLE SYNTAX RULE 1 — NO COMPLEX EXPRESSIONS
- Never write two operations on the same line
- Bad: `array[++index].setValue(flag == true ? 1 : 0);`
- Good: Write each operation on a separate line with clear variable names

### SIMPLE SYNTAX RULE 2 — NO TERNARY OPERATORS
- Never use the ternary operator `? :`
- Always use a full if/else block instead

### SIMPLE SYNTAX RULE 3 — NO NESTED FUNCTION CALLS
- Never call a function inside another function call on the same line
- Bad: `object.method(createObject(getValue(x, y)));`
- Good: Break into separate lines with intermediate variables

### SIMPLE SYNTAX RULE 4 — ONE STATEMENT PER LINE
- Every statement must be on its own separate line
- Never chain multiple statements with semicolons on one line

### SIMPLE SYNTAX RULE 5 — ALLOWED OOP FEATURES
- DO use: classes, objects, constructors, destructors, encapsulation
- DO use: inheritance (single and multi-level), polymorphism (virtual functions)
- DO use: operator overloading, friend functions, static members
- DO use: copy constructors, protected specifiers
- DO NOT use: templates, generic programming, abstract base classes
- DO NOT use: multiple inheritance, virtual inheritance
- Keep it simple and educational

### SIMPLE SYNTAX RULE 6 — SIMPLE IF/ELSE ONLY
- Use only simple if, else if, else blocks for all decisions
- Switch/case is allowed only for menus
- Never nest more than 2 levels of if/else inside each other
- If logic is getting deeply nested, break it into a separate method

### SIMPLE SYNTAX RULE 7 — SIMPLE LOOPS ONLY
- Use only for loops and while loops
- Never use do-while loops
- Never use complex loop conditions with multiple `&&` or `||` on one line
- Break complex conditions into separate bool variables first

### SIMPLE SYNTAX RULE 8 — SIMPLE STRING OPERATIONS ONLY
- Only use `==` to compare strings
- Only use `=` to assign strings
- Only use `+` to join strings
- Never use string iterators or string algorithms
- Never use substr, find, replace unless absolutely necessary
- If substr or find is needed, write a comment explaining exactly what it does

### SIMPLE SYNTAX RULE 9 — CLEAR RETURN STATEMENTS
- Every function that returns a value must have one clear return statement
- Never return complex expressions
- Assign result to a variable first, then return the variable

### SIMPLE SYNTAX RULE 10 — READABLE BOOLEAN VARIABLES
- Never use raw true/false in conditions without a named variable
- Always assign bool results to a clearly named variable first

### SIMPLE SYNTAX RULE 11 — SPACING AND INDENTATION
- Use 4 spaces for every level of indentation (no tabs)
- Always put opening curly brace `{` on its own new line
- Always put closing curly brace `}` on its own new line
- Leave one blank line between every method definition
- Leave one blank line between every major block inside a method

### SIMPLE SYNTAX RULE 12 — AVOID CONFUSING SYMBOLS
- Never use bitwise operators: `&`, `|`, `^`, `~`, `<<`, `>>`
- Never use pointer arithmetic: `*`, `->`, `&variable`
- Never use increment/decrement inside expressions: `array[i++]`, `*ptr++`
- Always increment/decrement on a separate line

### SIMPLE SYNTAX RULE 13 — FUNCTION SIZE LIMIT
- No single function or method should be longer than 30 lines
- If a method is getting longer than 30 lines, break it into 2 smaller helper methods
- This keeps every function easy to read in one glance

### SIMPLE SYNTAX RULE 14 — NO MAGIC NUMBERS
- Never use raw numbers directly in logic
- Always define them as named constants at the top

### SIMPLE SYNTAX RULE 15 — WRITE FOR A BEGINNER READER
- Imagine the person reading this code has only 3 months of C++ experience
- Every piece of logic must be so clear that a beginner can understand it without asking any questions
- If a block of code feels clever or tricky, rewrite it to be simpler
- Simple and correct is always better than clever and confusing

---

## SECTION 8: DEBUGGING RULES

Mandatory debugging steps Claude must follow:

- **RULE D1:** Never apply a fix without first identifying the root cause
- **RULE D2:** Read every error message completely before doing anything
- **RULE D3:** Reproduce the bug with a specific test case before fixing
- **RULE D4:** Trace the data flow backward from the error to the source
- **RULE D5:** Write the hypothesis as a comment before applying the fix
- **RULE D6:** Make the smallest possible change to test the hypothesis
- **RULE D7:** If 3 fixes fail in a row, stop and reconsider the class design
- **RULE D8:** Never stack multiple fixes at the same time
- **RULE D9:** After every fix, re-verify the entire affected class works
- **RULE D10:** Never say the bug is fixed without actually testing it

---

## SECTION 9: DOCUMENTATION RULES

Rules for documentation:

- **DOC RULE 1:** Write a full project header comment block at the very top of main.cpp
- **DOC RULE 2:** Every class must have a comment block above it describing its purpose
- **DOC RULE 3:** Every method must have a comment above it describing what it does
- **DOC RULE 4:** Every section of main() must have a comment describing what that section does
- **DOC RULE 5:** A README.md file must be created alongside main.cpp
- **DOC RULE 6:** README.md must include: project description, how to compile, how to run, OOP concepts used, class list, feature list

---

## SECTION 10: GENERAL VERIFICATION CHECKLIST

Must all be true before any project is complete:

- [ ] All required OOP concepts are implemented (see Section 3)
- [ ] Encapsulation is applied in every class (private data, public getters/setters)
- [ ] At least one class demonstrates constructor overloading
- [ ] At least one class demonstrates copy constructor
- [ ] At least one class contains an array of objects
- [ ] At least one class has static members (data and function)
- [ ] At least one pair of classes demonstrates inheritance
- [ ] At least one chain demonstrates multi-level inheritance
- [ ] At least one base class uses protected members
- [ ] At least one class demonstrates polymorphism with virtual functions
- [ ] At least one class demonstrates operator overloading
- [ ] At least one class demonstrates friend function
- [ ] Every line of code has a comment
- [ ] No variable name is abbreviated or unclear
- [ ] All user inputs are validated
- [ ] Program handles invalid input without crashing
- [ ] Code is organized into proper utility files
- [ ] main.cpp only contains the main() function and necessary includes
- [ ] No unnecessary files exist in the project directory
- [ ] Code compiles cleanly with: `g++ main.cpp -o <program_name>`
- [ ] Program runs correctly
- [ ] All syntax simplicity rules are followed
- [ ] No STL containers are used (only plain arrays)
- [ ] Only allowed headers are used: iostream, string, cstring
- [ ] No dynamic memory allocation (no new/delete)
- [ ] README.md is complete and accurate

---

## SECTION 11: CONTEXT7 USAGE REQUIREMENT

**CRITICAL INSTRUCTION:**

Before writing any C++ OOP code, Claude MUST:

1. Query the Context7 MCP server for authentic C++ syntax
2. Verify syntax for: inheritance, polymorphism, virtual functions, operator overloading, friend functions, copy constructors, static members
3. Never hallucinate or invent C++ syntax from training data
4. Ensure all code examples follow standard C++ conventions
5. Keep all examples simple and beginner-friendly
6. Avoid enterprise-level patterns or complex architectures
7. Focus on educational clarity, not production-ready code

**How to use Context7:**
- Use `mcp__plugin_context7_context7__resolve-library-id` to find C++ documentation
- Use `mcp__plugin_context7_context7__query-docs` to get specific syntax examples
- Always verify syntax before writing code
- If Context7 is unavailable, use web search for cppreference.com or learncpp.com

---

## SECTION 12: FINAL INSTRUCTION TO CLAUDE

When working on any C++ OOP project, Claude must:

1. Read this entire CLAUDE.md file before writing a single line of code
2. Follow every rule in every section without exception
3. Complete the project in the exact phase order:
   **Plan → Build class by class → Test each class → Debug → Verify checklist → Document**
4. Never skip a phase even if the task seems simple
5. Never mark the project as complete unless every item in Section 10 is confirmed
6. If any rule conflicts with a user request, follow the rule and explain why
7. Always prioritize correctness over speed
8. Always use Context7 or web search to verify C++ syntax before writing code
9. Keep all code simple, educational, and beginner-friendly
10. This CLAUDE.md file is the single source of truth for all C++ OOP projects

---

**END OF CLAUDE.MD**

This file is the universal guide for all C++ OOP projects.
All development must strictly adhere to these specifications.
