# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Iinclude -mconsole

# Folders
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Source and object files
SOURCES = $(SRC_DIR)/Book.cpp $(SRC_DIR)/Library.cpp $(SRC_DIR)/User.cpp main.cpp
OBJECTS = $(BIN_DIR)/Book.o $(BIN_DIR)/Library.o $(BIN_DIR)/User.o $(BIN_DIR)/main.o

# Target executable
TARGET = library_app

# Default rule
all: $(TARGET)

# Rules to compile each .cpp into .o
$(BIN_DIR)/Book.o: $(SRC_DIR)/Book.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/Library.o: $(SRC_DIR)/Library.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/User.o: $(SRC_DIR)/User.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linking all .o files into final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Clean build artifacts
clean:
	del /Q $(BIN_DIR)\*.o $(TARGET)
