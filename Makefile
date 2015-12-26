CC = gcc
CFLAGS = -I.
CFLAGS += -O3
CFLAGS += -std=c99
#CFLAGS += -DPCG_FORCE_EMULATED_128BIT_MATH
LDFLAGS = -L.
LDLIBS = -lpcg64

all: libpcg64.a test-pcg64-native test-pcg64-emulated

pcg64.o: pcg64.c pcg64.h

libpcg64.a: pcg64.o
	ar rc $@ $^
	ranlib $@

test-pcg64-native.o: test-pcg64.c pcg64.h
	$(CC) -c -o $@ $(CFLAGS) test-pcg64.c

test-pcg64-emulated.o: test-pcg64.c pcg64.h
	$(CC) -c -o $@ $(CFLAGS) -DPCG_FORCE_EMULATED_128BIT_MATH test-pcg64.c

test-pcg64-native: test-pcg64-native.o
test-pcg64-emulated: test-pcg64-emulated.o

clean:
	rm -f *.a *.o test-pcg64-native test-pcg64-emulated
