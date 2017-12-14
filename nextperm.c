#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int * C;
  int * A;
  size_t N;
  int i;
} perm_t;

void perm_swap(perm_t * P, int x, int y)
{
  int t = P->A[x];
  P->A[x] = P->A[y];
  P->A[y] = t;
}

perm_t perm_init(int N)
{
  perm_t P;
  P.C = malloc(sizeof(int)*N); // swap state variables
  P.A = malloc(sizeof(int)*N); // integers to be permuted. 
  for(int kk = 0; kk<N; kk++)
  {
    P.C[kk] = 0;
    P.A[kk] = kk+1;
  }
  P.i = 0;
  P.N = N;
  return P;
}

int perm_next(perm_t * P)
{

 do {
  if(P->i == P->N)
    return -1;

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

void perm_free(perm_t * P)
{
  free(P->C);
  free(P->A);
}

void perm_show(perm_t * P)
{
    for(int kk = 0; kk<P->N; kk++)
      printf("%d ", P->A[kk]);
    printf("\n");
}

int main(int argc, char ** argv)
{
  int N = 4;
int pnum = 1;
  if(argc == 2)
    N = atoi(argv[1]);

  if(N<1)
    return 0;

  perm_t P = perm_init(N);  

  printf("#%03d ", pnum++); perm_show(&P);
  while(perm_next(&P) == 0)
  {
  printf("#%03d ", pnum++);    perm_show(&P);
  }
  perm_free(&P);

  return 0;
}
