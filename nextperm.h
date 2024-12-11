#pragma once

/* Generates all permutations of the integers [1, ..., N] using
   Heap's algorithm: https://en.wikipedia.org/wiki/Heap's_algorithm
*/

#include <stdlib.h>
#include <stdint.h>

#define NEXTPERM_VERSION_MAJOR 0
#define NEXTPERM_VERSION_MINOR 1
#define NEXTPERM_VERSION_PATCH 0

typedef struct {
    uint32_t N; // Number of digits
    uint32_t * A; // N permuted values at current iteration
    uint32_t * C;
    uint32_t i;
} perm_t;

/** Allocate storage for permutation object,
 * and set the first permutation of the set
 * {1, 2, ..., N} to [1,2,...,N].
 * Returns NULL if the allocation failed.
 * **/
perm_t * perm_init(uint32_t N);

/**  Iterate P to the next permutation.
 * Returns 1 on sucess or 0 if all permutations
 * of the set already has been generated
 *
 * No calls to free or malloc are used.
 */
uint32_t perm_next(perm_t * P);

/** Free the storage allocated for P
 */
void perm_free(perm_t * P);

/** Generates the Nth lexicographical permutation of
 * the integers 1, 2, ... n
 *
 * The factoradic representation of N is calculated
 * before the permutation is generated and returned.
 *
 * The returned array will have n elements and it is
 * the responsibility of the caller to free it.
 *
 * Reference:
 * https://en.wikipedia.org/wiki/Factorial_number_system
 */

uint64_t * lexpermn(uint64_t Nth, uint64_t n_elements);
