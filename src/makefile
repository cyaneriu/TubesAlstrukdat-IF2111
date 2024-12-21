# compiler & flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Ispesifikasi -IADT

# source: directory spesifikasi & ADT, buat nambah source directories di source di bawah
SRC_DIRS = spesifikasi ADT

# source: semua program di spesifikasi & ADT, tambah welcome page program
SRCS = mainprogram.c $(wildcard $(addsuffix /*.c, $(SRC_DIRS))) welcome_perry.c

# object file dari.c ke -o -> otomatisasi
OBJS = $(SRCS:.c=.o)

# nama file .exe (executable)
TARGET = mainprogram

# buat target
all: $(TARGET)

# linking program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# cleaning program
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
.PHONY: all clean
