# Nextperm

Generates permutations when needed using non-recursive algorithm found
on [wikipedia](https://en.wikipedia.org/wiki/Heap's_algorithm)

## Example

```
$ make
gcc --std=c99 -Wall -c nextperm.c -o nextperm.o
gcc --std=c99 -Wall nextperm_test.c nextperm.o -o nextperm_test
$ ./nextperm_test 1
#001 1 
$ ./nextperm_test 2
#001 1 2 
#002 2 1 
$ ./nextperm_test 3
#001 1 2 3 
#002 2 1 3 
#003 3 1 2 
#004 1 3 2 
#005 2 3 1 
#006 3 2 1 
$ ./nextperm_test 4
#001 1 2 3 4 
#002 2 1 3 4 
#003 3 1 2 4 
#004 1 3 2 4 
#005 2 3 1 4 
#006 3 2 1 4 
#007 4 2 1 3 
#008 2 4 1 3 
#009 1 4 2 3 
#010 4 1 2 3 
#011 2 1 4 3 
#012 1 2 4 3 
#013 1 3 4 2 
#014 3 1 4 2 
#015 4 1 3 2 
#016 1 4 3 2 
#017 3 4 1 2 
#018 4 3 1 2 
#019 4 3 2 1 
#020 3 4 2 1 
#021 2 4 3 1 
#022 4 2 3 1 
#023 3 2 4 1 
#024 2 3 4 1 
``` 
