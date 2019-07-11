#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() {
  printf("Stopping process\n");
  wait_for_seconds();
  printf("Process stopped\n");
}
