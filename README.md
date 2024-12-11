The nextperm library provides:

- `hperm_init`, `hperm_next`, `...` to generate the next permutation of the
integers $[1, 2, ... N]$ using [Heap's
algorithm](https://en.wikipedia.org/wiki/Heap's_algorithm) similar to
`std::next_permutation` in C++.

   Usage is something like this:
   ``` c
   hperm_t * P = hperm_init(N);
   do
   {
       process(P->permutation);
   } while (!hperm_next(P));
   hperm_free(P);
   ```

- `lexpermn` to directly generate the Nth lexicographical permutation of the
  integers $[1,2,...N]$ using the [factorial number
  system](https://en.wikipedia.org/wiki/Factorial_number_system)
  (factoradic).


## Usage

Just include it in your project.

For the API documentation see `nextperm.h`.

The basic usage can be seen in `nextterm_test.c`.

```
-> All permutations for 1, ..., 3 (perm_init, perm_next)
1 2 3  (0)
2 1 3  (1)
3 1 2  (2)
1 3 2  (3)
2 3 1  (4)
3 2 1  (5)

-> All permutations for 1, ..., 3 (lexperm)
1 2 3  (0)
1 3 2  (1)
2 1 3  (2)
2 3 1  (3)
3 1 2  (4)
3 2 1  (5)
```
