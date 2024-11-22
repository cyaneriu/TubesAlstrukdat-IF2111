# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Ispesifikasi -IADT

# Source directories
SRC_DIRS = spesifikasi ADT

# Source files: find all .c files in the specified directories
SRCS = main.c $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

# Object files: replace .c with .o for all source files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
