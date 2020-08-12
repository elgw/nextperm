#include "permn.h"

static int * getfactoradic(size_t N, int n)
{
  int * F = malloc(n*sizeof(int));
  for(int kk = 0; kk<n; kk++)
  {
    ldiv_t d = ldiv(N, kk+1);
    F[n-1-kk] = d.rem;
    N=d.quot;
  }
  return F;
}

static void remove(int * S, int pos, int n)
{
  // Remove used integer from the array
  for(int ll = pos; ll+1<n; ll++)
  {
    S[ll] = S[ll+1];
  }
  return;
}

static int * getpermutation(int * L, int n)
{
  int * P = malloc(n*sizeof(int));

  // Set of integers to pick from
  int * S = malloc(n*sizeof(int));
  for(int kk = 0; kk<n; kk++)
  {
    S[kk] = kk+1;
  }

  for(int kk = 0; kk<n; kk++)
  {
    int pos = L[kk];
    P[kk] = S[pos];
    remove(S, pos, n);
  }

  free(S);
  return P;
}

int * permn(size_t N, int n)
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
  int * F = getfactoradic(N, n);
  int * P = getpermutation(F, n);
  free(F);
  return P;
}


