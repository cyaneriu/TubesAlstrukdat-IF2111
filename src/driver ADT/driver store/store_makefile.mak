# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I../../spesifikasi -I../../ADT

SRC_DIRS = ../../spesifikasi ../../ADT

SRCS = cobamain.c $(wildcard $(addsuffix /*.c, $(SRC_DIRS))) 

OBJS = $(SRCS:.c=.o)

TARGET = ./cobamain

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJS) $(TARGET)

.PHONY: all clean