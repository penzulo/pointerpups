CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -g -Iinclude

SRC_DIR := src
TEST_DIR := tests
OBJ_DIR := obj
BIN_DIR := bin

LIB_SRCS := $(wildcard $(SRC_DIR)/*.c)
LIB_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(TEST_SRCS))

# Default: Build all tests
all: $(TEST_BINS)

# --- STEP 1: COMPILE THE LIBRARY OBJECTS ---
# Rule: Turn src/%.c into obj/%.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# --- STEP 2: COMPILE AND LINK THE TESTS ---
# Rule: Turn tests/%.c into bin/%
# Note: We depend on $(LIB_OBJS) so the library is compiled first!
$(BIN_DIR)/%: $(TEST_DIR)/%.c $(LIB_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIB_OBJS) -o $@

# Create directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
