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
  u64 pnum = 1;
  if(argc == 2)
    N = atol(argv[1]);

  if(N<1)
    return 0;

  printf("Showing all permutations for 1, ..., %lu (perm_init, perm_next)\n", N);

  perm_t * P = perm_init(N);
  if(P == NULL)
  {
    printf("Allocation failed\n");
    return EXIT_FAILURE;
  }


  print_array32(P->A, P->N);
  printf(" (0)\n");
  while(perm_next(P) == 0)
  {
      print_array32(P->A, N);
      printf(" (%lu)\n", pnum++);
  }
  perm_free(P);

  printf("Showing using lexographic order (lexpermn)\n");
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
