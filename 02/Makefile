CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = filestat.c 

TARGET = filestat

all: $(TARGET) 

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)