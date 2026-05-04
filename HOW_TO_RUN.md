# How to Run the Airline Reservation System

## Quick Start

### Option 1: Using Make (Recommended)
```bash
make run
```

### Option 2: Direct Execution
```bash
./bin/airline
```

### Option 3: Compile and Run Manually
```bash
# Clean previous builds
make clean

# Compile the project
make all

# Run the executable
./bin/airline
```

## Available Make Commands

- `make` or `make all` - Compile the project
- `make run` - Compile and run the program
- `make clean` - Remove all compiled files
- `make rebuild` - Clean and rebuild from scratch
- `make test` - Build and run test program
- `make help` - Show all available commands

## Executable Location

The compiled executable is located at: `bin/airline`

## System Requirements

- **Operating System**: Linux
- **Compiler**: g++ with C++11 support
- **Platform**: x86_64 Linux

## Notes

- The `.exe` file in the root directory is a Windows executable and won't run on Linux
- Always use `bin/airline` for Linux systems
- The program includes sample flight data that loads automatically on startup
- Use Ctrl+C to force quit if needed, or enter `0` in the menu to exit properly

## Troubleshooting

If you get "Permission denied" error:
```bash
chmod +x bin/airline
./bin/airline
```

If compilation fails:
```bash
make clean
make rebuild
```
