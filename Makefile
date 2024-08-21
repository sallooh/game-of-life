CC = gcc
CFLAGS = -Iinclude -Wall

SRC = src/main.c src/game_of_life.c
OBJ = $(SRC:.c=.o)
TARGET = game_of_life

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean
