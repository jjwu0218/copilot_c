# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = eg

# Source files
SOURCES = eg.c
OBJECTS = $(SOURCES:.c=.o)

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean intermediate files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rule for running the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
