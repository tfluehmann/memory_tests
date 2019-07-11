#include <stdio.h>
#include <time.h>
//#define waittime 10 
#define clock_factor 1000000
void wait_for_seconds();
int waittime();

void wait_for_seconds(){
  int sec = 0;
  clock_t before = clock();
  printf("wait for %d seconds \n", waittime());
  while(sec < waittime()){
    clock_t diff = clock()-before;
    sec = diff / clock_factor;
  }
}

int waittime() {
  int x;
  sscanf(getenv("WAITTIME"), "%d", &x);
  return x;
}
