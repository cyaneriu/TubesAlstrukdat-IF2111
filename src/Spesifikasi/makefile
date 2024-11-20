# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I../ADT

# Source files
SRCS = cobamain.c store.c store_list.c store_remove.c store_request.c store_supply.c ../ADT/list_dinamis.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = cobamain

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
