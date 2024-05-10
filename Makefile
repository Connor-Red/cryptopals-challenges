# TO USE: CHANGE THE SRC_DIR TO THE DIRECTORY WITH THE SOURCE FILE TO COMPILE
# THEN USE MAKE TO COMPILE AND MAKE CLEAN TO CLEAN

CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC_DIR := 1_2_fixed_xor
UTILS_DIR := utils

# Find all .c files in the source and utils subfolders
SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

# Default target
all: program.out

# Build the program.out binary
program.out: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile the specified .c file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(UTILS_DIR)/*.o program.out