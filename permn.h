/* Generates the Nth lexicographical permutation of 
 * the integers 1, 2, ... n
 *
 * Internally it first calculates the factoradic representation of N
 * before the permutation is generated and returned.
 *
 * The returned array will have n elements and it is 
 * the responsibility of the caller to free it.
 *
 * Reference: 
 * https://en.wikipedia.org/wiki/Factorial_number_system
 */

#ifndef permn_h_
#define permn_h_h

#include <stdlib.h>

int * permn(size_t N, int n);

#endif
