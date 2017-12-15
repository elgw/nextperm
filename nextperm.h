typedef struct {
  int * C;
  int * A; // The permuted numbers at current iteration
  size_t N;
  int i;
} perm_t;

perm_t perm_init(int N);
int perm_next(perm_t * P);
void perm_free(perm_t * P);
void perm_show(perm_t * P);

// internal
void perm_swap(perm_t * P, int x, int y);

