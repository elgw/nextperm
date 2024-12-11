CC=gcc
CFLAGS=--std=c99 -Wall -Wextra -pedantic

DEBUG?=0
ifeq ($(DEBUG),1)
CFLAGS+=-g3
else
CFLAGS+=-O3 -DNDEBUG
LDFLAGS+=-flto
endif

nextperm_test: nextperm_test.c nextperm.o
	$(CC) $(CFLAGS) nextperm_test.c nextperm.o -o nextperm_test

nextperm.o: nextperm.c
	$(CC) -c $(CFLAGS) nextperm.c -o nextperm.o

clean:
	rm nextperm.o
	rm nextperm_test
