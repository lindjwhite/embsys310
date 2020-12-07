#include "stdio.h"

void swap_pointers(int **a, int **b) {
  int *tmp_ptr = *a;
  *a = *b;
  *b = tmp_ptr;
}

int main() {
  int x = 10, y = 20;
  int *x_ptr = &x, *y_ptr = &y;

  swap_pointers(&x_ptr, &y_ptr);

  printf("pointer x: %d, pointer y: %d\n", *x_ptr, *y_ptr);

  return 0;
}
