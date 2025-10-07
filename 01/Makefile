CC      = gcc
CFLAGS  = -Wall -Wextra -O2
TARGET_STATIC = main_static
TARGET_SHARED = main_shared
LIB_STATIC    = libstrutils.a
LIB_SHARED    = libstrutils.so
OBJS          = bstrutils.o
INCLUDES      = -I.

all: static shared

static: $(LIB_STATIC) $(TARGET_STATIC)

$(LIB_STATIC): $(OBJS)
	ar rcs $@ $(OBJS)

$(TARGET_STATIC): main.c $(LIB_STATIC)
	$(CC) $(CFLAGS) main.c -L. -lstrutils -o $@

shared: $(LIB_SHARED) $(TARGET_SHARED)

$(LIB_SHARED): bstrutils.c strutils.h
	$(CC) -fPIC -c bstrutils.c -o bstrutils.o
	$(CC) -shared -o $@ bstrutils.o

$(TARGET_SHARED): main.c $(LIB_SHARED)
	$(CC) $(CFLAGS) main.c -L. -lstrutils -o $@


clean:
	rm -f *.o *.a *.so $(TARGET_STATIC) $(TARGET_SHARED)


bstrutils.o: bstrutils.c strutils.h
	$(CC) $(CFLAGS) -c $< -o $@
