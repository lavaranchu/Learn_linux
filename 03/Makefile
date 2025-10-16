
CC = gcc
CFLAGS = -Wall -O2


SRC1 = bt1_fork_wait.c
SRC2 = bt2_exec_env.c
SRC3 = bt3_zombie.c
SRC4 = bt3_orphan.c


TARGET1 = bt1
TARGET2 = bt2
TARGET3 = zombie
TARGET4 = orphan

all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)


$(TARGET1): $(SRC1)
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET2): $(SRC2)
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET3): $(SRC3)
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET4): $(SRC4)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)
