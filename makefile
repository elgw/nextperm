nextperm_test:
	gcc --std=c99 -Wall -c nextperm.c -o nextperm.o
	gcc --std=c99 -Wall nextperm_test.c nextperm.o -o nextperm_test
