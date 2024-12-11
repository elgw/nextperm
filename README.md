# Nextperm

The library provides:

- `perm_init`, `perm_next`, `...` Generates the next permutation of the
integers $[1, 2, ... N]$ using [Heap's
algorithm](https://en.wikipedia.org/wiki/Heap's_algorithm) similar to
`std::next_permutation` in C++.

- `lexpermn` Generate the Nth lexicographical permutation of the
  integer set $[1,2,...B] using the [factorial number
  system](https://en.wikipedia.org/wiki/Factorial_number_system)
  (factoradic).


## Usage
For the API documentation see `nextperm.h`.

The basic usage can be seen in `nextterm_test.c`.

``` shell
$ ./nextperm_test 3
Showing all permutations for 1, ..., 3 (perm_init, perm_next)
1 2 3  (0)
2 1 3  (1)
3 1 2  (2)
1 3 2  (3)
2 3 1  (4)
3 2 1  (5)
Showing using lexographic order (lexpermn)
1 2 3  (0)
1 3 2  (1)
2 1 3  (2)
2 3 1  (3)
3 1 2  (4)
3 2 1  (5)
```
