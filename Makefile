CC = gcc
TARGET = app
OBJECTS = main.o database.o filefuncs.o search.o

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: $.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)

PHONY: all clean