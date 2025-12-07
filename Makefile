CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
DATA_DIR = data
TARGET = atm

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/auth.c $(SRC_DIR)/system.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
