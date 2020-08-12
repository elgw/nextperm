#include <stdio.h>
#include <stdlib.h>
#include "permn.h"

void showarray(int * A, int n)
{
  for(int kk = 0; kk<n; kk++)
  {
    printf("%d ", A[kk]);
  }
  printf("\n");
  fflush(stdout);
  return;
}

int main(int argc, char ** argv)
{
  if(argc < 3)
  {
    printf("Usage: %s #perm #symbols\n", argv[0]);
    return 1;
  }
  size_t perm = atol(argv[1]);
  int nsym = atoi(argv[2]);
  printf("Finding permutation %zu of %d elements\n", perm, nsym);
  int * P = permn(perm, nsym);
  showarray(P, nsym);
  return 0;
}
