#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define max 5000

int a[max][max];

int main() {
  int *b;
  b = malloc(sizeof(int));
  int i, j;
  for(i = 0; i < max; i++){
    for(j = 0; j < max; j++)
       a[i][j] = j;
  }
  printf("Last element %d\n\n", a[i-1][j-1]);
  wait_for_seconds();
  printf("finito\n");
}
