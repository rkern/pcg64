CC = gcc
CFLAGS = -I.
CFLAGS += -O3
CFLAGS += -std=c99
#CFLAGS += -DPCG_FORCE_EMULATED_128BIT_MATH
LDFLAGS = -L.
LDLIBS = -lpcg64

all: libpcg64.a test-pcg64

pcg64.o: pcg64.c pcg64.h

libpcg64.a: pcg64.o
	ar rc $@ $^
	ranlib $@

test-pcg64.o: test-pcg64.c pcg64.h
test-pcg64: test-pcg64.o

clean:
	rm -f *.a *.o test-pcg64
