# Makefile for Airline Reservation System
# Purpose: Automate compilation and build process

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I src/domain
LDFLAGS =

# Directories
SRC_DIR = src/domain
BIN_DIR = bin
OBJ_DIR = bin

# Source files
DOMAIN_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
MAIN_SOURCE = src/main.cpp
TEST_SOURCE = src/test_user_hierarchy.cpp

# Object files
DOMAIN_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(DOMAIN_SOURCES))
MAIN_OBJECT = $(OBJ_DIR)/main.o
TEST_OBJECT = $(OBJ_DIR)/test_user_hierarchy.o

# Executable names
MAIN_EXEC = $(BIN_DIR)/airline
TEST_EXEC = $(BIN_DIR)/test_user_hierarchy

# Default target: build main program
all: $(MAIN_EXEC)

# Build main program
$(MAIN_EXEC): $(MAIN_OBJECT) $(DOMAIN_OBJECTS)
	@echo "Linking main program..."
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build complete: $(MAIN_EXEC)"

# Build test program
test: $(TEST_EXEC)
	@echo "Running test program..."
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJECT) $(DOMAIN_OBJECTS)
	@echo "Linking test program..."
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Test build complete: $(TEST_EXEC)"

# Compile main.cpp to object file
$(MAIN_OBJECT): $(MAIN_SOURCE)
	@echo "Compiling $<..."
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test_user_hierarchy.cpp to object file
$(TEST_OBJECT): $(TEST_SOURCE)
	@echo "Compiling $<..."
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile domain source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the main program
run: $(MAIN_EXEC)
	@echo "Running Airline Reservation System..."
	./$(MAIN_EXEC)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(OBJ_DIR)/*.o
	rm -f $(MAIN_EXEC)
	rm -f $(TEST_EXEC)
	@echo "Clean complete"

# Rebuild everything from scratch
rebuild: clean all

# Display help information
help:
	@echo "Airline Reservation System - Makefile"
	@echo "Available targets:"
	@echo "  make          - Build main program (default)"
	@echo "  make all      - Build main program"
	@echo "  make test     - Build and run test program"
	@echo "  make run      - Build and run main program"
	@echo "  make clean    - Remove all build artifacts"
	@echo "  make rebuild  - Clean and rebuild everything"
	@echo "  make help     - Display this help message"

# Phony targets (not actual files)
.PHONY: all test run clean rebuild help
