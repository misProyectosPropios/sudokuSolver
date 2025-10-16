# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
LDLIBS = -lcunit

# Paths
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

# Files
SRC = $(SRC_DIR)/sudoku.c
TEST = $(TEST_DIR)/test.c
TARGET = $(BIN_DIR)/test

# Default target
all: $(TARGET)

# Link test executable
$(TARGET): $(SRC) $(TEST)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET) $(LDLIBS)

# Run tests
test: $(TARGET)
	./$(TARGET)

# Clean build
clean:
	rm -rf $(BIN_DIR)
