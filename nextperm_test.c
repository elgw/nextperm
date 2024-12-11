#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint64_t u64;

#include <assert.h>

#include "nextperm.h"


static void
print_array64(u64 * A, u64 n)
{
    for(u64 kk = 0; kk < n; kk++)
    {
        printf("%lu ", A[kk]);
    }
    return;
}

static void
print_array32(u32 * A, u32 n)
{
    for(u32 kk = 0; kk < n; kk++)
    {
        printf("%u ", A[kk]);
    }
    return;
}


static u64
factorial(u64 n)
{
    assert(n > 0);
    size_t nf = 1;
    for(u64 kk = 2; kk <= n; kk++)
    {
        nf*=kk;
    }
    return nf;
}

int main(int argc, char ** argv)
{
    u64 N = 4;

    if(argc == 2)
    {
        N = atol(argv[1]);
    }

    if(N<1)
    {
        printf("Please use at least one digit\n");
        return EXIT_FAILURE;
    }

    printf("Using %lu digits (%lu permutations)\n", N, factorial(N));
    fflush(stdout);

    printf("-> All permutations for 1, ..., %lu (perm_init, perm_next)\n", N);

    hperm_t * P = hperm_init(N);
    if(P == NULL)
    {
        printf("Allocation failed\n");
        return EXIT_FAILURE;
    }

    u64 n = 0;
    do
    {
        print_array32(P->permutation, N);
        printf(" (%lu)\n", n++);
    } while (!hperm_next(P));

    hperm_free(P);

    printf("\n");
    printf("-> All permutations for 1, ..., %lu (lexperm)\n", N);

    u64 nperm = factorial(N);
    for(u64 pnum = 0; pnum < nperm; pnum++)
    {
        u64 * P = lexpermn(pnum, N);
        print_array64(P, N);
        printf(" (%lu)\n", pnum);
        free(P);
    }

    return EXIT_SUCCESS;
}
