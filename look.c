#include <stdio.h>
#include <stdlib.h>

void fcfs(int blockList[], int count) {
  printf("In LOOK:\n");
  for (int i = 0; i < count; i++) {
    printf("%d ", blockList[i]);
  }
  printf("\n");
}
