# Running the Airline Reservation System Executables

This guide explains how to run the pre-compiled executables on Linux and Windows without recompiling.

---

## 📁 Executable Locations

### Linux Executables
- **Main executable:** `/home/ayeshakhalid/OOP-PROJECT/airline`
- **Backup copy:** `/home/ayeshakhalid/OOP-PROJECT/bin/airline`
- **File type:** ELF 64-bit executable
- **Size:** ~140 KB

### Windows Executable
- **Location:** `/home/ayeshakhalid/OOP-PROJECT/airline.exe`
- **File type:** PE32+ (Windows 64-bit)
- **Size:** ~2.4 MB
- **Note:** Larger due to static linking of C++ libraries

---

## 🐧 Running on Linux

### Method 1: Terminal (Recommended)
```bash
cd /home/ayeshakhalid/OOP-PROJECT
./airline
```

### Method 2: From Any Directory
```bash
/home/ayeshakhalid/OOP-PROJECT/airline
```

### Method 3: Desktop Launcher (Click to Run)

**Option A: Add to Desktop**
```bash
cp /home/ayeshakhalid/OOP-PROJECT/airline.desktop ~/Desktop/
```
Then double-click the icon on your desktop.

**Option B: Add to Applications Menu**
```bash
cp /home/ayeshakhalid/OOP-PROJECT/airline.desktop ~/.local/share/applications/
```
Then search for "Airline Reservation System" in your applications menu.

### Method 4: File Manager
1. Open your file manager
2. Navigate to `/home/ayeshakhalid/OOP-PROJECT/`
3. Right-click on `airline`
4. Select "Run in Terminal" or "Execute"

---

## 🪟 Running on Windows

### Method 1: Double-Click (Easiest)
1. Copy `airline.exe` to your Windows machine
2. Double-click `airline.exe`
3. A console window will open with the program

### Method 2: Command Prompt
1. Open Command Prompt (cmd)
2. Navigate to the folder containing `airline.exe`
3. Type: `airline.exe`
4. Press Enter

### Method 3: PowerShell
1. Open PowerShell
2. Navigate to the folder containing `airline.exe`
3. Type: `.\airline.exe`
4. Press Enter

### Method 4: Create Desktop Shortcut
1. Right-click on `airline.exe`
2. Select "Create shortcut"
3. Drag the shortcut to your Desktop
4. Double-click the shortcut to run

---

## 🔧 Recompiling (If Needed)

### Linux
```bash
./compile.sh
```
Or manually:
```bash
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline -I src/domain
```

### Windows (on Linux using MinGW)
```bash
x86_64-w64-mingw32-g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline.exe -I src/domain -static-libgcc -static-libstdc++
```

### Windows (on Windows)
Double-click `compile.bat` or run:
```cmd
g++ -std=c++11 src/main.cpp src/domain/*.cpp -o airline.exe -I src/domain
```

---

## ✅ Verification

### Check Linux Executable
```bash
file airline
# Output: airline: ELF 64-bit LSB pie executable, x86-64
```

### Check Windows Executable
```bash
file airline.exe
# Output: airline.exe: PE32+ executable for MS Windows
```

---

## 📝 Notes

- **Linux executable** works only on Linux systems
- **Windows executable** works on Windows 7, 8, 10, 11 (64-bit)
- Both executables are **standalone** - no additional libraries needed
- The Windows .exe is larger because it includes statically linked C++ runtime libraries
- Sample flight data loads automatically when the program starts

---

## 🚀 Quick Start

**Linux:**
```bash
./airline
```

**Windows:**
```cmd
airline.exe
```

That's it! The program will display the main menu and you can start using it immediately.

---

## 📞 Troubleshooting

### Linux: "Permission denied"
```bash
chmod +x airline
./airline
```

### Windows: "Windows protected your PC"
1. Click "More info"
2. Click "Run anyway"
(This happens because the .exe is not digitally signed)

### Linux: "No such file or directory"
Make sure you're in the correct directory:
```bash
cd /home/ayeshakhalid/OOP-PROJECT
```

---

**Last Updated:** May 4, 2026
