CC = gcc
CFLAGS = -Wall -Wextra -Ispesifikasi -IADT
# Source files
SRCS = cobamain.c \
       spesifikasi/store.c \
       spesifikasi/store_list.c \
       spesifikasi/store_remove.c \
       spesifikasi/store_request.c \
       spesifikasi/store_supply.c \
       ADT/list_dinamis.c \
       ADT/mesinkata.c \
       ADT/mesinkarakter.c
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
# Phony targets
.PHONY: all clean