#include <stdio.h>
#include <stdlib.h>

#include "nextperm.h"

int main(int argc, char ** argv)
{
  int N = 4;
  int pnum = 1;
  if(argc == 2)
    N = atoi(argv[1]);

  if(N<1)
    return 0;

  perm_t * P = perm_init(N);
  if(P==NULL)
  {
    printf("Allocation failed\n");
    return 1;
  }

  printf("#%03d ", pnum++); perm_show(P);
  while(perm_next(P) == 0)
  {
    printf("#%03d ", pnum++);    perm_show(P);
  }
  perm_free(P);

  return 0;
}
