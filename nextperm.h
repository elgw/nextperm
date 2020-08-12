#ifndef nextperm_h_
#define nextperm_h_

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int * C;
  int * A; // Permuted integers at current iteration
  size_t N; // Number of digits
  int i;
} perm_t;

/** Allocate storage for permutation object,
 * and set the first permutation of the set
 * {1, 2, ..., N} to [1,2,...,N].
 * Returns NULL if the allocation failed.
 * **/
perm_t * perm_init(int N);

/**  Iterate P to the next permutation.
 * Returns 1 on sucess or 0 if all permutations
 * of the set already has been generated
 */
int perm_next(perm_t * P);

/** Free the storage allocated for P
*/
void perm_free(perm_t * P);

/** Show the current permutation
 * This function is mostly for debugging and provided 
 * as an example on how to use P, i.e., access
 * P->A to get the current permutation */
void perm_show(perm_t * P);

#endif
