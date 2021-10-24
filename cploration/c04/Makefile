
CC = gcc
CFLAGS = -Wall -I.
LDLFLAGS =
OBJFILES = main.o parser.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDLFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
