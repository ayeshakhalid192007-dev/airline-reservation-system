# How to Compile and Run on Your System

## For Windows Users

### Option 1: Using MinGW (Recommended)

1. **Install MinGW:**
   - Download from: https://sourceforge.net/projects/mingw/
   - Or install via MSYS2: https://www.msys2.org/

2. **Open Command Prompt** in the project directory

3. **Compile the project:**
   ```cmd
   g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline.exe -I src/domain
   ```

4. **Run the executable:**
   ```cmd
   airline.exe
   ```

### Option 2: Using Visual Studio

1. **Open Visual Studio**
2. **Create a new Console Application project**
3. **Add all .cpp files** from `src/` and `src/domain/`
4. **Add all .h files** from `src/domain/`
5. **Build the project** (Ctrl+Shift+B)
6. **Run** (F5 or Ctrl+F5 for without debugging)

### Option 3: Using Code::Blocks

1. **Open Code::Blocks**
2. **Create new project** → Console Application → C++
3. **Add all files** from src/ and src/domain/
4. **Build and Run** (F9)

---

## For Linux Users

### Compile:
```bash
cd /home/ayeshakhalid/OOP-PROJECT
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline -I src/domain
```

### Run:
```bash
./airline
```

---

## For Mac Users

### Compile:
```bash
cd /path/to/OOP-PROJECT
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline -I src/domain
```

### Run:
```bash
./airline
```

---

## What You'll See When You Run It

The program will display:

```
Flight added successfully.
Flight added successfully.
Sample data loaded successfully.

========================================
  WELCOME TO AIRLINE RESERVATION SYSTEM
========================================

==========================================
      AIRLINE RESERVATION SYSTEM
==========================================
  1. View All Flights
  2. Search Flights by Route
  3. Book a Seat
  4. Cancel Booking
  5. View Booking Details
  6. Display Flight Manifest
  7. Test User Hierarchy (Admin/Customer)
  8. Test Payment Methods
  0. Exit
==========================================
Enter your choice:
```

Then you can interact with the menu by entering numbers!

---

## Troubleshooting

### "g++ is not recognized"
- Install MinGW or GCC compiler
- Add compiler to system PATH

### "No such file or directory"
- Make sure you're in the project directory
- Check that all source files exist

### Compilation errors
- Make sure you're using C++11 or later
- Check that all .cpp and .h files are present

---

## Quick Compilation Script

### For Windows (compile.bat):
```batch
@echo off
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline.exe -I src/domain
if %errorlevel% equ 0 (
    echo Compilation successful!
    echo Run airline.exe to start the program
) else (
    echo Compilation failed!
)
pause
```

### For Linux/Mac (compile.sh):
```bash
#!/bin/bash
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline -I src/domain
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Run ./airline to start the program"
else
    echo "Compilation failed!"
fi
```

---

## Note About Executables

- **Linux executable** won't run on Windows
- **Windows .exe** won't run on Linux
- You must compile on your target system
- The source code is the same for all platforms
- Only the compiled executable is platform-specific

---

## Files You Need to Copy to Your System

Copy the entire `OOP-PROJECT` folder with:
- `src/` directory (all source files)
- `src/domain/` directory (all class files)
- `Makefile` (optional, for make command)

Then compile on your system using the instructions above!
