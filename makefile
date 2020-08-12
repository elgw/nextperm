cc=gcc
cflags=--std=c99 -Wall

all: permn_test nextperm_test

permn_test:
	$(cc) $(cflags) -c permn.c
	$(cc) $(cflags) permn_test.c permn.o -o permn_test

nextperm_test:
	$(cc) $(cflags) -c nextperm.c
	$(cc) $(cflags) nextperm_test.c nextperm.o -o nextperm_test
