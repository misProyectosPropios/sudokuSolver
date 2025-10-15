# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src -I/usr/include/lcunit
LDFLAGS = -llcunit

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Files
SRC = $(SRC_DIR)/main.c
TEST = $(TEST_DIR)/test.c
TARGET = $(BUILD_DIR)/test_runner

# Default rule
all: test

# Build and run tests
test: $(TARGET)
	@echo "Running tests..."
	./$(TARGET)

# Build test binary
$(TARGET): $(SRC) $(TEST)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET) $(LDFLAGS)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
