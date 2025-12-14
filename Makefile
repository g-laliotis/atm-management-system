CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pthread
LDFLAGS = -pthread

# SQLite support (optional)
ifeq ($(USE_SQLITE),1)
    CFLAGS += -DUSE_SQLITE
    LDFLAGS += -lsqlite3
endif

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include
DATA_DIR = data

TARGET = $(BIN_DIR)/atm
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: dirs $(TARGET)

dirs:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(DATA_DIR) logs

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) logs/*.log

run: $(TARGET)
	@cd $(BIN_DIR) && ./atm

install: $(TARGET)
	@echo "Installing ATM Management System..."
	@cp $(TARGET) /usr/local/bin/atm 2>/dev/null || echo "Run with sudo for system-wide install"

sqlite: clean
	@echo "Building with SQLite support..."
	@$(MAKE) USE_SQLITE=1

help:
	@echo "Available targets:"
	@echo "  all     - Build with text file storage (default)"
	@echo "  sqlite  - Build with SQLite database support"
	@echo "  run     - Build and run the application"
	@echo "  clean   - Remove build artifacts"
	@echo "  install - Install system-wide"

.PHONY: all clean run install dirs sqlite help
