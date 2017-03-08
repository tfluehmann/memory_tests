#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define max 5000
#define waittime 10 
#define clock_factor 1000000

void wait_for_seconds();
int ** allocate(int **a);
void dellocate(int **a);

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
  for(int i = 0; i < max; i++)
    free(a[i]);
  free(a);
  printf("freed memory\n");
}

int ** allocate(int **a){
  int i, j;

  a=(int **) malloc(max * sizeof(int *));
  for(i=0;i<max;i++)
    a[i]=(int *) malloc(max * sizeof(int));

  for(i = 0; i < max; i++){
    for(j = 0; j < max; j++)
       a[i][j] = j;
  }
  printf("Last element %d\n\n", a[i-1][j-1]);
  return a;
}

void wait_for_seconds(){
  int sec = 0;
  clock_t before = clock();
  printf("wait for %d seconds \n", waittime);
  while(sec < waittime){
    clock_t diff = clock()-before;
    sec = diff / clock_factor;
  }
}
