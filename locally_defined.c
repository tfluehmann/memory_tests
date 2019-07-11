#include <stdio.h>
#include <stdlib.h>
#include "util.h"
//#define max 5000

int ** allocate(int **a);
void dellocate(int **a);
int max();

int main() {
  int **a;
  printf("size of int %lu bytes\n", sizeof(int));
  a = allocate(a);
  wait_for_seconds();
  dellocate(a);
  wait_for_seconds();
  printf("huston over\n");
}

void dellocate(int **a){
  for(int i = 0; i < max(); i++)
    free(a[i]);
  free(a);
  printf("freed memory\n");
}

int ** allocate(int **a){
  int i, j;

  a=(int **) malloc(max() * sizeof(int *));
  for(i=0; i < max(); i++)
    a[i]=(int *) malloc(max() * sizeof(int));

  for(i = 0; i < max(); i++){
    for(j = 0; j < max(); j++)
       a[i][j] = j;
  }
  printf("Last element %d\n\n", a[i-1][j-1]);
  return a;
}

int max() {
  char *val = getenv("MAX_MEMORY");
  if(val == NULL) {
    return 5000;
  } else {
    int x;
    sscanf(val, "%d", &x);
    return x;
  }
}
