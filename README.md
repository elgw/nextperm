# Nextperm

Generates permutations permutations of integer sets using [Heap's algorithm](https://en.wikipedia.org/wiki/Heap's_algorithm)

In C++ there is the `std::next_permutation`.

Observe that the sets use `1` as their first member.

## Usage
See `nextterm_test.c`.

## Example

```
$ make all
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
...
``` 

# Permn

Generate the Nth lexicographical permutation of the integer set 1,2,...n using the [factorial number system](https://en.wikipedia.org/wiki/Factorial_number_system) (factoradic).

## Usage
See `permn_test.c`.

## Example
```
$ ./permn_test 0 7
Finding permutation 0 of 7 elements
1 2 3 4 5 6 7 
$ ./permn_test 1 7
Finding permutation 1 of 7 elements
1 2 3 4 5 7 6 
$ ./permn_test 5039 7
Finding permutation 5039 of 7 elements
7 6 5 4 3 2 1
```
