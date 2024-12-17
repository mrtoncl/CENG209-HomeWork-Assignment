CC = gcc
CFLAGS = -Wall -std=c11

# Source files
SRCS = main.c game.c map.c room.c player.c creature.c item.c trap.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = game.exe

# Default rule
all: $(TARGET)

# Linking object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compiling source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Run the game
run: $(TARGET)
	./$(TARGET)