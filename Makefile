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
TEST_TARGET = $(BIN_DIR)/test_atm
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_OBJS = $(OBJ_DIR)/test_atm.o

all: dirs $(TARGET)

dirs:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(DATA_DIR) logs

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/test_atm.o: test_atm.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: dirs $(TEST_TARGET)
	@echo "Running ATM Management System Tests..."
	@./$(TEST_TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) logs/*.log test_atm

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
	@echo "  test    - Build and run test suite"
	@echo "  run     - Build and run the application"
	@echo "  clean   - Remove build artifacts"
	@echo "  install - Install system-wide"

.PHONY: all clean run install dirs sqlite help test
