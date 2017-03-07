#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define max 5000

int main() {
  int **a;
  int i, j;

  a=(int **) malloc(max * sizeof(int *));

  for(i=0;i<max;i++)
    a[i]=(int *) malloc(max * sizeof(int));

  for(i = 0; i < max; i++){
    for(j = 0; j < max; j++)
       a[i][j] = j;
  }
  printf("Last element %d\n\n", a[i-1][j-1]);

  int sec = 0, trigger = 10; // seconds
  int counter = 0;
  clock_t before = clock();
//  printf("clock %Lf", (long double) before);
  printf("loop started \n");
  while(sec < trigger){
    clock_t diff = clock()-before;
//    printf("clock %Lf", (long double) diff);
    counter++;
    sec = diff / 1000000;
  }
  printf("loop finished\n");
/* 
  long  long int_max = pow(2, 32);
  long start;
  printf("loop %lld\n", int_max);
  for(start = 0; start < int_max; start++){
  }
  printf("loop end \n");

  */
  for(i =0; i< max; i++){
    free(a[i]);
  }
  free(a);
  while(1){
  }
}
