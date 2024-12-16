# Compiler and flags
CXX = g++
CXXFLAGS = -O2 -g -Wall -fmessage-length=0
INCLUDE = -Iinclude

# Source and output directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = debug

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Target executable
TARGET = FinalProject.exe

# Libraries (if any, add them here)
LIBS =

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# Create debug directory if it doesn't exist
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Convenience targets
all: $(TARGET)

# Clean target (Windows compatible with checks for existence)
clean:
	@if exist $(TARGET) del /f $(TARGET)
	@if exist $(BUILD_DIR) del /f $(BUILD_DIR)\*.o
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
