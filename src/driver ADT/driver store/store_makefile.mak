# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I../../spesifikasi -I../../ADT

# Menentukan file sumber yang spesifik
SRCS = cobamain.c \
       ../../spesifikasi/store.c \
       ../../spesifikasi/store_list.c \
       ../../spesifikasi/store_request.c \
       ../../spesifikasi/store_supply.c \
       ../../spesifikasi/store_remove.c \
       ../../ADT/queue.c \
       ../../ADT/list_dinamis.c \
       ../../ADT/mesinkata.c \
       ../../ADT/mesinkarakter.c

# Menentukan file objek yang dihasilkan
OBJS = $(SRCS:.c=.o)

# Nama target output
TARGET = ./cobamain

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJS) $(TARGET)

.PHONY: all clean
