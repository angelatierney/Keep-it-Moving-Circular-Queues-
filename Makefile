# Compiler
CC = gcc
CFLAGS = -Wall -g

# Files
OBJS = main.o queue.o
TARGET = runqueue

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c queue.h list.h
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c queue.h list.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o $(TARGET)

