#include <assert.h>
#include <string.h>

#include "nextperm.h"

typedef uint32_t u32;
typedef uint64_t u64;

static void
hperm_swap(hperm_t * P, const u32 x, const u32 y)
{
    u32 t = P->permutation[x];
    P->permutation[x] = P->permutation[y];
    P->permutation[y] = t;
}

hperm_t *
hperm_init(const u32 n_elements)
{
    hperm_t * P = calloc(1, sizeof(hperm_t));
    if(P == NULL)
    {
        return NULL;
    }

    *(u32*)&P->n_elements = n_elements; /* set const value */

    P->C = calloc(n_elements, sizeof(u32)); // swap state variables
    if((P->C) == NULL)
    {
        free(P);
        return NULL;
    }

    P->permutation = calloc(n_elements, sizeof(u32)); // integers to be permuted
    if(P->permutation == NULL)
    {
        free(P->C);
        free(P);
        return NULL;
    }

    for(u32 kk = 0; kk<n_elements; kk++)
    {
        P->C[kk] = 0;
        P->permutation[kk] = kk+1;
    }


    return P;
}

u32
hperm_next(hperm_t * P)
{

    u64 ii = 0;
    do {
        if(ii == P->n_elements)
        {
            return -1;
        }

        if(P->C[ii] < ii)
        {
            if( (ii % 2) == 0)
            { // if even
                hperm_swap(P, 0, ii);
            }
            else
            {
                hperm_swap(P, P->C[ii], ii);
            }
            // output
            P->C[ii]++;
            ii = 0;
        }
        else
        {
            P->C[ii] = 0;
            ii++;
        }
    }
    while(ii != 0);

    return 0;
}

void
hperm_free(hperm_t * P)
{
    free(P->C);
    free(P->permutation);
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
    u64 * F = getfactoradic(N, n);
    u64 * P = getpermutation(F, n);
    free(F);
    return P;
}
