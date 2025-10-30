# === Makefile for cprogramming ===

CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -g
SRC_DIR := challenges
BIN_DIR := bin

# Collect all .c files in challenges/
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Replace .c with corresponding bin/ executables
BINS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRCS))

# Default target — build everything
all: $(BINS)

# Rule for building each binary
$(BIN_DIR)/%: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Remove all binaries
clean:
	rm -rf $(BIN_DIR)

# Rebuild from scratch
rebuild: clean all

# Just print what would be built
list:
	@echo "Source files:" $(SRCS)
	@echo "Binaries:" $(BINS)

.PHONY: all clean rebuild list
