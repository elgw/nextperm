#include "nextperm.h"

#include <assert.h>


typedef uint32_t u32;
typedef uint64_t u64;

static void
perm_swap(perm_t * P, const u32 x, const u32 y)
{
    u32 t = P->A[x];
    P->A[x] = P->A[y];
    P->A[y] = t;
}

perm_t *
perm_init(const u32 N)
{
    perm_t * P = calloc(1, sizeof(perm_t));
    if(P == NULL)
    {
        return NULL;
    }

    P->C = calloc(N, sizeof(u32)); // swap state variables
    if((P->C) == NULL)
    {
        free(P);
        return NULL;
    }

    P->A = calloc(N, sizeof(u32)); // u32egers to be permuted.
    if(P->A == NULL)
    {
        free(P->C);
        free(P);
        return NULL;
    }

    for(u32 kk = 0; kk<N; kk++)
    {
        P->C[kk] = 0;
        P->A[kk] = kk+1;
    }
    P->i = 0;
    P->N = N;
    return P;
}

u32
perm_next(perm_t * P)
{

    do {
        if(P->i == P->N)
        {
            return -1;
        }

        if(P->C[P->i] < P->i)
        {
            if( (P->i % 2) == 0)
            { // if even
                perm_swap(P, 0, P->i);
            }
            else
            {
                perm_swap(P, P->C[P->i], P->i);
            }
            // output
            P->C[P->i]++;
            P->i = 0;
        }
        else
        {
            P->C[P->i] = 0;
            P->i++;
        }
    }
    while(P->i != 0);

    return 0;
}

void
perm_free(perm_t * P)
{
    free(P->C);
    free(P->A);
    free(P);
    P = NULL;
}


/* Below: Functions for lexpermn */

static u64 *
getfactoradic(u64 N, u64 n)
{
    u64 * F = calloc(n, sizeof(u64));
    assert(F != NULL);
    for(u64 kk = 0; kk<n; kk++)
    {
        ldiv_t d = ldiv(N, kk+1);
        F[n-1-kk] = d.rem;
        N=d.quot;
    }
    return F;
}

static void
remove_used(u64 * S, u64 pos, u64 n)
{
    // Remove used integer from the array
    for(u64 ll = pos; ll+1<n; ll++)
    {
        S[ll] = S[ll+1];
    }
    return;
}

static u64 *
getpermutation(u64 * L, u64 n)
{
    u64 * P = calloc(n, sizeof(u64));
    assert(P != NULL);

    // Set of integers to pick from
    u64 * S = calloc(n, sizeof(u64));
    assert(S != NULL);

    for(u64 kk = 0; kk<n; kk++)
    {
        S[kk] = kk+1;
    }

    for(u64 kk = 0; kk<n; kk++)
    {
        u64 pos = L[kk];
        P[kk] = S[pos];
        remove_used(S, pos, n);
    }

    free(S);
    return P;
}

u64 *
lexpermn(u64 N, u64 n)
{
    /* Generate the Nth permutation of the integers 1, ..., n
     *  1. Get the factoradic of N -> F
     *  2. Get the Lehmer code of F -> L
     *  3. Generate the permutation from L -> P
     *  4. Return
     *
     *  The returned array will have n elements and it is
     *  the responsibility of the caller to free it.
     */
    u64 * F = getfactoradic(N, n);
    u64 * P = getpermutation(F, n);
    free(F);
    return P;
}
